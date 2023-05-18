/*
This is the c configuration file for the keymap

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

/* Use I2C or Serial, not both */
// #define USE_I2C
#define USE_SERIAL
#define SOFT_SERIAL_PIN D0

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT

#define POINTER_DIVISOR 4
#define POINTER_SHIFT_FACTOR 4
#define SEND_STR_DELAY 15

#define ENCODER_RESOLUTION 4

// Modify these values to adjust the scrolling speed
#define SCROLL_DIVISOR_H 32.0
#define SCROLL_DIVISOR_V 32.0
