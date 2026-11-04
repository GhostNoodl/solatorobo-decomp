#include "ov000/VObj.h"
#include "ov000/FieldMgr.h"

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

extern "C" {

BOOL FieldProp_DrawModel(FieldPropModel *p);

void FieldProp_Draw(FieldProp *self) {
    self->visible = FieldProp_DrawModel(&self->model);
}

void FieldProp_SetViewScale(FieldProp *self, s32 x) {
    s32 a = FX_MUL(x, -0xc3000);
    s32 c;
    self->viewMin.y = FX_MUL(x, -0x4e000);
    c = FX_MUL(x, 0xc3000);
    self->viewScale = x;
    self->viewMin.x = a;
    self->viewMin.z = a;
    self->viewMax.x = c;
    self->viewMax.z = c;
    self->viewMax.y = FX_MUL(x, 0x4e000);
}

}
