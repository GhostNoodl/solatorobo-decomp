#include "ov000/LoCommon.h"

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208ba30[];
extern u8 data_ov000_021cba18[];
extern u8 data_ov000_021cba3f[];
extern u8 data_ov000_021cba45[];
extern u8 data_ov000_021cba50[];
extern u16 *data_02097dc8;
extern void *data_02097e4c;
void func_0204bfcc(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0204bfe4(void *p, void *buf, const void *s);
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

void func_ov000_02178fd8(void *self) {
    u8 buf[0x20];
    VObj *obj = (VObj *)func_0203dd9c(0x58);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_0208b318);
        obj->vfunc_08();
        VOBJ_SET_VTABLE(obj, data_0208ba30);
        func_0204bfcc(obj);
    }
    LFLD(VObj *, self, 0x3c) = obj;
    STD_CopyString(buf, data_ov000_021cba18);
    STD_ConcatenateString(buf, data_ov000_021cba3f);
    func_0204bfe4(LFLD(VObj *, self, 0x3c), buf, data_ov000_021cba45);
}

BOOL func_ov000_02179064(void *self) {
    BOOL r = TRUE;
    if (!LFLD(VObj *, self, 0x3c)->vfunc_2c()) {
        r = FALSE;
    }
    if (!LoTaskObj()->vfunc_2c()) {
        r = FALSE;
    }
    return r;
}

}
