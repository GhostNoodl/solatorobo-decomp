#include "nitro/os.h"

void func_0201ae80(void);
void OS_Halt(void);

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
