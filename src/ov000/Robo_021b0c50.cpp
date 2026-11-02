#include "ov000/Actor.h"

typedef struct {
    u32 bit0 : 1;
    u32 rest : 31;
} RoboFlags;

#define ROBO_FLAGS(self) ((RoboFlags *)((u8 *)(self) + 0xb24))

typedef struct {
    RoboFlags flags;
    u8 pad_b28[0x20];
    s32 unk_b48;
    s32 unk_b4c;
    s32 unk_b50;
    s32 unk_b54;
    u16 unk_b58;
    u16 unk_b5a;
    u16 unk_b5c;
    u16 unk_b5e;
} RoboTail;

#define ROBO_TAIL(self) ((RoboTail *)((u8 *)(self) + 0xb24))

typedef struct {
    u8 pad_00[0x24];
    s32 unk_24;
    u8 pad_28[0x14];
    s32 unk_3c;
} Effect021b0d04;

extern "C" {

extern char data_ov000_021cc6c6[];
void func_ov000_021b0db0(Actor *self, s32 id);
BOOL func_ov000_02191120(void *p);
void func_ov000_0218996c(u8 a, u8 b);
void func_ov000_021ad130(Actor *self);
Effect021b0d04 *func_02065f88(s32 id, VecFx32 *pos);
s32 Rand_PlusMinus(s32 max);
s32 Rand_UpTo(s32 max);

void func_ov000_021b0c50(Actor *self) {
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov000_021cc6c6, 0x800, 0);
        func_ov000_0218996c(8, 0xc);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
    case 1:
        if (func_ov000_02191120(self->model)) {
            switch (ROBO_FLAGS(self)->bit0) {
            default:
                func_ov000_02198360(self->fsm, 0x14, 0);
                break;
            case 0:
                func_ov000_02198360(self->fsm, 1, 0);
                break;
            }
        }
        func_ov000_021b0db0(self, -1);
        break;
    }
}

void func_ov000_021b0d04(Actor *self) {
    func_ov000_021ad130(self);
    if (*self->hp == 0 && !(self->fsm->timer & 0x1f)) {
        Effect021b0d04 *e = func_02065f88(0x38f, &self->pos);
        s32 a;
        s32 b;
        s32 c;
        e->unk_3c = 0x2000;
        ROBO_TAIL(self)->unk_b48 = e->unk_24;
        ROBO_TAIL(self)->unk_b5e = 0x29;
        a = Rand_PlusMinus(0x1800);
        b = Rand_UpTo(0x3000);
        c = Rand_PlusMinus(0x1800);
        ROBO_TAIL(self)->unk_b4c = a;
        ROBO_TAIL(self)->unk_b50 = b;
        ROBO_TAIL(self)->unk_b54 = c;
        ROBO_TAIL(self)->unk_b58 = 0;
        ROBO_TAIL(self)->unk_b5a = 0;
        ROBO_TAIL(self)->unk_b5c = 0;
    }
    func_ov000_021b0db0(self, -1);
}

}
