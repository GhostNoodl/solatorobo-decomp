#include "types.h"
#include "nitro/fx.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    VecFx32 pos;
    u8 unk_0c[8];
    s16 hx, hy, hz;
    u16 rot;
    u8 unk_1c[8];
} Item021b628c;

typedef struct {
    VecFx32 pos;
    u16 rot;
} Start021b628c;

typedef struct {
    u8 pad_00[0xa];
    u16 unk_0a;
    u16 unk_0c;
    u16 unk_0e;
    u16 unk_10;
    s16 unk_12;
    u8 unk_14;
    u8 unk_15;
} Rect021b628c;

typedef struct {
    u8 pad_00[9];
    u8 unk_09;
    u8 unk_0a;
    u8 unk_0b;
    u8 pad_0c[8];
    Rect021b628c *unk_14;
    u8 pad_18[0xc];
    VecFx32 unk_24;
} Obj021b628c;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 2;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 2;
} Bits021b628c;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 7;
} Bit0_021b628c;

class Cam021b628c {
public:
    virtual void vfunc_00();
};

extern "C" {

extern u8 *data_ov000_021ccd54;
Item021b628c *func_0206e230(Rect021b628c *b);
Start021b628c *func_0206e264(Rect021b628c *b);
BOOL func_02062698(void);
void func_02062724(VecFx32 *pos);
u16 func_02062754(void);
void func_020626c0(void);
BOOL func_020625f8(void);
void func_02062540(VecFx32 *v);
BOOL func_02062620(void);
u16 func_02062588(void);
BOOL func_02062648(void);
u16 func_020625ac(void);
BOOL func_02062670(void);
s32 func_020625d0(void);
u8 *func_ov000_0219bf90(void);
void func_ov000_0219cbf8(u8 *pl, VecFx32 *pos, u16 *rot);
void func_0203d45c(void *q, u16 a, u16 b, u16 c, u16 d);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);

static inline void SetRot021b628c(u16 *r, u16 x, u16 y, u16 z) {
    r[0] = x;
    r[1] = y;
    r[2] = z;
}

class Pl021b628c {
public:
    virtual void vfunc_00();
    virtual void vfunc_04();
    virtual void vfunc_08();
    virtual void vfunc_0c();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
};

void func_ov000_021b628c(Obj021b628c *self) {
    VecFx32 pos;
    VecFx32 t;
    u16 rot[3];
    u8 *cam;
    u8 *pl;
    Rect021b628c *r;
    u8 idx = self->unk_0a;

    self->unk_0b = 0xff;
    self->unk_0a = 0xff;
    self->unk_09 = idx;
    if (idx != 0xff && self->unk_14 != NULL && self->unk_14->unk_14 != 0) {
        Item021b628c *items = func_0206e230(self->unk_14);
        if (items != NULL) {
            Item021b628c *it = &items[self->unk_09];
            pos.x = it->hx << 4;
            pos.y = it->hy << 4;
            pos.z = it->hz << 4;
            VEC_Add(&pos, &it->pos, &pos);
        }
        SetRot021b628c(rot, 0, items[self->unk_09].rot, 0);
    } else if (func_02062698()) {
        func_02062724(&pos);
        SetRot021b628c(rot, 0, func_02062754(), 0);
    } else if (self->unk_14 != NULL && self->unk_14->unk_15 != 0) {
        Start021b628c *st = func_0206e264(self->unk_14);
        if (st != NULL) {
            pos = st->pos;
            SetRot021b628c(rot, 0, st->rot, 0);
        }
    } else {
        pos.x = 0;
        pos.y = 0;
        pos.z = 0;
        SetRot021b628c(rot, 0, 0, 0);
    }
    func_020626c0();
    cam = data_ov000_021ccd54 + 0xf4;
    if (cam != NULL) {
        LFLD(u8, cam, 0xda) = 0;
        LFLD(u16, cam, 0x42) = rot[0];
        LFLD(u16, cam, 0x44) = rot[1];
        LFLD(u16, cam, 0x46) = rot[2];
        LFLD(VecFx32, cam, 0xbc) = pos;
        LFLD(VecFx32, cam, 0x10) = pos;
        t = pos;
        t.x -= FX_SinCosTable_[(rot[1] >> 4) * 2];
        t.z -= FX_SinCosTable_[(rot[1] >> 4) * 2 + 1];
        LFLD(VecFx32, cam, 0x4) = t;
        if (func_020625f8()) {
            func_02062540(&t);
            LFLD(VecFx32, cam, 0xe8) = t;
            LFLD(u8, cam, 0xda) |= 2;
        }
        if (func_02062620()) {
            LFLD(u16, cam, 0xf8) = func_02062588();
            LFLD(u8, cam, 0xda) |= 0x10;
        }
        if (func_02062648()) {
            LFLD(u16, cam, 0xfa) = func_020625ac();
            LFLD(u8, cam, 0xda) |= 0x20;
        }
        if (func_02062670()) {
            LFLD(s32, cam, 0xf4) = func_020625d0();
            LFLD(Bits021b628c, cam, 0xda).b2 = 1;
        }
        LFLD(Bit0_021b628c, cam, 0x9c).b0 = 0;
        ((Cam021b628c *)cam)->vfunc_00();
        LFLD(Bit0_021b628c, cam, 0x9c).b0 = 1;
    }
    pl = func_ov000_0219bf90();
    if (pl == NULL) {
        return;
    }
    func_ov000_0219cbf8(pl, &pos, rot);
    ((Pl021b628c *)pl)->vfunc_18();
    if (LFLD(u8, pl, 0xb2e) < 10) {
        LFLD(u8, pl, 0xb2e) = 10;
    }
    LFLD(u8, pl, 0xb2f) = LFLD(u8, pl, 0xb2e);
    self->unk_24 = pos;
    r = self->unk_14;
    if (r != NULL) {
        func_0203d45c(pl + 0xb70, r->unk_0a, r->unk_0c, r->unk_0e, r->unk_10);
        LFLD(s32, pl, 0xb0c) = self->unk_14->unk_12;
    } else {
        func_0203d45c(pl + 0xb70, 0, 0x4000, 0x8000, 0xc000);
        LFLD(s32, pl, 0xb0c) = 0x1000;
    }
}

}
