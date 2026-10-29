// Actimagine Mobiclip audio decoder, hand-written ARM assembly: the frame decoder func_02075d4c
// (its first word branches to the entry at 0x0207655c; the routines before it are only reached
// with local `bl`s), the 4-byte func_0207670c that branches to the synthesis filter
// func_02077118, and the 160-word quantiser table data_02076710 that func_02076990 reads
// pc-relatively. pc-relative operands stay numeric, commented with the label they resolve to.
// The code/data split comes from a flow analysis, not from any symbol information.
// Generated with tools/asm2mw/asmblob.py main func_02075d4c:02075d4c:0207670c:code
// func_0207670c:0207670c:02076710:code data_02076710:02076710:02076990:data; its --labels output
// is the .D_/.L_ labels in symbols.txt that give the delinked target the same $d/$a layout.

#include "mobiclip/mobiclip.h"

#pragma force_active on

void func_02077118(void);
int func_02075d4c(MoAudioDecoder *decoder);
void func_0207670c(MoAudioDecoder *decoder);
void data_02076710(void);

asm int func_02075d4c(MoAudioDecoder *decoder) {
    b @L0207655c
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x00000000
@L02075d5c:
    mov r6, #0x20
    add r7, r3, #0x200
    mov r8, #0
    mov r9, #0
    mov r10, #0
    mov r11, #0
@L02075d74:
    stmia r7!, {r8, r9, r10, r11}
    subs r6, r6, #1
    bne @L02075d74
    mov pc, lr
    dcd 0x00000000
    dcd 0x00000000
@L02075d8c:
    stmfd sp!, {r1, r3, r4}
    add r3, r3, #0x200
    rsb r12, r6, #0x7f
    add r4, r4, r12, lsl #2
    ldr r2, [r4], #4
    mov r1, #2
    mov r2, r2, asr #4
    str r2, [r3], #4
    ldr r2, [r4], #4
    ldr r7, [r4], #4
    ldr r8, [r4], #4
    ldr r9, [r4], #4
    ldr r10, [r4], #4
    ldr r11, [r4], #4
    mul r12, r2, r1
    add r1, r1, #1
    mov r12, r12, asr #4
    str r12, [r3], #4
    mul r12, r7, r1
    add r1, r1, #1
    mov r12, r12, asr #4
    str r12, [r3], #4
    mul r12, r8, r1
    add r1, r1, #1
    mov r12, r12, asr #4
    str r12, [r3], #4
    mul r12, r9, r1
    add r1, r1, #1
    mov r12, r12, asr #4
    str r12, [r3], #4
    mul r12, r10, r1
    add r1, r1, #1
    mov r12, r12, asr #4
    str r12, [r3], #4
    mul r12, r11, r1
    mov r12, r12, asr #4
    str r12, [r3], #4
    mov r12, #0x72
@L02075e24:
    ldmia r4!, {r6, r7, r8, r9, r10, r11}
    mov r6, r6, asr #1
    mov r7, r7, asr #1
    mov r8, r8, asr #1
    mov r9, r9, asr #1
    mov r10, r10, asr #1
    mov r11, r11, asr #1
    stmia r3!, {r6, r7, r8, r9, r10, r11}
    subs r12, r12, #6
    bne @L02075e24
    ldr r2, [r4], #4
    ldr r7, [r4], #4
    ldr r8, [r4], #4
    ldr r9, [r4], #4
    ldr r10, [r4], #4
    ldr r11, [r4], #4
    mul r12, r2, r1
    sub r1, r1, #1
    mov r12, r12, asr #4
    str r12, [r3], #4
    mul r12, r7, r1
    sub r1, r1, #1
    mov r12, r12, asr #4
    str r12, [r3], #4
    mul r12, r8, r1
    sub r1, r1, #1
    mov r12, r12, asr #4
    str r12, [r3], #4
    mul r12, r9, r1
    sub r1, r1, #1
    mov r12, r12, asr #4
    str r12, [r3], #4
    mul r12, r10, r1
    sub r1, r1, #1
    mov r12, r12, asr #4
    str r12, [r3], #4
    mul r12, r11, r1
    ldr r2, [r4], #4
    mov r12, r12, asr #4
    str r12, [r3], #4
    mov r2, r2, asr #4
    str r2, [r3], #4
    ldmfd sp!, {r1, r3, r4}
    mov pc, lr
    dcd 0x00000000
    dcd 0x00000000
@L02075edc:
    add r1, r3, #0x200
    add r1, r1, r7, lsl #2
    rsb r7, r6, #0
    mov r6, r6, lsl #1
    sub r7, r7, r6
@L02075ef0:
    ldrh r5, [r0], #2
    mov r11, #0xe
@L02075ef8:
    ldr r10, [r1]
    mov r2, r5, lsr r11
    and r2, r2, #3
    mla r2, r6, r2, r7
    add r10, r10, r2
    str r10, [r1], r9
    subs r11, r11, #2
    bge @L02075ef8
    subs r8, r8, #1
    bne @L02075ef0
    ldmfd sp!, {r1, pc}
    dcd 0x00000000
    dcd 0x00000000
@L02075f2c:
    add r1, r3, #0x200
    add r1, r1, r7, lsl #2
    rsb r7, r6, #0
    mov r6, r6, lsl #1
    sub r7, r7, r6, lsl #1
    sub r7, r7, r6
    mov r9, #0
    mov r8, #8
@L02075f4c:
    ldrh r5, [r0], #2
    mov r11, #0xd
@L02075f54:
    ldr r10, [r1]
    mov r2, r5, lsr r11
    and r2, r2, #7
    mla r2, r6, r2, r7
    add r10, r10, r2
    str r10, [r1], #0xc
    subs r11, r11, #3
    bge @L02075f54
    and r5, r5, #1
    orr r9, r5, r9, lsl #1
    subs r8, r8, #1
    bne @L02075f4c
    ldr r10, [r1]
    mov r2, r9, lsr #5
    and r2, r2, #7
    mla r2, r6, r2, r7
    add r10, r10, r2
    str r10, [r1], #0xc
    ldr r10, [r1]
    mov r2, r9, lsr #2
    and r2, r2, #7
    mla r2, r6, r2, r7
    add r10, r10, r2
    str r10, [r1]
    ldmfd sp!, {r1, pc}
    dcd 0x00000000
@L02075fbc:
    stmfd sp!, {r3, r4, lr}
    ldmia r2, {r5, r6, r7, r8, r9, r10, r11, r12}
    add r3, r1, #0x70
    ldrb r4, [r3]
    add r2, r1, #0x8c0
    add r4, r2, r4, lsl #4
    bl @L0207612c
    add r3, r1, #0x71
    ldrb r4, [r3]
    add r2, r1, #0xcc0
    add r4, r2, r4, lsl #4
    bl @L0207612c
    add r3, r1, #0x72
    ldrb r4, [r3]
    add r2, r1, #0x10c0
    add r4, r2, r4, lsl #4
    bl @L0207612c
    add r2, r1, #8
    stmia r2, {r5, r6, r7, r8, r9, r10, r11, r12}
    mul r3, r5, r6
    add r5, r5, r3, asr #15
    mul r3, r6, r7
    mul r4, r5, r7
    add r5, r5, r3, asr #15
    add r6, r6, r4, asr #15
    mul r3, r7, r8
    mul r4, r5, r8
    add r5, r5, r3, asr #15
    mul r3, r6, r8
    add r7, r7, r4, asr #15
    add r6, r6, r3, asr #15
    mul r3, r8, r9
    mul r4, r5, r9
    add r5, r5, r3, asr #15
    add r8, r8, r4, asr #15
    mul r3, r7, r9
    mul r4, r6, r9
    add r6, r6, r3, asr #15
    add r7, r7, r4, asr #15
    mul r3, r9, r10
    mul r4, r5, r10
    add r5, r5, r3, asr #15
    add r9, r9, r4, asr #15
    mul r3, r8, r10
    mul r4, r6, r10
    add r6, r6, r3, asr #15
    mul r3, r7, r10
    add r8, r8, r4, asr #15
    add r7, r7, r3, asr #15
    mul r3, r10, r11
    mul r4, r5, r11
    add r5, r5, r3, asr #15
    add r10, r10, r4, asr #15
    mul r3, r9, r11
    mul r4, r6, r11
    add r6, r6, r3, asr #15
    add r9, r9, r4, asr #15
    mul r3, r8, r11
    mul r4, r7, r11
    add r7, r7, r3, asr #15
    add r8, r8, r4, asr #15
    mul r3, r11, r12
    mul r4, r5, r12
    add r5, r5, r3, asr #15
    add r11, r11, r4, asr #15
    mul r3, r10, r12
    mul r4, r6, r12
    add r6, r6, r3, asr #15
    add r10, r10, r4, asr #15
    mul r3, r9, r12
    mul r4, r7, r12
    add r7, r7, r3, asr #15
    mul r3, r8, r12
    add r9, r9, r4, asr #15
    add r8, r8, r3, asr #15
    mov r5, r5, asr #1
    rsb r5, r5, #0
    mov r6, r6, asr #1
    rsb r6, r6, #0
    mov r7, r7, asr #1
    rsb r7, r7, #0
    mov r8, r8, asr #1
    rsb r8, r8, #0
    mov r9, r9, asr #1
    rsb r9, r9, #0
    mov r10, r10, asr #1
    rsb r10, r10, #0
    mov r11, r11, asr #1
    rsb r11, r11, #0
    mov r12, r12, asr #1
    rsb r12, r12, #0
    ldmfd sp!, {r3, r4, pc}
@L0207612c:
    ldrsh r0, [r4], #2
    ldrsh r3, [r4], #2
    ldrsh r2, [r4], #2
    add r5, r5, r0
    add r6, r6, r3
    add r7, r7, r2
    ldrsh r0, [r4], #2
    ldrsh r3, [r4], #2
    ldrsh r2, [r4], #2
    add r8, r8, r0
    add r9, r9, r3
    add r10, r10, r2
    ldrsh r0, [r4], #2
    ldrsh r3, [r4], #2
    add r11, r11, r0
    add r12, r12, r3
    mov pc, lr
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x00000000
@L0207617c:
    stmfd sp!, {r1, r3, r4, lr}
    add lr, r1, #0x78
    ldr r1, [r1, #0x74]
@L02076188:
    str r2, [sp, #-4]!
    ldr r4, [r0], #4
    ldr r3, [lr, #0x1c]
    mov r4, r4, lsl #0xe
    ldr r2, [lr, #0x18]
    mla r4, r5, r3, r4
    ldr r3, [lr, #0x14]
    mla r4, r6, r2, r4
    ldr r2, [lr, #0x10]
    mla r4, r7, r3, r4
    ldr r3, [lr, #0xc]
    mla r4, r8, r2, r4
    ldr r2, [lr, #8]
    mla r4, r9, r3, r4
    ldr r3, [lr, #4]
    mla r4, r10, r2, r4
    ldr r2, [lr]
    mla r4, r11, r3, r4
    mla r4, r12, r2, r4
    mov r4, r4, asr #0xe
    str r4, [lr]
    str r4, [r1], #4
    ldr r4, [r0], #4
    ldr r3, [lr]
    mov r4, r4, lsl #0xe
    ldr r2, [lr, #0x1c]
    mla r4, r5, r3, r4
    ldr r3, [lr, #0x18]
    mla r4, r6, r2, r4
    ldr r2, [lr, #0x14]
    mla r4, r7, r3, r4
    ldr r3, [lr, #0x10]
    mla r4, r8, r2, r4
    ldr r2, [lr, #0xc]
    mla r4, r9, r3, r4
    ldr r3, [lr, #8]
    mla r4, r10, r2, r4
    ldr r2, [lr, #4]
    mla r4, r11, r3, r4
    mla r4, r12, r2, r4
    mov r4, r4, asr #0xe
    str r4, [lr, #4]
    str r4, [r1], #4
    ldr r4, [r0], #4
    ldr r3, [lr, #4]
    mov r4, r4, lsl #0xe
    ldr r2, [lr]
    mla r4, r5, r3, r4
    ldr r3, [lr, #0x1c]
    mla r4, r6, r2, r4
    ldr r2, [lr, #0x18]
    mla r4, r7, r3, r4
    ldr r3, [lr, #0x14]
    mla r4, r8, r2, r4
    ldr r2, [lr, #0x10]
    mla r4, r9, r3, r4
    ldr r3, [lr, #0xc]
    mla r4, r10, r2, r4
    ldr r2, [lr, #8]
    mla r4, r11, r3, r4
    mla r4, r12, r2, r4
    mov r4, r4, asr #0xe
    str r4, [lr, #8]
    str r4, [r1], #4
    ldr r4, [r0], #4
    ldr r3, [lr, #8]
    mov r4, r4, lsl #0xe
    ldr r2, [lr, #4]
    mla r4, r5, r3, r4
    ldr r3, [lr]
    mla r4, r6, r2, r4
    ldr r2, [lr, #0x1c]
    mla r4, r7, r3, r4
    ldr r3, [lr, #0x18]
    mla r4, r8, r2, r4
    ldr r2, [lr, #0x14]
    mla r4, r9, r3, r4
    ldr r3, [lr, #0x10]
    mla r4, r10, r2, r4
    ldr r2, [lr, #0xc]
    mla r4, r11, r3, r4
    mla r4, r12, r2, r4
    mov r4, r4, asr #0xe
    str r4, [lr, #0xc]
    str r4, [r1], #4
    ldr r4, [r0], #4
    ldr r3, [lr, #0xc]
    mov r4, r4, lsl #0xe
    ldr r2, [lr, #8]
    mla r4, r5, r3, r4
    ldr r3, [lr, #4]
    mla r4, r6, r2, r4
    ldr r2, [lr]
    mla r4, r7, r3, r4
    ldr r3, [lr, #0x1c]
    mla r4, r8, r2, r4
    ldr r2, [lr, #0x18]
    mla r4, r9, r3, r4
    ldr r3, [lr, #0x14]
    mla r4, r10, r2, r4
    ldr r2, [lr, #0x10]
    mla r4, r11, r3, r4
    mla r4, r12, r2, r4
    mov r4, r4, asr #0xe
    str r4, [lr, #0x10]
    str r4, [r1], #4
    ldr r4, [r0], #4
    ldr r3, [lr, #0x10]
    mov r4, r4, lsl #0xe
    ldr r2, [lr, #0xc]
    mla r4, r5, r3, r4
    ldr r3, [lr, #8]
    mla r4, r6, r2, r4
    ldr r2, [lr, #4]
    mla r4, r7, r3, r4
    ldr r3, [lr]
    mla r4, r8, r2, r4
    ldr r2, [lr, #0x1c]
    mla r4, r9, r3, r4
    ldr r3, [lr, #0x18]
    mla r4, r10, r2, r4
    ldr r2, [lr, #0x14]
    mla r4, r11, r3, r4
    mla r4, r12, r2, r4
    mov r4, r4, asr #0xe
    str r4, [lr, #0x14]
    str r4, [r1], #4
    ldr r4, [r0], #4
    ldr r3, [lr, #0x14]
    mov r4, r4, lsl #0xe
    ldr r2, [lr, #0x10]
    mla r4, r5, r3, r4
    ldr r3, [lr, #0xc]
    mla r4, r6, r2, r4
    ldr r2, [lr, #8]
    mla r4, r7, r3, r4
    ldr r3, [lr, #4]
    mla r4, r8, r2, r4
    ldr r2, [lr]
    mla r4, r9, r3, r4
    ldr r3, [lr, #0x1c]
    mla r4, r10, r2, r4
    ldr r2, [lr, #0x18]
    mla r4, r11, r3, r4
    mla r4, r12, r2, r4
    mov r4, r4, asr #0xe
    str r4, [lr, #0x18]
    str r4, [r1], #4
    ldr r4, [r0], #4
    ldr r3, [lr, #0x18]
    mov r4, r4, lsl #0xe
    ldr r2, [lr, #0x14]
    mla r4, r5, r3, r4
    ldr r3, [lr, #0x10]
    mla r4, r6, r2, r4
    ldr r2, [lr, #0xc]
    mla r4, r7, r3, r4
    ldr r3, [lr, #8]
    mla r4, r8, r2, r4
    ldr r2, [lr, #4]
    mla r4, r9, r3, r4
    ldr r3, [lr]
    mla r4, r10, r2, r4
    ldr r2, [lr, #0x1c]
    mla r4, r11, r3, r4
    mla r4, r12, r2, r4
    mov r4, r4, asr #0xe
    str r4, [lr, #0x1c]
    str r4, [r1], #4
    ldr r2, [sp], #4
    subs r2, r2, #8
    bne @L02076188
    ldr r4, [sp]
    str r1, [r4, #0x74]
    ldmfd sp!, {r1, r3, r4, pc}
    dcd 0x00000000
    dcd 0x00000000
@L0207644c:
    stmfd sp!, {r0, lr}
    ldr r0, [r2], #4
    ldr lr, [r2], #4
    add r5, r5, r0
    add r6, r6, lr
    ldr r0, [r2], #4
    ldr lr, [r2], #4
    add r7, r7, r0
    add r8, r8, lr
    ldr r0, [r2], #4
    ldr lr, [r2], #4
    add r9, r9, r0
    add r10, r10, lr
    ldr r0, [r2], #4
    ldr lr, [r2], #4
    add r11, r11, r0
    add r12, r12, lr
    mov r5, r5, asr #1
    mov r6, r6, asr #1
    mov r7, r7, asr #1
    mov r8, r8, asr #1
    mov r9, r9, asr #1
    mov r10, r10, asr #1
    mov r11, r11, asr #1
    mov r12, r12, asr #1
    ldmfd sp!, {r0, pc}
    dcd 0x00000000
    dcd 0x00000000
@L020764bc:
    stmfd sp!, {r1, r4, lr}
    ldr r2, [r1, #0x6c]
    cmp r2, #1
    add r0, r3, #0x200
    str r4, [r1, #0x74]
    addne r3, r1, #0x28
    addne r4, r3, #0x20
    addeq r4, r1, #0x28
    addeq r3, r4, #0x20
    stmia r3, {r5, r6, r7, r8, r9, r10, r11, r12}
    mov r2, r4
    bl @L0207644c
    stmfd sp!, {r5, r6, r7, r8, r9, r10, r11, r12}
    mov r2, r4
    bl @L0207644c
    mov r2, #0x20
    bl @L0207617c
    ldmfd sp!, {r5, r6, r7, r8, r9, r10, r11, r12}
    mov r2, #0x20
    bl @L0207617c
    mov r2, r3
    bl @L0207644c
    mov r2, #0x20
    bl @L0207617c
    ldmia r3, {r5, r6, r7, r8, r9, r10, r11, r12}
    mov r2, #0x20
    bl @L0207617c
    ldmfd sp!, {r1, r4, pc}
@L0207652c:
    add r8, r1, #0x8c0
    ldr r7, [r8, #0xc30]
    mov r9, #1
    str r7, [r1, #0x68]
    mov r7, #8
    str r9, [r1, #0x6c]
    add r8, r1, #0x78
    mov r9, #0
@L0207654c:
    str r9, [r8], #4
    subs r7, r7, #1
    bne @L0207654c
    mov pc, lr
@L0207655c:
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    mov r1, r0
    ldr r0, [r0]
    ldrh r5, [r0], #2
    mov r6, r5, lsr #9
    cmp r6, #0x7f
    bleq @L0207666c
    blne @L020766ac
    ldr r7, [r1, #0x6c]
    eor r7, r7, #1
    str r7, [r1, #0x6c]
    add r3, r1, #0x1000
    ldr r2, [r1, #4]
    mov r0, #0x80
    ldr r5, [pc, #0x168] // @L02076704
    ldr r6, [pc, #0x168] // @L02076708
    ldr r3, [r3, #0x4f4]
@L020765a0:
    ldr r7, [r4], #4
    cmp r7, r5
    movgt r7, r5
    cmp r7, r6
    movlt r7, r6
    strh r7, [r2], r3
    subs r0, r0, #1
    bne @L020765a0
    ldrb r0, [r1, #0x73]
    add r2, pc, #0xe // @L020765da
    ldrb r0, [r2, r0]
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    bx lr
    dcd 0x10040c05
    dcd 0x0e141403
    dcd 0x00000a0c
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x00000000
@L020765ec:
    stmfd sp!, {r1, lr}
    add r12, r1, #0x70
    mov r6, r5, lsr #6
    and r6, r6, #7
    and r5, r5, #0x3f
    strb r5, [r12], #1
    ldrh r5, [r0], #2
    add r8, r1, #0x14c0
    mov r7, r5, lsr #0xe
    and r7, r7, #3
    add r6, r8, r6, lsl #1
    ldrsh r8, [r6]
    ldr r6, [r1, #0x68]
    mov r11, r5, lsr #0xc
    mul r6, r8, r6
    mov r10, r5, lsr #6
    mov r6, r6, asr #0xd
    str r6, [r1, #0x68]
    and r10, r10, #0x3f
    strb r10, [r12], #1
    and r5, r5, #0x3f
    strb r5, [r12]
    ands r11, r11, #3
    strb r11, [r1, #0x73]
    beq @L02075f2c
    sub r10, pc, #0x86 // @L020765d2
    add r10, r10, r11, lsl #1
    ldrb r8, [r10]
    ldrb r9, [r10, #1]
    b @L02075edc
    dcd 0x00000000
    dcd 0x00000000
@L0207666c:
    stmfd sp!, {r1, lr}
    bl @L0207652c
    add r4, r1, #0xc0
    add r3, r4, #0x400
    bl @L02075d5c
    bl @L020765ec
    add r2, r1, #0x8c0
    add r2, r2, #0xc10
    bl @L02075fbc
    add r2, r1, #0x48
    stmia r2, {r5, r6, r7, r8, r9, r10, r11, r12}
    str r4, [r1, #0x74]
    add r0, r3, #0x200
    mov r2, #0x80
    bl @L0207617c
    ldmfd sp!, {r1, pc}
@L020766ac:
    stmfd sp!, {r1, lr}
    mov r7, #0x400
    ldr r2, [r1, #0x6c]
    add r8, r1, #0xc0
    mla r3, r2, r7, r8
    eor r2, r2, #1
    mla r4, r2, r7, r8
    mov r8, r3
    add r7, r4, #0x200
    mov r2, #0x20
@L020766d4:
    ldmia r7!, {r9, r10, r11, r12}
    stmia r8!, {r9, r10, r11, r12}
    subs r2, r2, #1
    bne @L020766d4
    cmp r6, #0x7e
    bleq @L02075d5c
    blne @L02075d8c
    bl @L020765ec
    add r2, r1, #8
    bl @L02075fbc
    bl @L020764bc
    ldmfd sp!, {r1, pc}
@L02076704:
    dcd 0x00007fff
@L02076708:
    dcd 0xffff8000
}

asm void func_0207670c(MoAudioDecoder *decoder) {
    b func_02077118
}

asm void data_02076710(void) {
    dcd 0xffff8067
    dcd 0xffff8134
    dcd 0xffff8200
    dcd 0xffff82cd
    dcd 0xffff839a
    dcd 0xffff8467
    dcd 0xffff8534
    dcd 0xffff8600
    dcd 0xffff8801
    dcd 0xffff8b33
    dcd 0xffff8e67
    dcd 0xffff919b
    dcd 0xffff94cd
    dcd 0xffff9801
    dcd 0xffff9b33
    dcd 0xffff9e67
    dcd 0xffffa19b
    dcd 0xffffa4cd
    dcd 0xffffa801
    dcd 0xffffaccc
    dcd 0xffffb334
    dcd 0xffffb998
    dcd 0xffffc000
    dcd 0xffffc668
    dcd 0xffffcccc
    dcd 0xffffd334
    dcd 0xffffd998
    dcd 0xffffe000
    dcd 0xffffe668
    dcd 0xffffeccc
    dcd 0xfffff334
    dcd 0xfffff998
    dcd 0x00000000
    dcd 0x00000668
    dcd 0x00000ccc
    dcd 0x00001334
    dcd 0x00001998
    dcd 0x00002000
    dcd 0x00002668
    dcd 0x00002ccc
    dcd 0x00003334
    dcd 0x00003998
    dcd 0x00004000
    dcd 0x00004668
    dcd 0x00004ccc
    dcd 0x00005334
    dcd 0x000057ff
    dcd 0x00005b33
    dcd 0x00005e67
    dcd 0x00006199
    dcd 0x000064cd
    dcd 0x000067ff
    dcd 0x00006b33
    dcd 0x00006e65
    dcd 0x00007199
    dcd 0x000074cd
    dcd 0x000077ff
    dcd 0x00007a00
    dcd 0x00007acc
    dcd 0x00007b99
    dcd 0x00007c66
    dcd 0x00007d33
    dcd 0x00007e00
    dcd 0x00007ecc
    dcd 0xffff94cd
    dcd 0xffff9801
    dcd 0xffff9b33
    dcd 0xffff9e67
    dcd 0xffffa19b
    dcd 0xffffa4cd
    dcd 0xffffa801
    dcd 0xffffaccc
    dcd 0xffffb334
    dcd 0xffffb998
    dcd 0xffffc000
    dcd 0xffffc668
    dcd 0xffffcccc
    dcd 0xffffd334
    dcd 0xffffd998
    dcd 0xffffe000
    dcd 0xffffe668
    dcd 0xffffeccc
    dcd 0xfffff334
    dcd 0xfffff998
    dcd 0x00000000
    dcd 0x00000668
    dcd 0x00000ccc
    dcd 0x00001334
    dcd 0x00001998
    dcd 0x00002000
    dcd 0x00002668
    dcd 0x00002ccc
    dcd 0x00003334
    dcd 0x00003998
    dcd 0x00004000
    dcd 0x00004668
    dcd 0xffffb998
    dcd 0xffffc000
    dcd 0xffffc668
    dcd 0xffffcccc
    dcd 0xffffd334
    dcd 0xffffd998
    dcd 0xffffe000
    dcd 0xffffe668
    dcd 0xffffeccc
    dcd 0xfffff334
    dcd 0xfffff998
    dcd 0x00000000
    dcd 0x00000668
    dcd 0x00000ccc
    dcd 0x00001334
    dcd 0x00001998
    dcd 0x00002000
    dcd 0x00002668
    dcd 0x00002ccc
    dcd 0x00003334
    dcd 0x00003998
    dcd 0x00004000
    dcd 0x00004668
    dcd 0x00004ccc
    dcd 0x00005334
    dcd 0x000057ff
    dcd 0x00005b33
    dcd 0x00005e67
    dcd 0x00006199
    dcd 0x000064cd
    dcd 0x000067ff
    dcd 0x00006b33
    dcd 0xffffb330
    dcd 0xffffbc94
    dcd 0xffffc5f4
    dcd 0xffffcf58
    dcd 0xffffd8bc
    dcd 0xffffe220
    dcd 0xffffeb80
    dcd 0xfffff4e4
    dcd 0xfffffe48
    dcd 0x000007a8
    dcd 0x0000110c
    dcd 0x00001a70
    dcd 0x000023d4
    dcd 0x00002d34
    dcd 0x00003698
    dcd 0x00003ffc
    dcd 0xffffcccc
    dcd 0xffffdc28
    dcd 0xffffeb84
    dcd 0xfffffae0
    dcd 0x00000a3c
    dcd 0x00001998
    dcd 0x000028f4
    dcd 0x0000384c
    dcd 0xffffe664
    dcd 0xfffff4e4
    dcd 0x00000368
    dcd 0x000011e8
    dcd 0x00002068
    dcd 0x00002eec
    dcd 0x00003d6c
    dcd 0x00004bec
}

