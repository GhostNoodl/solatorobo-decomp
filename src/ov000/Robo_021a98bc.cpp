#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u16 state;
    u16 timer;
} State021a98bc;

typedef struct {
    u32 b0 : 12;
    u32 b12 : 2;
    u32 b14 : 4;
    u32 b18 : 1;
    u32 b19 : 1;
    u32 b20 : 1;
    u32 b21 : 1;
    u32 rest : 10;
} B24_021a98bc;

typedef struct {
    u16 b0 : 3;
    u16 rest : 13;
} B22_021a98bc;

extern "C" {

extern u8 data_ov000_021cc69c[];
extern u8 data_ov000_021cc6a2[];
extern u8 data_ov000_021cc6a8[];
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_02191120(void *a);
BOOL func_ov000_02198360(State021a98bc *st, s32 state, s32 x);
void func_ov000_021b1fac(void *self, BOOL a, s32 b);
u8 *func_ov000_0218d240(void *self);
u8 *func_ov000_0218d2e0(void *self);
u16 func_ov000_0218d8f4(void *self, void *target);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);

void func_ov000_021a98bc(Robo021ca458 *self) {
    u8 *t;
    State021a98bc *s;
    func_ov000_0218d240(self);
    t = func_ov000_0218d2e0(self);
    s = (State021a98bc *)self->unk_40;
    switch (s->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov000_021cc69c, 0x555, 0);
        self->unk_9c >>= 1;
        self->unk_a4 = 0xd9a;
        if (self->unk_a0 <= 0) {
            self->unk_a0 = 0x2e;
        } else {
            self->unk_a0 -= self->unk_a0 >> 2;
        }
        if (t != NULL) {
            self->unk_98 = func_ov000_0218d8f4(self, t);
        } else {
            self->unk_98 = self->unk_7e;
        }
        ((State021a98bc *)self->unk_40)->state++;
    case 1:
        if (self->unk_a0 < 0) {
            self->unk_a8 = 0x14;
        }
        if (LFLD(s16, self->unk_38, 0xc4) == 1) {
            LFLD(B24_021a98bc, self, 0xb24).b21 = 1;
            self->unk_a8 = 0x29;
            ((State021a98bc *)self->unk_40)->state++;
        }
        break;
    case 2:
        if (LFLD(s16, self->unk_38, 0xc4) == 2) {
            func_ov000_02190cb0(self->unk_38, data_ov000_021cc6a2, 0x333, 1);
            ((State021a98bc *)self->unk_40)->state = 10;
        }
        break;
    case 10:
        if (LFLD(s16, self->unk_38, 0xc4) == 1) {
            s->state = ((const State021a98bc *)s)->state + 1;
        }
        break;
    case 11:
        if (func_ov000_02191120(self->unk_38)) {
            ((State021a98bc *)self->unk_40)->state = 20;
        } else {
            State021a98bc *q = (State021a98bc *)self->unk_40;
            if (LFLD(u64, q, 4) != 0) {
                if (LFLD(u64, q, 4) & 0x10000) {
                    s32 lim;
                    BOOL hit = FALSE;
                    if (!(LFLD(u32, self->unk_48, 0x54) & 0x20000000)) {
                        lim = -0xf000;
                        if (LFLD(B22_021a98bc, self, 0xb22).b0 != 0 || LFLD(B24_021a98bc, self, 0xb24).b12 != 0 || LFLD(B24_021a98bc, self, 0xb24).b19) {
                            lim = -0x2d000;
                        }
                        if (self->unk_70.y - self->unk_b00 < lim) {
                            hit = TRUE;
                        }
                    }
                    if (hit) {
                        LFLD(B24_021a98bc, self, 0xb24).b18 = 1;
                        ((State021a98bc *)self->unk_40)->state = 20;
                    } else {
                        func_ov000_02190cb0(self->unk_38, data_ov000_021cc6a2, 0x333, 1);
                        ((State021a98bc *)self->unk_40)->state = 10;
                    }
                } else {
                    q->state = 20;
                }
            }
        }
        break;
    case 20:
        func_ov000_02190cb0(self->unk_38, data_ov000_021cc6a8, 0x800, 0);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0x52;
        ((State021a98bc *)self->unk_40)->state++;
        break;
    case 21:
        if (LFLD(s16, self->unk_38, 0xc4) == 1) {
            LFLD(B24_021a98bc, self, 0xb24).b21 = 0;
        }
        if (func_ov000_02191120(self->unk_38)) {
            LFLD(B24_021a98bc, self, 0xb24).b21 = 0;
            func_ov000_02198360((State021a98bc *)self->unk_40, 1, 0);
        }
        break;
    }
    self->unk_7e = func_01ffc128(self->unk_98, self->unk_7e, 0x400, 1, 0x8000);
    func_ov000_021b1fac(self, FALSE, 1);
}

}
