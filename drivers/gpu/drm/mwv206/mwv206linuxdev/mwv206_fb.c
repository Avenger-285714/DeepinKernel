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
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/string.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/ioport.h>
#include <linux/vmalloc.h>
#include <linux/device.h>
#include <linux/ctype.h>
#include <linux/pci.h>
#include <asm/io.h>
#include <linux/uaccess.h>
#include <linux/fb.h>
#include <linux/delay.h>
#include "../mwv206hal/mwv206dev.h"
#include "../include/mwv206reg.h"
#include "../include/mwv206config.h"
#include "common.h"
#include "../include/mwv206devconfig.h"
#include "../include/glj.h"
#include "../include/displaymode.h"
#include "../include/jmdev/jmgpuoverlay.h"
#include "../mwv206hal/cputype.h"

#include <linux/aperture.h>
#include <linux/platform_device.h>

#include <drm/drm_aperture.h>
#include <drm/drm_drv.h>
#include <drm/drm_print.h>

#ifndef _MWV206_CPU_
#define _MWV206_CPU_ 0
#endif /* _MWV206_CPU_ */

#ifndef _MWV206_OS_
#define _MWV206_OS_ _MWV206_DEEPIN_
#endif /* _MWV206_OS_ */

enum V206FB001 {
	V206FB002 = (0),
	V206FB003 = (1),
};

static int FUNC206LXDEV081(unsigned V206FB010, unsigned red, unsigned green,
		unsigned blue, unsigned transp, struct fb_info *info);
static void FUNC206LXDEV004(struct fb_info *info, const struct fb_fillrect *rect);
static void FUNC206LXDEV003(struct fb_info *info, const struct fb_copyarea *area);
static void FUNC206LXDEV015(struct fb_info *p, const struct fb_image *image);

static struct fb_ops mwv206fb_ops = {
	.owner              = THIS_MODULE,
	.fb_setcolreg       = FUNC206LXDEV081,
	.fb_fillrect        = FUNC206LXDEV004,
	.fb_copyarea        = FUNC206LXDEV003,
	.fb_imageblit       = FUNC206LXDEV015,
};

static void FUNC206LXDEV004(struct fb_info *info, const struct fb_fillrect *rect)
{
	struct V206DEV026 *V206FB005 = info->par;
	V206DEV025 *pDev = pci_get_drvdata(V206FB005->V206DEV103);
	int ret;

	ret = FUNC206LXDEV154(pDev, (unsigned long)V206FB005->mmio_base,
			V206FB005->V206DEV181,
			V206FB005->V206DEV182,
			V206FB005->V206KG2D001,
			rect->dx, rect->dy,
			rect->width, rect->height,
			rect->color,
			0xffffffff,
			rect->rop);
	if (ret) {
		cfb_fillrect(info, rect);
	}
}

static void FUNC206LXDEV003(struct fb_info *info, const struct fb_copyarea *area)
{
	struct V206DEV026 *V206FB005 = info->par;
	V206DEV025 *pDev = pci_get_drvdata(V206FB005->V206DEV103);
	int ret;

	ret = FUNC206LXDEV145(pDev, (unsigned long)V206FB005->mmio_base,
			V206FB005->V206DEV181, V206FB005->V206DEV181,
			V206FB005->V206DEV182, V206FB005->V206DEV182,
			V206FB005->V206KG2D001,
			area->sx, area->sy,
			area->dx, area->dy,
			area->width, area->height,
			0xffffffff, GXcopy);
	if (ret) {
		cfb_copyarea(info, area);
	}
}

static void FUNC206LXDEV015(struct fb_info *info, const struct fb_image *image)
{
	cfb_imageblit(info, image);
}

static int FUNC206LXDEV094(V206DEV025 *pDev, unsigned int addr)
{
	struct V206DEV026 *V206FB005 = pDev->fb_info;
	V206IOCTL159 V206DEV143;

	V206DEV143.addr = addr;
	V206DEV143.V206FB011 = V206FB005->crtc;
	V206DEV143.format = V206FB005->pixel_format;
	V206DEV143.V206KG2D033 = V206FB005->V206DEV182;
	V206DEV143.width = V206FB005->width;
	V206DEV143.height = V206FB005->height;
	V206DEV143.vsync = 1;

	return FUNC206HAL388(pDev, (long)&V206DEV143);
}

static int FUNC206LXDEV081(unsigned V206FB010, unsigned red, unsigned green,
		unsigned blue, unsigned transp, struct fb_info *info)
{
	if (V206FB010 >= info->cmap.len) {
		return 1;
	}

	if (V206FB010 < 16) {
		if (info->var.bits_per_pixel == 32) {
			red >>= 8;
			green >>= 8;
			blue >>= 8;
			((u32 *)(info->pseudo_palette))[V206FB010] =
				(red << info->var.red.offset)       |
				(green << info->var.green.offset)   |
				(blue << info->var.blue.offset);
		}
	}

	return 0;
}

static int FUNC206LXDEV080(struct fb_info *info)
{
	struct V206DEV026 *V206FB005 = info->par;
#if (_MWV206_OS_ == _MWV206_DEEPIN_)
	info->skip_vt_switch = true;
#endif
	info->pseudo_palette = V206FB005->pseudo_palette;
	info->flags = FBINFO_HWACCEL_COPYAREA | FBINFO_HWACCEL_FILLRECT;
	info->fbops = &mwv206fb_ops;
	info->screen_base = V206FB005->V206DEV178;
	info->screen_size = V206FB005->screen_size;

	strlcpy(info->fix.id, V206FB005->name, sizeof(info->fix.id));
	info->fix.smem_start = V206FB005->V206DEV177 + V206FB005->V206DEV181;
	info->fix.smem_len = V206FB005->V206DEV179;
	info->fix.type = FB_TYPE_PACKED_PIXELS;
	info->fix.visual = FB_VISUAL_TRUECOLOR;
	info->fix.mmio_start = V206FB005->V206DEV180;
	info->fix.mmio_len = V206FB005->mmio_len;
	info->fix.accel = FB_ACCEL_NONE;
	info->fix.line_length = V206FB005->V206DEV182;


	info->var.activate = FB_ACTIVATE_NOW;
	info->var.vmode = FB_VMODE_NONINTERLACED;
	info->var.xres = V206FB005->width;
	info->var.yres = V206FB005->height;
	info->var.xres_virtual = V206FB005->width;
	info->var.yres_virtual = V206FB005->height;
	if (V206FB005->pixel_format == V206FB002) {
		info->var.bits_per_pixel = 32;
		info->var.red.length = 8;
		info->var.green.length = 8;
		info->var.blue.length = 8;
		info->var.transp.length = 8;
		info->var.red.offset = 16;
		info->var.green.offset = 8;
		info->var.blue.offset = 0;
		info->var.transp.offset = 24;
	}

	return 0;
}

static MWV206PortConfig *jmgpuCfgGetPortConfig(MWV206DevConfig *V206DEV184, int type, int index)
{
	switch (type) {
	case V206CONFIG011:  return &V206DEV184->vga[index];
	case V206CONFIG013: return &V206DEV184->hdmi[index];
	case V206CONFIG014: return &V206DEV184->lvds[index];
	case V206CONFIG012:  return &V206DEV184->dvo[index];
	default: {
			 return NULL;
		 }
	}
}

static int jmgpuCfgGetOutputport(int type, int index)
{
	switch (type) {
	case V206CONFIG011:  return V206GLJ034 + index;
	case V206CONFIG013: return V206GLJ038 + index;
	case V206CONFIG014: return V206GLJ036 + index;
	case V206CONFIG012:  return V206GLJ032 + index;
	default: {
			 return -1;
		 }
	}
}

static void FUNC206LXDEV084(V206DEV025 *priv, int V206FB011,
		int type, int index, MWV206DevConfig *V206DEV184)
{
	MWV206PortConfig *V206FB007;
	V206IOCTL172 port;
	V206IOCTL173 V206FB009;
	uint8_t flags, V206FB008;

	V206DEV005("[INFO] %s: type = %d, index = %d.\n", __FUNCTION__, type, index);

	V206FB007 = jmgpuCfgGetPortConfig(V206DEV184, type, index);
	flags = V206FB007->flags;

	if (!V206DEVCONFIG036(flags)) {
		return;
	}

	V206FB008 = jmgpuCfgGetOutputport(type, index);

	port.enable = 1;
	port.V206FB008 = V206FB008;
	port.V206FB011 = V206FB011;
	port.dualpixel = V206DEVCONFIG037(flags);
	if ((1 == port.dualpixel)
			&& ((V206GLJ038 == V206FB008) || (V206GLJ040 == V206FB008))) {
		port.dualpixel = 0;
	}
	FUNC206HAL393(priv, (long)&port);

	if (V206FB008 == V206GLJ036 || V206FB008 == V206GLJ037) {
		V206FB009.V206FB008 = V206FB008;
		V206FB009.type = DP_LVDS_MODE;
		V206FB009.value = V206FB007->bitmode;
		FUNC206HAL394(priv, (long)&V206FB009);
	}
	return;
}

int mwv206fb_clear(struct V206DEV026 *V206FB005)
{
	struct fb_info *info = V206FB005->info;
	struct fb_fillrect rect;

	rect.dx = 0;
	rect.dy = 0;
	rect.width = V206FB005->width;
	rect.height = V206FB005->height;
	rect.color = 0;
	rect.rop = 3;
	FUNC206LXDEV004(info, &rect);

	return 0;
}

int mwv206fb_sethdmimode(V206DEV025 *priv, int V206FB011, int V206HDMIAUDIO027, V206IOCTL161 *p_mode, int dualpixel)
{
	V206IOCTL168 V206FB004;
	int mode = p_mode->mode;
	V206FB004.V206HDMIAUDIO027 = V206HDMIAUDIO027;
	V206FB004.V206FB011 = V206FB011;
	V206FB004.mode = mode;
	V206FB004.dualpixel = 0;
	if ((mode <= V206GLJ003) || (mode >  V206GLJ028)) {
		V206KDEBUG002("[ERROR] Invalid HDMI mode!.\n");
		return -ENOMEM;
	}

	if (!V206DEVCONFIG036(priv->V206DEV105.hdmi[V206HDMIAUDIO027].flags)) {
		return 0;
	}
	if (mode == V206GLJ028) {
		V206FB004.htotal = p_mode->htotal;
		V206FB004.hactive = p_mode->hactive;
		V206FB004.hfrontporch = p_mode->hfrontporch;
		V206FB004.hsync = p_mode->hsync;
		V206FB004.hpol = p_mode->hpol;
		V206FB004.vtotal = p_mode->vtotal;
		V206FB004.vactive = p_mode->vactive;
		V206FB004.vfrontporch = p_mode->vfrontporch;
		V206FB004.vsync = p_mode->vsync;
		V206FB004.vpol = p_mode->vpol;
		V206FB004.framerate = p_mode->framerate;
		V206FB004.dualpixel = dualpixel;
		V206FB004.isdvi = 1;

	} else {
		V206FB004.htotal = modeparams[mode][V206DISPMODE001];
		V206FB004.hactive = modeparams[mode][V206DISPMODE002];
		V206FB004.hfrontporch = modeparams[mode][V206DISPMODE003];
		V206FB004.hsync = modeparams[mode][V206DISPMODE004];
		V206FB004.hpol = modeparams[mode][V206DISPMODE012];
		V206FB004.vtotal = modeparams[mode][V206DISPMODE006];
		V206FB004.vactive = modeparams[mode][V206DISPMODE007];
		V206FB004.vfrontporch = modeparams[mode][V206DISPMODE008];
		V206FB004.vsync = modeparams[mode][V206DISPMODE009];
		V206FB004.vpol = modeparams[mode][V206DISPMODE013];
		V206FB004.framerate = modeparams[mode][V206DISPMODE011];
		V206FB004.dualpixel = dualpixel;
		V206FB004.isdvi = 1;

	}
	FUNC206HAL396(priv, (long)&V206FB004);

	return 0;
}
static void mwv206fb_pre_init(V206DEV025 *priv)
{
	struct V206DEV026 *V206FB005 = priv->fb_info;
	int i;

	FUNC206HAL236(priv, priv->V206DEV044[0], 0x40000000);

	FUNC206LXDEV143(priv, 0);

	for (i = 0; i < MAX_VIDEO_WINDOWS_NUMBER; i++) {
		FUNC206HAL423(priv, i);
		FUNC206HAL422(priv, i);
	}

	if (priv->pm.V206DEV109 == 0) {
		mwv206fb_clear(V206FB005);
	}
}

static void mwv206fb_post_init(V206DEV025 *priv)
{
	struct V206DEV026 *V206FB005 = priv->fb_info;
	MWV206DevConfig *V206DEV184;
	int i, V206FB011;

	V206DEV184 = FUNC206HAL109(priv);


	FUNC206HAL390(priv, (long)&V206FB005->V206DEV183);


	FUNC206LXDEV094(priv, V206FB005->V206DEV181);


	V206FB011 = V206FB005->crtc;
	for (i = 0; i < V206CONFIG005; i++) {
		FUNC206LXDEV084(priv, V206FB011, V206CONFIG011, i, V206DEV184);
	}

	for (i = 0; i < V206CONFIG006; i++) {
		mwv206fb_sethdmimode(priv, V206FB011, i, &V206FB005->V206DEV183, 0);
		FUNC206LXDEV084(priv, V206FB011, V206CONFIG013, i, V206DEV184);
	}

	for (i = 0; i < V206CONFIG008; i++) {
		FUNC206LXDEV084(priv, V206FB011, V206CONFIG012, i, V206DEV184);
	}

	for (i = 0; i < V206CONFIG007; i++) {
		FUNC206LXDEV084(priv, V206FB011, V206CONFIG014, i, V206DEV184);
	}
	FUNC206LXDEV143(priv, 1);
}

int mwv206fb_active(V206DEV025 *priv)
{
	mwv206fb_pre_init(priv);
	mwv206fb_post_init(priv);
	return 0;
}


int mwv206fb_getdisplayparam(V206DEV025 *priv, struct V206DEV026 *V206FB005)
{
	int i, V206FB011;

	MWV206DevConfig *V206DEV184;
	MWV206FbConfig *pMwv206FbCfg;
	V206IOCTL161 *pDpymode;

	pDpymode = &V206FB005->V206DEV183;
	V206DEV184 = FUNC206HAL109(priv);
	pMwv206FbCfg = &V206DEV184->fb;
	V206FB011 = V206FB005->crtc;


	for (i = 0; i < MAX_VIDEO_WINDOWS_NUMBER; i++) {
		FUNC206HAL423(priv, i);
	}



	if (pMwv206FbCfg->mode == V206GLJ028) {
		pDpymode->mode = V206GLJ028;
		pDpymode->V206FB011 = V206FB011;
		pDpymode->V206DEV079 = pMwv206FbCfg->V206DEV079;
		pDpymode->framerate = pMwv206FbCfg->rfsrate;
		pDpymode->htotal = pMwv206FbCfg->htotal;
		pDpymode->hactive = pMwv206FbCfg->hactive;
		pDpymode->hfrontporch = pMwv206FbCfg->hfrontporch;
		pDpymode->hpol = pMwv206FbCfg->hpol;
		pDpymode->hsync = pMwv206FbCfg->hsync;

		pDpymode->vtotal = pMwv206FbCfg->vtotal;
		pDpymode->vactive = pMwv206FbCfg->vactive;
		pDpymode->vfrontporch = pMwv206FbCfg->vfrontporch;
		pDpymode->vpol = pMwv206FbCfg->vpol;
		pDpymode->vsync = pMwv206FbCfg->vsync;
		V206FB005->width = pMwv206FbCfg->hactive;
		V206FB005->height = pMwv206FbCfg->vactive;
	} else if (pMwv206FbCfg->mode != CFG_FB_MODE_USER) {
		pDpymode->mode = pMwv206FbCfg->mode;
		pDpymode->V206FB011 = V206FB011;
		pDpymode->V206DEV079 = 0;
		V206FB005->width = modeparams[pMwv206FbCfg->mode][V206DISPMODE002];
		V206FB005->height = modeparams[pMwv206FbCfg->mode][V206DISPMODE007];
	} else {
		V206KDEBUG002("[ERROR] fb display param did not set!\n");
	}
	return 0;
}

int mwv206fb_init_early(struct pci_dev *V206DEV103)
{
/*
	struct apertures_struct *ap;
	int i;

	//ap = alloc_apertures(6);
	if (ap == NULL) {
		return -ENOMEM;
	}

	for (i = 0; i < 6; i++) {
		ap->ranges[i].base = pci_resource_start(V206DEV103, i);
		ap->ranges[i].size = pci_resource_len(V206DEV103, i);
	}
	//drm_aperture_remove_conflicting_framebuffers(ap, "MWV206FB", true);
	kfree(ap);
*/
	return 0;
}

int mwv206fb_register(struct pci_dev *V206DEV103)
{
	V206DEV025 *priv = pci_get_drvdata(V206DEV103);
	struct fb_info *info;
	struct V206DEV026 *V206FB005;
	unsigned pitch_mask = 64 - 1;
	unsigned int offset;
	int ret = 0;
	unsigned int V206DEV043, V206FB006;

#if (_MWV206_CPU_ == _MWV206_LOONGSON_)

	int i, max_fb;
	if (num_registered_fb > 0) {
		max_fb = num_registered_fb;
		for (i = 0; i < max_fb; i++) {
			if (NULL != registered_fb[i]) {
				unregister_framebuffer(registered_fb[i]);
			}
		}
	}
#endif

	info = framebuffer_alloc(sizeof(struct V206DEV026), &V206DEV103->dev);
	if (!info) {
		V206KDEBUG002("[ERROR] Allocation frame buffer failed.\n");
		return -ENOMEM;
	}


	V206DEV043 = priv->V206DEV043;
	V206FB006 = priv->V206DEV044[0];


#if 0
	info->apertures = alloc_apertures(1);
	if (info->apertures == NULL) {
		return -ENOMEM;
	}
	info->apertures->ranges[0].base = MWV206_GET_PCI_BAR_STARTADDR(V206DEV103, V206FB006);
	info->apertures->ranges[0].size = MWV206_GET_PCI_BAR_LEN(V206DEV103, V206FB006);
#endif

	V206FB005 = info->par;
	V206FB005->info = info;
	V206FB005->V206DEV103 = V206DEV103;
	priv->fb_info = V206FB005;


	mwv206fb_getdisplayparam(priv, V206FB005);
	V206DEV005("[INFO]fb_width = %d, fb_height = %d.\n", V206FB005->width, V206FB005->height);

	snprintf(V206FB005->name, sizeof(V206FB005->name), "MWV206");
	V206FB005->pixel_format = V206FB002;
	V206FB005->V206KG2D001 = 32;
	V206FB005->V206DEV182 = ((V206FB005->width * V206FB005->V206KG2D001 / 8) + pitch_mask) & ~pitch_mask;
	V206FB005->crtc = 0;
	V206FB005->screen_size = V206FB005->V206DEV182 * V206FB005->height;


	V206FB005->V206DEV177 = MWV206_GET_PCI_BAR_STARTADDR(V206DEV103, V206FB006);
	V206FB005->V206DEV180 = MWV206_GET_PCI_BAR_STARTADDR(V206DEV103, V206DEV043);

	if (V206FB005->screen_size > MWV206_GET_PCI_BAR_LEN(V206DEV103, V206FB006)) {
		V206KDEBUG002("[ERROR] PCIE BAR%d space not enough\n", V206FB006);
		ret = -ENOMEM;
		goto err0;
	}
	V206FB005->V206DEV179 = V206FB005->screen_size;
	V206FB005->mmio_len = MWV206_GET_PCI_BAR_LEN(V206DEV103, V206DEV043);

	V206FB005->mmio_base = (void *)priv->V206DEV033;


	if (fb_alloc_cmap(&info->cmap, 256, 0)) {
		ret = -ENOMEM;
		goto err1;
	}


	offset = FUNC206HAL223(priv, -V206FB005->screen_size, 64 * 1024);
	if (offset == 0) {
		V206KDEBUG002("[ERROR] allocate from framebuffer failure\n");
		ret = -ENOMEM;
		goto err2;
	}
	if (offset >= priv->V206DEV032[0]) {
		V206KDEBUG002("[ERROR] mwv206_mem_alloc allocate framebuffer address is to large\n");
		ret = -ENOMEM;
		goto err2;
	}

	V206KDEBUG003("[INFO] frame buffer offset: 0x%x\n", offset);
	V206FB005->V206DEV181 = offset;

	if (V206CTYPE009(priv->V206DEV028) || V206CTYPE008(priv->V206DEV028)
			|| V206CTYPE010(priv->V206DEV028)) {
		V206FB005->V206DEV178 = ioremap_wc(V206FB005->V206DEV177 + offset, V206FB005->V206DEV179);
	} else {
		V206FB005->V206DEV178 = ioremap(V206FB005->V206DEV177 + offset, V206FB005->V206DEV179);
	}

	V206KDEBUG003("[INFO] Frame buffer BAR%d - PHY: 0x%lx, offset: 0x%x, VIR: %p, size: 0x%lx\n",
			V206FB006, V206FB005->V206DEV177, offset, V206FB005->V206DEV178, V206FB005->V206DEV179);

	FUNC206LXDEV080(info);

	mwv206fb_pre_init(priv);
	ret = register_framebuffer(info);
	if (ret < 0) {
		V206KDEBUG002("[ERROR] mwv206fb (%s): could not register framebuffer\n",
				pci_name(V206FB005->V206DEV103));
		goto err3;
	}
	mwv206fb_post_init(priv);



	mdelay(1);
	V206KDEBUG003("[INFO] mwv206fb_register done.\n");
	return 0;

err3:
	FUNC206HAL226(priv, V206FB005->V206DEV181);
err2:
	fb_dealloc_cmap(&info->cmap);
err1:
	iounmap(V206FB005->V206DEV178);
err0:
	framebuffer_release(info);
	return ret;
}

void FUNC206LXDEV085(struct pci_dev *V206DEV103)
{
	V206DEV025 *priv = pci_get_drvdata(V206DEV103);
	struct V206DEV026 *V206FB005;
	struct fb_info *info;

	V206FB005 = priv->fb_info;
	if (V206FB005 == NULL) {
		return;
	}

	info = V206FB005->info;
	unregister_framebuffer(info);
	FUNC206HAL226(priv, V206FB005->V206DEV181);
	fb_dealloc_cmap(&info->cmap);
	iounmap(V206FB005->V206DEV178);
	framebuffer_release(info);
}