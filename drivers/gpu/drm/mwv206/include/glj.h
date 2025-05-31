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
#ifndef __GLJ_H
#define __GLJ_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _ASMLANGUAGE


typedef void *V206GLJ001;

typedef void *V206GLJ002;


typedef enum display_mode {
	V206GLJ003 = -1,
	V206GLJ004 = 0,
	V206GLJ005,
	V206GLJ006,
	V206GLJ007,
	V206GLJ008,
	V206GLJ009,
	V206GLJ010,
	V206GLJ011,
	V206GLJ012,
	V206GLJ013,
	V206GLJ014,
	V206GLJ015,
	V206GLJ016,
	V206GLJ017,
	V206GLJ018,
	V206GLJ019,
	V206GLJ020,
	V206GLJ021,
	V206GLJ022,
	V206GLJ023,
	V206GLJ024,
	V206GLJ025,
	V206GLJ026,
	V206GLJ027,
	V206GLJ028,
	V206GLJ029
} e_displayMode;


typedef enum pixel_mode {
	V206GLJ030 = 0,
	V206GLJ031
} e_pixelMode;


typedef enum output_port {
	V206GLJ032 = 0,
	V206GLJ033,
	V206GLJ034,
	V206GLJ035,
	V206GLJ036,
	V206GLJ037,
	V206GLJ038,
	V206GLJ039,
	V206GLJ040,
	V206GLJ041,
	V206GLJ042,
} e_outputPort;


typedef enum output_port_param {
	DP_LVDS_MODE = 0,
} e_outputPortparam;

typedef enum lvds_mode_param {
	V206GLJ043,
	V206GLJ044,
	V206GLJ045,
	V206GLJ046,
} e_lvds_mode_param;


int gljSetDisplayMode(int dev, int V206FB011, int V206DEV079, enum display_mode mode);


typedef enum pol_param {
	V206DISPMODE015 = 0,
	V206DISPMODE016 = 1,
} e_pol;


int gljSetUserDisplayMode(int dev, int V206FB011, int V206DEV079,
		int htotal, int hactive, int hfrontporch, int hsync, int hpol,
		int vtotal, int vactive, int vfrontporch, int vsync, int vpol,
		int framerate);

int gljSetDisplayPort(int dev, e_outputPort port, int V206FB011, int enable);


int gljSetDisplayPortEx(int dev, e_outputPort port, int dualpixel, int V206FB011, int enable);


int gljSetDisplayPortParam(int dev, e_outputPort port, e_outputPortparam paramtype, int paramvalue);


typedef enum syscursorid {
	V206GLJ047 = 0,
	V206GLJ048,
	V206GLJ049,
	V206GLJ050,
	V206GLJ051,
	V206GLJ052,
	V206GLJ053,
	V206GLJ054,
	V206GLJ055,
	V206GLJ056,
	V206GLJ057,
	V206GLJ058,
	V206GLJ059
} e_sysCursorid;


int gljCursorEnable(int dev, int V206FB011, int enable);


int gljCursorSetPos(int dev, int V206FB011, int x, int y);


int gljCursorSetAlpha(int dev, int V206FB011, int alpha);



int gljCursorGetSize(int dev);


int gljCursorSetShape(int dev, int V206FB011, int hotx, int hoty, unsigned int *shapedata);


int gljCursorSetSysShape(int dev, int V206FB011, int syscursor);


int gljFrameBufferCreate(int dev, int width, int height, int format, int dualbuf, V206GLJ001 *pFrameBuffer);


int gljFrameBufferCreate2(int *devArr, int devcnt,
		int width, int height, int format, int dualbuf, V206GLJ001 *pFrameBuffer);


int gljFrameBufferCreateWithAccum(int dev, int width, int height, int format, int dualbuf, V206GLJ001 *pFrameBuffer);


int gljFrameBufferCreate2WithAccum(int *devArr, int devcnt,
		int width, int height, int format, int dualbuf, V206GLJ001 *pFrameBuffer);


int gljFrameBufferDestroy(V206GLJ001 framebuffer);


int gljFrameBufferConnectToScreen(int dev, V206GLJ001 framebuffer, int V206FB011, int x, int y, int w, int h);


int gljFrameBufferCopy(int dev, V206GLJ001 dst, int dx, int dy, V206GLJ001 src, int sx, int sy, int w, int h);


int gljFrameBufferCopy2(int dev, V206GLJ001 fb,
		int dstsurfaceid, int dx, int dy,
		int srcsurfaceid, int sx, int sy,
		int w, int h, float zoomx, float zoomy);

typedef enum blendMode2D {
	V206GLJ060      = 0,
	V206GLJ061      = 0x01,
	V206GLJ062      = 0x02,
	V206GLJ063   = 0x03,
	V206GLJ064      = 0x04,
	V206GLJ065 = 0x05
} e_blendMode2D;

typedef enum blendFactor2D {
	V206GLJ066           = 0,
	V206GLJ067            = 0x01,
	V206GLJ068    = 0x02,
	V206GLJ069 = 0x03,
	V206GLJ070    = 0x04,
	V206GLJ071 = 0x05,
	V206GLJ072      = 0x06,
	V206GLJ073   = 0x07,
	V206GLJ074   = 0x08,
	V206GLJ075      = 0x09,
	V206GLJ076 = 0x0A,
	V206GLJ077    = 0x0D,
	V206GLJ078 = 0x0E,
	V206GLJ079
} e_blendFactor2D;

typedef struct tagFRAMEBUFFER_BLEND_INFO {
	e_blendMode2D        blendMode ;
	e_blendFactor2D      dfactor   ;
	e_blendFactor2D      sfactor   ;
	int                  alpha     ;
	V206GLJ001        dst       ;
	int                  dx        ;
	int                  dy        ;
	int                  V206KG2D015        ;
	int                  V206KG2D007        ;
	V206GLJ001        src       ;
	int                  sx        ;
	int                  sy        ;
	int                  V206KG2D034        ;
	int                  V206KG2D025        ;
} FRAMEBUFFER_BLEND_INFO;


int gljFrameBufferBlend(int dev, FRAMEBUFFER_BLEND_INFO *pBlendInfo);


int gljContextCreate(int dev, V206GLJ002 *pContext);


int gljShareContextCreate(int dev, V206GLJ002 *pContext, V206GLJ002 *shareContext);


int gljContextCreate2(int *devArr, int devcnt, V206GLJ002 *pContext);


int gljShareContextCreate2(int *devArr, int devcnt, V206GLJ002 *pContext, V206GLJ002 *shareContext);


int gljContextDestroy(V206GLJ002 context);


int gljMakeCurrent(V206GLJ002 context, V206GLJ001 framebuffer);


V206GLJ002 gljGetCurrentContext(void);



V206GLJ001 gljGetCurrentFrameBuffer(void);

int gljGetCurrentDev(void);


int gljSwapBuffer(void);


int gljBindFrameBufferToTexture(V206GLJ001 framebuffer, unsigned int *texid);




unsigned int jmDevReadReg(int dev, int V206DEV033);


unsigned int jmDevWriteReg(int dev, int V206DEV033, unsigned int value);


unsigned int jmDevMemAlloc(int dev, int size, int align);


int jmDevMemFree(int dev, unsigned int jmaddr);


int jmDevSendCommand(int dev, unsigned int *cmd, int cmdcount);


int jmDevMemRead(int dev, unsigned int jmaddr, unsigned char *pAddr, int size);


int jmDevMemReadBlock(int dev, unsigned int jmaddr, int jmstride,
		unsigned char *pAddr, int V206KG2D033, int width, int height);

int jmDevMemWrite(int dev, unsigned int jmaddr, unsigned char *pAddr, int size);


int jmDevMemWriteBlock(int dev, unsigned int jmaddr, int jmstride,
		unsigned char *pAddr, int V206KG2D033, int width, int height);

int jmDevMemSet(int dev, unsigned int jmaddr, unsigned int value, int vsize, int count);


int jmEnableIntrSrc(int dev, int intrsrc, int enable);


int gljSaveToFile(const char *filename);


void gljReadColorBufferDMA(void *pixels);


#define GLJ_DRAWARRAY_ATRRIB_HINT 0x0C55

#ifdef _VX7_
#define JMGPU_MAX_BAR_NO    (6)


int jmgpupciAddrSet(int *bar[JMGPU_MAX_BAR_NO]);
#endif

#endif

#ifdef __cplusplus
}
#endif

#endif