#include "ov009/ov009.h"

extern "C" {

void func_ov009_022049e4(Ov009Actor *self) {
    if (self->unk_40->state == 0 && FLD(u8, self, 0xf3) == 1) {
        self->unk_48->unk_30 = 0;
    }
    func_ov003_021d3a88(self);
}

}

#ifdef NONMATCHING
// func_ov009_02204a10: 153 / 279 (register-masked / raw, honest_search scorer; was 151 / 379),
// no fake parameters, volatile or junk locals. Round qpD: the trail loop reads self->trail[i]
// directly, which gives the ROM's code shape there (one i * 12 shared by the VEC_Distance
// argument and the [self + i * 12, #0x10c] loads, with self + 0x10c hoisted). What is left:
// - the ROM spills that hoisted self + 0x10c to [sp, #0x10] (frame 0x104, no pushed r3); our
//   colouring keeps it in fp and spills the hoisted &v instead, so every stack offset from
//   0x10 up is 4 bytes low. In our graph &v costs 13 and the base 17; the ROM needs one more
//   value live across the loop (or a base cost of 13 or less). The ROM's
//   "mov r0, #0; mov r4, r0" before the loop suggests that value is a hoisted zero.
// - the 0x666 block after VEC_Normalize(&d, &d): the ROM loads d.z into the register of the
//   stored d.x (so it is not hoisted after allocation) and stores d.y between them.
// Round qpG: the three trail-loop zeros (g.y and the two mla high words of x * 0x666) stay separate
// nodes because the ROM-like merge is refused twice: local CSE will not merge cheap constants in a
// loop preheader, and move-constant-loads stops reusing at the multi-def `i = 0` zero in block 64.
// Merging them by hand under gdb puts the zero in fp, not a spill (42 aligned, worse). "mov r0, #0;
// mov r4, r0" is post-allocation CSE of a constant move. See docs/MATCHING.md, round qpG.
// See docs/MATCHING.md, round qpD.
extern "C" {

extern void *const data_ov009_02215d0c[];
extern void *data_ov000_021ccd64;
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_01ffc9fc(Ov009Vec *dst, const Ov009Vec *src, s32 angle);
extern void func_020639d4(Ov009V *o, s32 a, s32 b);
extern s32 FX_Div(s32 a, s32 b);
extern void func_0203f364(Ov009Sub48 *p);
extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_ov000_0218ddd4(Ov009Actor *self, Ov009Vec *v, s32 a);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern void VEC_Normalize(const Ov009Vec *in, Ov009Vec *out);
extern s32 func_ov000_0219a510(Ov009Actor *self, u16 mask, Ov009Vec *pos, s32 r, s32 a, Ov009Actor **list);
extern Ov009Actor *func_ov000_021985c0(Ov009Actor *p);
extern void func_ov000_0219bd20(u16 a, u16 b, s32 c, s32 d, s32 e, void *f);
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_ov000_02191690(void *model);

struct Ov009AngSrc {
    u8 unk_00[0x40];
    u16 unk_40;
    u8 unk_42[2];
    u16 unk_44;
};

extern u16 func_0204bfa8(Ov009AngSrc *p);

static inline s32 Ov009_GetAng(Ov009AngSrc *p) {
    if (p->unk_40 != 0) {
        return p->unk_44;
    }
    return func_0204bfa8(p);
}

static inline BOOL Ov009Game_IsPaused(Ov009Game54 *g) {
    return g->unk_d4 != 0;
}

static inline void Ov009_VecSub(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *o) {
    o->x = a->x - b->x;
    o->y = a->y - b->y;
    o->z = a->z - b->z;
}

struct Ov009Trail {
    u8 unk_00[0x10c];
    Ov009Vec trail[5];
};

struct Ov009HitMsg {
    u8 idx;
    Ov009Vec pos;
};

void func_ov009_02204a10(Ov009Actor *self) {
    Ov009Vec v;
    Ov009Vec pp;
    Ov009Vec d;
    Ov009Vec f;
    Ov009Vec g;
    Ov009HitMsg msg;
    Ov009Vec x;
    Ov009Vec d2;
    Ov009Vec w;
    Ov009Actor *list[32];
    Ov009Actor *pl;
    Ov009Sub40 *st;
    Ov009V *o;
    Ov009Sub44 *s44;
    Ov009Sub48 *s48;
    s32 h;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (Ov009Game_IsPaused(data_ov000_021ccd54)) {
        return;
    }
    pl = func_ov000_0219bf90();
    pp = pl->pos;
    st = self->unk_40;
    switch (st->state) {
    case 0: {
        s32 t;
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c[0], 0x400, 0);
        v = self->pos;
        v.y += 0x2000;
        self->unk_b8 = v;
        t = 0x3c;
        if (FLD(u8, self, 0xf2) == 1) {
            t = 0x28;
        }
        FLD(u16, self, 0xf4) = t + func_02040498(0x32);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        if (FLD(u8, self, 0xf2) == 0) {
            self->unk_40->state++;
        } else {
            self->unk_40->state = 10;
        }
    }
    case 1:
        st = self->unk_40;
        st->timer++;
        if (st->timer == 5) {
            o = func_02065f88(0x192, &self->pos);
            o->v24(0, 0x4000, 0);
            o->v34(0xbfff, 0, 0);
            func_020639d4(o, 0x54, 0);
            o = func_02065f88(0x68, &self->pos);
            o->v24(0, 0x400, 0);
            FLD(s32, o, 0x7c) = FX_Div(0x1e000, 0x1f000);
            func_02065f88(0x12f, &self->pos)->v0c(0x800);
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    case 2: {
        s32 sy;
        Ov009Sub38 *m = self->unk_38;
        h = FLD(s32, m, 0xa8);
        sy = FLD(s32, m, 0xac);
        h -= 0x19a;
        if (h <= 0) {
            h = 0;
            s48 = self->unk_48;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            func_0203f364(s48);
            s44 = self->unk_44;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
            func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c[9], 0x1000, 0);
            self->unk_38->unk_c2_0 = 0;
            self->unk_40->timer = 0;
            self->unk_40->state = 0x14;
        }
        m = self->unk_38;
        FLD(s32, m, 0xa8) = h;
        FLD(s32, m, 0xac) = sy + 0xcd;
        FLD(s32, m, 0xb0) = h;
        v = self->unk_b8;
        Ov009_VecSub(&v, &self->pos, &d2);
        VEC_MultAdd(0x19a, &d2, &self->pos, &self->pos);
        break;
    }
    case 10:
        o = func_02065f88(0x389, &self->pos);
        o->v0c(0x3000);
        h = Ov009_GetAng((Ov009AngSrc *)((u8 *)data_ov000_021ccd54 + 0xf4));
        v.x = 0;
        v.y = 0;
        v.z = -0x800;
        func_01ffc9fc(&v, &v, h);
        o->v20(&v);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 11: {
        Ov009Sub38 *m;
        h = FLD(s32, self->unk_38, 0xa8) - 0x52;
        if (h <= 0) {
            func_02065f88(0x38a, &self->pos);
            h = 0;
            s48 = self->unk_48;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            func_0203f364(s48);
            self->unk_38->unk_c2_0 = 0;
            self->unk_40->timer = 0;
            self->unk_40->state = 0x14;
        }
        m = self->unk_38;
        FLD(s32, m, 0xa8) = h;
        FLD(s32, m, 0xac) = h;
        FLD(s32, m, 0xb0) = h;
        break;
    }
    case 0x14: {
        u32 t;
        s32 dist;
        st->timer++;
        t = st->timer;
        if (!(self->unk_48->unk_50 & 0x40000000)) {
            s32 off;
            s32 n;
            u8 i;
            dist = VEC_Distance(&self->pos, &pp);
            self->unk_9c = 0x1ec;
            if (dist < 0x2800) {
                self->unk_9c = -self->unk_9c;
            }
            func_ov000_0218ddd4(self, &pp, 0x1000);
            off = 0x2333;
            if (FLD(u8, self, 0xf2) == 1) {
                off = 0x2000;
            }
            w = self->pos;
            if (func_ov000_0219a2f4(&w, off + 0x1800, -0xa000) != -0x1000) {
                if (w.y < pp.y) {
                    w.y = pp.y;
                }
                w.y += off;
            }
            self->pos.y += Ov009_FxMul(w.y - self->pos.y, 0x1000);
            VEC_Distance(&self->pos, &w);
            Ov009_VecSub(&self->pos, &pp, &d);
            func_01ffc9fc(&d, &d, (u16)(self->unk_1c + 0xffff));
            VEC_Add(&d, &pp, &d);
            d.y = self->pos.y;
            Ov009_VecSub(&d, &self->pos, &d);
            VEC_Normalize(&d, &d);
            d.x = Ov009_FxMul(d.x, 0x666);
            d.z = Ov009_FxMul(d.z, 0x666);
            d.y = 0;
            VEC_Add(&self->pos, &d, &self->pos);
            n = func_ov000_0219a510(self, 0x20, &self->pos, 0x2000, 0, list);
            if (n != 0) {
                s32 k;
                for (k = 0; k < n; k++) {
                    Ov009Actor *q;
                    if (list[k] != NULL && (q = func_ov000_021985c0(list[k])) != NULL) {
                        v = q->pos;
                        Ov009_VecSub(&self->pos, &v, &v);
                        VEC_Normalize(&v, &v);
                        f.x = Ov009_FxMul(v.x, 0x666);
                        f.y = 0;
                        f.z = Ov009_FxMul(v.z, 0x666);
                        VEC_Add(&self->pos, &f, &self->pos);
                        break;
                    }
                }
            }
            for (i = 0; i < 5; i++) {
                if (FLD(u8, self, 0xf1) == i) {
                    continue;
                }
                if (VEC_Distance(&self->pos, &((Ov009Trail *)self)->trail[i]) <= FLD(s32, self, 0xfc)) {
                    v.x = self->pos.x - ((Ov009Trail *)self)->trail[i].x;
                    v.y = self->pos.y - ((Ov009Trail *)self)->trail[i].y;
                    v.z = self->pos.z - ((Ov009Trail *)self)->trail[i].z;
                    VEC_Normalize(&v, &v);
                    g.x = Ov009_FxMul(v.x, 0x666);
                    g.y = 0;
                    g.z = Ov009_FxMul(v.z, 0x666);
                    VEC_Add(&self->pos, &g, &self->pos);
                    self->unk_1c = -self->unk_1c;
                }
            }
            msg.idx = FLD(u8, self, 0xf1);
            msg.pos = self->pos;
            func_ov000_0219bd20(self->kind, self->kind, 0xe, 1, 0x10, &msg);
            if (t >= FLD(u16, self, 0xf4) && dist <= 0x3000) {
                func_ov000_02198360(self->unk_40, 0x10, 0);
            }
        } else {
            self->unk_1c = -self->unk_1c;
        }
        if (t >= 0xd2) {
            func_ov000_02198360(self->unk_40, 0x10, 0);
        }
        if (FLD(u8, self, 0xf2) == 0) {
            u8 *b = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
            if (b != NULL) {
                x = FLD(Ov009Vec, b, 0x88);
            }
            x.y = self->pos.y;
            if (VEC_Distance(&self->pos, &x) > self->unk_c8 + 0x4800) {
                if (b != NULL) {
                    x = FLD(Ov009Vec, b, 0x88);
                }
                x.y += 0x2000;
                self->pos = x;
                FLD(u8, self, 0xf0) = 1;
                func_ov000_02198360(self->unk_40, 0x10, 0);
            }
        }
        func_ov000_021987b8(self->unk_48, 0, 0, 0);
        break;
    }
    }
    self->unk_ea_0 = 3;
    self->unk_94_1 = 1;
    if ((s32)self->unk_40->state <= 2 && FLD(s16, self->unk_38, 0xc4) == 1) {
        func_ov000_02191690(self->unk_38);
    }
}

}
#endif
