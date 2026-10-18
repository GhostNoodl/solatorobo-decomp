#include "nitro/os.h"

#define HW_EXCP_VECTOR_BUF_FOR_DEBUGGER     0x02fffd9c
#define HW_EXCP_VECTOR_BUF_NITRO            0x027ffd9c
#define HW_ITCM_END                         0x02000000

typedef void (*OSExceptionHandler)(u32, void *);

typedef struct {
    u8 context[0x64];
    u32 cp15;
    u32 spsr;
    u32 exinfo;
} OSiExContext;

void OS_InitException(void);
void OS_EnableProtectionUnit(void);
void OS_DisableProtectionUnit(void);

static asm void OSi_ExceptionHandler(void);
static asm void OSi_GetAndDisplayContext(void);
static asm void OSi_SetExContext(void);
static void OSi_DisplayExContext(void);

static void * OSi_DebuggerHandler = NULL;
static OSExceptionHandler OSi_UserExceptionHandler = NULL;
static u32 OSi_DebuggerVector = 0;
static void * OSi_UserExceptionHandlerArg = NULL;
static u32 OSi_ExceptionHookStack[8] = { 0 };
static OSiExContext OSi_ExContext = { 0 };

void OS_InitException (void)
{
    OSi_DebuggerVector = *(u32 *)HW_EXCP_VECTOR_BUF_FOR_DEBUGGER;
    OSi_DebuggerHandler = (0x2600000 <= OSi_DebuggerVector && OSi_DebuggerVector < 0x2800000) ? (void *)OSi_DebuggerVector : NULL;

    if (!OSi_DebuggerHandler) {
        u32 *vector = (u32 *)HW_EXCP_VECTOR_BUF_FOR_DEBUGGER;
        *vector = (u32)OSi_ExceptionHandler;
        if (!OS_IsRunOnTwl()) {
            *(u32 *)((u32)vector & ~0x800000) = (u32)OSi_ExceptionHandler;
        }
    }

    OSi_UserExceptionHandler = NULL;
}

asm void OSi_ExceptionHandler (void)
{
    ldr r12, =OSi_DebuggerHandler
    ldr r12, [r12]
    cmp r12, #0
    movne lr, pc
    bxne r12
    ldr r12, =HW_ITCM_END
    stmfd r12!, {r0-r3, sp, lr}
    and r0, sp, #1
    mov sp, r12
    mrs r1, CPSR
    and r1, r1, #0x1f
    teq r1, #0x17
    bne @10
    bl OSi_GetAndDisplayContext
    b usr_return
@10:
    teq r1, #0x1b
    bne usr_return
    bl OSi_GetAndDisplayContext
usr_return:
    ldr r12, =OSi_DebuggerHandler
    ldr r12, [r12]
    cmp r12, #0
@1:
    beq @1
@2:
    mov r0, r0
    b @2
    ldmfd sp!, {r0-r3, r12, lr}
    mov sp, r12
    bx lr
}

static asm void OSi_GetAndDisplayContext (void)
{
    stmfd sp!, {r0, lr}
    bl OSi_SetExContext
    bl OSi_DisplayExContext
    ldmfd sp!, {r0, lr}
    bx lr
}

static asm void OSi_SetExContext (void)
{
    ldr r1, =OSi_ExContext
    str r0, [r1, #0x6c]
    ldr r0, [r12, #0]
    str r0, [r1, #0x4]
    ldr r0, [r12, #4]
    str r0, [r1, #0x8]
    ldr r0, [r12, #8]
    str r0, [r1, #0xc]
    ldr r0, [r12, #12]
    str r0, [r1, #0x10]
    ldr r2, [r12, #16]
    bic r2, r2, #1
    add r0, r1, #0x14
    stmia r0, {r4-r11}
    ldr r0, [r2, #0]
    str r0, [r1, #0x64]
    ldr r3, [r2, #4]
    str r3, [r1, #0x0]
    ldr r0, [r2, #8]
    str r0, [r1, #0x34]
    ldr r0, [r2, #12]
    str r0, [r1, #0x40]
    mrs r0, CPSR
    orr r3, r3, #0x80
    bic r3, r3, #0x20
    msr CPSR_cxsf, r3
    str sp, [r1, #0x38]
    str lr, [r1, #0x3c]
    mrs r2, SPSR
    msr CPSR_cxsf, r0
    bx lr
}

static void OSi_DisplayExContext (void)
{
    if (OSi_UserExceptionHandler) {
        asm {
            mrs r2, CPSR
            mov r0, sp
            ldr r1, =0x9f
            msr CPSR_cxsf, r1
            mov r1, sp
            mov sp, r0
            stmfd sp!, {r1, r2}
            bl OS_EnableProtectionUnit
            ldr r0, =OSi_ExContext
            ldr r1, =OSi_UserExceptionHandlerArg
            ldr r1, [r1]
            ldr r12, =OSi_UserExceptionHandler
            ldr r12, [r12]
            ldr lr, =@1
            bx r12
        @1:
            bl OS_DisableProtectionUnit
            ldmfd sp!, {r1, r2}
            mov sp, r1
            msr CPSR_cxsf, r2
        }
    }
}
