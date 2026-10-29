#include "ov000/LoCommon.h"

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208bf54[];
extern u8 data_ov000_021ca8f7[];
extern u8 data_ov000_021ca8ff[];
extern u8 data_ov000_021ca917[];
extern s32 data_ov000_021ca8d8;
extern u8 data_ov000_021ccd24[];
void func_0205a6a0(void *p);
void *STD_CopyString(void *buf, const void *s);
void *STD_ConcatenateString(void *buf, const void *s);
void func_0205a840(void *p, void *buf, const void *s);

void func_ov000_021501e4(u8 *self) {
    u8 buf[0x20];
    VObj *obj;
    if (LFLD(u16, self, 0x42) == 0xffff) {
        obj = (VObj *)func_0203dd9c(0xc4);
        if (obj != NULL) {
            VOBJ_SET_VTABLE(obj, data_0208b318);
            obj->vfunc_08();
            VOBJ_SET_VTABLE(obj, data_0208bf54);
            func_0205a6a0(obj);
        }
        LFLD(VObj *, data_ov000_021ccd24, 8) = obj;
        STD_CopyString(buf, data_ov000_021ca8f7);
        STD_ConcatenateString(buf, data_ov000_021ca8ff);
        func_0205a840(LFLD(VObj *, data_ov000_021ccd24, 8), buf, data_ov000_021ca917);
    }
    obj = (VObj *)func_0203dd9c(0x4c);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_0208b318);
        obj->vfunc_08();
    }
    LFLD(VObj *, self, 0x3c) = obj;
    LFLD(s32, obj, 0x44) = 7;
    LFLD(VObj *, self, 0x3c)->vfunc_1c(data_ov000_021ca8d8);
}
}
