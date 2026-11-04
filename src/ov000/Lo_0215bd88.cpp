#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "ov000/ModelPart.h"
#include "Main/Res/ResArc.h"

extern "C" {
extern const char *ResName_WifiCells;
extern const char *ArcPath_MenuWifi;
extern const char *ResName_CommonCells;
extern const char *ArcPath_Menu;
extern void *ResName_CommonModel;
extern void *ArcPath_MenuLoad;

void Lo021cadcc_Setup(Lo021cadcc *self) {
    self->height = self->vfunc_44();
    if ((s32)self->title != 0 && self->model == NULL) {
        if (self->flag6 ? TRUE : FALSE) {
            self->model = new ModelObj(ResName_WifiCells, ArcPath_MenuWifi);
        } else {
            self->model = new ModelObj(ResName_CommonCells, ArcPath_Menu);
        }
        {
            ResList *a = ResMgr_GetArcList(self->model->name);
            TexObj_SetRes(self->model, ResList_FindType2(a, self->model->unk_04c));
        }
        self->model->flags |= 2;
        TexObj_SelectImage(self->model, 0, 7);
    }
    if (self->flags & 0x10000) {
        self->posX = (0x100 - self->width) >> 1;
    }
    if (self->flags & 0x20000) {
        self->posY = (0xc0 - self->height) >> 1;
    }
    self->busy = 1;
}

}
