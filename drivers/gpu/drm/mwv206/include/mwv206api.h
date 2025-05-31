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
#ifndef _MWV206API_H_
#define _MWV206API_H_
#ifdef __cplusplus
extern "C" {
#endif


int mwv206framerateLimitSet(int dev, int enable);


int mwv206DevSendCommand(int dev, unsigned int *cmd, int cmdcount);


int mwv206DevSendCommandV(int *devArr, int devcnt, unsigned int *cmd, int cmdcount);


int mwv206DevWriteCommandToCPUMem(int dev, unsigned int *cmd, int cmdcount);


int mwv206DevWaitForIdle(int dev, int delay);


int mwv206DevWaitForIdleV(int *devArr, int devcnt, int delay);


void mwv206SetWaitTimes(int times);


unsigned int mwv206DevReadReg(int dev, int V206DEV033);


unsigned int mwv206DevWriteReg(int dev, int V206DEV033, unsigned int value);


unsigned int mwv206DevWriteRegV(int *devArr, int devcnt, int V206DEV033, unsigned int value);




int mwv206MemmapInit(int dev);


void mwv206MemmapExit(void);


unsigned int mwv206DevMemAlloc(int dev, int size, int align);


int mwv206DevMemReference(int dev, unsigned int addr);


unsigned int mwv206Dev2DMemAlloc(int dev, int size, int align);


int mwv206DevMemFree(int dev, unsigned int V206IOCTLCMD009);


int mwv206DevMemRead(int dev, unsigned int V206IOCTLCMD009, unsigned char *pAddr, int size);


int mwv206DevMemReadBlock(int dev, unsigned int V206IOCTLCMD009, int mwv206stride, unsigned char *pAddr, int V206KG2D033,
		int width, int height);


int mwv206DevMemWrite(int dev, unsigned int V206IOCTLCMD009, const unsigned char *pAddr, int size);



int mwv206DevMemWriteV(int *devArr, int devcnt, unsigned int V206IOCTLCMD009,
		const unsigned char *pAddr, int size);


int mwv206DevMemWriteVtx(int dev, unsigned int V206IOCTLCMD009, const unsigned char *pAddr, int size);


int mwv206DevMemWriteVtxV(int *devArr, int devcnt, unsigned int V206IOCTLCMD009,
		const unsigned char *pAddr, int size);


int mwv206DevMemWriteBlock(int dev, unsigned int V206IOCTLCMD009, int mwv206stride, unsigned char *pAddr, int V206KG2D033,
		int width, int height);


int mwv206DevMemWriteBlockV(int *devArr, int devcnt,
		unsigned int V206IOCTLCMD009, int mwv206stride,
		unsigned char *pAddr, int V206KG2D033, int width, int height);


int mwv206DevMemSet(int dev, unsigned int V206IOCTLCMD009, unsigned int value, int vsize, int count);


int mwv206DevMemSetV(int *devArr, int devcnt,
		unsigned int V206IOCTLCMD009, unsigned int value, int vsize, int count);


int mwv206DevMemCopyBlock(int dev,
		unsigned int V206KG2D026, int V206KG2D030,
		unsigned int V206KG2D008, int V206KG2D013,
		int width, int height);


int mwv206DevMemCopy(int dev, unsigned int V206KG2D026, unsigned int V206KG2D008, int size);


void mwv206SetVtxFrameCheckFlag(int flag);


int mwv206DevMemCheck(int dev);


int mwv206DevMemCheckV(int *devArr, int devcnt);


int mwv206Dev2DMemReadDMA(int dev, unsigned int V206IOCTLCMD009,
		unsigned char *V206KG2D008, int size);


int mwv206Dev2DMemWriteDMA(int dev, unsigned int V206IOCTLCMD009,
		const unsigned char *V206KG2D026, int size);


int mwv206Dev3DMemReadDMA(int dev, unsigned int V206IOCTLCMD009,
		unsigned char *V206KG2D008, int size);


int mwv206Dev3DMemWriteDMA(int dev, unsigned int V206IOCTLCMD009,
		const unsigned char *V206KG2D026, int size);


int mwv206Dev2DMemReadBlockDMA(int dev,
		unsigned int V206IOCTLCMD009, int mwv206stride,
		unsigned char *V206KG2D008, int V206KG2D033,
		int width, int height);


int mwv206Dev2DMemWriteBlockDMA(int dev,
		unsigned int V206IOCTLCMD009, int mwv206stride,
		unsigned char *V206KG2D026, int V206KG2D033,
		int width, int height);


int mwv206Dev3DMemReadBlockDMA(int dev,
		unsigned int V206IOCTLCMD009, int mwv206stride, unsigned char *V206KG2D008, int V206KG2D033,
		int width, int height);


int mwv206Dev3DMemWriteBlockDMA(int dev,
		unsigned int V206IOCTLCMD009, int mwv206stride, unsigned char *V206KG2D026, int V206KG2D033,
		int width, int height);







typedef enum {
	V206API001,
	V206API002,
	V206API003,
	V206API004,
	V206API005,
	V206API006,
	V206API007,
	V206API008,
	V206API009,
	V206API010,
	V206API011,
	V206API012,
	V206API013,
	V206API014,
	V206API015,
	V206API016,
	V206API017,
	V206API018,
	V206API019,
	V206API020 = 28,
	V206API021 = 33,
	V206API022 = 38,
	V206API023 = 43,
	V206API024 = 56,
	V206API025 = 57,
	V206API026 = 58,
	V206API027 = 59,
	V206API028 = 68,
	V206API029 = 69,
	V206API030 = 96,
} V206API031;


#define MWV206INTR_GROUP               3


#define MWV206INTR_CMDPORT_2D         (V206API030 + 8)


int mwv206DevEnableIntrSrc(int dev, V206API031 intrsrc, int enable);


int mwv206DevEnableIntrSrcV(int *devArr, int devcnt, V206API031 intrsrc, int enable);


typedef enum {
	MWV206INTR_ROUTE_TO_CPU,
	MWV206INTR_ROUTE_TO_PCIE,
	MWV206INTR_ROUTE_TO_CPU_PCIE,
	MWV206INTR_ROUTE_TO_OUTSIDE,
	MWV206INTR_ROUTE_MAX
} e_mwv206IntrRoute;


typedef enum  {
	V206API032,
	V206API033,
	V206API034,
	V206API035,
	V206API036
} V206API037;


typedef enum {
	V206API038,
	V206API039,
	V206API040,
	V206API041,
	V206API042,
} V206API043;


int mwv206DevSetSendCommandMode(int dev, V206API043 mode);


int mwv206DevSetSendCommandModeV(int *devArr, int devcnt, V206API043 mode);


int mwv206DevSetSendCommandMode2D(int dev,  V206API043 mode);


int mwv206DevSetSendCommandMode2(int dev, V206API043 mode, unsigned int ringbuffersize);


int mwv206DevSetSendCommandMode2V(int *devArr, int devcnt,
		V206API043 mode, unsigned int ringbuffersize);



typedef enum {
	V206API044,
	V206API045,
	V206API046,
} V206API047;


int mwv206DevSetVertexOrder(int dev, V206API047 order);


int mwv206DevSetVertexOrderV(int *devArr, int devcnt, V206API047 order);



typedef enum {
	V206API048,
	V206API049,
	V206API050,
	V206API051,
} V206API052;


int mwv206DevSetVertexLocation(int dev, V206API052 location);


int mwv206DevSetVertexLocationV(int *devArr, int devcnt, V206API052 location);


void mwv206EnableVariedMaterial(void);


void mwv206DisableVariedMaterial(void);


void mwv206SetPolygonOffsetRVal(float rval);


int mwv206MemmapExit2(int dev);


int mwv206DevDisableShader(int dev);


typedef enum {
	V206API053,
	V206API054,
	V206API055,
	V206API056,
	V206API057,
	MWV206PARAM_REFCLOCKFREQ,
	V206API059,
	V206API060,
	V206API061,
	V206API062,
	V206API063,
	V206API064,
	V206API065,
	V206API066,
	V206API067,
	V206API068,
	V206API069,
	V206API070,
	V206API071,
	V206API072,
	V206API073,
	V206API074,
	V206API075,
	V206API076,
	V206API077,
	V206API078,
} V206API079;



unsigned int mwv206DevGetDevParam(int dev, V206API079 paramid);


unsigned int mwv206DevGetResMemSize(int dev);


unsigned int mwv206DevGetRefClock(int dev);


int mwv206DevSoftwareReset3D(int dev);


int mwv206DevSaveOwner3D(int dev);


typedef enum {
	V206API080,
	V206API081,
	V206API082,
	V206API083,
	V206API084,
	V206API085,
	V206API086,
	V206API087,
	V206API088,
	V206API089,
	V206API090,
	V206API091,
	V206API092,
	V206API093,
	V206API094,
	V206API095,
	V206API096,
	V206API097,
	V206API098,
	V206API099,
	V206API100,
	V206API101,
	V206API102,
	V206API103,
	V206API104,
	V206API105,
	V206API106,
	V206API107,
	V206API108,
	V206API109,
	V206API110,
	V206API111,
	V206API112,
	V206API113,
	V206API114,
	V206API115,
} V206API116;


int mwv206DevSetClock(int dev, V206API116 module, int on);


int mwv206DevCloseStartupScreen(int dev);


int mwv206DevSetZBufClearOpt(int dev, int enable, float zInitVal);


int mwv206DevDecMemRead(int dev, unsigned int V206IOCTLCMD009, unsigned char *pAddr, int size);


int mwv206DevDecMemWrite(int dev, unsigned int V206IOCTLCMD009, unsigned char *pAddr, int size);


int FUNC206LXDEV137(void);


const char *getTimeStampStr(void);


unsigned int mwv206DevGetAXIAddr(unsigned int V206IOCTLCMD009);


int mwv206DevGetIndex(int fd, int bus, int dev, int func);

int mwv206DevKContextCreate(int dev, void **userctx);
int mwv206DevKContextDestroy(int dev, void *userctx);
int mwv206DevKContextCheckMatch(int dev, void *userctx);
int mwv206DevKContextMakeCurrent(int dev, void *userctx);

#define V206API117 (1)
#define V206API118           (2)
#define V206API119          (4)
#define V206API120          (8)
#define V206API121          (0x10)
#define V206API122          (0x20)
#define V206API123          (0x40)
#define V206API124       (0x80)
#define V206API125       (0x100)


typedef struct mwv206_GPUInfo_s {
	char vender[64];
	char venderId[64];
	char deviceId[64];
	char technology[64];
	char busType[64];
	char firmwareVersion[64];
	char memType[64];
	int mainFreq;
	int pixelFillRate;
	int textureFillRate;
	int memSize;
	int memFreq;
	int memRemainSize;
	float temperature;
	float gpuUseRate2d;
	float gpuUseRate3d;
} mwv206_GPUInfo_t;


int mwv206GPUInfoGet(int dev, mwv206_GPUInfo_t *gpuinfo);



int jmgpuTempFreqSet(int *pConf, int groups);


typedef enum {
	V206API126,
	V206API127,
	V206API128,
	V206API129,
	V206API130,
	V206API131
} V206API132;


int mwv206ModeSet(int dev, V206API132 mode);



int mwv206SaveAddrToFile(int dev, int V206IOCTLCMD009, int format,
		int width, int height, const char *filename);


#ifdef _VXWORKS_

int FUNC206HAL148(int V206DEV072, int corefreq, int memfreq,
		int V206DEV038, int V206DEV039, int subenable);


int jmgpuInitEx(int corefreq, int memfreq, int subenable);

#endif

#ifdef __cplusplus
}
#endif

#endif