// CodeWarrior ARM soft-float runtime (FP_fastI_v5t_LE), hand-written assembly.
// Branches into a neighbouring routine are emitted as raw words (dcd), since
// MWCC asm labels are local to one asm function.

#pragma force_active on

void _fmul(void);

asm void _fmul(void) {
    eor r2, r0, r1
    and r2, r2, #0x80000000
    mov ip, #0xff
    ands r3, ip, r0, lsr #0x17
    mov r0, r0, lsl #0x8
    cmpne r3, #0xff
    beq @L0200b6f0
    orr r0, r0, #0x80000000
    ands ip, ip, r1, lsr #0x17
    mov r1, r1, lsl #0x8
    cmpne ip, #0xff
    beq @L0200b730
    orr r1, r1, #0x80000000
@L0200b6a8:
    add ip, r3, ip
    umull r1, r3, r0, r1
    movs r0, r3
    addpl r0, r0, r0
    subpl ip, ip, #0x1
    subs ip, ip, #0x7f
    bmi @L0200b7bc
    cmp ip, #0xfe
    bge @L0200b828
    ands r3, r0, #0xff
    orr r0, r2, r0, lsr #0x8
    add r0, r0, ip, lsl #0x17
    tst r3, #0x80
    bxeq lr
    orrs r1, r1, r3, lsl #0x19
    andeqs r3, r0, #0x1
    addne r0, r0, #0x1
    bx lr
@L0200b6f0:
    cmp r3, #0x0
    beq @L0200b744
    movs r0, r0, lsl #0x1
    bne @L0200b818
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #0x9
    ands ip, ip, #0xff
    beq @L0200b724
    cmp ip, #0xff
    blt @L0200b80c
    cmp r1, #0x0
    beq @L0200b80c
    b @L0200b818
@L0200b724:
    cmp r1, #0x0
    beq @L0200b820
    b @L0200b80c
@L0200b730:
    cmp ip, #0x0
    beq @L0200b7a0
@L0200b738:
    movs r1, r1, lsl #0x1
    bne @L0200b818
    b @L0200b80c
@L0200b744:
    movs r0, r0, lsl #0x1
    beq @L0200b77c
    mov r0, r0, lsr #0x1
    clz r3, r0
    movs r0, r0, lsl r3
    rsb r3, r3, #0x1
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #0x8
    ands ip, ip, #0xff
    beq @L0200b7a0
    cmp ip, #0xff
    beq @L0200b738
    orr r1, r1, #0x80000000
    b @L0200b6a8
@L0200b77c:
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #0x9
    ands ip, ip, #0xff
    beq @L0200b84c
    cmp ip, #0xff
    blt @L0200b84c
    cmp r1, #0x0
    beq @L0200b820
    b @L0200b818
@L0200b7a0:
    movs r1, r1, lsl #0x1
    beq @L0200b84c
    mov r1, r1, lsr #0x1
    clz ip, r1
    movs r1, r1, lsl ip
    rsb ip, ip, #0x1
    b @L0200b6a8
@L0200b7bc:
    cmn ip, #0x18
    beq @L0200b804
    bmi @L0200b844
    cmp r1, #0x0
    orrne r0, r0, #0x1
    mov r3, r0
    mov r0, r0, lsr #0x8
    rsb ip, ip, #0x0
    orr r0, r2, r0, lsr ip
    rsb ip, ip, #0x18
    movs r1, r3, lsl ip
    bxeq lr
    tst r1, #0x80000000
    bxeq lr
    movs r1, r1, lsl #0x1
    andeqs r1, r0, #0x1
    addne r0, r0, #0x1
    bx lr
@L0200b804:
    mov r0, r0, lsl #0x1
    b @L0200b834
@L0200b80c:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #0x1
    bx lr
@L0200b818:
    mvn r0, #0x80000000
    bx lr
@L0200b820:
    mvn r0, #0x80000000
    bx lr
@L0200b828:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #0x1
    bx lr
@L0200b834:
    movs r1, r0
    mov r0, r2
    addne r0, r0, #0x1
    bx lr
@L0200b844:
    mov r0, r2
    bx lr
@L0200b84c:
    mov r0, r2
    bx lr
}

