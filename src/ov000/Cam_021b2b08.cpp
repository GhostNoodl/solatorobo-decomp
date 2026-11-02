#include "ov000/LoCommon.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    VecFx32 pos;
    u16 rot[3];
    u8 pad[2];
    s32 unk_10;
} Msg021b2b08;

extern "C" {
extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd54;
Actor *func_ov000_0218e640(void *mgr, u16 id);
BOOL func_ov000_02198360(void *a, s32 b, s32 c);
u16 func_0204bfa8(void *cam);
void func_ov000_0218db58(void *self, u16 angle, u16 center, u16 range, s32 step);
void func_ov000_0218d398(void *t, u16 id, s32 a, s32 b, s32 c, void *arg);

static inline Actor *FindActor021b2b08(u16 id) {
    void *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(mgr, id);
}

void func_ov000_021b2b08(Robo021ca458 *self) {
    Actor *a = FindActor021b2b08(self->unk_b20);
    void *sub = NULL;
    u8 *cam;
    u16 ang;
    u16 ry;
    u16 rx;
    if (a != NULL) {
        sub = ((void *)a->unk_4c);
    }
    if (self->unk_b2f == 0) {
        self->unk_b2f = 1;
    }
    if (sub == NULL || (self->unk_b6a & 2)) {
        self->unk_98 = self->rot_y - 0x8000;
        self->unk_9c = 0x114;
        self->unk_a4 = 0;
        self->unk_a0 = 0x53f;
        self->unk_a8 = 0x52;
        self->rot_x = 0;
        self->unk_b29 |= 2;
        func_ov000_02198360(((void *)self->unk_40), 0x1d, 0);
        self->unk_40->st = 0x64;
        return;
    }
    cam = data_ov000_021ccd54 + 0xf4;
    if (LFLD(u16, cam, 0x40) != 0) {
        ang = LFLD(u16, cam, 0x44);
    } else {
        ang = func_0204bfa8(cam);
    }
    ry = self->rot_y;
    if (self->unk_b68 & 0x20) {
        ry += 0x280;
    } else if (self->unk_b68 & 0x10) {
        ry -= 0x280;
    }
    func_ov000_0218db58(self, ry, ang, 0x1500, 0x400);
    {
        u16 f = self->unk_b68;
        u16 base = LFLD(u16, cam, 0x42);
        rx = self->rot_x;
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
    self->rot_x = rx;
    if (self->unk_b20 != 0xffff) {
        Msg021b2b08 msg;
        msg.pos = a->pos;
        msg.rot[0] = self->rot_x;
        msg.rot[1] = self->rot_y;
        msg.rot[2] = self->rot_z;
        msg.unk_10 = 0;
        func_ov000_0218d398(a, self->id, 7, 1, 0x18, &msg);
    }
}
}
