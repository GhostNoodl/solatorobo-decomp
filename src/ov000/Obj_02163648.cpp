#include "ov000/VObj.h"

typedef struct {
    void *current;
    void *unk_04;
    void *unk_08;
} HeapState;

typedef struct {
    u32 unk_00;
    u32 unk_04_0 : 6;
    u32 unk_04_6 : 1;
    u32 unk_04_7 : 25;
    u8 unk_08[0x64];
    void *unk_6c;
    u8 unk_70[0x18];
    u8 unk_88[0xd8];
} Model;

typedef struct {
    u32 unk_00;
    u32 unk_04;
} Sub02163b58;

class Obj02163648 : public VObj {
public:
    u8 unk_04[0xc];
    void *unk_10;
    s32 unk_14_pad[3];
    s32 unk_20;
    s32 unk_24;
    u8 unk_28[0x5c];
    Model *unk_84;
    u8 unk_88[0x8];
    void *unk_90;
    Model *unk_94;
    u8 unk_98[0x3c];
    Model *unk_d4;
};

extern "C" BOOL func_0203e63c(void *a);

static inline BOOL Model_IsIdle(Model *model) {
    if (model->unk_6c == NULL) {
        return TRUE;
    }
    if (func_0203e63c(model->unk_6c)) {
        model->unk_6c = NULL;
    } else {
        return !model->unk_04_6;
    }
    return TRUE;
}

extern "C" {

extern u8 data_ov000_021cac0c[];
extern u8 data_ov000_021cad50[];
extern u8 data_ov000_021cadcc[];
extern u8 data_ov000_021cae48[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cafc0[];
extern u8 data_ov000_021cb0b8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb3a8[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021cb5a8[];
extern HeapState *data_02097dd0;
extern u8 data_ov000_021cacd8[];
extern u8 data_ov000_021cac60[];

void func_0203de1c(void *ptr);
void func_02041558(Model *model);
void func_02041278(void *a);
s32 func_ov000_021580e8(Obj02163648 *self);
BOOL func_02054f10(void *a, u32 b);

Obj02163648 *func_ov000_02163648(Obj02163648 *self) {
    void *saved;
    Model *model;
    VOBJ_SET_VTABLE(self, data_ov000_021cacd8);
    saved = data_02097dd0->current;
    data_02097dd0->current = data_02097dd0->unk_08;
    model = self->unk_84;
    if (model != NULL) {
        if (model != NULL) {
            func_02041558(model);
            func_02041278(model->unk_88);
            func_0203de1c(model);
        }
        self->unk_84 = NULL;
    }
    data_02097dd0->current = saved;
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *func_ov000_021636d4(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cac0c);
    self->vfunc_18();
    func_0203de1c(self);
    return self;
}

static inline BOOL IsState10(void *self) {
    return *(s32 *)((u8 *)self + 4) == 10 ? TRUE : FALSE;
}

bool func_ov000_02163704(void *self) {
    return IsState10(self);
}

VObj *func_ov000_02163724(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cac0c);
    self->vfunc_18();
    return self;
}

s32 func_ov000_0216374c(void) {
    return 0x4;
}

s32 func_ov000_02163754(void) {
    return 0x4;
}

s32 func_ov000_0216375c(Obj02163648 *self) {
    s32 ret = func_ov000_021580e8(self);
    Model *model = self->unk_d4;
    if (model != NULL && !Model_IsIdle(model)) {
        ret = 0;
    }
    return ret;
}

VObj *func_ov000_021637c8(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cafc0);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cb0b8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cb1b0);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    func_0203de1c(self);
    return self;
}

VObj *func_ov000_02163868(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cafc0);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cb0b8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cb1b0);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *func_ov000_02163900(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb0b8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cb1b0);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *func_ov000_0216397c(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cae48);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    func_0203de1c(self);
    return self;
}

s32 func_ov000_021639c8(void) {
    return 0x10;
}

BOOL func_ov000_021639d0(Obj02163648 *self) {
    BOOL ret = TRUE;
    Model *model;
    if (self->unk_10 != NULL && !func_02054f10(self->unk_10, 0xffff)) {
        ret = FALSE;
    }
    if (self->unk_90 != NULL && !func_02054f10(self->unk_90, 0xffff)) {
        ret = FALSE;
    }
    model = self->unk_94;
    if (model != NULL && !Model_IsIdle(model)) {
        ret = FALSE;
    }
    return ret;
}

VObj *func_ov000_02163a74(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cae48);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

s32 func_ov000_02163ab8(void) {
    return 0x2;
}

VObj *func_ov000_02163ac0(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cad50);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *func_ov000_02163b04(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cadcc);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    func_0203de1c(self);
    return self;
}

s32 func_ov000_02163b50(void) {
    return 0x3;
}

void func_ov000_02163b58(Obj02163648 *self) {
    ((Sub02163b58 *)self->unk_84)->unk_04 |= 4;
}

VObj *func_ov000_02163b6c(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cadcc);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *func_ov000_02163bb0(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb1b0);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    func_0203de1c(self);
    return self;
}

VObj *func_ov000_02163c18(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb1b0);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

s32 func_ov000_02163c78(void) {
    return 0x4;
}

s32 func_ov000_02163c80(void) {
    return 0x1;
}

VObj *func_ov000_02163c88(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb5a8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *func_ov000_02163ce8(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb3a8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cb4a8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    func_0203de1c(self);
    return self;
}

s32 func_ov000_02163d6c(Obj02163648 *self) {
    s32 a = self->vfunc_40() * self->unk_20;
    s32 b = self->vfunc_34();
    return a + b + self->vfunc_38();
}

s32 func_ov000_02163db8(void) {
    return 0x4;
}

s32 func_ov000_02163dc0(void) {
    return 0x5;
}

s32 func_ov000_02163dc8(Obj02163648 *self) {
    return (s32)(((s64)(self->unk_24 << 12) * 0xe7a + 0x800) >> 12) >> 12;
}

VObj *func_ov000_02163dfc(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb3a8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cb4a8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *func_ov000_02163e78(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb4a8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    func_0203de1c(self);
    return self;
}

VObj *func_ov000_02163ee0(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb4a8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *func_ov000_02163f40(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    func_0203de1c(self);
    return self;
}

s32 func_ov000_02163f8c(void) {
    return 0x4;
}

VObj *func_ov000_02163f94(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *func_ov000_02163fd8(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    func_0203de1c(self);
    return self;
}

void func_ov000_02164008(void) {
}

VObj *func_ov000_0216400c(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *func_ov000_02164034(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb4a8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *func_ov000_02164094(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb4a8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    func_0203de1c(self);
    return self;
}

}
