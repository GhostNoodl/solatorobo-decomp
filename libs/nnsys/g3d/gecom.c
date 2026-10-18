#include <nnsys/g3d.h>

static inline void sendNB(const void *src, void *dst, u32 szByte) {
    MI_CpuSend32(src, dst, szByte);
}

void NNS_G3dGeSetBuffer(NNSG3dGeBuffer *p) {
    if (NNSi_G3dGeState.buffer == NULL) {
        p->idx = 0;
        NNSi_G3dGeState.buffer = p;
    }
}

void NNS_G3dGeFlushBuffer(void) {
    if (NNSi_G3dGeState.flagGXDmaAsync) {
        NNS_G3dGeWaitSendDL();
    }

    if (NNSi_G3dGeState.buffer && NNSi_G3dGeState.buffer->idx > 0) {
        sendNB(&NNSi_G3dGeState.buffer->data[0], (void *)&reg_G3X_GXFIFO, NNSi_G3dGeState.buffer->idx << 2);
        NNSi_G3dGeState.buffer->idx = 0;
    }
}

void NNS_G3dGeWaitSendDL(void) {
    while (NNSi_G3dGeState.flagGXDmaAsync)
        ;
}

// Referenced from NNS_G3dGeSendDL, which is still in the gap, so it cannot be static here.
void simpleUnlock_(void *arg) {
    *((volatile int *)arg) = 0;
}

void NNS_G3dGeUseFastDma(BOOL cond) {
    NNSi_G3dGeState.flagUseFastDma = cond;
}
