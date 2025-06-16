#include QMK_KEYBOARD_H
#include "keymap_norwegian.h" 


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
  _BEAKL,
  _LOWER,
  _RAISE,
  _ADJUST,
  _GAME,
  _GAMERAISE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define GAMERAISE MO(_GAMERAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* keys with a / in them, like SPC/sft are two keys. First key when tapped, second key when held for 120ms. 
      * beakl43, norwegian layout.
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐                   ┌─────┬─────┬─────┬─────┬─────┬───────┐
     * │ Tab │  Q  │   H │   O │   U │   , │                   │  G  │  L  │  R  │  F  │  B  │  ESC  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │ CTRL│  J  │   I │   E │   A │  Y  │                   │  D  │  T  │  S  │  N  │  P  │ -     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                   ├─────┼─────┼─────┼─────┼─────┼───────┤
     * │ Sft │  X  │  K  │  Å  │  .  │ '   │                   │  V  │  M  │  C  │  W  │  Z  │Ent/sft│
     * └─────┴─────┴─────┼─────┼─────┼─────┤────────┐    ┌─────├─────┼─────┼─────┴─────┴─────┴───────┘
     *                         │ Alt │Lower│ SPC/sft│    │BSPC │Raise│ Ctl │
     *                         └─────┴─────┴────────┘    └─────┴─────┴─────┘ 
     */
[_BEAKL] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   LOWER,
  KC_TAB,  KC_Q,    KC_H,    KC_O,    KC_U,    KC_COMM,                                      KC_G,    KC_L,    KC_R,    KC_F,    KC_B,   LOWER,
  KC_ESC,  KC_J,    KC_I,    KC_E,    KC_A,    KC_Y,                                         KC_D,    KC_T,    KC_S,    KC_N,    KC_P,   NO_MINS,
  KC_LSFT, KC_X,    KC_K,    NO_ARNG, KC_DOT,  NO_QUOT,                                      KC_V,    KC_M,    KC_C,    KC_W,    KC_Z,   MT(MOD_LSFT, KC_ENTER),
  KC_LCTL, KC_LGUI, NO_MICR,   KC_LALT, LOWER,   KC_SPC,  KC_BSPC, RAISE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |     |    \  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT(
  KC_TILD,         KC_EXLM,           NO_AT,          KC_HASH,        NO_DLR,           KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,       KC_RPRN,       KC_BSPC,
  KC_TRANSPARENT,  KC_TRANSPARENT,    LGUI(KC_DOT),   KC_TRANSPARENT, LCTL(KC_L),       LGUI(KC_TAB),   KC_TRANSPARENT, NO_QUES,        KC_TRANSPARENT, NO_LPRN,       NO_RPRN,       NO_SLSH,
  KC_TRANSPARENT,  LCTL(KC_A),        LCTL(KC_S),     LGUI(KC_E),     LGUI(LSFT(KC_S)), LSFT(KC_F10),   KC_TRANSPARENT, NO_AE,          NO_OSTR,        NO_LBRC,       NO_RBRC,       NO_BSLS,
  KC_TRANSPARENT,  LCTL(KC_Z),        LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),       LGUI(KC_V),     NO_MICR,        NO_LABK,        NO_RABK,        NO_LCBR,       NO_RCBR,       NO_PIPE,
  KC_TRANSPARENT,  KC_TRANSPARENT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MPRV,        KC_MSTP,       KC_MPLY,       KC_MNXT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  NO_GRV,         KC_EXLM,        NO_AT,          KC_HASH,        NO_DLR,         KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_TRANSPARENT,
  KC_DEL,         KC_4,           KC_2,           KC_3,           KC_1,           KC_5,           KC_6,           KC_0,           KC_8,           KC_9,           KC_7,           KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_SCLN,        KC_COMM,        NO_PLUS,        NO_DQUO,        KC_TRANSPARENT, NO_EQL,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|Sat Up|Sat Dn|Val Up|Val Dn|      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT(
  KC_F1,                 KC_F2,          KC_F3,          KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_F1,                 KC_F1,          KC_F2,          KC_F3,          KC_F4,             KC_F5,               KC_F6,               KC_F7,           KC_F8,          KC_F9,          KC_F10,         KC_F11,
  LALT(LCTL(KC_DELETE)), NO_LABK,        NO_LCBR,        NO_LBRC,        NO_LPRN,        KC_HOME,             KC_END,          KC_RBRC, KC_TRANSPARENT,KC_TRANSPARENT, KC_TRANSPARENT, KC_F12,
  KC_TRANSPARENT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_AUDIO_VOL_UP, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  RGB_TOG,        RGB_MODE_FORWARD, RGB_VAI, KC_TRANSPARENT, KC_TRANSPARENT,    KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT,  KC_TRANSPARENT, QK_BOOTLOADER,  QK_REBOOT,      TG(_GAME)

),
// qwerty based, no lower layout, for gaming. try it out. 
[_GAME] =  LAYOUT(
        KC_GRV, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,              KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS,
        KC_TAB, KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,              KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_BSLS,
        KC_ESC,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,               KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,              KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH, MT(MOD_LSFT, KC_ENTER),
        KC_LCTL, KC_M,  KC_I,  KC_LGUI,KC_LALT,KC_SPC,         KC_BSLS, GAMERAISE, KC_RALT, KC_RGUI, KC_RCTL, KC_BSPC
),
// gaming with raise layer
[_GAMERAISE] = LAYOUT(
        KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,         KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,
        KC_TAB, KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,              KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_BSLS,
        KC_ESC,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,               KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,              KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH, MT(MOD_LSFT, KC_ENTER),
        KC_LCTL, KC_M,  KC_I,  KC_LGUI,KC_LALT,KC_SPC,         KC_BSLS, GAMERAISE, KC_RALT, KC_RGUI, KC_RCTL, TG(_GAME)
      )

};

// combos
// used for ctrl-alt-delete
const uint16_t PROGMEM combo0[] = { KC_E, KC_A, KC_S, KC_T, COMBO_END};
// used for game layer
const uint16_t PROGMEM combo1[] = { KC_G, KC_A, KC_M, KC_E, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
   [0] = COMBO(combo0, LALT(LCTL(KC_DELETE))),
   [1] = COMBO(combo1, TG(_GAME) )
};

// dunno what this does but see it all over
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
