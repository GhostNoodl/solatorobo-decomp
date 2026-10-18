#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003Vec;

typedef struct {
    u8 unk_00[0xc];
    s32 *unk_0c;
} Ov003AnimData;

typedef struct {
    Ov003AnimData *data;
    u8 unk_04[0x74];
} Ov003Anim;

typedef struct {
    u8 unk_00[8];
    s32 unk_08;
} Ov003Model;

typedef struct {
    u8 unk_00[0x14];
    s32 unk_14;
} Ov003Shadow;

typedef struct {
    u8 unk_00[0xe];
    u16 kind;
    u8 unk_10[0x14];
    u8 unk_24[0x14];
    Ov003Model *model;
    Ov003Shadow *shadow;
    u8 unk_40[0x24];
    s32 unk_64;
    u8 unk_68[8];
    Ov003Vec pos;
    u16 unk_7c;
    u16 unk_7e;
    u8 unk_80[0x30];
    s16 unk_b0;
    u8 unk_b2[0x136];
    Ov003Anim anim;
    Ov003Vec effectPos;
    u8 unk_26c[0x64];
    u16 unk_2d0;
} Ov003Prop;

extern char data_ov003_021fa662[];
extern char data_ov003_021fa668[];
extern BOOL func_ov000_0218cf5c(void *self);
extern BOOL func_ov000_0218f110(s16 *p);
extern void func_ov000_021b4c60(void *self);
extern void func_ov000_0218ffdc(Ov003Anim *anim, s16 *res, s32 a, s32 b);
extern void func_ov000_02190cb0(void *anim, const char *name, s32 a, s32 b);
extern void func_ov000_02190758(Ov003Anim *anim, void *p, s32 a);
extern void func_ov000_02191318(Ov003Anim *anim, s32 a);
extern void *func_0203db40(void *p);
extern void func_ov000_02190a80(void *a, void *b);
extern BOOL func_ov000_0218cea4(void *self);
extern void func_ov000_021903b4(Ov003Anim *anim);
extern void *func_0202ac90(s32 a);
extern void func_02026df0(void *a, s32 b);
extern void func_01ffc9fc(Ov003Vec *src, Ov003Vec *dst, u16 angle);
extern void VEC_Add(Ov003Vec *a, Ov003Vec *b, Ov003Vec *dst);
extern void func_ov000_02191c24(Ov003Shadow *shadow, Ov003Vec *pos);

void func_ov003_021f3a94(Ov003Prop *self) {
    if (self->model != NULL) {
        func_ov000_02190a80(self->model, func_0203db40(self->unk_24));
    }
    func_ov000_02190a80(&self->anim, func_0203db40(self->unk_24));
}

BOOL func_ov003_021f3ad4(Ov003Prop *self) {
    Ov003Vec pos;
    BOOL r;
    self->shadow->unk_14 = self->unk_64 << 1;
    r = func_ov000_0218cea4(self);
    func_ov000_021903b4(&self->anim);
    pos.x = self->effectPos.x;
    pos.y = self->effectPos.y;
    pos.z = self->effectPos.z;
    func_ov000_02191c24(self->shadow, &pos);
    return r;
}
