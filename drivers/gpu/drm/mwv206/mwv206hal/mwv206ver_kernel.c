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
#include "../include/mwv206ioctl.h"
#include "mwv206dev.h"

int FUNC206HAL336(V206DEV025 *pDev, long arg)
{
	const char *kverstr = "mwv206kernel-1.1.2-20200929.1340(mwv206-dkms-closed.ko)";
	int ret;

	ret = copy_to_user((char __user *)arg, kverstr, strlen(kverstr));
	if (ret != 0) {
		V206KDEBUG002("###ERR[%s] copy_to_user error [%d].\n", __FUNCTION__, ret);
		return ret;
	}
	return 0;
}