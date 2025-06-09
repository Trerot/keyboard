// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
// Missing bottor row on base layer, 

#include QMK_KEYBOARD_H
#include "keymap_norwegian.h" 

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
    /* keys with a / in them, like SPC/sft are two keys. First key when tapped, second key when held for 120ms. 
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐                   ┌─────┬─────┬─────┬─────┬─────┬───────┐
     * │Tab  │  Q  │   H │   O │   U │   , │                   │  G  │  L  │  R  │  F  │  B  │ BSPC  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │Esc  │  J  │   I │   E │   A │  Y  │                   │  D  │  T  │  S  │  N  │  P  │ -     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │Ctl  │  X  │  K  │  Å  │  .  │ '   │                   │  V  │  M  │  C  │  W  │  Z  │Ent/sft│
     * └─────┴─────┴─────┼─────┼─────┼─────┤────────┐    ┌─────├─────┼─────┼─────┴─────┴─────┴───────┘
     *                         │ Alt │Lower│ SPC/sft│    │BSPC │Raise│Lft  │
     *                         └─────┴─────┴────────┘    └─────┴─────┴─────┘ 
     */
    [_BEAKL] = LAYOUT_ortho_4x12(
  KC_TAB,  KC_Q,    KC_H,    KC_O,    KC_U,    KC_COMM,                                      KC_G,    KC_L,    KC_R,    KC_F,    KC_B,   KC_BSPC,
  KC_ESC,  KC_J,    KC_I,    KC_E,    KC_A,    KC_Y,                                         KC_D,    KC_T,    KC_S,    KC_N,    KC_P,   NO_MINS,
  KC_LSFT, KC_X,    KC_K,    NO_ARNG, KC_DOT,  NO_QUOT,                                      KC_V,    KC_M,    KC_C,    KC_W,    KC_Z,   MT(MOD_LSFT, KC_ENTER),
                                      KC_LALT, LOWER,   MT(MOD_LSFT, KC_SPC),       KC_BSPC, RAISE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
    /*  Lower
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐                   ┌─────┬─────┬─────┬─────┬─────┬───────┐
     * │Tab  │  Q  │Gu+. │   O │CTR+L│Wi+tb│                   │ G   │ C   │ M   │ R   │ V   │ BSPC  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │Esc  │Ctl+A│Ctl+S│Win+E│ScrSh│S+F10│                   │ D   │ S   │ T   │ N   │ B   │ -     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │Sft  │Ctl+Z│Ctl+X│Ctl+C│Ctl+V│Win+V│                   │ W   │ F   │ L   │ P   │ Z   │Ent/sft│ (shift when held for 120ms, enter when tapped)
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │Ctl  │Gui  │  NO │ Alt │Lower│ SPC │                   │BSPC │Raise│Lft  │Dwn  │Up   │Rgt    │
     * └─────┴─────┴─────┼─────┼─────┼─────┤────────┐    ┌─────├─────┼─────┼─────┴─────┴─────┴───────┘
     *                         │ Alt │Lower│ SPC/sft│    │CT+bs│Raise│Lft  │
     *                         └─────┴─────┴────────┘    └─────┴─────┴─────┘ 
     */
    [_LOWER] = LAYOUT_ortho_4x12(
  KC_TRANSPARENT,  KC_TRANSPARENT,    LGUI(KC_DOT),   KC_TRANSPARENT, LCTL(KC_L),       LGUI(KC_TAB),   KC_TRANSPARENT, NO_QUES,        KC_TRANSPARENT, NO_LPRN,       NO_RPRN,       NO_SLSH,
  KC_TRANSPARENT,  LCTL(KC_A),        LCTL(KC_S),     LGUI(KC_E),     LGUI(LSFT(KC_S)), LSFT(KC_F10),   KC_TRANSPARENT, NO_AE,          NO_OSTR,        NO_LBRC,       NO_RBRC,       NO_BSLS,
  KC_TRANSPARENT,  LCTL(KC_Z),        LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),       LGUI(KC_V),     SIGN_MU,        NO_LABK,        NO_RABK,        NO_LCBR,       NO_RCBR,       NO_PIPE,
  KC_TRANSPARENT,  KC_TRANSPARENT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MPRV,        KC_MSTP,       KC_MPLY,       KC_MNXT
),
    /*  Raise
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐                   ┌─────┬─────┬─────┬─────┬─────┬───────┐
     * │Tab  │   Q │   H │   O │   U │   X │                   │   G │   C │   M │   R │   V │ BSPC  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │Esc  │   Y │   I │   E │   A │   . │                   │ D   │ S   │ T   │ N   │ B   │ -     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │Sft  │ J   │ ;   │ ,   │ K   │ '   │                   │ W   │ F   │ L   │ P   │ Z   │Ent/sft│ (shift when held for 120ms, enter when tapped)
     * └─────┴─────┴─────┼─────┼─────┼─────┤────────┐    ┌─────├─────┼─────┼─────┴─────┴─────┴───────┘
     *                         │ Alt │Lower│ SPC/sft│    │BSPC │Raise│Lft  │
     *                         └─────┴─────┴────────┘    └─────┴─────┴─────┘ 
     */
    [_RAISE] = LAYOUT_ortho_4x12(
  NO_GRV,         KC_EXLM,        NO_AT,          KC_HASH,        NO_DLR,         KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_TRANSPARENT,
  KC_DEL,         KC_4,           KC_2,           KC_3,           KC_1,           KC_5,           KC_6,           KC_0,           KC_8,           KC_9,           KC_7,           KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_SCLN,        KC_COMM,        NO_PLUS,        NO_DQUO,        KC_TRANSPARENT, NO_EQL,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
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

const uint16_t PROGMEM combo0[] = { KC_E, KC_A, KC_S, KC_T, COMBO_END};

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
