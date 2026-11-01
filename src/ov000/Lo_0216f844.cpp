#include "ov000/LoCommon.h"

extern "C" {

extern void *data_02097e4c;
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_0216f23c(void *p, s32 a);

struct Obj0216f844 {
    u8 unk_00[0x20];
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    VObj *unk_30;
};

void func_ov000_0216f844(Obj0216f844 *self, s32 a) {
    if (self->unk_2c == 0) {
        if (a == self->unk_28) {
            if (self->unk_30 != NULL) {
                self->unk_30->vfunc_0c();
            }
            return;
        }
        self->unk_2c = a;
        self->unk_20 = 3;
        self->unk_24 = 0;
    } else if (a != self->unk_2c) {
        self->unk_2c = a;
        self->unk_20 = 3;
        self->unk_24 = 0;
    }
}

}
