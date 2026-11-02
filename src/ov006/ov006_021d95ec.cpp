#include "ov006/Tasks.h"
#include "Main/Gfx/GfxMgr.h"

extern "C" {

void func_ov000_02180660(int a, int b);
void func_ov006_021da098(ov006_Task021ec040 *self);
void func_ov006_021da208(ov006_Task021ec040 *self);

BOOL func_ov006_021d95ec(ov006_Task021ec040 *self) {
    switch (self->subState) {
    case 0:
        func_ov000_02180660(0x23, 0);
        data_02097d48->unk_8b0[0] |= 0x30;
        *(vu16 *)0x4000060 = (*(vu16 *)0x4000060 & ~0x3000) | 0x20;
        self->subState++;
    case 1:
        if (data_ov000_021ccd40 != NULL) {
            data_ov000_021ccd40->vfunc_4c();
            data_ov006_021ec888->unk15E = 2;
            func_ov006_021da098(self);
            func_ov006_021da208(self);
            return TRUE;
        }
        break;
    }
    return FALSE;
}

}
