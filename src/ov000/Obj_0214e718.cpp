#include "ov000/VObj.h"

class Obj0214e718 : public VObj {
public:
    u8 unk_04[0x4c];
    VObj *unk_50;
    u8 unk_54[0x6c];
    u8 unk_c0;
};

extern "C" {

extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021caa44[];

void *func_0203dd9c(u32 size);
Obj0214e718 *func_ov000_02173610(s32 id);
s32 func_02061e7c(s32 a);

s32 func_ov000_0214e718(Obj0214e718 *self) {
    s32 value = self->vfunc_30();
    return self->unk_c0 + value + 0x12;
}

s32 func_ov000_0214e73c(void) {
    return 0xc;
}

VObj *func_ov000_0214e744(void) {
    VObj *obj = (VObj *)func_0203dd9c(0x68);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021caa44);
        obj->vfunc_58();
    }
    obj->vfunc_08(0xe, 0xc8);
    return obj;
}

void func_ov000_0214e7ac(s32 id) {
    VObj *obj = func_ov000_02173610(0xe)->unk_50;
    obj->vfunc_74(func_02061e7c(id), id, 0xffff, 0xffff);
}

}
