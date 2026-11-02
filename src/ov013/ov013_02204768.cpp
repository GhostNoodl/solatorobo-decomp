#include "ov013/ov013.h"

struct Ov013Pair32 {
    s32 a;
    s32 b;
};

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

BOOL Ov013ActEx_02204454_IsReady(Ov013ActEx_02204454 *self) {
    BOOL r = func_ov000_021946f8(self);
    if (*((s16 *)self->unk_dc) >= 0) {
        r = (r & func_ov000_0218f110(((void *)self->unk_dc))) ? TRUE : FALSE;
    }
    return r;
}

BOOL Ov013ActEx_02204454_Draw(Ov013ActEx_02204454 *self) {
    if (FLD(s8, self, 0xcf) != 2) {
        void *m = self->model;
        FLD(u16, m, 0xb6) = 0x5294;
        FLD(u16, m, 0xb8) = 0x5294;
        FLD(u16, m, 0xba) = 2;
        FLD(u16, m, 0xbc) = 1;
        m = self->unk_e0;
        FLD(u16, m, 0xb6) = 0x5294;
        FLD(u16, m, 0xb8) = 0x5294;
        FLD(u16, m, 0xba) = 2;
        FLD(u16, m, 0xbc) = 1;
    }
    func_ov003_021cf33c((u8 *)self + 0xec, self->fsm);
    u16 lk = Ov013_LockId();
    if (lk == self->id) {
        FLD(VecFx32, self->unk_e0, 0x78) = self->pos;
        func_ov000_02190758(self->unk_e0, &self->rot_x, 0);
        return func_ov000_021903b4(self->unk_e0);
    }
    {
        void *m = self->model;
        s32 x = FLD(s32, m, 0xa8);
        s32 y = FLD(s32, m, 0xac);
        s32 z = FLD(s32, m, 0xb0);
        s32 sc;
        BOOL r;
        FLD(s32, m, 0xa8) = FX_Mul(x, 0xd00);
        FLD(s32, m, 0xac) = FX_Mul(y, 0xd00);
        FLD(s32, m, 0xb0) = FX_Mul(z, 0xd00);
        sc = FLD(s32, self->unk_3c, 0x14);
        FLD(s32, self->unk_3c, 0x14) = FX_Mul(sc, 0x59a);
        r = func_ov000_02194c08(self);
        FLD(s32, self->unk_3c, 0x14) = sc;
        m = self->model;
        FLD(s32, m, 0xa8) = x;
        FLD(s32, m, 0xac) = y;
        FLD(s32, m, 0xb0) = z;
        return r;
    }
}

void func_ov013_02204910(Ov003Actor *self, u16 a, u16 b, u16 c, u16 d) {
    if (self->fsm->current == 0x15) {
        return;
    }
    FLD(Ov013Flags8, self, 0xce).b0 = 0;
    FLD(u16, self, 0xd0) = d;
    self->targetObj->target = a;
    self->target = b;
    FLD(void *, self, 0xd8) = data_ov013_0220b2ec;
    self->moveYaw = c;
    func_ov000_02198360(self->fsm, 0xe, 0);
}

u32 func_ov013_02204968(Ov003Actor *self) {
    return FLD(Ov013Flags8, self, 0xce).b0;
}

void func_ov013_02204978(Ov003Actor *self, u16 a) {
    FLD(u16, self, 0xd2) = a;
    FLD(Ov013Flags8, self, 0xce).b1 = 1;
}

struct Ov013Anim8 {
    u16 h8;
    u16 ha;
    u32 wc;
};

struct Ov013Anim10 {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u16 speed;
    u16 h6;
    u16 h8[2];
    u32 wc;
};

void func_ov013_0220498c(Ov003Actor *self, s16 v) {
    u8 *p;
    Ov013Anim10 t;
    if (self->state != 2) {
        return;
    }
    FLD(u16, self, 0xd4) = v;
    p = func_020704b4(self->kind);
    t = *((Ov013Anim10 *)self->targetObj);
    t.speed = FX_Mul((s32)(FLD(u16, p, 4) << 12), (s32)v) >> 12;
    *FLD(Ov013Anim10 *, self, 0x4c) = t;
}

}
