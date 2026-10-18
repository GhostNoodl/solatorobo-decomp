#include "ov014/ov014.h"

extern "C" {

extern void *data_02097e4c;
extern BOOL func_ov003_021daa0c(void *p, u8 id);
extern void func_ov003_021da9ac(void *p, u8 id, void *obj);
extern void func_0204a028(void *a, s32 b, Ov014Vec *c, s32 d);
extern Ov014V *func_02065f88(s32 id, Ov014Vec *pos);
extern BOOL func_ov003_021d9edc(s32 id);
extern void func_ov014_021fe3ec(Ov014Actor *self);

void func_ov014_021ff318(Ov014Actor *self) {
    if (FLD(s16, self, 0xf0) != 1) {
        return;
    }
    switch (self->unk_40->state) {
    case 0: {
        Ov014V *e = func_02065f88(0x2bd, &self->pos);
        e->v24(0, 0, 0x7000);
        e->v0c(0x8000);
        e->v34(0x4000, 0, 0);
        func_ov003_021da9ac(FLD(void *, self, 0xfc), 0, e);
        self->unk_40->state++;
    }
    case 1: {
        u8 i;
        if (func_ov003_021daa0c(FLD(void *, self, 0xfc), 0)) {
            return;
        }
        for (i = 0; i < 2; i++) {
            Ov014V *e = func_02065f88(0x57e, &self->pos);
            e->v24(0, 0, 0x7000);
            e->v0c(0x3000);
            func_0204a028(data_02097e4c, 0x79, &self->pos, -5);
        }
        self->unk_40->state++;
        break;
    }
    case 2: {
        Ov014Sub40 *w = self->unk_40;
        w->timer++;
        if (w->timer < 10) {
            return;
        }
        self->unk_40->timer = 0;
        if (FLD(s16 *, self, 0x15c)[0] == 12 && !func_ov003_021d9edc(0x482b)) {
            self->unk_40->state = 10;
        } else {
            self->unk_40->state = 0x1e;
        }
        func_ov014_021fe3ec(self);
        break;
    }
    case 10: {
        Ov014Sub40 *w = self->unk_40;
        w->timer++;
        if (w->timer < FLD(u16 *, self, 0x15c)[1]) {
            return;
        }
        self->unk_40->timer = 0;
        self->unk_40->state = 1;
        break;
    }
    case 0x1e: {
        u16 lim = 0;
        Ov014Sub40 *w = self->unk_40;
        if (FLD(u16 *, self, 0x15c) != NULL) {
            lim = FLD(u16 *, self, 0x15c)[3];
        }
        w->timer++;
        if (w->timer < lim) {
            return;
        }
        if (FLD(u32, self, 0xf4) & 8) {
            FLD(u32, self, 0xf4) ^= 8;
        }
        FLD(u8, self, 0x138) ^= 0x80;
        self->unk_40->timer = 0;
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    }
}
}
