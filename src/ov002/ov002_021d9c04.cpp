#include "ov002/ov002.h"

extern "C" {

void func_0206d0a8(void *a);

BOOL StageFlags_AddEntry(void *a, u16 id, u8 x, u8 y, u8 rot, int e);

u8 StageFlags_CountEntries(void *a, u16 id);

void func_0206f3f0(u16 id, u8 v);

void func_0206d3ac(void *a, int b, u8 x, u8 y, s32 *org);

void func_0206d390(void *a, u8 b, u8 c);

u16 StageFlags_CountItems(void *a);

void func_ov002_021d9c04(Obj021efe6c *self) {
    u16 id;
    u8 *p;
    u16 i;
    s16 *a;
    u8 j;
    Obj021efeb8 *n;
    s32 cols;
    u8 r;
    u8 c;
    Ov002Shape *shape;
    for (func_0206d0a8(data_0214a424), n = self->pieces; n != NULL; n = n->next) {
        StageFlags_AddEntry(data_0214a424, n->unk_48, n->unk_54, n->unk_58, n->shape.rot, 0);
    }
    for (i = 0; i < 0x53; i++) {
        p = (u8 *)self + i;
        id = i | 0x2000;
        if (p[8] != 0 || StageFlags_CountEntries(data_0214a424, id)) {
            func_0206f3f0(id, p[8]);
        }
    }
    {
        Obj021efe4c *o = self->field;
        s32 org[2];
        s32 rows;
        org[0] = o->map->ox;
        org[1] = o->map->oy;
        shape = o->map;
        rows = shape->h;
        cols = shape->w;
        for (r = 0; r < rows; r++) {
            for (c = 0; c < cols; c++) {
                u16 k = c + r * cols;
                if (shape->grid[k] == 0 && self->cells[k].unk_2 != 2) {
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
        c = ((u16)self->unk_8a);
        g = (u8 *)data_0214a424;
        if (c > 9999) {
            c = 9999;
        }
        FIELD(g, 0x24, u16) = c;
    }
    StageFlags_CountItems(data_0214a424);
}

}
