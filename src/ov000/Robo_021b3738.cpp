#include "nitro/fx.h"
#include "ov000/VObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define SC(r) FX_SinCosTable_[((r) >> 4) * 2], FX_SinCosTable_[((r) >> 4) * 2 + 1]

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 2;
    u32 b4 : 1;
    u32 b5 : 7;
    u32 b12 : 2;
    u32 rest : 18;
} Bits24_021b3738;

typedef struct {
    u16 b0 : 4;
    u16 b4 : 1;
    u16 rest : 11;
} Bits22_021b3738;

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} Bits94_021b3738;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
} Flags_021b3738;

extern "C" {
extern u8 *data_ov000_021ccd68;
VObj *func_ov000_021985c0(void *hit);
void func_ov000_0219a210(VecFx32 *pos, const VecFx32 *ofs, s32 angle);
BOOL func_ov000_0219b3b4(void *p);
BOOL func_ov000_021bd314(void *p, s32 x);
void func_ov000_021bd438(void *p, VecFx32 *v, s32 dy);
void func_ov000_021bd624(void *p);
void *func_ov000_0218e640(void *mgr, u16 id);

static inline void RotYXZ_021b3738(MtxFx33 *m, const u16 *rot) {
    MtxFx33 t;
    u16 rx;
    u16 ry;
    u16 rz;
    BOOL any = FALSE;
    ry = rot[1];
    rz = rot[2];
    rx = rot[0];
    MTX_Identity33_(m);
    if (ry != 0) {
        MTX_RotY33_(m, SC(ry));
        any = TRUE;
    }
    if (rx != 0) {
        if (any) {
            MTX_RotX33_(&t, SC(rx));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotX33_(m, SC(rx));
            any = TRUE;
        }
    }
    if (rz != 0) {
        if (any) {
            MTX_RotZ33_(&t, SC(rz));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotZ33_(m, SC(rz));
        }
    }
}

static inline s32 State_021b3738(VObj *a) {
    u8 *s = LFLD(u8 *, a, 0x40);
    return s != NULL ? s[0x13] : 0;
}

static inline BOOL IsB1_021b3738(void *p) {
    return LFLD(Flags_021b3738, p, 0).b1 == 1 ? TRUE : FALSE;
}

static inline BOOL IsLocked_021b3738(void *p) {
    return IsB1_021b3738(p) ? TRUE : FALSE;
}

void func_ov000_021b3738(VObj *self, u8 *hit) {
    VecFx32 pos;
    VecFx32 ofs;
    MtxFx33 m;
    s32 r;
    if (hit != NULL && (LFLD(u8, LFLD(u8 *, self, 0x40), 0x13) != 0x18 || LFLD(u16, self, 0xb1e) == 0xffff)) {
        VObj *a = func_ov000_021985c0(hit);
        BOOL flag;
        u8 *e;
        pos = *(VecFx32 *)hit;
        if (LFLD(Bits22_021b3738, hit, 0x22).b4) {
            ofs.z = LFLD(s32, hit, 0x1c);
            ofs.x = 0;
            ofs.y = 0;
            func_ov000_0219a210(&pos, &ofs, LFLD(u16, a, 0x7e));
        }
        r = LFLD(s32, hit, 0x10);
        if (r == 0) {
            r = LFLD(s32, hit, 0x1c);
        }
        r += 0x400;
        if (State_021b3738(a) == 0x13 || State_021b3738(a) == 0x14 || LFLD(Bits94_021b3738, a, 0x94).b0) {
            r >>= 2;
        }
        e = LFLD(u8 *, a, 0x4c);
        flag = TRUE;
        if (e != NULL) {
            u8 k = e[0];
            if ((u8)(k + 0xfa) <= 5) {
                flag = FALSE;
            } else if (!LFLD(Bits24_021b3738, self, 0xb24).b1) {
                if (k == 2 || k == 3 || k == 4 || k == 5 || ((u8)(k + 0xf2) <= 1 && e[2] == 1) || func_ov000_0219b3b4(e) || (u16)(LFLD(u16, a, 0xe) & 0xf000) == 0x5000) {
                    flag = FALSE;
                }
            }
        }
        func_ov000_021bd314(LFLD(void *, self, 0x5c), 0);
        if (LFLD(s32, LFLD(void *, self, 0x5c), 0x44) == 0) {
            LFLD(s32, LFLD(void *, self, 0x5c), 0x98) = flag;
        } else {
            LFLD(s32, LFLD(void *, self, 0x5c), 0x28) = flag;
        }
        LFLD(u32, LFLD(void *, self, 0x5c), 0) |= 2;
    } else if (LFLD(Bits24_021b3738, self, 0xb24).b12 == 3) {
        u16 id = LFLD(u16, self, 0xb20);
        u8 *o = data_ov000_021ccd68 == NULL ? NULL : (u8 *)func_ov000_0218e640(data_ov000_021ccd68, id);
        if (o == NULL) {
            goto end;
        }
        if (LFLD(u16, LFLD(u8 *, o, 0x4c), 0x1e) == 0) {
            func_ov000_021bd314(LFLD(void *, self, 0x5c), 5);
            pos = LFLD(VecFx32, self, 0x70);
            r = LFLD(s32, self, 0x68);
        } else {
            s32 h = LFLD(s16, o, 0x1e);
            s32 d = 0x14000;
            if (h != 0) {
                d = h << 4;
            }
            r = 0;
            RotYXZ_021b3738(&m, (u16 *)((u8 *)self + 0x7c));
            pos.x = 0;
            pos.y = 0x1000;
            pos.z = d;
            MTX_MultVec33(&pos, &m, &pos);
            VEC_Add(&pos, (VecFx32 *)((u8 *)self + 0x70), &pos);
            func_ov000_021bd314(LFLD(void *, self, 0x5c), 2);
        }
        LFLD(u32, LFLD(void *, self, 0x5c), 0) |= 2;
    } else {
        pos = LFLD(VecFx32, self, 0x70);
        r = LFLD(s32, self, 0x6c);
        LFLD(u32, LFLD(void *, self, 0x5c), 0) &= ~2;
        func_ov000_021bd438(LFLD(void *, self, 0x5c), (VecFx32 *)((u8 *)self + 0x70), 0);
    }
end:
    LFLD(s32, LFLD(void *, self, 0x5c), 0x5c) = r;
    LFLD(VecFx32, LFLD(void *, self, 0x5c), 0x50) = pos;
    func_ov000_021bd624(LFLD(void *, self, 0x5c));
    if (LFLD(Bits24_021b3738, self, 0xb24).b4 && !IsLocked_021b3738(LFLD(void *, self, 0x5c)) && (LFLD(u16, data_ov000_021ccd68, 0xa) & 0x3f) < 0x2c) {
        LFLD(u32, LFLD(void *, self, 0x9b0), 0) |= 2;
    } else {
        LFLD(u32, LFLD(void *, self, 0x9b0), 0) &= ~2;
    }
    LFLD(VecFx32, LFLD(void *, self, 0x9b0), 0x50) = LFLD(VecFx32, self, 0x75c);
    func_ov000_021bd624(LFLD(void *, self, 0x9b0));
}
}
