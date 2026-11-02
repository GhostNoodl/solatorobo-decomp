#include "types.h"
#include "ov000/ObjLayouts.h"
#include "Main/Sys/SysState.h"
#include "nitro/fx.h"
#include "Main/Effect/Effect.h"

typedef struct {
    s16 state;
} AnimRes;

extern "C" {

extern const u8 data_ov000_021cc480[];

void *Actor_Ctor(Actor *self);
void *Actor_DtorBase(Actor *self);
ResSet *ResSet_ReleaseAll(ResSet *self);
void Heap_Free(void *ptr);
BOOL ResSet_UpdateLoad(AnimRes *res);
void *Target_Get(void *p);
void *ActorMgr_FindPlayer(void);
void HitSphere_Unlink_0203f364(ActorSub48 *obj);
void HitMesh_Link(void *obj);
void ActorSub48_UpdatePos(ActorSub48 *obj, VecFx32 *pos, s32 c);

static inline void ResSet_Delete(ResSet *res) {
    if (res != NULL) {
        ResSet_ReleaseAll(res);
        Heap_Free(res);
    }
}

static inline void ActorEx_Init(ActorEx *self) {
    s32 i;

    Actor_Ctor(self);
    *(const void **)self = data_ov000_021cc480;
    self->unk_ac = 0xff;
    self->unk_ad = 0xff;
    self->unk_ae = 0xff;
    self->param = NULL;
    for (i = 0; i < 2; i++) {
        self->res[i] = NULL;
    }
    *((u16 *)self + 0x66) = 0;
    self->unk_bc = NULL;
    self->unk_c0 = 0;
    self->unk_c4 = 0;
    self->unk_c8 = 0;
    self->unk_cc_3 = 1;
    self->unk_cc_4 = 1;
    self->unk_cc_5 = 1;
}

static inline void ActorEx_Destroy(ActorEx *self) {
    s32 i;

    *(const void **)self = data_ov000_021cc480;
    for (i = 0; i < 2; i++) {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->heapHi;
        if (self->res[i] != NULL) {
            ResSet_Delete(self->res[i]);
            self->res[i] = NULL;
        }
        data_02097dd0->cur = saved;
    }
    if (self->unk_bc != NULL) {
        EffectMgr_Kill(data_0214a420, self->unk_bc);
    }
    Actor_DtorBase(self);
}

ActorEx *ActorEx_Ctor(ActorEx *self) {
    ActorEx_Init(self);
    return self;
}

ActorEx *func_ov000_021940e4(ActorEx *self) {
    ActorEx_Init(self);
    return self;
}

ActorEx *ActorEx_Dtor(ActorEx *self) {
    ActorEx_Destroy(self);
    return self;
}

ActorEx *ActorEx_DtorDelete(ActorEx *self) {
    ActorEx_Destroy(self);
    Heap_Free(self);
    return self;
}

ActorEx *ActorEx_DtorBase(ActorEx *self) {
    ActorEx_Destroy(self);
    return self;
}

}

typedef struct {
    u16 a;
    u16 b;
} Pair0219433c;

typedef struct {
    u8 a;
    u8 b;
    u8 kind;
    u8 d;
    u16 e;
    u16 f;
    struct {
        Pair0219433c p;
    } gh;
    u32 i;
} Hdr0219433c;

typedef struct {
    Pair0219433c p[2];
} Ids0219433c;

typedef struct {
    Hdr0219433c hdr;
    Ids0219433c ids;
    u8 f0 : 1;
    u8 f1 : 1;
    u8 frest : 6;
    u8 pad19[7];
    MtxFx43 mtx;
} Sub0219433c;

typedef struct {
    Hdr0219433c hdr;
    Ids0219433c ids;
    ActorExParam param;
} Data0219433c;

typedef struct {
    u8 pad[0x12];
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 10;
    u16 b12 : 2;
    u16 rest : 2;
} Info0219433c;

typedef struct {
    u8 pad00[0xe];
    u16 id;
    u8 pad10[0x10];
    u16 unk_20;
    u8 pad22[0x12];
    void *unk_34;
    u8 pad38[4];
    void *unk_3c;
    void *unk_40;
    u8 pad44[8];
    Sub0219433c *unk_4c;
    u8 pad50[0x20];
    VecFx32 pos;
    u16 rx;
    u16 ry;
    u16 rz;
    u8 pad82[0x11];
    u8 b93_0 : 7;
    u8 b93_7 : 1;
    u8 pad94[0x1c];
    ActorExParam *unk_b0;
    void *res[2];
    u8 padbc[0x10];
    u16 cc_0 : 1;
    u16 cc_1 : 1;
    u16 cc_2 : 1;
    u16 cc_3 : 1;
    u16 cc_4 : 1;
    u16 cc_5 : 11;
} Actor0219433c;

extern "C" {
void *Heap_Alloc(u32 size);
Info0219433c *Tbl_FindEntry_0206fef8(u16 id);
Data0219433c *func_020704b4(u16 id);
void *ResSet_Init(void *p);
void func_ov000_02193e5c(void *p, u16 id);
void *Shadow_Ctor(void *p);
void Shadow_Load(void *p);
void *History_Init(void *p);
void *Target_Init(void *p);
BOOL History_SetState(void *p, s32 a, s32 b);

#define SIN0219433c(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define COS0219433c(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

static inline void *NewRes0219433c(void) {
    void *p = Heap_Alloc(0x138);
    if (p != NULL) {
        p = ResSet_Init(p);
    }
    return p;
}

static inline void *NewA0219433c(void) {
    void *p = Heap_Alloc(0x1c);
    if (p != NULL) {
        p = Shadow_Ctor(p);
    }
    return p;
}

static inline void *NewB0219433c(void) {
    void *p = Heap_Alloc(0x14);
    if (p != NULL) {
        p = History_Init(p);
    }
    return p;
}

static inline Sub0219433c *NewSub0219433c(void) {
    void *p = Heap_Alloc(0x5c);
    if (p != NULL) {
        p = Target_Init(p);
    }
    return (Sub0219433c *)p;
}

static inline void CopyHdr0219433c(Hdr0219433c *d, const Hdr0219433c *s) {
    d->a = s->a;
    d->b = s->b;
    d->kind = s->kind;
    d->d = s->d;
    d->e = s->e;
    d->f = s->f;
    d->gh = s->gh;
    d->i = s->i;
}

static inline void CopyIds0219433c(Ids0219433c *d, const Ids0219433c *s) {
    *d = *s;
}

static inline void SetMtx0219433c(Actor0219433c *self, Sub0219433c *sub) {
    MtxFx43 t;
    MtxFx43 m;
    u16 rx;
    u16 ry;
    u16 rz;
    BOOL set = FALSE;
    sub->f0 = TRUE;
    ry = self->ry;
    rz = self->rz;
    rx = self->rx;
    MTX_Identity43_(&m);
    if (ry != 0) {
        MTX_RotY43_(&m, SIN0219433c(ry), COS0219433c(ry));
        set = TRUE;
    }
    if (rx != 0) {
        if (set) {
            MTX_RotX43_(&t, SIN0219433c(rx), COS0219433c(rx));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotX43_(&m, SIN0219433c(rx), COS0219433c(rx));
            set = TRUE;
        }
    }
    if (rz != 0) {
        if (set) {
            MTX_RotZ43_(&t, SIN0219433c(rz), COS0219433c(rz));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotZ43_(&m, SIN0219433c(rz), COS0219433c(rz));
        }
    }
    m.m[3][0] = self->pos.x;
    m.m[3][1] = self->pos.y;
    m.m[3][2] = self->pos.z;
    MI_Copy48B(&m, &self->unk_4c->mtx);
}

void ActorEx_InitActor(Actor0219433c *self) {
    Info0219433c *info = Tbl_FindEntry_0206fef8(self->id);
    Data0219433c *d = func_020704b4(self->id);
    s32 i;
    self->unk_b0 = &d->param;
    if (info->b0 || info->b1 || self->unk_b0->unk_02_3) {
        self->unk_34 = NewRes0219433c();
        func_ov000_02193e5c(self->unk_34, self->id);
    }
    if (info->b12 != 0) {
        self->unk_3c = NewA0219433c();
        Shadow_Load(self->unk_3c);
    }
    self->unk_40 = NewB0219433c();
    if (d->hdr.a != 0) {
        Sub0219433c *o = NewSub0219433c();
        self->unk_4c = o;
        if (d != NULL) {
            CopyHdr0219433c(&o->hdr, &d->hdr);
        }
        if (&d->ids != NULL) {
            CopyIds0219433c(&o->ids, &d->ids);
        }
        if (self->unk_b0->unk_02_8) {
            SetMtx0219433c(self, self->unk_4c);
        }
        if (d->hdr.kind == 2) {
            self->cc_2 = TRUE;
        }
        self->unk_4c->f1 = TRUE;
        if (self->unk_20 == 0xffff && d->hdr.a != 1) {
            History_SetState(self->unk_40, 10, 0);
        }
    }
    if (self->unk_4c != NULL) {
        for (i = 0; i < 2; i++) {
            u16 id = ((u16 *)&self->unk_4c->ids)[i + 2];
            if (id != 0xffff && (u16)(id & 0xf000) != 0) {
                self->res[i] = NewRes0219433c();
                func_ov000_02193e5c(self->res[i], id);
            }
        }
    }
    if (self->unk_b0->kind == 0x19) {
        self->cc_3 = FALSE;
        self->cc_4 = FALSE;
    }
    self->b93_7 = TRUE;
}

}
