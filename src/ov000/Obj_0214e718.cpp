#include "ov000/VObj.h"

class Obj0214e718 : public VObj {
public:
    u8 unk_04[0x4c];
    VObj *unk_50;
    u8 unk_54[0x6c];
    u8 unk_c0;
};

extern "C" {

extern u8 Task_vtbl[];
extern u8 Lo021caa44_vtbl[];

void *Heap_Alloc(u32 size);
Obj0214e718 *Task_FindById(s32 id);
s32 func_02061e7c(s32 a);

s32 UiList_GetTextX(Obj0214e718 *self) {
    s32 value = self->vfunc_30();
    return self->unk_c0 + value + 0x12;
}

s32 UiList_GetPadLeft(void) {
    return 0xc;
}

VObj *Lo021caa44_New(void) {
    VObj *obj = (VObj *)Heap_Alloc(0x68);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, Task_vtbl);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, Lo021caa44_vtbl);
        obj->vfunc_58();
    }
    obj->vfunc_08(0xe, 0xc8);
    return obj;
}

void func_ov000_0214e7ac(s32 id) {
    VObj *obj = Task_FindById(0xe)->unk_50;
    obj->vfunc_74(func_02061e7c(id), id, 0xffff, 0xffff);
}

}
