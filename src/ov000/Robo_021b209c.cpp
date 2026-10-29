#include "nitro/fx.h"
#include "ov000/VObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    s16 speed;
    u8 pad02[6];
    u16 rx;
    u16 ry;
    u16 rz;
    u16 mode;
    s16 se0;
    s16 se0arg;
    s16 se1;
    s16 se1arg;
} Hang_021b209c;

typedef struct {
    VecFx32 pos;
    u16 rx;
    u16 ry;
    u16 rz;
    s32 unk;
} Pose_021b209c;

typedef struct {
    u16 a;
    u8 b;
    u16 c;
} Arg_021b209c;

typedef struct {
    u8 pad[0xc];
    s32 tx;
    u8 pad10[4];
    s32 tz;
    u8 pad18[0x14];
    u32 keys;
} Pad_021b209c;

typedef struct {
    u32 b0 : 12;
    u32 b12 : 2;
    u32 rest : 18;
} B24_021b209c;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} B29_021b209c;

class Eff_021b209c {
public:
    virtual s32 v00(...);
    virtual s32 v04(...);
    virtual s32 v08(...);
    virtual s32 v0c(...);
    virtual s32 v10(...);
    virtual s32 v14(...);
    virtual s32 v18(...);
    virtual s32 v1c(...);
    virtual s32 v20(...);
    virtual s32 v24(...);
    virtual s32 v28(...);
    virtual s32 v2c(...);
    virtual s32 v30(...);
    virtual s32 v34(...);
};

extern "C" {
extern u8 *data_ov000_021ccd68;
extern Hang_021b209c data_ov000_021ca320[];
extern Pad_021b209c data_02fe0f14;
extern void *data_02097e4c;
u8 *func_ov000_0218e640(void *mgr, u16 id);
s32 func_01ffbd6c(VecFx32 *a, VecFx32 *b, u32 mask, s32 c, s32 d, s32 e);
u16 FX_Atan2(s32 x, s32 z);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
void func_ov000_0218d398(void *a, u16 id, s32 b, s32 c, s32 d, void *e);
void *func_02049f44(void *snd, s32 id, void *pos, s32 a);
void func_ov000_0218996c(s32 a, s32 b);
BOOL func_ov000_0219aae8(void *a, void *b, s32 c, s32 d, s32 e, VecFx32 *f, void *g, s32 h, s32 i, s32 j, s32 k);
void func_ov000_0218dbe0(void *self, s32 a);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
s32 func_02049afc(void *snd, s32 se);
void func_0204a0d4(void *snd, s32 h, s32 arg);
void func_02049bb4(void *snd, s32 h);
Eff_021b209c *func_02065f88(s32 id, void *pos);
void func_ov000_0218d46c(void *a, u16 id, s32 b);
BOOL func_ov000_02198360(void *a, s32 b, s32 c);

static inline u8 *FindActor_021b209c(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline s32 Mul_021b209c(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void func_ov000_021b209c(u8 *self) {
    BOOL grab = FALSE;
    u8 ok = FALSE;
    Hang_021b209c *info;
    s32 ret;
    u8 *actor;
    u8 *sub;
    VecFx32 from;
    VecFx32 to;
    VecFx32 v;
    Pose_021b209c p;
    Arg_021b209c arg;

    actor = FindActor_021b209c(LFLD(u16, self, 0xb20));
    sub = NULL;
    if (actor != NULL) {
        sub = LFLD(u8 *, actor, 0x4c);
    }
    info = NULL;
    if (sub != NULL) {
        info = &data_ov000_021ca320[LFLD(u16, sub, 6)];
    }
    if (info == NULL) {
        return;
    }
    from = LFLD(VecFx32, self, 0x70);
    from.y += LFLD(s32, self, 0x68);
    to = from;
    to.x += Mul_021b209c(FX_SinCosTable_[((u16)(LFLD(u16, self, 0x98) + 0x1200) >> 4) * 2], 0x2333);
    to.z += Mul_021b209c(FX_SinCosTable_[((u16)(LFLD(u16, self, 0x98) + 0x1200) >> 4) * 2 + 1], 0x2333);
    ret = func_01ffbd6c(&from, &to, 0x40000000, 0, 0, -1);
    if (ret == -0x1000) {
        to = from;
        to.x += Mul_021b209c(FX_SinCosTable_[((u16)(LFLD(u16, self, 0x98) - 0x1200) >> 4) * 2], 0x2333);
        to.z += Mul_021b209c(FX_SinCosTable_[((u16)(LFLD(u16, self, 0x98) - 0x1200) >> 4) * 2 + 1], 0x2333);
        ret = func_01ffbd6c(&from, &to, 0x40000000, 0, 0, -1);
    }
    if (ret != -0x1000) {
        if (data_02fe0f14.keys & 0x200) {
            grab = TRUE;
            if (info->mode == 1) {
                ok = TRUE;
            }
        } else {
            ok = TRUE;
        }
        if (ok) {
            u16 ang = FX_Atan2(data_02fe0f14.tx, data_02fe0f14.tz);
            if ((u16)(ang - LFLD(u16, self, 0x98)) < 0x8000) {
                LFLD(u16, self, 0x98) = ang - 0x4000;
            } else {
                LFLD(u16, self, 0x98) = ang + 0x4000;
            }
        }
    }
    if (grab) {
        LFLD(s32, self, 0x9c) = 0;
    } else {
        s32 spd = info->speed;
        if (LFLD(s32, self, 0x9c) != 0) {
            s32 d = (spd - LFLD(s32, self, 0x9c)) >> 3;
            if (d == 0) {
                LFLD(s32, self, 0x9c) = spd;
            }
            LFLD(s32, self, 0x9c) += d;
        } else {
            LFLD(s32, self, 0x9c) = spd;
        }
        LFLD(s32, self, 0xa8) = 0x52;
        if (!(LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x20000000)) {
            LFLD(s32, self, 0xa8) += 0x52;
        }
        LFLD(u16, self, 0x7e) = func_01ffc128(LFLD(u16, self, 0x98), LFLD(u16, self, 0x7e), 0x400, 1, 0x8000);
        if (LFLD(s32, LFLD(u8 *, self, 0x48), 0x58) != 0) {
            LFLD(s32, self, 0x9c) >>= 4;
            LFLD(s32, self, 0xa0) = 0x200;
            arg.c = 0xffff;
            arg.a = 0xa;
            arg.b = 1;
            func_ov000_0218d398(self, LFLD(u16, self, 0xc), 9, 0, 6, &arg);
            func_02049f44(data_02097e4c, 0x309, self + 0x70, 0);
            func_ov000_0218996c(0xa, 0xf);
            v.y = LFLD(s32, self, 0x6c);
            v.x = 0;
            v.z = 0;
            func_ov000_0219aae8(self, self, 0xa, 0, 0x30, &v, 0, LFLD(s32, self, 0x64) + 0xccd, 0, -1, 0x1000);
        }
    }
    LFLD(s32, self, 0xa4) = 0;
    func_ov000_0218dbe0(self, 0);
    func_ov000_021987b8(LFLD(void *, self, 0x48), 1, 0, 0);
    {
        u8 *body = LFLD(u8 *, self, 0x48);
        if (LFLD(u32, body, 0x50) & 0x20000000) {
            if (LFLD(s32, self, 0xa0) <= 0) {
                LFLD(s32, self, 0xa0) = -0x800;
                LFLD(u16, body, 0x9a) |= 0x20;
                if (info->se0 >= 0 && LFLD(s16, self, 0xb64) < 0) {
                    LFLD(s16, self, 0xb64) = func_02049afc(data_02097e4c, info->se0);
                    func_0204a0d4(data_02097e4c, LFLD(s16, self, 0xb64), info->se0arg);
                }
                if (info->se1 >= 0 && LFLD(s16, self, 0xb66) < 0) {
                    LFLD(s16, self, 0xb66) = func_02049afc(data_02097e4c, info->se1);
                    func_0204a0d4(data_02097e4c, LFLD(s16, self, 0xb66), info->se1arg);
                }
            }
            if ((LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x400) && (LFLD(u16, data_ov000_021ccd68, 0xa) & 0x1f)) {
                func_02065f88(0x2bd, self + 0x70);
            }
        } else {
            if (LFLD(s16, self, 0xb64) >= 0) {
                func_02049bb4(data_02097e4c, LFLD(s16, self, 0xb64));
                LFLD(s16, self, 0xb64) = -1;
            }
            if (LFLD(s16, self, 0xb66) >= 0) {
                func_02049bb4(data_02097e4c, LFLD(s16, self, 0xb66));
                LFLD(s16, self, 0xb66) = -1;
            }
        }
    }
    if (LFLD(u16, self, 0xb20) != 0xffff) {
        p.pos = LFLD(VecFx32, self, 0x70);
        p.rx = LFLD(u16, self, 0x7c);
        p.ry = LFLD(u16, self, 0x7e);
        p.rz = LFLD(u16, self, 0x80);
        p.rx += info->rx;
        p.ry += info->ry;
        p.rz += info->rz;
        p.unk = 0;
        if (grab && info->mode != 2) {
            p.ry += 0x8000;
        }
        func_ov000_0218d398(actor, LFLD(u16, self, 0xc), 7, 1, 0x18, &p);
    }
    if (!grab) {
        return;
    }
    if (LFLD(B24_021b209c, self, 0xb24).b12 == 1 && !(LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000)) {
        return;
    }
    if (info->mode == 2) {
        func_ov000_0218d46c(actor, LFLD(u16, self, 0xc), 0xa);
    }
    if (info->mode == 3) {
        LFLD(s32, self, 0x9c) = info->speed;
        LFLD(s32, self, 0xa0) = 0x200;
    } else {
        LFLD(s32, self, 0x9c) = Mul_021b209c(info->speed, 0x59a);
        if (LFLD(s32, self, 0x9c) < 0x229) {
            LFLD(s32, self, 0x9c) = 0x229;
        }
        LFLD(s32, self, 0xa0) = 0x53f;
    }
    LFLD(s32, self, 0xa4) = 0;
    LFLD(s32, self, 0xa8) = 0x52;
    if (LFLD(B24_021b209c, self, 0xb24).b12 == 1) {
        Eff_021b209c *e = func_02065f88(0x6d, self + 0x70);
        e->v0c(0xccd);
        e->v34(0x2000, 0, 0);
    }
    if (LFLD(s16, self, 0xb64) >= 0) {
        func_02049bb4(data_02097e4c, LFLD(s16, self, 0xb64));
        LFLD(s16, self, 0xb64) = -1;
    }
    if (LFLD(s16, self, 0xb66) >= 0) {
        func_02049bb4(data_02097e4c, LFLD(s16, self, 0xb66));
        LFLD(s16, self, 0xb66) = -1;
    }
    LFLD(B29_021b209c, self, 0xb29).b1 = 1;
    func_ov000_02198360(LFLD(void *, self, 0x40), 0x1d, 0);
    LFLD(u16, LFLD(u8 *, self, 0x40), 0) = 0x64;
}
}
