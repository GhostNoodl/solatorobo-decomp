#include "nitro/pxi.h"

#define PXI_FIFO_TAG_CTRDG 13

void CTRDGi_InitCommon(void);
void CTRDGi_SendtoPxi(u32 data);

static void func_02021bd0(u32 tag, u32 data, BOOL err);

void func_02021b9c(void) {
    CTRDGi_InitCommon();
    PXI_SetFifoRecvCallback(PXI_FIFO_TAG_CTRDG, NULL);
    PXI_SetFifoRecvCallback(PXI_FIFO_TAG_CTRDG, func_02021bd0);
    CTRDGi_SendtoPxi(1);
}

static void func_02021bd0(u32 tag, u32 data, BOOL err) {
#pragma unused(tag, data, err)
}
