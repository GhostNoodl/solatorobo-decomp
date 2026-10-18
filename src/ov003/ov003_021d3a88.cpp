#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003V3;

typedef struct {
    u16 state;
    u16 timer;
} Ov003Wk;

typedef struct {
    u8 unk_00[0x50];
    u32 flags;
    u8 unk_54[0x46];
    u16 unk_9a_0 : 1;
    u16 unk_9a_1 : 2;
    u16 unk_9a_3 : 1;
    u16 unk_9a_4 : 1;
    u16 unk_9a_5 : 1;
} Ov003Ct;

typedef struct {
    u16 unk_00;
} Ov003S50;

typedef struct {
    u8 unk_00[0x19];
    u8 unk_19;
    u8 unk_1a;
    u8 unk_1b;
    u16 unk_1c;
} Ov003S4c;

typedef struct {
    u8 unk_00[0x22];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
} Ov003S44;

class Ov003Fx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void SetScale(s32 x, s32 y, s32 z);
    u8 unk_04[0x20];
    void *unk_24;
    u8 unk_28[0x54];
    s32 unk_7c;
};

typedef struct {
    s16 unk_00;
    s16 unk_02;
} Ov003SB0;

typedef struct {
    u8 unk_00[0x38];
    void *model;
    u8 unk_3c[4];
    Ov003Wk *work;
    Ov003S44 *unk_44;
    Ov003Ct *ctl;
    Ov003S4c *unk_4c;
    Ov003S50 *unk_50;
    u8 unk_54[0x10];
    s32 unk_64;
    u8 unk_68[8];
    s32 pos[3];
    u8 unk_7c[2];
    u16 unk_7e;
    u8 unk_80[0x18];
    u16 unk_98;
    u8 unk_9a[2];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[4];
    Ov003SB0 *unk_b0;
    u16 unk_b4;
    u16 unk_b6;
    Ov003V3 unk_b8;
    u8 unk_c4[0x20];
    void *unk_e4;
    u8 unk_e8[6];
    u16 unk_ee_0 : 1;
} Ov003Unk;

extern "C" {

extern s32 func_02040528(s32 max);
extern void func_ov000_02198360(void *p, s32 a, s32 b);

extern void *data_02097e4c;
extern void *data_0214a420;
extern void func_0203f324(Ov003Ct *ctl);
extern void func_02049f44(void *mgr, s32 id, void *pos, s32 a);
extern void func_ov000_02199dc0(Ov003S4c *p, void *self);
extern void func_ov000_0218dbe0(void *self, s32 a);
extern void func_ov000_021987b8(Ov003Ct *ctl, s32 a, s32 b, s32 c);
extern s32 FX_Div(s32 a, s32 b);
extern void func_02065804(void *mgr, void *p);
extern Ov003Fx *func_02065f88(s32 id, void *pos);


void func_ov003_021d3a88(Ov003Unk *self) {
    Ov003Wk *w = self->work;
    switch (w->state) {
    case 0: {
        Ov003Ct *ctl;
        Ov003S44 *s;
        self->unk_b4 = 0;
        self->unk_b6 = 0;
        ctl = self->ctl;
        ctl->unk_9a_0 = 1;
        ctl->unk_9a_3 = 1;
        func_0203f324(ctl);
        s = self->unk_44;
        s->unk_22_0 = 1;
        s->unk_22_1 = 1;
        self->work->state++;
        self->work->timer = 0;
        if (self->unk_50->unk_00 == 0 || self->unk_4c->unk_19 != 0) {
            func_02049f44(data_02097e4c, 0x32, self->pos, 0);
        } else {
            func_02049f44(data_02097e4c, 0xb, self->pos, 0);
        }
        func_ov000_02199dc0(self->unk_4c, self);
        self->unk_98 = self->unk_7e;
        if (self->unk_4c->unk_1b == 0) {
            return;
        }
        if (self->unk_e4 != NULL) {
            func_02065804(data_0214a420, self->unk_e4);
            self->unk_e4 = NULL;
        }
        if (self->unk_e4 == NULL) {
            Ov003Fx *fx = func_02065f88(0x321, self->pos);
            s32 r;
            s32 t;
            self->unk_e4 = fx->unk_24;
            r = self->unk_64;
            t = (r >> 2) + (r >> 3);
            fx->SetScale(r + t, r + t, r + t);
            fx->unk_7c = FX_Div(0x10000, 0x1f000);
        }
        break;
    }
    case 1:
        w->timer++;
        if (w->timer > 2) {
            func_ov000_02198360(self->work, 4, 0);
        }
        func_ov000_0218dbe0(self, 0);
        func_ov000_021987b8(self->ctl, 0, 0, 0);
        if (self->unk_a0 > 0 && (self->ctl->flags & 0x80000000)) {
            self->unk_a0 = -0xcd;
        }
        break;
    }
}

void func_ov003_021d3c78(Ov003Unk *self) {
    switch (self->work->state) {
    case 0:
        self->unk_b4 = 0;
        self->unk_b6 = 0;
        self->unk_9c = func_02040528(0x7b) + 0xf6;
        self->unk_a0 = 0x35c - 0x7b;
        self->unk_a4 = 0;
        self->unk_a8 = 0x52;
        self->unk_98 = self->unk_7e;
        self->unk_4c->unk_1c = 0xffff;
        self->work->state++;
        break;
    case 1:
        if (self->unk_50->unk_00 == 0) {
            func_ov000_02198360(self->work, 0x14, 0);
        } else {
            func_ov000_02198360(self->work, 4, 0);
        }
        break;
    }
}

}
