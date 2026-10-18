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

void func_ov000_021795a4(void *self) {
    void *p = LFLD(void *, self, 0x44);
    u16 v;
    if (p == NULL) {
        return;
    }
    LBIT(p, 0xc).b2 = 0;
    if ((LBIT(LFLD(void *, self, 0x44), 0xc).b0 == 0 ? TRUE : FALSE) == FALSE) {
        return;
    }
    if (LFLD(u16, self, 0x4c) != 0xffff) {
        return;
    }
    v = data_02097dc8[9];
    if (v & 1) {
        return;
    }
    if (!(v & 2)) {
        return;
    }
    func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    if (LFLD(void *, self, 0x40) != NULL) {
        LBIT(LFLD(void *, self, 0x40), 0xc).b1 = 1;
    }
    if (LFLD(void *, self, 0x44) != NULL) {
        LBIT(LFLD(void *, self, 0x44), 0xc).b1 = 1;
    }
}

}
