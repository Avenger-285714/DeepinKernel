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
#ifndef _MWV206IOCTL_H_
#define _MWV206IOCTL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "../include/mwv206_internal.h"
#include "../include/mwv206api.h"
#include "../include/mwv206config.h"

#define MWV206PACKED __attribute__((packed))

typedef unsigned int jjuint32;
typedef int jjint32;

#ifdef __KERNEL_BITWIDTH_DIFFFROM_USER__
typedef unsigned long long jjuintptr;
#else
typedef unsigned long jjuintptr;
#endif

#define MWV206_DEFAULT_RINGBUFFER_SIZE (4)

#define V206IOCTL001                0
#define V206IOCTL002                 1
#define V206IOCTL003        2
#define V206IOCTL004           3

typedef struct V206IOCTL130 {
	int reg;
	int action;
	unsigned int setvalue;
	unsigned int getvalue;
	unsigned int setmask;
} V206IOCTL167;

enum V206IOCTL109 {
	V206IOCTL005 = 0,
	V206IOCTL006,
	V206IOCTL007,
	V206IOCTL008,
	V206IOCTL009,
	V206IOCTL010,
	V206IOCTL011,
	V206IOCTL012,
	V206IOCTL013,
	V206IOCTL014,
	V206IOCTL015
};

typedef struct V206IOCTL124 {
	int V206FB011;
	int mode;

	int htotal, hactive, hfrontporch, hsync, hpol;
	int vtotal, vactive, vfrontporch, vsync, vpol;
	int framerate;
	int V206DEV079;
} V206IOCTL161;

typedef struct V206IOCTL131 {
	int V206FB011;
	int V206HDMIAUDIO027;
	int mode;
	int htotal, hactive, hfrontporch, hsync, hpol;
	int vtotal, vactive, vfrontporch, vsync, vpol;
	int framerate;
	int dualpixel;
	int isdvi;
} V206IOCTL168;

typedef struct V206IOCTL137 {
	int  V206FB008;
	int  dualpixel;
	int  V206FB011;
	int  enable;
} V206IOCTL172;

typedef struct V206IOCTL138 {
	int V206FB008;
	int type;
	int value;
} V206IOCTL173;

#define V206IOCTL016    1
#define V206IOCTL017     2
#define V206IOCTL018       4
#define V206IOCTL019     8

typedef struct V206IOCTL123 {
	int options;
	int V206FB011;
	int enable;
	int alpha;
	int x, y;
	int hotx, hoty;
	unsigned int shape;
	unsigned int shapeHi;
} V206IOCTL160;

typedef struct V206IOCTL125 {
	int V206FB011;
	int paletteid;
	unsigned char palette[768];
} V206IOCTL162;

typedef struct V206IOCTL122 {
	int V206FB011;
	unsigned int addr;
	int           format;
	int           V206KG2D033;
	int           width;
	int           height;
	int           vsync;
} V206IOCTL159;

typedef int (*MWV206INTRFUNC)(int intrsrc, void *pDev);

typedef struct V206IOCTL129 {
	unsigned int param;
	unsigned int retval;
} V206IOCTL166;

typedef struct V206IOCTL132 {
	int             dev;
	unsigned int    param;
	int             intrsrc;
	int             inttype;
	MWV206INTRFUNC  V206DEV070;
} V206IOCTL169;

#define MWV206MEM_ALLOC     0
#define MWV206MEM_REFERENCE 1
typedef struct V206IOCTL135 {
	jjuint32 addr;
	int alignment;
	int size;
	int op;
} V206IOCTL170;

typedef struct V206IOCTL136 {
	jjuint32 addr;
} V206IOCTL171;

typedef struct V206IOCTL127 {
	unsigned long long vaddr;
	unsigned long long dma_handle;
	int size;
} V206IOCTL164;

#define V206IOCTL020            0
#define V206IOCTL021           1
#define V206IOCTL022             2
#define V206IOCTL023          3
#define V206IOCTL024         4

typedef struct V206IOCTL134 {
	jjuintptr V206DEV031;
	jjuint32  V206IOCTLCMD009;

	int vsize;
	int size;
	int memstride;
	int mwv206stride;
	unsigned int value;
	int op;
} MWV206PACKED V206IOCTL146;

typedef struct V206IOCTL126 {
	unsigned int V206DEV031;
	unsigned int memaddrHi;
	jjuint32     V206IOCTLCMD009;
	int chan;

	int vsize;
	int size;
	int memstride;
	int mwv206stride;
	int op;
} V206IOCTL163;

#define SYNC_WAITFORIDLE  0
#define SYNC_FLUSH        1
typedef struct V206IOCTL141 {
	int op;
	int timeout;
} V206IOCTL177;

enum {
	V206IOCTL025,
	V206IOCTL026,
	V206IOCTL027,
	V206IOCTL028,
};

typedef struct V206IOCTL133 {
	jjuintptr userctx;
	unsigned int op;
} MWV206PACKED V206IOCTL145 ;

typedef struct V206IOCTL140 {
	char str[MWV206_MAXVERSTRLEN];
} V206IOCTL176;

typedef struct V206IOCTL128 {
	jjuint32 addr;
	int V206KG2D033;
	int V206KG2D001;
	int x, y;
	int width, height;
	unsigned int color, mask;
	int rrop;
} V206IOCTL165;

typedef struct V206IOCTL120 {
	jjuint32 V206KG2D023, V206KG2D004;
	int V206KG2D032, V206KG2D011;
	int V206KG2D001;
	int sx, sy;
	int dx, dy;
	int width, height;
	unsigned int mask, rrop;
} V206IOCTL157;

typedef struct V206IOCTL139 {
	jjuint32 V206KG2D026;
	unsigned int V206KG2D030;
	unsigned int V206KG2D036;
	unsigned int V206KG2D038;
	unsigned int V206KG2D031;
	unsigned int V206KG2D028;
	jjuint32 V206KG2D008;
	unsigned int V206KG2D013;
	unsigned int V206KG2D035;
	unsigned int V206KG2D037;
	unsigned int V206KG2D014;
	unsigned int V206KG2D010;
} V206IOCTL174;


typedef struct V206IOCTL121 {
	int buffen;
	jjuint32 buffaddr, V206KG2D023, V206KG2D004;
	int buffstride, V206KG2D032, V206KG2D011;
	int sfmt, dfmt;
	int V206KG2D024, V206KG2D005;
	int sfactor, dfactor;
	int sx, sy;
	int dx, dy;
	int width, height;
} V206IOCTL158;


typedef struct V206IOCTL142 {
	int buffen;
	jjuint32 buffaddr, V206KG2D023, V206KG2D004;
	int buffstride, V206KG2D032, V206KG2D011;
	int mode;
	int sfmt, dfmt;
	int V206KG2D024, V206KG2D005;
	int sfactor, dfactor;
	int globalalpha;
	int sx, sy;
	int dx, dy;
	int V206KG2D034, V206KG2D025;
	int V206KG2D015, V206KG2D007;
} V206IOCTL178;

enum {
	V206IOCTL029 = 2,
	V206IOCTL030,
	V206IOCTL031,
};

enum {
	V206IOCTL032,
	V206IOCTL033,
};


#define V206IOCTL034       0
#define V206IOCTL035       1
#define V206IOCTL036      2
#define V206IOCTL037  3
#define V206IOCTL038  4
#define V206IOCTL039 5
#define V206IOCTL040 6
typedef struct V206IOCTL113 {
	void         *mpData;
	int           op;
	int           mOpResult;
	unsigned char mSlaveAddr;
	unsigned char mDestAddr;
	unsigned char mDirect;
	unsigned char mTRLen;
	unsigned char mIsSetStartBit;
	unsigned char mIsSetStopBit;
} V206IOCTL143, *V206IOCTL144;


typedef struct V206IOCTL117 {
	int             spi;
	unsigned int    slave;
	char           *cmdContent;
	unsigned int    cmdLength;
	char           *pTxBuffer;
	unsigned int   *pSendLen;
	char           *pRxBuffer;
	unsigned int   *pRecvLen;
	unsigned int    startRcv;
	unsigned int    transBytes;
	int             sclkPhase;
	int             sclkPolarity;
	int             lsbFirst;
	int             recvSampMode;
} V206IOCTL151, *V206IOCTL152;

typedef struct V206IOCTL119 {
	int             spi;
	char           *cmdContent;
	unsigned int    cmdLength;
	char           *pTxBuffer;
	unsigned int   *pSendLen;
	char           *pRxBuffer;
	unsigned int   *pRecvLen;
	unsigned int    startRcv;
	unsigned int    transBytes;
} V206IOCTL155, *V206IOCTL156;

typedef struct V206IOCTL118 {
	int             spi;
	unsigned int    slave;
	int             sclkPhase;
	int             sclkPolarity;
	int             lsbFirst;
	int             recvSampMode;
} V206IOCTL153, *V206IOCTL154;

typedef struct V206IOCTL115 {
	int           spi;
	unsigned int  freq;
	unsigned int *freq_out;
} V206IOCTL149, *V206IOCTL150;

#define V206IOCTL041    0
#define V206IOCTL042    1
#define V206IOCTL043    2
#define V206IOCTL044     3
#define V206IOCTL045  4
typedef struct V206IOCTL116 {
	union _tag_u {
		V206IOCTL151           trans;
		V206IOCTL155        trans_ex;
		V206IOCTL153   trans_context;
		V206IOCTL149       commufreq;
	} u;
	int op;
} V206IOCTL175;

typedef struct V206IOCTL114 {
	int         mUserPid;
	int         mIrq;
	int         mIndex;
	int         mReserved;
} V206IOCTL147, *V206IOCTL148;

typedef struct V206IOCTL112 {
	int plltype;
	int configfreq;
	int enable;
} V206IOCTL180, *V206IOCTL181;

typedef struct V206IOCTL111 {
	int plltype;
	int freq;
	int maxfreq;
	int minfreq;
} V206IOCTL179;

typedef struct V206IOCTL110 {
	unsigned char edid[8][V206CONFIG010];
	int connect_status[8];
	int changed[8];
	int isfake;
} EDID;

typedef enum {
	V206IOCTL046 = 4,
	V206IOCTL047,
	V206IOCTL048,
	V206IOCTL049,
	V206IOCTL050,
	V206IOCTL051,
	V206IOCTL052,
	V206IOCTL053,
	V206IOCTL054,
	V206IOCTL055,
	V206IOCTL056,
	V206IOCTL057,
	V206IOCTL058,
	V206IOCTL059,
	V206IOCTL060,
	V206IOCTL061,
} V206IOCTL062;

#include <linux/ioctl.h>

#define MWV206_IOC_MAGIC    'j'
#define V206IOCTL063           _IO(MWV206_IOC_MAGIC, 1)
#define V206IOCTL064             _IOWR(MWV206_IOC_MAGIC, 2, V206IOCTL170)
#define V206IOCTL065            _IOW(MWV206_IOC_MAGIC, 3, V206IOCTL146)
#define V206IOCTL066              _IOWR(MWV206_IOC_MAGIC, 4, V206IOCTL171)
#define V206IOCTL067         _IOW(MWV206_IOC_MAGIC, 5, V206IOCTL163)
#define V206IOCTL068    _IOW(MWV206_IOC_MAGIC, 6, V206IOCTL163)
#define V206IOCTL069             _IO(MWV206_IOC_MAGIC, 7)
#define V206IOCTL070            _IOWR(MWV206_IOC_MAGIC, 8, V206IOCTL167)
#define V206IOCTL071             _IOWR(MWV206_IOC_MAGIC, 9, V206IOCTL166)
#define V206IOCTL072           _IO(MWV206_IOC_MAGIC, 10)
#define V206IOCTL073         _IO(MWV206_IOC_MAGIC, 11)
#define V206IOCTL074           _IOW(MWV206_IOC_MAGIC, 12, V206IOCTL165)
#define V206IOCTL075              _IOW(MWV206_IOC_MAGIC, 13, V206IOCTL158)
#define V206IOCTL076           _IOW(MWV206_IOC_MAGIC, 14, V206IOCTL157)
#define V206IOCTL077          _IOW(MWV206_IOC_MAGIC, 15, V206IOCTL178)
#define V206IOCTL078             _IOW(MWV206_IOC_MAGIC, 16, V206IOCTL174)
#define V206IOCTL079       _IOW(MWV206_IOC_MAGIC, 17, V206IOCTL177)
#define V206IOCTL080          _IOW(MWV206_IOC_MAGIC, 18, V206IOCTL177)
#define V206IOCTL081          _IOWR(MWV206_IOC_MAGIC, 19, V206IOCTL145)
#define V206IOCTL082         _IO(MWV206_IOC_MAGIC, 20)
#define V206IOCTL083       _IO(MWV206_IOC_MAGIC, 21)
#define V206IOCTL084       _IO(MWV206_IOC_MAGIC, 22)
#define V206IOCTL085    _IO(MWV206_IOC_MAGIC, 23)
#define V206IOCTL086           _IO(MWV206_IOC_MAGIC, 24)
#define V206IOCTL087          _IOW(MWV206_IOC_MAGIC, 25, V206IOCTL168)
#define V206IOCTL088       _IOW(MWV206_IOC_MAGIC, 26, V206IOCTL159)
#define V206IOCTL089       _IOW(MWV206_IOC_MAGIC, 27, V206IOCTL161)
#define V206IOCTL090       _IOW(MWV206_IOC_MAGIC, 28, V206IOCTL172)
#define V206IOCTL091     _IOW(MWV206_IOC_MAGIC, 29, V206IOCTL160)
#define V206IOCTL092    _IOW(MWV206_IOC_MAGIC, 30, V206IOCTL162)
#define V206IOCTL093  _IOW(MWV206_IOC_MAGIC, 31, V206IOCTL173)
#define V206IOCTL094        _IO(MWV206_IOC_MAGIC, 32)
#define V206IOCTL095    _IO(MWV206_IOC_MAGIC, 33)
#define V206IOCTL096          _IOWR(MWV206_IOC_MAGIC, 34, int)
#define V206IOCTL097         _IOWR(MWV206_IOC_MAGIC, 35, V206IOCTL180)
#define V206IOCTL098          _IOWR(MWV206_IOC_MAGIC, 36, V206IOCTL179)
#define V206IOCTL099         _IO(MWV206_IOC_MAGIC, 37)
#define V206IOCTL100              _IO(MWV206_IOC_MAGIC, 38)
#define V206IOCTL101               _IO(MWV206_IOC_MAGIC, 39)
#define V206IOCTL102              _IO(MWV206_IOC_MAGIC, 40)
#define V206IOCTL103    _IO(MWV206_IOC_MAGIC, 41)
#define V206IOCTL104    _IO(MWV206_IOC_MAGIC, 42)
#define V206IOCTL105             _IO(MWV206_IOC_MAGIC, 43)
#define V206IOCTL106                  _IOWR(MWV206_IOC_MAGIC, 44, V206IOCTL143)
#define V206IOCTL107                  _IOWR(MWV206_IOC_MAGIC, 45, V206IOCTL175)
#define V206IOCTL108  45

#ifdef __cplusplus
}
#endif

#endif