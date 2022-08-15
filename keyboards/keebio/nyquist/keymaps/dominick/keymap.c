/**
 * make keebio/nyquist/rev3:dominick
 * atmega32u4
 */
#include QMK_KEYBOARD_H
#include "shared.h"

enum layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  PWD1P,
  PWDAA,
  PWDME,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define CTLTAB MT(MOD_LCTL, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | GESC   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | \  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab    |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | En |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Sh |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl   | Menu | GUI  | Alt  |Lower |Space |BkSp  |Raise | Home |  End |  Ins | Del |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
  KC_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  CTLTAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_APP,  KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_BSPC, RAISE,   KC_HOME, KC_END,  KC_INS,  KC_DEL
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Ins  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |   [  |   ]  |   -  |   =  | Play |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |   -  |   =  |   _  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Ent |  Del |      |      | LOWER|      |      |RAISE |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_INS,
  KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,  KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______,
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  KC_MINS, KC_EQL,  KC_UNDS, KC_PLUS, _______,
  KC_ENT,  KC_DEL,  _______, _______, LOWER,   _______, _______, RAISE,   _______, KC_SCRL, KC_PAUS, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |  ←   |  ↓   |  ↑   |  →   |  '   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | MUTE | VOLD | VOLU | PLAY |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | LOWER|      |      |RAISE |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, _______,
  _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, _______, _______,
  _______, _______, _______, _______, LOWER,   _______, _______, RAISE,   _______, _______, _______, _______
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |  `   | Togl | SatI | HueI | ValI |      | Pscr | Scrl | Paus |      |      | Reset|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Mode | SatD | HueD | ValD |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | LOWER|      |      |RAISE |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
  _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, _______, KC_PSCR, KC_SCRL, KC_PAUS, _______, _______, RESET,
  _______, RGB_MOD, RGB_SAD, RGB_HUD, RGB_VAD, _______, _______, KC_PGDN, KC_PGUP, _______, _______, _______,
  KC_CAPS, _______, _______, PWDME,   PWDAA,   PWD1P,   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, LOWER,   _______, _______, RAISE,   _______, _______, _______, _______
)
};


layer_state_t layer_state_set_user(layer_state_t state) {
  if(IS_LAYER_ON(_LOWER) || IS_LAYER_ON(_RAISE)) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  } else {
    return state;
  }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {

    case PWD1P:
      if (record->event.pressed) {
        send_string_with_delay_P(PSTR(CPWD1P SS_TAP(X_ENT)), 15);
      }
      break;

    case PWDAA:
      if (record->event.pressed) {
        send_string_with_delay_P(PSTR(CPWDAA SS_TAP(X_ENT)), 30);
      }
      break;

    case PWDME:
      if (record->event.pressed) {
        send_string_with_delay_P(PSTR(CPWDME), 15);
      }
      break;
  }

  return true;
};

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md
void matrix_init_user(void) { // Runs boot tasks for keyboard
  rgblight_enable();
  rgblight_sethsv(0,255,255);
  rgblight_mode(9);
};
