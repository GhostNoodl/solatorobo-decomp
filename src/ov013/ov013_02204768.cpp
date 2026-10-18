#include "ov013/ov013.h"

struct Ov013Pair32 {
    s32 a;
    s32 b;
};

extern "C" {

extern void *data_ov013_0220bbb8[];
extern char data_ov013_0220ba58[];
extern char data_ov013_0220ba60[];
extern void func_ov003_021d9980(Ov013Vec *out, u16 rot, const Ov013Vec *v);
extern void func_ov000_02194074(void *self);
extern void func_ov003_021cf2bc(void *p);
extern void func_ov003_021cf2d8(void *p);
extern void func_ov000_0218ea20(void *p);
extern void func_ov000_0218fee4(void *p);
extern void *func_ov000_0218e9c4(void *p);
extern void func_ov000_0219433c(void *self);
extern BOOL func_ov000_021946f8(void *self);
extern BOOL func_ov000_0218f110(void *p);

static inline void Ov013_InitDc(void *self) {
    FLD(Ov013Flags8, self, 0xce).b0 = 0;
    FLD(Ov013Flags8, self, 0xce).b1 = 0;
    FLD(u8, self, 0xcf) = 0;
    FLD(u16, self, 0xd0) = 0;
    FLD(u16, self, 0xd2) = 0;
    FLD(u16, self, 0xd4) = 0;
    FLD(s32, self, 0xd8) = 0;
    FLD(void *, self, 0xdc) = NULL;
    FLD(void *, self, 0xe0) = NULL;
    {
        const Ov013Pair32 *q = (const Ov013Pair32 *)0x02070edc;
        s32 b;
        s32 a;
        a = q->a;
        b = q->b;
        FLD(Ov013Pair32, self, 0xe4).a = a;
        FLD(Ov013Pair32, self, 0xe4).b = b;
    }
}

static inline void Ov013_DtorDc(void *self) {
    u32 saved;
    FLD(void *, self, 0) = data_ov013_0220bbb8;
    ((Ov013V *)((u8 *)self + 0xec))->v08();
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, 0xdc) != NULL) {
        void *p = FLD(void *, self, 0xdc);
        if (p != NULL) {
            func_ov000_0218ea20(p);
            func_0203de1c(p);
        }
        FLD(void *, self, 0xdc) = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, 0xe0) != NULL) {
        void *p = FLD(void *, self, 0xe0);
        if (p != NULL) {
            func_ov000_0218fee4(p);
            func_0203de1c(p);
        }
        FLD(void *, self, 0xe0) = NULL;
    }
    data_02097dd0->cur = saved;
    Ov013_InitDc(self);
    func_ov003_021cf2d8((u8 *)self + 0xec);
    func_ov000_0219429c(self);
}

static inline void Ov013_SetRes(Ov013Names *p, const char *a, const char *b) {
    func_0201e520(p->unk_10, a);
    func_0201e520(p->unk_30, b);
    p->unk_03_1 = 1;
}

struct Ov013ShadowGH {
    u16 g;
    u16 h;
};

struct Ov013ShadowSub {
    Ov013ShadowGH gh;
    s32 i;
};

struct Ov013Shadow {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
    u16 size;
    u16 f;
    Ov013ShadowSub sub;
};

extern void func_ov003_021cf33c(void *p, void *q);
extern Ov013Actor *func_ov000_0219bf90(void);
extern void func_ov000_02190758(void *m, u16 *rot, s32 a);
extern BOOL func_ov000_021903b4(void *m);
extern BOOL func_ov000_02194c08(void *self);
extern u8 data_ov013_0220b2ec[];
extern u8 *func_020704b4(u16 kind);

static inline u16 Ov013_LockId(void) {
    return FLD(u16, func_ov000_0219bf90(), 0xb1c);
}

static inline void Ov013_SetShadow(Ov013Shadow *s, u8 a, u8 b, u8 c, u8 d, u16 size, u16 f, Ov013ShadowSub sub) {
    s->a = a;
    s->b = b;
    s->c = c;
    s->d = d;
    s->size = size;
    s->f = f;
    s->sub = sub;
}

BOOL func_ov013_02204768(void *self) {
    BOOL r = func_ov000_021946f8(self);
    if (*FLD(s16 *, self, 0xdc) >= 0) {
        r = (r & func_ov000_0218f110(FLD(void *, self, 0xdc))) ? TRUE : FALSE;
    }
    return r;
}

BOOL func_ov013_022047a0(Ov013Actor *self) {
    if (FLD(s8, self, 0xcf) != 2) {
        void *m = self->unk_38;
        FLD(u16, m, 0xb6) = 0x5294;
        FLD(u16, m, 0xb8) = 0x5294;
        FLD(u16, m, 0xba) = 2;
        FLD(u16, m, 0xbc) = 1;
        m = FLD(void *, self, 0xe0);
        FLD(u16, m, 0xb6) = 0x5294;
        FLD(u16, m, 0xb8) = 0x5294;
        FLD(u16, m, 0xba) = 2;
        FLD(u16, m, 0xbc) = 1;
    }
    func_ov003_021cf33c((u8 *)self + 0xec, self->unk_40);
    u16 lk = Ov013_LockId();
    if (lk == self->id) {
        FLD(Ov013Vec, FLD(void *, self, 0xe0), 0x78) = self->pos;
        func_ov000_02190758(FLD(void *, self, 0xe0), self->rot, 0);
        return func_ov000_021903b4(FLD(void *, self, 0xe0));
    }
    {
        void *m = self->unk_38;
        s32 x = FLD(s32, m, 0xa8);
        s32 y = FLD(s32, m, 0xac);
        s32 z = FLD(s32, m, 0xb0);
        s32 sc;
        BOOL r;
        FLD(s32, m, 0xa8) = Ov013_FxMul(x, 0xd00);
        FLD(s32, m, 0xac) = Ov013_FxMul(y, 0xd00);
        FLD(s32, m, 0xb0) = Ov013_FxMul(z, 0xd00);
        sc = FLD(s32, self->unk_3c, 0x14);
        FLD(s32, self->unk_3c, 0x14) = Ov013_FxMul(sc, 0x59a);
        r = func_ov000_02194c08(self);
        FLD(s32, self->unk_3c, 0x14) = sc;
        m = self->unk_38;
        FLD(s32, m, 0xa8) = x;
        FLD(s32, m, 0xac) = y;
        FLD(s32, m, 0xb0) = z;
        return r;
    }
}

void func_ov013_02204910(Ov013Actor *self, u16 a, u16 b, u16 c, u16 d) {
    if (self->unk_40->unk_13 == 0x15) {
        return;
    }
    FLD(Ov013Flags8, self, 0xce).b0 = 0;
    FLD(u16, self, 0xd0) = d;
    FLD(u16, FLD(void *, self, 0x4c), 0x1c) = a;
    self->unk_90 = b;
    FLD(void *, self, 0xd8) = data_ov013_0220b2ec;
    self->unk_98 = c;
    func_ov000_02198360(self->unk_40, 0xe, 0);
}

u32 func_ov013_02204968(Ov013Actor *self) {
    return FLD(Ov013Flags8, self, 0xce).b0;
}

void func_ov013_02204978(Ov013Actor *self, u16 a) {
    FLD(u16, self, 0xd2) = a;
    FLD(Ov013Flags8, self, 0xce).b1 = 1;
}

}
