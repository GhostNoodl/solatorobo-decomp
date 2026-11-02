#include "ov014/ov014.h"

struct Ov014Mtx33 {
    s32 m[9];
};

static inline s32 Ov014y_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline s32 Ov014y_Abs(s32 x) {
    return x < 0 ? -x : x;
}

extern "C" {

extern void *data_02097e4c;

extern Ov014Actor *Target_Get(void *p);
extern Ov014Actor *Actor_GetTarget(Ov014Obj *self);
extern void func_ov014_02215ffc(Ov014ActEx_022152e8 *self);
extern void func_ov000_021911c8(void *a, s32 b);
extern Ov014V *func_02065f88(s32 id, Ov014Vec *pos);
extern void *func_02049f44(void *mgr, s32 id, Ov014Vec *pos, s32 a);
extern void Interp_SinLerpVec(Ov014Vec *out, s32 t, Ov014Vec *a, Ov014Vec *b);
extern void Actor_TurnToActor(Ov014Obj *self, Ov014Obj *target, s32 a);
extern void Actor_TurnToPos(Ov014Obj *self, Ov014Vec *v, s32 a);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, Ov014Vec *v, s32 f, s32 g, s32 h, s32 i, s32 j);
extern u8 *func_ov000_02190a30(void *p, s32 a);
extern void func_ov003_021f0c60(Ov014Obj *self, s32 a);

static inline void Ov014z_Set(Ov014Vec *v, s32 x, s32 y, s32 z) { v->x = x; v->y = y; v->z = z; }
void func_ov014_022153e0(Ov014ActEx_022152e8 *self) {
    Ov014Mtx33 m;
    Ov014Vec v0;
    Ov014Vec v1;
    Ov014Vec v2;
    Ov014Vec n;
    Ov014Mtx33 t;
    Ov014Actor *o;
    Ov014Actor *p;
    Ov014Sub40 *st;
    o = Target_Get(self->unk_4c);
    p = Actor_GetTarget(self);
    if (o == NULL) {
        func_ov000_02198360(self->unk_40, 0x15, 0);
        return;
    }
    if (o->kind == 0x1000) {
        func_ov014_02215ffc(self);
        return;
    }
    FLD(s32, self->unk_3c, 0x14) = self->unk_ec << 1;
    st = self->unk_40;
    switch (st->state) {
    case 0: {
        BOOL set;
        u16 rz;
        u16 ry;
        u16 rx;
        u16 f;
        set = FALSE;
        func_ov000_021911c8(self->unk_38, 0);
        ry = self->rot[1];
        rz = self->rot[2];
        rx = self->rot[0];
        MTX_Identity33_((MtxFx33 *)&m);
        if (ry != 0) {
            MTX_RotY33_((MtxFx33 *)&m, OV014_SIN(ry), OV014_COS(ry));
            set = TRUE;
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX33_((MtxFx33 *)&t, OV014_SIN(rx), OV014_COS(rx));
                MTX_Concat33((MtxFx33 *)&t, (MtxFx33 *)&m, (MtxFx33 *)&m);
            } else {
                MTX_RotX33_((MtxFx33 *)&m, OV014_SIN(rx), OV014_COS(rx));
                set = TRUE;
            }
        }
        if (rz != 0) {
            if (set) {
                MTX_RotZ33_((MtxFx33 *)&t, OV014_SIN(rz), OV014_COS(rz));
                MTX_Concat33((MtxFx33 *)&t, (MtxFx33 *)&m, (MtxFx33 *)&m);
            } else {
                MTX_RotZ33_((MtxFx33 *)&m, OV014_SIN(rz), OV014_COS(rz));
                set = TRUE;
            }
        }
        Ov014z_Set(&v0, 0, Rand_UpTo(0x2000), 0x1000);
        self->unk_dc = self->pos;
        VEC_Add(&v0, &self->pos, &self->unk_d0);
        f = 0;
        if (Rand_UpTo(1) == 0) {
            f = 0x2d;
        }
        self->unk_f0 = f;
        func_02065f88(0x69, &self->pos)->v0c(0x1800);
        func_02049f44(data_02097e4c, 0x82, &self->pos, 0);
        func_02049f44(data_02097e4c, 0x57, &self->pos, 0);
        self->unk_40->timer = 0x3c;
        self->unk_40->state++;
    }
    case 1: {
        s32 k = FX_Div(self->unk_40->timer << 12, 0x3c000);
        Interp_SinLerpVec(&self->pos, k, &self->unk_d0, &self->unk_dc);
        self->rot[0] = (Ov014y_FxMul64(k, -0x1800000) + 0x1fff000) >> 12;
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            break;
        }
        self->unk_40->timer = 0x1e;
        self->unk_40->state++;
        break;
    }
    case 2:
        if (st->timer < 0xf) {
            func_ov000_021911c8(self->unk_38, 0x1000);
        }
        if (self->unk_40->timer == 0xf) {
            Ov014V *e;
            Ov014V *e2;
            FieldState *g;
            e = func_02065f88(0x66, &self->pos);
            e->v0c(0x2800);
            e->v30(self->rot);
            e2 = func_02065f88(0x3ea, &self->pos);
            e2->v0c(0x3800);
            e2->v30(self->rot);
            g = data_ov000_021ccd54;
            g->cam.base.shakeX = 1;
            g->cam.base.shakeY = 1;
            g->cam.base.shakeZ = 1;
            g->cam.base.shakeTime = 0x14;
            g->cam.base.shakeLen = 10;
            g->cam.base.shakeCur = 10;
            func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
        }
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            break;
        }
        self->unk_40->timer = 0x28;
        self->unk_40->state++;
        break;
    case 3:
        if (p != NULL) {
            Actor_TurnToActor(self, p, 0x400);
        }
        self->pos.y -= 0x52;
        self->unk_ec = 0x3000;
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            break;
        }
        self->unk_84 = p->pos;
        self->unk_40->state = 10;
        self->unk_40->timer = 0;
        break;
    case 10: {
        s32 r;
        u16 a;
        v1.x = OV014_SIN(self->rot[1]);
        v1.z = OV014_COS(self->rot[1]);
        v1.y = 0;
        v1.y -= 0x2000;
        VEC_Normalize(&v1, &v1);
        VEC_MultAdd(self->unk_e8, &v1, &self->pos, &self->pos);
        if ((self->unk_e8 += 0x10) > 0x666) {
            self->unk_e8 = 0x666;
        }
        r = self->rot[0] - 0x3f;
        if (r < 0) {
            r = 0;
        }
        self->rot[0] = r;
        a = Ov014y_FxMul64(FX_Div(self->unk_f0 << 12, 0x5a000), 0xffff000) >> 12;
        self->rot[2] = Ov014y_FxMul64(OV014_SIN(a), 0xfff000) >> 12;
        self->unk_f0++;
        self->unk_f0 %= 0x5aU;
        Actor_TurnToPos(self, &self->unk_84, 0x29);
        if (self->pos.y >= self->unk_84.y + 0x2800) {
            break;
        }
        func_02049f44(data_02097e4c, 0x50, &self->pos, 0);
        self->unk_40->state++;
        self->unk_40->timer = 0;
        break;
    }
    case 11: {
        s32 r;
        u16 a;
        s32 sp;
        if (!(self->unk_48->unk_50 & 0x40000000)) {
            if ((self->unk_e8 += 0x21) > 0x666) {
                self->unk_e8 = 0x666;
            }
        } else {
            self->unk_e8 >>= 1;
        }
        v2.x = OV014_SIN(self->rot[1]);
        v2.y = 0;
        v2.z = OV014_COS(self->rot[1]);
        VEC_MultAdd(self->unk_e8, &v2, &self->pos, &self->pos);
        sp = self->unk_e8;
        self->unk_9c = FX_Mul(v2.x, sp);
        self->unk_a0 = FX_Mul(v2.y, sp);
        self->unk_a4 = FX_Mul(v2.z, sp);
        self->pos.y -= 0xcd;
        if (self->pos.y < 0x1000) {
            self->pos.y = 0x1000;
        }
        Actor_TurnToPos(self, &self->unk_84, 0x29);
        r = self->rot[0] - 0x8f;
        if (r < 0) {
            r = 0;
        }
        self->rot[0] = r;
        a = Ov014y_FxMul64(FX_Div(self->unk_f0 << 12, 0x5a000), 0xffff000) >> 12;
        self->rot[2] = Ov014y_FxMul64(OV014_SIN(a), 0xfff000) >> 12;
        self->unk_f0++;
        self->unk_f0 %= 0x5aU;
        if (self->unk_40->timer % 3 == 0) {
            u16 mask = 0xffff;
            mask &= (u16)~(1 << (self->kind >> 12));
            if (o != NULL) {
                mask &= (u16)~(1 << ((u16)(o->id & 0xf000) >> 12));
            }
            func_ov000_0219aae8(self, o, self->unk_4c->unk_08, self->unk_4c->unk_0a, mask, NULL, 0,
                                self->unk_ec, 0x1000, 0x64, 0x1000);
        }
        st = self->unk_40;
        st->timer++;
        if (st->timer >= 0x96) {
            self->unk_40->state = 0x14;
            self->unk_40->timer = 0;
        }
        break;
    }
    case 0x14: {
        s32 sp;
        Ov014Sub44 *q4;
        Ov014Sub38 *m38;
        self->unk_ec = 0x1000;
        VEC_Normalize((Ov014Vec *)&self->unk_9c, &n);
        self->unk_98 = FX_Atan2(n.x, n.z) - 0x7fff;
        sp = self->unk_e8;
        self->unk_9c = FX_Mul(Rand_PlusMinus(0x333) + 0x1000, sp);
        self->unk_a4 = 0xf33;
        self->unk_a8 = 0x52;
        self->unk_a0 = 0x333;
        self->unk_48->unk_30 = 0x60000000;
        q4 = self->unk_44;
        q4->unk_22_0 = 1;
        q4->unk_22_1 = 1;
        m38 = self->unk_38;
        {
            s32 x = FX_Mul(m38->unk_a8.x, 0x800);
            s32 y = FX_Mul(m38->unk_a8.y, 0x800);
            s32 z = FX_Mul(m38->unk_a8.z, 0x800);
            m38->unk_a8.x = x;
            m38->unk_a8.y = y;
            m38->unk_a8.z = z;
        }
        func_02049f44(data_02097e4c, 0xf, &self->pos, 0);
        self->unk_40->state++;
        self->unk_40->timer = 0x14;
    }
    case 0x15: {
        s16 k;
        Actor_Move((Actor *)self, 0);
        k = FLD(s16, func_ov000_02190a30(self->unk_38, 0), 0x112) - 0x29;
        if (k < 0) {
            k = 0;
        }
        func_ov000_021911c8(self->unk_38, k);
        if (k < 0x800) {
            u16 rz;
            s32 d;
            self->rot[1] += (u16)FX_Mul(k, 0x200);
            rz = self->rot[2];
            if (rz < 0x3fff) {
                d = 0x71c - rz;
                if (Ov014y_Abs(d) > 0x80) {
                    self->rot[2] += (u16)(Ov014y_FxMul64(d << 12, 0x19a) >> 12);
                }
            } else {
                d = 0xf8e4 - rz;
                if (Ov014y_Abs(d) > 0x80) {
                    self->rot[2] += (u16)(Ov014y_FxMul64(d << 12, 0x19a) >> 12);
                }
            }
        }
        if (self->unk_40->timer < 10 && !(self->unk_40->timer & 8)) {
            Ov014Sub38 *m38 = self->unk_38;
            m38->unk_b6 = 0x7fff;
            m38->unk_b8 = 0x7fff;
            m38->unk_ba = 2;
            m38->unk_bc = 1;
        }
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            break;
        }
        func_ov000_02198360(self->unk_40, 0x15, 0);
        self->unk_64 = Ov014y_FxMul64(self->unk_64, 0xb33);
        self->unk_68 = Ov014y_FxMul64(self->unk_68, 0xb33);
        func_ov003_021f0c60(self, 0);
        break;
    }
    }
    func_ov000_021987b8(self->unk_48, 0, 0, 0);
}

}
