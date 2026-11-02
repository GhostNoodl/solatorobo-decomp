#include "ov000/VObj.h"
#include "Main/Sys/FieldState.h"
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
void *Heap_Alloc(u32 size);
void func_ov000_0216b474(void *p);
void func_ov000_0216ad04(void *p);
void func_ov000_0216bf30(void *p);
void *func_ov000_0217006c(void *p);
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
    VObj *p = (VObj *)Heap_Alloc(size);
    if (p != NULL) {
        *(void **)p = data_ov000_021cac0c;
        p->vfunc_14();
        *(void **)p = vt;
        p->vfunc_14();
    }
    return p;
}

struct Obj02170a58 {
    u8 unk_00[0xc];
    u8 *unk_0c;
    u8 unk_10[0x10];
    u32 unk_20;
    u8 unk_24[0x4];
    VObj *unk_28;
    void *unk_2c;
    VObj *unk_30;
    void *unk_34;
    void *unk_38;
    void *unk_3c;
    void *unk_40;
    void *unk_44;
    VObj *unk_48;
    void *unk_4c;
    void *unk_50;
    void *unk_54;
    VObj *unk_58;
    VObj *unk_5c;
    VObj *unk_60;
    VObj *unk_64;
    void *unk_68;
    VObj *unk_6c;
    VObj *unk_70;
    VObj *unk_74;
    void *unk_78;
    void *unk_7c;
};

void func_ov000_02170a58(Obj02170a58 *self) {
    u8 *c = self->unk_0c;
    switch (STATE) {
    case 0:
        STATE = 1;
    case 1: {
        VObj *p;
        u8 *q;
        if (LFLD(Bit0, c, 0x114).b0) {
            break;
        }
        p = (VObj *)Heap_Alloc(0xb8);
        if (p != NULL) {
            *(void **)p = data_ov000_021cac0c;
            p->vfunc_14();
            *(void **)p = data_ov000_021cb798;
            p->vfunc_14();
            LFLD(s32, p, 0x9c) = 0;
        }
        self->unk_58 = p;
        p = (VObj *)Heap_Alloc(0xb8);
        if (p != NULL) {
            *(void **)p = data_ov000_021cac0c;
            p->vfunc_14();
            *(void **)p = data_ov000_021cb798;
            p->vfunc_14();
            LFLD(s32, p, 0x9c) = 1;
        }
        self->unk_5c = p;
        self->unk_60 = NewObj2(0xb0, data_ov000_021cb7ec);
        q = (u8 *)Heap_Alloc(0x1c);
        if (q != NULL) {
            func_ov000_0216b474(q);
        }
        self->unk_68 = q;
        self->unk_64 = NewObj2(0xb0, data_ov000_021cb744);
        self->unk_6c = NewObj2(0xa0, data_ov000_021cb6f0);
        self->unk_70 = NewObj2(0xac, data_ov000_021cb840);
        self->unk_74 = NewObj2(0xbc, data_ov000_021cb894);
        q = (u8 *)Heap_Alloc(0x20);
        if (q != NULL) {
            func_ov000_0216ad04(q);
        }
        self->unk_78 = q;
        q = (u8 *)Heap_Alloc(0x3d8);
        if (q != NULL) {
            __cxa_vec_ctor(q + 0x360, 10, 0xc, (void (*)(void *))func_ov000_0217125c, (void (*)(void *))func_ov000_0217006c);
            func_ov000_0216bf30(q);
        }
        self->unk_7c = q;
        func_ov000_021bce90();
        STATE = 2;
    }
    case 2:
        if (!func_0204c120()) {
            return;
        }
        func_ov000_0216bbec(self->unk_7c);
        self->unk_20 |= 2;
        STATE = 3;
        break;
    case 4:
        if ((void *)self->unk_48 == NULL && !self->unk_28->vfunc_8c()) {
            HEAP_DELETE(VObj *, self->unk_28, p->vfunc_04());
            STATE = 3;
        }
    case 10:
        if (self->unk_3c != NULL && !func_ov000_021b9010(self->unk_3c)) {
            HEAP_DELETE_FN(self->unk_3c, func_ov000_021b8ecc);
            if (STATE == 10) {
                STATE = 3;
            }
        }
    case 11:
        if (self->unk_48 != NULL && !self->unk_48->vfunc_1c()) {
            HEAP_DELETE(VObj *, self->unk_48, p->vfunc_04());
            if (self->unk_28 != NULL) {
                self->unk_28->vfunc_0c();
            }
            func_ov000_02182524((u8 *)data_ov000_021ccd54 + 0xac);
            if (STATE == 11) {
                STATE = 3;
            }
        }
        break;
    case 8:
        if (self->unk_40 != NULL && !func_ov000_021ba92c(self->unk_40)) {
            HEAP_DELETE_FN(self->unk_40, func_ov000_021bacf4);
            STATE = 3;
        }
        break;
    case 9:
        if (self->unk_44 != NULL && !func_ov000_021bb8dc(self->unk_44)) {
            HEAP_DELETE(u8 *, (u8 *)self->unk_44, func_ov000_021bbcac(p); *(void **)(p + 4) = data_0208b318; ((VObj *)(p + 4))->vfunc_0c(); Heap_Free(p));
            STATE = 3;
        }
        break;
    case 5:
        if (!func_0204fd60(self->unk_2c)) {
            HEAP_DELETE_FN(self->unk_2c, func_020507d8);
            STATE = 3;
        }
        break;
    case 6:
        if (!self->unk_30->vfunc_1c()) {
            HEAP_DELETE(VObj *, self->unk_30, p->vfunc_04());
            STATE = 3;
        }
        break;
    case 7:
        if (!func_ov000_021b8994(self->unk_38)) {
            HEAP_DELETE_FN(self->unk_38, func_ov000_021b88d8);
            STATE = 3;
        }
        break;
    }
    if (self->unk_4c != NULL && !func_ov000_021bb33c(self->unk_4c)) {
        HEAP_DELETE_FN(self->unk_4c, func_ov000_021bb840);
    }
    if (self->unk_34 != NULL && !func_ov000_021b8284(self->unk_34)) {
        HEAP_DELETE_FN(self->unk_34, func_ov000_021b8800);
    }
    if (self->unk_50 != NULL && !func_ov000_0216ca70(self->unk_50)) {
        HEAP_DELETE_FN(self->unk_50, func_ov000_0216c9b0);
    }
    if (self->unk_54 != NULL && !func_ov000_0216dae4(self->unk_54)) {
        HEAP_DELETE_FN(self->unk_54, func_ov000_0216e5d0);
    }
    if (self->unk_58 != NULL) {
        self->unk_58->vfunc_0c();
    }
    if (self->unk_5c != NULL) {
        self->unk_5c->vfunc_0c();
    }
    if (self->unk_60 != NULL) {
        self->unk_60->vfunc_0c();
    }
    if (self->unk_64 != NULL) {
        self->unk_64->vfunc_0c();
    }
    if (self->unk_68 != NULL) {
        func_ov000_0216b550(self->unk_68);
    }
    if (self->unk_78 != NULL) {
        func_ov000_0216adf8(self->unk_78);
    }
    if (self->unk_6c != NULL) {
        self->unk_6c->vfunc_0c();
    }
    if (self->unk_70 != NULL) {
        self->unk_70->vfunc_0c();
    }
    if (self->unk_74 != NULL) {
        self->unk_74->vfunc_0c();
    }
    if (self->unk_7c != NULL) {
        func_ov000_0216be58(self->unk_7c);
    }
}

void func_ov000_0217125c(void *self) {
    *(s32 *)((u8 *)self + 0x0) = 0x0;
    *(s32 *)((u8 *)self + 0x4) = 0x0;
    *(s32 *)((u8 *)self + 0x8) = 0x0;
}

}
