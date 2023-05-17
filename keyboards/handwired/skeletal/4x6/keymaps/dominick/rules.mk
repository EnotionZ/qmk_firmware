ENCODER_ENABLE    = yes
THUMBSTICK_ENABLE = yes
TAP_DANCE_ENABLE  = no

ifeq ($(strip $(THUMBSTICK_ENABLE)), yes)
    POINTING_DEVICE_ENABLE = yes
    POINTING_DEVICE_DRIVER = analog_joystick
endif
