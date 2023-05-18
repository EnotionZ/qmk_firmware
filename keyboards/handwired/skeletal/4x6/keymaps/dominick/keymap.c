#include QMK_KEYBOARD_H
#include "shared.h"

enum layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _CTRL,
};

enum custom_keycodes {
  PWD1P = SAFE_RANGE,
  PWDAA,
  PWDME,
};

#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define ADJUST  MO(_ADJUST)
#define CTRLMDE TG(_CTRL)
#define GUIBSPC MT(MOD_RGUI, KC_BSPC)
#define CTLSCLN MT(MOD_LCTL, KC_SCLN)
#define CTLTAB  MT(MOD_LCTL, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
      KC_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
      CTLTAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    CTLSCLN, KC_ENT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                        KC_MUTE, LOWER,   KC_SPC,  KC_LGUI,     KC_RALT, GUIBSPC, RAISE,   _______
  ),

  [_LOWER] = LAYOUT(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
      KC_TAB,  _______, _______, KC_ENT,  KC_BTN1, PWD1P,       _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______,
      KC_TRNS, KC_BSPC, KC_DEL,  CTRLMDE, PWDME,   PWDAA,       _______, KC_MINS, KC_EQL,  KC_UNDS, _______, _______,
                        _______, LOWER,   KC_TRNS, _______,     KC_BSPC, KC_TRNS, RAISE,   _______
  ),

  [_RAISE] = LAYOUT(
      KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
      _______, _______, _______, _______, KC_BTN1, _______,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, KC_MUTE,
      _______, _______, _______, _______, _______, _______,     KC_MPRV, KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT, _______,
                        _______, LOWER,   KC_LCTL, _______,     _______, KC_TRNS, RAISE,   _______
  ),

  [_ADJUST] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  RESET,
      _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_INS,  KC_F11,      KC_F12,  KC_PGDN, KC_PGUP, RGB_MOD, _______, _______,
      KC_CAPS, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
                        _______, LOWER,   _______, _______,     _______, _______, RAISE,   _______
  ),

  [_CTRL] = LAYOUT(
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
      KC_TAB,  _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
                        _______, LOWER,   _______, KC_LCTL,     _______, _______, RAISE,   _______
  ),
};

bool isShiftDown = false;
bool isGuiDown = false;

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;
int RGB_current_mode;
void matrix_init_user(void) {
  rgblight_enable();
  rgblight_sethsv(0,255,255);
  rgblight_mode(9);
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  if(IS_LAYER_ON(_LOWER) || IS_LAYER_ON(_RAISE)) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  } else {
    return state;
  }
}

void click(uint16_t mouseBtn, bool pressed) {
  report_mouse_t currentReport = pointing_device_get_report();
  if (pressed) {
    currentReport.buttons |= mouseBtn;
  } else {
    currentReport.buttons &= ~mouseBtn;
  }
  pointing_device_set_report(currentReport);
  pointing_device_send();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool keydown = record->event.pressed;

  switch (keycode) {
    case PWD1P:
      if (keydown) {
        send_string_with_delay_P(PSTR(CPWD1P SS_TAP(X_ENT)), SEND_STR_DELAY);
      }
      break;

    case PWDAA:
      if (keydown) {
        send_string_with_delay_P(PSTR(CPWDAA SS_TAP(X_ENT)), SEND_STR_DELAY);
      }
      break;

    case PWDME:
      if (keydown) {
        send_string_with_delay_P(PSTR(CPWDME), SEND_STR_DELAY);
      }
      break;

    case KC_LSFT:;
    case KC_RSFT:;
      isShiftDown = keydown;
      break;

    case KC_LGUI:;
    case KC_RGUI:;
      isGuiDown = keydown;
      break;

    case KC_BTN1:;
      click(isShiftDown ? MOUSE_BTN2 : MOUSE_BTN1, keydown);
      break;

    case KC_BTN2:;
      click(MOUSE_BTN2, keydown);
      break;

    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (keydown) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
  }

  return true;
}

int pointerDivisor = POINTER_DIVISOR;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (layer_state_is(_LOWER)) {
    // adjust joystick mouse sensitivity
    pointerDivisor += clockwise ? -1 : 1;
    if(pointerDivisor < 1) pointerDivisor = 1;
  } else if (layer_state_is(_RAISE)) {
    // native brightness
    tap_code(clockwise ? KC_BRIGHTNESS_DOWN : KC_BRIGHTNESS_UP);
  } else if(isGuiDown) {
    // OSX screen brightness
    tap_code(!clockwise ? KC_PAUSE : KC_SCROLLLOCK);
  } else {
    // volume control
    tap_code(clockwise ? KC_VOLD : KC_VOLU);
  }
  return true;
}

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
  mouse_report.x = (int) mouse_report.x/pointerDivisor;
  mouse_report.y = (int) mouse_report.y/pointerDivisor;

  if (isShiftDown) {
    mouse_report.x *= POINTER_SHIFT_FACTOR;
    mouse_report.y *= POINTER_SHIFT_FACTOR;
  }

  if (layer_state_is(_LOWER)) {
    // Calculate and accumulate scroll values based on mouse movement and divisors
    scroll_accumulated_h += (float) mouse_report.x / SCROLL_DIVISOR_H;
    scroll_accumulated_v += (float) mouse_report.y / SCROLL_DIVISOR_V;

    // Assign integer parts of accumulated scroll values to the mouse report
    mouse_report.h = (int8_t)scroll_accumulated_h;
    mouse_report.v = (int8_t)scroll_accumulated_v;

    // Update accumulated scroll values by subtracting the integer parts
    scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
    scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

    // Clear the X and Y values of the mouse report
    mouse_report.x = 0;
    mouse_report.y = 0;
  }
  return mouse_report;
}
