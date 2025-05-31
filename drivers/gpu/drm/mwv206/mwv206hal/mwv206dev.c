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
#define MAC206HAL147 1

#include "../include/glj.h"
#include "mwv206dev.h"
#include "../include/mwv206ioctl.h"
#include "mwv206dec.h"

#include "../include/mwv206reg.h"
#include "../include/mwv206config.h"
#include "../include/mwv206_internal.h"

#include <linux/pci.h>
#include <linux/delay.h>
#include <linux/sched.h>
#include <linux/interrupt.h>
#include <linux/input.h>
#include <linux/workqueue.h>
#include "../include/mwv206devconfig.h"

#include "../include/gljos.h"
#include "../include/mwv206config.h"

#include "../include/mwv206api.h"
#include "../include/videoadd_reg.h"
#include "cputype.h"


int FUNC206HAL006(V206DEV025 *pDev)
{
	unsigned int val, V206IOCTLCMD010;
	int ret;

	V206KDEBUG003("[INFO] software reset.\n");


	val = V206DEV001(0x400240);
	V206IOCTLCMD010 = val & 0xFFFFE000;
	FUNC206LXDEV128(FUNC206LXDEV098() / 2);
	ret = FUNC206HAL244(pDev, 0x400240, V206IOCTLCMD010);
	if (0 != ret) {
		V206KDEBUG002("[ERROR] mwv206WriteRegWithCheck  failed(%d)!\n", ret);
		return -1;
	} else {
		V206DEV005("[INFO] mwv206WriteRegWithCheck successed\n");
	}

	V206IOCTLCMD010 = val | 0x111F;
	ret = FUNC206HAL244(pDev, 0x400240, V206IOCTLCMD010);
	if (0 != ret) {
		V206KDEBUG002("[ERROR] mwv206WriteRegWithCheck  failed(%d)!\n", ret);
		return -2;
	} else {
		V206DEV005("[INFO] mwv206WriteRegWithCheck successed\n");
	}




	FUNC206LXDEV128(FUNC206LXDEV098() / 2);

	return ret;
}

int FUNC206HAL001(V206DEV025 *pDev)
{
	unsigned int val, V206IOCTLCMD010;


	val = V206DEV001(0x400240);
	V206IOCTLCMD010 = val & 0xFFFFE000;
	V206DEV002(0x400240, V206IOCTLCMD010);
	val = V206DEV001(0x400240);

	V206IOCTLCMD010 = val | 0x111F;
	V206DEV002(0x400240, V206IOCTLCMD010);
	val = V206DEV001(0x400240);

	return 0;
}

int FUNC206HAL004(V206DEV025 *pDev)
{
	int ret = 0;

	FUNC206HAL291(pDev, 1);

	FUNC206LXDEV128(FUNC206LXDEV098() / 100);
	ret = FUNC206HAL244(pDev, 0x400240, 0x31071100);
	if (0 != ret) {
		V206KDEBUG002("[ERROR] mwv206WriteRegWithCheck  failed(%d)!\n", ret);
		FUNC206HAL291(pDev, 0);
		return -1;
	} else {
		V206DEV005("[INFO] mwv206WriteRegWithCheck successed\n");
	}
	FUNC206LXDEV128(FUNC206LXDEV098() / 10);

	ret = FUNC206HAL244(pDev, 0x400240, 0x3107111F);
	if (0 != ret) {
		V206KDEBUG002("[ERROR] mwv206WriteRegWithCheck  failed(%d)!\n", ret);
		FUNC206HAL291(pDev, 0);
		return -2;
	} else {
		V206DEV005("[INFO] mwv206WriteRegWithCheck successed\n");
	}
	FUNC206LXDEV128(FUNC206LXDEV098() / 100);
	FUNC206HAL291(pDev, 0);
	return 0;
}

int FUNC206HAL065;
unsigned long FUNC206HAL067[4][2], FUNC206HAL068[4];


#define MAC206HAL146  (64)

#define MAC206HAL142  (512)


static int FUNC206HAL005(V206DEV025 *pDev)
{
	jjuint32 endaddr;
	jjuint32 startaddr;


	if (pDev->V206DEV039 == 0) {
		pDev->V206DEV083[0] = 0x00000000;
		endaddr = FUNC206HAL323(pDev, 32);
		pDev->V206DEV082[0] = endaddr;
		pDev->V206DEV083[1] = 0x80000000;
		pDev->V206DEV082[1] = 32;
	} else {
		pDev->V206DEV083[0] = 0x00000000;
		pDev->V206DEV082[0] = 32;


		startaddr = (jjuint32) 0x80000000;
		pDev->V206DEV083[1] = startaddr;
		endaddr = FUNC206HAL323(pDev, startaddr + 32);
		pDev->V206DEV082[1] = endaddr - startaddr;
	}

	return 0;
}

unsigned int FUNC206HAL224(void *dev, int size, int align, void *userdata);
unsigned int FUNC206HAL225(void *dev, int size, int align, void *userdata);



static int FUNC206HAL227(V206DEV025 *pDev, int V206DEV072,
		int V206DEV038, int V206DEV039)
{
	unsigned long addr;
	int blocksize;
	unsigned long memsize2d, memsize3d;
	int ddr0blockcnt, ddr1blockcnt;
	int ddr0resvsize = 0, ddr1resvsize = 0;
	unsigned long ddr02dsize, totolddrsize;

	if (V206DEV038 == 0) {
		V206KDEBUG002("[ERROR] ddrsize is not initialized.\n");
		return -1;
	}

	V206DEV005("pDev->memsize[MWV206_MEM2D_IDX] %#x, pDev->memsize[MWV206_MEM3D_IDX] %#x\n",
			pDev->V206DEV032[0],
			pDev->V206DEV032[1]);

	pDev->V206DEV038 = (unsigned long)V206DEV038 << 20;
	pDev->V206DEV039 = (unsigned long)V206DEV039 << 20;
	memsize2d = pDev->V206DEV032[0];
	memsize3d = pDev->V206DEV032[1];
	ddr02dsize = pDev->V206DEV038 / 2;
	totolddrsize = pDev->V206DEV038 + pDev->V206DEV039;


	if (pDev->V206DEV039 == 0) {
		pDev->V206DEV160 = FUNC206HAL224;
	} else {
		pDev->V206DEV160 = FUNC206HAL225;
	}


	if ((ddr02dsize % (64 << 20)) != 0) {
		V206KDEBUG002("2d reserved size should be aligh 64M.");
		return -1;
	}

	if (memsize2d > ddr02dsize) {
		memsize2d = ddr02dsize;
	}


	if (memsize2d == 0) {
		blocksize = memsize3d;
	} else if (memsize3d == 0) {
		blocksize = memsize2d;
	} else {
		blocksize = memsize2d > memsize3d ? memsize3d : memsize2d;
	}

	V206DEV005("[INFO] ddr02dsize = %ldMbytes\n", ddr02dsize >> 20);
	V206DEV005("[INFO] memblocksize = %dMbytes\n", blocksize >> 20);

	pDev->V206DEV045 = blocksize;
	if (pDev->V206DEV045 == 0 || ((pDev->V206DEV045 - 1) & pDev->V206DEV045)) {
		V206KDEBUG003("[INFO] memblocksize not aligned: 0x%x\n", pDev->V206DEV045);
	}


	FUNC206HAL005(pDev);
	ddr0resvsize = pDev->V206DEV082[0];
	ddr1resvsize = pDev->V206DEV082[1];
	if ((ddr0resvsize > blocksize) || (ddr1resvsize > blocksize)) {
		V206KDEBUG002("[ERROR] resv space(0x%x, 0x%x) is bigger than one block size(0x%x).\n",
				ddr0resvsize, ddr1resvsize, blocksize);
		return -2;
	}


	ddr0blockcnt = pDev->V206DEV038 / blocksize;
	V206DEV005("[INFO] ddr0blockcnt = %d\n", ddr0blockcnt);
	pDev->V206DEV068[0] = FUNC206HAL418.FUNC206HAL204(ddr0blockcnt);
	pDev->V206DEV068[2] = FUNC206HAL418.FUNC206HAL204(ddr0blockcnt);


	addr = 0x00000000;
	FUNC206HAL418.FUNC206HAL197(pDev->V206DEV068[2],
			addr + ddr0resvsize,
			blocksize - ddr0resvsize);
	addr += blocksize;


	while (addr < ddr02dsize) {
		FUNC206HAL418.FUNC206HAL197(pDev->V206DEV068[2], addr, blocksize);
		addr += blocksize;
	}


	if ((V206DEV072 < MAC206HAL146) || (V206DEV072 > MAC206HAL142)) {
		V206KDEBUG002("invalid resmemsize %dMbytes, should be in range of [%d..%d]Mbytes\n",
				V206DEV072, MAC206HAL146, MAC206HAL142);
		return -2;
	}
	V206DEV072 <<= 20;

	if ((unsigned long)V206DEV072 > totolddrsize / 4) {
		V206DEV072 = totolddrsize / 4;
	}

	if ((unsigned long)V206DEV072 > pDev->V206DEV038 - ddr02dsize) {
		pDev->V206DEV072 = pDev->V206DEV038 - ddr02dsize;
	} else {
		pDev->V206DEV072 = V206DEV072;
	}
	V206KDEBUG003("[INFO] resmemsize %dMbytes.\n", pDev->V206DEV072 >> 20);
	pDev->V206DEV077 = addr;
	addr += pDev->V206DEV072;


	if (addr < pDev->V206DEV038) {
		int size = blocksize - (addr % blocksize);
		FUNC206HAL418.FUNC206HAL197(pDev->V206DEV068[0], addr, size);
		addr += size;
	}

	while (addr < (pDev->V206DEV038 + 0x00000000)) {
		FUNC206HAL418.FUNC206HAL197(pDev->V206DEV068[0], addr, blocksize);
		addr += blocksize;
	}

	if (pDev->V206DEV039 == 0) {
		return 0;
	}



	ddr1blockcnt = pDev->V206DEV039 / blocksize;
	V206DEV005("[INFO] ddr1 blockcnt = %d\n", ddr1blockcnt);
	pDev->V206DEV068[1] = FUNC206HAL418.FUNC206HAL204(ddr1blockcnt);

	addr = 0x80000000;

	FUNC206HAL418.FUNC206HAL197(pDev->V206DEV068[1],
			addr + ddr1resvsize,
			blocksize - ddr1resvsize);

	addr += blocksize;

	while (addr < (pDev->V206DEV039 + 0x80000000)) {
		FUNC206HAL418.FUNC206HAL197(pDev->V206DEV068[1], addr, blocksize);
		addr += blocksize;
	}

	pDev->V206DEV084 = 0;
	pDev->V206DEV085 = 0;
	return 0;
}

static int FUNC206HAL003(V206DEV025 *pDev)
{
#define MAC206HAL207 (((0x200000) + 0x4000) + 0x0104)
	int oldval, V206IOCTLCMD010 = 0x5a, newval1;
	oldval = V206DEV001(MAC206HAL207);
	V206DEV005("[0x%x] 0x%x", MAC206HAL207, oldval);
	V206DEV002(MAC206HAL207, V206IOCTLCMD010);
	newval1 = V206DEV001(MAC206HAL207);
	if (V206IOCTLCMD010 != newval1) {
		V206KDEBUG002("[ERROR] reg_base_addr = 0x%lx\n", pDev->V206DEV033);
		V206KDEBUG002("[ERROR] register read/write ERROR!!![0x%x != 0x%x(expectedval)].\n", newval1, V206IOCTLCMD010);
		return -1;
	} else {
		V206KDEBUG003("[INFO] register read/write RIGHT!!![0x%x == 0x%x(expectedval)].\n", newval1, V206IOCTLCMD010);
		V206DEV002(MAC206HAL207, oldval);
		return 0;
	}
}

/*
static int FUNC206HAL239(V206DEV025 *pDev, unsigned long mask, int reset)
{
	unsigned long val;
	val = V206DEV001(0x4);
	if (!reset) {
		val |= mask;
	} else {
		val &= ~mask;
	}
	V206DEV002(0x4, val);
	return 0;
}
*/

int FUNC206HAL315(V206DEV025 *pDev, int memfreq)
{
	int ret = 0;

	FUNC206LXDEV154(pDev, 0,
			0x0,
			3840 * 4,
			32,
			0, 0,
			3840, 2160,
			0,
			0xffffffff,
			3);


	if (memfreq >= 50) {
		ret = FUNC206HAL136(pDev, V206IOCTL010, memfreq * 1000000);
		if (ret != 0) {
			return ret;
		}
	}

	ret = FUNC206HAL215(pDev);
	if (ret != 0) {
		return ret;
	}


	return 0;
}

static inline int FUNC206HAL070(V206DEV025 *pDev)
{
	int v = V206DEV001(0x400008);
	return (v & 0x3);
}

int FUNC206HAL379(V206DEV025 *dev)
{
	int i;
	int pcie_controller = 1;
	struct pci_dev *V206DEV103;

	pcie_controller = FUNC206HAL070(dev);

	if (pcie_controller == 0) {
		V206KDEBUG003("[INFO] pci controller 0.");
		dev->V206DEV036 = 0x0B000000;
		dev->V206DEV037 = 0x0B1FFFFF;
		dev->V206DEV090.V206DEV171 = 1024;

		for (i = 0; i < V206API030; i++) {
			FUNC206HAL367(dev, i, MWV206INTR_ROUTE_TO_PCIE);
			FUNC206HAL366(dev, i, V206API032);
		}
	} else if (pcie_controller == 1) {
		V206KDEBUG003("[INFO] pci controller 1.");
		dev->V206DEV036 = 0x2B000000;
		dev->V206DEV037 = 0x2B0FFFFF;
		if (V206CTYPE008(dev->V206DEV028)) {
			dev->V206DEV090.V206DEV171 = 1024;
		} else {
			dev->V206DEV090.V206DEV171 = (1024*1024*4);
		}

		for (i = 0; i < V206API030; i++) {
			FUNC206HAL367(dev, i, MWV206INTR_ROUTE_TO_PCIE);
			FUNC206HAL366(dev, i, V206API034);
		}
	} else {
		V206KDEBUG002("invalid pcie controller %d.", pcie_controller);
	}

	V206DEV103 = dev->V206DEV103;

	PCI_WRITE_U32(V206DEV103, 0xA78, 0);
	return 0;
}

void FUNC206HAL330(V206DEV025 *pDev)
{

	V206DEV003(((0x400000) + 0x140), 0x0000ffff, 0x00001111);
	V206DEV003(((0x400000) + 0x144), 0xffffffff, 0x11111111);

	if (V206DEVCONFIG036(pDev->V206DEV105.hdmi[0].flags)) {
		V206DEV003(((0x400000) + 0x16C), 0x0000ff00, 0x00002200);
		V206DEV003(((0x400000) + 0xE64), 0x0000ff00, 0x00003300);
	}
	if (V206DEVCONFIG036(pDev->V206DEV105.hdmi[1].flags)) {
		V206DEV003(((0x400000) + 0x16C), 0x0ff00000, 0x02200000);
		V206DEV003(((0x400000) + 0xE64), 0x0ff00000, 0x03300000);
	}

	V206DEV003(((0x400000) + 0x170), 0xff0ff0ff, 0x22022022);
	V206DEV003(((0x400000) + 0xE68), 0xff0ff0ff, 0x33033033);

	if (V206DEVCONFIG036(pDev->V206DEV105.vga[1].flags)) {
		V206DEV003(((0x400000) + 0x174), 0xff, 0x22);
		V206DEV003(((0x400000) + 0xE6C), 0xff, 0x33);
	}

	FUNC206HAL161(pDev->V206DEV051, 50);
}

static void FUNC206HAL318(V206DEV025 *pDev)
{
	pDev->V206DEV144[V206GLJ032].V206FB011 = 0;
	pDev->V206DEV144[V206GLJ032].dualpixel = V206DEVCONFIG037(pDev->V206DEV105.dvo[0].flags);
	pDev->V206DEV144[V206GLJ032].enable = V206DEVCONFIG036(pDev->V206DEV105.dvo[0].flags);
	pDev->V206DEV144[V206GLJ033].V206FB011 = 1;
	pDev->V206DEV144[V206GLJ033].dualpixel = V206DEVCONFIG037(pDev->V206DEV105.dvo[1].flags);
	pDev->V206DEV144[V206GLJ033].enable = V206DEVCONFIG036(pDev->V206DEV105.dvo[1].flags);
	pDev->V206DEV144[V206GLJ034].V206FB011 = 0;
	pDev->V206DEV144[V206GLJ034].dualpixel = V206DEVCONFIG037(pDev->V206DEV105.vga[0].flags);
	pDev->V206DEV144[V206GLJ034].enable = V206DEVCONFIG036(pDev->V206DEV105.vga[0].flags);
	pDev->V206DEV144[V206GLJ035].V206FB011 = 1;
	pDev->V206DEV144[V206GLJ035].dualpixel = V206DEVCONFIG037(pDev->V206DEV105.vga[1].flags);
	pDev->V206DEV144[V206GLJ035].enable = V206DEVCONFIG036(pDev->V206DEV105.vga[1].flags);
	pDev->V206DEV144[V206GLJ036].V206FB011 = 0;
	pDev->V206DEV144[V206GLJ036].dualpixel = V206DEVCONFIG037(pDev->V206DEV105.lvds[0].flags);
	pDev->V206DEV144[V206GLJ036].enable = V206DEVCONFIG036(pDev->V206DEV105.lvds[0].flags);
	pDev->V206DEV144[V206GLJ037].V206FB011 = 1;
	pDev->V206DEV144[V206GLJ037].dualpixel = V206DEVCONFIG037(pDev->V206DEV105.lvds[1].flags);
	pDev->V206DEV144[V206GLJ037].enable = V206DEVCONFIG036(pDev->V206DEV105.lvds[1].flags);
	pDev->V206DEV144[V206GLJ038].V206FB011 = 0;
	pDev->V206DEV144[V206GLJ038].dualpixel = V206DEVCONFIG037(pDev->V206DEV105.hdmi[0].flags);
	pDev->V206DEV144[V206GLJ038].enable = V206DEVCONFIG036(pDev->V206DEV105.hdmi[0].flags);
	pDev->V206DEV144[V206GLJ039].V206FB011 = 1;
	pDev->V206DEV144[V206GLJ039].dualpixel = V206DEVCONFIG037(pDev->V206DEV105.hdmi[1].flags);
	pDev->V206DEV144[V206GLJ039].enable = V206DEVCONFIG036(pDev->V206DEV105.hdmi[1].flags);
	pDev->V206DEV144[V206GLJ040].V206FB011 = 2;
	pDev->V206DEV144[V206GLJ040].dualpixel = V206DEVCONFIG037(pDev->V206DEV105.hdmi[2].flags);
	pDev->V206DEV144[V206GLJ040].enable = V206DEVCONFIG036(pDev->V206DEV105.hdmi[2].flags);
	pDev->V206DEV144[V206GLJ041].V206FB011 = 3;
	pDev->V206DEV144[V206GLJ041].dualpixel = V206DEVCONFIG037(pDev->V206DEV105.hdmi[3].flags);
	pDev->V206DEV144[V206GLJ041].enable = V206DEVCONFIG036(pDev->V206DEV105.hdmi[3].flags);
}

#define MAC206HAL214               (0x00400000)
#define MAC206HAL213             (27)
#define MAC206HAL216           (0x00400004)
#define MAC206HAL215           (0x00030103)
#define MAC206HAL223          (FUNC206LXDEV098()*25)

static void FUNC206HAL167(V206DEV025 *pDev)
{
	GLJ_TICK tick;
	unsigned int vbios_ver = 0, status = 0;


	vbios_ver = V206DEV001(MAC206HAL216);
	mwv206_timed_loop (tick, vbios_ver == 0, MAC206HAL223) {
		vbios_ver = V206DEV001(MAC206HAL216);
	}

	if (vbios_ver > MAC206HAL215) {

		status = V206DEV001(MAC206HAL214);
		mwv206_timed_loop (tick, ((status >> MAC206HAL213) & 1) == 0, MAC206HAL223) {
			status = V206DEV001(MAC206HAL214);
			schedule_timeout_uninterruptible(1);
		}
	}
	V206DEV005("[INFO] vbios version reg = 0x%x, val = 0x%x\n", MAC206HAL216, vbios_ver);
	V206DEV005("[INFO] vbios status reg = 0x%x, val = 0x%x\n", MAC206HAL214, status);
}

static int FUNC206HAL002(V206DEV025 *dev,
		int V206DEV072, int corefreq, int memfreq,
		int V206DEV038, int V206DEV039)
{
	int ret, value;
	V206DEV025 *pDev = dev;
	MWV206DevConfig  *cfg;


	value = V206DEV001(0x00400048);
	value = (value >> 16);
	dev->V206DEV035 = value;
	V206DEV005("axi clock %d\n", dev->V206DEV035);


	dev->V206DEV050 = 50;


	{

		FUNC206HAL167(dev);

		FUNC206HAL170();


		ret = FUNC206HAL166(dev, 0, &dev->V206DEV053);
		if (0 != ret) {
			V206KDEBUG002("[ERROR] jmspiCreate failed(%d)!\n", ret);
			return -7;
		}

		ret = FUNC206HAL166(dev, 1, &dev->V206DEV054);
		if (0 != ret) {
			V206KDEBUG002("[ERROR] jmspiCreate failed(%d)!\n", ret);
			return -8;
		}


		FUNC206HAL171(dev->V206DEV053, 25000);
		FUNC206HAL171(dev->V206DEV054, 25000);


		V206DEV002(0x400034, 1);

		FUNC206HAL184(dev->V206DEV053);
		FUNC206HAL112(dev->V206DEV053);

		if (FUNC206HAL110(dev, FUNC206HAL111, 0)) {
			if (FUNC206HAL110(dev, FUNC206HAL113, 0)) {
				V206KDEBUG003("[INFO] use default configuration!\n");
				FUNC206HAL110(dev, FUNC206HAL108, 1);

				FUNC206HAL146(dev);
				dev->V206DEV107 = 0;
			}
		}

		cfg = FUNC206HAL109(dev);
		if (cfg == NULL) {
			V206KDEBUG002("[ERROR] failed to get config\n");
			return -1;
		}

		V206DEV072 = cfg->chip.V206DEV072;
		corefreq   = cfg->chip.corefreq;
		V206DEV038   = cfg->chip.V206DEV038;
		V206DEV039   = cfg->chip.V206DEV039;
		memfreq    = cfg->chip.memfreq;
		if (memfreq == 533 && dev->V206DEV107 == 1) {
			FUNC206HAL146(dev);
			memfreq = cfg->chip.memfreq;
			cfg->chip.V206DEV038 = V206DEV038;
			cfg->chip.V206DEV039 = V206DEV039;
		}
	}

	if (V206DEV038 == 0) {
		V206KDEBUG002("[ERROR] ddr0 size must set!\n");
		return -3;
	}

	FUNC206HAL379(dev);

#ifdef MWV206_PCIE_RW_DMA
	ret = FUNC206HAL321(dev);
	if (ret != 0) {
		return -5;
	}
	V206KDEBUG003("[INFO] mwv206 dma init successfully!\n");
#endif

	dev->V206DEV049 = 1;

	FUNC206HAL256(dev);

	dev->V206DEV061 = FUNC206LXDEV118();
	dev->V206DEV060 = FUNC206LXDEV118();
	dev->V206DEV059 = FUNC206LXDEV118();
	dev->V206DEV058 = FUNC206LXDEV118();
	dev->V206DEV056 = FUNC206LXDEV118();
	dev->V206DEV057 = FUNC206LXDEV118();
	dev->V206DEV062 = FUNC206LXDEV118();

	V206DEV005("[INFO] decodelock:0x%lx, \tdevlock:0x%lx\n", dev->V206DEV058, dev->V206DEV055);
	V206DEV005("[INFO] ddr0checklock:0x%lx, \tddrlock:0x%lx\n", dev->V206DEV057, dev->V206DEV056);
	V206DEV005("[INFO] dev:0x%lx, \tprolock:0x%lx\n", dev->V206DEV055, dev->prolock);

	dev->V206DEV030 = V206DEV009;
	dev->V206DEV046 = 0x7200;
	dev->V206DEV073 = corefreq;
	dev->V206DEV074 = corefreq;
	dev->V206DEV075 = memfreq;
	dev->V206DEV153 = V206API126;
#if 0
	{
		V206DEV038   = 512;
		V206DEV039   = 0;
		V206DEV072 = 512;
		dev->V206DEV107 = 1;

	}
#endif

	if (dev->V206DEV107 == 0) {
		FUNC206HAL145(dev);
		V206DEV038   = pDev->V206DEV105.chip.V206DEV038;
		V206DEV039   = pDev->V206DEV105.chip.V206DEV039;
		V206DEV072 = pDev->V206DEV105.chip.V206DEV072;
		dev->V206DEV107 = 1;
	}

	if (V206DEV039 == 0) {
		dev->V206DEV041 = 1;
	} else {
		dev->V206DEV041 = 2;
	}
	V206KDEBUG003("[INFO] ddrcnt = %d.\n", dev->V206DEV041);


	FUNC206HAL136(pDev, V206IOCTL005, corefreq);
	V206KDEBUG003("[INFO] mwv206 prim pll inited!\n");
	FUNC206HAL134(pDev, V206IOCTL005, &corefreq);

	FUNC206HAL274(pDev, MWV206_2D_SENDCMDMODE, MWV206_3D_SENDCMDMODE);

	ret = FUNC206HAL315(dev, memfreq);
	if (ret != 0) {
		V206KDEBUG002("[ERROR] mwv206 ddr init failure!\n");
		return -6;
	}
	V206KDEBUG003("[INFO] mwv206 ddr inited!\n");

	memfreq = pDev->V206DEV075;
	V206KDEBUG003("[INFO] corefreq %dMhz, memfreq %dMhz\n", corefreq, memfreq);
	V206KDEBUG003("[INFO] ddr0 %dMbytes, ddr1 %dMbytes\n", V206DEV038, V206DEV039);
	V206KDEBUG003("[INFO] VRAM Size %dMbytes.\n", V206DEV038 + V206DEV039);
	pDev->V206DEV040 = V206DEV038 + V206DEV039;


	if (V206DEV038 > 1024 + 512) {
		V206KDEBUG003("[INFO] ddr0 size:%dMbytes, clamp to 1.5GB\n", V206DEV038);
		pDev->V206DEV105.chip.V206DEV038 = 1024 + 512;
		V206DEV038   = pDev->V206DEV105.chip.V206DEV038;
	}
	if (V206DEV039 > 1024 + 512) {
		V206KDEBUG003("[INFO] ddr1 size:%dMbytes, clamp to 1.5GB\n", V206DEV039);
		pDev->V206DEV105.chip.V206DEV039 = 1024 + 512;
		V206DEV039   = pDev->V206DEV105.chip.V206DEV039;
	}


	FUNC206HAL003(dev);

	ret = FUNC206HAL227(dev, V206DEV072, V206DEV038, V206DEV039);
	if (ret != 0) {
		V206KDEBUG002("[ERROR] mwv206MemInit failed(%d)!\n", ret);
		return -7;
	}

	V206DEV002((0x40024C), 0xffffffff);

	FUNC206HAL351(dev);


	FUNC206HAL156();
	ret = FUNC206HAL151(dev, &dev->V206DEV051);
	if (0 != ret) {
		V206KDEBUG002("[ERROR] jmiicCreate failed(%d)!\n", ret);
		return -9;
	} else {
		V206DEV005("[INFO] jmiicCreate successed, mJmIicHandle=%p\n", dev->V206DEV051);
	}

	FUNC206HAL330(dev);
	FUNC206HAL318(dev);


	FUNC206HAL362(pDev);

	FUNC206HAL255(pDev);


	FUNC206HAL383();

	FUNC206HAL385(pDev);

	return 0;
}

struct mem_bar_info {
	unsigned int no;
	unsigned long size;
};

static void FUNC206HAL216(struct pci_dev *V206DEV103)
{
	int             region;
#define MAC206HAL043 32

	for (region = 0; region < MAC206HAL043; region++) {
		PCI_WRITE_U32(V206DEV103, 0x900,
				(1 << 31)
				| (region << 0));
		PCI_WRITE_U32(V206DEV103, 0x908, 0);
	}

}

static void FUNC206HAL234(struct pci_dev *V206DEV103, int region, unsigned long phys, unsigned long size)
{
	PCI_WRITE_U32(V206DEV103, 0x900,
			(1 << 31)
			| (region << 0));

	PCI_WRITE_U32(V206DEV103, 0x90C, (phys) & 0xffffffff);
	PCI_WRITE_U32(V206DEV103, 0x910, (phys) >> 32);
	PCI_WRITE_U32(V206DEV103, 0x914, (phys + size - 1) & 0xffffffff);
}


void FUNC206HAL221(struct pci_dev *V206DEV103)
{
	unsigned long phys;
	unsigned long size;
	int region;
	int bar;
	V206DEV025 *pDev = pci_get_drvdata(V206DEV103);


	FUNC206HAL216(V206DEV103);


	for (bar = 0; bar < 7; bar++) {
		region = bar;
		size   = MWV206_GET_PCI_BAR_LEN(V206DEV103, bar);
		phys   = MWV206_GET_PCI_BAR_STARTADDR(V206DEV103, bar);

		if (V206CTYPE008(pDev->V206DEV028)) {
			phys &= ~0x80000000000;
		}

		FUNC206HAL234(V206DEV103, region, phys, size);
	}
}

int FUNC206HAL217(struct pci_dev *V206DEV103,
		unsigned int *pRegbar, unsigned int *pMem2dbar, unsigned int *pMem3dbar)
{
	unsigned long size;
	unsigned int bar;
	unsigned int V206DEV043;
	struct mem_bar_info V206DEV044[2] = { {0xff, 0}, {0xff, 0} };

	V206DEV043 = 0xff;

	for (bar = 0; bar < DEVICE_COUNT_RESOURCE; bar++) {
		size = (unsigned long)MWV206_GET_PCI_BAR_LEN(V206DEV103, bar);
		if (size == (16 << 20)) {
			V206DEV043 = bar;
		} else if (size == (32 << 20)) {
			V206DEV043 = bar;
		} else if (size > (16 << 20)) {
			if (V206DEV044[0].no == 0xff) {
				V206DEV044[0].no = bar;
				V206DEV044[0].size = size;
			} else {
				V206DEV044[1].no = bar;
				V206DEV044[1].size = size;
			}
		} else {

		}
		if ((V206DEV043 != 0xff) && (V206DEV044[0].no != 0xff) && (V206DEV044[1].no != 0xff)) {
			break;
		}
	}

	if (V206DEV044[0].no == 0xff) {
		V206KDEBUG002("[ERROR] mem bar is missing!!!!");
		return -2;
	}
	if (V206DEV043 == 0xff) {
		V206KDEBUG002("[ERROR] regbar is missing!!!!");
		return -3;
	}
	if (V206DEV044[1].no == 0xff) {
		V206DEV044[1].no = V206DEV044[0].no;
		V206DEV044[1].size = V206DEV044[0].size;
	}

	*pRegbar = V206DEV043;


	if (V206DEV044[0].size > V206DEV044[1].size) {
		*pMem2dbar = V206DEV044[0].no;
		*pMem3dbar = V206DEV044[1].no;
	} else {
		*pMem2dbar = V206DEV044[1].no;
		*pMem3dbar = V206DEV044[0].no;
	}

	V206KDEBUG003("[INFO] regbar: %d, mem2dbar: %d, mem3dbar: %d\n", V206DEV043, *pMem2dbar, *pMem3dbar);
	return 0;
}

int FUNC206HAL148(V206DEV025 *dev)
{
	unsigned long start, size;
	struct pci_dev *V206DEV103;
	int i, result, ret = 0;
	unsigned int V206DEV043, V206FB006, mem3dbar;

	V206DEV103 = dev->V206DEV103;

	if (V206DEV103 == NULL) {
		return -1;
	}

	dev->V206DEV028 = V206CTYPE011();


	start = (unsigned long)MWV206_GET_PCI_BAR_STARTADDR(V206DEV103, 4);
	size = (unsigned long)MWV206_GET_PCI_BAR_LEN(V206DEV103, 4);

	if (V206CTYPE008(dev->V206DEV028)) {
		start |= 0x80000000000;
	}

	dev->V206DEV034 = (unsigned long)ioremap(start, size);
	if (0 == dev->V206DEV034) {
		V206KDEBUG002("[ERROR] Can't ioremap BAR4\n");
		return -ENOMEM;
	}


	FUNC206HAL221(V206DEV103);

	ret = FUNC206HAL217(V206DEV103, &V206DEV043, &V206FB006, &mem3dbar);
	if (ret != 0) {
		goto FUNC206HAL054;
	}


	size = (unsigned long)MWV206_GET_PCI_BAR_LEN(V206DEV103, V206DEV043);
	if (size == (16 << 20)) {
		dev->V206DEV155 = 0;
	} else if (size == (32 << 20)) {
		dev->V206DEV155 = 1;
	}


	dev->V206DEV043 = V206DEV043;
	dev->V206DEV044[0] = V206FB006;
	dev->V206DEV044[1] = mem3dbar;


	start = (unsigned long)MWV206_GET_PCI_BAR_STARTADDR(V206DEV103, mem3dbar);

	if (V206CTYPE008(dev->V206DEV028)) {
		start |= 0x80000000000;
	}

	size = (unsigned long)MWV206_GET_PCI_BAR_LEN(V206DEV103, mem3dbar);
	V206DEV005("[INFO] MWV206 BAR%d - PHY: 0x%lx, size = 0x%lx\n", mem3dbar, start, size);

	V206DEV005("[INFO] size = 0x%lx\n", size);

	if (size > (2ULL << 30)) {
		size = (2ULL << 30);
	}

	V206DEV005("[INFO] size = 0x%lx\n", size);

	if (V206CTYPE009(dev->V206DEV028) || V206CTYPE008(dev->V206DEV028)
			|| V206CTYPE010(dev->V206DEV028)) {
		V206KDEBUG003("[INFO] wc is true.\n");
		dev->V206DEV145 = 1;
		dev->V206DEV031[1] = (unsigned long)ioremap_wc(start, size);
	} else {
		V206KDEBUG003("[INFO] wc is false.\n");
		dev->V206DEV145 = 0;
		dev->V206DEV031[1] = (unsigned long)ioremap(start, size);
	}

	dev->V206DEV032[1] = size;
	if (0 == dev->V206DEV031[1]) {
		V206KDEBUG002("[ERROR] Can't ioremap BAR%d  base = 0x%lx, size = %ldM\n", mem3dbar, start, size >> 20);
		ret = -ENOMEM;
		goto FUNC206HAL054;
	}
	FUNC206HAL067[FUNC206HAL065][1] = dev->V206DEV031[1];
	V206KDEBUG003("[INFO] MWV206 BAR%d - PHY: 0x%lx, size = %ldM, VIR: 0x%lx\n",
			mem3dbar, start, size >> 20, dev->V206DEV031[1]);


	size = (unsigned long)MWV206_GET_PCI_BAR_LEN(V206DEV103, V206FB006);
	dev->V206DEV032[0] = size;
	V206KDEBUG003("[INFO] MWV206 BAR%d - size = %ldM\n",
			V206FB006, size >> 20);


	start = (unsigned long)MWV206_GET_PCI_BAR_STARTADDR(V206DEV103, V206DEV043);
	size = (unsigned long)MWV206_GET_PCI_BAR_LEN(V206DEV103, V206DEV043);

	if (V206CTYPE008(dev->V206DEV028)) {
		start |= 0x80000000000;
	}


	dev->V206DEV033 = (unsigned long)ioremap(start, size);

	if (0 == dev->V206DEV033) {
		V206KDEBUG002("[ERROR] Can't ioremap BAR%d  base = 0x%lx\n", V206DEV043, start);
		ret = -ENOMEM;
		goto FUNC206HAL055;
	}
	FUNC206HAL068[FUNC206HAL065] = dev->V206DEV033;
	V206KDEBUG003("[INFO] MWV206 BAR%d - PHY: 0x%lx, size = %ldM, VIR: 0x%lx\n", V206DEV043, start, size >> 20, dev->V206DEV033);


	dev->V206DEV055 = FUNC206LXDEV118();
	for (i = 0; i < 4; i++) {
		dev->V206DEV093[i] = 65;
	}

	FUNC206HAL235(dev, V206DEV043, 0x2000000);
	FUNC206HAL235(dev, dev->V206DEV044[1], 0xA0000000);

	result = pci_msi_enabled();
	if (0 != result)    {
		result = pci_enable_msi(V206DEV103);

		if (0 == result) {
			V206DEV005("[INFO] MSI avaliable\n");
		} else {
			V206DEV005("[ERROR] MSI not avaliable\n");
		}
	}

	dev->V206DEV047 = V206DEV103->bus->number;
	dev->irq = V206DEV103->irq;



	if (dev->irq != 0xff) {
		FUNC206HAL355(dev);
		result = request_irq(dev->irq,
				FUNC206HAL364,
				IRQF_SHARED,
				"MWV206",
				(void *)dev);
		if (0 != result) {
			result = -ENODEV;
			V206KDEBUG002("[ERROR] request_irq (%d) failed, result = %d\n", dev->irq, result);
			goto FUNC206HAL056;
		}
		tasklet_init(&dev->V206DEV154, FUNC206HAL363, (unsigned long)dev);
	}
	dev->V206DEV104 = FUNC206LXDEV010((128));
	if (!dev->V206DEV104) {
		V206KDEBUG002("[ERROR] kmemalloc failed!\n");
		ret = -1;
		goto FUNC206HAL056;
	}


	ret = FUNC206HAL002(dev, 0, 0, 0, 0, 0);
	if (ret != 0) {
		V206KDEBUG002("[ERROR] mwv206DevInitConfig failed!\n");
		goto FUNC206HAL056;
	}


	{
		unsigned long decRegBase  = start + V206DECH023;
		V206DEV005("[INFO] decRegBase = 0x%lx\n", decRegBase);
		ret = mwv206dec_init(&dev->V206DEV138, decRegBase,  dev);
		if (0 != ret) {
			V206KDEBUG002("[ERROR] mwv206dec_init failed(%d)!\n", ret);
			goto FUNC206HAL056;
		} else {
			V206DEV005("[INFO] mwv206dec_init successed\n");
		}
	}

	dev->V206DEV029 = FUNC206HAL065;
	FUNC206HAL065++;
	V206KDEBUG003("[INFO] g_boardCnt is:%d!\n", FUNC206HAL065);

	return 0;

FUNC206HAL056:
	iounmap((void *)FUNC206HAL068[FUNC206HAL065]);
FUNC206HAL055:
	iounmap((void *)FUNC206HAL067[FUNC206HAL065][1]);
FUNC206HAL054:
	iounmap((void *)dev->V206DEV034);
	return ret;
}

int FUNC206HAL149(V206DEV025 *pDev)
{

	FUNC206HAL357(pDev);


	FUNC206HAL265(pDev);


	FUNC206HAL324(pDev);

	disable_irq(pDev->irq);
	free_irq(pDev->irq, (void *)pDev);
	pci_disable_msi(pDev->V206DEV103);

	if (pDev->V206DEV080.V206DEV162) {
#ifdef MWV206_RING_USE_DMABUF
		FUNC206LXDEV100(&(pDev->V206DEV103->dev), pDev->V206DEV080.V206DEV164,
				(void *)(uintptr_t)pDev->V206DEV080.V206DEV163, pDev->V206DEV080.V206DEV162);
#else
		FUNC206LXDEV120((void *)(uintptr_t)pDev->V206DEV080.V206DEV163);
#endif
	}


	if (pDev->V206DEV081.startaddr) {
		FUNC206HAL226(pDev, pDev->V206DEV081.startaddr);
	}

	mwv206dec_uninit(pDev->V206DEV138, pDev);

	if (pDev->V206DEV104) {
		FUNC206LXDEV120(pDev->V206DEV104);
	}
	return 0;
}

MODULE_LICENSE("GPL v2");
