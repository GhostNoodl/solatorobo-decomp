#include "ov010/ov010.h" // FX32_ONE: nitro/fx.h via ov000/Vec.h
#include "ov000/ObjLayouts.h"
#include "Main/Sys/FieldState.h"
#include "nitro/mi.h"

// The zero rotation is an Ov010Ang3 (ov010.h).

// A header's zero rotation and vector, plus copies made at startup, after this TU's count and
// name pointers and among its offsets and sizes, which other functions read.
// Those functions, 0x02209190..0x0220e740 (17 files, merged in round dtB, each in its own namespace),
// are part of this TU: they read the name pointers, the rotation and the zero vector through the
// .rodata base plus an offset, and now name them (data_ov010_0220f538/f53c/f540, f544, f594)
// instead of FLD views of data_ov010_0220f534. The rotation is typed as one (it is copied into
// u16 x/y/z fields).

extern const s32 data_ov010_0220f534;
extern const VecFx32 data_ov010_0220f54c;
extern const Ov010Blk12 data_ov010_0220f558;
extern const Ov010Blk12 data_ov010_0220f564;
extern const Ov010Blk12 data_ov010_0220f570;
extern const VecFx32 data_ov010_0220f57c;
extern const Ov010Blk12 data_ov010_0220f588;
extern const VecFx32 data_ov010_0220f594;
extern char data_ov010_02210204[];
extern char data_ov010_02210210[];
extern char data_ov010_02210228[];
char data_ov010_02210210[] = "ef3di1zai03";
static const char *const data_ov010_0220f538 = data_ov010_02210228;
static const char *const data_ov010_0220f53c = data_ov010_02210210;
const VecFx32 data_ov010_0220f57c = {0x2800, 0x2800, 0x2800};
const Ov010Blk12 data_ov010_0220f558 = {0, 0x4000, -0x3000};
const s32 data_ov010_0220f534 = 4;
static const char *const data_ov010_0220f540 = data_ov010_02210204;
const Ov010Blk12 data_ov010_0220f570 = {FX32_ONE, FX32_ONE, FX32_ONE};
const Ov010Blk12 data_ov010_0220f588 = {FX32_ONE, FX32_ONE, FX32_ONE};
const VecFx32 data_ov010_0220f54c = {0, 0, FX32_ONE};
const Ov010Blk12 data_ov010_0220f564 = {0, 0x4000, -0x3000};
static const Ov010Ang3 data_ov010_0220f544 = {0, 0, 0};
char data_ov010_02210204[] = "nut00";
static const Ov010Ang3 data_ov010_0221020a = data_ov010_0220f544;
const VecFx32 data_ov010_0220f594 = {0, 0, 0};
static const VecFx32 data_ov010_0221021c = data_ov010_0220f594;

// ---- merged from ov010_02209190.cpp
namespace m_02209190 {
struct Ov010Mtx33 {
    s32 m[3][3];
};

extern "C" {

extern void MTX_RotAxis33(Ov010Mtx33 *m, const VecFx32 *v, s32 s, s32 c);
extern void MTX_MultVec33(const VecFx32 *v, const Ov010Mtx33 *m, VecFx32 *o);
extern void VEC_Normalize(const VecFx32 *src, VecFx32 *dst);
extern u16 Ov003Vec_Yaw(VecFx32 *v);

u16 func_ov010_02209190(s32 type, const s32 *rect, const VecFx32 *c, const VecFx32 *p, u16 ang) {
    VecFx32 v;
    VecFx32 a;
    Ov010Mtx33 m;
    OV010_BLKCPY(&v, &data_ov010_0220f594);
    switch (type) {
    case 0:
        if (p->x < rect[0]) {
            v.x = 0x1000;
        } else if (rect[2] < p->x) {
            v.x = -0x1000;
        }
        if (p->z < rect[1]) {
            v.z = 0x1000;
        } else if (rect[3] < p->z) {
            v.z = -0x1000;
        }
        break;
    case 1:
        v.x = c->x - p->x;
        v.y = c->y - p->y;
        v.z = c->z - p->z;
        VEC_Normalize(&v, &v);
        break;
    }
    func_ov003_021d9980(&a, ang + 0x7fff, (VecFx32 *)&data_ov010_0220f54c);
    MTX_RotAxis33(&m, &v, OV010_SIN(0x7ff0), OV010_COS(0x7ff0));
    MTX_MultVec33(&a, &m, &a);
    return Ov003Vec_Yaw(&a);
}

}
}  // namespace m_02209190

// ---- merged from ov010_022092c8.cpp
namespace m_022092c8 {
struct Ov010Trig {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_05;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    s32 unk_0c;
};

extern "C" {

extern u8 data_ov010_02210280[];
extern void *History_Init(void *p);

Ov010Trig *Ov010Vt_02210280_Ctor(Ov010Trig *self) {
    self->vtbl = data_ov010_02210280;
    History_Init((u8 *)self + 0x1c);
    self->b0 = 0;
    self->b1 = 0;
    return self;
}

struct Obj02209300 : public Ov010Trig {
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    u16 unk_1c;
};

void *Ov010Vt_02210280_Dtor(Obj02209300 *self) {
    self->vtbl = data_ov010_02210280;
    ((VObj *)self)->vfunc_0c();
    return self;
}

void *Ov010Vt_02210280_DtorDelete(Obj02209300 *self) {
    self->vtbl = data_ov010_02210280;
    ((VObj *)self)->vfunc_0c();
    Heap_Free(self);
    return self;
}

BOOL func_ov010_02209358(Obj02209300 *self, s32 a) {
    self->unk_0c = a;
    self->b0 = 1;
    self->unk_0a = 0xffff;
    func_ov003_021da48c((u8 *)self + 0x1c, 0);
    return TRUE;
}

void func_ov010_02209390(Obj02209300 *self) {
    if (self->b0) {
        self->b0 = 0;
        self->b1 = 0;
    }
}

extern void *data_ov000_021ccd68;
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void func_ov010_0220dbc0(s32 p);
extern u16 *func_ov010_0220da74(s32 p, VecFx32 *pos, s32 b, s32 c, s32 d, u16 e, u16 f);

static inline Actor *Ov010_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline void Ov010_Activate(Obj0220a6b0 *a) {
    if (a->state == 1) {
        return;
    }
    if (!a->unk_ce.b0) {
        a->unk_ce.b0 = 1;
        a->unk_ce.b2 = 1;
        func_ov003_021da48c(&a->fsmA, 2);
    }
}

void func_ov010_022093b0(Obj02209300 *self) {
    Actor *a;
    if (!self->b0) {
        return;
    }
    switch (self->unk_1c) {
    case 0: {
        VecFx32 p;
        func_ov010_0220dbc0(self->unk_0c);
        a = Ov010_FindActor(self->unk_06);
        if (a == NULL) {
            self->unk_1c = 3;
            return;
        }
        p = a->pos;
        self->unk_0a = *func_ov010_0220da74(self->unk_0c, &p, self->unk_18, self->unk_10, self->unk_14, self->unk_06, self->unk_08);
        self->unk_1c = 1;
        break;
    }
    case 1:
        a = Ov010_FindActor(self->unk_0a);
        if (a == NULL) {
            self->unk_1c = 3;
            return;
        }
        if (a->state == 1) {
            return;
        }
        Ov010_Activate(static_cast<Obj0220a6b0 *>(a));
        self->unk_1c = 2;
        break;
    case 2:
        a = Ov010_FindActor(self->unk_0a);
        if (a != NULL && static_cast<Obj0220a6b0 *>(a)->unk_ce.b0) {
            return;
        }
        self->unk_1c = 3;
        break;
    case 3:
        ((VObj *)self)->vfunc_0c();
        break;
    }
}

}
}  // namespace m_022092c8

// ---- merged from ov010_02209568.cpp
namespace m_02209568 {
struct Ov010Trig {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_05;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    s32 unk_0c;
    const s32 *unk_10;     // area rectangle (func_ov010_0220a948)
    const VecFx32 *unk_14; // area circle
    s32 unk_18;
    s32 unk_1c;
};

struct Ov010IdNode {
    u16 id;
    Ov010IdNode *next;
};

struct Ov010IdList {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 count;
    u16 ids[0x11];
    Ov010IdNode *head;
};

// The trigger with vtable data_ov010_022102c0: started with a list of 0x4817 actors (func_ov010_02209638);
// func_ov010_02209684 starts fsmB of the first listed actor whose unk_d8 is 1.
struct Ov010Trig022102c0 {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_05;
    u16 unk_06; // id of the actor whose heading turns the offset
    Ov010IdList *list;
    ActorSub40 sm;
};

extern "C" {

extern u8 data_ov010_022102c0[];
extern void *History_Init(void *p);

BOOL func_ov010_02209568(Ov010Trig *self) {
    return self->b0;
}

void func_ov010_02209578(Ov010Trig *self, s32 a, const s32 *b, const VecFx32 *c, u16 d, u16 e) {
    self->b1 = 1;
    self->unk_18 = a;
    self->unk_10 = b;
    self->unk_14 = c;
    self->unk_06 = d;
    self->unk_08 = e;
}

Ov010Trig022102c0 *Ov010Vt_022102c0_Ctor(Ov010Trig022102c0 *self) {
    self->vtbl = data_ov010_022102c0;
    History_Init(&self->sm);
    self->b0 = 0;
    self->b1 = 0;
    return self;
}

void *Ov010Vt_022102c0_Dtor(Ov010Trig022102c0 *self) {
    self->vtbl = data_ov010_022102c0;
    ((VObj *)self)->vfunc_0c();
    return self;
}

void *Ov010Vt_022102c0_DtorDelete(Ov010Trig022102c0 *self) {
    self->vtbl = data_ov010_022102c0;
    ((VObj *)self)->vfunc_0c();
    Heap_Free(self);
    return self;
}

BOOL func_ov010_02209638(Ov010Trig022102c0 *self, Ov010IdList *a) {
    self->list = a;
    self->b0 = 1;
    func_ov003_021da48c(&self->sm, 0);
    return TRUE;
}

void func_ov010_02209664(Ov010Trig022102c0 *self) {
    if (self->b0) {
        self->b0 = 0;
        self->b1 = 0;
    }
}

extern void *data_ov000_021ccd68;
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);

static inline Actor *Ov010_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void func_ov010_02209684(Ov010Trig022102c0 *self) {
    if (!self->b0) {
        return;
    }
    switch (self->sm.st) {
    case 0: {
        Ov010IdList *l = self->list;
        u16 id;
        Obj0220a6b0 *a;
        Actor *s;
        if (l->b0) {
            Ov010IdNode *n;
            l->count = 0;
            for (n = l->head; n != NULL; n = n->next) {
                Obj0220a6b0 *e = static_cast<Obj0220a6b0 *>(Ov010_FindActor(n->id));
                if (e != NULL && e->unk_d8 == 1) {
                    l->ids[l->count] = n->id;
                    l->count++;
                }
            }
        }
        l = self->list;
        id = 0xffff;
        if (l->b0 && (s32)l->count > 0) {
            id = l->ids[0];
        }
        a = static_cast<Obj0220a6b0 *>(Ov010_FindActor(id));
        s = Ov010_FindActor(self->unk_06);
        if (a != NULL) {
            Ov010Blk12 t = data_ov010_0220f558;
            VecFx32 v;
            func_ov003_021d9980(&v, s->rot_y, (VecFx32 *)&t);
            if (a->state != 1 && !a->unk_ce.b1) {
                a->unk_ce.b1 = 1;
                func_ov003_021da48c(&a->fsmB, 1);
                Ov010_VecCopy(&a->unk_fc, &v);
            }
        }
        self->sm.st = 1;
        break;
    }
    case 1:
        ((VObj *)self)->vfunc_0c();
        break;
    }
}

}
}  // namespace m_02209568

// ---- merged from ov010_0220983c.cpp
namespace m_0220983c {
struct Ov010Trig {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_05;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    u16 unk_0c;
    u16 unk_0e;
    s32 unk_10;
};

extern "C" {

extern u8 data_ov010_022102a0[];
extern void *History_Init(void *p);

BOOL func_ov010_0220983c(Ov010Trig *self) {
    return self->b0;
}

void func_ov010_0220984c(Ov010Trig *self, u16 a) {
    self->unk_06 = a;
    self->b1 = 1;
}

Ov010Trig *Ov010Vt_022102a0_Ctor(Ov010Trig *self) {
    self->vtbl = data_ov010_022102a0;
    History_Init((u8 *)self + 0x20);
    self->b0 = 0;
    self->b1 = 0;
    return self;
}

struct Obj02209898 {
    void *unk_00;
};

void *Ov010Vt_022102a0_Dtor(Obj02209898 *self) {
    self->unk_00 = data_ov010_022102a0;
    ((VObj *)self)->vfunc_0c();
    return self;
}

void *Ov010Vt_022102a0_DtorDelete(Obj02209898 *self) {
    self->unk_00 = data_ov010_022102a0;
    ((VObj *)self)->vfunc_0c();
    Heap_Free(self);
    return self;
}
BOOL func_ov010_022098f0(Ov010Trig *self, s32 a) {
    self->b0 = 1;
    self->unk_0c = 0;
    self->unk_10 = a;
    self->unk_0e = 0;
    func_ov003_021da48c((u8 *)self + 0x20, 0);
    return TRUE;
}

}
}  // namespace m_0220983c

// ---- merged from ov010_02209928.cpp
namespace m_02209928 {
struct Ov010Trig {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_05;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    u16 unk_0c;
    u16 unk_0e;
    s32 unk_10;
};

extern "C" {

extern u8 data_ov010_022102a0[];
extern void *History_Init(void *p);

void func_ov010_02209928(Ov010Trig *self) {
    if (self->b0) {
        self->b0 = 0;
        self->b1 = 0;
    }
}

}
}  // namespace m_02209928

// ---- merged from ov010_02209948.cpp
namespace m_02209948 {
struct Ov010IdNode {
    u16 id;
    Ov010IdNode *next;
};

struct Ov010IdList {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 count;
    u16 ids[0x11];
    Ov010IdNode *head;
};

struct Ov010Wave {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_05;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    u16 unk_0c;
    u16 unk_0e;
    Ov010IdList *list;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    u16 state;
    u16 timer;
};

extern "C" {

extern void *data_ov000_021ccd68;
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void func_ov010_0220dbc0(Ov010IdList *l);
extern u16 *func_ov010_0220da74(Ov010IdList *l, VecFx32 *pos, s32 b, s32 c, s32 d, u16 e, u16 f);

static inline Actor *Ov010w_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline u8 Ov010w_Count(Ov010IdList *l) {
    u8 c = 0;
    if (l->b0) {
        c = l->count;
    }
    return c;
}

static inline u16 Ov010w_Get(Ov010IdList *l, s32 i) {
    u16 id = 0xffff;
    if (l->b0 && i >= 0 && i < l->count) {
        id = l->ids[i];
    }
    return id;
}

static inline BOOL Ov010w_IsActive(Obj0220a6b0 *a) {
    BOOL r = FALSE;
    if (a != NULL) {
        s32 k = a->unk_d8;
        r = (u32)(k - 1) <= 2;
    }
    return r;
}
static inline void Ov010w_Collect(Ov010IdList *l) {
    if (l->b0) {
        Ov010IdNode *n;
        l->count = 0;
        for (n = l->head; n != NULL; n = n->next) {
            if (Ov010w_IsActive(static_cast<Obj0220a6b0 *>(Ov010w_FindActor(n->id))) == TRUE) {
                l->ids[l->count] = n->id;
                l->count++;
            }
        }
    }
}

static inline void Ov010w_StartAll(Ov010Wave *self) {
    s32 i;
    for (i = 0; i < Ov010w_Count(self->list); i++) {
        Obj0220a6b0 *a = static_cast<Obj0220a6b0 *>(Ov010w_FindActor(Ov010w_Get(self->list, i)));
        if (a != NULL && a->state != 1 && !a->unk_ce.b0) {
            a->unk_ce.b0 = 1;
            a->unk_ce.b2 = 1;
            func_ov003_021da48c(&a->fsmA, 3);
        }
    }
}

static inline BOOL Ov010w_Tick(Ov010Wave *self) {
    return self->timer % (0x19 / (self->unk_0a - 1)) == 0;
}
static inline BOOL Ov010w_Last(Ov010Wave *self) {
    BOOL r = TRUE;
    if (self->unk_0c != self->unk_0a) {
        r = FALSE;
    }
    return r;
}
void func_ov010_02209948(Ov010Wave *self) {
    BOOL ok;
    if (!self->b0) {
        return;
    }
    switch (self->state) {
    case 0: {
        Actor *a;
        VecFx32 p;
        s32 i;
        func_ov010_0220dbc0(self->list);
        a = Ov010w_FindActor(self->unk_06);
        if (a == NULL) {
            self->state = 0x70;
            return;
        }
        p = a->pos;
        for (i = 0; i < self->unk_0a; i++) {
            func_ov010_0220da74(self->list, &p, self->unk_1c, self->unk_14, self->unk_18, self->unk_06, self->unk_08);
        }
        self->state = 0x10;
        break;
    }
    case 0x10: {
        Ov010IdList *l = self->list;
        s32 i;
        ok = TRUE;
        if (l->b0) {
            Ov010IdNode *n;
            l->count = 0;
            for (n = l->head; n != NULL; n = n->next) {
                Ov010w_FindActor(n->id);
                l->ids[l->count] = n->id;
                l->count++;
            }
        }
        for (i = 0; i < Ov010w_Count(self->list); i++) {
            Actor *a = Ov010w_FindActor(Ov010w_Get(self->list, i));
            if (a != NULL && a->state == 1) {
                ok = FALSE;
                break;
            }
        }
        if (ok) {
            self->state = 0x20;
        }
        break;
    }
    case 0x20: {
        BOOL last = Ov010w_Last(self);
        BOOL tick = Ov010w_Tick(self);
        if (last) {
            self->timer = 0;
            self->state = 0x30;
        } else if (tick) {
            Ov010IdList *l = self->list;
            Obj0220a6b0 *a;
            Actor *s;
            u16 idx;
            BOOL more;
            if (l->b0) {
                Ov010IdNode *n;
                l->count = 0;
                for (n = l->head; n != NULL; n = n->next) {
                    Obj0220a6b0 *e = static_cast<Obj0220a6b0 *>(Ov010w_FindActor(n->id));
                    if (e != NULL && e->unk_d8 == 1) {
                        l->ids[l->count] = n->id;
                        l->count++;
                    }
                }
            }
            a = static_cast<Obj0220a6b0 *>(Ov010w_FindActor(Ov010w_Get(self->list, 0)));
            idx = self->unk_0c;
            more = idx < self->unk_0a;
            s = Ov010w_FindActor(self->unk_06);
            if (a != NULL && a->state != 1 && s != NULL && more) {
                s32 q = 0x2000 / (self->unk_0a - 1);
                VecFx32 v;
                Ov010Blk12 t = data_ov010_0220f564;
                t.w[0] = q * idx - 0x1000;
                func_ov003_021d9980(&v, s->rot_y, (VecFx32 *)&t);
                if (a->state != 1 && !a->unk_ce.b1) {
                    a->unk_ce.b1 = 1;
                    func_ov003_021da48c(&a->fsmB, 2);
                    Ov010_VecCopy(&a->unk_fc, &v);
                }
            }
            self->unk_0c++;
        }
        self->timer++;
        break;
    }
    case 0x30:
        self->timer++;
        if (self->timer > 0x41) {
            self->timer = 0;
            self->state = 0x40;
        }
        break;
    case 0x40:
        Ov010w_Collect(self->list);
        Ov010w_StartAll(self);
        self->state = 0x41;
        break;
    case 0x41: {
        BOOL ok = TRUE;
        Ov010w_Collect(self->list);
        {
            s32 i;
            for (i = 0; i < Ov010w_Count(self->list); i++) {
                Obj0220a6b0 *a = static_cast<Obj0220a6b0 *>(Ov010w_FindActor(Ov010w_Get(self->list, i)));
                if (a != NULL && a->unk_ce.b0) {
                    ok = FALSE;
                    break;
                }
            }
            if (ok) {
                self->state = 0x70;
            }
        }
        break;
    }
    case 0x70:
        ((VObj *)self)->vfunc_0c();
        break;
    }
}

}
}  // namespace m_02209948

// ---- merged from ov010_0220a030.cpp
struct Obj0220a090 {
    void *unk_00;
    u8 unk_04;
};

namespace m_0220a030 {
struct Ov010Trig {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_05;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    s32 unk_0c;
    s32 unk_10;
    const s32 *unk_14;     // area rectangle (func_ov010_0220a948)
    const VecFx32 *unk_18; // area circle
    s32 unk_1c;
};

struct Ov010Tmr {
    void *vtbl;
    u8 on;
    u8 unk_05;
    u16 unk_06;
    s32 unk_08;
};
SIZE_ASSERT(Ov010Tmr, 0xc);

struct Ov010IdNode {
    u16 id;
    Ov010IdNode *next;
};

struct Ov010IdList {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 count;
    u16 ids[0x10];
    Ov010IdNode *head;
};

struct Ov010TblF534 {
    u8 unk_00[0x60];
    VecFx32 v60;
};

extern "C" {

extern u8 data_ov010_02210260[];

BOOL func_ov010_0220a030(Ov010Trig *self) {
    return self->b0;
}

void func_ov010_0220a040(Ov010Trig *self, u16 a, s32 b, const s32 *c, const VecFx32 *d, u16 e, u16 f) {
    self->b1 = 1;
    self->unk_0a = a;
    self->unk_1c = b;
    self->unk_14 = c;
    self->unk_18 = d;
    self->unk_06 = e;
    self->unk_08 = f;
}

Ov010Tmr *Ov010Vt_02210260_Ctor(Ov010Tmr *self) {
    self->vtbl = data_ov010_02210260;
    self->on = 0;
    return self;
}

void *Ov010Vt_02210260_Dtor(Obj0220a090 *self) {
    self->unk_00 = data_ov010_02210260;
    ((VObj *)self)->vfunc_0c();
    return self;
}

void *Ov010Vt_02210260_DtorDelete(Obj0220a090 *self) {
    self->unk_00 = data_ov010_02210260;
    ((VObj *)self)->vfunc_0c();
    Heap_Free(self);
    return self;
}

BOOL func_ov010_0220a0e8(Ov010Tmr *self, s32 a) {
    self->on = 1;
    self->unk_06 = 0;
    self->unk_08 = a;
    return 1;
}

void func_ov010_0220a104(Ov010Tmr *self) {
    if (self->on) {
        self->on = 0;
    }
}


extern void *data_ov000_021ccd68;
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);

static inline Actor *Ov010_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline u8 Ov010IdList_Count(Ov010IdList *l) {
    u8 c = 0;
    if (l->b0) {
        c = l->count;
    }
    return c;
}

static inline u16 Ov010IdList_Get(Ov010IdList *l, s32 i) {
    u16 id = 0xffff;
    if (l->b0 && i < l->count) {
        id = l->ids[i];
    }
    return id;
}

void func_ov010_0220a118(Ov010Tmr *self) {
    Ov010IdList *l;
    if (!self->on) {
        return;
    }
    l = (Ov010IdList *)self->unk_08;
    if (l->b0) {
        Ov010IdNode *n;
        l->count = 0;
        for (n = l->head; n != NULL; n = n->next) {
            Obj0220a6b0 *a = static_cast<Obj0220a6b0 *>(Ov010_FindActor(n->id));
            if (a != NULL && a->unk_d8 == 2) {
                l->ids[l->count] = n->id;
                l->count++;
            }
        }
    }
    l = (Ov010IdList *)self->unk_08;
    if (Ov010IdList_Count(l) == 0) {
        ((VObj *)self)->vfunc_0c();
    } else if (self->unk_06 % 3 == 0) {
        Obj0220a6b0 *a = static_cast<Obj0220a6b0 *>(Ov010_FindActor(Ov010IdList_Get(l, 0)));
        if (a != NULL && a->state != 1 && !a->unk_ce.b1) {
            a->unk_ce.b1 = 1;
            func_ov003_021da48c(&a->fsmB, 3);
            Ov010_VecCopy(&a->unk_fc, &data_ov010_0220f594);
        }
    }
    self->unk_06++;
}
}
}  // namespace m_0220a030

// ---- merged from ov010_0220a2a0.cpp
struct Obj0220a2d8 {
    void *unk_00;
    Ov010Flags8 unk_04;
};

namespace m_0220a2a0 {
struct Ov010Trig {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_05;
    u16 unk_06;
    s32 unk_08;
};

typedef struct Ov010CNode Ov010CNode;

struct Ov010CNode {
    u16 id;
    u16 unk_02;
    Ov010CNode *next;
};

struct Ov010CColl {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 count;
    u16 ids[0x11];
    Ov010CNode *list;
    void *handler;
    u8 pool[1];
};

struct Ov010Trig2 {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_05;
    u16 unk_06;
    Ov010CColl *coll;
    u16 state;
};

extern "C" {

extern u8 data_ov010_02210240[];
extern void *History_Init(void *p);

u8 func_ov010_0220a2a0(Obj0220a090 *self) {
    return self->unk_04;
}

Ov010Trig *Ov010Vt_02210240_Ctor(Ov010Trig *self) {
    self->vtbl = data_ov010_02210240;
    History_Init((u8 *)self + 0xc);
    self->b0 = 0;
    return self;
}

void *Ov010Vt_02210240_Dtor(Obj0220a2d8 *self) {
    self->unk_00 = data_ov010_02210240;
    ((VObj *)self)->vfunc_0c();
    return self;
}

void *Ov010Vt_02210240_DtorDelete(Obj0220a2d8 *self) {
    self->unk_00 = data_ov010_02210240;
    ((VObj *)self)->vfunc_0c();
    Heap_Free(self);
    return self;
}

BOOL func_ov010_0220a330(Ov010Trig *self, s32 a) {
    self->unk_08 = a;
    self->b0 = 1;
    func_ov003_021da48c((u8 *)self + 0xc, 0);
    return TRUE;
}

void func_ov010_0220a35c(Ov010Trig *self) {
    if (self->b0) {
        self->b0 = 0;
    }
}


extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void Actor_SendMsg(void *obj, u16 id, s32 a, s32 b, s32 c, u8 *d);
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
extern Ov010CNode *func_ov010_0220db74(Ov010CNode *head, Ov010CNode *node);
extern void Ov003Pool_Free(void *p, Ov010CNode *n);

static inline Actor *Ov010t_Find(u16 id) {
    if (data_ov000_021ccd68 != NULL) {
        return ActorMgr_GetActor(data_ov000_021ccd68, id);
    }
    return NULL;
}

static inline void Ov010t_Collect(Ov010CColl *c) {
    Ov010CNode *n;
    if (c->b0) {
        c->count = 0;
        for (n = c->list; n != NULL; n = n->next) {
            Ov010t_Find(n->id);
            c->ids[c->count] = n->id;
            c->count++;
        }
    }
}

static inline long Ov010t_Count(Ov010CColl *c) {
    u8 r = 0;
    if (c->b0) {
        r = c->count;
    }
    return r;
}

static inline u16 Ov010t_Id(Ov010CColl *c, s32 i) {
    u16 r = 0xffff;
    if (c->b0 && i >= 0 && i < c->count) {
        r = c->ids[i];
    }
    return r;
}

static inline void Ov010t_Remove(Ov010CColl *c, u16 id) {
    Ov010CNode *n;
    if (c->b0) {
        for (n = c->list; n != NULL; n = n->next) {
            if (n->id == id) {
                if (c->b0 && n != NULL) {
                    void *o = Ov010t_Find(n->id);
                    if (o != NULL) {
                        ((VObj *)o)->vfunc_08();
                    }
                    c->list = func_ov010_0220db74(c->list, n);
                    Ov003Pool_Free(c->pool, n);
                }
                return;
            }
        }
    }
}

void func_ov010_0220a374(Ov010Trig2 *self) {
    BOOL done;
    s32 i;
    if (!self->b0) {
        return;
    }
    switch (self->state) {
    case 0:
        done = FALSE;
        Ov010t_Collect(self->coll);
        for (i = 0; i < Ov010t_Count(self->coll); i++) {
            Obj0220a6b0 *obj = static_cast<Obj0220a6b0 *>(Ov010t_Find(Ov010t_Id(self->coll, i)));
            if (obj != NULL) {
                s32 kind = obj->unk_d8;
                BOOL a = kind == 6 ? TRUE : FALSE;
                BOOL b = kind == 8 ? TRUE : FALSE;
                BOOL c = kind == 5 ? TRUE : FALSE;
                if (a || b || c) {
                    u8 f = 0;
                    Actor_SendMsg(obj, 0xffff, 0xe, 1, 1, &f);
                } else if (kind == 7) {
                    if (!done) {
                        u8 f = 2;
                        VecFx32 p;
                        done = TRUE;
                        Actor_SendMsg(obj, 0xffff, 0xe, 1, 1, &f);
                        p = obj->pos;
                        func_02049f44(data_02097e4c, 0x77, &p, 0);
                    }
                } else {
                    Ov010t_Remove(self->coll, obj->id);
                }
            }
        }
        self->state = 1;
        break;
    case 1:
        Ov010t_Collect(self->coll);
        if (Ov010t_Count(self->coll) == 0) {
            ((VObj *)self)->vfunc_0c();
        }
        break;
    }
}

}
}  // namespace m_0220a2a0

// ---- merged from ov010_0220a6a0.cpp
// Obj0220a6b0 (the 0x4817 actor) is in ov010.h.

namespace m_0220a6a0 {
extern "C" {

extern u8 data_ov010_02210378[];
extern void *Ov003Vt_021f7d2c_Ctor(void *p);
extern void *History_Init(void *p);
extern void func_ov010_0220c49c(Obj0220a6b0 *self);

BOOL func_ov010_0220a6a0(Obj0220a2d8 *self) {
    return self->unk_04.b0;
}

void *Ov010ActVt_02210378_Ctor(Obj0220a6b0 *self) {
    ActorEx_Ctor((ActorEx *)self);
    *(void * *)self = data_ov010_02210378;
    Ov003Vt_021f7d2c_Ctor(&self->mover);
    History_Init(&self->fsmA);
    History_Init(&self->fsmB);
    func_ov010_0220c49c(self);
    return self;
}


extern u8 data_ov010_02210378[];
extern void *Ov003Vt_021f7d2c_Dtor(void *p);
extern void func_ov010_0220c49c(Obj0220a6b0 *self);

static inline void Ov010FxA_Dtor(Ov010Trail *p) {
    if (p->b0) {
        EffectMgr_Kill(data_0214a420, p->key);
        p->b0 = 0;
    }
}

static inline void Ov010FxB_Dtor(Ov010Path *p) {
    if (p->b0) {
        EffectMgr_Kill(data_0214a420, p->fxHandle);
        p->fxHandle = 0;
        p->b0 = 0;
    }
}

static inline void Ov010_FreeFxA(Obj0220a6b0 *self) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->trail != NULL) {
        Ov010Trail *p = self->trail;
        if (p != NULL) {
            Ov010FxA_Dtor(p);
            Heap_Free(p);
        }
        self->trail = NULL;
    }
    data_02097dd0->cur = saved;
}

static inline void Ov010_FreeFxB(Obj0220a6b0 *self) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->path != NULL) {
        Ov010Path *p = self->path;
        if (p != NULL) {
            Ov010FxB_Dtor(p);
            Heap_Free(p);
        }
        self->path = NULL;
    }
    data_02097dd0->cur = saved;
}

static inline void Ov010Boss_Dtor(Obj0220a6b0 *self) {
    *(void * *)self = data_ov010_02210378;
    Ov010_FreeFxA(self);
    Ov010_FreeFxB(self);
    self->mover.vfunc_08();
    func_ov010_0220c49c(self);
    Ov003Vt_021f7d2c_Dtor(&self->mover);
    func_ov000_0219429c((ActorEx *)self);
}

void *Ov010ActVt_02210378_Dtor(Obj0220a6b0 *self) {
    Ov010Boss_Dtor(self);
    return self;
}

void *Ov010ActVt_02210378_DtorDelete(Obj0220a6b0 *self) {
    Ov010Boss_Dtor(self);
    Heap_Free(self);
    return self;
}
}
}  // namespace m_0220a6a0

// ---- merged from ov010_0220a948.cpp
namespace m_0220a948 {
extern "C" {

static inline void Ov010_0220a948_Set(Obj0220a6b0 *self, u16 c, u16 d, s32 mode, s32 *a, VecFx32 *b) {
    self->unk_d0 = c;
    self->unk_d2 = d;
    self->unk_dc = mode;
    self->unk_e0 = a;
    self->unk_e4 = b;
}

void func_ov010_0220a948(Obj0220a6b0 *self, s32 mode, s32 *a, VecFx32 *b, u16 c, u16 d) {
    switch (mode) {
    case 0:
        Ov010_0220a948_Set(self, c, d, mode, a, NULL);
        break;
    case 1:
        Ov010_0220a948_Set(self, c, d, mode, NULL, b);
        break;
    }
}


struct Ov010Mtx33a {
    s32 m[9];
};

extern void *data_ov000_021ccd68;
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void MTX_Identity33_(Ov010Mtx33a *m);
extern void MTX_RotX33_(Ov010Mtx33a *m, s32 s, s32 c);
extern void MTX_RotY33_(Ov010Mtx33a *m, s32 s, s32 c);
extern void MTX_RotZ33_(Ov010Mtx33a *m, s32 s, s32 c);
extern void MTX_Concat33(Ov010Mtx33a *a, Ov010Mtx33a *b, Ov010Mtx33a *out);

void Ov010ActVt_02210378_Draw(Obj0220a6b0 *self) {
    Ov010Mtx33a out;
    Ov010Mtx33a tc;
    Ov010Mtx33a ma;
    Ov010Mtx33a mb;
    Ov010Mtx33a ta;
    Ov010Mtx33a tb;
    Actor *o;
    self->unk_93_0 = 1;
    o = NULL;
    if (self->unk_d8 == 7) {
        void *mgr = data_ov000_021ccd68;
        u16 id = self->unk_180;
        if (mgr != NULL) {
            o = ActorMgr_GetActor(mgr, id);
        }
    }
    if (o != NULL) {
        BOOL set2;
        BOOL set;
        u16 dz;
        u16 az;
        u16 ay;
        u16 ax;
        u16 dx;
        u16 dy;
        dx = o->rot_x - self->unk_190.x;
        dy = o->rot_y - self->unk_190.y;
        dz = o->rot_z - self->unk_190.z;
        az = self->unk_196.z;
        ay = self->unk_196.y;
        ax = self->unk_196.x;
        set = FALSE;
        MTX_Identity33_(&ma);
        if (az != 0) {
            MTX_RotZ33_(&ma, OV010_SIN(az), OV010_COS(az));
            set = TRUE;
        }
        if (ay != 0) {
            if (set) {
                MTX_RotY33_(&ta, OV010_SIN(ay), OV010_COS(ay));
                MTX_Concat33(&ta, &ma, &ma);
            } else {
                MTX_RotY33_(&ma, OV010_SIN(ay), OV010_COS(ay));
                set = TRUE;
            }
        }
        if (ax != 0) {
            if (set) {
                MTX_RotX33_(&ta, OV010_SIN(ax), OV010_COS(ax));
                MTX_Concat33(&ta, &ma, &ma);
            } else {
                MTX_RotX33_(&ma, OV010_SIN(ax), OV010_COS(ax));
                set = TRUE;
            }
        }
        set2 = FALSE;
        MTX_Identity33_(&mb);
        if (dz != 0) {
            MTX_RotZ33_(&mb, OV010_SIN(dz), OV010_COS(dz));
            set2 = TRUE;
        }
        if (dy != 0) {
            if (set2) {
                MTX_RotY33_(&tb, OV010_SIN(dy), OV010_COS(dy));
                MTX_Concat33(&tb, &mb, &mb);
            } else {
                MTX_RotY33_(&mb, OV010_SIN(dy), OV010_COS(dy));
                set2 = TRUE;
            }
        }
        if (dx != 0) {
            if (set2) {
                MTX_RotX33_(&tb, OV010_SIN(dx), OV010_COS(dx));
                MTX_Concat33(&tb, &mb, &mb);
            } else {
                MTX_RotX33_(&mb, OV010_SIN(dx), OV010_COS(dx));
                set2 = TRUE;
            }
        }
        MTX_Concat33(&ma, &mb, &out);
    } else {
        u16 rx;
        u16 ry;
        u16 rz;
        BOOL set;
        rz = self->rot_z;
        ry = self->rot_y;
        rx = self->rot_x;
        set = FALSE;
        MTX_Identity33_(&out);
        if (rz != 0) {
            MTX_RotZ33_(&out, OV010_SIN(rz), OV010_COS(rz));
            set = TRUE;
        }
        if (ry != 0) {
            if (set) {
                MTX_RotY33_(&tc, OV010_SIN(ry), OV010_COS(ry));
                MTX_Concat33(&tc, &out, &out);
            } else {
                MTX_RotY33_(&out, OV010_SIN(ry), OV010_COS(ry));
                set = TRUE;
            }
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX33_(&tc, OV010_SIN(rx), OV010_COS(rx));
                MTX_Concat33(&tc, &out, &out);
            } else {
                MTX_RotX33_(&out, OV010_SIN(rx), OV010_COS(rx));
                set = TRUE;
            }
        }
    }
    MI_Copy36B(&out, &self->model->rot);
    {
        Model0218fe1c *m = self->model;
        m->trans.x = self->pos.x;
        m->trans.y = self->pos.y;
        m->trans.z = self->pos.z;
    }
    func_ov000_02194c08((ActorEx *)self);
}

}
}  // namespace m_0220a948

// ---- merged from ov010_0220adb8.cpp
namespace m_0220adb8 {
extern "C" {
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);

static inline void Ov010FxB_Stop(Ov010Path *p) {
    if (p->b0) {
        EffectMgr_StopLoop(data_0214a420, p->fxHandle);
        p->fxHandle = 0;
        func_ov000_02198360(&p->sm, 1, 0);
    }
}

static inline void Ov010FxB_Start(Ov010Path *p) {
    if (p->b0) {
        p->timer = 0;
        p->duration = 0x50;
        func_ov003_021da48c(&p->sm, 2);
    }
}

BOOL func_ov010_0220adb8(Obj0220a6b0 *self, ActorMsg *msg) {
    BOOL r;
    if (msg->type == 0xe) {
        switch (msg->unk_08) {
        case 4:
            self->unk_ce.b3 = 1;
            if (self->unk_d8 == 7) {
                break;
            }
        case 1:
            func_ov000_02198360(self->fsm, 0x15, 0);
            break;
        case 0:
            Ov010FxB_Stop(self->path);
            Ov010FxB_Start(self->path);
            break;
        case 2:
            func_ov000_02198360(self->fsm, 6, 0);
            break;
        case 3:
            func_ov000_02198360(self->fsm, 0x12, 0);
            break;
        }
        r = TRUE;
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
    } else {
        r = func_ov000_021950e8((ActorEx *)self, msg);
    }
    return r;
}

extern void *History_Init(void *p);
extern void func_0203f364(void *p);

static inline Ov010Trail *Ov010FxA_New(void) {
    Ov010Trail *p = (Ov010Trail *)Heap_Alloc(sizeof(Ov010Trail));
    if (p != NULL) {
        History_Init(&p->st);
        p->b0 = 0;
    }
    return p;
}

static inline Ov010Path *Ov010FxB_New(void) {
    Ov010Path *p = (Ov010Path *)Heap_Alloc(sizeof(Ov010Path));
    if (p != NULL) {
        History_Init(&p->sm);
        p->b0 = 0;
    }
    return p;
}

void Ov010ActVt_02210378_Start(Obj0220a6b0 *self) {
    Ov010Trail *p;
    func_ov000_02194758((ActorEx *)self);
    func_ov000_02198360(self->fsm, 1, 0);
    func_ov000_02198360(&self->fsmA, 1, 0);
    self->unk_d8 = 1;
    self->trail = p = Ov010FxA_New();
    p->b0 = 1;
    p->b1 = 0;
    p->b2 = 0;
    p->life = 0;
    p->key = 0;
    p->pos = data_ov010_0220f594;
    func_ov003_021da48c(&p->st, 0);
    self->path = Ov010FxB_New();
    func_ov010_0220e740(self->path, self, &data_ov010_0220f534, 1, &data_ov010_0220f594, 0x68);
    if (self->path->b0) {
        self->path->scale = 0x4000;
    }
    self->unk_cc.b4 = 0;
    {
        ActorSub48 *mm = self->hit;
        mm->unk_9a_0 = 0;
        mm->unk_9a_3 = 0;
        func_0203f364(mm);
    }
    {
        ActorSub44 *q = self->unk_44;
        q->unk_22_0 = 0;
        q->unk_22_1 = 0;
    }
    self->model->visible = 0;
    {
        Model0218fe1c *m = self->model;
        m->scale.x = 0x1400;
        m->scale.y = 0x1400;
        m->scale.z = 0x1400;
    }
    self->targetObj->target = self->unk_d0;
    self->targetObj->unk_18_4 = 1;
    self->hit->unk_9a_7 = 1;
    self->hit->unk_48 = self->radius + (self->radius >> 1);
    self->unk_cf = 1;
}


}

typedef void (Obj0220a6b0::*Ov010AcFn)();

struct Ov010AcEntry {
    u32 key;
    Ov010AcFn fn;
};

struct Ov010Mtx33 {
    s32 m[9];
};

extern "C" {
extern const Ov010AcEntry data_ov010_0220f5a0[];
extern const Ov010AcEntry data_ov010_0220f5b8[];
extern void *data_ov000_021ccd68;
extern void func_ov010_0220c5a0(Obj0220a6b0 *self);
extern Robo021ca458 *func_ov000_0219bf90(void);
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void MTX_Identity33_(Ov010Mtx33 *m);
extern void MTX_RotX33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_RotY33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_RotZ33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_Concat33(Ov010Mtx33 *a, Ov010Mtx33 *b, Ov010Mtx33 *out);
extern void MTX_MultVec33(VecFx32 *v, Ov010Mtx33 *m, VecFx32 *out);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);

void Ov010ActVt_02210378_Update(Obj0220a6b0 *self) {
    VecFx32 t;
    Ov010Mtx33 tmp;
    Ov010Mtx33 m;
    func_ov000_021953b4((ActorEx *)self);
    if (self->unk_ce.b0) {
        u32 i;
        u8 key = self->fsmA.current;
        for (i = 0; i < 2; i++) {
            if (key == data_ov010_0220f5a0[i].key && *(s32 *)&data_ov010_0220f5a0[i].fn != 0) {
                (self->*data_ov010_0220f5a0[i].fn)();
                break;
            }
        }
    }
    if (self->unk_ce.b1) {
        u32 i;
        u8 key = self->fsmB.current;
        for (i = 0; i < 3; i++) {
            if (key == data_ov010_0220f5b8[i].key && *(s32 *)&data_ov010_0220f5b8[i].fn != 0) {
                (self->*data_ov010_0220f5b8[i].fn)();
                break;
            }
        }
    }
    func_ov010_0220c5a0(self);
    switch (self->unk_d8) {
    case 6: {
        Ov010Path *p = self->path;
        u8 n;
        if (p->b0) {
            n = p->sm.current;
        } else {
            n = 0;
        }
        if (n == 4) {
            self->unk_44->unk_22_1 = 0;
        }
        {
            ActorSub44 *q = self->unk_44;
            q->unk_22_0 = 1;
            q->unk_22_1 = 1;
        }
        u16 a = func_ov000_0219bf90()->unk_b1c;
        if (a == self->id) {
            self->unk_d8 = 8;
        }
        break;
    }
    case 7: {
        void *mgr = data_ov000_021ccd68;
        u16 id = self->unk_180;
        Actor *o = mgr == NULL ? NULL : ActorMgr_GetActor(mgr, id);
        if (o != NULL) {
            u16 rx;
            u16 ry;
            u16 rz;
            BOOL set;
            t = o->pos;
            set = FALSE;
            rz = o->rot_z - self->unk_190.z;
            ry = o->rot_y - self->unk_190.y;
            rx = o->rot_x - self->unk_190.x;
            MTX_Identity33_(&m);
            if (rz != 0) {
                MTX_RotZ33_(&m, OV010_SIN(rz), OV010_COS(rz));
                set = TRUE;
            }
            if (ry != 0) {
                if (set) {
                    MTX_RotY33_(&tmp, OV010_SIN(ry), OV010_COS(ry));
                    MTX_Concat33(&tmp, &m, &m);
                } else {
                    MTX_RotY33_(&m, OV010_SIN(ry), OV010_COS(ry));
                    set = TRUE;
                }
            }
            if (rx != 0) {
                if (set) {
                    MTX_RotX33_(&tmp, OV010_SIN(rx), OV010_COS(rx));
                    MTX_Concat33(&tmp, &m, &m);
                } else {
                    MTX_RotX33_(&m, OV010_SIN(rx), OV010_COS(rx));
                    set = TRUE;
                }
            }
            MTX_MultVec33(&self->unk_184, &m, &self->pos);
            VEC_Add(&self->pos, &t, &self->pos);
        }
        break;
    }
    }
    if (self->trail != NULL) {
        func_ov010_0220e38c(self->trail);
    }
    if (self->path != NULL) {
        func_ov010_0220e7c8(self->path);
    }
    self->mover.vfunc_0c();
}

}
}  // namespace m_0220adb8

// ---- merged from ov010_0220b7b0.cpp
namespace m_0220b7b0 {
extern "C" {

extern void *data_ov000_021ccd68;
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void Actor_SendMsg(void *obj, u16 id, s32 a, s32 b, s32 c, u8 *d);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern BOOL func_ov000_02190cb0(void *p, const void *a, s32 b, s32 c);
extern void func_ov000_021915a0(void *p);
extern AnimCtrl *func_ov000_02190a30(Model0218fe1c *self, u32 i);

static inline Actor *Ov010_FindObjById(u16 id) {
    if (data_ov000_021ccd68 != NULL) {
        return ActorMgr_GetActor(data_ov000_021ccd68, id);
    }
    return NULL;
}

struct Ov010AnMsg {
    u8 f0;
    u8 f1;
    u16 ang;
    u8 kind;
    u8 pad;
    u16 id;
};

extern void *ActorMgr_GetGroup(void *mgr, s32 a);
extern s32 Filter_Apply(void *a, void *b, s32 c);
extern u16 func_ov010_02207a44(s32 i);
extern void ActorMgr_SendMsg(u16 a, u16 b, s32 c, s32 d, s32 e, Ov010AnMsg *msg);
extern void ActorMgr_BroadcastKind(void *mgr, u16 id, s32 msg);

// Reads the effect's flag through a const view, which is not merged with the later plain
// reads of the same byte.
static inline u8 Ov010_FxCount(const Ov010Path *fx) {
    u8 n;
    if (fx->b0) {
        n = fx->sm.current;
    } else {
        n = 0;
    }
    return n;
}

void func_ov010_0220b40c(Obj0220a6b0 *self) {
    VecFx32 p;
    Ov010Blk12 q;
    Ov010AnMsg msg;
    u8 c;
    switch (self->fsm->st) {
    case 0: {
        Ov010Path *fx = self->path;
        if (Ov010_FxCount(fx) == 1) {
            if (fx->b0) {
                EffectMgr_StopLoop(data_0214a420, fx->fxHandle);
                fx->fxHandle = 0;
                func_ov000_02198360(&fx->sm, 1, 0);
            }
            fx = self->path;
            if (fx->b0) {
                fx->timer = 0;
                fx->duration = 0x50;
                func_ov003_021da48c(&fx->sm, 2);
            }
            self->unk_ce.b3 = 0;
        }
        self->unk_d6 = 0;
        self->fsm->st = 1;
    }
    case 1:
        if (self->unk_ce.b3) {
            self->fsm->st = 2;
        }
        return;
    case 2:
        if (self->fsm->timer % 8 == 0) {
            BOOL found = FALSE;
            Actor *o = FLD(Actor *, ActorMgr_GetGroup(data_ov000_021ccd68, 0x4000), 0xc);
            for (; o != NULL; o = o->next) {
                if (o != self && o->kind == 0x4817) {
                    BOOL ok = FALSE;
                    if (o != NULL && static_cast<Obj0220a6b0 *>(o)->unk_d8 == 7) {
                        ActorSub40 *s = o->fsm;
                        if ((s != NULL ? s->current : 0) != 0x12) {
                            ok = TRUE;
                        }
                    }
                    if (ok) {
                        c = 3;
                        found = TRUE;
                        Actor_SendMsg(o, self->id, 0xe, 1, 1, &c);
                        self->unk_d6++;
                        break;
                    }
                }
            }
            if (!found) {
                self->fsm->st = 3;
            }
        }
        self->fsm->timer++;
        return;
    case 3: {
        Actor *a;
        Actor *b;
        EffectObj *e;
        self->unk_d6++;
        a = Ov010_FindObjById(self->unk_180);
        b = Ov010_FindObjById(self->unk_182);
        if (a != NULL && b != NULL) {
            u16 ang = Filter_Apply(a->hp, b->hp, func_ov010_02207a44(self->unk_d6));
            msg.f0 = 0;
            msg.f1 = self->unk_d6;
            msg.ang = ang;
            msg.kind = 0x11;
            msg.id = self->id;
            ActorMgr_SendMsg(self->unk_180, self->unk_182, 0xe, 0, 8, &msg);
            p.x = a->pos.x;
            p.y = a->pos.y;
            p.z = a->pos.z;
            e = func_02065f88(0x38f, &p);
            e->SetScaleAll(0x2800);
            e->AddPosXYZ(0, a->height >> 1, 0);
        }
        q = *(const Ov010Blk12 *)&self->pos;
        e = func_02065f88(0x321, (VecFx32 *)&q);
        e->SetScaleAll(0x1000);
        e->onUpdate = func_ov010_02209074;
        e->unk_04 = 6;
        self->model->visible = 0;
        self->fsm->st = 4;
        return;
    }
    case 4:
        func_ov000_02198360(self->fsm, 0x15, 0);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4817, 0x15);
        break;
    }
}

void func_ov010_0220b7b0(Obj0220a6b0 *self) {
    if (self->fsm->st != 0) {
        return;
    }
    VecFx32 p = self->pos;
    EffectObj *fx;
    void *obj;
    fx = func_02065f88(0x321, &p);
    fx->SetScaleAll(0x1000);
    fx->onUpdate = func_ov010_02209074;
    fx->unk_04 = 6;
    obj = Ov010_FindObjById(self->unk_180);
    if (obj != NULL) {
        u8 c = 1;
        Actor_SendMsg(obj, self->id, 0xe, 1, 1, &c);
    }
    self->model->visible = 0;
    self->unk_cf = 0;
    func_ov000_02198360(self->fsm, 0x15, 0);
}

void func_ov010_0220b890(Obj0220a6b0 *self) {
    if (self->fsm->st != 0) {
        return;
    }
    if (self->model != NULL) {
        func_ov000_02190cb0(self->model, data_ov010_0220f540, 0x1000, 0);
        func_ov000_021915a0(self->model);
    }
    self->fsm->st = 1;
    self->speed = 0;
    self->velY = 0;
    self->friction = 0;
    self->gravity = 0;
}

void func_ov010_0220b8f8(Obj0220a6b0 *self) {
    func_ov000_02190a30(self->model, 0)->paused = 0;
    func_ov000_02195d88((ActorEx *)self);
}

extern void *data_02097e4c;
extern void HitSphere_Link(void *p);
extern void func_0203f364(void *p);
extern void MTX_RotY33_(void *m, s32 s, s32 c);
extern void MTX_MultVec33(const VecFx32 *v, const void *m, VecFx32 *out);
extern u16 Ov003Vec_Yaw(VecFx32 *v);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *c);
extern void VEC_Normalize(const VecFx32 *a, VecFx32 *b);
extern void Ov003Vec_MultAdd(VecFx32 *a, VecFx32 *b, VecFx32 *c, s32 d, s32 e);
extern void Ov003Vec_ToRot(void *out, const void *p);
extern void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
extern s32 Rand_UpTo(s32 max);
extern Actor *Target_Get(void *p);
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
extern s32 Ov003Vec_DistSq(const VecFx32 &a, const VecFx32 *b);

#define OV010_FXMUL_K(a, k) ((s32)(((s64)(a) * (k) + 0x800) >> 12))

struct Ov010Mtx33 {
    s32 m[9];
};

struct Ov010HitMsg {
    u16 a;
    u8 b;
    u8 pad;
    u16 id;
};

static inline void Ov010_VecSubA(const VecFx32 *a, const VecFx32 *b, VecFx32 *out) {
    s32 ax = a->x;
    s32 ay = a->y;
    s32 az = a->z;
    out->x = ax - b->x;
    out->y = ay - b->y;
    out->z = az - b->z;
}

static inline void Ov010_VecSubB(const VecFx32 *a, const VecFx32 *b, VecFx32 *out) {
    s32 bx = b->x;
    s32 by = b->y;
    s32 bz = b->z;
    out->x = a->x - bx;
    out->y = a->y - by;
    out->z = a->z - bz;
}

static inline Actor *Ov010_FindObjById2(u16 id) {
    Actor *o = NULL;
    if (data_ov000_021ccd68 != NULL) {
        o = ActorMgr_GetActor(data_ov000_021ccd68, id);
    }
    return o;
}

static inline Actor *Ov010_FindObjById3(u16 id) {
    return data_ov000_021ccd68 != NULL ? ActorMgr_GetActor(data_ov000_021ccd68, id) : NULL;
}

static inline VecFx32 Ov010_TargetCenter(Obj0220a6b0 *self) {
    VecFx32 v;
    VecFx32 *b = self->unk_e4;
    s32 *a = self->unk_e0;
    switch (self->unk_dc) {
    case 0:
        v.x = a[0] + ((a[2] - a[0]) >> 1);
        v.y = a[4];
        v.z = a[1] + ((a[3] - a[1]) >> 1);
        break;
    case 1:
        v.x = b->x;
        v.y = b->y;
        v.z = b->z;
        break;
    }
    return v;
}

void func_ov010_0220b924(Obj0220a6b0 *self) {
    VecFx32 d;
    VecFx32 v1;
    VecFx32 v2;
    Ov010Mtx33 m;
    VecFx32 o;
    VecFx32 p;
    VecFx32 d2;
    Ov010HitMsg msg;
    ActorSub40 *s40 = self->fsm;
    switch (s40->st) {
    case 0:
    case 0x10: {
        ActorSub48 *mm = self->hit;
        mm->unk_9a_0 = 1;
        mm->unk_9a_3 = 1;
        HitSphere_Link(mm);
        self->hit->unk_30 = 0;
        self->friction = 0;
        self->moveYaw = self->rot_y;
        self->speed = 0x2b0;
        self->velY = 0x80;
        self->gravity = 0x20;
        self->fsm->st = 0x11;
        break;
    }
    case 0x11:
        s40->timer++;
        if (self->fsm->timer >= 0xc) {
            self->fsm->timer = 0;
            self->fsm->st = 0x20;
        }
        Actor_Move(self, 0);
        break;
    case 0x20:
        self->friction = 0xa00;
        Actor_Move(self, 0);
        self->fsm->st = 0x21;
        break;
    case 0x21: {
        s32 k;
        s40->timer++;
        self->fsm->timer = 0;
        self->fsm->st = 0x30;
        Actor_Move(self, 0);
        k = self->friction;
        if (k != 0 && k != 0x1000) {
            self->velY = Ov010_FxMul(self->velY, k);
        }
        break;
    }
    case 0x30: {
        Actor *t;
        BOOL ok;
        self->moveYaw = self->rot_y;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->speed = 0;
        t = Ov010_FindObjById2(self->target);
        ok = FALSE;
        if (t != NULL) {
            BOOL b;
            BOOL a;
            ActorSub40 *q;
            s32 dot;
            u16 ang;
            Ov010_VecSubA(&t->pos, &self->pos, &d);
            q = t->fsm;
            a = (q != NULL ? q->current : 0) == 0x13;
            b = FALSE;
            MTX_RotY33_(&m, OV010_SIN(self->moveYaw), OV010_COS(self->moveYaw));
            MTX_MultVec33(&data_ov010_0220f54c, &m, &v1);
            ang = Ov003Vec_Yaw(&d);
            MTX_RotY33_(&m, OV010_SIN(ang), OV010_COS(ang));
            MTX_MultVec33(&data_ov010_0220f54c, &m, &v2);
            dot = (s32)(((s64)v1.x * v2.x + (s64)v1.y * v2.y + (s64)v1.z * v2.z + 0x800) >> 12);
            if (dot > 0x1000) {
                dot = 0x1000;
            } else if (dot < -0x1000) {
                dot = -0x1000;
            }
            if (dot >= 0xf00) {
                b = TRUE;
            }
            if (!a && b) {
                ok = TRUE;
            }
        }
        if (ok) {
            OV010_BLKCPY(&o, &data_ov010_0220f594);
            o.y += OV010_FXMUL_K(t->height, 0x99a);
            p.x = t->pos.x;
            p.y = t->pos.y;
            p.z = t->pos.z;
            VEC_Add(&p, &o, &p);
            self->unk_108.x = p.x - self->pos.x;
            self->unk_108.y = p.y - self->pos.y;
            self->unk_108.z = p.z - self->pos.z;
            VEC_Normalize(&self->unk_108, &self->unk_108);
        } else {
            func_ov003_021d9900(&self->unk_108, 0xfc71, &data_ov010_0220f54c);
            func_ov003_021d9980(&self->unk_108, self->rot_y, &self->unk_108);
        }
        self->fsm->st = 0x31;
        break;
    }
    case 0x31: {
        s32 sp;
        ActorSub48 *s48;
        sp = self->speed + 0x180;
        self->speed = sp;
        if (sp > 0x1666) {
            sp = 0x1666;
        } else if (sp < 0) {
            sp = 0;
        }
        self->speed = sp;
        Ov003Vec_MultAdd(&self->pos, &self->unk_108, &self->pos, self->speed, self->velY);
        func_ov003_021da2c8(self, self->speed, self->velY, self->friction, self->gravity);
        Ov003Vec_ToRot(&self->rot_x, &self->unk_108);
        s48 = self->hit;
        s48->unk_44 = OV010_FXMUL_K(s48->radius, 0x800);
        func_ov000_021987b8(self->hit, 1, 0, 0);
        if (self->hit->unk_58 & 0x20) {
            Actor *t = Ov010_FindObjById2(self->target);
            Actor *q;
            VObj *e;
            if (t == NULL) {
                self->fsm->st = 0x50;
                return;
            }
            self->unk_180 = t->id;
            func_ov000_02190a30(self->model, 0)->paused = 1;
            self->rot_x += (u16)(Rand_UpTo(0x2000) - 0x1000);
            self->rot_y += (u16)(Rand_UpTo(0x2000) - 0x1000);
            q = Target_Get(self->targetObj);
            if (q != NULL) {
                self->unk_182 = q->id;
                msg.a = Filter_Apply(t->hp, q->hp, 0x14);
                msg.b = 0x10;
                msg.id = self->id;
                Actor_SendMsg(t, self->id, 9, 0, 6, (u8 *)&msg);
            }
            Ov010_VecSubB(&self->pos, &t->pos, &d2);
            func_ov003_021d9980(&d2, (u16)(0xffff - t->rot_y), &d2);
            e = func_ov003_021da7e8(0x6c, t, &d2);
            e->vfunc_34((u16)(self->rot_x + 0x4000), 0, 0);
            e->vfunc_0c(0x1800);
            self->fsm->st = 0x40;
            func_02049f44(data_02097e4c, 0x66, &self->pos, 0);
            return;
        }
        if (Ov003Vec_DistSq(Ov010_TargetCenter(self), &self->pos) > 0x190000) {
            self->fsm->st = 0x50;
        }
        break;
    }
    case 0x40: {
        Actor *t = Ov010_FindObjById3(self->unk_180);
        Ov010Path *ec;
        BOOL found;
        if (t == NULL) {
            self->fsm->st = 0x50;
            return;
        }
        Ov010_VecSubB(&self->pos, &t->pos, &self->unk_184);
        self->unk_190.x = t->rot_x;
        self->unk_190.y = t->rot_y;
        self->unk_190.z = t->rot_z;
        self->unk_196.x = self->rot_x;
        self->unk_196.y = self->rot_y;
        self->unk_196.z = self->rot_z;
        self->unk_d8 = 7;
        {
            ActorSub48 *mm = self->hit;
            mm->unk_9a_0 = 0;
            mm->unk_9a_3 = 0;
            func_0203f364(mm);
        }
        self->fsm->st = 0x41;
        ec = self->path;
        if ((ec->b0 ? ec->sm.current : 0) == 1) {
            return;
        }
        found = FALSE;
        {
            void *g = ActorMgr_GetGroup(data_ov000_021ccd68, 0x4000);
            Actor *it;
            for (it = FLD(Actor *, g, 0xc); it != NULL; it = it->next) {
                if (it != self && it->kind == 0x4817 && static_cast<Obj0220a6b0 *>(it)->unk_d8 == 7) {
                    found = TRUE;
                    break;
                }
            }
        }
        if (found) {
            ec = self->path;
            if (!ec->b0) {
                return;
            }
            EffectMgr_StopLoop(data_0214a420, ec->fxHandle);
            ec->fxHandle = 0;
            func_ov000_02198360(&ec->sm, 1, 0);
            return;
        }
        func_ov000_02198360(self->fsm, 6, 0);
        break;
    }
    case 0x41:
        break;
    case 0x50: {
        func_ov000_02198360(s40, 0x15, 0);
        {
            ActorSub48 *mm = self->hit;
            mm->unk_9a_0 = 0;
            mm->unk_9a_3 = 0;
            func_0203f364(mm);
        }
        {
            ActorSub44 *f = self->unk_44;
            f->unk_22_0 = 0;
            f->unk_22_1 = 0;
        }
        break;
    }
    }
}

}
}  // namespace m_0220b7b0

// ---- merged from ov010_0220c2a4.cpp
namespace m_0220c2a4 {
extern "C" {
extern void *data_02097e4c;
extern void HitSphere_Link(void *p);
extern void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
extern void Actor_SendMsg(void *obj, u16 id, s32 a, s32 b, s32 c, u8 *d);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);
extern void func_ov000_0219763c(VObj *obj);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 mask, VecFx32 *v, s32 e, s32 f, s32 g, s32 h, s32 i);

void func_ov010_0220c2a4(Obj0220a6b0 *self) {
    ActorSub48 *h;
    ActorSub44 *q;
    switch (self->fsm->st) {
    case 0:
        h = self->hit;
        h->unk_9a_0 = 1;
        h->unk_9a_3 = 1;
        HitSphere_Link(h);
        q = self->unk_44;
        q->unk_22_0 = 0;
        q->unk_22_1 = 0;
        self->gravity = 0x52;
        self->fsm->st++;
        break;
    case 1:
        if (self->hit != NULL) {
            func_ov000_021987b8(self->hit, 1, 0, 0);
            if (self->hit->unk_50 & 0x20000000) {
                u8 c = 1;
                Actor_SendMsg(self, self->id, 0xe, 1, 1, &c);
            }
        }
        break;
    }
    Actor_Move(self, 0);
}

void func_ov010_0220c390(Obj0220a6b0 *self) {
    if (self->fsm->st == 0) {
        FieldState *g;
        EffectObj *fx;
        if (self->unk_cf != 0) {
            func_02049f44(data_02097e4c, 0x19, &self->pos, 0);
        }
        g = data_ov000_021ccd54;
        g->cam.base.shakeX = 1;
        g->cam.base.shakeY = 1;
        g->cam.base.shakeZ = 1;
        g->cam.base.shakeTime = 5;
        g->cam.base.shakeLen = 0xf;
        g->cam.base.shakeCur = 0xf;
        fx = func_02065f88(0x38f, &self->pos);
        fx->AddPosXYZ(0, 0x800, 0);
        fx->SetScaleAll(0x1800);
    }
    func_ov000_0219763c(self);
    func_ov000_0219aae8(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, 2, NULL, 0, 0x1b33, 0, 0x57e, 0x1000);
}

void func_ov010_0220c49c(Obj0220a6b0 *self) {
    s32 y;
    s32 z;
    s32 x;
    self->unk_ce.b0 = 0;
    self->unk_ce.b1 = 0;
    self->unk_ce.b2 = 0;
    self->unk_ce.b3 = 0;
    self->unk_cf = 0;
    self->unk_d0 = 0xffff;
    self->unk_d2 = 0xffff;
    self->unk_d4 = 0;
    self->unk_d6 = 0;
    self->unk_d8 = 0;
    self->unk_dc = -1;
    self->unk_e0 = 0;
    self->unk_e4 = 0;
    self->trail = 0;
    self->path = 0;
    Ov010_VecCopy(&self->unk_f0, &data_ov010_0220f594);
    x = self->unk_f0.x;
    y = self->unk_f0.y;
    z = self->unk_f0.z;
    Ov010_VecSet(&self->unk_fc, x, y, z);
    Ov010_VecSet(&self->unk_108, x, y, z);
    Ov010_VecSet(&self->unk_114, x, y, z);
    func_ov003_021da48c(&self->fsmA, 0);
    func_ov003_021da48c(&self->fsmB, 0);
    self->unk_180 = 0xffff;
    self->unk_182 = 0xffff;
    Ov010_VecSet(&self->unk_184, x, y, z);
    {
        const Ov010Ang3 *s = &data_ov010_0220f544;
        u16 a, b, c;
        self->unk_190.x = a = s->x;
        self->unk_190.y = b = s->y;
        self->unk_190.z = c = s->z;
        self->unk_196.x = a;
        self->unk_196.y = b;
        self->unk_196.z = c;
    }
}

}
}  // namespace m_0220c2a4

// ---- merged from ov010_0220c5a0.cpp
namespace m_0220c5a0 {
extern "C" {

extern void *data_ov000_021ccd68;
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void VEC_MultAdd(s32 s, const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern BOOL func_ov010_022090b4(s32 type, s32 *a, VecFx32 *b, VecFx32 *pos);
extern u16 func_ov010_02209190(s32 type, s32 *a, VecFx32 *b, VecFx32 *pos, u16 rot);
extern s32 func_ov000_0219a2f4(VecFx32 *p, s32 a, s32 b);

static inline Actor *Ov010_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline VecFx32 Ov010_PathPoint(s32 type, s32 *a, VecFx32 *b) {
    VecFx32 v;
    switch (type) {
    case 0:
        v.x = a[0] + ((a[2] - a[0]) >> 1);
        v.y = a[4];
        v.z = a[1] + ((a[3] - a[1]) >> 1);
        break;
    case 1:
        v.x = b->x;
        v.y = b->y;
        v.z = b->z;
        break;
    }
    return v;
}

static inline void Ov010_VecSub(const VecFx32 *a, const VecFx32 *b, VecFx32 *out) {
    s32 ax = a->x;
    s32 ay = a->y;
    s32 az = a->z;
    out->x = ax - b->x;
    out->y = ay - b->y;
    out->z = az - b->z;
}

static inline void Ov010_Approach(VecFx32 *pos, const VecFx32 *target, s32 rate) {
    VecFx32 d;
    Ov010_VecSub(target, pos, &d);
    VEC_MultAdd(rate, &d, pos, pos);
}

void func_ov010_0220c5a0(Obj0220a6b0 *self) {
    VecFx32 r;
    switch (self->fsmA.current) {
    case 1:
        return;
    case 2: {
        Actor *a = Ov010_FindActor(self->unk_d2);
        ActorSub48 *m;
        if (a == NULL || (m = a->hit) == NULL) {
            return;
        }
        Ov010_Approach(&self->unk_f0, &m->check, 0x11f);
        break;
    }
    case 3: {
        self->unk_f0.y = Ov010_PathPoint(self->unk_dc, self->unk_e0, self->unk_e4).y;
        if (func_ov010_022090b4(self->unk_dc, self->unk_e0, self->unk_e4, &self->unk_f0)) {
            self->unk_d4 = func_ov010_02209190(self->unk_dc, self->unk_e0, self->unk_e4, &self->unk_f0, self->unk_d4);
        }
        func_ov003_021d9980(&r, self->unk_d4, (VecFx32 *)&data_ov010_0220f54c);
        VEC_MultAdd(0x2b8, &r, &self->unk_f0, &self->unk_f0);
        func_ov000_0219a2f4(&self->unk_f0, 0x1000, -0x3000);
        break;
    }
    }
}

extern s32 Rand_Fx(void);
extern s32 Rand_UpTo(s32 max);

static inline s32 Ov010c_FxMul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline VecFx32 Ov010_RandPoint(s32 type, s32 *a, VecFx32 *b) {
    VecFx32 v;
    switch (type) {
    case 0: {
        s32 y;
        s32 z;
        s32 x;
        z = a[1] + Ov010c_FxMul(a[3] - a[1], Rand_Fx());
        y = a[4];
        x = a[0] + Ov010c_FxMul(a[2] - a[0], Rand_Fx());
        v.x = x;
        v.y = y;
        v.z = z;
        func_ov000_0219a2f4(&v, 0x1000, -0x3000);
        break;
    }
    case 1: {
        s32 r = Ov010c_FxMul(FLD(s32, b, 0xc), Rand_Fx());
        func_ov003_021d9980(&v, Rand_UpTo(0xffff), (VecFx32 *)&data_ov010_0220f54c);
        VEC_MultAdd(r, &v, b, &v);
        func_ov000_0219a2f4(&v, 0x1000, -0x3000);
        break;
    }
    }
    return v;
}

void func_ov010_0220c758(Obj0220a6b0 *self) {
    u16 t;
    s32 *ap;
    VecFx32 *bp;
    switch (self->fsmA.st) {
    case 0: {
        Actor *a = Ov010_FindActor(self->unk_d2);
        if (a != NULL && a->hit != NULL) {
            t = 0;
            Ov010Trail *c_0;
            switch (self->fsmA.current) {
            case 2: {
                bp = self->unk_e4;
                ap = self->unk_e0;
                VecFx32 p_0;
                p_0 = Ov010_RandPoint(self->unk_dc, ap, bp);
                t = 0x3c;
                self->unk_f0 = p_0;
                self->unk_d4 = 0;
                break;
            }
            case 3: {
                VecFx32 p_1;
                p_1 = Ov010_RandPoint(self->unk_dc, self->unk_e0, self->unk_e4);
                self->unk_f0 = p_1;
                self->unk_d4 = Rand_UpTo(0xffff);
                t = 0x64;
                break;
            }
            }
            c_0 = self->trail;
            if (c_0->b0) {
                c_0->b1 = 1;
                c_0->life = t;
                c_0->pos = self->unk_f0;
                func_ov003_021da48c(&c_0->st, 0);
            }
        }
        self->fsmA.st = 1;
        break;
    }
    case 1: {
        Ov010Trail *c_1 = self->trail;
        BOOL busy;
        BOOL done_0;
        if (c_1->b0 && c_1->b1) {
            c_1->pos = self->unk_f0;
        }
        c_1 = self->trail;
        busy = FALSE;
        if (c_1->b0) {
            busy = c_1->b2;
        }
        if (!busy) {
            done_0 = FALSE;
            if (c_1->b0) {
                if (!c_1->b1) {
                    done_0 = TRUE;
                }
            }
            if (!done_0) {
                return;
            }
        }
        self->fsmA.st = 2;
        break;
    }
    case 2: {
        Ov010Trail *c_2 = self->trail;
        BOOL done_1 = FALSE;
        VecFx32 *p_2;
        if (c_2->b0) {
            if (!c_2->b1) {
                done_1 = TRUE;
            }
        }
        if (!done_1) {
            return;
        }
        func_ov003_021da48c(&self->fsmA, 1);
        self->unk_ce.b0 = 0;
        c_2 = self->trail;
        p_2 = c_2->b0 ? &c_2->pos : NULL;
        self->unk_f0 = *p_2;
        break;
    }
    }
}

}
}  // namespace m_0220c5a0

// ---- merged from ov010_0220cba0.cpp
namespace m_0220cba0 {
extern "C" {

extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern BOOL Ov003Mover_Start(Ov010Mover *self, const VecFx32 *target, const VecFx32 *start, s32 speed, s32 maxDist, u8 noSnap);
extern void *func_0204a028(void *mgr, s32 id, const VecFx32 *pos, s32 a);

static inline Actor *Ov010_FindActorD(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

extern s32 Ov003Vec_DistSq(const VecFx32 *a, const VecFx32 *b);
extern BOOL Ov003Vec_Equal(VecFx32 *a, void *b);
extern u16 Ov003Vec_Yaw(void *p);
extern void *Target_Get(void *p);
extern void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, const void *f, void *g, s32 h, s32 i, s32 j, s32 k);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void *Ov003Mover_GetDir(void *p);
extern AnimCtrl *func_ov000_02190a30(Model0218fe1c *self, u32 i);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);

static inline void Ov010_Puff(Obj0220a6b0 *self) {
    VecFx32 q;
    EffectObj *e;
    OV010_BLKCPY(&q, &self->pos);
    e = func_02065f88(0x321, &q);
    e->SetScaleAll(0x1000);
    e->onUpdate = func_ov010_02209074;
    e->unk_04 = 6;
}

static inline void Ov010_Dust(Obj0220a6b0 *self) {
    u16 ry = self->rot_y;
    u16 rx = self->rot_x;
    VecFx32 p;
    s32 y = self->pos.y;
    s32 z = self->pos.z;
    p.x = self->pos.x;
    p.y = y + self->height / 2;
    p.z = z;
    func_02065f88(0x192, &p)->SetRotXYZ(rx, ry, 0);
}

void func_ov010_0220cba0(Obj0220a6b0 *self) {
    switch (self->fsmB.st) {
    case 0:
    case 10: {
        Actor *t = Ov010_FindActorD(self->unk_d0);
        VecFx32 d;
        if (t == NULL || self->unk_d8 != 1) {
            self->fsmB.st = 0x1e;
            return;
        }
        self->unk_d8 = 4;
        Ov010_VecCopy(&self->pos, &t->pos);
        VEC_Add(&self->pos, &self->unk_fc, &self->pos);
        self->model->visible = 1;
        {
            s32 x = self->pos.x;
            s32 y = self->pos.y;
            s32 z = self->pos.z;
            self->unk_114.x = x;
            self->unk_114.y = y;
            self->unk_114.z = z;
            self->unk_114.y = self->unk_114.y + (0x5800 - self->unk_fc.y);
            self->speed = 0xa00;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            d.x = self->unk_f0.x - x;
            d.y = self->unk_f0.y - y;
            d.z = self->unk_f0.z - z;
        }
        self->rot_y = Ov003Vec_Yaw(&d);
        func_0204a028(data_02097e4c, 0x29, &self->pos, 5);
        Ov010_Puff(self);
        self->fsmB.st = 0xb;
        return;
    }
    case 0xb:
        if (self->friction == 0) {
            if (Ov003Vec_DistSq(&self->unk_114, &self->pos) < 0x9000) {
                self->friction = 0xa00;
            }
        }
        if (Ov003Vec_Equal(&self->unk_114, &self->pos) || self->speed < 0x80) {
            self->fsmB.st = 0x14;
            return;
        }
        func_ov003_021d9f80(&self->rot_x, &self->unk_f0, &self->pos);
        func_ov003_021d9dbc(&self->pos, &self->unk_114, &self->pos, self->speed, self->velY);
        func_ov003_021da2c8(self, self->speed, self->velY, self->friction, self->gravity);
        return;
    case 0x14:
        Ov003Mover_Start(&self->mover, &self->unk_f0, &self->pos, 0x100, 0x2000, 0);
        func_ov003_021d9f80(&self->rot_x, &self->unk_f0, &self->pos);
        self->fsmB.st = 0x15;
        return;
    case 0x15: {
        VecFx32 a;
        VecFx32 b;
        EffectObj *e;
        self->fsmB.timer++;
        if (self->fsmB.timer == 10) {
            Ov010_Dust(self);
        }
        {
            VecFx32 *v = (VecFx32 *)self->mover.vfunc_10();
            self->pos.x = v->x;
            self->pos.y = v->y;
            self->pos.z = v->z;
        }
        self->hit->unk_9a_7 = 1;
        func_ov000_021987b8(self->hit, 1, 0, 0);
        {
            u16 mask = ~(1 << (self->id >> 12));
            u16 dd = self->targetObj->unk_0a;
            u16 c = self->targetObj->unk_08;
            void *x = Target_Get(self->targetObj);
            if (func_ov000_0219aae8(self, x, c, dd, mask, NULL, NULL, 0x400, 0, 0x38f, 0x1000)) {
                Ov010_Puff(self);
                func_ov000_02198360(self->fsm, 0x15, 0);
                return;
            }
        }
        if (!(self->hit->unk_50 & 0x20000000)) {
            if (!self->mover.vfunc_14()) {
                return;
            }
        }
        {
            u16 ang;
            FieldState *g;
            AnimCtrl *m;
            OV010_BLKCPY(&a, &self->pos);
            *(Ov010Blk12 *)&b = data_ov010_0220f588;
            ang = Ov003Vec_Yaw(Ov003Mover_GetDir(&self->mover)) + 0x7fff;
            e = func_02065f88(0x67, &a);
            e->SetRotXYZ(0, ang, 0);
            e->SetScale(&b);
            Ov010_Puff(self);
            g = data_ov000_021ccd54;
            g->cam.base.flags |= 0x1c;
            g->cam.base.shakeTime = 5;
            g->cam.base.shakeLen = 8;
            g->cam.base.shakeCur = 8;
            {
                u16 r;
                if (self->rot_x > 0x7fff) {
                    r = self->rot_x - 0xe38;
                } else {
                    r = self->rot_x + 0xe38;
                }
                self->rot_x = r;
            }
            m = func_ov000_02190a30(self->model, 0);
            m->paused = 1;
            self->targetObj->target = 0xffff;
            self->unk_d8 = 6;
            self->fsmB.st = 0x1e;
            self->fsmB.timer = 0;
            func_02049f44(data_02097e4c, 0x52, &self->pos, 0);
        }
        return;
    }
    case 0x1e:
        self->mover.vfunc_08();
        self->unk_ce.b1 = 0;
        return;
    }
}


void func_ov010_0220d1c4(Obj0220a6b0 *self) {
    switch (self->fsmB.st) {
    case 0: {
        Actor *t = Ov010_FindActorD(self->unk_d0);
        if (t != NULL && self->unk_d8 == 1) {
            VecFx32 p;
            VecFx32 q;
            EffectObj *e;
            self->unk_d8 = 3;
            Ov010_VecCopy(&self->pos, &t->pos);
            VEC_Add(&self->pos, &self->unk_fc, &self->pos);
            self->rot_x = 0xbfff;
            self->model->visible = 1;
            p.x = self->pos.x;
            p.y = self->pos.y + 0xa000;
            p.z = self->pos.z;
            Ov003Mover_Start(&self->mover, &p, &self->pos, 0x29, 0x4cd, 0);
            func_0204a028(data_02097e4c, 0x29, &self->pos, 5);
            OV010_BLKCPY(&q, &self->pos);
            e = func_02065f88(0x321, &q);
            e->SetScaleAll(0x1000);
            e->onUpdate = func_ov010_02209074;
            e->unk_04 = 6;
            self->fsmB.st = 1;
        } else {
            self->fsmB.st = 2;
        }
        break;
    }
    case 1: {
        VecFx32 *v = (VecFx32 *)self->mover.vfunc_10();
        self->pos.x = v->x;
        self->pos.y = v->y;
        self->pos.z = v->z;
        if (self->mover.vfunc_14()) {
            self->fsmB.st = 2;
        }
        break;
    }
    case 2:
        self->unk_d8 = 2;
        self->model->visible = 0;
        self->mover.vfunc_08();
        self->unk_ce.b1 = 0;
        break;
    }
}


extern s32 Rand_UpTo(s32 max);

void func_ov010_0220d3d8(Obj0220a6b0 *self) {
    switch (self->fsmB.st) {
    case 0:
        if (self->unk_d8 != 2) {
            self->fsmB.st = 2;
            return;
        }
        self->unk_d8 = 4;
        self->pos.x = self->unk_f0.x;
        self->pos.z = self->unk_f0.z;
        self->pos.y = self->unk_f0.y + 0xa000;
        VEC_Add(&self->pos, &self->unk_fc, &self->pos);
        self->rot_x = 0x4000;
        self->rot_y = Rand_UpTo(0xffff);
        self->model->visible = 1;
        Ov003Mover_Start(&self->mover, &self->unk_f0, &self->pos, 0x8cd, 0x8cd, 1);
        self->fsmB.st = 1;
        break;
    case 1: {
        VecFx32 a;
        VecFx32 b;
        VecFx32 q;
        VecFx32 q2;
        EffectObj *e;
        VecFx32 *v = (VecFx32 *)self->mover.vfunc_10();
        self->pos.x = v->x;
        self->pos.y = v->y;
        self->pos.z = v->z;
        self->hit->unk_9a_7 = 1;
        func_ov000_021987b8(self->hit, 1, 0, 0);
        {
        u16 mask = ~(1 << (self->id >> 12));
        u16 d = self->targetObj->unk_0a;
        u16 c = self->targetObj->unk_08;
        void *x = Target_Get(self->targetObj);
        if (func_ov000_0219aae8(self, x, c, d, mask, NULL, NULL, 0x400, 0, 0x38f, 0x1000)) {
            OV010_BLKCPY(&q, &self->pos);
            e = func_02065f88(0x321, &q);
            e->SetScaleAll(0x1000);
            e->onUpdate = func_ov010_02209074;
            e->unk_04 = 6;
            func_ov000_02198360(self->fsm, 0x15, 0);
            return;
        }
        }
        if (self->hit->unk_50 & 0x20000000) {
            u16 ang;
            FieldState *g;
            AnimCtrl *m;
            a.x = self->pos.x;
            a.y = self->pos.y - self->hit->radius;
            a.z = self->pos.z;
            *(Ov010Blk12 *)&b = data_ov010_0220f570;
            ang = Ov003Vec_Yaw(Ov003Mover_GetDir(&self->mover)) + 0x7fff;
            e = func_02065f88(0x66, &a);
            e->SetRotXYZ(0, ang, 0);
            e->SetScale(&b);
            OV010_BLKCPY(&q2, &self->pos);
            e = func_02065f88(0x321, &q2);
            e->SetScaleAll(0x1000);
            e->onUpdate = func_ov010_02209074;
            e->unk_04 = 6;
            g = data_ov000_021ccd54;
            g->cam.base.flags |= 0x1c;
            g->cam.base.shakeTime = 5;
            g->cam.base.shakeLen = 8;
            g->cam.base.shakeCur = 8;
            self->rot_x += Rand_UpTo(0x2aaa) - 0x1555;
            m = func_ov000_02190a30(self->model, 0);
            m->paused = 1;
            self->targetObj->target = 0xffff;
            self->fsmB.st = 2;
            self->unk_d8 = 6;
            func_02049f44(data_02097e4c, 0x52, &self->pos, 0);
        }
        break;
    }
    case 2:
        self->mover.vfunc_08();
        self->unk_ce.b1 = 0;
        break;
    }
}

}
}  // namespace m_0220cba0

// ---- merged from ov010_0220d77c.cpp
namespace m_0220d77c {
struct Ov010SpawnDesc {
    u16 kind;
    u16 flags;
    u16 arr[4];
    s16 last;
};

struct Ov010Rot3s {
    u16 x;
    u16 y;
    u16 z;
};

typedef s32 (*Ov010CollFn)(Obj0220a6b0 *obj);

extern "C" {

extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd64;
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void *Ov003Pool_Dtor(void *p);
extern void Ov003Pool_Release(void *p);
extern void Ov003Pool_Free(void *p, Ov010CollNode *n);
extern Ov010CollNode *Ov003Pool_Alloc(void *p);
extern void *Group_SpawnActor(void *mgr, Ov010SpawnDesc *d, s32 a, Ov010Rot3s *r, s32 b);
extern void func_ov010_0220a948(void *obj, s32 a, s32 b, s32 c, u16 d, u16 e);

// The list holds 0x4817 actors (Obj0220a6b0).
static inline Obj0220a6b0 *Ov010_FindObjById(u16 id) {
    if (data_ov000_021ccd68 != NULL) {
        return static_cast<Obj0220a6b0 *>(ActorMgr_GetActor(data_ov000_021ccd68, id));
    }
    return NULL;
}

static inline Ov010CollNode *Ov010_NodePush(Ov010CollNode *head, Ov010CollNode *n) {
    if (n != NULL) {
        n->next = head;
        head = n;
    }
    return head;
}

static inline void Ov010SpawnDesc_Init(Ov010SpawnDesc *d, u16 kind, u16 flags) {
    s32 i;
    d->kind = kind;
    d->flags = flags;
    for (i = 0; i < 4; i++) {
        d->arr[i] = 0;
    }
    d->last = -1;
}

BOOL func_ov010_0220d77c(Obj0220a6b0 *p) {
    if (p != NULL && p->unk_d8 == 6) {
        return TRUE;
    }
    return FALSE;
}

Ov010Coll *func_ov010_0220d79c(Ov010Coll *self) {
    func_ov003_021d7848(self->pool + 0);
    self->b0 = 0;
    return self;
}

Ov010Coll *Ov010Coll_Dtor(Ov010Coll *self) {
    if (self->b0) {
        self->b0 = 0;
        Ov003Pool_Release(self->pool);
    }
    Ov003Pool_Dtor(self->pool);
    return self;
}

BOOL Ov010Coll_Init(Ov010Coll *self) {
    self->b0 = 1;
    self->count = 0;
    self->list = NULL;
    self->handler = NULL;
    func_ov003_021d7894(self->pool, 8, 0x10);
    return TRUE;
}

void Ov010Coll_Release(Ov010Coll *self) {
    if (!self->b0) {
        return;
    }
    self->b0 = 0;
    Ov003Pool_Release(self->pool);
}

void func_ov010_0220d858(Ov010Coll *self) {
    Ov010CollNode *prev;
    Ov010CollNode *next;
    Ov010CollNode *n;
    if (!self->b0) {
        return;
    }
    n = self->list;
    prev = NULL;
    while (n != NULL) {
        next = n->next;
        if (Ov010_FindObjById(n->id) == NULL) {
            if (prev != NULL) {
                prev->next = next;
            } else {
                self->list = next;
            }
            Ov003Pool_Free(self->pool, n);
        } else {
            prev = n;
        }
        n = next;
    }
    if (self->handler != NULL) {
        if (!self->handler->vfunc_14()) {
            self->handler = NULL;
            return;
        }
        self->handler->vfunc_10();
    }
}

void func_ov010_0220d918(Ov010Coll *self, Ov010CollFn fn) {
    Ov010CollNode *n;
    if (self->b0 && fn != NULL) {
        self->count = 0;
        for (n = self->list; n != NULL; n = n->next) {
            if (fn(Ov010_FindObjById(n->id)) == 1) {
                self->ids[self->count] = n->id;
                self->count++;
            }
        }
    }
}

s32 Ov010Coll_GetCount(Ov010Coll *self) {
    s32 r = 0;
    if (self->b0) {
        r = self->count;
    }
    return r;
}

void Ov010Coll_SetHandler(Ov010Coll *self, VObj *h) {
    if (self->b0 && h != NULL) {
        if (self->handler != NULL) {
            self->handler->vfunc_0c();
        }
        self->handler = h;
        h->vfunc_08(self);
    }
}

void Ov010Coll_ClearHandler(Ov010Coll *self) {
    if (self->b0 && self->handler != NULL) {
        self->handler->vfunc_0c();
        self->handler = NULL;
    }
}

BOOL Ov010Coll_IsFree(Ov010Coll *self) {
    BOOL r = FALSE;
    if (self->b0) {
        r = self->handler == NULL;
    }
    return r;
}

Ov010CollNode *func_ov010_0220da74(Ov010Coll *self, s32 a, s32 b, s32 c, s32 d, u16 e, u16 f) {
    Ov010CollNode *n = NULL;
    if (self->b0) {
        n = Ov003Pool_Alloc(self->pool);
        if (n != NULL) {
            Ov010SpawnDesc desc;
            Ov010Rot3s rot;
            Obj0220a6b0 *obj;
            Ov010SpawnDesc_Init(&desc, 0x4817, 0x4000);
            rot.x = 0;
            rot.y = 0;
            rot.z = 0;
            obj = static_cast<Obj0220a6b0 *>(Group_SpawnActor(data_ov000_021ccd64, &desc, a, &rot, 0xffff));
            func_ov010_0220a948(obj, b, c, d, e, f);
            obj->flags_0 = 1;
            n->id = obj->id;
            self->list = Ov010_NodePush(self->list, n);
        }
    }
    return n;
}

Ov010CollNode *func_ov010_0220db74(Ov010CollNode *head, Ov010CollNode *node) {
    Ov010CollNode *p;
    Ov010CollNode *prev;
    if (head == NULL || node == NULL) {
        return head;
    }
    prev = NULL;
    for (p = head; p != NULL; p = p->next) {
        if (p == node) {
            if (prev == NULL) {
                head = p->next;
            } else {
                prev->next = p->next;
            }
            return head;
        }
        prev = p;
    }
    return head;
}

static inline long Ov010Coll_Count(Ov010Coll *self) {
    u8 r = 0;
    if (self->b0) {
        r = self->count;
    }
    return r;
}

static inline u16 Ov010Coll_Id(Ov010Coll *self, s32 i) {
    u16 r = 0xffff;
    if (self->b0 && i >= 0 && i < self->count) {
        r = self->ids[i];
    }
    return r;
}

static inline BOOL Ov010_ObjGone(Obj0220a6b0 *obj) {
    BOOL r = FALSE;
    if (obj == NULL) {
        r = TRUE;
    } else {
        switch (obj->unk_d8) {
        case 0:
        case 1:
        case 2:
        case 3:
            r = TRUE;
            break;
        }
    }
    return r;
}

static inline void Ov010Coll_Kill(Ov010Coll *self, Ov010CollNode *n) {
    if (self->b0 && n != NULL) {
        VObj *obj = Ov010_FindObjById(n->id);
        if (obj != NULL) {
            obj->vfunc_08();
        }
        self->list = func_ov010_0220db74(self->list, n);
        Ov003Pool_Free(self->pool, n);
    }
}

static inline void Ov010Coll_KillId(Ov010Coll *self, u16 id) {
    Ov010CollNode *n;
    if (self->b0) {
        for (n = self->list; n != NULL; n = n->next) {
            if (n->id == id) {
                Ov010Coll_Kill(self, n);
                return;
            }
        }
    }
}

void func_ov010_0220dbc0(Ov010Coll *self) {
    s32 i;
    Ov010CollNode *n;
    u16 id;
    if (self->b0) {
        self->count = 0;
        for (n = self->list; n != NULL; n = n->next) {
            Ov010_FindObjById(n->id);
            self->ids[self->count] = n->id;
            self->count++;
        }
    }
    for (i = 0; i < Ov010Coll_Count(self); i++) {
        id = Ov010Coll_Id(self, i);
        if (Ov010_ObjGone(Ov010_FindObjById(id))) {
            Ov010Coll_KillId(self, id);
        }
    }
}

}
}  // namespace m_0220d77c

// ---- merged from ov010_0220dd60.cpp
namespace m_0220dd60 {
extern "C" {

extern u8 data_ov010_022102e0[];
extern void MTX_Identity33_(void *m);
extern void MTX_RotZ33_(void *m, s32 s, s32 c);
extern void MTX_RotY33_(void *m, s32 s, s32 c);
extern void MTX_Concat33(void *a, void *b, void *c);
extern s32 func_ov000_021903b4(void *p);
extern BOOL func_ov000_02190cb0(void *p, const void *a, s32 b, s32 c);
extern void func_ov000_021915a0(void *p);
extern void func_0203f364(void *p);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);

struct Obj0220dd60 : public ActorEx {
    s32 unk_d0;
    s32 unk_d4; // effect handle (EffectObj_StopLoop)
    s32 unk_d8;
    MtxFx33 rot; // copied into model->rot (Draw)
};

static inline void Ov010_0220dd60_Reset(Obj0220dd60 *self) {
    self->unk_d0 = -1;
    self->unk_d4 = 0;
    self->unk_d8 = 0;
    MTX_Identity33_(&self->rot);
}

void *Ov010ActVt_022102e0_Ctor(Obj0220dd60 *self) {
    ActorEx_Ctor(self);
    *(void * *)self = data_ov010_022102e0;
    Ov010_0220dd60_Reset(self);
    return self;
}

static inline void Ov010_0220dd60_Dtor(Obj0220dd60 *self) {
    *(void * *)self = data_ov010_022102e0;
    EffectMgr_StopLoop(data_0214a420, self->unk_d4);
    Ov010_0220dd60_Reset(self);
    func_ov000_0219429c(self);
}

void *Ov010ActVt_022102e0_Dtor(Obj0220dd60 *self) {
    Ov010_0220dd60_Dtor(self);
    return self;
}

void *Ov010ActVt_022102e0_DtorDelete(Obj0220dd60 *self) {
    Ov010_0220dd60_Dtor(self);
    Heap_Free(self);
    return self;
}

struct Obj0220de4c {
    u8 unk_00[0x14];
    u8 unk_14;
    u8 unk_15[0xbb];
    s32 unk_d0;
};

void func_ov010_0220de4c(Obj0220de4c *self, s32 a) {
    if (self->unk_14 == 1) {
        self->unk_d0 = a;
    }
}

s32 Ov010ActVt_022102e0_Draw(Obj0220dd60 *self) {
    u8 m[0x24];
    s32 r = 0;
    if (self->model != NULL && self->unk_d0 != -1) {
        switch (self->unk_d0) {
        case 0:
            MTX_RotY33_(&self->rot, OV010_SIN(self->rot_y), OV010_COS(self->rot_y));
            break;
        case 1:
            MTX_RotZ33_(m, OV010_SIN(0x4000), OV010_COS(0x4000));
            MTX_RotY33_(&self->rot, OV010_SIN(self->rot_y), OV010_COS(self->rot_y));
            MTX_Concat33(m, &self->rot, &self->rot);
            break;
        }
        self->model->trans = self->pos;
        MI_Copy36B(&self->rot, &self->model->rot);
        r = func_ov000_021903b4(self->model);
    }
    return r;
}

void Ov010ActVt_022102e0_Start(Obj0220dd60 *self) {
    func_ov000_02194758(self);
    VecFx32 v = data_ov010_0220f57c;
    self->model->scale = v;
}

void func_ov010_0220dfac(Obj0220dd60 *self) {
    ActorSub48 *m;
    if (self->fsm->st != 0) {
        return;
    }
    if (self->unk_d0 == -1) {
        self->unk_d0 = 0;
    }
    func_ov000_02190cb0(self->model, data_ov010_0220f540, 0x1000, 0);
    func_ov000_021915a0(self->model);
    m = self->hit;
    if (m != NULL) {
        m->unk_9a_0 = 0;
        m->unk_9a_3 = 0;
        func_0203f364(m);
        m = self->hit;
        m->unk_9a_1 = 0;
        m->unk_9a_4 = 0;
        m = self->hit;
        m->unk_9a_2 = 0;
        m->unk_9a_5 = 0;
    }
    func_ov000_02198360(self->fsm, 4, 0);
}


struct Ov010Rot16 {
    u16 x;
    u16 y;
    u16 z;
};

extern s32 func_ov000_0219a2f4(VecFx32 *p, s32 a, s32 b);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, const void *f, void *g, s32 h, s32 i, s32 j, s32 k);

void func_ov010_0220e06c(Obj0220dd60 *self) {
    VecFx32 p;
    Ov010Rot16 ra;
    Ov010Rot16 rb;
    s32 scale;
    switch (self->fsm->st) {
    case 0:
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->speed = 0x733;
        self->moveYaw = self->rot_y;
        self->fsm->st = 1;
        break;
    case 1:
        if (self->unk_d8 > 0x28000) {
            func_ov000_02198360(self->fsm, 0x15, 0);
        }
        break;
    }
    self->speed = Ov010_FxMul(self->speed, 0x1029);
    self->unk_d8 += self->speed;
    Actor_Move(self, 0);
    if (self->hit == NULL) {
        return;
    }
    scale = Ov010_FxMul(self->model->scale.x, self->radius);
    switch (self->unk_d0) {
    case 0: {
        u16 a = self->rot_y + 0x4000;
        ra.x = 0x4000;
        ra.y = a;
        ra.z = 0;
        rb.x = 0xbfff;
        rb.y = a;
        rb.z = 0;
        break;
    }
    case 1: {
        s32 h;
        EffectObj *o;
        BOOL near;
        rb.x = 0x7fff;
        ra.x = 0;
        ra.y = 0;
        ra.z = 0;
        rb.y = 0;
        rb.z = 0;
        OV010_BLKCPY(&p, &self->pos);
        h = func_ov000_0219a2f4(&p, 0x1000, -0x3000);
        near = FALSE;
        if (self->pos.y - p.y < scale) {
            near = TRUE;
        }
        o = func_020657b0(data_0214a420, self->unk_d4);
        if (h != -0x1000 && near) {
            p.y += 0x800;
            if (o != NULL) {
                o->SetPos(&p);
                o->SetRotXYZ(0, (u16)(self->rot_y + 0x7fff), 0);
            } else {
                EffectObj *n = func_02065f88(0x25e, &p);
                n->SetRotXYZ(0, (u16)(self->rot_y + 0x7fff), 0);
                n->SetScaleXYZ(0x1800, 0x1800, 0x1800);
                self->unk_d4 = n->id;
            }
        } else if (o != NULL) {
            EffectObj_StopLoop(o);
            self->unk_d4 = 0;
        }
        break;
    }
    }
    func_ov000_0219aae8(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, 2, &data_ov010_0220f594, &ra, 0x800, scale, 100, 0x1000);
    func_ov000_0219aae8(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, 2, &data_ov010_0220f594, &rb, 0x800, scale, 100, 0x1000);
}


extern void *data_02097e4c;
extern s32 FX_Div(s32 a, s32 b);
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);

static inline void Ov010_TrailApply(EffectObj *o, s16 s, u32 n) {
    o->SetScaleXYZ(s, s, s);
    if (n > 0x1f) {
        n = 0x1f;
    }
    o->alpha = FX_Div((u8)n << 12, 0x1f000);
}

void func_ov010_0220e38c(Ov010Trail *self) {
    EffectObj *o;
    s32 s;
    s32 n;
    s16 sc;
    if (!self->b0) {
        return;
    }
    if (!self->b1) {
        return;
    }
    self->b2 = 0;
    switch (self->st.st) {
    case 0:
        o = Effect3D_Create(data_ov010_0220f538, data_ov010_0220f53c, 0, &self->pos);
        o->unk_28 = 0;
        o->loopCount = -1;
        self->key = o->id;
        o->SetScaleXYZ(0x6000, 0x6000, 0x6000);
        o->alpha = FX_Div(0xa000, 0x1f000);
        func_02049f44(data_02097e4c, 0x72, &self->pos, 0);
        self->st.st = 1;
        break;
    case 1: {
        BOOL early = self->life < 0xc;
        o = func_020657b0(data_0214a420, self->key);
        if (self->st.timer > 6 || early) {
            self->st.st = 10;
        } else if (o == NULL) {
            self->st.st = 30;
        } else {
            s = o->scale.x - 0xaaa;
            if (s > 0x6000) {
                s = 0x6000;
            } else if (s < 0x2000) {
                s = 0x2000;
            }
            sc = s;
        n = (u8)(Ov010_FxMul(o->alpha, 0x1f000) >> 12) + 6;
            if (n > 0x1e) {
                n = 0x1e;
            } else if (n < 1) {
                n = 1;
            }
            Ov010_TrailApply(o, sc, (u8)n);
        }
        break;
    }
    case 10:
        o = func_020657b0(data_0214a420, self->key);
        if (o == NULL) {
            self->st.st = 30;
            break;
        }
        o->SetScaleXYZ(0x2000, 0x2000, 0x2000);
        o->alpha = FX_Div(0x1e000, 0x1f000);
        if (self->life - self->st.timer <= 6) {
            self->st.st = 20;
        }
        break;
    case 20:
        self->b2 = 1;
        o = func_020657b0(data_0214a420, self->key);
        if (o == NULL) {
            self->st.st = 30;
            break;
        }
        o->SetScaleXYZ(0x2000, 0x2000, 0x2000);
        o->alpha = FX_Div(0x1e000, 0x1f000);
        self->st.st = 21;
        break;
    case 21:
        o = func_020657b0(data_0214a420, self->key);
        if (self->st.timer > self->life) {
            self->st.st = 30;
            break;
        }
        if (o == NULL) {
            break;
        }
        s = o->scale.x + 0xaaa;
        if (s > 0x6000) {
            s = 0x6000;
        } else if (s < 0x2000) {
            s = 0x2000;
        }
        sc = s;
        n = (u8)(Ov010_FxMul(o->alpha, 0x1f000) >> 12) - 6;
        if (n > 0x1e) {
            n = 0x1e;
        } else if (n < 1) {
            n = 1;
        }
        Ov010_TrailApply(o, sc, (u8)n);
        break;
    case 30:
        EffectMgr_Kill(data_0214a420, self->key);
        self->key = 0;
        self->b1 = 0;
        break;
    }
    self->st.timer++;
    o = func_020657b0(data_0214a420, self->key);
    if (o != NULL) {
        o->SetPosXYZ(self->pos.x, self->pos.y + 0x200, self->pos.z);
    }
}

}
}  // namespace m_0220dd60
