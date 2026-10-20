#include "types.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 y : 8;
    u32 attr0hi : 8;
    u32 x : 9;
    u32 attr1hi : 7;
    u32 tile : 10;
    u32 prio : 2;
    u32 pal : 4;
    u32 attr3 : 16;
} Oam021640fc;

typedef struct {
    u16 kind;
    u8 pad_02[6];
    s32 unk_08;
} Arg021640fc;

extern "C" {

extern u8 *data_0214a424;
u32 *func_ov000_0219bf7c(void);
u32 func_ov000_0219bf88(void);

static inline void OamPos021640fc(Oam021640fc *o, u16 x, u16 y) {
    o->x = x;
    o->y = y & 0x1ff;
}

Oam021640fc *func_ov000_021640fc(void *self, Arg021640fc *a, Oam021640fc *oam, u16 *cnt) {
    u16 n = *cnt;
    Oam021640fc *e = &oam[n - 1];
    void *p = LFLD(void *, self, 0x70);
    switch (a->kind) {
    case 0: {
        u32 t = e->tile;
        u32 v = data_0214a424[0x1a];
        s32 x = e->x;
        if (x > 0xff) {
            x |= ~0xff;
        }
        if (v >= 10) {
            e->tile = t - v % 10;
            e->x = (u16)(x + 6);
            e[-1].tile = t - v / 10;
            e[-1].x = (u16)(x - 6);
            e[-1].y = e->y;
            oam = e - 1;
            n = 2;
        } else {
            e->tile = t - v % 10;
            oam = e;
            n = 1;
        }
        break;
    }
    case 1: {
        u32 *tbl = func_ov000_0219bf7c();
        u32 lim = func_ov000_0219bf88();
        u32 t = e->tile;
        u8 *d = data_0214a424;
        u8 lv = d[0x1a];
        BOOL started = FALSE;
        s32 xpos;
        s32 ypos;
        u32 val;
        s32 digits;
        u32 div;
        if (a->unk_08 == 0) {
            digits = 4;
            div = 1000;
            xpos = 0xbd;
            ypos = 0xa0;
            if (lv >= lim) {
                val = 0;
            } else {
                val = tbl[lv] - LFLD(u32, d, 0x1c);
                if ((s32)val < 0) {
                    val = 0;
                }
            }
        } else {
            val = LFLD(u32, p, 0x50);
            div = 100000;
            digits = 6;
            xpos = 0x51;
            ypos = 0xb3;
        }
        if (val >= div * 10) {
            val = div * 10 - 1;
        }
        n = 0;
        for (; digits != 0; digits--) {
            u32 q = val / div;
            if ((digits == 1 && !started) || !(!started && q == 0)) {
                OamPos021640fc(&oam[n], xpos, ypos);
                oam[n].tile = t - q;
                n++;
                started = TRUE;
            }
            val -= q * div;
            div /= 10;
            xpos += 7;
        }
        break;
    }
    }
    *cnt = n;
    return oam;
}

}
