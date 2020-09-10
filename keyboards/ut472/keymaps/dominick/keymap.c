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
    _FUNCTION,
};

enum custom_keycodes {
  PWD1P = SAFE_RANGE,
  PWDAA,
  PWDME,
  LT3_TAB
};



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

LAYOUT(
  KC_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  LT3_TAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_APP, KC_LGUI, KC_LALT,  MO(1),      KC_SPC,     KC_QUOT,      MO(2), KC_MINS,  KC_EQL, KC_BSLS
),



  /* FN Layer 1
   * ,-------------------------------------------------------------------------.
   * |  Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  | Delete|
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |  [  |  ]  |  +  |  =  |      |
   * |-------------------------------------------------------------------------+
   * |       | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |Capsl|      |          |       | Home| PgDn| PgUp| End |
   * `-------------------------------------------------------------------------'
   */

LAYOUT( /* Left */
  KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DELETE,
  _______, RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, _______, _______, KC_LCBR, KC_RCBR, _______, _______, _______,
  _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,
  _______, _______, _______, KC_CAPS, _______,     KC_BSPC,      _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),



  /* FN Layer 2
   * ,-------------------------------------------------------------------------.
   * |  Esc |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |Delete|
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |  {  |  }  |     |     |      |
   * |-------------------------------------------------------------------------+
   * |       | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |Capsl|      |          |       | Home| PgDn| PgUp| End |
   * `-------------------------------------------------------------------------'
   */

LAYOUT( /* Right */
  KC_GESC,  KC_EXCLAIM,  KC_AT,  KC_HASH,  KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_DELETE,
  _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_PLUS, KC_EQL,   _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, _______, _______, _______, KC_ENT,     KC_BSPC,     KC_MPLY, _______, KC_VOLD, KC_VOLU, KC_MUTE

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

[_FUNCTION] = LAYOUT( /* Tab */
  KC_GRV,  _______, KC_UP, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, KC_PSCR, RESET,
  _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, KC_LCBR, KC_RCBR, _______, RGB_MOD, RGB_TOG,
  KC_CAPS, _______, _______,  PWDME, PWDAA, PWD1P, _______, _______, _______, _______, _______, _______,
  _______, _______, _______,  _______, KC_ENT,     KC_BSPC,  _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),
};


static bool fn_down = false;
static bool mod_down = false;
static uint16_t prev_keydown = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if(record->event.pressed) {
    prev_keydown = keycode;
  }

  switch (keycode) {
    case KC_LGUI:
    case KC_LALT:
      if(record->event.pressed) {
        mod_down = true;
      } else {
        mod_down = false;
      }
      break;

    case LT3_TAB:
      // if modifier down, treat as tab
      if(mod_down) {
        if(record->event.pressed) {
          register_code(KC_TAB);
        } else {
          unregister_code(KC_TAB);
        }

      // modifier is not down, treat as function
      } else {
        if(record->event.pressed) {
          layer_on(_FUNCTION);
        } else {
          layer_off(_FUNCTION);

          // previous keydown was fn/tab
          if (prev_keydown == LT3_TAB) {
            tap_code(KC_TAB);
            prev_keydown = keycode;
          }
        }
        fn_down = record->event.pressed;
      }
      break;

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
