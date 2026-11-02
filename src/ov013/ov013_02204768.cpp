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
extern BOOL func_ov000_0218f110(void *p);

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

BOOL Ov013ActEx_02204454_IsReady(Ov013ActEx_02204454 *self) {
    BOOL r = func_ov000_021946f8(self);
    if (self->unk_dc->unk_00 >= 0) {
        r = (r & func_ov000_0218f110(self->unk_dc)) ? TRUE : FALSE;
    }
    return r;
}

BOOL Ov013ActEx_02204454_Draw(Ov013ActEx_02204454 *self) {
    if (self->unk_cf != 2) {
        Model0218fe1c *m = self->model;
        m->color = 0x5294;
        m->color2 = 0x5294;
        m->blend = 2;
        m->blendMax = 1;
        m = self->unk_e0;
        m->color = 0x5294;
        m->color2 = 0x5294;
        m->blend = 2;
        m->blendMax = 1;
    }
    func_ov003_021cf33c(self->unk_ec, self->fsm);
    u16 lk = Ov013_LockId();
    if (lk == self->id) {
        self->unk_e0->trans = self->pos;
        func_ov000_02190758(self->unk_e0, &self->rot_x, 0);
        return func_ov000_021903b4(self->unk_e0);
    }
    {
        Model0218fe1c *m = self->model;
        s32 x = m->scale.x;
        s32 y = m->scale.y;
        s32 z = m->scale.z;
        s32 sc;
        BOOL r;
        m->scale.x = FX_Mul(x, 0xd00);
        m->scale.y = FX_Mul(y, 0xd00);
        m->scale.z = FX_Mul(z, 0xd00);
        sc = self->unk_3c->unk_14;
        self->unk_3c->unk_14 = FX_Mul(sc, 0x59a);
        r = func_ov000_02194c08(self);
        self->unk_3c->unk_14 = sc;
        m = self->model;
        m->scale.x = x;
        m->scale.y = y;
        m->scale.z = z;
        return r;
    }
}

void func_ov013_02204910(Ov013ActEx_02204454 *self, u16 a, u16 b, u16 c, u16 d) {
    if (self->fsm->current == 0x15) {
        return;
    }
    self->unk_ce_0 = 0;
    self->unk_d0 = d;
    self->targetObj->target = a;
    self->target = b;
    self->unk_d8 = &data_ov013_0220b2ec;
    self->moveYaw = c;
    func_ov000_02198360(self->fsm, 0xe, 0);
}

u32 func_ov013_02204968(Ov013ActEx_02204454 *self) {
    return self->unk_ce_0;
}

void func_ov013_02204978(Ov013ActEx_02204454 *self, u16 a) {
    self->unk_d2 = a;
    self->unk_ce_1 = 1;
}

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

void func_ov013_0220498c(Ov013ActEx_02204454 *self, s16 v) {
    u8 *p;
    Ov013Anim10 t;
    if (self->state != 2) {
        return;
    }
    self->unk_d4 = v;
    p = func_020704b4(self->kind);
    t = *((Ov013Anim10 *)self->targetObj);
    t.speed = FX_Mul((s32)(FLD(u16, p, 4) << 12), (s32)v) >> 12;
    *(Ov013Anim10 *)self->targetObj = t;
}

}
