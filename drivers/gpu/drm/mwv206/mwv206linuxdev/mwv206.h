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
#ifndef __MWV206_H__
#define __MWV206_H__

#ifdef __cplusplus
extern "C" {
#endif

#define error(fmt, args...) { \
	printk(KERN_ALERT "[%s: %d ] ", __FILE__, __LINE__);\
	printk(KERN_ALERT fmt, ##args); \
}

#define NDEBUG

#ifndef NDEBUG
#define debugline() { \
	printk(KERN_ALERT "[%s: %d ] ", __FILE__, __LINE__); \
}

#define debug error
#else
#define debug(fmt, args...)
#endif

#define MWV206_NAME "mwv206"

#ifdef __cplusplus
}
#endif

#endif