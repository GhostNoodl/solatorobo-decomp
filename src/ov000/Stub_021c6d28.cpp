#include "ov000/TextList.h"
#include "ov000/Vec.h"

extern "C" {

void func_ov000_02152f8c(UiObj *self, s32 a, VecFx32 *v, s32 d);

void func_ov000_021c6d28(TextList *self, s32 a, VecFx32 *v, s32 d) {
    VecFx32 tmp;
    tmp.x = v->x;
    tmp.y = v->y;
    tmp.z = v->z;
    tmp.y -= self->lift << 15;
    func_ov000_02152f8c(self, a, &tmp, d);
}

}
