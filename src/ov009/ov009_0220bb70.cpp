#include "ov009/ov009.h"

extern "C" {

extern void *data_ov009_02215ee4[];
extern void func_0203f324(Ov009Sub48 *p);
extern void *NNS_G3dGlbGetInvV(void);
extern void MTX_MultVec33(const Ov009Vec *v, const void *m, Ov009Vec *out);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);

static inline BOOL Ov009Game_IsPaused3(Ov009Game54 *g) {
    return g->unk_d4 != 0;
}

void func_ov009_0220bb70(Ov009Actor *self) {
    Ov009Vec p;
    Ov009Vec v;
    Ov009Sub40 *st;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (Ov009Game_IsPaused3(data_ov000_021ccd54)) {
        return;
    }
    switch (self->unk_40->state) {
    case 0: {
        Ov009Sub44 *s44;
        func_ov000_02190cb0(self->unk_38, data_ov009_02215ee4[0], 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        self->unk_40->timer = 0;
        self->unk_40->state++;
    }
    case 1: {
        Ov009Sub38 *m;
        u8 b;
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            s32 w;
            s32 y;
            s32 x;
            s32 r;
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            p.y -= FLD(s32, self, 0x6c);
            w = self->unk_64;
            y = func_02040528(FLD(s32, self, 0x68) << 1);
            x = func_02040528(w << 1);
            v.x = x;
            v.y = y;
            v.z = w;
            MTX_MultVec33(&v, NNS_G3dGlbGetInvV(), &v);
            VEC_Add(&v, &p, &v);
            r = func_02040498(0x1000);
            func_02065f88(0x389, &v)->v0c(r + 0x1000);
            self->unk_40->timer = 5;
        }
        m = self->unk_38;
        b = FLD(u8, m, 0xbe);
        if (b < 0x1f) {
            b++;
            if (b >= 0x1f) {
                b = 0x1f;
            }
            FLD(u8, m, 0xbe) = b;
        } else {
            self->unk_40->timer = 0;
            self->unk_40->state = 0x1e;
        }
        break;
    }
    case 0x1e:
        st = self->unk_40;
        st->timer++;
        if (st->timer >= 0x1e) {
            self->unk_40->timer = 0;
            if (FLD(u8, self, 0xf7) == 0) {
                Ov009Sub44 *s44 = self->unk_44;
                Ov009Sub48 *s48;
                s44->unk_22_0 = 1;
                s44->unk_22_1 = 1;
                s48 = self->unk_48;
                s48->unk_9a_0 = 1;
                s48->unk_9a_3 = 1;
                func_0203f324(s48);
            }
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    func_ov000_0218d988(self, func_ov000_0218d240(self), self->unk_b0->unk_02);
}

}
