#include "Main/Res/StageCmd.h"

extern "C" {

extern u8 *func_0206ede8(u16 id);

#define STAGE_ITEM_NONE 0xffff

u16 func_0206d02c(StageFlags *f) {
    u16 total = 0;
    s32 i;
    for (i = 0; i < 100; i++) {
        total += f->items[i];
    }
    for (i = 0; i < STAGE_ITEM_ENTRY_MAX; i++) {
        if (f->entries[i].id != STAGE_ITEM_NONE) {
            if (*func_0206ede8(f->entries[i].id) != 0x80) {
                total++;
            }
        }
    }
    f->itemTotal = total;
    return total;
}

void func_0206d0a8(StageFlags *f) {
    s32 i;
    for (i = 0; i < STAGE_ITEM_ENTRY_MAX; i++) {
        f->entries[i].id = STAGE_ITEM_NONE;
        f->entries[i].info = 0;
    }
}

}
