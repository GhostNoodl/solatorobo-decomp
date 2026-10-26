// DSProtect (anti-piracy middleware), hand-written assembly: self-checksumming stubs whose
// trailing words are relocated pointers/keys, so they are emitted as dcd.

#pragma force_active on

extern char DSProt_BSS[];
extern char func_ov004_021cd050[];
extern char func_ov004_021cd16c[];
extern char func_ov004_021cd288[];
extern char func_ov004_021cd3a4[];
void func_ov004_021ce574(void);
extern char func_ov004_021ce7d8[];
void func_ov004_021cd4c0(void);
void func_ov004_021cd548(void);
void func_ov004_021cd5d0(void);
void func_ov004_021cd658(void);
void func_ov004_021cd6e0(void);

asm void func_ov004_021cd4c0(void) {
    orr r12, pc, pc
    ands r12, r12, r12
    moveq r12, #0
    addne r12, r12, #0x68
    ldr r12, [r12, #0x14]
    sub r12, r12, #0
    stmfd sp!, {r0, r1, r2, r3, r4}
    mov r1, r12, lsr #0x1a
    eor r3, r3, r3
    mov r12, r12, lsl #6
    mov r12, r12, lsr #6
    mov r0, r12
@L021cd4f0:
    ldr r2, [r0]
    mov r4, r2, lsr #0x18
    cmp r4, #0xea
    cmpne r4, #0xeb
    eorne r3, r3, r2, ror #17
    addne r3, r3, r2, ror #28
    eorne r3, r3, r2, ror r1
    subs r1, r1, #1
    add r0, r0, #4
    bne @L021cd4f0
    streq r3, [pc, #0x14]
    ldmeqfd sp!, {r0, r1, r2, r3, r4}
    ldmnefd sp!, {r5, r6, r7, r8, r9}
    stmeqdb sp!, {r12}
    orr r12, pc, pc
    ldmeqia sp!, {pc}
    dcd DSProt_BSS+0x1
    dcd DSProt_BSS+0x3
    dcd func_ov004_021cd050+0x3200
    dcd DSProt_BSS+0x3310
    dcd 0x00000000
    dcd func_ov004_021ce7d8+0x68000000
}

asm void func_ov004_021cd548(void) {
    orr r12, pc, pc
    ands r12, r12, r12
    moveq r12, #0
    addne r12, r12, #0x68
    ldr r12, [r12, #0x14]
    sub r12, r12, #0
    stmfd sp!, {r0, r1, r2, r3, r4}
    mov r1, r12, lsr #0x1a
    eor r3, r3, r3
    mov r12, r12, lsl #6
    mov r12, r12, lsr #6
    mov r0, r12
@L021cd578:
    ldr r2, [r0]
    mov r4, r2, lsr #0x18
    cmp r4, #0xea
    cmpne r4, #0xeb
    eorne r3, r3, r2, ror #17
    addne r3, r3, r2, ror #28
    eorne r3, r3, r2, ror r1
    subs r1, r1, #1
    add r0, r0, #4
    bne @L021cd578
    streq r3, [pc, #0x14]
    ldmeqfd sp!, {r0, r1, r2, r3, r4}
    ldmnefd sp!, {r5, r6, r7, r8, r9}
    stmeqdb sp!, {r12}
    orr r12, pc, pc
    ldmeqia sp!, {pc}
    dcd DSProt_BSS+0x1
    dcd DSProt_BSS+0x3
    dcd func_ov004_021cd16c+0x3200
    dcd DSProt_BSS+0x3310
    dcd 0x00000000
    dcd func_ov004_021ce7d8+0x68000000
}

asm void func_ov004_021cd5d0(void) {
    orr r12, pc, pc
    ands r12, r12, r12
    moveq r12, #0
    addne r12, r12, #0x68
    ldr r12, [r12, #0x14]
    sub r12, r12, #0
    stmfd sp!, {r0, r1, r2, r3, r4}
    mov r1, r12, lsr #0x1a
    eor r3, r3, r3
    mov r12, r12, lsl #6
    mov r12, r12, lsr #6
    mov r0, r12
@L021cd600:
    ldr r2, [r0]
    mov r4, r2, lsr #0x18
    cmp r4, #0xea
    cmpne r4, #0xeb
    eorne r3, r3, r2, ror #17
    addne r3, r3, r2, ror #28
    eorne r3, r3, r2, ror r1
    subs r1, r1, #1
    add r0, r0, #4
    bne @L021cd600
    streq r3, [pc, #0x14]
    ldmeqfd sp!, {r0, r1, r2, r3, r4}
    ldmnefd sp!, {r5, r6, r7, r8, r9}
    stmeqdb sp!, {r12}
    orr r12, pc, pc
    ldmeqia sp!, {pc}
    dcd DSProt_BSS+0x1
    dcd DSProt_BSS+0x3
    dcd func_ov004_021cd288+0x3200
    dcd DSProt_BSS+0x3310
    dcd 0x00000000
    dcd func_ov004_021ce7d8+0x68000000
}

asm void func_ov004_021cd658(void) {
    orr r12, pc, pc
    ands r12, r12, r12
    moveq r12, #0
    addne r12, r12, #0x68
    ldr r12, [r12, #0x14]
    sub r12, r12, #0
    stmfd sp!, {r0, r1, r2, r3, r4}
    mov r1, r12, lsr #0x1a
    eor r3, r3, r3
    mov r12, r12, lsl #6
    mov r12, r12, lsr #6
    mov r0, r12
@L021cd688:
    ldr r2, [r0]
    mov r4, r2, lsr #0x18
    cmp r4, #0xea
    cmpne r4, #0xeb
    eorne r3, r3, r2, ror #17
    addne r3, r3, r2, ror #28
    eorne r3, r3, r2, ror r1
    subs r1, r1, #1
    add r0, r0, #4
    bne @L021cd688
    streq r3, [pc, #0x14]
    ldmeqfd sp!, {r0, r1, r2, r3, r4}
    ldmnefd sp!, {r5, r6, r7, r8, r9}
    stmeqdb sp!, {r12}
    orr r12, pc, pc
    ldmeqia sp!, {pc}
    dcd DSProt_BSS+0x1
    dcd DSProt_BSS+0x3
    dcd func_ov004_021cd3a4+0x3200
    dcd DSProt_BSS+0x3310
    dcd 0x00000000
    dcd func_ov004_021ce7d8+0x68000000
}

asm void func_ov004_021cd6e0(void) {
    orr r0, pc, #0
    adds r0, r0, #4
    bne func_ov004_021ce574
    dcd func_ov004_021cd4c0+0x3200
    dcd DSProt_BSS+0x3270
    dcd func_ov004_021cd548+0x3200
    dcd DSProt_BSS+0x3270
    dcd func_ov004_021cd5d0+0x3200
    dcd DSProt_BSS+0x3270
    dcd func_ov004_021cd658+0x3200
    dcd DSProt_BSS+0x3270
    dcd 0x00000000
    dcd 0x00000000
}

