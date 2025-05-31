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
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/pci.h>
#include <linux/mod_devicetable.h>
#include <linux/fs.h>
#include <linux/idr.h>
#include <linux/syscalls.h>
#include <linux/spinlock.h>
#include <linux/interrupt.h>

#include <asm/uaccess.h>
#include "../include/glj.h"
#include "mwv206.h"
#include "../include/mwv206_internal.h"
#include "../include/mwv206config.h"
#include "../include/mwv206reg.h"
#include "mwv206hal/mwv206dev.h"
#include "mwv206hal/mwv206dec.h"
#include <linux/delay.h>

#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/jiffies.h>
#include <linux/pci.h>
#include <drm/drm_edid.h>
struct device *event_dev;

static struct task_struct *event_task;
#define MAC206LXDEV019    (0x405500 + 0x0)
#define MAC206LXDEV015      (0x405500 + 0x4)
#define MAC206LXDEV020  (0x405500 + 0x8)
#define MAC206LXDEV021   (0x405500 + 0xc)
#define MAC206LXDEV016      (0x405500 + 0x10)
#define MAC206LXDEV018   (0x405500 + 0x14)
#define MAC206LXDEV017   (0x405500 + 0x18)
#define MAC206LXDEV022   (0x405500 + 0x1c)
#define MAC206LXDEV014     (0x405500 + 0x28)
#define MAC206LXDEV013    (0x405920)

int FUNC206LXDEV151(V206DEV025 *pDev, int arg)
{
	if (arg) {
		return FUNC206LXDEV116(pDev->V206DEV142);
	} else {
		return FUNC206LXDEV136(pDev->V206DEV142);
	}
}
static int FUNC206LXDEV051(V206DEV025 *pDev, unsigned char slave, unsigned char reg,
	unsigned char *buff, unsigned int len)
{
	unsigned char data;
	unsigned int i;
	int timeout;
	if (len > 32) {
		len = 32;
	}

	V206DEV002(MAC206LXDEV019, 0);
	udelay(200);
	V206DEV002(MAC206LXDEV019, 1);
	V206DEV002(MAC206LXDEV022, reg);
	V206DEV002(MAC206LXDEV018, 1);
	V206DEV002(MAC206LXDEV017, 0);
	V206DEV002(MAC206LXDEV015, 0x02000001 | ((slave & 0xfe) << 16));
	timeout = 1000;
	while (V206DEV001(MAC206LXDEV018) == 0 && timeout--) {
		udelay(1);
	}

	if (V206DEV001(MAC206LXDEV017)) {
		return -2;
	}

	V206DEV002(MAC206LXDEV018, 1);
	V206DEV002(MAC206LXDEV017, 0);
	V206DEV002(MAC206LXDEV015, 0x03010000 | ((slave & 0xfe) << 16) | len);
	timeout = 1000;
	while (V206DEV001(MAC206LXDEV018) == 0 && timeout--) {
		udelay(len);
	}
	if (V206DEV001(MAC206LXDEV017)) {
		return -4;
	}
	timeout = 1000;
	while (V206DEV001(MAC206LXDEV020) != len &&  timeout--) {
		udelay(len);
	}
	if (V206DEV001(MAC206LXDEV020) != len) {
		return -5;
	}
	for (i = 0; i < len; i++) {
		data = V206DEV001(MAC206LXDEV021);
		if (buff) {
			buff[i] = data;
		}
	}

	return 0;
}

bool FUNC206LXDEV146(const unsigned char *const block)
{
	uint8_t checksum = 0;
	int i;
	for (i = 0; i < EDID_LENGTH; i++) {
		checksum += block[i];
	}
	return checksum;
}

int FUNC206LXDEV152(V206DEV025 *pDev, int i2c_chan, unsigned char  *ddc_data, int *out_len)
{
	int ret = 0;
	int i = 0;
	int len = 0;
	if (pDev == NULL) {
		return -1;
	}

	if ((NULL == ddc_data) || (NULL == out_len)) {
		V206KDEBUG002("[ERROR] ddc read null\n");
		return -1;
	}
	*out_len = 0;

	V206DEV002(MAC206LXDEV013, i2c_chan);
	for (i = 0; i < EDID_LENGTH; i += 32) {
		ret = FUNC206LXDEV051(pDev, 0xa0, i, ddc_data + i, 32);
		if (ret) {
			return -1;
		}
	}

	len = EDID_LENGTH;
	if (ddc_data[0x7e] < V206CONFIG010 / 128 && ddc_data[0x7e]) {
		for (i = EDID_LENGTH; i < (ddc_data[0x7e] + 1)*EDID_LENGTH; i += 32) {
			ret = FUNC206LXDEV051(pDev, 0xa0, i, ddc_data + i, 32);
			if (ret) {
				return -1;
			}
		}
		len += ddc_data[0x7e] * EDID_LENGTH;
	}
	if (ddc_data[0x7e] >= V206CONFIG010 / 128) {

		return -1;
	}

	*out_len = len;

	return 0;
}

bool FUNC206LXDEV150(struct edid *edid)
{
	int i;
	u8 *raw = (u8 *)edid;

	if (!edid) {
		return false;
	}

	for (i = 0; i <= edid->extensions; i++) {
		if (!drm_edid_block_valid(raw + i * EDID_LENGTH, i, false, NULL)) {
			return false;
		}
	}
	return true;
}



int FUNC206LXDEV147(V206DEV025 *pDev)
{
	int i, j, ret, size, changed = 0;
	int disconnect = 0;
	char *edid = pDev->V206DEV148;
	char *check = pDev->V206DEV149;
	for (i = 0; i < 8; i++) {
		if (pDev->V206DEV156 & (1 << i)) {
			disconnect++;
			continue;
		}
		ret = FUNC206LXDEV152(pDev, i, edid, &size);
		pDev->V206DEV147.changed[i] = 0;
		if (!ret) {
			if (memcmp(pDev->V206DEV147.edid[i], edid, size)) {

				memcpy(check, edid, size);
				if (FUNC206LXDEV150((struct edid *)check)) {
					memcpy(pDev->V206DEV147.edid[i], edid, size);
					pDev->V206DEV147.changed[i] = 1;
					pDev->V206DEV147.connect_status[i] = 1;
					changed = 1;
				}
			}
		} else {
			if (pDev->V206DEV147.connect_status[i] ==
					1) {
				for (j = 0; j < 50; j++) {
					ret = FUNC206LXDEV152(pDev, i, edid, &size);
					if (!ret) {
						break;
					}
					mdelay(1);
				}
				if (ret) {
					changed = 1;
					pDev->V206DEV147.connect_status[i] = 0;
					pDev->V206DEV147.changed[i] = 1;
					disconnect++;
					memset(pDev->V206DEV147.edid[i], 0, V206CONFIG010);
				}
			} else {
				disconnect++;
			}
		}
	}
	pDev->V206DEV147.isfake = (disconnect == 8);
	return changed;
}

int FUNC206LXDEV149(V206DEV025 *pDev, unsigned long userdata)
{
	int ret;
	FUNC206LXDEV151(pDev, 1);
	ret = copy_to_user((void __user *)userdata, &pDev->V206DEV147, sizeof(EDID));
	FUNC206LXDEV151(pDev, 0);
	if (ret != 0) {
		V206KDEBUG002("[ERROR] MWV206 get edid failed, ret = %d.", ret);
		return ret;
	} else {
		return 0;
	}
}

int FUNC206LXDEV148(void *pData)
{
	char *event_string = "HOTPLUG=1";
	char *envp[] = { event_string, NULL };
	int edid_changed = 0;
	V206DEV025 *pDev = (V206DEV025 *)pData;
	while (!kthread_should_stop()) {
		FUNC206LXDEV151(pDev, 1);
		edid_changed = FUNC206LXDEV147(pDev);
		FUNC206LXDEV151(pDev, 0);
		if (edid_changed) {
			kobject_uevent_env(&event_dev->kobj, KOBJ_CHANGE, envp);
		}
		msleep(2000);
	}
	return 0;
}

void FUNC206LXDEV052(V206DEV025 *pDev)
{
	int err;
	event_task = kthread_create(FUNC206LXDEV148, pDev, "mwv206_edid_thread");
	if (IS_ERR(event_task)) {
		V206KDEBUG002("[ERROR] Unable to start kernel thread.\n");
		err = PTR_ERR(event_task);
		event_task = NULL;
		return ;
	}
	wake_up_process(event_task);
}

void FUNC206LXDEV053(void)
{
	if (event_task) {
		kthread_stop(event_task);
		event_task = NULL;
	}
}