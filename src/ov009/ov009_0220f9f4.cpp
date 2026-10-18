#include "ov009/ov009.h"

extern "C" {

extern Ov009Actor *func_ov000_0219bf90(void);

void func_ov009_0220f9f4(Ov009Actor *self) {
    Ov009Actor *a;
    func_ov003_021d112c(self);
    self->unk_90 = 0xffff;
    a = func_ov000_0219bf90();
    if (a != NULL) {
        self->unk_90 = a->id;
    }
}

}
