#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern char data_ov009_02216b98[];
extern Ov009Actor *func_ov000_02192b24(void *desc);
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);
extern void *func_020359d0(const char *name, s32 a, s32 b);
extern void func_02049564(void *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(void *p, s32 a);
void func_ov009_022026c8(Ov009Names *self, void *res);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 4;
    u8 b5 : 1;
    u8 b6 : 2;
};

struct Ov009SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
    Ov009SpawnDesc() {
        s32 i;
        kind = 0xffff;
        flags = 0xf000;
        for (i = 0; i < 4; i++) {
            unk_04[i] = 0;
        }
    }
};

void func_ov009_022028c8(Ov009Actor *self) {
    Ov009Names *n;
    Ov009Actor *o;
    u8 *p;
    u16 kind;
    char *a;
    char *b;
    u32 k;
    if (self->kind == 0x5055) {
        FLD(void *, self, 0xd8) = (void *)func_ov009_022026c8;
    }
    func_ov003_021d0fc0(self);
    kind = self->kind;
    a = func_0207011c((void *)kind);
    b = func_020701d4((void *)kind);
    n = FLD(Ov009Names *, self, 0x34);
    STD_CopyString(&FLD(char, n, 0x88), a);
    STD_CopyString(&FLD(char, n, 0xa8), b);
    n->unk_03_3 = 1;
    FLD(Ov009Names *, self, 0x34)->unk_00 = 0;
    k = 0x4083;
    if (self->kind == 0x5055) {
        k += 0x13;
    }
    {
        Ov009SpawnDesc desc;
        desc.parent = -1;
        desc.kind = k;
        desc.flags = k & 0xf000;
        o = func_ov000_02192b24(&desc);
    }
    if (o != NULL) {
        FLD(u16, self, 0xf0) = o->id;
        o->pos.x = self->pos.x;
        o->pos.y = self->pos.y;
        o->pos.z = self->pos.z;
        o->v04();
        ((Ov009Byte *)&FLD(u8, o, 0x16))->b0 = 1;
        if (FLD(u8 *, o, 0x4c) != NULL) {
            FLD(u16, FLD(u8 *, o, 0x4c), 0x1c) = self->id;
        }
    }
    p = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        Ov009Byte *bb = (Ov009Byte *)(p + 0xa2);
        bb->b0 = 0;
        bb->b5 = 1;
    }
    if (self->kind == 0x5055) {
        func_020359d0(data_ov009_02216b98, 7, 0);
    }
    func_02049564(data_02097e4c, 1, 1);
    switch (self->kind) {
    case 0x5049:
        func_ov000_02187a20(data_ov000_021ccd54, 0xe);
        self->unk_1a = 0;
        break;
    case 0x5055:
        func_ov000_02187a20(data_ov000_021ccd54, 0xf);
        self->unk_1a = 1;
        break;
    }
}

}
