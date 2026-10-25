#include "ov013/ov013.h"

struct Ov013Spot {
    Ov013Vec pos;
    u16 rot;
};

struct Ov013Pair {
    u8 a;
    u8 b;
};

extern "C" {

extern BOOL func_ov003_021da03c(Ov013Actor *self);
extern void func_ov003_021d8fc0(void *p);
extern BOOL func_ov003_021d9878(void *p);
extern Ov013Pair func_ov003_021d9644(void *p);
extern void func_ov003_021da40c(void *p);
extern void func_ov000_0218d7e8(Ov013Actor *self, s32 a);
extern void func_ov003_021d6548(Ov013Actor *self, void *p);
extern void func_ov003_021d68e0(Ov013Actor *self, s32 a, s32 b, s32 c);
extern void func_ov000_02191418(void *a, s32 b, s32 c);
extern BOOL func_ov003_021d1c00(Ov013Actor *self, Ov013Msg *msg);

extern u8 data_ov013_0220aedc[];
extern const Ov013Spot data_ov013_0220b900[];
struct Ov013SpotBlock {
    char name[16];
    void (*fn[6])(void);
    Ov013Spot far[4];
};
extern const Ov013SpotBlock data_ov013_0220b930;
extern void *func_ov000_02190a30(void *a, s32 b);
extern void func_ov000_0218fa28(void *a, void *b, void *c, void *d, const char *e, s32 f, s32 g);
extern void func_ov013_021fe948(Ov013Vec *outPos, u16 *outRot, const Ov013Spot *list, u32 count, void *exclude);
extern BOOL func_ov013_022038a8(Ov013Actor *self, Ov013Vec *pos, u16 rot);
extern void func_ov003_021d969c(void *p, s32 a);
extern Ov013Actor *func_ov000_0219bf90(void);
extern void func_ov013_02202dc8(Ov013Actor *self, s32 a, s32 b, BOOL c, s32 d);

static inline void Ov013_PartFlag(void *m, s32 i) {
    if (func_ov000_02190a30(m, i) != NULL) {
        FLD(Ov013Flags8, func_ov000_02190a30(m, i), 0x111).b2 = 1;
    }
}

static inline u32 Ov013_Nearest(const Ov013Vec *p, const Ov013Spot *tbl, u32 n) {
    u32 best = 0;
    u32 i;
    for (i = 0; i < n; i++) {
        if (VEC_Distance(p, &tbl[best].pos) > VEC_Distance(p, &tbl[i].pos)) {
            best = i;
        }
    }
    return best;
}

static inline bool Ov013_IsMode1(Ov013Actor *self) {
    return FLD(u8, self, 0x15d) == 1;
}

void func_ov013_021ff924(Ov013Actor *self) {
    const char *anim;
    void *m;
    if (self->unk_40->state != 0) {
        return;
    }
    anim = FLD(const char *, data_ov013_0220aedc, 4);
    self->unk_9c = 0;
    self->unk_a0 = 0;
    self->unk_a4 = 0;
    self->unk_a8 = 0;
    func_ov000_02190cb0(self->unk_38, anim, 0x266, 0);
    m = self->unk_38;
    if (FLD(void *, m, 0x14) != NULL) {
        void *o = FLD(void *, m, 0);
        func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, o, FLD(void *, FLD(void *, o, 0x48), 8), anim, 0x1000, 0);
    }
    FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
    m = self->unk_38;
    if (m != NULL) {
        Ov013_PartFlag(m, 0);
        Ov013_PartFlag(m, 1);
        Ov013_PartFlag(m, 3);
        Ov013_PartFlag(m, 4);
    }
    self->rot[0] = 0;
    self->rot[2] = 0;
    self->unk_40->state++;
}

void func_ov013_021ffab4(Ov013Actor *self) {
    if (self->unk_40->state == 0) {
        Ov013Vec p;
        u32 best;
        Ov013Actor *pl = func_ov000_0219bf90();
        p.x = pl->pos.x;
        p.y = pl->pos.y;
        p.z = pl->pos.z;
        switch (FLD(u8, self, 0x15d)) {
        case 1:
            best = Ov013_Nearest(&p, data_ov013_0220b900, 3);
            FLD(Ov013Vec, self, 0x114) = data_ov013_0220b900[best].pos;
            FLD(u16, self, 0xfc) = data_ov013_0220b900[best].rot;
            break;
        case 3:
            best = Ov013_Nearest(&p, data_ov013_0220b930.far, 4);
            FLD(Ov013Vec, self, 0x114) = data_ov013_0220b930.far[best].pos;
            FLD(u16, self, 0xfc) = data_ov013_0220b930.far[best].rot;
            break;
        case 2:
            func_ov013_021fe948(&FLD(Ov013Vec, self, 0x114), &FLD(u16, self, 0xfc), data_ov013_0220b900, 3, (u8 *)self + 0x108);
            break;
        case 4:
            func_ov013_021fe948(&FLD(Ov013Vec, self, 0x114), &FLD(u16, self, 0xfc), data_ov013_0220b930.far, 4, (u8 *)self + 0x108);
            break;
        }
    }
    if (func_ov013_022038a8(self, &FLD(Ov013Vec, self, 0x114), FLD(u16, self, 0xfc))) {
        FLD(Ov013Vec, self, 0x108) = FLD(Ov013Vec, self, 0x114);
        FLD(u16, self, 0xfa) = FLD(u16, self, 0xfc);
        func_ov003_021d969c((u8 *)self + 0x14c, 1);
        func_ov000_02198360(self->unk_40, 1, 0);
    }
}

extern void *data_02097e4c;
extern void *data_0214a420;
extern void func_0203f364(Ov013Sub48 *p);
extern void func_0204a028(void *a, s32 b, Ov013Vec *c, s32 d);
extern s32 FX_Div(s32 a, s32 b);
extern u16 func_02049130(s32 t, s32 a, s32 b);
extern BOOL func_ov003_021d98bc(Ov013Vec *a, Ov013Vec *b);
extern void func_02065804(void *a, s32 b);
extern void func_ov003_021d9dbc(Ov013Vec *out, const Ov013Vec *a, const Ov013Vec *b, s32 dist, s32 yoff);
extern void func_ov003_021da2c8(Ov013Actor *self, s32 a, s32 b, s32 c, s32 d);

void func_ov013_021ffc90(Ov013Actor *self) {
    BOOL move = FALSE;
    s32 c = 0;
    self->unk_44->unk_22_1 = 0;
    switch (self->unk_40->state) {
    case 0: {
        void *m;
        move = TRUE;
        func_ov000_02190cb0(self->unk_38, FLD(const char *, data_ov013_0220aedc, 0x28), 0x266, 0);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *o = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, o, FLD(void *, FLD(void *, o, 0x48), 8), FLD(const char *, data_ov013_0220aedc, 4), 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        m = self->unk_38;
        if (m != NULL) {
            Ov013_PartFlag(m, 0);
            Ov013_PartFlag(m, 1);
            Ov013_PartFlag(m, 3);
            Ov013_PartFlag(m, 4);
        }
        {
            Ov013Vec v;
            Ov013_VecCopy(&v, &self->pos);
            v.y -= 0xf000;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_9c = 0x100;
            Ov013_VecCopy(&self->unk_b8, &v);
        }
        self->unk_40->state = 1;
        {
            Ov013Sub48 *s = self->unk_48;
            s->unk_9a_0 = 0;
            s->unk_9a_3 = 0;
            func_0203f364(s);
        }
        func_0204a028(data_02097e4c, 0x3e, &self->pos, 5);
        break;
    }
    case 1: {
        s32 t;
        s32 sp;
        Ov013Vec v;
        self->unk_40->timer++;
        t = FX_Div(self->unk_40->timer << 12, 0x1e000);
        if (t > 0x1000) {
            c = 0x1000;
        } else if (t >= 0) {
            c = t;
        }
        self->rot[0] = func_02049130(c, 0, 0x4000);
        t = self->unk_9c + 0x30;
        sp = 0;
        if (t > 0x1000) {
            sp = 0x1000;
        } else if (t >= 0) {
            sp = t;
        }
        self->unk_9c = sp;
        v = self->unk_b8;
        if (func_ov003_021d98bc(&v, &self->pos)) {
            self->unk_40->state = 2;
        } else {
            move = TRUE;
        }
        break;
    }
    case 2:
        func_02065804(data_0214a420, FLD(s32, self, 0x100));
        FLD(s32, self, 0x100) = 0;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        func_ov003_021d969c((u8 *)self + 0x14c, 1);
        break;
    }
    if (move) {
        Ov013Vec v;
        Ov013_VecCopy(&v, &self->unk_b8);
        func_ov003_021d9dbc(&self->pos, &v, &self->pos, self->unk_9c, self->unk_a0);
        func_ov003_021da2c8(self, self->unk_9c, self->unk_a0, self->unk_a4, self->unk_a8);
    }
}

}
