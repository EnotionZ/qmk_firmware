CONSOLE_ENABLE         = no
MOUSEKEY_ENABLE        = no
ENCODER_ENABLE         = no

THUMBSTICK_ENABLE      = yes
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = analog_joystick
OPT_DEFS += -DTHUMBSTICK_ENABLE
SRC += analog.c
SRC += thumbstick.c
