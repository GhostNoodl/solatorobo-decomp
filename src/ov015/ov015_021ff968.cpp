#include "ov015/ov015.h"

extern "C" {

extern u8 data_ov015_022128fc[];
void func_ov015_02209270(void *p);
void func_0203f2b8(void *p);
void func_ov000_02191b04(void *p);
void func_ov000_0218fee4(void *p);
void func_ov000_0218ea20(void *p);
void func_ov015_0220900c(void *p);
s32 FX_Div(s32 a, s32 b);
BOOL func_ov015_022121b4(u8 *self);
void func_ov015_022123c4(u8 *self);
void func_ov000_02191318(void *a, s32 b);
void func_ov015_02209790(u8 *self, s32 a);
void func_ov015_02209b80(u8 *self, s32 a, s32 b);
u8 *func_ov015_0220c93c(u8 *self);

extern u8 data_ov015_0221292c[];
extern u8 data_ov015_022132e0[];
extern void *data_ov015_02213368;
void func_ov015_022120c0(void *p);
void func_ov015_02212180(void *p);
int func_ov015_0221219c(void *p);
void func_ov000_0218e9c4(void *p);
void func_ov000_0218fe1c(void *p);
void func_ov015_022119e8(void *p);
void func_ov015_021ff9e8(u8 *self);
BOOL func_ov015_021ffb90(u8 *self);
BOOL func_ov015_021ffdd4(u8 *self);
void *func_ov015_0220d878(void *p);
s32 func_ov015_02209fb8(s32 x);
void func_ov015_02211334(void *a, u16 id);
void func_ov015_022029d4(void *list, void *obj);
void func_ov015_021fd00c(u8 *self, s32 mode, const void *v);
void func_ov015_0220a058(u8 *self, void *out);

static inline s32 Ov015_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

BOOL func_ov015_021ff4a0(u8 *self, u8 *a1, u8 *a2, u8 *a3, u8 *a4) {
    BOOL ret = TRUE;
    FLD(u8 *, self, 0x28) = a4;
    FLD(u8 *, self, 0x1c) = a1;
    FLD(u8 *, self, 0x20) = a2;
    FLD(u8 *, self, 0x24) = a3;
    switch (FLD(s32, self, 0x4)) {
    case 0: {
        u8 *o = (u8 *)func_0203dd9c(0x34);
        if (o != NULL) {
            SET_VT(o, data_ov015_0221292c);
            func_ov015_022120c0(o);
        }
        FLD(u8 *, self, 0x10) = o;
        func_ov015_02212180(o);
        o = (u8 *)func_0203dd9c(0x290);
        if (o != NULL) {
            SET_VT(o, data_ov015_022132e0);
            func_ov000_0218e9c4(o + 0x14);
            func_ov000_0218fe1c(o + 0x14c);
            func_ov015_022119e8(o);
        }
        FLD(u8 *, self, 0x14) = o;
        VCALL(o)->v0c();
        FLD(s32, self, 0x4) = 1;
    }
    case 1: {
        bool a = func_ov015_0221219c(FLD(void *, self, 0x10)) & 1;
        bool ok = a & VCALL(FLD(void *, self, 0x14))->v10();
        if (!ok) {
            break;
        }
        FLD(s32, self, 0x4) = 2;
    }
    case 2:
        func_ov015_021ff9e8(self);
        FLD(s32, self, 0x4) = 3;
    case 3:
        if (!func_ov015_021ffb90(self)) {
            break;
        }
        FLD(s32, self, 0x4) = 4;
    case 4:
        if (!func_ov015_021ffdd4(self)) {
            break;
        }
        if (FLD(u8 *, self, 0x18) != NULL) {
            u8 *m;
            u8 *obj;
            u8 *n;
            u32 saved;
            m = (u8 *)func_0203dd9c(8);
            if (m != NULL) {
                m = (u8 *)func_ov015_0220d878(m);
            }
            func_ov015_02209b80(FLD(u8 *, self, 0x18), (s32)m, 6);
            FLD(s32, FLD(u8 *, self, 0x18), 0x108) = 0;
            {
                u8 *q = FLD(u8 *, self, 0x18);
                s32 x = FLD(s32, q, 0x40);
                s32 t = FX_Div(FLD(s32, q, 0x48) + 0x37000, -0x73000) - FLD(s32, a4, 0x14);
                if (t < 0x266) {
                    t = 0x266;
                }
                if (t > 0xa66) {
                    t = 0xa66;
                }
                q = FLD(u8 *, self, 0x18);
                FLD(s32, q, 0x40) = x;
                FLD(s32, q, 0x44) = -0x32000;
                FLD(s32, q, 0x48) = Ov015_FxMul64(t, -0x73000) - 0x37000;
            }
            data_ov015_0221332c.unk_00 = func_ov015_02209fb8(FLD(s32, FLD(u8 *, self, 0x18), 0x48));
            func_ov015_02211334(data_ov015_02213368, FLD(u16, FLD(u8 *, self, 0x18), 0xc4));
            n = FLD(u8 *, FLD(u8 *, self, 0x24), 0x4);
            while (n != NULL) {
                obj = FLD(u8 *, n, 0x4);
                n = FLD(u8 *, n, 0xc);
                if (obj != FLD(u8 *, self, 0x18)) {
                    func_ov015_022029d4(FLD(void *, self, 0x24), obj);
                    HEAP_PUSH(saved);
                    if (obj != NULL) {
                        if (obj != NULL) {
                            VCALL(obj)->v04();
                        }
                    }
                    HEAP_POP(saved);
                }
            }
            {
                u8 *q = FLD(u8 *, self, 0x18);
                u8 *d = FLD(u8 *, self, 0x1c);
                FLD(s32, d, 0xd4c) = FLD(s32, q, 0x40);
                FLD(s32, d, 0xd50) = FLD(s32, q, 0x44);
                FLD(s32, d, 0xd54) = FLD(s32, q, 0x48);
            }
            HEAP_PUSH(saved);
            DELETE_V(FLD(void *, self, 0x10));
            HEAP_POP(saved);
            FLD(s32, self, 0x4) = 6;
        } else {
            FLD(s32, self, 0x4) = 5;
        }
        break;
    case 5: {
        BOOL done = FALSE;
        if (FLD(u8, self, 0xc) == 0) {
            u8 *n;
            func_ov015_021fd00c(FLD(u8 *, self, 0x20), 7, FLD(u8 *, self, 0x10) + 0xc);
            for (n = FLD(u8 *, FLD(u8 *, self, 0x24), 0x4); n != NULL; n = FLD(u8 *, n, 0xc)) {
                func_ov015_02209790(FLD(u8 *, n, 0x4), 1);
            }
            if (VCALL(FLD(void *, self, 0x14))->v18() == 0) {
                done = TRUE;
            }
        }
        if (done) {
            FLD(u16, FLD(u8 *, self, 0x1c), 0xd3c) = 2;
            VCALL(FLD(void *, self, 0x14))->v08();
            FLD(s32, self, 0x4) = 3;
        }
        break;
    }
    case 6: {
        BOOL done = FALSE;
        if (FLD(u8, self, 0xc) == 0) {
            Ov015Vec v;
            func_ov015_0220a058(FLD(u8 *, self, 0x18), &v);
            func_ov015_021fd00c(FLD(u8 *, self, 0x20), 8, &v);
            VCALL(FLD(void *, self, 0x14))->v18();
            func_ov015_02209790(FLD(u8 *, self, 0x18), 1);
            if (FLD(s32, FLD(u8 *, self, 0x18), 0xf4) == 2) {
                done = TRUE;
            }
        }
        if (done) {
            u32 saved;
            HEAP_PUSH(saved);
            DELETE_V(FLD(void *, self, 0x10));
            HEAP_POP(saved);
            HEAP_PUSH(saved);
            DELETE_V(FLD(void *, self, 0x14));
            HEAP_POP(saved);
            FLD(s32, self, 0x4) = 7;
        }
        break;
    }
    case 7:
        ret = FALSE;
        break;
    }
    FLD(u8 *, self, 0x1c) = NULL;
    FLD(u8 *, self, 0x20) = NULL;
    FLD(u8 *, self, 0x24) = NULL;
    FLD(u8 *, self, 0x28) = NULL;
    if (--FLD(s32, self, 0x8) <= 0) {
        FLD(s32, self, 0x8) = 0;
    }
    return ret;
}

void *func_ov015_021ff968(u8 *self) {
    SET_VT(self, data_ov015_022128fc);
    func_ov015_02209270(self);
    func_0203f2b8(self + 0x568);
    func_ov000_02191b04(self + 0x54c);
    func_ov000_0218fee4(self + 0x464);
    func_ov000_0218ea20(self + 0x32c);
    func_ov000_0218fee4(self + 0x244);
    func_ov000_0218ea20(self + 0x10c);
    func_ov015_0220900c(self + 0xc0);
    func_0203de1c(self);
    return self;
}

void *func_ov015_021ff9d4(void *self) {
    func_ov000_02191b04(self);
    return self;
}

void func_ov015_021ff9e8(u8 *self) {
    u8 *n;
    s32 cnt;
    s32 i;
    func_ov015_022121b4(FLD(u8 *, self, 0x10));
    {
        u8 *p = FLD(u8 *, self, 0x10);
        i = 0;
        FLD(s32, p, 0xc) = 0;
        FLD(s32, p, 0x10) = 0x1800;
        FLD(s32, p, 0x14) = 0x1800 - 0x72000;
    }
    {
        s32 v = FLD(s32, FLD(u8 *, self, 0x28), 0x10);
        u8 *p = FLD(u8 *, self, 0x10);
        FLD(s32, p, 0x18) = v;
        FLD(s32, p, 0x1c) = v;
        FLD(s32, p, 0x20) = v;
    }
    FLD(s32, FLD(u8 *, self, 0x10), 0x30) = FLD(s32, FLD(u8 *, self, 0x28), 0x8);
    func_ov015_022123c4(FLD(u8 *, self, 0x10));
    FLD(s32, FLD(u8 *, self, 0x14), 0x28c) = FLD(s32, FLD(u8 *, self, 0x28), 0xc);
    VCALL(FLD(void *, self, 0x14))->v14();
    FLD(u16, FLD(u8 *, self, 0x1c), 0xd3c) = 2;
    n = FLD(u8 *, FLD(u8 *, self, 0x24), 0x4);
    cnt = FLD(s32, FLD(u8 *, self, 0x24), 0xc);
    for (; n != NULL; n = FLD(u8 *, n, 0xc), i++) {
        u8 *obj = FLD(u8 *, n, 0x4);
        u8 *m = (u8 *)func_0203dd9c(0x40);
        s32 q;
        if (m != NULL) m = func_ov015_0220c93c(m);
        func_ov015_02209b80(obj, (s32)m, 5);
        q = FX_Div(i << 12, cnt << 12);
        FLD(s32, obj, 0x40) = Ov015_FxMul(q, 0x64000) - 0x32000;
        FLD(s32, obj, 0x44) = -0x32000;
        FLD(s32, obj, 0x48) = Ov015_FxMul(q, -0x41000) - 0x4b000;
        func_ov000_02191318(obj + 0x244, Ov015_FxMul(q, 0x3c000));
        FLD(s32, obj, 0xac) = -0x32000;
        FLD(s32, obj, 0xb0) = 0x32000;
        FLD(s32, obj, 0xb4) = -0x4b000;
        FLD(s32, obj, 0xb8) = -0x8c000;
        func_ov015_02209790(obj, 1);
    }
}

}
