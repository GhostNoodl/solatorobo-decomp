// CodeWarrior ARM soft-float runtime (FP_fastI_v5t_LE), hand-written assembly.

#pragma force_active on

asm void _dls(void) {
    mov ip, #0x200000
    cmn ip, r1, lsl #0x1
    bhs @L0200acec
    cmn ip, r3, lsl #0x1
    bhs @L0200ad00
@L0200ac88:
    orrs ip, r3, r1
    bmi @L0200acb8
    cmp r1, r3
    cmpeq r0, r2
    movlo r0, #0x1
    movhs r0, #0x0
    bx lr
@L0200aca4:
    mov r0, #0x0
    mrs ip, cpsr
    orr ip, ip, #0x20000000
    msr cpsr_f, ip
    bx lr
@L0200acb8:
    orr ip, r0, ip, lsl #0x1
    orrs ip, ip, r2
    moveq r0, #0x0
    bne @L0200acd8
    mrs ip, cpsr
    orr ip, ip, #0x20000000
    msr cpsr_f, ip
    bxeq lr
@L0200acd8:
    cmp r3, r1
    cmpeq r2, r0
    movlo r0, #0x1
    movhs r0, #0x0
    bx lr
@L0200acec:
    bne @L0200aca4
    cmp r0, #0x0
    bhi @L0200aca4
    cmn ip, r3, lsl #0x1
    blo @L0200ac88
@L0200ad00:
    bne @L0200aca4
    cmp r2, #0x0
    bhi @L0200aca4
    b @L0200ac88
}

asm void _deq(void) {
    mov ip, #0x200000
    cmn ip, r1, lsl #0x1
    bhs @L0200ad78
    cmn ip, r3, lsl #0x1
    bhs @L0200ad8c
@L0200ad24:
    orrs ip, r3, r1
    bmi @L0200ad54
    cmp r1, r3
    cmpeq r0, r2
    moveq r0, #0x1
    movne r0, #0x0
    bx lr
@L0200ad40:
    mov r0, #0x0
    mrs ip, cpsr
    bic ip, ip, #0x40000000
    msr cpsr_f, ip
    bx lr
@L0200ad54:
    orr ip, r0, ip, lsl #0x1
    orrs ip, ip, r2
    moveq r0, #0x1
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    moveq r0, #0x1
    movne r0, #0x0
    bx lr
@L0200ad78:
    bne @L0200ad40
    cmp r0, #0x0
    bhi @L0200ad40
    cmn ip, r3, lsl #0x1
    blo @L0200ad24
@L0200ad8c:
    bne @L0200ad40
    cmp r2, #0x0
    bhi @L0200ad40
    b @L0200ad24
}

asm void _dneq(void) {
    mov ip, #0x200000
    cmn ip, r1, lsl #0x1
    bhs @L0200ae04
    cmn ip, r3, lsl #0x1
    bhs @L0200ae18
@L0200adb0:
    orrs ip, r3, r1
    bmi @L0200ade0
    cmp r1, r3
    cmpeq r0, r2
    movne r0, #0x1
    moveq r0, #0x0
    bx lr
@L0200adcc:
    mov r0, #0x1
    mrs ip, cpsr
    bic ip, ip, #0x40000000
    msr cpsr_f, ip
    bx lr
@L0200ade0:
    orr ip, r0, ip, lsl #0x1
    orrs ip, ip, r2
    moveq r0, #0x0
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    movne r0, #0x1
    moveq r0, #0x0
    bx lr
@L0200ae04:
    bne @L0200adcc
    cmp r0, #0x0
    bhi @L0200adcc
    cmn ip, r3, lsl #0x1
    blo @L0200adb0
@L0200ae18:
    bne @L0200adcc
    cmp r2, #0x0
    bhi @L0200adcc
    b @L0200adb0
}

asm int _fgr(register float a, register float b) {
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    cmphs r3, r1, lsl #1
    blo @nan
    cmp r0, #0
    bicmi r0, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r1, #0
    bicmi r1, r1, #0x80000000
    rsbmi r1, r1, #0
    cmp r0, r1
    movgt r0, #1
    movle r0, #0
    mrs ip, cpsr
    bicle ip, ip, #0x20000000
    orrgt ip, ip, #0x20000000
    msr cpsr_f, ip
    bx lr
@nan:
    mov r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x20000000
    msr cpsr_f, ip
    bx lr
}

asm int _fneq(register float a, register float b) {
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    blo @nan
    cmp r3, r1, lsl #1
    blo @nan
    orr r3, r0, r1
    movs r3, r3, lsl #1
    moveq r0, #0
    bne @cmp
    mrs ip, cpsr
    orr ip, ip, #0x40000000
    msr cpsr_f, ip
    bx lr
@cmp:
    cmp r0, r1
    movne r0, #1
    moveq r0, #0
    mrs ip, cpsr
    bicne ip, ip, #0x40000000
    orreq ip, ip, #0x40000000
    msr cpsr_f, ip
    bx lr
@nan:
    mov r0, #1
    mrs ip, cpsr
    bic ip, ip, #0x40000000
    msr cpsr_f, ip
    bx lr
}

asm float _fflt(register int x) {
    ands r2, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r0, #0
    bxeq lr
    clz r3, r0
    movs r0, r0, lsl r3
    rsb r3, r3, #0x9e
    ands r1, r0, #0xff
    add r0, r0, r0
    orr r0, r2, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bxeq lr
    tst r1, #0x80
    bxeq lr
    ands r3, r1, #0x7f
    andeqs r3, r0, #1
    addne r0, r0, #1
    bx lr
}

asm float _ffltu(register unsigned int x) {
    cmp r0, #0
    bxeq lr
    mov r3, #0x9e
    bmi @round
    clz ip, r0
    movs r0, r0, lsl ip
    sub r3, r3, ip
@round:
    ands r2, r0, #0xff
    add r0, r0, r0
    mov r0, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bxeq lr
    tst r2, #0x80
    bxeq lr
    ands r1, r2, #0x7f
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
}
