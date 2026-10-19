#include "ov000/LoCommon.h"
#include "nitro/fx.h"

typedef struct {
    s32 d;
    VecFx32 pos;
} Arg02154fb0;

extern "C" {

extern void *data_02fe152c;
extern u8 data_ov000_021ccd24[];
extern void *data_02097e4c;
void *func_0205976c(void *a, s32 b);
u32 func_0205975c(void *a, s32 b);
u32 func_ov000_0214bf2c(u16 a);
BOOL func_02059544(void *a, void *b, void *c, s32 d, s32 e);
BOOL func_0205a9c8(void *p);
void func_0204c7d0(void *p);
void *func_ov000_02173610(s32 kind);
void *func_ov000_0219bf90(void *p);
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
} LoBits8;

typedef struct {
    u32 y : 8;
    u32 a : 8;
    u32 x : 9;
    u32 b : 7;
    u32 unk_04;
} LoOam;

static inline BOOL LoIsLoaded24(void) {
    BOOL r = TRUE;
    if (!func_0205a9c8(LFLD(void *, data_ov000_021ccd24, 8))) {
        r = FALSE;
    }
    return r;
}

void func_ov000_02154ec4(void *self) {
    if (!LBIT(self, 0xc).b4) {
        return;
    }
    switch (LFLD(s32, self, 4)) {
    case 0:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    case 1:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    }
}

void func_ov000_02154f34(VObj *self) {
    if (LFLD(s32, self, 4) == 2) {
        LFLD(s32, self, 0x30) = LFLD(s32, self, 0x34);
        LFLD(s32, self, 0x38) = 0x1000;
        self->vfunc_c8();
        self->vfunc_c4();
    }
    self->vfunc_cc();
    self->vfunc_d0();
    self->vfunc_48(2, 0);
}

BOOL func_02054f10(void *p, s32 a);

static inline void VecAdd(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab) {
    ab->x = a->x + b->x;
    ab->y = a->y + b->y;
    ab->z = a->z + b->z;
}

static inline BOOL NoB5(VObj *self) {
    return !LBIT(self, 0xc).b5 ? TRUE : FALSE;
}

void func_ov000_02154fb0(VObj *self, s32 a, VecFx32 *pos, s32 d) {
    Arg02154fb0 arg;
    s32 v;
    if (LFLD(s32, self, 0x44) == 0) {
        arg.d = d;
        arg.pos = *pos;
        v = a;
    } else {
        v = self->vfunc_18(&arg.pos, &arg.d, LO_FX_MUL(a, 0x1000 - LFLD(s32, self, 0x44)));
        {
            VecFx32 ofs;
            ofs.x = LFLD(s16, self, 0x64) << 12;
            ofs.y = LFLD(s16, self, 0x66) << 12;
            ofs.z = 0;
            VecAdd(&arg.pos, &ofs, &arg.pos);
        }
    }
    if (LFLD(u32, self, 0xc) & 0x80000) {
        self->vfunc_d4(v, &arg.pos, arg.d);
    }
    self->vfunc_64(v, &arg.pos, arg.d);
    if (NoB5(self)) {
        self->vfunc_d8(v, &arg.pos, arg.d);
    }
    self->vfunc_e8(v, &arg.pos, arg.d);
    if (!func_02054f10(LFLD(void *, self, 0x10), 0xffff)) {
        return;
    }
    if (LFLD(u32, self, 0xc) & 0x40000) {
        self->vfunc_ec(v, &arg.pos, arg.d);
    }
    self->vfunc_60(a, pos, d);
    LFLD(u32, self, 0xc) |= 0x200;
}

}
