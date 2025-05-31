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
#ifndef _MWV206_INTERNAL_H_
#define _MWV206_INTERNAL_H_
#ifdef __cplusplus
extern "C" {
#endif


#ifdef likely
#undef likely
#endif
#ifdef unlikely
#undef unlikely
#endif

#ifdef __GNUC__
#define likely(x)     __builtin_expect(!!(x), 1)
#define unlikely(x)   __builtin_expect(!!(x), 0)
#else
#error "Please use compiler with __GNUC__ to guess-branch-probability"
#define likely(x)       (x)
#define unlikely(x)     (x)
#endif




typedef float float4_t[4];
typedef unsigned long GLuintptr;

typedef unsigned int uint32_t;
typedef int int32_t;
typedef unsigned char ubyte_t;
typedef signed char byte_t;




#define MWV206_MAXGPUCNT 2
#define MWV206_MASTERDEV_NO 0
#define MWV206_SLAVEDEV_NO 1

#define MWV206_MAXGLXREQDATALEN (65536)


#define MWV206_MAXVERSTRLEN     (128)

#define MWV206_CHECKVERSTRLEN(verStr) \
do { \
	if (strlen(verStr) >= MWV206_MAXVERSTRLEN) { \
		printf("version string should be less than %dbytes.\n", MWV206_MAXVERSTRLEN); \
		return NULL; \
	} \
} while (0)


#ifndef INLINE
#  ifdef __cplusplus
#    define INLINE inline
#  elif defined(__GNUC__)
#    define INLINE __inline__
#  elif defined(_MSC_VER)
#    define INLINE __inline
#  elif defined(__ICL)
#    define INLINE __inline
#  elif defined(__INTEL_COMPILER)
#    define INLINE inline
#  elif defined(__WATCOMC__) && (__WATCOMC__ >= 1100)
#    define INLINE __inline
#  elif defined(__SUNPRO_C) && defined(__C99FEATURES__)
#    define INLINE inline
#  elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
#    define INLINE inline
#  else
#    define INLINE
#  endif
#endif


#ifndef __has_attribute
# define __has_attribute(x) 0
#endif

#if (__has_attribute(visibility) || (defined(__GNUC__) && (__GNUC__ >= 4))) \
&& !defined(__CYGWIN__) && !defined(__MINGW32__)
# define _J_EXPORT      __attribute__((visibility("default")))
# define _J_HIDDEN      __attribute__((visibility("hidden")))
# define _J_INTERNAL    __attribute__((visibility("internal")))
#elif defined(__SUNPRO_C) && (__SUNPRO_C >= 0x550)
# define _J_EXPORT      __global
# define _J_HIDDEN      __hidden
# define _J_INTERNAL    __hidden
#else
# define _J_EXPORT
# define _J_HIDDEN
# define _J_INTERNAL
#endif

#ifdef USE_GLVND
#define JJAPI _J_HIDDEN
#else
#define JJAPI _J_EXPORT
#endif

#ifdef __cplusplus
}
#endif
#endif