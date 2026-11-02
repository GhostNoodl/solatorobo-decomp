#include "ov000/VObj.h"
#include "Main/Gfx/GfxMgr.h"

extern "C" {

void Gfx3D_SendDL(void *p, s32 a);
void func_ov000_021badd4(void *self);

void func_ov000_021bac78(void *self) {
    s32 state = *(s32 *)((u8 *)self + 0x4);
    if (state != 0xb && state != 0xc && state != 0xd) {
        return;
    }
    Gfx3D_SendDL(data_02097d48->unk_8b0, 0);
    func_ov000_021badd4(self);
}

}
