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

extern void *data_02149ef8;
void *MsgRes_GetString(void *a, s32 b);
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
extern const char *data_0208cb84;
extern const char *data_0208cc8c;
extern const char *data_0208cb74;
extern const char *data_0208cca0;

BOOL Obj02152e5c_LoadModel(UiObj *self) {
    if (self->model) {
        return TRUE;
    }
    if (self->flag6 ? TRUE : FALSE) {
        MODEL_NEW(self->model, data_0208cb84, data_0208cc8c);
    } else {
        MODEL_NEW(self->model, data_0208cb74, data_0208cca0);
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
