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
#ifndef _JMGPU_I2C_H_
#define _JMGPU_I2C_H_



int jmgpui2cMultiplex(int dev, int index);


int jmgpui2cClkFreqSet(int dev, int freq);


int jmgpui2cClkFreqGet(int dev, int *freq);


int jmgpui2cClkDivSet(int dev, int clkDiv);


int jmgpui2cRecv(int dev,
		int slaveaddr,
		int V206DEV033,
		int nbytes,
		char *pvalue,
		int isSetStartBit,
		int isSetStopBit);


int jmgpui2cSend(int dev,
		int slaveaddr,
		int V206DEV033,
		int nbytes,
		char *pvalue,
		int isSetStartBit,
		int isSetStopBit);


int jmgpui2cRegWrite_8bit(int dev, int slaveAddr, int addr, char value);


char jmgpui2cRegRead_8bit(int dev, int slaveAddr, int addr);


#endif