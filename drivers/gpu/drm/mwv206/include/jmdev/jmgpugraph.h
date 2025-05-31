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
#ifndef _JMGPU_GRAPH_H_
#define _JMGPU_GRAPH_H_


#define MAX_GRAPH_SCREEN_NUMBER         4

#ifdef __cplusplus
extern "C" {
#endif


int jmgpuscreenColorKeySet(int dev,
		int screen,
		unsigned char redMin,
		unsigned char redMax,
		unsigned char greenMin,
		unsigned char greenMax,
		unsigned char blueMin,
		unsigned char blueMax);


int jmgpuscreenColorKeyEn(int dev, int screen);



int jmgpuscreenColorKeyDis(int dev, int screen);


int jmgpuscreenContrastSet(int dev,
		int screen,
		unsigned char contrastIntegral,
		unsigned char contrastDecimal);



int jmgpuscreenPaletteEn(int dev, int screen);



int jmgpuscreenPaletteDis(int dev, int screen);


int jmgpuscreenPaletteSet(int dev, int screen, int paletteno, unsigned char data[768]);


int jmgpuscreenDefaultPaletteSet(int dev, int screen, int paletteno);



int jmgpuscreenPaletteBCSet(int dev,
		int screen,
		int paletteno,
		int nBrightness,
		int nContrast);



int jmgpuscreenClkSourceSet(int dev, int screen, int clkSource);


int jmgpuscreenSyncSourceSet(int dev, int screen, int synSource);


int jmgpugraphOutputOpen(int dev, int screen);



int jmgpugraphOutputClose(int dev, int screen);



int jmgpuscreenOverlayModeSet(int dev, int screen, int mode);


int jmgpuscreenOverlayOrderSet(int dev, int screen, int order);


int jmgpuscreenOverlayAlphaSet(int dev, int screen, unsigned char alpha0, unsigned char alpha1);

#ifdef __cplusplus
}
#endif

#endif