#include "nitro/os.h"

#define OSi_IRQCALLBACK_NUM 12

// OSi_IrqCallbackInfo is accessed through labels on its fields, so it stays in the gap's .bss.
extern OSIrqCallbackInfo OSi_IrqCallbackInfo[];

static u16 OSi_IrqCallbackInfoIndex[OSi_IRQCALLBACK_NUM] = {
    8, 9, 10, 11, 28, 29, 30, 31, 3, 4, 5, 6,
};

void OS_IrqDummy(void) {
}

void OSi_IrqCallback(s32 index) {
    OSIrqMask mask = 1UL << OSi_IrqCallbackInfoIndex[index];
    void (*callback)(void *) = OSi_IrqCallbackInfo[index].func;

    OSi_IrqCallbackInfo[index].func = NULL;

    if (callback != NULL) {
        callback(OSi_IrqCallbackInfo[index].arg);
    }

    OS_SetIrqCheckFlag(mask);

    if (!OSi_IrqCallbackInfo[index].enable) {
        (void)OS_DisableIrqMask(mask);
    }
}

void OSi_IrqDma0(void) {
    OSi_IrqCallback(0);
}

void OSi_IrqDma1(void) {
    OSi_IrqCallback(1);
}

void OSi_IrqDma2(void) {
    OSi_IrqCallback(2);
}

void OSi_IrqDma3(void) {
    OSi_IrqCallback(3);
}

void OSi_IrqNDma0(void) {
    OSi_IrqCallback(8);
}

void OSi_IrqNDma1(void) {
    OSi_IrqCallback(9);
}

void OSi_IrqNDma2(void) {
    OSi_IrqCallback(10);
}

void OSi_IrqNDma3(void) {
    OSi_IrqCallback(11);
}

void OSi_IrqTimer0(void) {
    OSi_IrqCallback(4);
}

void OSi_IrqTimer1(void) {
    OSi_IrqCallback(5);
}

void OSi_IrqTimer2(void) {
    OSi_IrqCallback(6);
}

void OSi_IrqTimer3(void) {
    OSi_IrqCallback(7);
}
