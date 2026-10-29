#include "ov014/ov014.h"

extern "C" {

extern char data_ov014_022170d8[];
extern char data_ov014_022170e7[];
extern char data_ov014_022170f4[];
extern void *data_02097e4c;
extern void func_02049564(void *a, s32 b, s32 c);
extern void func_ov000_02187a20(void *a, s32 b);
extern void *func_020359d0(const char *a, s32 b, s32 c);

void func_ov014_021fa838(Ov014Actor *self) {
    func_ov003_021d0fc0(self);
    {
        const char *a = data_ov014_022170e7;
        const char *b = data_ov014_022170f4;
        Ov014Names *n = &FLD(Ov014Names, self, 0x124);
        if (a) {
            STD_CopyString(n->unk_10, a);
            STD_CopyString(n->unk_30, b);
            n->unk_03_1 = 1;
            STD_CopyString(n->unk_4c, a);
            STD_CopyString(n->unk_6c, b);
            n->unk_03_2 = 1;
        }
        n->unk_00 = 0;
    }
    func_02049564(data_02097e4c, 1, 1);
    func_ov000_02187a20(data_ov000_021ccd54, 9);
    func_ov000_02187a20(data_ov000_021ccd54, 10);
    func_020359d0(data_ov014_022170d8, 7, 0);
}

}
