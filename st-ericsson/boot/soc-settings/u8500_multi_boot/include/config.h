/*
 * Copyright (C) ST-Ericsson SA 2012. All rights reserved.
 * This code is ST-Ericsson proprietary and confidential.
 * Any use of the code for whatever purpose is subject to
 * specific written permission of ST-Ericsson SA.
 *
 * Author: Jonas Aaberg <jonas.aberg@stericsson.com> for ST-Ericsson
 *
 */
#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <stdbool.h>
#include <types.h>
#include <options.h>
#include <peripheral.h>

#define MAX_UART_STRING 20

struct config {
	bool avs_enable;
	enum avs_type avs_type;
	enum memtest_method memtest_method;
	bool memtest_disable_cache;
	enum overclock overclock;
	enum log_level log_level;
	bool uart_enable;
	char uart_str[MAX_UART_STRING];
	u32  uart_base;
	enum uart_gpiopins uart_gpiopins;
	enum uart_baud uart_baud;
	enum modem_stm_gpiopins modem_stm_gpiopins;
	enum modem_uart_gpiopins modem_uart_gpiopins;
	enum prcmu_stm_gpiopins prcmu_stm_gpiopins;
	enum board_version board_version;
	bool modem_start;
	bool process_detection;
};

struct config * get_config(void);

#endif
