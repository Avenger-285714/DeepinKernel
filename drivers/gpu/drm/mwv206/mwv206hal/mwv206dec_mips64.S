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
	.section .mdebug.abi64
	.previous
	.nan	legacy
	.module	fp=64
	.module	oddspreg
	.text
	.rdata
	.align	3
	.type	DecHwId, @object
	.size	DecHwId, 20
DecHwId:
	.word	33168
	.word	33136
	.word	37232
	.word	37264
	.word	26417
	.text
	.align	2
	.set	nomips16
	.set	nomicromips
	.ent	ReadCoreConfig
	.type	ReadCoreConfig, @function
ReadCoreConfig:
	.frame	$fp,64,$31		# vars= 48, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-64
	sd	$31,56($sp)
	sd	$fp,48($sp)
	move	$fp,$sp
	sd	$4,16($fp)
	sd	$5,24($fp)
	sd	$6,32($fp)
	ld	$2,24($fp)
	daddiu	$2,$2,528
	li	$6,4			# 0x4
	move	$5,$0
	move	$4,$2
	lui	$2,%highest(FUNC206HAL084)
	daddiu	$2,$2,%higher(FUNC206HAL084)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL084)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL084)
	jalr	$2
	nop

	sw	$0,0($fp)
	b	.L2
	nop

.L23:
	ld	$3,16($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,2
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	sll	$2,$2,0
	addiu	$2,$2,200
	move	$5,$2
	ld	$4,32($fp)
	lui	$2,%highest(V206DEV007)
	daddiu	$2,$2,%higher(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV007)
	jalr	$2
	nop

	sw	$2,4($fp)
	lw	$2,4($fp)
	srl	$2,$2,24
	andi	$2,$2,0x3
	sw	$2,8($fp)
	ld	$3,24($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,132
	dsll	$2,$2,2
	daddu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,8($fp)
	beq	$2,$0,.L3
	nop

	li	$2,2			# 0x2
	b	.L4
	nop

.L3:
	move	$2,$0
.L4:
	or	$2,$2,$3
	move	$3,$2
	ld	$4,24($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,132
	dsll	$2,$2,2
	daddu	$2,$4,$2
	sw	$3,0($2)
	lw	$2,4($fp)
	srl	$2,$2,28
	andi	$2,$2,0x1
	sw	$2,8($fp)
	ld	$3,24($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,132
	dsll	$2,$2,2
	daddu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,8($fp)
	beq	$2,$0,.L5
	nop

	li	$2,8			# 0x8
	b	.L6
	nop

.L5:
	move	$2,$0
.L6:
	or	$2,$2,$3
	move	$3,$2
	ld	$4,24($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,132
	dsll	$2,$2,2
	daddu	$2,$4,$2
	sw	$3,0($2)
	lw	$2,4($fp)
	srl	$2,$2,26
	andi	$2,$2,0x3
	sw	$2,8($fp)
	ld	$3,24($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,132
	dsll	$2,$2,2
	daddu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,8($fp)
	beq	$2,$0,.L7
	nop

	li	$2,4			# 0x4
	b	.L8
	nop

.L7:
	move	$2,$0
.L8:
	or	$2,$2,$3
	move	$3,$2
	ld	$4,24($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,132
	dsll	$2,$2,2
	daddu	$2,$4,$2
	sw	$3,0($2)
	lw	$2,4($fp)
	srl	$2,$2,29
	andi	$2,$2,0x3
	sw	$2,8($fp)
	ld	$3,24($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,132
	dsll	$2,$2,2
	daddu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,8($fp)
	beq	$2,$0,.L9
	nop

	li	$2,32			# 0x20
	b	.L10
	nop

.L9:
	move	$2,$0
.L10:
	or	$2,$2,$3
	move	$3,$2
	ld	$4,24($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,132
	dsll	$2,$2,2
	daddu	$2,$4,$2
	sw	$3,0($2)
	lw	$2,4($fp)
	srl	$2,$2,31
	sw	$2,8($fp)
	ld	$3,24($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,132
	dsll	$2,$2,2
	daddu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,8($fp)
	beq	$2,$0,.L11
	nop

	li	$2,64			# 0x40
	b	.L12
	nop

.L11:
	move	$2,$0
.L12:
	or	$2,$2,$3
	move	$3,$2
	ld	$4,24($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,132
	dsll	$2,$2,2
	daddu	$2,$4,$2
	sw	$3,0($2)
	lw	$2,4($fp)
	srl	$2,$2,23
	andi	$2,$2,0x1
	sw	$2,8($fp)
	ld	$3,24($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,132
	dsll	$2,$2,2
	daddu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,8($fp)
	beq	$2,$0,.L13
	nop

	li	$2,128			# 0x80
	b	.L14
	nop

.L13:
	move	$2,$0
.L14:
	or	$2,$2,$3
	move	$3,$2
	ld	$4,24($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,132
	dsll	$2,$2,2
	daddu	$2,$4,$2
	sw	$3,0($2)
	ld	$3,16($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,2
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	sll	$2,$2,0
	addiu	$2,$2,216
	move	$5,$2
	ld	$4,32($fp)
	lui	$2,%highest(V206DEV007)
	daddiu	$2,$2,%higher(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV007)
	jalr	$2
	nop

	sw	$2,4($fp)
	li	$2,25690112			# 0x1880000
	sw	$2,12($fp)
	lw	$3,4($fp)
	lw	$2,12($fp)
	and	$2,$3,$2
	sw	$2,8($fp)
	ld	$3,24($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,132
	dsll	$2,$2,2
	daddu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,8($fp)
	beq	$2,$0,.L15
	nop

	li	$2,1024			# 0x400
	b	.L16
	nop

.L15:
	move	$2,$0
.L16:
	or	$2,$2,$3
	move	$3,$2
	ld	$4,24($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,132
	dsll	$2,$2,2
	daddu	$2,$4,$2
	sw	$3,0($2)
	lw	$2,4($fp)
	srl	$2,$2,22
	andi	$2,$2,0x1
	sw	$2,8($fp)
	ld	$3,24($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,132
	dsll	$2,$2,2
	daddu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,8($fp)
	beq	$2,$0,.L17
	nop

	li	$2,256			# 0x100
	b	.L18
	nop

.L17:
	move	$2,$0
.L18:
	or	$2,$2,$3
	move	$3,$2
	ld	$4,24($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,132
	dsll	$2,$2,2
	daddu	$2,$4,$2
	sw	$3,0($2)
	lw	$2,4($fp)
	srl	$2,$2,26
	andi	$2,$2,0x3
	sw	$2,8($fp)
	ld	$3,24($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,132
	dsll	$2,$2,2
	daddu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,8($fp)
	beq	$2,$0,.L19
	nop

	li	$2,512			# 0x200
	b	.L20
	nop

.L19:
	move	$2,$0
.L20:
	or	$2,$2,$3
	move	$3,$2
	ld	$4,24($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,132
	dsll	$2,$2,2
	daddu	$2,$4,$2
	sw	$3,0($2)
	ld	$3,16($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,2
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	sll	$2,$2,0
	addiu	$2,$2,400
	move	$5,$2
	ld	$4,32($fp)
	lui	$2,%highest(V206DEV007)
	daddiu	$2,$2,%higher(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV007)
	jalr	$2
	nop

	sw	$2,4($fp)
	lw	$2,4($fp)
	srl	$2,$2,16
	andi	$2,$2,0x1
	sw	$2,8($fp)
	ld	$3,24($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,132
	dsll	$2,$2,2
	daddu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,8($fp)
	beq	$2,$0,.L21
	nop

	li	$2,16			# 0x10
	b	.L22
	nop

.L21:
	move	$2,$0
.L22:
	or	$2,$2,$3
	move	$3,$2
	ld	$4,24($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,132
	dsll	$2,$2,2
	daddu	$2,$4,$2
	sw	$3,0($2)
	lw	$2,0($fp)
	addiu	$2,$2,1
	sw	$2,0($fp)
.L2:
	ld	$2,16($fp)
	lw	$2,28($2)
	lw	$3,0($fp)
	slt	$2,$3,$2
	bne	$2,$0,.L23
	nop

	nop
	move	$sp,$fp
	ld	$31,56($sp)
	ld	$fp,48($sp)
	daddiu	$sp,$sp,64
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	ReadCoreConfig
	.size	ReadCoreConfig, .-ReadCoreConfig
	.align	2
	.set	nomips16
	.set	nomicromips
	.ent	CoreHasFormat
	.type	CoreHasFormat, @function
CoreHasFormat:
	.frame	$fp,32,$31		# vars= 16, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-32
	sd	$fp,24($sp)
	move	$fp,$sp
	sd	$4,0($fp)
	move	$3,$5
	move	$2,$6
	sll	$3,$3,0
	sw	$3,8($fp)
	sll	$2,$2,0
	sw	$2,12($fp)
	lw	$2,8($fp)
	dsll	$2,$2,2
	ld	$3,0($fp)
	daddu	$2,$3,$2
	lw	$3,0($2)
	li	$4,1			# 0x1
	lw	$2,12($fp)
	sll	$2,$4,$2
	move	$4,$2
	mtlo	$4
	mflo	$2
	and	$2,$3,$2
	sltu	$2,$0,$2
	andi	$2,$2,0x00ff
	move	$sp,$fp
	ld	$fp,24($sp)
	daddiu	$sp,$sp,32
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	CoreHasFormat
	.size	CoreHasFormat, .-CoreHasFormat
	.align	2
	.globl	GetDecCore
	.set	nomips16
	.set	nomicromips
	.ent	GetDecCore
	.type	GetDecCore, @function
GetDecCore:
	.frame	$fp,64,$31		# vars= 48, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-64
	sd	$31,56($sp)
	sd	$fp,48($sp)
	move	$fp,$sp
	sd	$4,16($fp)
	sd	$5,24($fp)
	sd	$6,32($fp)
	sd	$7,40($fp)
	sw	$0,0($fp)
	ld	$2,40($fp)
	ld	$2,424($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL094)
	daddiu	$2,$2,%higher(FUNC206HAL094)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL094)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL094)
	jalr	$2
	nop

	sd	$2,8($fp)
	ld	$3,40($fp)
	ld	$2,16($fp)
	daddiu	$2,$2,60
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,8($2)
	bne	$2,$0,.L27
	nop

	ld	$3,40($fp)
	ld	$2,16($fp)
	daddiu	$2,$2,60
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$3,32($fp)
	sd	$3,8($2)
	li	$2,1			# 0x1
	sw	$2,0($fp)
.L27:
	ld	$2,40($fp)
	ld	$2,424($2)
	ld	$5,8($fp)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL095)
	daddiu	$2,$2,%higher(FUNC206HAL095)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL095)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL095)
	jalr	$2
	nop

	lw	$2,0($fp)
	move	$sp,$fp
	ld	$31,56($sp)
	ld	$fp,48($sp)
	daddiu	$sp,$sp,64
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	GetDecCore
	.size	GetDecCore, .-GetDecCore
	.align	2
	.globl	GetDecCoreAny
	.set	nomips16
	.set	nomicromips
	.ent	GetDecCoreAny
	.type	GetDecCoreAny, @function
GetDecCoreAny:
	.frame	$fp,80,$31		# vars= 64, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-80
	sd	$31,72($sp)
	sd	$fp,64($sp)
	move	$fp,$sp
	sd	$4,16($fp)
	sd	$5,24($fp)
	sd	$6,32($fp)
	sd	$7,40($fp)
	sd	$8,48($fp)
	sw	$0,0($fp)
	ld	$2,16($fp)
	li	$3,-1			# 0xffffffffffffffff
	sd	$3,0($2)
	sd	$0,8($fp)
	b	.L30
	nop

.L33:
	ld	$2,48($fp)
	daddiu	$2,$2,528
	lw	$3,8($fp)
	lw	$4,40($fp)
	move	$6,$4
	move	$5,$3
	move	$4,$2
	lui	$2,%highest(CoreHasFormat)
	daddiu	$2,$2,%higher(CoreHasFormat)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(CoreHasFormat)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(CoreHasFormat)
	jalr	$2
	nop

	beq	$2,$0,.L31
	nop

	ld	$7,48($fp)
	ld	$6,32($fp)
	ld	$5,24($fp)
	ld	$4,8($fp)
	lui	$2,%highest(GetDecCore)
	daddiu	$2,$2,%higher(GetDecCore)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(GetDecCore)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(GetDecCore)
	jalr	$2
	nop

	beq	$2,$0,.L31
	nop

	li	$2,1			# 0x1
	sw	$2,0($fp)
	ld	$2,16($fp)
	ld	$3,8($fp)
	sd	$3,0($2)
	b	.L32
	nop

.L31:
	ld	$2,8($fp)
	daddiu	$2,$2,1
	sd	$2,8($fp)
.L30:
	ld	$2,24($fp)
	lw	$2,28($2)
	move	$3,$2
	ld	$2,8($fp)
	slt	$2,$2,$3
	bne	$2,$0,.L33
	nop

.L32:
	lw	$2,0($fp)
	move	$sp,$fp
	ld	$31,72($sp)
	ld	$fp,64($sp)
	daddiu	$sp,$sp,80
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	GetDecCoreAny
	.size	GetDecCoreAny, .-GetDecCoreAny
	.align	2
	.globl	ReserveDecoder
	.set	nomips16
	.set	nomicromips
	.ent	ReserveDecoder
	.type	ReserveDecoder, @function
ReserveDecoder:
	.frame	$fp,80,$31		# vars= 48, regs= 3/0, args= 0, gp= 0
	.mask	0xc0010000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-80
	sd	$31,72($sp)
	sd	$fp,64($sp)
	sd	$16,56($sp)
	move	$fp,$sp
	sd	$4,16($fp)
	sd	$5,24($fp)
	sd	$6,32($fp)
	sd	$7,40($fp)
	sd	$0,0($fp)
	ld	$2,40($fp)
	ld	$2,504($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL090)
	daddiu	$2,$2,%higher(FUNC206HAL090)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL090)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL090)
	jalr	$2
	nop

	beq	$2,$0,.L36
	nop

	li	$2,-512			# 0xfffffffffffffe00
	b	.L39
	nop

.L36:
	ld	$2,40($fp)
	ld	$16,448($2)
	ld	$8,40($fp)
	ld	$7,32($fp)
	ld	$6,24($fp)
	ld	$5,16($fp)
	move	$4,$fp
	lui	$2,%highest(GetDecCoreAny)
	daddiu	$2,$2,%higher(GetDecCoreAny)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(GetDecCoreAny)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(GetDecCoreAny)
	jalr	$2
	nop

	sltu	$2,$0,$2
	andi	$2,$2,0x00ff
	move	$5,$2
	move	$4,$16
	lui	$2,%highest(FUNC206HAL096)
	daddiu	$2,$2,%higher(FUNC206HAL096)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL096)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL096)
	jalr	$2
	nop

	beq	$2,$0,.L38
	nop

	ld	$2,40($fp)
	ld	$2,504($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL091)
	daddiu	$2,$2,%higher(FUNC206HAL091)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL091)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL091)
	jalr	$2
	nop

	li	$2,-512			# 0xfffffffffffffe00
	b	.L39
	nop

.L38:
	ld	$2,0($fp)
.L39:
	move	$sp,$fp
	ld	$31,72($sp)
	ld	$fp,64($sp)
	ld	$16,56($sp)
	daddiu	$sp,$sp,80
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	ReserveDecoder
	.size	ReserveDecoder, .-ReserveDecoder
	.rdata
	.align	3
.LC0:
	.ascii	"\0011decoder: Killed, timeout\012\000"
	.text
	.align	2
	.globl	ReleaseDecoder
	.set	nomips16
	.set	nomicromips
	.ent	ReleaseDecoder
	.type	ReleaseDecoder, @function
ReleaseDecoder:
	.frame	$fp,64,$31		# vars= 48, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-64
	sd	$31,56($sp)
	sd	$fp,48($sp)
	move	$fp,$sp
	sd	$4,16($fp)
	sd	$5,24($fp)
	sd	$6,32($fp)
	sd	$7,40($fp)
	sw	$0,4($fp)
	ld	$3,16($fp)
	ld	$2,24($fp)
	daddiu	$2,$2,2
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	sll	$2,$2,0
	addiu	$2,$2,4
	move	$5,$2
	ld	$4,40($fp)
	lui	$2,%highest(V206DEV007)
	daddiu	$2,$2,%higher(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV007)
	jalr	$2
	nop

	sw	$2,0($fp)
	lw	$2,0($fp)
	andi	$2,$2,0x1
	beq	$2,$0,.L41
	nop

	b	.L42
	nop

.L44:
	ld	$3,16($fp)
	ld	$2,24($fp)
	daddiu	$2,$2,2
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	sll	$2,$2,0
	addiu	$2,$2,4
	move	$5,$2
	ld	$4,40($fp)
	lui	$2,%highest(V206DEV007)
	daddiu	$2,$2,%higher(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV007)
	jalr	$2
	nop

	sw	$2,0($fp)
	lw	$2,4($fp)
	addiu	$2,$2,1
	sw	$2,4($fp)
	lw	$3,4($fp)
	li	$2,458752			# 0x70000
	ori	$2,$2,0xa121
	sltu	$2,$3,$2
	bne	$2,$0,.L42
	nop

	lui	$2,%highest(.LC0)
	daddiu	$2,$2,%higher(.LC0)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(.LC0)
	dsll	$2,$2,16
	daddiu	$4,$2,%lo(.LC0)
	lui	$2,%highest(printk)
	daddiu	$2,$2,%higher(printk)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(printk)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(printk)
	jalr	$2
	nop

	b	.L43
	nop

.L42:
	lw	$2,0($fp)
	andi	$2,$2,0x1
	bne	$2,$0,.L44
	nop

.L43:
	ld	$3,16($fp)
	ld	$2,24($fp)
	daddiu	$2,$2,2
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	sll	$2,$2,0
	addiu	$2,$2,4
	move	$6,$0
	move	$5,$2
	ld	$4,40($fp)
	lui	$2,%highest(V206DEV006)
	daddiu	$2,$2,%higher(V206DEV006)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV006)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV006)
	jalr	$2
	nop

.L41:
	ld	$2,32($fp)
	ld	$2,424($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL094)
	daddiu	$2,$2,%higher(FUNC206HAL094)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL094)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL094)
	jalr	$2
	nop

	sd	$2,8($fp)
	ld	$3,32($fp)
	ld	$2,24($fp)
	daddiu	$2,$2,60
	dsll	$2,$2,3
	daddu	$2,$3,$2
	sd	$0,8($2)
	ld	$2,32($fp)
	ld	$2,424($2)
	ld	$5,8($fp)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL095)
	daddiu	$2,$2,%higher(FUNC206HAL095)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL095)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL095)
	jalr	$2
	nop

	ld	$2,32($fp)
	ld	$2,504($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL091)
	daddiu	$2,$2,%higher(FUNC206HAL091)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL091)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL091)
	jalr	$2
	nop

	ld	$2,32($fp)
	ld	$2,448($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL099)
	daddiu	$2,$2,%higher(FUNC206HAL099)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL099)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL099)
	jalr	$2
	nop

	nop
	move	$sp,$fp
	ld	$31,56($sp)
	ld	$fp,48($sp)
	daddiu	$sp,$sp,64
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	ReleaseDecoder
	.size	ReleaseDecoder, .-ReleaseDecoder
	.align	2
	.globl	ReservePostProcessor
	.set	nomips16
	.set	nomicromips
	.ent	ReservePostProcessor
	.type	ReservePostProcessor, @function
ReservePostProcessor:
	.frame	$fp,64,$31		# vars= 48, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-64
	sd	$31,56($sp)
	sd	$fp,48($sp)
	move	$fp,$sp
	sd	$4,16($fp)
	sd	$5,24($fp)
	sd	$6,32($fp)
	sd	$0,0($fp)
	ld	$2,32($fp)
	ld	$2,512($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL090)
	daddiu	$2,$2,%higher(FUNC206HAL090)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL090)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL090)
	jalr	$2
	nop

	beq	$2,$0,.L46
	nop

	li	$2,-512			# 0xfffffffffffffe00
	b	.L47
	nop

.L46:
	ld	$2,32($fp)
	ld	$2,424($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL094)
	daddiu	$2,$2,%higher(FUNC206HAL094)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL094)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL094)
	jalr	$2
	nop

	sd	$2,8($fp)
	ld	$3,32($fp)
	ld	$2,0($fp)
	daddiu	$2,$2,62
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$3,24($fp)
	sd	$3,0($2)
	ld	$2,32($fp)
	ld	$2,424($2)
	ld	$5,8($fp)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL095)
	daddiu	$2,$2,%higher(FUNC206HAL095)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL095)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL095)
	jalr	$2
	nop

	ld	$2,0($fp)
.L47:
	move	$sp,$fp
	ld	$31,56($sp)
	ld	$fp,48($sp)
	daddiu	$sp,$sp,64
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	ReservePostProcessor
	.size	ReservePostProcessor, .-ReservePostProcessor
	.rdata
	.align	3
.LC1:
	.ascii	"\0011PP: Wait for hardware finish, timeout(0x%x)\012\000"
	.text
	.align	2
	.set	nomips16
	.set	nomicromips
	.ent	WaitForPPFinish
	.type	WaitForPPFinish, @function
WaitForPPFinish:
	.frame	$fp,64,$31		# vars= 48, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-64
	sd	$31,56($sp)
	sd	$fp,48($sp)
	move	$fp,$sp
	sd	$4,16($fp)
	sd	$5,24($fp)
	sd	$6,32($fp)
	sw	$0,0($fp)
	ld	$3,16($fp)
	ld	$2,24($fp)
	daddiu	$2,$2,2
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	sll	$2,$2,0
	addiu	$2,$2,240
	move	$5,$2
	ld	$4,32($fp)
	lui	$2,%highest(V206DEV007)
	daddiu	$2,$2,%higher(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV007)
	jalr	$2
	nop

	sw	$2,4($fp)
	b	.L49
	nop

.L51:
	ld	$3,16($fp)
	ld	$2,24($fp)
	daddiu	$2,$2,2
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	sll	$2,$2,0
	addiu	$2,$2,240
	move	$5,$2
	ld	$4,32($fp)
	lui	$2,%highest(V206DEV007)
	daddiu	$2,$2,%higher(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV007)
	jalr	$2
	nop

	sw	$2,4($fp)
	lw	$2,0($fp)
	addiu	$2,$2,1
	sw	$2,0($fp)
	lw	$3,0($fp)
	li	$2,458752			# 0x70000
	ori	$2,$2,0xa121
	sltu	$2,$3,$2
	bne	$2,$0,.L49
	nop

	lw	$2,4($fp)
	move	$5,$2
	lui	$2,%highest(.LC1)
	daddiu	$2,$2,%higher(.LC1)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(.LC1)
	dsll	$2,$2,16
	daddiu	$4,$2,%lo(.LC1)
	lui	$2,%highest(printk)
	daddiu	$2,$2,%higher(printk)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(printk)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(printk)
	jalr	$2
	nop

	b	.L50
	nop

.L49:
	lw	$2,4($fp)
	andi	$2,$2,0x1
	bne	$2,$0,.L51
	nop

.L50:
	nop
	move	$sp,$fp
	ld	$31,56($sp)
	ld	$fp,48($sp)
	daddiu	$sp,$sp,64
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	WaitForPPFinish
	.size	WaitForPPFinish, .-WaitForPPFinish
	.align	2
	.globl	ReleasePostProcessor
	.set	nomips16
	.set	nomicromips
	.ent	ReleasePostProcessor
	.type	ReleasePostProcessor, @function
ReleasePostProcessor:
	.frame	$fp,64,$31		# vars= 48, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-64
	sd	$31,56($sp)
	sd	$fp,48($sp)
	move	$fp,$sp
	sd	$4,16($fp)
	sd	$5,24($fp)
	sd	$6,32($fp)
	sd	$7,40($fp)
	ld	$3,16($fp)
	ld	$2,24($fp)
	daddiu	$2,$2,2
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	sll	$2,$2,0
	addiu	$2,$2,240
	move	$5,$2
	ld	$4,40($fp)
	lui	$2,%highest(V206DEV007)
	daddiu	$2,$2,%higher(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV007)
	jalr	$2
	nop

	sw	$2,0($fp)
	lw	$2,0($fp)
	andi	$2,$2,0x1
	beq	$2,$0,.L53
	nop

	ld	$6,40($fp)
	ld	$5,24($fp)
	ld	$4,16($fp)
	lui	$2,%highest(WaitForPPFinish)
	daddiu	$2,$2,%higher(WaitForPPFinish)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(WaitForPPFinish)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(WaitForPPFinish)
	jalr	$2
	nop

	lw	$2,0($fp)
	ori	$2,$2,0x10
	sw	$2,0($fp)
	lw	$3,0($fp)
	li	$2,-2			# 0xfffffffffffffffe
	and	$2,$3,$2
	sw	$2,0($fp)
	ld	$3,16($fp)
	ld	$2,24($fp)
	daddiu	$2,$2,2
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	sll	$2,$2,0
	addiu	$2,$2,240
	li	$6,16			# 0x10
	move	$5,$2
	ld	$4,40($fp)
	lui	$2,%highest(V206DEV006)
	daddiu	$2,$2,%higher(V206DEV006)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV006)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV006)
	jalr	$2
	nop

.L53:
	ld	$2,32($fp)
	ld	$2,424($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL094)
	daddiu	$2,$2,%higher(FUNC206HAL094)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL094)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL094)
	jalr	$2
	nop

	sd	$2,8($fp)
	ld	$3,32($fp)
	ld	$2,24($fp)
	daddiu	$2,$2,62
	dsll	$2,$2,3
	daddu	$2,$3,$2
	sd	$0,0($2)
	ld	$2,32($fp)
	ld	$2,424($2)
	ld	$5,8($fp)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL095)
	daddiu	$2,$2,%higher(FUNC206HAL095)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL095)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL095)
	jalr	$2
	nop

	ld	$2,32($fp)
	ld	$2,512($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL091)
	daddiu	$2,$2,%higher(FUNC206HAL091)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL091)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL091)
	jalr	$2
	nop

	nop
	move	$sp,$fp
	ld	$31,56($sp)
	ld	$fp,48($sp)
	daddiu	$sp,$sp,64
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	ReleasePostProcessor
	.size	ReleasePostProcessor, .-ReleasePostProcessor
	.align	2
	.globl	ReserveDecPp
	.set	nomips16
	.set	nomicromips
	.ent	ReserveDecPp
	.type	ReserveDecPp, @function
ReserveDecPp:
	.frame	$fp,96,$31		# vars= 64, regs= 3/0, args= 0, gp= 0
	.mask	0xc0010000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-96
	sd	$31,88($sp)
	sd	$fp,80($sp)
	sd	$16,72($sp)
	move	$fp,$sp
	sd	$4,16($fp)
	sd	$5,24($fp)
	sd	$6,32($fp)
	sd	$7,40($fp)
	sd	$8,48($fp)
	sd	$0,0($fp)
	ld	$2,40($fp)
	daddiu	$2,$2,528
	lw	$3,0($fp)
	lw	$4,32($fp)
	move	$6,$4
	move	$5,$3
	move	$4,$2
	lui	$2,%highest(CoreHasFormat)
	daddiu	$2,$2,%higher(CoreHasFormat)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(CoreHasFormat)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(CoreHasFormat)
	jalr	$2
	nop

	bne	$2,$0,.L55
	nop

	li	$2,-14			# 0xfffffffffffffff2
	b	.L56
	nop

.L55:
	ld	$2,40($fp)
	daddiu	$2,$2,528
	lw	$3,0($fp)
	li	$6,4			# 0x4
	move	$5,$3
	move	$4,$2
	lui	$2,%highest(CoreHasFormat)
	daddiu	$2,$2,%higher(CoreHasFormat)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(CoreHasFormat)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(CoreHasFormat)
	jalr	$2
	nop

	bne	$2,$0,.L57
	nop

	li	$2,-14			# 0xfffffffffffffff2
	b	.L56
	nop

.L57:
	ld	$2,40($fp)
	ld	$2,504($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL090)
	daddiu	$2,$2,%higher(FUNC206HAL090)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL090)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL090)
	jalr	$2
	nop

	beq	$2,$0,.L58
	nop

	li	$2,-512			# 0xfffffffffffffe00
	b	.L56
	nop

.L58:
	ld	$2,40($fp)
	ld	$16,448($2)
	ld	$7,40($fp)
	ld	$6,24($fp)
	ld	$5,16($fp)
	ld	$4,0($fp)
	lui	$2,%highest(GetDecCore)
	daddiu	$2,$2,%higher(GetDecCore)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(GetDecCore)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(GetDecCore)
	jalr	$2
	nop

	sltu	$2,$0,$2
	andi	$2,$2,0x00ff
	move	$5,$2
	move	$4,$16
	lui	$2,%highest(FUNC206HAL096)
	daddiu	$2,$2,%higher(FUNC206HAL096)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL096)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL096)
	jalr	$2
	nop

	beq	$2,$0,.L59
	nop

	ld	$2,40($fp)
	ld	$2,504($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL091)
	daddiu	$2,$2,%higher(FUNC206HAL091)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL091)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL091)
	jalr	$2
	nop

	li	$2,-512			# 0xfffffffffffffe00
	b	.L56
	nop

.L59:
	ld	$2,40($fp)
	ld	$2,512($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL090)
	daddiu	$2,$2,%higher(FUNC206HAL090)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL090)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL090)
	jalr	$2
	nop

	beq	$2,$0,.L60
	nop

	ld	$7,48($fp)
	ld	$6,40($fp)
	ld	$5,0($fp)
	ld	$4,16($fp)
	lui	$2,%highest(ReleaseDecoder)
	daddiu	$2,$2,%higher(ReleaseDecoder)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(ReleaseDecoder)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(ReleaseDecoder)
	jalr	$2
	nop

	li	$2,-512			# 0xfffffffffffffe00
	b	.L56
	nop

.L60:
	ld	$2,40($fp)
	ld	$2,424($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL094)
	daddiu	$2,$2,%higher(FUNC206HAL094)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL094)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL094)
	jalr	$2
	nop

	sd	$2,8($fp)
	ld	$3,40($fp)
	ld	$2,0($fp)
	daddiu	$2,$2,62
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$3,24($fp)
	sd	$3,0($2)
	ld	$2,40($fp)
	ld	$2,424($2)
	ld	$5,8($fp)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL095)
	daddiu	$2,$2,%higher(FUNC206HAL095)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL095)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL095)
	jalr	$2
	nop

	ld	$2,0($fp)
.L56:
	move	$sp,$fp
	ld	$31,88($sp)
	ld	$fp,80($sp)
	ld	$16,72($sp)
	daddiu	$sp,$sp,96
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	ReserveDecPp
	.size	ReserveDecPp, .-ReserveDecPp
	.align	2
	.globl	DecFlushRegs
	.set	nomips16
	.set	nomicromips
	.ent	DecFlushRegs
	.type	DecFlushRegs, @function
DecFlushRegs:
	.frame	$fp,80,$31		# vars= 64, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-80
	sd	$31,72($sp)
	sd	$fp,64($sp)
	move	$fp,$sp
	sd	$4,32($fp)
	sd	$5,40($fp)
	sd	$6,48($fp)
	sd	$7,56($fp)
	sd	$0,8($fp)
	ld	$2,40($fp)
	lw	$2,0($2)
	sw	$2,16($fp)
	lwu	$3,16($fp)
	move	$2,$3
	dsll	$2,$2,1
	daddu	$2,$2,$3
	dsll	$2,$2,3
	daddu	$2,$2,$3
	dsll	$2,$2,2
	daddu	$2,$2,$3
	dsll	$2,$2,2
	daddiu	$2,$2,16
	ld	$3,48($fp)
	daddu	$3,$3,$2
	ld	$2,40($fp)
	ld	$2,8($2)
	li	$6,240			# 0xf0
	move	$5,$2
	move	$4,$3
	lui	$2,%highest(FUNC206HAL077)
	daddiu	$2,$2,%higher(FUNC206HAL077)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL077)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL077)
	jalr	$2
	nop

	sd	$2,8($fp)
	ld	$2,8($fp)
	beq	$2,$0,.L62
	nop

	li	$2,-14			# 0xfffffffffffffff2
	b	.L63
	nop

.L62:
	li	$2,2			# 0x2
	sd	$2,0($fp)
	b	.L64
	nop

.L65:
	ld	$3,32($fp)
	lwu	$2,16($fp)
	daddiu	$2,$2,2
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	ld	$3,0($fp)
	dsll	$3,$3,2
	daddu	$2,$2,$3
	sll	$2,$2,0
	move	$5,$2
	ld	$4,48($fp)
	lwu	$3,16($fp)
	move	$2,$3
	dsll	$2,$2,1
	daddu	$2,$2,$3
	dsll	$2,$2,3
	daddu	$2,$2,$3
	dsll	$2,$2,2
	daddu	$2,$2,$3
	ld	$3,0($fp)
	daddu	$2,$2,$3
	daddiu	$2,$2,4
	dsll	$2,$2,2
	daddu	$2,$4,$2
	lw	$2,0($2)
	move	$6,$2
	ld	$4,56($fp)
	lui	$2,%highest(V206DEV006)
	daddiu	$2,$2,%higher(V206DEV006)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV006)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV006)
	jalr	$2
	nop

	ld	$2,0($fp)
	daddiu	$2,$2,1
	sd	$2,0($fp)
.L64:
	ld	$2,0($fp)
	slt	$2,$2,60
	bne	$2,$0,.L65
	nop

	ld	$3,32($fp)
	lwu	$2,16($fp)
	daddiu	$2,$2,2
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	sll	$2,$2,0
	addiu	$2,$2,4
	move	$5,$2
	ld	$4,48($fp)
	lwu	$3,16($fp)
	move	$2,$3
	dsll	$2,$2,1
	daddu	$2,$2,$3
	dsll	$2,$2,3
	daddu	$2,$2,$3
	dsll	$2,$2,2
	daddu	$2,$2,$3
	dsll	$2,$2,2
	daddu	$2,$4,$2
	lw	$2,20($2)
	move	$6,$2
	ld	$4,56($fp)
	lui	$2,%highest(V206DEV006)
	daddiu	$2,$2,%higher(V206DEV006)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV006)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV006)
	jalr	$2
	nop

	move	$2,$0
.L63:
	move	$sp,$fp
	ld	$31,72($sp)
	ld	$fp,64($sp)
	daddiu	$sp,$sp,80
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	DecFlushRegs
	.size	DecFlushRegs, .-DecFlushRegs
	.align	2
	.globl	DecRefreshRegs
	.set	nomips16
	.set	nomicromips
	.ent	DecRefreshRegs
	.type	DecRefreshRegs, @function
DecRefreshRegs:
	.frame	$fp,80,$31		# vars= 64, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-80
	sd	$31,72($sp)
	sd	$fp,64($sp)
	move	$fp,$sp
	sd	$4,32($fp)
	sd	$5,40($fp)
	sd	$6,48($fp)
	sd	$7,56($fp)
	ld	$2,40($fp)
	lw	$2,0($2)
	sw	$2,8($fp)
	ld	$2,40($fp)
	lw	$3,16($2)
	li	$2,240			# 0xf0
	beq	$3,$2,.L67
	nop

	li	$2,-14			# 0xfffffffffffffff2
	b	.L68
	nop

.L67:
	sd	$0,0($fp)
	b	.L69
	nop

.L70:
	ld	$3,32($fp)
	lwu	$2,8($fp)
	daddiu	$2,$2,2
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	ld	$3,0($fp)
	dsll	$3,$3,2
	daddu	$2,$2,$3
	sll	$2,$2,0
	move	$5,$2
	ld	$4,56($fp)
	lui	$2,%highest(V206DEV007)
	daddiu	$2,$2,%higher(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV007)
	jalr	$2
	nop

	move	$4,$2
	ld	$5,48($fp)
	lwu	$3,8($fp)
	move	$2,$3
	dsll	$2,$2,1
	daddu	$2,$2,$3
	dsll	$2,$2,3
	daddu	$2,$2,$3
	dsll	$2,$2,2
	daddu	$2,$2,$3
	ld	$3,0($fp)
	daddu	$2,$2,$3
	daddiu	$2,$2,4
	dsll	$2,$2,2
	daddu	$2,$5,$2
	sw	$4,0($2)
	ld	$2,0($fp)
	daddiu	$2,$2,1
	sd	$2,0($fp)
.L69:
	ld	$2,0($fp)
	slt	$2,$2,60
	bne	$2,$0,.L70
	nop

	ld	$2,40($fp)
	ld	$4,8($2)
	lwu	$3,8($fp)
	move	$2,$3
	dsll	$2,$2,1
	daddu	$2,$2,$3
	dsll	$2,$2,3
	daddu	$2,$2,$3
	dsll	$2,$2,2
	daddu	$2,$2,$3
	dsll	$2,$2,2
	daddiu	$2,$2,16
	ld	$3,48($fp)
	daddu	$2,$3,$2
	li	$6,240			# 0xf0
	move	$5,$2
	lui	$2,%highest(FUNC206HAL078)
	daddiu	$2,$2,%higher(FUNC206HAL078)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL078)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL078)
	jalr	$2
	nop

	sd	$2,16($fp)
	ld	$2,16($fp)
	beq	$2,$0,.L71
	nop

	li	$2,-14			# 0xfffffffffffffff2
	b	.L68
	nop

.L71:
	move	$2,$0
.L68:
	move	$sp,$fp
	ld	$31,72($sp)
	ld	$fp,64($sp)
	daddiu	$sp,$sp,80
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	DecRefreshRegs
	.size	DecRefreshRegs, .-DecRefreshRegs
	.align	2
	.set	nomips16
	.set	nomicromips
	.ent	CheckDecIrq
	.type	CheckDecIrq, @function
CheckDecIrq:
	.frame	$fp,64,$31		# vars= 48, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-64
	sd	$31,56($sp)
	sd	$fp,48($sp)
	move	$fp,$sp
	sd	$4,16($fp)
	move	$2,$5
	sd	$6,32($fp)
	sll	$2,$2,0
	sw	$2,24($fp)
	sw	$0,0($fp)
	li	$3,1			# 0x1
	lw	$2,24($fp)
	sll	$2,$3,$2
	sw	$2,4($fp)
	ld	$2,32($fp)
	ld	$2,424($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL094)
	daddiu	$2,$2,%higher(FUNC206HAL094)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL094)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL094)
	jalr	$2
	nop

	sd	$2,8($fp)
	ld	$2,32($fp)
	lw	$2,520($2)
	lw	$3,4($fp)
	and	$2,$3,$2
	beq	$2,$0,.L73
	nop

	ld	$2,32($fp)
	lw	$2,520($2)
	move	$3,$2
	lw	$2,4($fp)
	nor	$2,$0,$2
	and	$2,$3,$2
	move	$3,$2
	mtlo	$3
	mflo	$3
	ld	$2,32($fp)
	sw	$3,520($2)
	li	$2,1			# 0x1
	sw	$2,0($fp)
.L73:
	ld	$2,32($fp)
	ld	$2,424($2)
	ld	$5,8($fp)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL095)
	daddiu	$2,$2,%higher(FUNC206HAL095)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL095)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL095)
	jalr	$2
	nop

	lw	$2,0($fp)
	move	$sp,$fp
	ld	$31,56($sp)
	ld	$fp,48($sp)
	daddiu	$sp,$sp,64
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	CheckDecIrq
	.size	CheckDecIrq, .-CheckDecIrq
	.align	2
	.globl	WaitDecReadyAndRefreshRegs
	.set	nomips16
	.set	nomicromips
	.ent	WaitDecReadyAndRefreshRegs
	.type	WaitDecReadyAndRefreshRegs, @function
WaitDecReadyAndRefreshRegs:
	.frame	$fp,80,$31		# vars= 48, regs= 3/0, args= 0, gp= 0
	.mask	0xc0010000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-80
	sd	$31,72($sp)
	sd	$fp,64($sp)
	sd	$16,56($sp)
	move	$fp,$sp
	sd	$4,16($fp)
	sd	$5,24($fp)
	sd	$6,32($fp)
	sd	$7,40($fp)
	ld	$2,24($fp)
	lw	$2,0($2)
	sw	$2,0($fp)
	ld	$2,32($fp)
	ld	$16,432($2)
	lw	$2,0($fp)
	ld	$6,32($fp)
	move	$5,$2
	ld	$4,16($fp)
	lui	$2,%highest(CheckDecIrq)
	daddiu	$2,$2,%higher(CheckDecIrq)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(CheckDecIrq)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(CheckDecIrq)
	jalr	$2
	nop

	move	$5,$2
	move	$4,$16
	lui	$2,%highest(FUNC206HAL096)
	daddiu	$2,$2,%higher(FUNC206HAL096)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL096)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL096)
	jalr	$2
	nop

	beq	$2,$0,.L76
	nop

	li	$2,-512			# 0xfffffffffffffe00
	b	.L77
	nop

.L76:
	ld	$2,32($fp)
	ld	$2,544($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL075)
	daddiu	$2,$2,%higher(FUNC206HAL075)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL075)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL075)
	jalr	$2
	nop

	ld	$7,40($fp)
	ld	$6,32($fp)
	ld	$5,24($fp)
	ld	$4,16($fp)
	lui	$2,%highest(DecRefreshRegs)
	daddiu	$2,$2,%higher(DecRefreshRegs)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(DecRefreshRegs)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(DecRefreshRegs)
	jalr	$2
	nop

.L77:
	move	$sp,$fp
	ld	$31,72($sp)
	ld	$fp,64($sp)
	ld	$16,56($sp)
	daddiu	$sp,$sp,80
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	WaitDecReadyAndRefreshRegs
	.size	WaitDecReadyAndRefreshRegs, .-WaitDecReadyAndRefreshRegs
	.align	2
	.globl	PPFlushRegs
	.set	nomips16
	.set	nomicromips
	.ent	PPFlushRegs
	.type	PPFlushRegs, @function
PPFlushRegs:
	.frame	$fp,80,$31		# vars= 64, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-80
	sd	$31,72($sp)
	sd	$fp,64($sp)
	move	$fp,$sp
	sd	$4,32($fp)
	sd	$5,40($fp)
	sd	$6,48($fp)
	sd	$7,56($fp)
	sd	$0,8($fp)
	ld	$2,40($fp)
	lw	$2,0($2)
	sw	$2,16($fp)
	lwu	$3,16($fp)
	move	$2,$3
	dsll	$2,$2,1
	daddu	$2,$2,$3
	dsll	$2,$2,3
	daddu	$2,$2,$3
	dsll	$2,$2,2
	daddu	$2,$2,$3
	dsll	$2,$2,2
	daddiu	$2,$2,16
	ld	$3,48($fp)
	daddu	$2,$3,$2
	daddiu	$3,$2,240
	ld	$2,40($fp)
	ld	$2,8($2)
	daddiu	$2,$2,240
	li	$6,164			# 0xa4
	move	$5,$2
	move	$4,$3
	lui	$2,%highest(FUNC206HAL077)
	daddiu	$2,$2,%higher(FUNC206HAL077)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL077)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL077)
	jalr	$2
	nop

	sd	$2,8($fp)
	ld	$2,8($fp)
	beq	$2,$0,.L79
	nop

	li	$2,-14			# 0xfffffffffffffff2
	b	.L80
	nop

.L79:
	lwu	$2,16($fp)
	ld	$6,56($fp)
	move	$5,$2
	ld	$4,32($fp)
	lui	$2,%highest(WaitForPPFinish)
	daddiu	$2,$2,%higher(WaitForPPFinish)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(WaitForPPFinish)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(WaitForPPFinish)
	jalr	$2
	nop

	li	$2,61			# 0x3d
	sw	$2,0($fp)
	b	.L81
	nop

.L82:
	ld	$3,32($fp)
	lwu	$2,16($fp)
	daddiu	$2,$2,2
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	sll	$2,$2,0
	move	$3,$2
	lw	$2,0($fp)
	sll	$2,$2,2
	addu	$2,$3,$2
	move	$7,$2
	ld	$4,48($fp)
	lwu	$5,0($fp)
	lwu	$3,16($fp)
	move	$2,$3
	dsll	$2,$2,1
	daddu	$2,$2,$3
	dsll	$2,$2,3
	daddu	$2,$2,$3
	dsll	$2,$2,2
	daddu	$2,$2,$3
	daddu	$2,$2,$5
	daddiu	$2,$2,4
	dsll	$2,$2,2
	daddu	$2,$4,$2
	lw	$2,0($2)
	move	$6,$2
	move	$5,$7
	ld	$4,56($fp)
	lui	$2,%highest(V206DEV006)
	daddiu	$2,$2,%higher(V206DEV006)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV006)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV006)
	jalr	$2
	nop

	lw	$2,0($fp)
	addiu	$2,$2,1
	sw	$2,0($fp)
.L81:
	lw	$2,0($fp)
	sltu	$2,$2,101
	bne	$2,$0,.L82
	nop

	ld	$3,32($fp)
	lwu	$2,16($fp)
	daddiu	$2,$2,2
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	sll	$2,$2,0
	addiu	$2,$2,240
	move	$5,$2
	ld	$4,48($fp)
	lwu	$3,16($fp)
	move	$2,$3
	dsll	$2,$2,1
	daddu	$2,$2,$3
	dsll	$2,$2,3
	daddu	$2,$2,$3
	dsll	$2,$2,2
	daddu	$2,$2,$3
	dsll	$2,$2,2
	daddu	$2,$4,$2
	lw	$2,256($2)
	move	$6,$2
	ld	$4,56($fp)
	lui	$2,%highest(V206DEV006)
	daddiu	$2,$2,%higher(V206DEV006)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV006)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV006)
	jalr	$2
	nop

	move	$2,$0
.L80:
	move	$sp,$fp
	ld	$31,72($sp)
	ld	$fp,64($sp)
	daddiu	$sp,$sp,80
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	PPFlushRegs
	.size	PPFlushRegs, .-PPFlushRegs
	.align	2
	.globl	PPRefreshRegs
	.set	nomips16
	.set	nomicromips
	.ent	PPRefreshRegs
	.type	PPRefreshRegs, @function
PPRefreshRegs:
	.frame	$fp,80,$31		# vars= 64, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-80
	sd	$31,72($sp)
	sd	$fp,64($sp)
	move	$fp,$sp
	sd	$4,32($fp)
	sd	$5,40($fp)
	sd	$6,48($fp)
	sd	$7,56($fp)
	ld	$2,40($fp)
	lw	$2,0($2)
	sw	$2,8($fp)
	ld	$2,40($fp)
	lw	$3,16($2)
	li	$2,164			# 0xa4
	beq	$3,$2,.L84
	nop

	li	$2,-14			# 0xfffffffffffffff2
	b	.L85
	nop

.L84:
	li	$2,60			# 0x3c
	sd	$2,0($fp)
	b	.L86
	nop

.L87:
	ld	$3,32($fp)
	lwu	$2,8($fp)
	daddiu	$2,$2,2
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	ld	$3,0($fp)
	dsll	$3,$3,2
	daddu	$2,$2,$3
	sll	$2,$2,0
	move	$5,$2
	ld	$4,56($fp)
	lui	$2,%highest(V206DEV007)
	daddiu	$2,$2,%higher(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV007)
	jalr	$2
	nop

	move	$4,$2
	ld	$5,48($fp)
	lwu	$3,8($fp)
	move	$2,$3
	dsll	$2,$2,1
	daddu	$2,$2,$3
	dsll	$2,$2,3
	daddu	$2,$2,$3
	dsll	$2,$2,2
	daddu	$2,$2,$3
	ld	$3,0($fp)
	daddu	$2,$2,$3
	daddiu	$2,$2,4
	dsll	$2,$2,2
	daddu	$2,$5,$2
	sw	$4,0($2)
	ld	$2,0($fp)
	daddiu	$2,$2,1
	sd	$2,0($fp)
.L86:
	ld	$2,0($fp)
	slt	$2,$2,101
	bne	$2,$0,.L87
	nop

	ld	$2,40($fp)
	ld	$2,8($2)
	daddiu	$4,$2,240
	lwu	$3,8($fp)
	move	$2,$3
	dsll	$2,$2,1
	daddu	$2,$2,$3
	dsll	$2,$2,3
	daddu	$2,$2,$3
	dsll	$2,$2,2
	daddu	$2,$2,$3
	dsll	$2,$2,2
	daddiu	$2,$2,16
	ld	$3,48($fp)
	daddu	$2,$3,$2
	daddiu	$2,$2,240
	li	$6,164			# 0xa4
	move	$5,$2
	lui	$2,%highest(FUNC206HAL078)
	daddiu	$2,$2,%higher(FUNC206HAL078)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL078)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL078)
	jalr	$2
	nop

	sd	$2,16($fp)
	ld	$2,16($fp)
	beq	$2,$0,.L88
	nop

	li	$2,-14			# 0xfffffffffffffff2
	b	.L85
	nop

.L88:
	move	$2,$0
.L85:
	move	$sp,$fp
	ld	$31,72($sp)
	ld	$fp,64($sp)
	daddiu	$sp,$sp,80
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	PPRefreshRegs
	.size	PPRefreshRegs, .-PPRefreshRegs
	.align	2
	.set	nomips16
	.set	nomicromips
	.ent	CheckPPIrq
	.type	CheckPPIrq, @function
CheckPPIrq:
	.frame	$fp,64,$31		# vars= 48, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-64
	sd	$31,56($sp)
	sd	$fp,48($sp)
	move	$fp,$sp
	sd	$4,16($fp)
	move	$2,$5
	sd	$6,32($fp)
	sll	$2,$2,0
	sw	$2,24($fp)
	sw	$0,0($fp)
	li	$3,1			# 0x1
	lw	$2,24($fp)
	sll	$2,$3,$2
	sw	$2,4($fp)
	ld	$2,32($fp)
	ld	$2,424($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL094)
	daddiu	$2,$2,%higher(FUNC206HAL094)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL094)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL094)
	jalr	$2
	nop

	sd	$2,8($fp)
	ld	$2,32($fp)
	lw	$2,524($2)
	lw	$3,4($fp)
	and	$2,$3,$2
	beq	$2,$0,.L90
	nop

	ld	$2,32($fp)
	lw	$2,524($2)
	move	$3,$2
	lw	$2,4($fp)
	nor	$2,$0,$2
	and	$2,$3,$2
	move	$3,$2
	mtlo	$3
	mflo	$3
	ld	$2,32($fp)
	sw	$3,524($2)
	li	$2,1			# 0x1
	sw	$2,0($fp)
.L90:
	ld	$2,32($fp)
	ld	$2,424($2)
	ld	$5,8($fp)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL095)
	daddiu	$2,$2,%higher(FUNC206HAL095)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL095)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL095)
	jalr	$2
	nop

	lw	$2,0($fp)
	move	$sp,$fp
	ld	$31,56($sp)
	ld	$fp,48($sp)
	daddiu	$sp,$sp,64
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	CheckPPIrq
	.size	CheckPPIrq, .-CheckPPIrq
	.align	2
	.globl	WaitPPReadyAndRefreshRegs
	.set	nomips16
	.set	nomicromips
	.ent	WaitPPReadyAndRefreshRegs
	.type	WaitPPReadyAndRefreshRegs, @function
WaitPPReadyAndRefreshRegs:
	.frame	$fp,80,$31		# vars= 48, regs= 3/0, args= 0, gp= 0
	.mask	0xc0010000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-80
	sd	$31,72($sp)
	sd	$fp,64($sp)
	sd	$16,56($sp)
	move	$fp,$sp
	sd	$4,16($fp)
	sd	$5,24($fp)
	sd	$6,32($fp)
	sd	$7,40($fp)
	ld	$2,24($fp)
	lw	$2,0($2)
	sw	$2,0($fp)
	ld	$2,32($fp)
	ld	$16,440($2)
	lw	$2,0($fp)
	ld	$6,32($fp)
	move	$5,$2
	ld	$4,16($fp)
	lui	$2,%highest(CheckPPIrq)
	daddiu	$2,$2,%higher(CheckPPIrq)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(CheckPPIrq)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(CheckPPIrq)
	jalr	$2
	nop

	move	$5,$2
	move	$4,$16
	lui	$2,%highest(FUNC206HAL096)
	daddiu	$2,$2,%higher(FUNC206HAL096)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL096)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL096)
	jalr	$2
	nop

	beq	$2,$0,.L93
	nop

	li	$2,-512			# 0xfffffffffffffe00
	b	.L94
	nop

.L93:
	ld	$2,32($fp)
	ld	$2,544($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL075)
	daddiu	$2,$2,%higher(FUNC206HAL075)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL075)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL075)
	jalr	$2
	nop

	ld	$7,40($fp)
	ld	$6,32($fp)
	ld	$5,24($fp)
	ld	$4,16($fp)
	lui	$2,%highest(PPRefreshRegs)
	daddiu	$2,$2,%higher(PPRefreshRegs)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(PPRefreshRegs)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(PPRefreshRegs)
	jalr	$2
	nop

.L94:
	move	$sp,$fp
	ld	$31,72($sp)
	ld	$fp,64($sp)
	ld	$16,56($sp)
	daddiu	$sp,$sp,80
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	WaitPPReadyAndRefreshRegs
	.size	WaitPPReadyAndRefreshRegs, .-WaitPPReadyAndRefreshRegs
	.align	2
	.set	nomips16
	.set	nomicromips
	.ent	CheckCoreIrq
	.type	CheckCoreIrq, @function
CheckCoreIrq:
	.frame	$fp,80,$31		# vars= 64, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-80
	sd	$31,72($sp)
	sd	$fp,64($sp)
	move	$fp,$sp
	sd	$4,32($fp)
	sd	$5,40($fp)
	sd	$6,48($fp)
	sd	$7,56($fp)
	sw	$0,0($fp)
	sw	$0,4($fp)
.L99:
	li	$3,1			# 0x1
	lw	$2,4($fp)
	sll	$2,$3,$2
	sw	$2,8($fp)
	ld	$2,56($fp)
	ld	$2,424($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL094)
	daddiu	$2,$2,%higher(FUNC206HAL094)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL094)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL094)
	jalr	$2
	nop

	sd	$2,16($fp)
	ld	$2,56($fp)
	lw	$2,520($2)
	lw	$3,8($fp)
	and	$2,$3,$2
	beq	$2,$0,.L96
	nop

	ld	$3,56($fp)
	lw	$2,4($fp)
	daddiu	$2,$2,60
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,8($2)
	ld	$3,40($fp)
	bne	$3,$2,.L97
	nop

	ld	$2,56($fp)
	lw	$2,520($2)
	move	$3,$2
	lw	$2,8($fp)
	nor	$2,$0,$2
	and	$2,$3,$2
	move	$3,$2
	mtlo	$3
	mflo	$3
	ld	$2,56($fp)
	sw	$3,520($2)
	ld	$2,48($fp)
	lw	$3,4($fp)
	sw	$3,0($2)
	li	$2,1			# 0x1
	sw	$2,0($fp)
	b	.L98
	nop

.L97:
	ld	$3,56($fp)
	lw	$2,4($fp)
	daddiu	$2,$2,60
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,8($2)
	bne	$2,$0,.L96
	nop

	ld	$2,56($fp)
	lw	$2,520($2)
	move	$3,$2
	lw	$2,8($fp)
	nor	$2,$0,$2
	and	$2,$3,$2
	move	$3,$2
	mtlo	$3
	mflo	$3
	ld	$2,56($fp)
	sw	$3,520($2)
.L96:
	ld	$2,56($fp)
	ld	$2,424($2)
	ld	$5,16($fp)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL095)
	daddiu	$2,$2,%higher(FUNC206HAL095)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL095)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL095)
	jalr	$2
	nop

	lw	$2,4($fp)
	addiu	$2,$2,1
	sw	$2,4($fp)
	ld	$2,32($fp)
	lw	$2,28($2)
	lw	$3,4($fp)
	slt	$2,$3,$2
	bne	$2,$0,.L99
	nop

.L98:
	lw	$2,0($fp)
	move	$sp,$fp
	ld	$31,72($sp)
	ld	$fp,64($sp)
	daddiu	$sp,$sp,80
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	CheckCoreIrq
	.size	CheckCoreIrq, .-CheckCoreIrq
	.align	2
	.globl	WaitCoreReady
	.set	nomips16
	.set	nomicromips
	.ent	WaitCoreReady
	.type	WaitCoreReady, @function
WaitCoreReady:
	.frame	$fp,64,$31		# vars= 32, regs= 3/0, args= 0, gp= 0
	.mask	0xc0010000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-64
	sd	$31,56($sp)
	sd	$fp,48($sp)
	sd	$16,40($sp)
	move	$fp,$sp
	sd	$4,0($fp)
	sd	$5,8($fp)
	sd	$6,16($fp)
	sd	$7,24($fp)
	ld	$2,24($fp)
	ld	$16,432($2)
	ld	$7,24($fp)
	ld	$6,16($fp)
	ld	$5,8($fp)
	ld	$4,0($fp)
	lui	$2,%highest(CheckCoreIrq)
	daddiu	$2,$2,%higher(CheckCoreIrq)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(CheckCoreIrq)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(CheckCoreIrq)
	jalr	$2
	nop

	move	$5,$2
	move	$4,$16
	lui	$2,%highest(FUNC206HAL096)
	daddiu	$2,$2,%higher(FUNC206HAL096)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL096)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL096)
	jalr	$2
	nop

	beq	$2,$0,.L102
	nop

	li	$2,-512			# 0xfffffffffffffe00
	b	.L103
	nop

.L102:
	ld	$2,24($fp)
	ld	$2,544($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL075)
	daddiu	$2,$2,%higher(FUNC206HAL075)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL075)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL075)
	jalr	$2
	nop

	move	$2,$0
.L103:
	move	$sp,$fp
	ld	$31,56($sp)
	ld	$fp,48($sp)
	ld	$16,40($sp)
	daddiu	$sp,$sp,64
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	WaitCoreReady
	.size	WaitCoreReady, .-WaitCoreReady
	.rdata
	.align	3
.LC2:
	.ascii	"\0011decoder: pDec->dec_irq     = 0x%08x \012\000"
	.align	3
.LC3:
	.ascii	"\0011decoder: pDec->pp_irq      = 0x%08x \012\000"
	.align	3
.LC4:
	.ascii	"\0011decoder: IRQs received/sent2user = %d / %d \012\000"
	.align	3
.LC5:
	.ascii	"FREE\000"
	.align	3
.LC6:
	.ascii	"RESERVED\000"
	.align	3
.LC7:
	.ascii	"\0011decoder: dec_core[%li] %s\012\000"
	.align	3
.LC8:
	.ascii	"\0011decoder: pp_core[%li]  %s\012\000"
	.text
	.align	2
	.globl	mwv206dec_ioctl
	.set	nomips16
	.set	nomicromips
	.ent	mwv206dec_ioctl
	.type	mwv206dec_ioctl, @function
mwv206dec_ioctl:
	.frame	$fp,272,$31		# vars= 240, regs= 3/0, args= 0, gp= 0
	.mask	0xc0010000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-272
	sd	$31,264($sp)
	sd	$fp,256($sp)
	sd	$16,248($sp)
	move	$fp,$sp
	sd	$4,192($fp)
	move	$2,$5
	sd	$6,208($fp)
	sd	$7,216($fp)
	sd	$8,224($fp)
	sll	$2,$2,0
	sw	$2,200($fp)
	sw	$0,8($fp)
	ld	$2,216($fp)
	sd	$2,16($fp)
	lw	$3,200($fp)
	li	$2,1074266112			# 0x40080000
	ori	$2,$2,0x6b07
	beq	$3,$2,.L105
	nop

	lw	$3,200($fp)
	li	$2,1074266112			# 0x40080000
	ori	$2,$2,0x6b08
	sltu	$2,$3,$2
	beq	$2,$0,.L106
	nop

	lw	$3,200($fp)
	li	$2,536870912			# 0x20000000
	ori	$2,$2,0x6b0d
	beq	$3,$2,.L107
	nop

	lw	$3,200($fp)
	li	$2,536870912			# 0x20000000
	ori	$2,$2,0x6b0e
	sltu	$2,$3,$2
	beq	$2,$0,.L108
	nop

	lw	$3,200($fp)
	li	$2,536870912			# 0x20000000
	ori	$2,$2,0x6b06
	beq	$3,$2,.L109
	nop

	lw	$3,200($fp)
	li	$2,536870912			# 0x20000000
	ori	$2,$2,0x6b07
	sltu	$2,$3,$2
	beq	$2,$0,.L110
	nop

	lw	$3,200($fp)
	li	$2,536870912			# 0x20000000
	ori	$2,$2,0x6b05
	beq	$3,$2,.L111
	nop

	b	.L112
	nop

.L110:
	lw	$3,200($fp)
	li	$2,536870912			# 0x20000000
	ori	$2,$2,0x6b0b
	beq	$3,$2,.L113
	nop

	lw	$3,200($fp)
	li	$2,536870912			# 0x20000000
	ori	$2,$2,0x6b0c
	beq	$3,$2,.L114
	nop

	b	.L112
	nop

.L108:
	lw	$3,200($fp)
	li	$2,536870912			# 0x20000000
	ori	$2,$2,0x6b1d
	beq	$3,$2,.L115
	nop

	lw	$3,200($fp)
	li	$2,536870912			# 0x20000000
	ori	$2,$2,0x6b1e
	sltu	$2,$3,$2
	beq	$2,$0,.L116
	nop

	lw	$3,200($fp)
	li	$2,536870912			# 0x20000000
	ori	$2,$2,0x6b0e
	beq	$3,$2,.L117
	nop

	b	.L112
	nop

.L116:
	lw	$3,200($fp)
	li	$2,1074266112			# 0x40080000
	ori	$2,$2,0x6b03
	beq	$3,$2,.L118
	nop

	lw	$3,200($fp)
	li	$2,1074266112			# 0x40080000
	ori	$2,$2,0x6b04
	beq	$3,$2,.L119
	nop

	b	.L112
	nop

.L106:
	lw	$3,200($fp)
	li	$2,-1073217536			# 0xffffffffc0080000
	ori	$2,$2,0x6b0f
	beq	$3,$2,.L120
	nop

	lw	$3,200($fp)
	li	$2,-1073217536			# 0xffffffffc0080000
	ori	$2,$2,0x6b10
	sltu	$2,$3,$2
	beq	$2,$0,.L121
	nop

	lw	$3,200($fp)
	li	$2,1074266112			# 0x40080000
	ori	$2,$2,0x6b13
	beq	$3,$2,.L122
	nop

	lw	$3,200($fp)
	li	$2,1074266112			# 0x40080000
	ori	$2,$2,0x6b14
	sltu	$2,$3,$2
	beq	$2,$0,.L123
	nop

	lw	$3,200($fp)
	li	$2,1074266112			# 0x40080000
	ori	$2,$2,0x6b08
	beq	$3,$2,.L124
	nop

	b	.L112
	nop

.L123:
	lw	$3,200($fp)
	li	$2,-2146959360			# 0xffffffff80080000
	ori	$2,$2,0x6b09
	beq	$3,$2,.L125
	nop

	lw	$3,200($fp)
	li	$2,-2146959360			# 0xffffffff80080000
	ori	$2,$2,0x6b0a
	beq	$3,$2,.L126
	nop

	b	.L112
	nop

.L121:
	lw	$3,200($fp)
	li	$2,-1073217536			# 0xffffffffc0080000
	ori	$2,$2,0x6b11
	beq	$3,$2,.L127
	nop

	lw	$3,200($fp)
	li	$2,-1073217536			# 0xffffffffc0080000
	ori	$2,$2,0x6b11
	sltu	$2,$3,$2
	bne	$2,$0,.L128
	nop

	lw	$3,200($fp)
	li	$2,-1073217536			# 0xffffffffc0080000
	ori	$2,$2,0x6b12
	beq	$3,$2,.L129
	nop

	lw	$3,200($fp)
	li	$2,-1073217536			# 0xffffffffc0080000
	ori	$2,$2,0x6b14
	beq	$3,$2,.L130
	nop

	b	.L112
	nop

.L111:
	ld	$2,16($fp)
	lw	$2,480($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL079)
	daddiu	$2,$2,%higher(FUNC206HAL079)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL079)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL079)
	jalr	$2
	nop

	b	.L131
	nop

.L109:
	ld	$2,16($fp)
	lw	$2,480($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL080)
	daddiu	$2,$2,%higher(FUNC206HAL080)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL080)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL080)
	jalr	$2
	nop

	b	.L131
	nop

.L118:
	ld	$2,16($fp)
	ld	$2,8($2)
	ld	$3,208($fp)
	move	$5,$3
	move	$4,$2
	lui	$2,%highest(FUNC206HAL087)
	daddiu	$2,$2,%higher(FUNC206HAL087)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL087)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL087)
	jalr	$2
	nop

	b	.L131
	nop

.L119:
	ld	$2,16($fp)
	lw	$2,464($2)
	ld	$3,208($fp)
	move	$5,$3
	move	$4,$2
	lui	$2,%highest(FUNC206HAL086)
	daddiu	$2,$2,%higher(FUNC206HAL086)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL086)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL086)
	jalr	$2
	nop

	b	.L131
	nop

.L105:
	ld	$3,208($fp)
	ld	$2,16($fp)
	daddiu	$2,$2,8
	li	$6,8			# 0x8
	move	$5,$2
	move	$4,$3
	lui	$2,%highest(FUNC206HAL078)
	daddiu	$2,$2,%higher(FUNC206HAL078)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL078)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL078)
	jalr	$2
	nop

	sd	$2,0($fp)
	lw	$2,8($fp)
	beq	$2,$0,.L157
	nop

	li	$2,-14			# 0xfffffffffffffff2
	b	.L133
	nop

.L124:
	ld	$2,16($fp)
	lw	$2,484($2)
	ld	$3,208($fp)
	move	$5,$3
	move	$4,$2
	lui	$2,%highest(FUNC206HAL086)
	daddiu	$2,$2,%higher(FUNC206HAL086)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL086)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL086)
	jalr	$2
	nop

	b	.L131
	nop

.L125:
	ld	$2,208($fp)
	daddiu	$3,$fp,32
	li	$6,24			# 0x18
	move	$5,$2
	move	$4,$3
	lui	$2,%highest(FUNC206HAL077)
	daddiu	$2,$2,%higher(FUNC206HAL077)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL077)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL077)
	jalr	$2
	nop

	sd	$2,0($fp)
	ld	$2,0($fp)
	beq	$2,$0,.L134
	nop

	li	$2,-14			# 0xfffffffffffffff2
	b	.L133
	nop

.L134:
	ld	$2,16($fp)
	daddiu	$2,$2,456
	daddiu	$3,$fp,32
	ld	$7,224($fp)
	ld	$6,16($fp)
	move	$5,$3
	move	$4,$2
	lui	$2,%highest(DecFlushRegs)
	daddiu	$2,$2,%higher(DecFlushRegs)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(DecFlushRegs)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(DecFlushRegs)
	jalr	$2
	nop

	b	.L133
	nop

.L126:
	ld	$2,208($fp)
	daddiu	$3,$fp,56
	li	$6,24			# 0x18
	move	$5,$2
	move	$4,$3
	lui	$2,%highest(FUNC206HAL077)
	daddiu	$2,$2,%higher(FUNC206HAL077)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL077)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL077)
	jalr	$2
	nop

	sd	$2,0($fp)
	ld	$2,0($fp)
	beq	$2,$0,.L136
	nop

	li	$2,-14			# 0xfffffffffffffff2
	b	.L133
	nop

.L136:
	ld	$2,16($fp)
	daddiu	$2,$2,456
	daddiu	$3,$fp,56
	ld	$7,224($fp)
	ld	$6,16($fp)
	move	$5,$3
	move	$4,$2
	lui	$2,%highest(PPFlushRegs)
	daddiu	$2,$2,%higher(PPFlushRegs)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(PPFlushRegs)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(PPFlushRegs)
	jalr	$2
	nop

	b	.L133
	nop

.L127:
	ld	$2,208($fp)
	daddiu	$3,$fp,80
	li	$6,24			# 0x18
	move	$5,$2
	move	$4,$3
	lui	$2,%highest(FUNC206HAL077)
	daddiu	$2,$2,%higher(FUNC206HAL077)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL077)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL077)
	jalr	$2
	nop

	sd	$2,0($fp)
	ld	$2,0($fp)
	beq	$2,$0,.L138
	nop

	li	$2,-14			# 0xfffffffffffffff2
	b	.L133
	nop

.L138:
	ld	$2,16($fp)
	daddiu	$2,$2,456
	daddiu	$3,$fp,80
	ld	$7,224($fp)
	ld	$6,16($fp)
	move	$5,$3
	move	$4,$2
	lui	$2,%highest(DecRefreshRegs)
	daddiu	$2,$2,%higher(DecRefreshRegs)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(DecRefreshRegs)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(DecRefreshRegs)
	jalr	$2
	nop

	b	.L133
	nop

.L129:
	ld	$2,208($fp)
	daddiu	$3,$fp,104
	li	$6,24			# 0x18
	move	$5,$2
	move	$4,$3
	lui	$2,%highest(FUNC206HAL077)
	daddiu	$2,$2,%higher(FUNC206HAL077)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL077)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL077)
	jalr	$2
	nop

	sd	$2,0($fp)
	ld	$2,0($fp)
	beq	$2,$0,.L140
	nop

	li	$2,-14			# 0xfffffffffffffff2
	b	.L133
	nop

.L140:
	ld	$2,16($fp)
	daddiu	$2,$2,456
	daddiu	$3,$fp,104
	ld	$7,224($fp)
	ld	$6,16($fp)
	move	$5,$3
	move	$4,$2
	lui	$2,%highest(PPRefreshRegs)
	daddiu	$2,$2,%higher(PPRefreshRegs)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(PPRefreshRegs)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(PPRefreshRegs)
	jalr	$2
	nop

	b	.L133
	nop

.L113:
	ld	$2,16($fp)
	daddiu	$2,$2,456
	ld	$7,16($fp)
	ld	$6,208($fp)
	ld	$5,192($fp)
	move	$4,$2
	lui	$2,%highest(ReserveDecoder)
	daddiu	$2,$2,%higher(ReserveDecoder)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(ReserveDecoder)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(ReserveDecoder)
	jalr	$2
	nop

	b	.L133
	nop

.L114:
	ld	$2,16($fp)
	lw	$2,484($2)
	move	$3,$2
	ld	$2,208($fp)
	sltu	$2,$2,$3
	beq	$2,$0,.L142
	nop

	ld	$3,16($fp)
	ld	$2,208($fp)
	daddiu	$2,$2,60
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,8($2)
	ld	$3,192($fp)
	beq	$3,$2,.L143
	nop

.L142:
	li	$2,-14			# 0xfffffffffffffff2
	b	.L133
	nop

.L143:
	ld	$2,16($fp)
	daddiu	$2,$2,456
	ld	$3,208($fp)
	ld	$7,224($fp)
	ld	$6,16($fp)
	move	$5,$3
	move	$4,$2
	lui	$2,%highest(ReleaseDecoder)
	daddiu	$2,$2,%higher(ReleaseDecoder)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(ReleaseDecoder)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(ReleaseDecoder)
	jalr	$2
	nop

	b	.L131
	nop

.L107:
	ld	$2,16($fp)
	daddiu	$2,$2,456
	ld	$6,16($fp)
	ld	$5,192($fp)
	move	$4,$2
	lui	$2,%highest(ReservePostProcessor)
	daddiu	$2,$2,%higher(ReservePostProcessor)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(ReservePostProcessor)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(ReservePostProcessor)
	jalr	$2
	nop

	b	.L133
	nop

.L117:
	ld	$2,208($fp)
	bne	$2,$0,.L144
	nop

	ld	$3,16($fp)
	ld	$2,208($fp)
	daddiu	$2,$2,62
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	ld	$3,192($fp)
	beq	$3,$2,.L145
	nop

.L144:
	li	$2,-14			# 0xfffffffffffffff2
	b	.L133
	nop

.L145:
	ld	$2,16($fp)
	daddiu	$2,$2,456
	ld	$3,208($fp)
	ld	$7,224($fp)
	ld	$6,16($fp)
	move	$5,$3
	move	$4,$2
	lui	$2,%highest(ReleasePostProcessor)
	daddiu	$2,$2,%higher(ReleasePostProcessor)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(ReleasePostProcessor)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(ReleasePostProcessor)
	jalr	$2
	nop

	b	.L131
	nop

.L120:
	ld	$2,208($fp)
	daddiu	$3,$fp,128
	li	$6,24			# 0x18
	move	$5,$2
	move	$4,$3
	lui	$2,%highest(FUNC206HAL077)
	daddiu	$2,$2,%higher(FUNC206HAL077)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL077)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL077)
	jalr	$2
	nop

	sd	$2,0($fp)
	ld	$2,0($fp)
	beq	$2,$0,.L146
	nop

	li	$2,-14			# 0xfffffffffffffff2
	b	.L133
	nop

.L146:
	ld	$2,16($fp)
	daddiu	$2,$2,456
	daddiu	$3,$fp,128
	ld	$7,224($fp)
	ld	$6,16($fp)
	move	$5,$3
	move	$4,$2
	lui	$2,%highest(WaitDecReadyAndRefreshRegs)
	daddiu	$2,$2,%higher(WaitDecReadyAndRefreshRegs)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(WaitDecReadyAndRefreshRegs)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(WaitDecReadyAndRefreshRegs)
	jalr	$2
	nop

	b	.L133
	nop

.L128:
	ld	$2,208($fp)
	daddiu	$3,$fp,152
	li	$6,24			# 0x18
	move	$5,$2
	move	$4,$3
	lui	$2,%highest(FUNC206HAL077)
	daddiu	$2,$2,%higher(FUNC206HAL077)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL077)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL077)
	jalr	$2
	nop

	sd	$2,0($fp)
	ld	$2,0($fp)
	beq	$2,$0,.L148
	nop

	li	$2,-14			# 0xfffffffffffffff2
	b	.L133
	nop

.L148:
	ld	$2,16($fp)
	daddiu	$2,$2,456
	daddiu	$3,$fp,152
	ld	$7,224($fp)
	ld	$6,16($fp)
	move	$5,$3
	move	$4,$2
	lui	$2,%highest(WaitPPReadyAndRefreshRegs)
	daddiu	$2,$2,%higher(WaitPPReadyAndRefreshRegs)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(WaitPPReadyAndRefreshRegs)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(WaitPPReadyAndRefreshRegs)
	jalr	$2
	nop

	b	.L133
	nop

.L122:
	ld	$2,16($fp)
	daddiu	$2,$2,456
	daddiu	$3,$fp,176
	ld	$7,16($fp)
	move	$6,$3
	ld	$5,192($fp)
	move	$4,$2
	lui	$2,%highest(WaitCoreReady)
	daddiu	$2,$2,%higher(WaitCoreReady)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(WaitCoreReady)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(WaitCoreReady)
	jalr	$2
	nop

	sd	$2,0($fp)
	lw	$2,176($fp)
	ld	$3,208($fp)
	move	$5,$3
	move	$4,$2
	lui	$2,%highest(FUNC206HAL085)
	daddiu	$2,$2,%higher(FUNC206HAL085)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL085)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL085)
	jalr	$2
	nop

	ld	$2,0($fp)
	b	.L133
	nop

.L130:
	ld	$2,208($fp)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL082)
	daddiu	$2,$2,%higher(FUNC206HAL082)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL082)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL082)
	jalr	$2
	nop

	sw	$2,24($fp)
	ld	$2,16($fp)
	lw	$2,484($2)
	lw	$3,24($fp)
	sltu	$2,$3,$2
	bne	$2,$0,.L150
	nop

	li	$2,-14			# 0xfffffffffffffff2
	b	.L133
	nop

.L150:
	ld	$3,16($fp)
	lwu	$2,24($fp)
	daddiu	$2,$2,58
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,8($2)
	sll	$2,$2,0
	move	$5,$2
	ld	$4,224($fp)
	lui	$2,%highest(V206DEV007)
	daddiu	$2,$2,%higher(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV007)
	jalr	$2
	nop

	sw	$2,24($fp)
	ld	$3,208($fp)
	lw	$2,24($fp)
	move	$5,$3
	move	$4,$2
	lui	$2,%highest(FUNC206HAL086)
	daddiu	$2,$2,%higher(FUNC206HAL086)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL086)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL086)
	jalr	$2
	nop

	b	.L131
	nop

.L115:
	ld	$2,16($fp)
	lw	$2,520($2)
	move	$5,$2
	lui	$2,%highest(.LC2)
	daddiu	$2,$2,%higher(.LC2)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(.LC2)
	dsll	$2,$2,16
	daddiu	$4,$2,%lo(.LC2)
	lui	$2,%highest(printk)
	daddiu	$2,$2,%higher(printk)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(printk)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(printk)
	jalr	$2
	nop

	ld	$2,16($fp)
	lw	$2,524($2)
	move	$5,$2
	lui	$2,%highest(.LC3)
	daddiu	$2,$2,%higher(.LC3)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(.LC3)
	dsll	$2,$2,16
	daddiu	$4,$2,%lo(.LC3)
	lui	$2,%highest(printk)
	daddiu	$2,$2,%higher(printk)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(printk)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(printk)
	jalr	$2
	nop

	ld	$2,16($fp)
	ld	$2,536($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL076)
	daddiu	$2,$2,%higher(FUNC206HAL076)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL076)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL076)
	jalr	$2
	nop

	move	$16,$2
	ld	$2,16($fp)
	ld	$2,544($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL076)
	daddiu	$2,$2,%higher(FUNC206HAL076)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL076)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL076)
	jalr	$2
	nop

	move	$6,$2
	move	$5,$16
	lui	$2,%highest(.LC4)
	daddiu	$2,$2,%higher(.LC4)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(.LC4)
	dsll	$2,$2,16
	daddiu	$4,$2,%lo(.LC4)
	lui	$2,%highest(printk)
	daddiu	$2,$2,%higher(printk)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(printk)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(printk)
	jalr	$2
	nop

	sd	$0,0($fp)
	b	.L151
	nop

.L156:
	ld	$3,16($fp)
	ld	$2,0($fp)
	daddiu	$2,$2,60
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,8($2)
	bne	$2,$0,.L152
	nop

	lui	$2,%highest(.LC5)
	daddiu	$2,$2,%higher(.LC5)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(.LC5)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(.LC5)
	b	.L153
	nop

.L152:
	lui	$2,%highest(.LC6)
	daddiu	$2,$2,%higher(.LC6)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(.LC6)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(.LC6)
.L153:
	move	$6,$2
	ld	$5,0($fp)
	lui	$2,%highest(.LC7)
	daddiu	$2,$2,%higher(.LC7)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(.LC7)
	dsll	$2,$2,16
	daddiu	$4,$2,%lo(.LC7)
	lui	$2,%highest(printk)
	daddiu	$2,$2,%higher(printk)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(printk)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(printk)
	jalr	$2
	nop

	ld	$3,16($fp)
	ld	$2,0($fp)
	daddiu	$2,$2,62
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	bne	$2,$0,.L154
	nop

	lui	$2,%highest(.LC5)
	daddiu	$2,$2,%higher(.LC5)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(.LC5)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(.LC5)
	b	.L155
	nop

.L154:
	lui	$2,%highest(.LC6)
	daddiu	$2,$2,%higher(.LC6)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(.LC6)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(.LC6)
.L155:
	move	$6,$2
	ld	$5,0($fp)
	lui	$2,%highest(.LC8)
	daddiu	$2,$2,%higher(.LC8)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(.LC8)
	dsll	$2,$2,16
	daddiu	$4,$2,%lo(.LC8)
	lui	$2,%highest(printk)
	daddiu	$2,$2,%higher(printk)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(printk)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(printk)
	jalr	$2
	nop

	ld	$2,0($fp)
	daddiu	$2,$2,1
	sd	$2,0($fp)
.L151:
	ld	$2,16($fp)
	lw	$2,484($2)
	move	$3,$2
	ld	$2,0($fp)
	slt	$2,$2,$3
	bne	$2,$0,.L156
	nop

	b	.L131
	nop

.L112:
	li	$2,-25			# 0xffffffffffffffe7
	b	.L133
	nop

.L157:
	nop
.L131:
	move	$2,$0
.L133:
	move	$sp,$fp
	ld	$31,264($sp)
	ld	$fp,256($sp)
	ld	$16,248($sp)
	daddiu	$sp,$sp,272
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	mwv206dec_ioctl
	.size	mwv206dec_ioctl, .-mwv206dec_ioctl
	.align	2
	.globl	mwv206dec_release
	.set	nomips16
	.set	nomicromips
	.ent	mwv206dec_release
	.type	mwv206dec_release, @function
mwv206dec_release:
	.frame	$fp,80,$31		# vars= 64, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-80
	sd	$31,72($sp)
	sd	$fp,64($sp)
	move	$fp,$sp
	sd	$4,32($fp)
	sd	$5,40($fp)
	sd	$6,48($fp)
	sd	$7,56($fp)
	ld	$2,48($fp)
	sd	$2,8($fp)
	ld	$2,8($fp)
	daddiu	$2,$2,456
	sd	$2,16($fp)
	sw	$0,0($fp)
	b	.L159
	nop

.L161:
	ld	$3,8($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,60
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,8($2)
	ld	$3,40($fp)
	bne	$3,$2,.L160
	nop

	lw	$2,0($fp)
	ld	$7,56($fp)
	ld	$6,8($fp)
	move	$5,$2
	ld	$4,16($fp)
	lui	$2,%highest(ReleaseDecoder)
	daddiu	$2,$2,%higher(ReleaseDecoder)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(ReleaseDecoder)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(ReleaseDecoder)
	jalr	$2
	nop

.L160:
	lw	$2,0($fp)
	addiu	$2,$2,1
	sw	$2,0($fp)
.L159:
	ld	$2,16($fp)
	lw	$2,28($2)
	lw	$3,0($fp)
	slt	$2,$3,$2
	bne	$2,$0,.L161
	nop

	sw	$0,0($fp)
	b	.L162
	nop

.L164:
	ld	$3,8($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,62
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	ld	$3,40($fp)
	bne	$3,$2,.L163
	nop

	lw	$2,0($fp)
	ld	$7,56($fp)
	ld	$6,8($fp)
	move	$5,$2
	ld	$4,16($fp)
	lui	$2,%highest(ReleasePostProcessor)
	daddiu	$2,$2,%higher(ReleasePostProcessor)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(ReleasePostProcessor)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(ReleasePostProcessor)
	jalr	$2
	nop

.L163:
	lw	$2,0($fp)
	addiu	$2,$2,1
	sw	$2,0($fp)
.L162:
	lw	$2,0($fp)
	blez	$2,.L164
	nop

	move	$2,$0
	move	$sp,$fp
	ld	$31,72($sp)
	ld	$fp,64($sp)
	daddiu	$sp,$sp,80
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	mwv206dec_release
	.size	mwv206dec_release, .-mwv206dec_release
	.rdata
	.align	3
.LC9:
	.ascii	"\0016[INFO] decoder: Init begin. \012\000"
	.align	3
.LC10:
	.ascii	"\0016[INFO] decoder: Init End. \012\000"
	.align	3
.LC11:
	.ascii	"\0011[ERROR] decoder: Init failed.\012\000"
	.text
	.align	2
	.globl	mwv206dec_init
	.set	nomips16
	.set	nomicromips
	.ent	mwv206dec_init
	.type	mwv206dec_init, @function
mwv206dec_init:
	.frame	$fp,80,$31		# vars= 64, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-80
	sd	$31,72($sp)
	sd	$fp,64($sp)
	move	$fp,$sp
	sd	$4,32($fp)
	sd	$5,40($fp)
	sd	$6,48($fp)
	li	$2,-1			# 0xffffffffffffffff
	sw	$2,4($fp)
	sw	$0,8($fp)
	li	$4,552			# 0x228
	lui	$2,%highest(FUNC206LXDEV010)
	daddiu	$2,$2,%higher(FUNC206LXDEV010)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206LXDEV010)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206LXDEV010)
	jalr	$2
	nop

	sd	$2,16($fp)
	ld	$2,16($fp)
	bne	$2,$0,.L167
	nop

	li	$2,-1			# 0xffffffffffffffff
	b	.L168
	nop

.L167:
	ld	$2,16($fp)
	ld	$3,40($fp)
	sd	$3,0($2)
	ld	$2,32($fp)
	ld	$3,16($fp)
	sd	$3,0($2)
	lui	$2,%highest(.LC9)
	daddiu	$2,$2,%higher(.LC9)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(.LC9)
	dsll	$2,$2,16
	daddiu	$4,$2,%lo(.LC9)
	lui	$2,%highest(printk)
	daddiu	$2,$2,%higher(printk)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(printk)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(printk)
	jalr	$2
	nop

	ld	$2,16($fp)
	ld	$3,40($fp)
	sd	$3,8($2)
	li	$2,1			# 0x1
	sw	$2,8($fp)
	li	$2,10			# 0xa
	sw	$2,4($fp)
	ld	$2,16($fp)
	sw	$0,520($2)
	ld	$2,16($fp)
	sw	$0,524($2)
	ld	$2,16($fp)
	li	$3,404			# 0x194
	sw	$3,464($2)
	ld	$2,16($fp)
	lw	$3,4($fp)
	sw	$3,480($2)
	sw	$0,0($fp)
	b	.L169
	nop

.L171:
	ld	$3,16($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,58
	dsll	$2,$2,3
	daddu	$2,$3,$2
	li	$3,11534336			# 0xb00000
	sd	$3,8($2)
	lw	$2,8($fp)
	beq	$2,$0,.L170
	nop

	lw	$3,0($fp)
	lw	$2,8($fp)
	slt	$2,$3,$2
	bne	$2,$0,.L170
	nop

	ld	$3,16($fp)
	lw	$2,0($fp)
	dsll	$2,$2,3
	daddu	$2,$3,$2
	li	$3,-1			# 0xffffffffffffffff
	sd	$3,8($2)
.L170:
	lw	$2,0($fp)
	addiu	$2,$2,1
	sw	$2,0($fp)
.L169:
	lw	$2,0($fp)
	blez	$2,.L171
	nop

	ld	$5,48($fp)
	ld	$4,16($fp)
	lui	$2,%highest(ReserveIO)
	daddiu	$2,$2,%higher(ReserveIO)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(ReserveIO)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(ReserveIO)
	jalr	$2
	nop

	sw	$2,24($fp)
	lw	$2,24($fp)
	bltz	$2,.L183
	nop

	ld	$2,16($fp)
	daddiu	$2,$2,488
	li	$6,8			# 0x8
	move	$5,$0
	move	$4,$2
	lui	$2,%highest(FUNC206HAL084)
	daddiu	$2,$2,%higher(FUNC206HAL084)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL084)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL084)
	jalr	$2
	nop

	ld	$2,16($fp)
	daddiu	$2,$2,496
	li	$6,8			# 0x8
	move	$5,$0
	move	$4,$2
	lui	$2,%highest(FUNC206HAL084)
	daddiu	$2,$2,%higher(FUNC206HAL084)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL084)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL084)
	jalr	$2
	nop

	lui	$2,%highest(FUNC206HAL088)
	daddiu	$2,$2,%higher(FUNC206HAL088)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL088)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL088)
	jalr	$2
	nop

	move	$3,$2
	ld	$2,16($fp)
	sd	$3,504($2)
	ld	$2,16($fp)
	ld	$2,504($2)
	bne	$2,$0,.L174
	nop

	li	$2,-1			# 0xffffffffffffffff
	b	.L168
	nop

.L174:
	lui	$2,%highest(FUNC206HAL088)
	daddiu	$2,$2,%higher(FUNC206HAL088)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL088)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL088)
	jalr	$2
	nop

	move	$3,$2
	ld	$2,16($fp)
	sd	$3,512($2)
	ld	$2,16($fp)
	ld	$2,512($2)
	bne	$2,$0,.L175
	nop

	li	$2,-1			# 0xffffffffffffffff
	b	.L168
	nop

.L175:
	ld	$2,16($fp)
	daddiu	$2,$2,456
	ld	$6,48($fp)
	ld	$5,16($fp)
	move	$4,$2
	lui	$2,%highest(ReadCoreConfig)
	daddiu	$2,$2,%higher(ReadCoreConfig)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(ReadCoreConfig)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(ReadCoreConfig)
	jalr	$2
	nop

	ld	$2,16($fp)
	daddiu	$2,$2,456
	ld	$5,48($fp)
	move	$4,$2
	lui	$2,%highest(ResetAsic)
	daddiu	$2,$2,%higher(ResetAsic)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(ResetAsic)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(ResetAsic)
	jalr	$2
	nop

	lui	$2,%highest(FUNC206HAL092)
	daddiu	$2,$2,%higher(FUNC206HAL092)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL092)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL092)
	jalr	$2
	nop

	move	$3,$2
	ld	$2,16($fp)
	sd	$3,424($2)
	ld	$2,16($fp)
	ld	$2,424($2)
	bne	$2,$0,.L176
	nop

	li	$2,-1			# 0xffffffffffffffff
	b	.L168
	nop

.L176:
	lui	$2,%highest(FUNC206HAL097)
	daddiu	$2,$2,%higher(FUNC206HAL097)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL097)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL097)
	jalr	$2
	nop

	move	$3,$2
	ld	$2,16($fp)
	sd	$3,432($2)
	ld	$2,16($fp)
	ld	$2,432($2)
	bne	$2,$0,.L177
	nop

	li	$2,-1			# 0xffffffffffffffff
	b	.L168
	nop

.L177:
	lui	$2,%highest(FUNC206HAL097)
	daddiu	$2,$2,%higher(FUNC206HAL097)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL097)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL097)
	jalr	$2
	nop

	move	$3,$2
	ld	$2,16($fp)
	sd	$3,440($2)
	ld	$2,16($fp)
	ld	$2,440($2)
	bne	$2,$0,.L178
	nop

	li	$2,-1			# 0xffffffffffffffff
	b	.L168
	nop

.L178:
	lui	$2,%highest(FUNC206HAL097)
	daddiu	$2,$2,%higher(FUNC206HAL097)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL097)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL097)
	jalr	$2
	nop

	move	$3,$2
	ld	$2,16($fp)
	sd	$3,448($2)
	ld	$2,16($fp)
	ld	$2,448($2)
	bne	$2,$0,.L179
	nop

	li	$2,-1			# 0xffffffffffffffff
	b	.L168
	nop

.L179:
	lui	$2,%highest(FUNC206HAL072)
	daddiu	$2,$2,%higher(FUNC206HAL072)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL072)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL072)
	jalr	$2
	nop

	move	$3,$2
	ld	$2,16($fp)
	sd	$3,536($2)
	ld	$2,16($fp)
	ld	$2,536($2)
	bne	$2,$0,.L180
	nop

	li	$2,-1			# 0xffffffffffffffff
	b	.L168
	nop

.L180:
	lui	$2,%highest(FUNC206HAL072)
	daddiu	$2,$2,%higher(FUNC206HAL072)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL072)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL072)
	jalr	$2
	nop

	move	$3,$2
	ld	$2,16($fp)
	sd	$3,544($2)
	ld	$2,16($fp)
	ld	$2,544($2)
	bne	$2,$0,.L181
	nop

	li	$2,-1			# 0xffffffffffffffff
	b	.L168
	nop

.L181:
	lui	$2,%highest(.LC10)
	daddiu	$2,$2,%higher(.LC10)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(.LC10)
	dsll	$2,$2,16
	daddiu	$4,$2,%lo(.LC10)
	lui	$2,%highest(printk)
	daddiu	$2,$2,%higher(printk)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(printk)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(printk)
	jalr	$2
	nop

	move	$2,$0
	b	.L168
	nop

.L183:
	nop
.L173 = .
	lui	$2,%highest(.LC11)
	daddiu	$2,$2,%higher(.LC11)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(.LC11)
	dsll	$2,$2,16
	daddiu	$4,$2,%lo(.LC11)
	lui	$2,%highest(printk)
	daddiu	$2,$2,%higher(printk)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(printk)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(printk)
	jalr	$2
	nop

	lw	$2,24($fp)
.L168:
	move	$sp,$fp
	ld	$31,72($sp)
	ld	$fp,64($sp)
	daddiu	$sp,$sp,80
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	mwv206dec_init
	.size	mwv206dec_init, .-mwv206dec_init
	.align	2
	.globl	mwv206dec_free_resources
	.set	nomips16
	.set	nomicromips
	.ent	mwv206dec_free_resources
	.type	mwv206dec_free_resources, @function
mwv206dec_free_resources:
	.frame	$fp,48,$31		# vars= 32, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-48
	sd	$31,40($sp)
	sd	$fp,32($sp)
	move	$fp,$sp
	sd	$4,16($fp)
	ld	$2,16($fp)
	sd	$2,0($fp)
	ld	$2,0($fp)
	beq	$2,$0,.L187
	nop

	ld	$2,0($fp)
	ld	$2,424($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL093)
	daddiu	$2,$2,%higher(FUNC206HAL093)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL093)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL093)
	jalr	$2
	nop

	ld	$2,0($fp)
	ld	$2,432($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL098)
	daddiu	$2,$2,%higher(FUNC206HAL098)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL098)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL098)
	jalr	$2
	nop

	ld	$2,0($fp)
	ld	$2,440($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL098)
	daddiu	$2,$2,%higher(FUNC206HAL098)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL098)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL098)
	jalr	$2
	nop

	ld	$2,0($fp)
	ld	$2,448($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL098)
	daddiu	$2,$2,%higher(FUNC206HAL098)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL098)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL098)
	jalr	$2
	nop

	ld	$2,0($fp)
	ld	$2,504($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL089)
	daddiu	$2,$2,%higher(FUNC206HAL089)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL089)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL089)
	jalr	$2
	nop

	ld	$2,0($fp)
	ld	$2,512($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL089)
	daddiu	$2,$2,%higher(FUNC206HAL089)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL089)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL089)
	jalr	$2
	nop

	ld	$2,0($fp)
	ld	$2,536($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL074)
	daddiu	$2,$2,%higher(FUNC206HAL074)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL074)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL074)
	jalr	$2
	nop

	ld	$2,0($fp)
	ld	$2,544($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL074)
	daddiu	$2,$2,%higher(FUNC206HAL074)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL074)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL074)
	jalr	$2
	nop

	b	.L184
	nop

.L187:
	nop
.L184:
	move	$sp,$fp
	ld	$31,40($sp)
	ld	$fp,32($sp)
	daddiu	$sp,$sp,48
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	mwv206dec_free_resources
	.size	mwv206dec_free_resources, .-mwv206dec_free_resources
	.align	2
	.globl	mwv206dec_reset
	.set	nomips16
	.set	nomicromips
	.ent	mwv206dec_reset
	.type	mwv206dec_reset, @function
mwv206dec_reset:
	.frame	$fp,48,$31		# vars= 32, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-48
	sd	$31,40($sp)
	sd	$fp,32($sp)
	move	$fp,$sp
	sd	$4,16($fp)
	sd	$5,24($fp)
	ld	$2,16($fp)
	sd	$2,0($fp)
	ld	$2,0($fp)
	beq	$2,$0,.L192
	nop

	ld	$2,0($fp)
	daddiu	$2,$2,456
	sd	$2,8($fp)
	ld	$2,8($fp)
	beq	$2,$0,.L193
	nop

	ld	$5,24($fp)
	ld	$4,8($fp)
	lui	$2,%highest(ResetAsic)
	daddiu	$2,$2,%higher(ResetAsic)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(ResetAsic)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(ResetAsic)
	jalr	$2
	nop

	lui	$2,%highest(ReleaseIO)
	daddiu	$2,$2,%higher(ReleaseIO)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(ReleaseIO)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(ReleaseIO)
	jalr	$2
	nop

	nop
	b	.L188
	nop

.L192:
	nop
	b	.L188
	nop

.L193:
	nop
.L188:
	move	$sp,$fp
	ld	$31,40($sp)
	ld	$fp,32($sp)
	daddiu	$sp,$sp,48
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	mwv206dec_reset
	.size	mwv206dec_reset, .-mwv206dec_reset
	.align	2
	.globl	mwv206dec_uninit
	.set	nomips16
	.set	nomicromips
	.ent	mwv206dec_uninit
	.type	mwv206dec_uninit, @function
mwv206dec_uninit:
	.frame	$fp,32,$31		# vars= 16, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-32
	sd	$31,24($sp)
	sd	$fp,16($sp)
	move	$fp,$sp
	sd	$4,0($fp)
	sd	$5,8($fp)
	ld	$5,8($fp)
	ld	$4,0($fp)
	lui	$2,%highest(mwv206dec_reset)
	daddiu	$2,$2,%higher(mwv206dec_reset)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(mwv206dec_reset)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(mwv206dec_reset)
	jalr	$2
	nop

	ld	$4,0($fp)
	lui	$2,%highest(mwv206dec_free_resources)
	daddiu	$2,$2,%higher(mwv206dec_free_resources)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(mwv206dec_free_resources)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(mwv206dec_free_resources)
	jalr	$2
	nop

	nop
	move	$sp,$fp
	ld	$31,24($sp)
	ld	$fp,16($sp)
	daddiu	$sp,$sp,32
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	mwv206dec_uninit
	.size	mwv206dec_uninit, .-mwv206dec_uninit
	.align	2
	.set	nomips16
	.set	nomicromips
	.ent	CheckHwId
	.type	CheckHwId, @function
CheckHwId:
	.frame	$fp,80,$31		# vars= 64, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-80
	sd	$31,72($sp)
	sd	$fp,64($sp)
	move	$fp,$sp
	sd	$4,32($fp)
	sd	$5,40($fp)
	sd	$6,48($fp)
	li	$2,5			# 0x5
	sw	$2,4($fp)
	sw	$0,8($fp)
	sw	$0,0($fp)
	b	.L196
	nop

.L203:
	ld	$3,32($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,2
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	beq	$2,$0,.L197
	nop

	ld	$3,32($fp)
	lw	$2,0($fp)
	daddiu	$2,$2,2
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	sll	$2,$2,0
	move	$5,$2
	ld	$4,48($fp)
	lui	$2,%highest(V206DEV007)
	daddiu	$2,$2,%higher(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV007)
	jalr	$2
	nop

	dext	$2,$2,0,32
	sd	$2,16($fp)
	ld	$2,16($fp)
	dsra	$2,$2,16
	andi	$2,$2,0xffff
	sd	$2,16($fp)
	b	.L198
	nop

.L200:
	lui	$2,%highest(DecHwId)
	daddiu	$2,$2,%higher(DecHwId)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(DecHwId)
	dsll	$2,$2,16
	lwu	$3,4($fp)
	dsll	$3,$3,2
	daddiu	$2,$2,%lo(DecHwId)
	daddu	$2,$3,$2
	lw	$2,0($2)
	move	$3,$2
	ld	$2,16($fp)
	bne	$2,$3,.L198
	nop

	lw	$2,8($fp)
	addiu	$2,$2,1
	sw	$2,8($fp)
	b	.L199
	nop

.L198:
	lw	$2,4($fp)
	addiu	$3,$2,-1
	sw	$3,4($fp)
	bne	$2,$0,.L200
	nop

.L199:
	lw	$2,8($fp)
	bne	$2,$0,.L201
	nop

	move	$2,$0
	b	.L202
	nop

.L201:
	sw	$0,8($fp)
	li	$2,5			# 0x5
	sw	$2,4($fp)
.L197:
	lw	$2,0($fp)
	addiu	$2,$2,1
	sw	$2,0($fp)
.L196:
	ld	$2,32($fp)
	lw	$2,28($2)
	lw	$3,0($fp)
	slt	$2,$3,$2
	bne	$2,$0,.L203
	nop

	li	$2,1			# 0x1
.L202:
	move	$sp,$fp
	ld	$31,72($sp)
	ld	$fp,64($sp)
	daddiu	$sp,$sp,80
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	CheckHwId
	.size	CheckHwId, .-CheckHwId
	.align	2
	.set	nomips16
	.set	nomicromips
	.ent	ReserveIO
	.type	ReserveIO, @function
ReserveIO:
	.frame	$fp,32,$31		# vars= 16, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-32
	sd	$31,24($sp)
	sd	$fp,16($sp)
	move	$fp,$sp
	sd	$4,0($fp)
	sd	$5,8($fp)
	ld	$2,0($fp)
	li	$3,11534336			# 0xb00000
	sd	$3,472($2)
	ld	$2,0($fp)
	ld	$2,472($2)
	bne	$2,$0,.L205
	nop

	lui	$2,%highest(ReleaseIO)
	daddiu	$2,$2,%higher(ReleaseIO)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(ReleaseIO)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(ReleaseIO)
	jalr	$2
	nop

	li	$2,-16			# 0xfffffffffffffff0
	b	.L206
	nop

.L205:
	ld	$2,0($fp)
	li	$3,1			# 0x1
	sw	$3,484($2)
	ld	$2,0($fp)
	daddiu	$2,$2,456
	ld	$6,8($fp)
	ld	$5,0($fp)
	move	$4,$2
	lui	$2,%highest(CheckHwId)
	daddiu	$2,$2,%higher(CheckHwId)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(CheckHwId)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(CheckHwId)
	jalr	$2
	nop

	bne	$2,$0,.L207
	nop

	lui	$2,%highest(ReleaseIO)
	daddiu	$2,$2,%higher(ReleaseIO)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(ReleaseIO)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(ReleaseIO)
	jalr	$2
	nop

	li	$2,-16			# 0xfffffffffffffff0
	b	.L206
	nop

.L207:
	move	$2,$0
.L206:
	move	$sp,$fp
	ld	$31,24($sp)
	ld	$fp,16($sp)
	daddiu	$sp,$sp,32
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	ReserveIO
	.size	ReserveIO, .-ReserveIO
	.align	2
	.set	nomips16
	.set	nomicromips
	.ent	ReleaseIO
	.type	ReleaseIO, @function
ReleaseIO:
	.frame	$fp,16,$31		# vars= 0, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-16
	sd	$fp,8($sp)
	move	$fp,$sp
	nop
	move	$sp,$fp
	ld	$fp,8($sp)
	daddiu	$sp,$sp,16
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	ReleaseIO
	.size	ReleaseIO, .-ReleaseIO
	.align	2
	.globl	mwv206dec_decoder_isr
	.set	nomips16
	.set	nomicromips
	.ent	mwv206dec_decoder_isr
	.type	mwv206dec_decoder_isr, @function
mwv206dec_decoder_isr:
	.frame	$fp,80,$31		# vars= 64, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-80
	sd	$31,72($sp)
	sd	$fp,64($sp)
	move	$fp,$sp
	sd	$4,48($fp)
	sd	$5,56($fp)
	sw	$0,0($fp)
	li	$2,11534336			# 0xb00000
	sd	$2,8($fp)
	li	$2,1			# 0x1
	sw	$2,16($fp)
	ld	$2,48($fp)
	sd	$2,24($fp)
	ld	$2,24($fp)
	ld	$2,424($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL094)
	daddiu	$2,$2,%higher(FUNC206HAL094)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL094)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL094)
	jalr	$2
	nop

	sd	$2,32($fp)
	sw	$0,4($fp)
	b	.L211
	nop

.L213:
	lw	$2,8($fp)
	addiu	$2,$2,4
	move	$5,$2
	ld	$4,56($fp)
	lui	$2,%highest(V206DEV007)
	daddiu	$2,$2,%higher(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV007)
	jalr	$2
	nop

	sw	$2,40($fp)
	lw	$2,40($fp)
	andi	$2,$2,0x100
	beq	$2,$0,.L212
	nop

	lw	$3,40($fp)
	li	$2,-257			# 0xfffffffffffffeff
	and	$2,$3,$2
	sw	$2,40($fp)
	lw	$2,8($fp)
	addiu	$2,$2,4
	lw	$3,40($fp)
	move	$6,$3
	move	$5,$2
	ld	$4,56($fp)
	lui	$2,%highest(V206DEV006)
	daddiu	$2,$2,%higher(V206DEV006)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV006)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV006)
	jalr	$2
	nop

	ld	$2,24($fp)
	ld	$2,536($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL075)
	daddiu	$2,$2,%higher(FUNC206HAL075)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL075)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL075)
	jalr	$2
	nop

	ld	$2,24($fp)
	lw	$3,520($2)
	li	$4,1			# 0x1
	lw	$2,4($fp)
	sll	$2,$4,$2
	or	$2,$3,$2
	move	$3,$2
	ld	$2,24($fp)
	sw	$3,520($2)
	ld	$2,24($fp)
	ld	$2,432($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL099)
	daddiu	$2,$2,%higher(FUNC206HAL099)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL099)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL099)
	jalr	$2
	nop

	lw	$2,0($fp)
	addiu	$2,$2,1
	sw	$2,0($fp)
.L212:
	lw	$2,4($fp)
	addiu	$2,$2,1
	sw	$2,4($fp)
.L211:
	lw	$3,4($fp)
	lw	$2,16($fp)
	slt	$2,$3,$2
	bne	$2,$0,.L213
	nop

	lw	$2,8($fp)
	addiu	$2,$2,240
	move	$5,$2
	ld	$4,56($fp)
	lui	$2,%highest(V206DEV007)
	daddiu	$2,$2,%higher(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV007)
	jalr	$2
	nop

	sw	$2,44($fp)
	lw	$2,44($fp)
	andi	$2,$2,0x100
	beq	$2,$0,.L214
	nop

	lw	$3,44($fp)
	li	$2,-257			# 0xfffffffffffffeff
	and	$2,$3,$2
	sw	$2,44($fp)
	lw	$2,8($fp)
	addiu	$2,$2,240
	lw	$3,44($fp)
	move	$6,$3
	move	$5,$2
	ld	$4,56($fp)
	lui	$2,%highest(V206DEV006)
	daddiu	$2,$2,%higher(V206DEV006)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV006)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV006)
	jalr	$2
	nop

	ld	$2,24($fp)
	ld	$2,536($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL075)
	daddiu	$2,$2,%higher(FUNC206HAL075)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL075)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL075)
	jalr	$2
	nop

	ld	$2,24($fp)
	lw	$2,524($2)
	ori	$2,$2,0x1
	move	$3,$2
	ld	$2,24($fp)
	sw	$3,524($2)
	ld	$2,24($fp)
	ld	$2,440($2)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL099)
	daddiu	$2,$2,%higher(FUNC206HAL099)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL099)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL099)
	jalr	$2
	nop

	lw	$2,0($fp)
	addiu	$2,$2,1
	sw	$2,0($fp)
.L214:
	ld	$2,24($fp)
	ld	$2,424($2)
	ld	$5,32($fp)
	move	$4,$2
	lui	$2,%highest(FUNC206HAL095)
	daddiu	$2,$2,%higher(FUNC206HAL095)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(FUNC206HAL095)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(FUNC206HAL095)
	jalr	$2
	nop

	lw	$2,0($fp)
	sltu	$2,$0,$2
	andi	$2,$2,0x00ff
	move	$sp,$fp
	ld	$31,72($sp)
	ld	$fp,64($sp)
	daddiu	$sp,$sp,80
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	mwv206dec_decoder_isr
	.size	mwv206dec_decoder_isr, .-mwv206dec_decoder_isr
	.align	2
	.set	nomips16
	.set	nomicromips
	.ent	ResetAsic
	.type	ResetAsic, @function
ResetAsic:
	.frame	$fp,48,$31		# vars= 32, regs= 2/0, args= 0, gp= 0
	.mask	0xc0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-48
	sd	$31,40($sp)
	sd	$fp,32($sp)
	move	$fp,$sp
	sd	$4,16($fp)
	sd	$5,24($fp)
	sw	$0,4($fp)
	b	.L217
	nop

.L221:
	ld	$3,16($fp)
	lw	$2,4($fp)
	daddiu	$2,$2,2
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	sll	$2,$2,0
	addiu	$2,$2,4
	move	$5,$2
	ld	$4,24($fp)
	lui	$2,%highest(V206DEV007)
	daddiu	$2,$2,%higher(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV007)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV007)
	jalr	$2
	nop

	sw	$2,8($fp)
	lw	$2,8($fp)
	andi	$2,$2,0x1
	beq	$2,$0,.L218
	nop

	li	$2,48			# 0x30
	sw	$2,8($fp)
	ld	$3,16($fp)
	lw	$2,4($fp)
	daddiu	$2,$2,2
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	sll	$2,$2,0
	addiu	$2,$2,4
	lw	$3,8($fp)
	move	$6,$3
	move	$5,$2
	ld	$4,24($fp)
	lui	$2,%highest(V206DEV006)
	daddiu	$2,$2,%higher(V206DEV006)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV006)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV006)
	jalr	$2
	nop

.L218:
	ld	$3,16($fp)
	lw	$2,4($fp)
	daddiu	$2,$2,2
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	sll	$2,$2,0
	addiu	$2,$2,240
	move	$6,$0
	move	$5,$2
	ld	$4,24($fp)
	lui	$2,%highest(V206DEV006)
	daddiu	$2,$2,%higher(V206DEV006)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV006)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV006)
	jalr	$2
	nop

	li	$2,4			# 0x4
	sw	$2,0($fp)
	b	.L219
	nop

.L220:
	ld	$3,16($fp)
	lw	$2,4($fp)
	daddiu	$2,$2,2
	dsll	$2,$2,3
	daddu	$2,$3,$2
	ld	$2,0($2)
	sll	$2,$2,0
	lw	$3,0($fp)
	addu	$2,$3,$2
	move	$6,$0
	move	$5,$2
	ld	$4,24($fp)
	lui	$2,%highest(V206DEV006)
	daddiu	$2,$2,%higher(V206DEV006)
	dsll	$2,$2,16
	daddiu	$2,$2,%hi(V206DEV006)
	dsll	$2,$2,16
	daddiu	$2,$2,%lo(V206DEV006)
	jalr	$2
	nop

	lw	$2,0($fp)
	addiu	$2,$2,4
	sw	$2,0($fp)
.L219:
	ld	$2,16($fp)
	lw	$2,8($2)
	lw	$3,0($fp)
	sltu	$2,$3,$2
	bne	$2,$0,.L220
	nop

	lw	$2,4($fp)
	addiu	$2,$2,1
	sw	$2,4($fp)
.L217:
	ld	$2,16($fp)
	lw	$2,28($2)
	lw	$3,4($fp)
	slt	$2,$3,$2
	bne	$2,$0,.L221
	nop

	nop
	move	$sp,$fp
	ld	$31,40($sp)
	ld	$fp,32($sp)
	daddiu	$sp,$sp,48
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	ResetAsic
	.size	ResetAsic, .-ResetAsic
