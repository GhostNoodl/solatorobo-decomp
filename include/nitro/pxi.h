#ifndef NITRO_PXI_H
#define NITRO_PXI_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PXI_FIFO_TAG_SOUND 7
#define PXI_PROC_ARM7 1

typedef void (*PXIFifoCallback)(u32 tag, u32 data, BOOL err);

void PXI_SetFifoRecvCallback(s32 tag, PXIFifoCallback callback);
BOOL PXI_IsCallbackReady(s32 tag, s32 proc);
s32 PXI_SendWordByFifo(s32 tag, u32 data, BOOL err);

#ifdef __cplusplus
}
#endif

#endif
