#!/usr/bin/env bash
set -euo pipefail

# Compile the Ferris sweep "3_layer_problem" keymap.
#
# Usage:    ./compile.sh           (DO NOT `source` this script)
#
# Default: builds against the vendored QMK at ./qmk_firmware
# Override: QMK_HOME=/path/to/qmk_firmware ./compile.sh

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]:-$0}")" && pwd)"
QMK_HOME="${QMK_HOME:-$SCRIPT_DIR/qmk_firmware}"
KEYMAP_DEST="$QMK_HOME/keyboards/ferris/keymaps/3_layer_problem"

if [[ ! -d "$QMK_HOME/keyboards/ferris/sweep" ]]; then
    echo "✗ QMK firmware not found at: $QMK_HOME" >&2
    echo "  This repo vendors QMK at ./qmk_firmware. If that's missing, restore it" >&2
    echo "  from git or set QMK_HOME=/path/to/qmk_firmware and re-run." >&2
    exit 1
fi

echo "→ Syncing keymap to $KEYMAP_DEST"
mkdir -p "$KEYMAP_DEST"
cp "$SCRIPT_DIR/keymap.c"  "$KEYMAP_DEST/"
cp "$SCRIPT_DIR/rules.mk"  "$KEYMAP_DEST/"

cd "$QMK_HOME"
qmk config "user.qmk_home=$QMK_HOME" >/dev/null
qmk compile -kb ferris/sweep -km 3_layer_problem

cp "$QMK_HOME/ferris_sweep_3_layer_problem.hex" "$SCRIPT_DIR/"
echo
echo "✓ Built: $SCRIPT_DIR/ferris_sweep_3_layer_problem.hex"
