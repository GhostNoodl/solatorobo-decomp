#include "ov013/ov013.h"

extern "C" {

extern void *data_02097e4c;
extern char data_ov013_0220be94[];
extern void func_ov000_02191418(void *a, s32 b, s32 c);
extern void func_0204a028(void *a, s32 b, Ov013Vec *c, s32 d);

void func_ov013_022074fc(Ov013Actor *self) {
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be94, 0x2ab, 0);
        func_ov000_02191418(self->unk_38, 5, 1);
        FLD(u16, self, 0xb4) = 0;
        self->unk_b6 = 0;
        func_0204a028(data_02097e4c, 0x6a, &self->pos, -3);
        self->unk_40->state = 10;
        self->unk_40->timer = 0;
        break;
    case 10:
        if (func_ov000_02191120(self->unk_38)) {
            func_ov000_02198360(self->unk_40, 1, 0);
            self->unk_b6 = 0x3c;
        }
        break;
    }
}

}
