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
};

enum macro_keycodes {
  SIGN_MU,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BEAKL] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_BSPC,
  KC_TAB,  KC_Q,    KC_H,    KC_O,    KC_U,    KC_X,    KC_G,    KC_C,    KC_M,    KC_R,    KC_V,   KC_BSPC,
  KC_ESC,  KC_Y,    KC_I,    KC_E,    KC_A,    KC_DOT,  KC_D,    KC_S,    KC_T,    KC_N,    KC_B,   NO_MINS,
  KC_LSFT, KC_J,    NO_ARNG, KC_COMM, KC_K,    NO_QUOT, KC_W,    KC_F,    KC_L,    KC_P,    KC_Z,   MT(MOD_LSFT, KC_ENTER),
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
  KC_TRANSPARENT,  LCTL(KC_Z),        LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),       LGUI(KC_V),     SIGN_MU,        KC_LABK,        KC_RABK,        NO_LCBR,       NO_RCBR,       NO_PIPE,
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
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
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
