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
extern void func_ov003_021d9980(VecFx32 *out, u16 rot, const VecFx32 *v);
extern void *ActorEx_Ctor(void *self);
extern void *Ov003Vt_021f79a8_Ctor(void *p);
extern void *Ov003Vt_021f79a8_Dtor(void *p);
extern void *func_ov000_0218ea20(void *p);
extern void *func_ov000_0218fee4(void *p);
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
    void *saved;
    FLD(void *, self, 0) = data_ov013_0220bbb8;
    ((Ov013V *)((u8 *)self + 0xec))->v08();
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (FLD(void *, self, 0xdc) != NULL) {
        void *p = FLD(void *, self, 0xdc);
        if (p != NULL) {
            func_ov000_0218ea20(p);
            Heap_Free(p);
        }
        FLD(void *, self, 0xdc) = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (FLD(void *, self, 0xe0) != NULL) {
        void *p = FLD(void *, self, 0xe0);
        if (p != NULL) {
            func_ov000_0218fee4(p);
            Heap_Free(p);
        }
        FLD(void *, self, 0xe0) = NULL;
    }
    data_02097dd0->cur = saved;
    Ov013_InitDc(self);
    Ov003Vt_021f79a8_Dtor((u8 *)self + 0xec);
    func_ov000_0219429c(self);
}

static inline void Ov013_SetRes(Ov013Names *p, const char *a, const char *b) {
    STD_CopyString(p->mdlDir, a);
    STD_CopyString(p->mdlName, b);
    p->ownMdl = 1;
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
extern Ov003Actor *func_ov000_0219bf90(void);
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

void *Ov013ActEx_02204454_Ctor(void *self) {
    ActorEx_Ctor(self);
    FLD(void *, self, 0) = data_ov013_0220bbb8;
    Ov003Vt_021f79a8_Ctor((u8 *)self + 0xec);
    Ov013_InitDc(self);
    return self;
}

void *Ov013ActEx_02204454_Dtor(void *self) {
    Ov013_DtorDc(self);
    return self;
}

void *Ov013ActEx_02204454_DtorDelete(void *self) {
    Ov013_DtorDc(self);
    Heap_Free(self);
    return self;
}

}
