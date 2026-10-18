#include "ov009/ov009.h"

extern "C" {

extern void VEC_Normalize(const Ov009Vec *in, Ov009Vec *out);

void func_ov009_0220e4fc(Ov009Actor *self) {
    Ov009Vec d;
    if (VEC_Distance(&self->pos, &FLD(Ov009Vec, self, 0xfc)) < 0xcd) {
        Ov009Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer > 0x1e) {
            s32 r;
            FLD(Ov009Vec, self, 0xfc) = FLD(Ov009Vec, self, 0xf0);
            r = func_02040528(0x7000);
            if (FLD(u8, self, 0x108) != 0 && r > 0) {
                r = -r;
            }
            FLD(Ov009Vec, self, 0xfc).x += r;
            FLD(Ov009Vec, self, 0xfc).y += func_02040528(0x3000);
            self->unk_40->timer = 0;
        }
    }
    d.x = FLD(Ov009Vec, self, 0xfc).x - self->pos.x;
    d.y = FLD(Ov009Vec, self, 0xfc).y - self->pos.y;
    d.z = FLD(Ov009Vec, self, 0xfc).z - self->pos.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(0x7b, &d, &self->pos, &self->pos);
}

extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);
extern s32 func_02040498(s32 max);
extern Ov009Actor *func_ov000_0219be1c(u16 kind, const Ov009Vec *pos, const void *rot, u16 id, u16 parent);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
struct Ov009Rot3 {
    u16 x;
    u16 y;
    u16 z;
};

void func_ov009_0220e5f0(Ov009Actor *self) {
    Ov009Vec d;
    Ov009Rot3 r;
    Ov009Sub40 *st;
    if (func_ov000_0218d240(self) == NULL) {
        return;
    }
    st = self->unk_40;
    switch (st->state) {
    case 0: {
        FLD(Ov009Vec, self, 0xfc).x = self->pos.x + 0x1e000;
        FLD(Ov009Vec, self, 0xfc).y = 0x5000;
        FLD(Ov009Vec, self, 0xfc).z = self->pos.z - 0xa000;
        self->unk_b8.x = FLD(Ov009Vec, self, 0xfc).x;
        self->unk_b8.y = FLD(Ov009Vec, self, 0xfc).y;
        self->unk_b8.z = FLD(Ov009Vec, self, 0xfc).z;
        st->state++;
        self->unk_40->timer = func_02040498(0x14) + 100;
        break;
    }
    case 1:
        self->rot[2] = func_01ffc128(0xd8e4, self->rot[2], 0x52, 1, 0x8000);
        d.x = FLD(Ov009Vec, self, 0xfc).x - self->pos.x;
        d.y = FLD(Ov009Vec, self, 0xfc).y - self->pos.y;
        d.z = FLD(Ov009Vec, self, 0xfc).z - self->pos.z;
        VEC_Normalize(&d, &d);
        VEC_MultAdd(0x11f, &d, &self->pos, &self->pos);
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        r.y = self->rot[1];
        r.x = 0;
        r.z = 0;
        func_ov000_0219be1c(0x482e, &self->pos, &r, self->id, self->unk_90);
        func_02065f88(0x325, &self->pos)->v34(0, (u16)(self->rot[1] + 0x8000), 0);
        self->unk_40->state++;
        self->unk_40->timer = func_02040498(0x14) + 0x46;
        break;
    case 2:
        self->rot[2] = func_01ffc128(0, self->rot[2], 0x29, 1, 0x8000);
        d.x = FLD(Ov009Vec, self, 0xfc).x - self->pos.x;
        d.y = FLD(Ov009Vec, self, 0xfc).y - self->pos.y;
        d.z = FLD(Ov009Vec, self, 0xfc).z - self->pos.z;
        VEC_Normalize(&d, &d);
        VEC_MultAdd(0x11f, &d, &self->pos, &self->pos);
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        FLD(Ov009Vec, self, 0xfc).x = FLD(Ov009Vec, self, 0xf0).x;
        FLD(Ov009Vec, self, 0xfc).y = FLD(Ov009Vec, self, 0xf0).y;
        FLD(Ov009Vec, self, 0xfc).z = FLD(Ov009Vec, self, 0xf0).z;
        self->unk_40->state++;
        self->unk_40->timer = 0;
        break;
    case 3: {
        s32 dist;
        self->rot[2] = func_01ffc128(0, self->rot[2], 0x29, 1, 0x8000);
        d.x = FLD(Ov009Vec, self, 0xfc).x - self->pos.x;
        d.y = FLD(Ov009Vec, self, 0xfc).y - self->pos.y;
        d.z = FLD(Ov009Vec, self, 0xfc).z - self->pos.z;
        VEC_Normalize(&d, &d);
        VEC_MultAdd(0x266, &d, &self->pos, &self->pos);
        dist = VEC_Distance(&self->pos, &FLD(Ov009Vec, self, 0xfc));
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x78 || dist < 0x3000) {
            self->rot[2] = 0;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    }
}

}
