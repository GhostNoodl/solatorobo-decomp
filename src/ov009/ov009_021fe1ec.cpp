#include "ov009/ov009.h"

extern "C" {

extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);

void func_ov009_021fe1ec(Ov009Actor *self) {
    Ov009Sub40 *st = self->unk_40;
    if (st->state != 0) {
        return;
    }
    st->timer++;
    if (st->timer > 0x50) {
        func_ov000_02198360(self->unk_40, 1, 0);
    }
    VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
    self->unk_9c = Ov009_FxMul(self->unk_9c, 0xf33);
    self->unk_a0 = Ov009_FxMul(self->unk_a0, 0xf33);
    self->unk_a4 = Ov009_FxMul(self->unk_a4, 0xf33);
    func_ov000_021987b8(self->unk_48, 0, 0, 0);
}

extern u8 data_ov009_02216ab6[];
extern void func_ov000_021911c8(void *model, s32 a);

void func_ov009_021fe2c8(Ov009Actor *self) {
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02216ab6, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        func_ov000_021911c8(self->unk_38, 0x800);
        self->unk_48->unk_30 = 0x40000000;
        self->unk_40->state++;
    case 1:
        VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
        self->unk_9c = Ov009_FxMul(self->unk_9c, 0xe66);
        self->unk_a0 = Ov009_FxMul(self->unk_a0, 0xe66);
        self->unk_a4 = Ov009_FxMul(self->unk_a4, 0xe66);
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        break;
    }
}

extern void func_ov000_0218d850(Ov009Actor *self);
extern void VEC_Normalize(const Ov009Vec *a, Ov009Vec *b);
void func_ov009_021fe3d4(Ov009Actor *self) {
    Ov009Vec d;
    Ov009Vec e;
    Ov009Vec t;
    s32 s;
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov009_02216ab6, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        func_ov000_021911c8(self->unk_38, 0x1000);
        self->unk_40->state++;
    }
    t = self->unk_b8;
    d.x = t.x - self->pos.x;
    d.y = t.y - self->pos.y;
    d.z = t.z - self->pos.z;
    VEC_Normalize(&d, &d);
    s = self->unk_b0->unk_00;
    if (FLD(u8, self, 0xf0) != 0) {
        s >>= 1;
    }
    d.x = Ov009_FxMul(d.x, s);
    d.y = Ov009_FxMul(d.y, s);
    d.z = Ov009_FxMul(d.z, s);
    d.y -= d.y >> 2;
    e.x = d.x - self->unk_9c;
    e.y = d.y - self->unk_a0;
    e.z = d.z - self->unk_a4;
    VEC_MultAdd(0x171, &e, &FLD(Ov009Vec, self, 0x9c), &FLD(Ov009Vec, self, 0x9c));
    VEC_Add(&self->pos, &FLD(Ov009Vec, self, 0x9c), &self->pos);
    if (self->pos.y - t.y < 0x4800) {
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
    }
    func_ov000_0218d850(self);
}

#define OV009_FXMUL_K(a, k) ((s32)(((s64)(a) * (k) + 0x800) >> 12))

extern void *data_0214a420;
extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern Ov009Vec data_ov009_02215cd0;
extern Ov009Vec data_ov009_02215cdc;
extern Ov009Vec data_ov009_02215ce8;
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern Ov009Actor *func_ov000_0219bf90(void);
extern void VEC_Normalize(const Ov009Vec *in, Ov009Vec *out);
extern void func_0204a028(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
extern void func_01ffc9fc(Ov009Vec *dst, Ov009Vec *src, u16 angle);
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 mask, const Ov009Vec *v, s32 e, s32 f, s32 g, s32 h, s32 i);
extern Ov009V *func_020657b0(void *mgr, s32 h);
extern void func_02065804(void *mgr, s32 h);
extern void MIi_CpuClear32(u32 v, void *dst, u32 size);
extern s32 FX_Div(s32 a, s32 b);

static inline Ov009Actor *Ov009_FindActor(void *mgr, u16 id) {
    if (mgr == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(mgr, id);
}

void func_ov009_021fe55c(Ov009Actor *self) {
    Ov009Actor *tgt;
    Ov009Sub40 *st;
    Ov009V *e;
    Ov009Vec v;
    if (!Ov009_GameIdle()) {
        return;
    }
    tgt = Ov009_FindActor(data_ov000_021ccd68, self->unk_90);
    if (tgt == NULL) {
        func_ov000_02198360(self->unk_40, 1, 0);
        return;
    }
    switch (FLD(u16, self, 0xf4)) {
    case 0x5013:
        st = self->unk_40;
        switch (st->state) {
        case 0:
            func_ov000_021911c8(self->unk_38, 0x2800);
            v = tgt->pos;
            v.x = self->pos.x - v.x;
            v.y = self->pos.y - v.y;
            v.z = self->pos.z - v.z;
            VEC_Normalize(&v, &v);
            v.y = 0x1800;
            VEC_MultAdd(0x1000, &v, &self->pos, &v);
            self->unk_b8 = v;
            func_0204a028(data_02097e4c, 0x71, &self->pos, -2);
            self->unk_40->state++;
            break;
        case 1:
            if (tgt->unk_48 == NULL || !(tgt->unk_48->unk_50 & 0x20000000)) {
                func_ov000_02198360(st, 1, 0);
                return;
            }
            st->timer++;
            if (st->timer > 0x32) {
                func_ov000_021911c8(self->unk_38, 0x3000);
                v = tgt->pos;
                v.y += FLD(s32, self, 0x6c);
                v.x = v.x - self->pos.x;
                v.y = v.y - self->pos.y;
                v.z = v.z - self->pos.z;
                VEC_Normalize(&v, &v);
                self->unk_9c = OV009_FXMUL_K(v.x, 0x400);
                self->unk_a0 = OV009_FXMUL_K(v.y, 0x400);
                self->unk_a4 = OV009_FXMUL_K(v.z, 0x400);
                self->rot[0] = 0x1000;
                self->unk_40->timer = 0;
                self->unk_40->state++;
                e = func_02065f88(0x3ea, &self->pos);
                e->v20(&data_ov009_02215ce8);
                e->v0c(0x3000);
                e->v34(0x1000, self->rot[1], 0x8000);
                FLD(s32, e, 0x3c) = 0x1800;
                FLD(s32, self, 0xf8) = FLD(s32, e, 0x24);
                return;
            }
            self->rot[0] = func_01ffc128(0x1000, self->rot[0], 0x19a, 1, 0x8000);
            v = self->unk_b8;
            v.x = v.x - self->pos.x;
            v.y = v.y - self->pos.y;
            v.z = v.z - self->pos.z;
            self->unk_9c = OV009_FXMUL_K(v.x, 0x52);
            self->unk_a0 = OV009_FXMUL_K(v.y, 0x52);
            self->unk_a4 = OV009_FXMUL_K(v.z, 0x52);
            self->unk_a0 -= self->unk_a0 >> 2;
            VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
            func_ov000_021987b8(self->unk_48, 1, 0, 0);
            func_ov000_0218d988(self, tgt, 0x400);
            break;
        case 2:
            st->timer++;
            if (st->timer > 0xf) {
                func_ov000_021911c8(self->unk_38, 0x1800);
                self->unk_40->timer = 0;
                self->unk_40->state++;
            }
            VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
            func_ov000_021987b8(self->unk_48, 0, 0, 0);
            v.y = FLD(s32, self, 0x6c);
            v.x = 0;
            v.z = 0;
            func_ov000_0219aae8(self, self, 0x1e, 0x20, 2, &v, 0, self->unk_64, 0, 100, 0x1000);
            e = func_020657b0(data_0214a420, FLD(s32, self, 0xf8));
            if (e == NULL) {
                FLD(s32, self, 0xf8) = 0;
                return;
            }
            VEC_Add(&self->pos, &data_ov009_02215ce8, &v);
            e->v18(&v);
            break;
        case 3:
            st->timer++;
            if (st->timer > 0x1e) {
                func_ov000_02198360(self->unk_40, 1, 0);
            }
            self->unk_9c = OV009_FXMUL_K(self->unk_9c, 0xa66);
            self->unk_a0 = OV009_FXMUL_K(self->unk_a0, 0xa66);
            self->unk_a4 = OV009_FXMUL_K(self->unk_a4, 0xa66);
            VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
            func_ov000_021987b8(self->unk_48, 1, 0, 0);
            self->rot[0] = func_01ffc128(0, self->rot[0], 0xcd, 1, 0x8000);
            break;
        }
        break;
    case 0x5045:
        st = self->unk_40;
        switch (st->state) {
        case 0: {
            s32 r;
            v = self->pos;
            r = func_ov000_0219a2f4(&v, 0x1800, -0xa000);
            if (r != -0x1000) {
                s32 ty = v.y + 0x1800;
                s32 d;
                self->pos.y += OV009_FXMUL_K(ty - self->pos.y, 0xcd);
                d = self->pos.y - ty;
                if (d < 0) {
                    d = -d;
                }
                if (d <= 0x19a) {
                    r = -0x1000;
                }
            }
            if (r != -0x1000) {
                st = self->unk_40;
                st->timer++;
                if (st->timer <= 0x78) {
                    return;
                }
            }
            func_ov000_021911c8(self->unk_38, 0x1800);
            self->unk_40->timer = 0;
            self->unk_40->state++;
            break;
        }
        case 1: {
            u8 i;
            for (i = 0; i < 2; i++) {
                e = func_02065f88(0x322, &self->pos);
                v.x = 0xb33;
                v.y = 0x1b33;
                v.z = 0;
                if (i == 1) {
                    v.x = -v.x;
                }
                func_01ffc9fc(&v, &v, self->rot[1]);
                e->v20(&v);
                e->v0c(0x800);
                MIi_CpuClear32(-1, (u8 *)e + 0x84, 0x40);
            }
            FLD(s32, self, 0xf8) = FLD(s32, e, 0x24);
            func_02049f44(data_02097e4c, 0x7a, &self->pos, 0);
            self->unk_40->state++;
            break;
        }
        case 2:
            if (func_020657b0(data_0214a420, FLD(s32, self, 0xf8)) != NULL) {
                return;
            }
            e = func_02065f88(0x321, &self->pos);
            e->v20(&data_ov009_02215cd0);
            e->v0c(0x19a);
            MIi_CpuClear32(-1, (u8 *)e + 0x84, 0x40);
            FLD(s32, e, 0x7c) = FX_Div(0x10000, 0x1f000);
            FLD(s32, self, 0xf8) = FLD(s32, e, 0x24);
            func_0204a028(data_02097e4c, 0x79, &self->pos, -10);
            self->unk_40->state++;
            break;
        case 3:
            e = func_020657b0(data_0214a420, FLD(s32, self, 0xf8));
            if (e != NULL) {
                s32 s = FLD(s32, e, 0x40);
                e->v0c(s + 0x333);
                if (s + 0x333 >= 0x2800) {
                    Ov009Sub38 *m = self->unk_38;
                    FLD(u16, m, 0xb6) = 0x7c00;
                    FLD(u16, m, 0xb8) = 0x7c00;
                    FLD(u16, m, 0xba) = 0x3d;
                    FLD(u16, m, 0xbc) = 0x3c;
                    self->unk_40->state++;
                }
            }
            self->unk_94_1 = 1;
            break;
        case 4:
            st->timer++;
            if (st->timer > 0x3c) {
                func_02065804(data_0214a420, FLD(s32, self, 0xf8));
                e = func_02065f88(0x322, &self->pos);
                e->v20(&data_ov009_02215cdc);
                e->v0c(0xccd);
                FLD(s32, self, 0xf8) = FLD(s32, e, 0x24);
                func_ov000_021911c8(self->unk_38, 0x1000);
                self->unk_40->timer = 0;
                self->unk_40->state++;
            }
            if (func_ov000_0219aae8(self, self, 0x3c, 0x11, 2, &data_ov009_02215cd0, 0, 0x2800, 0, 0x322, 0xccd)) {
                Ov009Vec p;
                p = func_ov000_0219bf90()->pos;
                func_02049f44(data_02097e4c, 0x77, &p, 0);
            }
            self->unk_94_1 = 1;
            break;
        case 5:
            if (func_020657b0(data_0214a420, FLD(s32, self, 0xf8)) != NULL) {
                return;
            }
            FLD(s32, self, 0xf8) = 0;
            self->unk_40->timer = 0;
            func_ov000_02198360(self->unk_40, 1, 0);
            break;
        }
        break;
    }
}

}
