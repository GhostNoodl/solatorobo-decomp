// DSProtect (anti-piracy middleware), hand-written assembly: self-checksumming stubs whose
// trailing words are relocated pointers/keys, so they are emitted as dcd.

#pragma force_active on

extern char DSProt_BSS[];
extern char data_ov004_021cf7d4[];
extern char data_ov004_021cf7d8[];
extern char func_ov004_021ce634[];
extern char func_ov004_021ce6f8[];
void func_ov004_021ce7d8(void);
void func_ov004_021ce848(void);
void func_ov004_021ce574(void);

asm void func_ov004_021ce7d8(void) {
    stmfd sp!, {r0, r1, r2, r3}
    str r10, [r12, #0x10]
    mov r10, r12
    ldr r12, =data_ov004_021cf7d4
    str lr, [r10]
    ldr r12, [r12]
    ldmib r10, {r0, r1, r2}
    sub r12, r12, #0x3200
    blx r12
    mov r12, r0
    ldmfd sp!, {r0, r1, r2, r3}
    blx r12
    ldr r12, =data_ov004_021cf7d8
    stmdb sp!, {r4}
    ldr r12, [r12]
    mov r4, r0
    sub r12, r12, #0x3200
    ldmib r10, {r0, r1, r2}
    blx r12
    str r0, [r10, #4]
    mov r0, r4
    ldmia sp!, {r4}
    ldr lr, [r10]
    str sp, [r10]
    ldr r10, [r10, #0x10]
    bx lr
}

asm void func_ov004_021ce848(void) {
    orr r0, pc, #0
    adds r0, r0, #4
    bne func_ov004_021ce574
    dcd func_ov004_021ce6f8+0x3200
    dcd DSProt_BSS+0x32d4
    dcd func_ov004_021ce634+0x3200
    dcd DSProt_BSS+0x32bc
    dcd func_ov004_021ce7d8+0x3200
    dcd DSProt_BSS+0x3268
    dcd 0x00000000
    dcd 0x00000000
}

