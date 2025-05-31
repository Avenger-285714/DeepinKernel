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
#ifndef _MWV206CPUTYPE_H_
#define _MWV206CPUTYPE_H_

#include "../include/mwv206platform.h"
#include <asm/syscall.h>
#define V206CTYPE001     0x660
#define V206CTYPE002   0x661
#define V206CTYPE003  0x662
#define V206CTYPE004   0x663
#define V206CTYPE005    0xD01

#define V206CTYPE006(V206DEV028)    (V206DEV028 == V206CTYPE001)
#define V206CTYPE007(V206DEV028)  (V206DEV028 == V206CTYPE002)
#define V206CTYPE008(V206DEV028) (V206DEV028 == V206CTYPE003)
#define V206CTYPE009(V206DEV028)  (V206DEV028 == V206CTYPE004)
#define V206CTYPE010(V206DEV028)    (V206DEV028 == V206CTYPE005)

#ifndef _MWV206_CPU_
#define _MWV206_CPU_ 0
#endif /* _MWV206_CPU_ */

#if (_MWV206_CPU_ == _MWV206_AARCH64_)
static inline u32 V206CTYPE011(void)
{
	u32 pn;
	pn = read_cpuid_part_number();
	//V206KDEBUG003("[INFO] cpu arch: 0x%x.\n", syscall_get_arch());
	V206KDEBUG003("[INFO] cpu arch: AARCH64.\n");
	V206KDEBUG003("[INFO] cpu part: 0x%x.\n", pn);
	return pn;
}
#else
static inline u32 V206CTYPE011(void)
{
	//V206KDEBUG003("[INFO] cpu arch: 0x%x.\n", syscall_get_arch());
	V206KDEBUG003("[INFO] cpu arch is not AARCH64.\n");
	return 0x12;
}
#endif
#endif