#include "ov015/ov015.h"

extern "C" {

u8 *func_02070744(u16 id);
Ov015ParamPrice *Param_GetFishItemInfo(u16 id);
void Ov015Shared_SetCatch(Ov015Shared *self, u16 id) {
    s32 i;
    self->catchId = id;
    MIi_CpuClear32(0, self->items, 0x18);
    if (id == 0x800b) {
        return;
    }
    Ov015Shared_RollItems(self, self->items, 3, FLD(u16, func_02070744(id), 0x2), 0x171);
    self->total = 0;
    for (i = 0; i < 3; i++) {
        s32 e = self->items[i].id;
        if (e == 0) {
            return;
        }
        self->total += self->items[i].count * Param_GetFishItemInfo(e)->price;

    }
}

}
