#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d9ed8(Obj021efe6c *self, Obj021efeb8 *obj, bool del) {
    s32 j;
    s32 i;
    void *saved;
    s32 rows;
    s32 cols;
    Ov002Cell *grid;
    Obj021efeb8 *next = obj->next;
    Obj021efeb8 *prev = obj->prev;
    if (prev == NULL) {
        self->pieces = next;
        if (next != NULL) {
            next->prev = NULL;
        }
    } else {
        prev->next = next;
        if (next != NULL) {
            next->prev = prev;
        }
    }
    obj->next = NULL;
    obj->prev = NULL;
    {
        Ov002Shape *q = self->field->map;
        u32 h;
        grid = self->cells;
        h = FIELD(q, 4, u16);
        cols = (h << 20) >> 28;
        rows = (h << 16) >> 28;
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            Ov002Cell *e = &grid[j + i * cols];
            if (e->obj == obj) {
                e->id = 0xffff;
                e->unk_2 = 0;
                e->unk_3 = 0;
                e->unk_4 = 0;
                e->obj = NULL;
            }
        }
    }
    if (data_0214a424->bits18.mode == 1) {
        func_ov000_021c9544(self->unk_76, self->pieces);
        func_ov000_021c95ac(self->unk_76, data_0214a424->bits18.unk_3 | 0x8000);
    } else {
        func_ov000_021c9544(self->unk_76, self->pieces);
    }
    if (del) {
        HEAP_PUSH(saved);
        if (obj != NULL) {
            if (obj != NULL) {
                obj->vfunc_04();
            }
        }
        HEAP_POP(saved);
    }
}

void *Heap_AllocArray(u32 size);

void func_ov002_021da054(Obj021efe6c *self) {
    s32 j;
    s32 i;
    s32 rows;
    s32 cols;
    Obj021efeb8 *p;
    if (self->field == NULL) {
        return;
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        if (self->cells != NULL) {
            Heap_Free(self->cells);
            self->cells = NULL;
        }
        HEAP_POP(saved);
    }
    self->cells = (Ov002Cell *)Heap_AllocArray(self->field->map->h * self->field->map->w * sizeof(Ov002Cell));
    cols = self->field->map->w;
    rows = self->field->map->h;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            Ov002Cell *e = &self->cells[j + i * rows];
            e->id = 0xffff;
            e->unk_2 = 0;
            e->unk_3 = 0;
            e->unk_4 = 0;
            e->obj = NULL;
        }
    }
    for (p = self->pieces; p != NULL; p = p->next) {
        func_ov002_021da184(self, p);
    }
}

typedef struct Bits021da184 {
    u16 lo : 8;
    u16 rot : 2;
    u16 hi : 6;
} Bits021da184;

void func_ov002_021e3aa0(s32 *out, s32 *m, s32 *p, s32 *q, s32 *t);

void func_ov002_021da184(Obj021efe6c *self, Obj021efeb8 *obj) {
    Ov002Shape *g;
    s32 j;
    Ov002Cell *e;
    s32 i;
    s32 m[4];
    s32 pos[2];
    s32 org[2];
    s32 v[2];
    u8 rows;
    u8 cols;
    pos[0] = obj->unk_54;
    pos[1] = obj->unk_58;
    func_ov002_021e38f8(org, &obj->shape);
    cols = obj->shape.w;
    rows = obj->shape.h;
    func_ov002_021e391c(m, obj->shape.rot);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (obj->shape.grid[i * cols + j] == 1) {
                s32 W;
                s32 H;
                v[0] = j;
                v[1] = i;
                func_ov002_021e3aa0(v, m, v, org, pos);
                g = self->field->map;
                W = g->w;
                H = g->h;
                if (v[0] >= 0 && v[1] >= 0 && v[0] < W && v[1] < H && g->grid[v[1] * H + v[0]] == 0) {
                    e = &self->cells[v[0] + v[1] * H];
                    u8 *info = func_0206ede8(obj->unk_48);
                    e->id = obj->unk_48;
                    e->unk_2 = obj->unk_4a;
                    e->unk_3 = info[0];
                    e->unk_4 = info[2];
                    e->obj = obj;
                }
            }
        }
    }
}

}
