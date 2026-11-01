#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u16 state;
    u16 timer;
} State021a5b50;

extern "C" {

extern u8 data_ov000_021cc678[];
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
BOOL func_ov000_02198360(State021a5b50 *st, s32 state, s32 x);
void func_ov000_021b1fac(void *self, BOOL a, s32 b);
u16 FX_Atan2(s32 y, s32 x);

void func_ov000_021a5b50(Robo021ca458 *self) {
    switch (((State021a5b50 *)self->unk_40)->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov000_021cc678, 0x200, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_a4 = 0x800;
        self->unk_93_5 = 1;
        if (self->unk_a8 == 0) {
            self->unk_a8 = 0x52;
        }
        ((State021a5b50 *)self->unk_40)->state++;
    case 1:
        if (self->unk_b36 == 0) {
            self->unk_93_5 = 0;
            func_ov000_02198360((State021a5b50 *)self->unk_40, 1, 0);
            return;
        }
        if (LFLD(u32, self->unk_48, 0x50) & 0x20000000) {
            LFLD(u16, self->unk_48, 0x9a) |= 0x20;
            self->unk_9c = 0;
            self->unk_a4 = 0;
        } else {
            State021a5b50 *st = (State021a5b50 *)self->unk_40;
            st->timer++;
            if (st->timer > 0x3c) {
                self->unk_93_5 = 0;
                self->unk_b36 = 0;
                func_ov000_02198360((State021a5b50 *)self->unk_40, 4, 0);
            }
        }
        func_ov000_021b1fac(self, FALSE, 1);
        if (!LBIT(self, 0xb24).b1) {
            return;
        }
        if (!(LFLD(u32, self->unk_48, 0x54) & 0x400)) {
            return;
        }
        self->unk_98 = FX_Atan2(self->unk_af0 - self->pos.x,
                                         self->unk_af8 - self->pos.z);
        self->unk_9c = 0x66;
        self->unk_a4 = 0;
        if (!LBIT(self, 0xb24).b17 || (LFLD(u32, self->unk_48, 0x50) & 0x40000000)) {
            self->unk_a0 = 0x200;
        }
        self->unk_a8 = 0x52;
        LBIT(self, 0xb24).b17 = 1;
        break;
    }
}

}
