#include "ov000/ObjLayouts.h"

extern "C" {

s32 Lo021cadcc_GetLineSpacing(void) {
    return 0x3;
}

u32 Lo021cadcc_GetPadLeft(Lo021cadcc *self) {
    return self->unk_88;
}

s32 Lo021cadcc_GetPadTop(void) {
    return 0x6;
}

}
