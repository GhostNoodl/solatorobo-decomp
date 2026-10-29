#include "ov013/ov013.h"

extern "C" {

extern void *data_02097e4c;
extern char data_ov013_0220be7c[];
extern void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_0218996c(s32 a, s32 b);
void func_020627a0(u16 a, u16 b);
void func_020627dc(s32 a);


void func_ov013_022069ec(Ov013Actor *self) {
    Ov013Sub40 *w = self->unk_40;
    switch (w->state) {
    case 0: {
        Ov013Sub44 *n;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be7c, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a4 = 0;
        FLD(Ov013Vec, self, 0xf0) = self->pos;
        self->pos.y -= 0x3c000;
        self->unk_a8 = 0;
        self->rot[1] = 0;
        self->unk_a0 = 0x148;
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->unk_40->state = 2;
        self->unk_40->timer = 0;
    }
    case 2:
        w = self->unk_40;
        w->timer++;
        if (w->timer <= 10) {
            return;
        }
        func_ov000_0218996c(0xf, 0x50);
        self->unk_40->state = 3;
        self->unk_40->timer = 0;
        break;
    case 3:
        w->timer++;
        if (w->timer <= 80) {
            return;
        }
        func_02049a48(data_02097e4c, 0x6a, -1, -1, -1);
        func_02049a48(data_02097e4c, 0x53, -1, -1, -1);
        func_ov000_0218996c(0x14, 0xf);
        self->unk_40->state = 4;
        self->unk_40->timer = 0;
        break;
    case 4:
        if (VEC_Distance(&FLD(Ov013Vec, self, 0xf0), &self->pos) > 0x333) {
            Ov013Vec d;
            s32 sc = self->unk_a0;
            d.x = FLD(s32, self, 0xf0) - self->pos.x;
            d.y = FLD(s32, self, 0xf4) - self->pos.y;
            d.z = FLD(s32, self, 0xf8) - self->pos.z;
            VEC_MultAdd(sc, &d, &self->pos, &self->pos);
            return;
        } else {
            Ov013Sub44 *n;
            self->pos = FLD(Ov013Vec, self, 0xf0);
            n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
            self->unk_40->state = 10;
            self->unk_40->timer = 0;
        }
        break;
    case 10:
        w->timer++;
        if (w->timer <= 30) {
            return;
        }
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        FLD(u8, data_ov000_021ccd54, 0xac) = 1;
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
}
}
