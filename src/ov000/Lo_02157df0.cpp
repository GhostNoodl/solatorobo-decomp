#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

extern "C" {

// UiLabel_Release inlined, then the label itself.
static inline void Free02157df0(UiLabel *p) {
    LO_FREE_V(p, 0x24); // text
    LO_FREE_M(p, 0x28); // model
    UiLabel_Reset(p);
    Heap_Free(p);
}

void UiList021cb4a8_Release(UiList021cb4a8 *self) {
    {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (self->unk_d4 != NULL) {
            UiLabel *p = self->unk_d4;
            if (p != NULL) {
                Free02157df0(p);
            }
            self->unk_d4 = NULL;
        }
        LO_HEAP_POP(saved);
    }
    {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (self->unk_d8 != NULL) {
            UiLabel *p = self->unk_d8;
            if (p != NULL) {
                Free02157df0(p);
            }
            self->unk_d8 = NULL;
        }
        LO_HEAP_POP(saved);
    }
}
}
