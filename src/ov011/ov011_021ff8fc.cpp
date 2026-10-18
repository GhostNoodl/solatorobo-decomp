#include "ov011/ov011.h"

extern "C" {

extern void *data_02097e4c;
extern u8 data_ov011_022078e1[];
void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
Ov011V *func_02065f88(s32 id, Ov011Vec *v);
void func_020627a0(u16 a, u16 b);
void func_020627dc(s32 a);
void func_ov000_02198360(void *a, s32 b, s32 c);
s32 func_02040528(s32 max);

void func_ov011_021ff8fc(Ov011Actor *self) {
    Ov011Sub40 *s = self->unk_40;
    switch (s->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov011_022078e1, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_38->unk_c2_0 = 0;
        self->unk_40->state++;
        break;
    case 1: {
        Ov011V *p;
        if (++s->timer > 100) {
            func_02049a48(data_02097e4c, 50, 100, -1, -1);
            p = func_02065f88(50 + 0x358, &self->pos);
            p->v14(0x1666, 0x1666, 0x1666);
            p->v24(0, 0x1000, 0);
            self->unk_38->unk_c2_0 = 1;
            FLD(u8, self->unk_38, 0xbe) = 0;
            self->unk_40->timer = 0;
            self->unk_40->state++;
        } else {
            u16 t = self->unk_40->timer;
            if (t <= 75 && t % 15 == 0) {
                s32 x;
                s32 z;
                s32 a;
                s32 b;
                p = func_02065f88(0x398 - 15, &self->pos);
                p->v14(0x1666, 0x1666, 0x1666);
                x = self->unk_64;
                z = FLD(s32, self, 0x6c);
                a = func_02040528(x);
                b = func_02040528(z);
                p->v24(a, z + 0x1000 + b, x);
            }
        }
        break;
    }
    case 2:
        if (++s->timer > 60) {
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            FLD(u8, data_ov000_021ccd54, 0xac) = 1;
            FLD(u8, self->unk_38, 0xbe) = 0x1f;
            func_ov000_02198360(self->unk_40, 1, 0);
        } else if (self->unk_40->timer > 30) {
            u8 v = FLD(u8, self->unk_38, 0xbe) + 1;
            if (v > 0x1f) {
                v = 0x1f;
            }
            FLD(u8, self->unk_38, 0xbe) = v;
        }
        break;
    }
}

}
