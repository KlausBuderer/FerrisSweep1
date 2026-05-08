#!/usr/bin/env bash
set -euo pipefail

# Compile the Ferris sweep keymap "3_layer_problem".
# Run from anywhere — the script always builds from the repo this file lives in.

REPO_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$REPO_DIR"

KEYBOARD="ferris/sweep"
KEYMAP="3_layer_problem"

qmk config "user.qmk_home=$REPO_DIR" >/dev/null
qmk compile -kb "$KEYBOARD" -km "$KEYMAP"

echo
echo "✓ Built: $REPO_DIR/ferris_sweep_3_layer_problem.hex"
