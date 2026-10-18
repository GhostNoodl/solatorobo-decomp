#include <nnsys/g3d.h>

static inline void sendNB(const void *src, void *dst, u32 szByte) {
    MI_CpuSend32(src, dst, szByte);
}

void NNS_G3dGeBufferOP_N(u32 op, const u32 *args, u32 num) {
    if (NNSi_G3dGeState.buffer) {
        if (NNSi_G3dGeState.flagGXDmaAsync) {
            if (NNSi_G3dGeState.buffer->idx + 1 + num <= NNS_G3D_SIZE_COMBUFFER) {
                NNSi_G3dGeState.buffer->data[NNSi_G3dGeState.buffer->idx++] = op;
                if (num > 0) {
                    MI_CpuCopyFast(args, &NNSi_G3dGeState.buffer->data[NNSi_G3dGeState.buffer->idx], num << 2);
                    NNSi_G3dGeState.buffer->idx += num;
                }
                return;
            }
        }

        if (NNSi_G3dGeState.buffer->idx != 0) {
            NNS_G3dGeFlushBuffer();
        } else {
            if (NNSi_G3dGeState.flagGXDmaAsync) {
                NNS_G3dGeWaitSendDL();
            }
        }
    } else {
        if (NNSi_G3dGeState.flagGXDmaAsync) {
            NNS_G3dGeWaitSendDL();
        }
    }

    reg_G3X_GXFIFO = op;
    sendNB(args, (void *)&reg_G3X_GXFIFO, num << 2);
}
