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
#ifndef _JMGPU_OVERLAY_H_
#define _JMGPU_OVERLAY_H_


typedef struct _tag_video_display_timing {
	unsigned short      mHBlankBegin;
	unsigned short      mHBlankEnd;
	unsigned short      mHSBegin;
	unsigned short      mHSEnd;
	unsigned short      mHTotal;
	unsigned short      mVBlankBegin;
	unsigned short      mVBlankEnd;
	unsigned short      mVSBegin;
	unsigned short      mVSEnd;
	unsigned short      mVTotal;

	unsigned short      mVBlankBegin2;
	unsigned short      mVBlankEnd2;

	unsigned short      mVSBegin2;
	unsigned short      mVSEnd2;

	unsigned short      mHalf;
	unsigned short      mTopfieldBegin;
} VIDEODISP_TIMING_PARAM, *P_VIDEODISP_TIMING_PARAM;



#define MAX_VIDEO_SOURCE_NUMBER         4


#define MAX_VIDEO_WINDOWS_NUMBER        4


#define MAX_VIDEO_SCREEN_NUMBER         4



typedef void (*OVERLAY_IRQ_CALLBACK)(int index, void *param);


typedef void *JMOVERLAY;


#ifdef __cplusplus
extern "C" {
#endif


int jmgpuoverlayCreate(int dev,
		JMOVERLAY * pOverlayHandle,
		OVERLAY_IRQ_CALLBACK lumArarmCallback,
		void *lumAlarmParam,
		OVERLAY_IRQ_CALLBACK sourceInvalidCallback,
		void *sourceInvalidparam);


int jmgpuoverlayClkReverse(int dev, int inputClk, int outputClk);


int jmgpuvideoSourceDetectWithDE(int dev,
		int video,
		int *pWidth,
		int *pHeight);


int jmgpuvideoSourcePreDetect(int dev,
		int video,
		int *pWidth,
		int *pHeight,
		int *pFreq);


int jmgpuvideoSourceDetectNoDE(int dev,
		int video,
		int *pWidth,
		int *pHeight,
		int *pFreq);


int jmgpuvideoDetectVGAPos(int dev,
		int video,
		int width,
		int height,
		int freq,
		int isDoublePixel,
		int *pHSWidth,
		int *pVSWidth,
		int *pHBegin,
		int *pHEnd,
		int *pVBegin,
		int *pVEnd);


int jmgpuvideoSetSourceTimeRecoveryMode(int dev,
		int video,
		int restoreMode);


int jmgpuvideoSetSourceParam(int dev,
		int video,
		int width,
		int height,
		int frequency,
		int isDoublePixel,
		int V206DEV079,
		int pixelformat);



int jmgpuvideoSetSourceUserTimeParam(int dev,
		int video,
		int frequency,
		int isDoublePixel,
		int V206DEV079,
		int pixelformat,
		int mHBlankBegin,
		int mHBlankEnd,
		int mHSBegin,
		int mHSEnd,
		int mHTotal,
		int mVBlankBegin,
		int mVBlankEnd,
		int mVSBegin,
		int mVSEnd,
		int mVTotal,
		int mVBlankBegin2,
		int mVBlankEnd2,
		int mVSBegin2,
		int mVSEnd2,
		int mHalf,
		int mTopfieldBegin);


int jmgpuvideoAdjustSourceTimeParam(int dev,
		int video,
		unsigned short      mHBlankBegin,
		unsigned short      mHBlankEnd,
		unsigned short      mHSBegin,
		unsigned short      mHSEnd,
		unsigned short      mHTotal,
		unsigned short      mVBlankBegin,
		unsigned short      mVBlankEnd,
		unsigned short      mVSBegin,
		unsigned short      mVSEnd,
		unsigned short      mVTotal,
		unsigned short      mVBlankBegin2,
		unsigned short      mVBlankEnd2,
		unsigned short      mVSBegin2,
		unsigned short      mVSEnd2,
		unsigned short      mHalf,
		unsigned short      mTopfieldBegin);



int jmgpuvideoSetSourceUserTimeParamEx(int dev,
		int video,
		int isDoublePixel,
		int htotal,
		int hactive,
		int hfrontporch,
		int hsync,
		int hpol,
		int vtotal,
		int vactive,
		int vfrontporch,
		int vsync,
		int vpol,
		int framerate,
		int V206DEV079,
		int pixelformat);


int jmgpuvideoConfigParamGet(int dev,
		int video,
		int *width,
		int *height,
		int *isDoublePixel,
		int *V206DEV079,
		int *pixelformat);


int jmgpuwinOfVideoGet(int dev, int win, int *pVideo);


int jmgpuwinOfVideoSet(int dev, int win, int video) ;


int jmgpuvideoDisplayParamSet(JMOVERLAY overlayHandle,
		int video,
		int win,
		int screen,
		int cutX,
		int cutY,
		int cutWidth,
		int cutHeight,
		int winX,
		int winY,
		int winWidth,
		int winHeight);


int jmgpuwinOfScreenSet(int dev,
		int win,
		int screen);


int jmgpuoverlayOpenSource(int dev, int video);


int jmgpuoverlayCloseSource(int dev, int video);


int jmgpuoverlaySetSourceRange(JMOVERLAY overlayHandle,
		int video,
		int minInputWidth,
		int minInputHeight,
		int minInputFreq,
		int maxInputWidth,
		int maxInputHeight,
		int maxInputFreq);


int jmgpuwinLumInfoGet(int dev,
		int win,
		int *pCurLum,
		int *pDifference,
		int *pDiffTag);


int jmgpuoverlaySetLumAlarmValve(JMOVERLAY overlayHandle, int win, int valve);


int jmgpuvideoErrInfoFrameStartAddrSet(int dev, int video, int startFrmAddr);


int jmgpuvideoStatusSet(int dev,
		int video,
		int status);


int jmgpuvideoStatusGet(int dev,
		int video,
		int *pStatus);



int jmgpuwinAlphaSet(int dev, int win, int alpha);


int jmgpuwinWinPixelBitWidthSet(int dev, int win, int bitWidth);


int jmgpuwinOverlayModeSet(int dev, int win, int addMode);


int jmgpuwinColorKeyEn(int dev, int win);


int jmgpuwinColorKeyDis(int dev, int win);


int jmgpuwinColorKeySet(int dev,
		int win,
		int redMin,
		int redMax,
		int greenMin,
		int greenMax,
		int blueMin,
		int blueMax);


int jmgpuwinContrastSet(int dev, int win, int contrast);


int jmgpuwinBrightnessSet(int dev, int win, int brightness);


int jmgpuwinPaletteEn(int dev, int win);


int jmgpuwinPaletteDis(int dev, int win);


int jmgpuwinRotate180(int dev, int win, int rotateFlag);


int jmgpuwinClose(int dev, int win);


int jmgpuwinDelayModeSet(int dev, int win, int mode);


int jmgpuwinLowDelayModeParamSet(int dev,
		int win,
		int writeLimitLine,
		int readLimitLine);


int jmgpuwinShowFrameParamSet(int dev,
		int win,
		int screen,
		unsigned int frameAddr,
		unsigned int pixelBitWidth,
		int width,
		int height,
		int V206KG2D033,
		int winx,
		int winy,
		int winWidth,
		int winHeight);


int jmgpuwinPalDispModeSet(int dev,
		int win,
		int mode);


int jmgpuvideoAsTextureInit(int dev,
		int screen,
		int win,
		int video,
		int videoWidth,
		int videoHeight,
		int cutX,
		int cutY,
		int cutWidth,
		int cutHeight,
		int bytesPerPixel);


int jmgpuvideoDataGet(int dev, int win, int *pwidth, int *pheight, int *pformat, unsigned long *paddr);


int jmgpuvideoDataRelease(int dev, int win);


int jmgpuwinHardwareZoomParamSet(int dev, int screen, int win, int V206KG2D033, int srcw,
		int srch, int src_fb,  int dstw, int dsth);

#ifdef __cplusplus
}
#endif

#endif