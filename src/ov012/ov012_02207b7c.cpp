#include "ov012/ov012.h"

extern "C" {

extern char data_ov012_0220b324[];
extern char data_ov012_0220b32e[];

void func_ov012_02207b7c(Ov012Names *self, void *res) {
    char *a = func_0207011c(res);
    char *b = func_020701d4(res);
    u8 *c = func_02070558(res);
    char *t;
    STD_CopyString(self->unk_10, a);
    STD_CopyString(self->unk_30, b);
    self->unk_03_1 = 1;
    {
        const char *s = data_ov012_0220b324;
        const char *u = data_ov012_0220b32e;
        if (s) {
            STD_CopyString(self->unk_4c, s);
            STD_CopyString(self->unk_6c, u);
            self->unk_03_2 = 1;
            t = FLD(char *, c, 0x28);
            if (t != NULL) {
                STD_CopyString(self->unk_c4, s);
                STD_CopyString(self->unk_e4, t);
                self->unk_03_4 = 1;
            }
        }
    }
    self->unk_00 = 0;
}

}
