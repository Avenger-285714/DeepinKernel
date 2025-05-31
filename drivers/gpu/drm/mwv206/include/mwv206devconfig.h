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
#ifndef _MWV206_DEV_CONFIG_H_
#define  _MWV206_DEV_CONFIG_H_

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
#endif

#include "../include/mwv206config.h"
#include "../include/glj.h"

#ifdef __cplusplus
extern "C" {
#endif


#define V206DEVCONFIG001(flag, bitpos, bit)           ((flag) = ((flag) & ~(1<<(bitpos))) | (((bit)&0x1)<<(bitpos)))
#define V206DEVCONFIG002(flag, bitpos)                (((flag) >> (bitpos))&0x1)
#define V206DEVCONFIG003(flag, bitmask, shift, dat)  ((flag) = ((flag) & (bitmask))|(((dat)<<(shift))&~(bitmask)))
#define V206DEVCONFIG004(flag, bitmask, shift)       (((flag)&~(bitmask))>>(shift))

typedef struct {

	uint32_t memfreq;
	uint32_t corefreq;
	uint32_t V206DEV038;
	uint32_t V206DEV039;

	uint32_t subenable;

	uint8_t  pcictrl;
	uint8_t  pcilane;
	uint8_t  pcibar;
	uint8_t  pcirom;
	uint32_t V206DEV072;
	uint8_t  memconf;
	uint8_t  blctrl;
	uint8_t  warningtemp;
	uint8_t  warninggpio;
} MWV206ChipConfig;

typedef struct {

	uint8_t    mode;
#define CFG_FB_MODE_USER            (0xff)


	uint8_t    V206DEV079;
	uint8_t    rfsrate;
	uint8_t    resv;
	uint32_t   htotal;
	uint32_t   hactive;
	uint32_t   hfrontporch;
	uint32_t   hsync;
	uint32_t   hpol;
	uint32_t   vtotal;
	uint32_t   vactive;
	uint32_t   vfrontporch;
	uint32_t   vsync;
	uint32_t   vpol;
} MWV206FbConfig;

typedef struct {

	uint8_t flags;
#define V206DEVCONFIG005               (7)
#define V206DEVCONFIG006            (6)
#define V206DEVCONFIG007            (5)
#define V206DEVCONFIG008                 (4)
#define V206DEVCONFIG009            (0xf3)
#define V206DEVCONFIG010           (0x02)
#define V206DEVCONFIG011            (0x00)
#define V206DEVCONFIG012             (0x01)
#define V206DEVCONFIG013            (0x02)
#define V206DEVCONFIG014              (0x03)
#define V206DEVCONFIG015           (1)


	uint8_t i2cchan;
	uint8_t sameas;
	uint8_t bitmode;
	uint8_t stdedid;
#define V206DEVCONFIG016                 (0xff)
#define V206DEVCONFIG017              (0xff)
#define V206DEVCONFIG018               (0xff)
#define V206DEVCONFIG019               (0xff)
#define V206DEVCONFIG020              (0x7f)

#define CFG_PORT_ISDVI_BIT               (7)

	uint8_t mainScreen;
	uint8_t resv0;
	uint8_t resv1;
#define EDID_ITEM_LEN                    (256)
	uint8_t edid[EDID_ITEM_LEN];

} MWV206PortConfig;

#define V206DEVCONFIG021            (0)
#define V206DEVCONFIG022            (1)
#define V206DEVCONFIG023            (2)
#define V206DEVCONFIG024            (3)
#define V206DEVCONFIG025             (4)
#define V206DEVCONFIG026             (5)
#define V206DEVCONFIG027            (6)
#define V206DEVCONFIG028            (7)
#define V206DEVCONFIG029             (8)
#define V206DEVCONFIG030             (9)


#define V206DEVCONFIG031(flags, enable)          V206DEVCONFIG001(flags, V206DEVCONFIG005, !!(enable))
#define V206DEVCONFIG032(flags, dualpixel)    V206DEVCONFIG001(flags, V206DEVCONFIG006, !!(dualpixel))
#define V206DEVCONFIG033(flags, pixelchan)    V206DEVCONFIG001(flags, V206DEVCONFIG007, !!(pixelchan))
#define V206DEVCONFIG034(flags, enable)            V206DEVCONFIG001(flags, V206DEVCONFIG008, !!(enable))
#define V206DEVCONFIG035(flags, enable)            V206DEVCONFIG001(flags, V206DEVCONFIG015, !!(enable))

#define V206DEVCONFIG036(flags)                  V206DEVCONFIG002(flags, V206DEVCONFIG005)
#define V206DEVCONFIG037(flags)               V206DEVCONFIG002(flags, V206DEVCONFIG006)
#define V206DEVCONFIG038(flags)               V206DEVCONFIG002(flags, V206DEVCONFIG007)
#define V206DEVCONFIG039(flags)                    V206DEVCONFIG002(flags, V206DEVCONFIG008)
#define V206DEVCONFIG040(flags)                    V206DEVCONFIG002(flags, V206DEVCONFIG015)


#define V206DEVCONFIG041(flags, mode)          V206DEVCONFIG003(flags, V206DEVCONFIG009, V206DEVCONFIG010, mode)
#define V206DEVCONFIG042(flags)                V206DEVCONFIG004(flags, V206DEVCONFIG009, V206DEVCONFIG010)


#define V206DEVCONFIG043(flags, enable)            V206DEVCONFIG001(flags, CFG_PORT_ISDVI_BIT, !!(enable))
#define V206DEVCONFIG044(flags)                    V206DEVCONFIG002(flags, CFG_PORT_ISDVI_BIT)


typedef struct {
	MWV206ChipConfig chip;
	MWV206FbConfig   fb;
	MWV206PortConfig hdmi[4];
	MWV206PortConfig vga[2];
	MWV206PortConfig lvds[2];
	MWV206PortConfig dvo[2];
} MWV206DevConfig;

typedef struct {
	uint8_t bl_maxlevel;
	uint8_t bl_maxdutyratio;
	uint8_t bl_mindutyratio;
	uint8_t bl_pwmgpio;
	char usrinfo[200];
} MWV206BoardConfig;

typedef struct {
	MWV206DevConfig V206DEV105;
	MWV206BoardConfig board;
} MWV206DevCfgAll;

#define MWV206DEV_CONFIG_SIZE   (sizeof(MWV206DevConfig))
#define MWV206DEV_CONFIG_MAXCFG (8)

#ifndef NULL
#define NULL (0)
#endif

typedef enum {
	V206DEVCONFIG045 = 0,
	V206DEVCONFIG046,
	V206DEVCONFIG047,
	V206DEVCONFIG048,
	V206DEVCONFIG049,
	V206DEVCONFIG050,
} e_MWV206KeyType;

typedef struct tagKEYVALUEITEM {
	const char *secName;
	const char *keyName;
	int valuetype;
	char *value;
} sKEYVALUEITEM;
#define STATE_NA            (0)
#define STATE_SECTION       (1)
#define STATE_KEY           (2)
#define STATE_VALUE         (3)



typedef int32_t (*FileReader_t)(int32_t offset, void *buf, uint32_t len);


int32_t FUNC206HAL108(int32_t offset, void *buf, uint32_t len);


int32_t FUNC206HAL113(int32_t offset, void *buf, uint32_t len);


int32_t FUNC206HAL111(int32_t offset, void *buf, uint32_t len);


int32_t  FUNC206HAL112(void   *handle);


int FUNC206HAL110(void *dev, FileReader_t fileReader, int bdefaultReader);


int FUNC206HAL146(void *V206DEV103);


int FUNC206HAL145(void *V206DEV103);



MWV206DevConfig *FUNC206HAL109(void *dev);



uint32_t FUNC206HAL107(void *buf, uint32_t len);




int jmgpuCfgGet(int dev, MWV206DevConfig *pcfg);

/*
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


static const char *jmgpuCfgGetPortName(int type)
{
	switch (type) {
	case V206CONFIG011:  return "VGA";
	case V206CONFIG013: return "HDMI";
	case V206CONFIG014: return "LVDS";
	case V206CONFIG012:  return "DVO";
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
*/

#ifdef __cplusplus
}
#endif

#endif