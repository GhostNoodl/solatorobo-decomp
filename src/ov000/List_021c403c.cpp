#include "types.h"

typedef struct Item021c403c {
    u8 pad_00[0x18];
    s32 unk_18;
    u8 pad_1c[0xc];
    struct Item021c403c *next;
    struct Item021c403c *prev;
} Item021c403c;

typedef struct {
    u8 pad_00[0x20];
    s32 unk_20;
    u8 pad_24[0x70];
    Item021c403c *unk_94;
    s32 unk_98;
    s32 unk_9c;
    Item021c403c *unk_a0;
    u8 pad_a4[4];
    s32 unk_a8;
    u16 unk_ac;
    u8 pad_ae[0x16];
    s32 unk_c4;
    s32 unk_c8;
} Obj021c403c;

extern "C" {

s32 FX_Div(s32 a, s32 b);

void func_ov000_021c403c(Obj021c403c *self, s32 sel) {
    s32 vis;
    s32 n;
    s32 half;
    s32 i;
    s32 j;
    Item021c403c *item;
    n = self->unk_98;
    vis = self->unk_20;
    if (sel > n - 1) {
        sel = n - 1;
    }
    half = (vis - 1) / 2;
    if (n < vis) {
        self->unk_9c = 0;
    } else {
        s32 top = sel - half;
        if (top < 0) {
            self->unk_9c = 0;
        } else if (top > n - vis) {
            self->unk_9c = n - vis;
        } else {
            self->unk_9c = top;
        }
    }
    self->unk_a8 = sel;
    item = self->unk_94;
    if (item == NULL) {
        self->unk_a0 = NULL;
    } else {
        for (i = 0; item != NULL; item = item->next, i++) {
            if (i == sel) {
                break;
            }
        }
        self->unk_a0 = item;
        self->unk_ac = 7;
        for (j = sel - 1; j >= self->unk_9c; j--) {
            self->unk_ac += (u16)item->unk_18;
            item = item->prev;
        }
    }
    if (self->unk_98 < self->unk_20) {
        self->unk_c8 = 0x1000;
    } else {
        self->unk_c8 = FX_Div(self->unk_20 << 12, self->unk_98 << 12);
    }
    self->unk_c4 = FX_Div(self->unk_9c << 12, self->unk_98 << 12);
}

}
