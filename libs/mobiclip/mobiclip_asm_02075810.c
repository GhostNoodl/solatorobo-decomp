// Actimagine Mobiclip video decoder, hand-written ARM assembly: the deblocking pass over one
// frame (luma, then both chroma planes; the second filter of each pair is skipped when the
// filter mode is 1), and the two byte tables that follow it. The code reads the tables
// pc-relatively from a base below their start, indexed by the quantiser.
// Generated with tools/asm2mw/asm2mw.py main 02075810 020758f4; the conditional calls are
// written with their symbols (relocs.txt has them, see docs/MATCHING.md, round sinit5).

#define B4(a, b, c, d) ((a) | ((b) << 8) | ((c) << 16) | ((d) << 24))

#pragma force_active on

void func_02075940(void);
void func_02075a78(void);
void func_02075b6c(void);
void func_02075c74(void);
void func_02075810(void);
void data_020758f4(void);

asm void func_02075810(void) {
    stmfd sp!, {r4, r5, r6, r7, r8, r9, lr}
    sub sp, sp, #0x18
    mov r4, r0
    ldr r5, [r4, #0x18]
    add r6, pc, #0xc0
    ldrb r6, [r6, r5]
    add r7, pc, #0xdd
    ldrb r7, [r7, r5]
    orr r6, r6, r7, lsl #8
    str r6, [sp, #0x10]
    ldr r5, [r4]
    ldr r6, [r4, #8]
    ldr r7, [r4, #0x10]
    ldr r8, [r4, #0x14]
    ldr r9, [r4, #0x1c]
    str r5, [sp]
    str r6, [sp, #4]
    str r7, [sp, #8]
    str r8, [sp, #0xc]
    add r9, r9, #0x40
    str r9, [sp, #0x14]
    mov r0, sp
    bl func_02075940
    ldr r0, [r4, #0x20]
    cmp r0, #1
    movne r0, sp
    blne func_02075a78
    ldr r5, [r4, #4]
    ldr r6, [r4, #0xc]
    ldr r7, [r4, #0x10]
    ldr r8, [r4, #0x14]
    str r5, [sp]
    str r6, [sp, #4]
    mov r7, r7, asr #1
    mov r8, r8, asr #1
    str r7, [sp, #8]
    str r8, [sp, #0xc]
    mov r0, sp
    bl func_02075b6c
    ldr r0, [r4, #0x20]
    cmp r0, #1
    movne r0, sp
    blne func_02075c74
    ldr r5, [r4, #4]
    ldr r6, [r4, #0xc]
    add r5, r5, #0x80
    add r6, r6, #0x80
    str r5, [sp]
    str r6, [sp, #4]
    mov r0, sp
    bl func_02075b6c
    ldr r0, [r4, #0x20]
    cmp r0, #1
    movne r0, sp
    blne func_02075c74
    add sp, sp, #0x18
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, pc}
}


asm void data_020758f4(void) {
    dcd 0
    dcd B4(3, 4, 5, 5)
    dcd B4(6, 7, 8, 10)
    dcd B4(11, 13, 15, 17)
    dcd B4(19, 22, 25, 29)
    dcd B4(33, 38, 44, 50)
    dcd B4(57, 66, 75, 86)
    dcd B4(98, 112, 128, 147)
    dcd B4(168, 192, 219, 251)
    dcd B4(255, 0, 0, 0)
    dcd B4(1, 1, 2, 2)
    dcd B4(3, 3, 4, 4)
    dcd B4(5, 5, 6, 6)
    dcd B4(7, 7, 8, 8)
    dcd B4(9, 9, 10, 11)
    dcd B4(11, 12, 12, 13)
    dcd B4(13, 14, 14, 15)
    dcd B4(15, 16, 16, 17)
    dcd B4(17, 18, 0, 0)
}
