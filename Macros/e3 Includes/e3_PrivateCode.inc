|----------------------------------------------------|
|- Uses Manastone                                   -|
|----------------------------------------------------|
SUB check_Manastone
    /if (${Debug}) /echo |- check_Manastone ==>

    /if (!${Bool[${FindItem[=Manastone]}]}) /return
    /if (${Me.Invis}) /return
    /if (${Zone.ShortName.Equal[poknowledge]}) /return

    /declare i int local 0
    /declare minMana int local 50
    /declare minHP int local 60
    /declare maxMana int local 90
    /declare maxLoop int local 10
    /declare currentLoop int local 1
    |bare min mana you decide you need that you want to exit for a heal.
    /declare minManaToTryAndHeal int local 1000
    |chance this if your having connectivity issues
    /declare totalNumberOfClicksToTry int local 90

    /if (${Me.Combat} || ${Me.CombatState.Equal[Combat]} ||  ${AssistTarget} >0 ) {
        |Values for when in combat
        /varset minMana 80
        /varset maxMana 95
    } else {
        |Values for when out of combat
        /varset minMana 80
        /varset maxMana 95
    }

    /if (${Me.PctMana} > ${minMana}) /return

    |### Check for mana recovery methods before trying to stone
    |I'm actively recovering mana -- don't waste another recovery method
    /if (${Bool[${Me.Buff[Mana Draw]}]} || ${Bool[${Me.Song[Mana Draw]}]}) {
      /if (${Me.PctMana} > 50) {
        /RETURN
      }
    }

    |I'm actively recovering mana -- don't waste another recovery method
    /if (${Bool[${Me.Buff[Death Bloom]}]} || ${Bool[${Me.Song[Death Bloom]}]}) {
      /RETURN
    }

    /if (${Me.ItemReady[Summoned: Large Modulation Shard]}) {
      /if (${Math.Calc[${Me.MaxMana} - ${Me.CurrentMana}]} > 3500 && ${Me.CurrentHPs} > 6000) {
        /useitem "Summoned: Large Modulation Shard"
      }
      /return
    }

    /if (${Me.ItemReady[Azure Mind Crystal]}) {
      /if (${Math.Calc[${Me.MaxMana} - ${Me.CurrentMana}]} > 3500) {
        /useitem "Azure Mind Crystal"
      }
      /return
    }
    |-- Looking for Necromancer Epic to ensure he's not naked...
    /if (${Me.AltAbilityReady[Cannibalization]} && ${Me.CurrentHPs} > 7000) {
      /call castSimpleSpell "Cannibalization" 0
      /return
    }
    |-- Looking for Necromancer Epic to ensure he's not naked...
    /if (${Me.AltAbilityReady[Death Bloom]} && ${Bool[${FindItem[Deathwhisper]}]}) {
      /if (${Me.PctMana} < 20) {
        /alt act ${Me.AltAbility[Death Bloom].ID}
      }
      /return
    }

    |-- Looking for Enchanter Epic to ensure he's not naked...
    /if (${Me.AltAbilityReady[Mana Draw]} && ${Bool[${FindItem[Staff of Eternal Eloquence]}]}) {
      /if (${Me.PctMana} < 40) {
        /alt act ${Me.AltAbility[Mana Draw].ID}
      }
      /return
    }
    |#################
    |End mana recovery before stone
    |################

    /declare isMounted bool local false
    /if (${NetBots[${Me.Name}].Mounted}) {
        /varset isMounted True
    }

    /if (${Defined[manaStoneTimer]}) {
      /if (${manaStoneTimer}>0) {
        |/echo ManaStone: Skipping mana stone, timer has been set.
        /return
      }
    }

    /if (!${Defined[ManaStoneMPCheck]}) {
     /declare ManaStoneMPCheck int outer 0
    }
    /declare delaycounter int local 0
    /declare meX string local ${Me.X}
    /declare meY string local ${Me.Y}

    /while ( ${Me.PctHPs} >${minHP} && ${Me.PctMana}< ${maxMana} ) {

        |save the current mp before we start using the mana stone
        |this is used to make sure we get updated information from the server for using the stone
        /varset ManaStoneMPCheck ${Me.CurrentMana}
        |up to 5400 hp value, but a good % will not get through
        /for i 0 to ${totalNumberOfClicksToTry}
          /useitem "Manastone"
        /next i

        |Sanity check Check to see if our mana has moved at all.
        |Lag detection and backoff
        /if (${ManaStoneMPCheck}==${Me.CurrentMana}) {

          /delay 1
          /varset delaycounter 0
          |this loop will wait up to 1.5 seconds for the client to be updated, if not we will set a timer below
          /while (${ManaStoneMPCheck}==${Me.CurrentMana} && ${delaycounter}<15) {
            /delay 1
            /varcalc delaycounter ${delaycounter}+1
          }

          /if (${ManaStoneMPCheck}==${Me.CurrentMana}) {
            |we have an issue, mana values not updating, slow down mana stone
            /echo ManaStone: Issue, client mana has not been updated, even after a backoff period. Possible LD, setting 15 sec timer.
            /call CreateTimer "manaStoneTimer" "15s"
            /break
          }

        }
        |check to see if we need to heal, but only do it if we have mana to actually heal
        /if (${Select[${Me.Class.ShortName},CLR,DRU,SHM]} && ${Me.CurrentMana} > ${minManaToTryAndHeal}) {
            |interupt stoning if we have someone to heal
            /call check_HealCasting_DuringDetrimental
            /if (!${c_SubToRun}) {
                /break
            }
        }
        /varset ManaStoneMPCheck ${Me.CurrentMana}
        |rangers need to face their target, so best not to mess with their direction
        |no need to worry if mounted, as mounted players will not be pushed
        /if (!${isMounted}) {
          /face fast loc ${meY},${meX}
        }
        /for i 0 to ${totalNumberOfClicksToTry}
          /useitem "Manastone"
        /next i
        /if (!${isMounted}) {
          /face fast loc ${meY},${meX}
        }
        |Sanity check Check to see if our mana has moved at all.
        |Lag detection and backoff
        /if (${ManaStoneMPCheck}==${Me.CurrentMana}) {

          /delay 1
          /varset delaycounter 0
          |this loop will wait up to 1.5 seconds for the client to be updated, if not we will set a timer below
          /while (${ManaStoneMPCheck}==${Me.CurrentMana} && ${delaycounter}<15) {
            /delay 1
            /varcalc delaycounter ${delaycounter}+1
          }

          /if (${ManaStoneMPCheck}==${Me.CurrentMana}) {
            |we have an issue, mana values not updating, slow down mana stone
            /echo ManaStone: Issue, client mana has not been updated, even after a backoff period. Possible LD, setting 15 sec timer.
            /call CreateTimer "manaStoneTimer" "15s"
            /break
          }

        }
        |check to see if we need to heal, but only do it if we have mana to actually heal
        /if (${Select[${Me.Class.ShortName},CLR,DRU,SHM]} && ${Me.CurrentMana} > ${minManaToTryAndHeal}) {
            |interupt stoning if we have someone to heal
            /call check_HealCasting_DuringDetrimental
            /if (!${c_SubToRun}) {
                /break
            }
        }

       | check for combat state, only allow stoning to allow /assistme/etc to work.
        /if (${Me.Combat} || ${Me.CombatState.Equal[Combat]} ||  ${AssistTarget} >0 ) {

          /if (${currentLoop}>=${maxLoop}) {
              /echo ManaStone: In combat, max loops (${maxLoop}) reached, kicking out.
              /break
          }

        }
        /varcalc currentLoop ${currentLoop}+1
    }
    /if (${Target.ID}) {
      /face fast id ${Target.ID}
    }
    |delay 0.3 sec for the spells that may come after this method call
    /delay 3
/RETURN

|/delay 4s
|/target 66 NPC
|/target 67 NPC
|/target 68 NPC
|/bcga //nav spawn id ${Target.ID}
|/varset ClearXTargetsOn TRUE
|/varset ClearXStick TRUE


|----------------------------------------------------------------------------|
|- The function "check_Shrink" will shrink you anytime it detects that your
|- height is over the set limit. The function "check_GroupShrink" will shrink
|- you, your group members, and pets anytime it detects that one of them is
|- over the set limit. Neither will cast if you are in PoK. It is recommended
|- that only one of the two be set to "On" at a time.
|- Install Instructions:
|- 		Add these SUB's to the bottom of e3 Includes/e3_Basics.inc
|-		Add the following variables to Sub basics_Setup
|-			/call iniToVarV "${Character_Ini},Auto Shrink,Auto Shrink (On/Off)" autoShrink bool outer
|-			/call IniToArrayV "${Character_Ini},Auto Shrink,Spell Name" shrinkSpell
|-			/call iniToVarV "${Character_Ini},Auto Shrink,Size" shrinkSize float outer
|-			/if (${Defined[shrinkSpell]}) /call BuildSpellArray "shrinkSpell" "shrinkSpell2D"
|-
|-			/call iniToVarV "${Character_Ini},Auto Shrink,Auto Shrink Group (On/Off)" autoShrinkGroup bool outer
|-			/call IniToArrayV "${Character_Ini},Auto Shrink,Group Spell Name" groupShrinkSpell
|-			/call iniToVarV "${Character_Ini},Auto Shrink,Size" shrinkSizeGroup float outer
|-			/if (${Defined[groupShrinkSpell]}) /call BuildSpellArray "groupShrinkSpell" "groupShrinkSpell2D"
|-		Add following to SUB basics_Background_Events
|-			/doevents autoShrinkSelf
|-			/doevents autoShrinkGroup
|-		Add subroutine check for the appropriate classes
|-		in e3 Macro Inis/Advanced Settings.ini
|-			ex: SHM Function#13=check_Shrink
|-			ex: SHM Function#14=check_GroupShrink
|-		Add settings to your character.ini
|-			[Auto Shrink]
|-			Auto Shrink (On/Off)=Off
|-			Auto Shrink Group (On/Off)=On
|-			Spell Name=Shrink
|-			Group Spell Name=Group Shrink
|-			Size=1.88
|----------------------------------------------------------------------------|
#event autoShrinkSelf "#1# tells you, 'shrink self toggle'"
#event autoShrinkSelf "<#1#> shrink self toggle"
#event autoShrinkSelf "#1# tells the group, 'shrink self toggle'"
SUB event_autoShrinkSelf(line, ChatSender)
	/if (!${Defined[shrinkSpell]}) /return

	/if (${autoShrink}) {
		/varset autoShrink FALSE
	} else {
		/varset autoShrink TRUE
	}

	/if (${autoShrink}) {
		/docommand ${ChatToggle} ${Me}: Auto Shrink Self On
	} else {
		/docommand ${ChatToggle} ${Me}: Auto Shrink Self Off
	}
/return

#event autoShrinkGroup "#1# tells you, 'shrink group toggle'"
#event autoShrinkGroup "<#1#> shrink group toggle"
#event autoShrinkGroup "#1# tells the group, 'shrink group toggle'"
SUB event_autoShrinkGroup(line, ChatSender)
	/if (!${Defined[groupShrinkSpell]}) /return

	/if (${autoShrinkGroup}) {
		/varset autoShrinkGroup FALSE
	} else {
		/varset autoShrinkGroup TRUE
	}

	/if (${autoShrinkGroup}) {
		/docommand ${ChatToggle} ${Me}: Auto Shrink Group On
	} else {
		/docommand ${ChatToggle} ${Me}: Auto Shrink Group Off
	}
/return

SUB check_Shrink
	/if (!${Defined[shrinkSpell]}) /return

	/if (${autoShrink} && !${Me.Combat} && !${Me.Moving}) {
		/call check_Ready "shrinkSpell2D" 1
		/if (${c_Ready} && (${Me.Height} > ${shrinkSize})) {
			/call e3_Cast ${Me.ID} "shrinkSpell2D" 1
		}
	}
/return

SUB check_GroupShrink
	/if (!${Defined[groupShrinkSpell]}) /return

	/if (${Group.Members} > 0 && ${autoShrinkGroup} && !${Me.Combat} && !${Me.Moving}) {
		/declare i int local 1
		/declare g int local
		/for g 0 to ${Group.Members} {
			/call check_Ready "groupShrinkSpell2D" ${i}
			|/if (${c_Ready} && (${Group.Member[${g}].Height} > ${shrinkSizeGroup}) && ${check_Distance[${Group.Member[${g}].ID},${${groupShrinkSpell2D}[${i},${iMyRange}]}]}) {
      /if (${c_Ready} && (${Group.Member[${g}].Height} > ${shrinkSizeGroup}) && ${check_Distance[${Group.Member[${g}].ID},175]}) {
				/call e3_Cast ${Group.Member[${g}].ID} "groupShrinkSpell2D" ${i}
			}

			/if (${Group.Member[${g}].Pet.ID} && ${c_Ready} && (${Group.Member[${g}].Pet.Height} > ${shrinkSizeGroup}) && ${check_Distance[${Group.Member[${g}].Pet.ID},${${groupShrinkSpell2D}[${i},${iMyRange}]}]}) {
				/call e3_Cast ${Group.Member[${g}].Pet.ID} "groupShrinkSpell2D" ${i}
			}
		}
		/next g
	}
/return


SUB check_HCUR
  /if (${Me.Class.ShortName.Equal[SHM]} && ${Bool[${Me.SpellInCooldown}]}) {
    /while (${Bool[${Me.SpellInCooldown}]}) {
      /delay 1
    }
  }
  /if (${Me.Class.ShortName.Equal[RNG]} && ${Bool[${Me.SpellInCooldown}]}) {
    /while (${Bool[${Me.SpellInCooldown}]}) {
      /delay 1
    }
  }
  /if (${Assisting} && ${Me.SpellReady[Abashi's Disempowerment]} && (${Target.Buff[Regeneration].ID} || ${Target.Buff[Scream of Hate Recourse].ID} || ${Target.Buff[Bond of Death Recourse].ID} || ${Target.Buff[Terror Leech Recourse].ID} || ${Target.Buff[Valor of Marr].ID})) {
    /cast ${Me.Gem[Abashi's Disempowerment]}
  }
  /if (${Assisting} && ${Me.SpellReady[Abashi's Disempowerment]} && (${Target.Buff[Regeneration].ID} || ${Target.Buff[Scream of Hate Recourse].ID} || ${Target.Buff[Bond of Death Recourse].ID} || ${Target.Buff[Terror Leech Recourse].ID} || ${Target.Buff[Valor of Marr].ID})) {
    /cast ${Me.Gem[Nature's Balance]}
  }
  /if (${Assisting} && ${Me.ItemReady[Abashi's Rod of Disempowerment]} && (${Target.Buff[Regeneration].ID} || ${Target.Buff[Scream of Hate Recourse].ID} || ${Target.Buff[Bond of Death Recourse].ID} || ${Target.Buff[Terror Leech Recourse].ID} || ${Target.Buff[Valor of Marr].ID})) {
    /useitem "Abashi's Rod of Disempowerment"
    ;/if ${Me.Casting}
    /delay 4s
  }
/RETURN
