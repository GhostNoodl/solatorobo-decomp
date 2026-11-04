#include "ov006/Tasks.h"
#include "Main/Gfx/GfxMgr.h"

extern "C" {

void TaskHost_Create(int a, int b);
void ov006_Winnings_SetupPrices(ov006_Task021ec040 *self);
void ov006_Winnings_BuildShopList(ov006_Task021ec040 *self);

BOOL Ov006Vt_021ec040_Start(ov006_Task021ec040 *self) {
    switch (self->subState) {
    case 0:
        TaskHost_Create(0x23, 0);
        gGfxSys->unk_8b0[0] |= 0x30;
        *(vu16 *)0x4000060 = (*(vu16 *)0x4000060 & ~0x3000) | 0x20;
        self->subState++;
    case 1:
        if (gFinishingTask != NULL) {
            gFinishingTask->vfunc_4c();
            gOv006Menu->unk15E = 2;
            ov006_Winnings_SetupPrices(self);
            ov006_Winnings_BuildShopList(self);
            return TRUE;
        }
        break;
    }
    return FALSE;
}

}
