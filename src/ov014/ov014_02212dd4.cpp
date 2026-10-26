#include "ov014/ov014.h"

extern "C" {

extern u8 data_ov014_02217d3a[];
extern void func_ov000_02191318(void *a, s32 b);
extern Ov014Actor *func_ov000_0219bf90(void);
extern void func_ov000_0218d988(Ov014Actor *self, Ov014Actor *target, s32 a);
extern Ov014Actor *func_02065f88(s32 id, Ov014Vec *pos);
extern s32 FX_Div(s32 a, s32 b);
extern s32 func_02049130(s32 a, s32 b, s32 c);

static inline void Ov014_TimerTick(Ov014Sub40 *s) {
    if (s->timer != 0) {
        s->timer--;
    }
}

void func_ov014_02212dd4(Ov014Actor *self) {
    Ov014Sub40 *s = self->unk_40;
    switch (Ov014Sub40_State(s)) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d3a, 0x19a, 0);
        func_ov000_02191318(self->unk_38, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state++;
        self->unk_40->timer = 120;
        break;
    case 1: {
        u16 t = s->timer;
        u8 b = func_02049130(FX_Div(t << 12, 0x78000), 0x1f000, 0) >> 12;
        FLD(u8, self->unk_38, 0xbe) = b;
        FLD(u8, self, 0x2e6) = b;
        if (t == 50) {
            func_02065f88(0xcb, &self->pos)->v14(0x2000, 0x2000, 0x2000);
        }
        if (t == 20) {
            Ov014Vec v;
            v.x = self->pos.x;
            v.y = self->pos.y;
            v.z = self->pos.z;
            v.y += 0x2000;
            func_02065f88(0x38a, &v)->v14(0x2000, 0x2000, 0x2000);
        }
        func_ov000_0218d988(self, func_ov000_0219bf90(), 0x400);
        s = self->unk_40;
        if (Ov014Sub40_Timer(s) == 0) {
            s->state++;
        } else {
            Ov014_TimerTick(s);
        }
        break;
    }
    case 2: {
        Ov014Sub44 *n;
        s->state = 0xffff;
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        break;
    }
    }
}

}
