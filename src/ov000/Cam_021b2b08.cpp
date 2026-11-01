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

struct Obj021b2b08 {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0x32];
    void *unk_40;
    u8 unk_44[0x38];
    u16 unk_7c;
    u16 unk_7e;
    u16 unk_80;
    u8 unk_82[0x16];
    u16 unk_98;
    u8 unk_9a[0x2];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0xa74];
    u16 unk_b20;
    u8 unk_b22[0x7];
    u8 unk_b29;
    u8 unk_b2a[0x5];
    u8 unk_b2f;
    u8 unk_b30[0x38];
    u16 unk_b68;
    u16 unk_b6a;
};

void func_ov000_021b2b08(Obj021b2b08 *self) {
    u8 *a = (u8 *)FindActor021b2b08(self->unk_b20);
    void *sub = NULL;
    u8 *cam;
    u16 ang;
    u16 ry;
    u16 rx;
    if (a != NULL) {
        sub = LFLD(void *, a, 0x4c);
    }
    if (self->unk_b2f == 0) {
        self->unk_b2f = 1;
    }
    if (sub == NULL || (self->unk_b6a & 2)) {
        self->unk_98 = self->unk_7e - 0x8000;
        self->unk_9c = 0x114;
        self->unk_a4 = 0;
        self->unk_a0 = 0x53f;
        self->unk_a8 = 0x52;
        self->unk_7c = 0;
        self->unk_b29 |= 2;
        func_ov000_02198360(self->unk_40, 0x1d, 0);
        LFLD(u16, self->unk_40, 0) = 0x64;
        return;
    }
    cam = data_ov000_021ccd54 + 0xf4;
    if (LFLD(u16, cam, 0x40) != 0) {
        ang = LFLD(u16, cam, 0x44);
    } else {
        ang = func_0204bfa8(cam);
    }
    ry = self->unk_7e;
    if (self->unk_b68 & 0x20) {
        ry += 0x280;
    } else if (self->unk_b68 & 0x10) {
        ry -= 0x280;
    }
    func_ov000_0218db58(self, ry, ang, 0x1500, 0x400);
    {
        u16 f = self->unk_b68;
        u16 base = LFLD(u16, cam, 0x42);
        rx = self->unk_7c;
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
    self->unk_7c = rx;
    if (self->unk_b20 != 0xffff) {
        Msg021b2b08 msg;
        msg.pos = LFLD(VecFx32, a, 0x70);
        msg.rot[0] = self->unk_7c;
        msg.rot[1] = self->unk_7e;
        msg.rot[2] = self->unk_80;
        msg.unk_10 = 0;
        func_ov000_0218d398(a, self->unk_0c, 7, 1, 0x18, &msg);
    }
}
}
