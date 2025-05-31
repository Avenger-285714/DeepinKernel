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
#ifndef _JMGPU_CURSOR_H_
#define _JMGPU_CURSOR_H_

#ifdef __cplusplus
extern "C" {
#endif



int jmgpucursorDis(int dev, int screen);



int jmgpucursorEn(int dev, int screen, int alphaMode);



int jmgpucursorPosSet(int dev, int screen, int posX, int posY);




int jmgpucursorFrameAddrSet(int dev, int screen, unsigned int frameAddr);


int jmgpucursorFrameAddrGet(int dev, int screen, unsigned int *pframeAddr);




int jmgpucursorAlphaModeSet(int dev, int screen, int alphaMode);



int jmgpucursorAlphaValueSet(int dev, int screen, int alphaValue);



int jmgpucursorCenterPosSet(int dev, int screen, unsigned int centerX, unsigned int centerY);



int jmgpucursorRotate180(int dev, int screen, int flag);

#ifdef __cplusplus
}
#endif

#endif