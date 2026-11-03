#include "ov000/VObj.h"

extern "C" void *gFinishingTask;

static inline BOOL IsCur_Inline(void *self) { return gFinishingTask == self; }

extern "C" {

extern u32 gLastTaskId;

void func_ov000_0214f188(void *a, s32 b);

void Task_ReleaseCurrent(VObj *self) {
    if (!self->vfunc_54()) {
        return;
    }
    if (gFinishingTask != NULL) {
        gLastTaskId = *(u32 *)((u8 *)gFinishingTask + 0x14);
    } else {
        gLastTaskId = 0;
    }
    gFinishingTask = NULL;
}

bool Task_IsCurrent(void *self) {
    return IsCur_Inline(self);
}

BOOL func_ov000_02150104(void *self, void *p) {
    void *q = *(void **)((u8 *)self + 8);
    if (p != NULL) {
        func_ov000_0214f188(q, *(u16 *)((u8 *)p + 0x30));
    } else {
        func_ov000_0214f188(q, -1);
    }
    return TRUE;
}

}
