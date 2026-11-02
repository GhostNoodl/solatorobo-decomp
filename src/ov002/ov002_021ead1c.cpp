#include "ov002/ov002.h"

extern "C" {

void *Heap_AllocArray(u32 size);

void func_ov002_021eb964(Ov002StageFile *self);

void func_ov002_021ead1c(Ov002StageFile *self, u8 *data, char *name, u8 c) {
    s32 hdr;
    s32 n0;
    s32 n1;
    s32 n2;
    s32 n3;
    func_ov002_021eae48(self);
    self->unk_04 = name;
    self->data = data;
    self->unk_0c = c;
    MI_CpuCopy8(data + 8, &hdr, 4);
    func_ov002_021eb964(self);
    MI_CpuCopy8(self->unk_18 + 8, &n0, 4);
    MI_CpuCopy8(self->unk_1c + 8, &n1, 4);
    MI_CpuCopy8(self->unk_20 + 8, &n2, 4);
    MI_CpuCopy8(self->unk_24 + 8, &n3, 4);
    if (n0 > 0) {
        self->links = (Ov002ObjLink *)(Heap_AllocArray(n0 * 0x1c));
        self->linkCount = n0;
    }
    if (n1 > 0) {
        self->unk_44 = (struct Ov002Obj021f075c **)(Heap_AllocArray(n1 * 4));
        self->unk_54 = n1;
    }
    if (n2 > 0) {
        self->unk_48 = (struct Ov002Obj021f075c **)(Heap_AllocArray(n2 * 4));
        self->unk_58 = n2;
    }
    if (n3 > 0) {
        self->unk_4c = (struct Ov002Obj021f075c **)(Heap_AllocArray(n3 * 4));
        self->unk_5c = n3;
    }
}

}
