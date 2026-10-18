/* OSi_IRQ_STACK_TOP is computed from the linker symbol SDK_IRQ_STACKSIZE, which C cannot express here */
#include "nitro/os.h"

void OS_SetIrqStackChecker(void);

asm void OS_SetIrqStackChecker (void)
{
    ldr ip, =data_02fe0000
    ldr r3, =0xfddb597d
    add r0, ip, #0x3000
    ldr r2, =0x7bf9dd5b
    ldr r1, =0x800
    str r3, [r0, #0xf7c]
    add r0, ip, #0x3f80
    str r2, [r0, -r1]
    bx lr
}
