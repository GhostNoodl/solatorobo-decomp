#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov000_021ccc94[];
extern u8 data_ov000_021cc060[];
extern void *data_02097cdc;
extern void *data_0208cc94;
extern char data_ov000_021ccc68[];
extern char data_ov000_021ccc72[];
extern char data_ov000_021ccc7e[];
void func_02036838(void *a, void *b, s32 c, s32 d);
void func_02035acc(void *a, void *b, s32 c);
void func_0203de1c(void *ptr);

static inline void Obj021ccc94_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021ccc94);
    func_02036838(data_02097cdc, data_0208cc94, 7, 0);
    func_02036838(data_02097cdc, data_ov000_021ccc68, 7, 0);
    func_02035acc(data_ov000_021ccc72, data_ov000_021ccc7e, 2);
    VOBJ_SET_VTABLE(self, data_ov000_021cc060);
    self->vfunc_5c();
}

VObj *func_ov000_021c96ec(VObj *self) {
    Obj021ccc94_Dtor(self);
    func_0203de1c(self);
    return self;
}

VObj *func_ov000_021c9788(VObj *self) {
    Obj021ccc94_Dtor(self);
    return self;
}

}
