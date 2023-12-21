ROOT_DIR="$(dirname "$(realpath "$0")")"
ROOT_DIR="$(dirname "$ROOT_DIR")"

CONF="$ROOT_DIR/pacMan/conf/"
# NASM="$ROOT_DIR/code/nasm.exe"  
NASM="/opt/homebrew/bin/nasm"
BIN_DIR="$ROOT_DIR/pacMan/bin/"
CONF_DOSBOX="/Users/pierregorin/Library/Preferences/DOSBox 0.74-3 Preferences"
DOSBOX_BIN="/opt/homebrew/Cellar/dosbox/0.74-3_1/bin/dosbox"

"$NASM" "$ROOT_DIR/pacMan/pacman.asm" -f bin -o "$BIN_DIR/pacman.com"

# "$DOSBOX_BIN" -c "config -set 'sdl fullscreen=true'" -c "config -writeconf $CONF/dosbox-0.74-3.conf" -c "exit"

# cp "$CONF/dosbox-0.74-3.conf" "$CONF_DOSBOX"

"$DOSBOX_BIN" -c "keyb fr189" -c "MOUNT c $BIN_DIR" -c "c:" -c "pacman.com"