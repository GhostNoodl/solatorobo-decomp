#include "nitro/fx.h"
#include "ov000/VObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define SC(r) FX_SinCosTable_[((r) >> 4) * 2], FX_SinCosTable_[((r) >> 4) * 2 + 1]

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 1;
    u16 rest : 9;
} B16_02195848;

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} B8_02195848;

typedef struct {
    u16 b0 : 3;
    u16 rest : 13;
} K_02195848;

extern "C" {
extern u8 *data_ov000_021ccd54;
extern void *data_ov000_021ccd64;
extern u8 data_ov000_021cc456[];
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void *func_ov003_021f0868(void *a, s32 r, s32 h);
void func_ov000_02199b88(void *body, void *p);
BOOL func_ov000_02198360(void *p, s32 a, s32 b);
void func_ov000_0218bed8(void *a, s32 b, void *c);
void func_0203f324(void *p);
void func_0203f364(void *p);
void func_ov000_021987b8(void *p, s32 a, s32 b, s32 c);
void func_0203f9dc(void *p, MtxFx43 *m);

static inline BOOL PlayerIdle02195848(void) {
    u8 *pl = data_ov000_021ccd54;
    if (pl != NULL) {
        if (LFLD(s32, pl, 0x90) != LFLD(s32, pl, 0x94) ? TRUE : FALSE) {
            return FALSE;
        }
        if (LFLD(s32, pl, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline void RotZYX02195848(MtxFx43 *m, MtxFx43 *tp, u16 rx, u16 ry, u16 rz) {
    BOOL any = FALSE;
    MTX_Identity43_(m);
    if (rz != 0) {
        MTX_RotZ43_(m, SC(rz));
        any = TRUE;
    }
    if (ry != 0) {
        if (any) {
            MTX_RotY43_(tp, SC(ry));
            MTX_Concat43(tp, m, m);
        } else {
            MTX_RotY43_(m, SC(ry));
            any = TRUE;
        }
    }
    if (rx != 0) {
        if (any) {
            MTX_RotX43_(tp, SC(rx));
            MTX_Concat43(tp, m, m);
        } else {
            MTX_RotX43_(m, SC(rx));
        }
    }
}

void func_ov000_02195848(VObj *obj) {
    u8 *self = (u8 *)obj;
    MtxFx43 t;
    MtxFx43 m;
    u8 *h;

    h = LFLD(u8 *, self, 0x48);
    if (h != NULL) {
        LFLD(B16_02195848, h, 0x9a).b6 = 0;
    }
    switch (LFLD(u16, LFLD(u8 *, self, 0x40), 0)) {
    case 0:
        if (LFLD(void *, self, 0x38) != NULL) {
            func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc456, 0x1000, 0);
            func_ov000_021915a0(LFLD(void *, self, 0x38));
        }
        LFLD(u16, LFLD(u8 *, self, 0x40), 0)++;
        LFLD(s32, self, 0x9c) = 0;
        LFLD(s32, self, 0xa0) = 0;
        LFLD(s32, self, 0xa4) = 0;
        LFLD(s32, self, 0xa8) = 0;
        LFLD(u16, self, 0xcc) |= 2;
        break;
    case 1:
        if (LFLD(u8 *, self, 0x4c) != NULL && LFLD(u8, LFLD(u8 *, self, 0x4c), 0) == 2) {
            void *r = func_ov003_021f0868(self + 0x70, LFLD(s32, self, 0x64), LFLD(s32, self, 0x68));
            if (r != NULL) {
                func_ov000_02199b88(LFLD(void *, self, 0x4c), r);
                func_ov000_02198360(LFLD(void *, self, 0x40), 0xd, 0);
                break;
            }
        }
        if (LFLD(u16, self, 0x20) == 0xffff && LFLD(B16_02195848, self, 0xcc).b4) {
            if (PlayerIdle02195848()) {
                u8 *st = LFLD(u8 *, self, 0x40);
                LFLD(u16, st, 2)++;
                if ((s32)LFLD(u16, st, 2) > 0x1fe) {
                    if ((s32)LFLD(u16, st, 2) > 0x258) {
                        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
                        obj->vfunc_08();
                        break;
                    }
                    if (LFLD(u8 *, self, 0x38) != NULL) {
                        if ((LFLD(u16, st, 2) & 7) > 2) {
                            LFLD(u8, LFLD(u8 *, self, 0x38), 0xbe) = 10;
                        } else {
                            LFLD(u8, LFLD(u8 *, self, 0x38), 0xbe) = 0x1f;
                        }
                    }
                }
            } else if (LFLD(u8 *, self, 0x38) != NULL) {
                LFLD(u8, LFLD(u8 *, self, 0x38), 0xbe) = 0x1f;
            }
        }
        if ((LFLD(u32, self, 0x30) & 0x80) && (h = LFLD(u8 *, self, 0x48)) != NULL) {
            LFLD(B16_02195848, h, 0x9a).b0 = 1;
            LFLD(u16, h, 0x9a) |= 8;
            func_0203f324(h);
            func_ov000_021987b8(LFLD(void *, self, 0x48), 0, 0, 0);
        }
        break;
    }
    if (LFLD(void *, self, 0x58) != NULL && (LFLD(B16_02195848, self, 0xcc).b1 || (LFLD(u32, self, 0x30) & 0x80))) {
        void *p;
        u16 rx;
        u16 ry;
        u16 rz;
        LFLD(B16_02195848, self, 0xcc).b0 = 1;
        rz = LFLD(u16, self, 0x80);
        p = LFLD(void *, self, 0x58);
        ry = LFLD(u16, self, 0x7e);
        rx = LFLD(u16, self, 0x7c);
        RotZYX02195848(&m, &t, rx, ry, rz);
        m._30 = LFLD(s32, self, 0x70);
        m._31 = LFLD(s32, self, 0x74);
        m._32 = LFLD(s32, self, 0x78);
        func_0203f9dc(p, &m);
    }
    h = LFLD(u8 *, self, 0x48);
    if (h == NULL) {
        return;
    }
    {
        s32 k = LFLD(K_02195848, LFLD(u8 *, self, 0xb0), 2).b0;
        if (k == 3) {
            return;
        }
        if (LFLD(void *, self, 0x58) != NULL && LFLD(B16_02195848, self, 0xcc).b0 && k != 1) {
            LFLD(B16_02195848, h, 0x9a).b3 = 0;
            func_0203f364(h);
        }
    }
    if (!LFLD(B16_02195848, self, 0xcc).b1) {
        LFLD(B16_02195848, LFLD(u8 *, self, 0x48), 0x9a).b4 = 0;
        LFLD(B8_02195848, self, 0x93).b0 = 1;
        return;
    }
    LFLD(u16, LFLD(u8 *, self, 0x48), 0x9a) |= 0x20;
    if (!(LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000)) {
        if (PlayerIdle02195848()) {
            func_ov000_02198360(LFLD(void *, self, 0x40), 4, 0);
        }
        return;
    }
    if (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x40000) {
        return;
    }
    if (!PlayerIdle02195848()) {
        return;
    }
    LFLD(B16_02195848, self, 0xcc).b1 = 0;
    LFLD(B16_02195848, LFLD(u8 *, self, 0x48), 0x9a).b4 = 0;
}
}
