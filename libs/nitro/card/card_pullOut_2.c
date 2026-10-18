#include "card_private.h"

#pragma force_active on

#define PXI_FIFO_TAG_CARD 14

void func_0200d930(u32 tag, u32 data, BOOL err);
void WaitByLoop(s32 count);

void func_0200da28(u32 id) {
    vu32 iplCardID = *(u32 *)0x02fffc00;

    if (id != iplCardID) {
        OSIntrMode bak_psr = OS_DisableInterrupts();
        func_0200d930(PXI_FIFO_TAG_CARD, 0x11, FALSE);
        (void)OS_RestoreInterrupts(bak_psr);
    }
}

void func_0200da78(u32 data, u32 wait) {
    while (PXI_SendWordByFifo(PXI_FIFO_TAG_CARD, data, FALSE) != 0) {
        WaitByLoop((s32)wait);
    }
}
