#include "ov002/ov002.h"

extern "C" {

void *func_ov002_021e35c0(void *self, u16 id) {
    void *node = FIELD(self, 0x94, void *);
    while (node != NULL) {
        if (id == FIELD(node, 0x38, u16)) {
            return node;
        }
        node = FIELD(node, 0x28, void *);
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

void func_ov002_021e3620(void *self, void *a, s32 b) {
    void *obj = func_ov000_02154b58(self, a);
    FIELD(obj, 0x24, s32) = b;
    func_ov000_02153c48(obj, FIELD(self, 0x1c, s32), 0, 0, 0);
}

BOOL func_ov002_021e364c(void) {
    return TRUE;
}

int func_ov002_021e3654(VObj *self) {
    int a = self->vfunc_40() * FIELD(self, 0x20, s32);
    int b = self->vfunc_34();
    int c = self->vfunc_38();
    a += b;
    return a + c;
}

BOOL func_ov002_021e36a0(void) {
    return FALSE;
}

void *Ov002Vt_021f002c_DtorDelete(void *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021f002c;
    HEAP_PUSH(saved);
    {
        void *p = FIELD(self, 0x30, void *);
        if (p != NULL) {
            if (p != NULL) {
                func_02041558((Model *)p);
                func_02041278((PlttRes *)((u8 *)p + 0x88));
                Heap_Free(p);
            }
            FIELD(self, 0x30, void *) = NULL;
        }
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x34, VObj *));
    HEAP_POP(saved);
    *(VFunc **)self = data_ov002_021ef684;
    func_ov000_021c2310(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021f002c_Dtor(void *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021f002c;
    HEAP_PUSH(saved);
    {
        void *p = FIELD(self, 0x30, void *);
        if (p != NULL) {
            if (p != NULL) {
                func_02041558((Model *)p);
                func_02041278((PlttRes *)((u8 *)p + 0x88));
                Heap_Free(p);
            }
            FIELD(self, 0x30, void *) = NULL;
        }
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x34, VObj *));
    HEAP_POP(saved);
    *(VFunc **)self = data_ov002_021ef684;
    func_ov000_021c2310(self);
    return self;
}

VObj *Ov002Vt_021f0044_Dtor(VObj *self) {
    *(VFunc **)self = data_ov000_021ccbe0;
    func_ov000_021c3bb0(self);
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
