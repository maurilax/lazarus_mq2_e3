@echo off
tasklist /nh /fi "IMAGENAME eq MacroQuest2.exe" | find /i "MacroQuest2.exe" > nul ||(start /d "C:\RoF2\E3_RoF2" C:\RoF2\E3_RoF2\MacroQuest2.exe)
tasklist /nh /fi " WINDOWTITLE eq C:\RoF2\E3_RoF2\EQBCServer.exe" | find /i "EQBCServer.exe" > nul ||(start C:\RoF2\E3_RoF2\EQBCServer.exe)
REM tasklist /nh /fi " IMAGENAME eq GamParse-2.0.0-Beta.exe" | find /i "GamParse-2.0.0-Beta.exe" > nul ||(start C:\RoF2\E3_RoF2\Creamo_Utilities\GameParse\GamParse-2.0.0-Beta.exe)
REM tasklist /nh /fi " IMAGENAME eq GamParse-1.5.1.7.exe" | find /i "GamParse-1.5.1.7.exe" > nul ||(start C:\RoF2\E3_RoF2\Creamo_Utilities\GameParse\GamParse-1.5.1.7.exe)
REM C:\Users\Joe\AppData\Local\atom\atom.exe

tasklist /nh /fi "WINDOWTITLE eq Mintman" | find /i "eqgame.exe" > nul ||(start "Mintman" /High /d "C:\RoF2WAR" "C:\RoF2WAR\eqgame.exe" patchme /Login:maurilax) && (timeout /t 8)
REM tasklist /nh /fi "WINDOWTITLE eq Mintbank" | find /i "eqgame.exe" > nul ||(start "Mintbank" /High /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:maurilax13) && (timeout /t 8)
REM tasklist /nh /fi "WINDOWTITLE eq Mintfu" | find /i "eqgame.exe" > nul ||(start "Mintfu" /High /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:maurilax5) && (timeout /t 8)
REM tasklist /nh /fi "WINDOWTITLE eq Mintsong" | find /i "eqgame.exe" > nul ||(start "Mintsong" /High /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:maurilax9) && (timeout /t 8)
