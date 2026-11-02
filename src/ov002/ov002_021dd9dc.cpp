#pragma opt_loop_invariants off
#include "ov002/ov002.h"

extern "C" {

typedef struct Ent021dd9dc {
    u16 id;
    u16 x : 3;
    u16 y : 3;
    u16 rot : 2;
    u16 rest : 8;
} Ent021dd9dc;



static inline void ov002_Piece_SetRot(Obj021efeb8 *self, u16 rot) {
    self->shape.rot = rot;
    switch (rot) {
    case 0:
        self->unk_10 = 0;
        self->unk_12 = 0;
        self->unk_14 = 0;
        MTX_Identity33_(&self->rot);
        break;
    case 1:
        self->unk_10 = 0;
        self->unk_12 = 0x3fff;
        self->unk_14 = 0;
        MTX_Identity33_(&self->rot);
        MTX_RotY33_(&self->rot, FX_SINCOS(0x3ff * 2), FX_SINCOS(0x3ff * 2 + 1));
        break;
    case 2:
        self->unk_10 = 0;
        self->unk_12 = 0x7fff;
        self->unk_14 = 0;
        MTX_Identity33_(&self->rot);
        MTX_RotY33_(&self->rot, FX_SINCOS(0x7ff * 2), FX_SINCOS(0x7ff * 2 + 1));
        break;
    case 3:
        self->unk_10 = 0;
        self->unk_12 = 0xbffd;
        self->unk_14 = 0;
        MTX_Identity33_(&self->rot);
        MTX_RotY33_(&self->rot, FX_SINCOS(0xbff * 2), FX_SINCOS(0xbff * 2 + 1));
        break;
    }
}

static inline void ov002_Board_Add(Obj021efe6c *self, Obj021efeb8 *node) {
    Obj021efeb8 *p = self->pieces;
    if (p != NULL) {
        if (p != NULL) {
            Obj021efeb8 *q;
            do {
                q = p->next;
                if (q == NULL) {
                    break;
                }
                p = q;
            } while (p != NULL);
        }
        p->next = node;
        node->prev = p;
    } else {
        self->pieces = node;
    }
    func_ov002_021da184(self, node);
    if (data_0214a424->bits18.mode == 1) {
        func_ov000_021c9544(self->unk_76, self->pieces);
        func_ov000_021c95ac(self->unk_76, data_0214a424->bits18.unk_3 | 0x8000);
    } else {
        func_ov000_021c9544(self->unk_76, self->pieces);
    }
}

// `w` is an unused register parameter reused as a local: it has to be numbered
// below every compiler temp, which only a parameter is. Each new piece reuses `a`
// (the first loop's cursor), so it is a split web of `a` with the target's register.
void func_ov002_021dd9dc(Obj021eff10 *self, Obj021efe6c *w) {
    Ent021dd9dc *e;
    w = self->owner->board;
    Obj021efe9c *a;
    Obj021efe9c *next;
    a = (Obj021efe9c *)w->pieces;
    if (a != NULL) {
        do {
            next = (Obj021efe9c *)a->next;
            if (a->unk_4a == 1) {
                func_ov002_021d9ed8(w, a, 1);
            }
            a = next;
        } while (a != NULL);
    }
    e = (Ent021dd9dc *)((u8 *)data_0214a424 + 0x8e);
    if (e->id != 0xffff) {
        do {
            u16 id = e->id | 0x2000;
            if (func_0206ede8(id)[0] != 0x80) {
            a = (Obj021efe9c *)Heap_Alloc(sizeof(Obj021efe9c));
            if (a != NULL) {
                *(VFunc **)a = data_ov002_021efeb8;
                func_ov002_021d7b80(a);
                *(VFunc **)a = data_ov002_021efe9c;
                func_ov002_021d7e54(a);
            }
            a->unk_48 = id;
            a->vfunc_08();
            if (a->unk_ac != 2) {
                a->unk_ac = 2;
                a->unk_a4 = 0;
                a->unk_a8 = 5;
            }
            {
                Ov002Shape *d = w->field->map;
                s32 n0 = d->ox;
                s32 n1 = d->oy;
                a->unk_64 = n0;
                a->unk_68 = n1;
            }
            {
                s32 x = e->x;
                s32 y = e->y;
                a->unk_54 = x;
                a->unk_58 = y;
            }
            func_ov002_021e3b0c(&a->trans.x, &a->unk_54, &a->unk_64);
            ov002_Piece_SetRot(a, (u8)e->rot);
            ov002_Board_Add(w, a);
            }
        } while ((++e)->id != 0xffff);
    }
    MI_CpuCopy8((u8 *)data_0214a424 + 0x2a, w->unk_08, sizeof(w->unk_08));
}

}
