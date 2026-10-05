#!/bin/bash

DICE_DIR="$(cd "$(dirname "$0")/src/display/assets/dice" && pwd)"

cd "$DICE_DIR" || exit 1

echo "$DICE_DIR"

for file in *.svg; do
    [ -e "$DICE_DIR/$file" ] || continue

    output="$DICE_DIR/${file%.svg}.png"

    if [ ! -f "$output" ]; then
        echo "Conversion de $file vers $output"

        inkscape "$DICE_DIR/$file" \
            --export-type=png \
            --export-width=400 \
            --export-filename="$output"
    else
        echo "$output existe déjà, conversion ignorée"
    fi
done
