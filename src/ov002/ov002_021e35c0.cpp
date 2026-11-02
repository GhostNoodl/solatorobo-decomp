#include "ov002/ov002.h"

extern "C" {

Obj021f002c *Ov002_FindRow(LoBase021ccb54_021ccbe0 *self, u16 id) {
    Obj021f002c *node = (Obj021f002c *)self->unk_94;
    while (node != NULL) {
        if (id == node->id) {
            return node;
        }
        node = (Obj021f002c *)node->next;
    }
    return node;
}

void func_ov002_021e35e8(void *a, void *b, VecFx32 *pos, s32 d) {
    VecFx32 tmp;
    tmp.x = pos->x;
    tmp.y = pos->y;
    tmp.z = pos->z;
    tmp.x -= 0x14000;
    func_ov000_021c524c(a, b, &tmp, d);
}

void func_ov002_021e3620(UiList *self, u16 id, s32 b) {
    UiListItem *obj = UiList_GetItemById(self, id);
    obj->unk_24 = b;
    Obj02153c48_CreateText(obj, self->font, 0, 0, 0);
}

BOOL func_ov002_021e364c(void) {
    return TRUE;
}

int Ov002RowList_GetHeight(VObj *self) {
    int a = self->vfunc_40() * FIELD(self, 0x20, s32);
    int b = self->vfunc_34();
    int c = self->vfunc_38();
    a += b;
    return a + c;
}

BOOL func_ov002_021e36a0(void) {
    return FALSE;
}

Obj021f002c *Ov002Vt_021f002c_DtorDelete(Obj021f002c *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021f002c;
    HEAP_PUSH(saved);
    {
        Model *p = self->model;
        if (p != NULL) {
            if (p != NULL) {
                TexObj_Release(p);
                PlttRes_Release(&p->pltt);
                Heap_Free(p);
            }
            self->model = NULL;
        }
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->text);
    HEAP_POP(saved);
    *(VFunc **)self = data_ov002_021ef684;
    ListRow_Unlink(self);
    Heap_Free(self);
    return self;
}

Obj021f002c *Ov002Vt_021f002c_Dtor(Obj021f002c *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021f002c;
    HEAP_PUSH(saved);
    {
        Model *p = self->model;
        if (p != NULL) {
            if (p != NULL) {
                TexObj_Release(p);
                PlttRes_Release(&p->pltt);
                Heap_Free(p);
            }
            self->model = NULL;
        }
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->text);
    HEAP_POP(saved);
    *(VFunc **)self = data_ov002_021ef684;
    ListRow_Unlink(self);
    return self;
}

VObj *Ov002Vt_021f0044_Dtor(VObj *self) {
    *(VFunc **)self = data_ov000_021ccbe0;
    LoBase021ccb54_021ccbe0_Release(self);
    *(VFunc **)self = data_ov000_021cac60;
    self->vfunc_2c();
    return self;
}

EffectObj *func_ov002_021e3874(const VecFx32 *pos, int unused, s32 n) {
    EffectObj *o = Effect3D_Create(data_ov002_021f00cc, data_ov002_021f00d8, 0, pos);
    s32 s = (s32)(((s64)((n - 1) << 12) * 0x4cd + 0x800) >> 12);
    o->SetScaleXYZ(s + 0x1000, s + 0x1000, s + 0x1000);
    o->unk_54 = 0x20;
    o->unk_28 = 0;
    return o;
}

}
