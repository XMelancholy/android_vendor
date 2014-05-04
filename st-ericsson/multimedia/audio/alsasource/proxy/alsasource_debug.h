/*****************************************************************************/
/*
 * Copyright (C) ST-Ericsson SA 2012. All rights reserved.
 * This code is ST-Ericsson proprietary and confidential.
 * Any use of the code for whatever purpose is subject to
 * specific written permission of ST-Ericsson SA.
 *
 */
/*****************************************************************************/

#ifndef _alsasource_debug_h_
#define _alsasource_debug_h_

#include <stdio.h>

#ifdef ALSASOURCE_DEBUG_CTRLLIST
	#define DUMP_CFG_FILE_PATH "/data/dumpcfg.txt"
#endif

/**
* Enum containing all available log levels.
*/
enum ALSASOURCE_LOGLEVEL {
	ALSASOURCE_LOG_INFO,
	ALSASOURCE_LOG_WARN,
	ALSASOURCE_LOG_ERR,
	ALSASOURCE_LOG_LAST
};

/**
* Rescans "ste.debug.alsasource.log".
*
* @return Success: 0 Failure: -1
*/
void alsasource_dbg_set_logs_from_properties();

/**
* Return 1 if a certain type of log is enabled, 0 otherwise
*/
int alsasource_debug_is_log_enabled(enum ALSASOURCE_LOGLEVEL level);

/**
* Logs data to output and/or file depending on current settings and level.
* Do not use directly, instead use the appropriate LOG_x macro.
*
* @param level The loglevel of the message, must be a value from the enum ALSASOURCE_LOGLEVEL
* @param file The filename where the print was triggered
* @param line Line number where the print was triggered
* @param function Functation name where the print was triggered
* @param fmt String to be printed, printf style
*
* @return Success: 0 Failure: -1
*/
int alsasource_debug_print(enum ALSASOURCE_LOGLEVEL level, const char *file, int line, const char *function, const char *fmt, ...);

#ifdef __GNUC__
	#define unlikely(x) __builtin_expect((x), 0)
	#define VISIBILITY_HIDDEN __attribute__ ((visibility("hidden")))
#else
	#define unlikely(x) (x)
	#define VISIBILITY_HIDDEN
#endif

// Read by all dynamic prints (ADM_LOG_BASE macro). We want low
// overhead for prints when they are disabled.
//
// visibility=hidden is important, since otherwise accesses to
// g_alsasource_debug_mask are more indirect via a GOT table (since
// it becomes a shared symbol that might become overriden during dynamic
// linking)
//
// __builtin_expect((x), 0) is important, since we otherwise get branching
// each time a print is skipped.
//
// obviously, the volatile attribute would slow things down. In practice, the
// new debug setting propagates essentially instantly anyway.
extern unsigned int g_alsasource_debug_mask VISIBILITY_HIDDEN;
//extern unsigned int g_alsasource_debug_mask;

/**
* Internal helper macro for logging, do not use!
*/

#define UNUSED_PAR(x) (void)x

#ifdef ALSASOURCE_LOG_FILENAME
#define ALSASOURCE_LOG_BASE(__LEVEL, ...) \
	do { \
		if (unlikely(g_alsasource_debug_mask & (1U<< (unsigned int) __LEVEL))) { \
			alsasource_debug_print(__LEVEL, ALSASOURCE_LOG_FILENAME, __LINE__, __func__, __VA_ARGS__); \
		} \
	} while(0)
#else
#define ALSASOURCE_LOG_BASE(__LEVEL, ...) \
	do { \
		if (unlikely(g_alsasource_debug_mask & (1U<< (unsigned int) __LEVEL))) { \
			alsasource_debug_print(__LEVEL, __FILE__, __LINE__, __func__, __VA_ARGS__); \
		} \
	} while(0)
#endif

#define LOG_I(...) \
	do { \
		ALSASOURCE_LOG_BASE(ALSASOURCE_LOG_INFO, __VA_ARGS__); \
	} while (0)

#define LOG_W(...) \
	do { \
		ALSASOURCE_LOG_BASE(ALSASOURCE_LOG_WARN, __VA_ARGS__); \
	} while (0)

#define LOG_E(...) \
	do { \
		ALSASOURCE_LOG_BASE(ALSASOURCE_LOG_ERR, __VA_ARGS__); \
	} while (0)

#endif