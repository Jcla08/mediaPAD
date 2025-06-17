// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ 1 │ 2 │ 3 │
     * ├───┼───┼───┤
     * │ 4 │ 5 │ 6 │
     * └───┴───┴───┘
     */
    [0] = LAYOUT(
        KEY_1,   KEY_2,   KEY_3,
        KEY_4,   KEY_5,   KEY_6
    )
};

const uint16_t PROGMEM encoder_map[][1][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
};

#ifdef OLED_ENABLED

// draw to oled
bool oled_task_user() {
    
    oled_set_cursor(0, 1);

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("Caps: On") : PSTR("Caps: Off"), false);
    return false;
}

#endif