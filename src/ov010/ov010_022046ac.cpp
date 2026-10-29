#include "ov010/ov010.h"

struct Ov010CamBits {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
};

struct Ov010Bits16 {
    u16 b0 : 1;
    u16 b1 : 15;
};

struct Ov010CamPreset {
    void *vt;
    Ov010CamBits bits;
    u8 pad[3];
    s32 x;
    s32 y;
    s32 z;
    u16 a;
    u16 b;
    u16 c;
    u16 pad2;
    s32 w;
};

extern "C" {

extern u8 data_ov010_0220ffc4[];
extern u8 data_ov010_0220f160[];
extern u8 data_ov010_0220ff70[];
extern u8 data_ov010_0220f174[];
extern u8 data_ov010_0220f150[];
extern u8 data_ov010_0220f0a0[];
extern void func_ov003_021d112c(void *self);
extern void func_ov003_021cf404(s32 a);
extern void func_ov003_021cf400(s32 a);
extern void *func_0203dd9c(u32 size);
extern void *func_ov010_022092c8(void *p);
extern void *func_ov010_022095a8(void *p);
extern void *func_ov010_02209860(void *p);
extern void *func_ov010_0220a078(void *p);
extern void *func_ov010_0220a2a8(void *p);
extern void *func_ov003_021d8910(void *p);
extern BOOL func_ov003_021d8f4c(void *p);
extern BOOL func_ov010_0220d7f8(void *p);
extern BOOL func_ov003_021d8198(void *p);
extern BOOL func_ov003_021d8c10(void *p);
extern BOOL func_ov003_021d8980(void *p);
extern void func_ov003_021d8a30(void *p, u8 id, void *st);
extern void *func_ov000_0219bf90(void);
extern BOOL func_020621c4(void);
extern void func_ov003_021d6bac(void *self, const void *a);

static inline Ov010CamPreset *Ov010Cam_New(void) {
    Ov010CamPreset *o = (Ov010CamPreset *)func_0203dd9c(0x20);
    if (o != NULL) {
        o->vt = data_ov010_0220ffc4;
        o->bits.b0 = 0;
        o->bits.b1 = 0;
    }
    return o;
}

static inline void Ov010Cam_Set(Ov010CamPreset *o, s32 x, s32 y, s32 z, u16 a, u16 b, s32 w) {
    if (!o->bits.b0) {
        o->bits.b1 = 1;
        o->x = x;
        o->y = y;
        o->z = z;
        o->a = a;
        o->b = b;
        o->c = 0;
        o->w = w;
    }
}

void func_ov010_022046ac(Ov010V *self) {
    void *o;
    u16 *p;
    u32 i;
    func_ov003_021d112c(self);
    func_ov003_021cf404(1);
    func_ov003_021cf400(1);
    FLD(u8, self, 0xf3) = 1;
    o = func_0203dd9c(0x30);
    if (o != NULL) {
        o = func_ov010_022092c8(o);
    }
    FLD(void *, self, 0x104) = o;
    o = func_0203dd9c(0x20);
    if (o != NULL) {
        o = func_ov010_022095a8(o);
    }
    FLD(void *, self, 0x108) = o;
    o = func_0203dd9c(0x34);
    if (o != NULL) {
        o = func_ov010_02209860(o);
    }
    FLD(void *, self, 0x10c) = o;
    o = func_0203dd9c(0xc);
    if (o != NULL) {
        o = func_ov010_0220a078(o);
    }
    FLD(void *, self, 0x110) = o;
    o = func_0203dd9c(0x20);
    if (o != NULL) {
        o = func_ov010_0220a2a8(o);
    }
    FLD(void *, self, 0x114) = o;
    o = func_0203dd9c(0x10);
    if (o != NULL) {
        o = func_ov003_021d8910(o);
    }
    FLD(void *, self, 0x118) = o;
    FLD(Ov010CamPreset *, self, 0x11c) = Ov010Cam_New();
    FLD(Ov010CamPreset *, self, 0x120) = Ov010Cam_New();
    p = (u16 *)func_0203dd9c(6);
    FLD(u16 *, self, 0x124) = p;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    func_ov003_021d8f4c((u8 *)self + 0x160);
    func_ov010_0220d7f8((u8 *)self + 0x174);
    func_ov003_021d8198((u8 *)self + 0x1b0);
    func_ov003_021d8c10((u8 *)self + 0x1dc);
    switch (FLD(u16, self, 0xe)) {
    case 0x5c04:
        FLD(void *, self, 0xf8) = data_ov010_0220f160;
        FLD(s32, self, 0x15c) = 0;
        FLD(void *, self, 0xfc) = data_ov010_0220ff70;
        Ov010Cam_Set(FLD(Ov010CamPreset *, self, 0x11c), 0x1266, -0xcd1f, -0x5ee1, 0x10e8, 0xd87e, 0x10571);
        Ov010Cam_Set(FLD(Ov010CamPreset *, self, 0x120), 0xcd, -0xd19a, -0x3800, 0xde8, 0xff7e, 0x14571);
        break;
    case 0x5c05:
        FLD(void *, self, 0xf8) = data_ov010_0220f174;
        FLD(s32, self, 0x15c) = 1;
        FLD(void *, self, 0x100) = data_ov010_0220f150;
        Ov010Cam_Set(FLD(Ov010CamPreset *, self, 0x11c), -0x20f6, 0x13d7, 0x3c7b, 0x10ce, 0x6c1c, 0x1711f);
        Ov010Cam_Set(FLD(Ov010CamPreset *, self, 0x120), -0xa66, 0x1a14, 0x2214, 0xd73, 0x801c, 0x144f6);
        break;
    }
    self->va4();
    for (i = 0; i < 9; i++) {
        FLD(s32, (u8 *)self + i * 4, 0x12c) = -1;
    }
    self->vac((u8 *)self + 0x12c, 9);
    func_ov003_021d8980(FLD(void *, self, 0x118));
    func_ov003_021d8a30(FLD(void *, self, 0x118), 0, FLD(void *, self, 0x120));
    func_ov003_021d8a30(FLD(void *, self, 0x118), 1, FLD(void *, self, 0x11c));
    FLD(Ov010Bits16, FLD(void *, self, 0x38), 0xc2).b0 = 0;
    FLD(u16, self, 0x90) = FLD(u16, func_ov000_0219bf90(), 0xc);
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov010_0220f0a0);
    }
    func_ov003_021cf400(1);
    FLD(u8, self, 0x15) = 2;
}

}
