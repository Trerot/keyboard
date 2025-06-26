// Copyright 2023 david (@trerot)
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

/* split configs*/
#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN GP23     // USART TX pin
#define SERIAL_USART_RX_PIN GP21     // USART RX pin
#define SERIAL_USART_PIN_SWAP // pin swap since i did them pin to pin
#define SERIAL_PIO_USE_PIO1 // Force the usage of PIO1 peripheral, by default the Serial implementation uses the PIO0 peripheral
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // so i dont need both buttons

// i saw this on the ergodox config. betting its needed to set tapping to 120ms
#define TAPPING_TERM 120
// combo amount
#define COMBO_COUNT 2
// nkro on boot, remove to remove

// #define FORCE_NKRO