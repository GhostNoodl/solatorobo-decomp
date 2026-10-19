#include "nitro/fx.h"

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
