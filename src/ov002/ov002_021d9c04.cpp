#include "ov002/ov002.h"

extern "C" {

typedef struct Bits021da184 {
    u16 lo : 8;
    u16 rot : 2;
    u16 hi : 6;
} Bits021da184;

void func_0206d0a8(void *a);

BOOL func_0206d0d4(void *a, u16 id, u8 x, u8 y, u8 rot, int e);

u8 func_0206d1d4(void *a, u16 id);

void func_0206f3f0(u16 id, u8 v);

void func_0206d3ac(void *a, int b, u8 x, u8 y, s32 *org);

void func_0206d390(void *a, u8 b, u8 c);

u16 func_0206d02c(void *a);

void func_ov002_021d9c04(void *self) {
    u16 id;
    u8 *p;
    u16 i;
    s16 *a;
    u8 j;
    u8 *n;
    s32 cols;
    u8 r;
    u8 c;
    u8 *shape;
    for (func_0206d0a8(data_0214a424), n = FIELD(self, 0x6c, u8 *); n != NULL; n = FIELD(n, 0x70, u8 *)) {
        func_0206d0d4(data_0214a424, FIELD(n, 0x48, u16), FIELD(n, 0x54, s32), FIELD(n, 0x58, s32), FIELD(n, 0x52, Bits021da184).rot, 0);
    }
    for (i = 0; i < 0x53; i++) {
        p = (u8 *)self + i;
        id = i | 0x2000;
        if (p[8] != 0 || func_0206d1d4(data_0214a424, id)) {
            func_0206f3f0(id, p[8]);
        }
    }
    {
        u8 *o = FIELD(self, 0x4, u8 *);
        s32 org[2];
        s32 rows;
        org[0] = FIELD(FIELD(o, 0x6c, u8 *), 0x6, Nibbles16).n0;
        org[1] = FIELD(FIELD(o, 0x6c, u8 *), 0x6, Nibbles16).n1;
        shape = FIELD(o, 0x6c, u8 *);
        rows = FIELD(shape, 0x4, Nibbles16).n3;
        cols = FIELD(shape, 0x4, Nibbles16).n2;
        for (r = 0; r < rows; r++) {
            for (c = 0; c < cols; c++) {
                u16 k = c + r * cols;
                if (FIELD(shape, 0x0, u8 *)[k] == 0 && (FIELD(self, 0x70, u8 *) + k * 0xc)[2] != 2) {
                    func_0206d3ac(data_0214a424, 1, c, r, org);
                }
            }
        }
    }
    a = (s16 *)((u8 *)self + 0x76);
    {
        for (j = 0; j < 5; j++) {
            s16 v = a[j] + a[j + 5];
            if (v < 0) {
                v = 0;
            } else if (v > 99) {
                v = 99;
            }
            func_0206d390(data_0214a424, j, (s8)v);
        }
    }
    {
        u8 *g;
        u16 c;
        c = FIELD(self, 0x8a, u16);
        g = (u8 *)data_0214a424;
        if (c > 9999) {
            c = 9999;
        }
        FIELD(g, 0x24, u16) = c;
    }
    func_0206d02c(data_0214a424);
}

}
