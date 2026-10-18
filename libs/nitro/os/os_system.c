#include "nitro/os.h"
#include "nitro/os_interrupt.h"

#define HW_PSR_IRQ_DISABLE      0x80
#define HW_PSR_IRQ_FIQ_DISABLE  0xc0
#define HW_PSR_CPU_MODE_MASK    0x1f

#define reg_SCFG_CLK            (*(vu16 *)0x04004004)

void WaitByLoop(s32 count);

#define SVC_WaitByLoop WaitByLoop

typedef u32 OSIntrMode_Irq;
typedef u32 OSProcMode;

OSIntrMode_Irq OS_GetCpsrIrq(void);
OSProcMode OS_GetProcMode(void);
void OS_WaitVBlankIntr(void);

asm OSIntrMode OS_EnableInterrupts (void)
{
    mrs r0, cpsr
    bic r1, r0, #HW_PSR_IRQ_DISABLE
    msr cpsr_c, r1
    and r0, r0, #HW_PSR_IRQ_DISABLE
    bx lr
}

asm OSIntrMode OS_DisableInterrupts (void)
{
    mrs r0, cpsr
    orr r1, r0, #HW_PSR_IRQ_DISABLE
    msr cpsr_c, r1
    and r0, r0, #HW_PSR_IRQ_DISABLE
    bx lr
}

asm OSIntrMode OS_RestoreInterrupts (register OSIntrMode state)
{
    mrs r1, cpsr
    bic r2, r1, #HW_PSR_IRQ_DISABLE
    orr r2, r2, r0
    msr cpsr_c, r2
    and r0, r1, #HW_PSR_IRQ_DISABLE
    bx lr
}

asm OSIntrMode OS_DisableInterrupts_IrqAndFiq (void)
{
    mrs r0, cpsr
    orr r1, r0, #HW_PSR_IRQ_FIQ_DISABLE
    msr cpsr_c, r1
    and r0, r0, #HW_PSR_IRQ_FIQ_DISABLE
    bx lr
}

asm OSIntrMode OS_RestoreInterrupts_IrqAndFiq (register OSIntrMode state)
{
    mrs r1, cpsr
    bic r2, r1, #HW_PSR_IRQ_FIQ_DISABLE
    orr r2, r2, r0
    msr cpsr_c, r2
    and r0, r1, #HW_PSR_IRQ_FIQ_DISABLE
    bx lr
}

asm OSIntrMode_Irq OS_GetCpsrIrq (void)
{
    mrs r0, cpsr
    and r0, r0, #HW_PSR_IRQ_DISABLE
    bx lr
}

asm OSProcMode OS_GetProcMode (void)
{
    mrs r0, cpsr
    and r0, r0, #HW_PSR_CPU_MODE_MASK
    bx lr
}

asm void OS_SpinWaitCpuCycles (u32 cycles)
{
_1: subs r0, r0, #4
    bcs _1
    bx lr
}

void OS_SpinWaitSysCycles (u32 cycles)
{
    cycles <<= ((reg_SCFG_CLK & 1) == 1) ? 2 : 1;
    if (cycles > 16) {
        OS_SpinWaitCpuCycles(cycles - 16);
    }
}

void OS_WaitVBlankIntr (void)
{
    SVC_WaitByLoop(1);
    OS_WaitIrq(TRUE, OS_IE_V_BLANK);
}
