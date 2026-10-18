#include "ov000/VObj.h"

typedef struct {
    u32 unk_00;
    u32 unk_04_0 : 4;
    u32 unk_04_4 : 1;
    u32 unk_04_5 : 1;
    u32 unk_04_6 : 1;
    u32 unk_04_7 : 1;
} FlagObj;

typedef struct {
    u32 unk_00;
    s32 state;
} StateObj;

class StateOwner : public VObj {
public:
    u8 unk_04[0x48];
    StateObj *unk_4c;
    StateObj *unk_50;
    u8 unk_54[0x4];
    StateObj *unk_58;
    StateObj *unk_5c;
    StateObj *unk_60;
};

extern "C" {

extern void *data_ov000_021ccd40;
extern u32 data_ov000_021ccd38;
extern u8 data_0208ba70[];
extern u8 data_ov000_021ca9c4[];
extern u8 data_ov000_021caa44[];
extern u8 data_ov000_021cc060[];
void func_0203de1c(void *ptr);

static inline BOOL IsState5(StateObj *obj) {
    return obj->state == 5 ? TRUE : FALSE;
}

static inline void UpdateCurrent(void) {
    if (data_ov000_021ccd40 != NULL) {
        data_ov000_021ccd38 = *(u32 *)((u8 *)data_ov000_021ccd40 + 0x14);
    } else {
        data_ov000_021ccd38 = 0;
    }
    data_ov000_021ccd40 = NULL;
}

static inline BOOL FlagObj_TestMask(FlagObj *self, u32 mask) {
    return (((u32 *)self)[1] & mask) ? TRUE : FALSE;
}

static inline bool FlagObj_TestBit6(FlagObj *self) {
    return self->unk_04_6;
}

static inline bool FlagObj_TestBit5(FlagObj *self) {
    return self->unk_04_5;
}

void func_ov000_021519fc(FlagObj *self) {
    self->unk_04_7 = 1;
}

void func_ov000_02151a0c(void *obj) {
    if (data_ov000_021ccd40 != NULL) {
        data_ov000_021ccd38 = *(u32 *)((u8 *)data_ov000_021ccd40 + 0x14);
    } else {
        data_ov000_021ccd38 = 0;
    }
    data_ov000_021ccd40 = obj;
}

bool func_ov000_02151a40(FlagObj *self, u32 mask) {
    return FlagObj_TestMask(self, mask);
}

void func_ov000_02151a60(FlagObj *self) {
    self->unk_04_7 = 0;
}

bool func_ov000_02151a70(FlagObj *self) {
    return FlagObj_TestBit6(self) != 0;
}

void func_ov000_02151a94(FlagObj *self) {
    self->unk_04_6 = 1;
}

bool func_ov000_02151aa4(FlagObj *self) {
    return FlagObj_TestBit5(self) != 0;
}

void func_ov000_02151ac8(FlagObj *self) {
    self->unk_04_5 = 1;
}

void func_ov000_02151ad8(FlagObj *self) {
    self->unk_04_4 = 0;
}

void func_ov000_02151ae8(FlagObj *self) {
    self->unk_04_4 = 1;
}

BOOL func_ov000_02151af8(void) {
    return TRUE;
}

VObj *func_ov000_02151b00(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021ca9c4);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x3f8), data_0208ba70);
    VOBJ_AT(self, 0x3f8)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x340), data_0208ba70);
    VOBJ_AT(self, 0x340)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x288), data_0208ba70);
    VOBJ_AT(self, 0x288)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x1d0), data_0208ba70);
    VOBJ_AT(self, 0x1d0)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x118), data_0208ba70);
    VOBJ_AT(self, 0x118)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x60), data_0208ba70);
    VOBJ_AT(self, 0x60)->vfunc_08();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    func_0203de1c(self);
    return self;
}

BOOL func_ov000_02151bcc(StateOwner *self) {
    BOOL ok = TRUE;
    if (self->unk_50 != NULL && !IsState5(self->unk_50)) {
        ok = FALSE;
    }
    if (self->unk_4c != NULL && !IsState5(self->unk_4c)) {
        ok = FALSE;
    }
    if (self->unk_58 != NULL && !IsState5(self->unk_58)) {
        ok = FALSE;
    }
    if (!ok) {
        return FALSE;
    }
    if (self->vfunc_54()) {
        UpdateCurrent();
    }
    return TRUE;
}

VObj *func_ov000_02151c9c(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021ca9c4);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x3f8), data_0208ba70);
    VOBJ_AT(self, 0x3f8)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x340), data_0208ba70);
    VOBJ_AT(self, 0x340)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x288), data_0208ba70);
    VOBJ_AT(self, 0x288)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x1d0), data_0208ba70);
    VOBJ_AT(self, 0x1d0)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x118), data_0208ba70);
    VOBJ_AT(self, 0x118)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x60), data_0208ba70);
    VOBJ_AT(self, 0x60)->vfunc_08();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    return self;
}

VObj *func_ov000_02151d60(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021caa44);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
    func_0203de1c(self);
    return self;
}

BOOL func_ov000_02151dac(StateOwner *self) {
    BOOL ok = TRUE;
    if (self->unk_50 != NULL && !IsState5(self->unk_50)) {
        ok = FALSE;
    }
    if (self->unk_4c != NULL && !IsState5(self->unk_4c)) {
        ok = FALSE;
    }
    if (self->unk_5c != NULL && !IsState5(self->unk_5c)) {
        ok = FALSE;
    }
    if (self->unk_60 != NULL && !IsState5(self->unk_60)) {
        ok = FALSE;
    }
    if (!ok) {
        return FALSE;
    }
    if (self->vfunc_54()) {
        UpdateCurrent();
    }
    return TRUE;
}

}
