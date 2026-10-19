// CodeWarrior ARM soft-float runtime (FP_fastI_v5t_LE), hand-written assembly.
// Branches into a neighbouring routine are emitted as raw words (dcd), since
// MWCC asm labels are local to one asm function.

#pragma force_active on

void _dadd(void);
void _drsb(void);
void _dsub(void);

asm void _dadd(void) {
    stmfd sp!, {r4, lr}
    eors ip, r1, r3
    eormi r3, r3, #0x80000000
    dcd 0x4a0000cb // bmi _dsub+0x10
    subs ip, r0, r2
    sbcs lr, r1, r3
    bhs @L0200a258
    adds r2, r2, ip
    adc r3, r3, lr
    subs r0, r0, ip
    sbc r1, r1, lr
@L0200a258:
    mov lr, #0x80000000
    mov ip, r1, lsr #0x14
    orr r1, lr, r1, lsl #0xb
    orr r1, r1, r0, lsr #0x15
    mov r0, r0, lsl #0xb
    movs r4, ip, lsl #0x15
    cmnne r4, #0x200000
    beq @L0200a354
    mov r4, r3, lsr #0x14
    orr r3, lr, r3, lsl #0xb
    orr r3, r3, r2, lsr #0x15
    mov r2, r2, lsl #0xb
    movs lr, r4, lsl #0x15
    beq @L0200a39c
@L0200a290:
    subs r4, ip, r4
    beq @L0200a2e8
    cmp r4, #0x20
    ble @L0200a2cc
    cmp r4, #0x38
    movge r4, #0x3f
    sub r4, r4, #0x20
    rsb lr, r4, #0x20
    orrs lr, r2, r3, lsl lr
    mov r2, r3, lsr r4
    orrne r2, r2, #0x1
    adds r0, r0, r2
    adcs r1, r1, #0x0
    blo @L0200a310
    b @L0200a2f4
@L0200a2cc:
    rsb lr, r4, #0x20
    movs lr, r2, lsl lr
    rsb lr, r4, #0x20
    mov r2, r2, lsr r4
    orr r2, r2, r3, lsl lr
    mov r3, r3, lsr r4
    orrne r2, r2, #0x1
@L0200a2e8:
    adds r0, r0, r2
    adcs r1, r1, r3
    blo @L0200a310
@L0200a2f4:
    add ip, ip, #0x1
    and r4, r0, #0x1
    movs r1, r1, rrx
    orr r0, r4, r0, rrx
    mov lr, ip, lsl #0x15
    cmn lr, #0x200000
    beq @L0200a520
@L0200a310:
    movs r2, r0, lsl #0x15
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #0x15
    add r1, r1, r1
    mov r1, r1, lsr #0xc
    orr r1, r1, ip, lsl #0x14
    tst r2, #0x80000000
    ldmeqfd sp!, {r4, lr}
    bxeq lr
    movs r2, r2, lsl #0x1
    andeqs r2, r0, #0x1
    ldmeqfd sp!, {r4, lr}
    bxeq lr
    adds r0, r0, #0x1
    adc r1, r1, #0x0
    ldmfd sp!, {r4, lr}
    bx lr
@L0200a354:
    cmp ip, #0x800
    movge lr, #0x80000000
    movlt lr, #0x0
    bics ip, ip, #0x800
    beq @L0200a3c0
    orrs r4, r0, r1, lsl #0x1
    bne @L0200a4fc
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #0x15
    mov r2, r2, lsl #0xb
    movs r4, r4, lsl #0x15
    beq @L0200a4e8
    cmn r4, #0x200000
    bne @L0200a4e8
    orrs r4, r2, r3, lsl #0x1
    beq @L0200a4e8
    b @L0200a4fc
@L0200a39c:
    cmp r4, #0x800
    movge lr, #0x80000000
    movlt lr, #0x0
    bic ip, ip, #0x800
    bics r4, r4, #0x800
    beq @L0200a42c
    orrs r4, r2, r3, lsl #0x1
    bne @L0200a4fc
    b @L0200a4e8
@L0200a3c0:
    orrs r4, r0, r1, lsl #0x1
    beq @L0200a400
    mov ip, #0x1
    bic r1, r1, #0x80000000
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #0x15
    mov r2, r2, lsl #0xb
    movs r4, r4, lsl #0x15
    cmnne r4, #0x200000
    mov r4, r4, lsr #0x15
    orr r4, r4, lr, lsr #0x14
    beq @L0200a39c
    orr r3, r3, #0x80000000
    orr ip, ip, lr, lsr #0x14
    b @L0200a290
@L0200a400:
    mov ip, r3, lsr #0x14
    mov r1, r3, lsl #0xb
    orr r1, r1, r2, lsr #0x15
    mov r0, r2, lsl #0xb
    movs r4, ip, lsl #0x15
    beq @L0200a4b4
    cmn r4, #0x200000
    bne @L0200a4b4
    orrs r4, r0, r1, lsl #0x1
    beq @L0200a4e8
    b @L0200a500
@L0200a42c:
    orrs r4, r2, r3, lsl #0x1
    beq @L0200a4c4
    mov r4, #0x1
    bic r3, r3, #0x80000000
    cmp r1, #0x0
    bpl @L0200a450
    orr ip, ip, lr, lsr #0x14
    orr r4, r4, lr, lsr #0x14
    b @L0200a290
@L0200a450:
    adds r0, r0, r2
    adcs r1, r1, r3
    blo @L0200a470
    add ip, ip, #0x1
    and r4, r0, #0x1
    movs r1, r1, rrx
    mov r0, r0, rrx
    orr r0, r0, r4
@L0200a470:
    cmp r1, #0x0
    subges ip, ip, #0x1
    movs r2, r0, lsl #0x15
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #0x15
    add r1, r1, r1
    orr r1, lr, r1, lsr #0xc
    orr r1, r1, ip, lsl #0x14
    ldmeqfd sp!, {r4, lr}
    bxeq lr
    tst r2, #0x80000000
    ldmeqfd sp!, {r4, lr}
    bxeq lr
    movs r2, r2, lsl #0x1
    andeqs r2, r0, #0x1
    ldmeqfd sp!, {r4, lr}
    bxeq lr
@L0200a4b4:
    mov r1, r3
    mov r0, r2
    ldmfd sp!, {r4, lr}
    bx lr
@L0200a4c4:
    cmp r1, #0x0
    subges ip, ip, #0x1
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #0x15
    add r1, r1, r1
    orr r1, lr, r1, lsr #0xc
    orr r1, r1, ip, lsl #0x14
    ldmfd sp!, {r4, lr}
    bx lr
@L0200a4e8:
    ldr r1, =0x7ff00000
    orr r1, lr, r1
    mov r0, #0x0
    ldmfd sp!, {r4, lr}
    bx lr
@L0200a4fc:
    mov r1, r3
@L0200a500:
    mvn r0, #0x0
    bic r1, r0, #0x80000000
    ldmfd sp!, {r4, lr}
    bx lr
    mvn r0, #0x0
    bic r1, r0, #0x80000000
    ldmfd sp!, {r4, lr}
    bx lr
@L0200a520:
    cmp ip, #0x800
    movge lr, #0x80000000
    movlt lr, #0x0
    ldr r1, =0x7ff00000
    orr r1, lr, r1
    mov r0, #0x0
    ldmfd sp!, {r4, lr}
    bx lr
}

asm void _drsb(void) {
    eor r1, r1, r3
    eor r3, r1, r3
    eor r1, r1, r3
    eor r0, r0, r2
    eor r2, r0, r2
    eor r0, r0, r2
}

asm void _dsub(void) {
    stmfd sp!, {r4, lr}
    eors ip, r1, r3
    eormi r3, r3, #0x80000000
    dcd 0x4affff33 // bmi _dadd+0x10
    subs ip, r0, r2
    sbcs lr, r1, r3
    bhs @L0200a58c
    eor lr, lr, #0x80000000
    adds r2, r2, ip
    adc r3, r3, lr
    subs r0, r0, ip
    sbc r1, r1, lr
@L0200a58c:
    mov lr, #0x80000000
    mov ip, r1, lsr #0x14
    orr r1, lr, r1, lsl #0xb
    orr r1, r1, r0, lsr #0x15
    mov r0, r0, lsl #0xb
    movs r4, ip, lsl #0x15
    cmnne r4, #0x200000
    beq @L0200a790
    mov r4, r3, lsr #0x14
    orr r3, lr, r3, lsl #0xb
    orr r3, r3, r2, lsr #0x15
    mov r2, r2, lsl #0xb
    movs lr, r4, lsl #0x15
    beq @L0200a7d8
@L0200a5c4:
    subs r4, ip, r4
    beq @L0200a66c
    cmp r4, #0x20
    ble @L0200a600
    cmp r4, #0x38
    movge r4, #0x3f
    sub r4, r4, #0x20
    rsb lr, r4, #0x20
    orrs lr, r2, r3, lsl lr
    mov r2, r3, lsr r4
    orrne r2, r2, #0x1
    subs r0, r0, r2
    sbcs r1, r1, #0x0
    bmi @L0200a628
    b @L0200a718
@L0200a600:
    rsb lr, r4, #0x20
    movs lr, r2, lsl lr
    rsb lr, r4, #0x20
    mov r2, r2, lsr r4
    orr r2, r2, r3, lsl lr
    mov r3, r3, lsr r4
    orrne r2, r2, #0x1
    subs r0, r0, r2
    sbcs r1, r1, r3
    bpl @L0200a718
@L0200a628:
    movs r2, r0, lsl #0x15
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #0x15
    add r1, r1, r1
    mov r1, r1, lsr #0xc
    orr r1, r1, ip, lsl #0x14
    tst r2, #0x80000000
    ldmeqfd sp!, {r4, lr}
    bxeq lr
    movs r2, r2, lsl #0x1
    andeqs r2, r0, #0x1
    ldmeqfd sp!, {r4, lr}
    bxeq lr
    adds r0, r0, #0x1
    adc r1, r1, #0x0
    ldmfd sp!, {r4, lr}
    bx lr
@L0200a66c:
    subs r0, r0, r2
    sbc r1, r1, r3
    orrs lr, r1, r0
    beq @L0200a8fc
    mov lr, ip, lsl #0x14
    and lr, lr, #0x80000000
    bic ip, ip, #0x800
    cmp r1, #0x0
    bmi @L0200a6f4
    bne @L0200a6a4
    sub ip, ip, #0x20
    movs r1, r0
    mov r0, #0x0
    bmi @L0200a6c0
@L0200a6a4:
    clz r4, r1
    movs r1, r1, lsl r4
    rsb r4, r4, #0x20
    orr r1, r1, r0, lsr r4
    rsb r4, r4, #0x20
    mov r0, r0, lsl r4
    sub ip, ip, r4
@L0200a6c0:
    cmp ip, #0x0
    bgt @L0200a6fc
    rsb ip, ip, #0xc
    cmp ip, #0x20
    movge r0, r1
    movge r1, #0x0
    subge ip, ip, #0x20
    rsb r4, ip, #0x20
    mov r0, r0, lsr ip
    orr r0, r0, r1, lsl r4
    orr r1, lr, r1, lsr ip
    ldmfd sp!, {r4, lr}
    bx lr
@L0200a6f4:
    cmp r1, #0x0
    subges ip, ip, #0x1
@L0200a6fc:
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #0x15
    add r1, r1, r1
    orr r1, lr, r1, lsr #0xc
    orr r1, r1, ip, lsl #0x14
    ldmfd sp!, {r4, lr}
    bx lr
@L0200a718:
    mov lr, ip, lsl #0x14
    and lr, lr, #0x80000000
    bic ip, ip, #0x800
    cmp r1, #0x0
    bne @L0200a73c
    sub ip, ip, #0x20
    movs r1, r0
    mov r0, #0x0
    bmi @L0200a758
@L0200a73c:
    clz r4, r1
    movs r1, r1, lsl r4
    rsb r4, r4, #0x20
    orr r1, r1, r0, lsr r4
    rsb r4, r4, #0x20
    mov r0, r0, lsl r4
    sub ip, ip, r4
@L0200a758:
    cmp ip, #0x0
    orrgt ip, ip, lr, lsr #0x14
    bgt @L0200a628
    rsb ip, ip, #0xc
    cmp ip, #0x20
    movge r0, r1
    movge r1, #0x0
    subge ip, ip, #0x20
    rsb r4, ip, #0x20
    mov r0, r0, lsr ip
    orr r0, r0, r1, lsl r4
    orr r1, lr, r1, lsr ip
    ldmfd sp!, {r4, lr}
    bx lr
@L0200a790:
    cmp ip, #0x800
    movge lr, #0x80000000
    movlt lr, #0x0
    bics ip, ip, #0x800
    beq @L0200a7fc
    orrs r4, r0, r1, lsl #0x1
    bne @L0200a8d8
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #0x15
    mov r2, r2, lsl #0xb
    movs r4, r4, lsl #0x15
    beq @L0200a8c4
    cmn r4, #0x200000
    bne @L0200a8c4
    orrs r4, r2, r3, lsl #0x1
    beq @L0200a8ec
    b @L0200a8d8
@L0200a7d8:
    cmp r4, #0x800
    movge lr, #0x80000000
    movlt lr, #0x0
    bic ip, ip, #0x800
    bics r4, r4, #0x800
    beq @L0200a874
    orrs r4, r2, r3, lsl #0x1
    bne @L0200a8d8
    b @L0200a8c4
@L0200a7fc:
    orrs r4, r0, r1, lsl #0x1
    beq @L0200a83c
    mov ip, #0x1
    bic r1, r1, #0x80000000
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #0x15
    mov r2, r2, lsl #0xb
    movs r4, r4, lsl #0x15
    cmnne r4, #0x200000
    mov r4, r4, lsr #0x15
    orr r4, r4, lr, lsr #0x14
    beq @L0200a7d8
    orr r3, r3, #0x80000000
    orr ip, ip, lr, lsr #0x14
    b @L0200a5c4
@L0200a83c:
    mov ip, r3, lsr #0x14
    mov r1, r3, lsl #0xb
    orr r1, r1, r2, lsr #0x15
    mov r0, r2, lsl #0xb
    movs r4, ip, lsl #0x15
    beq @L0200a868
    cmn r4, #0x200000
    bne @L0200a890
    orrs r4, r0, r1, lsl #0x1
    bne @L0200a8dc
    b @L0200a8c4
@L0200a868:
    orrs r4, r0, r1, lsl #0x1
    beq @L0200a8fc
    b @L0200a890
@L0200a874:
    orrs r4, r2, r3, lsl #0x1
    beq @L0200a8a0
    mov r4, #0x1
    bic r3, r3, #0x80000000
    orr ip, ip, lr, lsr #0x14
    orr r4, r4, lr, lsr #0x14
    b @L0200a5c4
@L0200a890:
    mov r1, r3
    mov r0, r2
    ldmfd sp!, {r4, lr}
    bx lr
@L0200a8a0:
    cmp r1, #0x0
    subges ip, ip, #0x1
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #0x15
    add r1, r1, r1
    orr r1, lr, r1, lsr #0xc
    orr r1, r1, ip, lsl #0x14
    ldmfd sp!, {r4, lr}
    bx lr
@L0200a8c4:
    ldr r1, =0x7ff00000
    orr r1, lr, r1
    mov r0, #0x0
    ldmfd sp!, {r4, lr}
    bx lr
@L0200a8d8:
    mov r1, r3
@L0200a8dc:
    mvn r0, #0x0
    bic r1, r0, #0x80000000
    ldmfd sp!, {r4, lr}
    bx lr
@L0200a8ec:
    mvn r0, #0x0
    bic r1, r0, #0x80000000
    ldmfd sp!, {r4, lr}
    bx lr
@L0200a8fc:
    mov r1, #0x0
    mov r0, #0x0
    ldmfd sp!, {r4, lr}
    bx lr
}

