	.text
; CodeWarrior ARM soft-float runtime (FP_fastI_v5t_LE), hand-written assembly.
; A .s file for mwasmarm, not MWCC inline asm: the routines branch into the middle
; of their neighbours (`bmi _dsub+0x10`), which the inline assembler can't write.
; Assemble-time branches need no relocation, as in the original object.

	.global _ll_mod
	.type _ll_mod, @function
_ll_mod:
	stmfd sp!, {r4, r5, r6, r7, r11, ip, lr}
	mov r4, r1
	orr r4, r4, #0x1
	b _ll_sdiv+0x10
	.size _ll_mod, .-_ll_mod

	.global _ll_sdiv
	.type _ll_sdiv, @function
_ll_sdiv:
	stmfd sp!, {r4, r5, r6, r7, r11, ip, lr}
	eor r4, r1, r3
	mov r4, r4, asr #0x1
	mov r4, r4, lsl #0x1
.L_0200af9c:
	orrs r5, r3, r2
	bne .L_0200afac
	ldmfd sp!, {r4, r5, r6, r7, r11, ip, lr}
	bx lr
.L_0200afac:
	mov r5, r0, lsr #0x1f
	add r5, r5, r1
	mov r6, r2, lsr #0x1f
	add r6, r6, r3
	orrs r6, r5, r6
	bne .L_0200afe0
	mov r1, r2
	bl _s32_div_f
	ands r4, r4, #0x1
	movne r0, r1
	mov r1, r0, asr #0x1f
	ldmfd sp!, {r4, r5, r6, r7, r11, ip, lr}
	bx lr
.L_0200afe0:
	cmp r1, #0x0
	bge .L_0200aff0
	rsbs r0, r0, #0x0
	rsc r1, r1, #0x0
.L_0200aff0:
	cmp r3, #0x0
	bge .L_0200b000
	rsbs r2, r2, #0x0
	rsc r3, r3, #0x0
.L_0200b000:
	orrs r5, r1, r0
	beq .L_0200b124
	mov r5, #0x0
	mov r6, #0x1
	cmp r3, #0x0
	bmi .L_0200b02c
.L_0200b018:
	add r5, r5, #0x1
	adds r2, r2, r2
	adcs r3, r3, r3
	bpl .L_0200b018
	add r6, r6, r5
.L_0200b02c:
	cmp r1, #0x0
	blt .L_0200b04c
.L_0200b034:
	cmp r6, #0x1
	beq .L_0200b04c
	sub r6, r6, #0x1
	adds r0, r0, r0
	adcs r1, r1, r1
	bpl .L_0200b034
.L_0200b04c:
	mov r7, #0x0
	mov ip, #0x0
	mov r11, #0x0
	b .L_0200b074
.L_0200b05c:
	orr ip, ip, #0x1
	subs r6, r6, #0x1
	beq .L_0200b0cc
	adds r0, r0, r0
	adcs r1, r1, r1
	adcs r7, r7, r7
.L_0200b074:
	subs r0, r0, r2
	sbcs r1, r1, r3
	sbcs r7, r7, #0x0
	adds ip, ip, ip
	adc r11, r11, r11
	cmp r7, #0x0
	bge .L_0200b05c
.L_0200b090:
	subs r6, r6, #0x1
	beq .L_0200b0c4
	adds r0, r0, r0
	adcs r1, r1, r1
	adc r7, r7, r7
	adds r0, r0, r2
	adcs r1, r1, r3
	adc r7, r7, #0x0
	adds ip, ip, ip
	adc r11, r11, r11
	cmp r7, #0x0
	bge .L_0200b05c
	b .L_0200b090
.L_0200b0c4:
	adds r0, r0, r2
	adc r1, r1, r3
.L_0200b0cc:
	ands r7, r4, #0x1
	moveq r0, ip
	moveq r1, r11
	beq .L_0200b104
	subs r7, r5, #0x20
	movge r0, r1, lsr r7
	bge .L_0200b128
	rsb r7, r5, #0x20
	mov r0, r0, lsr r5
	orr r0, r0, r1, lsl r7
	mov r1, r1, lsr r5
	b .L_0200b104
	mov r0, r1, lsr r7
	mov r1, #0x0
.L_0200b104:
	cmp r4, #0x0
	blt .L_0200b114
	ldmfd sp!, {r4, r5, r6, r7, r11, ip, lr}
	bx lr
.L_0200b114:
	rsbs r0, r0, #0x0
	rsc r1, r1, #0x0
	ldmfd sp!, {r4, r5, r6, r7, r11, ip, lr}
	bx lr
.L_0200b124:
	mov r0, #0x0
.L_0200b128:
	mov r1, #0x0
	cmp r4, #0x0
	blt .L_0200b114
	ldmfd sp!, {r4, r5, r6, r7, r11, ip, lr}
	bx lr
	.size _ll_sdiv, .-_ll_sdiv

	.global _ll_udiv
	.type _ll_udiv, @function
_ll_udiv:
	stmfd sp!, {r4, r5, r6, r7, r11, ip, lr}
	mov r4, #0x0
	b _ull_mod+0x8
	.size _ll_udiv, .-_ll_udiv

	.global _ull_mod
	.type _ull_mod, @function
_ull_mod:
	stmfd sp!, {r4, r5, r6, r7, r11, ip, lr}
	mov r4, #0x1
.L_0200b150:
	orrs r5, r3, r2
	bne .L_0200b160
	ldmfd sp!, {r4, r5, r6, r7, r11, ip, lr}
	bx lr
.L_0200b160:
	orrs r5, r1, r3
	bne _ll_sdiv+0x74
	mov r1, r2
	bl _u32_div_not_0_f
	cmp r4, #0x0
	movne r0, r1
	mov r1, #0x0
	ldmfd sp!, {r4, r5, r6, r7, r11, ip, lr}
	bx lr
	.size _ull_mod, .-_ull_mod

	.global _s32_div_f
	.type _s32_div_f, @function
_s32_div_f:
	eor ip, r0, r1
	and ip, ip, #0x80000000
	cmp r0, #0x0
	rsblt r0, r0, #0x0
	addlt ip, ip, #0x1
	cmp r1, #0x0
	rsblt r1, r1, #0x0
	beq .L_0200b37c
	cmp r0, r1
	movlo r1, r0
	movlo r0, #0x0
	blo .L_0200b37c
	mov r2, #0x1c
	mov r3, r0, lsr #0x4
	cmp r1, r3, lsr #0xc
	suble r2, r2, #0x10
	movle r3, r3, lsr #0x10
	cmp r1, r3, lsr #0x4
	suble r2, r2, #0x8
	movle r3, r3, lsr #0x8
	cmp r1, r3
	suble r2, r2, #0x4
	movle r3, r3, lsr #0x4
	mov r0, r0, lsl r2
	rsb r1, r1, #0x0
	adds r0, r0, r0
	add r2, r2, r2, lsl #0x1
	add pc, pc, r2, lsl #0x2
	mov r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	mov r1, r3
.L_0200b37c:
	ands r3, ip, #0x80000000
	rsbne r0, r0, #0x0
	ands r3, ip, #0x1
	rsbne r1, r1, #0x0
	bx lr
	.size _s32_div_f, .-_s32_div_f

	.global _u32_div_f
	.type _u32_div_f, @function
_u32_div_f:
	cmp r1, #0x0
	bxeq lr
	.size _u32_div_f, .-_u32_div_f

	.global _u32_div_not_0_f
	.type _u32_div_not_0_f, @function
_u32_div_not_0_f:
.L_0200b398:
	cmp r0, r1
	movlo r1, r0
	movlo r0, #0x0
	bxlo lr
	mov r2, #0x1c
	mov r3, r0, lsr #0x4
	cmp r1, r3, lsr #0xc
	suble r2, r2, #0x10
	movle r3, r3, lsr #0x10
	cmp r1, r3, lsr #0x4
	suble r2, r2, #0x8
	movle r3, r3, lsr #0x8
	cmp r1, r3
	suble r2, r2, #0x4
	movle r3, r3, lsr #0x4
	mov r0, r0, lsl r2
	rsb r1, r1, #0x0
	adds r0, r0, r0
	add r2, r2, r2, lsl #0x1
	add pc, pc, r2, lsl #0x2
	mov r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	adcs r3, r1, r3, lsl #0x1
	sublo r3, r3, r1
	adcs r0, r0, r0
	mov r1, r3
	bx lr
	.size _u32_div_not_0_f, .-_u32_div_not_0_f
