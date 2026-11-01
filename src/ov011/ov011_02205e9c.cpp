#include "ov011/ov011.h"

struct Ov011Rot {
    u16 x, y, z;
};

extern "C" {

BOOL func_ov000_02198360(void *a, s32 b, s32 c);
s32 func_02040498(s32 max);
s32 func_02040528(s32 max);
s32 *NNS_G3dGlbGetInvV(void);
void VEC_Add(const Ov011Vec *a, const Ov011Vec *b, Ov011Vec *c);
void VEC_Normalize(const Ov011Vec *a, Ov011Vec *b);
u16 FX_Atan(s32 x);
u16 FX_Atan2(s32 y, s32 x);
extern const Ov011Vec data_02092a50;
extern u8 data_ov011_0220755c[];
extern u8 data_ov011_022075d4[];
Ov011Eff *func_02065f88(s32 id, Ov011Vec *pos);
Ov011Obj *func_ov000_0219be1c(s32 kind, Ov011Vec *pos, Ov011Rot *rot, u16 a, u16 b);

static inline void Ov011_MulVec33(const Ov011Vec *v, const s32 *m, Ov011Vec *out) {
    s32 x = v->x;
    s32 y = v->y;
    s32 z = v->z;
    out->x = (s32)(((s64)x * m[0] + (s64)y * m[3] + (s64)z * m[6]) >> 12);
    out->y = (s32)(((s64)x * m[1] + (s64)y * m[4] + (s64)z * m[7]) >> 12);
    out->z = (s32)(((s64)x * m[2] + (s64)y * m[5] + (s64)z * m[8]) >> 12);
}

#pragma force_active on
void func_ov011_02205e9c(Ov011Act7da4 *self) {
    func_ov000_02198360(self->unk_40, 1, 0);
}

void func_ov011_02205eb4(Ov011Act7da4 *self) {
    Ov011Rot rot;
    Ov011Vec v;
    switch (self->unk_40->state) {
    case 0:
        self->unk_f0 = 0;
        self->unk_40->state++;
        self->unk_40->timer = 30;
        break;
    case 1:
        if (self->unk_40->timer != 0) {
            self->unk_40->timer--;
        }
        if (self->unk_40->timer == 18) {
            Ov011Eff *e;
            Ov011_VecSet(&self->unk_84, func_02040528(0x4000), -func_02040498(0x3000), -0xf000);
            Ov011_MulVec33(&self->unk_84, NNS_G3dGlbGetInvV(), &v);
            VEC_Add(&v, &data_02092a50, &v);
            e = func_02065f88(0x389, &v);
            if (e == NULL) {
                return;
            }
            e->v0c(0x2000);
            e->unk_3c = 0x299a;
        } else if (self->unk_40->timer == 0) {
            Ov011Player *pl = (Ov011Player *)func_ov000_0219bf90();
            if (pl != NULL) {
                Ov011Obj *o;
                v.x = pl->unk_af0.x;
                v.y = pl->unk_af0.y;
                v.z = pl->unk_af0.z;
                v.y += 0x3000;
                v.x -= self->unk_84.x;
                v.y -= self->unk_84.y;
                v.z -= self->unk_84.z;
                VEC_Normalize(&v, &v);
                rot.x = FX_Atan(-v.y);
                rot.y = FX_Atan2(v.x, v.z);
                rot.z = 0;
                o = func_ov000_0219be1c(0x4805, &self->unk_84, &rot, self->id, pl->id);
                if (o != NULL) {
                    o->unk_60 = data_ov011_0220755c;
                }
            }
            self->unk_f0++;
            if (self->unk_f0 < 5) {
                self->unk_40->timer = 20;
            } else {
                func_ov000_02198360(self->unk_40, 1, 0);
            }
        }
        break;
    }
}
void func_ov011_02206120(Ov011Act7da4 *self) {
    Ov011Rot rot;
    Ov011Vec v;
    switch (self->unk_40->state) {
    case 0:
        self->unk_f0 = 0;
        self->unk_40->state++;
        self->unk_40->timer = 30;
        break;
    case 1:
        if (self->unk_40->timer != 0) {
            self->unk_40->timer--;
        }
        if (self->unk_40->timer == 18) {
            Ov011Eff *e;
            Ov011_VecSet(&self->unk_84, 0x4000, func_02040528(0x3000), -0xf000);
            if (!(self->unk_f0 & 1)) {
                self->unk_84.x = -self->unk_84.x;
            }
            Ov011_MulVec33(&self->unk_84, NNS_G3dGlbGetInvV(), &v);
            VEC_Add(&v, &data_02092a50, &v);
            e = func_02065f88(0x389, &v);
            if (e == NULL) {
                return;
            }
            e->v0c(0x2000);
            e->unk_3c = 0x299a;
        } else if (self->unk_40->timer == 0) {
            Ov011Player *pl = (Ov011Player *)func_ov000_0219bf90();
            if (pl != NULL) {
                Ov011Obj *o;
                v.x = pl->unk_af0.x;
                v.y = pl->unk_af0.y;
                v.z = pl->unk_af0.z;
                v.y += 0x3000;
                v.x -= self->unk_84.x;
                v.y -= self->unk_84.y;
                v.z -= self->unk_84.z;
                VEC_Normalize(&v, &v);
                rot.x = FX_Atan(-v.y);
                rot.y = FX_Atan2(v.x, v.z);
                rot.z = 0;
                if (self->unk_f0 & 1) {
                    rot.y += 0x4000;
                } else {
                    rot.y -= 0x4000;
                }
                o = func_ov000_0219be1c(0x4804, &self->unk_84, &rot, self->id, pl->id);
                if (o != NULL) {
                    o->unk_60 = data_ov011_022075d4;
                }
            }
            self->unk_f0++;
            if (self->unk_f0 < 6) {
                self->unk_40->timer = 20;
            } else {
                func_ov000_02198360(self->unk_40, 1, 0);
            }
        }
        break;
    }
}
#pragma force_active reset
}
