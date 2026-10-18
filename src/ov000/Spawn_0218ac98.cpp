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
    u8 pad[0xca];
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
    Rec0218ac98 recs[3];
    u8 pad78[0x10];
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
    u8 unk_a3;
} Obj0218ac98;

extern "C" {

void func_ov000_0218adf0(Obj0218ac98 *self);
void func_ov000_0218af9c(Obj0218ac98 *self);
void func_ov000_0218bc9c(void *mgr, Obj0218ac98 *self, s32 a);

extern Glob0218ac98 *data_ov000_021ccd54;
extern Mgr0218ac98 *data_ov000_021ccd64;
BOOL func_01ffc89c(Obj0218ac98 *vol, Seg0218ac98 *seg);
s32 func_ov000_0219a2f4(VecFx32 *pos, s32 up, s32 down);
Spawn0218ac98 *func_ov000_0218bf1c(Mgr0218ac98 *mgr, void *a, VecFx32 *pos, void *b, u16 c);

static inline BOOL Obj0218ac98_SameColor(Obj0218ac98 *self) {
    Glob0218ac98 *g = data_ov000_021ccd54;
    BOOL r = FALSE;
    if (g->c.c[0] == self->recs[1].c.c[0] && g->c.c[1] == self->recs[1].c.c[1] && g->c.c[2] == self->recs[1].c.c[2]) {
        r = TRUE;
    }
    return r;
}

void func_ov000_0218ac98(Obj0218ac98 *self) {
    switch (self->state) {
    case 1:
        if (!Obj0218ac98_SameColor(self)) {
            return;
        }
        func_ov000_0218adf0(self);
        if (self->unk_0b != 0) {
            self->state = 2;
        }
        break;
    case 2: {
        BOOL done;
        func_ov000_0218af9c(self);
        if (self->unk_0b != 0) {
            return;
        }
        done = FALSE;
        if (self->unk_a1 < 0) {
            done = TRUE;
        } else {
            self->unk_a0++;
            if (self->unk_a1 >= self->unk_a0) {
                done = TRUE;
            }
        }
        if (done) {
            self->state = 3;
            return;
        }
        func_ov000_0218bc9c(data_ov000_021ccd64, self, 0);
        break;
    }
    case 3:
        if (!Obj0218ac98_SameColor(self)) {
            return;
        }
        if (++self->unk_9c >= self->unk_9a * 60) {
            self->unk_9c = 0;
            self->state = 1;
        }
        break;
    }
}


void func_ov000_0218adf0(Obj0218ac98 *self) {
    Seg0218ac98 seg;
    VecFx32 pos;
    u8 i;
    seg.from = self->pos;
    for (i = 0; i < data_ov000_021ccd64->count; i = (u8)(i + 1)) {
        seg.to.x = data_ov000_021ccd64->pts[i].x;
        seg.to.y = data_ov000_021ccd64->pts[i].y;
        seg.to.z = data_ov000_021ccd64->pts[i].z;
        seg.angle = data_ov000_021ccd64->angles[i];
        if (func_01ffc89c(self, &seg)) {
            BOOL done = FALSE;
            Spawn0218ac98 *sp;
            pos = self->pos;
            if (self->b4) {
                func_ov000_0219a2f4(&pos, 0x5dc000, -0x1000);
            }
            sp = func_ov000_0218bf1c(data_ov000_021ccd64, (u8 *)self + 0x30, &pos, &self->unk_94, self->unk_08);
            if (sp != NULL) {
                Rec0218ac98 *r;
                done = TRUE;
                if (self->unk_a3 != 0xff) {
                    sp->unk_17 = self->unk_a3;
                }
                r = &self->recs[self->unk_0b];
                r->unk_02 = sp->unk_0c;
                r->pos = self->pos;
                r->unk_12 = self->unk_94;
                r->unk_14 = self->unk_96;
                r->unk_16 = self->unk_98;
                r->c = data_ov000_021ccd54->c;
                self->unk_0b++;
            }
            if (done) {
                return;
            }
        }
    }
}

}
