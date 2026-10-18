#include "ov009/ov009.h"

extern "C" {

extern void *data_0214a420;
extern void func_02065804(void *mgr, void *p);

void func_ov009_02203b8c(Ov009Actor *self) {
    func_ov003_021d1e8c(self);
    if (self->unk_40->unk_13 == 0xf) {
        return;
    }
    func_02065804(data_0214a420, FLD(void *, self, 0xf0));
    FLD(void *, self, 0xf0) = NULL;
}

}
