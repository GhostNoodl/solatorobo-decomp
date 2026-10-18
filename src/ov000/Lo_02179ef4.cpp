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

void func_ov000_02179ef4(VObj *self) {
    s32 n;
    VObj *p;
    if (LFLD(s32, self, 8) != 0xd) {
        return;
    }
    n = 0;
    p = LFLD(VObj *, self, 0x40);
    if (p != NULL && p->vfunc_1c()) {
        n++;
    }
    p = LFLD(VObj *, self, 0x44);
    if (p != NULL && p->vfunc_1c()) {
        n++;
    }
    if (n != 0) {
        return;
    }
    self->vfunc_0c(0);
}

void func_ov000_02179f6c(void *self) {
    s32 s;
    if (LFLD(s32, self, 0x24) == 0 || (s = LFLD(s32, self, 8)) == 0) {
        return;
    }
    if (s != 0xc && s != 0xd) {
        return;
    }
    if (LFLD(VObj *, self, 0x40) != NULL) {
        LFLD(VObj *, self, 0x40)->vfunc_20();
    }
    if (LFLD(VObj *, self, 0x44) != NULL) {
        LFLD(VObj *, self, 0x44)->vfunc_20();
    }
}

}
