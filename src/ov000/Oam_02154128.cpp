#include "types.h"

typedef struct {
    u32 y : 8;
    u32 unk_00_8 : 8;
    u32 x : 9;
    u32 unk_00_25 : 7;
    u32 tile : 10;
    u32 unk_04_10 : 22;
} OamEntry02154128;

typedef struct {
    u16 type;
    u8 pad_02[6];
    u8 *unk_08;
} Req02154128;

extern "C" {

static inline void SetPos02154128(OamEntry02154128 *e, u16 x, u16 y) {
    e->x = x;
    e->y = y & 0x1ff;
}

OamEntry02154128 *func_ov000_02154128(u8 *self, Req02154128 *req, OamEntry02154128 *buf, u16 *count) {
    u16 n = *count;
    OamEntry02154128 *e = &buf[n - 1];
    switch (req->type) {
    case 6: {
        s32 digits;
        u32 val;
        BOOL shown;
        s32 x;
        u8 *obj = req->unk_08;
        s32 i;
        u32 div;
        u32 tile;
        tile = e->tile;
        val = *(u32 *)(self + 0x70);
        digits = obj != NULL ? (s8)obj[0xc1] : 5;
        div = 1;
        shown = FALSE;
        x = 0;
        n = 0;
        for (i = 0; i < digits - 1; i++) {
            div *= 10;
        }
        if (val >= div * 10) {
            val = div * 10 - 1;
        }
        for (; digits != 0; digits--) {
            u32 d = val / div;
            if ((digits == 1 && !shown) || shown || d != 0) {
                SetPos02154128(&buf[n], x, 0);
                buf[n].tile = tile - d;
                n++;
                shown = TRUE;
            }
            val -= d * div;
            div /= 10;
            x += 8;
        }
        break;
    }
    case 7:
        SetPos02154128(buf, 0, 0);
        break;
    }
    *count = n;
    return buf;
}

}
