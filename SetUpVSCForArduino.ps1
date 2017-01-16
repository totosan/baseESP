$listOfInstalledSW=Get-ItemProperty HKLM:\Software\Wow6432Node\Microsoft\Windows\CurrentVersion\Uninstall\* | Select-Object DisplayName, DisplayVersion, Publisher, InstallDate | Format-Table –AutoSize

if($(Test-Path "VisualStudioCodeArduino") -eq $false){
    git clone https://github.com/fabienroyer/VisualStudioCodeArduino.git
}
$vscode = "$($env:USERPROFILE)\.vscode\extensions"
Copy-Item ".\VisualStudioCodeArduino\ino" $vscode -Recurse -Force
if($(test-path ".vscode") -eq $false){
    New-Item -Name ".vscode" -ItemType Directory
}
Copy-Item ".\VisualStudioCodeArduino\tasks.json" ".\.vscode"