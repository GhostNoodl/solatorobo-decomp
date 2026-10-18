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
void func_0202a3ec(s32 cmd, void *data, s32 count);

void func_ov000_02178a5c(void *self) {
    u16 v;
    if (LFLD(s32, LFLD(void *, self, 0x54), 4) != 5) {
        return;
    }
    v = data_02097dc8[9];
    if (v & 1) {
        func_ov000_0215d980(LFLD(void *, self, 0x44), LFLD(s32, LFLD(void *, self, 0x44), 0x8c), 1);
        return;
    }
    if (!(v & 2)) {
        return;
    }
    LBIT(LFLD(void *, self, 0x3c), 0xc).b1 = 1;
    LBIT(LFLD(void *, self, 0x40), 0xc).b1 = 1;
    LBIT(LFLD(void *, self, 0x44), 0xc).b1 = 1;
    if (LFLD(void *, self, 0x48) != NULL) {
        LBIT(LFLD(void *, self, 0x48), 0xc).b1 = 1;
    }
    if (LFLD(void *, self, 0x4c) != NULL) {
        LBIT(LFLD(void *, self, 0x4c), 0xc).b1 = 1;
    }
    LBIT(LFLD(void *, self, 0x50), 0xc).b1 = 1;
}

}
