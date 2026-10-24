#include "card_private.h"

#pragma force_active on

#define PXI_FIFO_TAG_CARD 14

#define CARD_PXI_COMMAND_MASK            0x3f
#define CARD_PXI_COMMAND_PULLED_OUT      0x11
#define CARD_PXI_COMMAND_RESET_SLOT      0x02

#define CARD_EVENT_PULLEDOUT 1
#define CARD_EVENT_SLOTRESET 2

typedef BOOL (*CARDPulledOutCallback)(void);

typedef struct {
    u32 counter;                    // 0x00
    BOOL isCardPulledOut;           // 0x04
    CARDPulledOutCallback callback; // 0x08
} CARDiPullOutStat;

extern CARDiPullOutStat data_0208e800;
#define pullout_stat data_0208e800

void CARDi_NotifyEvent(u32 event, void *arg);
void func_0200d9d0(void);

BOOL CARD_WaitRomAsync(void) {
    return CARDi_WaitAsync();
}

BOOL CARD_TryWaitRomAsync(void) {
    return CARDi_TryWaitAsync();
}

void func_0200d930(u32 tag, u32 data, BOOL err);

void CARD_InitPulledOutCallback(void) {
    PXI_Init();
    pullout_stat.counter = 0;
    pullout_stat.isCardPulledOut = FALSE;
    PXI_SetFifoRecvCallback(PXI_FIFO_TAG_CARD, func_0200d930);
    pullout_stat.callback = NULL;
}

void func_0200d930(u32 tag, u32 data, BOOL err) {
    u32 command = data & CARD_PXI_COMMAND_MASK;

    if (command == CARD_PXI_COMMAND_PULLED_OUT) {
        if (!pullout_stat.isCardPulledOut) {
            BOOL isTerminateImm = TRUE;

            pullout_stat.isCardPulledOut = TRUE;
            CARDi_NotifyEvent(CARD_EVENT_PULLEDOUT, NULL);
            if (pullout_stat.callback) {
                isTerminateImm = pullout_stat.callback();
            }
            if (isTerminateImm) {
                func_0200d9d0();
            }
        }
    } else if (command == CARD_PXI_COMMAND_RESET_SLOT) {
        pullout_stat.counter++;
        pullout_stat.isCardPulledOut = FALSE;
        CARDi_NotifyEvent(CARD_EVENT_SLOTRESET, NULL);
    } else {
        OS_Terminate();
    }
}

BOOL CARD_IsPulledOut(void) {
    return pullout_stat.isCardPulledOut;
}

void PM_ForceToPowerOff(void);
void MI_StopAllDma(void);
void func_0200da78(u32 data, u32 wait);
void func_0228f864(void);  /* TWL only */
void func_0228e020(void);  /* TWL only */

static inline BOOL PAD_DetectFold(void) {
    return (BOOL)((*(vu16 *)0x02ffffa8 & 0x8000) >> 15);
}

void func_0200d9d0(void) {
    if (PAD_DetectFold()) {
        PM_ForceToPowerOff();
    }
    if (OS_IsRunOnTwl()) {
        func_0228f864();
    }
    func_0200da78(1, 1);
    MI_StopAllDma();
    if (OS_IsRunOnTwl()) {
        func_0228e020();
    }
    OS_Terminate();
}
