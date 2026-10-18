#include "nitro/os.h"

#pragma force_active on

void CP_SaveContext(CPContext *context); // CP_SaveContext
void CPi_RestoreContext(CPContext *context); // CPi_RestoreContext
BOOL OS_IsRunOnTwl(void);

asm void OS_InitContext(register OSContext *context, register u32 newpc, register u32 stack) {
    add r1, r1, #4
    str r1, [r0, #0x40]
    str r2, [r0, #0x44]
    sub r2, r2, #0x40
    tst r2, #4
    subne r2, r2, #4
    str r2, [r0, #0x38]
    ands r1, r1, #1
    movne r1, #0x3f
    moveq r1, #0x1f
    str r1, [r0, #0]
    mov r1, #0
    str r1, [r0, #0x4]
    str r1, [r0, #0x8]
    str r1, [r0, #0xc]
    str r1, [r0, #0x10]
    str r1, [r0, #0x14]
    str r1, [r0, #0x18]
    str r1, [r0, #0x1c]
    str r1, [r0, #0x20]
    str r1, [r0, #0x24]
    str r1, [r0, #0x28]
    str r1, [r0, #0x2c]
    str r1, [r0, #0x30]
    str r1, [r0, #0x34]
    str r1, [r0, #0x3c]
    bx lr
}

asm BOOL OS_SaveContext(register OSContext *context) {
    stmfd sp!, {r0, lr}
    add r0, r0, #0x48
    ldr r1, =CP_SaveContext
    blx r1
    ldmfd sp!, {r0, lr}
    add r1, r0, #0
    mrs r2, CPSR
    str r2, [r1], #4
    mov r0, #0xd3
    msr CPSR_c, r0
    str sp, [r1, #0x40]
    msr CPSR_c, r2
    mov r0, #1
    stmia r1, {r0-r14}
    add r0, pc, #8
    str r0, [r1, #0x3c]
    mov r0, #0
    bx lr
}

asm void OS_LoadContext(register OSContext *context) {
    stmfd sp!, {r0, lr}
    add r0, r0, #0x48
    ldr r1, =CPi_RestoreContext
    blx r1
    ldmfd sp!, {r0, lr}
    mrs r1, CPSR
    bic r1, r1, #0x1f
    orr r1, r1, #0xd3
    msr CPSR_c, r1
    ldr r1, [r0], #4
    msr SPSR_fsxc, r1
    ldr sp, [r0, #0x40]
    ldr lr, [r0, #0x3c]
    ldmia r0, {r0-r14}^
    mov r0, r0
    stmfd sp!, {r0-r3, r12, lr}
    bl OS_IsRunOnTwl
    beq @1
    ldr r0, =0x4000280
@2:
    ldr r1, [r0]
    ands r1, r1, #0x8000
    bne @2
@1:
    ldmfd sp!, {r0-r3, r12, lr}
    subs pc, lr, #4
}
