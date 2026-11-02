#include "ov013/ov013.h"

extern "C" {

extern char data_ov013_0220ba58[];
extern char data_ov013_0220ba60[];
void func_ov000_0219433c(void *self);
void *func_ov000_0218e9c4(void *p);

void Ov013ActEx_02204454_Init(Ov013ActEx_02204454 *self) {
    Ov013Names *n;
    func_ov000_0219433c(self);
    n = (Ov013Names *)Heap_Alloc(0x138);
    if (n != NULL) {
        n = (Ov013Names *)func_ov000_0218e9c4(n);
    }
    self->unk_dc = n;
    {
        const char *b = data_ov013_0220ba58;
        if (b) {
            STD_CopyString(n->unk_10, data_ov013_0220ba60);
            STD_CopyString(n->unk_30, b);
            n->unk_03_1 = 1;
        }
    }
    self->unk_dc->unk_00 = 0;
}

}
