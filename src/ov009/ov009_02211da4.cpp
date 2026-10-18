#include "ov009/ov009.h"

extern "C" {

extern u8 *func_0206fef8(void *res);

struct Ov009Bits16 {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 14;
};

void func_ov009_02211da4(Ov009Names *self, void *res) {
    char *a = func_0207011c(res);
    char *b = func_020701d4(res);
    u8 *c = func_0206fef8(res);
    if (FLD(Ov009Bits16, c, 0x12).b0) {
        STD_CopyString(self->unk_10, a);
        STD_CopyString(self->unk_30, b);
        self->unk_03_1 = 1;
    }
    if (FLD(Ov009Bits16, c, 0x12).b1) {
        STD_CopyString(self->unk_4c, a);
        STD_CopyString(self->unk_6c, b);
        self->unk_03_2 = 1;
    }
    STD_CopyString((char *)self + 0x88, a);
    STD_CopyString((char *)self + 0xa8, b);
    self->unk_03_3 = 1;
    self->unk_00 = 0;
}

struct Ov009SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 7;
};

extern Ov009Actor *func_ov000_02192b24(void *desc);

void func_ov009_02211e6c(Ov009Actor *self) {
    Ov009SpawnDesc desc;
    Ov009Actor *o;
    s32 i;
    s32 k;
    FLD(void *, self, 0xd8) = (void *)func_ov009_02211da4;
    func_ov003_021d0fc0(self);
    k = 0x4091;
    if (self->kind == 0x5050) {
        k++;
    }
    desc.kind = k;
    desc.flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        desc.unk_04[i] = 0;
    }
    desc.parent = -1;
    if (self->unk_1a == 1) {
        self->pos.z += 0x3000;
    }
    o = func_ov000_02192b24(&desc);
    if (o == NULL) {
        return;
    }
    FLD(u16, self, 0xf0) = o->id;
    o->pos.x = self->pos.x;
    o->pos.y = self->pos.y;
    o->pos.z = self->pos.z;
    o->v04();
    ((Ov009Byte *)&FLD(u8, o, 0x16))->b0 = 1;
}

}
