/* Copyright 2023 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum custom_keycodes {
    BOOTLOADER = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == BOOTLOADER && record->event.pressed) {
        reset_keyboard();
        return false;
    }
    return true;
}

// Define your combos
const uint16_t PROGMEM boot_combo[] = {KC_A, KC_LEFT, KC_RIGHT, DRAG_SCROLL, COMBO_END};

combo_t key_combos[] = {
    COMBO(boot_combo, BOOTLOADER),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_BTN4,
        KC_BTN5,
        DRAG_SCROLL, // Tap = Middle Click, Hold = Drag Scroll
        KC_BTN2,
        KC_BTN1,
        LT(1,KC_ENTER) // Tap = Enter, Hold = Layer 1
    ),
    [1] = LAYOUT(
        KC_A, // Placeholder for unused keys
        KC_LEFT,
        KC_RIGHT,
        DRAG_SCROLL,
        KC_E,
        KC_F
    )
};
/*
+--------+-------------+--------+--------+
| KC_BTN5| DRAG_SCROLL | KC_BTN2| KC_BTN1|
+--------+-------------+--------+--------+
|                                        |
+--------+                      +--------+
| KC_BTN4|                      | KC_BTN3|
+--------+                      +--------+
   */