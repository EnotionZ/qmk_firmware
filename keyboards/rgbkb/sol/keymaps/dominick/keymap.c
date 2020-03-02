#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _GUISWAP,
    _FN
};

// Keycode defines for layers
#define QWERTY   DF(_QWERTY)
#define GUISWAP  TG(_GUISWAP)
#define FN       MO(_FN)

enum custom_keycodes {
  RGBRST = SAFE_RANGE,
  RGB_MENU
};

#define FN_ESC   LT(_FN, KC_ESC)
#define FN_CAPS  LT(_FN, KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,------------------------------------------------.  ,------------------------------------------------.
   * | GESC |   1  |   2  |   3  |   4  |   5  |   -  |  |   =  |   6  |   7  |   8  |   9  |   0  |  =+  |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   [  |  |   ]  |   Y  |   U  |   I  |   O  |   P  |  \|  |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * | FN   |   A  |   S  |   D  |   F  |   G  |  FN  |  |      |   H  |   J  |   K  |   L  |   ;  |Enter |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |Shift |   Z  |   X  |   C  |   V  |   B  |      |  |      |   N  |   M  |   ,  |   .  |   /  |Shift |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * | Ctrl |  RGB |  DEL |  ALT | CTRL |      |      |  | MUTE |      |  '"  |  -_  |  FN  | ALT  | Ctrl |
   * |------+------+------+------+------+-SPACE+------|  |------+-BKSPC+------+------+------+------+------'
   *                                    |      | LGUI |  | RGUI |      |
   *                                    `-------------'  `-------------'
   */
  [_QWERTY] = LAYOUT( \
    KC_GESC,    KC_1,   KC_2,    KC_3,    KC_4,   KC_5, KC_MINS,  KC_EQL,    KC_6,    KC_7,       KC_8,    KC_9,    KC_0, KC_EQL, \
     KC_TAB,    KC_Q,   KC_W,    KC_E,    KC_R,   KC_T, KC_LBRC, KC_RBRC,    KC_Y,    KC_U,       KC_I,    KC_O,    KC_P, KC_BSLS, \
         FN,    KC_A,   KC_S,    KC_D,    KC_F,   KC_G,      FN,      FN,    KC_H,    KC_J,       KC_K,    KC_L, KC_SCLN, KC_ENT, \
    KC_LSFT,    KC_Z,   KC_X,    KC_C,    KC_V,   KC_B, _______, _______,    KC_N,    KC_M,    KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, \
    KC_LCTL, RGB_TOG, KC_DEL, KC_LALT, KC_LCTL, KC_SPC, _______, KC_MUTE, KC_BSPC,    KC_QUOT, KC_MINS,      FN, KC_RALT, KC_RCTL, \
                                                 KC_SPC, KC_LGUI, KC_RGUI, KC_BSPC \
    ),

  /* GUISWAP
   * Swap the left GUI and ALT keys (useful for switching between OSX and Windows, or while gaming to avoid minimize
   */
  [_GUISWAP] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_LGUI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                                 _______, KC_LALT, _______, _______ \
    ),

  /* FN
   * ,------------------------------------------------.  ,------------------------------------------------.
   * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |  |  F12 |  F6  |  F7  |   F8 |   F9 |  F10 |DELETE|
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * |      | PGDN |  UP  | PGUP |      |      | RESET|  | RESET| SLOCK|   [  |   ]  | PGUP | PRINT| HOME |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * |      | LEFT | DOWN | RIGHT|      |      |      |  |      | NLOCK|   {  |   }  | RIGHT|INSERT| END  |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |      |RGBMOD|      |      |      |      | GUISW|  | Play |      |      |      |      |      |      |
   * `------+------+------+------+------+------+------|  |------+------+------+------+------+------+------'
   *                                    | BSPC | ENTER|  |      | SPACE|
   *                                    `-------------'  `-------------'
   */
  [_FN] = LAYOUT( \
     KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F11,  KC_F12,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_DEL, \
    KC_CAPS, KC_PGDN,   KC_UP, KC_PGUP, _______, _______,   RESET,   RESET, KC_SLCK, KC_LBRC, KC_RBRC, _______, KC_PSCR, KC_HOME, \
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, KC_NLCK, KC_LCBR, KC_RCBR, _______,  KC_INS,  KC_END, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, RGB_MOD, _______, _______, _______, _______, GUISWAP, KC_MPLY, _______, _______, _______, _______, _______, _______, \
                                                 KC_BSPC,  KC_ENT, _______, KC_SPC \
  )

};

// For RGBRST Keycode
#if defined(RGB_MATRIX_ENABLE)
void rgb_matrix_increase_flags(void)
{
    switch (rgb_matrix_get_flags()) {
        case LED_FLAG_ALL: {
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_UNDERGLOW: {
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
            }
            break;
        default: {
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_enable_noeeprom();
            }
            break;
    }
}

void rgb_matrix_decrease_flags(void)
{
    switch (rgb_matrix_get_flags()) {
        case LED_FLAG_ALL: {
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
            }
            break;
        case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_UNDERGLOW: {
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        default: {
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_enable_noeeprom();
            }
            break;
    }
}
#endif

uint8_t rgb_encoder_state = 4;

typedef void (*rgb_matrix_f)(void);

const rgb_matrix_f rgb_matrix_functions[6][2] = {
    { rgb_matrix_increase_hue, rgb_matrix_decrease_hue },
    { rgb_matrix_increase_sat, rgb_matrix_decrease_sat },
    { rgb_matrix_increase_val, rgb_matrix_decrease_val },
    { rgb_matrix_increase_speed, rgb_matrix_decrease_speed },
    { rgb_matrix_step, rgb_matrix_step_reverse },
    { rgb_matrix_increase_flags, rgb_matrix_decrease_flags }
};

#ifdef ENCODER_ENABLE

static bool fn_down = false;

void encoder_update_user(uint8_t index, bool clockwise) {

  if (index == 0) { /* Left encoder */
    uint8_t layer = layer_state ? biton(layer_state) : biton32(default_layer_state);
    bool isMac = layer != _GUISWAP;

    if(fn_down) {
      (*rgb_matrix_functions[rgb_encoder_state][clockwise])();
    } else {
      if(isMac) {
        // scroll lock and pause controls brightness for active display on Mac
        tap_code(clockwise ? KC_SCROLLLOCK : KC_PAUSE);
      } else {
        tap_code(clockwise ? KC_BRIGHTNESS_DOWN : KC_BRIGHTNESS_UP);
      }
    }

  } else if (index == 1) { /* Right encoder*/
    if (!fn_down) {
      tap_code(clockwise ? KC_VOLD : KC_VOLU);
    } else {
      tap_code(clockwise ? KC_UP : KC_DOWN);
    }
  }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t reset_timer;
  switch (keycode) {
    case FN:
      if (record->event.pressed) {
        fn_down = true;
      } else {
        fn_down = false;
      }
      return true;

    case RGBRST:
#if defined(RGBLIGHT_ENABLE)
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
#elif defined(RGB_MATRIX_ENABLE)
        if (record->event.pressed) {
          eeconfig_update_rgb_matrix_default();
        }
#endif
      return false;
    case RESET:
      if (record->event.pressed) {
          reset_timer = timer_read();
      } else {
          if (timer_elapsed(reset_timer) >= 500) {
              reset_keyboard();
          }
      }
      return false;
#if defined(RGB_MATRIX_ENABLE) && defined(KEYBOARD_rgbkb_sol_rev2)
    case RGB_TOG:
      if (record->event.pressed) {
        rgb_matrix_increase_flags();
      }
      return false;
#endif
    case RGB_MENU:
#ifdef RGB_OLED_MENU
      // for encoder to advance to next option
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
          rgb_encoder_state = (rgb_encoder_state - 1);
          if (rgb_encoder_state > 5) {
            rgb_encoder_state = 5;
          }
        } else {
          rgb_encoder_state = (rgb_encoder_state + 1) % 6;
        }
      }
#endif
      return true;
  }
  return true;
}

// OLED Driver Logic
#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master())
    return OLED_ROTATION_270;
  return rotation;
}

static void render_logo(void) {
  static const char PROGMEM sol_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
  };
  oled_write_P(sol_logo, false);
}

static void render_status(void) {
  // Render to mode icon
  static const char PROGMEM sol_icon[] = {
    0x9b,0x9c,0x9d,0x9e,0x9f,
    0xbb,0xbc,0xbd,0xbe,0xbf,
    0xdb,0xdc,0xdd,0xde,0xdf,0
  };
  oled_write_P(sol_icon, false);

  // Define layers here
  oled_write_P(PSTR("Layer"), false);
  uint8_t layer = layer_state ? biton(layer_state) : biton32(default_layer_state);
  switch (layer) {
    case _QWERTY:
      oled_write_P(PSTR("BASE "), false);
      break;
    case _FN:
      oled_write_P(PSTR("FN   "), false);
      break;
    case _GUISWAP:
      oled_write_P(PSTR("GUISW"), false);
      break;
    default:
      oled_write_P(PSTR("UNDEF"), false);
  }

  // Host Keyboard LED Status
    uint8_t led_state = host_keyboard_leds();
    oled_write_P(PSTR("-----"), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_NUM_LOCK) ? PSTR("NUMLK") : PSTR("     "), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLK") : PSTR("     "), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLK") : PSTR("     "), false);

#ifdef RGB_OLED_MENU
    static char buffer[31] = { 0 };
    snprintf(buffer, sizeof(buffer), "h%3d s%3d v%3d s%3d m%3d e%3d ", rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v, rgb_matrix_config.speed, rgb_matrix_config.mode, rgb_matrix_get_flags());
    buffer[4 + rgb_encoder_state * 5] = '<';

    oled_write_P(PSTR("-----"), false);
    oled_write(buffer, false);
#endif
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
    //oled_scroll_left();
  }
}

#endif
