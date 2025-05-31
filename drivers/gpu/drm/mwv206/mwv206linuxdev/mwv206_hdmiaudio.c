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
#include <linux/kthread.h>

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/moduleparam.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/io.h>
#include <linux/delay.h>
#include <sound/core.h>

#include <sound/pcm.h>
#include <sound/info.h>
#include <sound/control.h>
#include <sound/initval.h>
#include <sound/asoundef.h>
#include <sound/pcm_iec958.h>
#include <asm/irq.h>
#include <linux/version.h>
#include "mwv206hal/mwv206dev.h"
#include "../include/mwv206reg.h"
#include "sethdmi_const_new.h"
#include "../include/mwv206_hdmiaudio.h"
#include "../mwv206hal/mwv206dev.h"

#define MAC206LXDEV029 (64*1024)
#define MAC206LXDEV030 (32*1024)

V206DEV025 *pDev_k;
int FUNC206LXDEV140(V206DEV025 *pDev, int arg)
{
	if (arg) {
		return FUNC206LXDEV116(pDev->V206DEV142);
	} else {
		return FUNC206LXDEV136(pDev->V206DEV142);
	}
}

static void FUNC206LXDEV017(V206DEV025 *pDev, int V206HDMIAUDIO027)
{
	V206DEV002(fc_acp0(V206HDMIAUDIO027), 0x00);
	V206DEV002(fc_acp1(V206HDMIAUDIO027), 0x01);
	V206DEV002(fc_acp2(V206HDMIAUDIO027), 0x9e);
	V206DEV002(fc_acp3(V206HDMIAUDIO027), 0x00);
	V206DEV002(fc_acp4(V206HDMIAUDIO027), 0x00);
	V206DEV002(fc_acp5(V206HDMIAUDIO027), 0x00);
	V206DEV002(fc_acp6(V206HDMIAUDIO027), 0x00);
	V206DEV002(fc_acp7(V206HDMIAUDIO027), 0x00);
	V206DEV002(fc_acp8(V206HDMIAUDIO027), 0x00);
	V206DEV002(fc_acp9(V206HDMIAUDIO027), 0x00);
	V206DEV002(fc_acp10(V206HDMIAUDIO027), 0x00);
	V206DEV002(fc_acp11(V206HDMIAUDIO027), 0x00);
	V206DEV002(fc_acp12(V206HDMIAUDIO027), 0x00);
	V206DEV002(fc_acp13(V206HDMIAUDIO027), 0x00);
	V206DEV002(fc_acp14(V206HDMIAUDIO027), 0x00);
	V206DEV002(fc_acp15(V206HDMIAUDIO027), 0x00);
	V206DEV002(fc_acp16(V206HDMIAUDIO027), 0x00);
}

static void FUNC206LXDEV020(V206DEV025 *pDev, int V206HDMIAUDIO027)
{
	V206DEV002(fc_audsconf(V206HDMIAUDIO027), 0x00);
	V206DEV002(fc_audsv(V206HDMIAUDIO027), 0x00);
	V206DEV002(fc_audsu(V206HDMIAUDIO027), 0x05);
	V206DEV002(fc_audschnls0(V206HDMIAUDIO027), 0x10);
	V206DEV002(fc_audschnls1(V206HDMIAUDIO027), 0x55);
	V206DEV002(fc_audschnls2(V206HDMIAUDIO027), 0x1a);
	V206DEV002(fc_audschnls3(V206HDMIAUDIO027), 0x01);
	V206DEV002(fc_audschnls4(V206HDMIAUDIO027), 0x22);
	V206DEV002(fc_audschnls5(V206HDMIAUDIO027), 0x01);
	V206DEV002(fc_audschnls6(V206HDMIAUDIO027), 0x12);
	V206DEV002(fc_audschnls7(V206HDMIAUDIO027), 0x3e);
	V206DEV002(fc_audschnls8(V206HDMIAUDIO027), 0x45);
}

static void FUNC206LXDEV018(V206DEV025 *pDev, int V206HDMIAUDIO027)
{
	V206DEV002(fc_rdrb0(V206HDMIAUDIO027), 0x00);
	V206DEV002(fc_rdrb1(V206HDMIAUDIO027), 0x10);
	V206DEV002(fc_rdrb2(V206HDMIAUDIO027), 0x00);
	V206DEV002(fc_rdrb3(V206HDMIAUDIO027), 0x1b);
	V206DEV002(fc_rdrb4(V206HDMIAUDIO027), 0x00);
	V206DEV002(fc_rdrb5(V206HDMIAUDIO027), 0x10);
	V206DEV002(fc_rdrb6(V206HDMIAUDIO027), 0x00);
	V206DEV002(fc_rdrb7(V206HDMIAUDIO027), 0x1e);
}

static void FUNC206LXDEV019(V206DEV025 *pDev, int V206HDMIAUDIO027)
{
	V206DEV002(fc_audiconf0(V206HDMIAUDIO027), 0x11);
	V206DEV002(fc_audiconf1(V206HDMIAUDIO027), 0x11);
	V206DEV002(fc_audiconf2(V206HDMIAUDIO027), 0x00);
	V206DEV002(fc_audiconf3(V206HDMIAUDIO027), 0x20);
}

static void FUNC206LXDEV030(V206DEV025 *pDev, int V206HDMIAUDIO027, unsigned int N, unsigned int C)
{
	V206DEV002(aud_n3(V206HDMIAUDIO027), (N >> 16) | (0x1 << 7));

	V206DEV002(aud_cts3(V206HDMIAUDIO027), (C >> 16) | (0x1 << 4));
	V206DEV002(aud_cts2(V206HDMIAUDIO027), C >> 8);
	V206DEV002(aud_cts1(V206HDMIAUDIO027), C);

	V206DEV002(aud_n3(V206HDMIAUDIO027), (N >> 16) | (0x1 << 7));
	V206DEV002(aud_n2(V206HDMIAUDIO027), N >> 8);
	V206DEV002(aud_n1(V206HDMIAUDIO027), N);
}

int FUNC206LXDEV138(V206DEV025 *pDev, int V206HDMIAUDIO027)
{
	if (pDev->audio[V206HDMIAUDIO027] == NULL) {
		return -1;
	}
	V206DEV002(aud_gp_conf0(V206HDMIAUDIO027), 0x01);
	mdelay(1);

	V206DEV002(aud_gp_conf1(V206HDMIAUDIO027), 0x3);
	V206DEV002(aud_gp_conf2(V206HDMIAUDIO027), 0x02);
	V206DEV002(fc_audsconf(V206HDMIAUDIO027), 0xf0);
	V206DEV002(fc_audsv(V206HDMIAUDIO027), 0xaf);
	V206DEV002(fc_audsu(V206HDMIAUDIO027), 0x5a);
	V206DEV002(fc_audschnls0(V206HDMIAUDIO027), 0x20);
	V206DEV002(fc_audschnls1(V206HDMIAUDIO027), 0x00);
	V206DEV002(fc_audschnls2(V206HDMIAUDIO027), 0x3e);
	V206DEV002(fc_audschnls3(V206HDMIAUDIO027), 0x12);
	V206DEV002(fc_audschnls4(V206HDMIAUDIO027), 0x01);
	V206DEV002(fc_audschnls5(V206HDMIAUDIO027), 0x02);
	V206DEV002(fc_audschnls6(V206HDMIAUDIO027), 0x20);
	V206DEV002(fc_audschnls7(V206HDMIAUDIO027), 0xc5);
	V206DEV002(fc_audschnls8(V206HDMIAUDIO027), 0x85);


	FUNC206LXDEV030(pDev, V206HDMIAUDIO027, 6144, 148500);

	FUNC206LXDEV019(pDev, V206HDMIAUDIO027);
	FUNC206LXDEV018(pDev, V206HDMIAUDIO027);
	FUNC206LXDEV020(pDev, V206HDMIAUDIO027);
	FUNC206LXDEV017(pDev, V206HDMIAUDIO027);
	return 0;
}

void FUNC206LXDEV021(V206DEV025 *pDev, int V206HDMIAUDIO027, unsigned int rate)
{
	static int srate[4] = {0};
	unsigned long V206DEV140;

	if (rate == 0) {
		rate = srate[V206HDMIAUDIO027];
	} else {
		srate[V206HDMIAUDIO027] = rate;
	}

	V206DEV140 = pDev->V206DEV140[V206HDMIAUDIO027];
	switch (rate) {
	case 32000:

		V206DEV140 = V206DEV140 / 100 * 1108051656272 / 10000000000;
		switch (V206DEV140) {
		case 25200000:
			FUNC206LXDEV030(pDev, V206HDMIAUDIO027, 4576, 28125);
			break;
		case 74175824:
			FUNC206LXDEV030(pDev, V206HDMIAUDIO027, 11648, 210937);
			break;
		case 148351648:
			FUNC206LXDEV030(pDev, V206HDMIAUDIO027, 11648, 421875);
			break;
		case 296703296:
			FUNC206LXDEV030(pDev, V206HDMIAUDIO027, 5824, 421875);
			break;
		case 297000000:
			FUNC206LXDEV030(pDev, V206HDMIAUDIO027, 3072, 222750);
			break;
		default:
			if (pDev->V206DEV140[V206HDMIAUDIO027]) {
				FUNC206LXDEV030(pDev, V206HDMIAUDIO027, 4096, V206DEV140 / 1000);
			} else {
				FUNC206LXDEV030(pDev, V206HDMIAUDIO027, 4096, 148500);
			}
			break;
		}
		break;
	case 44100:

		V206DEV140 = V206DEV140 / 100 * 1107553254102 / 10000000000;
		switch (V206DEV140) {
		case 25200000:
			FUNC206LXDEV030(pDev, V206HDMIAUDIO027, 7007, 31250);
			break;
		case 74175824:
			FUNC206LXDEV030(pDev, V206HDMIAUDIO027, 17836, 234375);
			break;
		case 148351648:
			FUNC206LXDEV030(pDev, V206HDMIAUDIO027, 8918, 234375);
			break;
		case 296703296:
			FUNC206LXDEV030(pDev, V206HDMIAUDIO027, 4459, 234375);
			break;
		case 297000000:
			FUNC206LXDEV030(pDev, V206HDMIAUDIO027, 4704, 247500);
			break;
		default:
			if (pDev->V206DEV140[V206HDMIAUDIO027]) {
				FUNC206LXDEV030(pDev, V206HDMIAUDIO027, 6272, V206DEV140 / 1000);
			} else {
				FUNC206LXDEV030(pDev, V206HDMIAUDIO027, 6272, 165000);
			}
			break;
		}
		break;

	case 48000:

		V206DEV140 = V206DEV140 / 100 * 1109240456842 / 10000000000;
		switch (V206DEV140) {
		case 25200000:
			FUNC206LXDEV030(pDev, V206HDMIAUDIO027, 6864, 28125);
			break;
		case 74175824:
			FUNC206LXDEV030(pDev, V206HDMIAUDIO027, 11648, 140625);
			break;
		case 148351648:
			FUNC206LXDEV030(pDev, V206HDMIAUDIO027, 5824, 140625);
			break;
		case 296703296:
			FUNC206LXDEV030(pDev, V206HDMIAUDIO027, 5824, 281250);
			break;
		case 297000000:
			FUNC206LXDEV030(pDev, V206HDMIAUDIO027, 5120, 247500);
			break;
		default:
			if (pDev->V206DEV140[V206HDMIAUDIO027]) {
				FUNC206LXDEV030(pDev, V206HDMIAUDIO027, 6144, V206DEV140 / 1000);
			} else {
				FUNC206LXDEV030(pDev, V206HDMIAUDIO027, 6144, 148500);
			}
			break;
		}
		break;
	case 88200:
		break;
	case 96000:
		break;
	case 176400:
		break;
	case 192000:
		break;
	default:
		break;
	}
	mdelay(1);
}

static void FUNC206LXDEV025(struct V206DEV139 *mwv)
{

	unsigned int i, period = 512;
	unsigned int  start = 0;
	int rec = -1;
	int V206HDMIAUDIO027 =  mwv->V206HDMIAUDIO027;
	V206DEV025 *pDev = mwv->pdata;

	rec = V206DEV001(0x403434 + (V206HDMIAUDIO027 << 8));
	rec = rec >> 16;
	period = (1000 - rec);
	if (period != 0) {
		mwv->V206HDMIAUDIO006 += 2 * period ;
	} else {
		mwv->V206HDMIAUDIO006 += (mwv->V206HDMIAUDIO003->runtime->rate * 4 / HZ) * 32 / 32;
		return ;
	}

	for (i = 0 ; i < period ; i++) {
		if (__kfifo_out(&mwv->fifo, &start, 2) == 0) {
			return ;
		}

		start = start << 8;
		V206DEV002(Audio_FIFOAddr(V206HDMIAUDIO027), start);
		start = 0;
	}
}

#ifdef setup_timer
static void FUNC206LXDEV023(unsigned long data)
#else
static void FUNC206LXDEV023(struct timer_list *data)
#endif
{
	unsigned long flags;
#ifdef setup_timer
	struct V206DEV139 *mwv = (struct V206DEV139 *)data;
#else
	struct V206DEV139 *mwv = from_timer(mwv, data, timer);
#endif
	spin_lock_irqsave(&mwv->lock, flags);
	if (mwv->V206HDMIAUDIO003 != NULL) {
		struct snd_pcm_substream *V206HDMIAUDIO003;
		FUNC206LXDEV025(mwv);
		V206HDMIAUDIO003 = mwv->V206HDMIAUDIO003;
		spin_unlock_irqrestore(&mwv->lock, flags);
		snd_pcm_period_elapsed(V206HDMIAUDIO003);
	} else {
		spin_unlock_irqrestore(&mwv->lock, flags);
	}
	mod_timer(&mwv->timer, jiffies + 1);
}

static int FUNC206LXDEV036(struct snd_pcm_substream *substream,
	int cmd)
{
	struct V206DEV139 *mwv = snd_pcm_substream_chip(substream);
	unsigned long flags;
	int ret = 0;

	switch (cmd) {
	case SNDRV_PCM_TRIGGER_START:

		spin_lock_irqsave(&mwv->lock, flags);
		mwv->V206HDMIAUDIO003 = substream;
		mwv->V206HDMIAUDIO006 = 0;
		substream->runtime->delay = substream->runtime->period_size;
		spin_unlock_irqrestore(&mwv->lock, flags);
		break;

	case SNDRV_PCM_TRIGGER_STOP:
		spin_lock_irqsave(&mwv->lock, flags);
		mwv->V206HDMIAUDIO003 = NULL;
		spin_unlock_irqrestore(&mwv->lock, flags);
		break;

	default:
		V206KDEBUG002("[ERROR] %s: error cmd %d.\n", __FUNCTION__, cmd);
		ret = -EINVAL;
		break;
	}

	return ret;
}

static int FUNC206LXDEV035(struct snd_pcm_substream *substream)
{
	struct V206DEV139 *mwv = snd_pcm_substream_chip(substream);
	struct snd_pcm_runtime *runtime = substream->runtime;
	unsigned int size = snd_pcm_lib_buffer_bytes(substream);
	unsigned long flags;
	V206DEV025 *pDev = mwv->pdata;

	spin_lock_irqsave(&mwv->lock, flags);
	FUNC206LXDEV021(pDev, mwv->V206HDMIAUDIO027, runtime->rate);

	mwv->flags |= V206HDMIAUDIO001;
	runtime->hw.fifo_size = 2 * 1024;

	mwv->V206HDMIAUDIO007 = size;
	mwv->channels = runtime->channels;
	mwv->V206HDMIAUDIO013  = runtime->dma_area;
	mwv->V206HDMIAUDIO014  = substream->dma_buffer.area;
	mwv->V206HDMIAUDIO015 = substream->dma_buffer.addr;
	mwv->V206HDMIAUDIO016 = snd_pcm_lib_period_bytes(substream);
	mwv->V206HDMIAUDIO017 = snd_pcm_lib_buffer_bytes(substream);

	spin_unlock_irqrestore(&mwv->lock, flags);

	return 0;
}

static snd_pcm_uframes_t FUNC206LXDEV034(struct snd_pcm_substream *substream)
{
	struct V206DEV139 *mwv = snd_pcm_substream_chip(substream);
	return bytes_to_frames(substream->runtime, mwv->V206HDMIAUDIO006 % mwv->V206HDMIAUDIO017);
}

#define MAC206LXDEV010    (4 * 1024)
#define MAC206LXDEV028    64
#define MAC206LXDEV027    1024

#define MAC206LXDEV026     16
#define MAC206LXDEV025     (MAC206LXDEV010 / MAC206LXDEV028)

static struct snd_pcm_hardware mwv206_audio_pcm_hw = {

	.info               = (SNDRV_PCM_INFO_INTERLEAVED | SNDRV_PCM_INFO_BLOCK_TRANSFER),
	.formats            = SNDRV_PCM_FMTBIT_S16,
	.rates              = SNDRV_PCM_RATE_44100,
	.rate_min           = 32000,
	.rate_max           = 48000,
	.channels_min       = 2,
	.channels_max       = 2,
	.buffer_bytes_max   = MAC206LXDEV010,
	.period_bytes_min   = MAC206LXDEV028,
	.period_bytes_max   = MAC206LXDEV027,
	.periods_min        = MAC206LXDEV026,
	.periods_max        = MAC206LXDEV025,
};

static int FUNC206LXDEV033(struct snd_pcm_substream *substream)
{
	struct V206DEV139 *mwv = snd_pcm_substream_chip(substream);
	struct snd_pcm_runtime *runtime = substream->runtime;
	V206DEV025 *pDev = mwv->pdata;
	int V206HDMIAUDIO027 = mwv->V206HDMIAUDIO027, ret;
	unsigned long flags;

	spin_lock_irqsave(&mwv->lock, flags);
	ret = snd_pcm_limit_hw_rates(runtime);
	if (ret < 0) {
		spin_unlock_irqrestore(&mwv->lock, flags);
		return ret;
	}

	ret = snd_pcm_hw_constraint_integer(runtime,
			SNDRV_PCM_HW_PARAM_PERIODS);
	if (ret < 0) {
		spin_unlock_irqrestore(&mwv->lock, flags);
		return ret;
	}


	ret = snd_pcm_hw_constraint_minmax(runtime,
			SNDRV_PCM_HW_PARAM_BUFFER_SIZE,
			0, substream->dma_buffer.bytes);
	if (ret < 0) {
		spin_unlock_irqrestore(&mwv->lock, flags);
		return ret;
	}

	FUNC206LXDEV138(pDev, V206HDMIAUDIO027);

	mwv->V206HDMIAUDIO003 = substream;
	runtime->hw = mwv206_audio_pcm_hw;
	snd_pcm_set_sync(substream);
	spin_unlock_irqrestore(&mwv->lock, flags);

	return 0;
}

static int FUNC206LXDEV032(struct snd_pcm_substream *substream)
{
	struct V206DEV139 *mwv = snd_pcm_substream_chip(substream);
	unsigned long flags;

	spin_lock_irqsave(&mwv->lock, flags);
	mwv->V206HDMIAUDIO003 = NULL;
	spin_unlock_irqrestore(&mwv->lock, flags);

	return 0;
}

static int FUNC206LXDEV028(struct snd_pcm_substream *substream,
	struct snd_pcm_hw_params *hw_params)
{
	return snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
}

static int FUNC206LXDEV027(struct snd_pcm_substream *substream)
{
	return snd_pcm_lib_free_pages(substream);
}

int FUNC206LXDEV139(struct snd_pcm_substream *substream, int channel,
	snd_pcm_uframes_t pos, void __user *buf, snd_pcm_uframes_t count)
{
	void *dst;
	int ret;
	unsigned int real_bytes;
	struct V206DEV139 *mwv = snd_pcm_substream_chip(substream);
	unsigned long flags;

#if LINUX_VERSION_CODE <= KERNEL_VERSION(4, 5, 58)
	struct snd_pcm_runtime *runtime = substream->runtime;
	real_bytes = frames_to_bytes(runtime, count);
#else
	real_bytes = count ;
#endif
	dst = mwv->V206HDMIAUDIO013;
	ret = copy_from_user(dst, buf, real_bytes);
	spin_lock_irqsave(&mwv->lock, flags);
	if (mwv->fifo.data) {
		ret = __kfifo_in(&mwv->fifo, dst, real_bytes);
	}
	spin_unlock_irqrestore(&mwv->lock, flags);

	return 0;
}

static struct snd_pcm_ops mwv206_audio_playback_ops = {
	.open         =   FUNC206LXDEV033,
	.close        =   FUNC206LXDEV032,
	.ioctl        =   snd_pcm_lib_ioctl,
	.hw_params    =   FUNC206LXDEV028,
	.hw_free      =   FUNC206LXDEV027,
	.prepare      =   FUNC206LXDEV035,
	.trigger      =   FUNC206LXDEV036,
	.pointer      =   FUNC206LXDEV034,
	//.copy         =   FUNC206LXDEV139,
};

static int FUNC206LXDEV031(struct V206DEV139 *mwv)
{
	struct snd_pcm *pcm;
	int err;

	err = snd_pcm_new(mwv->card, "mwv206", 0, 1, 0, &pcm);
	if (err < 0) {
		return err;
	}

	snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &mwv206_audio_playback_ops);


	pcm->private_data = mwv;
	pcm->info_flags = 0;
	strcpy(pcm->name, mwv->card->shortname);
	mwv->pcm = pcm;

/*
	snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_CONTINUOUS,
			snd_dma_continuous_data(GFP_KERNEL),
			128 * 1024, 1024 * 1024);
*/

	return 0;
}



static int FUNC206LXDEV022(struct snd_card *card,
		int irq, struct V206DEV139 **rmwv)
{
	struct V206DEV139 *mwv;

	*rmwv = NULL;
	mwv = kzalloc(sizeof(*mwv), GFP_KERNEL);
	if (mwv == NULL) {
		return -ENOMEM;
	}

	spin_lock_init(&mwv->lock);
	mwv->card = card;


	mwv->V206HDMIAUDIO019 = 128;
	mwv->V206HDMIAUDIO020 = 200;
	mwv->V206HDMIAUDIO021 = 0;



	*rmwv = mwv;
	return 0;
}

static int FUNC206LXDEV079(struct device *dev, V206DEV025 *pri, int V206HDMIAUDIO027)
{
	struct snd_card *card;
	struct V206DEV139 *mwv;
	int err;

	err = snd_card_new(dev, -1, NULL, THIS_MODULE, 0, &card);
	if (err < 0) {
		V206KDEBUG002("[ERROR] HDA-MWV206 new card failed(%d).\n", err);
		return err;
	}

	sprintf(card->driver, "HDA-MWV206:%d", V206HDMIAUDIO027);
	sprintf(card->shortname, "HDA-MWV206 : %d ", V206HDMIAUDIO027);
	sprintf(card->longname, "%s at 0x%02lx:0x%x, irq %d",
			card->shortname,
			0 & 0xffL,
			0,
			0);
	err = FUNC206LXDEV022(card, 0, &mwv);
	if (err < 0) {
		V206KDEBUG002("[ERROR] HDA-MWV206 create failed(%d).\n", err);
		goto out_err;

	}
	mwv->pdata = pri;
	err = FUNC206LXDEV031(mwv);
	if (err < 0) {
		V206KDEBUG002("[ERROR] HDA-MWV206 pcm failed(%d).\n", err);
		goto out_err;
	}
	err = snd_card_register(card);
	if (err < 0) {
		V206KDEBUG002("[ERROR] HDA-MWV206 registration failed(%d).\n", err);
		goto out_err;
	}
	pri->audio[V206HDMIAUDIO027] = mwv;
	mwv->V206HDMIAUDIO027 = V206HDMIAUDIO027;
	__kfifo_alloc(&mwv->fifo, 4 * 1024, 1, GFP_KERNEL);
	if (!mwv->fifo.data) {
		V206KDEBUG002("[ERROR] %s kfifo alloc fail.\n", __FUNCTION__);
		err = -1;
		goto out_err;
	}
	return 0;

out_err:
	V206KDEBUG002("[ERROR] HDA-MWV206 sbus probe failed.\n");
	snd_card_free(card);
	return err;

}


int FUNC206LXDEV141(V206DEV025 *pDev, long args)
{
	if (!pDev->V206DEV155) {
		V206KDEBUG003("[INFO] 16M register bar is detected, HDMI audio is disabled.\n");
		return 0;
	}
	FUNC206LXDEV140(pDev, 1);
	if (pDev->V206DEV141[args] == 0 && audio_dev != NULL && pDev->V206DEV140[args]) {
		int ret = 0;
		ret = FUNC206LXDEV079(audio_dev, pDev, args);
		if (ret) {
			V206KDEBUG002("[ERROR] HDM-MWV206 hdmi probe failed(%d).\n", ret);
			FUNC206LXDEV140(pDev, 0);
			return -1;
		}

		pDev_k = pDev;
#ifdef setup_timer
		setup_timer(&pDev->audio[args]->timer, FUNC206LXDEV023, (unsigned long)pDev->audio[args]);
#else
		timer_setup(&pDev->audio[args]->timer, FUNC206LXDEV023, 0);
#endif

		mod_timer(&pDev->audio[args]->timer, jiffies + 1);
		pDev->V206DEV141[args] = 1;
		FUNC206LXDEV140(pDev, 0);
		return 0;
	}
	FUNC206LXDEV140(pDev, 0);
	return 0;
}

int FUNC206LXDEV142(V206DEV025 *pDev, long args)
{
	if (!pDev->V206DEV155) {
		return 0;
	}
	FUNC206LXDEV140(pDev, 1);
	if (pDev->V206DEV141[args]) {
		if (pDev->audio[args]->card) {
			del_timer_sync(&pDev->audio[args]->timer);
			if (pDev->audio[args]->fifo.data) {
				__kfifo_free(&pDev->audio[args]->fifo);
			}
			snd_card_free(pDev->audio[args]->card);
			pDev->V206DEV141[args] = 0;
		}
	}
	FUNC206LXDEV140(pDev, 0);
	return 0;
}

void FUNC206LXDEV024(void)
{
	if (pDev_k != NULL) {
		int i;
		V206DEV025 *pDev = pDev_k;
		FUNC206LXDEV140(pDev, 1);
		for (i = 0; i < 4; i++) {
			if (pDev->V206DEV141[i]) {
				if (pDev->audio[i]->card) {
					del_timer_sync(&pDev->audio[i]->timer);
					if (pDev->audio[i]->fifo.data) {
						__kfifo_free(&pDev->audio[i]->fifo);
					}
					snd_card_free(pDev->audio[i]->card);
					pDev->V206DEV141[i] = 0;
				}
			}
		}
		FUNC206LXDEV140(pDev, 0);
		pDev_k = NULL;
	}
}