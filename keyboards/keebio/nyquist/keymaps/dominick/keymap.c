#include QMK_KEYBOARD_H
#include "shared.h"

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _FUNCTION,
};

enum custom_keycodes {
  PWD = SAFE_RANGE,
  PWDAA,
  LT3_TAB
};

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
  KC_LCTL, KC_APP, KC_LGUI, KC_LALT, MO(1), KC_SPC, KC_BSPC, KC_QUOT, MO(2), KC_MINS, KC_EQL, KC_MPLY
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
  KC_GRV,  KC_1,  KC_2,    KC_3,   KC_4,   KC_5,    KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  _______, KC_F1, KC_F2,   KC_F3,  KC_F4,  KC_F5,   KC_F6,  KC_LCBR, KC_RCBR, _______, _______, _______,
  _______, KC_F7, KC_F8,   KC_F9,  KC_F10, KC_F11,  KC_F12, KC_UNDS, KC_PLUS, _______, _______, _______,
  KC_ENT,  PWD,   PWDAA, _______, _______, KC_ENT, _______, _______, _______, KC_SCROLLLOCK, KC_PAUSE, _______
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
  KC_GRV,  KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  _______, _______, _______, _______, _______, _______, _______,  KC_LBRC, KC_RBRC, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, RGB_HUI,  RGB_SAI, RGB_VAI, RGB_MOD, RGB_TOG, _______,
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
  KC_GRV,   _______,   KC_UP,  _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, KC_PSCR, KC_INSERT,
  _______,  KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, KC_LCBR, KC_RCBR, _______, _______, _______,
  KC_CAPS,  _______, _______,  _______,   PWDAA,     PWD, _______, KC_MINS,  KC_EQL, _______, _______, _______,
  _______,    RESET, _______,   KC_DEL, KC_BSPC,  KC_ENT,  _______, _______, _______, _______, _______, _______
)

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

    case PWD:
      if (record->event.pressed) {
        SEND_STRING(CPWD1P SS_TAP(X_ENT));
      }
      break;

    case PWDAA:
      if (record->event.pressed) {
        SEND_STRING(CPWDAA SS_TAP(X_ENT));
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
