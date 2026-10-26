// DSProtect (anti-piracy middleware), hand-written assembly: self-checksumming stubs whose
// trailing words are relocated pointers/keys, so they are emitted as dcd.
// func_ov004_021cf544 is left in the preceding gap: MWLD does not follow relocations from asm dcd
// words when dead-stripping, so that gap is kept alive by the C reference to this stub instead.

#pragma force_active on

extern char DSProt_BSS[];
extern char func_ov004_021ce7d8[];
extern char func_ov004_021ce874[];
extern char func_ov004_021ce934[];
extern char func_ov004_021ceff8[];
extern char func_ov004_021cea18[];
extern char func_ov004_021cf544[];
void func_ov004_021cf5cc(void);
void func_ov004_021cf654(void);
void func_ov004_021cf6dc(void);
void func_ov004_021cf764(void);
void func_ov004_021ce574(void);

asm void func_ov004_021cf5cc(void) {
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
@L021cf5fc:
    ldr r2, [r0]
    mov r4, r2, lsr #0x18
    cmp r4, #0xea
    cmpne r4, #0xeb
    eorne r3, r3, r2, ror #17
    addne r3, r3, r2, ror #28
    eorne r3, r3, r2, ror r1
    subs r1, r1, #1
    add r0, r0, #4
    bne @L021cf5fc
    streq r3, [pc, #0x14]
    ldmeqfd sp!, {r0, r1, r2, r3, r4}
    ldmnefd sp!, {r5, r6, r7, r8, r9}
    stmeqdb sp!, {r12}
    orr r12, pc, pc
    ldmeqia sp!, {pc}
    dcd DSProt_BSS+0x1
    dcd DSProt_BSS+0x3
    dcd func_ov004_021ceff8+0x3200
    dcd DSProt_BSS+0x3740
    dcd 0x00000000
    dcd func_ov004_021ce7d8+0x68000000
}

asm void func_ov004_021cf654(void) {
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
@L021cf684:
    ldr r2, [r0]
    mov r4, r2, lsr #0x18
    cmp r4, #0xea
    cmpne r4, #0xeb
    eorne r3, r3, r2, ror #17
    addne r3, r3, r2, ror #28
    eorne r3, r3, r2, ror r1
    subs r1, r1, #1
    add r0, r0, #4
    bne @L021cf684
    streq r3, [pc, #0x14]
    ldmeqfd sp!, {r0, r1, r2, r3, r4}
    ldmnefd sp!, {r5, r6, r7, r8, r9}
    stmeqdb sp!, {r12}
    orr r12, pc, pc
    ldmeqia sp!, {pc}
    dcd DSProt_BSS+0x1
    dcd DSProt_BSS+0x3
    dcd func_ov004_021ce874+0x3200
    dcd DSProt_BSS+0x32bc
    dcd 0x00000000
    dcd func_ov004_021ce7d8+0x68000000
}

asm void func_ov004_021cf6dc(void) {
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
@L021cf70c:
    ldr r2, [r0]
    mov r4, r2, lsr #0x18
    cmp r4, #0xea
    cmpne r4, #0xeb
    eorne r3, r3, r2, ror #17
    addne r3, r3, r2, ror #28
    eorne r3, r3, r2, ror r1
    subs r1, r1, #1
    add r0, r0, #4
    bne @L021cf70c
    streq r3, [pc, #0x14]
    ldmeqfd sp!, {r0, r1, r2, r3, r4}
    ldmnefd sp!, {r5, r6, r7, r8, r9}
    stmeqdb sp!, {r12}
    orr r12, pc, pc
    ldmeqia sp!, {pc}
    dcd DSProt_BSS+0x1
    dcd DSProt_BSS+0x3
    dcd func_ov004_021ce934+0x3200
    dcd DSProt_BSS+0x32e0
    dcd 0x00000000
    dcd func_ov004_021ce7d8+0x68000000
}

asm void func_ov004_021cf764(void) {
    orr r0, pc, #0
    adds r0, r0, #4
    bne func_ov004_021ce574
    dcd func_ov004_021cf544+0x3200
    dcd DSProt_BSS+0x3270
    dcd func_ov004_021cf5cc+0x3200
    dcd DSProt_BSS+0x3270
    dcd func_ov004_021cf654+0x3200
    dcd DSProt_BSS+0x3270
    dcd func_ov004_021cf6dc+0x3200
    dcd DSProt_BSS+0x3270
    dcd func_ov004_021cea18+0x3200
    dcd DSProt_BSS+0x3290
    dcd 0x00000000
    dcd 0x00000000
}

