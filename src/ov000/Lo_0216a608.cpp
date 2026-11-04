#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "Main/Gfx/Model.h"
#include "Main/Res/ResArc.h"

extern "C" {

extern char gCommonTextPath[];
extern const char *ResName_TextCells;
extern const char *ArcPath_MenuBattle;
extern const char *ResName_BattleCells;
void Obj0215fdfc_SetEntry(ObjBase021cac0c_021cb6f0 *self, s32 a, const void *b);
extern u8 data_ov000_021c9b04[];
extern u8 data_ov000_021c9b0a[];

void Lo021cb744_Setup(Lo021cb744 *self) {
    void *res = ResList_FindType2(ResMgr_GetArcList(gCommonTextPath), ResName_TextCells);
    Model *m = (Model *)Heap_Alloc(sizeof(Model));
    if (m) {
        const char *nm = ResName_TextCells;
        PlttRes_Init_02041218(&m->pltt);
        TexObj_Init(m, nm, 0);
    }
    self->unk_9c = m;
    TexObj_SetRes(m, res);
    self->unk_9c->flags |= 2;
    self->unk_9c->flags |= 0x200000;
    self->unk_9c->flags |= 0x80000;
    TexObj_SelectImage(self->unk_9c, 0, 2);
    {
    Model *m2;
    void *res2;
    res2 = ResList_FindType2(ResMgr_GetArcList(ArcPath_MenuBattle), ResName_BattleCells);
    m2 = (Model *)Heap_Alloc(sizeof(Model));
    if (m2) {
        const char *nm = ResName_BattleCells;
        PlttRes_Init_02041218(&m2->pltt);
        TexObj_Init(m2, nm, 0);
    }
    self->unk_a0 = m2;
    TexObj_SetRes(m2, res2);
    self->unk_a0->flags |= 2;
    self->unk_a0->flags |= 0x200000;
    self->unk_a0->flags |= 0x80000;
    TexObj_SelectImage(self->unk_a0, 0, 0x21);
    }
    self->unk_28 = 2;
    self->unk_30 = 0xc000;
    self->unk_0c |= 0x1a0;
    self->unk_50 = 0x30;
    self->unk_54 = 6;
    self->unk_58 = 1;
    self->unk_38 = 0;
    self->unk_3c = 0x20;
    self->unk_40 = 0;
    self->unk_74 = 0x2d;
    self->unk_78 = 0xae;
    self->unk_7c = 0xffffe666;
    Obj0215fdfc_SetEntry(self, 1, data_ov000_021c9b04);
    Obj0215fdfc_SetEntry(self, 2, data_ov000_021c9b0a);
}

}
