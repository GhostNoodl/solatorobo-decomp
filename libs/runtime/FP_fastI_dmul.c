// CodeWarrior ARM soft-float runtime (FP_fastI_v5t_LE), hand-written assembly.
// Branches into a neighbouring routine are emitted as raw words (dcd), since
// MWCC asm labels are local to one asm function.

#pragma force_active on

void _dmul(void);

asm void _dmul(void) {
    stmfd sp!, {r4, r5, r6, r7, lr}
    eor lr, r1, r3
    and lr, lr, #0x80000000
    mov ip, r1, lsr #0x14
    mov r1, r1, lsl #0xb
    orr r1, r1, r0, lsr #0x15
    mov r0, r0, lsl #0xb
    movs r6, ip, lsl #0x15
    cmnne r6, #0x200000
    beq @L0200aa18
    orr r1, r1, #0x80000000
    bic ip, ip, #0x800
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #0x15
    mov r2, r2, lsl #0xb
    movs r5, r4, lsl #0x15
    cmnne r5, #0x200000
    beq @L0200aa60
    orr r3, r3, #0x80000000
    bic r4, r4, #0x800
@L0200a964:
    add ip, r4, ip
    umull r5, r4, r0, r2
    umull r7, r6, r0, r3
    adds r4, r7, r4
    adc r6, r6, #0x0
    umull r7, r0, r1, r2
    adds r4, r7, r4
    adcs r0, r0, r6
    umull r7, r2, r1, r3
    adc r1, r2, #0x0
    adds r0, r0, r7
    adc r1, r1, #0x0
    orrs r4, r4, r5
    orrne r0, r0, #0x1
    cmp r1, #0x0
    blt @L0200a9b0
    sub ip, ip, #0x1
    adds r0, r0, r0
    adc r1, r1, r1
@L0200a9b0:
    add ip, ip, #0x2
    subs ip, ip, #0x400
    bmi @L0200ab4c
    beq @L0200ab4c
    mov r6, ip, lsl #0x14
    cmn r6, #0x100000
    bmi @L0200ac4c
    movs r2, r0, lsl #0x15
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #0x15
    add r1, r1, r1
    orr r1, lr, r1, lsr #0xc
    orr r1, r1, ip, lsl #0x14
    ldmeqfd sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    tst r2, #0x80000000
    ldmeqfd sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    movs r2, r2, lsl #0x1
    andeqs r2, r0, #0x1
    ldmeqfd sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    adds r0, r0, #0x1
    adc r1, r1, #0x0
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
@L0200aa18:
    bics ip, ip, #0x800
    beq @L0200aa74
    orrs r6, r0, r1, lsl #0x1
    bne @L0200ac00
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #0x15
    mov r2, r2, lsl #0xb
    movs r5, r4, lsl #0x15
    beq @L0200aa54
    cmn r5, #0x200000
    bne @L0200abec
    orrs r5, r2, r3, lsl #0x1
    beq @L0200abec
    b @L0200ac00
@L0200aa54:
    orrs r5, r3, r2
    beq @L0200ac14
    b @L0200abec
@L0200aa60:
    bics r4, r4, #0x800
    beq @L0200ab08
    orrs r6, r2, r3, lsl #0x1
    bne @L0200ac00
    b @L0200abec
@L0200aa74:
    orrs r6, r0, r1, lsl #0x1
    beq @L0200aadc
    mov ip, #0x1
    cmp r1, #0x0
    bne @L0200aa98
    sub ip, ip, #0x20
    movs r1, r0
    mov r0, #0x0
    bmi @L0200aab4
@L0200aa98:
    clz r6, r1
    movs r1, r1, lsl r6
    rsb r6, r6, #0x20
    orr r1, r1, r0, lsr r6
    rsb r6, r6, #0x20
    mov r0, r0, lsl r6
    sub ip, ip, r6
@L0200aab4:
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #0x15
    mov r2, r2, lsl #0xb
    movs r5, r4, lsl #0x15
    cmnne r5, #0x200000
    beq @L0200aa60
    orr r3, r3, #0x80000000
    bic r4, r4, #0x800
    b @L0200a964
@L0200aadc:
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #0x15
    mov r2, r2, lsl #0xb
    movs r5, r4, lsl #0x15
    beq @L0200ac60
    cmn r5, #0x200000
    bne @L0200ac60
    orrs r6, r2, r3, lsl #0x1
    beq @L0200ac14
    b @L0200ac00
@L0200ab08:
    orrs r5, r2, r3, lsl #0x1
    beq @L0200ac60
    mov r4, #0x1
    cmp r3, #0x0
    bne @L0200ab2c
    sub r4, r4, #0x20
    movs r3, r2
    mov r2, #0x0
    bmi @L0200a964
@L0200ab2c:
    clz r6, r3
    movs r3, r3, lsl r6
    rsb r6, r6, #0x20
    orr r3, r3, r2, lsr r6
    rsb r6, r6, #0x20
    mov r2, r2, lsl r6
    sub r4, r4, r6
    b @L0200a964
@L0200ab4c:
    cmn ip, #0x34
    beq @L0200abe4
    bmi @L0200ac3c
    mov r2, r1
    mov r3, r0
    add r4, ip, #0x34
    cmp r4, #0x20
    movge r2, r3
    movge r3, #0x0
    subge r4, r4, #0x20
    rsb r5, r4, #0x20
    mov r2, r2, lsl r4
    orr r2, r2, r3, lsr r5
    movs r3, r3, lsl r4
    orrne r2, r2, #0x1
    rsb ip, ip, #0xc
    cmp ip, #0x20
    movge r0, r1
    movge r1, #0x0
    subge ip, ip, #0x20
    rsb r4, ip, #0x20
    mov r0, r0, lsr ip
    orr r0, r0, r1, lsl r4
    orr r1, lr, r1, lsr ip
    cmp r2, #0x0
    ldmeqfd sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    tst r2, #0x80000000
    ldmeqfd sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    movs r2, r2, lsl #0x1
    andeqs r2, r0, #0x1
    ldmeqfd sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    adds r0, r0, #0x1
    adc r1, r1, #0x0
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
@L0200abe4:
    orr r0, r0, r1, lsl #0x1
    b @L0200ac24
@L0200abec:
    ldr r1, =0x7ff00000
    orr r1, lr, r1
    mov r0, #0x0
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
@L0200ac00:
    mov r1, r3
    mvn r0, #0x0
    bic r1, r0, #0x80000000
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
@L0200ac14:
    mvn r0, #0x0
    bic r1, r0, #0x80000000
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
@L0200ac24:
    movs r2, r0
    mov r1, lr
    mov r0, #0x0
    addne r0, r0, #0x1
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
@L0200ac3c:
    mov r1, lr
    mov r0, #0x0
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
@L0200ac4c:
    ldr r1, =0x7ff00000
    orr r1, lr, r1
    mov r0, #0x0
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
@L0200ac60:
    mov r1, lr
    mov r0, #0x0
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
}

