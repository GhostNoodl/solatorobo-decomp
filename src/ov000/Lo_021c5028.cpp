#include "ov000/VObj.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

void func_ov000_021c5028(LoBase021ccb54_021ccbe0 *self, s32 unused, const VecFx32 *pos) {
    VObj *p = self->unk_94;
    s32 i = 0;
    s32 y = pos->y + self->unk_e0;
    s32 x = pos->x;
    s32 z = self->posZ;
    if (p == NULL) {
        return;
    }
    x += 0xc000;
    z -= 0x110;
    do {
        BOOL vis = FALSE;
        switch (self->unk_df) {
        case 0:
            if (i >= self->unk_9c && i <= self->unk_9c + (self->rows - 1)) {
                vis = TRUE;
            }
            break;
        case 1:
            if (i >= self->unk_9c && i <= self->unk_9c + self->rows) {
                vis = TRUE;
            }
            break;
        case 2:
            if (i >= self->unk_9c - 1 && i <= self->unk_9c + self->rows - 1) {
                vis = TRUE;
            }
            break;
        }
        if (vis) {
            LFLD(s32, p, 0xc) = x;
            LFLD(s32, p, 0x10) = y;
            LFLD(s32, p, 0x14) = z;
            p->vfunc_0c();
            y += LFLD(s32, p, 0x18) << 12;
        }
        p = LFLD(VObj *, p, 0x28);
        i++;
    } while (p != NULL);
}

}
