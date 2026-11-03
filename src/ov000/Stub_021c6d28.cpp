#include "ov000/TextList.h"
#include "ov000/Vec.h"

extern "C" {

void UiObj_DrawTitle(UiObj *self, s32 a, VecFx32 *v, s32 d);

void Ov000Vt_021ccadc_DrawTitle(TextList *self, s32 a, VecFx32 *v, s32 d) {
    VecFx32 tmp;
    tmp.x = v->x;
    tmp.y = v->y;
    tmp.z = v->z;
    tmp.y -= self->lift << 15;
    UiObj_DrawTitle(self, a, &tmp, d);
}

}
