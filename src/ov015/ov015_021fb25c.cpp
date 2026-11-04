#include "ov015/ov015.h"
#include "Main/Gfx/TexObj.h"

extern "C" {

// Entry 15 of the model, whose callback argument (unk_08) is the stats block.
static inline TexObjEntry *Src(TexObj *obj) {
    if (obj->count <= 15) {
        return NULL;
    }
    return &obj->entries[15];
}

// Glyph callback of entries 0xe/0xf (TexObj_SetOamFunc): writes the value of the stats block as digits.
Ov015Glyph *Ov015Hud_OamDigits(TexObj *obj, TexObjEntry *entry, Ov015Glyph *e, u16 *count) {
    Ov015Glyph *last;
    s32 val;
    u16 i;
    s32 n;
    s32 v;
    s32 x;
    s32 w;
    s32 idx;
    i = *count;
    idx = i - 1;
    last = &e[idx];
    w = last->w;
    val = ((Ov015Stat *)Src(obj)->unk_08)->unk_00 >> 12;
    n = 0;
    v = val;
    do {
        n++;
        v /= 10;
    } while (v != 0);
    switch (entry->index) {
    case 0xf:
        x = ((n + 1) * 12 >> 1) - 12;
        i = 0;
        for (; n > 0; n--) {
            x -= 12;
            e[i].x = (u16)x;
            e[i].code = 0xf4;
            e[i].w = w - (val % 10) * 2;
            i++;
            val /= 10;
            if (val == 0) {
                break;
            }
        }
        break;
    case 0xe:
        e[0].x = (u16)(((n + 1) * 12 >> 1) - 12);
        e[0].code = 0xf2;
        e[0].w = last->w;
        i = 1;
        break;
    }
    *count = i;
    return e;
}

}
