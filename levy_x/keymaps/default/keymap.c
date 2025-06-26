// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_norwegian.h" 

enum layers {
  _BEAKL,
  _LOWER,
  _RAISE,
  _ADJUST,
};


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* keys with a / in them, like SPC/sft are two keys. First key when tapped, second key when held for 120ms. 
      * beakl43, norwegian layout.
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐                   ┌─────┬─────┬─────┬─────┬─────┬───────┐
     * │ Tab │  Q  │   H │   O │   U │   , │                   │  G  │  L  │  R  │  F  │  B  │  ESC  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │ CTRL│  J  │   I │   E │   A │  Y  │                   │  D  │  T  │  S  │  N  │  P  │ -     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │ Sft │  X  │  K  │  Å  │  .  │ '   │                   │  V  │  M  │  C  │  W  │  Z  │Ent/sft│
     * └─────┴─────┴─────┴─────┼─────┼─────┤────────┐    ┌─────├─────┼─────┼─────┴─────┴─────┴───────┘
     *                         │Lower│Space│ ?CTRL? │    │     │BSPC │Raise│
     *                         └─────┴─────┴────────┘    └─────┴─────┴─────┘ 
     */
    [_BEAKL] = LAYOUT_ortho_4x12(
  KC_TAB,  KC_Q,    KC_H,    KC_O,    KC_U,    KC_COMM,                                      KC_G,    KC_L,    KC_R,    KC_F,    KC_B,   KC_ESC,
  KC_LCTL,  KC_J,    KC_I,    KC_E,    KC_A,    KC_Y,                                         KC_D,    KC_T,    KC_S,    KC_N,    KC_P,   NO_MINS,
  KC_LSFT, KC_X,    KC_K,    NO_ARNG, KC_DOT,  NO_QUOT,                                      KC_V,    KC_M,    KC_C,    KC_W,    KC_Z,   MT(MOD_LSFT, KC_ENTER),
  KC_NO, KC_NO, KC_NO,   KC_NO, LOWER,   KC_SPC,  KC_BSPC, RAISE,  KC_NO, KC_NO, KC_NO,  KC_NO
),
    /*  Lower
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐                   ┌─────┬─────┬─────┬─────┬─────┬───────┐
     * │Al+ta│     │Gu+. │c+s+p│CTR+L│Wi+tb│                   │     │ ?   │     │ (   │ )   │   /   │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │     │Ctl+A│Ctl+S│Win+E│ScrSh│S+F10│                   │     │ Æ   │ Ø   │ [   │ ]   │   \   │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │     │Ctl+Z│Ctl+X│Ctl+C│Ctl+V│Win+V│                   │  µ  │ <   │ >   │ {   │ }   │   |   │
     * └─────┴─────┴─────┼─────┼─────┼─────┤────────┐    ┌─────├─────┼─────┼─────┴─────┴─────┴───────┘
     *                         │Lower│Space│        │    │     │BSPC │Raise│
     *                         └─────┴─────┴────────┘    └─────┴─────┴─────┘ 
     */
    [_LOWER] = LAYOUT_ortho_4x12(
  LALT(KC_TAB),    KC_TRANSPARENT,    LGUI(KC_DOT),   LCTL(LSFT(KC_P)), LCTL(KC_L),       LGUI(KC_TAB),   KC_TRANSPARENT, NO_QUES,        KC_TRANSPARENT, NO_LPRN,       NO_RPRN,       NO_SLSH,
  KC_TRANSPARENT,  LCTL(KC_A),        LCTL(KC_S),     LGUI(KC_E),     LGUI(LSFT(KC_S)), LSFT(KC_F10),   KC_TRANSPARENT, NO_AE,          NO_OSTR,        NO_LBRC,       NO_RBRC,       NO_BSLS,
  KC_TRANSPARENT,  LCTL(KC_Z),        LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),       LGUI(KC_V),     NO_MICR,        NO_LABK,        NO_RABK,        NO_LCBR,       NO_RCBR,       NO_PIPE,
  KC_TRANSPARENT,  KC_TRANSPARENT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),
    /*  Raise
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐                   ┌─────┬─────┬─────┬─────┬─────┬───────┐
     * │  `  │   ! │   @ │   # │   $ │   % │                   │   & │Home │PgDwn│ PgUp│ End │       │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │CTRL │   4 │   2 │   3 │   1 │   5 │                   │ 6   │ 0   │ 8   │ 9   │ 7   │       │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │Sft  │ WIN │     │  =  │  +  │  "  │                   │     │ left│ down│ up  │right│       │
     * └─────┴─────┴─────┼─────┼─────┼─────┤────────┐    ┌─────├─────┼─────┼─────┴─────┴─────┴───────┘
     *                         │Lower│Space│        │    │     │BSPC │Raise│
     *                         └─────┴─────┴────────┘    └─────┴─────┴─────┘ 
     */
    [_RAISE] = LAYOUT_ortho_4x12(
  NO_GRV,         KC_EXLM,        NO_AT,          KC_HASH,        NO_DLR,         KC_PERC,        KC_AMPR,        KC_HOME,        KC_PGDN,       KC_PGUP,        KC_END,         KC_TRANSPARENT,
  KC_DEL,         KC_4,           KC_2,           KC_3,           KC_1,           KC_5,           KC_6,           KC_0,           KC_8,           KC_9,           KC_7,           KC_TRANSPARENT,
  KC_TRANSPARENT, KC_LGUI,         KC_TRANSPARENT, KC_EQL,         NO_PLUS,        NO_DQUO,        KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,        KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
    /*  Adjust (Lower + Raise)
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐                   ┌─────┬─────┬─────┬─────┬─────┬───────┐
     * │  `  │  F1 │  F2 │  F3 │  F4 │  F5 │                   │  F6 │  F7 │  F8 │  F9 │ F10 │  F11  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │C+A+D│     │     │     │ Home│Pgdwn│                   │Pgup │ End │     │     │     │  F12  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │ sft │     │     │     │     │     │                   │     │     │     │     │     │       │
     * └─────┴─────┴─────┼─────┼─────┼─────┤────────┐    ┌─────├─────┼─────┼─────┴─────┴─────┴───────┘
     *                         │     │Lower│        │    │     │Raise│     │
     *                         └─────┴─────┴────────┘    └─────┴─────┴─────┘ 
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
const uint16_t PROGMEM combo1[] = { KC_O, KC_U, KC_L, KC_R, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [0] =   COMBO(combo0, LALT(LCTL(KC_DELETE))),
  [1] =   COMBO(combo1, LGUI(KC_L))
};

// macros



// dunno what this does but see it all over
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
