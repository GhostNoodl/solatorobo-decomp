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

BOOL func_ov000_02178010(void *self, void *msg) {
    void *o = LFLD(void *, self, 8);
    if (msg == NULL || LFLD(u16, msg, 6) == 0xffff) {
        VObj *p = LFLD(VObj *, o, 0x40);
        func_ov000_0215bb14(p, func_0204c0e8(data_02149ef8, 0x9d));
        p->vfunc_70();
    } else {
        VObj *p = LFLD(VObj *, o, 0x40);
        func_0206ecd4(0x100, (u8 *)o + 0x58, LFLD(u16, msg, 6));
        func_ov000_0215bb14(p, (u8 *)o + 0x58);
        p->vfunc_70();
        if (LFLD(void *, o, 0x48) != NULL) {
            func_ov000_0215d980(LFLD(void *, o, 0x48), LFLD(u8, data_0214a424 + (u16)(LFLD(u16, msg, 6) & 0xfff), 0x2a), 1);
        }
        o = LFLD(void *, o, 0x4c);
        if (o != NULL) {
            func_ov000_0215d980(o, func_0206d1d4(data_0214a424, LFLD(u16, msg, 6)), 1);
        }
    }
    return TRUE;
}

}
