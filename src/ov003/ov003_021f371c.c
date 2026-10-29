#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003Vec;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Ov003SVec;

typedef struct {
    u8 unk_00[0xe];
    u16 kind;
    u8 unk_10[0x14];
    u8 unk_24[0x14];
    void *unk_38;
    u8 unk_3c[0x34];
    Ov003Vec pos;
    u8 unk_7c[0x34];
    s16 unk_b0;
    u8 unk_b2[0x136];
    u8 anim[0x78];
    Ov003Vec effectPos;
} Ov003Prop;

extern char data_ov003_021fa652[];
extern u32 data_ov003_021fa658;
extern void func_ov000_021b4adc(void *self);
extern void func_ov000_0218f074(s16 *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern void *data_02097e4c;
extern const Ov003SVec data_ov003_021f7694[];
extern BOOL func_ov000_0218cf5c(void *self);
extern BOOL func_ov000_0218f110(s16 *p);
extern void func_ov000_021b4c60(void *self);
extern BOOL func_ov000_0218ffdc(void *anim, s16 *res, s32 a, s32 b);
extern BOOL func_ov000_02190cb0(void *anim, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *anim);
extern void func_ov000_02190758(void *anim, void *p, s32 a);
extern void *func_0203db40(void *p);
extern void func_ov000_02190a80(void *a, void *b);
extern s32 **func_ov000_02190a30(void *a, s32 b);
extern void *func_0204a028(void *mgr, s32 id, Ov003Vec *pos, s32 a);
extern BOOL func_ov000_0218cea4(void *self);
extern BOOL func_ov000_021903b4(void *anim);

BOOL func_ov003_021f371c(Ov003Prop *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (self->kind != 0x6a01 && self->unk_b0 >= 0) {
        if (!func_ov000_0218f110(&self->unk_b0)) {
            r = FALSE;
        }
    }
    return r;
}

void func_ov003_021f3764(Ov003Prop *self) {
    func_ov000_021b4c60(self);
    if (self->kind == 0x6a01) {
        return;
    }
    func_ov000_0218ffdc(self->anim, &self->unk_b0, 0, 1);
    func_ov000_02190cb0(self->anim, data_ov003_021fa652, 0x1000, 0);
    func_ov000_021915a0(self->anim);
    func_ov000_02190758(self->anim, self->unk_7c, 0);
}

void func_ov003_021f37d0(Ov003Prop *self) {
    s32 v;
    s32 *p;
    Ov003Vec pos;
    if (self->unk_38 != NULL) {
        func_ov000_02190a80(self->unk_38, func_0203db40(self->unk_24));
    }
    v = 0;
    p = *func_ov000_02190a30(self->unk_38, 0);
    if (p != NULL) {
        v = *p;
    }
    if (v < 0x1000) {
        pos.x = self->pos.x;
        pos.y = self->pos.y;
        pos.z = self->pos.z + 0xc000;
        func_0204a028(data_02097e4c, 0x39, &pos, -5);
    }
    if (self->kind == 0x6a01) {
        return;
    }
    func_ov000_02190a80(self->anim, func_0203db40(self->unk_24));
}

BOOL func_ov003_021f388c(Ov003Prop *self) {
    BOOL r = func_ov000_0218cea4(self);
    int i;
    if (r && self->kind != 0x6a01) {
        for (i = 0; i < 5; i++) {
            s32 y = self->pos.y + (data_ov003_021f7694[i].y << 4);
            s32 z = self->pos.z + (data_ov003_021f7694[i].z << 4);
            s32 x = self->pos.x + (data_ov003_021f7694[i].x << 4);
            self->effectPos.x = x;
            self->effectPos.y = y;
            self->effectPos.z = z;
            func_ov000_021903b4(self->anim);
        }
    }
    return r;
}

void func_ov003_021f3914(Ov003Prop *self) {
    func_ov000_021b4adc(self);
    func_ov000_0218f074(&self->unk_b0, &data_ov003_021fa658, 1, 1, 0, 0);
    self->unk_b0 = 0;
}
