// DSProtect (anti-piracy middleware), hand-written assembly: self-checksumming stubs whose
// trailing words are relocated pointers/keys, so they are emitted as dcd.

#include "types.h"

#pragma force_active on

void func_ov004_021cd6e0(void);
void func_ov004_021cdc20(void);
void func_ov004_021ce848(void);
void func_ov004_021cf764(void);
extern char DSProt_BSS[];
extern char data_ov004_021cf7bc[];
extern char DSProt_CallEncrypted[];
extern char DSProt_RunRomCheckA[];
extern char DSProt_RunRomCheckB[];
extern char DSProt_RunEmuCheckA[];
extern char DSProt_RunEmuCheckB[];
void DSProt_DescrambleRanges(u32 *t);
BOOL DSProt_EntryRomCheckA(u32 addr, s32 arg);
BOOL DSProt_EntryEmuCheckA(u32 addr, s32 arg);
BOOL DSProt_EntryRomCheckB(u32 addr, s32 arg);
void DSProt_EntryEmuCheckB(void);
void func_ov004_021ce50c(void);

asm BOOL DSProt_EntryRomCheckA(u32 addr, s32 arg) {
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
@L021ce31c:
    ldr r2, [r0]
    mov r4, r2, lsr #0x18
    cmp r4, #0xea
    cmpne r4, #0xeb
    eorne r3, r3, r2, ror #17
    addne r3, r3, r2, ror #28
    eorne r3, r3, r2, ror r1
    subs r1, r1, #1
    add r0, r0, #4
    bne @L021ce31c
    streq r3, [pc, #0x14]
    ldmeqfd sp!, {r0, r1, r2, r3, r4}
    ldmnefd sp!, {r5, r6, r7, r8, r9}
    stmeqdb sp!, {r12}
    orr r12, pc, pc
    ldmeqia sp!, {pc}
    dcd DSProt_BSS+0x1
    dcd DSProt_BSS+0x3
    dcd DSProt_RunRomCheckA+0x3200
    dcd DSProt_BSS+0x3384
    dcd 0x00000000
    dcd DSProt_CallEncrypted+0x68000000
}

asm BOOL DSProt_EntryEmuCheckA(u32 addr, s32 arg) {
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
@L021ce3a4:
    ldr r2, [r0]
    mov r4, r2, lsr #0x18
    cmp r4, #0xea
    cmpne r4, #0xeb
    eorne r3, r3, r2, ror #17
    addne r3, r3, r2, ror #28
    eorne r3, r3, r2, ror r1
    subs r1, r1, #1
    add r0, r0, #4
    bne @L021ce3a4
    streq r3, [pc, #0x14]
    ldmeqfd sp!, {r0, r1, r2, r3, r4}
    ldmnefd sp!, {r5, r6, r7, r8, r9}
    stmeqdb sp!, {r12}
    orr r12, pc, pc
    ldmeqia sp!, {pc}
    dcd DSProt_BSS+0x1
    dcd DSProt_BSS+0x3
    dcd DSProt_RunEmuCheckA+0x3200
    dcd DSProt_BSS+0x3384
    dcd 0x00000000
    dcd DSProt_CallEncrypted+0x68000000
}

asm BOOL DSProt_EntryRomCheckB(u32 addr, s32 arg) {
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
@L021ce42c:
    ldr r2, [r0]
    mov r4, r2, lsr #0x18
    cmp r4, #0xea
    cmpne r4, #0xeb
    eorne r3, r3, r2, ror #17
    addne r3, r3, r2, ror #28
    eorne r3, r3, r2, ror r1
    subs r1, r1, #1
    add r0, r0, #4
    bne @L021ce42c
    streq r3, [pc, #0x14]
    ldmeqfd sp!, {r0, r1, r2, r3, r4}
    ldmnefd sp!, {r5, r6, r7, r8, r9}
    stmeqdb sp!, {r12}
    orr r12, pc, pc
    ldmeqia sp!, {pc}
    dcd DSProt_BSS+0x1
    dcd DSProt_BSS+0x3
    dcd DSProt_RunRomCheckB+0x3200
    dcd DSProt_BSS+0x3384
    dcd 0x00000000
    dcd DSProt_CallEncrypted+0x68000000
}

asm void DSProt_EntryEmuCheckB(void) {
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
@L021ce4b4:
    ldr r2, [r0]
    mov r4, r2, lsr #0x18
    cmp r4, #0xea
    cmpne r4, #0xeb
    eorne r3, r3, r2, ror #17
    addne r3, r3, r2, ror #28
    eorne r3, r3, r2, ror r1
    subs r1, r1, #1
    add r0, r0, #4
    bne @L021ce4b4
    streq r3, [pc, #0x14]
    ldmeqfd sp!, {r0, r1, r2, r3, r4}
    ldmnefd sp!, {r5, r6, r7, r8, r9}
    stmeqdb sp!, {r12}
    orr r12, pc, pc
    ldmeqia sp!, {pc}
    dcd DSProt_BSS+0x1
    dcd DSProt_BSS+0x3
    dcd DSProt_RunEmuCheckB+0x3200
    dcd DSProt_BSS+0x3384
    dcd 0x00000000
    dcd DSProt_CallEncrypted+0x68000000
}

asm void func_ov004_021ce50c(void) {
    stmdb sp!, {lr}
    bl func_ov004_021cf764
    bl func_ov004_021ce848
    bl func_ov004_021cd6e0
    bl func_ov004_021cdc20
    ldmia sp!, {lr}
    ldr r0, [pc, #0x40]
    ldr r1, [pc, #0x40]
    sub r0, r0, #0x3200
    stmia r0!, {r1, r2, r3, r4, r5, r6, r7, r8, r9, r10}
    orr r0, pc, #0
    adds r0, r0, #4
    bne DSProt_DescrambleRanges
    dcd DSProt_EntryRomCheckA+0x3200
    dcd DSProt_BSS+0x3270
    dcd DSProt_EntryEmuCheckA+0x3200
    dcd DSProt_BSS+0x3270
    dcd DSProt_EntryRomCheckB+0x3200
    dcd DSProt_BSS+0x3270
    dcd DSProt_EntryEmuCheckB+0x3200
    dcd DSProt_BSS+0x3270
    dcd 0x00000000
    dcd 0x00000000
    dcd data_ov004_021cf7bc+0x3200
    dcd func_ov004_021ce50c+0x3200
    dcd 0xe12fff1e
}

