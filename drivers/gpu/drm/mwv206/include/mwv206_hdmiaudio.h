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
#ifndef _MWV206_HDMIAUDIO_H_
#define _MWV206_HDMIAUDIO_H_

#include <sound/pcm.h>
#include <linux/kfifo.h>


struct V206HDMIAUDIO012 {
	uint16_t *buf;
	long bufsize;
	long rp;
	long wp;
};

struct V206DEV139 {
	spinlock_t lock;
	void __iomem *regs;
	u32 flags;
#define V206HDMIAUDIO001 0x00000001
#define V206HDMIAUDIO002 0x00000002

	struct snd_card *card;
	struct snd_pcm *pcm;
	struct snd_pcm_substream *V206HDMIAUDIO003;
	struct snd_pcm_substream *V206HDMIAUDIO004;
	void (*V206HDMIAUDIO005)(struct V206DEV139*, size_t, size_t);

	unsigned V206HDMIAUDIO006;
	int V206HDMIAUDIO007;
	unsigned char *V206HDMIAUDIO008, *V206HDMIAUDIO009;
	int V206HDMIAUDIO010;
	long V206HDMIAUDIO011;
	struct V206HDMIAUDIO012 V206HDMIAUDIO012;

	void *V206HDMIAUDIO013;
	void *V206HDMIAUDIO014;
	dma_addr_t V206HDMIAUDIO015;
	unsigned V206HDMIAUDIO016;
	unsigned V206HDMIAUDIO017;
	unsigned channels;
	int V206HDMIAUDIO018;
	int V206HDMIAUDIO019;
	int V206HDMIAUDIO020;
	int V206HDMIAUDIO021;
	u8 V206HDMIAUDIO022;
	u8 cs[192][8];
	struct platform_device *op;
	unsigned int irq;
	V206DEV025 *pdata;
	struct snd_pcm_runtime runtime;
	unsigned long V206HDMIAUDIO023;
	unsigned long V206HDMIAUDIO024;
	int V206HDMIAUDIO025;
	unsigned long V206HDMIAUDIO026;
	struct timer_list timer;
	struct __kfifo fifo;
	int V206HDMIAUDIO027;
	int V206DEV140;

};

#endif