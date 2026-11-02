#include "ov013/ov013.h"


extern "C" {

extern void *data_ov013_0220bbb8[];
extern char data_ov013_0220ba58[];
extern char data_ov013_0220ba60[];
extern void func_ov003_021d9980(VecFx32 *out, u16 rot, const VecFx32 *v);
extern void *Ov003Vt_021f79a8_Ctor(void *p);
extern void *Ov003Vt_021f79a8_Dtor(void *p);
extern void *func_ov000_0218ea20(void *p);
extern void *func_ov000_0218fee4(void *p);
extern ResSet *func_ov000_0218e9c4(ResSet *p);
extern BOOL func_ov000_0218f110(ResSet *p);

static inline void Ov013_InitDc(Ov013ActEx_02204454 *self) {
    self->unk_ce_0 = 0;
    self->unk_ce_1 = 0;
    self->unk_cf = 0;
    self->unk_d0 = 0;
    self->unk_d2 = 0;
    self->unk_d4 = 0;
    self->unk_d8 = NULL;
    self->unk_dc = NULL;
    self->unk_e0 = NULL;
    self->unk_e4 = NULL;
}

static inline void Ov013_DtorDc(Ov013ActEx_02204454 *self) {
    void *saved;
    *(void **)self = data_ov013_0220bbb8;
    ((Ov013V *)(self->unk_ec))->v08();
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_dc != NULL) {
        Ov013Names *p = self->unk_dc;
        if (p != NULL) {
            func_ov000_0218ea20(p);
            Heap_Free(p);
        }
        self->unk_dc = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_e0 != NULL) {
        Model0218fe1c *p = self->unk_e0;
        if (p != NULL) {
            func_ov000_0218fee4(p);
            Heap_Free(p);
        }
        self->unk_e0 = NULL;
    }
    data_02097dd0->cur = saved;
    Ov013_InitDc(self);
    Ov003Vt_021f79a8_Dtor(self->unk_ec);
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
extern Ov013Prm data_ov013_0220b2ec;
extern u8 *func_020704b4(s32 kind);

static inline u16 Ov013_LockId(void) {
    return ((Robo021ca458 *)func_ov000_0219bf90())->unk_b1c;
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

Ov013ActEx_02204454 *Ov013ActEx_02204454_Ctor(Ov013ActEx_02204454 *self) {
    ActorEx_Ctor(self);
    *(void **)self = data_ov013_0220bbb8;
    Ov003Vt_021f79a8_Ctor(self->unk_ec);
    Ov013_InitDc(self);
    return self;
}

Ov013ActEx_02204454 *Ov013ActEx_02204454_Dtor(Ov013ActEx_02204454 *self) {
    Ov013_DtorDc(self);
    return self;
}

Ov013ActEx_02204454 *Ov013ActEx_02204454_DtorDelete(Ov013ActEx_02204454 *self) {
    Ov013_DtorDc(self);
    Heap_Free(self);
    return self;
}

}
