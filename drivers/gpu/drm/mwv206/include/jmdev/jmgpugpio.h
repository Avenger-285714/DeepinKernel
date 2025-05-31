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
#ifndef _JMGPU_GPIO_H_
#define _JMGPU_GPIO_H_

#ifdef __cplusplus
extern "C" {
#endif


int jmgpugpioRead(int dev, int port, int *pValue);


int jmgpugpioWrite(int dev, int port, int outValue);


int jmgpugpioSetDirection(int dev, int port, int direction);



#ifdef __cplusplus
}
#endif

#endif