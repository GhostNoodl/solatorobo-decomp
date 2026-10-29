#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

typedef struct {
    VecFx32 pos;
    u16 rot[3];
    u8 pad[2];
    s32 unk_10;
} Msg021b2b08;

extern "C" {
extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd54;
void *func_ov000_0218e640(void *mgr, u16 id);
BOOL func_ov000_02198360(void *a, s32 b, s32 c);
u16 func_0204bfa8(void *cam);
void func_ov000_0218db58(void *self, u16 angle, u16 center, u16 range, s32 step);
void func_ov000_0218d398(void *t, u16 id, s32 a, s32 b, s32 c, void *arg);

static inline void *FindActor021b2b08(u16 id) {
    void *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(mgr, id);
}

void func_ov000_021b2b08(u8 *self) {
    u8 *a = (u8 *)FindActor021b2b08(LFLD(u16, self, 0xb20));
    void *sub = NULL;
    u8 *cam;
    u16 ang;
    u16 ry;
    u16 rx;
    if (a != NULL) {
        sub = LFLD(void *, a, 0x4c);
    }
    if (LFLD(u8, self, 0xb2f) == 0) {
        LFLD(u8, self, 0xb2f) = 1;
    }
    if (sub == NULL || (LFLD(u16, self, 0xb6a) & 2)) {
        LFLD(u16, self, 0x98) = LFLD(u16, self, 0x7e) - 0x8000;
        LFLD(s32, self, 0x9c) = 0x114;
        LFLD(s32, self, 0xa4) = 0;
        LFLD(s32, self, 0xa0) = 0x53f;
        LFLD(s32, self, 0xa8) = 0x52;
        LFLD(u16, self, 0x7c) = 0;
        LFLD(u8, self, 0xb29) |= 2;
        func_ov000_02198360(LFLD(void *, self, 0x40), 0x1d, 0);
        LFLD(u16, LFLD(u8 *, self, 0x40), 0) = 0x64;
        return;
    }
    cam = data_ov000_021ccd54 + 0xf4;
    if (LFLD(u16, cam, 0x40) != 0) {
        ang = LFLD(u16, cam, 0x44);
    } else {
        ang = func_0204bfa8(cam);
    }
    ry = LFLD(u16, self, 0x7e);
    if (LFLD(u16, self, 0xb68) & 0x20) {
        ry += 0x280;
    } else if (LFLD(u16, self, 0xb68) & 0x10) {
        ry -= 0x280;
    }
    func_ov000_0218db58(self, ry, ang, 0x1500, 0x400);
    {
        u16 f = LFLD(u16, self, 0xb68);
        u16 base = LFLD(u16, cam, 0x42);
        rx = LFLD(u16, self, 0x7c);
        if (f & 0x40) {
            u16 d;
            rx -= 0x80;
            d = rx - base;
            if (d > 0x8000 && d < 0xea00) {
                rx = base + 0xea00;
            }
        } else if (f & 0x80) {
            u16 d;
            rx += 0x80;
            d = rx - base;
            if (d < 0x8000 && d > 0x600) {
                rx = base + 0x600;
            }
        }
    }
    LFLD(u16, self, 0x7c) = rx;
    if (LFLD(u16, self, 0xb20) != 0xffff) {
        Msg021b2b08 msg;
        msg.pos = LFLD(VecFx32, a, 0x70);
        msg.rot[0] = LFLD(u16, self, 0x7c);
        msg.rot[1] = LFLD(u16, self, 0x7e);
        msg.rot[2] = LFLD(u16, self, 0x80);
        msg.unk_10 = 0;
        func_ov000_0218d398(a, LFLD(u16, self, 0xc), 7, 1, 0x18, &msg);
    }
}
}
