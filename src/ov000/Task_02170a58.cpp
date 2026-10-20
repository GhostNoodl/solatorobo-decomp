#include "ov000/VObj.h"
#include "ov000/HeapScope.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

extern u8 data_0208b318[];
extern u8 data_ov000_021cac0c[];
extern u8 data_ov000_021cb798[];
extern u8 data_ov000_021cb7ec[];
extern u8 data_ov000_021cb744[];
extern u8 data_ov000_021cb6f0[];
extern u8 data_ov000_021cb840[];
extern u8 data_ov000_021cb894[];
extern u8 *data_ov000_021ccd54;
void *func_0203dd9c(u32 size);
void func_ov000_0216b474(void *p);
void func_ov000_0216ad04(void *p);
void func_ov000_0216bf30(void *p);
void func_ov000_0217006c(void *p);
void func_ov000_0217125c(void *p);
void __cxa_vec_ctor(void *arr, int n, u32 size, void (*ctor)(void *), void (*dtor)(void *));
void func_ov000_021bce90(void);
BOOL func_0204c120(void);
void func_ov000_0216bbec(void *p);
BOOL func_ov000_021b9010(void *p);
BOOL func_ov000_021ba92c(void *p);
BOOL func_ov000_021bb8dc(void *p);
BOOL func_0204fd60(void *p);
BOOL func_ov000_021b8994(void *p);
BOOL func_ov000_021bb33c(void *p);
BOOL func_ov000_021b8284(void *p);
BOOL func_ov000_0216ca70(void *p);
BOOL func_ov000_0216dae4(void *p);
void func_ov000_02182524(void *p);
void func_ov000_0216b550(void *p);
void func_ov000_0216adf8(void *p);
void func_ov000_0216be58(void *p);
void func_ov000_021bbcac(void *p);
void func_020507d8(void *p);
void func_ov000_0216c9b0(void *p);
void func_ov000_0216e5d0(void *p);
void func_ov000_021b8800(void *p);
void func_ov000_021b88d8(void *p);
void func_ov000_021b8ecc(void *p);
void func_ov000_021bacf4(void *p);
void func_ov000_021bb840(void *p);

typedef struct {
    u32 b0 : 1;
} Bit0;

#define STATE LFLD(s32, self, 0x24)

static inline VObj *NewObj2(u32 size, void *vt) {
    VObj *p = (VObj *)func_0203dd9c(size);
    if (p != NULL) {
        *(void **)p = data_ov000_021cac0c;
        p->vfunc_14();
        *(void **)p = vt;
        p->vfunc_14();
    }
    return p;
}

void func_ov000_02170a58(u8 *self) {
    u8 *c = LFLD(u8 *, self, 0xc);
    switch (STATE) {
    case 0:
        STATE = 1;
    case 1: {
        VObj *p;
        u8 *q;
        if (LFLD(Bit0, c, 0x114).b0) {
            break;
        }
        p = (VObj *)func_0203dd9c(0xb8);
        if (p != NULL) {
            *(void **)p = data_ov000_021cac0c;
            p->vfunc_14();
            *(void **)p = data_ov000_021cb798;
            p->vfunc_14();
            LFLD(s32, p, 0x9c) = 0;
        }
        LFLD(VObj *, self, 0x58) = p;
        p = (VObj *)func_0203dd9c(0xb8);
        if (p != NULL) {
            *(void **)p = data_ov000_021cac0c;
            p->vfunc_14();
            *(void **)p = data_ov000_021cb798;
            p->vfunc_14();
            LFLD(s32, p, 0x9c) = 1;
        }
        LFLD(VObj *, self, 0x5c) = p;
        LFLD(VObj *, self, 0x60) = NewObj2(0xb0, data_ov000_021cb7ec);
        q = (u8 *)func_0203dd9c(0x1c);
        if (q != NULL) {
            func_ov000_0216b474(q);
        }
        LFLD(u8 *, self, 0x68) = q;
        LFLD(VObj *, self, 0x64) = NewObj2(0xb0, data_ov000_021cb744);
        LFLD(VObj *, self, 0x6c) = NewObj2(0xa0, data_ov000_021cb6f0);
        LFLD(VObj *, self, 0x70) = NewObj2(0xac, data_ov000_021cb840);
        LFLD(VObj *, self, 0x74) = NewObj2(0xbc, data_ov000_021cb894);
        q = (u8 *)func_0203dd9c(0x20);
        if (q != NULL) {
            func_ov000_0216ad04(q);
        }
        LFLD(u8 *, self, 0x78) = q;
        q = (u8 *)func_0203dd9c(0x3d8);
        if (q != NULL) {
            __cxa_vec_ctor(q + 0x360, 10, 0xc, func_ov000_0217125c, func_ov000_0217006c);
            func_ov000_0216bf30(q);
        }
        LFLD(u8 *, self, 0x7c) = q;
        func_ov000_021bce90();
        STATE = 2;
    }
    case 2:
        if (!func_0204c120()) {
            return;
        }
        func_ov000_0216bbec(LFLD(void *, self, 0x7c));
        LFLD(u32, self, 0x20) |= 2;
        STATE = 3;
        break;
    case 4:
        if (LFLD(void *, self, 0x48) == NULL && !LFLD(VObj *, self, 0x28)->vfunc_8c()) {
            HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x28), p->vfunc_04());
            STATE = 3;
        }
    case 10:
        if (LFLD(void *, self, 0x3c) != NULL && !func_ov000_021b9010(LFLD(void *, self, 0x3c))) {
            HEAP_DELETE_FN(LFLD(void *, self, 0x3c), func_ov000_021b8ecc);
            if (STATE == 10) {
                STATE = 3;
            }
        }
    case 11:
        if (LFLD(VObj *, self, 0x48) != NULL && !LFLD(VObj *, self, 0x48)->vfunc_1c()) {
            HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x48), p->vfunc_04());
            if (LFLD(VObj *, self, 0x28) != NULL) {
                LFLD(VObj *, self, 0x28)->vfunc_0c();
            }
            func_ov000_02182524(data_ov000_021ccd54 + 0xac);
            if (STATE == 11) {
                STATE = 3;
            }
        }
        break;
    case 8:
        if (LFLD(void *, self, 0x40) != NULL && !func_ov000_021ba92c(LFLD(void *, self, 0x40))) {
            HEAP_DELETE_FN(LFLD(void *, self, 0x40), func_ov000_021bacf4);
            STATE = 3;
        }
        break;
    case 9:
        if (LFLD(void *, self, 0x44) != NULL && !func_ov000_021bb8dc(LFLD(void *, self, 0x44))) {
            HEAP_DELETE(u8 *, LFLD(u8 *, self, 0x44), func_ov000_021bbcac(p); *(void **)(p + 4) = data_0208b318; ((VObj *)(p + 4))->vfunc_0c(); func_0203de1c(p));
            STATE = 3;
        }
        break;
    case 5:
        if (!func_0204fd60(LFLD(void *, self, 0x2c))) {
            HEAP_DELETE_FN(LFLD(void *, self, 0x2c), func_020507d8);
            STATE = 3;
        }
        break;
    case 6:
        if (!LFLD(VObj *, self, 0x30)->vfunc_1c()) {
            HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x30), p->vfunc_04());
            STATE = 3;
        }
        break;
    case 7:
        if (!func_ov000_021b8994(LFLD(void *, self, 0x38))) {
            HEAP_DELETE_FN(LFLD(void *, self, 0x38), func_ov000_021b88d8);
            STATE = 3;
        }
        break;
    }
    if (LFLD(void *, self, 0x4c) != NULL && !func_ov000_021bb33c(LFLD(void *, self, 0x4c))) {
        HEAP_DELETE_FN(LFLD(void *, self, 0x4c), func_ov000_021bb840);
    }
    if (LFLD(void *, self, 0x34) != NULL && !func_ov000_021b8284(LFLD(void *, self, 0x34))) {
        HEAP_DELETE_FN(LFLD(void *, self, 0x34), func_ov000_021b8800);
    }
    if (LFLD(void *, self, 0x50) != NULL && !func_ov000_0216ca70(LFLD(void *, self, 0x50))) {
        HEAP_DELETE_FN(LFLD(void *, self, 0x50), func_ov000_0216c9b0);
    }
    if (LFLD(void *, self, 0x54) != NULL && !func_ov000_0216dae4(LFLD(void *, self, 0x54))) {
        HEAP_DELETE_FN(LFLD(void *, self, 0x54), func_ov000_0216e5d0);
    }
    if (LFLD(VObj *, self, 0x58) != NULL) {
        LFLD(VObj *, self, 0x58)->vfunc_0c();
    }
    if (LFLD(VObj *, self, 0x5c) != NULL) {
        LFLD(VObj *, self, 0x5c)->vfunc_0c();
    }
    if (LFLD(VObj *, self, 0x60) != NULL) {
        LFLD(VObj *, self, 0x60)->vfunc_0c();
    }
    if (LFLD(VObj *, self, 0x64) != NULL) {
        LFLD(VObj *, self, 0x64)->vfunc_0c();
    }
    if (LFLD(void *, self, 0x68) != NULL) {
        func_ov000_0216b550(LFLD(void *, self, 0x68));
    }
    if (LFLD(void *, self, 0x78) != NULL) {
        func_ov000_0216adf8(LFLD(void *, self, 0x78));
    }
    if (LFLD(VObj *, self, 0x6c) != NULL) {
        LFLD(VObj *, self, 0x6c)->vfunc_0c();
    }
    if (LFLD(VObj *, self, 0x70) != NULL) {
        LFLD(VObj *, self, 0x70)->vfunc_0c();
    }
    if (LFLD(VObj *, self, 0x74) != NULL) {
        LFLD(VObj *, self, 0x74)->vfunc_0c();
    }
    if (LFLD(void *, self, 0x7c) != NULL) {
        func_ov000_0216be58(LFLD(void *, self, 0x7c));
    }
}

void func_ov000_0217125c(void *self) {
    *(s32 *)((u8 *)self + 0x0) = 0x0;
    *(s32 *)((u8 *)self + 0x4) = 0x0;
    *(s32 *)((u8 *)self + 0x8) = 0x0;
}

}
