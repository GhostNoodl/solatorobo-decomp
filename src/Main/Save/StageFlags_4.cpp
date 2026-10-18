#include "Main/Res/StageCmd.h"

extern "C" {

extern u8 *func_0206ede8(u16 id);

#define STAGE_ITEM_NONE 0xffff

u8 func_0206d1d4(StageFlags *f, u16 id) {
    u8 n = 0;
    s32 i;
    for (i = 0; i < STAGE_ITEM_ENTRY_MAX; i++) {
        if (id == f->entries[i].id) {
            n++;
        }
    }
    return n;
}

u8 func_0206d204(StageFlags *f, BOOL consume) {
    u8 total = 0;
    s32 i;
    for (i = 0; i < STAGE_ITEM_ENTRY_MAX; i++) {
        StageItemEntry *e = &f->entries[i];
        if (e->id != STAGE_ITEM_NONE && !e->bits.used) {
            u8 *info = func_0206ede8(e->id);
            if (info[0] == 4) {
                total += info[2];
                if (consume) {
                    e->bits.used = 1;
                }
            }
        }
    }
    if (total != 0) {
        if (total > 99) {
            total = 99;
        }
        if (consume) {
            f->unk_12c[4] = 0;
        }
    }
    return total;
}

s32 func_0206d2a4(StageFlags *f, u16 id, u8 n) {
    if (*func_0206ede8(id) == 0x80) {
        return -1;
    }
    f->items[(u16)(id & 0xfff)] = n;
    return n;
}

s32 func_0206d2ec(StageFlags *f, u16 id, u32 n) {
    u16 idx;
    s32 v;
    if (*func_0206ede8(id) == 0x80) {
        return -1;
    }
    if (n + data_0214a424->itemTotal > 100) {
        return -1;
    }
    idx = id & 0xfff;
    v = n + f->items[idx];
    if (v > 100) {
        return -1;
    }
    if (v < 0) {
        return 0;
    }
    f->items[idx] = v;
    f->itemTotal += (u16)n;
    return v;
}

u8 func_0206d37c(StageFlags *f, u32 i) {
    if (i >= 5) {
        return 0;
    }
    return f->unk_12c[i];
}

void func_0206d390(StageFlags *f, u32 i, u32 v) {
    if (i >= 5) {
        return;
    }
    if (v > 99) {
        v = 99;
    }
    f->unk_12c[i] = v;
}

void func_0206d3ac(StageFlags *f, BOOL on, s32 bit, s32 idx, const s32 *ofs) {
    u8 *bits = f->bits;
    s32 y = idx + (3 - ofs[1]);
    s32 x = bit + (3 - ofs[0]);
    u8 v = bits[y];
    bits[y] = on ? (v | (1 << x)) : (v & ~(1 << x));
}
}
