#include "nitro/mi.h"

#pragma thumb off

asm void MIi_CpuClear16 (register u16 data, register void * destp, register u32 size)
{
    mov r3, #0
@00:
    cmp r3, r2
    strlth r0, [r1, r3]
    addlt r3, r3, #2
    blt @00
    bx lr
}

asm void MIi_CpuCopy16 (register const void * srcp, register void * destp, register u32 size)
{
    mov r12, #0
@10:
    cmp r12, r2
        ldrlth r3, [r0, r12]
        strlth r3, [r1, r12]
    addlt r12, r12, #2
    blt @10
    bx lr
}

asm void MIi_CpuClear32 (register u32 data, register void * destp, register u32 size)
{
    add r12, r1, r2
@20:
    cmp r1, r12
    stmltia r1 !, {r0}
    blt @20
    bx lr
}

asm void MIi_CpuCopy32 (register const void * srcp, register void * destp, register u32 size)
{
    add r12, r1, r2
@30:
    cmp r1, r12
    ldmltia r0 !, {r2}
    stmltia r1 !, {r2}
    blt @30
    bx lr
}

asm void MIi_CpuSend32 (register const void * srcp, volatile void * destp, u32 size)
{
    add r12, r0, r2
@31:
    cmp r0, r12
    ldmltia r0 !, {r2}
    strlt r2, [r1]
    blt @31
    bx lr
}

asm void MIi_CpuClearFast (register u32 data, register void * destp, register u32 size)
{
    stmfd sp !, {r4 - r9}
    add r9, r1, r2
    mov r12, r2, lsr #5
    add r12, r1, r12, lsl #5
    mov r2, r0
    mov r3, r2
    mov r4, r2
    mov r5, r2
    mov r6, r2
    mov r7, r2
    mov r8, r2
@40:
    cmp r1, r12
    stmltia r1 !, {r0, r2 - r8}
    blt @40
@41:
    cmp r1, r9
    stmltia r1 !, {r0}
    blt @41
    ldmfd sp !, {r4 - r9}
    bx lr
}

asm void MIi_CpuCopyFast (register const void * srcp, register void * destp, register u32 size)
{
    stmfd sp !, {r4 - r10}
    add r10, r1, r2
    mov r12, r2, lsr #5
    add r12, r1, r12, lsl #5
@50:
    cmp r1, r12
    ldmltia r0 !, {r2 - r9}
    stmltia r1 !, {r2 - r9}
    blt @50
@51:
    cmp r1, r10
    ldmltia r0 !, {r2}
    stmltia r1 !, {r2}
    blt @51
    ldmfd sp !, {r4 - r10}
    bx lr
}

asm void MI_Copy32B (register const void * pSrc, register void * pDest)
{
    ldmia r0 !, {r2, r3, r12}
    stmia r1 !, {r2, r3, r12}
    ldmia r0 !, {r2, r3, r12}
    stmia r1 !, {r2, r3, r12}
    ldmia r0 !, {r2, r3}
    stmia r1 !, {r2, r3}
    bx lr
}

asm void MI_Copy36B (register const void * pSrc, register void * pDest)
{
    ldmia r0 !, {r2, r3, r12}
    stmia r1 !, {r2, r3, r12}
    ldmia r0 !, {r2, r3, r12}
    stmia r1 !, {r2, r3, r12}
    ldmia r0 !, {r2, r3, r12}
    stmia r1 !, {r2, r3, r12}
    bx lr
}

asm void MI_Copy48B (register const void * pSrc, register void * pDest)
{
    ldmia r0 !, {r2, r3, r12}
    stmia r1 !, {r2, r3, r12}
    ldmia r0 !, {r2, r3, r12}
    stmia r1 !, {r2, r3, r12}
    ldmia r0 !, {r2, r3, r12}
    stmia r1 !, {r2, r3, r12}
    ldmia r0 !, {r2, r3, r12}
    stmia r1 !, {r2, r3, r12}
    bx lr
}

asm void MI_Copy64B (register const void * pSrc, register void * pDest)
{
    ldmia r0 !, {r2, r3, r12}
    stmia r1 !, {r2, r3, r12}
    ldmia r0 !, {r2, r3, r12}
    stmia r1 !, {r2, r3, r12}
    ldmia r0 !, {r2, r3, r12}
    stmia r1 !, {r2, r3, r12}
    ldmia r0 !, {r2, r3, r12}
    stmia r1 !, {r2, r3, r12}
    ldmia r0, {r0, r2, r3, r12}
    stmia r1 !, {r0, r2, r3, r12}
    bx lr
}

    asm void MI_CpuFill8 (register void * dstp, register u8 data, register u32 size)
    {
        cmp r2, #0
            bxeq lr
        tst r0, #1
        beq @_1
        ldrh r12, [r0, #- 1]
        and r12, r12, #0x00FF
        orr r3, r12, r1, lsl #8
        strh r3, [r0, #- 1]
        add r0, r0, #1
        subs r2, r2, #1
        bxeq lr
    @_1:
        cmp r2, #2
        bcc @_6
        orr r1, r1, r1, lsl #8
        tst r0, #2
        beq @_8
        strh r1, [r0], #2
        subs r2, r2, #2
        bxeq lr
    @_8:
        orr r1, r1, r1, lsl #16
        bics r3, r2, #3
        beq @_10
        sub r2, r2, r3
        add r12, r3, r0
    @_9:
        str r1, [r0], #4
        cmp r0, r12
        bcc @_9
    @_10:
        tst r2, #2
            strneh r1, [r0], #2
    @_6:
        tst r2, #1
        bxeq lr
        ldrh r3, [r0]
        and r3, r3, #0xFF00
        and r1, r1, #0x00FF
        orr r1, r1, r3
        strh r1, [r0]
        bx lr
    }

#pragma force_active on
asm void func_02016ebc(register void *dstp, register u8 data, register u32 size)
{
    cmp r2, #0
    bxeq lr
    cmp r2, #8
    bgt @L2016efc
    rsb r3, r2, #8
    add pc, pc, r3, lsl #2
    mov r0, r0
    strb r1, [r0], #1
    strb r1, [r0], #1
    strb r1, [r0], #1
    strb r1, [r0], #1
    strb r1, [r0], #1
    strb r1, [r0], #1
    strb r1, [r0], #1
    strb r1, [r0], #1
    bx lr
@L2016efc:
    orr r1, r1, r1, lsl #8
    orr r1, r1, r1, lsl #16
    tst r0, #1
    subne r2, r2, #1
    strneb r1, [r0], #1
    tst r0, #2
    subne r2, r2, #2
    strneh r1, [r0], #2
    tst r0, #4
    subne r2, r2, #4
    strne r1, [r0], #4
    cmp r2, #0x20
    blt @L2016f68
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10}
    mov r4, r1
    mov r5, r1
    mov r6, r1
    mov r7, r1
    mov r8, r1
    mov r9, r1
    mov r10, r1
    subs r2, r2, #0x20
@L2016f54:
    stmgeia r0!, {r1, r4, r5, r6, r7, r8, r9, r10}
    subges r2, r2, #0x20
    bge @L2016f54
    add r2, r2, #0x20
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10}
@L2016f68:
    cmp r2, #4
    blt @L2016f84
    subs r2, r2, #4
@L2016f74:
    strge r1, [r0], #4
    subs r2, r2, #4
    bge @L2016f74
    add r2, r2, #4
@L2016f84:
    subs r2, r2, #1
    strgeb r1, [r0], #1
    subges r2, r2, #1
    strgeb r1, [r0], #1
    subges r2, r2, #1
    strgeb r1, [r0], #1
    bx lr
}
#pragma force_active reset

asm void MI_CpuCopy8(register const void *srcp, register void *dstp, register u32 size)
{
    cmp r2, #0
    bxeq lr
    tst r1, #1
    beq @L2016fe0
    ldrh r12, [r1, #-1]
    and r12, r12, #0xff
    tst r0, #1
    ldrneh r3, [r0, #-1]
    movne r3, r3, lsr #8
    ldreqh r3, [r0]
    orr r3, r12, r3, lsl #8
    strh r3, [r1, #-1]
    add r0, r0, #1
    add r1, r1, #1
    subs r2, r2, #1
    bxeq lr
@L2016fe0:
    eor r12, r1, r0
    tst r12, #1
    beq @L2017034
    bic r0, r0, #1
    ldrh r12, [r0], #2
    mov r3, r12, lsr #8
    subs r2, r2, #2
    blo @L2017018
@L2017000:
    ldrh r12, [r0], #2
    orr r12, r3, r12, lsl #8
    strh r12, [r1], #2
    mov r3, r12, lsr #0x10
    subs r2, r2, #2
    bhs @L2017000
@L2017018:
    tst r2, #1
    bxeq lr
    ldrh r12, [r1]
    and r12, r12, #0xff00
    orr r12, r12, r3
    strh r12, [r1]
    bx lr
@L2017034:
    tst r12, #2
    beq @L2017060
    bics r3, r2, #1
    beq @L20170ac
    sub r2, r2, r3
    add r12, r3, r1
@L201704c:
    ldrh r3, [r0], #2
    strh r3, [r1], #2
    cmp r1, r12
    blo @L201704c
    b @L20170ac
@L2017060:
    cmp r2, #2
    blo @L20170ac
    tst r1, #2
    beq @L2017080
    ldrh r3, [r0], #2
    strh r3, [r1], #2
    subs r2, r2, #2
    bxeq lr
@L2017080:
    bics r3, r2, #3
    beq @L20170a0
    sub r2, r2, r3
    add r12, r3, r1
@L2017090:
    ldr r3, [r0], #4
    str r3, [r1], #4
    cmp r1, r12
    blo @L2017090
@L20170a0:
    tst r2, #2
    ldrneh r3, [r0], #2
    strneh r3, [r1], #2
@L20170ac:
    tst r2, #1
    bxeq lr
    ldrh r2, [r1]
    ldrh r0, [r0]
    and r2, r2, #0xff00
    and r0, r0, #0xff
    orr r0, r2, r0
    strh r0, [r1]
    bx lr
}

#pragma force_active on
s32 func_020170d0(const void *buf1, const void *buf2, u32 size) {
    const u8 *p1 = (const u8 *)buf1;
    const u8 *p2 = (const u8 *)buf2;
    const u8 *end = p1 + size;
    while (p1 < end) {
        s32 diff = *p1++ - *p2++;
        if (diff != 0) {
            return diff;
        }
    }
    return 0;
}
#pragma force_active reset

#pragma force_active on
asm void func_02017100(register const void *srcp, register void *dstp, register u32 size)
{
    cmp r2, #8
    bgt @L2017158
    rsb r3, r2, #8
    add pc, pc, r3, lsl #3
    mov r0, r0
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    bx lr
@L2017158:
    tst r0, #1
    subne r2, r2, #1
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    tst r0, #2
    subne r2, r2, #2
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    and r3, r1, #3
    bic r1, r1, #3
    cmp r3, #0
    beq @L20171a4
    cmp r3, #1
    beq @L20171e0
    cmp r3, #2
    beq @L2017278
    b @L2017310
@L20171a4:
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #0x20
@L20171ac:
    ldmgeia r0!, {r4, r5, r6, r7, r8, r9, r10, lr}
    stmgeia r1!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subges r2, r2, #0x20
    bge @L20171ac
    add r2, r2, #0x20
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #4
@L20171c8:
    ldrge r3, [r0], #4
    strge r3, [r1], #4
    subges r2, r2, #4
    bge @L20171c8
    add r2, r2, #4
    b @L20173a8
@L20171e0:
    ldr r12, [r1]
    mov r12, r12, lsl #0x18
    mov r12, r12, lsr #0x18
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #0x20
@L20171f4:
    ldmgeia r0!, {r4, r5, r6, r7, r8, r9, r10, lr}
    movge r3, r4, lsr #0x18
    orrge r4, r12, r4, lsl #8
    movge r12, r5, lsr #0x18
    orrge r5, r3, r5, lsl #8
    movge r3, r6, lsr #0x18
    orrge r6, r12, r6, lsl #8
    movge r12, r7, lsr #0x18
    orrge r7, r3, r7, lsl #8
    movge r3, r8, lsr #0x18
    orrge r8, r12, r8, lsl #8
    movge r12, r9, lsr #0x18
    orrge r9, r3, r9, lsl #8
    movge r3, r10, lsr #0x18
    orrge r10, r12, r10, lsl #8
    movge r12, lr, lsr #0x18
    orrge lr, r3, lr, lsl #8
    stmgeia r1!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subges r2, r2, #0x20
    bge @L20171f4
    add r2, r2, #0x20
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #4
@L2017250:
    ldrge r3, [r0], #4
    orrge r12, r12, r3, lsl #8
    strge r12, [r1], #4
    movge r12, r3, lsr #0x18
    subges r2, r2, #4
    bge @L2017250
    add r2, r2, #4
    sub r0, r0, #1
    add r2, r2, #1
    b @L20173a8
@L2017278:
    ldr r12, [r1]
    mov r12, r12, lsl #0x10
    mov r12, r12, lsr #0x10
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #0x20
@L201728c:
    ldmgeia r0!, {r4, r5, r6, r7, r8, r9, r10, lr}
    movge r3, r4, lsr #0x10
    orrge r4, r12, r4, lsl #16
    movge r12, r5, lsr #0x10
    orrge r5, r3, r5, lsl #16
    movge r3, r6, lsr #0x10
    orrge r6, r12, r6, lsl #16
    movge r12, r7, lsr #0x10
    orrge r7, r3, r7, lsl #16
    movge r3, r8, lsr #0x10
    orrge r8, r12, r8, lsl #16
    movge r12, r9, lsr #0x10
    orrge r9, r3, r9, lsl #16
    movge r3, r10, lsr #0x10
    orrge r10, r12, r10, lsl #16
    movge r12, lr, lsr #0x10
    orrge lr, r3, lr, lsl #16
    stmgeia r1!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subges r2, r2, #0x20
    bge @L201728c
    add r2, r2, #0x20
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #4
@L20172e8:
    ldrge r3, [r0], #4
    orrge r12, r12, r3, lsl #16
    strge r12, [r1], #4
    movge r12, r3, lsr #0x10
    subges r2, r2, #4
    bge @L20172e8
    add r2, r2, #4
    sub r0, r0, #2
    add r2, r2, #2
    b @L20173a8
@L2017310:
    ldr r12, [r1]
    mov r12, r12, lsl #8
    mov r12, r12, lsr #8
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #0x20
@L2017324:
    ldmgeia r0!, {r4, r5, r6, r7, r8, r9, r10, lr}
    movge r3, r4, lsr #8
    orrge r4, r12, r4, lsl #24
    movge r12, r5, lsr #8
    orrge r5, r3, r5, lsl #24
    movge r3, r6, lsr #8
    orrge r6, r12, r6, lsl #24
    movge r12, r7, lsr #8
    orrge r7, r3, r7, lsl #24
    movge r3, r8, lsr #8
    orrge r8, r12, r8, lsl #24
    movge r12, r9, lsr #8
    orrge r9, r3, r9, lsl #24
    movge r3, r10, lsr #8
    orrge r10, r12, r10, lsl #24
    movge r12, lr, lsr #8
    orrge lr, r3, lr, lsl #24
    stmgeia r1!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subges r2, r2, #0x20
    bge @L2017324
    add r2, r2, #0x20
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #4
@L2017380:
    ldrge r3, [r0], #4
    orrge r12, r12, r3, lsl #24
    strge r12, [r1], #4
    movge r12, r3, lsr #8
    subges r2, r2, #4
    bge @L2017380
    add r2, r2, #4
    sub r0, r0, #3
    add r2, r2, #3
    b @L20173a8
@L20173a8:
    tst r2, #4
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    tst r2, #2
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    tst r2, #1
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    bx lr
}
#pragma force_active reset

#pragma thumb on

asm void MI_Zero36B(register void *pDest)
{
    mov r1, #0
    mov r2, #0
    mov r3, #0
    stmia r0!, {r1, r2, r3}
    stmia r0!, {r1, r2, r3}
    stmia r0!, {r1, r2, r3}
    bx lr
}

#pragma thumb reset
#pragma thumb reset
