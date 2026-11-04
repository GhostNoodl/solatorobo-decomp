#include "ov000/LoCommon.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/TextWin.h"

typedef struct {
    u32 b0 : 2;
    u32 f2 : 5;
    u32 rest : 25;
} LoF2;

extern "C" {

void Lo021cb5a8_DrawFrameOam(BOOL skip, s32 x, s32 y, s32 z, s32 unused, const void *oam, const void *img, u32 charBase, u32 plttBase, s32 unused2, const void *ctx);

void UiObj_Release(UiObj *self) {
    self->vfunc_48(1, 0);
    HEAP_DELETE_MODEL(self->model);
    HEAP_DELETE(TextWin *, self->title, p->unk_vf04());
    HEAP_DELETE(TextWin *, self->caption, p->unk_vf04());
}

}
