#ifndef NITRO_OS_INTERRUPT_H
#define NITRO_OS_INTERRUPT_H

// From the NitroSDK (nitro/os/common/interrupt.h)
#include "nitro/os.h"
#include "nitro/ioreg.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OS_IME_DISABLE              (0UL << REG_OS_IME_IME_SHIFT)
#define OS_IME_ENABLE               (1UL << REG_OS_IME_IME_SHIFT)

#define OS_IE_V_BLANK               (1UL << REG_OS_IE_VB_SHIFT)
#define OS_IE_H_BLANK               (1UL << REG_OS_IE_HB_SHIFT)
#define OS_IE_V_COUNT               (1UL << REG_OS_IE_VE_SHIFT)
#define OS_IE_TIMER0                (1UL << REG_OS_IE_T0_SHIFT)
#define OS_IE_TIMER1                (1UL << REG_OS_IE_T1_SHIFT)
#define OS_IE_TIMER2                (1UL << REG_OS_IE_T2_SHIFT)
#define OS_IE_TIMER3                (1UL << REG_OS_IE_T3_SHIFT)
#define OS_IE_SIO                   (1UL << 7)
#define OS_IE_DMA0                  (1UL << REG_OS_IE_D0_SHIFT)
#define OS_IE_DMA1                  (1UL << REG_OS_IE_D1_SHIFT)
#define OS_IE_DMA2                  (1UL << REG_OS_IE_D2_SHIFT)
#define OS_IE_DMA3                  (1UL << REG_OS_IE_D3_SHIFT)
#define OS_IE_KEY                   (1UL << REG_OS_IE_K_SHIFT)
#define OS_IE_CARTRIDGE             (1UL << REG_OS_IE_I_D_SHIFT)
#define OS_IE_SUBP                  (1UL << REG_OS_IE_A7_SHIFT)
#define OS_IE_SPFIFO_SEND           (1UL << REG_OS_IE_IFE_SHIFT)
#define OS_IE_SPFIFO_RECV           (1UL << REG_OS_IE_IFN_SHIFT)
#define OS_IE_CARD_DATA             (1UL << REG_OS_IE_MC_SHIFT)
#define OS_IE_CARD_IREQ             (1UL << REG_OS_IE_MI_SHIFT)

    #define OS_IE_GXFIFO            (1UL << REG_OS_IE_GF_SHIFT)
    #define OS_IRQ_TABLE_MAX        22

#define OS_IE_FIFO_SEND             OS_IE_SPFIFO_SEND
#define OS_IE_FIFO_RECV             OS_IE_SPFIFO_RECV

#define OS_IE_USER_FLAG0_SHIFT      31
#define OS_IE_USER_FLAG1_SHIFT      30
#define OS_IE_USER_FLAG0            (1UL << OS_IE_USER_FLAG0_SHIFT)
#define OS_IE_USER_FLAG1            (1UL << OS_IE_USER_FLAG1_SHIFT)

#define OSi_IRQCALLBACK_NO_DMA0     0
#define OSi_IRQCALLBACK_NO_DMA1     1
#define OSi_IRQCALLBACK_NO_DMA2     2
#define OSi_IRQCALLBACK_NO_DMA3     3
#define OSi_IRQCALLBACK_NO_TIMER0   4
#define OSi_IRQCALLBACK_NO_TIMER1   5
#define OSi_IRQCALLBACK_NO_TIMER2   6
#define OSi_IRQCALLBACK_NO_TIMER3   7

    #define OSi_IRQCALLBACK_NUM         (7 + 1)

#define OS_IRQ_MAIN_BUFFER_SIZE         (0x200)

void OS_IrqDummy(void);
void OS_IrqHandler(void);
void OS_IrqHandler_ThreadSwitch(void);

static inline BOOL OS_EnableIrq (void)
{
    u16 prep = reg_OS_IME;
    reg_OS_IME = OS_IME_ENABLE;
    return (BOOL)prep;
}

static inline BOOL OS_DisableIrq (void)
{
    u16 prep = reg_OS_IME;
    reg_OS_IME = OS_IME_DISABLE;
    return (BOOL)prep;
}

static inline BOOL OS_RestoreIrq (BOOL enable)
{
    u16 prep = reg_OS_IME;
    reg_OS_IME = (u16)enable;
    return (BOOL)prep;
}

static inline OSIrqMask OS_GetIrqMask (void)
{
    return reg_OS_IE;
}

static inline OSIrqMask OS_GetRequestIrqMask (void)
{
    return reg_OS_IF;
}

static inline void OS_ClearIrqCheckFlag (OSIrqMask intr)
{
    *(vu32 *)((u32)data_02fe0000 + 0x3ff8) &= (u32) ~intr;
}

static inline OSIrqMask OS_GetIrqCheckFlag (void)
{
    return *(OSIrqMask *)((u32)data_02fe0000 + 0x3ff8);
}

void OS_WaitIrq(BOOL clear, OSIrqMask irqFlags);
void OS_WaitAnyIrq(void);

static inline vu32 OS_GetVBlankCount (void)
{
    return *(vu32 *)((u32)data_02fe0000 + 0x3ffc);
}

static inline void OSi_SetVBlankCount (u32 count)
{
    *(u32 *)((u32)data_02fe0000 + 0x3ffc) = count;
}

void OSi_CheckIrqStack(char * file, int line);

#if !defined(SDK_FINALROM) && !defined(SDK_NO_MESSAGE)
    #define  OS_CheckIrqStack()  OSi_CheckIrqStack(__FILE__, __LINE__);
#else
    #define  OS_CheckIrqStack()  ((void)0)
#endif

#ifdef __cplusplus
}
#endif

#endif
