#include "nitro/os.h"
#include "nitro/pxi.h"

void PXI_Init(void);
void OS_InitArena(void);
void OS_InitLock(void);
void func_020194a0(void);
void OS_InitIrqTable(void);
void OS_SetIrqStackChecker(void);
void OS_InitException(void);
void func_0201771c(void);
void OS_InitVAlarm(void);
void OSi_InitVramExclusive(void);
void OS_InitThread(void);
void OS_InitReset(void);
void func_0203d5b8(void);
void CARD_Init(void);
void func_020163b8(void);
void func_0201bbd4(void);
void PM_Init(void);
void func_0201af94(void);

void OS_Init(void);
void func_02019318(void);

static asm void OSi_WaitVCount0 (void)
{
    mov ip, #0x4000000
    ldr r1, [ip, #0x208]
    str ip, [ip, #0x208]
@1:
    ldrh r0, [ip, #0x6]
    cmp r0, #0
    bne @1
    str r1, [ip, #0x208]
    bx lr
}

void OS_Init (void)
{
    func_02019318();
}

void func_02019318 (void)
{
    PXI_Init();
    OS_InitArena();
    OS_InitLock();
    func_020194a0();
    OS_InitIrqTable();
    OS_SetIrqStackChecker();
    OS_InitException();
    func_0201771c();
    OS_InitVAlarm();
    OSi_InitVramExclusive();
    OS_InitThread();
    OS_InitReset();
    func_0203d5b8();
    CARD_Init();
    func_020163b8();
    if (OS_IsRunOnTwl() == TRUE) {
        func_0201bbd4();
    }
    PM_Init();
    OSi_WaitVCount0();
    if (OS_IsRunOnTwl() == TRUE) {
        func_0201af94();
    }
}
