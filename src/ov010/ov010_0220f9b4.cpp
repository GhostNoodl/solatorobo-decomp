#include "ov010/ov010.h"

#define FX32_ONE 0x1000

// The zero rotation.
struct Ov010Rot3 { u16 x, y, z; };

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
static const Ov010Rot3 data_ov010_0220f544 = {0, 0, 0};
char data_ov010_02210204[] = "nut00";
static const Ov010Rot3 data_ov010_0221020a = data_ov010_0220f544;
const VecFx32 data_ov010_0220f594 = {0, 0, 0};
static const VecFx32 data_ov010_0221021c = data_ov010_0220f594;

// ---- merged from ov010_02209190.cpp
namespace m_02209190 {
struct Ov010Mtx33 {
    s32 m[3][3];
};

extern "C" {

extern void MTX_RotAxis33(Ov010Mtx33 *m, const Ov010Vec *v, s32 s, s32 c);
extern void MTX_MultVec33(const Ov010Vec *v, const Ov010Mtx33 *m, Ov010Vec *o);
extern void VEC_Normalize(const Ov010Vec *src, Ov010Vec *dst);
extern u16 Ov003Vec_Yaw(Ov010Vec *v);

u16 func_ov010_02209190(s32 type, const s32 *rect, const Ov010Vec *c, const Ov010Vec *p, u16 ang) {
    Ov010Vec v;
    Ov010Vec a;
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
    func_ov003_021d9980(&a, ang + 0x7fff, (Ov010Vec *)&data_ov010_0220f54c);
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
extern void *func_ov000_02198328(void *p);
extern void func_ov003_021da48c(void *p, s32 a);

Ov010Trig *Ov010Vt_02210280_Ctor(Ov010Trig *self) {
    self->vtbl = data_ov010_02210280;
    func_ov000_02198328((u8 *)self + 0x1c);
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
    ((Ov010V *)self)->v0c();
    return self;
}

void *Ov010Vt_02210280_DtorDelete(Obj02209300 *self) {
    self->vtbl = data_ov010_02210280;
    ((Ov010V *)self)->v0c();
    func_0203de1c(self);
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
extern Ov010Obj *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov010_0220dbc0(s32 p);
extern u16 *func_ov010_0220da74(s32 p, Ov010Vec *pos, s32 b, s32 c, s32 d, u16 e, u16 f);

static inline Ov010Obj *Ov010_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline void Ov010_Activate(Ov010Obj *a) {
    if (a->state == 1) {
        return;
    }
    if (!FLD(Ov010Flags8, a, 0xce).b0) {
        FLD(Ov010Flags8, a, 0xce).b0 = 1;
        FLD(Ov010Flags8, a, 0xce).b2 = 1;
        func_ov003_021da48c((u8 *)a + 0x158, 2);
    }
}

void func_ov010_022093b0(Obj02209300 *self) {
    Ov010Obj *a;
    if (!self->b0) {
        return;
    }
    switch (self->unk_1c) {
    case 0: {
        Ov010Vec p;
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
        Ov010_Activate(a);
        self->unk_1c = 2;
        break;
    case 2:
        a = Ov010_FindActor(self->unk_0a);
        if (a != NULL && FLD(Ov010Flags8, a, 0xce).b0) {
            return;
        }
        self->unk_1c = 3;
        break;
    case 3:
        ((Ov010V *)self)->v0c();
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
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
};

extern "C" {

extern u8 data_ov010_022102c0[];
extern void *func_ov000_02198328(void *p);
extern void func_ov003_021da48c(void *p, s32 a);

BOOL func_ov010_02209568(Ov010Trig *self) {
    return self->b0;
}

void func_ov010_02209578(Ov010Trig *self, s32 a, s32 b, s32 c, u16 d, u16 e) {
    self->b1 = 1;
    self->unk_18 = a;
    self->unk_10 = b;
    self->unk_14 = c;
    self->unk_06 = d;
    self->unk_08 = e;
}

Ov010Trig *Ov010Vt_022102c0_Ctor(Ov010Trig *self) {
    self->vtbl = data_ov010_022102c0;
    func_ov000_02198328((u8 *)self + 0xc);
    self->b0 = 0;
    self->b1 = 0;
    return self;
}

void *Ov010Vt_022102c0_Dtor(void *self) {
    FLD(void *, self, 0) = data_ov010_022102c0;
    ((Ov010V *)self)->v0c();
    return self;
}

void *Ov010Vt_022102c0_DtorDelete(void *self) {
    FLD(void *, self, 0) = data_ov010_022102c0;
    ((Ov010V *)self)->v0c();
    func_0203de1c(self);
    return self;
}

BOOL func_ov010_02209638(Ov010Trig *self, s32 a) {
    FLD(s32, self, 8) = a;
    self->b0 = 1;
    func_ov003_021da48c((u8 *)self + 0xc, 0);
    return TRUE;
}

void func_ov010_02209664(Ov010Trig *self) {
    if (self->b0) {
        self->b0 = 0;
        self->b1 = 0;
    }
}

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

extern void *data_ov000_021ccd68;
extern Ov010Obj *func_ov000_0218e640(void *mgr, u16 id);

static inline Ov010Obj *Ov010_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov010_02209684(Ov010Trig *self) {
    if (!self->b0) {
        return;
    }
    switch (FLD(u16, self, 0xc)) {
    case 0: {
        Ov010IdList *l = FLD(Ov010IdList *, self, 8);
        u16 id;
        Ov010Obj *a;
        Ov010Obj *s;
        if (l->b0) {
            Ov010IdNode *n;
            l->count = 0;
            for (n = l->head; n != NULL; n = n->next) {
                Ov010Obj *e = Ov010_FindActor(n->id);
                if (e != NULL && FLD(s32, e, 0xd8) == 1) {
                    l->ids[l->count] = n->id;
                    l->count++;
                }
            }
        }
        l = FLD(Ov010IdList *, self, 8);
        id = 0xffff;
        if (l->b0 && (s32)l->count > 0) {
            id = l->ids[0];
        }
        a = Ov010_FindActor(id);
        s = Ov010_FindActor(self->unk_06);
        if (a != NULL) {
            Ov010Blk12 t = data_ov010_0220f558;
            Ov010Vec v;
            func_ov003_021d9980(&v, s->rot_y, (Ov010Vec *)&t);
            if (a->state != 1 && !FLD(Ov010Flags8, a, 0xce).b1) {
                FLD(Ov010Flags8, a, 0xce).b1 = 1;
                func_ov003_021da48c((u8 *)a + 0x16c, 1);
                Ov010_VecCopy(&FLD(Ov010Vec, a, 0xfc), &v);
            }
        }
        FLD(u16, self, 0xc) = 1;
        break;
    }
    case 1:
        ((Ov010V *)self)->v0c();
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
extern void *func_ov000_02198328(void *p);
extern void func_ov003_021da48c(void *p, s32 a);

BOOL func_ov010_0220983c(Ov010Trig *self) {
    return self->b0;
}

void func_ov010_0220984c(Ov010Trig *self, u16 a) {
    self->unk_06 = a;
    self->b1 = 1;
}

Ov010Trig *Ov010Vt_022102a0_Ctor(Ov010Trig *self) {
    self->vtbl = data_ov010_022102a0;
    func_ov000_02198328((u8 *)self + 0x20);
    self->b0 = 0;
    self->b1 = 0;
    return self;
}

struct Obj02209898 {
    void *unk_00;
};

void *Ov010Vt_022102a0_Dtor(Obj02209898 *self) {
    self->unk_00 = data_ov010_022102a0;
    ((Ov010V *)self)->v0c();
    return self;
}

void *Ov010Vt_022102a0_DtorDelete(Obj02209898 *self) {
    self->unk_00 = data_ov010_022102a0;
    ((Ov010V *)self)->v0c();
    func_0203de1c(self);
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
extern void *func_ov000_02198328(void *p);
extern void func_ov003_021da48c(void *p, s32 a);

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
extern Ov010Obj *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov010_0220dbc0(Ov010IdList *l);
extern u16 *func_ov010_0220da74(Ov010IdList *l, Ov010Vec *pos, s32 b, s32 c, s32 d, u16 e, u16 f);
extern void func_ov003_021da48c(void *p, s32 a);

static inline Ov010Obj *Ov010w_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
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

static inline BOOL Ov010w_IsActive(u8 *a) {
    BOOL r = FALSE;
    if (a != NULL) {
        s32 k = FLD(s32, a, 0xd8);
        r = (u32)(k - 1) <= 2;
    }
    return r;
}
static inline void Ov010w_Collect(Ov010IdList *l) {
    if (l->b0) {
        Ov010IdNode *n;
        l->count = 0;
        for (n = l->head; n != NULL; n = n->next) {
            if (Ov010w_IsActive((u8 *)Ov010w_FindActor(n->id)) == TRUE) {
                l->ids[l->count] = n->id;
                l->count++;
            }
        }
    }
}

static inline void Ov010w_StartAll(Ov010Wave *self) {
    s32 i;
    for (i = 0; i < Ov010w_Count(self->list); i++) {
        Ov010Obj *a = Ov010w_FindActor(Ov010w_Get(self->list, i));
        if (a != NULL && a->state != 1 && !FLD(Ov010Flags8, a, 0xce).b0) {
            FLD(Ov010Flags8, a, 0xce).b0 = 1;
            FLD(Ov010Flags8, a, 0xce).b2 = 1;
            func_ov003_021da48c((u8 *)a + 0x158, 3);
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
        Ov010Obj *a;
        Ov010Vec p;
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
            Ov010Obj *a = Ov010w_FindActor(Ov010w_Get(self->list, i));
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
            Ov010Obj *a;
            Ov010Obj *s;
            u16 idx;
            BOOL more;
            if (l->b0) {
                Ov010IdNode *n;
                l->count = 0;
                for (n = l->head; n != NULL; n = n->next) {
                    Ov010Obj *e = Ov010w_FindActor(n->id);
                    if (e != NULL && FLD(s32, e, 0xd8) == 1) {
                        l->ids[l->count] = n->id;
                        l->count++;
                    }
                }
            }
            a = Ov010w_FindActor(Ov010w_Get(self->list, 0));
            idx = self->unk_0c;
            more = idx < self->unk_0a;
            s = Ov010w_FindActor(self->unk_06);
            if (a != NULL && a->state != 1 && s != NULL && more) {
                s32 q = 0x2000 / (self->unk_0a - 1);
                Ov010Vec v;
                Ov010Blk12 t = data_ov010_0220f564;
                t.w[0] = q * idx - 0x1000;
                func_ov003_021d9980(&v, s->rot_y, (Ov010Vec *)&t);
                if (a->state != 1 && !FLD(Ov010Flags8, a, 0xce).b1) {
                    FLD(Ov010Flags8, a, 0xce).b1 = 1;
                    func_ov003_021da48c((u8 *)a + 0x16c, 2);
                    Ov010_VecCopy(&FLD(Ov010Vec, a, 0xfc), &v);
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
                Ov010Obj *a = Ov010w_FindActor(Ov010w_Get(self->list, i));
                if (a != NULL && FLD(Ov010Flags8, a, 0xce).b0) {
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
        ((Ov010V *)self)->v0c();
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
    s32 unk_14;
    s32 unk_18;
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
    Ov010Vec v60;
};

extern "C" {

extern u8 data_ov010_02210260[];

BOOL func_ov010_0220a030(Ov010Trig *self) {
    return self->b0;
}

void func_ov010_0220a040(Ov010Trig *self, u16 a, s32 b, s32 c, s32 d, u16 e, u16 f) {
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
    ((Ov010V *)self)->v0c();
    return self;
}

void *Ov010Vt_02210260_DtorDelete(Obj0220a090 *self) {
    self->unk_00 = data_ov010_02210260;
    ((Ov010V *)self)->v0c();
    func_0203de1c(self);
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
extern Ov010Obj *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov003_021da48c(void *p, s32 a);

static inline Ov010Obj *Ov010_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
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
            Ov010Obj *a = Ov010_FindActor(n->id);
            if (a != NULL && FLD(s32, a, 0xd8) == 2) {
                l->ids[l->count] = n->id;
                l->count++;
            }
        }
    }
    l = (Ov010IdList *)self->unk_08;
    if (Ov010IdList_Count(l) == 0) {
        ((Ov010V *)self)->v0c();
    } else if (self->unk_06 % 3 == 0) {
        Ov010Obj *a = Ov010_FindActor(Ov010IdList_Get(l, 0));
        if (a != NULL && a->state != 1 && !FLD(Ov010Flags8, a, 0xce).b1) {
            FLD(Ov010Flags8, a, 0xce).b1 = 1;
            func_ov003_021da48c((u8 *)a + 0x16c, 3);
            Ov010_VecCopy(&FLD(Ov010Vec, a, 0xfc), &data_ov010_0220f594);
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
extern void *func_ov000_02198328(void *p);
extern void func_ov003_021da48c(void *p, s32 a);

u8 func_ov010_0220a2a0(Obj0220a090 *self) {
    return self->unk_04;
}

Ov010Trig *Ov010Vt_02210240_Ctor(Ov010Trig *self) {
    self->vtbl = data_ov010_02210240;
    func_ov000_02198328((u8 *)self + 0xc);
    self->b0 = 0;
    return self;
}

void *Ov010Vt_02210240_Dtor(Obj0220a2d8 *self) {
    self->unk_00 = data_ov010_02210240;
    ((Ov010V *)self)->v0c();
    return self;
}

void *Ov010Vt_02210240_DtorDelete(Obj0220a2d8 *self) {
    self->unk_00 = data_ov010_02210240;
    ((Ov010V *)self)->v0c();
    func_0203de1c(self);
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
extern Ov010Obj *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218d398(void *obj, u16 id, s32 a, s32 b, s32 c, u8 *d);
extern void *func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern Ov010CNode *func_ov010_0220db74(Ov010CNode *head, Ov010CNode *node);
extern void Ov003Pool_Free(void *p, Ov010CNode *n);

static inline Ov010Obj *Ov010t_Find(u16 id) {
    if (data_ov000_021ccd68 != NULL) {
        return func_ov000_0218e640(data_ov000_021ccd68, id);
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
                        ((Ov010V *)o)->v08();
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
            Ov010Obj *obj = Ov010t_Find(Ov010t_Id(self->coll, i));
            if (obj != NULL) {
                s32 kind = FLD(s32, obj, 0xd8);
                BOOL a = kind == 6 ? TRUE : FALSE;
                BOOL b = kind == 8 ? TRUE : FALSE;
                BOOL c = kind == 5 ? TRUE : FALSE;
                if (a || b || c) {
                    u8 f = 0;
                    func_ov000_0218d398(obj, 0xffff, 0xe, 1, 1, &f);
                } else if (kind == 7) {
                    if (!done) {
                        u8 f = 2;
                        Ov010Vec p;
                        done = TRUE;
                        func_ov000_0218d398(obj, 0xffff, 0xe, 1, 1, &f);
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
            ((Ov010V *)self)->v0c();
        }
        break;
    }
}

}
}  // namespace m_0220a2a0

// ---- merged from ov010_0220a6a0.cpp
struct Obj0220a6b0 : public Ov010Obj {
    u8 unk_ac[0x20];
    Ov010Flags unk_cc;
    Ov010Flags8 unk_ce;
    u8 unk_cf;
    u16 unk_d0;
    u16 unk_d2;
    u16 unk_d4;
    u16 unk_d6;
    s32 unk_d8;
    s32 unk_dc;
    s32 *unk_e0;
    Ov010Vec *unk_e4;
    u8 *unk_e8;
    u8 *unk_ec;
    Ov010Vec unk_f0;
    Ov010Vec unk_fc;
    Ov010Vec unk_108;
    Ov010Vec unk_114;
    u8 unk_120[0x60];
    u16 unk_180;
    u16 unk_182;
    Ov010Vec unk_184;
    Ov010Rot3 unk_190;
    Ov010Rot3 unk_196;
};

namespace m_0220a6a0 {
struct Ov010Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
};

extern "C" {

extern u8 data_ov010_02210378[];
extern void *func_ov000_02194074(void *self);
extern void *Ov003Vt_021f7d2c_Ctor(void *p);
extern void *func_ov000_02198328(void *p);
extern void func_ov010_0220c49c(Obj0220a6b0 *self);

BOOL func_ov010_0220a6a0(Obj0220a2d8 *self) {
    return self->unk_04.b0;
}

void *Ov010ActVt_02210378_Ctor(Obj0220a6b0 *self) {
    func_ov000_02194074(self);
    *(void * *)self = data_ov010_02210378;
    Ov003Vt_021f7d2c_Ctor((u8 *)self + 0x120);
    func_ov000_02198328((u8 *)self + 0x158);
    func_ov000_02198328((u8 *)self + 0x16c);
    func_ov010_0220c49c(self);
    return self;
}


extern Ov010Heap *data_02097dd0;
extern void *data_0214a420;
extern u8 data_ov010_02210378[];
extern void func_02065804(void *a, s32 b);
extern void *Ov003Vt_021f7d2c_Dtor(void *p);
extern void *func_ov000_0219429c(void *self);
extern void func_ov010_0220c49c(Obj0220a6b0 *self);

static inline void Ov010FxA_Dtor(u8 *p) {
    if (FLD(Ov010Flags8, p, 0).b0) {
        func_02065804(data_0214a420, FLD(s32, p, 4));
        FLD(Ov010Flags8, p, 0).b0 = 0;
    }
}

static inline void Ov010FxB_Dtor(u8 *p) {
    if (FLD(Ov010Flags8, p, 0).b0) {
        func_02065804(data_0214a420, FLD(s32, p, 8));
        FLD(s32, p, 8) = 0;
        FLD(Ov010Flags8, p, 0).b0 = 0;
    }
}

static inline void Ov010_FreeFxA(Obj0220a6b0 *self, u32 off) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, off) != NULL) {
        u8 *p = FLD(u8 *, self, off);
        if (p != NULL) {
            Ov010FxA_Dtor(p);
            func_0203de1c(p);
        }
        FLD(void *, self, off) = NULL;
    }
    data_02097dd0->cur = saved;
}

static inline void Ov010_FreeFxB(Obj0220a6b0 *self, u32 off) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, off) != NULL) {
        u8 *p = FLD(u8 *, self, off);
        if (p != NULL) {
            Ov010FxB_Dtor(p);
            func_0203de1c(p);
        }
        FLD(void *, self, off) = NULL;
    }
    data_02097dd0->cur = saved;
}

static inline void Ov010Boss_Dtor(Obj0220a6b0 *self) {
    *(void * *)self = data_ov010_02210378;
    Ov010_FreeFxA(self, 0xe8);
    Ov010_FreeFxB(self, 0xec);
    ((Ov010V *)((u8 *)self + 0x120))->v08();
    func_ov010_0220c49c(self);
    Ov003Vt_021f7d2c_Dtor((u8 *)self + 0x120);
    func_ov000_0219429c(self);
}

void *Ov010ActVt_02210378_Dtor(Obj0220a6b0 *self) {
    Ov010Boss_Dtor(self);
    return self;
}

void *Ov010ActVt_02210378_DtorDelete(Obj0220a6b0 *self) {
    Ov010Boss_Dtor(self);
    func_0203de1c(self);
    return self;
}
}
}  // namespace m_0220a6a0

// ---- merged from ov010_0220a948.cpp
namespace m_0220a948 {
extern "C" {

struct Obj0220a948 {
    u8 unk_00[0xd0];
    u16 unk_d0;
    u16 unk_d2;
    u8 unk_d4[0x8];
    s32 unk_dc;
    s32 unk_e0;
    s32 unk_e4;
};

static inline void Ov010_0220a948_Set(Obj0220a948 *self, u16 c, u16 d, s32 mode, s32 a, s32 b) {
    self->unk_d0 = c;
    self->unk_d2 = d;
    self->unk_dc = mode;
    self->unk_e0 = a;
    self->unk_e4 = b;
}

void func_ov010_0220a948(Obj0220a948 *self, s32 mode, s32 a, s32 b, u16 c, u16 d) {
    switch (mode) {
    case 0:
        Ov010_0220a948_Set(self, c, d, mode, a, 0);
        break;
    case 1:
        Ov010_0220a948_Set(self, c, d, mode, 0, b);
        break;
    }
}


struct Ov010Mtx33a {
    s32 m[9];
};

extern void *data_ov000_021ccd68;
extern Ov010Obj *func_ov000_0218e640(void *mgr, u16 id);
extern void MTX_Identity33_(Ov010Mtx33a *m);
extern void MTX_RotX33_(Ov010Mtx33a *m, s32 s, s32 c);
extern void MTX_RotY33_(Ov010Mtx33a *m, s32 s, s32 c);
extern void MTX_RotZ33_(Ov010Mtx33a *m, s32 s, s32 c);
extern void MTX_Concat33(Ov010Mtx33a *a, Ov010Mtx33a *b, Ov010Mtx33a *out);
extern void MI_Copy36B(const void *src, void *dst);
extern BOOL func_ov000_02194c08(void *self);

void Ov010ActVt_02210378_Draw(Obj0220a6b0 *self) {
    Ov010Mtx33a out;
    Ov010Mtx33a tc;
    Ov010Mtx33a ma;
    Ov010Mtx33a mb;
    Ov010Mtx33a ta;
    Ov010Mtx33a tb;
    Ov010Obj *o;
    self->unk_93.b0 = 1;
    o = NULL;
    if (self->unk_d8 == 7) {
        void *mgr = data_ov000_021ccd68;
        u16 id = self->unk_180;
        if (mgr != NULL) {
            o = func_ov000_0218e640(mgr, id);
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
        dx = o->rot_x - FLD(u16, self, 0x190);
        dy = o->rot_y - FLD(u16, self, 0x192);
        dz = o->rot_z - FLD(u16, self, 0x194);
        az = FLD(u16, self, 0x19a);
        ay = FLD(u16, self, 0x198);
        ax = FLD(u16, self, 0x196);
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
    MI_Copy36B(&out, (u8 *)self->unk_38 + 0x84);
    {
        u8 *m = (u8 *)self->unk_38;
        FLD(s32, m, 0x78) = self->pos.x;
        FLD(s32, m, 0x7c) = self->pos.y;
        FLD(s32, m, 0x80) = self->pos.z;
    }
    func_ov000_02194c08(self);
}

}
}  // namespace m_0220a948

// ---- merged from ov010_0220adb8.cpp
namespace m_0220adb8 {
extern "C" {
extern void *data_0214a420;
extern void func_02065860(void *a, s32 b);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void func_ov003_021da48c(void *p, s32 a);
extern BOOL func_ov000_021950e8(void *self, u8 *msg);

static inline void Ov010FxB_Stop(u8 *p) {
    if (FLD(Ov010Flags8, p, 0).b0) {
        func_02065860(data_0214a420, FLD(s32, p, 8));
        FLD(s32, p, 8) = 0;
        func_ov000_02198360(p + 0x58, 1, 0);
    }
}

static inline void Ov010FxB_Start(u8 *p) {
    if (FLD(Ov010Flags8, p, 0).b0) {
        FLD(u16, p, 2) = 0;
        FLD(u16, p, 4) = 0x50;
        func_ov003_021da48c(p + 0x58, 2);
    }
}

BOOL func_ov010_0220adb8(Obj0220a6b0 *self, u8 *msg) {
    BOOL r;
    if (msg[5] == 0xe) {
        switch (msg[8]) {
        case 4:
            self->unk_ce.b3 = 1;
            if (self->unk_d8 == 7) {
                break;
            }
        case 1:
            func_ov000_02198360(((void *)self->unk_40), 0x15, 0);
            break;
        case 0:
            Ov010FxB_Stop(self->unk_ec);
            Ov010FxB_Start(self->unk_ec);
            break;
        case 2:
            func_ov000_02198360(((void *)self->unk_40), 6, 0);
            break;
        case 3:
            func_ov000_02198360(((void *)self->unk_40), 0x12, 0);
            break;
        }
        r = TRUE;
        self->msg_flags |= 1 << msg[5];
        msg[5] = 0;
    } else {
        r = func_ov000_021950e8(self, msg);
    }
    return r;
}

extern void func_ov000_02194758(void *self);
extern void *func_ov000_02198328(void *p);
extern void func_0203f364(void *p);
extern BOOL func_ov010_0220e740(void *self, void *a, const void *b, s32 c, const Ov010Vec *v, s32 e);

static inline u8 *Ov010FxA_New(void) {
    u8 *p = (u8 *)func_0203dd9c(0x28);
    if (p != NULL) {
        func_ov000_02198328(p + 0x14);
        FLD(Ov010Flags8, p, 0).b0 = 0;
    }
    return p;
}

static inline u8 *Ov010FxB_New(void) {
    u8 *p = (u8 *)func_0203dd9c(0x6c);
    if (p != NULL) {
        func_ov000_02198328(p + 0x58);
        FLD(Ov010Flags8, p, 0).b0 = 0;
    }
    return p;
}

void Ov010ActVt_02210378_Start(Obj0220a6b0 *self) {
    u8 *p;
    func_ov000_02194758(self);
    func_ov000_02198360(((void *)self->unk_40), 1, 0);
    func_ov000_02198360((u8 *)self + 0x158, 1, 0);
    self->unk_d8 = 1;
    self->unk_e8 = p = Ov010FxA_New();
    FLD(Ov010Flags8, p, 0).b0 = 1;
    FLD(Ov010Flags8, p, 0).b1 = 0;
    FLD(Ov010Flags8, p, 0).b2 = 0;
    FLD(u16, p, 2) = 0;
    FLD(s32, p, 4) = 0;
    FLD(Ov010Vec, p, 8) = data_ov010_0220f594;
    func_ov003_021da48c(p + 0x14, 0);
    self->unk_ec = Ov010FxB_New();
    func_ov010_0220e740(self->unk_ec, self, &data_ov010_0220f534, 1, &data_ov010_0220f594, 0x68);
    if (FLD(Ov010Flags8, self->unk_ec, 0).b0) {
        FLD(s32, self->unk_ec, 0x14) = 0x4000;
    }
    self->unk_cc.b4 = 0;
    {
        ActorSub48 *mm = self->unk_48;
        FLD(Ov010Flags, mm, 0x9a).b0 = 0;
        mm->unk_9a_3 = 0;
        func_0203f364(mm);
    }
    {
        u8 *q = (u8 *)self->unk_44;
        FLD(Ov010Flags, q, 0x22).b0 = 0;
        FLD(Ov010Flags, q, 0x22).b1 = 0;
    }
    FLD(Ov010Flags, self->unk_38, 0xc2).b0 = 0;
    {
        u8 *m = (u8 *)self->unk_38;
        FLD(s32, m, 0xa8) = 0x1400;
        FLD(s32, m, 0xac) = 0x1400;
        FLD(s32, m, 0xb0) = 0x1400;
    }
    FLD(u16, ((void *)self->unk_4c), 0x1c) = self->unk_d0;
    FLD(Ov010Flags8, ((void *)self->unk_4c), 0x18).b4 = 1;
    self->unk_48->unk_9a_7 = 1;
    self->unk_48->unk_48 = self->unk_64 + (self->unk_64 >> 1);
    self->unk_cf = 1;
}


}

class Ov010Ac {
public:
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0x36];
    u8 *unk_44;
    u8 unk_48[0x28];
    Ov010Vec unk_70;
    u8 unk_7c[0x52];
    u8 f0 : 1;
    u8 f1 : 1;
    u8 f2 : 6;
    u8 unk_cf[0x9];
    s32 unk_d8;
    u8 unk_dc[0xc];
    void *unk_e8;
    void *unk_ec;
    u8 unk_f0[0x7b];
    u8 key16b;
    u8 unk_16c[0x13];
    u8 key17f;
};

typedef void (Ov010Ac::*Ov010AcFn)();

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
extern void func_ov000_021953b4(void *self);
extern void func_ov010_0220c5a0(void *self);
extern u8 *func_ov000_0219bf90(void);
extern Ov010Obj *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov010_0220e38c(void *p);
extern void func_ov010_0220e7c8(void *p);
extern void MTX_Identity33_(Ov010Mtx33 *m);
extern void MTX_RotX33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_RotY33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_RotZ33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_Concat33(Ov010Mtx33 *a, Ov010Mtx33 *b, Ov010Mtx33 *out);
extern void MTX_MultVec33(Ov010Vec *v, Ov010Mtx33 *m, Ov010Vec *out);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);

void Ov010ActVt_02210378_Update(Ov010Ac *self) {
    Ov010Vec t;
    Ov010Mtx33 tmp;
    Ov010Mtx33 m;
    func_ov000_021953b4(self);
    if (self->f0) {
        u32 i;
        u8 key = self->key16b;
        for (i = 0; i < 2; i++) {
            if (key == data_ov010_0220f5a0[i].key && *(s32 *)&data_ov010_0220f5a0[i].fn != 0) {
                (self->*data_ov010_0220f5a0[i].fn)();
                break;
            }
        }
    }
    if (self->f1) {
        u32 i;
        u8 key = self->key17f;
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
        u8 *p = ((u8 *)self->unk_ec);
        u8 n;
        if (FLD(Ov010Flags8, p, 0).b0) {
            n = FLD(u8, p, 0x6b);
        } else {
            n = 0;
        }
        if (n == 4) {
            FLD(Ov010Flags, self->unk_44, 0x22).b1 = 0;
        }
        {
            u8 *q = self->unk_44;
            FLD(Ov010Flags, q, 0x22).b0 = 1;
            FLD(Ov010Flags, q, 0x22).b1 = 1;
        }
        u16 a = FLD(u16, func_ov000_0219bf90(), 0xb1c);
        if (a == self->unk_0c) {
            self->unk_d8 = 8;
        }
        break;
    }
    case 7: {
        void *mgr = data_ov000_021ccd68;
        u16 id = FLD(u16, self, 0x180);
        u8 *o = mgr == NULL ? NULL : (u8 *)func_ov000_0218e640(mgr, id);
        if (o != NULL) {
            u16 rx;
            u16 ry;
            u16 rz;
            BOOL set;
            t = FLD(Ov010Vec, o, 0x70);
            set = FALSE;
            rz = FLD(u16, o, 0x80) - FLD(u16, self, 0x194);
            ry = FLD(u16, o, 0x7e) - FLD(u16, self, 0x192);
            rx = FLD(u16, o, 0x7c) - FLD(u16, self, 0x190);
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
            MTX_MultVec33(&FLD(Ov010Vec, self, 0x184), &m, &self->unk_70);
            VEC_Add(&self->unk_70, &t, &self->unk_70);
        }
        break;
    }
    }
    if (self->unk_e8 != NULL) {
        func_ov010_0220e38c(self->unk_e8);
    }
    if (self->unk_ec != NULL) {
        func_ov010_0220e7c8(self->unk_ec);
    }
    ((Ov010V *)((u8 *)self + 0x120))->v0c();
}

}
}  // namespace m_0220adb8

// ---- merged from ov010_0220b7b0.cpp
namespace m_0220b7b0 {
extern "C" {

extern void *data_ov000_021ccd68;
extern Ov010Obj *func_ov000_0218e640(void *mgr, u16 id);
extern Ov010V *func_02065f88(s32 a, Ov010Vec *b);
extern void func_ov010_02209074(void *p);
extern void func_ov000_0218d398(void *obj, u16 id, s32 a, s32 b, s32 c, u8 *d);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern BOOL func_ov000_02190cb0(void *p, const void *a, s32 b, s32 c);
extern void func_ov000_021915a0(void *p);
extern u8 *func_ov000_02190a30(void *p, s32 a);
extern void func_ov000_02195d88(void *self);

static inline Ov010Obj *Ov010_FindObjById(u16 id) {
    if (data_ov000_021ccd68 != NULL) {
        return func_ov000_0218e640(data_ov000_021ccd68, id);
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

extern void *data_0214a420;
extern void func_02065860(void *a, void *b);
extern void func_ov003_021da48c(void *p, s32 a);
extern void *func_ov000_0218e4cc(void *mgr, s32 a);
extern s32 func_ov000_0219a874(void *a, void *b, s32 c);
extern u16 func_ov010_02207a44(s32 i);
extern void func_ov000_0219bdb0(u16 a, u16 b, s32 c, s32 d, s32 e, Ov010AnMsg *msg);
extern void func_ov000_0218e8ec(void *mgr, u16 id, s32 msg);

// Reads the effect's flag through a const view, which is not merged with the later plain
// reads of the same byte.
static inline u8 Ov010_FxCount(const u8 *fx) {
    u8 n;
    if (FLD(const Ov010Flags8, fx, 0).b0) {
        n = FLD(const u8, fx, 0x6b);
    } else {
        n = 0;
    }
    return n;
}

void func_ov010_0220b40c(Obj0220a6b0 *self) {
    Ov010Vec p;
    Ov010Blk12 q;
    Ov010AnMsg msg;
    u8 c;
    switch (self->unk_40->st) {
    case 0: {
        u8 *fx = self->unk_ec;
        if (Ov010_FxCount(fx) == 1) {
            if (FLD(Ov010Flags8, fx, 0).b0) {
                func_02065860(data_0214a420, FLD(void *, fx, 8));
                FLD(s32, fx, 8) = 0;
                func_ov000_02198360(fx + 0x58, 1, 0);
            }
            fx = self->unk_ec;
            if (FLD(Ov010Flags8, fx, 0).b0) {
                FLD(u16, fx, 2) = 0;
                FLD(u16, fx, 4) = 0x50;
                func_ov003_021da48c(fx + 0x58, 2);
            }
            self->unk_ce.b3 = 0;
        }
        self->unk_d6 = 0;
        self->unk_40->st = 1;
    }
    case 1:
        if (self->unk_ce.b3) {
            self->unk_40->st = 2;
        }
        return;
    case 2:
        if (self->unk_40->timer % 8 == 0) {
            BOOL found = FALSE;
            u8 *o = FLD(u8 *, func_ov000_0218e4cc(data_ov000_021ccd68, 0x4000), 0xc);
            for (; o != NULL; o = FLD(u8 *, o, 8)) {
                if (o != (u8 *)self && FLD(u16, o, 0xe) == 0x4817) {
                    BOOL ok = FALSE;
                    if (o != NULL && FLD(s32, o, 0xd8) == 7) {
                        u8 *s = FLD(u8 *, o, 0x40);
                        if ((s != NULL ? FLD(u8, s, 0x13) : 0) != 0x12) {
                            ok = TRUE;
                        }
                    }
                    if (ok) {
                        c = 3;
                        found = TRUE;
                        func_ov000_0218d398(o, self->id, 0xe, 1, 1, &c);
                        self->unk_d6++;
                        break;
                    }
                }
            }
            if (!found) {
                self->unk_40->st = 3;
            }
        }
        self->unk_40->timer++;
        return;
    case 3: {
        Ov010Obj *a;
        Ov010Obj *b;
        Ov010V *e;
        self->unk_d6++;
        a = Ov010_FindObjById(self->unk_180);
        b = Ov010_FindObjById(self->unk_182);
        if (a != NULL && b != NULL) {
            u16 ang = func_ov000_0219a874(((void *)a->hp), ((void *)b->hp), func_ov010_02207a44(self->unk_d6));
            msg.f0 = 0;
            msg.f1 = self->unk_d6;
            msg.ang = ang;
            msg.kind = 0x11;
            msg.id = self->id;
            func_ov000_0219bdb0(self->unk_180, self->unk_182, 0xe, 0, 8, &msg);
            p.x = a->pos.x;
            p.y = a->pos.y;
            p.z = a->pos.z;
            e = func_02065f88(0x38f, &p);
            e->v0c(0x2800);
            e->v24(0, a->unk_68 >> 1, 0);
        }
        q = FLD(Ov010Blk12, self, 0x70);
        e = func_02065f88(0x321, (Ov010Vec *)&q);
        e->v0c(0x1000);
        FLD(void *, e, 0xdc) = (void *)func_ov010_02209074;
        FLD(s32, e, 4) = 6;
        FLD(Ov010Flags, self->unk_38, 0xc2).b0 = 0;
        self->unk_40->st = 4;
        return;
    }
    case 4:
        func_ov000_02198360(((void *)self->unk_40), 0x15, 0);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4817, 0x15);
        break;
    }
}

void func_ov010_0220b7b0(Obj0220a6b0 *self) {
    if (self->unk_40->st != 0) {
        return;
    }
    Ov010Vec p = self->pos;
    Ov010V *fx;
    void *obj;
    fx = func_02065f88(0x321, &p);
    fx->v0c(0x1000);
    FLD(void *, fx, 0xdc) = (void *)func_ov010_02209074;
    FLD(s32, fx, 4) = 6;
    obj = Ov010_FindObjById(self->unk_180);
    if (obj != NULL) {
        u8 c = 1;
        func_ov000_0218d398(obj, self->id, 0xe, 1, 1, &c);
    }
    FLD(Ov010Flags, self->unk_38, 0xc2).b0 = 0;
    self->unk_cf = 0;
    func_ov000_02198360(((void *)self->unk_40), 0x15, 0);
}

void func_ov010_0220b890(Obj0220a6b0 *self) {
    if (self->unk_40->st != 0) {
        return;
    }
    if (self->unk_38 != NULL) {
        func_ov000_02190cb0(self->unk_38, data_ov010_0220f540, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
    }
    self->unk_40->st = 1;
    self->unk_9c = 0;
    self->unk_a0 = 0;
    self->unk_a4 = 0;
    self->unk_a8 = 0;
}

void func_ov010_0220b8f8(Obj0220a6b0 *self) {
    u8 *p = func_ov000_02190a30(self->unk_38, 0);
    FLD(Ov010Flags8, p, 0x111).b3 = 0;
    func_ov000_02195d88(self);
}

extern void *data_02097e4c;
extern void func_0203f324(void *p);
extern void func_0203f364(void *p);
extern void func_ov000_0218dbe0(void *self, s32 a);
extern void MTX_RotY33_(void *m, s32 s, s32 c);
extern void MTX_MultVec33(const Ov010Vec *v, const void *m, Ov010Vec *out);
extern u16 Ov003Vec_Yaw(Ov010Vec *v);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *c);
extern void VEC_Normalize(const Ov010Vec *a, Ov010Vec *b);
extern void func_ov003_021d9e90(Ov010Vec *a, Ov010Vec *b, Ov010Vec *c, s32 d, s32 e);
extern void func_ov003_021da2c8(void *self, s32 a, s32 b, s32 c, s32 d);
extern void Ov003Vec_ToRot(void *out, const void *p);
extern void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
extern s32 func_02040498(s32 max);
extern void *func_ov000_02199ba0(void *p);
extern Ov010V *func_ov003_021da7e8(s32 id, void *src, const Ov010Vec *ofs);
extern void *func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern s32 Ov003Vec_DistSq(const Ov010Vec &a, const Ov010Vec *b);

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

static inline void Ov010_VecSubA(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out) {
    s32 ax = a->x;
    s32 ay = a->y;
    s32 az = a->z;
    out->x = ax - b->x;
    out->y = ay - b->y;
    out->z = az - b->z;
}

static inline void Ov010_VecSubB(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out) {
    s32 bx = b->x;
    s32 by = b->y;
    s32 bz = b->z;
    out->x = a->x - bx;
    out->y = a->y - by;
    out->z = a->z - bz;
}

static inline void *Ov010_FindObjById2(u16 id) {
    void *o = NULL;
    if (data_ov000_021ccd68 != NULL) {
        o = func_ov000_0218e640(data_ov000_021ccd68, id);
    }
    return o;
}

static inline void *Ov010_FindObjById3(u16 id) {
    return data_ov000_021ccd68 != NULL ? func_ov000_0218e640(data_ov000_021ccd68, id) : NULL;
}

static inline Ov010Vec Ov010_TargetCenter(Obj0220a6b0 *self) {
    Ov010Vec v;
    Ov010Vec *b = self->unk_e4;
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
    Ov010Vec d;
    Ov010Vec v1;
    Ov010Vec v2;
    Ov010Mtx33 m;
    Ov010Vec o;
    Ov010Vec p;
    Ov010Vec d2;
    Ov010HitMsg msg;
    void *s40 = ((void *)self->unk_40);
    switch (FLD(u16, s40, 0)) {
    case 0:
    case 0x10: {
        ActorSub48 *mm = self->unk_48;
        FLD(Ov010Flags, mm, 0x9a).b0 = 1;
        mm->unk_9a_3 = 1;
        func_0203f324(mm);
        self->unk_48->unk_30 = 0;
        self->unk_a4 = 0;
        self->unk_98 = self->rot_y;
        self->unk_9c = 0x2b0;
        self->unk_a0 = 0x80;
        self->unk_a8 = 0x20;
        self->unk_40->st = 0x11;
        break;
    }
    case 0x11:
        FLD(u16, s40, 2)++;
        if (self->unk_40->timer >= 0xc) {
            self->unk_40->timer = 0;
            self->unk_40->st = 0x20;
        }
        func_ov000_0218dbe0(self, 0);
        break;
    case 0x20:
        self->unk_a4 = 0xa00;
        func_ov000_0218dbe0(self, 0);
        self->unk_40->st = 0x21;
        break;
    case 0x21: {
        s32 k;
        FLD(u16, s40, 2)++;
        self->unk_40->timer = 0;
        self->unk_40->st = 0x30;
        func_ov000_0218dbe0(self, 0);
        k = self->unk_a4;
        if (k != 0 && k != 0x1000) {
            self->unk_a0 = Ov010_FxMul(self->unk_a0, k);
        }
        break;
    }
    case 0x30: {
        void *t;
        BOOL ok;
        self->unk_98 = self->rot_y;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_9c = 0;
        t = Ov010_FindObjById2(self->target);
        ok = FALSE;
        if (t != NULL) {
            BOOL b;
            BOOL a;
            void *q;
            s32 dot;
            u16 ang;
            Ov010_VecSubA(&FLD(Ov010Vec, t, 0x70), &self->pos, &d);
            q = FLD(void *, t, 0x40);
            a = (q != NULL ? FLD(u8, q, 0x13) : 0) == 0x13;
            b = FALSE;
            MTX_RotY33_(&m, OV010_SIN(self->unk_98), OV010_COS(self->unk_98));
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
            o.y += OV010_FXMUL_K(FLD(s32, t, 0x68), 0x99a);
            p.x = FLD(s32, t, 0x70);
            p.y = FLD(s32, t, 0x74);
            p.z = FLD(s32, t, 0x78);
            VEC_Add(&p, &o, &p);
            self->unk_108.x = p.x - self->pos.x;
            self->unk_108.y = p.y - self->pos.y;
            self->unk_108.z = p.z - self->pos.z;
            VEC_Normalize(&self->unk_108, &self->unk_108);
        } else {
            func_ov003_021d9900(&self->unk_108, 0xfc71, &data_ov010_0220f54c);
            func_ov003_021d9980(&self->unk_108, self->rot_y, &self->unk_108);
        }
        self->unk_40->st = 0x31;
        break;
    }
    case 0x31: {
        s32 sp;
        ActorSub48 *s48;
        sp = self->unk_9c + 0x180;
        self->unk_9c = sp;
        if (sp > 0x1666) {
            sp = 0x1666;
        } else if (sp < 0) {
            sp = 0;
        }
        self->unk_9c = sp;
        func_ov003_021d9e90(&self->pos, &self->unk_108, &self->pos, self->unk_9c, self->unk_a0);
        func_ov003_021da2c8(self, self->unk_9c, self->unk_a0, self->unk_a4, self->unk_a8);
        Ov003Vec_ToRot(&self->rot_x, &self->unk_108);
        s48 = self->unk_48;
        s48->unk_44 = OV010_FXMUL_K(s48->unk_38, 0x800);
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (self->unk_48->unk_58 & 0x20) {
            void *t = Ov010_FindObjById2(self->target);
            void *q;
            Ov010V *e;
            if (t == NULL) {
                self->unk_40->st = 0x50;
                return;
            }
            self->unk_180 = FLD(u16, t, 0xc);
            FLD(Ov010Flags8, func_ov000_02190a30(self->unk_38, 0), 0x111).b3 = 1;
            self->rot_x += (u16)(func_02040498(0x2000) - 0x1000);
            self->rot_y += (u16)(func_02040498(0x2000) - 0x1000);
            q = func_ov000_02199ba0(((void *)self->unk_4c));
            if (q != NULL) {
                self->unk_182 = FLD(u16, q, 0xc);
                msg.a = func_ov000_0219a874(FLD(void *, t, 0x50), FLD(void *, q, 0x50), 0x14);
                msg.b = 0x10;
                msg.id = self->id;
                func_ov000_0218d398(t, self->id, 9, 0, 6, (u8 *)&msg);
            }
            Ov010_VecSubB(&self->pos, &FLD(Ov010Vec, t, 0x70), &d2);
            func_ov003_021d9980(&d2, (u16)(0xffff - FLD(u16, t, 0x7e)), &d2);
            e = func_ov003_021da7e8(0x6c, t, &d2);
            e->v34((u16)(self->rot_x + 0x4000), 0, 0);
            e->v0c(0x1800);
            self->unk_40->st = 0x40;
            func_02049f44(data_02097e4c, 0x66, &self->pos, 0);
            return;
        }
        if (Ov003Vec_DistSq(Ov010_TargetCenter(self), &self->pos) > 0x190000) {
            self->unk_40->st = 0x50;
        }
        break;
    }
    case 0x40: {
        void *t = Ov010_FindObjById3(self->unk_180);
        u8 *ec;
        BOOL found;
        if (t == NULL) {
            self->unk_40->st = 0x50;
            return;
        }
        Ov010_VecSubB(&self->pos, &FLD(Ov010Vec, t, 0x70), &self->unk_184);
        FLD(u16, self, 0x190) = FLD(u16, t, 0x7c);
        FLD(u16, self, 0x192) = FLD(u16, t, 0x7e);
        FLD(u16, self, 0x194) = FLD(u16, t, 0x80);
        FLD(u16, self, 0x196) = self->rot_x;
        FLD(u16, self, 0x198) = self->rot_y;
        FLD(u16, self, 0x19a) = self->rot_z;
        self->unk_d8 = 7;
        {
            ActorSub48 *mm = self->unk_48;
            FLD(Ov010Flags, mm, 0x9a).b0 = 0;
            mm->unk_9a_3 = 0;
            func_0203f364(mm);
        }
        self->unk_40->st = 0x41;
        ec = self->unk_ec;
        if ((FLD(Ov010Flags8, ec, 0).b0 ? ec[0x6b] : 0) == 1) {
            return;
        }
        found = FALSE;
        {
            void *g = func_ov000_0218e4cc(data_ov000_021ccd68, 0x4000);
            void *it;
            for (it = FLD(void *, g, 0xc); it != NULL; it = FLD(void *, it, 8)) {
                if (it != self && FLD(u16, it, 0xe) == 0x4817 && FLD(s32, it, 0xd8) == 7) {
                    found = TRUE;
                    break;
                }
            }
        }
        if (found) {
            ec = self->unk_ec;
            if (!FLD(Ov010Flags8, ec, 0).b0) {
                return;
            }
            func_02065860(data_0214a420, FLD(void *, ec, 8));
            FLD(void *, ec, 8) = NULL;
            func_ov000_02198360(ec + 0x58, 1, 0);
            return;
        }
        func_ov000_02198360(((void *)self->unk_40), 6, 0);
        break;
    }
    case 0x41:
        break;
    case 0x50: {
        func_ov000_02198360(s40, 0x15, 0);
        {
            ActorSub48 *mm = self->unk_48;
            FLD(Ov010Flags, mm, 0x9a).b0 = 0;
            mm->unk_9a_3 = 0;
            func_0203f364(mm);
        }
        {
            Ov010Flags *f = &FLD(Ov010Flags, self->unk_44, 0x22);
            f->b0 = 0;
            f->b1 = 0;
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
extern void *data_ov000_021ccd54;
extern void func_0203f324(void *p);
extern void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
extern void func_ov000_0218d398(void *obj, u16 id, s32 a, s32 b, s32 c, u8 *d);
extern void func_ov000_0218dbe0(void *self, s32 a);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);
extern Ov010V *func_02065f88(s32 a, void *b);
extern void func_ov000_0219763c(void *self);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 mask, Ov010Vec *v, s32 e, s32 f, s32 g, s32 h, s32 i);

void func_ov010_0220c2a4(Obj0220a6b0 *self) {
    void *m;
    switch (self->unk_40->st) {
    case 0:
        m = self->unk_48;
        FLD(Ov010Flags, m, 0x9a).b0 = 1;
        FLD(Ov010Flags, m, 0x9a).b3 = 1;
        func_0203f324(m);
        m = self->unk_44;
        FLD(Ov010Flags, m, 0x22).b0 = 0;
        FLD(Ov010Flags, m, 0x22).b1 = 0;
        self->unk_a8 = 0x52;
        self->unk_40->st++;
        break;
    case 1:
        if (self->unk_48 != NULL) {
            func_ov000_021987b8(self->unk_48, 1, 0, 0);
            if (self->unk_48->unk_50 & 0x20000000) {
                u8 c = 1;
                func_ov000_0218d398(self, self->id, 0xe, 1, 1, &c);
            }
        }
        break;
    }
    func_ov000_0218dbe0(self, 0);
}

void func_ov010_0220c390(Obj0220a6b0 *self) {
    if (self->unk_40->st == 0) {
        u8 *g;
        Ov010V *fx;
        if (self->unk_cf != 0) {
            func_02049f44(data_02097e4c, 0x19, &self->pos, 0);
        }
        g = (u8 *)data_ov000_021ccd54;
        FLD(Ov010Flags8, g, 0x190).b2 = 1;
        FLD(Ov010Flags8, g, 0x190).b3 = 1;
        FLD(Ov010Flags8, g, 0x190).b4 = 1;
        g[0x18d] = 5;
        g[0x18e] = 0xf;
        g[0x18f] = 0xf;
        fx = func_02065f88(0x38f, &self->pos);
        fx->v24(0, 0x800, 0);
        fx->v0c(0x1800);
    }
    func_ov000_0219763c(self);
    func_ov000_0219aae8(self, self, FLD(u16, ((void *)self->unk_4c), 0x8), FLD(u16, ((void *)self->unk_4c), 0xa), 2, NULL, 0, 0x1b33, 0, 0x57e, 0x1000);
}
extern void func_ov003_021da48c(void *p, s32 a);

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
    self->unk_e8 = 0;
    self->unk_ec = 0;
    Ov010_VecCopy(&self->unk_f0, &data_ov010_0220f594);
    x = self->unk_f0.x;
    y = self->unk_f0.y;
    z = self->unk_f0.z;
    Ov010_VecSet(&self->unk_fc, x, y, z);
    Ov010_VecSet(&self->unk_108, x, y, z);
    Ov010_VecSet(&self->unk_114, x, y, z);
    func_ov003_021da48c((u8 *)self + 0x158, 0);
    func_ov003_021da48c((u8 *)self + 0x16c, 0);
    self->unk_180 = 0xffff;
    self->unk_182 = 0xffff;
    Ov010_VecSet(&self->unk_184, x, y, z);
    {
        const Ov010Rot3 *s = &data_ov010_0220f544;
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
extern Ov010Obj *func_ov000_0218e640(void *mgr, u16 id);
extern void VEC_MultAdd(s32 s, const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);
extern BOOL func_ov010_022090b4(s32 type, s32 *a, Ov010Vec *b, Ov010Vec *pos);
extern u16 func_ov010_02209190(s32 type, s32 *a, Ov010Vec *b, Ov010Vec *pos, u16 rot);
extern s32 func_ov000_0219a2f4(Ov010Vec *p, s32 a, s32 b);

static inline Ov010Obj *Ov010_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline Ov010Vec Ov010_PathPoint(s32 type, s32 *a, Ov010Vec *b) {
    Ov010Vec v;
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

static inline void Ov010_VecSub(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out) {
    s32 ax = a->x;
    s32 ay = a->y;
    s32 az = a->z;
    out->x = ax - b->x;
    out->y = ay - b->y;
    out->z = az - b->z;
}

static inline void Ov010_Approach(Ov010Vec *pos, const Ov010Vec *target, s32 rate) {
    Ov010Vec d;
    Ov010_VecSub(target, pos, &d);
    VEC_MultAdd(rate, &d, pos, pos);
}

void func_ov010_0220c5a0(void *self) {
    Ov010Vec r;
    switch (FLD(u8, self, 0x16b)) {
    case 1:
        return;
    case 2: {
        Ov010Obj *a = Ov010_FindActor(FLD(u16, self, 0xd2));
        u8 *m;
        if (a == NULL || (m = ((u8 *)a->unk_48)) == NULL) {
            return;
        }
        Ov010_Approach(&FLD(Ov010Vec, self, 0xf0), &FLD(Ov010Vec, m, 0x68), 0x11f);
        break;
    }
    case 3: {
        FLD(s32, self, 0xf4) = Ov010_PathPoint(FLD(s32, self, 0xdc), FLD(s32 *, self, 0xe0), FLD(Ov010Vec *, self, 0xe4)).y;
        if (func_ov010_022090b4(FLD(s32, self, 0xdc), FLD(s32 *, self, 0xe0), FLD(Ov010Vec *, self, 0xe4), &FLD(Ov010Vec, self, 0xf0))) {
            FLD(u16, self, 0xd4) = func_ov010_02209190(FLD(s32, self, 0xdc), FLD(s32 *, self, 0xe0), FLD(Ov010Vec *, self, 0xe4), &FLD(Ov010Vec, self, 0xf0), FLD(u16, self, 0xd4));
        }
        func_ov003_021d9980(&r, FLD(u16, self, 0xd4), (Ov010Vec *)&data_ov010_0220f54c);
        VEC_MultAdd(0x2b8, &r, &FLD(Ov010Vec, self, 0xf0), &FLD(Ov010Vec, self, 0xf0));
        func_ov000_0219a2f4(&FLD(Ov010Vec, self, 0xf0), 0x1000, -0x3000);
        break;
    }
    }
}

extern s32 func_020404e0(void);
extern s32 func_02040498(s32 max);
extern void func_ov003_021da48c(void *p, s32 a);

struct Ov010Mark {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
    u8 pad;
    u16 time;
    u8 pad4[4];
    Ov010Vec pos;
    u8 st[4];
};

static inline s32 Ov010c_FxMul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline Ov010Vec Ov010_RandPoint(s32 type, s32 *a, Ov010Vec *b) {
    Ov010Vec v;
    switch (type) {
    case 0: {
        s32 y;
        s32 z;
        s32 x;
        z = a[1] + Ov010c_FxMul(a[3] - a[1], func_020404e0());
        y = a[4];
        x = a[0] + Ov010c_FxMul(a[2] - a[0], func_020404e0());
        v.x = x;
        v.y = y;
        v.z = z;
        func_ov000_0219a2f4(&v, 0x1000, -0x3000);
        break;
    }
    case 1: {
        s32 r = Ov010c_FxMul(FLD(s32, b, 0xc), func_020404e0());
        func_ov003_021d9980(&v, func_02040498(0xffff), (Ov010Vec *)&data_ov010_0220f54c);
        VEC_MultAdd(r, &v, b, &v);
        func_ov000_0219a2f4(&v, 0x1000, -0x3000);
        break;
    }
    }
    return v;
}

struct Obj0220c758 {
    u8 unk_00[0xd2];
    u16 unk_d2;
    u16 unk_d4;
    u8 unk_d6[0x6];
    s32 unk_dc;
    s32 *unk_e0;
    Ov010Vec *unk_e4;
    Ov010Mark *unk_e8;
    u8 unk_ec[0x4];
    Ov010Vec unk_f0;
    u8 unk_fc[0x5c];
    u16 unk_158;
    u8 unk_15a[0x11];
    u8 unk_16b;
};

void func_ov010_0220c758(Obj0220c758 *self) {
    u16 t;
    s32 *ap;
    Ov010Vec *bp;
    switch (self->unk_158) {
    case 0: {
        Ov010Obj *a = Ov010_FindActor(self->unk_d2);
        if (a != NULL && ((u8 *)a->unk_48) != NULL) {
            t = 0;
            Ov010Mark *c_0;
            switch (self->unk_16b) {
            case 2: {
                bp = self->unk_e4;
                ap = self->unk_e0;
                Ov010Vec p_0;
                p_0 = Ov010_RandPoint(self->unk_dc, ap, bp);
                t = 0x3c;
                self->unk_f0 = p_0;
                self->unk_d4 = 0;
                break;
            }
            case 3: {
                Ov010Vec p_1;
                p_1 = Ov010_RandPoint(self->unk_dc, self->unk_e0, self->unk_e4);
                self->unk_f0 = p_1;
                self->unk_d4 = func_02040498(0xffff);
                t = 0x64;
                break;
            }
            }
            c_0 = self->unk_e8;
            if (c_0->b0) {
                c_0->b1 = 1;
                c_0->time = t;
                c_0->pos = self->unk_f0;
                func_ov003_021da48c(c_0->st, 0);
            }
        }
        self->unk_158 = 1;
        break;
    }
    case 1: {
        Ov010Mark *c_1 = self->unk_e8;
        BOOL busy;
        BOOL done_0;
        if (c_1->b0 && c_1->b1) {
            c_1->pos = self->unk_f0;
        }
        c_1 = self->unk_e8;
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
        self->unk_158 = 2;
        break;
    }
    case 2: {
        Ov010Mark *c_2 = self->unk_e8;
        BOOL done_1 = FALSE;
        Ov010Vec *p_2;
        if (c_2->b0) {
            if (!c_2->b1) {
                done_1 = TRUE;
            }
        }
        if (!done_1) {
            return;
        }
        func_ov003_021da48c((u8 *)self + 0x158, 1);
        FLD(Ov010Mark, self, 0xce).b0 = 0;
        c_2 = self->unk_e8;
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
extern Ov010Obj *func_ov000_0218e640(void *mgr, u16 id);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);
extern BOOL func_ov003_021d7a44(void *self, const Ov010Vec *target, const Ov010Vec *start, s32 speed, s32 maxDist, u8 noSnap);
extern void *func_0204a028(void *mgr, s32 id, const Ov010Vec *pos, s32 a);
extern Ov010V *func_02065f88(s32 id, const Ov010Vec *pos);
extern void func_ov010_02209074(void *p);

static inline Ov010Obj *Ov010_FindActorD(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

extern void *data_ov000_021ccd54;
extern s32 Ov003Vec_DistSq(const Ov010Vec *a, const Ov010Vec *b);
extern BOOL Ov003Vec_Equal(Ov010Vec *a, void *b);
extern void func_ov003_021d9f80(void *rot, const Ov010Vec *a, const Ov010Vec *b);
extern void func_ov003_021d9dbc(Ov010Vec *out, const Ov010Vec *a, const Ov010Vec *b, s32 dist, s32 yoff);
extern void func_ov003_021da2c8(void *self, s32 a, s32 b, s32 c, s32 d);
extern u16 Ov003Vec_Yaw(void *p);
extern void *func_ov000_02199ba0(void *p);
extern void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, const void *f, void *g, s32 h, s32 i, s32 j, s32 k);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void *Ov003Mover_GetDir(void *p);
extern u8 *func_ov000_02190a30(void *p, s32 a);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);

struct Obj0220cba0 {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0x2a];
    u8 *unk_38;
    u8 unk_3c[0x4];
    void *unk_40;
    u8 unk_44[0x4];
    u8 *unk_48;
    u8 *unk_4c;
    u8 unk_50[0x18];
    s32 unk_68;
    u8 unk_6c[0x4];
    Ov010Vec unk_70;
    u16 unk_7c;
    u16 unk_7e;
    u8 unk_80[0x1c];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0x22];
    Ov010Flags8 unk_ce;
    u8 unk_cf[0x1];
    u16 unk_d0;
    u8 unk_d2[0x6];
    s32 unk_d8;
    u8 unk_dc[0x14];
    Ov010Vec unk_f0;
    Ov010Vec unk_fc;
    u8 unk_108[0xc];
    Ov010Vec unk_114;
    u8 unk_120[0x4c];
    u16 unk_16c;
    u16 unk_16e;
};

static inline void Ov010_Puff(Obj0220cba0 *self) {
    Ov010Vec q;
    Ov010V *e;
    *(Ov010Blk12 *)&q = FLD(Ov010Blk12, self, 0x70);
    e = func_02065f88(0x321, &q);
    e->v0c(0x1000);
    FLD(void *, e, 0xdc) = (void *)func_ov010_02209074;
    FLD(s32, e, 4) = 6;
}

static inline void Ov010_Dust(Obj0220cba0 *self) {
    u16 ry = self->unk_7e;
    u16 rx = self->unk_7c;
    Ov010Vec p;
    s32 y = self->unk_70.y;
    s32 z = self->unk_70.z;
    p.x = self->unk_70.x;
    p.y = y + self->unk_68 / 2;
    p.z = z;
    func_02065f88(0x192, &p)->v34(rx, ry, 0);
}

void func_ov010_0220cba0(Obj0220cba0 *self) {
    switch (self->unk_16c) {
    case 0:
    case 10: {
        Ov010Obj *t = Ov010_FindActorD(self->unk_d0);
        Ov010Vec d;
        if (t == NULL || self->unk_d8 != 1) {
            self->unk_16c = 0x1e;
            return;
        }
        self->unk_d8 = 4;
        Ov010_VecCopy(&self->unk_70, &t->pos);
        VEC_Add(&self->unk_70, &self->unk_fc, &self->unk_70);
        FLD(Ov010Flags, self->unk_38, 0xc2).b0 = 1;
        {
            s32 x = self->unk_70.x;
            s32 y = self->unk_70.y;
            s32 z = self->unk_70.z;
            self->unk_114.x = x;
            self->unk_114.y = y;
            self->unk_114.z = z;
            self->unk_114.y = self->unk_114.y + (0x5800 - self->unk_fc.y);
            self->unk_9c = 0xa00;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            d.x = self->unk_f0.x - x;
            d.y = self->unk_f0.y - y;
            d.z = self->unk_f0.z - z;
        }
        self->unk_7e = Ov003Vec_Yaw(&d);
        func_0204a028(data_02097e4c, 0x29, &self->unk_70, 5);
        Ov010_Puff(self);
        self->unk_16c = 0xb;
        return;
    }
    case 0xb:
        if (self->unk_a4 == 0) {
            if (Ov003Vec_DistSq(&self->unk_114, &self->unk_70) < 0x9000) {
                self->unk_a4 = 0xa00;
            }
        }
        if (Ov003Vec_Equal(&self->unk_114, &self->unk_70) || self->unk_9c < 0x80) {
            self->unk_16c = 0x14;
            return;
        }
        func_ov003_021d9f80((u8 *)self + 0x7c, &self->unk_f0, &self->unk_70);
        func_ov003_021d9dbc(&self->unk_70, &self->unk_114, &self->unk_70, self->unk_9c, self->unk_a0);
        func_ov003_021da2c8(self, self->unk_9c, self->unk_a0, self->unk_a4, self->unk_a8);
        return;
    case 0x14:
        func_ov003_021d7a44((u8 *)self + 0x120, &self->unk_f0, &self->unk_70, 0x100, 0x2000, 0);
        func_ov003_021d9f80((u8 *)self + 0x7c, &self->unk_f0, &self->unk_70);
        self->unk_16c = 0x15;
        return;
    case 0x15: {
        Ov010Vec a;
        Ov010Vec b;
        Ov010V *e;
        self->unk_16e++;
        if (self->unk_16e == 10) {
            Ov010_Dust(self);
        }
        {
            Ov010Vec *v = (Ov010Vec *)((Ov010V *)((u8 *)self + 0x120))->v10();
            self->unk_70.x = v->x;
            self->unk_70.y = v->y;
            self->unk_70.z = v->z;
        }
        FLD(Ov010Flags, self->unk_48, 0x9a).b7 = 1;
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        {
            u16 mask = ~(1 << (self->unk_0c >> 12));
            u16 dd = FLD(u16, self->unk_4c, 0xa);
            u16 c = FLD(u16, self->unk_4c, 8);
            void *x = func_ov000_02199ba0(self->unk_4c);
            if (func_ov000_0219aae8(self, x, c, dd, mask, NULL, NULL, 0x400, 0, 0x38f, 0x1000)) {
                Ov010_Puff(self);
                func_ov000_02198360(self->unk_40, 0x15, 0);
                return;
            }
        }
        if (!(FLD(u32, self->unk_48, 0x50) & 0x20000000)) {
            if (!((Ov010V *)((u8 *)self + 0x120))->v14()) {
                return;
            }
        }
        {
            u16 ang;
            u8 *g;
            u8 *m;
            *(Ov010Blk12 *)&a = FLD(Ov010Blk12, self, 0x70);
            *(Ov010Blk12 *)&b = data_ov010_0220f588;
            ang = Ov003Vec_Yaw(Ov003Mover_GetDir((u8 *)self + 0x120)) + 0x7fff;
            e = func_02065f88(0x67, &a);
            e->v34(0, ang, 0);
            e->v10(&b);
            Ov010_Puff(self);
            g = (u8 *)data_ov000_021ccd54;
            FLD(u8, g, 0x190) |= 0x1c;
            FLD(u8, g, 0x18d) = 5;
            FLD(u8, g, 0x18e) = 8;
            FLD(u8, g, 0x18f) = 8;
            {
                u16 r;
                if (self->unk_7c > 0x7fff) {
                    r = self->unk_7c - 0xe38;
                } else {
                    r = self->unk_7c + 0xe38;
                }
                self->unk_7c = r;
            }
            m = func_ov000_02190a30(self->unk_38, 0);
            FLD(u8, m, 0x111) |= 8;
            FLD(u16, self->unk_4c, 0x1c) = 0xffff;
            self->unk_d8 = 6;
            self->unk_16c = 0x1e;
            self->unk_16e = 0;
            func_02049f44(data_02097e4c, 0x52, &self->unk_70, 0);
        }
        return;
    }
    case 0x1e:
        ((Ov010V *)((u8 *)self + 0x120))->v08();
        self->unk_ce.b1 = 0;
        return;
    }
}


void func_ov010_0220d1c4(Obj0220cba0 *self) {
    switch (self->unk_16c) {
    case 0: {
        Ov010Obj *t = Ov010_FindActorD(self->unk_d0);
        if (t != NULL && self->unk_d8 == 1) {
            Ov010Vec p;
            Ov010Vec q;
            Ov010V *e;
            self->unk_d8 = 3;
            Ov010_VecCopy(&self->unk_70, &t->pos);
            VEC_Add(&self->unk_70, &self->unk_fc, &self->unk_70);
            self->unk_7c = 0xbfff;
            FLD(Ov010Flags, self->unk_38, 0xc2).b0 = 1;
            p.x = self->unk_70.x;
            p.y = self->unk_70.y + 0xa000;
            p.z = self->unk_70.z;
            func_ov003_021d7a44((u8 *)self + 0x120, &p, &self->unk_70, 0x29, 0x4cd, 0);
            func_0204a028(data_02097e4c, 0x29, &self->unk_70, 5);
            OV010_BLKCPY(&q, &self->unk_70);
            e = func_02065f88(0x321, &q);
            e->v0c(0x1000);
            FLD(void *, e, 0xdc) = (void *)func_ov010_02209074;
            FLD(s32, e, 4) = 6;
            self->unk_16c = 1;
        } else {
            self->unk_16c = 2;
        }
        break;
    }
    case 1: {
        Ov010Vec *v = (Ov010Vec *)((Ov010V *)((u8 *)self + 0x120))->v10();
        self->unk_70.x = v->x;
        self->unk_70.y = v->y;
        self->unk_70.z = v->z;
        if (((Ov010V *)((u8 *)self + 0x120))->v14()) {
            self->unk_16c = 2;
        }
        break;
    }
    case 2:
        self->unk_d8 = 2;
        FLD(Ov010Flags, self->unk_38, 0xc2).b0 = 0;
        ((Ov010V *)((u8 *)self + 0x120))->v08();
        self->unk_ce.b1 = 0;
        break;
    }
}


extern s32 func_02040498(s32 max);

void func_ov010_0220d3d8(Obj0220cba0 *self) {
    switch (self->unk_16c) {
    case 0:
        if (self->unk_d8 != 2) {
            self->unk_16c = 2;
            return;
        }
        self->unk_d8 = 4;
        self->unk_70.x = self->unk_f0.x;
        self->unk_70.z = self->unk_f0.z;
        self->unk_70.y = self->unk_f0.y + 0xa000;
        VEC_Add(&self->unk_70, &self->unk_fc, &self->unk_70);
        self->unk_7c = 0x4000;
        self->unk_7e = func_02040498(0xffff);
        FLD(Ov010Flags, self->unk_38, 0xc2).b0 = 1;
        func_ov003_021d7a44((u8 *)self + 0x120, &self->unk_f0, &self->unk_70, 0x8cd, 0x8cd, 1);
        self->unk_16c = 1;
        break;
    case 1: {
        Ov010Vec a;
        Ov010Vec b;
        Ov010Vec q;
        Ov010Vec q2;
        Ov010V *e;
        Ov010Vec *v = (Ov010Vec *)((Ov010V *)((u8 *)self + 0x120))->v10();
        self->unk_70.x = v->x;
        self->unk_70.y = v->y;
        self->unk_70.z = v->z;
        FLD(Ov010Flags, self->unk_48, 0x9a).b7 = 1;
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        {
        u16 mask = ~(1 << (self->unk_0c >> 12));
        u16 d = FLD(u16, self->unk_4c, 0xa);
        u16 c = FLD(u16, self->unk_4c, 8);
        void *x = func_ov000_02199ba0(self->unk_4c);
        if (func_ov000_0219aae8(self, x, c, d, mask, NULL, NULL, 0x400, 0, 0x38f, 0x1000)) {
            *(Ov010Blk12 *)&q = FLD(Ov010Blk12, self, 0x70);
            e = func_02065f88(0x321, &q);
            e->v0c(0x1000);
            FLD(void *, e, 0xdc) = (void *)func_ov010_02209074;
            FLD(s32, e, 4) = 6;
            func_ov000_02198360(self->unk_40, 0x15, 0);
            return;
        }
        }
        if (FLD(u32, self->unk_48, 0x50) & 0x20000000) {
            u16 ang;
            u8 *g;
            u8 *m;
            a.x = self->unk_70.x;
            a.y = self->unk_70.y - FLD(s32, self->unk_48, 0x38);
            a.z = self->unk_70.z;
            *(Ov010Blk12 *)&b = data_ov010_0220f570;
            ang = Ov003Vec_Yaw(Ov003Mover_GetDir((u8 *)self + 0x120)) + 0x7fff;
            e = func_02065f88(0x66, &a);
            e->v34(0, ang, 0);
            e->v10(&b);
 *(Ov010Blk12 *)&q2 = FLD(Ov010Blk12, self, 0x70);
            e = func_02065f88(0x321, &q2);
            e->v0c(0x1000);
            FLD(void *, e, 0xdc) = (void *)func_ov010_02209074;
            FLD(s32, e, 4) = 6;
            g = (u8 *)data_ov000_021ccd54;
            FLD(u8, g, 0x190) |= 0x1c;
            FLD(u8, g, 0x18d) = 5;
            FLD(u8, g, 0x18e) = 8;
            FLD(u8, g, 0x18f) = 8;
            self->unk_7c += func_02040498(0x2aaa) - 0x1555;
            m = func_ov000_02190a30(self->unk_38, 0);
            FLD(u8, m, 0x111) |= 8;
            FLD(u16, self->unk_4c, 0x1c) = 0xffff;
            self->unk_16c = 2;
            self->unk_d8 = 6;
            func_02049f44(data_02097e4c, 0x52, &self->unk_70, 0);
        }
        break;
    }
    case 2:
        ((Ov010V *)((u8 *)self + 0x120))->v08();
        self->unk_ce.b1 = 0;
        break;
    }
}

}
}  // namespace m_0220cba0

// ---- merged from ov010_0220d77c.cpp
namespace m_0220d77c {
struct Ov010Node {
    u16 id;
    u16 unk_02;
    Ov010Node *next;
};

struct Ov010Coll {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 count;
    u16 ids[0x11];
    Ov010Node *list;
    Ov010V *handler;
    u8 pool[1];
};

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

typedef s32 (*Ov010CollFn)(void *obj);

extern "C" {

extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd64;
extern Ov010Obj *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov003_021d7848(void *p);
extern void *func_ov003_021d7858(void *p);
extern void func_ov003_021d7948(void *p);
extern BOOL func_ov003_021d7894(void *p, s32 a, s32 b);
extern void Ov003Pool_Free(void *p, Ov010Node *n);
extern Ov010Node *func_ov003_021d7980(void *p);
extern void *func_ov000_0218bf1c(void *mgr, Ov010SpawnDesc *d, s32 a, Ov010Rot3s *r, s32 b);
extern void func_ov010_0220a948(void *obj, s32 a, s32 b, s32 c, u16 d, u16 e);

static inline Ov010Obj *Ov010_FindObjById(u16 id) {
    if (data_ov000_021ccd68 != NULL) {
        return func_ov000_0218e640(data_ov000_021ccd68, id);
    }
    return NULL;
}

static inline Ov010Node *Ov010_NodePush(Ov010Node *head, Ov010Node *n) {
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

BOOL func_ov010_0220d77c(void *p) {
    if (p != NULL && FLD(s32, p, 0xd8) == 6) {
        return TRUE;
    }
    return FALSE;
}

Ov010Coll *func_ov010_0220d79c(Ov010Coll *self) {
    func_ov003_021d7848(self->pool + 0);
    self->b0 = 0;
    return self;
}

Ov010Coll *func_ov010_0220d7c0(Ov010Coll *self) {
    if (self->b0) {
        self->b0 = 0;
        func_ov003_021d7948(self->pool);
    }
    func_ov003_021d7858(self->pool);
    return self;
}

BOOL func_ov010_0220d7f8(Ov010Coll *self) {
    self->b0 = 1;
    self->count = 0;
    self->list = NULL;
    self->handler = NULL;
    func_ov003_021d7894(self->pool, 8, 0x10);
    return TRUE;
}

void func_ov010_0220d834(Ov010Coll *self) {
    if (!self->b0) {
        return;
    }
    self->b0 = 0;
    func_ov003_021d7948(self->pool);
}

void func_ov010_0220d858(Ov010Coll *self) {
    Ov010Node *prev;
    Ov010Node *next;
    Ov010Node *n;
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
        if (!self->handler->v14()) {
            self->handler = NULL;
            return;
        }
        self->handler->v10();
    }
}

void func_ov010_0220d918(Ov010Coll *self, Ov010CollFn fn) {
    Ov010Node *n;
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

void func_ov010_0220d9c0(Ov010Coll *self, Ov010V *h) {
    if (self->b0 && h != NULL) {
        if (self->handler != NULL) {
            self->handler->v0c();
        }
        self->handler = h;
        h->v08(self);
    }
}

void func_ov010_0220da14(Ov010Coll *self) {
    if (self->b0 && self->handler != NULL) {
        self->handler->v0c();
        self->handler = NULL;
    }
}

BOOL func_ov010_0220da4c(Ov010Coll *self) {
    BOOL r = FALSE;
    if (self->b0) {
        r = self->handler == NULL;
    }
    return r;
}

Ov010Node *func_ov010_0220da74(Ov010Coll *self, s32 a, s32 b, s32 c, s32 d, u16 e, u16 f) {
    Ov010Node *n = NULL;
    if (self->b0) {
        n = func_ov003_021d7980(self->pool);
        if (n != NULL) {
            Ov010SpawnDesc desc;
            Ov010Rot3s rot;
            void *obj;
            Ov010SpawnDesc_Init(&desc, 0x4817, 0x4000);
            rot.x = 0;
            rot.y = 0;
            rot.z = 0;
            obj = func_ov000_0218bf1c(data_ov000_021ccd64, &desc, a, &rot, 0xffff);
            func_ov010_0220a948(obj, b, c, d, e, f);
            FLD(Ov010Flags8, obj, 0x16).b0 = 1;
            n->id = FLD(u16, obj, 0xc);
            self->list = Ov010_NodePush(self->list, n);
        }
    }
    return n;
}

Ov010Node *func_ov010_0220db74(Ov010Node *head, Ov010Node *node) {
    Ov010Node *p;
    Ov010Node *prev;
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

static inline BOOL Ov010_ObjGone(void *obj) {
    BOOL r = FALSE;
    if (obj == NULL) {
        r = TRUE;
    } else {
        switch (FLD(s32, obj, 0xd8)) {
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

static inline void Ov010Coll_Kill(Ov010Coll *self, Ov010Node *n) {
    if (self->b0 && n != NULL) {
        Ov010V *obj = (Ov010V *)Ov010_FindObjById(n->id);
        if (obj != NULL) {
            obj->v08();
        }
        self->list = func_ov010_0220db74(self->list, n);
        Ov003Pool_Free(self->pool, n);
    }
}

static inline void Ov010Coll_KillId(Ov010Coll *self, u16 id) {
    Ov010Node *n;
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
    Ov010Node *n;
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
extern void *data_0214a420;
extern void *func_ov000_02194074(void *self);
extern void *func_ov000_0219429c(void *self);
extern void func_ov000_02194758(void *self);
extern void MTX_Identity33_(void *m);
extern void func_02065860(void *a, s32 b);
extern void MTX_RotZ33_(void *m, s32 s, s32 c);
extern void MTX_RotY33_(void *m, s32 s, s32 c);
extern void MTX_Concat33(void *a, void *b, void *c);
extern void MI_Copy36B(void *m, void *b);
extern s32 func_ov000_021903b4(void *p);
extern BOOL func_ov000_02190cb0(void *p, const void *a, s32 b, s32 c);
extern void func_ov000_021915a0(void *p);
extern void func_0203f364(void *p);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);

struct Obj0220dd60 : public Ov010Obj {
    u8 unk_ac[0x24];
    s32 unk_d0;
    s32 unk_d4;
    s32 unk_d8;
};

static inline void Ov010_0220dd60_Reset(Obj0220dd60 *self) {
    self->unk_d0 = -1;
    self->unk_d4 = 0;
    self->unk_d8 = 0;
    MTX_Identity33_((u8 *)self + 0xdc);
}

void *Ov010ActVt_022102e0_Ctor(Obj0220dd60 *self) {
    func_ov000_02194074(self);
    *(void * *)self = data_ov010_022102e0;
    Ov010_0220dd60_Reset(self);
    return self;
}

static inline void Ov010_0220dd60_Dtor(Obj0220dd60 *self) {
    *(void * *)self = data_ov010_022102e0;
    func_02065860(data_0214a420, self->unk_d4);
    Ov010_0220dd60_Reset(self);
    func_ov000_0219429c(self);
}

void *Ov010ActVt_022102e0_Dtor(Obj0220dd60 *self) {
    Ov010_0220dd60_Dtor(self);
    return self;
}

void *Ov010ActVt_022102e0_DtorDelete(Obj0220dd60 *self) {
    Ov010_0220dd60_Dtor(self);
    func_0203de1c(self);
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
    if (self->unk_38 != NULL && self->unk_d0 != -1) {
        switch (self->unk_d0) {
        case 0:
            MTX_RotY33_((u8 *)self + 0xdc, OV010_SIN(self->rot_y), OV010_COS(self->rot_y));
            break;
        case 1:
            MTX_RotZ33_(m, OV010_SIN(0x4000), OV010_COS(0x4000));
            MTX_RotY33_((u8 *)self + 0xdc, OV010_SIN(self->rot_y), OV010_COS(self->rot_y));
            MTX_Concat33(m, (u8 *)self + 0xdc, (u8 *)self + 0xdc);
            break;
        }
        FLD(Ov010Vec, self->unk_38, 0x78) = self->pos;
        MI_Copy36B((u8 *)self + 0xdc, (u8 *)self->unk_38 + 0x84);
        r = func_ov000_021903b4(self->unk_38);
    }
    return r;
}

void Ov010ActVt_022102e0_Start(Obj0220dd60 *self) {
    func_ov000_02194758(self);
    Ov010Vec v = data_ov010_0220f57c;
    FLD(Ov010Vec, self->unk_38, 0xa8) = v;
}

void func_ov010_0220dfac(Obj0220dd60 *self) {
    ActorSub48 *m;
    if (self->unk_40->st != 0) {
        return;
    }
    if (self->unk_d0 == -1) {
        self->unk_d0 = 0;
    }
    func_ov000_02190cb0(self->unk_38, data_ov010_0220f540, 0x1000, 0);
    func_ov000_021915a0(self->unk_38);
    m = self->unk_48;
    if (m != NULL) {
        FLD(Ov010Flags, m, 0x9a).b0 = 0;
        m->unk_9a_3 = 0;
        func_0203f364(m);
        m = self->unk_48;
        FLD(Ov010Flags, m, 0x9a).b1 = 0;
        m->unk_9a_4 = 0;
        m = self->unk_48;
        FLD(Ov010Flags, m, 0x9a).b2 = 0;
        m->unk_9a_5 = 0;
    }
    func_ov000_02198360(((u8 *)self->unk_40), 4, 0);
}


struct Ov010Rot16 {
    u16 x;
    u16 y;
    u16 z;
};

extern void func_ov000_0218dbe0(void *self, s32 a);
extern s32 func_ov000_0219a2f4(Ov010Vec *p, s32 a, s32 b);
extern Ov010V *func_020657b0(void *a, s32 b);
extern Ov010V *func_02065f88(s32 a, Ov010Vec *b);
extern void func_02063a14(Ov010V *p);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, const void *f, void *g, s32 h, s32 i, s32 j, s32 k);

void func_ov010_0220e06c(Obj0220dd60 *self) {
    Ov010Vec p;
    Ov010Rot16 ra;
    Ov010Rot16 rb;
    s32 scale;
    switch (self->unk_40->st) {
    case 0:
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_9c = 0x733;
        self->unk_98 = self->rot_y;
        self->unk_40->st = 1;
        break;
    case 1:
        if (self->unk_d8 > 0x28000) {
            func_ov000_02198360(((u8 *)self->unk_40), 0x15, 0);
        }
        break;
    }
    self->unk_9c = Ov010_FxMul(self->unk_9c, 0x1029);
    self->unk_d8 += self->unk_9c;
    func_ov000_0218dbe0(self, 0);
    if (self->unk_48 == NULL) {
        return;
    }
    scale = Ov010_FxMul(FLD(s32, self->unk_38, 0xa8), self->unk_64);
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
        Ov010V *o;
        BOOL near;
        rb.x = 0x7fff;
        ra.x = 0;
        ra.y = 0;
        ra.z = 0;
        rb.y = 0;
        rb.z = 0;
        *(Ov010Blk12 *)&p = FLD(Ov010Blk12, self, 0x70);
        h = func_ov000_0219a2f4(&p, 0x1000, -0x3000);
        near = FALSE;
        if (self->pos.y - p.y < scale) {
            near = TRUE;
        }
        o = func_020657b0(data_0214a420, self->unk_d4);
        if (h != -0x1000 && near) {
            p.y += 0x800;
            if (o != NULL) {
                o->v18(&p);
                o->v34(0, (u16)(self->rot_y + 0x7fff), 0);
            } else {
                Ov010V *n = func_02065f88(0x25e, &p);
                n->v34(0, (u16)(self->rot_y + 0x7fff), 0);
                n->v14(0x1800, 0x1800, 0x1800);
                self->unk_d4 = FLD(s32, n, 0x24);
            }
        } else if (o != NULL) {
            func_02063a14(o);
            self->unk_d4 = 0;
        }
        break;
    }
    }
    func_ov000_0219aae8(self, self, FLD(u16, self->unk_4c, 8), FLD(u16, self->unk_4c, 0xa), 2, &data_ov010_0220f594, &ra, 0x800, scale, 100, 0x1000);
    func_ov000_0219aae8(self, self, FLD(u16, self->unk_4c, 8), FLD(u16, self->unk_4c, 0xa), 2, &data_ov010_0220f594, &rb, 0x800, scale, 100, 0x1000);
}


struct Ov010Trail {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
    u8 pad_01;
    u16 life;
    s32 key;
    Ov010Vec pos;
    u16 state;
    u16 timer;
};

extern void *data_02097e4c;
extern s32 FX_Div(s32 a, s32 b);
extern void func_02065804(void *a, s32 b);
extern Ov010V *func_02066774(const void *a, const void *b, s32 c, Ov010Vec *pos);
extern void *func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);

static inline void Ov010_TrailApply(Ov010V *o, s16 s, u32 n) {
    o->v14(s, s, s);
    if (n > 0x1f) {
        n = 0x1f;
    }
    FLD(s32, o, 0x7c) = FX_Div((u8)n << 12, 0x1f000);
}

void func_ov010_0220e38c(Ov010Trail *self) {
    Ov010V *o;
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
    switch (self->state) {
    case 0:
        o = func_02066774(data_ov010_0220f538, data_ov010_0220f53c, 0, &self->pos);
        FLD(u8, o, 0x28) = 0;
        FLD(s32, o, 0xc8) = -1;
        self->key = FLD(s32, o, 0x24);
        o->v14(0x6000, 0x6000, 0x6000);
        FLD(s32, o, 0x7c) = FX_Div(0xa000, 0x1f000);
        func_02049f44(data_02097e4c, 0x72, &self->pos, 0);
        self->state = 1;
        break;
    case 1: {
        BOOL early = self->life < 0xc;
        o = func_020657b0(data_0214a420, self->key);
        if (self->timer > 6 || early) {
            self->state = 10;
        } else if (o == NULL) {
            self->state = 30;
        } else {
            s = FLD(s32, o, 0x40) - 0xaaa;
            if (s > 0x6000) {
                s = 0x6000;
            } else if (s < 0x2000) {
                s = 0x2000;
            }
            sc = s;
        n = (u8)(Ov010_FxMul(FLD(s32, o, 0x7c), 0x1f000) >> 12) + 6;
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
            self->state = 30;
            break;
        }
        o->v14(0x2000, 0x2000, 0x2000);
        FLD(s32, o, 0x7c) = FX_Div(0x1e000, 0x1f000);
        if (self->life - self->timer <= 6) {
            self->state = 20;
        }
        break;
    case 20:
        self->b2 = 1;
        o = func_020657b0(data_0214a420, self->key);
        if (o == NULL) {
            self->state = 30;
            break;
        }
        o->v14(0x2000, 0x2000, 0x2000);
        FLD(s32, o, 0x7c) = FX_Div(0x1e000, 0x1f000);
        self->state = 21;
        break;
    case 21:
        o = func_020657b0(data_0214a420, self->key);
        if (self->timer > self->life) {
            self->state = 30;
            break;
        }
        if (o == NULL) {
            break;
        }
        s = FLD(s32, o, 0x40) + 0xaaa;
        if (s > 0x6000) {
            s = 0x6000;
        } else if (s < 0x2000) {
            s = 0x2000;
        }
        sc = s;
        n = (u8)(Ov010_FxMul(FLD(s32, o, 0x7c), 0x1f000) >> 12) - 6;
        if (n > 0x1e) {
            n = 0x1e;
        } else if (n < 1) {
            n = 1;
        }
        Ov010_TrailApply(o, sc, (u8)n);
        break;
    case 30:
        func_02065804(data_0214a420, self->key);
        self->key = 0;
        self->b1 = 0;
        break;
    }
    self->timer++;
    o = func_020657b0(data_0214a420, self->key);
    if (o != NULL) {
        o->v1c(self->pos.x, self->pos.y + 0x200, self->pos.z);
    }
}

}
}  // namespace m_0220dd60
