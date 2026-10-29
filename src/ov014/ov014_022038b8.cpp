#include "ov014/ov014.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov014_02216500[];
extern const Ov014Vec data_ov014_022165dc;
extern BOOL func_ov003_021d8820(void *p);
extern void func_ov003_021d87d0(void *p, s32 a);
extern void func_ov003_021d8800(void *p, s32 a);
extern void func_ov000_0218dbe0(Ov014Actor *self, s32 a);
extern BOOL func_ov003_021daa0c(void *p, u8 id);
extern void func_ov003_021da9ac(void *p, u8 id, void *obj);
extern void func_ov003_021daa6c(void *p, s32 a);
extern s32 FX_Div(s32 a, s32 b);
extern void *func_0204a028(void *a, s32 b, Ov014Vec *c, s32 d);
extern void func_ov003_021d85c8(void *p, s32 a, s32 b, s32 c, s32 d);
extern Ov014V *func_02065f88(s32 id, Ov014Vec *pos);

void func_ov014_022038b8(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0x14:
        func_ov000_02190cb0(self->unk_38, data_ov014_02216500[3], 0x111, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_48->unk_60 = -0x800;
        self->unk_9c = 0;
        self->unk_a0 = -0x148;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
        break;
    case 0x15: {
        u16 n = 0;
        Ov014Sub40 *w;
        func_ov000_0218dbe0(self, 0);
        w = self->unk_40;
        w->timer++;
        if (w->timer != 15) {
            return;
        }
        self->unk_40->timer = 0;
        if (FLD(void *, self, 0x130) != NULL) {
            n = FLD(u16, FLD(void *, self, 0x130), 4);
        }
        FLD(u8, self, 0xf9)++;
        if (FLD(u8, self, 0xf9) >= n) {
            self->unk_40->state = 0x1e;
            return;
        }
        func_ov003_021d85c8((u8 *)self + 0x100, 0, 0, 1, 0);
        self->unk_40->state++;
        break;
    }
    case 0x16: {
        u16 t;
        Ov014Sub40 *w = self->unk_40;
        w->timer++;
        t = w->timer;
        if (t <= 70) {
            if (!func_ov003_021d8820((u8 *)self + 0x100)) {
                func_ov003_021d8800((u8 *)self + 0x100, 1);
            }
        } else {
            if (func_ov003_021d8820((u8 *)self + 0x100) == 1) {
                func_ov003_021d87d0((u8 *)self + 0x100, 0);
            }
        }
        if (t == 50 && !func_ov003_021daa0c(FLD(void *, self, 0xfc), 0xfc)) {
            Ov014Vec v = data_ov014_022165dc;
            Ov014V *e;
            v.x = self->pos.x;
            v.z = self->pos.z;
            e = func_02065f88(0x2bd, &v);
            e->v0c(0x4000);
            FLD(s32, e, 0x3c) = 0x2000;
            FLD(s32, e, 0x7c) = FX_Div(0x10000, 0x1f000);
            FLD(s32, e, 0xc8) = -1;
            func_ov003_021da9ac(FLD(void *, self, 0xfc), 0xfc, e);
        }
        if (t == FLD(u16, FLD(void *, self, 0x130), 2)) {
            func_0204a028(data_02097e4c, 0x71, &self->pos, -2);
            func_ov003_021d87d0((u8 *)self + 0x100, 1);
            func_ov003_021daa6c(FLD(void *, self, 0xfc), 0xfc);
            self->unk_40->timer = 0;
            self->unk_40->state = 0;
        }
        break;
    }
    }
}
}
