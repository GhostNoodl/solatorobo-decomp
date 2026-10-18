#include "ov002/ov002.h"

extern "C" {

void func_ov002_021dedf0(void *self);

void func_ov002_021e3b40(s32 *out, s32 x, s32 z, s32 *origin);

static inline bool isState5(void *p) {
    return FIELD(p, 0x4, s32) == 5;
}

static inline void updateModel(u8 *m) {
    s32 v[3];
    func_ov002_021e3b40(v, FIELD(m, 0x74, s32), FIELD(m, 0x78, s32), (s32 *)(m + 0x7c));
    v[1] = FIELD(m, 0x84, s32);
    FIELD(m, 0x38, s32) = v[0];
    FIELD(m, 0x3c, s32) = v[1];
    FIELD(m, 0x40, s32) = v[2];
    if (FIELD(m, 0x1c, void *) != NULL && func_0203e63c(FIELD(m, 0x20, void *))) {
        NNS_G3dGlbSetBaseTrans(m + 0x38);
        NNS_G3dGlbSetBaseScale(m + 0x44);
        MI_Copy36B(m + 0x50, data_020928b4);
        NNS_G3dGlb.fc &= ~0xa4;
        NNS_G3dGlbFlushVP();
        NNS_G3dDraw(FIELD(m, 0x1c, void *));
        NNS_G3dGeFlushBuffer();
    }
}

void func_ov002_021deb60(void *self, s32 a) {
    VObject *c;
    u8 *m;
    FIELD(self, 0x4, s32) = a;
    FIELD(self, 0x8, VObject *)->v0x20();
    c = FIELD(self, 0xc, VObject *);
    if (c != NULL) {
        BOOL s = isState5(c);
        if (!s) {
            c->v0x20();
            func_ov002_021dedf0(self);
        }
    }
    m = FIELD(self, 0x10, u8 *);
    FIELD(m, 0x74, s32) = FIELD(self, 0x2c, s32);
    FIELD(m, 0x78, s32) = FIELD(self, 0x30, s32);
    updateModel(FIELD(self, 0x10, u8 *));
    FIELD(self, 0x4, s32) = 0;
}

typedef struct Fn021dec74 {
    s32 (*fn)(void *, void *);
    u32 pad;
} Fn021dec74;

typedef struct Id021dec74 {
    u16 id;
    u8 pad[6];
} Id021dec74;

extern Fn021dec74 data_ov002_021eef8c[];

extern Id021dec74 data_ov002_021eef90[];

void func_0206ecd4(int a, void *b, u16 c);

void func_ov002_021e34fc(void *self, s32 (*cmp)(void *, void *));

void func_ov002_021dec74(void *self) {
    u16 btn = FIELD(data_02097dc8, 0x12, u16);
    BOOL ch;
    if (btn & 2) {
        FIELD(self, 0x24, s32) = 0;
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        FIELD(self, 0x1c, s32) = 0;
        return;
    }
    if (FIELD(self, 0x23, u8)) {
        FIELD(self, 0x24, s32) = FIELD(FIELD(self, 0xc, void *), 0xa4, s32);
        FIELD(self, 0x23, u8) = 0;
        FIELD(self, 0x1c, s32) = 0x14;
        return;
    }
    if (FIELD(self, 0x22, u8)) {
        void *t = FIELD(FIELD(self, 0xc, void *), 0xa0, void *);
        if (t != NULL) {
            u8 *w;
            func_0206ecd4(0x100, (u8 *)self + 0x38, FIELD(t, 0x38, u16));
            w = FIELD(self, 0x4, u8 *);
            func_ov000_0215bb14(FIELD(w, 0x20, void *), (u8 *)self + 0x38);
            FIELD(w, 0x20, VObject *)->v0x70();
        }
        FIELD(self, 0x22, u8) = 0;
        return;
    }
    ch = FALSE;
    if (btn & 0x800) {
        ch = TRUE;
        FIELD(self, 0x34, s32) = (FIELD(self, 0x34, s32) + 1) % 2;
        func_02049a48(data_02097e4c, 0x66, -1, -1, -1);
    }
    if (ch) {
        s32 k = FIELD(self, 0x34, s32);
        void *r;
        u8 *w;
        func_ov002_021e34fc(FIELD(self, 0xc, void *), data_ov002_021eef8c[k].fn);
        r = func_0204c0e8(data_02149ef8, data_ov002_021eef90[k].id);
        w = FIELD(self, 0x4, u8 *);
        func_ov000_0215bb14(FIELD(w, 0x20, void *), r);
        FIELD(w, 0x20, VObject *)->v0x70();
    }
}

}
