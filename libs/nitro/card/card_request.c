#include "card_private.h"

#pragma force_active on

#define CARD_REQ_INIT        0
#define CARD_RESULT_TIMEOUT  4

static inline void CARDi_SendPxi(u32 data) {
    while (PXI_SendWordByFifo(PXI_FIFO_TAG_FS, data, TRUE) < 0) {
    }
}

BOOL CARDi_Request(CARDiCommon *p, int req_type, int retry_count) {
    if (!(p->flag & CARD_STAT_INIT_CMD)) {
        p->flag |= CARD_STAT_INIT_CMD;
        while (!PXI_IsCallbackReady(PXI_FIFO_TAG_FS, 1)) {
            OS_SpinWaitSysCycles(50);
        }
        (void)CARDi_Request(p, CARD_REQ_INIT, 1);
    }

    DC_FlushRange(p->cmd, sizeof(*p->cmd));
    DC_WaitWriteBufferEmpty();

    p->cur_th = OS_GetCurrentThread();

    do {
        p->flag |= CARD_STAT_REQ;
        CARDi_SendPxi((u32)req_type);

        switch (req_type) {
        case CARD_REQ_INIT:
            CARDi_SendPxi((u32)p->cmd);
            break;
        }

        {
            OSIntrMode bak_psr = OS_DisableInterrupts();
            while (p->flag & CARD_STAT_REQ) {
                OS_SleepThread(NULL);
            }
            (void)OS_RestoreInterrupts(bak_psr);
        }

        DC_InvalidateRange(p->cmd, sizeof(*p->cmd));
    } while (p->cmd->result == CARD_RESULT_TIMEOUT && --retry_count > 0);

    return p->cmd->result == CARD_RESULT_SUCCESS;
}
