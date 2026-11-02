#include "ov000/VObj.h"
#include "ov000/Vec.h"
#include "ov000/ModelPart.h"
#include "ov000/FieldMgr.h"

#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 28;
} Bits4;

extern "C" {
s32 FX_Div(s32 a, s32 b);
BOOL func_01ffc318(VecFx32 *a, FieldExit *item, VecFx32 *min, VecFx32 *max, VecFx16 *rot);

FieldExit *FieldMgr_FindExitAt(FieldMgr *self, VecFx32 *pos) {
    FieldExit *ret = NULL;
    FieldExit *item;
    u8 i;
    if (self->blockB != NULL) {
        item = self->exits;
        for (i = 0; i < self->blockB->count0; i++, item++) {
            VecFx32 max;
            VecFx32 min;
            VecFx16 rot;
            max.x = item->hx << 4;
            max.y = item->hy << 4;
            max.z = item->hz << 4;
            min.x = -max.x;
            min.y = -max.y;
            min.z = -max.z;
            rot.y = item->rot;
            rot.x = 0;
            rot.z = 0;
            if (func_01ffc318(pos, item, &min, &max, &rot)) {
                ret = item;
                break;
            }
        }
    }
    return ret;
}

}
