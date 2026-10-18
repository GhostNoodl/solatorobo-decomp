#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x8];
    s32 unk_08;
    s32 unk_0c;
    u8 unk_10[0x4];
    VObj *unk_14;
} Obj021b9a84;

extern "C" {

extern u8 *data_02097d48;
void func_02043d20(void *p, s32 a);
void func_ov000_021b9b14(Obj021b9a84 *self);
void func_ov000_021ba338(Obj021b9a84 *self);

void func_ov000_021b9a84(Obj021b9a84 *self) {
    switch (self->unk_08) {
    case 11:
    case 12:
    case 13:
        func_02043d20(data_02097d48 + 0x8b0, 0);
        func_ov000_021b9b14(self);
        if (self->unk_0c == 1 || self->unk_0c == 3) {
            func_ov000_021ba338(self);
        }
        break;
    case 14:
    case 15:
        break;
    case 16:
        if (self->unk_14 != NULL) {
            self->unk_14->vfunc_20();
        }
        break;
    }
}

}
