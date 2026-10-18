#include "card_private.h"
#include "nitro/os_valarm.h"

#pragma force_active on

typedef struct {
    vu32 flag;
    OSThreadQueue queue;
} CARDiEvent;

void OS_InitEvent(CARDiEvent *event);
u32 OSi_WaitEvent(CARDiEvent *event, u32 pattern, u32 mode, u32 clearBit);
void OS_SignalEvent(CARDiEvent *event, u32 setPattern);
s32 OS_TryLockCard(u16 lockID);
s32 OS_UnlockCard(u16 lockID);
void func_0200d85c(void);
void CARD_InitPulledOutCallback(void);
BOOL CARD_TryWaitBackupAsync(void);
BOOL CARD_WaitBackupAsync(void);

extern u32 data_0208de94;
extern CARDiCommandArg data_0208dea0;
extern u32 data_0208e540;

typedef struct CARDHookContext {
    struct CARDHookContext *next;
    void *userdata;
    void (*callback)(void *userdata, u32 event, void *arg);
} CARDHookContext;

extern CARDHookContext *data_0208e420;

typedef struct {
    CARDiEvent event;           // 0x00
    OSVAlarm valarm;            // 0x0c
    BOOL (*func)(void *arg);    // 0x34
    void *arg;                  // 0x38
    u32 pad;                    // 0x3c
} CARDiLockTask;

typedef struct {
    u8 unk_00[0x1b4];
    u32 unk_0_4 : 5;
    u32 game_card_nitro_mode : 1;
    u32 unk_6_7 : 2;
    u32 game_card_on : 1;
    u32 unk_9_14 : 6;
    u32 access_flag_0 : 1;
    u32 access_flag_1 : 1;
    u32 unk_17_31 : 15;
} CARDRomHeaderTWLAccess;
void CARDi_OnFifoRecv(u32 tag, u32 data, BOOL err);

void CARDi_InitCommand(void) {
    CARDiCommon *p = &cardi_common;

    p->cmd = &data_0208dea0;
    MI_CpuClearFast(&data_0208dea0, sizeof(data_0208dea0));
    DC_FlushRange(&data_0208dea0, sizeof(data_0208dea0));
    PXI_SetFifoRecvCallback(PXI_FIFO_TAG_FS, CARDi_OnFifoRecv);
}

