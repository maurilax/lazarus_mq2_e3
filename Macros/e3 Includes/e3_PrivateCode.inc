|----------------------------------------------------|
|- Uses Manastone                                   -|
|----------------------------------------------------|
SUB check_Manastone
    /if (${Debug}) /echo |- check_Manastone ==>

    /declare i int local 0
    /declare minMana int local 35
    /declare minHP int local 60
    /declare maxMana int local 95
    /declare maxLoop int local 10
    /declare currentLoop int local 1
    |bare min mana you decide you need that you want to exit for a heal.
    /declare minManaToTryAndHeal int local 1000
    |chance this if your having connectivity issues
    /declare totalNumberOfClicksToTry int local 90

    /if (${Me.Combat} || ${Me.CombatState.Equal[Combat]} ||  ${AssistTarget} >0 ) {
        |Values for when in combat
        /varset minMana 85
        /varset maxMana 95
    } else {
        |Values for when out of combat
        /varset minMana 85
        /varset maxMana 95
    }


    /if (!${Bool[${FindItem[=Manastone]}]}) /return
    /if (${Me.PctMana} > ${minMana}) /return
    /if (${Me.Invis}) /return
    /if (${Zone.ShortName.Equal[poknowledge]}) /return
    |/if (${Bool[${Me.Song[Gift of Mana].ID}]} || ${Bool[${Me.Song[Celestial Gift].ID}]} || ${Bool[${Me.Song[Celestial Boon].ID}]}) /return
    |/if (${Bool[${Me.Buff[Twincast].ID}]}) /return


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
    |delay 0.3 sec for the spells that may come after this method call
    /delay 3
/RETURN
