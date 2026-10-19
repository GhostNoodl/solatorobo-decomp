#include "ov002/ov002.h"

namespace K { extern "C" const char data_ov002_021efdea[]; }
namespace K { extern "C" const char data_ov002_021efdf6[]; }
namespace K { extern "C" const char data_ov002_021efe02[]; }
namespace K { extern "C" const char data_ov002_021efe0e[]; }
namespace K { extern "C" const char data_ov002_021efe1a[]; }
namespace K { extern "C" const char data_ov002_021efe26[]; }

extern "C" {

extern VFunc data_ov002_021efe5c[];
extern VFunc data_ov002_021efe8c[];
void *func_ov002_021d744c(void *self);
void func_ov002_021d7620(void *self);
void *func_02035de0(void *file, void *name);
void func_02041c34(void *a, int b, void *c, int d);
void MTX_Identity22_(void *m);
void MTX_Rot22_(void *m, s32 s, s32 c);
void MTX_Concat22(void *a, void *b, void *ab);
void *func_ov002_021e0488(void *a, void *b, void *c, u16 *d);
extern void *data_0208cc88;

static inline void ov002_CamMove(u8 *c, s32 px, s32 py, s32 pz, s32 tx, s32 ty, s32 tz) {
    FIELD(c, 0x90, s32) = 15;
    FIELD(c, 0x94, s32) = 15;
    *(Vec3 *)(c + 0x98) = *(Vec3 *)FIELD(c, 0x8c, u8 *);
    *(Vec3 *)(c + 0xa4) = *(Vec3 *)(FIELD(c, 0x8c, u8 *) + 0xc);
    FIELD(c, 0xb0, s32) = px;
    FIELD(c, 0xb4, s32) = py;
    FIELD(c, 0xb8, s32) = pz;
    FIELD(c, 0xbc, s32) = tx;
    FIELD(c, 0xc0, s32) = ty;
    FIELD(c, 0xc4, s32) = tz;
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

void func_ov002_021dbec8(void *self, void *owner) {
    u8 *m;
    u8 r[0x10];
    FIELD(self, 0x4, void *) = owner;
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
    FIELD(self, 0x8, u8 *) = m;
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
        u8 *q = FIELD(self, 0x8, u8 *);
        FIELD(q, 0x1dc, s32) = 0xb33;
        FIELD(q, 0x1e0, s32) = 0x23d;
        FIELD(q, 0x1e4, s32) = 0;
    }
    {
        void *mdl = func_0203dd9c(0x160);
        if (mdl != NULL) {
            void *file = data_0208cc94;
            void *nm = data_0208cc88;
            func_02041218((u8 *)mdl + 0x88);
            func_02041440(mdl, nm, 0);
            STD_CopyString((u8 *)mdl + 0x2c, file);
        }
        FIELD(self, 0x10, void *) = mdl;
    }
    func_020417e0(FIELD(self, 0x10, void *), func_02035de0(data_0208cc94, data_0208cc88));
    FIELD(FIELD(self, 0x10, void *), 0x6c, u32) |= 2;
    FIELD(FIELD(self, 0x10, void *), 0x150, s32) = -0x2000;
    func_02041c34(FIELD(self, 0x10, void *), 6, (void *)func_ov002_021e0488, 0);
    func_02041d9c(FIELD(self, 0x10, void *), 0, 6);
    {
        u8 *c = (u8 *)func_0203dd9c(0x8c);
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
            u8 *map = FIELD(FIELD(FIELD(owner, 0x4, u8 *), 0x4, u8 *), 0x6c, u8 *);
            s32 w = FIELD(map, 0x6, Nibbles16).n0;
            s32 h = FIELD(map, 0x6, Nibbles16).n1;
            FIELD(c, 0x7c, s32) = w;
            FIELD(c, 0x80, s32) = h;
        }
    }
    FIELD(self, 0x14, u8 *)[0x88] = 0;
    ov002_Cursor_SetMode(FIELD(self, 0x14, u8 *));
    FIELD(self, 0x24, s32) = FIELD(owner, 0x28, s32);
    FIELD(self, 0x28, s32) = FIELD(owner, 0x2c, s32);
    {
        s32 d;
        s32 px;
        s32 py;
        s32 pz;
        s32 tz;
        u8 *c;
        c = FIELD(owner, 0x4, u8 *);
        d = (u8)FIELD(self, 0x28, s32) - FIELD(FIELD(FIELD(c, 0x4, u8 *), 0x6c, u8 *), 6, Nibbles16).n1;
        px = *(s32 *)(data_ov002_021eef74 + 0x58);
        py = *(s32 *)(data_ov002_021eef74 + 0x5c);
        pz = *(s32 *)(data_ov002_021eef74 + 0x60);
        tz = 0x148;
        if (d < -1) {
            pz -= 0x1ec;
            tz -= 0x1ec;
        } else if (d > 1) {
            pz += 0x1ec;
            tz += 0x1ec;
        }
        ov002_CamMove(c, px, py, pz, 0, 0, tz);
    }
    FIELD(self, 0x18, s32) = 0;
    FIELD(self, 0x4, void *) = NULL;
}

}
