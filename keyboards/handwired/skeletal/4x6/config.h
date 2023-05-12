/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define PRODUCT_ID 0x3436
#define DEVICE_VER 0x0001

/*
              ._|~~|_.
    D3 [Tx0] -|      |- [RAW]
    D2 [Rx1] -|      |- [GND]
       [GND] -|      |- [RST]
       [GND] -|Pro   |- [Vcc]
SDA/D1 [  2] -|Micro |- [ A3] F4
SCL/D0 [  3] -|      |- [ A2] F5
    D4 [  4] -|      |- [ A1] F6
    C6 [  5] -|      |- [ A0] F7
    D7 [  6] -|      |- [ 15] B1
    E6 [  7] -|      |- [ 14] B3
    B4 [  8] -|      |- [ 16] B2
    B5 [  9] -|______|- [ 10] B6
*/

// key matrix size; rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

// row-driven
#define MATRIX_ROW_PINS { B1, B3, B2, B6 }
#define MATRIX_COL_PINS { B5, B4, E6, D7, C6, D4 }

// COL2ROW or ROW2COL
#define DIODE_DIRECTION COL2ROW

#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT

// Rotary Encoder
#define ENCODERS_PAD_A { F6 }
#define ENCODERS_PAD_B { F7 }
#define ENCODERS_PAD_A_RIGHT { }
#define ENCODERS_PAD_B_RIGHT { }

// Joystick Pointer
#define ANALOG_JOYSTICK_X_AXIS_PIN F5
#define ANALOG_JOYSTICK_Y_AXIS_PIN F6
#define ANALOG_JOYSTICK_CLICK_PIN F7

// WS2812 RGB LED strip input and number of LEDs
// #define RGB_DI_PIN D3
// #ifdef  RGB_DI_PIN
// #define RGBLIGHT_ANIMATIONS
// #define RGBLED_NUM 16
// #define RGBLED_SPLIT {8, 8}
// #define RGBLIGHT_HUE_STEP 8
// #define RGBLIGHT_SAT_STEP 8
// #define RGBLIGHT_VAL_STEP 8
// #endif
