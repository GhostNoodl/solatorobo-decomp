#include "Main/Res/StageCmd.h"

extern "C" {

extern u8 *Param_GetEntry(u16 id);

#define STAGE_ITEM_NONE 0xffff

static inline u16 StageFlags_ItemType(u32 id) {
    return id >> 12;
}

static inline u16 StageFlags_ItemIdx(u32 id) {
    return id & 0xfff;
}

// `used` is a BOOL here but a u8 parameter of StageFlags_AddEntry; that mix gives the target's load order of the two stack arguments.
static inline void StageFlags_SetEntryBits(StageFlags *f, s32 i, u8 x, u8 y, u8 rot, BOOL used) {
    f->entries[i].bits.a = x;
    f->entries[i].bits.b = y;
    f->entries[i].bits.c = rot;
    f->entries[i].bits.used = used;
}

BOOL StageFlags_AddEntry(StageFlags *f, u16 id, u8 x, u8 y, u8 rot, u8 used) {
    s32 i;
    BOOL ok;
    ok = TRUE;
    if (StageFlags_ItemType(id) - 1 != 1 || StageFlags_ItemIdx(id) >= 0x53) {
        return FALSE;
    }
    for (i = 0; i < STAGE_ITEM_ENTRY_MAX; i++) {
        if (f->entries[i].id == STAGE_ITEM_NONE) {
            break;
        }
    }
    if (i == STAGE_ITEM_ENTRY_MAX) {
        ok = FALSE;
    } else {
        f->entries[i].id = id;
        StageFlags_SetEntryBits(f, i, x, y, rot, used);
        if (*Param_GetEntry(id) != 0x80) {
            f->itemTotal++;
        }
    }
    return ok;
}

u8 StageFlags_CountEntries(StageFlags *f, u16 id) {
    u8 n = 0;
    s32 i;
    for (i = 0; i < STAGE_ITEM_ENTRY_MAX; i++) {
        if (id == f->entries[i].id) {
            n++;
        }
    }
    return n;
}

u8 StageFlags_UseReviveItems(StageFlags *f, BOOL consume) {
    u8 total = 0;
    s32 i;
    for (i = 0; i < STAGE_ITEM_ENTRY_MAX; i++) {
        StageItemEntry *e = &f->entries[i];
        if (e->id != STAGE_ITEM_NONE && !e->bits.used) {
            u8 *info = Param_GetEntry(e->id);
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

s32 StageFlags_SetItemCount(StageFlags *f, u16 id, u8 n) {
    if (*Param_GetEntry(id) == 0x80) {
        return -1;
    }
    f->items[(u16)(id & 0xfff)] = n;
    return n;
}

s32 StageFlags_AddItem(StageFlags *f, u16 id, u32 n) {
    u16 idx;
    s32 v;
    if (*Param_GetEntry(id) == 0x80) {
        return -1;
    }
    if (n + gStageFlags->itemTotal > 100) {
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

u8 StageFlags_GetCounter(StageFlags *f, u32 i) {
    if (i >= 5) {
        return 0;
    }
    return f->unk_12c[i];
}

void StageFlags_SetCounter(StageFlags *f, u32 i, u32 v) {
    if (i >= 5) {
        return;
    }
    if (v > 99) {
        v = 99;
    }
    f->unk_12c[i] = v;
}

void StageFlags_SetGridBit(StageFlags *f, BOOL on, s32 bit, s32 idx, const s32 *ofs) {
    u8 *bits = f->bits;
    s32 y = idx + (3 - ofs[1]);
    s32 x = bit + (3 - ofs[0]);
    u8 v = bits[y];
    bits[y] = on ? (v | (1 << x)) : (v & ~(1 << x));
}
}
