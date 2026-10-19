#include "ov000/LoCommon.h"

typedef struct {
    u16 state;
    u16 timer;
} State021a783c;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 3;
    u32 lock : 2;
    u32 f7 : 2;
    u32 b9 : 1;
    u32 b10 : 2;
    u32 mode : 2;
    u32 b14 : 3;
    u32 b17 : 1;
    u32 rest : 14;
} B24_021a783c;

typedef struct {
    u8 pad_00[0x40];
    u16 unk_40;
    u16 pad_42;
    u16 yaw;
} Cam021a783c;

extern "C" {

extern u8 data_ov000_021cc696[];
extern u8 data_ov000_021cc672[];
extern u8 data_ov000_021ca0a4[];
extern u8 data_ov000_021cc5e3[];
VObj *func_02065f88(s32 id, void *pos);
extern u8 data_ov000_021cc618[];
extern u8 *data_ov000_021ccd54;
extern void *data_ov000_021ccd68;
void func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_02191120(void *a);
void func_ov000_02198360(State021a783c *st, s32 state, s32 x);
void func_ov000_021b1fac(void *self, BOOL a, s32 b);
void func_ov000_021b03c8(void *self);
u8 *func_ov000_0218d240(void *self);
u8 *func_ov000_0218e640(void *mgr, u16 id);
void func_ov000_0218d46c(void *a, u16 id, s32 b);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
u16 func_0204bfa8(Cam021a783c *cam);
u16 FX_Atan2(s32 y, s32 x);

static inline u16 CamYaw(Cam021a783c *cam) {
    if (cam->unk_40 != 0) {
        return cam->yaw;
    }
    return func_0204bfa8(cam);
}

static inline u8 *FindActor021a783c(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline u16 AngleTo(u8 *self, u8 *other) {
    u16 angle;
    if (other == NULL || other == self) {
        angle = LFLD(u16, self, 0x7e);
    } else {
        angle = FX_Atan2(LFLD(s32, other, 0x70) - LFLD(s32, self, 0x70), LFLD(s32, other, 0x78) - LFLD(s32, self, 0x78));
    }
    return angle;
}

typedef struct {
    u8 b0 : 4;
    u8 b4 : 1;
    u8 b5 : 3;
} B93_021a7574;

static inline s32 FxMul64(s64 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void func_ov000_021a7574(u8 *self) {
    switch (LFLD(State021a783c *, self, 0x40)->state) {
    case 0:
        func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc672, 0x800, 0);
        if (LFLD(B24_021a783c, self, 0xb24).lock != 2) {
            u8 *m = LFLD(u8 *, self, 0x38);
            LFLD(void *, m, 0xd8) = data_ov000_021ca0a4;
            LFLD(void *, m, 0xdc) = data_ov000_021ca0a4;
        }
        if (LFLD(s32, self, 0xa0) > 0) {
            LFLD(s32, self, 0xa0) = 0;
        }
        LFLD(s32, self, 0xa4) = 0xccd;
        LFLD(s32, self, 0xa8) = 10;
        LFLD(B24_021a783c, self, 0xb24).f7 = 2;
        LFLD(State021a783c *, self, 0x40)->state++;
        break;
    case 1:
        if (LFLD(s16, LFLD(u8 *, self, 0x38), 0xc4) == 1 || func_ov000_02191120(LFLD(void *, self, 0x38))) {
            if (LFLD(B24_021a783c, self, 0xb24).lock != 0) {
                VObj *e;
                u8 *a = FindActor021a783c(LFLD(u16, self, 0xb1c));
                if (a != NULL) {
                    func_ov000_0218d46c(a, LFLD(u16, self, 0xc), 0xd);
                }
                LFLD(B24_021a783c, self, 0xb24).lock = 0;
                LFLD(u16, self, 0xb1c) = 0xffff;
                LFLD(u16, self, 0xb1e) = 0xffff;
                LFLD(B24_021a783c, self, 0xb24).f7 = LFLD(B24_021a783c, self, 0xb24).b9;
                e = func_02065f88(0xc9, self + 0x70);
                LFLD(void *, self, 0xb48) = LFLD(void *, e, 0x24);
                LFLD(u16, self, 0xb5e) = 0;
                LFLD(s32, self, 0xb4c) = 0;
                LFLD(s32, self, 0xb50) = FxMul64(LFLD(s32, self, 0x68), 0xa66);
                LFLD(s32, self, 0xb54) = 0;
                LFLD(u16, self, 0xb58) = 0xe000;
                LFLD(u16, self, 0xb5a) = 0;
                LFLD(u16, self, 0xb5c) = 0;
                e->vfunc_14(0x2800, 0x2000, 0x2800);
            }
            func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc5e3, 0x155, 0);
            LFLD(s32, self, 0xa8) = 0x52;
            LFLD(State021a783c *, self, 0x40)->state++;
        }
        break;
    case 2: {
        State021a783c *st = LFLD(State021a783c *, self, 0x40);
        s32 lim = 0x10;
        if (LFLD(B93_021a7574, self, 0x93).b4) {
            lim = 8;
        }
        st->timer++;
        if (st->timer > lim) {
            func_ov000_02198360(LFLD(State021a783c *, self, 0x40), 1, 0);
        }
        break;
    }
    }
    func_ov000_021b1fac(self, FALSE, 1);
    if (!LBIT(self, 0xb24).b1) {
        return;
    }
    if (!(LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x400)) {
        return;
    }
    LFLD(u16, self, 0x98) = FX_Atan2(LFLD(s32, self, 0xaf0) - LFLD(s32, self, 0x70),
                                     LFLD(s32, self, 0xaf8) - LFLD(s32, self, 0x78));
    LFLD(s32, self, 0x9c) = 0x66;
    LFLD(s32, self, 0xa4) = 0;
    if (!LBIT(self, 0xb24).b17 || (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x40000000)) {
        LFLD(s32, self, 0xa0) = 0x200;
    }
    LFLD(s32, self, 0xa8) = 0x52;
    LBIT(self, 0xb24).b17 = 1;
}

void func_ov000_021a783c(u8 *self) {
    if (LFLD(B24_021a783c, self, 0xb24).mode == 3) {
        func_ov000_021b03c8(self);
        return;
    }
    switch (LFLD(State021a783c *, self, 0x40)->state) {
    case 0:
        if (LFLD(s32, self, 0xa0) > 0) {
            LFLD(s32, self, 0xa0) = 0;
        }
        LFLD(s32, self, 0xa4) = 0xe66;
        LFLD(s32, self, 0xa8) = 10;
        func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc696, 0x800, 0);
        LFLD(State021a783c *, self, 0x40)->state++;
        break;
    case 1: {
        u16 ang;
        u8 *t = func_ov000_0218d240(self);
        if (t != NULL) {
            ang = AngleTo(self, t);
        } else {
            ang = LFLD(u16, self, 0x7e);
            if (LFLD(u8, self, 0x15) == 1 && (LFLD(u16, self, 0xb68) & 0xf0)) {
                ang = CamYaw((Cam021a783c *)(data_ov000_021ccd54 + 0xf4)) + LFLD(u16, self, 0xb6e);
            }
        }
        LFLD(u16, self, 0x7e) = func_01ffc128(ang, LFLD(u16, self, 0x7e), 0x8cd, 1, 0x8000);
        if (LFLD(B24_021a783c, self, 0xb24).lock != 0 && LFLD(s16, LFLD(u8 *, self, 0x38), 0xc4) == 1) {
            u8 *a = FindActor021a783c(LFLD(u16, self, 0xb1c));
            if (a != NULL) {
                func_ov000_0218d46c(a, LFLD(u16, self, 0xc), 0xe);
            }
            LFLD(State021a783c *, self, 0x40)->state++;
        }
        break;
    }
    case 2:
        if (func_ov000_02191120(LFLD(void *, self, 0x38))) {
            LFLD(s32, self, 0xa8) = 0x52;
            func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc618, 0x19a, 0);
            LFLD(State021a783c *, self, 0x40)->state++;
            LFLD(State021a783c *, self, 0x40)->timer = 0;
        }
        break;
    case 3: {
        State021a783c *st = LFLD(State021a783c *, self, 0x40);
        st->timer++;
        if (st->timer > 20) {
            func_ov000_02198360(LFLD(State021a783c *, self, 0x40), 1, 0);
        }
        break;
    }
    }
    func_ov000_021b1fac(self, FALSE, 1);
    if (!LBIT(self, 0xb24).b1) {
        return;
    }
    if (!(LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x400)) {
        return;
    }
    LFLD(u16, self, 0x98) = FX_Atan2(LFLD(s32, self, 0xaf0) - LFLD(s32, self, 0x70),
                                     LFLD(s32, self, 0xaf8) - LFLD(s32, self, 0x78));
    LFLD(s32, self, 0x9c) = 0x66;
    LFLD(s32, self, 0xa4) = 0;
    if (!LBIT(self, 0xb24).b17 || (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x40000000)) {
        LFLD(s32, self, 0xa0) = 0x200;
    }
    LFLD(s32, self, 0xa8) = 0x52;
    LBIT(self, 0xb24).b17 = 1;
}

}
