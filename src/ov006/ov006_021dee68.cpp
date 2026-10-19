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

typedef struct ov006_OamEnt {
    u32 y : 8;
    u32 unk8 : 8;
    u32 x : 9;
    u32 unk25 : 7;
    u32 name : 10;
    u32 unk2A : 22;
} ov006_OamEnt;

typedef struct ov006_Counter {
    u8 unk0[0x70];
    u32 value;
} ov006_Counter;

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

ov006_OamEnt *func_ov006_021deea4(ov006_Counter *self, const u16 *mode, ov006_OamEnt *oam, u16 *count) {
    u16 n;
    ov006_OamEnt *last;
    u32 base;
    u32 t;
    s16 x;
    u8 digits;
    u32 v;
    n = *count;
    last = &oam[n - 1];
    if (*mode == 0x1e) {
        base = last->name;
        v = self->value;
        t = v;
        digits = 0;
        do {
            digits++;
            t /= 10;
        } while (t != 0);
        x = -6;
        n = 0;
        for (; digits != 0; digits--) {
            oam[n].x = x;
            oam[n].y = 0;
            oam[n].name = base - v % 10;
            n++;
            x -= 6;
            v /= 10;
        }
    }
    *count = n;
    return oam;
}

}
