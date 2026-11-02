#include "ov000/VObj.h"
#include "Main/Gfx/GfxMgr.h"

typedef struct {
    u8 unk_00[0x50];
    s32 unk_50;
    u8 unk_54[0x8];
    VObj *unk_5c;
} Obj021bbbdc;

extern "C" {

void Gfx3D_SendDL(void *p, s32 a);
void func_ov000_021bbf78(Obj021bbbdc *self);

void func_ov000_021bbbdc(Obj021bbbdc *self) {
    switch (self->unk_50) {
    case 6:
    case 11:
    case 12:
    case 13:
        Gfx3D_SendDL(data_02097d48->unk_8b0, 0);
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
