#include "ov002/ov002.h"

typedef struct Oam021e1988 {
    u32 y : 8;
    u32 a0 : 8;
    u32 x : 9;
    u32 a1 : 7;
    u32 charNo : 10;
    u32 a2 : 22;
} Oam021e1988;

typedef struct Info021e1988 {
    u16 type;
    u8 pad[6];
    s32 value;
} Info021e1988;

typedef struct Obj021e1988 {
    u8 pad[0x70];
    u32 unk70;
} Obj021e1988;

static inline void SetPos021e1988(Oam021e1988 *o, u16 x, u16 y) {
    o->x = x;
    o->y = y & 0x1ff;
}

extern "C" {

Oam021e1988 *func_ov002_021e1988(Obj021e1988 *obj, Info021e1988 *info, Oam021e1988 *oam, u16 *count) {
    u16 n;
    u8 mode;
    Oam021e1988 *tmpl;
    u32 base;
    s32 x;
    s32 y;
    s32 val;
    s32 i;
    s32 t;
    n = *count;
    tmpl = &oam[n - 1];
    base = tmpl->charNo;
    mode = obj->unk70;
    switch (info->type) {
    case 1:
        x = tmpl->x;
        y = tmpl->y;
        val = info->value;
        if (mode == 1) {
            if (val < 10) {
                SetPos021e1988(&oam[0], x + 8, y);
                oam[0].charNo = base - val;
                n = 1;
            } else {
                n = 2;
                x += 8;
                for (i = 0; i < 2; i++) {
                    SetPos021e1988(&oam[i], x, y);
                    oam[i].charNo = base - val % 10;
                    val /= 10;
                    x -= 8;
                }
            }
        } else if (mode == 0) {
            if (val == 0) {
                SetPos021e1988(&oam[0], x, y);
                oam[0].charNo = base;
                n = 1;
            } else {
                t = val;
                n = 0;
                while (t != 0) {
                    t /= 10;
                    n++;
                }
                x += (n - 1) * 8;
                for (i = 0; i < n; i++) {
                    SetPos021e1988(&oam[i], x, y);
                    oam[i].charNo = base - val % 10;
                    val /= 10;
                    x -= 8;
                }
            }
        }
        break;
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        break;
    case 8:
    case 9:
    case 10:
        oam[0].x = tmpl->x;
        oam[0].y = tmpl->y;
        oam[0].charNo = base;
        n = 1;
        break;
    }
    *count = n;
    return oam;
}

}
