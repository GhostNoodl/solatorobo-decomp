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

#pragma thumb reset
