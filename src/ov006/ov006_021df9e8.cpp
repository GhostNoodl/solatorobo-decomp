#include "ov006/ov006.h"

typedef struct ov006_Rect16 {
    u16 x;
    u16 y;
    u16 w;
    u16 h;
} ov006_Rect16;

typedef struct ov006_Unk021df9e8 {
    u8 unk0[0x28];
    ov006_Rect16 rects[10];
    u8 unk78[10];
} ov006_Unk021df9e8;

extern "C" {

void func_ov006_021df9e8(ov006_Unk021df9e8 *self, const ov006_Rect16 *rect, u32 idx, u8 value) {
    if (idx >= 10) {
        return;
    }
    self->rects[idx].x = rect->x;
    self->rects[idx].y = rect->y;
    self->rects[idx].w = rect->w;
    self->rects[idx].h = rect->h;
    self->unk78[idx] = value;
}

}
