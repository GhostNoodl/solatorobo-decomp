// Built at a lower optimization level than the rest of the overlay: at the default level the
// registers of the camera temporaries don't match.
#pragma optimization_level 3
#include "ov002/ov002.h"

extern "C" {

void func_ov002_021dd7f0(void *self, Vec2 *a, Vec2 *b, int c);

static inline void ov002_ShowMsg(void *self, void *str) {
    u8 *t = FIELD(self, 0x4, u8 *);
    func_ov000_0215bb14(FIELD(t, 0x20, void *), str);
    FIELD(t, 0x20, VObject *)->v0x70();
}

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

static inline void *ov002_NewDcee0(void) {
    void *p = func_0203dd9c(0x138);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021efef0;
        func_ov002_021ddd80(p);
    }
    return p;
}

static inline u16 sumItems(u8 *w) {
    u16 sum = 0;
    s32 i;
    for (i = 0; i < 100; i++) {
        sum += w[8 + i];
    }
    return sum;
}

void func_ov002_021dcf00(void *self) {
    s32 px;
    u16 trig;
    s32 py;
    s32 pz;
    s32 tz;
    s32 d;
    u8 *w;
    void *msg;
    trig = FIELD(data_02097dc8, 0x12, u16);
    w = FIELD(FIELD(self, 0x4, u8 *), 0x4, u8 *);
    msg = data_02149ef8;
    if (trig & 1) {
        if (sumItems(w) == 0) {
            ov002_ShowMsg(self, func_0204c0e8(msg, 0x107));
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            return;
        }
        {
            u8 *q = FIELD(w, 0x4, u8 *);
            void *p;
            FIELD(self, 0x24, s32) = FIELD(FIELD(q, 0x6c, u8 *), 6, Nibbles16).n0;
            FIELD(self, 0x28, s32) = FIELD(FIELD(q, 0x6c, u8 *), 6, Nibbles16).n1;
            u8 *t;
            p = ov002_NewDcee0();
            t = FIELD(self, 0x4, u8 *);
            FIELD(t, 0x10, void *) = p;
            FIELD(t, 0xc, s32) = 0x14;
        }
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        return;
    }
    if ((trig & 0x20) || (trig & 2)) {
        d = (u8)FIELD(self, 0x28, s32) - FIELD(FIELD(FIELD(w, 0x4, u8 *), 0x6c, u8 *), 6, Nibbles16).n1;
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
        ov002_CamMove(w, px, py, pz, 0, 0, tz);
        func_ov002_021dd7f0(self, (Vec2 *)((u8 *)self + 0x24), (Vec2 *)((u8 *)self + 0x24), 1);
        FIELD(self, 0x18, s32) = 10;
        func_02049a48(data_02097e4c, 0xf, -1, -1, -1);
    }
}

}
