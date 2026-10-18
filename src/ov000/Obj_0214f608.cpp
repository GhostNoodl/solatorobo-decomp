#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0xc];
    u32 unk_0c;
} Sub0214f770;

typedef struct {
    u8 unk_00[0x50];
    Sub0214f770 *unk_50;
    u8 unk_54[0xc];
    Sub0214f770 *unk_60;
} Obj0214f770;

extern "C" {

extern u8 data_0208ba70[];
extern u8 data_ov000_021ca94c[];
extern u8 data_ov000_021caac8[];
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021cb5a8[];
void func_0203de1c(void *ptr);

VObj *func_ov000_0214f608(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021ca94c);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x148), data_0208ba70);
    VOBJ_AT(self, 0x148)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x90), data_0208ba70);
    VOBJ_AT(self, 0x90)->vfunc_08();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    func_0203de1c(self);
    return self;
}

VObj *func_ov000_0214f684(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb5a8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    func_0203de1c(self);
    return self;
}

VObj *func_ov000_0214f6ec(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021caac8);
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

void func_ov000_0214f770(Obj0214f770 *self) {
    if (self->unk_60 == NULL) {
        return;
    }
    if (self->unk_60->unk_0c & 0x30000) {
        return;
    }
    if (self->unk_50 != NULL) {
        self->unk_50->unk_0c &= ~4;
    }
}

void func_ov000_0214f7a0(void) {
}

}
