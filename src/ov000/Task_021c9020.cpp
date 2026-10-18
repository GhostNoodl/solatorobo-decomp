#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021ccc94[];
extern void *data_0208cc94;
extern char data_ov000_021ccc68[];
extern char data_ov000_021ccc72[];
extern char data_ov000_021ccc7e[];
extern u8 data_ov002_021f0f90;
void *func_0203dd9c(u32 size);
void func_02043858(void *p);
void func_020359d0(void *p, s32 a, s32 b);
void func_020359fc(void *p, void *q, s32 a, s32 b);
BOOL func_02035b90(void *p, s32 a);
BOOL func_02035bd4(void *p, void *q, s32 a);
void func_ov000_02173648(void *self);

VObj *func_ov000_021c9020(void) {
    VObj *obj = (VObj *)func_0203dd9c(0x1c4);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021ccc94);
        func_02043858((u8 *)obj + 0x40);
        *(s32 *)((u8 *)obj + 0x3c) = 0;
        *((u8 *)obj + 0x1c0) = 0;
    }
    obj->vfunc_08(0x1a, 0xc8);
    return obj;
}

void func_ov000_021c908c(void) {
    func_020359d0(data_0208cc94, 7, 0);
    func_020359d0(data_ov000_021ccc68, 7, 0);
    func_020359fc(data_ov000_021ccc72, data_ov000_021ccc7e, 2, 0);
}

BOOL func_ov000_021c90e4(void) {
    BOOL ok = func_02035b90(data_0208cc94, 7) ? TRUE : FALSE;
    ok = (ok & func_02035b90(data_ov000_021ccc68, 7)) ? TRUE : FALSE;
    return (ok & func_02035bd4(data_ov000_021ccc72, data_ov000_021ccc7e, 2)) ? TRUE : FALSE;
}

void func_ov000_021c914c(VObj *self) {
    *(u32 *)((u8 *)self + 0x4) &= ~2;
    if (self->vfunc_28()) {
        return;
    }
    *(s32 *)((u8 *)self + 0x20) = 0x1000;
    data_ov002_021f0f90 = 0;
    func_ov000_02173648(self);
}

}
