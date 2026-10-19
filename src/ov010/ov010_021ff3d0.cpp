#include "ov010/ov010.h"

struct Ov010Shake {
    u8 unk_00[4];
    u8 active;
    u8 unk_05;
    s16 decay;
    Ov010Vec a;
    Ov010Vec b;
    Ov010Vec vel;
    Ov010Vec pos;
    u16 state;
    u16 timer;
    u8 unk_3c[0x10];
    Ov010Vec dir;
    s16 lim;
    s16 acc;
    u16 dur;
    s16 k5e;
    s16 k60;
    s16 k62;
    s16 k64;
    s16 k66;
};

extern "C" {

void func_ov010_021ff3d0(void *self, s32 *msg) {
    switch (msg[0]) {
    case 2:
        FLD(u8, self, 4) = (msg[1] == 1) ? TRUE : FALSE;
        break;
    case 3:
        FLD(s32, self, 8) = msg[1];
        break;
    }
}

extern u8 data_ov010_0220ebc0[];
extern Ov010Vec data_ov010_0220ec38;
extern const Ov010Vec data_ov010_0220ecc8;
extern u16 func_ov003_021d9c38(Ov010Vec *v);
extern void VEC_MultAdd(s32 s, const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *o);
extern void VEC_Normalize(const Ov010Vec *a, Ov010Vec *o);
extern s32 VEC_Mag(const Ov010Vec *v);
extern void func_ov003_021d9aec(Ov010Vec *out, const Ov010Vec *in, s32 max);

static inline s32 Ov010s_Mul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline s32 Ov010s_Dot(const Ov010Vec *a, const Ov010Vec *b) {
    return (s32)(((s64)a->x * b->x + (s64)a->y * b->y + (s64)a->z * b->z + 0x800) >> 12);
}

void func_ov010_021ff404(Ov010Shake *self) {
    if (self->active) {
        switch (self->state) {
        case 0: {
            u16 r = func_ov003_021d9c38(&self->dir);
            self->a.x = Ov010s_Mul64(self->dir.x, -0x1000);
            self->a.y = Ov010s_Mul64(self->dir.y, -0x1000);
            self->a.z = Ov010s_Mul64(self->dir.z, -0x1000);
            func_ov003_021d9900(&self->b, 0xe39, &data_ov010_0220ec38);
            func_ov003_021d9980(&self->b, r, &self->b);
            self->pos = self->vel = FLD(Ov010Vec, data_ov010_0220ebc0, 0x60);
            self->state = 10;
            break;
        }
        case 10:
            VEC_MultAdd(self->acc, &self->dir, &self->vel, &self->vel);
            self->timer++;
            if (self->timer > self->dur) {
                self->timer = 0;
                self->state = 0x14;
            }
            break;
        case 0x14: {
            Ov010Vec u;
            Ov010Vec t;
            s32 k;
            self->vel.y = Ov010s_Mul64(self->vel.y, 0xf00);
            *(Ov010Blk12 *)&t = *(Ov010Blk12 *)&data_ov010_0220ecc8;
            k = self->k5e;
            u.x = Ov010_FxMul(self->a.x, k);
            u.y = Ov010_FxMul(self->a.y, k);
            u.z = Ov010_FxMul(self->a.z, k);
            k = self->k60;
            t.x = Ov010_FxMul(t.x, k);
            t.y = Ov010_FxMul(t.y, k);
            t.z = Ov010_FxMul(t.z, k);
            if (Ov010s_Dot(&self->pos, &self->dir) < 0) {
                k = self->k62;
                self->vel.x = Ov010_FxMul(self->vel.x, k);
                self->vel.y = Ov010_FxMul(self->vel.y, k);
                self->vel.z = Ov010_FxMul(self->vel.z, k);
                if (VEC_Mag(&self->vel) < self->k64) {
                    self->state = 0x1e;
                }
            } else {
                VEC_Add(&self->vel, &u, &self->vel);
                VEC_Add(&self->vel, &t, &self->vel);
            }
            break;
        }
        case 0x1e: {
            Ov010Vec w;
            s32 e;
            w.x = Ov010s_Mul64(self->pos.x, -0x1000);
            w.y = Ov010s_Mul64(self->pos.y, -0x1000);
            w.z = Ov010s_Mul64(self->pos.z, -0x1000);
            VEC_Normalize(&w, &w);
            VEC_MultAdd(self->k66, &w, &self->vel, &self->vel);
            func_ov003_021d9aec(&self->vel, &self->vel, 0x300);
            {
            Ov010Vec up;
            up.x = 0; up.y = 0x1000; up.z = 0;
            e = Ov010s_Dot(&self->pos, &up);
            }
            if (Ov010s_Dot(&self->pos, &self->dir) >= 0 && e <= 0) {
                self->state = 0x14;
            }
            break;
        }
        }
        VEC_Add(&self->pos, &self->vel, &self->pos);
        func_ov003_021d9aec(&self->vel, &self->vel, self->lim);
    } else {
        s32 k = self->decay;
        self->vel.x = Ov010_FxMul(self->vel.x, k);
        self->vel.y = Ov010_FxMul(self->vel.y, k);
        self->vel.z = Ov010_FxMul(self->vel.z, k);
        if (VEC_Mag(&self->vel) < 0x20) {
            self->vel = FLD(Ov010Vec, data_ov010_0220ebc0, 0x60);
        }
    }
}

}
