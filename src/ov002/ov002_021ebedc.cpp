#include "ov002/ov002.h"

typedef struct ov002_Hdr021ec010 {
    s16 count;
    s16 offset;
    s16 pad[2];
} ov002_Hdr021ec010;

extern "C" {

void *Ov002Vt_021f0ce8_Ctor(Ov002Msg021f0ce8 *self) {
    *(VFunc **)self = data_ov002_021f0ce8;
    self->res = NULL;
    self->index = 0;
    self->count = 0;
    self->body = NULL;
    self->unk_10 = 0;
    self->unk_12 = 0;
    self->unk_14 = 0;
    self->unk_16 = -1;
    self->unk_18 = 0;
    self->unk_1a = 0;
    self->unk_1c = 0;
    self->name = NULL;
    self->text = NULL;
    return self;
}

void *Ov002Vt_021f0ce8_Dtor(Ov002Msg021f0ce8 *self) {
    *(VFunc **)self = data_ov002_021f0ce8;
    self->res = NULL;
    self->index = 0;
    self->count = 0;
    self->body = NULL;
    self->unk_10 = 0;
    self->unk_12 = 0;
    self->unk_14 = 0;
    self->unk_16 = -1;
    self->unk_18 = 0;
    self->unk_1a = 0;
    self->unk_1c = 0;
    self->name = NULL;
    self->text = NULL;
    return self;
}

void *Ov002Vt_021f0ce8_DtorDelete(Ov002Msg021f0ce8 *self) {
    *(VFunc **)self = data_ov002_021f0ce8;
    self->res = NULL;
    self->index = 0;
    self->count = 0;
    self->body = NULL;
    self->unk_10 = 0;
    self->unk_12 = 0;
    self->unk_14 = 0;
    self->unk_16 = -1;
    self->unk_18 = 0;
    self->unk_1a = 0;
    self->unk_1c = 0;
    self->name = NULL;
    self->text = NULL;
    Heap_Free(self);
    return self;
}

void func_ov002_021ebfd0(Ov002Msg021f0ce8 *self) {
    self->res = NULL;
    self->index = 0;
    self->count = 0;
    self->body = NULL;
    self->unk_10 = 0;
    self->unk_12 = 0;
    self->unk_14 = 0;
    self->unk_16 = -1;
    self->unk_18 = 0;
    self->unk_1a = 0;
    self->unk_1c = 0;
    self->name = NULL;
    self->text = NULL;
}

void func_ov002_021ec010(Ov002Msg021f0ce8 *self, const void *src) {
    const Ov002MsgRes *res = (const Ov002MsgRes *)src;
    ov002_Hdr021ec010 hdr;
    u8 *d = res->data;
    self->res = res;
    self->index = 0;
    self->count = 0;
    self->body = NULL;
    self->unk_10 = 0;
    self->unk_12 = 0;
    self->unk_14 = 0;
    self->unk_16 = -1;
    self->unk_18 = 0;
    self->unk_1a = 0;
    self->unk_1c = 0;
    self->name = NULL;
    self->text = NULL;
    MI_CpuCopy8(d, &hdr, 8);
    self->count = hdr.count;
    if (self->count == 0) {
        return;
    }
    {
        u8 *body = d + hdr.offset;
        char *name;
        self->body = body;
        MI_CpuCopy8(body, &self->unk_10, 0xe);
        name = (char *)body + self->unk_18;
        self->name = name;
        self->text = name + (STD_GetStringLength(name) + 1);
    }
    self->index = 1;
}

}
