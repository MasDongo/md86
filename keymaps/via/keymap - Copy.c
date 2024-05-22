// Copyright 2024 %YOUR_FULL_NAME% (@%YOUR_GITHUB_USERNAME%)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_F21, KC_F22, KC_F23, KC_F24,  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,
        KC_HOME, KC_UP,   KC_PGUP, KC_DEL,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LEFT, _______, KC_RGHT, KC_INS,  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_PIPE, KC_ENT,
        KC_END,  KC_DOWN, KC_PGDN, _______, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_RCTL,
        KC_PMNS, KC_PSLS, TG(1),   KC_ENT,  KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_LALT, TT(2),   KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_P7,   KC_P8,   KC_P9,   KC_BSPC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_P4,   KC_P5,   KC_P6,   KC_P0,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_P1,   KC_P2,   KC_P3,   KC_PDOT,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_PPLS, KC_PAST, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [2] = LAYOUT(
        _______, _______, _______, _______, KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HOME,
        _______, _______, _______, _______, _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_PGUP,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_END,
        _______, _______, _______, _______, _______, _______, _______, QK_BOOT, _______, _______, _______, _______, _______, _______
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)  },
    [2] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)  },
   };
#endif

enum layer_names {
    _STD,
    _NUM,
    _FUN
};



/* Rotate OLED
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}*/



#ifdef OLED_ENABLE
bool oled_task_user() {
    oled_set_cursor(0, 0);


    switch (get_highest_layer(layer_state)){
           case _STD:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num On\n"), false);
            break;
        case _FUN:
            oled_write_P(PSTR("Function\n"), false);
            break;
        }

    // Host Keyboard LED Status
    oled_set_cursor(34, 0);
    led_t led_state = host_keyboard_led_state();
      oled_write_P(led_state.caps_lock ? PSTR("Caps On ") : PSTR("Caps Off"), false);

   
    return false;
}
#endif
