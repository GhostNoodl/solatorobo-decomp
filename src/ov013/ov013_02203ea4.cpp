#include "ov013/ov013.h"

extern "C" {

extern u8 data_ov013_0220aedc[];
extern void *data_02097e4c;
extern void *data_0214a420;
extern Ov013Actor *func_ov000_0219bf90(void);
extern void *func_ov000_02190a30(void *a, s32 b);
extern BOOL func_ov000_0218fa28(void *a, void *b, void *c, void *d, const char *e, s32 f, s32 g);
extern Ov013V *func_02065f88(s32 id, Ov013Vec *pos);
extern void *func_0204a028(void *a, s32 b, Ov013Vec *c, s32 d);
extern void func_02065804(void *a, s32 b);
extern u16 FX_Atan2(s32 y, s32 x);
extern BOOL func_ov003_021d98bc(Ov013Vec *a, Ov013Vec *b);
extern void func_ov003_021d9dbc(Ov013Vec *out, const Ov013Vec *a, const Ov013Vec *b, s32 dist, s32 yoff);
extern void func_ov003_021da2c8(Ov013Actor *self, s32 a, s32 b, s32 c, s32 d);
extern void func_ov003_021d8a7c(void *p, s32 a);

static inline void Ov013_PartFlagB2(void *m, s32 i) {
    if (func_ov000_02190a30(m, i) != NULL) {
        FLD(Ov013Flags8, func_ov000_02190a30(m, i), 0x111).b2 = 1;
    }
}

static inline s32 Ov013_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

BOOL func_ov013_02203ea4(Ov013Actor *self, const Ov013Vec *dst) {
    BOOL ret = FALSE;
    BOOL move = FALSE;
    self->unk_44->unk_22_1 = 0;
    switch (self->unk_40->state) {
    case 0: {
        void *m;
        Ov013V *o;
        Ov013Vec v;
        Ov013_VecCopy(&v, dst);
        Ov013_VecCopy(&self->unk_b8, &v);
        self->pos.x = v.x;
        self->pos.z = v.z;
        self->pos.y = v.y - 0xf000;
        move = TRUE;
        self->rot[0] = 0xbfff;
        o = func_02065f88(0x2bd, (Ov013Vec *)dst);
        o->v0c(0x3000);
        FLD(s32, o, 0xc8) = -1;
        FLD(s32, self, 0x100) = FLD(s32, o, 0x24);
        self->unk_9c = 0x900;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        func_ov003_021d8a7c((u8 *)self + 0x12c, 0);
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
        self->unk_40->state = 10;
        func_0204a028(data_02097e4c, 0x3e, &self->pos, 5);
        break;
    }
    case 10:
        self->unk_40->timer++;
        if (self->unk_40->timer > 0x4b) {
            self->unk_40->timer = 0;
            self->unk_40->state = 20;
        }
        break;
    case 20: {
        Ov013Actor *a = func_ov000_0219bf90();
        u16 r;
        if (a == NULL || a == self) {
            r = self->rot[1];
        } else {
            r = FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
        }
        self->rot[1] = r;
        self->unk_40->state = 21;
        break;
    }
    case 21: {
        Ov013Vec w;
        Ov013_VecCopy(&w, &self->unk_b8);
        move = TRUE;
        if (func_ov003_021d98bc(&w, &self->pos) || self->unk_9c < 0x40) {
            self->unk_40->state = 100;
        } else if (VEC_Distance(&w, &self->pos) < 0x5000) {
            self->unk_9c = Ov013_FxMul64(self->unk_9c, 0xf00);
        }
        break;
    }
    case 100:
        func_02065804(data_0214a420, FLD(s32, self, 0x100));
        FLD(s32, self, 0x100) = 0;
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
        func_ov003_021d9dbc(&self->pos, &w, &self->pos, self->unk_9c, self->unk_a0);
        func_ov003_021da2c8(self, self->unk_9c, self->unk_a0, self->unk_a4, self->unk_a8);
    }
    return ret;
}
}
