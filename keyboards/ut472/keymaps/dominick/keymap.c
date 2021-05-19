/* Copyright 2018 Carlos Filoteo
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
#include "shared.h"

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  PWD1P,
  PWDAA,
  PWDME,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define CTLTAB MT(MOD_LCTL, KC_TAB)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base Layer
   * ,-------------------------------------------------------------------------.
   * |  `~ |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |Bspace |
   * |-------------------------------------------------------------------------+
   * |Tab/L3|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |   \  |
   * |-------------------------------------------------------------------------+
   * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |Sh/En|
   * |-------------------------------------------------------------------------+
   * | Ctrl| Menu | Gui | Alt |  L2  |   Space   |  L1  | '" | _ |  = | Esc |
   * `-------------------------------------------------------------------------'
   */

[_QWERTY] = LAYOUT(
  KC_GESC, KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  CTLTAB,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_APP, KC_LGUI, KC_LALT, LOWER,      KC_SPC,        RAISE,   KC_BSPC, KC_MINS,  KC_EQL, RGB_TOG
),



  /* FN Layer 1
   * ,-------------------------------------------------------------------------.
   * |  Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  | Delete|
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |  [  |  ]  |  +  |  =  |      |
   * |-------------------------------------------------------------------------+
   * |       | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       | Home| PgDn| PgUp| End |
   * `-------------------------------------------------------------------------'
   */

[_LOWER] = LAYOUT( /* Left */
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_MINS, KC_EQL,  KC_UNDS, KC_PLUS, KC_TILD,
  _______, _______, _______, _______, LOWER,     KC_BSPC,       RAISE, _______,   KC_PGDN, KC_PGUP, KC_END
),



  /* FN Layer 2
   * ,-------------------------------------------------------------------------.
   * |  Esc |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |Delete|
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |  {  |  }  |     |     |      |
   * |-------------------------------------------------------------------------+
   * |       | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       | Home| PgDn| PgUp| End |
   * `-------------------------------------------------------------------------'
   */

[_RAISE] = LAYOUT( /* Right */
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN, KC_BSPC,
  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_QUOT, _______,
  _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,  RGB_TOG, _______,
  _______, _______, _______, _______, LOWER,        KC_BSPC,     RAISE,   KC_VOLD, KC_VOLU,  KC_MPLY, KC_MUTE

),



  /* FN Layer 3
   * ,-------------------------------------------------------------------------.
   * | Esc  |      |  Up  |       |     |     |     |     |     |     |PrtSc| RESET |
   * |-------------------------------------------------------------------------+
   * |      | Left | Down | Right |     |     |     |     |     |     | RGB Cycle| RGB Toggle|
   * |-------------------------------------------------------------------------+
   * |       |     |      |       |     |     |     |     |     |     |     |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       | Play/Pause | Vol Up | Vol Down | Media Next|
   * `-------------------------------------------------------------------------'
   */

[_ADJUST] = LAYOUT( /* Tab */
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_CAPS, _______, _______, PWDME,   PWDAA,   PWD1P,   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, LOWER,       KC_BSPC,      RAISE,   KC_HOME, KC_PGDN, KC_PGUP, KC_END
),
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
        SEND_STRING(CPWD1P SS_TAP(X_ENT));
      }
      break;

    case PWDAA:
      if (record->event.pressed) {
        SEND_STRING(CPWDAA SS_TAP(X_ENT));
      }
      break;

    case PWDME:
      if (record->event.pressed) {
        SEND_STRING(CPWDME);
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
