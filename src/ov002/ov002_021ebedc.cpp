#include "ov002/ov002.h"

typedef struct ov002_Res021ec010 {
    u8 *data;
} ov002_Res021ec010;

typedef struct ov002_Hdr021ec010 {
    s16 count;
    s16 offset;
    s16 pad[2];
} ov002_Hdr021ec010;

typedef struct ov002_Msg021ec010 {
    u8 unk0[4];
    const ov002_Res021ec010 *res;
    s16 loaded;
    s16 count;
    u8 *body;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    u8 unk1C;
    u8 *name;
    u8 *text;
} ov002_Msg021ec010;

extern "C" {

void *func_ov002_021ebedc(void *self) {
    *(VFunc **)self = data_ov002_021f0ce8;
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, s16) = 0;
    FIELD(self, 0xa, s16) = 0;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s16) = 0;
    FIELD(self, 0x12, s16) = 0;
    FIELD(self, 0x14, s16) = 0;
    FIELD(self, 0x16, s16) = -1;
    FIELD(self, 0x18, s16) = 0;
    FIELD(self, 0x1a, s16) = 0;
    FIELD(self, 0x1c, u8) = 0;
    FIELD(self, 0x20, s32) = 0;
    FIELD(self, 0x24, s32) = 0;
    return self;
}

void *func_ov002_021ebf28(void *self) {
    *(VFunc **)self = data_ov002_021f0ce8;
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, s16) = 0;
    FIELD(self, 0xa, s16) = 0;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s16) = 0;
    FIELD(self, 0x12, s16) = 0;
    FIELD(self, 0x14, s16) = 0;
    FIELD(self, 0x16, s16) = -1;
    FIELD(self, 0x18, s16) = 0;
    FIELD(self, 0x1a, s16) = 0;
    FIELD(self, 0x1c, u8) = 0;
    FIELD(self, 0x20, s32) = 0;
    FIELD(self, 0x24, s32) = 0;
    return self;
}

void *func_ov002_021ebf74(void *self) {
    *(VFunc **)self = data_ov002_021f0ce8;
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, s16) = 0;
    FIELD(self, 0xa, s16) = 0;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s16) = 0;
    FIELD(self, 0x12, s16) = 0;
    FIELD(self, 0x14, s16) = 0;
    FIELD(self, 0x16, s16) = -1;
    FIELD(self, 0x18, s16) = 0;
    FIELD(self, 0x1a, s16) = 0;
    FIELD(self, 0x1c, u8) = 0;
    FIELD(self, 0x20, s32) = 0;
    FIELD(self, 0x24, s32) = 0;
    func_0203de1c(self);
    return self;
}

void func_ov002_021ebfd0(void *self) {
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, s16) = 0;
    FIELD(self, 0xa, s16) = 0;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s16) = 0;
    FIELD(self, 0x12, s16) = 0;
    FIELD(self, 0x14, s16) = 0;
    FIELD(self, 0x16, s16) = -1;
    FIELD(self, 0x18, s16) = 0;
    FIELD(self, 0x1a, s16) = 0;
    FIELD(self, 0x1c, u8) = 0;
    FIELD(self, 0x20, s32) = 0;
    FIELD(self, 0x24, s32) = 0;
}

void func_ov002_021ec010(void *p, const void *src) {
    ov002_Msg021ec010 *self = (ov002_Msg021ec010 *)p;
    const ov002_Res021ec010 *res = (const ov002_Res021ec010 *)src;
    ov002_Hdr021ec010 hdr;
    u8 *d = res->data;
    self->res = res;
    self->loaded = 0;
    self->count = 0;
    self->body = NULL;
    self->unk10 = 0;
    self->unk12 = 0;
    self->unk14 = 0;
    self->unk16 = -1;
    self->unk18 = 0;
    self->unk1A = 0;
    self->unk1C = 0;
    self->name = NULL;
    self->text = NULL;
    MI_CpuCopy8(d, &hdr, 8);
    self->count = hdr.count;
    if (self->count == 0) {
        return;
    }
    {
        u8 *body = d + hdr.offset;
        u8 *name;
        self->body = body;
        MI_CpuCopy8(body, &self->unk10, 0xe);
        name = body + self->unk18;
        self->name = name;
        self->text = name + (STD_GetStringLength(name) + 1);
    }
    self->loaded = 1;
}

}
