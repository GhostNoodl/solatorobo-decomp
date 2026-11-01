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

struct Obj02195848 {
    u8 unk_00[0x20];
    u16 unk_20;
    u8 unk_22[0xe];
    u32 unk_30;
    u8 unk_34[0x4];
    u8 *unk_38;
    u8 unk_3c[0x4];
    u8 *unk_40;
    u8 unk_44[0x4];
    u8 *unk_48;
    u8 *unk_4c;
    u8 unk_50[0x8];
    void *unk_58;
    u8 unk_5c[0x8];
    s32 unk_64;
    s32 unk_68;
    u8 unk_6c[0x4];
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    u16 unk_7c;
    u16 unk_7e;
    u16 unk_80;
    u8 unk_82[0x11];
    B8_02195848 unk_93;
    u8 unk_94[0x8];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0x4];
    u8 *unk_b0;
    u8 unk_b4[0x18];
    B16_02195848 unk_cc;
};

void func_ov000_02195848(VObj *obj) {
    Obj02195848 *self = (Obj02195848 *)obj;
    MtxFx43 t;
    MtxFx43 m;
    u8 *h;

    h = self->unk_48;
    if (h != NULL) {
        LFLD(B16_02195848, h, 0x9a).b6 = 0;
    }
    switch (LFLD(u16, self->unk_40, 0)) {
    case 0:
        if ((void *)self->unk_38 != NULL) {
            func_ov000_02190cb0(self->unk_38, data_ov000_021cc456, 0x1000, 0);
            func_ov000_021915a0(self->unk_38);
        }
        LFLD(u16, self->unk_40, 0)++;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        LFLD(u16, self, 0xcc) |= 2;
        break;
    case 1:
        if (self->unk_4c != NULL && LFLD(u8, self->unk_4c, 0) == 2) {
            void *r = func_ov003_021f0868((u8 *)self + 0x70, self->unk_64, self->unk_68);
            if (r != NULL) {
                func_ov000_02199b88(self->unk_4c, r);
                func_ov000_02198360(self->unk_40, 0xd, 0);
                break;
            }
        }
        if (self->unk_20 == 0xffff && self->unk_cc.b4) {
            if (PlayerIdle02195848()) {
                u8 *st = self->unk_40;
                LFLD(u16, st, 2)++;
                if ((s32)LFLD(u16, st, 2) > 0x1fe) {
                    if ((s32)LFLD(u16, st, 2) > 0x258) {
                        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
                        obj->vfunc_08();
                        break;
                    }
                    if (self->unk_38 != NULL) {
                        if ((LFLD(u16, st, 2) & 7) > 2) {
                            LFLD(u8, self->unk_38, 0xbe) = 10;
                        } else {
                            LFLD(u8, self->unk_38, 0xbe) = 0x1f;
                        }
                    }
                }
            } else if (self->unk_38 != NULL) {
                LFLD(u8, self->unk_38, 0xbe) = 0x1f;
            }
        }
        if ((self->unk_30 & 0x80) && (h = self->unk_48) != NULL) {
            LFLD(B16_02195848, h, 0x9a).b0 = 1;
            LFLD(u16, h, 0x9a) |= 8;
            func_0203f324(h);
            func_ov000_021987b8(self->unk_48, 0, 0, 0);
        }
        break;
    }
    if (self->unk_58 != NULL && (self->unk_cc.b1 || (self->unk_30 & 0x80))) {
        void *p;
        u16 rx;
        u16 ry;
        u16 rz;
        self->unk_cc.b0 = 1;
        rz = self->unk_80;
        p = self->unk_58;
        ry = self->unk_7e;
        rx = self->unk_7c;
        RotZYX02195848(&m, &t, rx, ry, rz);
        m._30 = self->unk_70;
        m._31 = self->unk_74;
        m._32 = self->unk_78;
        func_0203f9dc(p, &m);
    }
    h = self->unk_48;
    if (h == NULL) {
        return;
    }
    {
        s32 k = LFLD(K_02195848, self->unk_b0, 2).b0;
        if (k == 3) {
            return;
        }
        if (self->unk_58 != NULL && self->unk_cc.b0 && k != 1) {
            LFLD(B16_02195848, h, 0x9a).b3 = 0;
            func_0203f364(h);
        }
    }
    if (!self->unk_cc.b1) {
        LFLD(B16_02195848, self->unk_48, 0x9a).b4 = 0;
        self->unk_93.b0 = 1;
        return;
    }
    LFLD(u16, self->unk_48, 0x9a) |= 0x20;
    if (!(LFLD(u32, self->unk_48, 0x50) & 0x20000000)) {
        if (PlayerIdle02195848()) {
            func_ov000_02198360(self->unk_40, 4, 0);
        }
        return;
    }
    if (LFLD(u32, self->unk_48, 0x50) & 0x40000) {
        return;
    }
    if (!PlayerIdle02195848()) {
        return;
    }
    self->unk_cc.b1 = 0;
    LFLD(B16_02195848, self->unk_48, 0x9a).b4 = 0;
}
}
