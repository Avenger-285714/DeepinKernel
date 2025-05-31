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
	.arch armv8-a
	.text
	.section	.rodata
	.align	3
	.type	DecHwId, %object
	.size	DecHwId, 20
DecHwId:
	.word	33168
	.word	33136
	.word	37232
	.word	37264
	.word	26417
	.text
	.align	2
	.type	ReadCoreConfig, %function
ReadCoreConfig:
.LFB0:
	.cfi_startproc
	stp	x29, x30, [sp, -64]!
	.cfi_def_cfa_offset 64
	.cfi_offset 29, -64
	.cfi_offset 30, -56
	mov	x29, sp
	str	x0, [sp, 40]
	str	x1, [sp, 32]
	str	x2, [sp, 24]
	ldr	x0, [sp, 32]
	add	x0, x0, 528
	mov	w2, 4
	mov	w1, 0
	bl	FUNC206HAL084
	str	wzr, [sp, 60]
	b	.L2
.L23:
	ldr	x0, [sp, 40]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 2
	ldr	x0, [x0, x1, lsl 3]
	add	w0, w0, 200
	mov	w1, w0
	ldr	x0, [sp, 24]
	bl	V206DEV007
	str	w0, [sp, 56]
	ldr	w0, [sp, 56]
	lsr	w0, w0, 24
	and	w0, w0, 3
	str	w0, [sp, 52]
	ldr	x0, [sp, 32]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 132
	ldr	w1, [x0, x1, lsl 2]
	ldr	w0, [sp, 52]
	cmp	w0, 0
	beq	.L3
	mov	w0, 2
	b	.L4
.L3:
	mov	w0, 0
.L4:
	orr	w2, w0, w1
	ldr	x0, [sp, 32]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 132
	str	w2, [x0, x1, lsl 2]
	ldr	w0, [sp, 56]
	lsr	w0, w0, 28
	and	w0, w0, 1
	str	w0, [sp, 52]
	ldr	x0, [sp, 32]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 132
	ldr	w1, [x0, x1, lsl 2]
	ldr	w0, [sp, 52]
	cmp	w0, 0
	beq	.L5
	mov	w0, 8
	b	.L6
.L5:
	mov	w0, 0
.L6:
	orr	w2, w0, w1
	ldr	x0, [sp, 32]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 132
	str	w2, [x0, x1, lsl 2]
	ldr	w0, [sp, 56]
	lsr	w0, w0, 26
	and	w0, w0, 3
	str	w0, [sp, 52]
	ldr	x0, [sp, 32]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 132
	ldr	w1, [x0, x1, lsl 2]
	ldr	w0, [sp, 52]
	cmp	w0, 0
	beq	.L7
	mov	w0, 4
	b	.L8
.L7:
	mov	w0, 0
.L8:
	orr	w2, w0, w1
	ldr	x0, [sp, 32]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 132
	str	w2, [x0, x1, lsl 2]
	ldr	w0, [sp, 56]
	lsr	w0, w0, 29
	and	w0, w0, 3
	str	w0, [sp, 52]
	ldr	x0, [sp, 32]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 132
	ldr	w1, [x0, x1, lsl 2]
	ldr	w0, [sp, 52]
	cmp	w0, 0
	beq	.L9
	mov	w0, 32
	b	.L10
.L9:
	mov	w0, 0
.L10:
	orr	w2, w0, w1
	ldr	x0, [sp, 32]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 132
	str	w2, [x0, x1, lsl 2]
	ldr	w0, [sp, 56]
	lsr	w0, w0, 31
	str	w0, [sp, 52]
	ldr	x0, [sp, 32]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 132
	ldr	w1, [x0, x1, lsl 2]
	ldr	w0, [sp, 52]
	cmp	w0, 0
	beq	.L11
	mov	w0, 64
	b	.L12
.L11:
	mov	w0, 0
.L12:
	orr	w2, w0, w1
	ldr	x0, [sp, 32]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 132
	str	w2, [x0, x1, lsl 2]
	ldr	w0, [sp, 56]
	lsr	w0, w0, 23
	and	w0, w0, 1
	str	w0, [sp, 52]
	ldr	x0, [sp, 32]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 132
	ldr	w1, [x0, x1, lsl 2]
	ldr	w0, [sp, 52]
	cmp	w0, 0
	beq	.L13
	mov	w0, 128
	b	.L14
.L13:
	mov	w0, 0
.L14:
	orr	w2, w0, w1
	ldr	x0, [sp, 32]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 132
	str	w2, [x0, x1, lsl 2]
	ldr	x0, [sp, 40]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 2
	ldr	x0, [x0, x1, lsl 3]
	add	w0, w0, 216
	mov	w1, w0
	ldr	x0, [sp, 24]
	bl	V206DEV007
	str	w0, [sp, 56]
	mov	w0, 25690112
	str	w0, [sp, 48]
	ldr	w1, [sp, 56]
	ldr	w0, [sp, 48]
	and	w0, w1, w0
	str	w0, [sp, 52]
	ldr	x0, [sp, 32]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 132
	ldr	w1, [x0, x1, lsl 2]
	ldr	w0, [sp, 52]
	cmp	w0, 0
	beq	.L15
	mov	w0, 1024
	b	.L16
.L15:
	mov	w0, 0
.L16:
	orr	w2, w0, w1
	ldr	x0, [sp, 32]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 132
	str	w2, [x0, x1, lsl 2]
	ldr	w0, [sp, 56]
	lsr	w0, w0, 22
	and	w0, w0, 1
	str	w0, [sp, 52]
	ldr	x0, [sp, 32]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 132
	ldr	w1, [x0, x1, lsl 2]
	ldr	w0, [sp, 52]
	cmp	w0, 0
	beq	.L17
	mov	w0, 256
	b	.L18
.L17:
	mov	w0, 0
.L18:
	orr	w2, w0, w1
	ldr	x0, [sp, 32]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 132
	str	w2, [x0, x1, lsl 2]
	ldr	w0, [sp, 56]
	lsr	w0, w0, 26
	and	w0, w0, 3
	str	w0, [sp, 52]
	ldr	x0, [sp, 32]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 132
	ldr	w1, [x0, x1, lsl 2]
	ldr	w0, [sp, 52]
	cmp	w0, 0
	beq	.L19
	mov	w0, 512
	b	.L20
.L19:
	mov	w0, 0
.L20:
	orr	w2, w0, w1
	ldr	x0, [sp, 32]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 132
	str	w2, [x0, x1, lsl 2]
	ldr	x0, [sp, 40]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 2
	ldr	x0, [x0, x1, lsl 3]
	add	w0, w0, 400
	mov	w1, w0
	ldr	x0, [sp, 24]
	bl	V206DEV007
	str	w0, [sp, 56]
	ldr	w0, [sp, 56]
	lsr	w0, w0, 16
	and	w0, w0, 1
	str	w0, [sp, 52]
	ldr	x0, [sp, 32]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 132
	ldr	w1, [x0, x1, lsl 2]
	ldr	w0, [sp, 52]
	cmp	w0, 0
	beq	.L21
	mov	w0, 16
	b	.L22
.L21:
	mov	w0, 0
.L22:
	orr	w2, w0, w1
	ldr	x0, [sp, 32]
	ldrsw	x1, [sp, 60]
	add	x1, x1, 132
	str	w2, [x0, x1, lsl 2]
	ldr	w0, [sp, 60]
	add	w0, w0, 1
	str	w0, [sp, 60]
.L2:
	ldr	x0, [sp, 40]
	ldr	w0, [x0, 28]
	ldr	w1, [sp, 60]
	cmp	w1, w0
	blt	.L23
	nop
	ldp	x29, x30, [sp], 64
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE0:
	.size	ReadCoreConfig, .-ReadCoreConfig
	.align	2
	.type	CoreHasFormat, %function
CoreHasFormat:
.LFB1:
	.cfi_startproc
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, 8]
	str	w1, [sp, 4]
	str	w2, [sp]
	ldrsw	x0, [sp, 4]
	lsl	x0, x0, 2
	ldr	x1, [sp, 8]
	add	x0, x1, x0
	ldr	w0, [x0]
	ldr	w1, [sp]
	mov	w2, 1
	lsl	w1, w2, w1
	and	w0, w0, w1
	cmp	w0, 0
	cset	w0, ne
	and	w0, w0, 255
	add	sp, sp, 16
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE1:
	.size	CoreHasFormat, .-CoreHasFormat
	.align	2
	.global	GetDecCore
	.type	GetDecCore, %function
GetDecCore:
.LFB2:
	.cfi_startproc
	stp	x29, x30, [sp, -64]!
	.cfi_def_cfa_offset 64
	.cfi_offset 29, -64
	.cfi_offset 30, -56
	mov	x29, sp
	str	x0, [sp, 40]
	str	x1, [sp, 32]
	str	x2, [sp, 24]
	str	x3, [sp, 16]
	str	wzr, [sp, 60]
	ldr	x0, [sp, 16]
	ldr	x0, [x0, 424]
	bl	FUNC206HAL094
	str	x0, [sp, 48]
	ldr	x1, [sp, 16]
	ldr	x0, [sp, 40]
	add	x0, x0, 60
	lsl	x0, x0, 3
	add	x0, x1, x0
	ldr	x0, [x0, 8]
	cmp	x0, 0
	bne	.L27
	ldr	x1, [sp, 16]
	ldr	x0, [sp, 40]
	add	x0, x0, 60
	lsl	x0, x0, 3
	add	x0, x1, x0
	ldr	x1, [sp, 24]
	str	x1, [x0, 8]
	mov	w0, 1
	str	w0, [sp, 60]
.L27:
	ldr	x0, [sp, 16]
	ldr	x0, [x0, 424]
	ldr	x1, [sp, 48]
	bl	FUNC206HAL095
	ldr	w0, [sp, 60]
	ldp	x29, x30, [sp], 64
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE2:
	.size	GetDecCore, .-GetDecCore
	.align	2
	.global	GetDecCoreAny
	.type	GetDecCoreAny, %function
GetDecCoreAny:
.LFB3:
	.cfi_startproc
	stp	x29, x30, [sp, -80]!
	.cfi_def_cfa_offset 80
	.cfi_offset 29, -80
	.cfi_offset 30, -72
	mov	x29, sp
	str	x0, [sp, 56]
	str	x1, [sp, 48]
	str	x2, [sp, 40]
	str	x3, [sp, 32]
	str	x4, [sp, 24]
	str	wzr, [sp, 76]
	ldr	x0, [sp, 56]
	mov	x1, -1
	str	x1, [x0]
	str	xzr, [sp, 64]
	b	.L30
.L33:
	ldr	x0, [sp, 24]
	add	x0, x0, 528
	ldr	x1, [sp, 64]
	mov	w3, w1
	ldr	x1, [sp, 32]
	mov	w2, w1
	mov	w1, w3
	bl	CoreHasFormat
	cmp	w0, 0
	beq	.L31
	ldr	x3, [sp, 24]
	ldr	x2, [sp, 40]
	ldr	x1, [sp, 48]
	ldr	x0, [sp, 64]
	bl	GetDecCore
	cmp	w0, 0
	beq	.L31
	mov	w0, 1
	str	w0, [sp, 76]
	ldr	x0, [sp, 56]
	ldr	x1, [sp, 64]
	str	x1, [x0]
	b	.L32
.L31:
	ldr	x0, [sp, 64]
	add	x0, x0, 1
	str	x0, [sp, 64]
.L30:
	ldr	x0, [sp, 48]
	ldr	w0, [x0, 28]
	sxtw	x0, w0
	ldr	x1, [sp, 64]
	cmp	x1, x0
	blt	.L33
.L32:
	ldr	w0, [sp, 76]
	ldp	x29, x30, [sp], 80
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE3:
	.size	GetDecCoreAny, .-GetDecCoreAny
	.align	2
	.global	ReserveDecoder
	.type	ReserveDecoder, %function
ReserveDecoder:
.LFB4:
	.cfi_startproc
	stp	x29, x30, [sp, -80]!
	.cfi_def_cfa_offset 80
	.cfi_offset 29, -80
	.cfi_offset 30, -72
	mov	x29, sp
	str	x19, [sp, 16]
	.cfi_offset 19, -64
	str	x0, [sp, 56]
	str	x1, [sp, 48]
	str	x2, [sp, 40]
	str	x3, [sp, 32]
	str	xzr, [sp, 72]
	ldr	x0, [sp, 32]
	ldr	x0, [x0, 504]
	bl	FUNC206HAL090
	cmp	w0, 0
	beq	.L36
	mov	x0, -512
	b	.L39
.L36:
	ldr	x0, [sp, 32]
	ldr	x19, [x0, 448]
	add	x0, sp, 72
	ldr	x4, [sp, 32]
	ldr	x3, [sp, 40]
	ldr	x2, [sp, 48]
	ldr	x1, [sp, 56]
	bl	GetDecCoreAny
	cmp	w0, 0
	cset	w0, ne
	and	w0, w0, 255
	mov	w1, w0
	mov	x0, x19
	bl	FUNC206HAL096
	cmp	w0, 0
	beq	.L38
	ldr	x0, [sp, 32]
	ldr	x0, [x0, 504]
	bl	FUNC206HAL091
	mov	x0, -512
	b	.L39
.L38:
	ldr	x0, [sp, 72]
.L39:
	ldr	x19, [sp, 16]
	ldp	x29, x30, [sp], 80
	.cfi_restore 30
	.cfi_restore 29
	.cfi_restore 19
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE4:
	.size	ReserveDecoder, .-ReserveDecoder
	.section	.rodata
	.align	3
.LC0:
	.string	"\0011decoder: Killed, timeout\n"
	.text
	.align	2
	.global	ReleaseDecoder
	.type	ReleaseDecoder, %function
ReleaseDecoder:
.LFB5:
	.cfi_startproc
	stp	x29, x30, [sp, -64]!
	.cfi_def_cfa_offset 64
	.cfi_offset 29, -64
	.cfi_offset 30, -56
	mov	x29, sp
	str	x0, [sp, 40]
	str	x1, [sp, 32]
	str	x2, [sp, 24]
	str	x3, [sp, 16]
	str	wzr, [sp, 56]
	ldr	x0, [sp, 40]
	ldr	x1, [sp, 32]
	add	x1, x1, 2
	ldr	x0, [x0, x1, lsl 3]
	add	w0, w0, 4
	mov	w1, w0
	ldr	x0, [sp, 16]
	bl	V206DEV007
	str	w0, [sp, 60]
	ldr	w0, [sp, 60]
	and	w0, w0, 1
	cmp	w0, 0
	beq	.L41
	b	.L42
.L44:
	ldr	x0, [sp, 40]
	ldr	x1, [sp, 32]
	add	x1, x1, 2
	ldr	x0, [x0, x1, lsl 3]
	add	w0, w0, 4
	mov	w1, w0
	ldr	x0, [sp, 16]
	bl	V206DEV007
	str	w0, [sp, 60]
	ldr	w0, [sp, 56]
	add	w0, w0, 1
	str	w0, [sp, 56]
	ldr	w1, [sp, 56]
	mov	w0, 41248
	movk	w0, 0x7, lsl 16
	cmp	w1, w0
	bls	.L42
	adrp	x0, .LC1
	add	x0, x0, :lo12:.LC1
	ldr	x0, [x0]
	bl	printk
	b	.L43
.L42:
	ldr	w0, [sp, 60]
	and	w0, w0, 1
	cmp	w0, 0
	bne	.L44
.L43:
	ldr	x0, [sp, 40]
	ldr	x1, [sp, 32]
	add	x1, x1, 2
	ldr	x0, [x0, x1, lsl 3]
	add	w0, w0, 4
	mov	w2, 0
	mov	w1, w0
	ldr	x0, [sp, 16]
	bl	V206DEV006
.L41:
	ldr	x0, [sp, 24]
	ldr	x0, [x0, 424]
	bl	FUNC206HAL094
	str	x0, [sp, 48]
	ldr	x1, [sp, 24]
	ldr	x0, [sp, 32]
	add	x0, x0, 60
	lsl	x0, x0, 3
	add	x0, x1, x0
	str	xzr, [x0, 8]
	ldr	x0, [sp, 24]
	ldr	x0, [x0, 424]
	ldr	x1, [sp, 48]
	bl	FUNC206HAL095
	ldr	x0, [sp, 24]
	ldr	x0, [x0, 504]
	bl	FUNC206HAL091
	ldr	x0, [sp, 24]
	ldr	x0, [x0, 448]
	bl	FUNC206HAL099
	nop
	ldp	x29, x30, [sp], 64
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE5:
	.size	ReleaseDecoder, .-ReleaseDecoder
	.align	3
.LC1:
	.xword	.LC0
	.align	2
	.global	ReservePostProcessor
	.type	ReservePostProcessor, %function
ReservePostProcessor:
.LFB6:
	.cfi_startproc
	stp	x29, x30, [sp, -64]!
	.cfi_def_cfa_offset 64
	.cfi_offset 29, -64
	.cfi_offset 30, -56
	mov	x29, sp
	str	x0, [sp, 40]
	str	x1, [sp, 32]
	str	x2, [sp, 24]
	str	xzr, [sp, 56]
	ldr	x0, [sp, 24]
	ldr	x0, [x0, 512]
	bl	FUNC206HAL090
	cmp	w0, 0
	beq	.L46
	mov	x0, -512
	b	.L47
.L46:
	ldr	x0, [sp, 24]
	ldr	x0, [x0, 424]
	bl	FUNC206HAL094
	str	x0, [sp, 48]
	ldr	x0, [sp, 24]
	ldr	x1, [sp, 56]
	add	x1, x1, 62
	ldr	x2, [sp, 32]
	str	x2, [x0, x1, lsl 3]
	ldr	x0, [sp, 24]
	ldr	x0, [x0, 424]
	ldr	x1, [sp, 48]
	bl	FUNC206HAL095
	ldr	x0, [sp, 56]
.L47:
	ldp	x29, x30, [sp], 64
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE6:
	.size	ReservePostProcessor, .-ReservePostProcessor
	.section	.rodata
	.align	3
.LC2:
	.string	"\0011PP: Wait for hardware finish, timeout(0x%x)\n"
	.text
	.align	2
	.type	WaitForPPFinish, %function
WaitForPPFinish:
.LFB7:
	.cfi_startproc
	stp	x29, x30, [sp, -64]!
	.cfi_def_cfa_offset 64
	.cfi_offset 29, -64
	.cfi_offset 30, -56
	mov	x29, sp
	str	x0, [sp, 40]
	str	x1, [sp, 32]
	str	x2, [sp, 24]
	str	wzr, [sp, 60]
	ldr	x0, [sp, 40]
	ldr	x1, [sp, 32]
	add	x1, x1, 2
	ldr	x0, [x0, x1, lsl 3]
	add	w0, w0, 240
	mov	w1, w0
	ldr	x0, [sp, 24]
	bl	V206DEV007
	str	w0, [sp, 56]
	b	.L49
.L51:
	ldr	x0, [sp, 40]
	ldr	x1, [sp, 32]
	add	x1, x1, 2
	ldr	x0, [x0, x1, lsl 3]
	add	w0, w0, 240
	mov	w1, w0
	ldr	x0, [sp, 24]
	bl	V206DEV007
	str	w0, [sp, 56]
	ldr	w0, [sp, 60]
	add	w0, w0, 1
	str	w0, [sp, 60]
	ldr	w1, [sp, 60]
	mov	w0, 41248
	movk	w0, 0x7, lsl 16
	cmp	w1, w0
	bls	.L49
	ldr	w1, [sp, 56]
	adrp	x0, .LC3
	add	x0, x0, :lo12:.LC3
	ldr	x0, [x0]
	bl	printk
	b	.L50
.L49:
	ldr	w0, [sp, 56]
	and	w0, w0, 1
	cmp	w0, 0
	bne	.L51
.L50:
	nop
	ldp	x29, x30, [sp], 64
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE7:
	.size	WaitForPPFinish, .-WaitForPPFinish
	.align	3
.LC3:
	.xword	.LC2
	.align	2
	.global	ReleasePostProcessor
	.type	ReleasePostProcessor, %function
ReleasePostProcessor:
.LFB8:
	.cfi_startproc
	stp	x29, x30, [sp, -64]!
	.cfi_def_cfa_offset 64
	.cfi_offset 29, -64
	.cfi_offset 30, -56
	mov	x29, sp
	str	x0, [sp, 40]
	str	x1, [sp, 32]
	str	x2, [sp, 24]
	str	x3, [sp, 16]
	ldr	x0, [sp, 40]
	ldr	x1, [sp, 32]
	add	x1, x1, 2
	ldr	x0, [x0, x1, lsl 3]
	add	w0, w0, 240
	mov	w1, w0
	ldr	x0, [sp, 16]
	bl	V206DEV007
	str	w0, [sp, 60]
	ldr	w0, [sp, 60]
	and	w0, w0, 1
	cmp	w0, 0
	beq	.L53
	ldr	x2, [sp, 16]
	ldr	x1, [sp, 32]
	ldr	x0, [sp, 40]
	bl	WaitForPPFinish
	ldr	w0, [sp, 60]
	orr	w0, w0, 16
	str	w0, [sp, 60]
	ldr	w0, [sp, 60]
	and	w0, w0, -2
	str	w0, [sp, 60]
	ldr	x0, [sp, 40]
	ldr	x1, [sp, 32]
	add	x1, x1, 2
	ldr	x0, [x0, x1, lsl 3]
	add	w0, w0, 240
	mov	w2, 16
	mov	w1, w0
	ldr	x0, [sp, 16]
	bl	V206DEV006
.L53:
	ldr	x0, [sp, 24]
	ldr	x0, [x0, 424]
	bl	FUNC206HAL094
	str	x0, [sp, 48]
	ldr	x0, [sp, 24]
	ldr	x1, [sp, 32]
	add	x1, x1, 62
	str	xzr, [x0, x1, lsl 3]
	ldr	x0, [sp, 24]
	ldr	x0, [x0, 424]
	ldr	x1, [sp, 48]
	bl	FUNC206HAL095
	ldr	x0, [sp, 24]
	ldr	x0, [x0, 512]
	bl	FUNC206HAL091
	nop
	ldp	x29, x30, [sp], 64
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE8:
	.size	ReleasePostProcessor, .-ReleasePostProcessor
	.align	2
	.global	ReserveDecPp
	.type	ReserveDecPp, %function
ReserveDecPp:
.LFB9:
	.cfi_startproc
	stp	x29, x30, [sp, -96]!
	.cfi_def_cfa_offset 96
	.cfi_offset 29, -96
	.cfi_offset 30, -88
	mov	x29, sp
	str	x19, [sp, 16]
	.cfi_offset 19, -80
	str	x0, [sp, 72]
	str	x1, [sp, 64]
	str	x2, [sp, 56]
	str	x3, [sp, 48]
	str	x4, [sp, 40]
	str	xzr, [sp, 88]
	ldr	x0, [sp, 48]
	add	x0, x0, 528
	ldr	x1, [sp, 88]
	mov	w3, w1
	ldr	x1, [sp, 56]
	mov	w2, w1
	mov	w1, w3
	bl	CoreHasFormat
	cmp	w0, 0
	bne	.L55
	mov	x0, -14
	b	.L56
.L55:
	ldr	x0, [sp, 48]
	add	x0, x0, 528
	ldr	x1, [sp, 88]
	mov	w2, 4
	bl	CoreHasFormat
	cmp	w0, 0
	bne	.L57
	mov	x0, -14
	b	.L56
.L57:
	ldr	x0, [sp, 48]
	ldr	x0, [x0, 504]
	bl	FUNC206HAL090
	cmp	w0, 0
	beq	.L58
	mov	x0, -512
	b	.L56
.L58:
	ldr	x0, [sp, 48]
	ldr	x19, [x0, 448]
	ldr	x3, [sp, 48]
	ldr	x2, [sp, 64]
	ldr	x1, [sp, 72]
	ldr	x0, [sp, 88]
	bl	GetDecCore
	cmp	w0, 0
	cset	w0, ne
	and	w0, w0, 255
	mov	w1, w0
	mov	x0, x19
	bl	FUNC206HAL096
	cmp	w0, 0
	beq	.L59
	ldr	x0, [sp, 48]
	ldr	x0, [x0, 504]
	bl	FUNC206HAL091
	mov	x0, -512
	b	.L56
.L59:
	ldr	x0, [sp, 48]
	ldr	x0, [x0, 512]
	bl	FUNC206HAL090
	cmp	w0, 0
	beq	.L60
	ldr	x3, [sp, 40]
	ldr	x2, [sp, 48]
	ldr	x1, [sp, 88]
	ldr	x0, [sp, 72]
	bl	ReleaseDecoder
	mov	x0, -512
	b	.L56
.L60:
	ldr	x0, [sp, 48]
	ldr	x0, [x0, 424]
	bl	FUNC206HAL094
	str	x0, [sp, 80]
	ldr	x0, [sp, 48]
	ldr	x1, [sp, 88]
	add	x1, x1, 62
	ldr	x2, [sp, 64]
	str	x2, [x0, x1, lsl 3]
	ldr	x0, [sp, 48]
	ldr	x0, [x0, 424]
	ldr	x1, [sp, 80]
	bl	FUNC206HAL095
	ldr	x0, [sp, 88]
.L56:
	ldr	x19, [sp, 16]
	ldp	x29, x30, [sp], 96
	.cfi_restore 30
	.cfi_restore 29
	.cfi_restore 19
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE9:
	.size	ReserveDecPp, .-ReserveDecPp
	.align	2
	.global	DecFlushRegs
	.type	DecFlushRegs, %function
DecFlushRegs:
.LFB10:
	.cfi_startproc
	stp	x29, x30, [sp, -80]!
	.cfi_def_cfa_offset 80
	.cfi_offset 29, -80
	.cfi_offset 30, -72
	mov	x29, sp
	str	x0, [sp, 40]
	str	x1, [sp, 32]
	str	x2, [sp, 24]
	str	x3, [sp, 16]
	str	xzr, [sp, 64]
	ldr	x0, [sp, 32]
	ldr	w0, [x0]
	str	w0, [sp, 60]
	ldr	w1, [sp, 60]
	mov	x0, 404
	mul	x0, x1, x0
	add	x0, x0, 16
	ldr	x1, [sp, 24]
	add	x3, x1, x0
	ldr	x0, [sp, 32]
	ldr	x0, [x0, 8]
	mov	x2, 240
	mov	x1, x0
	mov	x0, x3
	bl	FUNC206HAL077
	str	x0, [sp, 64]
	ldr	x0, [sp, 64]
	cmp	x0, 0
	beq	.L62
	mov	x0, -14
	b	.L63
.L62:
	mov	x0, 2
	str	x0, [sp, 72]
	b	.L64
.L65:
	ldr	x0, [sp, 40]
	ldr	w1, [sp, 60]
	add	x1, x1, 2
	ldr	x0, [x0, x1, lsl 3]
	mov	w1, w0
	ldr	x0, [sp, 72]
	lsl	w0, w0, 2
	add	w3, w1, w0
	ldr	x0, [sp, 24]
	ldr	w2, [sp, 60]
	mov	x1, 101
	mul	x2, x2, x1
	ldr	x1, [sp, 72]
	add	x1, x2, x1
	add	x1, x1, 4
	ldr	w0, [x0, x1, lsl 2]
	mov	w2, w0
	mov	w1, w3
	ldr	x0, [sp, 16]
	bl	V206DEV006
	ldr	x0, [sp, 72]
	add	x0, x0, 1
	str	x0, [sp, 72]
.L64:
	ldr	x0, [sp, 72]
	cmp	x0, 59
	ble	.L65
	ldr	x0, [sp, 40]
	ldr	w1, [sp, 60]
	add	x1, x1, 2
	ldr	x0, [x0, x1, lsl 3]
	add	w3, w0, 4
	ldr	x1, [sp, 24]
	ldr	w2, [sp, 60]
	mov	x0, 404
	mul	x0, x2, x0
	add	x0, x1, x0
	ldr	w0, [x0, 20]
	mov	w2, w0
	mov	w1, w3
	ldr	x0, [sp, 16]
	bl	V206DEV006
	mov	x0, 0
.L63:
	ldp	x29, x30, [sp], 80
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE10:
	.size	DecFlushRegs, .-DecFlushRegs
	.align	2
	.global	DecRefreshRegs
	.type	DecRefreshRegs, %function
DecRefreshRegs:
.LFB11:
	.cfi_startproc
	stp	x29, x30, [sp, -80]!
	.cfi_def_cfa_offset 80
	.cfi_offset 29, -80
	.cfi_offset 30, -72
	mov	x29, sp
	str	x0, [sp, 40]
	str	x1, [sp, 32]
	str	x2, [sp, 24]
	str	x3, [sp, 16]
	ldr	x0, [sp, 32]
	ldr	w0, [x0]
	str	w0, [sp, 68]
	ldr	x0, [sp, 32]
	ldr	w0, [x0, 16]
	cmp	w0, 240
	beq	.L67
	mov	x0, -14
	b	.L68
.L67:
	str	xzr, [sp, 72]
	b	.L69
.L70:
	ldr	x0, [sp, 40]
	ldr	w1, [sp, 68]
	add	x1, x1, 2
	ldr	x0, [x0, x1, lsl 3]
	mov	w1, w0
	ldr	x0, [sp, 72]
	lsl	w0, w0, 2
	add	w0, w1, w0
	mov	w1, w0
	ldr	x0, [sp, 16]
	bl	V206DEV007
	mov	w3, w0
	ldr	x0, [sp, 24]
	ldr	w2, [sp, 68]
	mov	x1, 101
	mul	x2, x2, x1
	ldr	x1, [sp, 72]
	add	x1, x2, x1
	add	x1, x1, 4
	str	w3, [x0, x1, lsl 2]
	ldr	x0, [sp, 72]
	add	x0, x0, 1
	str	x0, [sp, 72]
.L69:
	ldr	x0, [sp, 72]
	cmp	x0, 59
	ble	.L70
	ldr	x0, [sp, 32]
	ldr	x3, [x0, 8]
	ldr	w1, [sp, 68]
	mov	x0, 404
	mul	x0, x1, x0
	add	x0, x0, 16
	ldr	x1, [sp, 24]
	add	x0, x1, x0
	mov	x2, 240
	mov	x1, x0
	mov	x0, x3
	bl	FUNC206HAL078
	str	x0, [sp, 56]
	ldr	x0, [sp, 56]
	cmp	x0, 0
	beq	.L71
	mov	x0, -14
	b	.L68
.L71:
	mov	x0, 0
.L68:
	ldp	x29, x30, [sp], 80
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE11:
	.size	DecRefreshRegs, .-DecRefreshRegs
	.align	2
	.type	CheckDecIrq, %function
CheckDecIrq:
.LFB12:
	.cfi_startproc
	stp	x29, x30, [sp, -64]!
	.cfi_def_cfa_offset 64
	.cfi_offset 29, -64
	.cfi_offset 30, -56
	mov	x29, sp
	str	x0, [sp, 40]
	str	w1, [sp, 36]
	str	x2, [sp, 24]
	str	wzr, [sp, 60]
	ldr	w0, [sp, 36]
	mov	w1, 1
	lsl	w0, w1, w0
	str	w0, [sp, 56]
	ldr	x0, [sp, 24]
	ldr	x0, [x0, 424]
	bl	FUNC206HAL094
	str	x0, [sp, 48]
	ldr	x0, [sp, 24]
	ldr	w0, [x0, 520]
	mov	w1, w0
	ldr	w0, [sp, 56]
	and	w0, w1, w0
	cmp	w0, 0
	beq	.L73
	ldr	x0, [sp, 24]
	ldr	w0, [x0, 520]
	mov	w1, w0
	ldr	w0, [sp, 56]
	mvn	w0, w0
	and	w0, w1, w0
	mov	w1, w0
	ldr	x0, [sp, 24]
	str	w1, [x0, 520]
	mov	w0, 1
	str	w0, [sp, 60]
.L73:
	ldr	x0, [sp, 24]
	ldr	x0, [x0, 424]
	ldr	x1, [sp, 48]
	bl	FUNC206HAL095
	ldr	w0, [sp, 60]
	ldp	x29, x30, [sp], 64
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE12:
	.size	CheckDecIrq, .-CheckDecIrq
	.align	2
	.global	WaitDecReadyAndRefreshRegs
	.type	WaitDecReadyAndRefreshRegs, %function
WaitDecReadyAndRefreshRegs:
.LFB13:
	.cfi_startproc
	stp	x29, x30, [sp, -80]!
	.cfi_def_cfa_offset 80
	.cfi_offset 29, -80
	.cfi_offset 30, -72
	mov	x29, sp
	str	x19, [sp, 16]
	.cfi_offset 19, -64
	str	x0, [sp, 56]
	str	x1, [sp, 48]
	str	x2, [sp, 40]
	str	x3, [sp, 32]
	ldr	x0, [sp, 48]
	ldr	w0, [x0]
	str	w0, [sp, 76]
	ldr	x0, [sp, 40]
	ldr	x19, [x0, 432]
	ldr	w0, [sp, 76]
	ldr	x2, [sp, 40]
	mov	w1, w0
	ldr	x0, [sp, 56]
	bl	CheckDecIrq
	mov	w1, w0
	mov	x0, x19
	bl	FUNC206HAL096
	cmp	w0, 0
	beq	.L76
	mov	x0, -512
	b	.L77
.L76:
	ldr	x0, [sp, 40]
	ldr	x0, [x0, 544]
	bl	FUNC206HAL075
	ldr	x3, [sp, 32]
	ldr	x2, [sp, 40]
	ldr	x1, [sp, 48]
	ldr	x0, [sp, 56]
	bl	DecRefreshRegs
.L77:
	ldr	x19, [sp, 16]
	ldp	x29, x30, [sp], 80
	.cfi_restore 30
	.cfi_restore 29
	.cfi_restore 19
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE13:
	.size	WaitDecReadyAndRefreshRegs, .-WaitDecReadyAndRefreshRegs
	.align	2
	.global	PPFlushRegs
	.type	PPFlushRegs, %function
PPFlushRegs:
.LFB14:
	.cfi_startproc
	stp	x29, x30, [sp, -80]!
	.cfi_def_cfa_offset 80
	.cfi_offset 29, -80
	.cfi_offset 30, -72
	mov	x29, sp
	str	x0, [sp, 40]
	str	x1, [sp, 32]
	str	x2, [sp, 24]
	str	x3, [sp, 16]
	str	xzr, [sp, 64]
	ldr	x0, [sp, 32]
	ldr	w0, [x0]
	str	w0, [sp, 60]
	ldr	w1, [sp, 60]
	mov	x0, 404
	mul	x0, x1, x0
	add	x0, x0, 16
	ldr	x1, [sp, 24]
	add	x0, x1, x0
	add	x3, x0, 240
	ldr	x0, [sp, 32]
	ldr	x0, [x0, 8]
	add	x0, x0, 240
	mov	x2, 164
	mov	x1, x0
	mov	x0, x3
	bl	FUNC206HAL077
	str	x0, [sp, 64]
	ldr	x0, [sp, 64]
	cmp	x0, 0
	beq	.L79
	mov	x0, -14
	b	.L80
.L79:
	ldr	w0, [sp, 60]
	ldr	x2, [sp, 16]
	mov	x1, x0
	ldr	x0, [sp, 40]
	bl	WaitForPPFinish
	mov	w0, 61
	str	w0, [sp, 76]
	b	.L81
.L82:
	ldr	x0, [sp, 40]
	ldr	w1, [sp, 60]
	add	x1, x1, 2
	ldr	x0, [x0, x1, lsl 3]
	mov	w1, w0
	ldr	w0, [sp, 76]
	lsl	w0, w0, 2
	add	w4, w1, w0
	ldr	x0, [sp, 24]
	ldr	w1, [sp, 76]
	ldr	w3, [sp, 60]
	mov	x2, 101
	mul	x2, x3, x2
	add	x1, x2, x1
	add	x1, x1, 4
	ldr	w0, [x0, x1, lsl 2]
	mov	w2, w0
	mov	w1, w4
	ldr	x0, [sp, 16]
	bl	V206DEV006
	ldr	w0, [sp, 76]
	add	w0, w0, 1
	str	w0, [sp, 76]
.L81:
	ldr	w0, [sp, 76]
	cmp	w0, 100
	bls	.L82
	ldr	x0, [sp, 40]
	ldr	w1, [sp, 60]
	add	x1, x1, 2
	ldr	x0, [x0, x1, lsl 3]
	add	w3, w0, 240
	ldr	x1, [sp, 24]
	ldr	w2, [sp, 60]
	mov	x0, 404
	mul	x0, x2, x0
	add	x0, x1, x0
	ldr	w0, [x0, 256]
	mov	w2, w0
	mov	w1, w3
	ldr	x0, [sp, 16]
	bl	V206DEV006
	mov	x0, 0
.L80:
	ldp	x29, x30, [sp], 80
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE14:
	.size	PPFlushRegs, .-PPFlushRegs
	.align	2
	.global	PPRefreshRegs
	.type	PPRefreshRegs, %function
PPRefreshRegs:
.LFB15:
	.cfi_startproc
	stp	x29, x30, [sp, -80]!
	.cfi_def_cfa_offset 80
	.cfi_offset 29, -80
	.cfi_offset 30, -72
	mov	x29, sp
	str	x0, [sp, 40]
	str	x1, [sp, 32]
	str	x2, [sp, 24]
	str	x3, [sp, 16]
	ldr	x0, [sp, 32]
	ldr	w0, [x0]
	str	w0, [sp, 68]
	ldr	x0, [sp, 32]
	ldr	w0, [x0, 16]
	cmp	w0, 164
	beq	.L84
	mov	x0, -14
	b	.L85
.L84:
	mov	x0, 60
	str	x0, [sp, 72]
	b	.L86
.L87:
	ldr	x0, [sp, 40]
	ldr	w1, [sp, 68]
	add	x1, x1, 2
	ldr	x0, [x0, x1, lsl 3]
	mov	w1, w0
	ldr	x0, [sp, 72]
	lsl	w0, w0, 2
	add	w0, w1, w0
	mov	w1, w0
	ldr	x0, [sp, 16]
	bl	V206DEV007
	mov	w3, w0
	ldr	x0, [sp, 24]
	ldr	w2, [sp, 68]
	mov	x1, 101
	mul	x2, x2, x1
	ldr	x1, [sp, 72]
	add	x1, x2, x1
	add	x1, x1, 4
	str	w3, [x0, x1, lsl 2]
	ldr	x0, [sp, 72]
	add	x0, x0, 1
	str	x0, [sp, 72]
.L86:
	ldr	x0, [sp, 72]
	cmp	x0, 100
	ble	.L87
	ldr	x0, [sp, 32]
	ldr	x0, [x0, 8]
	add	x3, x0, 240
	ldr	w1, [sp, 68]
	mov	x0, 404
	mul	x0, x1, x0
	add	x0, x0, 16
	ldr	x1, [sp, 24]
	add	x0, x1, x0
	add	x0, x0, 240
	mov	x2, 164
	mov	x1, x0
	mov	x0, x3
	bl	FUNC206HAL078
	str	x0, [sp, 56]
	ldr	x0, [sp, 56]
	cmp	x0, 0
	beq	.L88
	mov	x0, -14
	b	.L85
.L88:
	mov	x0, 0
.L85:
	ldp	x29, x30, [sp], 80
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE15:
	.size	PPRefreshRegs, .-PPRefreshRegs
	.align	2
	.type	CheckPPIrq, %function
CheckPPIrq:
.LFB16:
	.cfi_startproc
	stp	x29, x30, [sp, -64]!
	.cfi_def_cfa_offset 64
	.cfi_offset 29, -64
	.cfi_offset 30, -56
	mov	x29, sp
	str	x0, [sp, 40]
	str	w1, [sp, 36]
	str	x2, [sp, 24]
	str	wzr, [sp, 60]
	ldr	w0, [sp, 36]
	mov	w1, 1
	lsl	w0, w1, w0
	str	w0, [sp, 56]
	ldr	x0, [sp, 24]
	ldr	x0, [x0, 424]
	bl	FUNC206HAL094
	str	x0, [sp, 48]
	ldr	x0, [sp, 24]
	ldr	w0, [x0, 524]
	mov	w1, w0
	ldr	w0, [sp, 56]
	and	w0, w1, w0
	cmp	w0, 0
	beq	.L90
	ldr	x0, [sp, 24]
	ldr	w0, [x0, 524]
	mov	w1, w0
	ldr	w0, [sp, 56]
	mvn	w0, w0
	and	w0, w1, w0
	mov	w1, w0
	ldr	x0, [sp, 24]
	str	w1, [x0, 524]
	mov	w0, 1
	str	w0, [sp, 60]
.L90:
	ldr	x0, [sp, 24]
	ldr	x0, [x0, 424]
	ldr	x1, [sp, 48]
	bl	FUNC206HAL095
	ldr	w0, [sp, 60]
	ldp	x29, x30, [sp], 64
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE16:
	.size	CheckPPIrq, .-CheckPPIrq
	.align	2
	.global	WaitPPReadyAndRefreshRegs
	.type	WaitPPReadyAndRefreshRegs, %function
WaitPPReadyAndRefreshRegs:
.LFB17:
	.cfi_startproc
	stp	x29, x30, [sp, -80]!
	.cfi_def_cfa_offset 80
	.cfi_offset 29, -80
	.cfi_offset 30, -72
	mov	x29, sp
	str	x19, [sp, 16]
	.cfi_offset 19, -64
	str	x0, [sp, 56]
	str	x1, [sp, 48]
	str	x2, [sp, 40]
	str	x3, [sp, 32]
	ldr	x0, [sp, 48]
	ldr	w0, [x0]
	str	w0, [sp, 76]
	ldr	x0, [sp, 40]
	ldr	x19, [x0, 440]
	ldr	w0, [sp, 76]
	ldr	x2, [sp, 40]
	mov	w1, w0
	ldr	x0, [sp, 56]
	bl	CheckPPIrq
	mov	w1, w0
	mov	x0, x19
	bl	FUNC206HAL096
	cmp	w0, 0
	beq	.L93
	mov	x0, -512
	b	.L94
.L93:
	ldr	x0, [sp, 40]
	ldr	x0, [x0, 544]
	bl	FUNC206HAL075
	ldr	x3, [sp, 32]
	ldr	x2, [sp, 40]
	ldr	x1, [sp, 48]
	ldr	x0, [sp, 56]
	bl	PPRefreshRegs
.L94:
	ldr	x19, [sp, 16]
	ldp	x29, x30, [sp], 80
	.cfi_restore 30
	.cfi_restore 29
	.cfi_restore 19
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE17:
	.size	WaitPPReadyAndRefreshRegs, .-WaitPPReadyAndRefreshRegs
	.align	2
	.type	CheckCoreIrq, %function
CheckCoreIrq:
.LFB18:
	.cfi_startproc
	stp	x29, x30, [sp, -80]!
	.cfi_def_cfa_offset 80
	.cfi_offset 29, -80
	.cfi_offset 30, -72
	mov	x29, sp
	str	x0, [sp, 40]
	str	x1, [sp, 32]
	str	x2, [sp, 24]
	str	x3, [sp, 16]
	str	wzr, [sp, 76]
	str	wzr, [sp, 72]
.L99:
	ldr	w0, [sp, 72]
	mov	w1, 1
	lsl	w0, w1, w0
	str	w0, [sp, 68]
	ldr	x0, [sp, 16]
	ldr	x0, [x0, 424]
	bl	FUNC206HAL094
	str	x0, [sp, 56]
	ldr	x0, [sp, 16]
	ldr	w0, [x0, 520]
	mov	w1, w0
	ldr	w0, [sp, 68]
	and	w0, w1, w0
	cmp	w0, 0
	beq	.L96
	ldr	x1, [sp, 16]
	ldrsw	x0, [sp, 72]
	add	x0, x0, 60
	lsl	x0, x0, 3
	add	x0, x1, x0
	ldr	x0, [x0, 8]
	ldr	x1, [sp, 32]
	cmp	x1, x0
	bne	.L97
	ldr	x0, [sp, 16]
	ldr	w0, [x0, 520]
	mov	w1, w0
	ldr	w0, [sp, 68]
	mvn	w0, w0
	and	w0, w1, w0
	mov	w1, w0
	ldr	x0, [sp, 16]
	str	w1, [x0, 520]
	ldr	x0, [sp, 24]
	ldr	w1, [sp, 72]
	str	w1, [x0]
	mov	w0, 1
	str	w0, [sp, 76]
	b	.L98
.L97:
	ldr	x1, [sp, 16]
	ldrsw	x0, [sp, 72]
	add	x0, x0, 60
	lsl	x0, x0, 3
	add	x0, x1, x0
	ldr	x0, [x0, 8]
	cmp	x0, 0
	bne	.L96
	ldr	x0, [sp, 16]
	ldr	w0, [x0, 520]
	mov	w1, w0
	ldr	w0, [sp, 68]
	mvn	w0, w0
	and	w0, w1, w0
	mov	w1, w0
	ldr	x0, [sp, 16]
	str	w1, [x0, 520]
.L96:
	ldr	x0, [sp, 16]
	ldr	x0, [x0, 424]
	ldr	x1, [sp, 56]
	bl	FUNC206HAL095
	ldr	w0, [sp, 72]
	add	w0, w0, 1
	str	w0, [sp, 72]
	ldr	x0, [sp, 40]
	ldr	w0, [x0, 28]
	ldr	w1, [sp, 72]
	cmp	w1, w0
	blt	.L99
.L98:
	ldr	w0, [sp, 76]
	ldp	x29, x30, [sp], 80
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE18:
	.size	CheckCoreIrq, .-CheckCoreIrq
	.align	2
	.global	WaitCoreReady
	.type	WaitCoreReady, %function
WaitCoreReady:
.LFB19:
	.cfi_startproc
	stp	x29, x30, [sp, -64]!
	.cfi_def_cfa_offset 64
	.cfi_offset 29, -64
	.cfi_offset 30, -56
	mov	x29, sp
	str	x19, [sp, 16]
	.cfi_offset 19, -48
	str	x0, [sp, 56]
	str	x1, [sp, 48]
	str	x2, [sp, 40]
	str	x3, [sp, 32]
	ldr	x0, [sp, 32]
	ldr	x19, [x0, 432]
	ldr	x3, [sp, 32]
	ldr	x2, [sp, 40]
	ldr	x1, [sp, 48]
	ldr	x0, [sp, 56]
	bl	CheckCoreIrq
	mov	w1, w0
	mov	x0, x19
	bl	FUNC206HAL096
	cmp	w0, 0
	beq	.L102
	mov	x0, -512
	b	.L103
.L102:
	ldr	x0, [sp, 32]
	ldr	x0, [x0, 544]
	bl	FUNC206HAL075
	mov	x0, 0
.L103:
	ldr	x19, [sp, 16]
	ldp	x29, x30, [sp], 64
	.cfi_restore 30
	.cfi_restore 29
	.cfi_restore 19
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE19:
	.size	WaitCoreReady, .-WaitCoreReady
	.section	.rodata
	.align	3
.LC4:
	.string	"\0011decoder: pDec->dec_irq     = 0x%08x \n"
	.align	3
.LC6:
	.string	"\0011decoder: pDec->pp_irq      = 0x%08x \n"
	.align	3
.LC8:
	.string	"\0011decoder: IRQs received/sent2user = %d / %d \n"
	.align	3
.LC10:
	.string	"FREE"
	.align	3
.LC12:
	.string	"RESERVED"
	.align	3
.LC14:
	.string	"\0011decoder: dec_core[%li] %s\n"
	.align	3
.LC16:
	.string	"\0011decoder: pp_core[%li]  %s\n"
	.text
	.align	2
	.global	mwv206dec_ioctl
	.type	mwv206dec_ioctl, %function
mwv206dec_ioctl:
.LFB20:
	.cfi_startproc
	stp	x29, x30, [sp, -272]!
	.cfi_def_cfa_offset 272
	.cfi_offset 29, -272
	.cfi_offset 30, -264
	mov	x29, sp
	str	x19, [sp, 16]
	.cfi_offset 19, -256
	str	x0, [sp, 72]
	str	w1, [sp, 68]
	str	x2, [sp, 56]
	str	x3, [sp, 48]
	str	x4, [sp, 40]
	str	wzr, [sp, 260]
	ldr	x0, [sp, 48]
	str	x0, [sp, 248]
	ldr	w1, [sp, 68]
	mov	w0, 27395
	movk	w0, 0x8008, lsl 16
	cmp	w1, w0
	beq	.L105
	ldr	w1, [sp, 68]
	mov	w0, 27395
	movk	w0, 0x8008, lsl 16
	cmp	w1, w0
	bhi	.L106
	ldr	w1, [sp, 68]
	mov	w0, 27405
	cmp	w1, w0
	beq	.L107
	ldr	w1, [sp, 68]
	mov	w0, 27405
	cmp	w1, w0
	bhi	.L108
	ldr	w1, [sp, 68]
	mov	w0, 27398
	cmp	w1, w0
	beq	.L109
	ldr	w1, [sp, 68]
	mov	w0, 27398
	cmp	w1, w0
	bhi	.L110
	ldr	w1, [sp, 68]
	mov	w0, 27397
	cmp	w1, w0
	beq	.L111
	b	.L112
.L110:
	ldr	w1, [sp, 68]
	mov	w0, 27403
	cmp	w1, w0
	beq	.L113
	ldr	w1, [sp, 68]
	mov	w0, 27404
	cmp	w1, w0
	beq	.L114
	b	.L112
.L108:
	ldr	w1, [sp, 68]
	mov	w0, 27421
	cmp	w1, w0
	beq	.L115
	ldr	w1, [sp, 68]
	mov	w0, 27421
	cmp	w1, w0
	bhi	.L116
	ldr	w1, [sp, 68]
	mov	w0, 27406
	cmp	w1, w0
	beq	.L117
	b	.L112
.L116:
	ldr	w1, [sp, 68]
	mov	w0, 27401
	movk	w0, 0x4008, lsl 16
	cmp	w1, w0
	beq	.L118
	ldr	w1, [sp, 68]
	mov	w0, 27402
	movk	w0, 0x4008, lsl 16
	cmp	w1, w0
	beq	.L119
	b	.L112
.L106:
	ldr	w1, [sp, 68]
	mov	w0, 27407
	movk	w0, 0xc008, lsl 16
	cmp	w1, w0
	beq	.L120
	ldr	w1, [sp, 68]
	mov	w0, 27407
	movk	w0, 0xc008, lsl 16
	cmp	w1, w0
	bhi	.L121
	ldr	w1, [sp, 68]
	mov	w0, 27399
	movk	w0, 0x8008, lsl 16
	cmp	w1, w0
	beq	.L122
	ldr	w1, [sp, 68]
	mov	w0, 27399
	movk	w0, 0x8008, lsl 16
	cmp	w1, w0
	bhi	.L123
	ldr	w1, [sp, 68]
	mov	w0, 27396
	movk	w0, 0x8008, lsl 16
	cmp	w1, w0
	beq	.L124
	b	.L112
.L123:
	ldr	w1, [sp, 68]
	mov	w0, 27400
	movk	w0, 0x8008, lsl 16
	cmp	w1, w0
	beq	.L125
	ldr	w1, [sp, 68]
	mov	w0, 27411
	movk	w0, 0x8008, lsl 16
	cmp	w1, w0
	beq	.L126
	b	.L112
.L121:
	ldr	w1, [sp, 68]
	mov	w0, 27409
	movk	w0, 0xc008, lsl 16
	cmp	w1, w0
	beq	.L127
	ldr	w1, [sp, 68]
	mov	w0, 27409
	movk	w0, 0xc008, lsl 16
	cmp	w1, w0
	bcc	.L128
	ldr	w1, [sp, 68]
	mov	w0, 27410
	movk	w0, 0xc008, lsl 16
	cmp	w1, w0
	beq	.L129
	ldr	w1, [sp, 68]
	mov	w0, 27412
	movk	w0, 0xc008, lsl 16
	cmp	w1, w0
	beq	.L130
	b	.L112
.L111:
	ldr	x0, [sp, 248]
	ldr	w0, [x0, 480]
	bl	FUNC206HAL079
	b	.L131
.L109:
	ldr	x0, [sp, 248]
	ldr	w0, [x0, 480]
	bl	FUNC206HAL080
	b	.L131
.L105:
	ldr	x0, [sp, 248]
	ldr	x0, [x0, 8]
	ldr	x1, [sp, 56]
	bl	FUNC206HAL087
	b	.L131
.L124:
	ldr	x0, [sp, 248]
	ldr	w0, [x0, 464]
	ldr	x1, [sp, 56]
	bl	FUNC206HAL086
	b	.L131
.L122:
	ldr	x3, [sp, 56]
	ldr	x0, [sp, 248]
	add	x0, x0, 8
	mov	x2, 8
	mov	x1, x0
	mov	x0, x3
	bl	FUNC206HAL078
	str	x0, [sp, 264]
	ldr	w0, [sp, 260]
	cmp	w0, 0
	beq	.L157
	mov	x0, -14
	b	.L133
.L125:
	ldr	x0, [sp, 248]
	ldr	w0, [x0, 484]
	mov	w2, w0
	ldr	x0, [sp, 56]
	mov	x1, x0
	mov	w0, w2
	bl	FUNC206HAL086
	b	.L131
.L118:
	ldr	x1, [sp, 56]
	add	x0, sp, 216
	mov	x2, 24
	bl	FUNC206HAL077
	str	x0, [sp, 264]
	ldr	x0, [sp, 264]
	cmp	x0, 0
	beq	.L134
	mov	x0, -14
	b	.L133
.L134:
	ldr	x0, [sp, 248]
	add	x0, x0, 456
	add	x1, sp, 216
	ldr	x3, [sp, 40]
	ldr	x2, [sp, 248]
	bl	DecFlushRegs
	b	.L133
.L119:
	ldr	x1, [sp, 56]
	add	x0, sp, 192
	mov	x2, 24
	bl	FUNC206HAL077
	str	x0, [sp, 264]
	ldr	x0, [sp, 264]
	cmp	x0, 0
	beq	.L136
	mov	x0, -14
	b	.L133
.L136:
	ldr	x0, [sp, 248]
	add	x0, x0, 456
	add	x1, sp, 192
	ldr	x3, [sp, 40]
	ldr	x2, [sp, 248]
	bl	PPFlushRegs
	b	.L133
.L127:
	ldr	x1, [sp, 56]
	add	x0, sp, 168
	mov	x2, 24
	bl	FUNC206HAL077
	str	x0, [sp, 264]
	ldr	x0, [sp, 264]
	cmp	x0, 0
	beq	.L138
	mov	x0, -14
	b	.L133
.L138:
	ldr	x0, [sp, 248]
	add	x0, x0, 456
	add	x1, sp, 168
	ldr	x3, [sp, 40]
	ldr	x2, [sp, 248]
	bl	DecRefreshRegs
	b	.L133
.L129:
	ldr	x1, [sp, 56]
	add	x0, sp, 144
	mov	x2, 24
	bl	FUNC206HAL077
	str	x0, [sp, 264]
	ldr	x0, [sp, 264]
	cmp	x0, 0
	beq	.L140
	mov	x0, -14
	b	.L133
.L140:
	ldr	x0, [sp, 248]
	add	x0, x0, 456
	add	x1, sp, 144
	ldr	x3, [sp, 40]
	ldr	x2, [sp, 248]
	bl	PPRefreshRegs
	b	.L133
.L113:
	ldr	x0, [sp, 248]
	add	x0, x0, 456
	ldr	x3, [sp, 248]
	ldr	x2, [sp, 56]
	ldr	x1, [sp, 72]
	bl	ReserveDecoder
	b	.L133
.L114:
	ldr	x0, [sp, 248]
	ldr	w0, [x0, 484]
	sxtw	x0, w0
	ldr	x1, [sp, 56]
	cmp	x1, x0
	bcs	.L142
	ldr	x1, [sp, 248]
	ldr	x0, [sp, 56]
	add	x0, x0, 60
	lsl	x0, x0, 3
	add	x0, x1, x0
	ldr	x0, [x0, 8]
	ldr	x1, [sp, 72]
	cmp	x1, x0
	beq	.L143
.L142:
	mov	x0, -14
	b	.L133
.L143:
	ldr	x0, [sp, 248]
	add	x0, x0, 456
	ldr	x1, [sp, 56]
	ldr	x3, [sp, 40]
	ldr	x2, [sp, 248]
	bl	ReleaseDecoder
	b	.L131
.L107:
	ldr	x0, [sp, 248]
	add	x0, x0, 456
	ldr	x2, [sp, 248]
	ldr	x1, [sp, 72]
	bl	ReservePostProcessor
	b	.L133
.L117:
	ldr	x0, [sp, 56]
	cmp	x0, 0
	bne	.L144
	ldr	x0, [sp, 248]
	ldr	x1, [sp, 56]
	add	x1, x1, 62
	ldr	x0, [x0, x1, lsl 3]
	ldr	x1, [sp, 72]
	cmp	x1, x0
	beq	.L145
.L144:
	mov	x0, -14
	b	.L133
.L145:
	ldr	x0, [sp, 248]
	add	x0, x0, 456
	ldr	x1, [sp, 56]
	ldr	x3, [sp, 40]
	ldr	x2, [sp, 248]
	bl	ReleasePostProcessor
	b	.L131
.L120:
	ldr	x1, [sp, 56]
	add	x0, sp, 120
	mov	x2, 24
	bl	FUNC206HAL077
	str	x0, [sp, 264]
	ldr	x0, [sp, 264]
	cmp	x0, 0
	beq	.L146
	mov	x0, -14
	b	.L133
.L146:
	ldr	x0, [sp, 248]
	add	x0, x0, 456
	add	x1, sp, 120
	ldr	x3, [sp, 40]
	ldr	x2, [sp, 248]
	bl	WaitDecReadyAndRefreshRegs
	b	.L133
.L128:
	ldr	x1, [sp, 56]
	add	x0, sp, 96
	mov	x2, 24
	bl	FUNC206HAL077
	str	x0, [sp, 264]
	ldr	x0, [sp, 264]
	cmp	x0, 0
	beq	.L148
	mov	x0, -14
	b	.L133
.L148:
	ldr	x0, [sp, 248]
	add	x0, x0, 456
	add	x1, sp, 96
	ldr	x3, [sp, 40]
	ldr	x2, [sp, 248]
	bl	WaitPPReadyAndRefreshRegs
	b	.L133
.L126:
	ldr	x0, [sp, 248]
	add	x0, x0, 456
	add	x1, sp, 92
	ldr	x3, [sp, 248]
	mov	x2, x1
	ldr	x1, [sp, 72]
	bl	WaitCoreReady
	str	x0, [sp, 264]
	ldr	w0, [sp, 92]
	ldr	x1, [sp, 56]
	bl	FUNC206HAL085
	ldr	x0, [sp, 264]
	b	.L133
.L130:
	ldr	x0, [sp, 56]
	bl	FUNC206HAL082
	str	w0, [sp, 244]
	ldr	x0, [sp, 248]
	ldr	w0, [x0, 484]
	mov	w1, w0
	ldr	w0, [sp, 244]
	cmp	w0, w1
	bcc	.L150
	mov	x0, -14
	b	.L133
.L150:
	ldr	x1, [sp, 248]
	ldr	w0, [sp, 244]
	add	x0, x0, 58
	lsl	x0, x0, 3
	add	x0, x1, x0
	ldr	x0, [x0, 8]
	mov	w1, w0
	ldr	x0, [sp, 40]
	bl	V206DEV007
	str	w0, [sp, 244]
	ldr	x0, [sp, 56]
	mov	x1, x0
	ldr	w0, [sp, 244]
	bl	FUNC206HAL086
	b	.L131
.L115:
	ldr	x0, [sp, 248]
	ldr	w0, [x0, 520]
	mov	w1, w0
	adrp	x0, .LC5
	add	x0, x0, :lo12:.LC5
	ldr	x0, [x0]
	bl	printk
	ldr	x0, [sp, 248]
	ldr	w0, [x0, 524]
	mov	w1, w0
	adrp	x0, .LC7
	add	x0, x0, :lo12:.LC7
	ldr	x0, [x0]
	bl	printk
	ldr	x0, [sp, 248]
	ldr	x0, [x0, 536]
	bl	FUNC206HAL076
	mov	w19, w0
	ldr	x0, [sp, 248]
	ldr	x0, [x0, 544]
	bl	FUNC206HAL076
	mov	w2, w0
	mov	w1, w19
	adrp	x0, .LC9
	add	x0, x0, :lo12:.LC9
	ldr	x0, [x0]
	bl	printk
	str	xzr, [sp, 264]
	b	.L151
.L156:
	ldr	x1, [sp, 248]
	ldr	x0, [sp, 264]
	add	x0, x0, 60
	lsl	x0, x0, 3
	add	x0, x1, x0
	ldr	x0, [x0, 8]
	cmp	x0, 0
	bne	.L152
	adrp	x0, .LC11
	add	x0, x0, :lo12:.LC11
	ldr	x0, [x0]
	b	.L153
.L152:
	adrp	x0, .LC13
	add	x0, x0, :lo12:.LC13
	ldr	x0, [x0]
.L153:
	mov	x2, x0
	ldr	x1, [sp, 264]
	adrp	x0, .LC15
	add	x0, x0, :lo12:.LC15
	ldr	x0, [x0]
	bl	printk
	ldr	x0, [sp, 248]
	ldr	x1, [sp, 264]
	add	x1, x1, 62
	ldr	x0, [x0, x1, lsl 3]
	cmp	x0, 0
	bne	.L154
	adrp	x0, .LC11
	add	x0, x0, :lo12:.LC11
	ldr	x0, [x0]
	b	.L155
.L154:
	adrp	x0, .LC13
	add	x0, x0, :lo12:.LC13
	ldr	x0, [x0]
.L155:
	mov	x2, x0
	ldr	x1, [sp, 264]
	adrp	x0, .LC17
	add	x0, x0, :lo12:.LC17
	ldr	x0, [x0]
	bl	printk
	ldr	x0, [sp, 264]
	add	x0, x0, 1
	str	x0, [sp, 264]
.L151:
	ldr	x0, [sp, 248]
	ldr	w0, [x0, 484]
	sxtw	x0, w0
	ldr	x1, [sp, 264]
	cmp	x1, x0
	blt	.L156
	b	.L131
.L112:
	mov	x0, -25
	b	.L133
.L157:
	nop
.L131:
	mov	x0, 0
.L133:
	ldr	x19, [sp, 16]
	ldp	x29, x30, [sp], 272
	.cfi_restore 30
	.cfi_restore 29
	.cfi_restore 19
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE20:
	.size	mwv206dec_ioctl, .-mwv206dec_ioctl
	.align	3
.LC5:
	.xword	.LC4
	.align	3
.LC7:
	.xword	.LC6
	.align	3
.LC9:
	.xword	.LC8
	.align	3
.LC11:
	.xword	.LC10
	.align	3
.LC13:
	.xword	.LC12
	.align	3
.LC15:
	.xword	.LC14
	.align	3
.LC17:
	.xword	.LC16
	.align	2
	.global	mwv206dec_release
	.type	mwv206dec_release, %function
mwv206dec_release:
.LFB21:
	.cfi_startproc
	stp	x29, x30, [sp, -80]!
	.cfi_def_cfa_offset 80
	.cfi_offset 29, -80
	.cfi_offset 30, -72
	mov	x29, sp
	str	x0, [sp, 40]
	str	x1, [sp, 32]
	str	x2, [sp, 24]
	str	x3, [sp, 16]
	ldr	x0, [sp, 24]
	str	x0, [sp, 64]
	ldr	x0, [sp, 64]
	add	x0, x0, 456
	str	x0, [sp, 56]
	str	wzr, [sp, 76]
	b	.L159
.L161:
	ldr	x1, [sp, 64]
	ldrsw	x0, [sp, 76]
	add	x0, x0, 60
	lsl	x0, x0, 3
	add	x0, x1, x0
	ldr	x0, [x0, 8]
	ldr	x1, [sp, 32]
	cmp	x1, x0
	bne	.L160
	ldrsw	x0, [sp, 76]
	ldr	x3, [sp, 16]
	ldr	x2, [sp, 64]
	mov	x1, x0
	ldr	x0, [sp, 56]
	bl	ReleaseDecoder
.L160:
	ldr	w0, [sp, 76]
	add	w0, w0, 1
	str	w0, [sp, 76]
.L159:
	ldr	x0, [sp, 56]
	ldr	w0, [x0, 28]
	ldr	w1, [sp, 76]
	cmp	w1, w0
	blt	.L161
	str	wzr, [sp, 76]
	b	.L162
.L164:
	ldr	x0, [sp, 64]
	ldrsw	x1, [sp, 76]
	add	x1, x1, 62
	ldr	x0, [x0, x1, lsl 3]
	ldr	x1, [sp, 32]
	cmp	x1, x0
	bne	.L163
	ldrsw	x0, [sp, 76]
	ldr	x3, [sp, 16]
	ldr	x2, [sp, 64]
	mov	x1, x0
	ldr	x0, [sp, 56]
	bl	ReleasePostProcessor
.L163:
	ldr	w0, [sp, 76]
	add	w0, w0, 1
	str	w0, [sp, 76]
.L162:
	ldr	w0, [sp, 76]
	cmp	w0, 0
	ble	.L164
	mov	w0, 0
	ldp	x29, x30, [sp], 80
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE21:
	.size	mwv206dec_release, .-mwv206dec_release
	.section	.rodata
	.align	3
.LC18:
	.string	"\0016[INFO] decoder: Init begin. \n"
	.align	3
.LC20:
	.string	"\0016[INFO] decoder: Init End. \n"
	.align	3
.LC22:
	.string	"\0011[ERROR] decoder: Init failed.\n"
	.text
	.align	2
	.global	mwv206dec_init
	.type	mwv206dec_init, %function
mwv206dec_init:
.LFB22:
	.cfi_startproc
	stp	x29, x30, [sp, -80]!
	.cfi_def_cfa_offset 80
	.cfi_offset 29, -80
	.cfi_offset 30, -72
	mov	x29, sp
	str	x0, [sp, 40]
	str	x1, [sp, 32]
	str	x2, [sp, 24]
	mov	w0, -1
	str	w0, [sp, 72]
	str	wzr, [sp, 68]
	mov	w0, 552
	bl	FUNC206LXDEV010
	str	x0, [sp, 56]
	ldr	x0, [sp, 56]
	cmp	x0, 0
	bne	.L167
	mov	w0, -1
	b	.L168
.L167:
	ldr	x0, [sp, 56]
	ldr	x1, [sp, 32]
	str	x1, [x0]
	ldr	x0, [sp, 40]
	ldr	x1, [sp, 56]
	str	x1, [x0]
	adrp	x0, .LC19
	add	x0, x0, :lo12:.LC19
	ldr	x0, [x0]
	bl	printk
	ldr	x0, [sp, 56]
	ldr	x1, [sp, 32]
	str	x1, [x0, 8]
	mov	w0, 1
	str	w0, [sp, 68]
	mov	w0, 10
	str	w0, [sp, 72]
	ldr	x0, [sp, 56]
	str	wzr, [x0, 520]
	ldr	x0, [sp, 56]
	str	wzr, [x0, 524]
	ldr	x0, [sp, 56]
	mov	w1, 404
	str	w1, [x0, 464]
	ldr	x0, [sp, 56]
	ldr	w1, [sp, 72]
	str	w1, [x0, 480]
	str	wzr, [sp, 76]
	b	.L169
.L171:
	ldr	x1, [sp, 56]
	ldrsw	x0, [sp, 76]
	add	x0, x0, 58
	lsl	x0, x0, 3
	add	x0, x1, x0
	mov	x1, 11534336
	str	x1, [x0, 8]
	ldr	w0, [sp, 68]
	cmp	w0, 0
	beq	.L170
	ldr	w1, [sp, 76]
	ldr	w0, [sp, 68]
	cmp	w1, w0
	blt	.L170
	ldr	x1, [sp, 56]
	ldrsw	x0, [sp, 76]
	lsl	x0, x0, 3
	add	x0, x1, x0
	mov	x1, -1
	str	x1, [x0, 8]
.L170:
	ldr	w0, [sp, 76]
	add	w0, w0, 1
	str	w0, [sp, 76]
.L169:
	ldr	w0, [sp, 76]
	cmp	w0, 0
	ble	.L171
	ldr	x1, [sp, 24]
	ldr	x0, [sp, 56]
	bl	ReserveIO
	str	w0, [sp, 52]
	ldr	w0, [sp, 52]
	cmp	w0, 0
	blt	.L183
	ldr	x0, [sp, 56]
	add	x0, x0, 488
	mov	w2, 8
	mov	w1, 0
	bl	FUNC206HAL084
	ldr	x0, [sp, 56]
	add	x0, x0, 496
	mov	w2, 8
	mov	w1, 0
	bl	FUNC206HAL084
	bl	FUNC206HAL088
	mov	x1, x0
	ldr	x0, [sp, 56]
	str	x1, [x0, 504]
	ldr	x0, [sp, 56]
	ldr	x0, [x0, 504]
	cmp	x0, 0
	bne	.L174
	mov	w0, -1
	b	.L168
.L174:
	bl	FUNC206HAL088
	mov	x1, x0
	ldr	x0, [sp, 56]
	str	x1, [x0, 512]
	ldr	x0, [sp, 56]
	ldr	x0, [x0, 512]
	cmp	x0, 0
	bne	.L175
	mov	w0, -1
	b	.L168
.L175:
	ldr	x0, [sp, 56]
	add	x0, x0, 456
	ldr	x2, [sp, 24]
	ldr	x1, [sp, 56]
	bl	ReadCoreConfig
	ldr	x0, [sp, 56]
	add	x0, x0, 456
	ldr	x1, [sp, 24]
	bl	ResetAsic
	bl	FUNC206HAL092
	mov	x1, x0
	ldr	x0, [sp, 56]
	str	x1, [x0, 424]
	ldr	x0, [sp, 56]
	ldr	x0, [x0, 424]
	cmp	x0, 0
	bne	.L176
	mov	w0, -1
	b	.L168
.L176:
	bl	FUNC206HAL097
	mov	x1, x0
	ldr	x0, [sp, 56]
	str	x1, [x0, 432]
	ldr	x0, [sp, 56]
	ldr	x0, [x0, 432]
	cmp	x0, 0
	bne	.L177
	mov	w0, -1
	b	.L168
.L177:
	bl	FUNC206HAL097
	mov	x1, x0
	ldr	x0, [sp, 56]
	str	x1, [x0, 440]
	ldr	x0, [sp, 56]
	ldr	x0, [x0, 440]
	cmp	x0, 0
	bne	.L178
	mov	w0, -1
	b	.L168
.L178:
	bl	FUNC206HAL097
	mov	x1, x0
	ldr	x0, [sp, 56]
	str	x1, [x0, 448]
	ldr	x0, [sp, 56]
	ldr	x0, [x0, 448]
	cmp	x0, 0
	bne	.L179
	mov	w0, -1
	b	.L168
.L179:
	bl	FUNC206HAL072
	mov	x1, x0
	ldr	x0, [sp, 56]
	str	x1, [x0, 536]
	ldr	x0, [sp, 56]
	ldr	x0, [x0, 536]
	cmp	x0, 0
	bne	.L180
	mov	w0, -1
	b	.L168
.L180:
	bl	FUNC206HAL072
	mov	x1, x0
	ldr	x0, [sp, 56]
	str	x1, [x0, 544]
	ldr	x0, [sp, 56]
	ldr	x0, [x0, 544]
	cmp	x0, 0
	bne	.L181
	mov	w0, -1
	b	.L168
.L181:
	adrp	x0, .LC21
	add	x0, x0, :lo12:.LC21
	ldr	x0, [x0]
	bl	printk
	mov	w0, 0
	b	.L168
.L183:
	nop
.L173:
	adrp	x0, .LC23
	add	x0, x0, :lo12:.LC23
	ldr	x0, [x0]
	bl	printk
	ldr	w0, [sp, 52]
.L168:
	ldp	x29, x30, [sp], 80
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE22:
	.size	mwv206dec_init, .-mwv206dec_init
	.align	3
.LC19:
	.xword	.LC18
	.align	3
.LC21:
	.xword	.LC20
	.align	3
.LC23:
	.xword	.LC22
	.align	2
	.global	mwv206dec_free_resources
	.type	mwv206dec_free_resources, %function
mwv206dec_free_resources:
.LFB23:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	mov	x29, sp
	str	x0, [sp, 24]
	ldr	x0, [sp, 24]
	str	x0, [sp, 40]
	ldr	x0, [sp, 40]
	cmp	x0, 0
	beq	.L187
	ldr	x0, [sp, 40]
	ldr	x0, [x0, 424]
	bl	FUNC206HAL093
	ldr	x0, [sp, 40]
	ldr	x0, [x0, 432]
	bl	FUNC206HAL098
	ldr	x0, [sp, 40]
	ldr	x0, [x0, 440]
	bl	FUNC206HAL098
	ldr	x0, [sp, 40]
	ldr	x0, [x0, 448]
	bl	FUNC206HAL098
	ldr	x0, [sp, 40]
	ldr	x0, [x0, 504]
	bl	FUNC206HAL089
	ldr	x0, [sp, 40]
	ldr	x0, [x0, 512]
	bl	FUNC206HAL089
	ldr	x0, [sp, 40]
	ldr	x0, [x0, 536]
	bl	FUNC206HAL074
	ldr	x0, [sp, 40]
	ldr	x0, [x0, 544]
	bl	FUNC206HAL074
	b	.L184
.L187:
	nop
.L184:
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE23:
	.size	mwv206dec_free_resources, .-mwv206dec_free_resources
	.align	2
	.global	mwv206dec_reset
	.type	mwv206dec_reset, %function
mwv206dec_reset:
.LFB24:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	mov	x29, sp
	str	x0, [sp, 24]
	str	x1, [sp, 16]
	ldr	x0, [sp, 24]
	str	x0, [sp, 40]
	ldr	x0, [sp, 40]
	cmp	x0, 0
	beq	.L192
	ldr	x0, [sp, 40]
	add	x0, x0, 456
	str	x0, [sp, 32]
	ldr	x0, [sp, 32]
	cmp	x0, 0
	beq	.L193
	ldr	x1, [sp, 16]
	ldr	x0, [sp, 32]
	bl	ResetAsic
	bl	ReleaseIO
	nop
	b	.L188
.L192:
	nop
	b	.L188
.L193:
	nop
.L188:
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE24:
	.size	mwv206dec_reset, .-mwv206dec_reset
	.align	2
	.global	mwv206dec_uninit
	.type	mwv206dec_uninit, %function
mwv206dec_uninit:
.LFB25:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	x0, [sp, 24]
	str	x1, [sp, 16]
	ldr	x1, [sp, 16]
	ldr	x0, [sp, 24]
	bl	mwv206dec_reset
	ldr	x0, [sp, 24]
	bl	mwv206dec_free_resources
	nop
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE25:
	.size	mwv206dec_uninit, .-mwv206dec_uninit
	.align	2
	.type	CheckHwId, %function
CheckHwId:
.LFB26:
	.cfi_startproc
	stp	x29, x30, [sp, -80]!
	.cfi_def_cfa_offset 80
	.cfi_offset 29, -80
	.cfi_offset 30, -72
	mov	x29, sp
	str	x0, [sp, 40]
	str	x1, [sp, 32]
	str	x2, [sp, 24]
	mov	w0, 5
	str	w0, [sp, 72]
	str	wzr, [sp, 68]
	str	wzr, [sp, 76]
	b	.L196
.L203:
	ldr	x0, [sp, 40]
	ldrsw	x1, [sp, 76]
	add	x1, x1, 2
	ldr	x0, [x0, x1, lsl 3]
	cmp	x0, 0
	beq	.L197
	ldr	x0, [sp, 40]
	ldrsw	x1, [sp, 76]
	add	x1, x1, 2
	ldr	x0, [x0, x1, lsl 3]
	mov	w1, w0
	ldr	x0, [sp, 24]
	bl	V206DEV007
	uxtw	x0, w0
	str	x0, [sp, 56]
	ldr	x0, [sp, 56]
	asr	x0, x0, 16
	and	x0, x0, 65535
	str	x0, [sp, 56]
	b	.L198
.L200:
	adrp	x0, .LC24
	add	x0, x0, :lo12:.LC24
	ldr	x0, [x0]
	ldr	w1, [sp, 72]
	ldr	w0, [x0, x1, lsl 2]
	sxtw	x0, w0
	ldr	x1, [sp, 56]
	cmp	x1, x0
	bne	.L198
	ldr	w0, [sp, 68]
	add	w0, w0, 1
	str	w0, [sp, 68]
	b	.L199
.L198:
	ldr	w0, [sp, 72]
	sub	w1, w0, #1
	str	w1, [sp, 72]
	cmp	w0, 0
	bne	.L200
.L199:
	ldr	w0, [sp, 68]
	cmp	w0, 0
	bne	.L201
	mov	w0, 0
	b	.L202
.L201:
	str	wzr, [sp, 68]
	mov	w0, 5
	str	w0, [sp, 72]
.L197:
	ldr	w0, [sp, 76]
	add	w0, w0, 1
	str	w0, [sp, 76]
.L196:
	ldr	x0, [sp, 40]
	ldr	w0, [x0, 28]
	ldr	w1, [sp, 76]
	cmp	w1, w0
	blt	.L203
	mov	w0, 1
.L202:
	ldp	x29, x30, [sp], 80
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE26:
	.size	CheckHwId, .-CheckHwId
	.align	3
.LC24:
	.xword	DecHwId
	.align	2
	.type	ReserveIO, %function
ReserveIO:
.LFB27:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	x0, [sp, 24]
	str	x1, [sp, 16]
	ldr	x0, [sp, 24]
	mov	x1, 11534336
	str	x1, [x0, 472]
	ldr	x0, [sp, 24]
	ldr	x0, [x0, 472]
	cmp	x0, 0
	bne	.L205
	bl	ReleaseIO
	mov	w0, -16
	b	.L206
.L205:
	ldr	x0, [sp, 24]
	mov	w1, 1
	str	w1, [x0, 484]
	ldr	x0, [sp, 24]
	add	x0, x0, 456
	ldr	x2, [sp, 16]
	ldr	x1, [sp, 24]
	bl	CheckHwId
	cmp	w0, 0
	bne	.L207
	bl	ReleaseIO
	mov	w0, -16
	b	.L206
.L207:
	mov	w0, 0
.L206:
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE27:
	.size	ReserveIO, .-ReserveIO
	.align	2
	.type	ReleaseIO, %function
ReleaseIO:
.LFB28:
	.cfi_startproc
	nop
	ret
	.cfi_endproc
.LFE28:
	.size	ReleaseIO, .-ReleaseIO
	.align	2
	.global	mwv206dec_decoder_isr
	.type	mwv206dec_decoder_isr, %function
mwv206dec_decoder_isr:
.LFB29:
	.cfi_startproc
	stp	x29, x30, [sp, -80]!
	.cfi_def_cfa_offset 80
	.cfi_offset 29, -80
	.cfi_offset 30, -72
	mov	x29, sp
	str	x0, [sp, 24]
	str	x1, [sp, 16]
	str	wzr, [sp, 76]
	mov	x0, 11534336
	str	x0, [sp, 64]
	mov	w0, 1
	str	w0, [sp, 60]
	ldr	x0, [sp, 24]
	str	x0, [sp, 48]
	ldr	x0, [sp, 48]
	ldr	x0, [x0, 424]
	bl	FUNC206HAL094
	str	x0, [sp, 40]
	str	wzr, [sp, 72]
	b	.L211
.L213:
	ldr	x0, [sp, 64]
	add	w0, w0, 4
	mov	w1, w0
	ldr	x0, [sp, 16]
	bl	V206DEV007
	str	w0, [sp, 36]
	ldr	w0, [sp, 36]
	and	w0, w0, 256
	cmp	w0, 0
	beq	.L212
	ldr	w0, [sp, 36]
	and	w0, w0, -257
	str	w0, [sp, 36]
	ldr	x0, [sp, 64]
	add	w0, w0, 4
	ldr	w2, [sp, 36]
	mov	w1, w0
	ldr	x0, [sp, 16]
	bl	V206DEV006
	ldr	x0, [sp, 48]
	ldr	x0, [x0, 536]
	bl	FUNC206HAL075
	ldr	x0, [sp, 48]
	ldr	w1, [x0, 520]
	ldr	w0, [sp, 72]
	mov	w2, 1
	lsl	w0, w2, w0
	orr	w1, w1, w0
	ldr	x0, [sp, 48]
	str	w1, [x0, 520]
	ldr	x0, [sp, 48]
	ldr	x0, [x0, 432]
	bl	FUNC206HAL099
	ldr	w0, [sp, 76]
	add	w0, w0, 1
	str	w0, [sp, 76]
.L212:
	ldr	w0, [sp, 72]
	add	w0, w0, 1
	str	w0, [sp, 72]
.L211:
	ldr	w1, [sp, 72]
	ldr	w0, [sp, 60]
	cmp	w1, w0
	blt	.L213
	ldr	x0, [sp, 64]
	add	w0, w0, 240
	mov	w1, w0
	ldr	x0, [sp, 16]
	bl	V206DEV007
	str	w0, [sp, 32]
	ldr	w0, [sp, 32]
	and	w0, w0, 256
	cmp	w0, 0
	beq	.L214
	ldr	w0, [sp, 32]
	and	w0, w0, -257
	str	w0, [sp, 32]
	ldr	x0, [sp, 64]
	add	w0, w0, 240
	ldr	w2, [sp, 32]
	mov	w1, w0
	ldr	x0, [sp, 16]
	bl	V206DEV006
	ldr	x0, [sp, 48]
	ldr	x0, [x0, 536]
	bl	FUNC206HAL075
	ldr	x0, [sp, 48]
	ldr	w0, [x0, 524]
	orr	w1, w0, 1
	ldr	x0, [sp, 48]
	str	w1, [x0, 524]
	ldr	x0, [sp, 48]
	ldr	x0, [x0, 440]
	bl	FUNC206HAL099
	ldr	w0, [sp, 76]
	add	w0, w0, 1
	str	w0, [sp, 76]
.L214:
	ldr	x0, [sp, 48]
	ldr	x0, [x0, 424]
	ldr	x1, [sp, 40]
	bl	FUNC206HAL095
	ldr	w0, [sp, 76]
	cmp	w0, 0
	cset	w0, ne
	and	w0, w0, 255
	ldp	x29, x30, [sp], 80
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE29:
	.size	mwv206dec_decoder_isr, .-mwv206dec_decoder_isr
	.align	2
	.type	ResetAsic, %function
ResetAsic:
.LFB30:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	mov	x29, sp
	str	x0, [sp, 24]
	str	x1, [sp, 16]
	str	wzr, [sp, 40]
	b	.L217
.L221:
	ldr	x0, [sp, 24]
	ldrsw	x1, [sp, 40]
	add	x1, x1, 2
	ldr	x0, [x0, x1, lsl 3]
	add	w0, w0, 4
	mov	w1, w0
	ldr	x0, [sp, 16]
	bl	V206DEV007
	str	w0, [sp, 36]
	ldr	w0, [sp, 36]
	and	w0, w0, 1
	cmp	w0, 0
	beq	.L218
	mov	w0, 48
	str	w0, [sp, 36]
	ldr	x0, [sp, 24]
	ldrsw	x1, [sp, 40]
	add	x1, x1, 2
	ldr	x0, [x0, x1, lsl 3]
	add	w0, w0, 4
	ldr	w2, [sp, 36]
	mov	w1, w0
	ldr	x0, [sp, 16]
	bl	V206DEV006
.L218:
	ldr	x0, [sp, 24]
	ldrsw	x1, [sp, 40]
	add	x1, x1, 2
	ldr	x0, [x0, x1, lsl 3]
	add	w0, w0, 240
	mov	w2, 0
	mov	w1, w0
	ldr	x0, [sp, 16]
	bl	V206DEV006
	mov	w0, 4
	str	w0, [sp, 44]
	b	.L219
.L220:
	ldr	x0, [sp, 24]
	ldrsw	x1, [sp, 40]
	add	x1, x1, 2
	ldr	x0, [x0, x1, lsl 3]
	mov	w1, w0
	ldr	w0, [sp, 44]
	add	w0, w1, w0
	mov	w2, 0
	mov	w1, w0
	ldr	x0, [sp, 16]
	bl	V206DEV006
	ldr	w0, [sp, 44]
	add	w0, w0, 4
	str	w0, [sp, 44]
.L219:
	ldr	x0, [sp, 24]
	ldr	w0, [x0, 8]
	ldr	w1, [sp, 44]
	cmp	w1, w0
	bcc	.L220
	ldr	w0, [sp, 40]
	add	w0, w0, 1
	str	w0, [sp, 40]
.L217:
	ldr	x0, [sp, 24]
	ldr	w0, [x0, 28]
	ldr	w1, [sp, 40]
	cmp	w1, w0
	blt	.L221
	nop
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE30:
	.size	ResetAsic, .-ResetAsic
	.section	.note.GNU-stack,"",@progbits
