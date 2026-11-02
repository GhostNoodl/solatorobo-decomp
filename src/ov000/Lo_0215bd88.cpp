#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "ov000/ModelPart.h"
#include "Main/Res/ResArc.h"

extern "C" {
extern const char *data_0208cb84;
extern const char *data_0208cc8c;
extern const char *data_0208cb74;
extern const char *data_0208cca0;
extern void *data_0208cb78;
extern void *data_0208cc9c;
VObj *func_ov000_02176208(void);

void Lo021cadcc_Setup(Lo021cadcc *self) {
    self->height = self->vfunc_44();
    if ((s32)self->title != 0 && self->model == NULL) {
        if (self->flag6 ? TRUE : FALSE) {
            self->model = new ModelObj(data_0208cb84, data_0208cc8c);
        } else {
            self->model = new ModelObj(data_0208cb74, data_0208cca0);
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
