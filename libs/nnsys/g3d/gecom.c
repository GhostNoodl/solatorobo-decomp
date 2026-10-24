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

// Referenced from NNS_G3dGeSendDL; kept global as in symbols.txt.
void simpleUnlock_(void *arg) {
    *((volatile int *)arg) = 0;
}

void NNS_G3dGeUseFastDma(BOOL cond) {
    NNSi_G3dGeState.flagUseFastDma = cond;
}

typedef void (*MIDmaCallback)(void *arg);
void MI_SendGXCommandAsync(u32 dmaNo, const void *src, u32 commandLength, MIDmaCallback callback, void *arg);
void MI_SendGXCommandAsyncFast(u32 dmaNo, const void *src, u32 commandLength, MIDmaCallback callback, void *arg);
BOOL OS_IsRunOnTwl(void);
/* TWL only */
void func_0228e3f8(u32 ndmaNo, const void *src, u32 commandLength, MIDmaCallback callback, void *arg);
void func_0228e1fc(u32 ndmaNo, const void *src, u32 commandLength, MIDmaCallback callback, void *arg);

static inline u32 GXi_GetDma(u32 id) {
    return (id <= 3) ? id : (u32)-1;
}

static inline u32 GXi_GetNDma(u32 id) {
    return (id > 3 && id <= 7) ? id - 4 : (u32)-1;
}

static inline void GXi_SendGXCommandAsyncFast(const void *src, u32 sz, MIDmaCallback cb, void *arg) {
    if (OS_IsRunOnTwl()) {
        u32 id = GXi_DmaId;
        u32 dma = GXi_GetDma(id);
        if (dma == (u32)-1) {
            func_0228e3f8(GXi_GetNDma(id), src, sz, cb, arg);
        } else {
            MI_SendGXCommandAsyncFast(dma, src, sz, cb, arg);
        }
    } else {
        MI_SendGXCommandAsyncFast(GXi_GetDma(GXi_DmaId), src, sz, cb, arg);
    }
}

static inline void GXi_SendGXCommandAsync(const void *src, u32 sz, MIDmaCallback cb, void *arg) {
    if (OS_IsRunOnTwl()) {
        u32 id = GXi_DmaId;
        u32 dma = GXi_GetDma(id);
        if (dma == (u32)-1) {
            func_0228e1fc(GXi_GetNDma(id), src, sz, cb, arg);
        } else {
            MI_SendGXCommandAsync(dma, src, sz, cb, arg);
        }
    } else {
        MI_SendGXCommandAsync(GXi_GetDma(GXi_DmaId), src, sz, cb, arg);
    }
}

void NNS_G3dGeSendDL(const void *src, u32 szByte) {
    if (szByte < 0x100 || GXi_DmaId == (u32)-1) {
        NNS_G3dGeBufferOP_N(*(const u32 *)src, (const u32 *)src + 1, (szByte >> 2) - 1);
        return;
    }

    NNS_G3dGeFlushBuffer();
    NNSi_G3dGeState.flagGXDmaAsync = 1;
    if (NNSi_G3dGeState.flagUseFastDma) {
        GXi_SendGXCommandAsyncFast(src, szByte, &simpleUnlock_, (void *)&NNSi_G3dGeState.flagGXDmaAsync);
    } else {
        GXi_SendGXCommandAsync(src, szByte, &simpleUnlock_, (void *)&NNSi_G3dGeState.flagGXDmaAsync);
    }
}
