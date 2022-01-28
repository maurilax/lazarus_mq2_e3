@echo off
tasklist /nh /fi "IMAGENAME eq MacroQuest2.exe" | find /i "MacroQuest2.exe" > nul ||(start /d "C:\RoF2\E3_RoF2" C:\RoF2\E3_RoF2\MacroQuest2.exe)
tasklist /nh /fi " WINDOWTITLE eq C:\RoF2\E3_RoF2\EQBCServer.exe" | find /i "EQBCServer.exe" > nul ||(start C:\RoF2\E3_RoF2\EQBCServer.exe)
REM tasklist /nh /fi " IMAGENAME eq GamParse-2.0.0-Beta.exe" | find /i "GamParse-2.0.0-Beta.exe" > nul ||(start C:\RoF2\E3_RoF2\Creamo_Utilities\GameParse\GamParse-2.0.0-Beta.exe)
REM tasklist /nh /fi " IMAGENAME eq GamParse-1.5.1.7.exe" | find /i "GamParse-1.5.1.7.exe" > nul ||(start C:\RoF2\E3_RoF2\Creamo_Utilities\GameParse\GamParse-1.5.1.7.exe)
REM C:\Users\Joe\AppData\Local\atom\atom.exe

REM tasklist /nh /fi "WINDOWTITLE eq Mintheals" | find /i "eqgame.exe" > nul ||(start "Mintheals" /High /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:maurilax10) && (timeout /t 8)
REM tasklist /nh /fi "WINDOWTITLE eq Mintbow" | find /i "eqgame.exe" > nul ||(start "Mintbow" /High /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:maurilax12) && (timeout /t 8)
REM tasklist /nh /fi "WINDOWTITLE eq Mintdeath" | find /i "eqgame.exe" > nul ||(start "Mintdeath" /d "C:\RoF2War" "C:\RoF2War\eqgame.exe" patchme /Login:maurilax11) && (timeout /t 8)
REM tasklist /nh /fi "WINDOWTITLE eq Mintpal" | find /i "eqgame.exe" > nul ||(start "Mintpal" /d "C:\RoF2War" "C:\RoF2War\eqgame.exe" patchme /Login:maurilax15) && (timeout /t 8)
REM tasklist /nh /fi "WINDOWTITLE eq Mintshamwow" | find /i "eqgame.exe" > nul ||(start "Mintshamwow" /High /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:maurilax22) && (timeout /t 8)
REM tasklist /nh /fi "WINDOWTITLE eq Mintzerker" | find /i "eqgame.exe" > nul ||(start "Mintzerker" /High /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:maurilax8) && (timeout /t 8)
REM tasklist /nh /fi "WINDOWTITLE eq Minttunez" | find /i "eqgame.exe" > nul ||(start "Minttunez" /High /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:maurilax14) && (timeout /t 8)
REM tasklist /nh /fi "WINDOWTITLE eq Mintboomboom" | find /i "eqgame.exe" > nul ||(start "Mintboomboom" /High /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:maurilax20) && (timeout /t 8)
REM tasklist /nh /fi "WINDOWTITLE eq Mintnaturelover" | find /i "eqgame.exe" > nul ||(start "Mintnaturelover" /High /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:maurilax21) && (timeout /t 8)
REM tasklist /nh /fi "WINDOWTITLE eq Mintmage" | find /i "eqgame.exe" > nul ||(start "Mintmage" /High /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:maurilax7) && (timeout /t 8)
