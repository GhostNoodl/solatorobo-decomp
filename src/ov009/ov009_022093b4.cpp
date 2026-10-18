#include "ov009/ov009.h"

extern "C" {

struct Ov009Bits16 {
    u16 b0 : 1;
    u16 b1 : 15;
};

void func_ov009_022093b4(Ov009Actor *self) {
    if (self->unk_40->state != 0) {
        return;
    }
    self->unk_38->unk_c2_0 = 0;
    FLD(Ov009Bits16, self, 0x2ea).b0 = 0;
    self->unk_40->state++;
}

extern void *data_02097e4c;
extern u8 data_ov009_022172b5[];
extern void func_ov000_02190e98(void *p, s32 a, s32 b, s32 c);
extern void func_0203f364(Ov009Sub48 *p);
extern void func_0203f324(Ov009Sub48 *p);
extern BOOL func_ov000_02191120(void *m);
extern void func_ov000_02191780(Ov009Sub38 *m);
extern void func_ov000_021917f8(Ov009Sub38 *m);
extern void func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
void func_ov009_022093f8(Ov009Actor *self) {
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_022172b5, 0x1000, 1);
        self->unk_38->unk_c2_0 = 1;
        func_ov000_02190e98(&FLD(u8, self, 0x228), 1, 0x1000, 1);
        FLD(Ov009Bits16, self, 0x2ea).b0 = 1;
        self->unk_40->state++;
        self->unk_40->timer = 0x41;
        break;
    case 1: {
        Ov009Sub40 *st;
        if (FLD(s16, self->unk_38, 0xc4) == 1) {
            Ov009Sub44 *s44 = self->unk_44;
            Ov009Sub48 *s48;
            s44->unk_22_0 = 1;
            s44->unk_22_1 = 1;
            s48 = self->unk_48;
            s48->unk_9a_0 = 1;
            s48->unk_9a_3 = 1;
            func_0203f324(s48);
        }
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            if (FLD(u16, self, 0x310) % 2 == 0) {
                func_ov000_02191780(self->unk_38);
            } else {
                func_ov000_021917f8(self->unk_38);
            }
            if (FLD(u16, self, 0x310) == 1 || FLD(u16, self, 0x310) == 5) {
                func_02049f44(data_02097e4c, 0x41, &self->pos, 0);
            }
            FLD(u16, self, 0x310)++;
            self->unk_40->timer = 0xc;
        }
        if (FLD(u16, self, 0x310) > 7) {
            self->unk_40->state++;
            self->unk_40->timer = 0;
            FLD(u16, self, 0x310) = 0;
        }
        break;
    }
    case 2:
        if (FLD(s16, self->unk_38, 0xc4) == 2) {
            Ov009Sub44 *s44 = self->unk_44;
            Ov009Sub48 *s48;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
            s48 = self->unk_48;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            func_0203f364(s48);
        }
        if (func_ov000_02191120(self->unk_38)) {
            func_ov000_02198360(self->unk_40, 1, 0);
            if (FLD(u8, self, 0x312) != 0) {
                func_020627a0(self->kind, self->id);
                func_020627dc(4);
                FLD(u8, data_ov000_021ccd54, 0xac) = 1;
                FLD(u8, self, 0x312) = 0;
            }
        }
        break;
    }
}

}
