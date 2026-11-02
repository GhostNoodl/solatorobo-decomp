#include "ov011/ov011.h"


// A header's zero rotation and vector, plus copies made at startup, between this TU's resource
// names and the pointers to them. The first pointer and a scale are read by other functions.
// The functions of 0x021ffb58..0x02200aac (three files, merged in rounds dtB and jkL, each in its
// own namespace) are part of this TU: they read the name pointers and the zero vector through the
// .rodata base plus an offset, and name them (data_ov011_02207258/725c/7260/7264, 7278.x/y/z)
// instead of a data_ov011_02207258[n] array view. With the TU's own objects func_ov011_021fff38
// keeps the ROM's load order without a volatile. The other readers (021fc0b8..021ff8fc) are cut
// off from this range by the unmatched Ov011SceneActor_Update.
extern const char *const data_ov011_02207258;
extern const fx16 data_ov011_0220726e[4];
extern const VecFx32 data_ov011_02207278;
extern char data_ov011_022078c0[];
extern char data_ov011_022078cf[];
extern char data_ov011_022078a0[];
extern char data_ov011_022078ac[];
static const char *const data_ov011_02207260 = data_ov011_022078c0;
static const char *const data_ov011_0220725c = data_ov011_022078cf;
static const char *const data_ov011_02207264 = data_ov011_022078a0;
const char *const data_ov011_02207258 = data_ov011_022078ac;
const fx16 data_ov011_0220726e[4] = {0x1800, 0x1800, 0x1800, 0x1800};
static const VecFx16 data_ov011_02207268 = {0, 0, 0};
const VecFx32 data_ov011_02207278 = {0, 0, 0};
char data_ov011_022078ac[] = "nut00";
char data_ov011_022078a0[] = "run00";
static const VecFx16 data_ov011_022078a6 = data_ov011_02207268;
static const VecFx32 data_ov011_022078b4 = data_ov011_02207278;


// ---- merged from ov011_021ffb58.cpp
namespace m_021ffb58 {

extern "C" {

extern void *data_02097e4c;
void *func_02049f44(void *a, s32 b, void *c, s32 d);
void func_ov003_021d4fd8(void *p);
void func_ov003_021d5348(void *p);

void func_ov003_021d5900(void *p);
void ActorMgr_BroadcastKind(void *mgr, u16 id, s32 c);
void EffectMgr_Kill(void *a, void *b);
extern void *data_0214a420;

static inline void Ov011_ChrKick(Ov011Scene *c, s32 v) {
    if (c->b0 && c->b2) {
        c->unk_04 = v;
        c->b2 = 0;
    }
}

static inline u32 Ov011_ChrBusy(Ov011Scene *c) {
    u32 r = 0;
    if (c->b0) {
        r = c->b2;
    }
    return r;
}

#pragma force_active on
void func_ov011_021ffb58(Ov011SceneActor *self) {
    switch (self->unk_40->state) {
    case 0:
        if (self->unk_f0_1) {
            Ov011_ChrKick(self->scene, 2);
        } else {
            Ov011_ChrKick(self->scene, 3);
        }
        self->unk_40->state = 1;
        break;
    case 1:
        if (Ov011_ChrBusy(self->scene)) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    self->unk_f4.y = 0x3e69;
}

void func_ov011_021ffc38(Ov011SceneActor *self) {
    switch (self->unk_40->state) {
    case 0:
        Ov011_ChrKick(self->scene, 4);
        self->unk_40->state = 1;
        break;
    case 1:
        if (Ov011_ChrBusy(self->scene)) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

void func_ov011_021ffcd0(Ov011SceneActor *self) {
    if (self->unk_40->state == 0) {
        Ov011Scene *c;
        Ov011Sa108 *p;
        Ov011Sa104 *o;
        self->unk_f0_0 = 0;
        c = self->scene;
        if (c->b0) {
            c->b1 = 1;
        }
        p = self->unk_108;
        p->b0 = 0;
        p->b1 = 0;
        p->unk_02 = 0;
        p->unk_04 = 0x1000;
        o = self->unk_104;
        if (o != NULL) {
            func_ov003_021da48c(o, 0);
            o->tw.v08();
            if (o->unk_38 != NULL) {
                EffectMgr_Kill(data_0214a420, o->unk_38);
                o->unk_38 = NULL;
            }
        }
        self->unk_3c->unk_14 = self->unk_64 << 1;
        self->unk_3c->unk_19 = 0xff;
        if (*self->hp == 0) {
            ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4812, 0x15);
        }
    }
    func_ov003_021d5900(self);
}

void func_ov011_021ffdd0(Ov011SceneActor *self) {
    if (self->unk_40->state == 0) {
        func_02049f44(data_02097e4c, 0x42, &self->pos, 0);
    }
    func_ov003_021d4fd8(self);
}

void func_ov011_021ffe10(Ov011SceneActor *self) {
    if (self->unk_40->state == 0) {
        func_02049f44(data_02097e4c, 0x42, &self->pos, 0);
    }
    func_ov003_021d5348(self);
}

Ov011Eff *func_02065f88(s32 id, VecFx32 *v);
void func_ov003_021d6054(void *p);
void func_ov011_021ffe50(Ov011SceneActor *self) {
    if (self->unk_40->state == 0) {
        Ov011Sa104 *o;
        Ov011V *v;
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4812, 0x15);
        o = self->unk_104;
        if (o != NULL) {
            func_ov003_021da48c(o, 0);
            o->tw.v08();
            if (o->unk_38 != NULL) {
                EffectMgr_Kill(data_0214a420, o->unk_38);
                o->unk_38 = NULL;
            }
        }
        self->unk_3c->unk_14 = self->unk_64 << 1;
        self->unk_3c->unk_19 = 0xff;
        v = func_02065f88(0x69, &self->pos);
        if (v != NULL) {
            v->v0c(0x2800);
            v->v24(0, 0x1000, 0);
        }
    }
    func_ov003_021d6054(self);
}

Ov011Eff *EffectGroup_Create(const char *arc, const char *name, const VecFx32 *pos);
Ov011Eff *func_020657b0(void *m, void *id);
void EffectMgr_StopLoop(void *m, void *id);
BOOL Ov011TwB_Start(void *self, const VecFx32 *to, const VecFx32 *from, s16 speed);

static inline void VSet_ff38(VecFx32 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void func_ov011_021fff38(Ov011SceneActor *self) {
    VecFx32 t;
    VecFx32 spawnPos;
    VecFx32 effPos;

    Ov011Sa104 *o;
    const VecFx32 *home;

    home = &data_ov011_02207278;
    t.x = data_ov011_02207278.x;
    t.y = data_ov011_02207278.y - 0x2000;
    t.z = data_ov011_02207278.z;
    o = self->unk_104;
    if (o == NULL) {
        return;
    }
    switch (o->seq.unk_13) {
    case 0:
        break;
    case 1: {
        u8 n;
        s32 v = self->unk_3c->unk_14;
        n = self->unk_3c->unk_19;
        if (n == 0xff) {
            n = 0xf;
        }
        v += FX_Mul(0x8000 - v, 0x333);
        if (n >= 0x1e) {
            n = 0x1e;
        } else {
            n++;
        }
        self->unk_3c->unk_14 = v;
        self->unk_3c->unk_19 = n;
        break;
    }
    case 2:
        if (o->seq.state == 0) {
            Ov011Eff *g;
            o->tw.v08();
            Ov011TwB_Start(&self->unk_104->tw, &t, home, 0x19a);
            self->unk_104->seq.state++;
            spawnPos = self->unk_48->unk_68;
            g = EffectGroup_Create(data_ov011_02207260, data_ov011_0220725c, &spawnPos);
            self->unk_104->unk_38 = (void *)g->unk_24;
            g->unk_c8 = -1;
        }
        if (self->unk_104->unk_38 != NULL) {
            Ov011Eff *e = func_020657b0(data_0214a420, self->unk_104->unk_38);
            if (e != NULL) {
                effPos = self->unk_48->unk_68;
                e->v18(&effPos);
            }
        }
        self->unk_94_1 = 1;
        break;
    case 3:
        if (o->seq.state == 0) {
            o->tw.v08();
            Ov011TwB_Start(&self->unk_104->tw, home, &t, 0x19a);
            self->unk_104->seq.state++;
            if (self->unk_104->unk_38 != NULL) {
                EffectMgr_StopLoop(data_0214a420, self->unk_104->unk_38);
                self->unk_104->unk_38 = NULL;
            }
            self->unk_f0_0 = 0;
        } else {
            s32 v;
            v = self->unk_3c->unk_14;
            u8 n = self->unk_3c->unk_19;
            if (n <= 0xf) {
                n = 0xf;
                if (o->tw.v14()) {
                    self->unk_104->tw.v08();
                    self->unk_94_1 = 0;
                    self->unk_104->seq.flags |= 1;
                }
            } else {
                n--;
                v += FX_Mul((self->unk_64 << 1) - v, 0x59a);
            }
            self->unk_3c->unk_14 = v;
            self->unk_3c->unk_19 = n;
        }
        break;
    }
    func_ov003_021da40c(self->unk_104);
    self->unk_104->tw.v0c();
}
#pragma force_active reset
}
}  // namespace m_021ffb58

// ---- merged from ov011_0220023c.cpp
namespace m_0220023c {
extern "C" {

void Actor_TurnToActor(void *self, void *target, s32 c);
void func_ov000_02191690(void *a);
void func_ov000_02191708(void *a);
void func_ov000_021911c8(void *a, s32 b);

#pragma force_active on
void func_ov011_0220023c(Ov011SceneActor *self) {
    void *pl;
    Ov011Param *q;
    s32 s;
    if (self->unk_108 == NULL) {
        return;
    }
    pl = func_ov000_0219bf90();
    q = self->unk_b0;
    if (q != NULL && pl != NULL && (s = self->unk_108->unk_02) != 0) {
        Actor_TurnToActor(self, pl, FX_Mul(q->unk_02, s));
    }
    if (self->unk_108->b1) {
        self->unk_ea_0 = 2;
    } else {
        self->unk_ea_0 = self->unk_b0->unk_0a_7;
    }
    if (self->unk_108->b0) {
        func_ov000_02191690(self->unk_38);
    } else {
        func_ov000_02191708(self->unk_38);
    }
    func_ov000_021911c8(self->unk_38, self->unk_108->unk_04);
}
#pragma force_active reset

struct Ov011Tbl6 {
    s32 v[6];
};

extern const Ov011Tbl6 data_ov011_022072c0;
extern void *data_02097e4c;
void func_ov000_02191618(void *a);
u16 Ov003Vec_YawTo(VecFx32 *a, VecFx32 *b);
Ov011Eff *func_02065f88(s32 id, VecFx32 *pos);
void *func_02049f44(void *mgr, s32 id, const VecFx32 *pos, s32 a);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);

static inline void Ov011_SetTw(Ov011Sa108 *q, s16 a, s16 b) {
    q->b0 = 0;
    q->b1 = 0;
    q->unk_02 = a;
    q->unk_04 = b;
}

void func_ov011_02200310(Ov011SceneActor *self) {
    Ov011Tbl6 tbl = data_ov011_022072c0;
    VecFx32 v;
    BOOL ok;
    u32 i;
    u8 st;
    Ov011Sa10c *p;
    st = self->unk_40->unk_13;
    ok = TRUE;
    for (i = 0; i < 6; i++) {
        s32 *e = &tbl.v[i];
        if (*e == st) {
            ok = FALSE;
            break;
        }
    }
    p = self->unk_10c;
    if (p == NULL || !ok) {
        return;
    }
    if (p->b0) {
        if (p->timer == 0) {
            Ov011Eff *e;
            s32 r;
            if (!p->b1) {
                Ov011_SetTw(self->unk_108, 0, 0x1000);
                p = self->unk_10c;
                p->b0 = 1;
                p->b1 = 1;
                p->b2 = 1;
                p->timer = 0x78;
                func_ov000_02190cb0(self->unk_38, data_ov011_02207264, 0x1000, 0);
                func_ov000_02191618(self->unk_38);
                self->unk_9c = 0;
                self->unk_a0 = 0;
                self->unk_a4 = 0;
                self->unk_a8 = 0;
            } else {
                Ov011_SetTw(self->unk_108, 0x1000, 0x1000);
                p = self->unk_10c;
                p->b0 = 1;
                p->b1 = 0;
                p->b2 = 1;
                p->timer = 1;
                func_ov000_02190cb0(self->unk_38, data_ov011_02207258, 0x1000, 0);
                func_ov000_021915a0(self->unk_38);
            }
            v = self->unk_b8;
            r = Ov003Vec_YawTo(&v, &self->pos);
            e = func_02065f88(0x192, &self->pos);
            e->v34(0, r, 0);
            e->v14(0x4000, 0x4000, 0x4000);
            func_02049f44(data_02097e4c, 0x32, &self->pos, 0);
        } else if (p->b1 == 1) {
            self->unk_48->unk_9a_5 = 1;
            self->unk_10c->b2 = 0;
            if (VEC_Distance(&self->pos, &self->unk_b8) < 0x4000) {
                if (self->unk_9c >= 0x200) {
                    self->unk_9c = 0x200;
                }
                self->unk_a4 = 0xf60;
            } else {
                self->unk_9c += FX_Mul(self->unk_b0->unk_00, 0xcd);
                self->unk_9c = self->unk_9c > self->unk_b0->unk_00 ? self->unk_b0->unk_00 : (self->unk_9c < 0 ? 0 : self->unk_9c);
            }
            Actor_Move((Actor *)self, 0);
            func_ov000_021987b8(self->unk_48, 1, 0, 0);
            if (self->unk_48->unk_50 & 0x40000000) {
                self->unk_9c = 0;
                self->unk_a0 = 0;
                self->unk_a4 = 0;
                self->unk_a8 = 0;
                self->unk_10c->b0 = 0;
            }
        }
        self->unk_10c->timer--;
    }
    if (!self->unk_10c->b2) {
        return;
    }
    if (func_ov000_0219bf90() == NULL) {
        return;
    }
    {
        Ov011Obj *pl = (Ov011Obj *)func_ov000_0219bf90();
        VecFx32 t;
        t = pl->pos;
        self->unk_b8 = t;
        self->unk_98 = FX_Atan2(t.x - self->pos.x, t.z - self->pos.z);
    }
}
}
}  // namespace m_0220023c

// ---- merged from ov011_0220068c.cpp
namespace m_0220068c {
// Teardown of the scene object: inlines the whole destructor of the object at
// 0x100. Past the default inline size limit MWCC calls the helpers instead.
#pragma inline_max_size(512)


extern "C" {

extern void *data_0214a420;
void EffectMgr_Kill(void *a, void *b);
void __cxa_vec_delete(void *arr, u32 size, u32 hdr, void *dtor);
void *func_ov011_021fb66c(void *self);
void func_ov003_021d7800(void *p);
void func_ov011_02201688(void *p);
void func_ov011_0220205c(void *p);
void func_ov011_02202fbc(void *p);
void func_ov011_021fa7dc(void *p);
void func_ov011_02202f04(void *p);
void *func_ov011_02201d10(void *p);
void *func_ov011_0220154c(void *p);
void *Ov011Vt_022079b0_Dtor(void *p);

static inline void Ov011B_FreeBuf(Ov011Scene *b) {
    if (b->ring.b0) {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->heapHi;
        if (b->ring.buf != NULL) {
            Heap_FreeArray(b->ring.buf);
            b->ring.buf = NULL;
        }
        data_02097dd0->cur = saved;
        b->ring.b0 = 0;
    }
}

static inline void Ov011B_FreeVec(Ov011Scene *b) {
    if (b->mgr2.b0) {
        b->mgr2.b0 = 0;
        {
            void *saved = data_02097dd0->cur;
            data_02097dd0->cur = data_02097dd0->heapHi;
            if (b->mgr2.arr8 != NULL) {
                __cxa_vec_delete(b->mgr2.arr8, 0x40, 8, func_ov011_021fb66c);
                b->mgr2.arr8 = NULL;
            }
            data_02097dd0->cur = saved;
        }
        func_ov011_0220205c(b->mgr2.unk_28);
        func_ov011_02202fbc(&b->mgr2.mov);
    }
}

static inline void Ov011B_FreeList(Ov011Scene *b) {
    if (b->ent.active) {
        if (b->ent.active) {
            Ov011PNode *p = b->ent.nodes;
            while (p != NULL) {
                Ov011PNode *next = p->next;
                if (p != NULL) {
                    Heap_Free(p);
                }
                p = next;
            }
            b->ent.nodes = NULL;
        }
        b->ent.active = 0;
    }
}

static inline void Ov011B_Free(Ov011Scene *b) {
    if (b->b0) {
        Ov011Node *p;
        Ov011Node *next;
        b->b0 = 0;
        for (p = b->head; p != NULL; p = next) {
            next = p->next;
            func_ov003_021d7800(p);
        }
        Ov011B_FreeBuf(b);
        func_ov011_02201688(&b->fx);
        Ov011B_FreeVec(b);
        if (b->s1b4.b0) {
            b->s1b4.b0 = 0;
        }
        func_ov011_021fa7dc(&b->mgr);
        Ov011B_FreeList(b);
    }
}

static inline void Ov011B_Dtor(Ov011Scene *b) {
    Ov011B_Free(b);
    Ov011B_FreeList(b);
    func_ov011_021fa7dc(&b->mgr);
    if (b->s1b4.b0) {
        b->s1b4.b0 = 0;
    }
    Ov011B_FreeVec(b);
    func_ov011_02202f04(&b->mgr2.mov);
    func_ov011_02201d10(b->mgr2.unk_28);
    func_ov011_0220154c(&b->fx);
    Ov011B_FreeBuf(b);
}

void func_ov011_0220068c(Ov011SceneActor *self) {
    Ov011Sa104 *a = self->unk_104;
    if (a != NULL) {
        func_ov003_021da48c(a, 0);
        a->tw.v08();
        if (a->unk_38 != NULL) {
            EffectMgr_Kill(data_0214a420, a->unk_38);
            a->unk_38 = NULL;
        }
    }
    if (self->unk_108 != NULL) {
        Ov011Sa108 *q = self->unk_108;
        q->b0 = 0;
        q->b1 = 0;
        q->unk_02 = 0x1000;
        q->unk_04 = 0x1000;
    }
    {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->heapHi;
        if (self->scene != NULL) {
            Ov011Scene *b = self->scene;
            if (b != NULL) {
                Ov011B_Dtor(b);
                Heap_Free(b);
            }
            self->scene = NULL;
        }
        data_02097dd0->cur = saved;
    }
    {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->heapHi;
        if (self->unk_104 != NULL) {
            Ov011Sa104 *b = self->unk_104;
            if (b != NULL) {
                Ov011Vt_022079b0_Dtor(&b->tw);
                Heap_Free(b);
            }
            self->unk_104 = NULL;
        }
        data_02097dd0->cur = saved;
    }
    {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->heapHi;
        if (self->unk_108 != NULL) {
            Heap_Free(self->unk_108);
            self->unk_108 = NULL;
        }
        data_02097dd0->cur = saved;
    }
    {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->heapHi;
        if (self->unk_10c != NULL) {
            Heap_Free(self->unk_10c);
            self->unk_10c = NULL;
        }
        data_02097dd0->cur = saved;
    }
    self->unk_f0_0 = 0;
    self->unk_f0_1 = 0;
    self->unk_f2 = 0;
    self->unk_f4.x = data_ov011_02207278.x;
    self->unk_f4.y = data_ov011_02207278.y;
    self->unk_f4.z = data_ov011_02207278.z;
    self->scene = NULL;
    self->unk_104 = NULL;
    self->unk_108 = NULL;
    self->unk_10c = NULL;
}

}
}  // namespace m_0220068c
