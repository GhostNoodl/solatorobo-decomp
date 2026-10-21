#pragma opt_lifetimes on
#include "ov002/ov002.h"

namespace K { extern "C" const char data_ov002_021efdea[]; }
namespace K { extern "C" const char data_ov002_021efdf6[]; }
namespace K { extern "C" const char data_ov002_021efe02[]; }
namespace K { extern "C" const char data_ov002_021efe0e[]; }
namespace K { extern "C" const char data_ov002_021efe1a[]; }
namespace K { extern "C" const char data_ov002_021efe26[]; }

extern "C" {

typedef struct { u16 lo : 8; u16 rot : 2; u16 hi : 6; } Bits52;

extern VFunc data_ov002_021efe5c[];
extern VFunc data_ov002_021efe8c[];
void *func_ov002_021d744c(void *self);
void func_ov002_021d7620(void *self);
void *func_02035de0(void *file, void *name);
void MTX_Identity22_(void *m);
void MTX_Rot22_(void *m, s32 s, s32 c);
void MTX_Concat22(void *a, void *b, void *ab);
void func_ov002_021d9ed8(void *self, void *obj, int del);
void func_ov002_021d7b80(void *self);
void func_ov002_021d7e54(void *self);
void func_ov002_021d7d5c(void *self, void *b);
void func_ov002_021e3b0c(s32 *out, s32 *pos, s32 *origin);

static inline u8 *ov002_GetCell(u8 *w, Vec2 *pos) {
    s32 y = pos->y;
    s32 x = pos->x;
    void *q = FIELD(w, 4, void *);
    u8 *base;
    if (q == NULL || (base = FIELD(w, 0x70, u8 *)) == NULL) {
        return NULL;
    }
    return base + (y * FIELD(FIELD(q, 0x6c, u8 *), 4, Nibbles16).n3 + x) * 0xc;
}

static inline void ov002_Cursor_SetMode(u8 *c) {
    switch (c[0x88]) {
    case 0:
        { const char *s = ((char *)K::data_ov002_021efdea);
        FIELD(c, 0x8, void *) = ((char *)K::data_ov002_021efdf6);
        FIELD(c, 0xc, const char *) = s;
        FIELD(c, 0x10, const char *) = s; }
        FIELD(c, 0x84, s32) = 0x29;
        break;
    case 1:
        { const char *s = ((char *)K::data_ov002_021efe02);
        FIELD(c, 0x8, void *) = ((char *)K::data_ov002_021efdf6);
        FIELD(c, 0xc, const char *) = s;
        FIELD(c, 0x10, const char *) = s; }
        FIELD(c, 0x84, s32) = 0xcd;
        break;
    }
    func_ov002_021d7620(c + 4);
}

// y, x, id and w are locals; declaring them as parameters gives the target register allocation.
void func_ov002_021df2ec(void *self, u8 *own, s32 y, s32 x, u16 id, u8 *w) {
    s32 kind;
    u8 *c;
    u8 *o;
    u8 *map;
    u8 r[0x10];
    u8 *m;
    FIELD(self, 0x4, void *) = own;
    kind = FIELD(own, 0x1c, s32);
    w = FIELD(own, 0x4, u8 *);
    FIELD(self, 0x8, s32) = kind;
    if (kind == 10) {
        FIELD(self, 0x10, u8 *) = FIELD(ov002_GetCell(w, (Vec2 *)((u8 *)own + 0x28)), 0x8, u8 *);
        func_ov002_021d9ed8(w, FIELD(self, 0x10, u8 *), 0);
        o = FIELD(self, 0x10, u8 *);
        if (FIELD(o, 0xa4, s32) == 0 && FIELD(o, 0xac, s32) == 2) {
            FIELD(o, 0xa4, s32) = 5;
            FIELD(o, 0xa8, s32) = 5;
            FIELD(o, 0xac, s32) = 7;
        }
        o = FIELD(self, 0x10, u8 *);
        FIELD(self, 0x24, s32) = FIELD(o, 0x54, s32);
        FIELD(self, 0x28, s32) = FIELD(o, 0x58, s32);
        FIELD(self, 0x2c, u8) = FIELD(o, 0x52, Bits52).rot;
    } else {
        id = FIELD(own, 0x30, u16);
        func_0206ede8(id);
        x = FIELD(own, 0x28, s32);
        y = FIELD(own, 0x2c, s32);
        o = (u8 *)func_0203dd9c(0xd4);
        if (o != NULL) {
            *(VFunc **)o = data_ov002_021efeb8;
            func_ov002_021d7b80(o);
            *(VFunc **)o = data_ov002_021efe9c;
            func_ov002_021d7e54(o);
        }
        FIELD(self, 0x10, u8 *) = o;
        FIELD(o, 0x48, u16) = id;
        FIELD(self, 0x10, VObject *)->v0x8();
        map = FIELD(FIELD(w, 0x4, u8 *), 0x6c, u8 *);
        {
            s32 mw = FIELD(map, 0x6, Nibbles16).n0;
            s32 mh = FIELD(map, 0x6, Nibbles16).n1;
            o = FIELD(self, 0x10, u8 *);
            FIELD(o, 0x64, s32) = mw;
            FIELD(o, 0x68, s32) = mh;
        }
        o = FIELD(self, 0x10, u8 *);
        FIELD(o, 0x54, s32) = (u16)x;
        FIELD(o, 0x58, s32) = (u16)y;
        func_ov002_021e3b0c((s32 *)(o + 0x4), (s32 *)(o + 0x54), (s32 *)(o + 0x64));
        o = FIELD(self, 0x10, u8 *);
        FIELD(o, 0x52, Bits52).rot = 0;
        FIELD(o, 0x10, u16) = 0;
        FIELD(o, 0x12, u16) = 0;
        FIELD(o, 0x14, u16) = 0;
        MTX_Identity33_(o + 0x18);
        o = FIELD(self, 0x10, u8 *);
        map = FIELD(FIELD(w, 0x4, u8 *), 0x6c, u8 *);
        if (FIELD(o, 0xac, s32) != 9 && FIELD(o, 0xa4, s32) == 0) {
            func_ov002_021d7d5c(o, map);
            func_ov002_021e3b0c((s32 *)(o + 0xb0), (s32 *)(o + 0x54), (s32 *)(o + 0x64));
            FIELD(o, 0xb4, s32) = 0x400;
            FIELD(o, 0xbc, s32) = 0xb33;
            FIELD(o, 0xc4, s32) = 0;
            FIELD(o, 0xc0, s32) = 0x400;
            FIELD(o, 0xa4, s32) = 0x14;
            FIELD(o, 0xa8, s32) = 0x14;
            FIELD(o, 0xac, s32) = 9;
        }
        (w + 8)[(u16)(id & 0xfff)]--;
        FIELD(self, 0x24, s32) = x;
        FIELD(self, 0x28, s32) = y;
        FIELD(self, 0x2c, u8) = 0;
    }
    {
        c = (u8 *)func_0203dd9c(0x8c);
        if (c != NULL) {
            *(VFunc **)c = data_ov002_021efe8c;
            func_ov002_021d744c(c + 4);
            FIELD(c, 0x78, s32) = 0;
            FIELD(c, 0x74, s32) = 0;
            FIELD(c, 0x80, s32) = 0;
            FIELD(c, 0x7c, s32) = 0;
            FIELD(c, 0x84, s32) = 0;
            c[0x88] = 0;
            FIELD(c, 0x8a, u16) = 0x7fff;
        }
        FIELD(self, 0x14, u8 *) = c;
        {
            u8 *map = FIELD(FIELD(FIELD(FIELD(self, 0x4, u8 *), 0x4, u8 *), 0x4, u8 *), 0x6c, u8 *);
            s32 mw = FIELD(map, 0x6, Nibbles16).n0;
            s32 mh = FIELD(map, 0x6, Nibbles16).n1;
            FIELD(c, 0x7c, s32) = mw;
            FIELD(c, 0x80, s32) = mh;
        }
    }
    FIELD(self, 0x14, u8 *)[0x88] = 1;
    ov002_Cursor_SetMode(FIELD(self, 0x14, u8 *));
    m = (u8 *)func_0203dd9c(0x1e8);
    if (m != NULL) {
        *(VFunc **)m = data_ov002_021efe5c;
        func_ov002_021d744c(m + 4);
        func_02041218(m + 0x74 + 0x88);
        func_02041440(m + 0x74, NULL, 0);
        m[0x1d4] = 0;
        FIELD(m, 0x1dc, s32) = 0;
        FIELD(m, 0x1e0, s32) = 0;
        FIELD(m, 0x1e4, s32) = 0;
    }
    FIELD(self, 0xc, u8 *) = m;
    FIELD(m, 0x8, void *) = ((char *)K::data_ov002_021efdf6);
    FIELD(m, 0xc, void *) = ((char *)K::data_ov002_021efe0e);
    FIELD(m, 0x10, void *) = ((char *)K::data_ov002_021efe0e);
    func_ov002_021d7620(m + 4);
    {
        char *nm = ((char *)K::data_ov002_021efe1a);
        char *file = ((char *)K::data_ov002_021efe26);
        func_02041440(m + 0x74, nm, 0);
        STD_CopyString(m + 0x74 + 0x2c, file);
        func_020417e0(m + 0x74, func_02035de0(file, nm));
    }
    FIELD(m, 0x74 + 0x6c, u32) |= 2;
    FIELD(m, 0x74 + 0x150, s32) = -0x2000;
    func_02041d9c(m + 0x74, 0, 4);
    MTX_Identity22_(m + 0x188);
    MTX_Rot22_(r, FX_SINCOS(0xbff * 2), FX_SINCOS(0xbff * 2 + 1));
    MTX_Concat22(r, m + 0x188, m + 0x188);
    {
        u8 *q = FIELD(self, 0xc, u8 *);
        FIELD(q, 0x1dc, s32) = 0xb33;
        FIELD(q, 0x1e0, s32) = 0x23d;
        FIELD(q, 0x1e4, s32) = 0;
    }
    {
        void *str = func_0206ec48(FIELD(FIELD(self, 0x10, u8 *), 0x48, u16));
        u8 *t = FIELD(self, 0x4, u8 *);
        func_ov000_0215bb14(FIELD(t, 0x20, void *), str);
        FIELD(t, 0x20, VObject *)->v0x70();
    }
    {
        u8 *b = FIELD(FIELD(self, 0x4, u8 *), 0x4, u8 *);
        b[0x74] = 7;
        b[0x75] = 1;
    }
    {
        s32 px;
        s32 py;
        py = FIELD(FIELD(self, 0x10, u8 *), 0x58, s32);
        px = FIELD(FIELD(self, 0x10, u8 *), 0x54, s32);
        func_ov002_021e019c(self, px, py);
        FIELD(self, 0x1c, s32) = px;
        FIELD(self, 0x20, s32) = py;
    }
    FIELD(self, 0x18, s32) = 0;
    FIELD(self, 0x4, void *) = NULL;
}

}
