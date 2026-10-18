#include "ov000/LoCommon.h"

extern "C" {

extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbbe0[];
extern u8 data_0208ba70[];
extern u8 *data_0214a424;
extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
void func_0204c7d0(void *p);
void func_0203cc58(s32 a, s32 b, s32 c);
s32 func_02012ab8(s32 a, s32 b);
void func_02043d20(void *a, s32 b);
void func_0202a3ec(s32 cmd, void *data, s32 count);
void func_ov000_0217558c(void *self);

VObj *func_ov000_021740b0(void) {
    VObj *obj = (VObj *)func_0203dd9c(0x4b0);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbbe0);
        VOBJ_SET_VTABLE((u8 *)obj + 0x60, data_0208ba70);
        func_0204c7d0((u8 *)obj + 0x60);
        VOBJ_SET_VTABLE((u8 *)obj + 0x118, data_0208ba70);
        func_0204c7d0((u8 *)obj + 0x118);
        VOBJ_SET_VTABLE((u8 *)obj + 0x1d0, data_0208ba70);
        func_0204c7d0((u8 *)obj + 0x1d0);
        VOBJ_SET_VTABLE((u8 *)obj + 0x288, data_0208ba70);
        func_0204c7d0((u8 *)obj + 0x288);
        VOBJ_SET_VTABLE((u8 *)obj + 0x340, data_0208ba70);
        func_0204c7d0((u8 *)obj + 0x340);
        VOBJ_SET_VTABLE((u8 *)obj + 0x3f8, data_0208ba70);
        func_0204c7d0((u8 *)obj + 0x3f8);
        obj->vfunc_58();
    }
    obj->vfunc_08(2, 100);
    return obj;
}

}
