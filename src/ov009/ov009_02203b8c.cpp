#include "ov009/ov009.h"

extern "C" {

extern void *data_0214a420;
extern void func_02065804(void *mgr, void *p);

void func_ov009_02203b8c(Ov009Actor *self) {
    func_ov003_021d1e8c(self);
    if (self->unk_40->unk_13 == 0xf) {
        return;
    }
    func_02065804(data_0214a420, FLD(void *, self, 0xf0));
    FLD(void *, self, 0xf0) = NULL;
}

extern void *data_02097e4c;
extern void *const data_ov009_02215d0c[];
extern const s32 data_ov009_02215d5c[];
extern const Ov009Vec data_ov009_02215e08;
extern u8 data_ov009_02216bae[];
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern s32 func_020658cc(void *mgr, s32 id);
extern Ov009V *func_020657b0(void *mgr, void *p);
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 a);

class Ov009Act3 : public Ov009Actor {
public:
    void *unk_f0;
};

void func_ov009_02203bc8(Ov009Act3 *self) {
    Ov009Actor *t;
    s32 state;
    Ov009Sub40 *st;
    Ov009V *e;
    state = self->unk_40->state;
    t = func_ov000_0218d240(self);
    switch (state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c[0], 0x400, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        e = func_02065f88(0x3ea, &self->pos);
        e->v20(&data_ov009_02215e08);
        e->v30(self->rot);
        e->v0c(0x5800);
        FLD(s32, e, 0x3c) = 0x1800;
        FLD(s32, e, 0xc8) = -1;
        FLD(void *, self, 0xf0) = FLD(void *, e, 0x24);
        func_02049f44(data_02097e4c, data_ov009_02215d5c[self->unk_1a], &self->pos, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        if (func_020658cc(data_0214a420, 0x2bd) == 0) {
            e = func_02065f88(0x2bd, &self->pos);
            e->v24(0, 0x19a, 0);
            e->v0c(0x2000);
            FLD(s32, e, 0x3c) = 0x4000;
        }
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x50) {
            self->unk_a0 = 0x266;
            self->unk_a8 = 0x29;
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        func_ov000_0218d988(self, t, 0x400);
        self->unk_98 = self->rot[1];
        break;
    case 2:
        if (self->unk_48->unk_50 & 0x20000000) {
            func_02049f44(data_02097e4c, 0x7e, &self->pos, 0);
            func_ov000_0218996c(3, 5);
            self->unk_a0 = 0x666;
            self->unk_9c = 0x266;
            self->unk_a8 = 0x52;
            self->unk_40->state++;
        }
        func_ov000_0218d988(self, t, 0x400);
        self->unk_98 = self->rot[1];
        break;
    case 3:
        if (!(self->unk_48->unk_50 & 0x20000000)) {
            break;
        }
        func_02049f44(data_02097e4c, 0x7e, &self->pos, 0);
        func_ov000_0218996c(3, 5);
        func_02065f88(0x12f, &self->pos)->v0c(0x800);
        st = self->unk_40;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        st->state++;
        break;
    case 4: {
        u16 tm;
        st = self->unk_40;
        st->timer++;
        tm = st->timer;
        if (tm == 0x32) {
            func_02065804(data_0214a420, self->unk_f0);
            self->unk_f0 = NULL;
            func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c[4], 0x400, 0);
        }
        if (tm > 0x32 && FLD(s16, self->unk_38, 0xc4) == 1) {
            self->unk_40->timer = 0;
            if (func_02040498(9) > 1) {
                e = func_02065f88(0x44d, &self->pos);
                e->v24(0, 0x1800, 0);
                FLD(s32, e, 0xc8) = 1;
                st = self->unk_40;
                st->state++;
            } else {
                self->unk_40->state = 10;
            }
        }
        break;
    }
    case 5:
        if (FLD(s16, self->unk_38, 0xc4) == 2) {
            self->unk_40->state++;
        }
        break;
    case 6:
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0xc8) {
            func_ov000_02190cb0(self->unk_38, data_ov009_02216bae, 0x111, 0);
            self->unk_40->timer = 0;
            self->unk_40->state = 0x1e;
        }
        break;
    case 10:
        if (FLD(s16, self->unk_38, 0xc4) == 2) {
            func_02065f88(0x68, &self->pos)->v24(0, 0x19a, 0);
            func_02049f44(data_02097e4c, 8, &self->pos, 0);
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    case 0x1e:
        if (func_ov000_02191120(self->unk_38)) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    func_ov000_0218dbe0(self, 0);
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
    e = func_020657b0(data_0214a420, FLD(void *, self, 0xf0));
    if (e != NULL) {
        e->v18(&self->pos);
        e->v20(&data_ov009_02215e08);
        e->v30(self->rot);
    }
    if (state < 4) {
        self->unk_94_1 = 1;
    }
}

}
