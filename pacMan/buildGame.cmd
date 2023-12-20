@echo off
set "ROOT_DIR=%~dp0"
set "CONF=%ROOT_DIR%\conf"
set "NASM=%ROOT_DIR%\nasm\nasm"
set "BIN_DIR=%ROOT_DIR%\bin"
set "CONF_DOSBOX=%userprofile%\AppData\Local\DOSBox"
set "DOSBOX_BIN=%ProgramFiles(x86)%\DOSBox-0.74-3\DOSBox.exe"

"%NASM%" "%ROOT_DIR%\pacman.asm" -f bin -o "%BIN_DIR%\pacman.com"

"%DOSBOX_BIN%" -c "config -set 'sdl fullscreen=true'" , -c "config -writeconf conf\dosbox-0.74-3.conf" , -c "exit"

cd\
copy "%CONF%\dosbox-0.74-3.conf" "%CONF_DOSBOX%"

"%DOSBOX_BIN%" -c keyb fr189 , -c "MOUNT c %BIN_DIR%" , -c c: , -c pacman.com

exit
