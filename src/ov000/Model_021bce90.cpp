#include "types.h"
#include "ov000/Bss021ccd74.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"
#include "Main/Res/ResArc.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
extern const char *ArcPath_Menu;
extern const char *ResName_CommonCells;
extern const char *ArcPath_MenuBattle;
extern const char *ResName_BattleCells;
extern const char *ResName_TextCells;
extern char gCommonTextPath[];
void *Heap_Alloc(u32 size);

void Bss021ccd74_LoadModels(void) {
    void *res;
    Model *m;
    res = ResList_FindType2(ResMgr_GetArcList(ArcPath_Menu), ResName_CommonCells);
    MODEL_NEW(m, ResName_CommonCells, ArcPath_Menu);
    data_ov000_021ccd74.unk_0c = m;
    TexObj_SetRes(m, res);
    data_ov000_021ccd74.unk_0c->flags |= 2;
    TexObj_SelectImage(data_ov000_021ccd74.unk_0c, 0, 0);
    TexObj_SelectImage(data_ov000_021ccd74.unk_0c, 0, 1);
    TexObj_SelectImage(data_ov000_021ccd74.unk_0c, 0, 2);
    TexObj_SelectImage(data_ov000_021ccd74.unk_0c, 0, 3);
    TexObj_SelectImage(data_ov000_021ccd74.unk_0c, 0, 0xf);
    res = ResList_FindType2(ResMgr_GetArcList(ArcPath_MenuBattle), ResName_BattleCells);
    MODEL_NEW(m, ResName_BattleCells, ArcPath_MenuBattle);
    data_ov000_021ccd74.unk_14 = m;
    TexObj_SetRes(m, res);
    data_ov000_021ccd74.unk_14->flags |= 2;
    TexObj_SelectImage(data_ov000_021ccd74.unk_14, 0, 2);
    res = ResList_FindType2(ResMgr_GetArcList(gCommonTextPath), ResName_TextCells);
    MODEL_NEW(m, ResName_TextCells, gCommonTextPath);
    data_ov000_021ccd74.unk_04 = m;
    TexObj_SetRes(m, res);
    data_ov000_021ccd74.unk_04->flags |= 2;
    TexObj_SelectImage(data_ov000_021ccd74.unk_04, 0, 6);
}
}
