#pragma opt_loop_invariants off
#include "ov002/ov002.h"

extern "C" {

typedef struct {
    u16 x : 3;
    u16 z : 3;
    u16 rot : 2;
    u16 flag : 1;
    u16 rest : 7;
} Info98ac;

typedef struct {
    u16 id;
    Info98ac info;
} Ent98ac;

static inline void ov002_SetRot(Obj021efeb8 *self, u8 rot) {
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

static inline void ov002_AddNode(Obj021efe6c *self, Obj021efeb8 *node) {
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
    Obj021efe6c_MarkPieceCells(self, node);
    if (gStageFlags->bits18.mode == 1) {
        Parts_SumStats(self->unk_76, self->pieces);
        Obj021c95ac_Init_021c95ac(self->unk_76, gStageFlags->bits18.unk_3 | 0x8000);
    } else {
        Parts_SumStats(self->unk_76, self->pieces);
    }
}

void Obj021efe6c_LoadPieces(Obj021efe6c *self) {
    int i;
    Obj021efe6c_FreePieces(self);
    Obj021efe6c_RebuildCells(self);
    MI_CpuCopy8((u8 *)gStageFlags + 0x2a, self->unk_08, sizeof(self->unk_08));
    for (i = 0; i < 0x25; i++) {
        Ent98ac *e = (Ent98ac *)((u8 *)gStageFlags + 0x8e) + i;
        u16 id = e->id;
        Obj021efeb8 *n;
        if (id == 0xffff) {
            break;
        }
        if (Param_GetEntry(id)[0] == 0x80) {
            n = (Obj021efeb8 *)Heap_Alloc(sizeof(Obj021efed4));
            if (n != NULL) {
                *(VFunc **)n = Ov002Vt_021efeb8_vtbl;
                Obj021efeb8_Init(n);
                *(VFunc **)n = Ov002Vt_021efed4_vtbl;
                Obj021efed4_Init((Obj021efed4 *)n);
            }
            n->unk_48 = id;
            n->vfunc_08();
            ((Obj021efed4 *)n)->unk_ac = ((Obj021efed4 *)n)->unk_a8 <= gStageFlags->unk_024 ? 2 : 1;
        } else {
            n = (Obj021efeb8 *)Heap_Alloc(sizeof(Obj021efe9c));
            if (n != NULL) {
                *(VFunc **)n = Ov002Vt_021efeb8_vtbl;
                Obj021efeb8_Init(n);
                *(VFunc **)n = Ov002Vt_021efe9c_vtbl;
                Obj021efe9c_Init((Obj021efe9c *)n);
            }
            n->unk_48 = id;
            n->vfunc_08();
            if (e->info.flag) {
                n->unk_6c = 1;
            }
        }
        {
            Ov002Shape *m = self->field->map;
            s32 x = m->ox;
            s32 z = m->oy;
            n->unk_64 = x;
            n->unk_68 = z;
        }
        {
            s32 x = e->info.x;
            s32 z = e->info.z;
            n->unk_54 = x;
            n->unk_58 = z;
        }
        Ov002_CellToPos(&n->trans.x, &n->unk_54, &n->unk_64);
        ov002_SetRot(n, e->info.rot);
        ov002_AddNode(self, n);
    }
    self->unk_8a = gStageFlags->unk_024;
    if (gStageFlags->bits18.mode == 1) {
        Parts_SumStats(self->unk_76, self->pieces);
        Obj021c95ac_Init_021c95ac(self->unk_76, gStageFlags->bits18.unk_3 | 0x8000);
    } else {
        Parts_SumStats(self->unk_76, self->pieces);
    }
}

}
