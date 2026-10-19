#include "nitro/fx.h"

typedef struct {
    u8 b0 : 4;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
} Bits0218a9d8;

typedef struct {
    s32 unk_00;
    s32 unk_04;
    u16 unk_08;
    u8 unk_0a;
    u8 unk_0b;
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0x20];
    u16 unk_30;
    u16 unk_32;
    u16 unk_34[4];
    s16 unk_3c;
    u8 unk_3e[3];
    u8 unk_41[3];
    VecFx32 box[4];
    s32 unk_74[5];
    s32 unk_88;
    s32 unk_8c;
    s32 unk_90;
    u16 unk_94;
    u16 unk_96;
    u16 unk_98;
    u16 unk_9a;
    s32 unk_9c;
    u8 unk_a0;
    u8 unk_a1;
    Bits0218a9d8 unk_a2;
    u8 unk_a3;
} Obj0218a9d8;

typedef struct {
    VecFx32 from;
    VecFx32 to;
    u16 angle;
} Seg0218ac98;

typedef struct {
    u8 c[3];
} Rgb0218ac98;

typedef struct {
    u8 pad[0xc9];
    u8 unk_c9;
    Rgb0218ac98 c;
} Glob0218ac98;

typedef struct {
    u8 pad[0xc];
    u16 unk_0c;
    u8 pad0e[9];
    u8 unk_17;
} Spawn0218ac98;

typedef struct {
    u8 pad[2];
    u16 unk_02;
    u8 pad04[0xa];
    Rgb0218ac98 c;
    u8 pad11;
    u16 unk_12;
    u16 unk_14;
    u16 unk_16;
    VecFx32 pos;
} Rec0218ac98;

typedef struct {
    u8 pad[0xe];
    Rgb0218ac98 c;
    u8 mask[3];
    u8 pad14[0x44];
} Param0218ac98;

typedef struct {
    u8 pad[0xc];
    u16 unk_0c;
    u8 pad0e[8];
    u8 f0 : 1;
    u8 f1 : 1;
} Actor0218ab00;

typedef struct {
    u8 pad[0xb1c];
    u16 unk_b1c;
    u8 padb1e[2];
    u16 unk_b20;
} Ctx0218ab00;

typedef struct {
    u8 pad[0xd];
    u8 count;
    u8 pad0e[2];
    VecFx32 pts[4];
    u16 angles[4];
} Mgr0218ac98;

typedef struct {
    u8 pad[8];
    u16 unk_08;
    u8 state;
    u8 unk_0b;
    Rec0218ac98 recs[1];
    Param0218ac98 param;
    VecFx32 pos;
    u16 unk_94;
    u16 unk_96;
    u16 unk_98;
    u16 unk_9a;
    u32 unk_9c;
    s8 unk_a0;
    s8 unk_a1;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 unk_a3;
} Obj0218ac98;

extern "C" {

Obj0218a9d8 *func_ov000_0218a9d8(Obj0218a9d8 *self) {
    s32 i;
    self->unk_00 = 0;
    self->unk_04 = 0;
    self->unk_08 = 0xffff;
    self->unk_0a = 1;
    self->unk_0b = 0;
    self->unk_0c = 0xffff;
    self->unk_0e = 0xffff;
    self->unk_30 = 0xffff;
    self->unk_32 = 0xf000;
    for (i = 0; i < 4; i++) {
        self->unk_34[i] = 0;
    }
    self->unk_3c = -1;
    self->unk_3e[0] = 0xff;
    self->unk_3e[1] = 0xff;
    self->unk_3e[2] = 0xff;
    self->unk_41[0] = 0xff;
    self->unk_41[1] = 0xff;
    self->unk_41[2] = 0xff;
    self->unk_88 = 0;
    self->unk_8c = 0;
    self->unk_90 = 0;
    self->unk_94 = 0;
    self->unk_96 = 0;
    self->unk_98 = 0;
    self->unk_74[0] = 0x37000;
    self->unk_74[1] = 0x39000;
    self->unk_74[2] = 0x14000;
    self->unk_74[3] = 0x16000;
    self->unk_74[4] = 0x32000;
    self->box[0].x = -self->unk_74[0];
    self->box[0].y = -self->unk_74[2];
    self->box[0].z = -self->unk_74[0];
    self->box[1].x = self->unk_74[0];
    self->box[1].y = self->unk_74[2];
    self->box[1].z = self->unk_74[0];
    self->box[2].x = -self->unk_74[1];
    self->box[2].y = -self->unk_74[3];
    self->box[2].z = -self->unk_74[1];
    self->box[3].x = self->unk_74[1];
    self->box[3].y = self->unk_74[3];
    self->box[3].z = self->unk_74[1];
    self->unk_9c = 0;
    self->unk_9a = 0;
    self->unk_a0 = 0;
    self->unk_a1 = 0;
    *(u8 *)&self->unk_a2 = 0xff;
    self->unk_a2.b4 = 0;
    self->unk_a2.b5 = 0;
    self->unk_a2.b6 = 0;
    self->unk_a3 = 0xff;
    return self;
}


extern Glob0218ac98 *data_ov000_021ccd54;
extern Mgr0218ac98 *data_ov000_021ccd64;
BOOL func_01ffc89c(Obj0218ac98 *vol, Seg0218ac98 *seg);
s32 func_ov000_0219a2f4(VecFx32 *pos, s32 up, s32 down);
Spawn0218ac98 *func_ov000_0218bf1c(Mgr0218ac98 *mgr, void *a, VecFx32 *pos, void *b, u16 c);

void func_ov000_0218adf0(Obj0218ac98 *self);
void func_ov000_0218af9c(Obj0218ac98 *self);
void func_ov000_0218bc9c(void *mgr, Obj0218ac98 *self, s32 a);
extern void *data_ov000_021ccd68;
Ctx0218ab00 *func_ov000_0219bf90(void);
Actor0218ab00 *func_ov000_0218e640(void *mgr, u16 id);
void *func_ov000_0218e4cc(void *mgr, u16 key);
void func_ov000_0218df68(void *group, Actor0218ab00 *actor);
void func_ov000_0218b4b4(Obj0218ac98 *self, s32 mode, Actor0218ab00 *actor);

static inline Actor0218ab00 *GetActor0218ab00(u16 id) {
    Actor0218ab00 *a;
    if (data_ov000_021ccd68 == NULL) {
        a = NULL;
    } else {
        a = func_ov000_0218e640(data_ov000_021ccd68, id);
    }
    return a;
}

#define REC(s, i) ((Rec0218ac98 *)((u8 *)(s) + (i) * 0x24 + 0xc))

void func_ov000_0218ab00(Obj0218ac98 *self) {
    Glob0218ac98 *g;
    BOOL changed;
    Ctx0218ab00 *ctx;
    u8 *base;
    s32 i;
    Actor0218ab00 *a;
    g = data_ov000_021ccd54;
    changed = FALSE;
    if (self->param.mask[2] != 0xff && self->param.mask[2] != g->c.c[2]) {
        changed = TRUE;
    }
    if (self->param.mask[1] != 0xff && self->param.mask[1] != g->c.c[1]) {
        changed = TRUE;
    }
    if (self->param.mask[0] != 0xff && self->param.mask[0] != g->c.c[0]) {
        changed = TRUE;
    }
    if (g->unk_c9 != 0) {
        changed = TRUE;
    }
    ctx = func_ov000_0219bf90();
    for (i = 0; i < self->unk_0b; i++) {
        if (REC(self, i)->unk_02 == 0xffff) {
            continue;
        }
        base = (u8 *)self + i * 0x24;
        a = GetActor0218ab00(((Rec0218ac98 *)(base + 0xc))->unk_02);
        if (a == NULL) {
            continue;
        }
        if (ctx != NULL && ((Rec0218ac98 *)(base + 0xc))->unk_02 == ctx->unk_b20) {
            continue;
        }
        if (a->f1) {
            a->f1 = 0;
            continue;
        }
        if (changed) {
            a->f0 = 1;
        }
        if (self->b6 && ctx != NULL && ((Rec0218ac98 *)(base + 0xc))->unk_02 == ctx->unk_b1c && data_ov000_021ccd54->unk_c9 == 0) {
            continue;
        }
        func_ov000_0218b4b4(self, 2, a);
        func_ov000_0218df68(func_ov000_0218e4cc(data_ov000_021ccd68, a->unk_0c & 0xf000), a);
    }
    if (changed) {
        func_ov000_0218bc9c(data_ov000_021ccd64, self, 0);
    }
}

}
