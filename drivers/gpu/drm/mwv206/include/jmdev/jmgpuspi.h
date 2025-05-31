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
#ifndef _JMGPU_SPI_H_
#define _JMGPU_SPI_H_




#define MAC206HAL027           1

#define MAC206HAL028        0

#define MAC206HAL029            0

#define MAC206HAL030         0



int jmgpuspiClockFreqSet(int dev,
		int spi,
		unsigned long freq);


int jmgpuspiTrans(int dev,
		int spi,
		int slave,
		const char *cmdContent,
		unsigned int cmdLength,
		const char *pSendBuffer,
		unsigned int *pSendLen,
		char *pRxBuffer,
		unsigned int *pRecvLen,
		unsigned int startRcv,
		unsigned int transBytes);



int jmgpuspiTransEx(int dev,
		int spi,
		int slave,
		const char *cmdContent,
		unsigned int cmdLength,
		const char *pSendBuffer,
		unsigned int *pSendLen,
		char *pRxBuffer,
		unsigned int *pRecvLen,
		unsigned int startRcv,
		unsigned int transBytes,
		int sclkPhase,
		int sclkPolarity,
		int lsbFirst,
		int recvSampMode);


#endif