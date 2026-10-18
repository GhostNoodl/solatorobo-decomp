#include "ov006/ov006.h"

typedef struct ov006_Rect16 {
    u16 x;
    u16 y;
    u16 w;
    u16 h;
} ov006_Rect16;

typedef struct ov006_Unk021dee68_Sub {
    u8 unk0[6];
    ov006_Rect16 rect;
    u8 unkE;
} ov006_Unk021dee68_Sub;

typedef struct ov006_Unk021dee68 {
    void *vtbl;
    u8 unk4;
    u8 unk5;
    u8 unk6[0x12];
    ov006_Unk021dee68_Sub *unk18;
} ov006_Unk021dee68;

extern "C" {

void func_ov006_021dee68(ov006_Unk021dee68 *self, const ov006_Rect16 *rect, u8 a, u8 b) {
    ov006_Unk021dee68_Sub *sub = self->unk18;
    if (sub == NULL) {
        return;
    }
    sub->rect.x = rect->x;
    sub->rect.y = rect->y;
    sub->rect.w = rect->w;
    sub->rect.h = rect->h;
    sub->unkE = a;
    self->unk5 = b;
}

}
