#include "ov002/ov002.h"
#include "types.h"

extern "C" {

// The TU's two .bss objects, reached through the 0x021f0f98 pool literal plus offsets. They are
// defined before the first function, which already reads them that way.
void *data_ov002_021f0f98;
void *data_ov002_021f0f9c;

}

// ---- merged from ov002_021e4b80.cpp
namespace m_021e4b80 {
extern "C" {

void func_ov002_021e4b80(void *self) {
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, s32) = 0;
    {
        void *saved;
        HEAP_PUSH(saved);
        if (FIELD(self, 0xc, void *) != NULL) {
            Heap_FreeArray(FIELD(self, 0xc, void *));
            FIELD(self, 0xc, void *) = NULL;
        }
        HEAP_POP(saved);
    }
}

s32 func_ov002_021e4bd0(void *self, u32 idx) {
    if (idx >= FIELD(self, 0x8, u32) || FIELD(self, 0xc, u8 *) == NULL) {
        return 0;
    }
    return FIELD(FIELD(self, 0xc, u8 *) + idx * 0xc, 0x4, s32);
}

s32 func_ov002_021e4c00(void *self, u32 idx) {
    if (idx >= FIELD(self, 0x8, u32) || FIELD(self, 0xc, u8 *) == NULL) {
        return 0;
    }
    return FIELD(FIELD(self, 0xc, u8 *) + idx * 0xc, 0x8, s32);
}

u32 func_ov002_021e4c30(int which) {
    u32 r = 0;
    switch (which) {
    case 0:
        r = data_02097dd0->frameCount / 3600;
        break;
    case 1:
        r = FIELD(data_0214a424, 0xa, u16);
        break;
    case 2:
        r = FIELD(data_0214a424, 0xc, u32);
        break;
    case 3:
        r = FIELD(data_0214a424, 0x61c, u16);
        break;
    case 4:
        r = FIELD(data_0214a424, 0x10, u32);
        break;
    case 5:
        r = FIELD(data_0214a424, 0x14, u16);
        break;
    case 6:
        r = FIELD(data_0214a424, 0x16, u16);
        break;
    }
    return r;
}

void func_ov002_021e4cd8(void *self) {
    u8 *ctx;
    FIELD(self, 0x4, s32) = -1;
    FIELD(self, 0x8, s32) = 1;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s32) = 0;
    FIELD(self, 0x14, s32) = 0;
    FIELD(self, 0x18, s32) = 0;
    FIELD(self, 0x1c, s32) = 0;
    FIELD(self, 0x20, s32) = -0x29;
    FIELD(self, 0x24, s32) = 0;
    MIi_CpuClear32(0, (u8 *)self + 0x28, 0x20);
    FIELD(self, 0x48, s32) = 0;
    ctx = (u8 *)data_ov002_021f0f9c;
    if (FIELD(ctx, 0xe0, void *) == NULL) {
        FIELD(ctx, 0xdc, void *) = self;
    } else {
        FIELD(FIELD(ctx, 0xe0, void *), 0x24, void *) = self;
    }
    FIELD(ctx, 0xe0, void *) = self;
}

void func_ov002_021e4d4c(void *self) {
    int i;
    u8 *owner = FIELD(self, 0x48, u8 *);
    if (owner != NULL) {
        for (i = 0; i < 8; i++) {
            if (((void **)(owner + 0x28))[i] == self) {
                ((void **)(owner + 0x28))[i] = NULL;
                break;
            }
        }
        FIELD(self, 0x48, void *) = NULL;
    }
    for (i = 0; i < 8; i++) {
        void *child = ((void **)((u8 *)self + 0x28))[i];
        if (child != NULL) {
            FIELD(child, 0x48, void *) = NULL;
        }
    }
}

void func_ov002_021e4dac(void *self, void *item) {
    int i;
    for (i = 0; i < 8; i++) {
        if (((void **)((u8 *)self + 0x28))[i] == NULL) {
            ((void **)((u8 *)self + 0x28))[i] = item;
            return;
        }
    }
}

}
}  // namespace m_021e4b80

// ---- merged from ov002_021e4dd4.cpp
namespace m_021e4dd4 {
extern "C" {

BOOL func_ov002_021e4dd4(VObject *self) {
    BOOL r = TRUE;
    switch (FIELD(self, 0xc, s32)) {
    case 0:
        if (!self->v0xc()) {
            break;
        }
        FIELD(self, 0xc, s32) = 1;
    case 1:
        if (!self->v0x10()) {
            break;
        }
        FIELD(self, 0xc, s32) = 2;
    case 2:
        if (!self->v0x14()) {
            break;
        }
        FIELD(self, 0xc, s32) = 3;
    case 3: {
        u8 *g = (u8 *)data_ov002_021f0f9c;
        s32 m;
        if (FIELD(g, 0x10, u8)) {
            break;
        }
        m = FIELD(self, 0x8, s32);
        if (m == 3) {
            m = 2;
        }
        if (m != FIELD(g, 0xc, s32)) {
            break;
        }
        if (self->v0x18()) {
            break;
        }
        FIELD(self, 0xc, s32) = 4;
    }
    case 4:
    default:
        FIELD(self, 0xc, s32) = 4;
        r = FALSE;
        break;
    }
    return r;
}

}
}  // namespace m_021e4dd4

// ---- merged from ov002_021e4ec0.cpp
namespace m_021e4ec0 {
extern "C" {

BOOL func_ov002_021e4ec0(void) {
    return TRUE;
}

BOOL func_ov002_021e4ec8(void) {
    return TRUE;
}

BOOL func_ov002_021e4ed0(void) {
    return TRUE;
}

BOOL func_ov002_021e4ed8(void) {
    return FALSE;
}

void func_ov002_021e4ee0(void) {
}

void *func_ov002_021e4ee4(void *self, s32 kind, s32 min) {
    s32 limit;
    void *best = NULL;
    limit = FIELD(data_ov002_021f0f9c, 0xd0, s32);
    int i;
    for (i = 0; i < 8; i++) {
        u8 *item = ((u8 **)((u8 *)self + 0x28))[i];
        if (item != NULL && kind == FIELD(item, 0x4, s32)) {
            s32 v = FIELD(item, 0x18, s32);
            if (min + 1 <= v && v <= limit) {
                best = item;
                limit = v;
            }
        }
    }
    return best;
}

void func_ov002_021e4f48(void *self) {
    u8 *ctx;
    s32 v;
    if (FIELD(self, 0x8, u32) & 0x10) {
        v = FIELD(self, 0xae, u8);
    } else {
        v = -1;
    }
    if (v != 0) {
        return;
    }
    ctx = (u8 *)data_ov002_021f0f98;
    if (FIELD(ctx, 0x1ec, s32) != 0) {
        func_ov002_021e4fac(self);
    }
    if (FIELD(ctx, 0x1f0, Bits8).b1) {
        self = FIELD(self, 0xb4, void *);
        MI_Copy36B(NNS_G3dGlbGetInvV(), (u8 *)self + 0x28);
    }
}

}
}  // namespace m_021e4ec0

// ---- merged from ov002_021e4fac.cpp
namespace m_021e4fac {
extern "C" {

void MTX_Concat33(void *a, void *b, void *c);

void func_ov002_021e4fac(void *self) {
    u8 *o = FIELD(data_ov002_021f0f98, 0x1ec, u8 *);
    u8 *m = FIELD(self, 0xb4, u8 *);
    s32 a = FIELD(o, 0xdc, s32);
    s32 b = FIELD(o, 0xe0, s32);
    s32 c = FIELD(o, 0xe4, s32);
    s32 sx = FIELD(o, 0x94, s32);
    s32 sy = FIELD(o, 0x98, s32);
    s32 sz = FIELD(o, 0x9c, s32);
    if (FIELD(m, 0x0, u32) & 1) {
        FIELD(m, 0x4, s32) = 0x1000;
        FIELD(m, 0x8, s32) = 0x1000;
        FIELD(m, 0xc, s32) = 0x1000;
        FIELD(m, 0x0, u32) &= ~1;
    }
    FIELD(m, 0x4, s32) = FX_MUL(sx, FIELD(m, 0x4, s32));
    FIELD(m, 0x8, s32) = FX_MUL(sy, FIELD(m, 0x8, s32));
    FIELD(m, 0xc, s32) = FX_MUL(sz, FIELD(m, 0xc, s32));
    if (FIELD(m, 0x0, u32) & 2) {
        MTX_Identity33_((MtxFx33 *)(m + 0x28));
        FIELD(m, 0x0, u32) &= ~2;
    }
    MTX_Concat33(m + 0x28, o + 0xb8, m + 0x28);
    if (FIELD(m, 0x0, u32) & 4) {
        FIELD(m, 0x0, u32) &= ~4;
    }
    FIELD(m, 0x4c, s32) = a;
    FIELD(m, 0x50, s32) = b;
    FIELD(m, 0x54, s32) = c;
}

}
}  // namespace m_021e4fac

// ---- merged from ov002_021e50a8.cpp
namespace m_021e50a8 {
extern "C" {

void func_ov002_021e50a8(void *self, void *src) {
    MIi_CpuCopy32(src, (u8 *)self + 0xc0 + FIELD(self, 0x1a0, s32) * 0x1c, 0x1c);
    FIELD(self, 0x1a0, s32)++;
}

}
}  // namespace m_021e50a8

// ---- merged from ov002_021e50d8.cpp
namespace m_021e50d8 {
extern "C" {
typedef struct Rec021e50d8 {
    s32 id;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    u8 e;
    u8 f;
    s32 g;
} Rec021e50d8;

void func_ov002_021e50d8(void *self, s32 a, s32 b) {
    Rec021e50d8 rec;
    rec.id = 0;
    rec.a = a;
    rec.b = b;
    rec.c = 0;
    rec.d = 0;
    rec.e = 0;
    rec.f = 0;
    rec.g = 0;
    rec.id = (u8)FIELD(self, 0x4c, s32);
    MIi_CpuCopy32(&rec, (u8 *)self + 0xc0 + FIELD(self, 0x1a0, s32) * 0x1c, 0x1c);
    FIELD(self, 0x1a0, s32)++;
}
}
}  // namespace m_021e50d8

// ---- merged from ov002_021e5140.cpp
namespace m_021e5140 {
extern "C" {

typedef struct Ent021e5140 {
    s32 kind;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    u8 e;
    u8 f;
    s32 g;
} Ent021e5140;

typedef struct Self021e5140 {
    u8 pad[0xc0];
    Ent021e5140 ents[8];
} Self021e5140;

static inline void setv021e5140(void *self, s32 v) {
    FIELD(self, 0x4c, s32) = v >> 12;
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x20, s32) = v;
}

void func_ov002_021e5140(void *self) {
    s32 i;
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x20, s32) = -0xa66;
    FIELD(self, 0x4c, s32) = FIELD(self, 0x20, s32) >> 12;
    FIELD(self, 0x50, s32) = 0;
    FIELD(self, 0x54, s32) = 0;
    FIELD(self, 0x58, s32) = 0;
    FIELD(self, 0x5c, s32) = 0;
    FIELD(self, 0x60, s32) = 0;
    FIELD(self, 0x64, s32) = 0;
    FIELD(self, 0xbc, s32) = 0;
    for (i = 0; i < 8; i++) {
        u8 *e = (u8 *)self + i * 0x1c;
        FIELD(e, 0xc0, s32) = 0;
        FIELD(e, 0xc4, s32) = 0;
        FIELD(e, 0xc8, s32) = 0;
        FIELD(e, 0xcc, s32) = 0;
        FIELD(e, 0xd0, s32) = 0;
        FIELD(e, 0xd4, u8) = 0;
        FIELD(e, 0xd5, u8) = 0;
        FIELD(e, 0xd8, s32) = 0;
    }
    FIELD(self, 0x1a0, s32) = 0;
    FIELD(self, 0x1a4, s32) = 0;
    FIELD(self, 0x1a8, s32) = 0;
    FIELD(self, 0x1ac, s32) = 0;
    FIELD(self, 0x1b0, s32) = 0x1000;
    FIELD(self, 0x1b4, s32) = 0x1000;
    FIELD(self, 0x1b8, s32) = 0x1000;
    MTX_Identity33_((MtxFx33 *)((u8 *)self + 0x1bc));
    FIELD(self, 0x1e0, s32) = 0;
    FIELD(self, 0x1e4, s32) = 0;
    FIELD(self, 0x1e8, s32) = 0;
    FIELD(self, 0x1ec, s32) = 0;
    FIELD(self, 0x1f0, u8) = 0;
}

void func_ov002_021e51f8(void *self) {
    s32 i;
    if (FIELD(self, 0x10, s32) >= 0x28) {
        if (FIELD(self, 0x5c, void **) != NULL) {
            func_0203f0b4(*FIELD(self, 0x5c, void **));
        }
        for (i = 0; i < FIELD(self, 0x1a0, s32); i++) {
            u8 *e = (u8 *)self + 0xc0 + i * 0x1c;
            if (FIELD(e, 0x10, void **) != NULL) {
                func_0203f0b4(*FIELD(e, 0x10, void **));
            } else if (FIELD(e, 0x15, u8)) {
                func_0203f0b4(*FIELD(e, 0x18, void **));
            }
        }
    }
    if (FIELD(self, 0x14, void *) != NULL) {
        if (FIELD(self, 0x50, void *) != NULL) {
            func_02035acc(FIELD(self, 0x50, void *), FIELD(self, 0x54, void *), 4);
        } else {
            func_02036838(data_02097cdc, (char *)FIELD(self, 0x54, void *), 4, 0);
        }
    }
    for (i = 0; i < FIELD(self, 0x1a0, s32); i++) {
        u8 *e = (u8 *)self + 0xc0 + i * 0x1c;
        if (FIELD(e, 0x14, u8)) {
            if (FIELD(e, 0x4, void *) != NULL) {
                if (FIELD(e, 0x15, u8)) {
                    func_02035acc(FIELD(e, 0x4, void *), FIELD(e, 0x8, void *), 4);
                } else {
                    func_02035acc(FIELD(e, 0x4, void *), FIELD(e, 0x8, void *), 5);
                }
            } else {
                func_02036838(data_02097cdc, (char *)FIELD(e, 0x8, void *), 5, 0);
            }
        }
    }
}

}
}  // namespace m_021e5140

// ---- merged from ov002_021e5344.cpp
namespace m_021e5344 {
extern "C" {

BOOL func_ov002_021e5344(void) {
    return TRUE;
}

}

extern "C" {
extern char data_ov002_021f0640[];
void *func_02034ec0(void *a, void *b);
void *func_02034f5c(void *a, void *b);
void *func_02035ccc(void *a);
void func_02035cfc(void *a);
void func_02039494(u32 a);
void *NNS_G3dGetResDataByName(void *a, char *name);
void NNSi_G3dModifyMatFlag(void *mdl, BOOL a, u32 flag);
void *STD_ConcatenateString(char *dst, const char *src);
BOOL func_0203ed04(const char *name, u32 res);
u32 func_0203ebf8(void);
BOOL NNS_G3dBindMdlTex(void *mdl, void *tex);
BOOL NNS_G3dBindMdlPltt(void *mdl, void *tex);

typedef struct Ent021e534c {
    s32 kind;
    void *arc;
    char *name;
    u32 task;
    u32 *res;
    u8 loaded;
    u8 alt;
    u32 *res2;
} Ent021e534c;

static inline void *ov002_021e534c_getMdl(u8 *set, char *name) {
    u32 *e;
    if (set != NULL && (e = (u32 *)NNS_G3dGetResDataByName(set + 8, name)) != NULL) {
        return set + *e;
    }
    return NULL;
}

static inline void *ov002_021e534c_mdlName(void *self) {
    return FIELD(self, 0x58, void *) != NULL ? FIELD(self, 0x58, void *) : FIELD(self, 0x54, void *);
}

static inline u32 *ov002_021e534c_res(Ent021e534c *e) {
    return e->alt ? e->res2 : e->res;
}

BOOL func_ov002_021e534c(void *self) {
    BOOL done = FALSE;
    switch (FIELD(self, 0x10, s32)) {
    case 0:
        if (FIELD(self, 0x50, void *) != NULL) {
            func_020359fc(FIELD(self, 0x50, void *), FIELD(self, 0x54, void *), 4, 0);
        } else {
            func_020359d0((char *)FIELD(self, 0x54, void *), 4, 0);
        }
        FIELD(self, 0x14, s32) = 1;
        FIELD(self, 0x10, s32) = 10;
    case 10: {
        void *res;
        if (FIELD(self, 0x50, void *) != NULL) {
            if (!func_02035bd4(FIELD(self, 0x50, void *), FIELD(self, 0x54, void *), 4)) {
                break;
            }
            void *p = func_02035f30(FIELD(self, 0x50, void *), FIELD(self, 0x54, void *), 4);
            res = func_02034ec0(p, FIELD(self, 0x54, void *));
        } else {
            if (!func_02035b90((char *)FIELD(self, 0x54, void *), 4)) {
                break;
            }
            res = func_02035ccc(FIELD(self, 0x54, void *));
        }
        FIELD(self, 0x5c, void *) = res;
        FIELD(self, 0x10, s32)++;
    }
    case 11: {
        char name[16];
        char path[32];
        MI_CpuFill8(name, 0, sizeof(name));
        if (FIELD(self, 0x58, void *) != NULL) {
            STD_CopyLString(name, (char *)FIELD(self, 0x58, void *), sizeof(name));
        } else {
            STD_CopyLString(name, (char *)FIELD(self, 0x54, void *), sizeof(name));
        }
        FIELD(self, 0x60, void *) = ov002_021e534c_getMdl((u8 *)NNS_G3dGetMdlSet((NNSG3dResFileHeader *)*FIELD(self, 0x5c, u32 *)), name);
        STD_CopyLString(path, data_ov002_021f0640, sizeof(path));
        STD_ConcatenateString(path, FIELD(self, 0x54, char *));
        if (FIELD(self, 0x5c, u32 *) != NULL) {
            func_0203ed04(path, *FIELD(self, 0x5c, u32 *));
        }
        FIELD(self, 0xbc, u32) = func_0203ebf8();
        NNSi_G3dModifyMatFlag(FIELD(self, 0x60, void *), FALSE, 0x40);
        NNSi_G3dModifyMatFlag(FIELD(self, 0x60, void *), FALSE, 0x80);
        NNSi_G3dModifyMatFlag(FIELD(self, 0x60, void *), FALSE, 0x200);
        NNSi_G3dModifyMatFlag(FIELD(self, 0x60, void *), FALSE, 0x400);
        FIELD(self, 0x10, s32)++;
    }
    case 12:
        if (func_0203e63c((unsigned int)FIELD(self, 0xbc, u32))) {
            FIELD(self, 0xbc, u32) = 0;
            FIELD(self, 0x10, s32)++;
        }
        break;
    case 13:
        func_02039494(*FIELD(self, 0x5c, u32 *));
        for (s32 i = 0; i < FIELD(self, 0x1a0, s32); i++) {
            Ent021e534c *e = &((Ent021e534c *)((u8 *)self + 0xc0))[i];
            if (e->arc != NULL) {
                func_020359fc(e->arc, e->name, 5, 0);
            } else {
                func_020359d0(e->name, 5, 0);
            }
            e->loaded = 1;
        }
        FIELD(self, 0x10, s32) = 20;
    case 20: {
        BOOL ok = TRUE;
        for (s32 i = 0; i < FIELD(self, 0x1a0, s32); i++) {
            Ent021e534c *e = &((Ent021e534c *)((u8 *)self + 0xc0))[i];
            BOOL r;
            if (e->arc != NULL) {
                r = func_02035bd4(e->arc, e->name, 5);
            } else {
                r = func_02035b90(e->name, 5);
            }
            ok = (ok & r) ? TRUE : FALSE;
        }
        if (!ok) {
            break;
        }
        FIELD(self, 0x10, s32)++;
    }
    case 21:
        for (s32 i = 0; i < FIELD(self, 0x1a0, s32); i++) {
            Ent021e534c *e = &((Ent021e534c *)((u8 *)self + 0xc0))[i];
            if (e->arc != NULL) {
                void *p = func_02035f30(e->arc, e->name, 5);
                u32 *r = (u32 *)func_02034f5c(p, e->name);
                if (r == NULL) {
                    func_02035acc(e->arc, e->name, 5);
                    func_020359fc(e->arc, e->name, 4, 0);
                    e->alt = 1;
                }
                e->res = r;
            } else {
                func_02035cfc(e->name);
            }
        }
        FIELD(self, 0x10, s32)++;
    case 22: {
        BOOL ok = TRUE;
        for (s32 i = 0; i < FIELD(self, 0x1a0, s32); i++) {
            Ent021e534c *e = &((Ent021e534c *)((u8 *)self + 0xc0))[i];
            if (e->alt) {
                ok = (ok & func_02035bd4(e->arc, e->name, 4)) ? TRUE : FALSE;
            }
        }
        if (!ok) {
            break;
        }
        FIELD(self, 0x10, s32)++;
    }
    case 23:
        for (s32 i = 0; i < FIELD(self, 0x1a0, s32); i++) {
            Ent021e534c *e = &((Ent021e534c *)((u8 *)self + 0xc0))[i];
            if (e->alt) {
                void *p = func_02035f30(e->arc, e->name, 4);
                e->res2 = (u32 *)func_02034ec0(p, e->name);
            }
        }
        FIELD(self, 0x10, s32) = 30;
    case 30:
        for (s32 i = 0; i < FIELD(self, 0x1a0, s32); i++) {
            Ent021e534c *e = &((Ent021e534c *)((u8 *)self + 0xc0))[i];
            char path[32];
            void *tex;
            path[0] = 0;
            STD_CopyLString(path, data_ov002_021f0640, sizeof(path));
            STD_ConcatenateString(path, e->name);
            tex = NNS_G3dGetTex((NNSG3dResFileHeader *)*ov002_021e534c_res(e));
            if (e->alt) {
                if (e->res2 != NULL) {
                    func_0203ed04(path, *e->res2);
                }
            } else {
                if (e->res != NULL) {
                    func_0203ed04(path, *e->res);
                }
            }
            NNS_G3dBindMdlTex(FIELD(self, 0x60, void *), tex);
            NNS_G3dBindMdlPltt(FIELD(self, 0x60, void *), tex);
            e->task = func_0203ebf8();
        }
        FIELD(self, 0x10, s32)++;
    case 31: {
        BOOL ok = TRUE;
        for (s32 i = 0; i < FIELD(self, 0x1a0, s32); i++) {
            if (!func_0203e63c((unsigned int)(void *)((Ent021e534c *)((u8 *)self + 0xc0))[i].task)) {
                ok = FALSE;
                break;
            }
        }
        if (ok) {
            FIELD(self, 0x10, s32)++;
        }
        break;
    }
    case 32:
        for (s32 i = 0; i < FIELD(self, 0x1a0, s32); i++) {
            Ent021e534c *e = &((Ent021e534c *)((u8 *)self + 0xc0))[i];
            if (e->task != 0) {
                func_02039494(*(e->alt ? e->res2 : e->res));
            }
            e->task = 0;
        }
        FIELD(self, 0x10, s32) = 0x28;
    case 0x28:
        done = TRUE;
        break;
    default:
        FIELD(self, 0x10, s32) = 0x28;
        break;
    }
    return done;
}
}
}  // namespace m_021e5344

// ---- merged from ov002_021e5974.cpp
namespace m_021e5974 {
extern "C" {

// Kinds of the scene objects in the `+0xdc` list (the `+0x4` word). 7 is the camera
// (func_ov002_021e7390 reads its position, target, up vector and angle).
typedef enum Ov002ObjKind {
    OV002_OBJ_CAMERA = 7,
    OV002_OBJ_CAMERA2 = 8
} Ov002ObjKind;

BOOL func_ov002_021e5974(void *self) {
    Ov002ObjKind kind;
    u8 *p;
    NNS_G3dRenderObjInit((NNSG3dRenderObj *)((u8 *)self + 0x68), (NNSG3dResMdl *)FIELD(self, 0x60, void *));
    FIELD(self, 0x64, void *) = NNS_G3dGetTex((NNSG3dResFileHeader *)*FIELD(self, 0x5c, void **));
    if (FIELD(self, 0x1f0, Bits8).b0) {
        kind = OV002_OBJ_CAMERA2;
    } else {
        kind = OV002_OBJ_CAMERA;
    }
    for (p = FIELD(data_ov002_021f0f9c, 0xdc, u8 *); p != NULL; p = FIELD(p, 0x24, u8 *)) {
        if (kind == FIELD(p, 0x4, s32)) {
            s32 st = FIELD(p, 0x8, s32);
            switch (st) {
            case 1:
                FIELD(self, 0x1e0, u8 *) = p;
                break;
            case 2:
                FIELD(self, 0x1e4, u8 *) = p;
                break;
            default:
                FIELD(self, 0x1e0, u8 *) = p;
                break;
            }
            FIELD(p, 0x8, s32) = st;
        }
    }
    return TRUE;
}

}
}  // namespace m_021e5974

// ---- merged from ov002_021e5a10.cpp
namespace m_021e5a10 {
extern "C" {

void func_ov002_021e5fe4(void *p);

BOOL func_ov002_021e5a10(void *self) {
    void *n;
    void *c;
    if (FIELD(data_ov002_021f0f9c, 0xd0, s32) > FIELD(self, 0x1c, s32)) {
        return FALSE;
    }
    n = NULL;
    c = FIELD(self, 0x1e8, void *);
    if (c == NULL) {
        n = func_ov002_021e4ee4(self, 2, -1);
    } else if (FIELD(c, 0xe8, Bits8).b1) {
        n = func_ov002_021e4ee4(self, 2, FIELD(c, 0x18, s32));
    }
    if (n != NULL) {
        if (FIELD(self, 0x1e8, void *) != NULL) {
            func_ov002_021e6360(FIELD(self, 0x1e8, void *));
        }
        func_ov002_021e5fe4(n);
        FIELD(self, 0x1e8, void *) = n;
    }
    n = NULL;
    c = FIELD(self, 0x1ec, void *);
    if (c == NULL) {
        n = func_ov002_021e4ee4(self, 3, -1);
    } else if (FIELD(c, 0xe8, Bits8).b1) {
        n = func_ov002_021e4ee4(self, 3, FIELD(c, 0x18, s32));
    }
    if (n != NULL) {
        if (FIELD(self, 0x1ec, void *) != NULL) {
            func_ov002_021e6360(FIELD(self, 0x1ec, void *));
        }
        func_ov002_021e61b4(n);
        FIELD(self, 0x1ec, void *) = n;
    }
    return TRUE;
}

}
}  // namespace m_021e5a10

// ---- merged from ov002_021e5cf4.cpp
namespace m_021e5cf4 {
extern "C" {

void NNS_G3dRenderObjSetCallBack(void *a, void *fn, int b, int c, int d);
void NNS_G3dRenderObjResetCallBack(void *a);
void func_ov002_021e4f48(void *self);

static inline void ov002_021e5b08_Scale(VecFx32 *out, const VecFx32 *in, s32 s) {
    out->x = FX_MUL(in->x, s);
    out->y = FX_MUL(in->y, s);
    out->z = FX_MUL(in->z, s);
}

void func_ov002_021e5b08(void *self) {
    VObject *o;
    if (FIELD(data_ov002_021f0f9c, 0xd0, s32) <= FIELD(self, 0x18, s32)) {
        return;
    }
    switch (FIELD(data_ov002_021f0f9c, 0xc, s32)) {
    case 1:
        o = FIELD(self, 0x1e0, VObject *);
        break;
    case 2:
        o = FIELD(self, 0x1e4, VObject *);
        break;
    default:
        o = FIELD(self, 0x1e0, VObject *);
        break;
    }
    o->v0x20();
    if (FIELD(self, 0x1f0, Bits8).b0) {
        VecFx32 v;
        ov002_021e5b08_Scale(&v, &FIELD(self, 0x1b0, VecFx32), 0x64000);
        v.z = 0x1000;
        NNS_G3dGlbSetBaseScale(&v);
        ov002_021e5b08_Scale(&v, &FIELD(self, 0x1a4, VecFx32), 0x64000);
        v.z = FIELD(self, 0x20, s32);
        NNS_G3dGlbSetBaseTrans(&v);
        MI_Copy36B((u8 *)self + 0x1bc, data_020928b4);
        NNS_G3dGlb.flag &= ~0xa4;
    } else {
        MI_Copy36B((u8 *)self + 0x1bc, data_020928b4);
        NNS_G3dGlb.flag &= ~0xa4;
        NNS_G3dGlbSetBaseTrans((VecFx32 *)((u8 *)self + 0x1a4));
        NNS_G3dGlbSetBaseScale((VecFx32 *)((u8 *)self + 0x1b0));
    }
    NNS_G3dGlbFlushVP();
    data_ov002_021f0f98 = self;
    NNS_G3dRenderObjSetCallBack((u8 *)self + 0x68, (void *)func_ov002_021e4f48, 0, 6, 2);
    NNS_G3dDraw((NNSG3dRenderObj *)((u8 *)self + 0x68));
    NNS_G3dRenderObjResetCallBack((u8 *)self + 0x68);
    data_ov002_021f0f98 = NULL;
}


void func_ov002_021e5cf4(void) {
}

BOOL func_ov002_021e5cf8(void *self) {
    return FIELD(self, 0xc, s32) >= 3;
}

void func_ov002_021e5d0c(void *self) {
    FIELD(self, 0x4, s32) = 2;
    FIELD(self, 0x10, s32) = 0;
    FIELD(self, 0x4c, s32) = 0;
    FIELD(self, 0x50, s32) = 0;
    FIELD(self, 0x54, s32) = 0;
    FIELD(self, 0x58, s32) = -1;
    FIELD(self, 0x5c, s32) = -1;
    FIELD(self, 0x60, s32) = 0;
    FIELD(self, 0x64, s32) = 0;
    FIELD(self, 0x68, s32) = 0;
    FIELD(self, 0x6c, s32) = 0;
    FIELD(self, 0x70, s32) = 0;
    FIELD(self, 0x74, s32) = 0;
    FIELD(self, 0x78, s32) = 0;
    FIELD(self, 0x7c, s32) = 0;
    FIELD(self, 0x80, s32) = 0;
    FIELD(self, 0x84, s32) = 0;
    FIELD(self, 0x88, s32) = 0x1000;
    FIELD(self, 0x8c, s32) = 0;
    MI_CpuFill8((u8 *)self + 0x90, 0, 0x58);
    FIELD(self, 0xe8, s32) = 0;
}

void func_ov002_021e5d88(void *self) {
    if (FIELD(self, 0x64, void *) != NULL) {
        Heap_FreeHi(FIELD(self, 0x64, void *));
        FIELD(self, 0x64, void *) = NULL;
    }
    if (FIELD(self, 0x68, void *) != NULL) {
        Heap_FreeHi(FIELD(self, 0x68, void *));
        FIELD(self, 0x68, void *) = NULL;
    }
    if (FIELD(self, 0x6c, void *) != NULL) {
        Heap_FreeHi(FIELD(self, 0x6c, void *));
        FIELD(self, 0x6c, void *) = NULL;
    }
    if (FIELD(self, 0x70, void *) != NULL) {
        Heap_FreeHi(FIELD(self, 0x70, void *));
        FIELD(self, 0x70, void *) = NULL;
    }
    if (FIELD(self, 0x74, void *) != NULL) {
        Heap_FreeHi(FIELD(self, 0x74, void *));
        FIELD(self, 0x74, void *) = NULL;
    }
    if (FIELD(self, 0x14, s32) != 0) {
        if (FIELD(self, 0x4c, void *) != NULL) {
            func_02035acc(FIELD(self, 0x4c, void *), FIELD(self, 0x50, void *), 6);
        } else {
            func_02036838(data_02097cdc, (char *)FIELD(self, 0x50, void *), 6, 0);
        }
    }
}

BOOL func_ov002_021e5e3c(void) {
    return TRUE;
}

BOOL func_ov002_021e5e44(void *self) {
    BOOL r = FALSE;
    switch (FIELD(self, 0x10, s32)) {
    case 0:
        if (FIELD(self, 0x4c, void *) != NULL) {
            func_020359fc(FIELD(self, 0x4c, void *), FIELD(self, 0x50, void *), 6, 0);
        } else {
            func_020359d0((char *)FIELD(self, 0x50, void *), 6, 0);
        }
        FIELD(self, 0x14, s32) = 1;
        FIELD(self, 0x10, s32)++;
        break;
    case 1:
        if (FIELD(self, 0x4c, void *) != NULL) {
            if (func_02035bd4(FIELD(self, 0x4c, void *), FIELD(self, 0x50, void *), 6) == 0) {
                break;
            }
            {
                void *t = func_02035f30(FIELD(self, 0x4c, void *), FIELD(self, 0x50, void *), 6);
                FIELD(self, 0x60, void *) = func_02034ff8(t, (char *)FIELD(self, 0x50, void *));
            }
        } else {
            if (func_02035b90((char *)FIELD(self, 0x50, void *), 6) == 0) {
                break;
            }
            FIELD(self, 0x60, void *) = func_02035d2c(FIELD(self, 0x50, void *));
        }
    case 10:
        FIELD(self, 0x10, s32) = -1;
        r = TRUE;
        break;
    }
    return r;
}

BOOL func_ov002_021e5f2c(void) {
    return TRUE;
}

BOOL func_ov002_021e5f34(void *self) {
    Bits8 *fl = &FIELD(self, 0xe8, Bits8);
    s32 lim = FIELD(data_ov002_021f0f9c, 0xd0, s32);
    if (fl->b2) {
        return FALSE;
    }
    if (!fl->b0 || lim <= FIELD(self, 0x18, s32)) {
        return TRUE;
    }
    if (!fl->b1) {
        BOOL t = FALSE;
        if (FIELD(self, 0x8c, s32) >= 0 && FIELD(self, 0x7c, s32) > FIELD(self, 0x8c, s32)) {
            t = TRUE;
        }
        if (t) {
            FIELD(self, 0xe8, Bits8).b1 = 1;
        }
    }
    func_ov002_021e63f0(self);
    if (!FIELD(self, 0xe8, Bits8).b1) {
        FIELD(self, 0x7c, s32) += FIELD(data_ov002_021f0f9c, 0xd8, s32);
    }
    return TRUE;
}

}
}  // namespace m_021e5cf4

// ---- merged from ov002_021e6290.cpp
namespace m_021e6290 {
extern "C" {
u32 NNS_G3dAnmObjCalcSizeRequired(void *a, void *b);
void NNS_G3dAnmObjInit(void *a, void *b, void *c, int d);
void NNS_G3dRenderObjAddAnmObj(void *a, void *b);

static inline void ov002_021e5fe4_Load(void **slot, void *set, char *name, void *mdl, void *tex, void *robj) {
    void *a = NNS_G3dGetAnmByName(set, (NNSG3dResName *)name);
    if (a != NULL) {
        *slot = Heap_AllocHi(NNS_G3dAnmObjCalcSizeRequired(a, mdl), 4);
        NNS_G3dAnmObjInit(*slot, a, mdl, (int)tex);
        NNS_G3dRenderObjAddAnmObj(robj, *slot);
    }
}

void func_ov002_021e5fe4(void *self) {
    char name[0x10];
    void *obj = FIELD(self, 0x48, void *);
    void *mdl = FIELD(obj, 0x60, void *);
    void *tex = FIELD(obj, 0x64, void *);
    MI_CpuFill8(name, 0, sizeof(name));
    if (FIELD(self, 0x54, void *) != NULL) {
        STD_CopyLString(name, (char *)FIELD(self, 0x54, void *), sizeof(name));
    } else {
        STD_CopyLString(name, (char *)FIELD(self, 0x50, void *), sizeof(name));
    }
    ov002_021e5fe4_Load(&FIELD(self, 0x64, void *), FIELD(self, 0x60, void **)[0], name, mdl, tex, (u8 *)obj + 0x68);
    ov002_021e5fe4_Load(&FIELD(self, 0x68, void *), FIELD(self, 0x60, void **)[1], name, mdl, tex, (u8 *)obj + 0x68);
    ov002_021e5fe4_Load(&FIELD(self, 0x6c, void *), FIELD(self, 0x60, void **)[2], name, mdl, tex, (u8 *)obj + 0x68);
    ov002_021e5fe4_Load(&FIELD(self, 0x70, void *), FIELD(self, 0x60, void **)[3], name, mdl, tex, (u8 *)obj + 0x68);
    ov002_021e5fe4_Load(&FIELD(self, 0x74, void *), FIELD(self, 0x60, void **)[4], name, mdl, tex, (u8 *)obj + 0x68);
    func_ov002_021e63f0(self);
    func_ov002_021e6290(self);
}

void func_ov002_021e61b4(void *self) {
    char name[0x10];
    void *anm;
    FIELD(self, 0x4, s32) = 3;
    MI_CpuFill8(name, 0, sizeof(name));
    if (FIELD(self, 0x54, void *) != NULL) {
        STD_CopyLString(name, (char *)FIELD(self, 0x54, void *), sizeof(name));
    } else {
        STD_CopyLString(name, (char *)FIELD(self, 0x50, void *), sizeof(name));
    }
    anm = NNS_G3dGetAnmByName(*FIELD(self, 0x60, void **), (NNSG3dResName *)name);
    FIELD(self, 0x64, void *) = Heap_AllocHi(0x100, 4);
    FIELD(FIELD(self, 0x64, void *), 0x8, void *) = anm;
    FIELD(FIELD(self, 0x64, void *), 0x0, s32) = 0;
    FIELD(FIELD(self, 0x64, void *), 0x4, s32) = 0x1000;
    FIELD(FIELD(self, 0x64, void *), 0xc, void *) = (void *)NNS_G3dFuncAnmJntNsBcaDefault;
    FIELD(FIELD(self, 0x64, void *), 0x10, s32) = 0;
    FIELD(FIELD(self, 0x64, void *), 0x14, s32) = 0;
    FIELD(FIELD(self, 0x64, void *), 0x18, u8) = 0x7f;
    FIELD(FIELD(self, 0x64, void *), 0x19, u8) = 0;
    func_ov002_021e63f0(self);
    func_ov002_021e6290(self);
}

void func_ov002_021e6290(void *self) {
    void *m;
    s32 cur;
    s32 lim;
    s32 t;
    if (FIELD(self, 0x64, void *) != NULL) {
        m = FIELD(self, 0x64, void *);
    } else if (FIELD(self, 0x68, void *) != NULL) {
        m = FIELD(self, 0x68, void *);
    } else if (FIELD(self, 0x6c, void *) != NULL) {
        m = FIELD(self, 0x6c, void *);
    }
    t = FIELD(self, 0x1c, s32);
    lim = (FIELD(FIELD(m, 8, void *), 4, u16) << 12) - 0x1000;
    FIELD(self, 0x80, s32) = lim;
    cur = FIELD(data_ov002_021f0f9c, 0xd0, s32);
    if (t < 0) {
        FIELD(self, 0x8c, s32) = -1;
    } else if (FIELD(self, 0x78, s32) == 0) {
        FIELD(self, 0x8c, s32) = t - FIELD(self, 0x18, s32);
    } else if (FIELD(self, 0x78, s32) == 1) {
        FIELD(self, 0x8c, s32) = ((t - FIELD(self, 0x18, s32)) / lim + 1) * lim;
    }
    {
        FIELD(self, 0x7c, s32) = cur > FIELD(self, 0x18, s32) ? cur - FIELD(self, 0x18, s32) : 0;
    }
    FIELD(self, 0xe8, Bits8).b0 = 1;
}

void func_ov002_021e6360(void *self) {
    u8 *o = FIELD(self, 0x48, u8 *);
    if (FIELD(self, 4, s32) == 2) {
        if (FIELD(self, 0x64, void *) != NULL) {
            NNS_G3dRenderObjRemoveAnmObj((NNSG3dRenderObj *)(o + 0x68), (NNSG3dAnmObj *)FIELD(self, 0x64, void *));
        }
        if (FIELD(self, 0x68, void *) != NULL) {
            NNS_G3dRenderObjRemoveAnmObj((NNSG3dRenderObj *)(o + 0x68), (NNSG3dAnmObj *)FIELD(self, 0x68, void *));
        }
        if (FIELD(self, 0x6c, void *) != NULL) {
            NNS_G3dRenderObjRemoveAnmObj((NNSG3dRenderObj *)(o + 0x68), (NNSG3dAnmObj *)FIELD(self, 0x6c, void *));
        }
        if (FIELD(self, 0x70, void *) != NULL) {
            NNS_G3dRenderObjRemoveAnmObj((NNSG3dRenderObj *)(o + 0x68), (NNSG3dAnmObj *)FIELD(self, 0x70, void *));
        }
        if (FIELD(self, 0x74, void *) != NULL) {
            NNS_G3dRenderObjRemoveAnmObj((NNSG3dRenderObj *)(o + 0x68), (NNSG3dAnmObj *)FIELD(self, 0x74, void *));
        }
    } else {
        FIELD(self, 0xe8, Bits8).b2 = 1;
    }
}

}
}  // namespace m_021e6290

// ---- merged from ov002_021e63f0.cpp
namespace m_021e63f0 {
/* The frame read sits in every arm of the mode switch; the arms are tail-merged
   into one block that loads 0x7c before the join loads the rate at 0x88. */
static inline s32 Ov002Anm_Frame(void *self) {
    switch (FIELD(self, 0x84, s32)) {
    case 1:
        return FIELD(self, 0x7c, s32);
    case 0:
        return FIELD(self, 0x7c, s32);
    default:
        return FIELD(self, 0x7c, s32);
    }
}

extern "C" {

void func_ov002_021e6508(void *self, void *out);

extern void *NNS_G3dRS;

extern u32 NNS_G3dGetJointScale_FuncArray;

void MIi_CpuClearFast(int v, void *dst, u32 size);

typedef void (*Func0208b000)(void *a, void *b, int c);

void func_ov002_021e63f0(void *self) {
    u8 buf[0x188];
    u32 fl;
    if (FIELD(self, 0x64, void *) != NULL) {
        func_ov002_021e6508(self, FIELD(self, 0x64, void *));
    }
    if (FIELD(self, 0x68, void *) != NULL) {
        func_ov002_021e6508(self, FIELD(self, 0x68, void *));
    }
    if (FIELD(self, 0x6c, void *) != NULL) {
        func_ov002_021e6508(self, FIELD(self, 0x6c, void *));
    }
    if (FIELD(self, 0x70, void *) != NULL) {
        func_ov002_021e6508(self, FIELD(self, 0x70, void *));
    }
    if (FIELD(self, 0x74, void *) != NULL) {
        func_ov002_021e6508(self, FIELD(self, 0x74, void *));
    }
    if (FIELD(self, 0x64, void *) == NULL) {
        return;
    }
    NNS_G3dRS = buf;
    MIi_CpuClearFast(0, buf, 0x188);
    FIELD(buf, 0xe8, u32) = NNS_G3dGetJointScale_FuncArray;
    ((Func0208b000)NNS_G3dFuncAnmJntNsBcaDefault)((u8 *)self + 0x90, FIELD(self, 0x64, void *), 0);
    fl = FIELD(self, 0x90, u32);
    if (fl & 2) {
        MTX_Identity33_((MtxFx33 *)((u8 *)self + 0xb8));
    }
    if (fl & 4) {
        FIELD(self, 0xdc, s32) = 0;
        FIELD(self, 0xe0, s32) = 0;
        FIELD(self, 0xe4, s32) = 0;
    }
    if (fl & 1) {
        FIELD(self, 0x94, s32) = 0x1000;
        FIELD(self, 0x98, s32) = 0x1000;
        FIELD(self, 0x9c, s32) = 0x1000;
    }
    NNS_G3dRS = NULL;
}

void func_ov002_021e6508(void *self, void *out) {
    s32 n = FIELD(FIELD(out, 0x8, u8 *), 0x4, u16) << 12;
    s32 f;
    f = Ov002Anm_Frame(self);
    f = FX_MUL(f, FIELD(self, 0x88, s32));
    if (FIELD(self, 0x78, s32) == 0) {
        if (f >= n - 0x1000) {
            f = n - 0x1000;
        }
        FIELD(out, 0x0, s32) = f;
    } else if (FIELD(self, 0x78, s32) == 1) {
        if (FIELD(self, 0x7c, s32) >= FIELD(self, 0x8c, s32) && FIELD(self, 0x8c, s32) >= 0) {
            FIELD(out, 0x0, s32) = n - 0x1000;
            return;
        }
        FIELD(out, 0x0, s32) = f % n;
    }
}

}
}  // namespace m_021e63f0

// ---- merged from ov002_021e659c.cpp
namespace m_021e659c {
extern "C" {

BOOL func_ov002_021e659c(void *self) {
    FIELD(self, 0x6c, s32) = FIELD(self, 0x18, s32);
    return TRUE;
}

}
}  // namespace m_021e659c

// ---- merged from ov002_021e65ac.cpp
namespace m_021e65ac {
extern "C" {

void func_ov002_021e6784(void *self);

void Math_DirToAngles(void *out, VecFx32 *dir);

static inline BOOL ov002_inWindow(s32 t) {
    u8 *g = (u8 *)data_ov002_021f0f9c;
    BOOL r = FALSE;
    if (t > FIELD(g, 0xd4, s32) && t <= FIELD(g, 0xd0, s32)) {
        r = TRUE;
    }
    return r;
}

BOOL func_ov002_021e65ac(void *self) {
    u8 *g = (u8 *)data_ov002_021f0f9c;
    s32 now = FIELD(g, 0xd0, s32);
    s32 i;
    if (now > FIELD(self, 0x1c, s32)) {
        return FALSE;
    }
    if (now < FIELD(self, 0x18, s32)) {
        return TRUE;
    }
    if (FIELD(self, 0x18, s32) > FIELD(g, 0xd4, s32) && FIELD(self, 0x18, s32) <= now) {
        func_ov002_021e61b4(FIELD(self, 0x60, void *));
    }
    if (FIELD(self, 0x64, s32) == 1) {
        while (ov002_inWindow(FIELD(self, 0x6c, s32))) {
            func_ov002_021e6784(self);
            FIELD(self, 0x6c, s32) += FIELD(self, 0x68, s32);
        }
    } else if (ov002_inWindow(FIELD(self, 0x18, s32))) {
        func_ov002_021e6784(self);
    }
    for (i = 0; i < 4; i++) {
        EffectObj *o = func_020657b0(data_0214a420, ((u32 *)((u8 *)self + 0x50))[i]);
        if (o == NULL) {
            ((u32 *)((u8 *)self + 0x50))[i] = 0;
        } else {
            VecFx32 dir;
            VecFx32 scale;
            VecFx32 pos;
            s32 rot[2];
            u8 *m = FIELD(self, 0x60, u8 *);
            pos.x = FIELD(m, 0xdc, s32);
            pos.y = FIELD(m, 0xe0, s32);
            pos.z = FIELD(m, 0xe4, s32);
            scale.x = FIELD(m, 0x94, s32);
            scale.y = FIELD(m, 0x98, s32);
            scale.z = FIELD(m, 0x9c, s32);
            dir.x = 0;
            dir.y = 0;
            dir.z = 0x1000;
            MTX_MultVec33(&dir, (MtxFx33 *)(m + 0xb8), &dir);
            Math_DirToAngles(rot, &dir);
            o->SetPos(&pos);
            o->SetScale(&scale);
            o->SetRot((const EffectRot *)rot); // rot is s32[2]: Rot16 would shrink the frame
        }
    }
    return TRUE;
}


void func_ov002_021e6784(void *self) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (((u32 *)((u8 *)self + 0x50))[i] == 0) {
            VecFx32 zero;
            VecFx32 dir;
            VecFx32 scale;
            VecFx32 pos;
            s32 rot[2];
            EffectObj *o;
            u8 *m;
            s32 k;
            zero.x = 0;
            zero.y = 0;
            zero.z = 0;
            o = func_02065f88(FIELD(self, 0x4c, s32), &zero);
            m = FIELD(self, 0x60, u8 *);
            pos.x = FIELD(m, 0xdc, s32);
            pos.y = FIELD(m, 0xe0, s32);
            pos.z = FIELD(m, 0xe4, s32);
            scale.x = FIELD(m, 0x94, s32);
            scale.y = FIELD(m, 0x98, s32);
            scale.z = FIELD(m, 0x9c, s32);
            dir.x = 0;
            dir.y = 0;
            dir.z = 0x1000;
            MTX_MultVec33(&dir, (MtxFx33 *)(m + 0xb8), &dir);
            Math_DirToAngles(rot, &dir);
            o->SetPos(&pos);
            o->SetScale(&scale);
            o->SetRot((const EffectRot *)rot); // rot is s32[2]: Rot16 would shrink the frame
            o->SetParam(FIELD(self, 0x8, s32));
            o->unk_50 = 0xfb1e0000;
            o->unk_54 = 0;
            k = FIELD(self, 0x64, s32);
            if (k == -1) {
                o->loopCount = -1;
            } else if (k == -2) {
                o->loopCount = -2;
            }
            ((u32 *)((u8 *)self + 0x50))[i] = o->id;
            return;
        }
    }
}

}
}  // namespace m_021e65ac

// ---- merged from ov002_021e68d4.cpp
namespace m_021e68d4 {
extern "C" {

BOOL func_ov002_021e68d4(void *self) {
    BOOL r = FALSE;
    switch (FIELD(self, 0x10, s32)) {
    case 0:
        if (FIELD(self, 0x4c, s8) != 0 && FIELD(self, 0x6c, s8) != 0) {
            func_020359fc((u8 *)self + 0x4c, (u8 *)self + 0x6c, 0, 0);
            FIELD(self, 0x10, s32)++;
            FIELD(self, 0x14, s32) = 1;
        } else {
            FIELD(self, 0x10, s32) = -1;
            r = TRUE;
            break;
        }
    case 1:
        if (func_02035bd4((u8 *)self + 0x4c, (u8 *)self + 0x6c, 0) == 0) {
            break;
        }
        FIELD(self, 0x10, s32)++;
    case 2: {
        void *t = func_02035fe8((u8 *)self + 0x4c, (u8 *)self + 0x6c);
        if (t != NULL) {
            func_ov002_021ec1e0((u8 *)self + 0x94, t);
        }
        FIELD(self, 0x10, s32) = -1;
        break;
    }
    case -1:
    default:
        r = TRUE;
        break;
    }
    return r;
}

BOOL func_ov002_021e69a8(void) {
    return TRUE;
}

}
}  // namespace m_021e68d4

// ---- merged from ov002_021e69b0.cpp
namespace m_021e69b0 {
extern "C" {

BOOL func_ov002_021e69b0(void *self) {
    s16 *p;
    s32 v;
    while ((p = FIELD(self, 0xa8, s16 *)) != NULL && FIELD((u8 *)data_ov002_021f0f9c, 0xd4, s32) < (v = *p << 12) && v <= FIELD((u8 *)data_ov002_021f0f9c, 0xd0, s32)) {
        func_0204aaec(data_02097e48.queue, (SndCmd *)p);
        func_ov002_021ec2ac((u8 *)self + 0x94);
    }
    return TRUE;
}

}
}  // namespace m_021e69b0

// ---- merged from ov002_021e6a14.cpp
namespace m_021e6a14 {
extern "C" {

void func_ov002_021e6a14(void *self) {
    FIELD(self, 4, s32) = 5;
    FIELD(self, 0x20, s32) = -0x29;
    MI_CpuFill8((u8 *)self + 0x4c, 0, 0x20);
    MI_CpuFill8((u8 *)self + 0x6c, 0, 0x20);
    func_ov002_021ebfd0((u8 *)self + 0x8c);
    FIELD(self, 0xb4, s32) = 0;
    FIELD(self, 0xb8, s32) = 0;
    FIELD(self, 0xbc, s16) = 0;
    FIELD(self, 0xc0, s32) = 0;
    MI_CpuFill8((u8 *)self + 0xc4, 0, 0x80);
    FIELD(self, 0x144, void *) = (u8 *)self + 0xc4;
    FIELD(self, 0x148, s32) = 0xff;
    FIELD(self, 0x150, s32) = 6;
    FIELD(self, 0x14c, s32) = 0;
    FIELD(self, 0x154, s32) = 2;
    FIELD(self, 0x158, s32) = 0;
    FIELD(self, 0x15c, s32) = 0;
}

BOOL func_ov002_021e6aac(void *self) {
    BOOL r = FALSE;
    switch (FIELD(self, 0x10, s32)) {
    case 0:
        if (FIELD(self, 0x4c, s8) != 0 && FIELD(self, 0x6c, s8) != 0) {
            func_020359fc((u8 *)self + 0x4c, (u8 *)self + 0x6c, 0, 0);
            FIELD(self, 0x14, s32) = 1;
            FIELD(self, 0x10, s32)++;
        } else {
            FIELD(self, 0x10, s32) = 2;
            r = TRUE;
            break;
        }
    case 1:
        if (func_02035bd4((u8 *)self + 0x4c, (u8 *)self + 0x6c, 0) == 0) {
            break;
        }
        FIELD(self, 0x10, s32)++;
    case 2:
        r = TRUE;
        break;
    }
    return r;
}

BOOL func_ov002_021e6b54(void *self) {
    s8 **r;
    if (FIELD(self, 0x14, s32) != 0) {
        void *t = func_02035fe8((u8 *)self + 0x4c, (u8 *)self + 0x6c);
        if (t == NULL) {
            FIELD(self, 8, s32) = 0;
        } else {
            func_ov002_021ec010((u8 *)self + 0x8c, t);
            FIELD(self, 8, s32) = 2;
        }
    }
    switch (FIELD(self, 8, s32)) {
    case 1:
        FIELD(self, 0x150, s32) = 5;
        FIELD(self, 0x154, s32) = 1;
        break;
    case 2:
        FIELD(self, 0x150, s32) = 6;
        FIELD(self, 0x154, s32) = 2;
        break;
    }
    FIELD(data_02097ce0, 4, s32) = FIELD(self, 0x150, s32);
    r = (s8 **)GfxMgr_GetFont(data_02097ce0);
    FIELD(self, 0x158, s8 **) = r;
    FIELD(self, 0x15c, s8 *) = r[1];
    FIELD(data_ov002_021f0f9c, 0x128, s32) = FIELD(self, 8, s32);
    return TRUE;
}

}
}  // namespace m_021e6a14

// ---- merged from ov002_021e6c0c.cpp
namespace m_021e6c0c {
extern "C" {

void func_ov002_021ec0cc(void *p);

void func_ov002_021e6e40(void *self);

static inline bool isVisible021e6c0c(void *self) {
    BOOL in = FALSE;
    s32 idx = FIELD(self, 0xb8, s32);
    if (idx >= 0 && idx < FIELD(data_ov002_021f0f9c, 0xd0, s32)) {
        in = TRUE;
    }
    return in;
}

BOOL func_ov002_021e6c0c(void *self) {
    if (FIELD(self, 0x96, s16) != 0) {
        if (FIELD(data_ov002_021f0f9c, 0xd4, s32) < FIELD(self, 0x9c, s16) << 12 && FIELD(self, 0x9c, s16) << 12 <= FIELD(data_ov002_021f0f9c, 0xd0, s32)) {
            BOOL has;
            char *s;
            FIELD(self, 0xb4, s32) = 0;
            FIELD(self, 0xb8, s32) = FIELD(self, 0x9e, s16) << 12;
            FIELD(self, 0xbc, s16) = 0;
            FIELD(self, 0xc0, s32) = FIELD(self, 0xb0, s32);
            FIELD(self, 0x14c, s32) = FIELD(self, 0xac, s32);
            MI_CpuFill8((u8 *)self + 0xc4, 0, 0x80);
            FIELD(self, 0x144, void *) = (u8 *)self + 0xc4;
            has = FALSE;
            s = FIELD(self, 0xac, char *);
            if (s != NULL && s[0] != 0) {
                has = TRUE;
            }
            if (!has) {
                FIELD(self, 0x148, s32) = 0xff;
            } else if (FIELD(self, 0xa8, s8) == 1) {
                FIELD(self, 0x148, s32) = 0;
            } else {
                FIELD(self, 0x148, s32) = 1;
            }
            func_ov002_021ec0cc((u8 *)self + 0x8c);
        }
    }
    if (!isVisible021e6c0c(self)) {
        func_ov002_021e6e40(self);
    }
    if (isVisible021e6c0c(self)) {
        FIELD(self, 0x148, s32) = 0xff;
    }
    FIELD(data_ov002_021f0f9c, 0x12c, s32) = FIELD(self, 0x148, s32);
    return TRUE;
}

}
}  // namespace m_021e6c0c

// ---- merged from ov002_021e6d4c.cpp
namespace m_021e6d4c {
extern "C" {

#define FIELD(p, off, T) (*(T *)((u8 *)(p) + (off)))
u8 LangData_GetLang(void);
void func_0203a4e4(void *mgr, void *arg);
int NNSi_G2dFontGetTextWidth(const void *pFont, int hSpace, const void *txt);

static inline BOOL Ov002_IsValidIdx(s32 idx) {
    BOOL r = FALSE;
    if (idx < 0) {
        return r;
    }
    if (idx < FIELD(data_ov002_021f0f9c, 0xd0, s32)) {
        r = TRUE;
    }
    return r;
}

static inline void Pos_Set(s16 *p, s16 x, s16 y) {
    p[0] = x;
    p[1] = y;
}

void func_ov002_021e6d4c(void *self) {
    s16 x;
    s16 y;
    s16 pal;
    if (Ov002_IsValidIdx(FIELD(self, 0xb8, s32))) {
        return;
    }
    if (!LangData_GetLang()) {
        y = 0x9c;
        pal = 3;
        x = 10;
    } else {
        y = 0x99;
        pal = 1;
        x = 10;
    }
    FIELD(data_02097ce0, 0x4, s32) = FIELD(self, 0x150, s32);
    FIELD(data_02097ce0, 0x8, s32) = 0;
    Pos_Set((s16 *)((u8 *)data_02097ce0 + 0xc), x, y);
    FIELD(data_02097ce0, 0x10, s16) = pal;
    func_0203a4e4(data_02097ce0, (u8 *)self + 0xc4);
    if (FIELD(self, 0x148, s32) == 0xff) {
        return;
    }
    {
        void *txt = FIELD(self, 0x14c, void *);
        void *font = GfxMgr_GetFont(data_02097ce0);
        s32 w = NNSi_G2dFontGetTextWidth(font, 0, txt);
        FIELD(data_02097ce0, 0x4, s32) = FIELD(self, 0x154, s32);
        FIELD(data_02097ce0, 0x8, s32) = 0;
        Pos_Set((s16 *)((u8 *)data_02097ce0 + 0xc), (0x60 - w) >> 1, 0x8d);
        func_0203a4e4(data_02097ce0, FIELD(self, 0x14c, void *));
    }
}

}
}  // namespace m_021e6d4c

// ---- merged from ov002_021e6e40.cpp
namespace m_021e6e40 {
extern "C" {

void func_ov002_021e6fbc(void *self, s32 ch);

typedef s32 (*GetChar)(void *);

static inline s32 classifyChar(s32 ch) {
    if (ch == 0) {
        return 1;
    }
    if (ch == 10) {
        return 4;
    }
    if (((int (*)(void))LangData_GetLang)() == 0) {
        if (ch == 0x8141) {
            return 2;
        }
        if (ch == 0x8142) {
            return 3;
        }
    } else {
        if (ch == 0xfeff) {
            return 5;
        }
    }
    return 0;
}

void func_ov002_021e6e40(void *self) {
    char *s = FIELD(self, 0xc0, char *);
    if (s == NULL || s[0] == 0) {
        return;
    }
    FIELD(self, 0xb4, s32) -= FIELD(data_ov002_021f0f9c, 0xd8, s32);
    while (FIELD(self, 0xb4, s32) < 0 && FIELD(self, 0xc0, char *)[0] != 0) {
        s32 ch = FIELD(self, 0x15c, GetChar)((u8 *)self + 0xc0);
        switch (classifyChar(ch)) {
        case 0:
        case 1:
            break;
        case 2:
            if (((int (*)(void))LangData_GetLang)() == 0) {
                ch = 0x8140;
            }
            FIELD(self, 0xb4, s32) += FIELD(self, 0xbc, s16) != 0 ? 0x5000 : 0;
            break;
        case 3:
            if (((int (*)(void))LangData_GetLang)() == 0) {
                ch = 0x8140;
            }
            FIELD(self, 0xb4, s32) += FIELD(self, 0xbc, s16) != 0 ? 0xa000 : 0;
            break;
        case 4:
            func_ov002_021e6fbc(self, ch);
            ch = FIELD(self, 0x15c, GetChar)((u8 *)self + 0xc0);
            break;
        case 5:
            ch = FIELD(self, 0x15c, GetChar)((u8 *)self + 0xc0);
            break;
        }
        func_ov002_021e6fbc(self, ch);
        FIELD(self, 0xb4, s32) += FIELD(self, 0xbc, s16) << 12;
    }
}

typedef u8 Buf80[0x80];

void func_ov002_021e6fbc(void *self, s32 ch) {
    if (FIELD(self, 0x144, u8 *) > FIELD(self, 0xc4, Buf80) + 0x7e) {
        return;
    }
    if (((int (*)(void))LangData_GetLang)() == 0) {
        if (ch == (ch & 0xff)) {
            *FIELD(self, 0x144, u8 *)++ = ch;
            *FIELD(self, 0x144, u8 *) = 0;
        } else {
            *FIELD(self, 0x144, u8 *)++ = ch >> 8;
            *FIELD(self, 0x144, u8 *)++ = ch;
            *FIELD(self, 0x144, u8 *) = 0;
        }
    } else if (ch == (ch & 0x7f)) {
        *FIELD(self, 0x144, u8 *)++ = ch;
        *FIELD(self, 0x144, u8 *) = 0;
    } else if (ch == (ch & 0x7ff)) {
        *FIELD(self, 0x144, u8 *)++ = ((ch >> 6) & 0x1f) | 0xc0;
        *FIELD(self, 0x144, u8 *)++ = (ch & 0x3f) | 0x80;
        *FIELD(self, 0x144, u8 *) = 0;
    } else {
        *FIELD(self, 0x144, u8 *)++ = ((ch >> 12) & 0xf) | 0xe0;
        *FIELD(self, 0x144, u8 *)++ = ((ch >> 6) & 0x3f) | 0x80;
        *FIELD(self, 0x144, u8 *)++ = (ch & 0x3f) | 0x80;
        *FIELD(self, 0x144, u8 *) = 0;
    }
}

}
}  // namespace m_021e6e40

// ---- merged from ov002_021e7118.cpp
namespace m_021e7118 {
extern "C" {

BOOL func_ov002_021e7118(void) {
    return TRUE;
}

BOOL func_ov002_021e7120(void *self) {
    switch (FIELD(self, 0x4c, s32)) {
    case 0:
        FIELD(self, 0x54, s32) = 0x1f;
        FIELD(self, 0x58, s32) = 0;
        break;
    case 1:
        FIELD(self, 0x54, s32) = 0;
        FIELD(self, 0x58, s32) = 0x1f;
        break;
    }
    return TRUE;
}

BOOL func_ov002_021e715c(void *self) {
    u8 *ctx = (u8 *)data_ov002_021f0f9c;
    s32 v = FIELD(ctx, 0xd0, s32);
    if (v <= FIELD(self, 0x18, s32)) {
        return TRUE;
    }
    if (v > FIELD(self, 0x1c, s32)) {
        return FALSE;
    }
    FIELD(ctx, 0x138, u16) = FIELD(self, 0x50, u16);
    return TRUE;
}

}
}  // namespace m_021e7118

// ---- merged from ov002_021e719c.cpp
namespace m_021e719c {
extern "C" {

s32 Interp_SinLerp(s32 t, s32 a, s32 b);

void NNS_G3dGlbFlushP(void);

void NNS_G3dGeBufferOP_N(int cmd, void *data, int n);

void func_02043db4(int a, s32 b, s32 c, u16 d);

extern VecFx32 data_ov002_021ef104;

extern VecFx32 data_ov002_021ef0bc;

void func_ov002_021e719c(void *self) {
    s32 now = FIELD(data_ov002_021f0f9c, 0xd0, s32);
    s32 a;
    if (now < FIELD(self, 0x18, s32)) {
        return;
    }
    if (now - FIELD(self, 0x18, s32) >= FIELD(self, 0x5c, s32)) {
        a = FIELD(self, 0x58, s32);
    } else {
        a = Interp_SinLerp(FX_Div(now - FIELD(self, 0x18, s32), FIELD(self, 0x5c, s32)), FIELD(self, 0x54, s32) << 12, FIELD(self, 0x58, s32) << 12) >> 12;
    }
    {
        VecFx32 zero = {0, 0, 0};
        VecFx32 up = data_ov002_021ef104;
        VecFx32 at = data_ov002_021ef0bc;
        VecFx32 w;
        s32 t;
        u32 c;
        s32 t2;
        s32 t3;
        u8 *g2 = (u8 *)data_ov002_021f0f9c;
        NNS_G3dGlb.camPos = zero;
        NNS_G3dGlb.camUp = up;
        NNS_G3dGlb.camTarget = at;
        MTX_LookAt(&zero, &up, &at, (MtxFx43 *)data_02092844);
        NNS_G3dGlb.flag &= ~0xe8;
        MIi_CpuCopyFast(g2 + 0xe4, data_02092800, 0x40);
        NNS_G3dGlb.flag &= ~0x50;
        NNS_G3dGlbFlushP();
        t = 2;
        NNS_G3dGeBufferOP_N(0x10, &t, 1);
        NNS_G3dGeBufferOP_N(0x11, NULL, 0);
        NNS_G3dGeBufferOP_N(0x15, NULL, 0);
        c = 0x3f0000c0 | (a << 16);
        NNS_G3dGeBufferOP_N(0x29, &c, 1);
        w.z = FIELD(self, 0x20, s32);
        w.x = 0x80000;
        w.y = 0x60000;
        NNS_G3dGeBufferOP_N(0x1c, &w, 3);
        func_02043db4(0, 0x100000, 0xc0000, FIELD(self, 0x50, u16));
        t2 = 2;
        NNS_G3dGeBufferOP_N(0x10, &t2, 1);
        t3 = 1;
        NNS_G3dGeBufferOP_N(0x12, &t3, 1);
    }
}

}
}  // namespace m_021e719c

// ---- merged from ov002_021e7390.cpp
namespace m_021e7390 {
extern "C" {

void VEC_Normalize(VecFx32 *src, VecFx32 *dst);
void VEC_Add(VecFx32 *a, VecFx32 *b, VecFx32 *ab);
void MTX_RotAxis33(void *m, VecFx32 *axis, s32 s, s32 c);
void MTX_PerspectiveW(s32 s, s32 c, s32 aspect, s32 n, s32 f, s32 scale, void *mtx);

typedef struct Mtx33_021e7390 {
    s32 m[3][3];
} Mtx33_021e7390;

static inline void ov002_Cross(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb) {
    s32 x = (s32)(((s64)a->y * b->z - (s64)a->z * b->y + 0x800) >> 12);
    s32 y = (s32)(((s64)a->z * b->x - (s64)a->x * b->z + 0x800) >> 12);
    s32 z = (s32)(((s64)a->x * b->y - (s64)a->y * b->x + 0x800) >> 12);
    axb->x = x;
    axb->y = y;
    axb->z = z;
}

void func_ov002_021e7390(void *self) {
    void *obj = FIELD(self, 0x48, void *);
    if (obj != NULL && FIELD(obj, 0x4, s32) == 7) {
        VecFx32 pos;
        VecFx32 at;
        VecFx32 dir;
        VecFx32 axis;
        Mtx33_021e7390 m;
        VecFx32 up;
        u16 ang;
        pos = FIELD(obj, 0x50, VecFx32);
        at = FIELD(obj, 0x5c, VecFx32);
        up = FIELD(obj, 0x68, VecFx32);
        ang = FIELD(obj, 0xb8, u16) + 0x3e9;
        dir.x = at.x - pos.x;
        dir.y = at.y - pos.y;
        dir.z = at.z - pos.z;
        ov002_Cross(&dir, &up, &axis);
        VEC_Normalize(&axis, &axis);
        MTX_RotAxis33(&m, &axis, FX_SINCOS((ang >> 4) * 2), FX_SINCOS((ang >> 4) * 2 + 1));
        MTX_MultVec33(&dir, (MtxFx33 *)&m, &dir);
        VEC_Add(&dir, &pos, &at);
        FIELD(self, 0x5c, VecFx32) = at;
        FIELD(self, 0x50, VecFx32) = pos;
        FIELD(self, 0x68, VecFx32) = up;
    }
    NNS_G3dGlb.camPos = FIELD(self, 0x50, VecFx32);
    NNS_G3dGlb.camUp = FIELD(self, 0x68, VecFx32);
    NNS_G3dGlb.camTarget = FIELD(self, 0x5c, VecFx32);
    MTX_LookAt((VecFx32 *)((u8 *)self + 0x50), (VecFx32 *)((u8 *)self + 0x68), (VecFx32 *)((u8 *)self + 0x5c), (MtxFx43 *)data_02092844);
    NNS_G3dGlb.flag &= ~0xe8;
    MTX_PerspectiveW(FIELD(self, 0xba, s16), FIELD(self, 0xbc, s16), FIELD(self, 0xbe, s16), FIELD(self, 0xc0, s32),
                     FIELD(self, 0xc4, s32), 0x1000, (u8 *)self + 0x74);
    MIi_CpuCopyFast((u8 *)self + 0x74, data_02092800, 0x40);
    NNS_G3dGlb.flag &= ~0x50;
}

}
}  // namespace m_021e7390

// ---- merged from ov002_021e75f0.cpp
namespace m_021e75f0 {
extern "C" {

extern VecFx32 data_ov002_021ef0f8;

extern VecFx32 data_ov002_021ef0d4;

void VEC_Add(void *a, void *b, void *c);

BOOL func_ov002_021e75f0(void *self) {
    void *n;
    void *c;
    u8 *m;
    n = NULL;
    c = FIELD(self, 0xc8, void *);
    if (c == NULL) {
        n = func_ov002_021e4ee4(self, 3, -1);
    } else if (FIELD(c, 0xe8, Bits8).b1) {
        n = func_ov002_021e4ee4(self, 3, FIELD(c, 0x18, s32));
    }
    if (n != NULL) {
        if (FIELD(self, 0xc8, void *) != NULL) {
            func_ov002_021e6360(FIELD(self, 0xc8, void *));
        }
        func_ov002_021e61b4(n);
        FIELD(self, 0xc8, void *) = n;
    }
    m = FIELD(self, 0xc8, u8 *);
    if (m != NULL) {
        VecFx32 pos;
        VecFx32 a = data_ov002_021ef0f8;
        VecFx32 b = data_ov002_021ef0d4;
        pos.x = FIELD(m, 0xdc, s32);
        pos.y = FIELD(m, 0xe0, s32);
        pos.z = FIELD(m, 0xe4, s32);
        MTX_MultVec33(&a, (MtxFx33 *)(m + 0xb8), &a);
        VEC_Add(&pos, &a, &a);
        MTX_MultVec33(&b, (MtxFx33 *)(m + 0xb8), &b);
        FIELD(self, 0x50, VecFx32) = pos;
        FIELD(self, 0x5c, VecFx32) = a;
        FIELD(self, 0x68, VecFx32) = b;
    }
    return TRUE;
}

void func_ov002_021e772c(void *self, s32 deg) {
    s32 idx;
    FIELD(self, 0xb8, u16) = (u16)(((s64)deg * 0xb60b60b60bLL + 0x80000000000LL) >> 44);
    FIELD(self, 0xb4, s32) = deg;
    idx = (u16)(FIELD(self, 0xb8, u16) >> 1);
    FIELD(self, 0xba, s16) = FX_SINCOS_TABLE[(idx >> 4) * 2];
    FIELD(self, 0xbc, s16) = FX_SINCOS_TABLE[(idx >> 4) * 2 + 1];
}

}
}  // namespace m_021e75f0

// ---- merged from ov002_021e779c.cpp
namespace m_021e779c {
extern "C" {

void func_ov002_021e779c(void *self) {
    void *o = FIELD(self, 0x48, void *);
    NNSG3dGlb *g;
    if (o != NULL && FIELD(o, 4, s32) == 8) {
        s32 y = FIELD(o, 0x54, s32) + 0x120000;
        s32 x = FIELD(o, 0x50, s32);
        VecFx32 *v = &FIELD(self, 0x50, VecFx32);
        VecFx32 *w = &FIELD(self, 0x5c, VecFx32);
        v->x = x;
        v->y = y;
        v->z = 0;
        w->x = x;
        w->y = y;
        w->z = -0x1000;
    }
    g = &NNS_G3dGlb;
    g->camPos = FIELD(self, 0x50, VecFx32);
    g->camUp = FIELD(self, 0x68, VecFx32);
    g->camTarget = FIELD(self, 0x5c, VecFx32);
    MTX_LookAt((VecFx32 *)((u8 *)self + 0x50), (VecFx32 *)((u8 *)self + 0x68), (VecFx32 *)((u8 *)self + 0x5c), (MtxFx43 *)data_02092844);
    g->flag &= ~0xe8;
    MIi_CpuCopyFast((u8 *)self + 0x74, data_02092800, 0x40);
    g->flag &= ~0x50;
}

BOOL func_ov002_021e7880(void *self) {
    VecFx32 v = data_ov002_021ef110;
    s32 x;
    FIELD(self, 0x68, VecFx32) = v;
    if (FIELD(self, 8, s32) == 1) {
        x = 0x90000;
    } else if (FIELD(self, 8, s32) == 2) {
        x = -0x90000;
    }
    FIELD(self, 0x50, s32) = 0;
    FIELD(self, 0x54, s32) = x;
    FIELD(self, 0x58, s32) = 0;
    FIELD(self, 0x5c, s32) = 0;
    FIELD(self, 0x60, s32) = x;
    FIELD(self, 0x64, s32) = -0x1000;
    return TRUE;
}

BOOL func_ov002_021e7900(void *self) {
    void *found = NULL;
    void *cur = FIELD(self, 0xb4, void *);
    if (cur == NULL) {
        found = func_ov002_021e4ee4(self, 3, -1);
    } else if (FIELD(cur, 0xe8, Bits8).b1) {
        found = func_ov002_021e4ee4(self, 3, FIELD(cur, 0x18, s32));
    }
    if (found != NULL) {
        if (FIELD(self, 0xb4, void *) != NULL) {
            func_ov002_021e6360(FIELD(self, 0xb4, void *));
        }
        func_ov002_021e61b4(found);
        FIELD(self, 0xb4, void *) = found;
    }
    cur = FIELD(self, 0xb4, void *);
    if (cur != NULL) {
        s32 x = FIELD(cur, 0xdc, s32);
        s32 y = FIELD(cur, 0xe0, s32);
        VecFx32 *v = &FIELD(self, 0x50, VecFx32);
        VecFx32 *w = &FIELD(self, 0x5c, VecFx32);
        v->x = x * 100;
        v->y = y * 100;
        v->z = 0;
        w->x = x * 100;
        w->y = y * 100;
        w->z = -0x1000;
    }
    return TRUE;
}

BOOL func_ov002_021e79b0(void *self) {
    FIELD(self, 0x4c, Bits16).b6 = 0;
    return TRUE;
}

BOOL func_ov002_021e79c4(void *self) {
    u8 *ctx = (u8 *)data_ov002_021f0f9c;
    BOOL r = TRUE;
    if (FIELD(self, 0x18, s32) > FIELD(ctx, 0xd4, s32) && FIELD(self, 0x18, s32) <= FIELD(ctx, 0xd0, s32)) {
        u8 *g;
        func_0206e3a0((u8 *)self + 0x4c, FIELD(self, 0x50, void *));
        g = data_02097d48->unk_8b0;
        if (!FIELD(self, 0x4c, Bits16).b2) {
            FIELD(g, 0, Bits8).b4 = 0;
            FIELD(g, 0, Bits8).b5 = 1;
            *(vu16 *)0x04000060 &= 0xcfdf;
        }
        if (!FIELD(self, 0x4c, Bits16).b3) {
            G3X_SetFog(0, (GXFogBlend)FIELD(g, 8, void *), (GXFogSlope)FIELD(g, 0xc, void *), FIELD(g, 0x10, u16));
            FIELD(g, 0, Bits8).b3 = 0;
        }
        func_02043b20(g);
        r = FALSE;
    }
    return r;
}

BOOL func_ov002_021e7a94(void *self) {
    BOOL r = TRUE;
    if (FIELD(data_ov002_021f0f9c, 0xd0, s32) >= FIELD(self, 0x1c, s32)) {
        r = FALSE;
    }
    return r;
}

Oam021e7ab8 *func_ov002_021e7ab8(void *self, u16 *flag, Oam021e7ab8 *oam, u16 *count) {
    u16 n = *count;
    if (*flag == 0) {
        u8 pal = FIELD(self, 0x70, s32);
        int i;
        for (i = 0; i < n; i++) {
            oam[i].x -= 0x80;
            oam[i].y -= 0x60;
            oam[i].pal += pal;
        }
    }
    *count = n;
    return oam;
}

void func_ov002_021e7b58(void) {
    void *p;
    {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(*(VObject **)&data_ov002_021f0f9c);
        HEAP_POP(saved);
    }
    p = Heap_Alloc(0x2cc);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0674;
        *(VFunc **)((u8 *)p + 0x6c) = data_ov002_021f0684;
        func_ov002_021eacd0((u8 *)p + 0x6c);
        Gfx3DState_Init((u8 *)p + 0x14c);
        func_ov002_021e7cb4(p);
    }
    data_ov002_021f0f9c = p;
}

void *Ov002Vt_021f0684_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021f0684;
    func_ov002_021eae3c(self);
    return self;
}

void func_ov002_021e7c1c(void) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(*(VObject **)&data_ov002_021f0f9c);
    HEAP_POP(saved);
}

void *Ov002Vt_021f0674_DtorDelete(void *self) {
    *(VFunc **)self = data_ov002_021f0674;
    func_ov002_021e7dac(self);
    *(VFunc **)((u8 *)self + 0x6c) = data_ov002_021f0684;
    func_ov002_021eae3c((u8 *)self + 0x6c);
    Heap_Free(self);
    return self;
}

}
}  // namespace m_021e779c

// ---- merged from ov002_021e7cb4.cpp
namespace m_021e7cb4 {
extern "C" {

void MTX_OrthoW(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, void *out);

void func_ov002_021e7cb4(void *self) {
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, s32) = 0;
    FIELD(self, 0xc, s32) = 1;
    FIELD(self, 0x10, u8) = 1;
    FIELD(self, 0x14, s32) = -1;
    FIELD(self, 0x18, s16) = 0;
    FIELD(self, 0x1a, u8) = 1;
    FIELD(self, 0x1c, s32) = -1;
    FIELD(self, 0x20, s32) = 0;
    MI_CpuFill8((u8 *)self + 0x24, 0, 0x20);
    FIELD(self, 0x44, s32) = 0;
    MI_CpuFill8((u8 *)self + 0x48, 0, 0x20);
    FIELD(self, 0x68, s32) = 0;
    FIELD(self, 0xd0, s32) = 0;
    FIELD(self, 0xd4, s32) = -1;
    FIELD(self, 0xd8, s32) = 0x1000;
    FIELD(self, 0xdc, s32) = 0;
    FIELD(self, 0xe0, s32) = 0;
    MTX_OrthoW(0, 0xc0000, 0, 0x100000, 0, 0x20000, 0x400000, (u8 *)self + 0xe4);
    FIELD(self, 0x124, s32) = 0;
    FIELD(self, 0x128, s32) = 0;
    FIELD(self, 0x130, s32) = 0;
    FIELD(self, 0x134, s32) = 0;
    FIELD(self, 0x13c, s32) = 0;
    FIELD(self, 0x140, s32) = 0;
    FIELD(self, 0x144, s32) = 0;
    FIELD(self, 0x148, u8) = 0;
    FIELD(self, 0x12c, s32) = 0xff;
    FIELD(self, 0x138, s16) = 0;
    MI_CpuFill8((u8 *)self + 0x14c, 0, 0x180);
}

void func_ov002_021e8c0c(void *self);


void GXx_SetMasterBrightness_(u32 reg, int v);

extern void *data_ov002_021f0104[];

void func_ov002_021e7dac(void *self) {
    func_ov002_021e8c0c(self);
    if (FIELD(self, 0x44, void *) != NULL) {
        if (FIELD(self, 0x20, void *) != NULL) {
            func_02035acc((u8 *)self + 0x24, (u8 *)self + 0x48, 0);
        } else {
            func_02036838(data_02097cdc, (char *)((u8 *)self + 0x48), 0, 0);
        }
    }
    func_02035acc(data_ov002_021f0104[1], data_ov002_021f0104[2], 2);
    SndQueue_StopSeqArcs(data_02097e48.queue);
    if (FIELD(self, 0x148, u8)) {
        u8 *g = (u8 *)data_02097d48;
        MIi_CpuCopy32((u8 *)self + 0x14c, g + 0x8b0, 0x180);
        func_02043b20(g + 0x8b0);
        FIELD(self, 0x148, u8) = 0;
    }
    FIELD(data_02097d48, 0x4, s32) = 1;
    FIELD(data_0214a420, 0x10, u8) = 0;
    FIELD(data_0214a420, 0x34, u8) = 0;
    GXx_SetMasterBrightness_(0x400006c, 0);
    GXx_SetMasterBrightness_(0x400106c, 0);
}

}
}  // namespace m_021e7cb4

// ---- merged from ov002_021e7ea8.cpp
namespace m_021e7ea8 {
extern "C" {

void GXx_SetMasterBrightness_(vu16 *reg, int v);
static inline void GX_SetMasterBrightness(int b) { GXx_SetMasterBrightness_((vu16 *)0x400006c, b); }
static inline void GXS_SetMasterBrightness(int b) { GXx_SetMasterBrightness_((vu16 *)0x400106c, b); }

int func_0203ca84(int a);
void func_02043904(void *p);
BOOL func_ov002_021e828c(void *self);
BOOL func_ov002_021e86a0(void *self);
BOOL func_ov002_021e8828(void *self);
void func_ov002_021e8c0c(void *self);

static inline void ov002_SetBright(int v) {
    GX_SetMasterBrightness(v);
    GXS_SetMasterBrightness(v);
}

static inline void G3X_EdgeMarking(BOOL e) {
    if (e) *(vu16 *)0x04000060 = (u16)((*(vu16 *)0x04000060 & ~0x3000) | 0x20);
    else *(vu16 *)0x04000060 &= ~(0x3000 | 0x20);
}
static inline void ov002_SetState(void *self, s32 st) {
    FIELD(self, 0x4, s32) = st;
    FIELD(self, 0x8, s32) = 0;
}

static inline s32 FxM7ea8(s32 a, s32 b) { return (s32)(((s64)a * b + 0x800) >> 12); }
BOOL func_ov002_021e7ea8(void *self) {
    BOOL ret = TRUE;
    u8 *gx;
    BOOL done;
    int mode;
    u8 *g;
    s32 b;
    FIELD(self, 0xc, s32) = FIELD(data_02097d48, 0xa30, Bits8).b4 ? 1 : 2;
    switch (FIELD(self, 0x4, s32)) {
    case 0: {
        b = 0;
        switch (FIELD(self, 0x130, s32)) {
        case 0:
            b = func_0203ca84(0);
            break;
        case 1:
            b = 0x10;
            break;
        case 2:
            b = -0x10;
            break;
        }
        ov002_SetBright(b);
        func_0203caf8(-1);
        FIELD(self, 0x13c, s32) = b << 12;
        FIELD(self, 0x140, s32) = 0;
        FIELD(self, 0x144, s32) = 0;
        gx = data_02097d48->unk_8b0;
        MIi_CpuCopy32(gx, (u8 *)self + 0x14c, 0x180);
        func_02043904(gx);
        FIELD(gx, 0, Bits8).b4 = 0;
        FIELD(gx, 0, Bits8).b5 = 1;
        G3X_EdgeMarking(FALSE);
        FIELD(gx, 0xac, u16) = 0x4a52;
        FIELD(gx, 0xae, u16) = 0x1084;
        FIELD(gx, 0xb0, u16) = 0x739c;
        FIELD(gx, 0xb2, u16) = 0;
        func_02043b20(gx);
        FIELD(self, 0x148, u8) = 1;
        FIELD(data_02097d48, 0x4, s32) = 2;
        FIELD(data_0214a420, 0x10, u8) = 1;
        FIELD(data_0214a420, 0x34, u8) = 1;
        ov002_SetState(self, 1);
        break;
    }
    case 1:
        if (!func_ov002_021e828c(self)) {
            break;
        }
        ov002_SetState(self, 2);
    case 2:
        if (!func_ov002_021e86a0(self)) {
            break;
        }
        ov002_SetState(self, 3);
    case 3:
        func_ov002_021e8828(self);
        if (FIELD(self, 0x10, u8) == 0) {
            ov002_SetState(self, 4);
        }
        break;
    case 4: {
        if (FIELD(self, 0x144, s32) < 0xa000) {
            {
                s32 t_0 = FIELD(self, 0x144, s32);
                b = (FIELD(self, 0x13c, s32) + FxM7ea8(FX_Div(FIELD(self, 0x140, s32) - FIELD(self, 0x13c, s32), 0xa000), t_0)) >> 12;
                ov002_SetBright(b);
                FIELD(self, 0x144, s32) += 0x1000;
            }
        }
        if (func_ov002_021e8828(self)) {
            break;
        }
        b = 0;
        switch (FIELD(self, 0x134, s32)) {
        case 0:
            b = FIELD(self, 0x138, u16) > 0x4210 ? 0x10 : -0x10;
            break;
        case 1:
            b = 0x10;
            break;
        case 2:
            b = -0x10;
            break;
        }
        FIELD(self, 0x13c, s32) = 0;
        FIELD(self, 0x140, s32) = b << 12;
        FIELD(self, 0x144, s32) = 0;
        ov002_SetState(self, 5);
    }
    case 5: {
        done = FALSE;
        if (FIELD(self, 0x144, s32) >= 0x14000) {
            mode = FIELD(self, 0x140, s32) > 0 ? 1 : 2;
            func_0203cc58(0x1000, mode, 0);
            done = TRUE;
            func_0203cc58(0x1000, mode, 1);
        } else {
            {
                s32 t_1 = FIELD(self, 0x144, s32);
                b = (FIELD(self, 0x13c, s32) + FxM7ea8(FX_Div(FIELD(self, 0x140, s32) - FIELD(self, 0x13c, s32), 0x14000), t_1)) >> 12;
                ov002_SetBright(b);
                FIELD(self, 0x144, s32) += 0x1000;
            }
        }
        if (done) {
            func_ov002_021e8c0c(self);
            EffectMgr_FreeAll(data_0214a420);
            FIELD(data_0214a420, 0x10, u8) = 0;
            FIELD(data_02097d48, 0x4, s32) = 1;
            ov002_SetState(self, 6);
        }
        break;
    }
    case 6: {
        ov002_SetBright(0);
        g = (u8 *)data_02097d48;
        MIi_CpuCopy32((u8 *)self + 0x14c, g + 0x8b0, 0x180);
        func_02043b20(g + 0x8b0);
        FIELD(self, 0x148, u8) = 0;
        ov002_SetState(self, 7);
    }
    case 7:
        ret = FALSE;
        break;
    }
    return ret;
}

}
}  // namespace m_021e7ea8

// ---- merged from ov002_021e828c.cpp
namespace m_021e828c {
extern "C" {

extern void *data_ov002_021f0104[];
void *func_02035c9c(void *a);
void func_ov002_021e9d7c(void *dst, u32 size, void *src, int mode, u8 idx);

static inline BOOL ov002_ResReady(void *self) {
    BOOL r = FALSE;
    if (FIELD(self, 0x20, void *) != NULL) {
        if (func_02035bd4((u8 *)self + 0x24, (u8 *)self + 0x48, 0)) {
            r = TRUE;
            FIELD(self, 0x68, void *) = func_02035fe8((u8 *)self + 0x24, (u8 *)self + 0x48);
        }
    } else {
        if (func_02035b90((char *)((u8 *)self + 0x48), 0)) {
            r = TRUE;
            FIELD(self, 0x68, void *) = func_02035c9c((u8 *)self + 0x48);
        }
    }
    return r;
}

static inline void ov002_ResLoad(void *self) {
    if (FIELD(self, 0x20, void *) != NULL) {
        func_020359fc((u8 *)self + 0x24, (u8 *)self + 0x48, 0, 0);
    } else {
        func_020359d0((char *)((u8 *)self + 0x48), 0, 0);
    }
}

static inline void ov002_ResFree(void *self) {
    if (FIELD(self, 0x20, void *) != NULL) {
        func_02035acc((u8 *)self + 0x24, (u8 *)self + 0x48, 0);
    } else {
        func_02036838(data_02097cdc, (char *)((u8 *)self + 0x48), 0, 0);
    }
}

BOOL func_ov002_021e828c(void *self) {
    BOOL r = FALSE;
    switch (FIELD(self, 0x8, s32)) {
    case 0:
        func_020359fc(data_ov002_021f0104[1], data_ov002_021f0104[2], 2, 0);
        if (FIELD(self, 0x44, void *) != NULL) {
            ov002_ResLoad(self);
            FIELD(self, 0x8, s32) = 10;
        } else {
            FIELD(self, 0x8, s32) = 0x28;
            break;
        }
    case 10:
        if (!ov002_ResReady(self)) {
            break;
        }
        if (FIELD(self, 0x68, void *) != NULL) {
            FIELD(self, 0x8, s32) = 0x28;
            break;
        }
        ov002_ResFree(self);
        FIELD(self, 0x8, s32) = 0x14;
    case 0x14:
        if (FIELD(self, 0x20, void *) != NULL) {
            func_ov002_021e9d7c((u8 *)self + 0x48, 0x20, FIELD(self, 0x44, void *), 0, 1);
            func_020359fc((u8 *)self + 0x24, (u8 *)self + 0x48, 0, 0);
        } else {
            func_ov002_021e9d7c((u8 *)self + 0x48, 0x20, FIELD(self, 0x44, void *), 0, 1);
            func_020359d0((char *)((u8 *)self + 0x48), 0, 0);
        }
        FIELD(self, 0x8, s32)++;
    case 0x15:
        if (!ov002_ResReady(self)) {
            break;
        }
        if (FIELD(self, 0x68, void *) != NULL) {
            FIELD(self, 0x8, s32) = 0x28;
            break;
        }
        ov002_ResFree(self);
        FIELD(self, 0x8, s32) = 0x1e;
    case 0x1e: {
        char *n = FIELD(self, 0x20, char *);
        if (n != NULL) {
            MI_CpuFill8((u8 *)self + 0x24, 0, 0x20);
            STD_CopyLString((char *)((u8 *)self + 0x24), n, 0x20);
            STD_TSNPrintf((u8 *)self + 0x24, 0x20, data_ov002_021f0647, n, data_ov002_021f0104[0x520 / 4]);
            func_ov002_021e9d7c((u8 *)self + 0x48, 0x20, FIELD(self, 0x44, void *), 0, 0);
            func_020359fc((u8 *)self + 0x24, (u8 *)self + 0x48, 0, 0);
        } else {
            func_ov002_021e9d7c((u8 *)self + 0x48, 0x20, FIELD(self, 0x44, void *), 0, 0);
            func_020359d0((char *)((u8 *)self + 0x48), 0, 0);
        }
        FIELD(self, 0x8, s32)++;
    }
    case 0x1f:
        if (!ov002_ResReady(self)) {
            break;
        }
        FIELD(self, 0x8, s32) = 0x28;
    case 0x28:
        if (!func_02035bd4(data_ov002_021f0104[1], data_ov002_021f0104[2], 2)) {
            break;
        }
        FIELD(self, 0x8, s32) = 0x64;
    case 0x64:
    default:
        r = TRUE;
        break;
    }
    return r;
}

}
}  // namespace m_021e828c

// ---- merged from ov002_021e86a0.cpp
namespace m_021e86a0 {
extern "C" {

extern void *data_ov002_021f0104[];


void func_02041c34(void *a, int b, void *c, int d);


void func_0204a360(void *a, int b);

BOOL SndMgr_IsLoadDone(void *a);

void func_ov002_021eaf20(void *self);

Oam021e7ab8 *func_ov002_021e7ab8(void *self, u16 *flag, Oam021e7ab8 *oam, u16 *count);

void func_ov002_021ead1c(void *self, u8 *a, s32 b, u8 c);

BOOL func_ov002_021e86a0(void *self) {
    BOOL r = FALSE;
    switch (FIELD(self, 0x8, s32)) {
    case 0: {
        void **tbl;
        void *res;
        void *m = Heap_Alloc(0x160);
        if (m != NULL) {
            void *file = data_ov002_021f0104[1];
            void *name = data_ov002_021f0104[2];
            func_02041218((PlttRes *)((u8 *)m + 0x88));
            func_02041440((Model *)m, (char *)name, 0);
            STD_CopyString((char *)((u8 *)m + 0x2c), (char *)file);
        }
        FIELD(self, 0x124, void *) = m;
        tbl = data_ov002_021f0104;
        res = func_02035f30(tbl[1], tbl[2], 2);
        func_020417e0((Model *)FIELD(self, 0x124, void *), func_02034d88(res, tbl[2]));
        FIELD(FIELD(self, 0x124, void *), 0x6c, u32) |= 2;
        FIELD(FIELD(self, 0x124, void *), 0x150, s32) = -9;
        func_02041c34(FIELD(self, 0x124, void *), 0, (void *)func_ov002_021e7ab8, 0);
        func_02041d9c((Model *)FIELD(self, 0x124, void *), 0, 0);
        FIELD(FIELD(self, 0x124, void *), 0x6c, u32) |= 0x80000;
        FIELD(FIELD(self, 0x124, void *), 0x6c, u32) |= 0x200000;
        FIELD(FIELD(self, 0x124, void *), 0x6c, u32) = (FIELD(FIELD(self, 0x124, void *), 0x6c, u32) & ~0x7c) | 0x78;
        func_0204aad0(data_02097e48.queue);
        if (FIELD(self, 0x68, void *) != NULL) {
            func_ov002_021ead1c((u8 *)self + 0x6c, *FIELD(self, 0x68, u8 **), FIELD(self, 0x44, s32), 1);
            func_ov002_021eaf20((u8 *)self + 0x6c);
        }
        func_0204a360(data_02097e4c, -1);
        FIELD(self, 0x8, s32) = 10;
    }
    case 10:
        if (SndMgr_IsLoadDone(data_02097e4c)) {
            FIELD(self, 0x8, s32) = 0x14;
        }
        break;
    default:
        r = TRUE;
        break;
    }
    return r;
}

BOOL func_ov002_021e4dd4(void *n);

void func_ov002_021e8bbc(void *self, void *n);

void MI_Copy64B(void *src, void *dst);

typedef struct Blk24_8828 { s32 v[9]; } Blk24_8828;

static inline BOOL ov002_inRange8828(void *self) {
    BOOL r = FALSE;
    if (FIELD(self, 0x14, s32) >= 0 && FIELD(self, 0x14, s32) <= FIELD(self, 0xd0, s32)) {
        r = TRUE;
    }
    return r;
}

BOOL func_ov002_021e8828(void *self) {
    BOOL ret = TRUE;
    BOOL busy = FALSE;
    BOOL in;
    BOOL r;
    u8 *next;
    u8 *n;
    if (FIELD(self, 0x1c, s32) != 0x5c && FIELD(self, 0x1c, s32) != 0x1e) {
        if ((data_02097dc8->trig & 8) && FIELD(self, 0x1a, u8) != 0) {
            ret = busy;
        }
    }
    for (n = FIELD(self, 0xdc, u8 *); n != NULL; n = next) {
        next = FIELD(n, 0x24, u8 *);
        r = func_ov002_021e4dd4(n);
        if (FIELD(n, 0x4, s32) == 7 && FIELD(self, 0xc, s32) == FIELD(n, 0x8, s32)) {
            {
                s32 *sv = (s32 *)(n + 0x50);
                s32 a0 = sv[0], a1 = sv[1], a2 = sv[2], a3 = sv[3], a4 = sv[4], a5 = sv[5], a6 = sv[6], a7 = sv[7], a8 = sv[8];
                s32 *d = (s32 *)((u8 *)data_0214a420 + 0x38);
                d[0] = a0; d[1] = a1; d[2] = a2; d[3] = a3; d[4] = a4; d[5] = a5; d[6] = a6; d[7] = a7; d[8] = a8;
            }
            MI_Copy64B(n + 0x74, (u8 *)data_0214a420 + 0x5c);
        }
        if (!r) {
            if (FIELD(n, 0x4, s32) == 9) {
                ret = FALSE;
            }
            func_ov002_021e8bbc(self, n);
            {
                void *saved;
                HEAP_PUSH(saved);
                if (n != NULL) {
                    if (n != NULL) {
                        ((VObject *)n)->v0x4();
                    }
                }
                HEAP_POP(saved);
            }
        } else if (!((VObject *)n)->v0x8()) {
            busy = TRUE;
        }
    }
    in = ov002_inRange8828(self);
    if (in && (FIELD(self, 0x18, u16) & data_02097dc8->trig)) {
        u8 *ctx = (u8 *)data_ov002_021f0f9c;
        FIELD(ctx, 0x14, s32) = -1;
        FIELD(ctx, 0x18, u16) = 0;
    }
    if (FIELD(self, 0xc, s32) == 2) {
        if (FIELD(self, 0x10, u8) == 0) {
            u8 *p;
            FIELD(self, 0xd4, s32) = FIELD(self, 0xd0, s32);
            FIELD(self, 0xd0, s32) = FIELD(self, 0xd0, s32) + FIELD(self, 0xd8, s32);
            func_02065ac0(data_0214a420);
            for (p = FIELD(data_0214a420, 0x20, u8 *); p != NULL; p = FIELD(p, 0xec, u8 *)) {
                FIELD(p, 0x3c, s32) = FIELD(self, 0xd8, s32);
            }
            FIELD(data_0214a420, 0x34, u8) = 1;
        }
        { BOOL v = TRUE; if (!busy && !ov002_inRange8828(self)) v = FALSE; FIELD(self, 0x10, u8) = v; }
    }
    return ret;
}

}
}  // namespace m_021e86a0

// ---- merged from ov002_021e8aac.cpp
namespace m_021e8aac {
extern "C" {

void *Ov002Vt_021f0734_DtorDelete(void *self) {
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

BOOL func_ov002_021e8b28(void *self) {
    return FIELD(self, 0xc, s32) >= 3;
}

void func_ov002_021e8b3c(VObject *self) {
    u32 mask;
    if (FIELD(self, 4, s32) != 4 && FIELD(self, 4, s32) != 5) {
        return;
    }
    mask = FIELD(self, 0xc, u32);
    if ((FIELD(self, 0x128, u32) & mask) && FIELD(self, 0xd0, s32) > 0) {
        func_ov002_021e8cc4(self);
    }
    for (self = FIELD(self, 0xdc, VObject *); self != NULL; self = FIELD(self, 0x24, VObject *)) {
        if ((FIELD(self, 8, u32) & mask) && FIELD(self, 0xc, s32) == 3) {
            self->v0x1c();
        }
    }
}

void func_ov002_021e8bbc(void *self, void *item) {
    void *node = FIELD(self, 0xdc, void *);
    void *prev = NULL;
    if (node == item) {
        FIELD(self, 0xdc, void *) = FIELD(item, 0x24, void *);
        return;
    }
    while (node != NULL) {
        if (node == item) {
            break;
        }
        prev = node;
        node = FIELD(node, 0x24, void *);
    }
    if (node != NULL) {
        FIELD(prev, 0x24, void *) = FIELD(node, 0x24, void *);
        FIELD(node, 0x24, void *) = NULL;
    }
}

void func_ov002_021e8c0c(void *self) {
    VObject *o = FIELD(self, 0xdc, VObject *);
    while (o != NULL) {
        VObject *next = FIELD(o, 0x24, VObject *);
        void *saved;
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->v0x4();
            }
        }
        HEAP_POP(saved);
        o = next;
    }
    FIELD(self, 0xdc, void *) = NULL;
    {
        void *saved;
        HEAP_PUSH(saved);
        {
            void *p = FIELD(self, 0x124, void *);
            if (p != NULL) {
                if (p != NULL) {
                    func_02041558((Model *)p);
                    func_02041278((PlttRes *)((u8 *)p + 0x88));
                    Heap_Free(p);
                }
                FIELD(self, 0x124, void *) = NULL;
            }
        }
        HEAP_POP(saved);
    }
}

}
}  // namespace m_021e8aac

// ---- merged from ov002_021e8cc4.cpp
namespace m_021e8cc4 {
extern "C" {

void NNS_G3dGlbFlushP(void);
void NNS_G3dGeBufferOP_N(int cmd, void *data, int n);
void func_02043db4(int a, s32 b, s32 c, u16 d);
void func_02041c18(void *a, int b);
extern VecFx32 data_ov002_021ef104;
extern VecFx32 data_ov002_021ef0bc;

static inline void *ov002_Model_GetPart(void *self, int idx) {
    if (idx >= FIELD(self, 0x80, s32)) {
        return NULL;
    }
    return (u8 *)FIELD(self, 0x78, void *) + idx * 0x28;
}

static inline void ov002_Model_PlayPart(void *model, int idx) {
    void *res = FIELD(model, 0x28, void *);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = ov002_Model_GetPart(model, idx);
    if (part != NULL && FIELD(part, 0x4, void *) != NULL) {
        anim = FIELD(FIELD(part, 0x4, void *), 0x30, void *);
    } else {
        anim = NNS_G2dGetCellDataByIdx(FIELD(res, 0x4, void *), **(u16 **)FIELD(NNS_G2dGetAnimSequenceByIdx(FIELD(res, 0xc, void *), idx), 0xc, void *));
    }
    func_02042628((Model *)model, anim, (ModelPart *)part, 0);
}

typedef struct Blk12 {
    s32 w[3];
} Blk12;

typedef struct Bits021e8cc4 {
    u32 lo : 7;
    u32 b7 : 6;
    u32 hi : 19;
} Bits021e8cc4;

void func_ov002_021e8cc4(void *self) {
    VecFx32 at;
    VecFx32 up = data_ov002_021ef104;
    VecFx32 zero = {0, 0, 0};
    VecFx32 w;
    s32 t;
    u32 c;
    s32 t2;
    s32 t3;
    *(Blk12 *)&at = *(Blk12 *)&data_ov002_021ef0bc;
    NNS_G3dGlb.camPos = zero;
    NNS_G3dGlb.camUp = up;
    NNS_G3dGlb.camTarget = at;
    MTX_LookAt(&zero, &up, &at, (MtxFx43 *)data_02092844);
    NNS_G3dGlb.flag &= ~0xe8;
    MIi_CpuCopyFast((u8 *)self + 0xe4, data_02092800, 0x40);
    NNS_G3dGlb.flag &= ~0x50;
    NNS_G3dGlbFlushP();
    t = 2;
    NNS_G3dGeBufferOP_N(0x10, &t, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    NNS_G3dGeBufferOP_N(0x15, NULL, 0);
    w.x = 0;
    w.y = 0x93000;
    w.z = -0x29;
    NNS_G3dGeBufferOP_N(0x1c, &w, 3);
    c = 0x3e1e08c0;
    NNS_G3dGeBufferOP_N(0x29, &c, 1);
    func_02043db4(1, 0x100000, 0x2d000, 0);
    t2 = 2;
    NNS_G3dGeBufferOP_N(0x10, &t2, 1);
    t3 = 1;
    NNS_G3dGeBufferOP_N(0x12, &t3, 1);
    if (FIELD(self, 0x12c, s32) == 0xff) {
        return;
    }
    FIELD(FIELD(self, 0x124, u8 *), 0x6c, Bits021e8cc4).b7 = 0x3d;
    func_02041c18(FIELD(self, 0x124, void *), FIELD(self, 0x12c, s32));
    {
        u8 *m = FIELD(self, 0x124, u8 *);
        FIELD(m, 0xfc, s32) = 0;
        FIELD(m, 0x100, s32) = 0x8a000;
    }
    ov002_Model_PlayPart(FIELD(self, 0x124, void *), 0);
}

}
}  // namespace m_021e8cc4

// ---- merged from ov002_021e8f04.cpp
namespace m_021e8f04 {
extern "C" {


extern u8 data_ov002_021f0878[];
extern u8 data_ov002_021f087c[];
extern u8 data_ov002_021f0880[];
void func_ov002_021e9d7c(void *dst, u32 size, void *src, int mode, u8 idx);

#define GAME ((u8 *)data_ov002_021f0f9c)

void func_ov002_021e8f04(s32 idx) {
    void *p;
    void *name;
    u8 *g;
    u8 m;
    s32 v;
    float f;
    s32 off;
    {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(*(VObject **)&data_ov002_021f0f9c);
        HEAP_POP(saved);
    }
    p = Heap_Alloc(0x2cc);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0674;
        *(VFunc **)((u8 *)p + 0x6c) = data_ov002_021f0684;
        func_ov002_021eacd0((u8 *)p + 0x6c);
        Gfx3DState_Init((u8 *)p + 0x14c);
        func_ov002_021e7cb4(p);
    }
    off = idx * 0xc;
    GAME = (u8 *)p;
    FIELD(p, 0x1c, s32) = idx;
    name = *(void **)(data_ov002_021f0878 + off);
    g = (u8 *)GAME;
    FIELD(g, 0x20, void *) = name;
    m = ((u8 (*)(void))LangData_GetLang)();
    MI_CpuFill8(g + 0x24, 0, 0x20);
    STD_CopyLString((char *)(g + 0x24), (char *)name, 0x20);
    STD_TSNPrintf(g + 0x24, 0x20, data_ov002_021f0647, name, data_ov002_021f0624[m]);
    {
        void *desc;
        u8 *g2;
        g2 = GAME;
        desc = *(void **)(data_ov002_021f087c + off);
        FIELD(g2, 0x44, void *) = desc;
        func_ov002_021e9d7c(g2 + 0x48, 0x20, desc, 0, ((u8 (*)(void))LangData_GetLang)());
    }
    v = *(s16 *)(data_ov002_021f0880 + off);
    if (v > 0) {
        f = (float)(v << 12) + 0.5f;
    } else {
        f = (float)(v << 12) - 0.5f;
    }
    v = (s32)f;
    {
        u8 *g3 = GAME;
        FIELD(g3, 0x14, s32) = v;
        FIELD(g3, 0x18, s16) = 1;
    }
}

}
}  // namespace m_021e8f04
#undef GAME

// ---- merged from ov002_021e90ac.cpp
namespace m_021e90ac {
extern "C" {

bool func_ov002_021e90ac(void) {
    BOOL r;
    if (data_ov002_021f0f9c == NULL) {
        r = FALSE;
    } else {
        r = func_ov002_021e7ea8(data_ov002_021f0f9c);
    }
    return r;
}

void func_ov002_021e90dc(void) {
    VObject *self = (VObject *)data_ov002_021f0f9c;
    u32 mask;
    if (self == NULL) {
        return;
    }
    if (FIELD(self, 4, s32) != 4 && FIELD(self, 4, s32) != 5) {
        return;
    }
    mask = FIELD(self, 0xc, u32);
    if ((FIELD(self, 0x128, u32) & mask) && FIELD(self, 0xd0, s32) > 0) {
        func_ov002_021e8cc4(self);
    }
    for (self = FIELD(self, 0xdc, VObject *); self != NULL; self = FIELD(self, 0x24, VObject *)) {
        if ((FIELD(self, 8, u32) & mask) && FIELD(self, 0xc, s32) == 3) {
            self->v0x1c();
        }
    }
}

void func_ov002_021e916c(void) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(*(VObject **)&data_ov002_021f0f9c);
    HEAP_POP(saved);
}

static inline void func_ov002_021e4cd8_inline5(void *self) {
    u8 *ctx;
    FIELD(self, 0x4, s32) = -1;
    FIELD(self, 0x8, s32) = 1;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s32) = 0;
    FIELD(self, 0x14, s32) = 0;
    FIELD(self, 0x18, s32) = 0;
    FIELD(self, 0x1c, s32) = 0;
    FIELD(self, 0x20, s32) = -0x29;
    FIELD(self, 0x24, s32) = 0;
    MIi_CpuClear32(0, (u8 *)self + 0x28, 0x20);
    FIELD(self, 0x48, s32) = 0;
    ctx = (u8 *)data_ov002_021f0f9c;
    if (FIELD(ctx, 0xe0, void *) == NULL) {
        FIELD(ctx, 0xdc, void *) = self;
    } else {
        FIELD(FIELD(ctx, 0xe0, void *), 0x24, void *) = self;
    }
    FIELD(ctx, 0xe0, void *) = self;
}
void *func_ov002_021e91c8(s32 a, s32 b, s32 c, bool d, u8 e) {
    void *p = Heap_Alloc(0x1f4);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0734;
        func_ov002_021e4cd8_inline5(p);
        *(VFunc **)p = data_ov002_021f07d4;
        func_ov002_021e5140(p);
    }
    FIELD(p, 0x18, s32) = a;
    FIELD(p, 0x1c, s32) = b;
    FIELD(p, 0x8, s32) = c;
    FIELD(p, 0x1f0, Bits8).b0 = e;
    FIELD(p, 0x1f0, Bits8).b1 = d;
    return p;
}

static inline void func_ov002_021e4cd8_inline2(void *self) {
    u8 *ctx;
    FIELD(self, 0x4, s32) = -1;
    FIELD(self, 0x8, s32) = 1;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s32) = 0;
    FIELD(self, 0x14, s32) = 0;
    FIELD(self, 0x18, s32) = 0;
    FIELD(self, 0x1c, s32) = 0;
    FIELD(self, 0x20, s32) = -0x29;
    FIELD(self, 0x24, s32) = 0;
    MIi_CpuClear32(0, (u8 *)self + 0x28, 0x20);
    FIELD(self, 0x48, s32) = 0;
    ctx = (u8 *)data_ov002_021f0f9c;
    if (FIELD(ctx, 0xe0, void *) == NULL) {
        FIELD(ctx, 0xdc, void *) = self;
    } else {
        FIELD(FIELD(ctx, 0xe0, void *), 0x24, void *) = self;
    }
    FIELD(ctx, 0xe0, void *) = self;
}
void *func_ov002_021e92b0(s32 a, s32 b, s32 c, s32 d, s32 e) {
    void *p = Heap_Alloc(0xec);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0734;
        func_ov002_021e4cd8_inline2(p);
        *(VFunc **)p = data_ov002_021f075c;
        func_ov002_021e5d0c(p);
    }
    FIELD(p, 0x18, s32) = a;
    FIELD(p, 0x1c, s32) = b;
    FIELD(p, 0x8, s32) = c;
    FIELD(p, 0x78, s32) = d;
    FIELD(p, 0x88, s32) = e;
    return p;
}

}
}  // namespace m_021e90ac

// ---- merged from ov002_021e9380.cpp
namespace m_021e9380 {
extern "C" {

static inline void func_ov002_021e4cd8_inline2(void *self) {
    u8 *ctx;
    FIELD(self, 0x4, s32) = -1;
    FIELD(self, 0x8, s32) = 1;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s32) = 0;
    FIELD(self, 0x14, s32) = 0;
    FIELD(self, 0x18, s32) = 0;
    FIELD(self, 0x1c, s32) = 0;
    FIELD(self, 0x20, s32) = -0x29;
    FIELD(self, 0x24, s32) = 0;
    MIi_CpuClear32(0, (u8 *)self + 0x28, 0x20);
    FIELD(self, 0x48, s32) = 0;
    ctx = (u8 *)data_ov002_021f0f9c;
    if (FIELD(ctx, 0xe0, void *) == NULL) {
        FIELD(ctx, 0xdc, void *) = self;
    } else {
        FIELD(FIELD(ctx, 0xe0, void *), 0x24, void *) = self;
    }
    FIELD(ctx, 0xe0, void *) = self;
}

void *func_ov002_021e9380(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    void *p = Heap_Alloc(0x70);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0734;
        func_ov002_021e4cd8_inline2(p);
        *(VFunc **)p = data_ov002_021f070c;
        FIELD(p, 0x4c, s32) = -1;
        MIi_CpuClear32(0, (u8 *)p + 0x50, 0x10);
        FIELD(p, 0x68, s32) = -1;
        FIELD(p, 0x6c, s32) = -1;
    }
    FIELD(p, 0x18, s32) = a;
    FIELD(p, 0x1c, s32) = b;
    FIELD(p, 0x8, s32) = c;
    FIELD(p, 0x4c, s32) = d;
    FIELD(p, 0x64, s32) = e;
    FIELD(p, 0x68, s32) = e == 1 ? f : -1;
    return p;
}

extern VFunc data_ov002_021f0784[];

void *func_ov002_021e9478(s32 a, s32 b, s32 c, s32 d, u16 e, s32 mode, u8 f, u8 g) {
    void *p = Heap_Alloc(0x60);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0734;
        func_ov002_021e4cd8_inline2(p);
        *(VFunc **)p = data_ov002_021f0784;
        FIELD(p, 0x4, s32) = 6;
        FIELD(p, 0x20, s32) = -0x19a;
        FIELD(p, 0x4c, s32) = 0;
        FIELD(p, 0x50, u16) = 0;
        FIELD(p, 0x54, s32) = 0;
        FIELD(p, 0x58, s32) = 0;
        FIELD(p, 0x5c, s32) = 0;
    }
    FIELD(p, 0x18, s32) = a;
    FIELD(p, 0x1c, s32) = b;
    FIELD(p, 0x8, s32) = d;
    switch (mode) {
    case 0:
        FIELD(p, 0x4c, s32) = 0;
        break;
    case 1:
        FIELD(p, 0x4c, s32) = 1;
        break;
    case 2:
        FIELD(p, 0x4c, s32) = 2;
        FIELD(p, 0x54, u32) = f > 0x1f ? 0x1f : f;
        FIELD(p, 0x58, u32) = g > 0x1f ? 0x1f : g;
        break;
    }
    FIELD(p, 0x5c, s32) = c;
    FIELD(p, 0x50, u16) = e;
    return p;
}

void *GfxCamPos_Init(void *p);

void MTX_Identity44_(void *p);

extern VFunc data_ov002_021f0854[];

extern VFunc data_ov002_021f0828[];

extern const VecFx32 data_ov002_021ef0e0;

extern const VecFx32 data_ov002_021ef0ec;

extern const VecFx32 data_ov002_021ef0c8;

void *func_ov002_021e95c4(u8 *a, u8 *b) {
    s32 i;
    u8 *p = (u8 *)Heap_Alloc(0xcc);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0734;
        func_ov002_021e4cd8_inline2(p);
        *(VFunc **)p = data_ov002_021f0854;
        GfxCamPos_Init(p + 0x50);
        FIELD(p, 0x4, s32) = 7;
        FIELD(p, 0x4c, s32) = -1;
        MTX_Identity44_(p + 0x74);
        *(VFunc **)p = data_ov002_021f0828;
        FIELD(p, 0x4, s32) = 7;
        {
            VecFx32 v = data_ov002_021ef0e0;
            FIELD(p, 0x50, VecFx32) = v;
        }
        {
            VecFx32 v = data_ov002_021ef0ec;
            FIELD(p, 0x68, VecFx32) = v;
        }
        {
            VecFx32 v = data_ov002_021ef0c8;
            FIELD(p, 0x5c, VecFx32) = v;
        }
        FIELD(p, 0xb8, u16) = 0xaaa;
        FIELD(p, 0xb4, s32) = 0xeff1;
        FIELD(p, 0xba, s16) = FX_SINCOS(0xaa);
        FIELD(p, 0xbc, s16) = FX_SINCOS(0xab);
        FIELD(p, 0xbe, u16) = 0x1555;
        FIELD(p, 0xc0, s32) = 0x2000;
        FIELD(p, 0xc4, s32) = 0x7d0000;
        FIELD(p, 0xc8, s32) = 0;
    }
    if (a != NULL) {
        FIELD(p, 0x48, void *) = a;
        for (i = 0; i < 8; i++) {
            if (((void **)(a + 0x28))[i] == NULL) {
                ((void **)(a + 0x28))[i] = p;
                break;
            }
        }
    }
    if (b != NULL) {
        for (i = 0; i < 8; i++) {
            if (((void **)(p + 0x28))[i] == NULL) {
                ((void **)(p + 0x28))[i] = b;
                break;
            }
        }
        FIELD(b, 0x48, void *) = p;
    }
    FIELD(p, 0x18, s32) = 0;
    FIELD(p, 0x1c, s32) = 0x7ffffffe;
    FIELD(p, 0x8, s32) = 1;
    return p;
}

void MTX_OrthoW(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, void *out);

extern VFunc data_ov002_021f07fc[];

void *func_ov002_021e97e8(u8 *a, u8 *b) {
    s32 i;
    u8 *p = (u8 *)Heap_Alloc(0xb8);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0734;
        func_ov002_021e4cd8_inline2(p);
        *(VFunc **)p = data_ov002_021f0854;
        GfxCamPos_Init(p + 0x50);
        FIELD(p, 0x4, s32) = 7;
        FIELD(p, 0x4c, s32) = -1;
        MTX_Identity44_(p + 0x74);
        *(VFunc **)p = data_ov002_021f07fc;
        FIELD(p, 0x4, s32) = 8;
        MTX_OrthoW(0x60000, -0x60000, -0x80000, 0x80000, 0, 0x20000, 0x400000, p + 0x74);
        FIELD(p, 0xb4, s32) = 0;
    }
    if (a != NULL) {
        FIELD(p, 0x48, void *) = a;
        for (i = 0; i < 8; i++) {
            if (((void **)(a + 0x28))[i] == NULL) {
                ((void **)(a + 0x28))[i] = p;
                break;
            }
        }
    }
    if (b != NULL) {
        for (i = 0; i < 8; i++) {
            if (((void **)(p + 0x28))[i] == NULL) {
                ((void **)(p + 0x28))[i] = b;
                break;
            }
        }
        FIELD(b, 0x48, void *) = p;
    }
    FIELD(p, 0x18, s32) = 0;
    FIELD(p, 0x1c, s32) = 0x7ffffffe;
    FIELD(p, 0x8, s32) = 1;
    return p;
}

}
}  // namespace m_021e9380

// ---- merged from ov002_021e9974.cpp
namespace m_021e9974 {
extern "C" {

static inline void func_ov002_021e4cd8_inline4(void *self) {
    u8 *ctx;
    FIELD(self, 0x4, s32) = -1;
    FIELD(self, 0x8, s32) = 1;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s32) = 0;
    FIELD(self, 0x14, s32) = 0;
    FIELD(self, 0x18, s32) = 0;
    FIELD(self, 0x1c, s32) = 0;
    FIELD(self, 0x20, s32) = -0x29;
    FIELD(self, 0x24, s32) = 0;
    MIi_CpuClear32(0, (u8 *)self + 0x28, 0x20);
    FIELD(self, 0x48, s32) = 0;
    ctx = (u8 *)data_ov002_021f0f9c;
    if (FIELD(ctx, 0xe0, void *) == NULL) {
        FIELD(ctx, 0xdc, void *) = self;
    } else {
        FIELD(FIELD(ctx, 0xe0, void *), 0x24, void *) = self;
    }
    FIELD(ctx, 0xe0, void *) = self;
}
void *func_ov002_021e9974(s32 a, s32 b, s16 c, void *d) {
    void *p = Heap_Alloc(0x54);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0734;
        func_ov002_021e4cd8_inline4(p);
        *(VFunc **)p = data_ov002_021f06e4;
        FIELD(p, 4, s32) = 10;
        FIELD(p, 0x4c, s16) = 0;
        FIELD(p, 0x50, void *) = NULL;
    }
    FIELD(p, 0x18, s32) = a;
    FIELD(p, 0x1c, s32) = b;
    FIELD(p, 0x8, s32) = 2;
    FIELD(p, 0x4c, s16) = c;
    FIELD(p, 0x50, void *) = d;
    return p;
}

static inline void func_ov002_021e4cd8_inline3(void *self) {
    u8 *ctx;
    FIELD(self, 0x4, s32) = -1;
    FIELD(self, 0x8, s32) = 1;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s32) = 0;
    FIELD(self, 0x14, s32) = 0;
    FIELD(self, 0x18, s32) = 0;
    FIELD(self, 0x1c, s32) = 0;
    FIELD(self, 0x20, s32) = -0x29;
    FIELD(self, 0x24, s32) = 0;
    MIi_CpuClear32(0, (u8 *)self + 0x28, 0x20);
    FIELD(self, 0x48, s32) = 0;
    ctx = (u8 *)data_ov002_021f0f9c;
    if (FIELD(ctx, 0xe0, void *) == NULL) {
        FIELD(ctx, 0xdc, void *) = self;
    } else {
        FIELD(FIELD(ctx, 0xe0, void *), 0x24, void *) = self;
    }
    FIELD(ctx, 0xe0, void *) = self;
}
void *func_ov002_021e9a50(void *a, void *b) {
    void *p = Heap_Alloc(0x160);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0734;
        func_ov002_021e4cd8_inline3(p);
        *(VFunc **)p = data_ov002_021f07ac;
        Ov002Vt_021f0ce8_Ctor((u8 *)p + 0x8c);
        func_ov002_021e6a14(p);
    }
    STD_CopyLString((char *)((u8 *)p + 0x4c), (char *)a, 0x20);
    STD_CopyLString((char *)((u8 *)p + 0x6c), (char *)b, 0x20);
    return p;
}

static inline void func_ov002_021e4cd8_inline(void *self) {
    u8 *ctx;
    FIELD(self, 0x4, s32) = -1;
    FIELD(self, 0x8, s32) = 1;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s32) = 0;
    FIELD(self, 0x14, s32) = 0;
    FIELD(self, 0x18, s32) = 0;
    FIELD(self, 0x1c, s32) = 0;
    FIELD(self, 0x20, s32) = -0x29;
    FIELD(self, 0x24, s32) = 0;
    MIi_CpuClear32(0, (u8 *)self + 0x28, 0x20);
    FIELD(self, 0x48, s32) = 0;
    ctx = (u8 *)data_ov002_021f0f9c;
    if (FIELD(ctx, 0xe0, void *) == NULL) {
        FIELD(ctx, 0xdc, void *) = self;
    } else {
        FIELD(FIELD(ctx, 0xe0, void *), 0x24, void *) = self;
    }
    FIELD(ctx, 0xe0, void *) = self;
}
void *func_ov002_021e9b28(void *arg) {
    void *p = Heap_Alloc(0x4c);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0734;
        func_ov002_021e4cd8_inline(p);
        *(VFunc **)p = data_ov002_021f0694;
        FIELD(p, 4, s32) = 9;
    }
    FIELD(p, 0x1c, void *) = arg;
    return p;
}

}
}  // namespace m_021e9974

// ---- merged from ov002_021e9bd8.cpp
namespace m_021e9bd8 {
extern "C" {

static inline void func_ov002_021e4cd8_inline2(void *self) {
    u8 *ctx;
    FIELD(self, 0x4, s32) = -1;
    FIELD(self, 0x8, s32) = 1;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s32) = 0;
    FIELD(self, 0x14, s32) = 0;
    FIELD(self, 0x18, s32) = 0;
    FIELD(self, 0x1c, s32) = 0;
    FIELD(self, 0x20, s32) = -0x29;
    FIELD(self, 0x24, s32) = 0;
    MIi_CpuClear32(0, (u8 *)self + 0x28, 0x20);
    FIELD(self, 0x48, s32) = 0;
    ctx = (u8 *)data_ov002_021f0f9c;
    if (FIELD(ctx, 0xe0, void *) == NULL) {
        FIELD(ctx, 0xdc, void *) = self;
    } else {
        FIELD(FIELD(ctx, 0xe0, void *), 0x24, void *) = self;
    }
    FIELD(ctx, 0xe0, void *) = self;
}

extern VFunc data_ov002_021f06bc[];

void *Ov002Vt_021f0cf8_Ctor(void *p);

void func_ov002_021ec1c4(void *p);

void *func_ov002_021e9bd8(void *a, void *b) {
    void *p = Heap_Alloc(0xac);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0734;
        func_ov002_021e4cd8_inline2(p);
        *(VFunc **)p = data_ov002_021f06bc;
        Ov002Vt_021f0cf8_Ctor((u8 *)p + 0x94);
        FIELD(p, 0x4, s32) = 4;
        MI_CpuFill8((u8 *)p + 0x4c, 0, 0x20);
        MI_CpuFill8((u8 *)p + 0x6c, 0, 0x20);
        FIELD(p, 0x8c, s32) = 0;
        FIELD(p, 0x90, s32) = 0;
        func_ov002_021ec1c4((u8 *)p + 0x94);
    }
    STD_CopyLString((char *)((u8 *)p + 0x4c), (char *)a, 0x20);
    STD_CopyLString((char *)((u8 *)p + 0x6c), (char *)b, 0x20);
    return p;
}

}
}  // namespace m_021e9bd8

// ---- merged from ov002_021e9cec.cpp
namespace m_021e9cec {
extern "C" {

void func_ov002_021e9cec(void *dst, u32 size, void *src, int mode, u8 idx) {
    void *s;
    MI_CpuFill8(dst, 0, size);
    STD_CopyLString((char *)dst, (char *)src, size);
    switch (mode) {
    case 0:
        s = data_ov002_021f0624[idx];
        break;
    case 1:
        s = data_ov002_021f064c;
        break;
    case 2:
        s = data_ov002_021f0624[idx];
        break;
    default:
        s = data_ov002_021f064c;
        break;
    }
    STD_TSNPrintf(dst, size, data_ov002_021f0647, src, s);
}

void func_ov002_021e9d7c(void *dst, u32 size, void *src, int mode, u8 idx) {
    void *a;
    void *b;
    MI_CpuFill8(dst, 0, size);
    STD_CopyLString((char *)dst, (char *)src, size);
    switch (mode) {
    case 0:
        a = data_ov002_021f0624[idx];
        b = data_ov002_021f064d;
        break;
    case 1:
        b = data_ov002_021f0654;
        a = data_ov002_021f064c;
        break;
    case 2:
        a = data_ov002_021f0624[idx];
        b = data_ov002_021f065e;
        break;
    default:
        b = data_ov002_021f064c;
        a = b;
        break;
    }
    STD_TSNPrintf(dst, size, data_ov002_021f0665, src, a, b);
}

}
}  // namespace m_021e9cec

// ---- merged from ov002_021e9e40.cpp
namespace m_021e9e40 {
extern "C" {


extern u8 data_ov002_021f0878[];
extern u8 data_ov002_021f087c[];
extern u8 data_ov002_021f0880[];
void func_ov002_021e9d7c(void *dst, u32 size, void *src, int mode, u8 idx);

#define GAME ((u8 *)data_ov002_021f0f9c)
void func_ov002_021e9e40(int idx) {
    void *name;
    u8 *g;
    u8 m;
    s32 v;
    float f;
    s32 off = idx * 0xc;
    FIELD(GAME, 0x1c, s32) = idx;
    name = *(void **)(data_ov002_021f0878 + off);
    g = (u8 *)GAME;
    FIELD(g, 0x20, void *) = name;
    m = ((u8 (*)(void))LangData_GetLang)();
    MI_CpuFill8(g + 0x24, 0, 0x20);
    STD_CopyLString((char *)(g + 0x24), (char *)name, 0x20);
    STD_TSNPrintf(g + 0x24, 0x20, data_ov002_021f0647, name, data_ov002_021f0624[m]);
    {
        void *desc;
        u8 *g2;
        g2 = GAME;
        desc = *(void **)(data_ov002_021f087c + off);
        FIELD(g2, 0x44, void *) = desc;
        func_ov002_021e9d7c(g2 + 0x48, 0x20, desc, 0, ((u8 (*)(void))LangData_GetLang)());
    }
    v = *(s16 *)(data_ov002_021f0880 + off);
    if (v > 0) {
        f = (float)(v << 12) + 0.5f;
    } else {
        f = (float)(v << 12) - 0.5f;
    }
    v = (s32)f;
    {
        u8 *g3 = GAME;
        FIELD(g3, 0x14, s32) = v;
        FIELD(g3, 0x18, s16) = 1;
    }
}

}
}  // namespace m_021e9e40
#undef GAME
