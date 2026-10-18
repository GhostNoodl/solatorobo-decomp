#include "types.h"

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 1;
} Ov003Unit;

typedef struct {
    u16 state;
    u16 timer;
} Ov003PropWk;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0x10];
    u16 unk_20;
    u8 unk_22[0x1e];
    Ov003PropWk *work;
    u8 unk_44[0x2c];
    s32 pos[3];
} Ov003Prop;

typedef struct {
    u8 unk_00[0xac];
    u8 unk_ac;
} Ov003G54;

extern void *data_ov000_021ccd64;
extern void func_ov000_02194758(void *p);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_ov000_0218b700(Ov003Unit *u, s32 a, s32 b);

void func_ov003_021def4c(Ov003Prop *self) {
    Ov003Unit *u;
    func_ov000_02194758(self);
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (u == NULL) {
        return;
    }
    u->unk_a2_0 = 0;
    func_ov000_0218b700(u, 0x5000, 0);
}

extern Ov003G54 *data_ov000_021ccd54;
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);

void func_ov003_021def90(Ov003Prop *self) {
    Ov003PropWk *w = self->work;
    switch (w->state) {
    case 0:
        w->timer++;
        if (w->timer > 0x2d) {
            func_ov000_0218996c(0x28, 0x5a);
            self->work->timer = 0;
            self->work->state++;
        }
        break;
    case 1:
        w->timer++;
        if (w->timer > 100) {
            func_020627a0(self->unk_0e, self->unk_0c);
            func_020627dc(4);
            data_ov000_021ccd54->unk_ac = 1;
            self->work->timer = 0;
            self->work->state++;
        } else {
            self->pos[1] -= self->work->timer * 2 + 0x200;
        }
        break;
    case 2:
        w->timer++;
        if (w->timer > 0x32) {
            self->pos[1] += 0x1e800;
            self->work->state++;
        }
        self->pos[1] -= 0x266;
        break;
    }
}
