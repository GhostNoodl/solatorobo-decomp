#include "ov009/ov009.h"

extern "C" {

extern u8 data_ov009_02216aaa[];
extern u8 data_ov009_02216abc[];
extern void func_ov000_0218ddd4(Ov009Actor *self, Ov009Vec *v, s32 a);

void func_ov009_021fb890(Ov009Actor *self) {
    Ov009Vec v;
    Ov009Param *p;
    if (self->unk_40->state == 0) {
        u8 *anim = data_ov009_02216aaa;
        if (self->unk_ee_0) {
            anim = data_ov009_02216abc;
        }
        func_ov000_02190cb0(self->unk_38, anim, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state++;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
    }
    p = self->unk_b0;
    self->unk_9c = p->unk_00;
    v = self->unk_b8;
    func_ov000_0218ddd4(self, &v, p->unk_02);
    self->pos.y += Ov009_FxMul(v.y + 0x1400 - self->pos.y, 0xcd);
    if (self->pos.y - v.y > 0x3000) {
        self->unk_48->unk_30 = 0x80000000;
    }
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
    self->unk_48->unk_30 = 0xc0000000;
}

extern void *data_ov000_021ccd68;
extern u8 data_ov009_02216aa4[];
extern u8 data_ov009_02216ab6[];
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 turn);
static inline Ov009Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov009_021fb9b0(Ov009Actor *self) {
    Ov009Sub40 *st;
    s32 g;
    if (!Ov009_GameIdle()) {
        func_ov000_02198360(self->unk_40, 1, 0);
        return;
    }
    st = self->unk_40;
    switch (st->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02216aa4, 0x200, 1);
        self->unk_40->state++;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        break;
    case 1:
        func_ov000_0218d988(self, Ov009_FindActor(self->unk_90), self->unk_b0->unk_02);
        if (FLD(s16, self->unk_38, 0xc4) == 1) {
            self->unk_40->state++;
        }
        break;
    case 2:
        g = self->unk_48->unk_68.y;
        st->timer++;
        if (st->timer > 0x2d || self->pos.y < g + 0xc00) {
            func_ov000_02190cb0(self->unk_38, data_ov009_02216ab6, 0x200, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_40->timer = 0;
            self->unk_40->state++;
            if (self->pos.y < g + 0xc00) {
                self->unk_a0 >>= 1;
            }
        }
        break;
    case 3:
        self->unk_9c -= self->unk_9c >> 3;
        self->unk_a0 -= self->unk_a0 >> 2;
        g = self->unk_1c;
        st->timer++;
        if (st->timer > g) {
            func_ov000_02198360(self->unk_40, 1, 0);
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
        }
        break;
    }
    func_ov000_0218dbe0(self, 0);
    func_ov000_021987b8(self->unk_48, 0, 0, 0);
}

}
