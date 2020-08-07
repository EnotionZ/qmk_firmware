#include QMK_KEYBOARD_H
#include "version.h"
#include "shared.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  PWD1P,
  PWDAA,
  PWDME
};

#define FN MO(SYMB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | GESC   |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   =+   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [   |           |   ]  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | FN     |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  Enter |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  End |  App | LGUI | Ctrl |                                       |  '"  |  -_  |   FN |  Alt | Ctrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Pscr | Ins  |       | Mute |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space| LALT |------|       |------|  RGUI  |BKSPC |
 *                                 |      |      | Del  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GESC,         KC_1,        KC_2,   KC_3,    KC_4,   KC_5,   KC_LEFT,
        KC_TAB,          KC_Q,        KC_W,   KC_E,    KC_R,   KC_T,   KC_LBRC,
        FN,              KC_A,        KC_S,   KC_D,    KC_F,   KC_G,
        KC_LSFT,         CTL_T(KC_Z), KC_X,   KC_C,    KC_V,   KC_B,   ALL_T(KC_NO),
        LT(SYMB,KC_GRV), KC_END,     KC_APP, KC_LGUI, KC_LCTL,
                                                    KC_PSCR,  KC_INS,
                                                             KC_HOME,
                                               KC_SPC,KC_LALT,KC_DEL,
        // right hand
             KC_RGHT,     KC_6,   KC_7,  KC_8,    KC_9,   KC_0,    KC_EQL,
             KC_RBRC,     KC_Y,   KC_U,  KC_I,    KC_O,   KC_P,    KC_BSLS,
                          KC_H,   KC_J,  KC_K,    KC_L,   KC_SCLN, KC_ENT,
             MEH_T(KC_NO),KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                               KC_QUOT,  KC_MINS, FN,     KC_RGUI, KC_RCTL,
             KC_MUTE,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_RALT, KC_BSPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |   Del  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |  UP  |      |      |      |      |           |      |   Up |   [  |   ]  |      | PRINT|  Home  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         | LEFT | DOWN | RIGHT|      |      |------|           |------| Down |   {  |   }  |      |  INS |  End   |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |   &  |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat| RESET|       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Space |
 *                                 | BSPC | ENT  |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_GRV,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F11,
       KC_CAPS,_______,KC_UP,  _______,_______,_______,_______,
       _______,KC_LEFT,KC_DOWN,KC_RIGHT,_______,_______,
       _______,_______,_______,  PWDME,  PWDAA,   PWD1P,_______,
          VRSN,_______,_______,_______,_______,
                                       RGB_MOD, RESET,
                                               _______,
                               KC_BSPC,KC_ENT, _______,
       // right hand
       KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
       _______, KC_UP,   KC_LBRC, KC_RBRC, _______, KC_PSCR, KC_HOME,
                KC_DOWN, KC_LCBR, KC_RCBR, _______, KC_INS,  KC_END,
       _______, KC_AMPR, _______, _______, _______, _______, _______,
                         KC_MUTE, KC_MPLY, _______, KC_VOLU, KC_VOLD,
       RGB_TOG, RGB_SLD,
       _______,
       _______, _______, KC_SPC
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;

    case PWD1P:
      if (record->event.pressed) {
        SEND_STRING(CPWD1P SS_TAP(X_ENT));
      }
      return true;

    case PWDAA:
      if (record->event.pressed) {
        SEND_STRING(CPWDAA SS_TAP(X_ENT));
      }
      return true;

    case PWDME:
      if (record->event.pressed) {
        SEND_STRING(CPWDME);
      }
      return true;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};

