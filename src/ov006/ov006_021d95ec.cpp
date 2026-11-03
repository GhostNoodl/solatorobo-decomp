#include "ov006/Tasks.h"
#include "Main/Gfx/GfxMgr.h"

extern "C" {

void TaskHost_Create(int a, int b);
void ov006_Task021ec040_SetupPrices(ov006_Task021ec040 *self);
void ov006_Task021ec040_BuildShopList(ov006_Task021ec040 *self);

BOOL Ov006Vt_021ec040_Start(ov006_Task021ec040 *self) {
    switch (self->subState) {
    case 0:
        TaskHost_Create(0x23, 0);
        data_02097d48->unk_8b0[0] |= 0x30;
        *(vu16 *)0x4000060 = (*(vu16 *)0x4000060 & ~0x3000) | 0x20;
        self->subState++;
    case 1:
        if (data_ov000_021ccd40 != NULL) {
            data_ov000_021ccd40->vfunc_4c();
            data_ov006_021ec888->unk15E = 2;
            ov006_Task021ec040_SetupPrices(self);
            ov006_Task021ec040_BuildShopList(self);
            return TRUE;
        }
        break;
    }
    return FALSE;
}

}
