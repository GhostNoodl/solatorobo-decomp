#include "ov000/VObj.h"
#include "ov000/Vec.h"

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208bf54[];
void func_0205a6e8(void *ptr);
void func_0204b2c0(void *self);
void VEC_Add(const void *a, const void *b, void *out);
extern u8 data_ov000_021cc3a0[];
extern u8 data_ov000_021c9d4c[];

typedef struct {
    void *vtable;
    u8 pad_04[0xc];
    VecFx32 unk_10;
    u8 pad_1c[0x9c - 0x1c];
    u8 unk_9c_0 : 1;
    u8 unk_9c_1 : 7;
    u8 pad_9d[0xbc - 0x9d];
    s32 unk_bc;
    s32 unk_c0;
    s32 unk_c4;
    s32 unk_c8;
    s32 unk_cc;
    u8 pad_d0[4];
    s16 unk_d4;
    s16 unk_d6;
    u8 unk_d8;
    u8 pad_d9;
    u8 unk_da;
} Obj02189a74;

VObj *func_ov000_02189a38(VObj *self) {
    VOBJ_SET_VTABLE(self, data_0208bf54);
    func_0205a6e8(self);
    VOBJ_SET_VTABLE(self, data_0208b318);
    self->vfunc_0c();
    return self;
}

Obj02189a74 *func_ov000_02189a74(Obj02189a74 *self) {
    VecFx32 v;
    func_0204b2c0(self);
    self->vtable = data_ov000_021cc3a0;
    v = self->unk_10;
    VEC_Add(&v, data_ov000_021c9d4c, &v);
    self->unk_10 = v;
    self->unk_bc = 0;
    self->unk_c0 = 0;
    self->unk_c4 = 0;
    self->unk_c8 = 0;
    self->unk_cc = 0;
    self->unk_d4 = 0;
    self->unk_d6 = 0;
    self->unk_d8 = 0;
    self->unk_da = 0;
    self->unk_9c_0 = 0;
    return self;
}

}
