#include "ov009/ov009.h"

extern "C" {

extern char data_ov009_0221729c[];
extern char data_ov009_022172a7[];

void func_ov009_02207614(Ov009Actor *self) {
    func_ov003_021d0fc0(self);
    {
        const char *a = data_ov009_0221729c;
        const char *b = data_ov009_022172a7;
        Ov009Names *n = &FLD(Ov009Names, self, 0xf0);
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
}

}
