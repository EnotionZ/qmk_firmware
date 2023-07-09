#pragma once

#define SEND_STR_DELAY 15

#define POINTING_DEVICE_INVERT_X
#define POINTING_DEVICE_INVERT_Y

// #define ANALOG_JOYSTICK_CLICK_PIN F7
#define ANALOG_JOYSTICK_Y_AXIS_PIN B6
#define ANALOG_JOYSTICK_X_AXIS_PIN D7
#define ANALOG_JOYSTICK_SPEED_MAX 5
#define ANALOG_JOYSTICK_SPEED_REGULATOR 10
#define ANALOG_JOYSTICK_READ_INTERVAL 3

// scale down the pointer by this amount
#define POINTER_DIVISOR 6

// scale up by this factor when holding shift
#define POINTER_SHIFT_FACTOR 3

// if holding down to fire tap
#define JOYSTICK_HOLD_THROTTLE 100

// Modify these values to adjust the scrolling speed
#define SCROLL_DIVISOR_H 32.0
#define SCROLL_DIVISOR_V 32.0
