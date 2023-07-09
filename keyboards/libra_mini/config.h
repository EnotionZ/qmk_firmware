// https://github.com/vial-kb/vial-qmk/tree/vial/keyboards/libra_mini
#pragma once

// key matrix size; rows are doubled-up
#define MATRIX_ROWS 5
#define MATRIX_COLS 12

#define MATRIX_ROW_PINS { E6, B4, B5, B2, NO_PIN }
#define MATRIX_COL_PINS { B3, B1, F7, F6, F5, F4, C6, D4, D0, D1, D2, D3 }

#define DIODE_DIRECTION ROW2COL

// Max 32
#define JOYSTICK_BUTTON_COUNT 0
// Max 6: X, Y, Z, Rx, Ry, Rz
#define JOYSTICK_AXES_COUNT 2


#define USB_POLLING_INTERVAL_MS 1

#define TAPPING_TERM 300