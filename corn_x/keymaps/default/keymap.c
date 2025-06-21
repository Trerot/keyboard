// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
// missing combo for CTRL+ALT+DELETE
// missing combo for bootloader

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
    /*  Base layer
    /* keys with a / in them, like SPC/sft are two keys. First key when tapped, second key when held for 120ms. 
     * ┌─────┬─────┬─────┬─────┬─────┬───────┐                   ┌─────┬─────┬─────┬─────┬─────┬───────┐
     * │ Tab │  Q  │   H │   O │   U │   ,   │                   │  G  │  L  │  R  │  F  │  B  │  ESC  │
     * ├─────┼─────┼─────┼─────┼─────┼───────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │ CTRL│  J  │   I │   E │   A │  Y    │                   │  D  │  T  │  S  │  N  │  P  │ -     │
     * ├─────┼─────┼─────┼─────┼─────┼───────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │     │  X  │  K  │  Å  │  .  │ '     │                   │  V  │  M  │  C  │  W  │  Z  │Ent/sft│
     * └─────┴─────┴─────┼─────┼─────┼───────┤────────┐    ┌─────├─────┼─────┼─────┴─────┴─────┴───────┘
     *                         │lower│  SPC  │  BSPC  |    |Alt  │Sft  │raise│
     *                         └─────┴───────┴────────┘    └─────┴─────┴─────┘ 
     */
    [_BEAKL] = LAYOUT_ortho_4x12(
  KC_TAB,  KC_Q,    KC_H,    KC_O,    KC_U,    KC_COMM,                                      KC_G,    KC_L,    KC_R,    KC_F,    KC_B,   LOWER,
  KC_ESC,  KC_J,    KC_I,    KC_E,    KC_A,    KC_Y,                                         KC_D,    KC_T,    KC_S,    KC_N,    KC_P,   NO_MINS,
  KC_LSFT, KC_X,    KC_K,    NO_ARNG, KC_DOT,  NO_QUOT,                                      KC_V,    KC_M,    KC_C,    KC_W,    KC_Z,   MT(MOD_LSFT, KC_ENTER),
                                      KC_LALT, MT(MOD_LSFT, KC_SPC), LOWER,         RAISE,  KC_BSPC, KC_LEFT
),
    /*  Lower
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐                   ┌─────┬─────┬─────┬─────┬─────┬───────┐
     * │Al+ta│Ctl+W│Gu+. │c+s+p│CTR+L│Wi+tb│                   │     │ ?   │     │ (   │ )   │   /   │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │     │Ctl+A│Ctl+S│Win+E│ScrSh│S+F10│                   │     │ Æ   │ Ø   │ [   │ ]   │   \   │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │     │Ctl+Z│Ctl+X│Ctl+C│Ctl+V│Win+V│                   │  µ  │ <   │ >   │ {   │ }   │   |   │
     * └─────┴─────┴─────┼─────┼─────┼─────┤────────┐    ┌─────├─────┼─────┼─────┴─────┴─────┴───────┘
     *                         │     │Lower│        │    │CT+bs│Raise│     │
     *                         └─────┴─────┴────────┘    └─────┴─────┴─────┘ 
     */
    [_LOWER] = LAYOUT_ortho_4x12(
  KC_TRANSPARENT,  LCTL(KC_W),    LGUI(KC_DOT),   KC_TRANSPARENT, LCTL(KC_L),       LGUI(KC_TAB),   KC_TRANSPARENT, NO_QUES,        KC_TRANSPARENT, NO_LPRN,       NO_RPRN,       NO_SLSH,
  KC_TRANSPARENT,  LCTL(KC_A),        LCTL(KC_S),     LGUI(KC_E),     LGUI(LSFT(KC_S)), LSFT(KC_F10),   KC_TRANSPARENT, NO_AE,          NO_OSTR,        NO_LBRC,       NO_RBRC,       NO_BSLS,
  KC_TRANSPARENT,  LCTL(KC_Z),        LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),       LGUI(KC_V),     NO_MICR,        NO_LABK,        NO_RABK,        NO_LCBR,       NO_RCBR,       NO_PIPE,
  KC_TRANSPARENT,  KC_TRANSPARENT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MPRV,        KC_MSTP,       KC_MPLY,       KC_MNXT
),
    /*  Raise
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐                   ┌─────┬─────┬─────┬─────┬─────┬───────┐
     * │  `  │   ! │   @ │   # │   $ │   % │                   │   & │     |Home │PgDwn│ PgUp│ End   │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │CTRL │   4 │   2 │   3 │   1 │   5 │                   │ 6   │ 0   │ 8   │ 9   │ 7   │       │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │Sft  │  _  │  -  │  =  │  +  │  "  │                   │     │  =  │ left│ down│ up  │ right │
     * └─────┴─────┴─────┼─────┼─────┼─────┤────────┐    ┌─────├─────┼─────┼─────┴─────┴─────┴───────┘
     *                         │ Alt │Lower│sft+ctrl│    │     │Raise│     │
     *                         └─────┴─────┴────────┘    └─────┴─────┴─────┘ 
     */
    [_RAISE] = LAYOUT_ortho_4x12(
  NO_GRV,         KC_EXLM,        NO_AT,          KC_HASH,        NO_DLR,         KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_TRANSPARENT,
  KC_DEL,         KC_4,           KC_2,           KC_3,           KC_1,           KC_5,           KC_6,           KC_0,           KC_8,           KC_9,           KC_7,           KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_SCLN,        KC_COMM,        NO_PLUS,        NO_DQUO,        KC_TRANSPARENT, NO_EQL,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
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

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, LALT(LCTL(KC_DELETE)))
};


// dunno what this does but see it all over
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
