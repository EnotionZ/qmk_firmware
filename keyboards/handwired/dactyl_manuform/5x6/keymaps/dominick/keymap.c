#include QMK_KEYBOARD_H
#include "shared.h"

enum layers {
  _QWERTY = 0,
  _MAC,
  _FN,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  PWD1P = SAFE_RANGE,
  EMAIL,
  PWDME,
  PWDEV,
  CTLTB,
  MACDEL,
  VSCLOSE,
  VSCLALL,
  FASTCLK,
};

#define TGMAC  TG(_MAC)
#define TGFN   TG(_FN)
#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define CTLTAB MT(MOD_LCTL, KC_TAB)

#ifndef ADJUST_RAPID_FIRE_INTERVAL_MS
#define ADJUST_RAPID_FIRE_INTERVAL_MS 45
#endif
#ifndef ADJUST_RAPID_MAX_KEYS
#define ADJUST_RAPID_MAX_KEYS 8
#endif

typedef struct {
    uint16_t keycode;
    uint16_t last_tap;
} adjust_rapid_slot_t;

static adjust_rapid_slot_t adjust_rapid_slots[ADJUST_RAPID_MAX_KEYS];

static bool adjust_rapid_eligible(uint16_t keycode) {
    if (keycode == KC_NO || keycode == KC_TRNS) {
        return false;
    }
    if (IS_QUANTUM_KEYCODE(keycode)) {
        return false;
    }
    if (keycode >= SAFE_RANGE) {
        return false;
    }
    return IS_BASIC_KEYCODE(keycode) || IS_MODIFIER_KEYCODE(keycode) || IS_SYSTEM_KEYCODE(keycode) || IS_CONSUMER_KEYCODE(keycode) || IS_MOUSE_KEYCODE(keycode);
}

static void adjust_rapid_clear(void) {
    for (uint8_t i = 0; i < ADJUST_RAPID_MAX_KEYS; i++) {
        adjust_rapid_slots[i].keycode = KC_NO;
    }
}

static void adjust_rapid_register(uint16_t keycode) {
    for (uint8_t i = 0; i < ADJUST_RAPID_MAX_KEYS; i++) {
        if (adjust_rapid_slots[i].keycode == keycode) {
            adjust_rapid_slots[i].last_tap = timer_read();
            return;
        }
    }
    for (uint8_t i = 0; i < ADJUST_RAPID_MAX_KEYS; i++) {
        if (adjust_rapid_slots[i].keycode == KC_NO) {
            adjust_rapid_slots[i].keycode = keycode;
            adjust_rapid_slots[i].last_tap = timer_read();
            return;
        }
    }
}

static void adjust_rapid_unregister(uint16_t keycode) {
    for (uint8_t i = 0; i < ADJUST_RAPID_MAX_KEYS; i++) {
        if (adjust_rapid_slots[i].keycode == keycode) {
            adjust_rapid_slots[i].keycode = KC_NO;
        }
    }
}

static void adjust_rapid_tick(void) {
    uint16_t now = timer_read();
    for (uint8_t i = 0; i < ADJUST_RAPID_MAX_KEYS; i++) {
        uint16_t kc = adjust_rapid_slots[i].keycode;
        if (kc == KC_NO) {
            continue;
        }
        if (timer_elapsed(adjust_rapid_slots[i].last_tap) >= ADJUST_RAPID_FIRE_INTERVAL_MS) {
            tap_code16(kc);
            adjust_rapid_slots[i].last_tap = now;
        }
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_HOME,
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
     KC_RCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                       KC_LGUI, KC_LALT,                                           KC_RALT, KC_RGUI,
                                         LOWER,   KC_TRNS,       KC_TRNS, RAISE,
                                         KC_SPC,  KC_MUTE,       MS_BTN1, KC_BSPC,
                                         KC_RALT, KC_LCTL,       KC_MINS, KC_DEL
  ),

  [_MAC] = LAYOUT_5x6(
     _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
                       KC_LALT, KC_LGUI,                                           KC_RGUI, KC_RALT,
                                         _______, _______,       _______, _______,
                                         _______, _______,       _______, _______,
                                         KC_RGUI, _______,       _______, _______
  ),

  [_FN] = LAYOUT_5x6(
     KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
     QK_GESC, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
     KC_TAB,  _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
                       _______, _______,                                           _______, _______,
                                         _______, KC_TRNS,       KC_TRNS, _______,
                                         _______, _______,       _______, _______,
                                         _______, _______,       _______, KC_MENU
  ),


  [_LOWER] = LAYOUT_5x6(
     KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
     KC_TAB,  PWDEV,   MACDEL,  KC_INS,  KC_ENT,  PWD1P,         _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______,
     KC_TRNS, KC_BSPC, KC_DEL,  VSCLOSE, PWDME,   EMAIL,         _______, KC_MINS, KC_EQL,  KC_UNDS, KC_PLUS, _______,
                       _______, _______,                                           _______, _______,
                                         _______, KC_TRNS,       KC_TRNS, _______,
                                         _______, _______,       _______, KC_SPC,
                                         _______, _______,       _______, _______
  ),

  [_RAISE] = LAYOUT_5x6(
     KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR , KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
     KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR , KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
     _______, _______, _______, _______, _______, _______,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, KC_MUTE,
     _______, _______, _______, VSCLALL, _______, _______,       KC_MPLY, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, _______,
                       _______, _______,                                           _______, _______,
                                         _______, KC_TRNS,       KC_TRNS, _______,
                                         _______, _______,       FASTCLK, _______,
                                         _______, _______,       _______, KC_DEL
  ),

  [_ADJUST] = LAYOUT_5x6(
     _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, QK_BOOT,
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
     _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_INS,  KC_F11,        KC_F12,  KC_PGDN, KC_PGUP, _______, _______, TGFN,
     KC_CAPS, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
                       _______, _______,                                           _______, _______,
                                         _______, KC_TRNS,       KC_TRNS, _______,
                                         _______, _______,       _______, _______,
                                         TGMAC,   _______,       _______, _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  if(IS_LAYER_ON(_LOWER) || IS_LAYER_ON(_RAISE)) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  } else {
    return state;
  }
}
bool rapid_fire = false;
void matrix_scan_user(void) {
  if (rapid_fire) {
    tap_code(MS_BTN1);
  }
  if (layer_state_is(_ADJUST)) {
    adjust_rapid_tick();
  } else {
    adjust_rapid_clear();
  }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (layer_state_is(_RAISE)) {
    tap_code(!clockwise ? KC_PAUSE : KC_SCROLL_LOCK);
  } else if(layer_state_is(_LOWER)) {
    tap_code(clockwise ? KC_BRIGHTNESS_DOWN : KC_BRIGHTNESS_UP);
  } else {
    tap_code(clockwise ? KC_VOLD : KC_VOLU);
  }
  return false;
}

/* void matrix_init_user(void) { */
/*   rgblight_enable(); */
/*   rgblight_sethsv(0,255,255); */
/*   rgblight_mode(9); */
/* }; */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (layer_state_is(_ADJUST) && adjust_rapid_eligible(keycode)) {
    if (record->event.pressed) {
      tap_code16(keycode);
      adjust_rapid_register(keycode);
    } else {
      adjust_rapid_unregister(keycode);
    }
    return false;
  }

  switch (keycode) {
    case CTLTB:
      if (record->event.pressed) {
        // if lower, shift, or gui is down, sent tab
        if(layer_state_is(_LOWER) ||
            layer_state_is(_RAISE) ||
            keyboard_report->mods & MOD_BIT(KC_LSFT) ||
            keyboard_report->mods & MOD_BIT(KC_LGUI)) {
          register_code(KC_TAB);
        } else {
          register_code(KC_LCTL);
        }
      } else {
        if(layer_state_is(_LOWER) ||
            layer_state_is(_RAISE) ||
            keyboard_report->mods & MOD_BIT(KC_LSFT) ||
            keyboard_report->mods & MOD_BIT(KC_LGUI)) {
          unregister_code(KC_TAB);
        } else {
          unregister_code(KC_LCTL);
        }
      }
      break;

    case PWD1P:
      if (record->event.pressed) {
        send_string_with_delay_P(PSTR(CPWD1P SS_TAP(X_ENT)), SEND_STR_DELAY);
      }
      break;

    case EMAIL:
      if (record->event.pressed) {
        send_string_with_delay_P(PSTR(EMAIL_STR), SEND_STR_DELAY);
      }
      break;

    case PWDME:
      if (record->event.pressed) {
        send_string_with_delay_P(PSTR(CPWDME SS_TAP(X_ENT)), SEND_STR_DELAY);
      }
      break;

    case PWDEV:
      if (record->event.pressed) {
        send_string_with_delay_P(PSTR(CPWDEV SS_TAP(X_ENT)), SEND_STR_DELAY);
      }
      break;

    case VSCLOSE:
      if(record->event.pressed) {
        register_code(KC_LCTL);
        tap_code(KC_W);
        unregister_code(KC_LCTL);
        tap_code(KC_Q);
      }
      break;

    case FASTCLK:
      if (record->event.pressed) {
        rapid_fire = !rapid_fire;
      }
      break;

    case VSCLALL:
      if(record->event.pressed) {
        register_code(KC_LCTL);
        tap_code(KC_K);
        unregister_code(KC_LCTL);
        tap_code(KC_W);
      }
      break;

    case MACDEL:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_BSPC);
      } else {
        unregister_code(KC_LGUI);
        unregister_code(KC_BSPC);
      }

      break;

    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
  }

  return true;
}
