#include QMK_KEYBOARD_H
#include "joystick.h"
#include "analog.h"
#include "shared.h"

enum layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  PWD1P = SAFE_RANGE,
  PWDAA,
  PWDME,
  PWDEV,
  TD_LWRC,
};

#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define ADJUST  MO(_ADJUST)
#define GUIBSPC MT(MOD_RGUI, KC_BSPC)
#define CTLTAB  MT(MOD_LCTL, KC_TAB)
#define MIN_ALT MT(MOD_RALT, KC_MINS)
#define KC_BALT MT(MOD_RALT, KC_B)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
      KC_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,  KC_BSLS,
      CTLTAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_BALT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
      KC_LALT, KC_LGUI,          TD_LWRC, KC_SPC,                        GUIBSPC, RAISE,                     KC_RALT, KC_RGUI
  ),

  [_LOWER] = LAYOUT(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______,
      KC_TAB,  PWDEV,   _______, KC_INS,  KC_ENT,  PWD1P,       _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______,
      KC_TRNS, KC_BSPC, KC_DEL,  KC_BTN1, PWDME,   PWDAA,       _______, KC_BSPC, KC_MINS, KC_EQL,  KC_UNDS, _______, _______,
      _______, _______,          TD_LWRC, KC_SPC,                        _______, RAISE,                     _______, _______
  ),

  [_RAISE] = LAYOUT(
      KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, KC_DEL,
      _______, _______, _______, _______, _______, _______,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, _______,
      _______, _______, _______, _______, _______, _______,     _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_MUTE,
      _______, _______,          TD_LWRC, KC_SPC,                        _______, RAISE,                     _______, _______
  ),

  [_ADJUST] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, RESET,
      _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_INS,  KC_F11,      KC_F12,  KC_PGDN, KC_PGUP, _______, _______, _______,
      KC_CAPS, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
      _______, _______,          TD_LWRC, KC_SPC,                        _______, RAISE,                     _______, _______
  ),
};

bool isShiftDown = false;
bool isLshiftDown = false;
bool isRshiftDown = false;
bool isGuiDown = false;

bool isTapdanceKey1Down = false;
bool isTapdanceKey2Down = false;
uint16_t prevTapdanceTime = 0;

layer_state_t layer_state_set_user(layer_state_t state) {
  if(IS_LAYER_ON(_LOWER) || IS_LAYER_ON(_RAISE)) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  } else {
    return state;
  }
}

uint32_t lastThrottle = 0;
bool joystickThrottleCheck(void) {
  if(timer_elapsed32(lastThrottle) < JOYSTICK_HOLD_THROTTLE) {
    return false;
  }
  lastThrottle = timer_read32();
  return true;
}

bool joystickHasReset = true;
bool joystickCanFire(int y) {
  if(y == 0) {
    joystickHasReset = true;
    return false;
  }

  if(joystickHasReset) {
    joystickHasReset = false;
    return joystickThrottleCheck();
  }
  return false;
}

/**
 * click functionality without `MOUSEKEY_ENABLE = no` in rules.mk
 */
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

#define TD_NULL 2
#define TD_DBLTAP_ON 1
#define TD_DBLTAP_OFF 0
int handle_tapdance(keyrecord_t *record, uint16_t downKeycode, bool isKey1Layer, uint16_t dbltapKeycode, bool isKey2Layer) {
  if(record->event.pressed) {
    uint16_t diffWithin = TIMER_DIFF_16(record->event.time, prevTapdanceTime) < TAPPING_TERM;
    if(!isTapdanceKey1Down && !diffWithin) {
      isTapdanceKey1Down = true;
      prevTapdanceTime = record->event.time;
      if(isKey1Layer) {
        layer_on(downKeycode);
      } else {
        register_code(downKeycode);
      }
    } else {
      isTapdanceKey2Down = true;
      if(isKey2Layer) {
        layer_on(dbltapKeycode);
      } else {
        register_code(dbltapKeycode);
      }
      return TD_DBLTAP_ON;
    }
  } else {
    if(isTapdanceKey1Down) {
      isTapdanceKey1Down = false;
      if(isKey1Layer) {
        layer_off(downKeycode);
      } else {
        unregister_code(downKeycode);
      }
    } else if(isTapdanceKey2Down) {
      isTapdanceKey2Down = false;
      if(isKey2Layer) {
        layer_off(dbltapKeycode);
      } else {
        unregister_code(dbltapKeycode);
      }
      return TD_DBLTAP_OFF;
    }
  }
  return TD_NULL;
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

    case PWDEV:
      if (keydown) {
        send_string_with_delay_P(PSTR(CPWDEV SS_TAP(X_ENT)), SEND_STR_DELAY);
      }
      break;

    case TD_LWRC:
      handle_tapdance(record, LOWER, true, KC_LCTL, false);
      break;

    case KC_LSFT:;
      isLshiftDown = keydown;
      isShiftDown = keydown;
      break;
    case KC_RSFT:;
      isRshiftDown = keydown;
      isShiftDown = keydown;
      break;

    case KC_LGUI:;
    case KC_RGUI:;
      isGuiDown = keydown;
      break;

    case KC_BTN1:;
      click(isShiftDown ? MOUSE_BTN2 : MOUSE_BTN1, keydown);
      break;
  }

  return true;
}

int pointerDivisor = POINTER_DIVISOR;
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (layer_state_is(_LOWER)) {
    // adjust joystick mouse sensitivity
    pointerDivisor += clockwise ? 1 : -1;
    if(pointerDivisor < 1) pointerDivisor = 1;
  } else if (layer_state_is(_RAISE)) {
  } else if(isGuiDown) {
    tap_code(clockwise ? KC_PAUSE : KC_SCROLLLOCK); // OSX screen brightness
  } else if(isRshiftDown) {
  } else if(isLshiftDown) {
  }
  return true;
}

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
  mouse_report.x = (int) mouse_report.x/pointerDivisor;
  mouse_report.y = (int) mouse_report.y/pointerDivisor;

  if(isGuiDown) {
    // hold GUI for brightness
    if(joystickCanFire(mouse_report.y)) {
      if(mouse_report.y < 0) tap_code(KC_BRIGHTNESS_UP);
      if(mouse_report.y > 0) tap_code(KC_BRIGHTNESS_DOWN);
    }
    mouse_report.x = 0;
    mouse_report.y = 0;
  } else if (isShiftDown) {
    // hold SHIFT to move faster
    mouse_report.x *= POINTER_SHIFT_FACTOR;
    mouse_report.y *= POINTER_SHIFT_FACTOR;
  } else if (layer_state_is(_LOWER)) {
    // hold LOWER to scroll

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
