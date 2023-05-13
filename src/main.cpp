/*
 * Copyright (c) 2018 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/usb/usb_device.h>
#include <zephyr/usb/usbd.h>
#include <zephyr/drivers/uart.h>

#include <Controller.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(main);

int main(void)
{
	int ret = usb_enable(NULL);
	if (ret != 0) {
		return -1;
	}

    LOG_INF("Start All in one hub");

	Controller* ctrl = Controller::getInstance();
	ctrl->setup();

    while(true) {
        ctrl->loop();
    }

    return 0;
}

