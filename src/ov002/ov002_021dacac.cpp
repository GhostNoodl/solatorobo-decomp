#include "ov002/ov002.h"

extern "C" {

extern VFunc data_ov000_021cadcc[];
extern u8 data_ov002_021efe30[];
int func_ov002_021dac8c(void *self, void *arg);
BOOL func_ov000_0219bf90(void);
BOOL func_ov000_0219d5a0(void);
void *func_ov000_02154b80(void *a, u8 b);

static inline void ov002_SetId(void *x, u16 id) {
    if (x != NULL) {
        func_ov002_021e2754(x, id);
    }
}

static inline void ov002_CamInit(u8 *c, const Vec3 *pos) {
    FIELD(c, 0x90, s32) = 15;
    FIELD(c, 0x94, s32) = 15;
    *(Vec3 *)(c + 0x98) = *(Vec3 *)FIELD(c, 0x8c, u8 *);
    *(Vec3 *)(c + 0xa4) = *(Vec3 *)(FIELD(c, 0x8c, u8 *) + 0xc);
    if (pos != NULL) {
        *(Vec3 *)(c + 0xb0) = *pos;
    }
    FIELD(c, 0xbc, s32) = -0x2b8;
    FIELD(c, 0xc0, s32) = 0;
    FIELD(c, 0xc4, s32) = 0x2b8;
}

void func_ov002_021dacac(void *self) {
    void *g = data_02149ef8;
    VObject *o;
    VObject *m;
    u8 *s;
    u8 *w;
    void *t;
    o = (VObject *)func_0203dd9c(0xd4);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->v0x28();
        *(VFunc **)o = data_ov000_021caec8;
        o->v0x28();
    }
    FIELD(self, 0xc, VObject *) = o;
    FIELD(self, 0xc, VObject *)->v0x10(func_0204c0e8(g, 0xba));
    FIELD(self, 0xc, VObject *)->v0x14(func_0204c0e8(g, 0xbb));
    FIELD(FIELD(self, 0xc, void *), 0x20, s32) = 2;
    FIELD(FIELD(self, 0xc, void *), 0x24, s32) = 0x78;
    s = FIELD(self, 0xc, u8 *);
    FIELD(s, 0x64, s16) = 0;
    FIELD(s, 0x66, s16) = 0x1e;
    FIELD(s, 0x68, s16) = -0x2000;
    FIELD(FIELD(self, 0xc, void *), 0x68, s16) = -0x2000;
    s = FIELD(self, 0xc, u8 *);
    FIELD(s, 0x58, s32) = -0xff;
    FIELD(s, 0x5c, s32) = 0;
    FIELD(s, 0x60, s32) = -0x2000;
    FIELD(FIELD(self, 0xc, void *), 0xc, u32) &= ~0x400000;
    FIELD(FIELD(self, 0xc, void *), 0xc, u32) &= ~0x80000;
    FIELD(FIELD(self, 0xc, void *), 0xc, u32) &= ~0x40000;
    FIELD(FIELD(self, 0xc, void *), 0xc, u32) |= 0x800000;
    FIELD(FIELD(self, 0xc, void *), 0x8, void *) = self;
    FIELD(FIELD(self, 0xc, void *), 0x84, void *) = (void *)func_ov002_021dac8c;
    FIELD(self, 0xc, VObject *)->v0x74(func_0204c0e8(g, 0xbc), 0, 0xffff, 0xffff);
    if (func_020594bc(data_02fe152c, 5, 1, 1)) {
        u8 *e = (u8 *)FIELD(self, 0xc, VObject *)->v0x74(func_0204c0e8(g, 0xbe), 1, 0xffff, 0xffff);
        if (func_ov000_0219bf90()) {
            if ((FIELD(self, 0x20, u8) = func_ov000_0219d5a0()) != 0) {
                FIELD(e, 0x24, s32) = 0xe;
            }
        }
    }
    FIELD(self, 0xc, VObject *)->v0x74(func_0204c0e8(g, 0xfa), 2, 0xffff, 0xffff);
    m = FIELD(self, 0xc, VObject *);
    m->v0xa8(func_ov000_02154b80(m, *(u8 *)data_ov002_021f0f90));
    FIELD(FIELD(self, 0xc, void *), 0xc, u32) &= ~0x20000;
    FIELD(FIELD(self, 0xc, void *), 0xc, u32) &= ~0x40000;
    FIELD(FIELD(self, 0xc, void *), 0xc, u32) &= ~0x10000;
    FIELD(self, 0xc, VObject *)->v0x8();
    o = (VObject *)func_0203dd9c(0x8c);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->v0x28();
        *(VFunc **)o = data_ov000_021cadcc;
        o->v0x28();
    }
    FIELD(self, 0x10, VObject *) = o;
    FIELD(o, 0x24, s32) = 0xf8;
    FIELD(FIELD(self, 0x10, void *), 0x20, s32) = 2;
    s = FIELD(self, 0x10, u8 *);
    FIELD(s, 0x64, s16) = 4;
    FIELD(s, 0x66, s16) = 0x96;
    FIELD(s, 0x68, s16) = -0x2000;
    s = FIELD(self, 0x10, u8 *);
    FIELD(s, 0x58, s32) = -0x100;
    FIELD(s, 0x5c, s32) = 0;
    FIELD(s, 0x60, s32) = -0x2000;
    FIELD(FIELD(self, 0x10, void *), 0x2c, s32) = 1;
    FIELD(self, 0x10, VObject *)->v0x8();
    {
        u8 kind = *(u8 *)data_ov002_021f0f90;
        if (FIELD(self, 0x10, void *) != NULL) {
            void *str;
            void *g2 = data_02149ef8;
            switch (kind) {
            case 0:
                str = func_0204c0e8(g2, 0xbd);
                break;
            case 1:
                str = func_0204c0e8(g2, 0xbf);
                break;
            case 2:
                str = func_0204c0e8(g2, 0xfb);
                break;
            default:
                str = data_ov002_021efe30;
                break;
            }
            func_ov000_0215bb14(FIELD(self, 0x10, void *), str);
            FIELD(self, 0x10, VObject *)->v0x70();
        }
    }
    ov002_CamInit(FIELD(self, 0x4, u8 *), (const Vec3 *)(data_ov002_021eef74 + 0x70));
    if (func_ov002_isMode4()) {
        func_0203cb78(0xa000, 0, -1);
    }
    {
        u8 *c = FIELD(self, 0x4, u8 *);
        FIELD(c, 0x74, u8) = 0;
        FIELD(c, 0x75, u8) = 1;
    }
    w = FIELD(self, 0x4, u8 *);
    if (FIELD(data_0214a424, 0x18, Bits021d9e38).mode == 1) {
        func_ov000_021c9544(w + 0x76, FIELD(w, 0x6c, void *));
        func_ov000_021c95ac(w + 0x76, FIELD(data_0214a424, 0x18, Bits021d9e38).id | 0x8000);
    } else {
        func_ov000_021c9544(w + 0x76, FIELD(w, 0x6c, void *));
    }
    t = func_ov000_02173610(0x1b);
    if (t != NULL && FIELD(data_0214a424, 0x18, Bits021d9e38).mode == 1) {
        ov002_SetId(FIELD(t, 0x3c, void *), FIELD(data_0214a424, 0x18, Bits021d9e38).id | 0x8000);
    }
}

}
