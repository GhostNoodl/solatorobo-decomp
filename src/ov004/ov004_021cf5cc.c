// DSProtect (anti-piracy middleware), hand-written assembly: self-checksumming stubs whose
// trailing words are relocated pointers/keys, so they are emitted as dcd.

#pragma force_active on

extern char DSProt_BSS[];
extern char DSProt_CallEncrypted[];
extern char DSProt_EmuCheckA[];
extern char DSProt_EmuCheckB[];
extern char DSProt_RomCheckB[];
extern char DSProt_Crc32[];
extern char DSProt_RomCheckA[];
void DSProt_RomCheckA_Stub(void);
void DSProt_RomCheckB_Stub(void);
void DSProt_EmuCheckA_Stub(void);
void DSProt_EmuCheckB_Stub(void);
void func_ov004_021cf764(void);
void DSProt_DescrambleRanges(void);

asm void DSProt_RomCheckA_Stub(void) {
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
@L021cf574:
    ldr r2, [r0]
    mov r4, r2, lsr #0x18
    cmp r4, #0xea
    cmpne r4, #0xeb
    eorne r3, r3, r2, ror #17
    addne r3, r3, r2, ror #28
    eorne r3, r3, r2, ror r1
    subs r1, r1, #1
    add r0, r0, #4
    bne @L021cf574
    streq r3, [pc, #0x14]
    ldmeqfd sp!, {r0, r1, r2, r3, r4}
    ldmnefd sp!, {r5, r6, r7, r8, r9}
    stmeqdb sp!, {r12}
    orr r12, pc, pc
    ldmeqia sp!, {pc}
    dcd DSProt_BSS+0x1
    dcd DSProt_BSS+0x3
    dcd DSProt_RomCheckA+0x3200
    dcd DSProt_BSS+0x3740
    dcd 0x00000000
    dcd DSProt_CallEncrypted+0x68000000
}

asm void DSProt_RomCheckB_Stub(void) {
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
    dcd DSProt_RomCheckB+0x3200
    dcd DSProt_BSS+0x3740
    dcd 0x00000000
    dcd DSProt_CallEncrypted+0x68000000
}

asm void DSProt_EmuCheckA_Stub(void) {
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
    dcd DSProt_EmuCheckA+0x3200
    dcd DSProt_BSS+0x32bc
    dcd 0x00000000
    dcd DSProt_CallEncrypted+0x68000000
}

asm void DSProt_EmuCheckB_Stub(void) {
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
    dcd DSProt_EmuCheckB+0x3200
    dcd DSProt_BSS+0x32e0
    dcd 0x00000000
    dcd DSProt_CallEncrypted+0x68000000
}

asm void func_ov004_021cf764(void) {
    orr r0, pc, #0
    adds r0, r0, #4
    bne DSProt_DescrambleRanges
    dcd DSProt_RomCheckA_Stub+0x3200
    dcd DSProt_BSS+0x3270
    dcd DSProt_RomCheckB_Stub+0x3200
    dcd DSProt_BSS+0x3270
    dcd DSProt_EmuCheckA_Stub+0x3200
    dcd DSProt_BSS+0x3270
    dcd DSProt_EmuCheckB_Stub+0x3200
    dcd DSProt_BSS+0x3270
    dcd DSProt_Crc32+0x3200
    dcd DSProt_BSS+0x3290
    dcd 0x00000000
    dcd 0x00000000
}

