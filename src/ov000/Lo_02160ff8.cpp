#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"
#include "Main/Res/ResArc.h"

extern "C" {

extern const char *ResName_WifiCells;
extern const char *ArcPath_MenuWifi;
extern const char *ResName_CommonCells;
extern const char *ArcPath_Menu;
extern const char *ResName_BattleCells;
extern const char *ArcPath_MenuBattle;
void TexObj_SetOamFuncArg(void *model, s32 a, void *b);
void TexObj_SetAllOamFuncs(void *model, void *cb);
void *Lo021cacd8_OamCallback(u8 *self, u16 *cmd, void *arr, u16 *count);

static inline BOOL EnsureModel(Lo021cacd8 *self) {
    if (self->model) {
        return TRUE;
    }
    if (self->flag6 ? TRUE : FALSE) {
        MODEL_NEW(self->model, ResName_WifiCells, ArcPath_MenuWifi);
    } else {
        MODEL_NEW(self->model, ResName_CommonCells, ArcPath_Menu);
    }
    {
        ResList *a = ResMgr_GetArcList(self->model->name);
        void *b = ResList_FindType2(a, self->model->unk_04c);
        TexObj_SetRes(self->model, b);
    }
    self->model->flags |= 2;
    TexObj_SelectImage(self->model, 0, 7);
    return TRUE;
}

void Lo021cacd8_Setup(Lo021cacd8 *self) {
    self->width = 0x50;
    self->height = 0x1e;
    self->posX = 0x80;
    self->posY = 0x60;
    self->slideMode = 0;
    self->color = 0x294a;
    MODEL_NEW(self->unk_84, ResName_BattleCells, ArcPath_MenuBattle);
    TexObj_SetRes(self->unk_84, ResList_FindType2(ResMgr_GetArcList(ArcPath_MenuBattle), ResName_BattleCells));
    self->unk_84->flags |= 2;
    TexObj_SelectImage(self->unk_84, 0, 6);
    TexObj_SetOamFuncArg(self->unk_84, 6, self);
    TexObj_SelectImage(self->unk_84, 0, 8);
    TexObj_SetAllOamFuncs(self->unk_84, (void *)Lo021cacd8_OamCallback);
    if (EnsureModel(self)) {
        TexObj_SelectImage(self->model, 0, 10);
        self->model->flags |= 0x80000;
    }
}

}
