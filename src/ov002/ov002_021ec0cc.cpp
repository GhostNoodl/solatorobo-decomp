#include "ov002/ov002.h"

extern "C" {

void func_ov002_021ec0cc(Ov002Msg021f0ce8 *self) {
    u8 *p;
    if (self->index >= self->count) {
        return;
    }
    p = self->body + (self->unk_18 + self->unk_1a);
    self->body = p;
    MI_CpuCopy8(p, (u8 *)self + 0x10, 0xe);
    p += self->unk_18;
    self->name = (char *)p;
    self->text = (char *)(p + (STD_GetStringLength((char *)p) + 1));
    self->index++;
}

void *Ov002Vt_021f0cf8_Ctor(Ov002Snd021f0cf8 *self) {
    *(VFunc **)self = data_ov002_021f0cf8;
    self->src = NULL;
    self->index = 0;
    self->mask = 0;
    self->count = 0;
    self->cur = NULL;
    return self;
}

void *Ov002Vt_021f0cf8_Dtor(Ov002Snd021f0cf8 *self) {
    *(VFunc **)self = data_ov002_021f0cf8;
    self->src = NULL;
    self->index = 0;
    self->mask = 0;
    self->count = 0;
    self->cur = NULL;
    return self;
}

void *Ov002Vt_021f0cf8_DtorDelete(Ov002Snd021f0cf8 *self) {
    *(VFunc **)self = data_ov002_021f0cf8;
    self->src = NULL;
    self->index = 0;
    self->mask = 0;
    self->count = 0;
    self->cur = NULL;
    Heap_Free(self);
    return self;
}

void func_ov002_021ec1c4(Ov002Snd021f0cf8 *self) {
    self->src = NULL;
    self->index = 0;
    self->mask = 0;
    self->count = 0;
    self->cur = NULL;
}

void func_ov002_021ec1e0(Ov002Snd021f0cf8 *self, void *src) {
    s16 n;
    s16 rec[8];
    u8 *p = *(u8 **)src;
    u8 *q;
    int i = 0;
    self->src = src;
    self->index = 0;
    self->mask = 0;
    self->count = 0;
    self->cur = NULL;
    MI_CpuCopy8(p, &n, 2);
    self->count = n;
    if (self->count == 0) {
        return;
    }
    for (q = p + 2; i < self->count; i++, q += 0x10) {
        MI_CpuCopy8(q, rec, 0x10);
        if (rec[1] == 6 || rec[1] == 8) {
            self->mask |= 1 << (rec[2] / 256);
        }
    }
    self->cur = (s16 *)(p + 2);
    self->index = 1;
}

void func_ov002_021ec2ac(Ov002Snd021f0cf8 *self) {
    if (self->index >= self->count) {
        self->cur = NULL;
    } else {
        FIELD(self, 0x14, s32) += 0x10;
        self->index++;
    }
}

}
