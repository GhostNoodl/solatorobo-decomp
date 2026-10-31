#include "ov010/ov010.h"

typedef Ov010Vec VecFx32;
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
extern u16 func_ov003_021d9c38(Ov010Vec *v);

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
    return func_ov003_021d9c38(&a);
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

Ov010Trig *func_ov010_022092c8(Ov010Trig *self) {
    self->vtbl = data_ov010_02210280;
    func_ov000_02198328((u8 *)self + 0x1c);
    self->b0 = 0;
    self->b1 = 0;
    return self;
}

void *func_ov010_02209300(void *self) {
    FLD(void *, self, 0) = data_ov010_02210280;
    ((Ov010V *)self)->v0c();
    return self;
}

void *func_ov010_02209328(void *self) {
    FLD(void *, self, 0) = data_ov010_02210280;
    ((Ov010V *)self)->v0c();
    func_0203de1c(self);
    return self;
}

BOOL func_ov010_02209358(Ov010Trig *self, s32 a) {
    self->unk_0c = a;
    self->b0 = 1;
    self->unk_0a = 0xffff;
    func_ov003_021da48c((u8 *)self + 0x1c, 0);
    return TRUE;
}

void func_ov010_02209390(Ov010Trig *self) {
    if (self->b0) {
        self->b0 = 0;
        self->b1 = 0;
    }
}

extern void *data_ov000_021ccd68;
extern u8 *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov010_0220dbc0(s32 p);
extern u16 *func_ov010_0220da74(s32 p, Ov010Vec *pos, s32 b, s32 c, s32 d, u16 e, u16 f);

static inline u8 *Ov010_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline void Ov010_Activate(u8 *a) {
    if (FLD(u8, a, 0x14) == 1) {
        return;
    }
    if (!FLD(Ov010Flags8, a, 0xce).b0) {
        FLD(Ov010Flags8, a, 0xce).b0 = 1;
        FLD(Ov010Flags8, a, 0xce).b2 = 1;
        func_ov003_021da48c(a + 0x158, 2);
    }
}

void func_ov010_022093b0(Ov010Trig *self) {
    u8 *a;
    if (!self->b0) {
        return;
    }
    switch (FLD(u16, self, 0x1c)) {
    case 0: {
        Ov010Vec p;
        func_ov010_0220dbc0(self->unk_0c);
        a = Ov010_FindActor(self->unk_06);
        if (a == NULL) {
            FLD(u16, self, 0x1c) = 3;
            return;
        }
        p = FLD(Ov010Vec, a, 0x70);
        self->unk_0a = *func_ov010_0220da74(self->unk_0c, &p, FLD(s32, self, 0x18), FLD(s32, self, 0x10), FLD(s32, self, 0x14), self->unk_06, self->unk_08);
        FLD(u16, self, 0x1c) = 1;
        break;
    }
    case 1:
        a = Ov010_FindActor(self->unk_0a);
        if (a == NULL) {
            FLD(u16, self, 0x1c) = 3;
            return;
        }
        if (FLD(u8, a, 0x14) == 1) {
            return;
        }
        Ov010_Activate(a);
        FLD(u16, self, 0x1c) = 2;
        break;
    case 2:
        a = Ov010_FindActor(self->unk_0a);
        if (a != NULL && FLD(Ov010Flags8, a, 0xce).b0) {
            return;
        }
        FLD(u16, self, 0x1c) = 3;
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

Ov010Trig *func_ov010_022095a8(Ov010Trig *self) {
    self->vtbl = data_ov010_022102c0;
    func_ov000_02198328((u8 *)self + 0xc);
    self->b0 = 0;
    self->b1 = 0;
    return self;
}

void *func_ov010_022095e0(void *self) {
    FLD(void *, self, 0) = data_ov010_022102c0;
    ((Ov010V *)self)->v0c();
    return self;
}

void *func_ov010_02209608(void *self) {
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
extern u8 *func_ov000_0218e640(void *mgr, u16 id);

static inline u8 *Ov010_FindActor(u16 id) {
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
        u8 *a;
        u8 *s;
        if (l->b0) {
            Ov010IdNode *n;
            l->count = 0;
            for (n = l->head; n != NULL; n = n->next) {
                u8 *e = Ov010_FindActor(n->id);
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
            func_ov003_021d9980(&v, FLD(u16, s, 0x7e), (Ov010Vec *)&t);
            if (FLD(u8, a, 0x14) != 1 && !FLD(Ov010Flags8, a, 0xce).b1) {
                FLD(Ov010Flags8, a, 0xce).b1 = 1;
                func_ov003_021da48c(a + 0x16c, 1);
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

Ov010Trig *func_ov010_02209860(Ov010Trig *self) {
    self->vtbl = data_ov010_022102a0;
    func_ov000_02198328((u8 *)self + 0x20);
    self->b0 = 0;
    self->b1 = 0;
    return self;
}

void *func_ov010_02209898(void *self) {
    FLD(void *, self, 0) = data_ov010_022102a0;
    ((Ov010V *)self)->v0c();
    return self;
}

void *func_ov010_022098c0(void *self) {
    FLD(void *, self, 0) = data_ov010_022102a0;
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
extern u8 *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov010_0220dbc0(Ov010IdList *l);
extern u16 *func_ov010_0220da74(Ov010IdList *l, Ov010Vec *pos, s32 b, s32 c, s32 d, u16 e, u16 f);
extern void func_ov003_021da48c(void *p, s32 a);

static inline u8 *Ov010w_FindActor(u16 id) {
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
            if (Ov010w_IsActive(Ov010w_FindActor(n->id)) == TRUE) {
                l->ids[l->count] = n->id;
                l->count++;
            }
        }
    }
}

static inline void Ov010w_StartAll(Ov010Wave *self) {
    s32 i;
    for (i = 0; i < Ov010w_Count(self->list); i++) {
        u8 *a = Ov010w_FindActor(Ov010w_Get(self->list, i));
        if (a != NULL && FLD(u8, a, 0x14) != 1 && !FLD(Ov010Flags8, a, 0xce).b0) {
            FLD(Ov010Flags8, a, 0xce).b0 = 1;
            FLD(Ov010Flags8, a, 0xce).b2 = 1;
            func_ov003_021da48c(a + 0x158, 3);
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
        u8 *a;
        Ov010Vec p;
        s32 i;
        func_ov010_0220dbc0(self->list);
        a = Ov010w_FindActor(self->unk_06);
        if (a == NULL) {
            self->state = 0x70;
            return;
        }
        p = FLD(Ov010Vec, a, 0x70);
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
            u8 *a = Ov010w_FindActor(Ov010w_Get(self->list, i));
            if (a != NULL && FLD(u8, a, 0x14) == 1) {
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
            u8 *a;
            u8 *s;
            u16 idx;
            BOOL more;
            if (l->b0) {
                Ov010IdNode *n;
                l->count = 0;
                for (n = l->head; n != NULL; n = n->next) {
                    u8 *e = Ov010w_FindActor(n->id);
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
            if (a != NULL && FLD(u8, a, 0x14) != 1 && s != NULL && more) {
                s32 q = 0x2000 / (self->unk_0a - 1);
                Ov010Vec v;
                Ov010Blk12 t = data_ov010_0220f564;
                t.w[0] = q * idx - 0x1000;
                func_ov003_021d9980(&v, FLD(u16, s, 0x7e), (Ov010Vec *)&t);
                if (FLD(u8, a, 0x14) != 1 && !FLD(Ov010Flags8, a, 0xce).b1) {
                    FLD(Ov010Flags8, a, 0xce).b1 = 1;
                    func_ov003_021da48c(a + 0x16c, 2);
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
                u8 *a = Ov010w_FindActor(Ov010w_Get(self->list, i));
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

Ov010Tmr *func_ov010_0220a078(Ov010Tmr *self) {
    self->vtbl = data_ov010_02210260;
    self->on = 0;
    return self;
}

void *func_ov010_0220a090(void *self) {
    FLD(void *, self, 0) = data_ov010_02210260;
    ((Ov010V *)self)->v0c();
    return self;
}

void *func_ov010_0220a0b8(void *self) {
    FLD(void *, self, 0) = data_ov010_02210260;
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
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov003_021da48c(void *p, s32 a);

static inline void *Ov010_FindActor(u16 id) {
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
            void *a = Ov010_FindActor(n->id);
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
        void *a = Ov010_FindActor(Ov010IdList_Get(l, 0));
        if (a != NULL && FLD(u8, a, 0x14) != 1 && !FLD(Ov010Flags8, a, 0xce).b1) {
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

u8 func_ov010_0220a2a0(void *self) {
    return FLD(u8, self, 4);
}

Ov010Trig *func_ov010_0220a2a8(Ov010Trig *self) {
    self->vtbl = data_ov010_02210240;
    func_ov000_02198328((u8 *)self + 0xc);
    self->b0 = 0;
    return self;
}

void *func_ov010_0220a2d8(void *self) {
    FLD(void *, self, 0) = data_ov010_02210240;
    ((Ov010V *)self)->v0c();
    return self;
}

void *func_ov010_0220a300(void *self) {
    FLD(void *, self, 0) = data_ov010_02210240;
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
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218d398(void *obj, u16 id, s32 a, s32 b, s32 c, u8 *d);
extern void *func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern Ov010CNode *func_ov010_0220db74(Ov010CNode *head, Ov010CNode *node);
extern void func_ov003_021d79ac(void *p, Ov010CNode *n);

static inline void *Ov010t_Find(u16 id) {
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
                    func_ov003_021d79ac(c->pool, n);
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
            u8 *obj = (u8 *)Ov010t_Find(Ov010t_Id(self->coll, i));
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
                        p = FLD(Ov010Vec, obj, 0x70);
                        func_02049f44(data_02097e4c, 0x77, &p, 0);
                    }
                } else {
                    Ov010t_Remove(self->coll, FLD(u16, obj, 0xc));
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
namespace m_0220a6a0 {
struct Ov010Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
};

extern "C" {

extern u8 data_ov010_02210378[];
extern void *func_ov000_02194074(void *self);
extern void *func_ov003_021d79d0(void *p);
extern void *func_ov000_02198328(void *p);
extern void func_ov010_0220c49c(void *self);

BOOL func_ov010_0220a6a0(void *self) {
    return FLD(Ov010Flags8, self, 4).b0;
}

void *func_ov010_0220a6b0(void *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov010_02210378;
    func_ov003_021d79d0((u8 *)self + 0x120);
    func_ov000_02198328((u8 *)self + 0x158);
    func_ov000_02198328((u8 *)self + 0x16c);
    func_ov010_0220c49c(self);
    return self;
}


extern Ov010Heap *data_02097dd0;
extern void *data_0214a420;
extern u8 data_ov010_02210378[];
extern void func_02065804(void *a, s32 b);
extern void *func_ov003_021d79ec(void *p);
extern void *func_ov000_0219429c(void *self);
extern void func_ov010_0220c49c(void *self);

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

static inline void Ov010_FreeFxA(void *self, u32 off) {
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

static inline void Ov010_FreeFxB(void *self, u32 off) {
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

static inline void Ov010Boss_Dtor(void *self) {
    FLD(void *, self, 0) = data_ov010_02210378;
    Ov010_FreeFxA(self, 0xe8);
    Ov010_FreeFxB(self, 0xec);
    ((Ov010V *)((u8 *)self + 0x120))->v08();
    func_ov010_0220c49c(self);
    func_ov003_021d79ec((u8 *)self + 0x120);
    func_ov000_0219429c(self);
}

void *func_ov010_0220a6f0(void *self) {
    Ov010Boss_Dtor(self);
    return self;
}

void *func_ov010_0220a818(void *self) {
    Ov010Boss_Dtor(self);
    func_0203de1c(self);
    return self;
}
}
}  // namespace m_0220a6a0

// ---- merged from ov010_0220a948.cpp
namespace m_0220a948 {
extern "C" {

static inline void Ov010_0220a948_Set(void *self, u16 c, u16 d, s32 mode, s32 a, s32 b) {
    FLD(u16, self, 0xd0) = c;
    FLD(u16, self, 0xd2) = d;
    FLD(s32, self, 0xdc) = mode;
    FLD(s32, self, 0xe0) = a;
    FLD(s32, self, 0xe4) = b;
}

void func_ov010_0220a948(void *self, s32 mode, s32 a, s32 b, u16 c, u16 d) {
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
extern u8 *func_ov000_0218e640(void *mgr, u16 id);
extern void MTX_Identity33_(Ov010Mtx33a *m);
extern void MTX_RotX33_(Ov010Mtx33a *m, s32 s, s32 c);
extern void MTX_RotY33_(Ov010Mtx33a *m, s32 s, s32 c);
extern void MTX_RotZ33_(Ov010Mtx33a *m, s32 s, s32 c);
extern void MTX_Concat33(Ov010Mtx33a *a, Ov010Mtx33a *b, Ov010Mtx33a *out);
extern void MI_Copy36B(const void *src, void *dst);
extern BOOL func_ov000_02194c08(void *self);

void func_ov010_0220a9a8(u8 *self) {
    Ov010Mtx33a out;
    Ov010Mtx33a tc;
    Ov010Mtx33a ma;
    Ov010Mtx33a mb;
    Ov010Mtx33a ta;
    Ov010Mtx33a tb;
    u8 *o;
    FLD(Ov010Flags8, self, 0x93).b0 = 1;
    o = NULL;
    if (FLD(s32, self, 0xd8) == 7) {
        void *mgr = data_ov000_021ccd68;
        u16 id = FLD(u16, self, 0x180);
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
        dx = FLD(u16, o, 0x7c) - FLD(u16, self, 0x190);
        dy = FLD(u16, o, 0x7e) - FLD(u16, self, 0x192);
        dz = FLD(u16, o, 0x80) - FLD(u16, self, 0x194);
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
        rz = FLD(u16, self, 0x80);
        ry = FLD(u16, self, 0x7e);
        rx = FLD(u16, self, 0x7c);
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
    MI_Copy36B(&out, FLD(u8 *, self, 0x38) + 0x84);
    {
        u8 *m = FLD(u8 *, self, 0x38);
        FLD(s32, m, 0x78) = FLD(s32, self, 0x70);
        FLD(s32, m, 0x7c) = FLD(s32, self, 0x74);
        FLD(s32, m, 0x80) = FLD(s32, self, 0x78);
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

BOOL func_ov010_0220adb8(void *self, u8 *msg) {
    BOOL r;
    if (msg[5] == 0xe) {
        switch (msg[8]) {
        case 4:
            FLD(Ov010Flags8, self, 0xce).b3 = 1;
            if (FLD(s32, self, 0xd8) == 7) {
                break;
            }
        case 1:
            func_ov000_02198360(FLD(void *, self, 0x40), 0x15, 0);
            break;
        case 0:
            Ov010FxB_Stop(FLD(u8 *, self, 0xec));
            Ov010FxB_Start(FLD(u8 *, self, 0xec));
            break;
        case 2:
            func_ov000_02198360(FLD(void *, self, 0x40), 6, 0);
            break;
        case 3:
            func_ov000_02198360(FLD(void *, self, 0x40), 0x12, 0);
            break;
        }
        r = TRUE;
        FLD(u32, self, 0x30) |= 1 << msg[5];
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

void func_ov010_0220aecc(u8 *self) {
    u8 *p;
    func_ov000_02194758(self);
    func_ov000_02198360(FLD(void *, self, 0x40), 1, 0);
    func_ov000_02198360(self + 0x158, 1, 0);
    FLD(s32, self, 0xd8) = 1;
    FLD(u8 *, self, 0xe8) = p = Ov010FxA_New();
    FLD(Ov010Flags8, p, 0).b0 = 1;
    FLD(Ov010Flags8, p, 0).b1 = 0;
    FLD(Ov010Flags8, p, 0).b2 = 0;
    FLD(u16, p, 2) = 0;
    FLD(s32, p, 4) = 0;
    FLD(Ov010Vec, p, 8) = data_ov010_0220f594;
    func_ov003_021da48c(p + 0x14, 0);
    FLD(u8 *, self, 0xec) = Ov010FxB_New();
    func_ov010_0220e740(FLD(u8 *, self, 0xec), self, &data_ov010_0220f534, 1, &data_ov010_0220f594, 0x68);
    if (FLD(Ov010Flags8, FLD(u8 *, self, 0xec), 0).b0) {
        FLD(s32, FLD(u8 *, self, 0xec), 0x14) = 0x4000;
    }
    FLD(Ov010Flags, self, 0xcc).b4 = 0;
    {
        u8 *mm = FLD(u8 *, self, 0x48);
        FLD(Ov010Flags, mm, 0x9a).b0 = 0;
        FLD(Ov010Flags, mm, 0x9a).b3 = 0;
        func_0203f364(mm);
    }
    {
        u8 *q = FLD(u8 *, self, 0x44);
        FLD(Ov010Flags, q, 0x22).b0 = 0;
        FLD(Ov010Flags, q, 0x22).b1 = 0;
    }
    FLD(Ov010Flags, FLD(u8 *, self, 0x38), 0xc2).b0 = 0;
    {
        u8 *m = FLD(u8 *, self, 0x38);
        FLD(s32, m, 0xa8) = 0x1400;
        FLD(s32, m, 0xac) = 0x1400;
        FLD(s32, m, 0xb0) = 0x1400;
    }
    FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = FLD(u16, self, 0xd0);
    FLD(Ov010Flags8, FLD(u8 *, self, 0x4c), 0x18).b4 = 1;
    FLD(Ov010Flags, FLD(u8 *, self, 0x48), 0x9a).b7 = 1;
    FLD(s32, FLD(u8 *, self, 0x48), 0x48) = FLD(s32, self, 0x64) + (FLD(s32, self, 0x64) >> 1);
    FLD(u8, self, 0xcf) = 1;
}


}

class Ov010Ac {
public:
    u8 unk_00[0xce];
    u8 f0 : 1;
    u8 f1 : 1;
    u8 f2 : 6;
    u8 unk_cf[0x9c];
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
extern u8 *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov010_0220e38c(void *p);
extern void func_ov010_0220e7c8(void *p);
extern void MTX_Identity33_(Ov010Mtx33 *m);
extern void MTX_RotX33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_RotY33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_RotZ33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_Concat33(Ov010Mtx33 *a, Ov010Mtx33 *b, Ov010Mtx33 *out);
extern void MTX_MultVec33(Ov010Vec *v, Ov010Mtx33 *m, Ov010Vec *out);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);

void func_ov010_0220b0a8(Ov010Ac *self) {
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
    switch (FLD(s32, self, 0xd8)) {
    case 6: {
        u8 *p = FLD(u8 *, self, 0xec);
        u8 n;
        if (FLD(Ov010Flags8, p, 0).b0) {
            n = FLD(u8, p, 0x6b);
        } else {
            n = 0;
        }
        if (n == 4) {
            FLD(Ov010Flags, FLD(u8 *, self, 0x44), 0x22).b1 = 0;
        }
        {
            u8 *q = FLD(u8 *, self, 0x44);
            FLD(Ov010Flags, q, 0x22).b0 = 1;
            FLD(Ov010Flags, q, 0x22).b1 = 1;
        }
        u16 a = FLD(u16, func_ov000_0219bf90(), 0xb1c);
        if (a == FLD(u16, self, 0xc)) {
            FLD(s32, self, 0xd8) = 8;
        }
        break;
    }
    case 7: {
        void *mgr = data_ov000_021ccd68;
        u16 id = FLD(u16, self, 0x180);
        u8 *o = mgr == NULL ? NULL : func_ov000_0218e640(mgr, id);
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
            MTX_MultVec33(&FLD(Ov010Vec, self, 0x184), &m, &FLD(Ov010Vec, self, 0x70));
            VEC_Add(&FLD(Ov010Vec, self, 0x70), &t, &FLD(Ov010Vec, self, 0x70));
        }
        break;
    }
    }
    if (FLD(void *, self, 0xe8) != NULL) {
        func_ov010_0220e38c(FLD(void *, self, 0xe8));
    }
    if (FLD(void *, self, 0xec) != NULL) {
        func_ov010_0220e7c8(FLD(void *, self, 0xec));
    }
    ((Ov010V *)((u8 *)self + 0x120))->v0c();
}

}
}  // namespace m_0220adb8

// ---- merged from ov010_0220b7b0.cpp
namespace m_0220b7b0 {
extern "C" {

extern void *data_ov000_021ccd68;
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern Ov010V *func_02065f88(s32 a, Ov010Vec *b);
extern void func_ov010_02209074(void *p);
extern void func_ov000_0218d398(void *obj, u16 id, s32 a, s32 b, s32 c, u8 *d);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern BOOL func_ov000_02190cb0(void *p, const void *a, s32 b, s32 c);
extern void func_ov000_021915a0(void *p);
extern u8 *func_ov000_02190a30(void *p, s32 a);
extern void func_ov000_02195d88(void *self);

static inline void *Ov010_FindObjById(u16 id) {
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

void func_ov010_0220b40c(u8 *self) {
    Ov010Vec p;
    Ov010Blk12 q;
    Ov010AnMsg msg;
    u8 c;
    switch (FLD(u16, FLD(void *, self, 0x40), 0)) {
    case 0: {
        u8 *fx = FLD(u8 *, self, 0xec);
        if (Ov010_FxCount(fx) == 1) {
            if (FLD(Ov010Flags8, fx, 0).b0) {
                func_02065860(data_0214a420, FLD(void *, fx, 8));
                FLD(s32, fx, 8) = 0;
                func_ov000_02198360(fx + 0x58, 1, 0);
            }
            fx = FLD(u8 *, self, 0xec);
            if (FLD(Ov010Flags8, fx, 0).b0) {
                FLD(u16, fx, 2) = 0;
                FLD(u16, fx, 4) = 0x50;
                func_ov003_021da48c(fx + 0x58, 2);
            }
            FLD(Ov010Flags8, self, 0xce).b3 = 0;
        }
        FLD(u16, self, 0xd6) = 0;
        FLD(u16, FLD(void *, self, 0x40), 0) = 1;
    }
    case 1:
        if (FLD(Ov010Flags8, self, 0xce).b3) {
            FLD(u16, FLD(void *, self, 0x40), 0) = 2;
        }
        return;
    case 2:
        if (FLD(u16, FLD(void *, self, 0x40), 2) % 8 == 0) {
            BOOL found = FALSE;
            u8 *o = FLD(u8 *, func_ov000_0218e4cc(data_ov000_021ccd68, 0x4000), 0xc);
            for (; o != NULL; o = FLD(u8 *, o, 8)) {
                if (o != self && FLD(u16, o, 0xe) == 0x4817) {
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
                        func_ov000_0218d398(o, FLD(u16, self, 0xc), 0xe, 1, 1, &c);
                        FLD(u16, self, 0xd6)++;
                        break;
                    }
                }
            }
            if (!found) {
                FLD(u16, FLD(void *, self, 0x40), 0) = 3;
            }
        }
        FLD(u16, FLD(void *, self, 0x40), 2)++;
        return;
    case 3: {
        u8 *a;
        u8 *b;
        Ov010V *e;
        FLD(u16, self, 0xd6)++;
        a = (u8 *)Ov010_FindObjById(FLD(u16, self, 0x180));
        b = (u8 *)Ov010_FindObjById(FLD(u16, self, 0x182));
        if (a != NULL && b != NULL) {
            u16 ang = func_ov000_0219a874(FLD(void *, a, 0x50), FLD(void *, b, 0x50), func_ov010_02207a44(FLD(u16, self, 0xd6)));
            msg.f0 = 0;
            msg.f1 = FLD(u16, self, 0xd6);
            msg.ang = ang;
            msg.kind = 0x11;
            msg.id = FLD(u16, self, 0xc);
            func_ov000_0219bdb0(FLD(u16, self, 0x180), FLD(u16, self, 0x182), 0xe, 0, 8, &msg);
            p.x = FLD(s32, a, 0x70);
            p.y = FLD(s32, a, 0x74);
            p.z = FLD(s32, a, 0x78);
            e = func_02065f88(0x38f, &p);
            e->v0c(0x2800);
            e->v24(0, FLD(s32, a, 0x68) >> 1, 0);
        }
        q = FLD(Ov010Blk12, self, 0x70);
        e = func_02065f88(0x321, (Ov010Vec *)&q);
        e->v0c(0x1000);
        FLD(void *, e, 0xdc) = (void *)func_ov010_02209074;
        FLD(s32, e, 4) = 6;
        FLD(Ov010Flags, FLD(void *, self, 0x38), 0xc2).b0 = 0;
        FLD(u16, FLD(void *, self, 0x40), 0) = 4;
        return;
    }
    case 4:
        func_ov000_02198360(FLD(void *, self, 0x40), 0x15, 0);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4817, 0x15);
        break;
    }
}

void func_ov010_0220b7b0(void *self) {
    if (FLD(u16, FLD(void *, self, 0x40), 0) != 0) {
        return;
    }
    Ov010Vec p = FLD(Ov010Vec, self, 0x70);
    Ov010V *fx;
    void *obj;
    fx = func_02065f88(0x321, &p);
    fx->v0c(0x1000);
    FLD(void *, fx, 0xdc) = (void *)func_ov010_02209074;
    FLD(s32, fx, 4) = 6;
    obj = Ov010_FindObjById(FLD(u16, self, 0x180));
    if (obj != NULL) {
        u8 c = 1;
        func_ov000_0218d398(obj, FLD(u16, self, 0xc), 0xe, 1, 1, &c);
    }
    FLD(Ov010Flags, FLD(void *, self, 0x38), 0xc2).b0 = 0;
    FLD(u8, self, 0xcf) = 0;
    func_ov000_02198360(FLD(void *, self, 0x40), 0x15, 0);
}

void func_ov010_0220b890(void *self) {
    if (FLD(u16, FLD(void *, self, 0x40), 0) != 0) {
        return;
    }
    if (FLD(void *, self, 0x38) != NULL) {
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f540, 0x1000, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
    }
    FLD(u16, FLD(void *, self, 0x40), 0) = 1;
    FLD(s32, self, 0x9c) = 0;
    FLD(s32, self, 0xa0) = 0;
    FLD(s32, self, 0xa4) = 0;
    FLD(s32, self, 0xa8) = 0;
}

void func_ov010_0220b8f8(void *self) {
    u8 *p = func_ov000_02190a30(FLD(void *, self, 0x38), 0);
    FLD(Ov010Flags8, p, 0x111).b3 = 0;
    func_ov000_02195d88(self);
}

extern void *data_02097e4c;
extern void func_0203f324(void *p);
extern void func_0203f364(void *p);
extern void func_ov000_0218dbe0(void *self, s32 a);
extern void MTX_RotY33_(void *m, s32 s, s32 c);
extern void MTX_MultVec33(const Ov010Vec *v, const void *m, Ov010Vec *out);
extern u16 func_ov003_021d9c38(Ov010Vec *v);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *c);
extern void VEC_Normalize(const Ov010Vec *a, Ov010Vec *b);
extern void func_ov003_021d9e90(Ov010Vec *a, Ov010Vec *b, Ov010Vec *c, s32 d, s32 e);
extern void func_ov003_021da2c8(void *self, s32 a, s32 b, s32 c, s32 d);
extern void func_ov003_021d9f04(void *out, const void *p);
extern void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
extern s32 func_02040498(s32 max);
extern void *func_ov000_02199ba0(void *p);
extern Ov010V *func_ov003_021da7e8(s32 id, void *src, const Ov010Vec *ofs);
extern void *func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern s32 func_ov003_021d9a80(const Ov010Vec &a, const Ov010Vec *b);

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

static inline Ov010Vec Ov010_TargetCenter(void *self) {
    Ov010Vec v;
    Ov010Vec *b = FLD(Ov010Vec *, self, 0xe4);
    s32 *a = FLD(s32 *, self, 0xe0);
    switch (FLD(s32, self, 0xdc)) {
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

void func_ov010_0220b924(void *self) {
    Ov010Vec d;
    Ov010Vec v1;
    Ov010Vec v2;
    Ov010Mtx33 m;
    Ov010Vec o;
    Ov010Vec p;
    Ov010Vec d2;
    Ov010HitMsg msg;
    void *s40 = FLD(void *, self, 0x40);
    switch (FLD(u16, s40, 0)) {
    case 0:
    case 0x10: {
        void *mm = FLD(void *, self, 0x48);
        FLD(Ov010Flags, mm, 0x9a).b0 = 1;
        FLD(Ov010Flags, mm, 0x9a).b3 = 1;
        func_0203f324(mm);
        FLD(s32, FLD(void *, self, 0x48), 0x30) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(u16, self, 0x98) = FLD(u16, self, 0x7e);
        FLD(s32, self, 0x9c) = 0x2b0;
        FLD(s32, self, 0xa0) = 0x80;
        FLD(s32, self, 0xa8) = 0x20;
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x11;
        break;
    }
    case 0x11:
        FLD(u16, s40, 2)++;
        if (FLD(u16, FLD(void *, self, 0x40), 2) >= 0xc) {
            FLD(u16, FLD(void *, self, 0x40), 2) = 0;
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x20;
        }
        func_ov000_0218dbe0(self, 0);
        break;
    case 0x20:
        FLD(s32, self, 0xa4) = 0xa00;
        func_ov000_0218dbe0(self, 0);
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x21;
        break;
    case 0x21: {
        s32 k;
        FLD(u16, s40, 2)++;
        FLD(u16, FLD(void *, self, 0x40), 2) = 0;
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x30;
        func_ov000_0218dbe0(self, 0);
        k = FLD(s32, self, 0xa4);
        if (k != 0 && k != 0x1000) {
            FLD(s32, self, 0xa0) = Ov010_FxMul(FLD(s32, self, 0xa0), k);
        }
        break;
    }
    case 0x30: {
        void *t;
        BOOL ok;
        FLD(u16, self, 0x98) = FLD(u16, self, 0x7e);
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        FLD(s32, self, 0x9c) = 0;
        t = Ov010_FindObjById2(FLD(u16, self, 0x90));
        ok = FALSE;
        if (t != NULL) {
            BOOL b;
            BOOL a;
            void *q;
            s32 dot;
            u16 ang;
            Ov010_VecSubA(&FLD(Ov010Vec, t, 0x70), &FLD(Ov010Vec, self, 0x70), &d);
            q = FLD(void *, t, 0x40);
            a = (q != NULL ? FLD(u8, q, 0x13) : 0) == 0x13;
            b = FALSE;
            MTX_RotY33_(&m, OV010_SIN(FLD(u16, self, 0x98)), OV010_COS(FLD(u16, self, 0x98)));
            MTX_MultVec33(&data_ov010_0220f54c, &m, &v1);
            ang = func_ov003_021d9c38(&d);
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
            FLD(s32, self, 0x108) = p.x - FLD(s32, self, 0x70);
            FLD(s32, self, 0x10c) = p.y - FLD(s32, self, 0x74);
            FLD(s32, self, 0x110) = p.z - FLD(s32, self, 0x78);
            VEC_Normalize(&FLD(Ov010Vec, self, 0x108), &FLD(Ov010Vec, self, 0x108));
        } else {
            func_ov003_021d9900(&FLD(Ov010Vec, self, 0x108), 0xfc71, &data_ov010_0220f54c);
            func_ov003_021d9980(&FLD(Ov010Vec, self, 0x108), FLD(u16, self, 0x7e), &FLD(Ov010Vec, self, 0x108));
        }
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x31;
        break;
    }
    case 0x31: {
        s32 sp;
        void *s48;
        sp = FLD(s32, self, 0x9c) + 0x180;
        FLD(s32, self, 0x9c) = sp;
        if (sp > 0x1666) {
            sp = 0x1666;
        } else if (sp < 0) {
            sp = 0;
        }
        FLD(s32, self, 0x9c) = sp;
        func_ov003_021d9e90(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0x108), &FLD(Ov010Vec, self, 0x70), FLD(s32, self, 0x9c), FLD(s32, self, 0xa0));
        func_ov003_021da2c8(self, FLD(s32, self, 0x9c), FLD(s32, self, 0xa0), FLD(s32, self, 0xa4), FLD(s32, self, 0xa8));
        func_ov003_021d9f04(&FLD(u16, self, 0x7c), &FLD(Ov010Vec, self, 0x108));
        s48 = FLD(void *, self, 0x48);
        FLD(s32, s48, 0x44) = OV010_FXMUL_K(FLD(s32, s48, 0x38), 0x800);
        func_ov000_021987b8(FLD(void *, self, 0x48), 1, 0, 0);
        if (FLD(u32, FLD(void *, self, 0x48), 0x58) & 0x20) {
            void *t = Ov010_FindObjById2(FLD(u16, self, 0x90));
            void *q;
            Ov010V *e;
            if (t == NULL) {
                FLD(u16, FLD(void *, self, 0x40), 0) = 0x50;
                return;
            }
            FLD(u16, self, 0x180) = FLD(u16, t, 0xc);
            FLD(Ov010Flags8, func_ov000_02190a30(FLD(void *, self, 0x38), 0), 0x111).b3 = 1;
            FLD(u16, self, 0x7c) += (u16)(func_02040498(0x2000) - 0x1000);
            FLD(u16, self, 0x7e) += (u16)(func_02040498(0x2000) - 0x1000);
            q = func_ov000_02199ba0(FLD(void *, self, 0x4c));
            if (q != NULL) {
                FLD(u16, self, 0x182) = FLD(u16, q, 0xc);
                msg.a = func_ov000_0219a874(FLD(void *, t, 0x50), FLD(void *, q, 0x50), 0x14);
                msg.b = 0x10;
                msg.id = FLD(u16, self, 0xc);
                func_ov000_0218d398(t, FLD(u16, self, 0xc), 9, 0, 6, (u8 *)&msg);
            }
            Ov010_VecSubB(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, t, 0x70), &d2);
            func_ov003_021d9980(&d2, (u16)(0xffff - FLD(u16, t, 0x7e)), &d2);
            e = func_ov003_021da7e8(0x6c, t, &d2);
            e->v34((u16)(FLD(u16, self, 0x7c) + 0x4000), 0, 0);
            e->v0c(0x1800);
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x40;
            func_02049f44(data_02097e4c, 0x66, &FLD(Ov010Vec, self, 0x70), 0);
            return;
        }
        if (func_ov003_021d9a80(Ov010_TargetCenter(self), &FLD(Ov010Vec, self, 0x70)) > 0x190000) {
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x50;
        }
        break;
    }
    case 0x40: {
        void *t = Ov010_FindObjById3(FLD(u16, self, 0x180));
        u8 *ec;
        BOOL found;
        if (t == NULL) {
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x50;
            return;
        }
        Ov010_VecSubB(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, t, 0x70), &FLD(Ov010Vec, self, 0x184));
        FLD(u16, self, 0x190) = FLD(u16, t, 0x7c);
        FLD(u16, self, 0x192) = FLD(u16, t, 0x7e);
        FLD(u16, self, 0x194) = FLD(u16, t, 0x80);
        FLD(u16, self, 0x196) = FLD(u16, self, 0x7c);
        FLD(u16, self, 0x198) = FLD(u16, self, 0x7e);
        FLD(u16, self, 0x19a) = FLD(u16, self, 0x80);
        FLD(s32, self, 0xd8) = 7;
        {
            void *mm = FLD(void *, self, 0x48);
            FLD(Ov010Flags, mm, 0x9a).b0 = 0;
            FLD(Ov010Flags, mm, 0x9a).b3 = 0;
            func_0203f364(mm);
        }
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x41;
        ec = FLD(u8 *, self, 0xec);
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
            ec = FLD(u8 *, self, 0xec);
            if (!FLD(Ov010Flags8, ec, 0).b0) {
                return;
            }
            func_02065860(data_0214a420, FLD(void *, ec, 8));
            FLD(void *, ec, 8) = NULL;
            func_ov000_02198360(ec + 0x58, 1, 0);
            return;
        }
        func_ov000_02198360(FLD(void *, self, 0x40), 6, 0);
        break;
    }
    case 0x41:
        break;
    case 0x50: {
        func_ov000_02198360(s40, 0x15, 0);
        {
            void *mm = FLD(void *, self, 0x48);
            FLD(Ov010Flags, mm, 0x9a).b0 = 0;
            FLD(Ov010Flags, mm, 0x9a).b3 = 0;
            func_0203f364(mm);
        }
        {
            Ov010Flags *f = &FLD(Ov010Flags, FLD(void *, self, 0x44), 0x22);
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

void func_ov010_0220c2a4(void *self) {
    void *m;
    switch (FLD(u16, FLD(void *, self, 0x40), 0)) {
    case 0:
        m = FLD(void *, self, 0x48);
        FLD(Ov010Flags, m, 0x9a).b0 = 1;
        FLD(Ov010Flags, m, 0x9a).b3 = 1;
        func_0203f324(m);
        m = FLD(void *, self, 0x44);
        FLD(Ov010Flags, m, 0x22).b0 = 0;
        FLD(Ov010Flags, m, 0x22).b1 = 0;
        FLD(s32, self, 0xa8) = 0x52;
        FLD(u16, FLD(void *, self, 0x40), 0)++;
        break;
    case 1:
        if (FLD(void *, self, 0x48) != NULL) {
            func_ov000_021987b8(FLD(void *, self, 0x48), 1, 0, 0);
            if (FLD(u32, FLD(void *, self, 0x48), 0x50) & 0x20000000) {
                u8 c = 1;
                func_ov000_0218d398(self, FLD(u16, self, 0xc), 0xe, 1, 1, &c);
            }
        }
        break;
    }
    func_ov000_0218dbe0(self, 0);
}

void func_ov010_0220c390(void *self) {
    if (FLD(u16, FLD(void *, self, 0x40), 0) == 0) {
        u8 *g;
        Ov010V *fx;
        if (FLD(u8, self, 0xcf) != 0) {
            func_02049f44(data_02097e4c, 0x19, (u8 *)self + 0x70, 0);
        }
        g = (u8 *)data_ov000_021ccd54;
        FLD(Ov010Flags8, g, 0x190).b2 = 1;
        FLD(Ov010Flags8, g, 0x190).b3 = 1;
        FLD(Ov010Flags8, g, 0x190).b4 = 1;
        g[0x18d] = 5;
        g[0x18e] = 0xf;
        g[0x18f] = 0xf;
        fx = func_02065f88(0x38f, (u8 *)self + 0x70);
        fx->v24(0, 0x800, 0);
        fx->v0c(0x1800);
    }
    func_ov000_0219763c(self);
    func_ov000_0219aae8(self, self, FLD(u16, FLD(void *, self, 0x4c), 0x8), FLD(u16, FLD(void *, self, 0x4c), 0xa), 2, NULL, 0, 0x1b33, 0, 0x57e, 0x1000);
}
extern void func_ov003_021da48c(void *p, s32 a);

void func_ov010_0220c49c(u8 *self) {
    s32 y;
    s32 z;
    s32 x;
    FLD(Ov010Flags8, self, 0xce).b0 = 0;
    FLD(Ov010Flags8, self, 0xce).b1 = 0;
    FLD(Ov010Flags8, self, 0xce).b2 = 0;
    FLD(Ov010Flags8, self, 0xce).b3 = 0;
    FLD(u8, self, 0xcf) = 0;
    FLD(u16, self, 0xd0) = 0xffff;
    FLD(u16, self, 0xd2) = 0xffff;
    FLD(u16, self, 0xd4) = 0;
    FLD(u16, self, 0xd6) = 0;
    FLD(s32, self, 0xd8) = 0;
    FLD(s32, self, 0xdc) = -1;
    FLD(s32, self, 0xe0) = 0;
    FLD(s32, self, 0xe4) = 0;
    FLD(s32, self, 0xe8) = 0;
    FLD(s32, self, 0xec) = 0;
    Ov010_VecCopy(&FLD(Ov010Vec, self, 0xf0), &data_ov010_0220f594);
    x = FLD(Ov010Vec, self, 0xf0).x;
    y = FLD(Ov010Vec, self, 0xf0).y;
    z = FLD(Ov010Vec, self, 0xf0).z;
    Ov010_VecSet(&FLD(Ov010Vec, self, 0xfc), x, y, z);
    Ov010_VecSet(&FLD(Ov010Vec, self, 0x108), x, y, z);
    Ov010_VecSet(&FLD(Ov010Vec, self, 0x114), x, y, z);
    func_ov003_021da48c(self + 0x158, 0);
    func_ov003_021da48c(self + 0x16c, 0);
    FLD(u16, self, 0x180) = 0xffff;
    FLD(u16, self, 0x182) = 0xffff;
    Ov010_VecSet(&FLD(Ov010Vec, self, 0x184), x, y, z);
    {
        const Ov010Rot3 *s = &data_ov010_0220f544;
        u16 a, b, c;
        FLD(Ov010Rot3, self, 0x190).x = a = s->x;
        FLD(Ov010Rot3, self, 0x190).y = b = s->y;
        FLD(Ov010Rot3, self, 0x190).z = c = s->z;
        FLD(Ov010Rot3, self, 0x196).x = a;
        FLD(Ov010Rot3, self, 0x196).y = b;
        FLD(Ov010Rot3, self, 0x196).z = c;
    }
}

}
}  // namespace m_0220c2a4

// ---- merged from ov010_0220c5a0.cpp
namespace m_0220c5a0 {
extern "C" {

extern void *data_ov000_021ccd68;
extern u8 *func_ov000_0218e640(void *mgr, u16 id);
extern void VEC_MultAdd(s32 s, const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);
extern BOOL func_ov010_022090b4(s32 type, s32 *a, Ov010Vec *b, Ov010Vec *pos);
extern u16 func_ov010_02209190(s32 type, s32 *a, Ov010Vec *b, Ov010Vec *pos, u16 rot);
extern s32 func_ov000_0219a2f4(Ov010Vec *p, s32 a, s32 b);

static inline u8 *Ov010_FindActor(u16 id) {
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
        u8 *a = Ov010_FindActor(FLD(u16, self, 0xd2));
        u8 *m;
        if (a == NULL || (m = FLD(u8 *, a, 0x48)) == NULL) {
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

void func_ov010_0220c758(void *self) {
    u16 t;
    s32 *ap;
    Ov010Vec *bp;
    switch (FLD(u16, self, 0x158)) {
    case 0: {
        u8 *a = Ov010_FindActor(FLD(u16, self, 0xd2));
        if (a != NULL && FLD(u8 *, a, 0x48) != NULL) {
            t = 0;
            Ov010Mark *c_0;
            switch (FLD(u8, self, 0x16b)) {
            case 2: {
                bp = FLD(Ov010Vec *, self, 0xe4);
                ap = FLD(s32 *, self, 0xe0);
                Ov010Vec p_0;
                p_0 = Ov010_RandPoint(FLD(s32, self, 0xdc), ap, bp);
                t = 0x3c;
                FLD(Ov010Vec, self, 0xf0) = p_0;
                FLD(u16, self, 0xd4) = 0;
                break;
            }
            case 3: {
                Ov010Vec p_1;
                p_1 = Ov010_RandPoint(FLD(s32, self, 0xdc), FLD(s32 *, self, 0xe0), FLD(Ov010Vec *, self, 0xe4));
                FLD(Ov010Vec, self, 0xf0) = p_1;
                FLD(u16, self, 0xd4) = func_02040498(0xffff);
                t = 0x64;
                break;
            }
            }
            c_0 = FLD(Ov010Mark *, self, 0xe8);
            if (c_0->b0) {
                c_0->b1 = 1;
                c_0->time = t;
                c_0->pos = FLD(Ov010Vec, self, 0xf0);
                func_ov003_021da48c(c_0->st, 0);
            }
        }
        FLD(u16, self, 0x158) = 1;
        break;
    }
    case 1: {
        Ov010Mark *c_1 = FLD(Ov010Mark *, self, 0xe8);
        BOOL busy;
        BOOL done_0;
        if (c_1->b0 && c_1->b1) {
            c_1->pos = FLD(Ov010Vec, self, 0xf0);
        }
        c_1 = FLD(Ov010Mark *, self, 0xe8);
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
        FLD(u16, self, 0x158) = 2;
        break;
    }
    case 2: {
        Ov010Mark *c_2 = FLD(Ov010Mark *, self, 0xe8);
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
        c_2 = FLD(Ov010Mark *, self, 0xe8);
        p_2 = c_2->b0 ? &c_2->pos : NULL;
        FLD(Ov010Vec, self, 0xf0) = *p_2;
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
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);
extern BOOL func_ov003_021d7a44(void *self, const Ov010Vec *target, const Ov010Vec *start, s32 speed, s32 maxDist, u8 noSnap);
extern void *func_0204a028(void *mgr, s32 id, const Ov010Vec *pos, s32 a);
extern Ov010V *func_02065f88(s32 id, const Ov010Vec *pos);
extern void func_ov010_02209074(void *p);

static inline u8 *Ov010_FindActorD(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return (u8 *)func_ov000_0218e640(data_ov000_021ccd68, id);
}

extern void *data_ov000_021ccd54;
extern s32 func_ov003_021d9a80(const Ov010Vec *a, const Ov010Vec *b);
extern BOOL func_ov003_021d98bc(Ov010Vec *a, void *b);
extern void func_ov003_021d9f80(void *rot, const Ov010Vec *a, const Ov010Vec *b);
extern void func_ov003_021d9dbc(Ov010Vec *out, const Ov010Vec *a, const Ov010Vec *b, s32 dist, s32 yoff);
extern void func_ov003_021da2c8(void *self, s32 a, s32 b, s32 c, s32 d);
extern u16 func_ov003_021d9c38(void *p);
extern void *func_ov000_02199ba0(void *p);
extern void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, const void *f, void *g, s32 h, s32 i, s32 j, s32 k);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void *func_ov003_021d7bd4(void *p);
extern u8 *func_ov000_02190a30(void *p, s32 a);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);

static inline void Ov010_Puff(u8 *self) {
    Ov010Vec q;
    Ov010V *e;
    *(Ov010Blk12 *)&q = FLD(Ov010Blk12, self, 0x70);
    e = func_02065f88(0x321, &q);
    e->v0c(0x1000);
    FLD(void *, e, 0xdc) = (void *)func_ov010_02209074;
    FLD(s32, e, 4) = 6;
}

static inline void Ov010_Dust(u8 *self) {
    u16 ry = FLD(u16, self, 0x7e);
    u16 rx = FLD(u16, self, 0x7c);
    Ov010Vec p;
    s32 y = FLD(s32, self, 0x74);
    s32 z = FLD(s32, self, 0x78);
    p.x = FLD(s32, self, 0x70);
    p.y = y + FLD(s32, self, 0x68) / 2;
    p.z = z;
    func_02065f88(0x192, &p)->v34(rx, ry, 0);
}

void func_ov010_0220cba0(u8 *self) {
    switch (FLD(u16, self, 0x16c)) {
    case 0:
    case 10: {
        u8 *t = Ov010_FindActorD(FLD(u16, self, 0xd0));
        Ov010Vec d;
        if (t == NULL || FLD(s32, self, 0xd8) != 1) {
            FLD(u16, self, 0x16c) = 0x1e;
            return;
        }
        FLD(s32, self, 0xd8) = 4;
        Ov010_VecCopy(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, t, 0x70));
        VEC_Add(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0xfc), &FLD(Ov010Vec, self, 0x70));
        FLD(Ov010Flags, FLD(u8 *, self, 0x38), 0xc2).b0 = 1;
        {
            s32 x = FLD(s32, self, 0x70);
            s32 y = FLD(s32, self, 0x74);
            s32 z = FLD(s32, self, 0x78);
            FLD(s32, self, 0x114) = x;
            FLD(s32, self, 0x118) = y;
            FLD(s32, self, 0x11c) = z;
            FLD(s32, self, 0x118) = FLD(s32, self, 0x118) + (0x5800 - FLD(s32, self, 0x100));
            FLD(s32, self, 0x9c) = 0xa00;
            FLD(s32, self, 0xa0) = 0;
            FLD(s32, self, 0xa4) = 0;
            FLD(s32, self, 0xa8) = 0;
            d.x = FLD(s32, self, 0xf0) - x;
            d.y = FLD(s32, self, 0xf4) - y;
            d.z = FLD(s32, self, 0xf8) - z;
        }
        FLD(u16, self, 0x7e) = func_ov003_021d9c38(&d);
        func_0204a028(data_02097e4c, 0x29, &FLD(Ov010Vec, self, 0x70), 5);
        Ov010_Puff(self);
        FLD(u16, self, 0x16c) = 0xb;
        return;
    }
    case 0xb:
        if (FLD(s32, self, 0xa4) == 0) {
            if (func_ov003_021d9a80(&FLD(Ov010Vec, self, 0x114), &FLD(Ov010Vec, self, 0x70)) < 0x9000) {
                FLD(s32, self, 0xa4) = 0xa00;
            }
        }
        if (func_ov003_021d98bc(&FLD(Ov010Vec, self, 0x114), self + 0x70) || FLD(s32, self, 0x9c) < 0x80) {
            FLD(u16, self, 0x16c) = 0x14;
            return;
        }
        func_ov003_021d9f80(self + 0x7c, &FLD(Ov010Vec, self, 0xf0), &FLD(Ov010Vec, self, 0x70));
        func_ov003_021d9dbc(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0x114), &FLD(Ov010Vec, self, 0x70), FLD(s32, self, 0x9c), FLD(s32, self, 0xa0));
        func_ov003_021da2c8(self, FLD(s32, self, 0x9c), FLD(s32, self, 0xa0), FLD(s32, self, 0xa4), FLD(s32, self, 0xa8));
        return;
    case 0x14:
        func_ov003_021d7a44(self + 0x120, &FLD(Ov010Vec, self, 0xf0), &FLD(Ov010Vec, self, 0x70), 0x100, 0x2000, 0);
        func_ov003_021d9f80(self + 0x7c, &FLD(Ov010Vec, self, 0xf0), &FLD(Ov010Vec, self, 0x70));
        FLD(u16, self, 0x16c) = 0x15;
        return;
    case 0x15: {
        Ov010Vec a;
        Ov010Vec b;
        Ov010V *e;
        FLD(u16, self, 0x16e)++;
        if (FLD(u16, self, 0x16e) == 10) {
            Ov010_Dust(self);
        }
        {
            Ov010Vec *v = (Ov010Vec *)((Ov010V *)(self + 0x120))->v10();
            FLD(s32, self, 0x70) = v->x;
            FLD(s32, self, 0x74) = v->y;
            FLD(s32, self, 0x78) = v->z;
        }
        FLD(Ov010Flags, FLD(u8 *, self, 0x48), 0x9a).b7 = 1;
        func_ov000_021987b8(FLD(void *, self, 0x48), 1, 0, 0);
        {
            u16 mask = ~(1 << (FLD(u16, self, 0xc) >> 12));
            u16 dd = FLD(u16, FLD(u8 *, self, 0x4c), 0xa);
            u16 c = FLD(u16, FLD(u8 *, self, 0x4c), 8);
            void *x = func_ov000_02199ba0(FLD(void *, self, 0x4c));
            if (func_ov000_0219aae8(self, x, c, dd, mask, NULL, NULL, 0x400, 0, 0x38f, 0x1000)) {
                Ov010_Puff(self);
                func_ov000_02198360(FLD(void *, self, 0x40), 0x15, 0);
                return;
            }
        }
        if (!(FLD(u32, FLD(u8 *, self, 0x48), 0x50) & 0x20000000)) {
            if (!((Ov010V *)(self + 0x120))->v14()) {
                return;
            }
        }
        {
            u16 ang;
            u8 *g;
            u8 *m;
            *(Ov010Blk12 *)&a = FLD(Ov010Blk12, self, 0x70);
            *(Ov010Blk12 *)&b = data_ov010_0220f588;
            ang = func_ov003_021d9c38(func_ov003_021d7bd4(self + 0x120)) + 0x7fff;
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
                if (FLD(u16, self, 0x7c) > 0x7fff) {
                    r = FLD(u16, self, 0x7c) - 0xe38;
                } else {
                    r = FLD(u16, self, 0x7c) + 0xe38;
                }
                FLD(u16, self, 0x7c) = r;
            }
            m = func_ov000_02190a30(FLD(void *, self, 0x38), 0);
            FLD(u8, m, 0x111) |= 8;
            FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
            FLD(s32, self, 0xd8) = 6;
            FLD(u16, self, 0x16c) = 0x1e;
            FLD(u16, self, 0x16e) = 0;
            func_02049f44(data_02097e4c, 0x52, self + 0x70, 0);
        }
        return;
    }
    case 0x1e:
        ((Ov010V *)(self + 0x120))->v08();
        FLD(Ov010Flags8, self, 0xce).b1 = 0;
        return;
    }
}


void func_ov010_0220d1c4(u8 *self) {
    switch (FLD(u16, self, 0x16c)) {
    case 0: {
        u8 *t = Ov010_FindActorD(FLD(u16, self, 0xd0));
        if (t != NULL && FLD(s32, self, 0xd8) == 1) {
            Ov010Vec p;
            Ov010Vec q;
            Ov010V *e;
            FLD(s32, self, 0xd8) = 3;
            Ov010_VecCopy(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, t, 0x70));
            VEC_Add(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0xfc), &FLD(Ov010Vec, self, 0x70));
            FLD(u16, self, 0x7c) = 0xbfff;
            FLD(Ov010Flags, FLD(u8 *, self, 0x38), 0xc2).b0 = 1;
            p.x = FLD(s32, self, 0x70);
            p.y = FLD(s32, self, 0x74) + 0xa000;
            p.z = FLD(s32, self, 0x78);
            func_ov003_021d7a44(self + 0x120, &p, &FLD(Ov010Vec, self, 0x70), 0x29, 0x4cd, 0);
            func_0204a028(data_02097e4c, 0x29, &FLD(Ov010Vec, self, 0x70), 5);
            OV010_BLKCPY(&q, self + 0x70);
            e = func_02065f88(0x321, &q);
            e->v0c(0x1000);
            FLD(void *, e, 0xdc) = (void *)func_ov010_02209074;
            FLD(s32, e, 4) = 6;
            FLD(u16, self, 0x16c) = 1;
        } else {
            FLD(u16, self, 0x16c) = 2;
        }
        break;
    }
    case 1: {
        Ov010Vec *v = (Ov010Vec *)((Ov010V *)(self + 0x120))->v10();
        FLD(s32, self, 0x70) = v->x;
        FLD(s32, self, 0x74) = v->y;
        FLD(s32, self, 0x78) = v->z;
        if (((Ov010V *)(self + 0x120))->v14()) {
            FLD(u16, self, 0x16c) = 2;
        }
        break;
    }
    case 2:
        FLD(s32, self, 0xd8) = 2;
        FLD(Ov010Flags, FLD(u8 *, self, 0x38), 0xc2).b0 = 0;
        ((Ov010V *)(self + 0x120))->v08();
        FLD(Ov010Flags8, self, 0xce).b1 = 0;
        break;
    }
}


extern s32 func_02040498(s32 max);

void func_ov010_0220d3d8(u8 *self) {
    switch (FLD(u16, self, 0x16c)) {
    case 0:
        if (FLD(s32, self, 0xd8) != 2) {
            FLD(u16, self, 0x16c) = 2;
            return;
        }
        FLD(s32, self, 0xd8) = 4;
        FLD(s32, self, 0x70) = FLD(s32, self, 0xf0);
        FLD(s32, self, 0x78) = FLD(s32, self, 0xf8);
        FLD(s32, self, 0x74) = FLD(s32, self, 0xf4) + 0xa000;
        VEC_Add(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0xfc), &FLD(Ov010Vec, self, 0x70));
        FLD(u16, self, 0x7c) = 0x4000;
        FLD(u16, self, 0x7e) = func_02040498(0xffff);
        FLD(Ov010Flags, FLD(u8 *, self, 0x38), 0xc2).b0 = 1;
        func_ov003_021d7a44(self + 0x120, &FLD(Ov010Vec, self, 0xf0), &FLD(Ov010Vec, self, 0x70), 0x8cd, 0x8cd, 1);
        FLD(u16, self, 0x16c) = 1;
        break;
    case 1: {
        Ov010Vec a;
        Ov010Vec b;
        Ov010Vec q;
        Ov010Vec q2;
        Ov010V *e;
        Ov010Vec *v = (Ov010Vec *)((Ov010V *)(self + 0x120))->v10();
        FLD(s32, self, 0x70) = v->x;
        FLD(s32, self, 0x74) = v->y;
        FLD(s32, self, 0x78) = v->z;
        FLD(Ov010Flags, FLD(u8 *, self, 0x48), 0x9a).b7 = 1;
        func_ov000_021987b8(FLD(void *, self, 0x48), 1, 0, 0);
        {
        u16 mask = ~(1 << (FLD(u16, self, 0xc) >> 12));
        u16 d = FLD(u16, FLD(u8 *, self, 0x4c), 0xa);
        u16 c = FLD(u16, FLD(u8 *, self, 0x4c), 8);
        void *x = func_ov000_02199ba0(FLD(void *, self, 0x4c));
        if (func_ov000_0219aae8(self, x, c, d, mask, NULL, NULL, 0x400, 0, 0x38f, 0x1000)) {
            *(Ov010Blk12 *)&q = FLD(Ov010Blk12, self, 0x70);
            e = func_02065f88(0x321, &q);
            e->v0c(0x1000);
            FLD(void *, e, 0xdc) = (void *)func_ov010_02209074;
            FLD(s32, e, 4) = 6;
            func_ov000_02198360(FLD(void *, self, 0x40), 0x15, 0);
            return;
        }
        }
        if (FLD(u32, FLD(u8 *, self, 0x48), 0x50) & 0x20000000) {
            u16 ang;
            u8 *g;
            u8 *m;
            a.x = FLD(s32, self, 0x70);
            a.y = FLD(s32, self, 0x74) - FLD(s32, FLD(u8 *, self, 0x48), 0x38);
            a.z = FLD(s32, self, 0x78);
            *(Ov010Blk12 *)&b = data_ov010_0220f570;
            ang = func_ov003_021d9c38(func_ov003_021d7bd4(self + 0x120)) + 0x7fff;
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
            FLD(u16, self, 0x7c) += func_02040498(0x2aaa) - 0x1555;
            m = func_ov000_02190a30(FLD(void *, self, 0x38), 0);
            FLD(u8, m, 0x111) |= 8;
            FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
            FLD(u16, self, 0x16c) = 2;
            FLD(s32, self, 0xd8) = 6;
            func_02049f44(data_02097e4c, 0x52, self + 0x70, 0);
        }
        break;
    }
    case 2:
        ((Ov010V *)(self + 0x120))->v08();
        FLD(Ov010Flags8, self, 0xce).b1 = 0;
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
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov003_021d7848(void *p);
extern void *func_ov003_021d7858(void *p);
extern void func_ov003_021d7948(void *p);
extern BOOL func_ov003_021d7894(void *p, s32 a, s32 b);
extern void func_ov003_021d79ac(void *p, Ov010Node *n);
extern Ov010Node *func_ov003_021d7980(void *p);
extern void *func_ov000_0218bf1c(void *mgr, Ov010SpawnDesc *d, s32 a, Ov010Rot3s *r, s32 b);
extern void func_ov010_0220a948(void *obj, s32 a, s32 b, s32 c, u16 d, u16 e);

static inline void *Ov010_FindObjById(u16 id) {
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
            func_ov003_021d79ac(self->pool, n);
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

s32 func_ov010_0220d9a4(Ov010Coll *self) {
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
        func_ov003_021d79ac(self->pool, n);
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

static inline void Ov010_0220dd60_Reset(void *self) {
    FLD(s32, self, 0xd0) = -1;
    FLD(s32, self, 0xd4) = 0;
    FLD(s32, self, 0xd8) = 0;
    MTX_Identity33_((u8 *)self + 0xdc);
}

void *func_ov010_0220dd60(void *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov010_022102e0;
    Ov010_0220dd60_Reset(self);
    return self;
}

static inline void Ov010_0220dd60_Dtor(void *self) {
    FLD(void *, self, 0) = data_ov010_022102e0;
    func_02065860(data_0214a420, FLD(s32, self, 0xd4));
    Ov010_0220dd60_Reset(self);
    func_ov000_0219429c(self);
}

void *func_ov010_0220dd9c(void *self) {
    Ov010_0220dd60_Dtor(self);
    return self;
}

void *func_ov010_0220ddf0(void *self) {
    Ov010_0220dd60_Dtor(self);
    func_0203de1c(self);
    return self;
}

void func_ov010_0220de4c(void *self, s32 a) {
    if (FLD(u8, self, 0x14) == 1) {
        FLD(s32, self, 0xd0) = a;
    }
}

s32 func_ov010_0220de5c(void *self) {
    u8 m[0x24];
    s32 r = 0;
    if (FLD(void *, self, 0x38) != NULL && FLD(s32, self, 0xd0) != -1) {
        switch (FLD(s32, self, 0xd0)) {
        case 0:
            MTX_RotY33_((u8 *)self + 0xdc, OV010_SIN(FLD(u16, self, 0x7e)), OV010_COS(FLD(u16, self, 0x7e)));
            break;
        case 1:
            MTX_RotZ33_(m, OV010_SIN(0x4000), OV010_COS(0x4000));
            MTX_RotY33_((u8 *)self + 0xdc, OV010_SIN(FLD(u16, self, 0x7e)), OV010_COS(FLD(u16, self, 0x7e)));
            MTX_Concat33(m, (u8 *)self + 0xdc, (u8 *)self + 0xdc);
            break;
        }
        FLD(Ov010Vec, FLD(u8 *, self, 0x38), 0x78) = FLD(Ov010Vec, self, 0x70);
        MI_Copy36B((u8 *)self + 0xdc, FLD(u8 *, self, 0x38) + 0x84);
        r = func_ov000_021903b4(FLD(void *, self, 0x38));
    }
    return r;
}

void func_ov010_0220df64(void *self) {
    func_ov000_02194758(self);
    Ov010Vec v = data_ov010_0220f57c;
    FLD(Ov010Vec, FLD(u8 *, self, 0x38), 0xa8) = v;
}

void func_ov010_0220dfac(void *self) {
    void *m;
    if (FLD(u16, FLD(void *, self, 0x40), 0) != 0) {
        return;
    }
    if (FLD(s32, self, 0xd0) == -1) {
        FLD(s32, self, 0xd0) = 0;
    }
    func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f540, 0x1000, 0);
    func_ov000_021915a0(FLD(void *, self, 0x38));
    m = FLD(void *, self, 0x48);
    if (m != NULL) {
        FLD(Ov010Flags, m, 0x9a).b0 = 0;
        FLD(Ov010Flags, m, 0x9a).b3 = 0;
        func_0203f364(m);
        m = FLD(void *, self, 0x48);
        FLD(Ov010Flags, m, 0x9a).b1 = 0;
        FLD(Ov010Flags, m, 0x9a).b4 = 0;
        m = FLD(void *, self, 0x48);
        FLD(Ov010Flags, m, 0x9a).b2 = 0;
        FLD(Ov010Flags, m, 0x9a).b5 = 0;
    }
    func_ov000_02198360(FLD(void *, self, 0x40), 4, 0);
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

void func_ov010_0220e06c(u8 *self) {
    Ov010Vec p;
    Ov010Rot16 ra;
    Ov010Rot16 rb;
    s32 scale;
    switch (FLD(u16, FLD(u8 *, self, 0x40), 0)) {
    case 0:
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        FLD(s32, self, 0x9c) = 0x733;
        FLD(u16, self, 0x98) = FLD(u16, self, 0x7e);
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 1;
        break;
    case 1:
        if (FLD(s32, self, 0xd8) > 0x28000) {
            func_ov000_02198360(FLD(u8 *, self, 0x40), 0x15, 0);
        }
        break;
    }
    FLD(s32, self, 0x9c) = Ov010_FxMul(FLD(s32, self, 0x9c), 0x1029);
    FLD(s32, self, 0xd8) += FLD(s32, self, 0x9c);
    func_ov000_0218dbe0(self, 0);
    if (FLD(void *, self, 0x48) == NULL) {
        return;
    }
    scale = Ov010_FxMul(FLD(s32, FLD(u8 *, self, 0x38), 0xa8), FLD(s32, self, 0x64));
    switch (FLD(s32, self, 0xd0)) {
    case 0: {
        u16 a = FLD(u16, self, 0x7e) + 0x4000;
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
        if (FLD(s32, self, 0x74) - p.y < scale) {
            near = TRUE;
        }
        o = func_020657b0(data_0214a420, FLD(s32, self, 0xd4));
        if (h != -0x1000 && near) {
            p.y += 0x800;
            if (o != NULL) {
                o->v18(&p);
                o->v34(0, (u16)(FLD(u16, self, 0x7e) + 0x7fff), 0);
            } else {
                Ov010V *n = func_02065f88(0x25e, &p);
                n->v34(0, (u16)(FLD(u16, self, 0x7e) + 0x7fff), 0);
                n->v14(0x1800, 0x1800, 0x1800);
                FLD(s32, self, 0xd4) = FLD(s32, n, 0x24);
            }
        } else if (o != NULL) {
            func_02063a14(o);
            FLD(s32, self, 0xd4) = 0;
        }
        break;
    }
    }
    func_ov000_0219aae8(self, self, FLD(u16, FLD(u8 *, self, 0x4c), 8), FLD(u16, FLD(u8 *, self, 0x4c), 0xa), 2, &data_ov010_0220f594, &ra, 0x800, scale, 100, 0x1000);
    func_ov000_0219aae8(self, self, FLD(u16, FLD(u8 *, self, 0x4c), 8), FLD(u16, FLD(u8 *, self, 0x4c), 0xa), 2, &data_ov010_0220f594, &rb, 0x800, scale, 100, 0x1000);
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
