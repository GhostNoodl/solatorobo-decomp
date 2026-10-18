#include "ov000/LoCommon.h"

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208bf54[];
extern u8 data_ov000_021cba18[];
extern u8 data_ov000_021cba20[];
extern u8 data_ov000_021cba28[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbe60[];
extern u8 *data_0214a424;
extern void *data_02149ef8;
extern void *data_02097e4c;
extern u16 *data_02097dc8;
extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_0205a6a0(void *p);
void func_0201e520(void *buf, const void *s);
void func_0201e78c(void *buf, const void *s);
void func_0205a840(void *p, void *buf, const void *s);
void *func_0204c0e8(void *p, s32 a);
void func_ov000_0215bb14(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215d980(void *a, s32 b, s32 c);
s32 func_0206d1d4(void *a, u16 b);
void func_02043d20(void *a, s32 b);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 count);

void func_ov000_021765c8(void) {
    u8 buf[0x20];
    if (LFLD(s8, data_ov000_021ccd34, 1) == 0) {
        VObj *obj;
        LO_FREE_V(data_ov000_021ccd34, 0x14);
        obj = (VObj *)func_0203dd9c(0xc4);
        if (obj != NULL) {
            VOBJ_SET_VTABLE(obj, data_0208b318);
            obj->vfunc_08();
            VOBJ_SET_VTABLE(obj, data_0208bf54);
            func_0205a6a0(obj);
        }
        LFLD(VObj *, data_ov000_021ccd34, 0x14) = obj;
        func_0201e520(buf, data_ov000_021cba18);
        func_0201e78c(buf, data_ov000_021cba20);
        func_0205a840(LFLD(VObj *, data_ov000_021ccd34, 0x14), buf, data_ov000_021cba28);
    }
    LFLD(s8, data_ov000_021ccd34, 1) = LFLD(s8, data_ov000_021ccd34, 1) + 1;
}

}
