#include "ov000/VObj.h"

typedef struct {
    u32 bit0 : 1;
    u32 bits1 : 11;
    u32 bits12 : 2;
    u32 bits14 : 2;
    u32 bit16 : 1;
    u32 bit17 : 1;
    u32 bit18 : 1;
    u32 rest : 13;
} RoboFlags;

typedef struct {
    u8 pad_00[0x50];
    u32 unk_50;
    u8 pad_54[4];
    s32 unk_58;
    u8 pad_5c[0x28];
    s32 unk_84;
} Body021b468c;

typedef struct {
    u8 pad_00[0x48];
    Body021b468c *unk_48;
    u8 pad_4c[0x4c];
    u16 unk_98;
    u8 pad_9a[2];
    s32 unk_9c;
    s32 unk_a0;
    u8 pad_a4[0xb24 - 0xa4];
    RoboFlags flags;
} Robo021b468c;

typedef struct {
    u32 bits0 : 7;
    u32 bit7 : 1;
    u32 rest : 24;
} Flags021b4774;

typedef struct {
    u8 pad_00[0xc];
    Flags021b4774 unk_0c;
} Part021b4774;

typedef struct {
    u8 pad_00[0x58];
    Part021b4774 *unk_58;
} Obj021b4774;

typedef struct {
    u8 pad_00[0x11c];
    Obj021b4774 *unk_11c;
} Data021ccd30;

typedef struct {
    u8 pad_00[0xc2];
    u16 unk_c2_0 : 1;
    u16 unk_c2_1 : 15;
} Model021b4774;

typedef struct {
    u8 pad_00[0x19];
    u8 unk_19;
} Anim021b4774;

typedef struct {
    u8 pad_00[0x38];
    Model021b4774 *unk_38;
    Anim021b4774 *unk_3c;
    void *unk_40;
    u8 pad_44[0xc];
    u16 *unk_50;
    u8 pad_54[0xb24 - 0x54];
    RoboFlags flags;
} Robo021b4774;

extern "C" {

extern char data_ov000_021cc5e3[];
extern Data021ccd30 *data_ov000_021ccd30;
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_021697dc(Part021b4774 *p, u16 a, u16 b);
BOOL func_ov000_02198360(void *a, s32 b, s32 c);

u16 func_ov000_02198da8(Body021b468c *body, u16 angle);

BOOL func_ov000_021b468c(Robo021b468c *self) {
    BOOL r = FALSE;
    if (self->flags.bits12 == 0) {
        Body021b468c *body = self->unk_48;
        if ((body->unk_50 & 0x40000000) || body->unk_58 != 0) {
            if (!self->flags.bit18) {
                self->unk_98 = func_ov000_02198da8(body, self->unk_98);
                self->unk_9c = 0x8a;
                if (self->unk_48->unk_84 > 0x400 || self->unk_48->unk_58 != 0) {
                    self->unk_9c = 0x229;
                    if (self->unk_a0 < -0xcd) {
                        self->unk_a0 = -0xcd;
                    }
                }
            }
            self->flags.bit16 = 1;
            r = TRUE;
        }
    }
    return r;
}

extern void *data_0214a424;
u8 func_0206d204(void *p, s32 a);

BOOL func_ov000_021b4738(void *self) {
    BOOL r = FALSE;
    s32 x = func_0206d204(data_0214a424, 0);
    if (**(u16 **)((u8 *)self + 0x50) == 0 && x == 0) {
        r = TRUE;
    }
    return r;
}

void func_ov000_021b4774(Robo021b4774 *self) {
    u16 *p;
    u16 v;
    Obj021b4774 *o;

    func_ov000_02190cb0(self->unk_38, data_ov000_021cc5e3, 0x400, 0);
    self->flags.bit0 = 0;
    p = self->unk_50;
    v = p[1];
    p[0] = v;
    o = data_ov000_021ccd30->unk_11c;
    if (o != NULL && o->unk_58 != NULL) {
        o->unk_58->unk_0c.bit7 = 0;
        func_ov000_021697dc(o->unk_58, v, v);
        o->unk_58->unk_0c.bit7 = 1;
    }
    self->unk_38->unk_c2_0 = 1;
    self->unk_3c->unk_19 = 0xff;
    func_ov000_02198360(self->unk_40, 1, 0);
}

}
