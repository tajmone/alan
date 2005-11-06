; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
AppName=Alan V3 Adventure Language System for Windows
AppVerName=Alan VERSION preview
AppPublisher=ThoNi Adventure Factories
AppPublisherURL=http://www.alanif.se
AppSupportURL=http://www.alanif.se
AppUpdatesURL=http://www.alanif.se
DefaultDirName={pf}\Alan V3 for Windows
DefaultGroupName=Alan V3 for Windows
AllowNoIcons=yes
ChangesAssociations = yes
OutputDir=.
OutputBaseFilename=alanVERSIONsetup

[Registry]
Root: HKCR; Subkey: ".a3c"; ValueType: string; ValueName: ""; ValueData: "AlanV3Game"; Flags: uninsdeletevalue
Root: HKCR; Subkey: "AlanV3Game"; ValueType: string; ValueName: ""; ValueData: "Alan V3 Game"; Flags: uninsdeletekey
Root: HKCR; Subkey: "AlanV3Game\DefaultIcon"; ValueType: string; ValueName: ""; ValueData: "{app}\winarun.exe,0"
Root: HKCR; Subkey: "AlanV3Game\shell\open\command"; ValueType: string; ValueName: ""; ValueData: """{app}\winarun.exe"" ""%1"""
Root: HKCR; Subkey: ".alan"; ValueType: string; ValueName: ""; ValueData: "AlanV3Source"; Flags: uninsdeletevalue
Root: HKCR; Subkey: "AlanV3Source"; ValueType: string; ValueName: ""; ValueData: "Alan V3 Source"; Flags: uninsdeletekey
Root: HKCR; Subkey: "AlanV3Source\DefaultIcon"; ValueType: string; ValueName: ""; ValueData: "{app}\winalan.exe,0"
Root: HKCR; Subkey: "AlanV3Source\shell\edit\command"; ValueType: string; ValueName: ""; ValueData: """notepad.exe"" ""%1"""
Root: HKCR; Subkey: "AlanV3Source\shell\compile\command"; ValueType: string; ValueName: ""; ValueData: """{app}\winalan.exe"" ""%1"""

[Tasks]
; NOTE: The following entry contains English phrases ("Create a desktop icon" and "Additional icons"). You are free to translate them into another language if required.
Name: "desktopicon"; Description: "Create &desktop icons"; GroupDescription: "Additional icons:"
; NOTE: The following entry contains English phrases ("Create a Quick Launch icon" and "Additional icons"). You are free to translate them into another language if required.
Name: "quicklaunchicon"; Description: "Create &Quick Launch icons"; GroupDescription: "Additional icons:"; Flags: unchecked

[Files]
Source: "bin\winalan.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "alan.readme"; DestDir: "{app}"; Flags: ignoreversion
Source: "bin\winarun.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "bin\a2a3.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "converter\a2a3.readme"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\WindowsGLK\Glk.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\WindowsGLK\mppsdk.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "regression\saviour.alan"; DestDir: "{app}"; Flags: ignoreversion
Source: "regression\saviour.a3c"; DestDir: "{app}"; Flags: ignoreversion
Source: "doc\manual\manual.pdf"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\games\adventv3\adventV3.a3c"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[INI]
Filename: "{app}\alan.url"; Section: "InternetShortcut"; Key: "URL"; String: "http://www.alanif.se"

[Icons]
Name: "{group}\Alan V3 Compiler for Windows"; Filename: "{app}\winalan.exe"
Name: "{group}\Alan VERSION ReadMe"; Filename: "{app}\alan.readme"
Name: "{group}\Alan V3 Interpreter for Windows"; Filename: "{app}\winarun.exe"
Name: "{group}\Alan V2 to V3 Source Converter"; Filename: "{app}\a2a3.exe"
Name: "{group}\Alan V2 to V3 Source Converter ReadMe"; Filename: "{app}\a2a3.readme"
; NOTE: The following entry contains an English phrase ("on the Web"). You are free to translate it into another language if required.
Name: "{group}\Alan V3 Manual"; Filename: "{app}\manual.pdf"
Name: "{group}\Alan on the Web"; Filename: "{app}\alan.url"
Name: "{group}\Saviour - a sample game (compile)"; Filename: "{app}\saviour.alan"
Name: "{group}\Saviour - a sample game (run)"; Filename: "{app}\saviour.a3c"
Name: "{group}\Advent - a crude conversion of ADVENT"; Filename: "{app}\adventV3.a3c"
Name: "{group}\Uninstall Alan V3"; Filename: "{uninstallexe}"
; NOTE: The following entry contains an English phrase ("Uninstall"). You are free to translate it into another language if required.
Name: "{userdesktop}\Alan V3 Interpreter for Windows"; Filename: "{app}\winarun.exe"; Tasks: desktopicon
Name: "{userdesktop}\Alan V3 Compiler for Windows"; Filename: "{app}\winalan.exe"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\Alan V3 Interpreter for Windows"; Filename: "{app}\winarun.exe"; Tasks: quicklaunchicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\Alan V3 Compiler for Windows"; Filename: "{app}\winalan.exe"; Tasks: quicklaunchicon

[UninstallDelete]
Type: files; Name: "{app}\saviour.a3c"

