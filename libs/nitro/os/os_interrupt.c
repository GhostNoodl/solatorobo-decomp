#include "nitro/os.h"

#define OS_IRQ_TABLE_MAX 32

void OS_InitIrqTable(void) {
    OS_InitThreadQueue(&OSi_IrqThreadQueue);
}

void OS_SetIrqFunction(OSIrqMask intrBit, OSIrqFunction function) {
    s32 i;
    OSIrqCallbackInfo *info;

    for (i = 0; i < OS_IRQ_TABLE_MAX; i++) {
        if (intrBit & 1) {
            info = NULL;

            if (8 <= i && i <= 11) {
                info = &OSi_IrqCallbackInfo[i - 8];
            } else if (28 <= i && i <= 31) {
                info = &OSi_IrqCallbackInfo[i - 28 + 4];
            } else if (3 <= i && i <= 6) {
                info = &OSi_IrqCallbackInfo[i - 3 + 8];
            } else {
                OS_IRQTable[i] = function;
            }

            if (info != NULL) {
                info->func = (void (*)(void *))function;
                info->arg = NULL;
                info->enable = TRUE;
            }
        }
        intrBit >>= 1;
    }
}

OSIrqFunction OS_GetIrqFunction(OSIrqMask intrBit) {
    s32 i = 0;
    OSIrqFunction *funcPtr = &OS_IRQTable[0];

    do {
        if (intrBit & 1) {
            if (8 <= i && i <= 11) {
                i = i - 8;
                return (OSIrqFunction)OSi_IrqCallbackInfo[i].func;
            } else if (3 <= i && i <= 6) {
                i = i - 3 + 8;
                return (OSIrqFunction)OSi_IrqCallbackInfo[i].func;
            }
            return *funcPtr;
        }
        intrBit >>= 1;
        funcPtr++;
        i++;
    } while (i < OS_IRQ_TABLE_MAX);

    return NULL;
}

void OSi_EnterDmaCallback(u32 dmaNo, void (*callback)(void *), void *arg) {
    OSIrqMask mask = 1UL << (dmaNo + 8);

    OSi_IrqCallbackInfo[dmaNo].func = callback;
    OSi_IrqCallbackInfo[dmaNo].arg = arg;
    OSi_IrqCallbackInfo[dmaNo].enable = OS_EnableIrqMask(mask) & mask;
}

