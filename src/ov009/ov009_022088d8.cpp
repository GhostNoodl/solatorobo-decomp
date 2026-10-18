#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern Ov009Path data_ov009_02215fd0[];
extern Ov009Actor *func_ov000_0219bf90(void);
extern BOOL func_01ffc584(const Ov009Vec *a, const Ov009Vec *b, s32 r, s32 h);
extern void func_ov000_0219aae8(Ov009Actor *self, Ov009Actor *src, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern void func_0204a028(void *mgr, s32 id, const Ov009Vec *pos, s32 a);

static inline BOOL Ov009Game_IsPaused(Ov009Game54 *g) {
    return g->unk_d4 != 0;
}

void func_ov009_022088d8(Ov009Actor *self) {
    Ov009Sub40 *st;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (Ov009Game_IsPaused(data_ov000_021ccd54)) {
        return;
    }
    st = self->unk_40;
    if (st->unk_13 == 1 && st->timer >= 0x2d) {
        Ov009Actor *a = func_ov000_0219bf90();
        Ov009Vec v = self->unk_84;
        v.y -= 0x3000;
        s32 r = data_ov009_02215fd0[self->unk_1a].start.x;
        if (func_01ffc584(&a->pos, &v, r + a->unk_64, 0x5000)) {
            self->unk_40->flags = 0;
            func_ov000_02198360(self->unk_40, 0xf, 0);
        }
    }
    if (self->unk_40->unk_13 == 0xf) {
        func_ov000_0219aae8(self, self, 0x78, FLD(u16, FLD(u8 *, self, 0x4c), 0xa) & 0xff, 2, 0, 0, 0x3000, 0x1b33, 0x64, 0x1000);
    }
    if (FLD(s16, self->unk_38, 0xc4) == 1) {
        func_0204a028(data_02097e4c, 9, &self->pos, -3);
    }
}

extern void *data_ov009_02215ee4[];

void func_ov009_02208a84(Ov009Actor *self) {
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02215ee4[0], 0x111, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 1: {
        Ov009Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer > 0x2d) {
            self->unk_40->timer = 0x2d;
        }
        break;
    }
    }
}

}
