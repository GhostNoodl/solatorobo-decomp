#include "ov000/LoCommon.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"
#include "ov000/UiObj.h"
#include "Main/Res/ResArc.h"

typedef struct {
    u32 a : 8;
    u32 b : 8;
    u32 c : 9;
    u32 d : 7;
    u32 f : 10;
    u32 rest : 22;
} LoGlyphEnt;

extern "C" {

extern void *gMsgRes;
void *MsgRes_GetString(void *a, s32 b);
extern u8 UiObj_vtbl[];
extern u8 UiList_vtbl[];
extern u8 Ov000Vt_021cb1b0_vtbl[];
extern u8 Ov000Vt_021cb0b8_vtbl[];
extern const char *ResName_WifiCells;
extern const char *ArcPath_MenuWifi;
extern const char *ResName_CommonCells;
extern const char *ArcPath_Menu;

BOOL Obj02152e5c_LoadModel(UiObj *self) {
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

}
