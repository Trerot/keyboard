// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
  _BEAKL,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*  Base layer
     * ┌───┬───┬───┬───┬───┬───┐      ┌───┬───┬───┬───┬───┬───┐
     * │Tab│ Q │ H │ O │ U │ X │      │ G │ C │ M │ R │ V │<--│
     * ├───┼───┼───┼───┼───┼───┤      ├───┼───┼───┼───┼───┼───┤
     * │Esc│ Y │ I │ E │ A │ . │      │ D │ S │ T │ N │ B │ - │
     * ├───┼───┼───┼───┼───┼───┤      ├───┼───┼───┼───┼───┼───┤
     * │Sft│ J │ ; │ , │ K │ ' │      │ W │ F │ L │ P │ Z │ENT│ (shift when held for 120ms, enter when tapped)
     * ├───┼───┼───┼───┼───┼───┤      ├───┼───┼───┼───┼───┼───┤
     * │Ctl│Gui│No │Alt│MO1│Spc│      │Spc│MO2│Lft│Dwn│Up │Rgt│
     * └───┴───┴───┴───┴───┴───┘      └───┴───┴───┴───┴───┴───┘
     */
    [_BEAKL] = LAYOUT_ortho_4x12(
        KC_TAB,  KC_Q,    KC_H,    KC_O,    KC_U,    KC_X,    KC_G,    KC_C,    KC_M,    KC_R,    KC_V,    KC_BSPC,
        KC_ESC,  KC_Y,    KC_I,    KC_E,    KC_A,    KC_DOT,  KC_D,    KC_S,    KC_T,    KC_N,    KC_B,    KC_MINS,
        KC_LSFT, KC_J,    KC_SCLN, KC_COMM, KC_K,    KC_QUOT, KC_W,    KC_F,    KC_L,    KC_P,    KC_Z,    KC_ENT,
        KC_LCTL, KC_LGUI, KC_NO,   KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
        /*  Lower layer
     * ┌───┬───┬───┬───┬───┬───┐      ┌───┬───┬───┬───┬───┬───┐
     * │Tab│ Q │ H │ O │ U │ X │      │ G │ C │ M │ R │ V │<--│
     * ├───┼───┼───┼───┼───┼───┤      ├───┼───┼───┼───┼───┼───┤
     * │Esc│ Y │ I │ E │ A │ . │      │ D │ S │ T │ N │ B │ - │
     * ├───┼───┼───┼───┼───┼───┤      ├───┼───┼───┼───┼───┼───┤
     * │Sft│ J │ ; │ , │ K │ ' │      │ W │ F │ L │ P │ Z │ENT│ (shift when held for 120ms, enter when tapped)
     * ├───┼───┼───┼───┼───┼───┤      ├───┼───┼───┼───┼───┼───┤
     * │Ctl│Gui│No │Alt│MO1│Spc│      │Spc│MO2│Lft│Dwn│Up │Rgt│
     * └───┴───┴───┴───┴───┴───┘      └───┴───┴───┴───┴───┴───┘
     */
        [_LOWER] = LAYOUT_ortho_4x12(
        KC_TAB,  KC_Q,       LGUI(KC_DOT), KC_NO,      LCTL(KC_L), LGUI(KC_TAB), KC_G,       KC_C,       KC_M,       KC_LPRN,    	KC_RPRN,       KC_SLSH,
        KC_ESC,  LCTL(KC_A), LCTL(KC_S),   LGUI(KC_E), KC_A,       KC_DOT,       RALT(KC_Z), RALT(KC_L), RALT(KC_W), KC_LBRC,       KC_RBRC,       KC_BSLS,
        KC_LSFT, LCTL(KC_Z), LCTL(KC_X),   LCTL(KC_C), LCTL(KC_V), LGUI(KC_V),   KC_NO,      KC_LABK,    KC_RABK,    KC_LCBR,       KC_RCBR,       KC_PIPE,
        KC_LCTL, KC_LGUI,    KC_NO,        KC_LALT,    LOWER,      KC_SPC,       KC_SPC,     RAISE,      KC_MPRV,    KC_MSTP,       KC_MPLY,       KC_MNXT
    ),
        /*  Raise layer
     * ┌───┬───┬───┬───┬───┬───┐      ┌───┬───┬───┬───┬───┬───┐
     * │Tab│ Q │ H │ O │ U │ X │      │ G │ C │ M │ R │ V │<--│
     * ├───┼───┼───┼───┼───┼───┤      ├───┼───┼───┼───┼───┼───┤
     * │Esc│ Y │ I │ E │ A │ . │      │ D │ S │ T │ N │ B │ - │
     * ├───┼───┼───┼───┼───┼───┤      ├───┼───┼───┼───┼───┼───┤
     * │Sft│ J │ ; │ , │ K │ ' │      │ W │ F │ L │ P │ Z │ENT│ (shift when held for 120ms, enter when tapped)
     * ├───┼───┼───┼───┼───┼───┤      ├───┼───┼───┼───┼───┼───┤
     * │Ctl│Gui│No │Alt│MO1│Spc│      │Spc│MO2│Lft│Dwn│Up │Rgt│
     * └───┴───┴───┴───┴───┴───┘      └───┴───┴───┴───┴───┴───┘
     */
        [_RAISE] = LAYOUT_ortho_4x12(
        KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_LSFT, KC_J,    KC_SCLN, KC_COMM, KC_PLUS, KC_QUOT, KC_W,    KC_EQL,  KC_L,    KC_P,    KC_Z,    KC_ENT,
        KC_LCTL, KC_LGUI, KC_NO,   KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT
    )
        /*  adjust(lower + raise)
     * ┌───┬───┬───┬───┬───┬───┐      ┌───┬───┬───┬───┬───┬───┐
     * │Tab│ Q │ H │ O │ U │ X │      │ G │ C │ M │ R │ V │<--│
     * ├───┼───┼───┼───┼───┼───┤      ├───┼───┼───┼───┼───┼───┤
     * │Esc│ Y │ I │ E │ A │ . │      │ D │ S │ T │ N │ B │ - │
     * ├───┼───┼───┼───┼───┼───┤      ├───┼───┼───┼───┼───┼───┤
     * │Sft│ J │ ; │ , │ K │ ' │      │ W │ F │ L │ P │ Z │ENT│ (shift when held for 120ms, enter when tapped)
     * ├───┼───┼───┼───┼───┼───┤      ├───┼───┼───┼───┼───┼───┤
     * │Ctl│Gui│No │Alt│MO1│Spc│      │Spc│MO2│Lft│Dwn│Up │Rgt│
     * └───┴───┴───┴───┴───┴───┘      └───┴───┴───┴───┴───┴───┘
     */

    [_ADJUST] =  LAYOUT( 
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
   KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
  _______, _______, _______,   AU_ON,  AU_OFF, AG_NORM, AG_SWAP, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
};