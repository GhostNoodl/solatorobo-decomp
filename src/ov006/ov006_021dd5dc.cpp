#include "ov006/ov006.h"

typedef struct ov006_Oam021dd5dc {
    u32 y : 8;
    u32 a0 : 8;
    u32 x : 9;
    u32 a1 : 7;
    u32 tile : 10;
    u32 b1 : 22;
} ov006_Oam021dd5dc;

typedef struct ov006_Time021dd5dc {
    u16 h;
    u16 m;
    u16 s;
    u16 ms;
} ov006_Time021dd5dc;

extern "C" {

static inline void ov006_Put(ov006_Oam021dd5dc *o, u16 x) {
    o->x = x;
    o->y = 0;
}

ov006_Oam021dd5dc *func_ov006_021dd5dc(void *self, u16 *flag, ov006_Oam021dd5dc *oam, u16 *count) {
    u16 n = *count;
    s16 x = 0x2a;
    ov006_Oam021dd5dc *last = &oam[n - 1];
    switch (*flag) {
    case 0x1e: {
        u32 tile = last->tile;
        ov006_Time021dd5dc *p = *(ov006_Time021dd5dc **)((u8 *)self + 0x70);
        if (p != NULL) {
            ov006_Time021dd5dc t = *p;
            t.ms = (t.ms + 5) / 10;
            n = 0;
            ov006_Put(&oam[n], x);
            oam[n].tile = tile - t.ms % 10;
            n++;
            x -= 6;
            ov006_Put(&oam[n], x);
            oam[n].tile = tile - t.ms / 10;
            n++;
            x -= 0xc;
            ov006_Put(&oam[n], x);
            oam[n].tile = tile - t.s % 10;
            n++;
            x -= 6;
            ov006_Put(&oam[n], x);
            oam[n].tile = tile - t.s / 10;
            n++;
            x -= 0xc;
            ov006_Put(&oam[n], x);
            oam[n].tile = tile - t.m % 10;
            n++;
            x -= 6;
            ov006_Put(&oam[n], x);
            oam[n].tile = tile - t.m / 10;
            n++;
        }
    } break;
    case 0x1f:
        n = 0;
        x -= 0xc;
        ov006_Put(&oam[n], x);
        n++;
        x -= 0x12;
        {
            ov006_Oam021dd5dc *o = &oam[n];
            oam[n] = oam[n - 1];
            ov006_Put(o, x);
        }
        n++;
        break;
    case 0x24:
        n = 0;
        ov006_Put(&oam[n], x);
        n++;
        x -= 6;
        {
            ov006_Oam021dd5dc *o = &oam[n];
            oam[n] = oam[n - 1];
            ov006_Put(o, x);
        }
        n++;
        x -= 0xc;
        {
            ov006_Oam021dd5dc *o = &oam[n];
            oam[n] = oam[n - 1];
            ov006_Put(o, x);
        }
        n++;
        x -= 6;
        {
            ov006_Oam021dd5dc *o = &oam[n];
            oam[n] = oam[n - 1];
            ov006_Put(o, x);
        }
        n++;
        x -= 0xc;
        {
            ov006_Oam021dd5dc *o = &oam[n];
            oam[n] = oam[n - 1];
            ov006_Put(o, x);
        }
        n++;
        x -= 6;
        {
            ov006_Oam021dd5dc *o = &oam[n];
            oam[n] = oam[n - 1];
            ov006_Put(o, x);
        }
        n++;
        break;
    }
    *count = n;
    return oam;
}

}
