#include "ov002/ov002.h"

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

extern "C" {

void func_ov002_021e019c(void *self, u8 a, u8 b) {
    s32 dx;
    s32 dy;
    s32 px;
    s32 py;
    s32 pz;
    s32 tx;
    s32 tz;
    u8 *c;
    c = FIELD(FIELD(self, 0x4, u8 *), 0x4, u8 *);
    dx = a - FIELD(FIELD(FIELD(c, 0x4, u8 *), 0x6c, u8 *), 6, Nibbles16).n0;
    dy = b - FIELD(FIELD(FIELD(c, 0x4, u8 *), 0x6c, u8 *), 6, Nibbles16).n1;
    px = *(s32 *)(data_ov002_021eef74 + 0x40);
    py = *(s32 *)(data_ov002_021eef74 + 0x44);
    pz = *(s32 *)(data_ov002_021eef74 + 0x48);
    tx = 0;
    tz = 0xa4;
    if (dy < -1) {
        pz -= 0x1ec;
        tz -= 0x1ec;
    } else if (dy > 1) {
        pz += 0x1ec;
        tz += 0x1ec;
    }
    if (dx < -1) {
        px -= 0x1ec;
        tx -= 0x1ec;
    } else if (dx > 1) {
        px += 0x1ec;
        tx += 0x1ec;
    }
    ov002_CamMove(c, px, py, pz, tx, 0, tz);
}

}
