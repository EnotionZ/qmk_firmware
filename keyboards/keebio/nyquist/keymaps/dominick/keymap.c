#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _FUNCTION,
};

#define LT3_TAB LT(3, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | GESC   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | \  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab/L3 |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | En |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Sh |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl   | Menu | GUI  | Alt  |Lower |Space |BkSp  |Raise |  '"  |  _  |   =  | Esc |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
  KC_GESC, KC_Q,   KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_BSLS,
  LT3_TAB, KC_A,   KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_APP, KC_LGUI, KC_LALT, MO(1), KC_SPC, KC_BSPC, MO(2), KC_QUOT, KC_MINS, KC_EQL, KC_GESC
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   [  |   ]  |   -  |   =  | Play |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_LBRC, KC_RBRC, KC_QUOT, KC_DOUBLE_QUOTE,  KC_MPLY,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MUTE
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   [  |   ]  |   +  |   =  | Play |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | Bksp | Enter| Space|      | Next | Vol- | Vol+ | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
  KC_ESC,  KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  _______, _______, _______, _______, _______, _______, _______,  KC_LBRC, KC_RBRC, KC_QUOT,  KC_DOUBLE_QUOTE, KC_MPLY,
  _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, KC_BSPC,  KC_ENT,  KC_SPC,  KC_MNXT, _______, KC_VOLD, KC_VOLU, KC_MUTE
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |  `   |      |  Up  |      |      |      |      |      |      |      | PrtSc|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Left | Down | Right|      |      |      |   [  |   ]  |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |Delete| Bksp | Enter|      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_ortho_4x12(
  KC_GRV,   _______,   KC_UP,  _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_INSERT,
  _______,  KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, KC_LBRC, KC_RBRC, KC_QUOT,  KC_DOUBLE_QUOTE, KC_MPLY,
  KC_CAPS,  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______,    RESET, _______,   KC_DEL, KC_BSPC, KC_ENT,  _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MUTE
)

};
