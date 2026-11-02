#include "types.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "nitro/fx.h"

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

class Cam021b628c {
public:
    virtual void vfunc_00();
};

extern "C" {

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
Robo021ca458 *func_ov000_0219bf90(void);
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
    FieldCam *cam;
    Robo021ca458 *pl;
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
    cam = &data_ov000_021ccd54->cam;
    if (cam != NULL) {
        cam->unk_da = 0;
        cam->base.pitch = rot[0];
        cam->base.yaw = rot[1];
        cam->base.roll = rot[2];
        cam->unk_bc = pos;
        cam->base.at = pos;
        t = pos;
        t.x -= FX_SinCosTable_[(rot[1] >> 4) * 2];
        t.z -= FX_SinCosTable_[(rot[1] >> 4) * 2 + 1];
        cam->base.eye = t;
        if (func_020625f8()) {
            func_02062540(&t);
            cam->unk_e8 = t;
            cam->unk_da_1 = 1;
        }
        if (func_02062620()) {
            cam->unk_f8 = func_02062588();
            cam->unk_da_4 = 1;
        }
        if (func_02062648()) {
            cam->unk_fa = func_020625ac();
            cam->unk_da_5 = 1;
        }
        if (func_02062670()) {
            cam->unk_f4 = func_020625d0();
            cam->unk_da_2 = 1;
        }
        cam->base.smooth = 0;
        ((Cam021b628c *)cam)->vfunc_00();
        cam->base.smooth = 1;
    }
    pl = func_ov000_0219bf90();
    if (pl == NULL) {
        return;
    }
    func_ov000_0219cbf8((u8 *)pl, &pos, rot);
    ((Pl021b628c *)pl)->vfunc_18();
    if (pl->unk_b2e < 10) {
        pl->unk_b2e = 10;
    }
    pl->unk_b2f = pl->unk_b2e;
    self->unk_24 = pos;
    r = self->unk_14;
    if (r != NULL) {
        func_0203d45c((u8 *)pl + 0xb70, r->unk_0a, r->unk_0c, r->unk_0e, r->unk_10);
        pl->unk_b0c = self->unk_14->unk_12;
    } else {
        func_0203d45c((u8 *)pl + 0xb70, 0, 0x4000, 0x8000, 0xc000);
        pl->unk_b0c = 0x1000;
    }
}

}
