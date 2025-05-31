/*
 * JM7200 GPU driver
 *
 * Copyright (c) 2018 ChangSha JingJiaMicro Electronics Co., Ltd.
 *
 * Author:
 *      rfshen <jjwgpu@jingjiamicro.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */
#ifndef __MWV206DEBUG_H
#define __MWV206DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/mwv206_internal.h"




enum e_mwv206_debug_level {
	MWV206_DEBUG_ERROR,
	MWV206_DEBUG_UNSUPPORT,
	MWV206_DEBUG_GLERROR,
	MWV206_DEBUG_WARNING,
	MWV206_DEBUG_INFO,
	MWV206_DEBUG_TRACE,
};

#define V206KDEBUG006     MWV206_DEBUG_ERROR
#define V206KDEBUG007    MWV206_DEBUG_INFO
#define V206KDEBUG008     MWV206_DEBUG_INFO
#define V206KDEBUG009     MWV206_DEBUG_GLERROR
#define V206KDEBUG010       MWV206_DEBUG_TRACE



extern int g_mwv206_debug_level;

extern int g_mwv206_debug_info_module;

extern void mwv206SetDebugLevel(void);


#define V206KDEBUG001(level, fmt, args...) do { \
if (unlikely(level <= g_mwv206_debug_level)) \
printf(fmt, ##args);\
} while (0)

#define MWV206_DEBUG_H V206KDEBUG001


#define V206DEBUG001        0x1
#define V206DEBUG002            0x2
#define V206DEBUG003         0x4
#define V206DEBUG004         0x8
#define V206DEBUG005          0x10
#define V206DEBUG006            0x20
#define V206DEBUG007        0x40
#define V206DEBUG008          0x80
#define V206DEBUG009        0x100
#define V206DEBUG010      0x200
#define V206DEBUG011         0x400
#define V206DEBUG012    0x800
#define V206DEBUG013         0x1000
#define V206DEBUG014      0x2000
#define V206DEBUG015  0x4000
#define V206DEBUG016    0x8000
#define V206DEBUG017        0x10000
#define V206DEBUG018          0x20000
#define V206DEBUG019          0x40000
#define V206DEBUG020       0x80000
#define V206DEBUG021    0x100000
#define V206DEBUG022           0x200000
#define V206DEBUG023       0x400000
#define V206DEBUG024            0x800000
#define V206DEBUG025           0x1000000
#define V206DEBUG026         0x2000000
#define V206DEBUG027            0x4000000

#ifdef __DEBUG_MORE_INFO__
static void MWV206Error1(const char *filename, int line, const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	fprintf(stderr, "[##Assertion##] in '%s': %d:\n", filename, line);
	fprintf(stderr, "[##Assertion##]:");
	vfprintf(stderr, format, ap);
	va_end(ap);
	fputc('\n', stderr);
	exit(-1);
}


#define MWV206_ERROR(...) MWV206Error1(__FILE__, __LINE__, __VA_ARGS__);

#define MWV206_ASSERT(cond, ...) do {\
		if (unlikely(!(cond)) { \
			MWV206_ERROR(__VA_ARGS__); \
		} \
	} while (0)

static void MWV206_DEBUG1(const char *filename, int line, int level, const char *info, const char *format, ...)
{
	va_list ap;

	if (likely(g_mwv206_debug_level < level)) {
		return;
	}

	va_start(ap, format);
	fprintf(stderr, "[##%s##] in '%s': %d:\n", info, filename, line);
	fprintf(stderr, "[##%s##]:", info);
	vfprintf(stderr, format, ap);
	va_end(ap);
	fputc('\n', stderr);
}

static void MWV206_INFO1(const char *filename, int line, int module, const char *format, ...)
{
	va_list ap;

	if (likely(g_mwv206_debug_level < MWV206_DEBUG_INFO)) {
		return;
	}
	if (!likely(g_mwv206_debug_info_module & module)) {
		return;
	}

	va_start(ap, format);
	fprintf(stderr, "[##Info##] in '%s': %d:\n", filename, line);
	fprintf(stderr, "[##Info##]:");
	vfprintf(stderr, format, ap);
	va_end(ap);
	fputc('\n', stderr);
}


#define MWV206_UNSUPPORT(...) MWV206_DEBUG1(__FILE__, __LINE__, MWV206_DEBUG_UNSUPPORT, "Unsupport",  __VA_ARGS__);

#define MWV206_GLERROR(...) MWV206_DEBUG1(__FILE__, __LINE__, MWV206_DEBUG_GLERROR, "glError",  __VA_ARGS__);

#define MWV206_WARNING(...) MWV206_DEBUG1(__FILE__, __LINE__, MWV206_DEBUG_WARNING, "Warning",  __VA_ARGS__);

#define MWV206_INFO(...) MWV206_INFO1(__FILE__, __LINE__, __VA_ARGS__);


#define MWV206_INFO_MODULE_TEST(module) \
	(unlikely((g_mwv206_debug_level >= MWV206_DEBUG_INFO) && (g_mwv206_debug_info_module & module)))


#define MWV206_INFO_PRINT(fmt, args...) do { \
	fprintf(stderr, "[##Info##]:"fmt"\n", ##args); \
} while (0)



#define V206KDEBUG005() do {\
	printf("%s, %d, %s\n", __FILE__, __LINE__, __FUNCTION__); \
	 \
} while (0)
#else

#define MWV206_ERROR(fmt, args...) do { \
	fprintf(stderr, "\n[##Assertion##]:"fmt"\n\n", ##args); \
	exit(-1); \
} while (0)


#define MWV206_ASSERT(cond, ...) do {\
	if (!likely(cond)) { \
		MWV206_ERROR(__VA_ARGS__);\
	} \
} while (0)

#define MWV206_DEBUG1(level, info, fmt, args...) do { \
	if (unlikely(g_mwv206_debug_level >= level)) { \
		fprintf(stderr, "[##%s##]:"fmt"\n", info, ##args); \
	} \
} while (0)


#define MWV206_UNSUPPORT(...) MWV206_DEBUG1(MWV206_DEBUG_UNSUPPORT, "Unsupport",  __VA_ARGS__);

#define MWV206_GLERROR(...) MWV206_DEBUG1(MWV206_DEBUG_GLERROR, "glError",  __VA_ARGS__);

#define MWV206_WARNING(...) MWV206_DEBUG1(MWV206_DEBUG_WARNING, "Warning",  __VA_ARGS__);


#define MWV206_INFO(module, fmt, args...)
#define MWV206_INFO_T(module, fmt, args...) do { \
	if (unlikely((g_mwv206_debug_level >= MWV206_DEBUG_INFO) && (g_mwv206_debug_info_module & module))) { \
		fprintf(stderr, "[##Info##]:"fmt"\n", ##args); \
	} \
} while (0)

#define MWV206_INFO_GLX(fmt, args...)

#define MWV206_INFO_MODULE_TEST(module) (0)


#define MWV206_INFO_PRINT(fmt, args...)


#define V206KDEBUG005()
#endif



extern const char *getEnumString(int eval);
extern const char *getEnumStringSpecial(int eval);
#ifdef __cplusplus
}
#endif

#endif