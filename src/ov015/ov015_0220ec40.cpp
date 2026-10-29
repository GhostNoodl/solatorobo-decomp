#include "ov015/ov015.h"

extern "C" {



extern u8 *data_ov015_02213368;
extern void *data_02149ef8;
extern u8 *data_0214a424;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021cb3a8[];
extern u8 data_ov000_021ccbe0[];
extern u8 data_ov000_021ccb54[];
extern u8 data_ov015_022131ac[];
extern u8 data_ov000_021cca40[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021cae48[];
extern char data_ov015_02213100[];
void *func_0204c0e8(void *a, s32 b);
void func_ov000_02157c90(void *a, void *b);
const char *func_0206ffa0(u16 id);
int STD_CopyLString(char *dst, const char *src, s32 n);
void func_ov000_021c3af4(void *p);
void func_ov000_021c54f4(void *p);
void func_ov000_021c22d8(void *p);
void func_ov000_021c5bac(void *p);
void *func_0206ec48(u16 id);
u8 *func_0206ee20(u16 id);
void func_ov000_021c3fd4(void *a, void *b);
void func_ov000_021c55e8(void *a, void *b);
void func_ov000_021c5630(void *a, void *b);
void func_ov000_021c5678(void *a, void *b);
void func_ov000_0215d980(void *a, s32 b, s32 c);

struct Ov015ItemEnt {
    u16 id;
    s32 cnt;
};

static inline void Ov015_SetXYZ16(u8 *o, s16 x, s16 y, s16 z) {
    FLD(s16, o, 0x64) = x;
    FLD(s16, o, 0x66) = y;
    FLD(s16, o, 0x68) = z;
}

static inline void Ov015_SetXYZ32(u8 *o, s32 x, s32 y, s32 z) {
    FLD(s32, o, 0x58) = x;
    FLD(s32, o, 0x5c) = y;
    FLD(s32, o, 0x60) = z;
}

static inline void *GetRes0220e634(void) {
    return data_02149ef8;
}

void func_ov015_0220e634(u8 *self, s32 mode) {
    u8 *sh;
    s32 i;
    u8 *p;
    Ov015ItemEnt *items;
    void *res;
    res = GetRes0220e634();
    sh = data_ov015_02213368;
    FLD(s32, self, 0x60) = mode;
    p = (u8 *)func_0203dd9c(0xf0);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021caec8);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cb4a8);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cb3a8);
        VCALL(p)->v28();
    }
    FLD(u8 *, self, 0x4) = p;
    FLD(s32, p, 0x24) = 0xf8;
    FLD(s32, FLD(u8 *, self, 0x4), 0x20) = 1;
    Ov015_SetXYZ16(FLD(u8 *, self, 0x4), 0, 0x19, -0xccd);
    FLD(u16, FLD(u8 *, self, 0x4), 0x48) = 0x28;
    Ov015_SetXYZ32(FLD(u8 *, self, 0x4), -0x100, 0, -0xccd);
    FLD(u32, FLD(u8 *, self, 0x4), 0xc) &= ~0x40000;
    FLD(u32, FLD(u8 *, self, 0x4), 0xc) &= ~0x20000;
    VCALL(FLD(u8 *, self, 0x4))->v10(func_0204c0e8(res, 0xcc));
    VCALL(FLD(u8 *, self, 0x4))->v14(func_0204c0e8(res, 0xcd));
    FLD(s32, FLD(u8 *, self, 0x4), 0x2c) = 1;
    switch (mode) {
    case 0:
        STD_CopyLString((char *)(self + 0x20), (const char *)func_0204c0e8(res, 0xcf), 0x40);
        break;
    case 1:
        func_ov000_02157c90(FLD(u8 *, self, 0x4), func_0204c0e8(res, 0xce));
        STD_CopyLString((char *)(self + 0x20), func_0206ffa0(FLD(u16, sh, 0xc)), 0x40);
        break;
    default:
        STD_CopyLString((char *)(self + 0x20), data_ov015_02213100, 0x40);
        break;
    }
    FLD(u8 *, FLD(u8 *, self, 0x4), 0xe0) = self + 0x20;
    VCALL(FLD(u8 *, self, 0x4))->v08();
    items = (Ov015ItemEnt *)(sh + 0x10);
    p = (u8 *)func_0203dd9c(0x100);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021ccbe0);
        func_ov000_021c3af4(p);
        SET_VT(p, data_ov000_021ccb54);
        func_ov000_021c54f4(p);
    }
    FLD(u8 *, self, 0x8) = p;
    FLD(s32, p, 0x24) = 0xf8;
    FLD(s32, FLD(u8 *, self, 0x8), 0x20) = 3;
    Ov015_SetXYZ16(FLD(u8 *, self, 0x8), 2, 0x3c, -0xccd);
    Ov015_SetXYZ32(FLD(u8 *, self, 0x8), -0x100, 0, -0xccd);
    FLD(s32, FLD(u8 *, self, 0x8), 0x2c) = 1;
    FLD(u32, FLD(u8 *, self, 0x8), 0xc) &= ~0x40000;
    FLD(u8, FLD(u8 *, self, 0x8), 0xf0) = 0;
    if (mode == 1) {
        for (i = 0; i < 3; i++) {
            u16 n;
            void *name;
            u16 k;
            u8 *e;
            u8 *d;
            if (items[i].cnt == 0) {
                break;
            }
            e = (u8 *)func_0203dd9c(0x48);
            if (e != NULL) {
                SET_VT(e, data_ov015_022131ac);
                func_ov000_021c22d8(e);
                SET_VT(e, data_ov000_021cca40);
                func_ov000_021c5bac(e);
            }
            name = func_0206ec48(items[i].id);
            k = 0;
            d = func_0206ee20(items[i].id);
            if (d != NULL) {
                k = FLD(u16, d, 2);
            }
            n = items[i].cnt;
            FLD(void *, e, 0x38) = name;
            FLD(u16, e, 0x3c) = n;
            FLD(s32, e, 0x40) = k * n;
            func_ov000_021c3fd4(FLD(u8 *, self, 0x8), e);
        }
    }
    func_ov000_021c55e8(FLD(u8 *, self, 0x8), func_0204c0e8(res, 0x9a));
    func_ov000_021c5630(FLD(u8 *, self, 0x8), func_0204c0e8(res, 0xd3));
    func_ov000_021c5678(FLD(u8 *, self, 0x8), func_0204c0e8(res, 0x3f));
    VCALL(FLD(u8 *, self, 0x8))->v08();
    FLD(u32, FLD(u8 *, self, 0x8), 0xc) |= 4;
    p = (u8 *)func_0203dd9c(0xe0);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021caec8);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cb5a8);
        VCALL(p)->v28();
    }
    FLD(u8 *, self, 0x14) = p;
    FLD(u32, p, 0xc) |= 0x4000000;
    FLD(s32, FLD(u8 *, self, 0x14), 0x2c) = 1;
    FLD(u32, FLD(u8 *, self, 0x14), 0xc) |= 0x20000000;
    FLD(u32, FLD(u8 *, self, 0x14), 0xc) |= 0x80000000;
    Ov015_SetXYZ32(FLD(u8 *, self, 0x14), 0x100, 0, -0xcd);
    VCALL(FLD(u8 *, self, 0x14))->vf4(1, func_0204c0e8(res, 0x36));
    VCALL(FLD(u8 *, self, 0x14))->v08();
    FLD(u32, FLD(u8 *, self, 0x14), 0xc) |= 2;
    p = (u8 *)func_0203dd9c(0x98);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cae48);
        VCALL(p)->v28();
    }
    FLD(u8 *, self, 0xc) = p;
    Ov015_SetXYZ16(p, 0x92, 0x78, -0x99a);
    Ov015_SetXYZ32(FLD(u8 *, self, 0xc), 0x100, 0, -0x99a);
    FLD(s32, FLD(u8 *, self, 0xc), 0x2c) = 1;
    FLD(s32, FLD(u8 *, self, 0xc), 0x84) = 1;
    VCALL(FLD(u8 *, self, 0xc))->v08();
    if (mode == 1) {
        func_ov000_0215d980(FLD(u8 *, self, 0xc), FLD(s32, sh, 0x28), 0);
    } else {
        func_ov000_0215d980(FLD(u8 *, self, 0xc), 0, 0);
    }
    p = (u8 *)func_0203dd9c(0x98);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cae48);
        VCALL(p)->v28();
    }
    FLD(u8 *, self, 0x10) = p;
    Ov015_SetXYZ16(p, 0x92, 0x8c, -0x99a);
    Ov015_SetXYZ32(FLD(u8 *, self, 0x10), 0x100, 0, -0x99a);
    FLD(s32, FLD(u8 *, self, 0x10), 0x2c) = 1;
    FLD(s32, FLD(u8 *, self, 0x10), 0x84) = 1;
    VCALL(FLD(u8 *, self, 0x10))->v08();
    func_ov000_0215d980(FLD(u8 *, self, 0x10), FLD(s32, data_0214a424, 0x618), 0);
}

void func_ov015_0220ec40(u8 *self) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x4));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x8));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0xc));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x10));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x14));
    HEAP_POP(saved);
}

}
