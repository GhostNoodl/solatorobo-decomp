	.text
; CodeWarrior ARM soft-float runtime (FP_fastI_v5t_LE), hand-written assembly.
; A .s file for mwasmarm, not MWCC inline asm: the routines branch into the middle
; of their neighbours (`bmi _dsub+0x10`), which the inline assembler can't write.
; Assemble-time branches need no relocation, as in the original object.

	.global _fadd
	.type _fadd, @function
_fadd:
	eors r2, r0, r1
	eormi r1, r1, #0x80000000
	bmi _fsub+0xc
	subs ip, r0, r1
	sublo r0, r0, ip
	addlo r1, r1, ip
	mov r2, #0x80000000
	mov r3, r0, lsr #0x17
	orr r0, r2, r0, lsl #0x8
	ands ip, r3, #0xff
	cmpne ip, #0xff
	beq .L_0200b8f4
	mov ip, r1, lsr #0x17
	orr r1, r2, r1, lsl #0x8
	ands r2, ip, #0xff
	beq .L_0200b934
.L_0200b894:
	subs ip, r3, ip
	beq .L_0200b8ac
	rsb r2, ip, #0x20
	movs r2, r1, lsl r2
	mov r1, r1, lsr ip
	orrne r1, r1, #0x1
.L_0200b8ac:
	adds r0, r0, r1
	blo .L_0200b8cc
	and r1, r0, #0x1
	orr r0, r1, r0, rrx
	add r3, r3, #0x1
	and r2, r3, #0xff
	cmp r2, #0xff
	beq .L_0200ba3c
.L_0200b8cc:
	ands r1, r0, #0xff
	add r0, r0, r0
	mov r0, r0, lsr #0x9
	orr r0, r0, r3, lsl #0x17
	tst r1, #0x80
	bxeq lr
	ands r1, r1, #0x7f
	andeqs r1, r0, #0x1
	addne r0, r0, #0x1
	bx lr
.L_0200b8f4:
	cmp r3, #0x100
	movge r2, #0x80000000
	movlt r2, #0x0
	ands r3, r3, #0xff
	beq .L_0200b958
	movs r0, r0, lsl #0x1
	bne .L_0200ba68
	mov ip, r1, lsr #0x17
	mov r1, r1, lsl #0x9
	ands ip, ip, #0xff
	beq .L_0200ba5c
	cmp ip, #0xff
	blt .L_0200ba5c
	cmp r1, #0x0
	beq .L_0200ba5c
	b .L_0200ba68
.L_0200b934:
	cmp r3, #0x100
	movge r2, #0x80000000
	movlt r2, #0x0
	and r3, r3, #0xff
	ands ip, ip, #0xff
	beq .L_0200b9b4
.L_0200b94c:
	movs r1, r1, lsl #0x1
	bne .L_0200ba68
	b .L_0200ba5c
.L_0200b958:
	movs r0, r0, lsl #0x1
	beq .L_0200b990
	mov r3, #0x1
	mov r0, r0, lsr #0x1
	mov ip, r1, lsr #0x17
	mov r1, r1, lsl #0x8
	ands ip, ip, #0xff
	beq .L_0200b9b4
	cmp ip, #0xff
	beq .L_0200b94c
	orr r1, r1, #0x80000000
	orr r3, r3, r2, lsr #0x17
	orr ip, ip, r2, lsr #0x17
	b .L_0200b894
.L_0200b990:
	mov r3, r1, lsr #0x17
	mov r0, r1, lsl #0x9
	ands r3, r3, #0xff
	beq .L_0200ba1c
	cmp r3, #0xff
	blt .L_0200ba1c
	cmp r0, #0x0
	beq .L_0200ba5c
	b .L_0200ba54
.L_0200b9b4:
	movs r1, r1, lsl #0x1
	beq .L_0200ba24
	mov r1, r1, lsr #0x1
	mov ip, #0x1
	orr r3, r3, r2, lsr #0x17
	orr ip, ip, r2, lsr #0x17
	cmp r0, #0x0
	bmi .L_0200b894
	adds r0, r0, r1
	blo .L_0200b9e8
	and r1, r0, #0x1
	orr r0, r1, r0, rrx
	add ip, ip, #0x1
.L_0200b9e8:
	cmp r0, #0x0
	subge ip, ip, #0x1
	ands r1, r0, #0xff
	add r0, r0, r0
	mov r0, r0, lsr #0x9
	orr r0, r0, ip, lsl #0x17
	bxeq lr
	tst r1, #0x80
	bxeq lr
	ands r1, r1, #0x7f
	andeqs r1, r0, #0x1
	addne r0, r0, #0x1
	bx lr
.L_0200ba1c:
	mov r0, r1
	bx lr
.L_0200ba24:
	cmp r0, #0x0
	subges r3, r3, #0x1
	add r0, r0, r0
	orr r0, r2, r0, lsr #0x9
	orr r0, r0, r3, lsl #0x17
	bx lr
.L_0200ba3c:
	cmp r3, #0x100
	movge r2, #0x80000000
	movlt r2, #0x0
	mov r0, #0xff000000
	orr r0, r2, r0, lsr #0x1
	bx lr
.L_0200ba54:
	mvn r0, #0x80000000
	bx lr
.L_0200ba5c:
	mov r0, #0xff000000
	orr r0, r2, r0, lsr #0x1
	bx lr
.L_0200ba68:
	mvn r0, #0x80000000
	bx lr
	.size _fadd, .-_fadd

	.global func_0200ba70
	.type func_0200ba70, @function
func_0200ba70:
	mvn r0, #0x80000000
	bx lr
	.size func_0200ba70, .-func_0200ba70

	.global _frsb
	.type _frsb, @function
_frsb:
	eor r0, r0, r1
	eor r1, r0, r1
	eor r0, r0, r1
	.size _frsb, .-_frsb

	.global _fsub
	.type _fsub, @function
_fsub:
	eors r2, r0, r1
	eormi r1, r1, #0x80000000
	bmi _fadd+0xc
	subs ip, r0, r1
	eorlo ip, ip, #0x80000000
	sublo r0, r0, ip
	addlo r1, r1, ip
	mov r2, #0x80000000
	mov r3, r0, lsr #0x17
	orr r0, r2, r0, lsl #0x8
	ands ip, r3, #0xff
	cmpne ip, #0xff
	beq .L_0200bbac
	mov ip, r1, lsr #0x17
	orr r1, r2, r1, lsl #0x8
	ands r2, ip, #0xff
	beq .L_0200bbec
.L_0200bac8:
	subs ip, r3, ip
	beq .L_0200bb10
	rsb r2, ip, #0x20
	movs r2, r1, lsl r2
	mov r1, r1, lsr ip
	orrne r1, r1, #0x1
	subs r0, r0, r1
	bpl .L_0200bb54
	ands r1, r0, #0xff
	add r0, r0, r0
	mov r0, r0, lsr #0x9
	orr r0, r0, r3, lsl #0x17
	tst r1, #0x80
	bxeq lr
	ands r1, r1, #0x7f
	andeqs r1, r0, #0x1
	addne r0, r0, #0x1
	bx lr
.L_0200bb10:
	subs r0, r0, r1
	beq .L_0200bcb8
	mov r2, r3, lsl #0x17
	and r2, r2, #0x80000000
	bic r3, r3, #0x100
	clz ip, r0
	movs r0, r0, lsl ip
	sub r3, r3, ip
	cmp r3, #0x0
	bgt .L_0200bb44
	rsb r3, r3, #0x9
	orr r0, r2, r0, lsr r3
	bx lr
.L_0200bb44:
	add r0, r0, r0
	orr r0, r2, r0, lsr #0x9
	orr r0, r0, r3, lsl #0x17
	bx lr
.L_0200bb54:
	mov r2, r3, lsl #0x17
	and r2, r2, #0x80000000
	bic r3, r3, #0x100
	clz ip, r0
	movs r0, r0, lsl ip
	sub r3, r3, ip
	cmp r3, #0x0
	bgt .L_0200bb80
	rsb r3, r3, #0x9
	orr r0, r2, r0, lsr r3
	bx lr
.L_0200bb80:
	ands r1, r0, #0xff
	add r0, r0, r0
	orr r0, r2, r0, lsr #0x9
	orr r0, r0, r3, lsl #0x17
	bxeq lr
	tst r1, #0x80
	bxeq lr
	ands r1, r1, #0x7f
	andeqs r1, r0, #0x1
	addne r0, r0, #0x1
	bx lr
.L_0200bbac:
	cmp r3, #0x100
	movge r2, #0x80000000
	movlt r2, #0x0
	ands r3, r3, #0xff
	beq .L_0200bc14
	movs r0, r0, lsl #0x1
	bne .L_0200bcec
	mov ip, r1, lsr #0x17
	mov r1, r1, lsl #0x9
	ands ip, ip, #0xff
	beq .L_0200bce0
	cmp ip, #0xff
	blt .L_0200bce0
	cmp r1, #0x0
	beq .L_0200bcf4
	b .L_0200bcec
.L_0200bbec:
	cmp ip, #0x100
	movge r2, #0x80000000
	movlt r2, #0x0
	and r3, r3, #0xff
	ands ip, ip, #0xff
	beq .L_0200bc7c
.L_0200bc04:
	eor r2, r2, #0x80000000
	movs r1, r1, lsl #0x1
	bne .L_0200bcec
	b .L_0200bce0
.L_0200bc14:
	movs r0, r0, lsl #0x1
	beq .L_0200bc4c
	mov r0, r0, lsr #0x1
	mov r3, #0x1
	mov ip, r1, lsr #0x17
	mov r1, r1, lsl #0x8
	ands ip, ip, #0xff
	beq .L_0200bc7c
	cmp ip, #0xff
	beq .L_0200bc04
	orr r1, r1, #0x80000000
	orr r3, r3, r2, lsr #0x17
	orr ip, ip, r2, lsr #0x17
	b .L_0200bac8
.L_0200bc4c:
	mov r3, r1, lsr #0x17
	mov r0, r1, lsl #0x9
	ands r2, r3, #0xff
	beq .L_0200bc70
	cmp r2, #0xff
	blt .L_0200bc98
	cmp r0, #0x0
	bne .L_0200bcd8
	b .L_0200bce0
.L_0200bc70:
	cmp r0, #0x0
	beq .L_0200bcb8
	b .L_0200bc98
.L_0200bc7c:
	movs r1, r1, lsl #0x1
	beq .L_0200bca0
	mov r1, r1, lsr #0x1
	mov ip, #0x1
	orr ip, ip, r2, lsr #0x17
	orr r3, r3, r2, lsr #0x17
	b .L_0200bac8
.L_0200bc98:
	mov r0, r1
	bx lr
.L_0200bca0:
	cmp r0, #0x0
	subges r3, r3, #0x1
	add r0, r0, r0
	orr r0, r2, r0, lsr #0x9
	orr r0, r0, r3, lsl #0x17
	bx lr
.L_0200bcb8:
	mov r0, #0x0
	bx lr
	cmp r0, #0x0
	subges r3, r3, #0x1
	add r0, r0, r0
	mov r0, r0, lsr #0x9
	orr r0, r0, r3, lsl #0x17
	bx lr
.L_0200bcd8:
	mvn r0, #0x80000000
	bx lr
.L_0200bce0:
	mov r0, #0xff000000
	orr r0, r2, r0, lsr #0x1
	bx lr
.L_0200bcec:
	mvn r0, #0x80000000
	bx lr
.L_0200bcf4:
	mvn r0, #0x80000000
	bx lr
	.size _fsub, .-_fsub

	.global _frdiv
	.type _frdiv, @function
_frdiv:
	eor r0, r0, r1
	eor r1, r0, r1
	eor r0, r0, r1
	.size _frdiv, .-_frdiv
