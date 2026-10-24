#include "nitro/os.h"

void func_0201ae80(void);
void OS_Halt(void);
void func_02017c1c(u16 data);
u32 OS_GetProcMode(void);
BOOL OS_IsRunOnTwl(void);
BOOL func_0221cce8(void);  /* TWL only */
void func_0221ccf8(void);  /* TWL only */

typedef struct {
    void *arg;               // 0x00
    void (*func)(void *arg); // 0x04
    BOOL terminating;        // 0x08
} OSiTerminateStat;

extern OSiTerminateStat data_0208eff0;

static inline u16 OSi_EnableIrq(void)
{
    u16 prep = *(vu16 *)0x04000208;
    *(vu16 *)0x04000208 = 1;
    return prep;
}

void OS_Terminate (void)
{
    void (*func)(void *) = data_0208eff0.func;

    if (func) {
        data_0208eff0.func = NULL;
        func(data_0208eff0.arg);
    }
    if (!data_0208eff0.terminating) {
        data_0208eff0.terminating = TRUE;
        if (OS_GetProcMode() != 0x12) {
            (void)OSi_EnableIrq();
            (void)OS_EnableInterrupts();
        }
        if (OS_IsRunOnTwl()) {
            if (func_0221cce8()) {
                func_0221ccf8();
            }
        }
        func_02017c1c(0x20);
    }
    func_0201ae80();
}

void func_0201ae80 (void)
{
    (void)OS_DisableInterrupts();
    while (1) {
        OS_Halt();
    }
}

asm void OS_Halt (void)
{
    mov r0, #0
    mcr p15, 0, r0, c7, c0, 4
    bx lr
}
