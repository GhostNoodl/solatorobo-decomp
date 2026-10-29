#include "ov013/ov013.h"

extern "C" {

extern u8 data_ov013_0220aedc[];
extern const Ov013Vec data_ov013_0220afe8;
extern void *data_02097e4c;
extern void *func_ov000_02190a30(void *a, s32 b);
extern BOOL func_ov000_0218fa28(void *a, void *b, void *c, void *d, const char *e, s32 f, s32 g);
extern void func_ov003_021d9980(Ov013Vec *out, u16 rot, const Ov013Vec *v);
extern void VEC_Add(const Ov013Vec *a, const Ov013Vec *b, Ov013Vec *out);
extern void *func_0204a028(void *a, s32 b, Ov013Vec *c, s32 d);
extern BOOL func_ov003_021d98bc(Ov013Vec *a, Ov013Vec *b);
extern void func_ov003_021d9dbc(Ov013Vec *out, const Ov013Vec *a, const Ov013Vec *b, s32 dist, s32 yoff);
extern void func_ov003_021d8a7c(void *p, s32 a);
extern void func_ov003_021d8afc(void *p);
extern u16 func_ov003_021d9c38(Ov013Vec *v);
extern u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);

static inline void Ov013_PartFlagB2(void *m, s32 i) {
    if (func_ov000_02190a30(m, i) != NULL) {
        FLD(Ov013Flags8, func_ov000_02190a30(m, i), 0x111).b2 = 1;
    }
}

static inline s32 Ov013_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline s32 Ov013_Clamp(s32 v, s32 lo, s32 hi) {
    if (v > hi) {
        return hi;
    }
    if (v < lo) {
        return lo;
    }
    return v;
}

static inline Ov013Vec Ov013_Around(const Ov013Vec *base, u16 r) {
    Ov013Vec v;
    Ov013Vec t = data_ov013_0220afe8;
    func_ov003_021d9980(&v, r, &t);
    VEC_Add(&v, base, &v);
    return v;
}

static inline void Ov013_VecSubYZ(Ov013Vec *o, const Ov013Vec *a, const Ov013Vec *b) {
    s32 y = a->y;
    s32 z = a->z;
    o->x = a->x - b->x;
    o->y = y - b->y;
    o->z = z - b->z;
}

BOOL func_ov013_022038a8(Ov013Actor *self, const Ov013Vec *pos, u16 rot) {
    BOOL ret = FALSE;
    BOOL move = TRUE;
    BOOL turn = TRUE;
    s32 rate = 0x400;
    switch (self->unk_40->state) {
    case 0: {
        void *m;
        move = FALSE;
        turn = FALSE;
        func_ov000_02190cb0(self->unk_38, FLD(const char *, data_ov013_0220aedc, 0x28), 0x266, 0);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *p = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, p, FLD(void *, FLD(void *, p, 0x48), 8), FLD(const char *, data_ov013_0220aedc, 4), 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        m = self->unk_38;
        if (m != NULL) {
            Ov013_PartFlagB2(m, 0);
            Ov013_PartFlagB2(m, 1);
            Ov013_PartFlagB2(m, 3);
            Ov013_PartFlagB2(m, 4);
        }
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->rot[0] = 0;
        self->rot[2] = 0;
        self->unk_40->state = 10;
        func_0204a028(data_02097e4c, 0x3e, &self->pos, 5);
        break;
    }
    case 10:
    case 11: {
        rate = 0x80;
        if (self->unk_40->state == 10) {
            Ov013Vec c = Ov013_Around(&FLD(Ov013Vec, self, 0x108), FLD(u16, self, 0xfa));
            Ov013_VecCopy(&self->unk_b8, &c);
            self->unk_40->state = 11;
        }
        self->unk_9c += 0x40;
        self->unk_9c = Ov013_Clamp(self->unk_9c, 0, 0x2000);
        {
            Ov013Vec w;
            Ov013_VecCopy(&w, &self->unk_b8);
            if (func_ov003_021d98bc(&w, &self->pos)) {
                func_ov003_021d8afc((u8 *)self + 0x12c);
                self->unk_40->state = 20;
            }
        }
        break;
    }
    case 20:
    case 21: {
        rate = 0x300;
        if (self->unk_40->state == 20) {
            Ov013Vec c = Ov013_Around(pos, rot);
            Ov013_VecCopy(&self->unk_b8, &c);
            FLD(u8, self, 0xf0) |= 8;
            self->unk_40->state = 21;
        }
        {
            Ov013Vec w;
            Ov013_VecCopy(&w, &self->unk_b8);
            if (VEC_Distance(&w, &self->pos) < 0x6000) {
                self->unk_9c = Ov013_FxMul64(self->unk_9c, 0xe00);
            } else {
                self->unk_9c += 0x100;
                self->unk_9c = Ov013_Clamp(self->unk_9c, 0, 0x4000);
            }
            if (func_ov003_021d98bc(&w, &self->pos) || self->unk_9c < 0x10) {
                self->unk_40->state = 30;
            }
        }
        break;
    }
    case 30:
    case 31: {
        Ov013Vec w;
        rate = 0x180;
        if (self->unk_40->state == 30) {
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            func_ov003_021d8a7c((u8 *)self + 0x12c, 0);
            Ov013_VecCopy(&self->unk_b8, pos);
            self->unk_40->state = 31;
        }
        Ov013_VecCopy(&w, &self->unk_b8);
        if (VEC_Distance(&w, &self->pos) < 0x7000) {
            self->unk_9c = Ov013_FxMul64(self->unk_9c, 0xf00);
            turn = FALSE;
        } else {
            self->unk_9c += 0xa0;
            self->unk_9c = Ov013_Clamp(self->unk_9c, 0, 0xa00);
        }
        if (func_ov003_021d98bc(&w, &self->pos) || self->unk_9c < 8) {
            self->unk_40->state = 40;
            turn = FALSE;
            func_0204a028(data_02097e4c, 0x3e, &self->pos, 5);
        }
        break;
    }
    case 40:
        move = FALSE;
        turn = FALSE;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        ret = TRUE;
        break;
    }
    if (move) {
        Ov013Vec w;
        Ov013_VecCopy(&w, &self->unk_b8);
        func_ov003_021d9dbc(&self->pos, &w, &self->pos, self->unk_9c, 0);
    }
    if (turn) {
        Ov013Vec d;
        Ov013_VecSubYZ(&d, &self->unk_b8, &self->pos);
        self->rot[1] = func_01ffc128(func_ov003_021d9c38(&d), self->rot[1], rate, 1, 0x8000);
    }
    return ret;
}

}
