#include "ov014/ov014.h"
#include "Main/Res/ResArc.h"
#include "nitro/mi.h"


// A header's zero rotation and vector, plus copies made at startup, next to this TU's name,
// colour scale and offset, which other functions read. The readers of 0x021fa8f8..0x021fc220
// (three files, each in its own namespace) joined in round dtD.
extern const char *const data_ov014_02216430;
extern const fx16 data_ov014_0221643a[4];
extern const VecFx32 data_ov014_02216444;
extern const VecFx32 data_ov014_02216450;
extern char data_ov014_022170c0[];
const char *const data_ov014_02216430 = data_ov014_022170c0;
static const VecFx16 data_ov014_02216434 = {0, 0, 0};
const fx16 data_ov014_0221643a[4] = {0x1800, 0x1800, 0x1800, 0x159a};
const VecFx32 data_ov014_02216444 = {0, 0x4333, 0};
const VecFx32 data_ov014_02216450 = {0, 0, 0};
char data_ov014_022170c0[] = "nut00";
static const VecFx16 data_ov014_022170c6 = data_ov014_02216434;
static const VecFx32 data_ov014_022170cc = data_ov014_02216450;

// ---- merged from ov014_021fa8f8.cpp
namespace m_021fa8f8 {
extern "C" {

extern char data_ov014_022170d8[];
extern const u8 data_ov014_02216480[];
extern BOOL func_ov000_0218cf5c(Ov003Actor *self);
extern BOOL func_ov000_0218f110(void *p);
extern BOOL func_ov000_021903b4(void *p);
extern void func_0203f364(ActorSub48 *p);
extern BOOL func_020621c4(void);
extern BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
extern void func_ov003_021cf1f0(void *a, s32 b, s32 c, const void *d);
extern Ov003Actor *func_ov000_0219bf90(void);
extern void *func_ov003_021ceff4(void *p);
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
extern void func_ov000_021911c8(void *a, s32 b);

BOOL Ov014Act_021fa6a0_IsReady(Ov014Act_021fa6a0 *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (((s16)self->unk_124.unk_00) >= 0) {
        r = (r & func_ov000_0218f110((u8 *)self + 0x124)) ? TRUE : FALSE;
    }
    return (r & func_02035b90(data_ov014_022170d8, 7)) ? TRUE : FALSE;
}

BOOL Ov014Act_021fa6a0_Draw(Ov014Act_021fa6a0 *self) {
    BOOL r = func_ov003_021d16cc(self);
    self->unk_2d4 = self->unk_104;
    func_ov000_021903b4((u8 *)self + 0x25c);
    return r;
}

void func_ov014_021fa984(Ov014Act_021fa6a0 *self) {
    func_ov003_021d1b88(self);
    func_ov000_02190a80((u8 *)self + 0x25c, func_0203db40((u8 *)self + 0x24));
}

void Ov014Act_021fa6a0_Start(Ov014Act_021fa6a0 *self) {
    ActorSub48 *m;
    ActorSub44 *n;
    func_ov003_021d112c(self);
    m = self->hit;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    func_0203f364(m);
    m = self->hit;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    m = self->hit;
    m->unk_9a_2 = 0;
    m->unk_9a_5 = 0;
    self->hit->unk_30 = 0;
    m = self->hit;
    m->offset.x = -0x1800;
    m->offset.y = 0x2000;
    m->offset.z = 0;
    n = self->unk_44;
    Ov014_VecSet(&FLD(VecFx32, n, 0xc), -0x1000, FLD(VecFx32, n, 0xc).y, 0);
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov014_0221643a);
        self->unk_364 = 0x1800;
    }
    self->pos = self->unk_f8;
    self->rot_y = 0;
    func_ov000_0218ffdc((u8 *)self + 0x25c, (u8 *)self + 0x124, 0, 1);
    self->unk_304 = 0x2000;
    self->unk_308 = 0x2000;
    self->unk_30c = 0x1000;
    self->unk_31e.b0 = 1;
    func_ov003_021cf1f0((u8 *)self + 0x348, 0, 4, data_ov014_02216480);
}

void Ov014Act_021fa6a0_Update(Ov014Act_021fa6a0 *self) {
    s32 pct;
    u8 k;
    s32 f;
    u8 *p;
    Ov003Actor *a;
    self->unk_93_4 = 0;
    if (!Ov014_GameIdle()) {
        return;
    }
    self->target = 0xffff;
    a = func_ov000_0219bf90();
    if (a != NULL) {
        self->target = a->id;
    }
    self->unk_93_4 = 1;
    k = self->fsm->current;
    pct = (u16)(self->hp[0] * 100 / self->hp[1]);
    if (k == 1) {
        f = self->unk_f4;
        if (f == 0) {
            u8 *t = self->unk_354;
            self->unk_344 = FLD(u8 *, t, 0xc) + FLD(u16, t, 8) * 8;
            func_ov003_021ceff4((u8 *)self + 0x348);
            switch (*((s16 *)self->unk_344)) {
            case 0:
                self->unk_f4 |= 4;
                self->unk_11f = 0;
                self->fsm->flags |= 0x8000;
                break;
            case 1:
                self->unk_f4 |= 8;
                self->unk_11f = 0;
                self->fsm->flags |= 0x10000;
                break;
            }
        } else if (f & 1) {
            p = self->unk_344;
            if (p != NULL) {
                self->unk_b6++;
                if (self->unk_b6 >= FLD(u16, p, 6)) {
                    self->unk_f4 = f ^ 1;
                    self->unk_b6 = 0;
                }
            } else if ((s32)++self->unk_b6 >= 0x19) {
                self->unk_f4 = f ^ 1;
                self->unk_b6 = 0;
            }
        }
    }
    if (self->msg_flags & 0x200) {
        if (Rand_UpTo(1)) {
            func_02049f44(data_02097e4c, 0x905, &self->pos, 0);
        } else {
            func_02049f44(data_02097e4c, 0xa05, &self->pos, 0);
        }
        if (self->hp[0] != 0 && k != 0xf && k != 0x10) {
            self->fsm->flags = 0;
            self->fsm->flags |= 0x40000;
        }
        if (self->unk_364 == 0x1000 && pct <= 50 && !(self->unk_f4 & 0x1000)) {
            self->unk_f4 |= 0x1000;
            self->fsm->flags = 0;
            self->fsm->flags |= 0x200000;
        }
        self->unk_312 = 0x14bf;
        self->unk_314 = 0x14bf;
        self->unk_316 = 0xb;
        self->unk_318 = 0xa;
    }
    self->unk_ea_0 = 3;
}


}
}  // namespace m_021fa8f8

// ---- merged from ov014_021fad9c.cpp
namespace m_021fad9c {
extern "C" {

extern char data_ov014_022170d8[];
extern const u8 data_ov014_02216480[];
extern BOOL func_ov000_0218cf5c(Ov003Actor *self);
extern BOOL func_ov000_0218f110(void *p);
extern BOOL func_ov000_021903b4(void *p);
extern void func_0203f364(ActorSub48 *p);
extern BOOL func_020621c4(void);
extern BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
extern void func_ov003_021cf1f0(void *a, s32 b, s32 c, const void *d);
extern Ov003Actor *func_ov000_0219bf90(void);
extern void *func_ov003_021ceff4(void *p);
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
extern void func_ov000_021911c8(void *a, s32 b);

void func_ov014_021fad9c(Ov014Act_021fa6a0 *self) {
    const char *anim;
    if (self->fsm->st != 0) {
        return;
    }
    anim = data_ov014_02216430;
    func_ov000_02190cb0(self->model, anim, 0x111, 0);
    func_ov000_021911c8(self->model, 0x1ec);
    func_ov000_021915a0(self->model);
    func_ov000_02190cb0((u8 *)self + 0x25c, anim, 0x111, 0);
    func_ov000_021911c8((u8 *)self + 0x25c, 0x1ec);
    func_ov000_021915a0((u8 *)self + 0x25c);
    self->speed = 0;
    self->velY = 0;
    self->friction = 0;
    self->gravity = 0;
    self->fsm->st++;
}

extern char data_ov014_022170fe[];
extern char data_ov014_02217104[];
extern void func_ov014_021fbb90(Ov014Act_021fa6a0 *self, s16 n);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
void func_020627a0(u16 a, u16 b);
void func_020627dc(s32 a);
void func_ov000_02182590(void *p);

void func_ov014_021fae44(Ov014Act_021fa6a0 *self) {
    VecFx32 v;
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov014_022170fe, 0x111, 0);
        func_ov000_021911c8(self->model, 0x400);
        self->unk_84.x = self->pos.x;
        self->unk_84.y = self->pos.y - 0x1333;
        self->unk_84.z = self->pos.z;
        self->fsm->st++;
        break;
    case 1:
        if (func_ov000_02191120(self->model)) {
            EffectObj *e;
            VEC_Add(&self->pos, &data_ov014_02216444, &v);
            e = func_02065f88(0x195, &v);
            self->unk_120 = e->id;
            func_02049f44(data_02097e4c, 0x36, &v, 0);
            self->fsm->st++;
        } else {
            self->pos.y += (s32)(((s64)(self->unk_84.y - self->pos.y) * 0x133 + 0x800) >> 12);
        }
        break;
    case 2:
        if (func_020657b0(data_0214a420, self->unk_120) == NULL) {
            func_ov014_021fbb90(self, 1);
            self->fsm->st = 10;
        }
        break;
    case 10: {
        Ov003Actor *a;
        u16 id = self->target_id;
        if (data_ov000_021ccd68 == NULL) {
            a = NULL;
        } else {
            a = ActorMgr_GetActor(data_ov000_021ccd68, id);
        }
        if (a != NULL) {
            ActorSub40 *s = a->fsm;
            if ((s != NULL ? s->current : 0) == 11) {
                self->fsm->st++;
            }
        }
        break;
    }
    case 11:
        func_ov000_02190cb0(self->model, data_ov014_02217104, 0x400, 0);
        func_ov000_021911c8(self->model, 0x4cd);
        func_02049f44(data_02097e4c, 0x64, &self->pos, 0);
        self->fsm->st++;
        break;
    case 12:
        if (func_ov000_02191120(self->model)) {
            self->fsm->st = 0x1e;
        }
        break;
    case 0x1e: {
        Ov003Actor *a;
        u16 id = self->target_id;
        if (data_ov000_021ccd68 == NULL) {
            a = NULL;
        } else {
            a = ActorMgr_GetActor(data_ov000_021ccd68, id);
        }
        if (a == NULL) {
            u8 *g;
            func_ov000_02190cb0(self->model, data_ov014_02216430, 0x400, 0);
            func_ov000_021911c8(self->model, 0x1ec);
            func_ov000_021915a0(self->model);
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            g = (u8 *)data_ov000_021ccd54;
            g[0xac] = 1;
            func_ov000_02182590(g + 0xac);
            self->fsm->st++;
        }
        break;
    }
    }
}

extern const VecFx32 data_ov014_0221645c;
extern Ov003Actor *Actor_GetTarget(Actor *self);
extern void func_ov014_021fbab8(Ov014Act_021fa6a0 *self, s16 n);

void func_ov014_021fb198(Ov014Act_021fa6a0 *self) {
    VecFx32 v;
    VecFx32 w;
    Ov003Actor *t = Actor_GetTarget(self);
    v.x = t->pos.x;
    v.y = t->pos.y;
    v.z = t->pos.z;
    switch (self->fsm->st) {
    case 0: {
        EffectObj *e;
        func_ov000_02190cb0((u8 *)self + 0x25c, data_ov014_022170fe, 0x111, 0);
        func_ov000_021911c8((u8 *)self + 0x25c, 0x400);
        self->unk_11c = 0;
        self->unk_110 = v;
        self->unk_11e = 0;
        VEC_Add(&self->unk_104, &data_ov014_0221645c, &w);
        e = func_02065f88(0x5e3, &w);
        self->unk_120 = e->id;
        VEC_Add(&self->unk_104, &data_ov014_0221645c, &w);
        func_02065f88(0xcb, &w);
        self->fsm->st++;
        break;
    }
    case 1: {
        EffectObj *e;
        if (func_020657b0(data_0214a420, self->unk_120) != NULL) {
            break;
        }
        func_ov000_02190cb0((u8 *)self + 0x25c, data_ov014_02217104, 0x400, 0);
        func_ov000_021911c8((u8 *)self + 0x25c, 0x4cd);
        func_02049f44(data_02097e4c, 0x900, &self->pos, 0);
        VEC_Add(&self->unk_104, &data_ov014_0221645c, &w);
        e = func_02065f88(0x68, &w);
        e->SetScale(&data_ov014_02216450);
        e->SetRotXYZ(0xbfff, self->rot_y, self->rot_z);
        self->unk_120 = e->id;
        self->fsm->st = 10;
        break;
    }
    case 10: {
        u8 b = self->unk_11e;
        if (b == 1) {
            if (self->unk_110.x >= v.x) {
                self->unk_11c = 10;
            }
        }
        func_ov014_021fbab8(self, b + self->unk_11c);
        self->fsm->timer = 0;
        self->fsm->st++;
    }
    case 11: {
        EffectObj *e;
        ActorSub40 *s = self->fsm;
        s->timer++;
        if (s->timer >= 14) {
            u16 n;
            self->fsm->timer = 0;
            n = 0;
            if (++self->unk_11e < 6) {
                self->fsm->st = 10;
            } else {
                if (((u16 *)self->unk_344) != NULL) {
                    n = ((u16 *)self->unk_344)[2];
                }
                if (++self->unk_11f >= n) {
                    self->fsm->st = 0x1e;
                } else {
                    func_ov000_02190cb0((u8 *)self + 0x25c, data_ov014_02216430, 0x111, 0);
                    func_ov000_021911c8((u8 *)self + 0x25c, 0x1ec);
                    func_ov000_021915a0((u8 *)self + 0x25c);
                    self->fsm->st = 0x14;
                }
            }
        }
        e = func_020657b0(data_0214a420, self->unk_120);
        if (e != NULL) {
            e->SetScaleAll(e->scale.x + 0xcd);
        }
        break;
    }
    case 0x14: {
        ActorSub40 *s = self->fsm;
        s->timer++;
        if (s->timer >= ((u16 *)self->unk_344)[1]) {
            self->fsm->timer = 0;
            self->fsm->st = 0;
        }
        break;
    }
    case 0x1e:
        if (FLD(u32, self, 0xf4) & 4) {
            FLD(u32, self, 0xf4) ^= 4;
        }
        FLD(u32, self, 0xf4) |= 1;
        func_ov000_02198360(self->fsm, 1, 0);
        break;
    }
}

extern void *Target_Get(void *p);

void func_ov014_021fb554(Ov014Act_021fa6a0 *self) {
    VecFx32 v;
    Actor_GetTarget(self);
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov014_022170fe, 0x111, 0);
        func_ov000_021911c8(self->model, 0x400);
        self->fsm->st++;
        break;
    case 1:
        if (func_ov000_02191120(self->model)) {
            EffectObj *e;
            VEC_Add(&self->pos, &data_ov014_02216444, &v);
            e = func_02065f88(0x195, &v);
            EffectObj_AddSndCue(e, 0x36, 0);
            self->unk_120 = e->id;
            self->fsm->st++;
        }
        break;
    case 2:
        if (func_020657b0(data_0214a420, self->unk_120) == NULL) {
            func_02049f44(data_02097e4c, 0xa01, &self->pos, 0);
            func_ov014_021fbb90(self, 0);
            self->fsm->st = 10;
        }
        break;
    case 10: {
        Ov003Actor *a;
        void *r;
        u16 id = self->target_id;
        if (data_ov000_021ccd68 == NULL) {
            a = NULL;
        } else {
            a = ActorMgr_GetActor(data_ov000_021ccd68, id);
        }
        if (a != NULL) {
            if (a->targetObj == NULL) {
                break;
            }
            r = Target_Get(a->targetObj);
            if (r == NULL) {
                break;
            }
            {
                ActorSub40 *s = a->fsm;
                if ((s != NULL ? s->current : 0) == 11 && FLD(u16, r, 0xe) == 0x5c15) {
                    self->fsm->st++;
                }
            }
        } else {
            self->fsm->st = 0;
        }
        break;
    }
    case 11:
        func_ov000_02190cb0(self->model, data_ov014_02217104, 0x400, 0);
        func_ov000_021911c8(self->model, 0x4cd);
        func_02049f44(data_02097e4c, 0x64, &self->pos, 0);
        self->fsm->st++;
        break;
    case 12:
        if (func_ov000_02191120(self->model)) {
            u16 n = 0;
            if (((u16 *)self->unk_344) != NULL) {
                n = ((u16 *)self->unk_344)[2];
            }
            if (++self->unk_11f >= n) {
                self->fsm->st = 0x1e;
                break;
            }
            func_ov000_02190cb0(self->model, data_ov014_02216430, 0x111, 0);
            func_ov000_021911c8(self->model, 0x1ec);
            func_ov000_021915a0(self->model);
            self->fsm->st = 0x14;
        }
        break;
    case 0x14: {
        ActorSub40 *s = self->fsm;
        s->timer++;
        if (s->timer >= ((u16 *)self->unk_344)[1]) {
            self->fsm->timer = 0;
            self->fsm->st = 0;
        }
        break;
    }
    case 0x1e:
        if (FLD(u32, self, 0xf4) & 8) {
            FLD(u32, self, 0xf4) ^= 8;
        }
        FLD(u32, self, 0xf4) |= 1;
        func_ov000_02198360(self->fsm, 1, 0);
        break;
    }
}

}
}  // namespace m_021fad9c

// ---- merged from ov014_021fb8dc.cpp
namespace m_021fb8dc {
struct Ov014SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov014Spawn_Init(Ov014SpawnDesc *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

static inline void Ov014Spawn_Set(Ov014SpawnDesc *d, u16 k) {
    d->kind = k;
    d->flags = k & 0xf000;
}

extern "C" {

extern const s32 data_ov014_022164e8[];
extern u8 data_ov014_022172c4[];
extern void func_ov000_021911c8(void *a, s32 b);
extern void ActorMgr_BroadcastKind(void *mgr, u16 id, s32 msg);
extern void func_0203f364(ActorSub48 *p);
extern Ov003Actor *func_ov000_02192b24(Ov014SpawnDesc *desc);
extern void func_ov000_0219bebc(Ov003Actor *a, s32 b);
extern void func_ov000_021984f4(void *a, s32 b, s32 c);
extern void func_ov000_0219864c(void *a, s32 b, s32 c);
extern void *ActorEx_Ctor(void *self);
extern void func_ov000_02194758(void *self);

void func_ov014_021fb8dc(Ov014Act_021fa6a0 *self) {
    if (self->fsm->st != 0) {
        return;
    }
    self->unk_312 = 0x14bf;
    self->unk_314 = 0x14bf;
    self->unk_316 = 0xb;
    self->unk_318 = 0xa;
    self->unk_f4 = 1;
    func_ov000_02198360(self->fsm, 1, 0);
}

void func_ov014_021fb92c(Ov014Act_021fa6a0 *self) {
    self->unk_f4 = 1;
    func_ov000_02198360(self->fsm, 1, 0);
}

void func_ov014_021fb948(Ov014Act_021fa6a0 *self) {
    const char *anim;
    ActorSub40 *st;
    FLD(Ov014Flags, self, 0xea).b9 = 1;
    switch (self->fsm->st) {
    case 0:
        anim = data_ov014_02216430;
        func_ov000_02190cb0(self->model, anim, 0x111, 0);
        func_ov000_021911c8(self->model, 0x1ec);
        func_ov000_021915a0(self->model);
        func_ov000_02190cb0((u8 *)self + 0x25c, anim, 0x111, 0);
        func_ov000_021911c8((u8 *)self + 0x25c, 0x1ec);
        func_ov000_021915a0((u8 *)self + 0x25c);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4821, 0x15);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4822, 0x15);
        {
            ActorSub48 *m = self->hit;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
        }
        {
            ActorSub44 *n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
        }
        self->targetObj->target = 0xffff;
        self->fsm->st++;
    case 1:
        st = self->fsm;
        st->timer++;
        if (st->timer > 0x3c) {
            func_ov003_021d6a3c(self, 0, 1, 1);
            self->fsm->st++;
        }
        break;
    }
}

void func_ov014_021fbab8(Ov014Act_021fa6a0 *self, s16 n) {
    Ov014SpawnDesc desc;
    Ov003Actor *o;
    Ov014Spawn_Init(&desc, 0xffff);
    Ov014Spawn_Set(&desc, 0x4821);
    o = func_ov000_02192b24(&desc);
    if (o == NULL) {
        return;
    }
    o->unk_18 = n;
    o->pos = self->unk_110;
    func_ov000_0219bebc(o, self->unk_364);
    o->vfunc_04();
    o->flags_0 = 1;
    o->target = self->target;
    if (o->targetObj != NULL) {
        o->targetObj->target = self->id;
    }
}

void func_ov014_021fbb90(Ov014Act_021fa6a0 *self, s16 n) {
    Ov014SpawnDesc desc;
    VecFx32 v;
    Ov003Actor *o;
    Ov014Spawn_Init(&desc, 0xffff);
    Ov014Spawn_Set(&desc, 0x4822);
    o = func_ov000_02192b24(&desc);
    if (o == NULL) {
        return;
    }
    VEC_Add(&self->pos, &data_ov014_02216444, &v);
    o->pos = v;
    o->unk_18 = n;
    func_ov000_0219bebc(o, self->unk_364);
    o->vfunc_04();
    o->flags_0 = 1;
    o->target = self->target;
    self->target_id = o->id;
    if (o->targetObj != NULL) {
        o->targetObj->target = self->id;
    }
}

void func_ov014_021fbc88(Ov003Actor *self) {
    if (self->unk_44 != NULL) {
        func_ov000_021984f4(self->unk_44, 0, 0);
    }
}

void func_ov014_021fbca8(Ov003Actor *self) {
    if (self->hit != NULL) {
        func_ov000_0219864c(self->hit, 0, 0);
    }
}

void func_ov014_021fbcc8(void) {
}

void func_ov014_021fbccc(void) {
}

void func_ov014_021fbcd0(void) {
}

void func_ov014_021fbcd4(void) {
}

void func_ov014_021fbcd8(void) {
}

void func_ov014_021fbcdc(void) {
}

void func_ov014_021fbce0(void) {
}

void func_ov014_021fbce4(Ov003Actor *self) {
    self->vfunc_54();
}

void func_ov014_021fbcf8(Ov003Actor *self) {
    self->unk_ee_5 = 1;
    self->vfunc_70();
}

void func_ov014_021fbd18(Ov003Actor *self) {
    self->unk_ee_2 = 2;
    self->vfunc_64();
}

void func_ov014_021fbd3c(Ov014Act_021fa6a0 *self) {
    self->vfunc_60();
}

void func_ov014_021fbd50(Ov014Act_021fa6a0 *self) {
    self->vfunc_7c();
}

#pragma force_active on
Ov014ActEx_021fbd64 *Ov014ActEx_021fbd64_Ctor(Ov014ActEx_021fbd64 *self) {
    ActorEx_Ctor(self);
    FLD(void *, self, 0) = data_ov014_022172c4;
    FLD(u8, self, 0xce) = 0;
    self->unk_d0 = NULL;
    return self;
}
#pragma force_active reset

static inline void Ov014_FreeD0(Ov014ActEx_021fbd64 *self) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_d0 != NULL) {
        Ov003FxList *p = self->unk_d0;
        if (p != NULL) {
            func_ov003_021da940(p);
            Heap_Free(p);
        }
        self->unk_d0 = NULL;
    }
    data_02097dd0->cur = saved;
}

Ov014ActEx_021fbd64 *Ov014ActEx_021fbd64_Dtor(Ov014ActEx_021fbd64 *self) {
    FLD(void *, self, 0) = data_ov014_022172c4;
    Ov014_FreeD0(self);
    func_ov000_0219429c(self);
    return self;
}

Ov014ActEx_021fbd64 *Ov014ActEx_021fbd64_DtorDelete(Ov014ActEx_021fbd64 *self) {
    FLD(void *, self, 0) = data_ov014_022172c4;
    Ov014_FreeD0(self);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void Ov014ActEx_021fbd64_Start(Ov014ActEx_021fbd64 *self) {
    s16 n;
    func_ov000_02194758(self);
    n = self->unk_18;
    if (self->pos.y > 0x5000) {
        self->pos.y = 0x5000;
    }
    if (n < 10) {
        self->pos.x = self->pos.x + data_ov014_022164e8[n];
    } else {
        self->pos.x = self->pos.x - data_ov014_022164e8[(s16)(n % 10)];
    }
    self->unk_d0 = Ov014_NewFx();
}


extern char data_ov014_022171d0[];
extern char data_ov014_022171df[];
extern char data_ov014_022171f1[];
extern char data_ov014_022171fd[];
extern void *func_0204a028(void *a, s32 b, VecFx32 *c, s32 d);
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
extern BOOL func_ov000_0219aca8(Actor *a, Actor *b, u16 c, u8 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern Ov003Actor *Actor_GetTarget(Actor *self);

void func_ov014_021fbf0c(Ov014ActEx_021fbd64 *self) {
    EffectObj *e;
    switch (self->fsm->st) {
    case 0:
        e = EffectGroup_Create(data_ov014_022171d0, data_ov014_022171df, &self->pos);
        e->AddPosXYZ(0, 0xcd, 0);
        e->SetScaleAll(0x1333);
        MIi_CpuClear32(0xffffffff, (u8 *)e + 0x84, 0x40);
        func_ov003_021da9ac(self->unk_d0, 0xff, e);
        func_0204a028(data_02097e4c, 0x11, &self->pos, 0xa);
        e = Effect3D_Create(data_ov014_022171d0, data_ov014_022171f1, 0, &self->pos);
        e->AddPosXYZ(0, 0xcd, 0);
        e->SetScaleAll(0x2000);
        e->unk_28 = 0;
        e->loopCount = 1;
        e->alpha = FX_Div(0x1e000, 0x1f000);
        func_ov003_021da9ac(self->unk_d0, 0xfe, e);
        self->fsm->st++;
    case 1:
        if (Ov003FxList_Has(self->unk_d0, 0xfe)) {
            break;
        }
        Ov003FxList_Kill(self->unk_d0, 0xff);
        self->fsm->st++;
    case 2: {
        FieldState *g;
        e = Effect3D_Create(data_ov014_022171d0, data_ov014_022171fd, 0, &self->pos);
        e->SetScaleXYZ(0x14cd, 0x1800, 0x14cd);
        e->speed = 0x1800;
        e->alpha = FX_Div(0x1e000, 0x1f000);
        e->unk_28 = 0;
        EffectObj_AddSndCue(e, 0x79, 3);
        func_ov003_021da9ac(self->unk_d0, 0xfd, e);
        func_02049f44(data_02097e4c, 0x19, &self->pos, 0x140);
        g = data_ov000_021ccd54;
        g->cam.base.shakeX = 0;
        g->cam.base.shakeY = 1;
        g->cam.base.shakeZ = 0;
        g->cam.base.shakeTime = 0xf;
        g->cam.base.shakeLen = 5;
        g->cam.base.shakeCur = 5;
        self->fsm->st++;
    }
    case 3: {
        Ov003Param *pr = ((Ov003Param *)self->targetObj);
        if (func_ov000_0219aca8(self, self, pr->unk_08, FLD(u16, pr, 0xa), 0, 0, 0x119a, 0x5000, 0x6b, 0x1000)) {
            Ov003Actor *o = Actor_GetTarget(self);
            if (o != NULL) {
                VecFx32 v;
                v.x = o->pos.x;
                v.y = o->pos.y;
                v.z = o->pos.z;
                func_02049f44(data_02097e4c, 0x10, &v, 0);
            }
        }
        if (!Ov003FxList_Has(self->unk_d0, 0xfd)) {
            func_ov000_02198360(self->fsm, 0x15, 0);
        }
        break;
    }
    }
    func_ov003_021dacfc(self->unk_d0);
}

}
}  // namespace m_021fb8dc
