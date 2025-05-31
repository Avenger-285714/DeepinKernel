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
#ifndef _JMGPU_PWM_H_
#define _JMGPU_PWM_H_

#ifdef __cplusplus
extern "C" {
#endif


int jmgpupwmConfig(int dev,
		int chIndex,
		int highLevel_Time,
		int totalTime,
		int forwareTime);


int jmgpupwmEnable(int dev, int group, int chMask);



int jmgpupwmDisable(int dev, int chMask);


#ifdef __cplusplus
}
#endif

#endif