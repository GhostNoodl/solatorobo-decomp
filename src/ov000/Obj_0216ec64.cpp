#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x4];
    s32 unk_04;
    u8 unk_08[0x4];
    s32 unk_0c;
} Data02097d78;

typedef struct {
    void *vtbl;
    u32 unk_04;
    u32 unk_08;
    void *unk_0c;
    void (*unk_10)(void *self);
    void (*unk_14)(void *self);
    u32 unk_18;
    u32 unk_1c;
} Buffer0216f144;

extern "C" {

extern u8 data_ov000_021cb6f0[];
extern u8 data_ov000_021cb744[];
extern u8 data_ov000_021cb798[];
extern u8 data_ov000_021cb7ec[];
extern u8 data_ov000_021cb840[];
extern u8 data_ov000_021cb894[];
extern u8 data_ov000_021cac0c[];
extern u8 data_ov000_021cb6b0[];
extern u8 data_ov000_021cb6d0[];
extern Data02097d78 data_02097d78;

void func_0203de1c(void *ptr);
void func_0203df0c(void *ptr);
void func_0203cb78(s32 a, s32 b, s32 c);
void func_ov000_02164420(void *self);
void func_ov000_0216f168(Buffer0216f144 *self);

VObj *func_ov000_0216ec64(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb744);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, data_ov000_021cac0c);
    self->vfunc_18();
    func_0203de1c(self);
    return self;
}

BOOL func_ov000_0216ecb0(void) {
    return TRUE;
}

void func_ov000_0216ecb8(void) {
}

VObj *func_ov000_0216ecbc(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb744);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, data_ov000_021cac0c);
    self->vfunc_18();
    return self;
}

VObj *func_ov000_0216ed00(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb798);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, data_ov000_021cac0c);
    self->vfunc_18();
    func_0203de1c(self);
    return self;
}

BOOL func_ov000_0216ed4c(void) {
    return TRUE;
}

void func_ov000_0216ed54(void) {
}

VObj *func_ov000_0216ed58(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb798);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, data_ov000_021cac0c);
    self->vfunc_18();
    return self;
}

VObj *func_ov000_0216ed9c(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb7ec);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, data_ov000_021cac0c);
    self->vfunc_18();
    func_0203de1c(self);
    return self;
}

BOOL func_ov000_0216ede8(void) {
    return TRUE;
}

void func_ov000_0216edf0(void) {
}

VObj *func_ov000_0216edf4(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb7ec);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, data_ov000_021cac0c);
    self->vfunc_18();
    return self;
}

VObj *func_ov000_0216ee38(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb840);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, data_ov000_021cac0c);
    self->vfunc_18();
    func_0203de1c(self);
    return self;
}

BOOL func_ov000_0216ee84(void) {
    return TRUE;
}

void func_ov000_0216ee8c(void) {
}

VObj *func_ov000_0216ee90(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb840);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, data_ov000_021cac0c);
    self->vfunc_18();
    return self;
}

VObj *func_ov000_0216eed4(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb894);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, data_ov000_021cac0c);
    self->vfunc_18();
    func_0203de1c(self);
    return self;
}

BOOL func_ov000_0216ef20(void) {
    return TRUE;
}

void func_ov000_0216ef28(void) {
}

VObj *func_ov000_0216ef2c(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb894);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, data_ov000_021cac0c);
    self->vfunc_18();
    return self;
}

VObj *func_ov000_0216ef70(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb6f0);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, data_ov000_021cac0c);
    self->vfunc_18();
    func_0203de1c(self);
    return self;
}

BOOL func_ov000_0216efbc(void) {
    return TRUE;
}

void func_ov000_0216efc4(void) {
}

VObj *func_ov000_0216efc8(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb6f0);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, data_ov000_021cac0c);
    self->vfunc_18();
    return self;
}

BOOL func_ov000_0216f00c(void) {
    return FALSE;
}

Buffer0216f144 *func_ov000_0216f014(Buffer0216f144 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb6b0);
    func_ov000_02164420(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cb6d0);
    func_ov000_0216f168(self);
    func_0203de1c(self);
    return self;
}

Buffer0216f144 *func_ov000_0216f050(Buffer0216f144 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb6b0);
    func_ov000_02164420(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cb6d0);
    func_ov000_0216f168(self);
    return self;
}

Buffer0216f144 *func_ov000_0216f084(Buffer0216f144 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb6d0);
    func_ov000_0216f168(self);
    func_0203de1c(self);
    return self;
}

void func_ov000_0216f0ac(Buffer0216f144 *self) {
    if (self->unk_14 != NULL) {
        self->unk_14(self);
    }
}

void func_ov000_0216f0c4(Buffer0216f144 *self) {
    if (self->unk_10 != NULL) {
        self->unk_10(self);
    }
}

static inline BOOL func_0216f0dc_Check(void) {
    if (data_02097d78.unk_0c == 4) {
        return TRUE;
    }
    return data_02097d78.unk_04 == 4;
}

void func_ov000_0216f0dc(void) {
    if (func_0216f0dc_Check()) {
        func_0203cb78(0xa000, 0, 1);
    }
}

Buffer0216f144 *func_ov000_0216f124(Buffer0216f144 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb6d0);
    func_ov000_0216f168(self);
    return self;
}

void func_ov000_0216f144(Buffer0216f144 *self) {
    self->unk_04 = 0;
    self->unk_08 = 0;
    self->unk_0c = NULL;
    self->unk_10 = NULL;
    self->unk_14 = NULL;
    self->unk_18 = 0;
    self->unk_1c = 0;
}

void func_ov000_0216f168(Buffer0216f144 *self) {
    if ((self->unk_04 & 0x20) && self->unk_0c != NULL) {
        func_0203df0c(self->unk_0c);
    }
    self->unk_04 = 0;
    self->unk_08 = 0;
    self->unk_0c = NULL;
    self->unk_10 = NULL;
    self->unk_14 = NULL;
    self->unk_18 = 0;
    self->unk_1c = 0;
}

}
