/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 hathach for Adafruit Industries
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef COMMON_HAL_USB_HID_DEVICE_H
#define COMMON_HAL_USB_HID_DEVICE_H

#include <stdint.h>
#include <stdbool.h>

#include "py/obj.h"

#ifdef __cplusplus
 extern "C" {
#endif

// 1 to enable device, 0 to disable
#define USB_HID_DEVICE_KEYBOARD        1
#define USB_HID_DEVICE_MOUSE           1
#define USB_HID_DEVICE_CONSUMER        0
#define USB_HID_DEVICE_GAMEPAD         0

enum {
    USB_HID_REPORT_ID_UNUSED   = 0,

#if USB_HID_DEVICE_KEYBOARD
    USB_HID_REPORT_ID_KEYBOARD,
#endif

#if USB_HID_DEVICE_MOUSE
    USB_HID_REPORT_ID_MOUSE,
#endif

#if USB_HID_DEVICE_CONSUMER
    USB_HID_REPORT_ID_CONSUMER,
#endif

#if USB_HID_DEVICE_GAMEPAD
    USB_HID_REPORT_ID_GAMEPAD,
#endif
};

#define USB_HID_NUM_DEVICES             (USB_HID_DEVICE_KEYBOARD + USB_HID_DEVICE_MOUSE + USB_HID_DEVICE_CONSUMER + USB_HID_DEVICE_GAMEPAD )

typedef struct  {
    mp_obj_base_t base;
    uint8_t* report_buffer;
    uint8_t report_id;     // If non-zero, prefix report with given id.
    uint8_t report_length; // Length not including Report ID.
    uint8_t usage_page;
    uint8_t usage;
} usb_hid_device_obj_t;


usb_hid_device_obj_t usb_hid_devices[USB_HID_NUM_DEVICES];

#ifdef __cplusplus
 }
#endif

#endif /* COMMON_HAL_USB_HID_DEVICE_H */
