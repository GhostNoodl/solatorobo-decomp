#include "ov013/ov013.h"

struct Ov013Pair32 {
    s32 a;
    s32 b;
};

class Ov013Cls;
typedef void (Ov013Cls::*Ov013Pmf)();

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
    FLD(Ov013Pmf, self, 0xe4) = NULL;
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
    STD_CopyString(p->unk_10, a);
    STD_CopyString(p->unk_30, b);
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

void *func_ov013_02204454(void *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov013_0220bbb8;
    func_ov003_021cf2bc((u8 *)self + 0xec);
    Ov013_InitDc(self);
    return self;
}

void *func_ov013_022044c8(void *self) {
    Ov013_DtorDc(self);
    return self;
}

void *func_ov013_022045e0(void *self) {
    Ov013_DtorDc(self);
    func_0203de1c(self);
    return self;
}

}
