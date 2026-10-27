#include "ov000/VObj.h"
#include "ov000/Vec.h"
#include "ov000/ModelPart.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 28;
} Bits4;

typedef struct {
    u8 unk_00[0xc];
    s16 hx, hy, hz;
    u16 rot;
    u8 unk_14[0x10];
} Item021b68b8;

typedef struct {
    s16 x, y, z;
} Rot3;

extern "C" {
s32 FX_Div(s32 a, s32 b);
BOOL func_01ffc318(void *a, Item021b68b8 *item, VecFx32 *min, VecFx32 *max, Rot3 *rot);

Item021b68b8 *func_ov000_021b68b8(u8 *self, void *arg) {
    Item021b68b8 *ret = NULL;
    Item021b68b8 *item;
    u8 i;
    if (LFLD(u8 *, self, 0x14) != NULL) {
        item = LFLD(Item021b68b8 *, self, 0x18);
        for (i = 0; i < LFLD(u8 *, self, 0x14)[0x14]; i++, item++) {
            VecFx32 max;
            VecFx32 min;
            Rot3 rot;
            max.x = item->hx << 4;
            max.y = item->hy << 4;
            max.z = item->hz << 4;
            min.x = -max.x;
            min.y = -max.y;
            min.z = -max.z;
            rot.y = item->rot;
            rot.x = 0;
            rot.z = 0;
            if (func_01ffc318(arg, item, &min, &max, &rot)) {
                ret = item;
                break;
            }
        }
    }
    return ret;
}

}
