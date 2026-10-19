// CodeWarrior ARM soft-float runtime (FP_fastI_v5t_LE), hand-written assembly.

#pragma force_active on

asm void _ffix(void) {
    bic r1, r0, #0x80000000
    mov r2, #0x9e
    subs r2, r2, r1, lsr #0x17
    ble @L0200b59c
    mov r1, r1, lsl #0x8
    orr r1, r1, #0x80000000
    cmp r0, #0x0
    mov r0, r1, lsr r2
    rsbmi r0, r0, #0x0
    bx lr
@L0200b59c:
    mvn r0, r0, asr #0x1f
    add r0, r0, #0x80000000
    bx lr
}

asm void _ffixu(void) {
    tst r0, #0x80000000
    bne @L0200b5cc
    mov r1, #0x9e
    subs r1, r1, r0, lsr #0x17
    blt @L0200b5e0
    mov r2, r0, lsl #0x8
    orr r0, r2, #0x80000000
    mov r0, r0, lsr r1
    bx lr
@L0200b5cc:
    mov r2, #0xff000000
    cmp r2, r0, lsl #0x1
    movhs r0, #0x0
    mvnlo r0, #0x0
    bx lr
@L0200b5e0:
    mvn r0, #0x0
    bx lr
}

asm void _ll_ufrom_d(void) {
    tst r1, #0x80000000
    bne @L0200b64c
    ldr r2, =0x43e
    subs r2, r2, r1, lsr #0x14
    blt @L0200b664
    cmp r2, #0x40
    bge @L0200b640
    mov ip, r1, lsl #0xb
    orr ip, ip, #0x80000000
    orr ip, ip, r0, lsr #0x15
    cmp r2, #0x20
    ble @L0200b628
    sub r2, r2, #0x20
    mov r1, #0x0
    mov r0, ip, lsr r2
    bx lr
@L0200b628:
    mov r3, r0, lsl #0xb
    mov r1, ip, lsr r2
    mov r0, r3, lsr r2
    rsb r2, r2, #0x20
    orr r0, r0, ip, lsl r2
    bx lr
@L0200b640:
    mov r1, #0x0
    mov r0, #0x0
    bx lr
@L0200b64c:
    cmn r1, #0x100000
    cmpeq r0, #0x0
    bhi @L0200b664
    mov r1, #0x0
    mov r0, #0x0
    bx lr
@L0200b664:
    mvn r1, #0x0
    mvn r0, #0x0
    bx lr
}

