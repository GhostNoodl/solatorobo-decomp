#include "ov000/VObj.h"
#include "ov000/Vec.h"

extern "C" {

void func_ov000_02152f8c(void *self, s32 a, VecFx32 *v, s32 d);

void func_ov000_021c6d28(void *self, s32 a, VecFx32 *v, s32 d) {
    VecFx32 tmp;
    tmp.x = v->x;
    tmp.y = v->y;
    tmp.z = v->z;
    tmp.y -= *(s32 *)((u8 *)self + 0xc0) << 15;
    func_ov000_02152f8c(self, a, &tmp, d);
}

}
