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

#define LT3_TAB LT(3, KC_TAB)




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
  KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  LT3_TAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_BSLS,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
  KC_LCTL, KC_APP, KC_LGUI, KC_LALT,  MO(2),      KC_SPC,        MO(1),  KC_QUOT, KC_MINS, KC_EQL,   KC_GESC
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

LAYOUT( /* Right */
  KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DELETE,
  _______, RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, _______, _______, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_PLUS, KC_EQL, _______,
  _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,
  _______, _______, _______, KC_CAPS, _______,     _______,      _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
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

LAYOUT( /* Left */
  KC_GESC,  KC_EXCLAIM,  KC_AT,  KC_HASH,  KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_DELETE,
  _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_PLUS, KC_EQL,   _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, _______, _______, KC_CAPS, _______,     _______,      _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
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

LAYOUT( /* Tab */
  KC_ESC,  _______, KC_UP, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, RESET,
  _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_TOG,
  _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______,  _______, KC_BSPC,     KC_ENT,       _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT
),
};
