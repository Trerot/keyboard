// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
  _BEAKL,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum macro_keycodes {
  SIGN_MU,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*  Base layer
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐      ┌─────┬─────┬─────┬─────┬─────┬───────┐
     * │Tab  │  Q  │   H │   O │   U │   X │      │   G │   C │   M │   R │   V │ BSPC  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │Esc  │  Y  │   I │   E │   A │   . │      │ D   │ S   │ T   │ N   │ B   │ -     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │Sft  │  J  │  ;  │  ,  │  K  │ '   │      │ W   │ F   │ L   │ P   │ Z   │Ent/sft│ (shift when held for 120ms, enter when tapped)
     * ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │Ctl  │Gui  │  NO │ Alt │Lower│ SPC │      │BSPC │Raise│Lft  │Dwn  │Up   │Rgt    │
     * └─────┴─────┴─────┴─────┴─────┴─────┘      └─────┴─────┴─────┴─────┴─────┴───────┘
     */
    [_BEAKL] = LAYOUT_ortho_4x12(
        KC_TAB,  KC_Q,    KC_H,    KC_O,    KC_U,    KC_X,    KC_G,    KC_C,    KC_M,    KC_R,    KC_V,   KC_BSPC,
        KC_ESC,  KC_Y,    KC_I,    KC_E,    KC_A,    KC_DOT,  KC_D,    KC_S,    KC_T,    KC_N,    KC_B,   KC_MINS,
        KC_LSFT, KC_J,    KC_SCLN, KC_COMM, KC_K,    KC_QUOT, KC_W,    KC_F,    KC_L,    KC_P,    KC_Z,   MT(MOD_LSFT, KC_ENTER),
        KC_LCTL, KC_LGUI, KC_NO,   KC_LALT, LOWER,   KC_SPC,  KC_BSPC, RAISE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    /*  Lower
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐      ┌─────┬─────┬─────┬─────┬─────┬───────┐
     * │Tab  │  Q  │Gu+. │   O │Sft+L│Gu+tb│      │   G │   C │   M │   R │   V │ BSPC  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │Esc  │  Y  │   I │   E │   A │   . │      │ D   │ S   │ T   │ N   │ B   │ -     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │Sft  │ J   │ ;   │ ,   │ K   │ '   │      │ W   │ F   │ L   │ P   │ Z   │Ent/sft│ (shift when held for 120ms, enter when tapped)
     * ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │Ctl  │Gui  │  NO │ Alt │Lower│ SPC │      │BSPC │Raise│Lft  │Dwn  │Up   │Rgt    │
     * └─────┴─────┴─────┴─────┴─────┴─────┘      └─────┴─────┴─────┴─────┴─────┴───────┘
     */
    [_LOWER] = LAYOUT_ortho_4x12(
        KC_TRANSPARENT,  KC_TRANSPARENT,    LGUI(KC_DOT),   KC_TRANSPARENT, LCTL(KC_L),       LGUI(KC_TAB),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LPRN,       KC_RPRN,       KC_SLSH,
        KC_TRANSPARENT,  LCTL(KC_A),        LCTL(KC_S),     LGUI(KC_E),     LGUI(LSFT(KC_S)), LSFT(KC_F10),  RALT(KC_Z),     RALT(KC_L),     RALT(KC_W),     KC_LBRC,       KC_RBRC,       KC_BSLS,
        KC_TRANSPARENT,  LCTL(KC_Z),        LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),       LGUI(KC_V),     SIGN_MU,        KC_LABK,        KC_RABK,        KC_LCBR,       KC_RCBR,       KC_PIPE,
        KC_TRANSPARENT,  KC_TRANSPARENT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,            KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,          KC_MPRV,        KC_MSTP,       KC_MPLY,       KC_MNXT
    ),
    /*  Raise
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐      ┌─────┬─────┬─────┬─────┬─────┬───────┐
     * │Tab  │   Q │   H │   O │   U │   X │      │   G │   C │   M │   R │   V │ BSPC  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │Esc  │   Y │   I │   E │   A │   . │      │ D   │ S   │ T   │ N   │ B   │ -     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │Sft  │ J   │ ;   │ ,   │ K   │ '   │      │ W   │ F   │ L   │ P   │ Z   │Ent/sft│ (shift when held for 120ms, enter when tapped)
     * ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │Ctl  │Gui  │  NO │ Alt │Lower│ SPC │      │BSPC │Raise│Lft  │Dwn  │Up   │Rgt    │
     * └─────┴─────┴─────┴─────┴─────┴─────┘      └─────┴─────┴─────┴─────┴─────┴───────┘
     */
    [_RAISE] = LAYOUT_ortho_4x12(
        KC_GRV,         KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_TRANSPARENT,
        KC_DEL,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_SCLN,        KC_COMM,        KC_PLUS,        KC_TRANSPARENT, KC_TRANSPARENT, KC_EQL,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
    /*  Adjust
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐      ┌─────┬─────┬─────┬─────┬─────┬───────┐
     * │Tab  │   Q │   H │   O │   U │   X │      │   G │   C │   M │   R │   V │ BSPC  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │Esc  │   Y │   I │   E │   A │   . │      │ D   │ S   │ T   │ N   │ B   │ -     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │Sft  │ J   │ ;   │ ,   │ K   │ '   │      │ W   │ F   │ L   │ P   │ Z   │Ent/sft│ (shift when held for 120ms, enter when tapped)
     * ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │Ctl  │Gui  │  NO │ Alt │Lower│ SPC │      │BSPC │Raise│Lft  │Dwn  │Up   │Rgt    │
     * └─────┴─────┴─────┴─────┴─────┴─────┘      └─────┴─────┴─────┴─────┴─────┴───────┘
     */

    [_ADJUST] =  LAYOUT_ortho_4x12( 
    KC_F1,                 KC_F1,          KC_F2,          KC_F3,          KC_F4,             KC_F5,               KC_F6,               KC_F7,           KC_F8,          KC_F9,          KC_F10,         KC_F11,
    LALT(LCTL(KC_DELETE)), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME,           KC_PAGE_DOWN,        KC_PGUP,             KC_END,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F12,
    KC_TRANSPARENT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_AUDIO_VOL_UP, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,    KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT,  KC_TRANSPARENT, QK_BOOTLOADER,  QK_REBOOT,      KC_TRANSPARENT

)

};

// combos

const uint16_t PROGMEM combo0[] = { KC_E, KC_A, KC_S, KC_T};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, LALT(LCTL(KC_DELETE)))
};

// macros

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
switch (keycode) {
    case SIGN_MU:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_1) ));
    }
    break;

}
return true;
}

// dunno what this does but see it all over
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
