#include "ov012/ov012.h"

extern "C" {

extern char data_ov012_0220ab08[];
extern char data_ov012_0220ab10[];

void func_ov012_021fa80c(Ov012Actor *self) {
    func_ov003_021d0fc0(self);
    FLD(s16, self, 0xf0) = self->unk_18;
    func_02049564(data_02097e4c, 1, 1);
    func_ov000_02187a20(data_ov000_021ccd54, 5);
    func_020359d0(data_ov012_0220aaf9, 7, 0);
    if (FLD(s16, self, 0xf0) == 1) {
        func_ov000_02187a20(data_ov000_021ccd54, 6);
        {
            const char *b = data_ov012_0220ab08;
            Ov012Names *n = &FLD(Ov012Names, self, 0x174);
            if (b) {
                STD_CopyString(n->unk_10, data_ov012_0220ab10);
                STD_CopyString(n->unk_30, b);
                n->unk_03_1 = 1;
            }
            n->unk_00 = 0;
        }
    }
}

}
