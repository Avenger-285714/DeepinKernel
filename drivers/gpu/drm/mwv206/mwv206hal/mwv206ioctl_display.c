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
#include "mwv206dev.h"
#include "../include/videoadd_reg.h"
#include "../include/mwv206reg.h"
#include "../include/displaymode.h"
#include "jmgraphoutput.h"
#include "../include/glj.h"

enum FUNC206HAL038 {
	CLK_FREQ_0 = 0,
	CLK_FREQ_1,
	CLK_FREQ_2,
	CLK_FREQ_3,
	CLK_FREQ_4,
	CLK_FREQ_MAX
};
const int clkfreq[CLK_FREQ_MAX] = {0x00280040, 0x00280230, 0x00280420, 0x00280810, 0x00281000};

int FUNC206HAL389(V206DEV025 *pDev, long arg)
{
	unsigned int value;
	unsigned int V206DEV033;
	V206IOCTL160 *setdispcursor;
	setdispcursor = (V206IOCTL160 *)arg;
	if ((setdispcursor->V206FB011 < 0) || (setdispcursor->V206FB011 > 3)) {
		return -2;
	}

	FUNC206HAL369(pDev, 1);

	if (setdispcursor->options & V206IOCTL016) {


		V206DEV033 = 0x9478 + OUTPUT_REG_OFFSET(setdispcursor->V206FB011);
		value = V206DEV001(V206DEV033);
		if (setdispcursor->enable) {
			value &= 0xFF00;
			value |= 6;
		} else {
			value &= ~1;
		}
		V206DEV002(V206DEV033, value);
	}

	if (setdispcursor->options & V206IOCTL017) {

		V206DEV033 = 0x9478 + OUTPUT_REG_OFFSET(setdispcursor->V206FB011);
		value = V206DEV001(V206DEV033);
		value &= 0xF;
		value |= ((setdispcursor->alpha & 0xFF) << 8);
		V206DEV002(V206DEV033, value);
	}

	if (setdispcursor->options & V206IOCTL018) {
		unsigned int bmpx, bmpy;
		int x, y, V206FB011;
		V206FB011 = setdispcursor->V206FB011;
		x = setdispcursor->x;
		y = setdispcursor->y;
		x -= pDev->V206DEV078[V206FB011][0];
		y -= pDev->V206DEV078[V206FB011][1];
		if (x < -31) {
			x = 0;
		}
		if (y < -31) {
			y = 0;
		}
		bmpx = 0;
		bmpy = 0;
		if (x < 0) {
			bmpx = -x;
			x = 0;
		}
		if (y < 0) {
			bmpy = -y;
			y = 0;
		}


		V206DEV033 = 0x9454 +  OUTPUT_REG_OFFSET(V206FB011);
		value = V206DEV001(V206DEV033);
		if (bmpx != (value & 0x3F) || bmpy != ((value >> 16) & 0x3F)) {
			value = (bmpx & 0x3F) | ((bmpy & 0x3F) << 16);
			V206DEV002(V206DEV033, value);
		}

		value = (x & 0xFFF) | ((y & 0xFFF) << 16);
		V206DEV033 = 0x94A8 + OUTPUT_REG_OFFSET(V206FB011);
		V206DEV002(V206DEV033, value);
	}

	if (setdispcursor->options & V206IOCTL019) {

		pDev->V206DEV078[setdispcursor->V206FB011][0] = setdispcursor->hotx;
		pDev->V206DEV078[setdispcursor->V206FB011][1] = setdispcursor->hoty;
	}

	FUNC206HAL369(pDev, 0);
	return 0;
}

static int FUNC206HAL037(int freq)
{
	if ((freq > 20) && (freq <= 21)) {
		return CLK_FREQ_0;
	} else if ((freq > 21) && (freq <= 42)) {
		return CLK_FREQ_1;
	} else if ((freq > 42) && (freq <= 85)) {
		return CLK_FREQ_2;
	} else if ((freq > 85) && (freq <= 170)) {
		return CLK_FREQ_3;
	} else if ((freq > 170) && (freq <= 348)) {
		return CLK_FREQ_4;
	} else {
		return CLK_FREQ_MAX;
	}
}

static int FUNC206HAL350(V206DEV025 *pDev, int winid, int V206HDMIAUDIO027, int FUNC206HAL038, int dualpixel,
		int hpol, int vpol)
{
	int val_car, formerval_car, newval_car;
	int pllreg, pllctrl, hdmireg;
	int hpolval, vpolval;

	if (FUNC206HAL038 < CLK_FREQ_0 || FUNC206HAL038 >= CLK_FREQ_MAX) {
		V206KDEBUG002("[ERROR] invalid pll clkindex %d!\n\n", FUNC206HAL038);
		return -2;
	}


	pllreg = (V206HDMIAUDIO027 == 0) ? ((0x403000) + 0x0400) :
		((V206HDMIAUDIO027 == 1)  ? ((0x403000) + 0x0500) :
		 ((V206HDMIAUDIO027 == 2)  ? ((0x403000) + 0x0600) :
		  ((0x403000) + 0x0700)));

	pllctrl = (V206HDMIAUDIO027 == 0) ? ((0x403000) + 0x0A04) :
		((V206HDMIAUDIO027 == 1)  ? ((0x403000) + 0x0A08) :
		 ((V206HDMIAUDIO027 == 2)  ? ((0x403000) + 0x0A0C) :
		  ((0x403000) + 0x0A10)));



	hpolval = 1; vpolval = 1;
	if (hpol == V206DISPMODE015)  {
		hpolval = 1;
	} else {
		hpolval = 0;
	}

	if (vpol == V206DISPMODE015)  {
		vpolval = 1;
	} else {
		vpolval = 0;
	}

	formerval_car = V206DEV001(pllreg);
	V206DEV005("[HDMICTRL]hpolval = %d, vpolval = %d.\n", hpolval, vpolval);
	newval_car  = (formerval_car & 0xFFFFFCFF) | (vpolval << 8) | (hpolval << 9);
	V206DEV002(pllreg, newval_car);
	V206DEV005("formerval_car = %x, Hpol = %d, Vpol = %d, value = %x\n", formerval_car, hpolval, vpolval, newval_car);



	hdmireg = MWV206_HDMI_REG(V206HDMIAUDIO027, (0x1000));
	formerval_car = V206DEV001(hdmireg);
	newval_car  = (formerval_car & 0xFFFFFF9F) | (vpolval << 6) | (hpolval << 5);
	V206DEV002(hdmireg, newval_car);


	V206DEV002(pllctrl, clkfreq[FUNC206HAL038]);

	formerval_car = V206DEV001(pllreg);
	if (pDev->V206DEV093[winid] > 165) {
		val_car = 1 << 18;
	} else {
		val_car = 0 << 18;
	}
	newval_car = (formerval_car & 0xFFF3FFFF) | val_car;
	V206DEV002(pllreg, newval_car);

	return 0;
}

static int FUNC206HAL349(V206DEV025 *pDev, int winid, int V206HDMIAUDIO027, int FUNC206HAL038, int dualpixel,
		int hpol, int vpol)
{

	int reg_barno, ret = 0;
	int ticks;
	ticks = 200;

	FUNC206LXDEV128(ticks);
	V206DEV005("wait %d ticks.\n", ticks);

	reg_barno = pDev->V206DEV043;
	if ((V206DEV001(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x104)))
				& 0x2) == 0) {
		V206KDEBUG002("[INFO] hdmi%d pll not locked, clkindex = %d.\n", V206HDMIAUDIO027, FUNC206HAL038);
		ret = -1;
	}

	return ret;
}


int FUNC206HAL394(V206DEV025 *pDev, long arg)
{
	V206IOCTL173 *modeparam;
	int regval;
	int V206DEV033;
	int port, type, value;

	modeparam = (V206IOCTL173 *)arg;
	port = modeparam->V206FB008;
	type = modeparam->type;
	value = modeparam->value;

	if (pDev->pm.V206DEV109 == 0) {
		pDev->pm.V206DEV118[port] = *modeparam;
		pDev->pm.V206DEV113[port] = 1;
	}

	switch (type) {
	case DP_LVDS_MODE:
		if ((port > V206GLJ037) || (port < V206GLJ036)) {
			return 0;
		}
		V206DEV033 = ((0x403000) + 0x0800) + (port - V206GLJ036) * 0x100;
		regval = V206DEV001(V206DEV033);
		regval = regval & ~(0x30);
		switch (value) {
		case V206GLJ043:
		case V206GLJ044:
			regval = (0x1 << 4) | regval;
			V206DEV002(V206DEV033, regval);
			break;
		case V206GLJ046:
			regval = (0 << 4) | regval;
			V206DEV002(V206DEV033, regval);
			break;
		case V206GLJ045:
			regval = (0x3 << 4) | regval;
			V206DEV002(V206DEV033, regval);
			break;
		default:
			V206KDEBUG002("invalid lvds mode value.");
			return -1;
			break;
		}
		break;
	default:
		V206KDEBUG002("Unsupport paramtype %d!\n", type);
		return -1;
		break;
	}
	V206DEV005("[%s:%d] type = %d, value = %d, regval = 0x%x.\n", __FUNCTION__, __LINE__, type, value, regval);
	return 0;
}

static void FUNC206HAL387(V206DEV025 *pDev, int V206FB011, int V206HDMIAUDIO027, int dualpixel)
{
	int val_car, formerval_car, newval_car;
	int val_pll, formerval_pll, newval_pll;
	int pllreg, pllctrl;


	pllreg = (V206HDMIAUDIO027 == 0) ? ((0x403000) + 0x0400) :
		((V206HDMIAUDIO027 == 1)  ? ((0x403000) + 0x0500) :
		 ((V206HDMIAUDIO027 == 2)  ? ((0x403000) + 0x0600) :
		  ((0x403000) + 0x0700)));

	pllctrl = (V206HDMIAUDIO027 == 0) ? ((0x403000) + 0x0A04) :
		((V206HDMIAUDIO027 == 1)  ? ((0x403000) + 0x0A08) :
		 ((V206HDMIAUDIO027 == 2)  ? ((0x403000) + 0x0A0C) :
		  ((0x403000) + 0x0A10)));


	formerval_pll = V206DEV001(((0x400000) + 0x0014));
	val_pll = V206FB011 << (V206HDMIAUDIO027 * 8);
	if (dualpixel) {
		val_pll = (V206FB011 + 8) << (V206HDMIAUDIO027 * 8);
	}
	newval_pll = (formerval_pll & (~(0xFF << (V206HDMIAUDIO027 * 8)))) | val_pll;
	V206DEV002(((0x400000) + 0x0014), newval_pll);


	formerval_car = V206DEV001(pllreg);
	val_car = (V206FB011 << 4) | 1;
	if (dualpixel) {
		val_car |= 0x06;
	}
	newval_car = (formerval_car & 0xFFFFFFCF) | val_car;
	V206DEV002(pllreg, newval_car);
}

static void FUNC206HAL386(V206DEV025 *pDev, V206IOCTL172 *setdispport, int ctrlreg, int enable)
{
	int formerval, V206IOCTLCMD010, tempval;
	int V206HDMIAUDIO027 = setdispport->V206FB008 - V206GLJ038;

	if (enable) {
		FUNC206HAL387(pDev, setdispport->V206FB011, V206HDMIAUDIO027, setdispport->dualpixel);

		formerval = V206DEV001(((0x403000) + 0x0A00));
		tempval = ((1 << V206HDMIAUDIO027) | (1 << V206HDMIAUDIO027 << 4));
		V206IOCTLCMD010 = formerval | tempval;
		V206DEV002(((0x403000) + 0x0A00), V206IOCTLCMD010);

		formerval = V206DEV001(ctrlreg);
		V206IOCTLCMD010 = formerval | 1;
		V206DEV002(ctrlreg, V206IOCTLCMD010);
	} else {

		formerval = V206DEV001(ctrlreg);
		tempval = 0xFFFFFFFC;
		V206IOCTLCMD010 = formerval & tempval;
		V206DEV002(ctrlreg, V206IOCTLCMD010);

		formerval = V206DEV001(((0x403000) + 0x0A00));
		tempval = (~((1 << V206HDMIAUDIO027) | (1 << V206HDMIAUDIO027 << 4)));
		V206IOCTLCMD010 = formerval & tempval;
		V206DEV002(((0x403000) + 0x0A00), V206IOCTLCMD010);
	}
}

int FUNC206HAL393(V206DEV025 *pDev, long arg)
{
	int val_car, formerval_car, newval_car, val_clk, formerval_clk, newval_clk, en;
	int V206HDMIAUDIO027, hpol, vpol;
	V206IOCTL172 *setdispport;

	setdispport = (V206IOCTL172 *)arg;
	V206HDMIAUDIO027 = setdispport->V206FB008 - V206GLJ038;
	if ((setdispport->V206FB011 < 0) || (setdispport->V206FB011 > 3)) {
		return -2;
	}
	if ((setdispport->V206FB008 < V206GLJ032) || (setdispport->V206FB008 > V206GLJ041)) {
		return -2;
	}
	if (pDev->pm.V206DEV109 == 0) {
		int id = setdispport->V206FB008;
		pDev->pm.V206DEV117[id] = *setdispport;
		pDev->pm.V206DEV112[id] = 1;
	}

	hpol = pDev->V206DEV146[setdispport->V206FB011].hpol;
	vpol = pDev->V206DEV146[setdispport->V206FB011].vpol;

	en = (setdispport->enable) ? 1 : 0;
	FUNC206HAL369(pDev, 1);
	switch (setdispport->V206FB008) {
	case V206GLJ032:
		formerval_car = V206DEV001(((0x403000) + 0x0200));
		if (en) {

			formerval_clk = V206DEV001(((0x400000) + 0x0010));
			val_clk = setdispport->V206FB011;
			if (setdispport->dualpixel) {
				val_clk += 8;
			}
			newval_clk = (formerval_clk & 0xFFFFFFF0) | val_clk;
			V206DEV002(((0x400000) + 0x0010), newval_clk);

			val_car = ((setdispport->V206FB011) << 2)
				| (setdispport->dualpixel << 1)
				| (hpol << 9)
				| (vpol << 8)
				| (en);
			newval_car = (formerval_car & 0xFFFFFCF1) | val_car;
			V206DEV002(((0x403000) + 0x0200), newval_car);
			pDev->V206DEV144[V206GLJ032].V206FB011 = setdispport->V206FB011;
			pDev->V206DEV144[V206GLJ032].dualpixel = setdispport->dualpixel;
		} else {
			val_car = 0xFFFFFFFE;
			newval_car = formerval_car & val_car;
			V206DEV002(((0x403000) + 0x0200), newval_car);
		}
		pDev->V206DEV144[V206GLJ032].enable = en;
		break;
	case V206GLJ033:
		formerval_car = V206DEV001(((0x403000) + 0x0300));
		if (en) {

			formerval_clk = V206DEV001(((0x400000) + 0x0010));
			val_clk = setdispport->V206FB011 << 8;
			if (setdispport->dualpixel) {
				val_clk = (setdispport->V206FB011 + 8) << 8;
			}
			newval_clk = (formerval_clk & 0xFFFFF0FF) | val_clk;
			V206DEV002(((0x400000) + 0x0010), newval_clk);

			val_car = ((setdispport->V206FB011) << 2)
				| (setdispport->dualpixel << 1)
				| (hpol << 9)
				| (vpol << 8)
				| (en);
			newval_car = (formerval_car & 0xFFFFFCF1) | val_car;
			V206DEV002(((0x403000) + 0x0300), newval_car);
			pDev->V206DEV144[V206GLJ033].V206FB011 = setdispport->V206FB011;
			pDev->V206DEV144[V206GLJ033].dualpixel = setdispport->dualpixel;
		} else {
			val_car = 0xFFFFFFFE;
			newval_car = formerval_car & val_car;
			V206DEV002(((0x403000) + 0x0300), newval_car);
		}
		pDev->V206DEV144[V206GLJ033].enable = en;
		break;
	case V206GLJ034:
		formerval_car = V206DEV001(((0x403000) + 0x0000));
		if (en) {

			formerval_clk = V206DEV001(((0x400000) + 0x000c));
			val_clk = setdispport->V206FB011;
			newval_clk = (formerval_clk & 0xFFFFFFF0) | val_clk;
			V206DEV002(((0x400000) + 0x000c), newval_clk);

			val_car = (setdispport->V206FB011)
				| (hpol << 2)
				| (vpol << 3)
				| (0x80000000);
			newval_car = (formerval_car & 0xFFFFFFF0) | val_car;
			V206DEV002(((0x403000) + 0x0000), newval_car);
			pDev->V206DEV144[V206GLJ034].V206FB011 = setdispport->V206FB011;
			pDev->V206DEV144[V206GLJ034].dualpixel = setdispport->dualpixel;
		} else {
			val_car = 0x7FFFFFFF;
			newval_car = formerval_car & val_car;
			V206DEV002(((0x403000) + 0x0000), newval_car);
		}
		pDev->V206DEV144[V206GLJ034].enable = en;
		break;
	case V206GLJ035:
		formerval_car = V206DEV001(((0x403000) + 0x0100));
		if (en) {

			formerval_clk = V206DEV001(((0x400000) + 0x000c));
			val_clk = setdispport->V206FB011 << 8;
			newval_clk = (formerval_clk & 0xFFFFF0FF) | val_clk;
			V206DEV002(((0x400000) + 0x000c), newval_clk);

			val_car = (setdispport->V206FB011)
				| (hpol << 2)
				| (vpol << 3)
				| (0x80000000);
			newval_car = (formerval_car & 0xFFFFFFF0) | val_car;
			V206DEV002(((0x403000) + 0x0100), newval_car);
			pDev->V206DEV144[V206GLJ035].V206FB011 = setdispport->V206FB011;
			pDev->V206DEV144[V206GLJ035].dualpixel = setdispport->dualpixel;
		} else {
			val_car = 0x7FFFFFFF;
			newval_car = formerval_car & val_car;
			V206DEV002(((0x403000) + 0x0100), newval_car);
		}
		pDev->V206DEV144[V206GLJ035].enable = en;
		break;
	case V206GLJ036:
		formerval_car = V206DEV001(((0x403000) + 0x0800));
		if (en) {

			formerval_clk = V206DEV001(((0x400000) + 0x0018));
			val_clk = setdispport->V206FB011;
			if (setdispport->dualpixel) {
				val_clk += 8;
			}

			newval_clk = (formerval_clk & 0xFFFFFFF0) | val_clk;
			V206DEV002(((0x400000) + 0x0018), newval_clk);

			val_car = ((setdispport->V206FB011) << 2)
				| (setdispport->dualpixel << 1)
				| (hpol << 9)
				| (vpol << 8)
				| en;
			newval_car = (formerval_car & 0xFFFFFCF1) | val_car;
			V206DEV002(((0x403000) + 0x0800), newval_car);
			pDev->V206DEV144[V206GLJ036].V206FB011 = setdispport->V206FB011;
			pDev->V206DEV144[V206GLJ036].dualpixel = setdispport->dualpixel;
		} else {
			val_car = 0xFFFFFFFE;
			newval_car = formerval_car & val_car;
			V206DEV002(((0x403000) + 0x0800), newval_car);
		}
		pDev->V206DEV144[V206GLJ036].enable = en;
		break;
	case V206GLJ037:
		formerval_car = V206DEV001(((0x403000) + 0x0900));
		if (en) {

			formerval_clk = V206DEV001(((0x400000) + 0x0018));
			val_clk = setdispport->V206FB011 << 8;
			if (setdispport->dualpixel) {
				val_clk = (setdispport->V206FB011 + 8) << 8;
			}
			newval_clk = (formerval_clk & 0xFFFFF0FF) | val_clk;
			V206DEV002(((0x400000) + 0x0018), newval_clk);

			formerval_car = V206DEV001(((0x403000) + 0x0900));
			val_car = ((setdispport->V206FB011) << 2)
				| (setdispport->dualpixel << 1)
				| (hpol << 9)
				| (vpol << 8)
				| en;
			newval_car = (formerval_car & 0xFFFFFCF1) | val_car;
			V206DEV002(((0x403000) + 0x0900), newval_car);
			pDev->V206DEV144[V206GLJ037].V206FB011 = setdispport->V206FB011;
			pDev->V206DEV144[V206GLJ037].dualpixel = setdispport->dualpixel;
		} else {
			val_car = 0xFFFFFFFE;
			newval_car = formerval_car & val_car;
			V206DEV002(((0x403000) + 0x0900), newval_car);
		}
		pDev->V206DEV144[V206GLJ037].enable = en;
		break;
	case V206GLJ038:
		FUNC206HAL386(pDev, setdispport, ((0x403000) + 0x0400), en);
		pDev->V206DEV144[V206GLJ038].V206FB011 = setdispport->V206FB011;
		pDev->V206DEV144[V206GLJ038].dualpixel = setdispport->dualpixel;
		pDev->V206DEV144[V206GLJ038].enable = en;
		break;
	case V206GLJ039:
		FUNC206HAL386(pDev, setdispport, ((0x403000) + 0x0500), en);
		pDev->V206DEV144[V206GLJ039].V206FB011 = setdispport->V206FB011;
		pDev->V206DEV144[V206GLJ039].dualpixel = setdispport->dualpixel;
		pDev->V206DEV144[V206GLJ039].enable = en;
		break;
	case V206GLJ040:
		FUNC206HAL386(pDev, setdispport, ((0x403000) + 0x0600), en);
		pDev->V206DEV144[V206GLJ040].V206FB011 = setdispport->V206FB011;
		pDev->V206DEV144[V206GLJ040].dualpixel = setdispport->dualpixel;
		pDev->V206DEV144[V206GLJ040].enable = en;
		break;
	case V206GLJ041:
		FUNC206HAL386(pDev, setdispport, ((0x403000) + 0x0700), en);
		pDev->V206DEV144[V206GLJ041].V206FB011 = setdispport->V206FB011;
		pDev->V206DEV144[V206GLJ041].dualpixel = setdispport->dualpixel;
		pDev->V206DEV144[V206GLJ041].enable = en;
		break;
	default:
		FUNC206HAL369(pDev, 0);
		return -1;
		break;
	}
	FUNC206HAL369(pDev, 0);
	return 0;
}

int FUNC206HAL391(V206DEV025 *priv, int crtc, int width, int height, int isInterleaved)
{
	unsigned int i;

	for (i = 0; i < sizeof(modeparams) / sizeof(modeparams[0]); i++) {
		if (modeparams[i][V206DISPMODE002] == (unsigned int)width && \
				modeparams[i][V206DISPMODE007] == (unsigned int)height && \
				modeparams[i][V206DISPMODE011] == 60) {
			FUNC206HAL192(
					priv, crtc,
					modeparams[i][V206DISPMODE001],
					modeparams[i][V206DISPMODE002],
					modeparams[i][V206DISPMODE003],
					modeparams[i][V206DISPMODE004],
					modeparams[i][V206DISPMODE006],
					modeparams[i][V206DISPMODE007],
					modeparams[i][V206DISPMODE008],
					modeparams[i][V206DISPMODE009],
					modeparams[i][V206DISPMODE011],
					isInterleaved, 1);
			return 0;
		}
	}

	return -1;
}

int FUNC206HAL390(V206DEV025 *pDev, long arg)
{
	V206IOCTL161 *setdispmode;
	int  hpol = 0, vpol = 0;

	setdispmode = (V206IOCTL161 *)arg;
	if ((setdispmode->mode < 0) || (setdispmode->mode > V206GLJ028)) {
		return -1;
	}

	if ((setdispmode->V206FB011 < 0) || (setdispmode->V206FB011 > 3)) {
		return -2;
	}

	if (pDev->pm.V206DEV109 == 0) {
		int id = setdispmode->V206FB011;
		pDev->pm.V206DEV115[id] = *setdispmode;
		pDev->pm.V206DEV110[id] = 1;
	}

	pDev->V206DEV079[setdispmode->V206FB011] = setdispmode->V206DEV079;
	FUNC206HAL369(pDev, 1);
	if (setdispmode->mode == V206GLJ028) {
		if (setdispmode->framerate > 1) {
			FUNC206HAL192(pDev,
					setdispmode->V206FB011,
					setdispmode->htotal,
					setdispmode->hactive,
					setdispmode->hfrontporch,
					setdispmode->hsync,
					setdispmode->vtotal,
					setdispmode->vactive,
					setdispmode->vfrontporch,
					setdispmode->vsync,
					setdispmode->framerate,
					setdispmode->V206DEV079,
					1);
			hpol =  setdispmode->hpol;
			vpol =  setdispmode->vpol;

		}
	} else {
		FUNC206HAL192(pDev,
				setdispmode->V206FB011,
				modeparams[setdispmode->mode][V206DISPMODE001],
				modeparams[setdispmode->mode][V206DISPMODE002],
				modeparams[setdispmode->mode][V206DISPMODE003] + modeparams[setdispmode->mode][V206DISPMODE005],
				modeparams[setdispmode->mode][V206DISPMODE004],
				modeparams[setdispmode->mode][V206DISPMODE006],
				modeparams[setdispmode->mode][V206DISPMODE007],
				modeparams[setdispmode->mode][V206DISPMODE008] + modeparams[setdispmode->mode][V206DISPMODE010],
				modeparams[setdispmode->mode][V206DISPMODE009],
				modeparams[setdispmode->mode][V206DISPMODE011],
				setdispmode->V206DEV079,
				1);
		hpol =  modeparams[setdispmode->mode][V206DISPMODE012];
		vpol =  modeparams[setdispmode->mode][V206DISPMODE013];
	}
	FUNC206HAL369(pDev, 0);

	pDev->V206DEV146[setdispmode->V206FB011].hpol = hpol;
	pDev->V206DEV146[setdispmode->V206FB011].vpol = vpol;

	return 0;
}

int FUNC206HAL388(V206DEV025 *pDev, long arg)
{
	V206IOCTL159 *setdispaddr;
	int ret;
	unsigned int offset = 0;

	int len;

	setdispaddr = (V206IOCTL159 *)arg;

	V206DEV005("setdispaddr: 0x%x\n", setdispaddr->addr);

	len = sizeof(V206IOCTL159);
	if (memcmp(&pDev->V206DEV143, setdispaddr, len) == 0) {
		return 0;
	}

	if (setdispaddr->vsync == 1) {
		memcpy(&pDev->V206DEV143, setdispaddr, len);
	}

	if (pDev->pm.V206DEV109 == 0) {
		int id = setdispaddr->V206FB011;
		pDev->pm.V206DEV116[id] = *setdispaddr;
		pDev->pm.V206DEV111[id] = 1;
	}

	FUNC206HAL369(pDev, 1);
	offset = 0;

	if (setdispaddr->V206FB011 == 0) {
		offset = 0;
	} else if (setdispaddr->V206FB011 == 1) {
		offset = 0x100;
	} else if (setdispaddr->V206FB011 == 2) {
		offset = 0x800;
	} else if (setdispaddr->V206FB011 == 3) {
		offset = 0x900;
	} else {
		V206KDEBUG002("Invalid screen number, should be 0~3.\n");
		FUNC206HAL369(pDev, 0);
		return -1;
	}

	if (setdispaddr->vsync == 1) {
		ret = FUNC206HAL405(pDev, setdispaddr->V206FB011);
		if (ret != 0) {
			V206KDEBUG002("wait for display signal timeout!\n");
			FUNC206HAL369(pDev, 0);
			return -2;
		}
	}
	V206DEV002(((0x409000) + 0x0434) + offset, setdispaddr->V206KG2D033 / 16);
	V206DEV002(((0x409000) + 0x0430) + offset, (setdispaddr->format == V206GLJ030) ? 0 : 1);





	V206DEV002(((0x409000) + 0x043C) + offset,
			((setdispaddr->width - 1) << 0) | ((setdispaddr->height - 1) << 16));
	V206DEV002(((0x409000) + 0x04AC) + offset, 0);
	V206DEV002(((0x409000) + 0x0438) + offset, setdispaddr->addr);
	FUNC206HAL369(pDev, 0);
	return 0;
}


static int FUNC206HAL460(
		unsigned int targetOutFreq,
		int *pRefDiv,
		int *pFbIntDiv,
		int *pFbRacDiv,
		int *pPostDiv1,
		int *pPostDiv2)
{
	unsigned int refDiv, postDiv1, postDiv2;
	unsigned int vcoFreq;
	unsigned int fbRacDiv = 0;
	unsigned int compTargetOutFreq;
	unsigned int tempTargetFreq, mError;
	unsigned int mPostDiv1 = 0;
	unsigned int mPostDiv2 = 0;
	unsigned int mRefDiv = 0;
	unsigned int mFbIntDIV = 0;
	unsigned int mIntError;
	unsigned int mFbRacDIV = 0;
	unsigned int fbIntDiv = 0;

	compTargetOutFreq = targetOutFreq;

	if (NULL == pRefDiv
			|| NULL == pFbIntDiv
			|| NULL == pFbRacDiv
			|| NULL == pPostDiv1
			|| NULL == pPostDiv2)   {
		return -1;
	}

	if (16000000u > compTargetOutFreq || 3200000000u < compTargetOutFreq) {

		V206DEV004(V206KDEBUG006, "[ERROR] targetOutFreq is outrange of 12MHz ~ 2.4GHz\n");
		return -2;
	}

	V206DEV004(V206KDEBUG008, "targetOutFreq=%d\n", targetOutFreq);


	postDiv1 = 1;
	postDiv2 = 1;
	refDiv = 1;
	mIntError = 0x7fffffff;
	for (postDiv2 = 1; postDiv2 < 8; postDiv2++) {
		for (postDiv1 = 1; postDiv1 < 8; postDiv1++) {
			for (refDiv = 1; refDiv < 64; refDiv++) {
				unsigned int temp;
				vcoFreq = targetOutFreq * postDiv1 * postDiv2;

				if (800000000u > vcoFreq || 3200000000u < vcoFreq) {
					continue;
				}

				V206DEV004(V206KDEBUG008, "####################################################\n");
				V206DEV004(V206KDEBUG008, "postdiv1=%d, postdiv2=%d\n", postDiv1, postDiv2);

				fbIntDiv = (vcoFreq * refDiv) / 100000000u;
				fbRacDiv = (vcoFreq * refDiv) % 100000000u;
				if (((100000000u / refDiv) < 10)
						|| ((100000000u / refDiv) > (vcoFreq / 16))) {
					continue;
				}

				if (fbRacDiv == 0) {

					if ((fbIntDiv < 16) || (fbIntDiv > 3200)) {

						continue;
					}
					if (postDiv2 > postDiv1) {

						temp = postDiv1;
						postDiv1 = postDiv2;
						postDiv2 = temp;
					}
					mPostDiv1 = postDiv1;
					mPostDiv2 = postDiv2;
					mRefDiv = refDiv;
					mFbIntDIV = fbIntDiv;
					mFbRacDIV = fbRacDiv;
					goto CALCULATE_FREQDIV_SUCCESSED;
				} else {

					if ((fbIntDiv < 20) || (fbIntDiv > 320)) {

						continue;
					}

					temp = vcoFreq * refDiv;
					while (temp >= 100000000u) {
						temp -= 100000000u;
					}
					fbRacDiv = 0;
					{
						int bits = 24;
						while (bits >= 0) {
							if (temp >= 100000000u) {
								fbRacDiv += 1 << bits;
								temp -= 100000000u;
							}
							temp *= 2;
							bits--;
						}
					}


					tempTargetFreq = fbIntDiv * 100000000u;
					temp = 100000000u;
					{
						int bits = 24;
						while (bits >= 0) {
							if (fbRacDiv & (1 << bits)) {
								tempTargetFreq += temp;
							}
							bits--;
							temp /= 2;
						}
					}
					tempTargetFreq /= refDiv * postDiv1 * postDiv2;
					if (tempTargetFreq >= compTargetOutFreq) {
						mError = tempTargetFreq - compTargetOutFreq;
					} else {
						mError = compTargetOutFreq - tempTargetFreq;
					}

					if (mError < mIntError) {
						if (postDiv2 > postDiv1) {

							temp = postDiv1;
							postDiv1 = postDiv2;
							postDiv2 = temp;
						}
						mPostDiv1 = postDiv1;
						mPostDiv2 = postDiv2;
						mRefDiv = refDiv;
						mFbIntDIV = fbIntDiv;
						mIntError = mError;
						mFbRacDIV = fbRacDiv;
						goto CALCULATE_FREQDIV_SUCCESSED;
					} else {
						V206KDEBUG002("[%s:%d] no handled.\n", __FILE__, __LINE__);
						return -3;
					}
				}
			}
		}
	}

CALCULATE_FREQDIV_SUCCESSED:
	*pRefDiv = mRefDiv;
	*pFbIntDiv = mFbIntDIV;
	*pPostDiv1 = mPostDiv1;
	*pPostDiv2 = mPostDiv2;
	*pFbRacDiv = mFbRacDIV;

	V206DEV004(V206KDEBUG007, "\n*******************************************\n");
	V206DEV004(V206KDEBUG007, "targetOutFreq : %d\n", targetOutFreq);
	V206DEV004(V206KDEBUG007, "refdiv : %d\n",    mRefDiv);
	V206DEV004(V206KDEBUG007, "postdiv1 : %d\n", mPostDiv1);
	V206DEV004(V206KDEBUG007, "postdiv2 : %d\n", mPostDiv2);
	V206DEV004(V206KDEBUG007, "fbintdiv : %d\n", fbIntDiv);
	V206DEV004(V206KDEBUG007, "fbfracdiv : %d\n", mFbRacDIV);
	V206DEV004(V206KDEBUG007, "freq error : %d\n", mIntError);

	V206DEV004(V206KDEBUG007, "*******************************************\n");

	return 0;
}

static int FUNC206HAL461(
		unsigned int targetOutFreq,
		int *pRefDiv,
		int *pFbIntDiv,
		int *pFbRacDiv,
		int *pPostDiv1,
		int *pPostDiv2)
{
	unsigned int refDiv, postDiv1, postDiv2;
	unsigned int vcoFreq;
	unsigned int fbRacDiv = 0;
	unsigned int compTargetOutFreq;
	unsigned int tempTargetFreq, mError;
	unsigned int mPostDiv1 = 0;
	unsigned int mPostDiv2 = 0;
	unsigned int mRefDiv = 0;
	unsigned int mFbIntDIV = 0;
	unsigned int mIntError;
	unsigned int mFbRacDIV = 0;
	unsigned int fbIntDiv = 0;

	compTargetOutFreq = targetOutFreq;

	if (NULL == pRefDiv
			|| NULL == pFbIntDiv
			|| NULL == pFbRacDiv
			|| NULL == pPostDiv1
			|| NULL == pPostDiv2)   {
		return -1;
	}

	if (16u > compTargetOutFreq || 3200u < compTargetOutFreq) {

		V206DEV004(V206KDEBUG006, "[ERROR] targetOutFreq is outrange of 12MHz ~ 2.4GHz\n");
		return -2;
	}

	V206DEV004(V206KDEBUG008, "targetOutFreq=%d\n", targetOutFreq);


	postDiv1 = 1;
	postDiv2 = 1;
	refDiv = 1;
	mIntError = targetOutFreq / 200;
	if (mIntError < 2) {
		mIntError = 2;
	}
	for (postDiv2 = 7; postDiv2 > 0; postDiv2--) {
		for (postDiv1 = 7; postDiv1 > 0; postDiv1--) {
			for (refDiv = 63; refDiv > 0 ; refDiv--) {
				unsigned int temp;
				vcoFreq = targetOutFreq * postDiv1 * postDiv2;

				if (800u > vcoFreq || 3200u < vcoFreq) {
					continue;
				}

				V206DEV004(V206KDEBUG008, "####################################################\n");
				V206DEV004(V206KDEBUG008, "postdiv1=%d, postdiv2=%d\n", postDiv1, postDiv2);

				fbIntDiv = (vcoFreq * refDiv) / 100u;
				fbRacDiv = (vcoFreq * refDiv) % 100u;
				if (((100u / refDiv) < 10)
						|| ((100u / refDiv) > (vcoFreq / 16))) {
					continue;
				}

				if (fbRacDiv == 0) {

					if ((fbIntDiv < 16) || (fbIntDiv > 3200)) {

						continue;
					}
					if (postDiv2 > postDiv1) {

						temp = postDiv1;
						postDiv1 = postDiv2;
						postDiv2 = temp;
					}
					mPostDiv1 = postDiv1;
					mPostDiv2 = postDiv2;
					mRefDiv = refDiv;
					mFbIntDIV = fbIntDiv;
					mFbRacDIV = fbRacDiv;
					goto CALCULATE_FREQDIV_SUCCESSED;
				} else {

					if ((fbIntDiv < 20) || (fbIntDiv > 320)) {

						continue;
					}

					temp = vcoFreq * refDiv;
					while (temp >= 100u) {
						temp -= 100u;
					}
					fbRacDiv = 0;
					{
						int bits = 24;
						while (bits >= 0) {
							if (temp >= 100u) {
								fbRacDiv += 1 << bits;
								temp -= 100u;
							}
							temp *= 2;
							bits--;
						}
					}


					tempTargetFreq = fbIntDiv * 100u;
					temp = 100u;
					{
						int bits = 24;
						while (bits >= 0) {
							if (fbRacDiv & (1 << bits)) {
								tempTargetFreq += temp;
							}
							bits--;
							temp /= 2;
						}
					}
					tempTargetFreq /= refDiv * postDiv1 * postDiv2;
					if (tempTargetFreq >= compTargetOutFreq) {
						mError = tempTargetFreq - compTargetOutFreq;
					} else {
						mError = compTargetOutFreq - tempTargetFreq;
					}

					if (mError < mIntError) {
						if (postDiv2 > postDiv1) {

							temp = postDiv1;
							postDiv1 = postDiv2;
							postDiv2 = temp;
						}
						mPostDiv1 = postDiv1;
						mPostDiv2 = postDiv2;
						mRefDiv = refDiv;
						mFbIntDIV = fbIntDiv;
						mIntError = mError;
						mFbRacDIV = fbRacDiv;
						goto CALCULATE_FREQDIV_SUCCESSED;
					} else {
						V206KDEBUG002("[%s:%d] no handled.\n", __FILE__, __LINE__);
						return -3;
					}
				}
			}
		}
	}

CALCULATE_FREQDIV_SUCCESSED:
	*pRefDiv = mRefDiv;
	*pFbIntDiv = mFbIntDIV;
	*pPostDiv1 = mPostDiv1;
	*pPostDiv2 = mPostDiv2;
	*pFbRacDiv = mFbRacDIV;

	V206DEV004(V206KDEBUG007, "\n*******************************************\n");
	V206DEV004(V206KDEBUG007, "targetOutFreq : %d\n", targetOutFreq);
	V206DEV004(V206KDEBUG007, "refdiv : %d\n",    mRefDiv);
	V206DEV004(V206KDEBUG007, "postdiv1 : %d\n", mPostDiv1);
	V206DEV004(V206KDEBUG007, "postdiv2 : %d\n", mPostDiv2);
	V206DEV004(V206KDEBUG007, "fbintdiv : %d\n", fbIntDiv);
	V206DEV004(V206KDEBUG007, "fbfracdiv : %d\n", mFbRacDIV);
	V206DEV004(V206KDEBUG007, "freq error : %d\n", mIntError);

	V206DEV004(V206KDEBUG007, "*******************************************\n");

	return 0;
}


int FUNC206HAL136(V206DEV025 *pDev,
		enum V206IOCTL109 pllID,
		int freq)
{
	int result = 0;
	GLJ_TICK tick;
	unsigned int value;
	int refDiv, fbIntDiv, fbRacDiv, postDiv1, postDiv2;

	if (pllID == V206IOCTL005) {
		result = FUNC206HAL461(freq, &refDiv, &fbIntDiv, &fbRacDiv, &postDiv1, &postDiv2);
	} else if (pllID == V206IOCTL010 && freq == 533 * 1000000) {
		refDiv = 50;
		fbIntDiv = 533;
		fbRacDiv = 0;
		postDiv1 = 2;
		postDiv2 = 1;
	} else {
		result = FUNC206HAL460(freq, &refDiv, &fbIntDiv, &fbRacDiv, &postDiv1, &postDiv2);
	}

	if (0 > result) {
		V206KDEBUG002("[ERROR] calculate the div parameters failed \n");
		return -2;
	}

	FUNC206HAL382(pDev, 1);
	V206DEV002(0x400CB0, 0);
	V206DEV002(0x400C44, pllID);

	V206DEV002(0x400C00, refDiv);
	V206DEV002(0x400C04, fbIntDiv);
	V206DEV002(0x400C08, fbRacDiv);
	V206DEV002(0x400C0C, postDiv1);
	V206DEV002(0x400C10, postDiv2);

	if (fbRacDiv == 0) {
		V206DEV002(0x400C1C, 1);
	} else {
		V206DEV002(0x400C1C, 0);
	}
	V206DEV002(0x400C48, 0);
	V206DEV002(0x400C40, 1);



#define MAC206HAL221     300



	value = V206DEV001(0x400CB0);
	mwv206_timed_loop (tick, (value & 0x1) != 1, MAC206HAL221) {
		value = V206DEV001(0x400CB0);
	}

	FUNC206HAL382(pDev, 0);

	if ((value & 0x1) != 1) {
		V206KDEBUG002("[ERROR] wait pll %d locked timeout[%08x]\n", pllID, value);
		return -3;
	}

	return 0;
}


int FUNC206HAL396(V206DEV025 *pDev, long arg)
{
	V206IOCTL168 *V206FB004;
	V206IOCTL172 setdispport;
	int V206FB011;
	int V206HDMIAUDIO027;
	int clk, pllclkindex;
	int val, formerval, V206IOCTLCMD010;
	int dualpixel;
	int hdmiport, j;
	int enable;

	V206FB004 = (V206IOCTL168 *)arg;
	V206FB011 = V206FB004->V206FB011;
	V206HDMIAUDIO027 = V206FB004->V206HDMIAUDIO027;
	dualpixel = V206FB004->dualpixel;
	if (V206HDMIAUDIO027 > 3 || V206HDMIAUDIO027 < 0) {
		V206KDEBUG002("mwv206_hdmi_config error hdmiid\n");
		return -1;
	}
	if (pDev->pm.V206DEV109 == 0) {
		int id = V206FB004->V206FB011;
		pDev->pm.V206DEV119[id] = *V206FB004;
		pDev->pm.V206DEV114[id] = 1;
	}

	hdmiport = V206GLJ038 + V206HDMIAUDIO027 ;
	enable = pDev->V206DEV144[hdmiport].enable;
	if (dualpixel) {
		enable = 1;
	}

	if (enable) {
		setdispport.V206FB011 = V206FB011;
		setdispport.V206FB008 = hdmiport;
		setdispport.enable = 0;
		setdispport.dualpixel = dualpixel;
		FUNC206HAL393(pDev, (long)&setdispport);
	}

	if (dualpixel && ((V206HDMIAUDIO027 == 2) || (V206HDMIAUDIO027 == 0))) {
		setdispport.V206FB008 = hdmiport + 1;
		FUNC206HAL393(pDev, (long)&setdispport);
	}


	FUNC206HAL192(pDev, V206FB011,
			V206FB004->htotal, V206FB004->hactive, V206FB004->hfrontporch, V206FB004->hsync,
			V206FB004->vtotal, V206FB004->vactive, V206FB004->vfrontporch, V206FB004->vsync,
			V206FB004->framerate, 0, 1);


	{

#if 0
		phystat = V206DEV001(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x3004)));
		if ((phystat != 0xF1) && (phystat != 0xF3)) {
			V206KDEBUG002("The display device is not  connected correctly!\n");
			return -1;
		}
#endif

		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x4002)), 0x0);
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x4002)), 0xFF);

		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x4001)), 0xFF);


		formerval = V206DEV001((0x400248));
		val = ~(1 << V206HDMIAUDIO027);
		V206IOCTLCMD010 = formerval & val;
		V206DEV002((0x400248), V206IOCTLCMD010);
		val = 1 << V206HDMIAUDIO027;
		V206IOCTLCMD010 = formerval | val;
		V206DEV002((0x400248), V206IOCTLCMD010);

		formerval = V206DEV001(((0x400000) + 0x0014));
		val = V206FB011 << (V206HDMIAUDIO027 * 8);
		V206IOCTLCMD010 = (formerval & (~(0xFF << (V206HDMIAUDIO027 * 8)))) | val;
		V206DEV002(((0x400000) + 0x0014), V206IOCTLCMD010);

		val = V206FB004->hactive;
		V206IOCTLCMD010 = val >> 8;
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x1002)), V206IOCTLCMD010);
		V206IOCTLCMD010 = val;
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x1001)), V206IOCTLCMD010);

		val = V206FB004->vactive;
		V206IOCTLCMD010 = val >> 8;
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x1006)), V206IOCTLCMD010);
		V206IOCTLCMD010 = val;
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x1005)), V206IOCTLCMD010);

		val = V206FB004->htotal - V206FB004->hactive;
		V206IOCTLCMD010 = val >> 8;
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x1004)), V206IOCTLCMD010);
		V206IOCTLCMD010 = val;
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x1003)), V206IOCTLCMD010);

		val = V206FB004->vtotal - V206FB004->vactive;
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x1007)), val);

		val = V206FB004->hfrontporch;
		V206IOCTLCMD010 = val >> 8;
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x1009)), V206IOCTLCMD010);
		V206IOCTLCMD010 = val;
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x1008)), V206IOCTLCMD010);

		val = V206FB004->hsync;
		V206IOCTLCMD010 = val >> 8;
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x100B)), V206IOCTLCMD010);
		V206IOCTLCMD010 = val;
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x100A)), V206IOCTLCMD010);

		val = V206FB004->vfrontporch;
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x100C)), val);

		val = V206FB004->vsync;
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x100D)), val);

		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x1011)), 0x0C);
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x1012)), 0x20);
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x1013)), 0x0F);

		val = (V206FB004->framerate) * 1000;
		V206IOCTLCMD010 = val >> 16;
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x1010)), V206IOCTLCMD010);
		V206IOCTLCMD010 = val >> 8;
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x100F)), V206IOCTLCMD010);
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x100E)), val);

		formerval = V206DEV001(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x1000)));
		val = 1 << 3;
		if (V206FB004->isdvi) {
			V206IOCTLCMD010 = formerval & (~val);
		} else {
			V206IOCTLCMD010 = formerval | val;



			pDev->V206DEV140[V206HDMIAUDIO027] = ((unsigned int)V206FB004->htotal * (unsigned int)V206FB004->vtotal *
					(unsigned int)V206FB004->framerate);
		}
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x1000)), V206IOCTLCMD010);


		formerval = V206DEV001(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x1019)));
		val = (formerval & 0xc);
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x1019)), val);

		formerval = V206DEV001(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x101A)));
		if (((V206FB004->hactive) / 16) == ((V206FB004->vactive) / 9)) {
			val = 0xA;
		} else {
			val = 0x9;
		}
		V206IOCTLCMD010 = (formerval & 0xFFFFFFF0) | val;
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x101A)), V206IOCTLCMD010);

		if ((V206FB004->hactive == 640) && (V206FB004->vactive == 480)) {
			V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x101C)), 1);
		}
		if ((V206FB004->hactive == 1920) && (V206FB004->vactive == 1080)) {
			V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x101C)), 16);
		}


		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x4001)), 0);

		val = V206DEV001(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x1000)));
		V206DEV002(MWV206_HDMI_REG(V206HDMIAUDIO027, (0x1000)), val);

	}
	if (V206FB004->isdvi) {
		V206DEV002(((0x403000) + 0x0408) + (0x100 * V206HDMIAUDIO027), 0x0000555F);
		V206DEV002(((0x403000) + 0x040C) + (0x100 * V206HDMIAUDIO027), 0x500F0000);
	} else {
		V206DEV002(((0x403000) + 0x0408) + (0x100 * V206HDMIAUDIO027), pDev->V206DEV159[V206HDMIAUDIO027].V206DEV157);
		V206DEV002(((0x403000) + 0x040C) + (0x100 * V206HDMIAUDIO027), pDev->V206DEV159[V206HDMIAUDIO027].V206DEV158);
	}

	for (j = 0; j < 2; j++) {


		clk = pDev->V206DEV093[V206FB011];
		if (dualpixel) {
			clk /= 2;
		}
		pllclkindex = FUNC206HAL037(clk);
		if (pllclkindex == CLK_FREQ_MAX) {
			V206KDEBUG002("pllclkindex == CLK_FREQ_MAX return -1\n");
			return -1;
		}

		if (FUNC206HAL350(pDev, V206FB011, V206HDMIAUDIO027, pllclkindex, dualpixel, V206FB004->hpol, V206FB004->vpol) != 0) {
			V206KDEBUG002("mwv206_hdmi_config_phy_pll return -1\n");
			return -1;
		}


		if (enable) {
			setdispport.enable = 1;
			FUNC206HAL393(pDev, (long)&setdispport);
			if (FUNC206HAL349(pDev, V206FB011, V206HDMIAUDIO027, pllclkindex, dualpixel, V206FB004->hpol, V206FB004->vpol) == 0) {
				break;
			} else {
				setdispport.enable = 0;
				FUNC206HAL393(pDev, (long)&setdispport);
			}
		}
	}


	if (!V206FB004->isdvi && pDev->V206DEV155) {
		FUNC206LXDEV138(pDev, V206HDMIAUDIO027);
		FUNC206LXDEV021(pDev, V206HDMIAUDIO027, 0);
	}

	return 0;
}

#define   V206IOCTLDISPLAY001       (0x1002<<2)
#define   V206IOCTLDISPLAY002       (0x1001<<2)
#define   V206IOCTLDISPLAY003       (0x1006<<2)
#define   V206IOCTLDISPLAY004       (0x1005<<2)
#define   V206IOCTLDISPLAY005      (0x1003<<2)
#define   V206IOCTLDISPLAY006      (0x1004<<2)
#define   V206IOCTLDISPLAY007       (0x1007<<2)
#define   V206IOCTLDISPLAY008  (0x1008<<2)
#define   V206IOCTLDISPLAY009  (0x1009<<2)
#define   V206IOCTLDISPLAY010   (0x100c<<2)
#define   V206IOCTLDISPLAY011  (0x100a<<2)
#define   V206IOCTLDISPLAY012  (0x100b<<2)
#define   V206IOCTLDISPLAY013   (0x100d<<2)
#define   V206IOCTLDISPLAY014        (0x100e<<2)
#define   V206IOCTLDISPLAY015        (0x100f<<2)
#define   V206IOCTLDISPLAY016        (0x1010<<2)
#define   V206IOCTLDISPLAY017       (0x101a<<2)
#define   V206IOCTLDISPLAY018      (0x1000<<2)
#define   V206IOCTLDISPLAY019        (0x1011<<2)
#define   V206IOCTLDISPLAY020      (0x1012<<2)
#define   V206IOCTLDISPLAY021     (0x1013<<2)

/*
static void FUNC206HAL103(V206DEV025 *pDev, int sel)
{
	V206DEV002(V206IOCTLDISPLAY001 + sel, 4);
	V206DEV002(V206IOCTLDISPLAY002 + sel, 1024);
	V206DEV002(V206IOCTLDISPLAY003 + sel, 3);
	V206DEV002(V206IOCTLDISPLAY004 + sel, 768);
	V206DEV002(V206IOCTLDISPLAY006 + sel, 1);
	V206DEV002(V206IOCTLDISPLAY005 + sel, 280);
	V206DEV002(V206IOCTLDISPLAY007 + sel, 45);
	V206DEV002(V206IOCTLDISPLAY009 + sel, 0);
	V206DEV002(V206IOCTLDISPLAY008 + sel, 88);
	V206DEV002(V206IOCTLDISPLAY010 + sel, 5);
	V206DEV002(V206IOCTLDISPLAY012 + sel, 0);
	V206DEV002(V206IOCTLDISPLAY011 + sel, 44);
	V206DEV002(V206IOCTLDISPLAY013 + sel, 5);
	V206DEV002(V206IOCTLDISPLAY016 + sel, 0);
	V206DEV002(V206IOCTLDISPLAY015 + sel, 234);
	V206DEV002(V206IOCTLDISPLAY014 + sel, 60000);
	V206DEV002(V206IOCTLDISPLAY018 + sel, (1 << 6) | (1 << 5)
			| (1 << 4) | (1 << 3)
			| (2 << 1) |  0);

	V206DEV002(V206IOCTLDISPLAY019 + sel, 0x0C);
	V206DEV002(V206IOCTLDISPLAY020 + sel, 0x20);
	V206DEV002(V206IOCTLDISPLAY021 + sel, 0x0F);

	V206KDEBUG003("[INFO] init hdmi Select done 0x%x.", sel);

}
*/

void FUNC206HAL351(V206DEV025 *pDev)
{
	int value;
	V206DEV002(0x40024C, 0xffffffff);
	V206DEV005("[INFO] video reset done.\n");

	value = V206DEV001(0x800008);
	if (value) {
		pDev->V206DEV159[0].V206DEV157 = V206DEV001(((0x403000) + 0x0408));
		pDev->V206DEV159[1].V206DEV157 = V206DEV001(((0x403000) + 0x0508));
		pDev->V206DEV159[2].V206DEV157 = V206DEV001(((0x403000) + 0x0608));
		pDev->V206DEV159[3].V206DEV157 = V206DEV001(((0x403000) + 0x0708));
		pDev->V206DEV159[0].V206DEV158 = V206DEV001(((0x403000) + 0x040C));
		pDev->V206DEV159[1].V206DEV158 = V206DEV001(((0x403000) + 0x050C));
		pDev->V206DEV159[2].V206DEV158 = V206DEV001(((0x403000) + 0x060C));
		pDev->V206DEV159[3].V206DEV158 = V206DEV001(((0x403000) + 0x070C));
	} else {
		pDev->V206DEV159[0].V206DEV157 = 0x0000333F;
		pDev->V206DEV159[1].V206DEV157 = 0x0000333F;
		pDev->V206DEV159[2].V206DEV157 = 0x0000333F;
		pDev->V206DEV159[3].V206DEV157 = 0x0000333F;
		pDev->V206DEV159[0].V206DEV158 = 0x9000007F;
		pDev->V206DEV159[1].V206DEV158 = 0x9000007F;
		pDev->V206DEV159[2].V206DEV158 = 0x9000007F;
		pDev->V206DEV159[3].V206DEV158 = 0x9000007F;
	}


	V206DEV002(0x400034, 1);


	V206DEV002(((0x400000) + 0x004C), 0x00000000);
	V206DEV002(((0x400000) + 0x014C), 0x00000000);
	return;
}



#define MAC206HAL155(reg, value)    V206DEV006(devInfo, reg, value)
#define MAC206HAL154(reg) V206DEV007(devInfo, reg)


#define V206IOCTLDISPLAY022   (0x400048)


#define V206IOCTLDISPLAY027 (0x400c50)

#define V206IOCTLDISPLAY024 (0x400C8C)


#define V206IOCTLDISPLAY025 (0x400C90)


#define V206IOCTLDISPLAY026 (0x400c80)


#define V206IOCTLDISPLAY023 (0x400c84)

typedef struct FUNC206HAL030 {
	int POSTDIV1;
	int POSTDIV2;
	int min;
	int max;
} PLLRECONFPARAM;

static PLLRECONFPARAM FUNC206HAL100[] = {
	{2, 1, 0, 1600},
	{5, 4, 27,  700},
	{5, 4, 27,  700},
	{5, 4, 27,  700},
	{5, 4, 27,  700},
	{4, 1, 166, 533},
	{2, 1, 400, 1600},
	{4, 1, 50,  2350},
	{4, 1, 200, 800},
	{2, 1, 50,  1200},
};

static int FUNC206HAL010(V206DEV025 *devInfo, enum V206IOCTL109 index, int configfreq)
{
	int FBDIV = 0;
	int postdiv1 = 0;
	int postdiv2 = 0;
	int refdiv = 0;

	postdiv1 = MAC206HAL154(V206IOCTLDISPLAY024);
	postdiv2 = MAC206HAL154(V206IOCTLDISPLAY025);
	refdiv = MAC206HAL154(V206IOCTLDISPLAY026);
	FBDIV = configfreq * postdiv1 * postdiv2;
	FBDIV = FBDIV * refdiv / 100;
	return FBDIV;
}

#define MAC206HAL222 (FUNC206LXDEV098()*5)


int FUNC206HAL135(V206DEV025 *devInfo, int plltype, int configfreq, int enable)
{
	int fbdiv;
	int value;
	GLJ_TICK tick;
	enum V206IOCTL109 index;
	index = plltype;

	if (index >= V206IOCTL015) {
		V206KDEBUG002("unsupport pll type! just support %d~%d\n",
				V206IOCTL005,
				V206IOCTL015);
		return -1;
	}

	if ((enable != 0) && (enable != 1)) {
		V206KDEBUG002("param 4 just support 0 or 1\n");
		return -4;
	}

	if ((configfreq < FUNC206HAL100[index].min)
			|| (configfreq > FUNC206HAL100[index].max)) {
		V206KDEBUG002("unsupport freq! just support %d~%d\n",
				FUNC206HAL100[index].min, FUNC206HAL100[index].max);
		return -2;
	}

	FUNC206HAL382(devInfo, 1);

	if (index == V206IOCTL013) {
		value = MAC206HAL154(V206IOCTLDISPLAY022);
		V206DEV005("PLL_default_freq %#x\n", value);
		value = value >> 16;
		V206DEV005("axi default pll %d\n", value);
		if (value == 600) {
			FUNC206HAL100[index].POSTDIV1 = 2;
		}
	}


	value = MAC206HAL154(V206IOCTLDISPLAY027);
	mwv206_timed_loop (tick, value != 0, MAC206HAL222) {
		value = MAC206HAL154(V206IOCTLDISPLAY027);
	}
	if (value != 0) {
		V206KDEBUG002("[ERROR] wait pll no busy timeout[%d]\n", value);
		FUNC206HAL382(devInfo, 0);
		return -3;
	}

	MAC206HAL155(0x400C44, index);
	if (enable == 1) {
		MAC206HAL155(0x400C48, 1);
	} else {
		MAC206HAL155(0x400C48, 2);
	}
	fbdiv = FUNC206HAL010(devInfo, index, configfreq);
	V206DEV005("FBIDV get %d\n", fbdiv);
	MAC206HAL155(0x400C04, fbdiv);
	MAC206HAL155(0x400C40, 1);

	if (plltype == V206IOCTL005) {
		devInfo->V206DEV073 = configfreq;
	}
	FUNC206HAL382(devInfo, 0);
	return 0;
}


int FUNC206HAL134(V206DEV025 *devInfo, int plltype, int *freq)
{
	int postdiv1 = 0;
	int postdiv2 = 0;
	int refdiv = 0;
	int fbdiv = 0;
	int val = 0;

	FUNC206HAL382(devInfo, 1);

	MAC206HAL155(0x400C44, plltype);

	postdiv1 = MAC206HAL154(V206IOCTLDISPLAY024);
	postdiv2 = MAC206HAL154(V206IOCTLDISPLAY025);
	refdiv = MAC206HAL154(V206IOCTLDISPLAY026);
	fbdiv = MAC206HAL154(V206IOCTLDISPLAY023);
	val = 100 / refdiv;
	val *= fbdiv;
	val /= postdiv1;
	val /= postdiv2;
	*freq = val;
	V206DEV005("\n0x%x: 0x%x, 0x%x: 0x%x,0x%x: 0x%x, 0x%x: 0x%x.\n",
			V206IOCTLDISPLAY024, postdiv1, V206IOCTLDISPLAY025, postdiv2,
			V206IOCTLDISPLAY026, refdiv, V206IOCTLDISPLAY023, fbdiv);
	V206DEV005("\nfreq %d\n", val);
	FUNC206HAL382(devInfo, 0);
	return 0;
}



int FUNC206HAL381(V206DEV025 *pDev, long arg)
{
	V206IOCTL180 *kpll = (V206IOCTL180 *)arg;
	int ret;
	V206DEV005("plltype %d, configfreq %d, enable %d\n", kpll->plltype, kpll->configfreq, kpll->enable);
	FUNC206LXDEV128(FUNC206LXDEV098() / 10);
	ret = FUNC206HAL135(pDev, kpll->plltype, kpll->configfreq, kpll->enable);
	FUNC206LXDEV128(FUNC206LXDEV098() / 10);
	return ret;
}


int FUNC206HAL380(V206DEV025 *pDev, long arg)
{
	V206IOCTL179 *cpll = (V206IOCTL179 *)arg;
	int ret;
	V206DEV005("plltype %d\n", cpll->plltype);
	ret = FUNC206HAL134(pDev, cpll->plltype, &cpll->freq);
	cpll->maxfreq = FUNC206HAL100[cpll->plltype].max;
	cpll->minfreq = FUNC206HAL100[cpll->plltype].min;

	V206DEV005("pllVAL %d\n", cpll->freq);
	return ret;
}

int FUNC206HAL333(V206DEV025 *pDev, long arg)
{
	printk("fall back to show fb\n");
	mwv206fb_active(pDev);
	return 0;
}