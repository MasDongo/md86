// Copyright 2024 Viola Allegro (@MasDongo)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

//1 Encoder
#define ENCODERS_PAD_A { GP28 }
#define ENCODERS_PAD_B { GP29 }
#define ENCODER_RESOLUTION 4
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP26
#define I2C1_SCL_PIN GP27
#define MY_I2C_ADDRESS (0x7B << 1)
#define OLED_DISPLAY_128X64
#define OLED_TIMEOUT 600000
#define DEBOUNCE 12
#define FORCE_NKRO
