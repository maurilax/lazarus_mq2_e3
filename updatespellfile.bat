@echo on
REM powershell -Command "(New-Object Net.WebClient).DownloadFile('http://www.example.com/package.zip', 'package.zip')"
powershell -Command "Invoke-WebRequest http://192.99.254.193:3000/download/spells -OutFile C:\RoF2\spells_us.zip"
REM powershell Expand-Archive C:\RoF2\spells_us.zip -DestinationPath C:\RoF2 -force
REM powershell Expand-Archive C:\RoF2\spells_us.zip -DestinationPath C:\RoF2Enc -force
powershell Expand-Archive C:\RoF2\spells_us.zip -DestinationPath C:\RoF2War2 -force
pause 