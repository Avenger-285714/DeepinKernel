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
#ifndef MWV206_CONFIG_H
#define MWV206_CONFIG_H
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/mwv206platform.h"

#define JJ_VENDOR_ID         0x0731
#define MWV206_DEVICE_ID     0x7200
#define MWV206_PCIE_RW_DMA

#define MWV206_MEM2D_IDX     0
#define MWV206_MEM3D_IDX     1

#define MWV206_KERNEL_MAPPED_FBSIZE (2ULL << 30)

#define MWV206_MAX_DMA_SIZE                (1024*1024*4)
#define MWV206_MIN_DMA_READ_BYTES           (128)
#define MWV206_MIN_DMA_WRITE_BYTES          (128)

#define MWV206_RING_USE_DMABUF

#define MWV206_MAX_DMA_WRITE_SIZE ((1024*1024*4))

#define MWV206_MAX_DMA_LIST_NODE  (4096)
#define MWV206_OUTOFBOUND_VTXBAR_ID   16
#define MWV206_AXI_PCIE_VTX_START_ADDR (0x09000000)
#define MWV206_AXI_PCIE_VTX_END_ADDR   (0x0AFFFFFF)

#define MWV206_OUTOFBOUND_CMDBAR_ID   17

#define MWV206_2D_SENDCMDMODE V206API040

#define MWV206_3D_SENDCMDMODE V206API040

/*
#else
#define MWV206_2D_SENDCMDMODE V206API041
#define MWV206_3D_SENDCMDMODE V206API038
#endif
*/

#define MWV206_REFCOLOCK_FREQ 50

#define MWV206_MAX2DCMDLEN 128

#define MWV206_MAXCMDLEN 0x40000

#define MWV206CMDADDRLEN (0x100 / 4)

#define MWV206_MAX_DEVICEBUSNO 256

#define MWV206CMDTIMEOUT ((GLJ_TICK)FUNC206LXDEV098() * 1)
#define __WAIT_TIMEOUT__ ((GLJ_TICK)FUNC206LXDEV098() * 1)

#define V206CONFIG001  0
#define V206CONFIG002  1
#define V206CONFIG003 2
#define V206CONFIG004  3

#define MWV206_GET_PCI_BAR_LEN pci_resource_len
#define MWV206_GET_PCI_BAR_STARTADDR pci_resource_start

#define V206CONFIG005   2
#define V206CONFIG006  4
#define V206CONFIG007  2
#define V206CONFIG008   2

#define V206CONFIG009     2

typedef enum {
	V206CONFIG011 = 0,
	V206CONFIG012,
	V206CONFIG013,
	V206CONFIG014,
} e_MWV206OutputType;

typedef enum {
	V206CONFIG015 = 0,
	V206CONFIG016 = 1,
} e_MWV206DDRConfType;

#define V206CONFIG017 0
#define V206CONFIG018 1

#define V206CONFIG010 512


#ifdef __cplusplus
}
#endif
#endif