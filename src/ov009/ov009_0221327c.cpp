#include "ov009/ov009.h"

extern "C" {
extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
extern void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov003_021d6a3c(Ov009Actor *self, s32 a, s32 b, s32 c);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);

void func_ov009_0221327c(Ov009Actor *self) {
    Ov009Vec p;
    Ov009V *e;
    Ov009Sub40 *st;
    switch (self->unk_40->state) {
    case 0: {
        Ov009Sub44 *s44;
        self->unk_ea_6 = 1;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x483f, 0x15);
        func_ov000_0218996c(10, 0x28);
        func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
        e = func_02065f88(5, &self->pos);
        e->v14(0x7800, 0x7800, 0x7800);
        self->unk_40->state++;
        break;
    }
    case 1:
        func_ov003_021d6a3c(self, 0, 1, 1);
        self->unk_40->state++;
        break;
    }
    self->v50();
    st = self->unk_40;
    st->timer++;
    if (st->timer != 0x5a) {
        return;
    }
    p.x = self->pos.x;
    p.y = self->pos.y;
    p.z = self->pos.z;
    {
        s32 w = self->unk_64;
        p.x += func_02040498(w >> 1) + (w >> 1);
    }
    p.y += func_02040528(FLD(s32, self, 0x68));
    p.z += func_02040528(0x4000) + 0x3000;
    e = func_02065f88(0x325, &p);
    e->v34(0, (u16)(self->rot[1] + 0x8000), 0);
    e->v14(0x1ccd, 0x1ccd, 0x1ccd);
    self->unk_40->timer = 0;
}

}
