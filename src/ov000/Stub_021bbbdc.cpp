#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x50];
    s32 unk_50;
    u8 unk_54[0x8];
    VObj *unk_5c;
} Obj021bbbdc;

extern "C" {

extern u8 *data_02097d48;
void func_02043d20(void *p, s32 a);
void func_ov000_021bbf78(Obj021bbbdc *self);

void func_ov000_021bbbdc(Obj021bbbdc *self) {
    switch (self->unk_50) {
    case 6:
    case 11:
    case 12:
    case 13:
        func_02043d20(data_02097d48 + 0x8b0, 0);
        func_ov000_021bbf78(self);
        if (self->unk_5c != NULL) {
            self->unk_5c->vfunc_20();
        }
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
    case 9:
    case 10:
        break;
    }
}

}
