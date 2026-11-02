#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "Main/Res/StageFlags.h"

typedef struct {
    u8 pad_00[0x14];
    s16 hx;
    s16 hy;
} Info0219d1a8;

typedef struct {
    u16 max;
    u16 cur;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    u16 unk_0c;
    u16 unk_0e;
    void *fn10;
    void *fn14;
    void *fn18;
} Gauge0219d1a8;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
} Trio0219d1a8;

extern "C" {

extern char data_ov000_021cc60f[];
s16 *func_ov003_021ce630(s16 *p, void *hit);
u16 func_ov003_021ce6fc(u16 v);
u16 func_ov003_021ce79c(u16 v);
u16 func_ov003_021ce7c0(u16 v);
void *Heap_Alloc(u32 size);
Info0219d1a8 *func_0206fef8(u16 id);
BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
s32 func_ov000_021909a8(void *m, void *p, const char *name);
void func_ov000_0219c8e0(u8 *self);
void func_ov000_02198c8c(void *o, u16 id);
void func_0203f364(void *o);
void *func_ov000_021984c8(void *p);
void *History_Init(void *p);
void func_ov000_021bd198(void *p);
BOOL func_ov000_021bd314(void *p, s32 a);
void func_02062764(s32 a, s32 b);

static inline void *NewObj44_0219d1a8(void) {
    void *p = Heap_Alloc(0x24);
    if (p != NULL) {
        p = func_ov000_021984c8(p);
    }
    return p;
}

static inline void *NewObj40_0219d1a8(void) {
    void *p = Heap_Alloc(0x14);
    if (p != NULL) {
        p = History_Init(p);
    }
    return p;
}

static inline void *NewObj5c_0219d1a8(void) {
    void *p = Heap_Alloc(0xa8);
    if (p != NULL) {
        func_ov000_021bd198(p);
    }
    return p;
}

static inline Gauge0219d1a8 *NewGauge0219d1a8(void) {
    Gauge0219d1a8 *g = (Gauge0219d1a8 *)Heap_Alloc(0x1c);
    if (g != NULL) {
        g->max = 100;
        g->cur = g->max;
        g->unk_04 = 0xffff;
        g->unk_0a = 0;
        g->unk_0e = 0;
        g->unk_0c = 0;
        g->fn10 = NULL;
        g->fn14 = NULL;
        g->fn18 = NULL;
    }
    return g;
}

static inline Trio0219d1a8 *NewTrio0219d1a8(void) {
    Trio0219d1a8 *t = (Trio0219d1a8 *)Heap_Alloc(6);
    if (t != NULL) {
        t->a = 0;
        t->b = 0;
        t->c = 0;
    }
    return t;
}

void Robo021ca458_Start(Robo021ca458 *self) {
    Info0219d1a8 *info = func_0206fef8(self->kind);
    AnimEventTable *p;
    u32 *q;
    s32 x;
    s32 z;
    u16 n;

    self->radius = info->hx << 4;
    self->height = info->hy << 4;
    self->centerY = self->height >> 1;
    func_ov000_0218ffdc(&self->mdl0, &self->res0, 0, 1);
    self->mdl0.actor_id = self->id;
    self->mdl0.evFunc = (void *)func_ov003_021ce630;
    p = NULL;
    q = self->res0.unk_c0;
    if (q != NULL) {
        p = (AnimEventTable *)((u8 *)*q + 8);
    }
    self->mdl0.evTable = p;
    if (p != NULL && p->is_ptr == 0) {
        self->mdl0.evData = (s16 *)&p->entries[p->count];
    }
    self->unk_a4b = 0;
    self->mdl0.unk_c2 |= 0x100;
    if (!self->unk_b24_1) {
        self->mdl0.unk_cc = 0x320;
    }
    self->unk_a4c = 0;
    self->unk_a48 = func_ov000_021909a8(&self->mdl0, (u8 *)self + 0x200, data_ov000_021cc60f);
    func_ov000_0218ffdc(&self->mdl2, &self->res3, 0, 1);
    self->mdl2.actor_id = self->id;
    func_ov000_0219c8e0((u8 *)self);
    x = self->radius;
    z = self->centerY;
    func_ov000_02198c8c(&self->hit0, self->id);
    self->hit0.radius = (x >> 1) + (x >> 3);
    self->hit0.unk_28 = 2;
    self->hit0.offset.y = z - (z >> 3);
    self->hit0.unk_9a_0 = 0;
    self->hit0.unk_9a_3 = 0;
    func_0203f364(&self->hit0);
    func_ov000_02198c8c(&self->hit1, self->id);
    self->hit1.unk_28 = 2;
    self->hit1.unk_9a_0 = 0;
    self->hit1.radius = x;
    self->hit1.offset.y = z;
    self->hit1.unk_9a_3 = 0;
    func_0203f364(&self->hit1);
    self->hit1.unk_48 = x;
    self->unk_44 = (ActorSub44 *)(NewObj44_0219d1a8());
    self->unk_44->unk_20 = self->id;
    self->unk_44->unk_1c = x;
    self->unk_44->unk_0c.y = z;
    {
        ActorSub44 *o = self->unk_44;
        o->unk_22_0 = 1;
        o->unk_22_1 = 1;
    }
    self->fsm = (ActorSub40 *)NewObj40_0219d1a8();
    n = data_0214a424->unk_01a * 100 + 500;
    self->hp = (u16 *) NewGauge0219d1a8();
    ((Gauge0219d1a8 *)self->hp)->max = n;
    ((Gauge0219d1a8 *)self->hp)->cur = n;
    ((Gauge0219d1a8 *)self->hp)->unk_0c = 0x30;
    ((Gauge0219d1a8 *)self->hp)->fn10 = (void *)func_ov003_021ce6fc;
    ((Gauge0219d1a8 *)self->hp)->fn14 = (void *)func_ov003_021ce79c;
    ((Gauge0219d1a8 *)self->hp)->fn18 = (void *)func_ov003_021ce7c0;
    self->unk_b34 = n;
    self->unk_54 = NewTrio0219d1a8();
    self->mode = 3;
    self->unk_5c = NewObj5c_0219d1a8();
    func_ov000_021bd314(self->unk_5c, 0);
    LFLD(s32, self->unk_5c, 0x4c) = 0x400;
    self->unk_9b0 = NewObj5c_0219d1a8();
    LFLD(s32, self->unk_9b0, 0x28) = 3;
    func_ov000_021bd314(self->unk_9b0, 6);
    LFLD(s32, self->unk_9b0, 0x5c) = z >> 1;
    self->unk_9b4 = NewObj5c_0219d1a8();
    func_ov000_021bd314(self->unk_9b4, 9);
    {
        s32 v = 1;
        if (!self->unk_b24_1) {
            v = 2;
        }
        func_02062764(3, v);
    }
}

}
