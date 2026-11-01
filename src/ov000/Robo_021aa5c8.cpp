#include "ov000/LoCommon.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u8 c[3];
} Rgb021aa5c8;

typedef struct {
    u16 st;
    u8 pad02[0x11];
    u8 kind;
} State021aa5c8;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 rest : 3;
} Bits8021aa5c8;

typedef struct {
    u8 lo : 4;
    u8 hi : 4;
} Nib021aa5c8;

extern "C" {

extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd54;
extern Rgb021aa5c8 data_ov000_021c9fe8;
extern void *data_02097e4c;
u8 *func_ov000_0218e640(void *mgr, u16 id);
VObj *func_02065f88(s32 id, void *pos);
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
void func_ov003_021cedf4(u16 n);
s32 func_02040498(s32 max);
s32 func_02049bdc(void *a, s32 b, s32 c);
void func_ov000_021aa978(u8 *self);
void func_ov000_021aaf80(u8 *self);
void func_ov000_021ab68c(u8 *self);
void func_ov000_0218a358(void *s, VecFx32 *pos, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
BOOL func_ov000_02198360(void *s, s32 a, s32 b);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);

static inline u8 *FindActor021aa5c8(u16 id) {
    void *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(mgr, id);
}

static inline BOOL RgbEq021aa5c8(Rgb021aa5c8 *a, Rgb021aa5c8 b) {
    BOOL r = FALSE;
    if (a->c[0] == b.c[0] && a->c[1] == b.c[1] && a->c[2] == b.c[2]) {
        r = TRUE;
    }
    return r;
}

static inline s32 FxMulL021aa5c8(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

void func_ov000_021aa5c8(Robo021ca458 *self) {
    u8 *actor;
    u8 *sub;
    u8 *g;
    VecFx32 d;
    VecFx32 out;
    actor = FindActor021aa5c8(self->unk_b1c);
    sub = NULL;
    if (actor != NULL) {
        sub = LFLD(u8 *, actor, 0x4c);
    }
    g = data_ov000_021ccd54;
    if (((State021aa5c8 *)self->unk_40)->st == 0) {
        VObj *e = func_02065f88(0x391, (u8 *)self + 0x70);
        e->vfunc_24(0, self->unk_68 - (self->unk_68 >> 2), 0);
        e->vfunc_14(0x159a, 0x159a, 0x159a);
        LFLD(s32, e, 0x3c) = 0x4000;
        LFLD(Bits8021aa5c8, g, 0x190).b2 = 1;
        LFLD(Bits8021aa5c8, g, 0x190).b3 = 1;
        LFLD(Bits8021aa5c8, g, 0x190).b4 = 1;
        LFLD(u8, g, 0x18d) = 8;
        LFLD(u8, g, 0x18e) = 6;
        LFLD(u8, g, 0x18f) = 6;
        func_02049a48(data_02097e4c, 0x44, -1, -1, -1);
        func_02049a48(data_02097e4c, 0x30c, -1, -1, -1);
        if (!self->unk_b22_3) {
            u16 n = 0x14;
            if (sub != NULL) {
                n += (u16)(LFLD(u8, sub, 0x1a) * 2);
            }
            if (self->unk_ba4 != NULL) {
                n += LFLD(Nib021aa5c8, self->unk_ba4, 5).hi;
            }
            func_ov003_021cedf4(n);
        }
        if (RgbEq021aa5c8((Rgb021aa5c8 *)(data_ov000_021ccd54 + 0xca), data_ov000_021c9fe8)) {
            func_02049bdc(data_02097e4c, 0x5e, func_02040498(3));
        }
    }
    if (self->unk_b2c_0) {
        func_ov000_021aa978((u8 *)self);
    } else if (self->unk_b2c_1) {
        func_ov000_021aaf80((u8 *)self);
    } else if (self->unk_b2c_2) {
        func_ov000_021ab68c((u8 *)self);
    }
    if (((State021aa5c8 *)self->unk_40)->st <= 1 && sub != NULL && !(LFLD(Bits8021aa5c8, sub, 0x18).b4 ? TRUE : FALSE)) {
        d = LFLD(VecFx32, actor, 0x70);
        d.x -= self->pos.x;
        d.y -= self->pos.y;
        d.z -= self->pos.z;
        d.x = FxMulL021aa5c8(d.x, 0x733);
        d.y = FxMulL021aa5c8(d.y, 0x733);
        d.z = FxMulL021aa5c8(d.z, 0x733);
        d.y = self->unk_6c;
        VEC_Add(&d, (VecFx32 *)((u8 *)self + 0x70), &out);
        func_ov000_0218a358(g + 0xf4, &out, 0, LFLD(s32, actor, 0x64) + 0x8c00, 1, 0x2333, 0x1000, 1);
    }
    if (((State021aa5c8 *)self->unk_40)->kind != 0x11) {
        return;
    }
    if (self->unk_b2c_0 || self->unk_b2c_1 || self->unk_b2c_2) {
        return;
    }
    func_ov000_02198360(self->unk_40, 1, 0);
}

}
