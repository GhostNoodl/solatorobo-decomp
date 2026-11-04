#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "Main/Gfx/Model.h"
#include "Main/Res/ResArc.h"

extern "C" {

extern const char *ArcPath_MenuBattle;
extern const char *ResName_BattleCells;

void Lo021cb894_Setup(Lo021cb894 *self) {
    void *res;
    Model *m;
    self->unk_28 = 0;
    self->unk_30 = 0xc000;
    self->unk_50 = 0;
    self->unk_54 = 0;
    self->unk_0c |= 0x2c0;
    self->unk_58 = 1;
    self->unk_74 = 0;
    self->unk_78 = 0;
    self->unk_7c = -0x2000;
    res = ResList_FindType2(ResMgr_GetArcList(ArcPath_MenuBattle), ResName_BattleCells);
    m = (Model *)Heap_Alloc(sizeof(Model));
    if (m) {
        const char *nm = ResName_BattleCells;
        PlttRes_Init_02041218(&m->pltt);
        TexObj_Init(m, nm, 0);
    }
    self->unk_9c = (Model *)(m);
    TexObj_SetRes(m, res);
    self->unk_9c->flags |= 2;
    self->unk_9c->flags |= 0x200000;
    self->unk_9c->flags |= 0x80000;
    TexObj_SelectImage(self->unk_9c, 0, 0x1a);
    TexObj_SelectImage(self->unk_9c, 0, 0x1b);
    TexObj_SelectImage(self->unk_9c, 0, 0x1c);
}

}
