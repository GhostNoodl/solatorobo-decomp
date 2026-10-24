#include "nitro/mi_uncomp_stream.h"

void MI_InitUncompContextRL (MIUncompContextRL * context, u8 * dest, const MICompressionHeader * header)
{
    context->destp = dest;
    context->destCount = (s32)header->destSize;
    context->flags = 0;
    context->length = 0;
    context->destTmp = 0;
    context->destTmpCnt = 0;
}

void MI_InitUncompContextLZ (MIUncompContextLZ * context, u8 * dest, const MICompressionHeader * header)
{
    context->destp = dest;
    context->destCount = (s32)header->destSize;
    context->flags = 0;
    context->flagIndex = 0;
    context->length = 0;
    context->lengthFlg = 3;
    context->destTmp = 0;
    context->destTmpCnt = 0;
    context->exFormat = (u8)((header->compParam == 0)? 0U : 1U);
}

#pragma thumb off

asm s32 MI_ReadUncompRL8 (register MIUncompContextRL * context, register const u8 * data, register u32 len)
{
    stmfd sp !, {r4 - r8}
    ldr r3, [r0, #MIUncompContextRL.destp]
    ldr r4, [r0, #MIUncompContextRL.destCount]
    ldrb r5, [r0, #MIUncompContextRL.flags]
    ldrh r6, [r0, #MIUncompContextRL.length]
@41:
    cmp r4, #0
    ble @49
    tst r5, #0x80
    bne @43
@42:
    cmp r6, #0
    ble @45
    sub r6, r6, #1
    ldrb r7, [r1], #1
    sub r4, r4, #1
    swpb r8, r7, [r3]
    add r3, r3, #1
    subs r2, r2, #1
    beq @49
    b @42
@43:
    cmp r6, #0
    ble @45
    ldrb r7, [r1], #1
@44:
    sub r4, r4, #1
    swpb r8, r7, [r3]
    add r3, r3, #1
    subs r6, r6, #1
    bgt @44
    subs r2, r2, #1
    beq @49
@45:
    ldrb r5, [r1], #1
    and r6, r5, #0x7F
    tst r5, #0x80
    addne r6, r6, #2
    add r6, r6, #1
    subs r2, r2, #1
    bne @41
@49:
    str r3, [r0, #MIUncompContextRL.destp]
    str r4, [r0, #MIUncompContextRL.destCount]
    strb r5, [r0, #MIUncompContextRL.flags]
    strh r6, [r0, #MIUncompContextRL.length]
    mov r0, r4
    ldmfd sp !, {r4 - r8}
    bx lr
}

asm s32 MI_ReadUncompLZ8 (register MIUncompContextLZ * context, register const u8 * data, register u32 len)
{
    stmfd sp !, {r4 - r11}
    ldr r3, [r0, #MIUncompContextLZ.destp]
    ldr r4, [r0, #MIUncompContextLZ.destCount]
    ldrb r5, [r0, #MIUncompContextLZ.flags]
    ldrb r6, [r0, #MIUncompContextLZ.flagIndex]
    ldr r7, [r0, #MIUncompContextLZ.length]
    ldrb r8, [r0, #MIUncompContextLZ.lengthFlg]
    ldrb r11, [r0, #MIUncompContextLZ.exFormat]
@21:
    cmp r4, #0
    ble @29
    cmp r6, #0
    beq @28
@22
    cmp r2, #0
    beq @29
    tst r5, #0x80
    bne @23
    ldrb r9, [r1], #1
    sub r4, r4, #1
    sub r2, r2, #1
    swpb r9, r9, [r3]
    add r3, r3, #1
    b @26
@23:
    cmp r8, #0
    beq @24
    cmp r11, #1
    bne @23_9
    subs r8, r8, #1
    beq @23_7
    cmp r8, #1
    beq @23_6
    ldrb r7, [r1], #1
    tst r7, #0xE0
    beq @23_4
    add r7, r7, #0x10
    mov r8, #0
    b @23_10
@23_4:
    mov r10, #0x110
    tst r7, #0x10
    beq @23_5
    and r7, r7, #0xF
    add r10, r10, #0x1000
    add r7, r10, r7, lsl #16
    b @23_8
@23_5:
    and r7, r7, #0xF
    add r7, r10, r7, lsl #8
    mov r8, #1
    b @23_8
@23_6:
    ldrb r10, [r1], #1
    add r7, r7, r10, lsl #8
    b @23_8
@23_7:
    ldrb r10, [r1], #1
    add r7, r7, r10
    b @23_10
@23_8:
    subs r2, r2, #1
    beq @29
    b @23
@23_9:
    ldrb r7, [r1], #1
    add r7, r7, #0x30
    mov r8, #0
@23_10:
    subs r2, r2, #1
    beq @29
@24:
    and r9, r7, #0xF
    mov r10, r9, lsl #8
    ldrb r9, [r1], #1
    mov r8, #3
    sub r2, r2, #1
    orr r9, r9, r10
    add r9, r9, #1
    movs r7, r7, asr #4
    beq @26
@25:
    ldrb r10, [r3, -r9]
    sub r4, r4, #1
    swpb r10, r10, [r3]
    add r3, r3, #1
    subs r7, r7, #1
    bgt @25
@26:
    cmp r4, #0
    beq @29
    mov r5, r5, lsl #1
    subs r6, r6, #1
    bne @22
@28:
    cmp r2, #0
    beq @29
    ldrb r5, [r1], #1
    mov r6, #8
    sub r2, r2, #1
    b @21
@29:
    str r3, [r0, #MIUncompContextLZ.destp]
    str r4, [r0, #MIUncompContextLZ.destCount]
    strb r5, [r0, #MIUncompContextLZ.flags]
    strb r6, [r0, #MIUncompContextLZ.flagIndex]
    str r7, [r0, #MIUncompContextLZ.length]
    strb r8, [r0, #MIUncompContextLZ.lengthFlg]
    strb r11, [r0, #MIUncompContextLZ.exFormat]
    mov r0, r4
    ldmfd sp !, {r4 - r11}
    bx lr
}

#define TREE_END_MASK 0x80

#pragma thumb reset

void MI_SetWramBank(int cnt);
BOOL OS_IsRunOnTwl(void);
void MI_StopDma(u32 dmaNo);
void func_0228de18(void);  /* TWL only */

void func_0201771c (void)
{
    MI_SetWramBank(3);
    if (OS_IsRunOnTwl()) {
        func_0228de18();
    }
    MI_StopDma(0);
}
