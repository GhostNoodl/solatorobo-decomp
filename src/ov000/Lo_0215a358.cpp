#include "ov000/VObj.h"
#include "ov000/ModelPart.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
void func_02041c18(Model *m, s32 a);

void Lo021cb5a8_DrawItemModels(Lo021cb5a8 *self, s32 enable, s32 *pos) {
    s16 z;
    UiListItem *item;
    s32 ox;
    s32 oy;
    s32 x;
    s32 y;
    if (enable == 0) {
        return;
    }
    z = self->posZ - 0x80;
    item = self->items;
    ox = self->vfunc_30();
    oy = self->vfunc_34();
    if (item == NULL) {
        return;
    }
    do {
        x = ((s32)item->unk_14) + (ox + (pos[0] >> 12));
        y = ((s32)item->unk_18) + (oy + (pos[1] >> 12));
        if (item->id != 0) {
            MODEL_FLAGS(self->model)->unk_19 = 0;
            self->model->unk_150 = z;
            Model_SetPos(self->model, (x - 0x84) << 12, (y - 0x61) << 12);
            func_02041c18(self->model, item->id);
            Model_PlayPart(self->model, 2);
        }
        if (item->label != NULL) {
            LFLD(s32, item->label, 0x70) = z;
            item->label->vfunc_20(x + 0xc, y);
            item->label->vfunc_90();
        }
        item = (UiListItem *)((u8 *)item->next);
    } while (item != NULL);
}

}
