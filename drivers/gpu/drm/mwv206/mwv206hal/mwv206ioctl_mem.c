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
#include "cputype.h"

void *FUNC206HAL377(void *dst, const unsigned char *src, int len)
{
	int i;
	unsigned char *cdst, *csrc;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;

	for (i = 0; i < len; i++) {
		*cdst = *csrc; cdst++; csrc++;
	}

	return dst;
}

void *FUNC206HAL378(void *dst, unsigned char val, int len)
{
	int i;
	unsigned char *cdst;

	cdst = (unsigned char *)dst;

	for (i = 0; i < len; i++) {
		*cdst = val; cdst++;
	}

	return dst;
}

void *FUNC206HAL071(unsigned int addr, unsigned int addrHi)
{
	unsigned long a;
	a = addrHi;
	a <<= 16;
	a <<= 16;
	a += addr;
	return (void *)a;
}


unsigned int FUNC206HAL225(void *dev, int size, int align, void *userdata)
{
	unsigned int addr = 0;
	int mid;
	V206DEV025 *pDev = dev;

	if (size < 0) {
		size = -size;

		if (size < 0) {
			return 0;
		}
		addr = (int)FUNC206HAL418.FUNC206HAL206(pDev->V206DEV068[2], size, align, userdata);
		if (addr != 0) {
			return addr;
		}
	}

	{
		V206DEV005("alignment = %d, size =  %d\n", align, size);
		mid = 1;
		addr = (unsigned int)FUNC206HAL418.FUNC206HAL206(pDev->V206DEV068[mid], size, align, userdata);
		if (addr == 0) {
			mid = 0;
			addr = (unsigned int)FUNC206HAL418.FUNC206HAL206(pDev->V206DEV068[mid], size, align, userdata);
		}
	}

	if (0 != addr) {
		V206DEV005("[INFO] mwv206 mem alloc successed, mid = %d, align = 0x%x, size = %d, addr = 0x%x\n", mid, align, size, addr);
	}

	return addr;
}

unsigned int FUNC206HAL224(void *dev, int size, int align, void *userdata)
{
	unsigned int addr = 0;
	V206DEV025 *pDev = dev;

	if (size < 0) {
		size = -size;

		if (size < 0) {
			return 0;
		}
	}

	addr = (int)FUNC206HAL418.FUNC206HAL206(pDev->V206DEV068[2], size, align, userdata);
	if (addr != 0) {
		return addr;
	}

	addr = (unsigned int)FUNC206HAL418.FUNC206HAL206(pDev->V206DEV068[0], size, align, userdata);
	if (0 != addr) {
		V206DEV005("[INFO] mwv2066 mem alloc successed, mid = %d, align = %d, size = %d, addr = 0x%x\n",
				mid, align, size, addr);
	}

	return addr;
}

unsigned int FUNC206HAL373(V206DEV025 *pDev, unsigned int addr, void *userdata)
{

	if (FUNC206HAL418.FUNC206HAL211(pDev->V206DEV068[2], addr, userdata) == 0) {
		return 0;
	}
	if (FUNC206HAL418.FUNC206HAL211(pDev->V206DEV068[0], addr, userdata) == 0) {
		return 0;
	}

	return FUNC206HAL418.FUNC206HAL211(pDev->V206DEV068[1], addr, userdata);
}

void FUNC206HAL374(V206DEV025 *pDev)
{
	V206KDEBUG002("==============memory control 0:==============\n");
	FUNC206HAL418.FUNC206HAL212(pDev->V206DEV068[0]);
	V206KDEBUG002("==============memory control 1:==============\n");
	FUNC206HAL418.FUNC206HAL212(pDev->V206DEV068[1]);
	V206KDEBUG002("==============memory control 2:==============\n");
	FUNC206HAL418.FUNC206HAL212(pDev->V206DEV068[2]);
	return;
}

unsigned int FUNC206HAL375(V206DEV025 *pDev)
{
	return FUNC206HAL418.FUNC206HAL213(pDev->V206DEV068[0])
		+ FUNC206HAL418.FUNC206HAL213(pDev->V206DEV068[1])
		+ FUNC206HAL418.FUNC206HAL213(pDev->V206DEV068[2]);
}

unsigned int FUNC206HAL371(V206DEV025 *pDev, unsigned int *paddr)
{
	unsigned int b0, b1, b2, mb, addr0, addr1, addr2;

	b0 = FUNC206HAL418.FUNC206HAL207(pDev->V206DEV068[0], &addr0);
	b1 = FUNC206HAL418.FUNC206HAL207(pDev->V206DEV068[1], &addr1);
	b2 = FUNC206HAL418.FUNC206HAL207(pDev->V206DEV068[2], &addr2);

	mb = b0; *paddr = addr0;
	if (mb < b1) {
		mb = b1;
		*paddr = addr1;
	}

	if (mb < b2) {
		mb = b2;
		*paddr = addr2;
	}

	return mb;
}

unsigned int FUNC206HAL376(V206DEV025 *pDev)
{
	return FUNC206HAL418.FUNC206HAL213(pDev->V206DEV068[0])
		+ FUNC206HAL418.FUNC206HAL213(pDev->V206DEV068[1]);
}

unsigned int FUNC206HAL372(V206DEV025 *pDev, unsigned int *paddr)
{
	unsigned int b1, b2, mb, addr1, addr2;

	b1 = FUNC206HAL418.FUNC206HAL207(pDev->V206DEV068[0], &addr1);
	b2 = FUNC206HAL418.FUNC206HAL207(pDev->V206DEV068[1], &addr2);

	mb = b1; *paddr = addr1;
	if (mb < b2) {
		mb = b2;
		*paddr = addr2;
	}

	return mb;
}

int V206IOCTL135(V206DEV025 *pDev, long arg, void *userdata)
{
	V206IOCTL170 *alloc;
	unsigned int addr;

	alloc = (V206IOCTL170 *)arg;

	switch (alloc->op) {
	case MWV206MEM_ALLOC:
		addr = pDev->V206DEV160(pDev, alloc->size, alloc->alignment, userdata);
		if (0 == addr) {
			unsigned int mb, maddr;
			V206KDEBUG002("[ERROR] mwv206 mem alloc failed, size = %d, align = %d.\n",
					alloc->size, alloc->alignment);
			if (alloc->size < 0) {
				mb = FUNC206HAL371(pDev, &maddr);
				V206KDEBUG002("[INFO] mwv206 mem: maxblock size = %dbytes, addr = 0x%x for 2D module.\n",
						mb, maddr);
				V206KDEBUG002("[INFO] mwv206 mem: %dbytes is free for 2D module.\n",
						FUNC206HAL375(pDev));
			} else {
				mb = FUNC206HAL372(pDev, &maddr);
				V206KDEBUG002("[INFO] mwv206 mem: maxblock size = %dbytes, addr = 0x%x for modules except 2D.\n",
						mb, maddr);
				V206KDEBUG002("[INFO] mwv206 mem: %dbytes is free for modules except 2D.\n",
						FUNC206HAL376(pDev));
			}
#ifdef __DEBUG__
			FUNC206HAL374(pDev);
#endif
		}
		alloc->addr = addr;
		return addr ? 0 : -2;
		break;
	case MWV206MEM_REFERENCE:
		if (FUNC206HAL373(pDev, alloc->addr, userdata) != 0) {
			V206KDEBUG002("[ERROR] mwv206 mem reference failed, addr = 0x%x.\n", alloc->addr);
			return -2;
		}
		return 0;
		break;
	default:
		break;
	}

	return -3;
}

int V206IOCTL136(V206DEV025 *pDev, long arg, void *userdata)
{
	V206IOCTL171 *memfree;
	int ret;
	memfree = (V206IOCTL171 *)arg;

	ret = FUNC206HAL418.FUNC206HAL201(pDev->V206DEV068[2], memfree->addr, userdata);
	if (ret == 0) {
		goto FUNC206HAL021;
	}

	ret = FUNC206HAL418.FUNC206HAL201(pDev->V206DEV068[0], memfree->addr, userdata);
	if (ret == 0) {
		goto FUNC206HAL021;
	}

	ret = FUNC206HAL418.FUNC206HAL201(pDev->V206DEV068[1], memfree->addr, userdata);

FUNC206HAL021:
	memfree->addr = 0;
	return ret;
}



unsigned int FUNC206HAL223(void *pDev, int size, int alignment)
{
	int ret;
	ret = ((V206DEV025 *)pDev)->V206DEV160(pDev, size, alignment, pDev);
	if (ret == 0) {
		V206KDEBUG002("[ERROR] mwv206MemAlloc failed, size = %d, align = 0x%x.\n",
				size, alignment);
	}
	return ret;
}



void FUNC206HAL226(void *pDev, unsigned int addr)
{
	V206IOCTL171 memfree;

	memfree.addr = addr;

	V206IOCTL136((V206DEV025 *)pDev, (long)&memfree, pDev);
}

unsigned long FUNC206HAL334(V206DEV025 *pDev, unsigned int barIdx, unsigned int addr)
{
	unsigned int bsize;
	unsigned int page, offset;

	bsize = pDev->V206DEV032[barIdx] - 1;
	addr = mwv206GetAXIAddr(addr);

	page   = addr & (~bsize);
	offset = addr & bsize;

	FUNC206HAL235(pDev, pDev->V206DEV044[barIdx], page);
	return (pDev->V206DEV031[barIdx] + offset);
}

/*
static int FUNC206HAL475(void *usermem, void *kermem, int size, int ksize)
{
	int ret, oncecopysize;
	int i, cnt;
	void *pmem;

	ret = 0;

	oncecopysize = size < ksize ? size : ksize;
	cnt = size / oncecopysize;

	pmem = usermem;
	for (i = 0; i < cnt; i++) {
		ret = copy_to_user((void __user *)pmem, kermem, oncecopysize);
		if (ret != 0) {
			return ret;
		}
		pmem += oncecopysize;
	}

	oncecopysize = size % oncecopysize;
	if (oncecopysize) {
		ret = copy_to_user((void __user *)pmem, kermem, oncecopysize);
	}
	return ret;
}

static int FUNC206HAL474(void *usermem, void *kermem, int size, int ksize)
{
	int ret, oncecopysize;
	int i, cnt;
	void *pmem;

	ret = 0;

	oncecopysize = size < ksize ? size : ksize;
	cnt = size / oncecopysize;

	pmem = usermem;
	for (i = 0; i < cnt; i++) {
		ret = copy_from_user(kermem, (void __user *)pmem, oncecopysize);
		if (ret != 0) {
			return ret;
		}
		pmem += oncecopysize;
	}

	oncecopysize = size % oncecopysize;
	if (oncecopysize) {
		ret = copy_from_user(kermem, (void __user *)pmem, oncecopysize);
	}
	return ret;
}

static int FUNC206HAL476(void *usermem, void *kermem, unsigned char *V206IOCTLCMD009,
		int size, int ksize)
{
	int ret, oncecopysize;
	int i, cnt;
	void *pmem;

	ret = 0;

	oncecopysize = size < ksize ? size : ksize;
	cnt = size / oncecopysize;

	pmem = usermem;
	for (i = 0; i < cnt; i++) {

		ret = copy_from_user(kermem, (void __user *)pmem, oncecopysize);
		if (ret != 0) {
			return ret;
		}

		memcpy_toio((void *)V206IOCTLCMD009, kermem, oncecopysize);
		pmem += oncecopysize;
		V206IOCTLCMD009 += oncecopysize;
	}

	oncecopysize = size % oncecopysize;
	if (oncecopysize) {

		ret = copy_from_user(kermem, (void __user *)pmem, oncecopysize);
		if (ret == 0) {

			memcpy_toio((void *)V206IOCTLCMD009, kermem, oncecopysize);
		}
	}

	return ret;
}
*/

static int valid_mem_access(V206DEV025 *pDev, V206IOCTL146 *memaccess)
{
	unsigned int addr;
	unsigned int size;

	addr     = memaccess->V206IOCTLCMD009;
	size     = memaccess->size;

	switch (memaccess->op) {
	case V206IOCTL020:
	case V206IOCTL021:
		size = memaccess->size;
		break;
	case V206IOCTL023:
	case V206IOCTL024:
		size  = memaccess->mwv206stride * memaccess->vsize;

		size -= (memaccess->mwv206stride - memaccess->size);
		break;
	case V206IOCTL022:
		size = memaccess->vsize * memaccess->size;
		break;
	default:
		return 0;

	}

	if (!addr_in_fb_range(pDev, addr) || !size_in_fb_range(pDev, addr, size)) {
		return 0;
	}

	return 1;
}

int V206IOCTL134(V206DEV025 *pDev, long arg)
{
	V206IOCTL146 *memaccess;
	int ret;
	int lines, size;
	unsigned char *V206DEV031;
	unsigned char *V206IOCTLCMD009;
	ret = 0;
	memaccess = (V206IOCTL146 *)arg;

	if (!valid_mem_access(pDev, memaccess)) {
		V206KDEBUG002("[INFO] invalid memaccess, ignored:\n");
		V206KDEBUG002("[INFO] pid:%d op:%d mwv206addr:0x%x mwv206stride:0x%x size:%d vsize:%d\n",
				current->pid,
				memaccess->op,
				memaccess->V206IOCTLCMD009,
				memaccess->mwv206stride,
				memaccess->size,
				memaccess->vsize);
		return -1;
	}


	FUNC206HAL316(pDev, 1);

	V206IOCTLCMD009 = (unsigned char *)FUNC206HAL334(pDev, 1, memaccess->V206IOCTLCMD009);
	V206DEV031 = (unsigned char *)memaccess->V206DEV031;


	size = memaccess->size;
	switch (memaccess->op) {
	case V206IOCTL023: {


		{
			for (lines = 0; lines < memaccess->vsize; lines++) {
				ret = copy_to_user((void __user *)V206DEV031, (void *)V206IOCTLCMD009, size);
				if (ret != 0) {
					V206KDEBUG002("MWV206MEM_READ2D: copy_to_user error, ret = %d.", ret);
					goto FUNC206HAL020;
				}
				V206DEV031 += memaccess->memstride;
				V206IOCTLCMD009 += memaccess->mwv206stride;
			}
		}
		} break;
	case V206IOCTL024: {
#if (_MWV206_CPU_ == _MWV206_AARCH64_)

		{
			for (lines = 0; lines < memaccess->vsize; lines++) {

				ret = FUNC206HAL476(V206DEV031, pDev->V206DEV104, V206IOCTLCMD009, size, (128));
				if (ret != 0) {
					V206KDEBUG002("MWV206MEM_WRITE2D: copy_from_user error, ret = %d.", ret);
					goto FUNC206HAL020;
				}
				V206DEV031 += memaccess->memstride;
				V206IOCTLCMD009 += memaccess->mwv206stride;
			}
		}
#else
		{
			for (lines = 0; lines < memaccess->vsize; lines++) {
				ret = copy_from_user((void *)V206IOCTLCMD009, (void __user *)V206DEV031, size);
				if (ret != 0) {
					V206KDEBUG002("MWV206MEM_WRITE2D: copy_from_user error, ret = %d.", ret);
					goto FUNC206HAL020;
				}
				V206DEV031 += memaccess->memstride;
				V206IOCTLCMD009 += memaccess->mwv206stride;
			}
		}
#endif
		} break;
	case V206IOCTL020: {

		{
			V206DEV005("[cpu-type] MWV206MEM_READ: not ft1500a.\n");
			ret = copy_to_user((void __user *)V206DEV031, (void *)V206IOCTLCMD009, size);
			if (ret != 0) {
				V206KDEBUG002("MWV206MEM_READ: copy_to_user error, ret = %d.", ret);
				goto FUNC206HAL020;
			}
		}
		} break;
	case V206IOCTL021: {
#if (_MWV206_CPU_ == _MWV206_AARCH64_)

		{


			ret = FUNC206HAL476(V206DEV031, pDev->V206DEV104, V206IOCTLCMD009, size, (128));
			if (ret != 0) {
				V206KDEBUG002("MWV206MEM_WRITE: copy_from_user error, ret = %d.", ret);
				goto FUNC206HAL020;
			}
			break;
		}
#else
		{
			V206DEV005("[cpu-type] MWV206MEM_WRITE: not ft1500a.\n");
			ret = copy_from_user((void *)V206IOCTLCMD009, (void __user *)V206DEV031, size);
			if (ret != 0) {
				V206KDEBUG002("MWV206MEM_WRITE: copy_from_user error, ret = %d.", ret);
				goto FUNC206HAL020;
			}
		}
#endif
		} break;
	case V206IOCTL022: {
		int vsize = memaccess->vsize;
		unsigned int value = memaccess->value;
		if (vsize == 1) {
#if (_MWV206_CPU_ == _MWV206_AARCH64_)
			{
				memset_io((void *)V206IOCTLCMD009, value, size);
			}
#else
			{
				V206DEV005("[cpu-type] MWV206MEM_SET: not ft1500a.\n");
				memset((void *)V206IOCTLCMD009, value, size);
			}
#endif
		} else if (vsize == 2) {
			unsigned short *pdest;
			int i;
			pdest = (unsigned short *)V206IOCTLCMD009;
			for (i = 0; i < size; i++) {
				*pdest++ = (unsigned short)value;
			}
		} else if (vsize == 4) {
			unsigned int *pdest;
			int i;
			pdest = (unsigned int *)V206IOCTLCMD009;
			for (i = 0; i < size; i++) {
				*pdest++ = value;
			}
		} else {
			ret = -102;
		}
		} break;
	default: {
		 ret = -101;
		} break;
	}
FUNC206HAL020:

	FUNC206HAL316(pDev, 0);
	V206DEV005("[DONE]mwv206_mem_access 0x%x unlock.\n", memaccess->op);
	return ret;
}

int FUNC206HAL229(V206DEV025 *pDev,
		unsigned int V206IOCTLCMD009, const unsigned char *V206IOCTLCMD006, unsigned int size)
{
	unsigned long V206KG2D008;

	FUNC206HAL316(pDev, 1);
	V206KG2D008 = FUNC206HAL334(pDev, 1, V206IOCTLCMD009);
#if (_MWV206_CPU_ == _MWV206_AARCH64_)
	{
		V206DEV005("[cpu-type] mwv206MemWrite: aarch.\n");
		memcpy_toio((void *)(V206KG2D008), (void *)V206IOCTLCMD006, size);
	}
#else
	{
		V206DEV005("[cpu-type] mwv206MemWrite: not ft1500a.\n");
		memcpy((void *)(V206KG2D008), V206IOCTLCMD006, size);
	}
#endif

	FUNC206HAL316(pDev, 0);
	return 0;
}


void FUNC206HAL228(V206DEV025 *pDev,
		const unsigned char *V206IOCTLCMD006, unsigned int V206IOCTLCMD009, unsigned int size)
{
	unsigned long V206KG2D026;

	FUNC206HAL316(pDev, 1);
	V206KG2D026 = FUNC206HAL334(pDev, 1, V206IOCTLCMD009);
	V206DEV005("mwv206addr = 0x%x\n", V206IOCTLCMD009);


	{
		V206DEV005("[cpu-type] mwv206MemRead: not ft1500a.\n");
		memcpy((void *)V206IOCTLCMD006, (void *)(V206KG2D026), size);
	}

	FUNC206HAL316(pDev, 0);
}

int FUNC206HAL230(V206DEV025 *pDev,
		unsigned int V206IOCTLCMD009, const unsigned char *V206IOCTLCMD006, unsigned int size)
{
	return FUNC206HAL229(pDev, V206IOCTLCMD009, V206IOCTLCMD006, size);
}

int FUNC206HAL243(unsigned long V206DEV031, unsigned int val)
{
	unsigned int readval;
	GLJ_TICK tick;

	V206DEV005("memcheck;\n");

	FUNC206HAL470(V206DEV031, val);


	readval = FUNC206HAL467(V206DEV031);
	mwv206_timed_loop (tick, readval != val, MWV206CMDTIMEOUT) {
		readval = FUNC206HAL467(V206DEV031);
	}

	if (readval != val) {
		V206KDEBUG002("write 0x%x to 0x%lx gpu-mem timeout, readval = 0x%x.",
				val, V206DEV031, readval);
		return -1;
	}

	V206DEV005("write 0x%x to 0x%lx gpu-mem successfully.", val, V206DEV031);
	return 0;
}

static int FUNC206HAL311(V206DEV025 *pDev)
{
	unsigned int val;
	unsigned long V206DEV083;
	int ret;

	FUNC206HAL316(pDev, 1);
	V206DEV083 = pDev->V206DEV083[0];
	V206DEV083 = FUNC206HAL334(pDev, 1, V206DEV083);
	V206DEV005("check memaddr 0x%lx\n\n\n\n", V206DEV083);

	pDev->V206DEV084 = (pDev->V206DEV084 + 1) % 0x10000;
	val = 0x5a5a0000 + pDev->V206DEV084;


	ret = FUNC206HAL243(V206DEV083, val);

	V206DEV005("check done.\n\n\n");
	FUNC206HAL316(pDev, 0);

	return ret;
}

static int FUNC206HAL313(V206DEV025 *pDev)
{
	unsigned int val;
	unsigned long V206DEV083;
	int ret;

	FUNC206HAL316(pDev, 1);

	V206DEV083 = pDev->V206DEV083[1];
	V206DEV083 = FUNC206HAL334(pDev, 1, V206DEV083);
	V206DEV005("check memaddr 0x%lx\n\n\n\n", V206DEV083);

	pDev->V206DEV084 = (pDev->V206DEV085 + 1) % 0x10000;
	val = 0xa5a50000 + pDev->V206DEV085;


	ret = FUNC206HAL243(V206DEV083, val);

	FUNC206HAL316(pDev, 0);

	if (ret != 0) {
		return ret;
	}
	V206DEV005("check done.\n\n\n");

	return 0;
}

int FUNC206HAL314(V206DEV025 *pDev, unsigned int V206IOCTLCMD009)
{
	if (V206IOCTLCMD009 >= 0x80000000) {
		return FUNC206HAL313(pDev);
	} else {
		return FUNC206HAL311(pDev);
	}
}

int FUNC206HAL370(V206DEV025 *pDev)
{

	FUNC206HAL311(pDev);

	if (pDev->V206DEV041 > 1) {
		FUNC206HAL313(pDev);
	}
	V206DEV005("check done.\n\n\n");

	return 0;
}