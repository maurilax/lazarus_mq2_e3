@echo off
tasklist /nh /fi "IMAGENAME eq MacroQuest2.exe" | find /i "MacroQuest2.exe" > nul ||(start /d "C:\RoF2\E3_RoF2" C:\RoF2\E3_RoF2\MacroQuest2.exe)
tasklist /nh /fi " WINDOWTITLE eq C:\RoF2\E3_RoF2\EQBCServer.exe" | find /i "EQBCServer.exe" > nul ||(start C:\RoF2\E3_RoF2\EQBCServer.exe)
REM tasklist /nh /fi " IMAGENAME eq GamParse-2.0.0-Beta.exe" | find /i "GamParse-2.0.0-Beta.exe" > nul ||(start C:\RoF2\E3_RoF2\Creamo_Utilities\GameParse\GamParse-2.0.0-Beta.exe)
REM tasklist /nh /fi " IMAGENAME eq GamParse-1.5.1.7.exe" | find /i "GamParse-1.5.1.7.exe" > nul ||(start C:\RoF2\E3_RoF2\Creamo_Utilities\GameParse\GamParse-1.5.1.7.exe)
REM C:\Users\Joe\AppData\Local\atom\atom.exe

tasklist /nh /fi "WINDOWTITLE eq Minty" | find /i "eqgame.exe" > nul ||(start "Minty" /High /Affinity 0x2 /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:maurilax2) && (timeout /t 8)
tasklist /nh /fi "WINDOWTITLE eq Mintsawce" | find /i "eqgame.exe" > nul ||(start "Mintsawce" /High /Affinity 0x4 /d "C:\RoF2ENC" "C:\RoF2ENC\eqgame.exe" patchme /Login:maurilax3) && (timeout /t 8)
tasklist /nh /fi "WINDOWTITLE eq Mintfatterson" | find /i "eqgame.exe" > nul ||(start "Mintfatterson" /High /Affinity 0x4 /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:maurilax4) && (timeout /t 8)
tasklist /nh /fi "WINDOWTITLE eq Mintfu" | find /i "eqgame.exe" > nul ||(start "Mintfu" /High /Affinity 0x8 /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:maurilax5) && (timeout /t 8)
tasklist /nh /fi "WINDOWTITLE eq Mintstab" | find /i "eqgame.exe" > nul ||(start "Mintstab" /High /Affinity 0x8 /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:maurilax6) && (timeout /t 8)
tasklist /nh /fi "WINDOWTITLE eq Tusea" | find /i "eqgame.exe" > nul ||(start "Tusea" /High /Affinity 0x8 /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:146290) && (timeout /t 8)
REM tasklist /nh /fi "WINDOWTITLE eq Mintmage" | find /i "eqgame.exe" > nul ||(start "Mintmage" /High /Affinity 0x8 /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:maurilax7) && (timeout /t 8)
tasklist /nh /fi "WINDOWTITLE eq Mintsong" | find /i "eqgame.exe" > nul ||(start "Mintsong" /High /Affinity 0x2 /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:maurilax9) && (timeout /t 8)
tasklist /nh /fi "WINDOWTITLE eq Mintbank" | find /i "eqgame.exe" > nul ||(start "Mintbank" /High /Affinity 0x2 /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:maurilax13) && (timeout /t 8)
tasklist /nh /fi "WINDOWTITLE eq Mintman" | find /i "eqgame.exe" > nul ||(start "Mintman" /High /Affinity 0x2 /d "C:\RoF2WAR" "C:\RoF2WAR\eqgame.exe" patchme /Login:maurilax) && (timeout /t 8)
REM tasklist /nh /fi "WINDOWTITLE eq Laeret" | find /i "eqgame.exe" > nul ||(start "Laeret" /High /Affinity 0x8 /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:462902) && (timeout /t 8)
REM tasklist /nh /fi "WINDOWTITLE eq Resheo" | find /i "eqgame.exe" > nul ||(start "Resheo" /High /Affinity 0x8 /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:462901) && (timeout /t 8)
REM tasklist /nh /fi "WINDOWTITLE eq Verdant" | find /i "eqgame.exe" > nul ||(start "Resheo" /High /Affinity 0x8 /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:46290dru) && (timeout /t 8)
REM tasklist /nh /fi "WINDOWTITLE eq Remarkable" | find /i "eqgame.exe" > nul ||(start "Remarkable" /High /Affinity 0x8 /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:dazzle01) && (timeout /t 8)
REM tasklist /nh /fi "WINDOWTITLE eq Mintzerker" | find /i "eqgame.exe" > nul ||(start "Mintzerker" /High /Affinity 0x8 /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:maurilax8) && (timeout /t 8)
REM tasklist /nh /fi "WINDOWTITLE eq Moshend" | find /i "eqgame.exe" > nul ||(start "Moshend" /High /Affinity 0x8 /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:samadcit4) && (timeout /t 8)
REM tasklist /nh /fi "WINDOWTITLE eq Oversanai" | find /i "eqgame.exe" > nul ||(start "Remarkable" /High /Affinity 0x8 /d "C:\RoF2" "C:\RoF2\eqgame.exe" patchme /Login:samadcit2) && (timeout /t 8)