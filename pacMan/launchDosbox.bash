ROOT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
BIN_DIR="$ROOT_DIR/bin"
DOSBOX_BIN="/opt/homebrew/Cellar/dosbox/0.74-3_1/bin/dosbox"  # Replace with the actual path to DOSBox
CONFIG_LOC="$ROOT_DIR"


"$DOSBOX_BIN" -c "MOUNT c $BIN_DIR" -c "C:" -c "keyb fr120"