#include "ov014/ov014.h"

extern "C" {

extern void *data_02097e4c;
extern char data_ov014_02217d7c[];
extern void *func_ov000_02191318(void *a, s32 b);
extern void func_ov000_02191618(void *p);
extern void *func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern void func_ov000_021911c8(void *a, s32 b);
extern void func_ov000_0219bd20(s32 a, u16 b, s32 c, s32 d, s32 e, u8 *f);
extern Ov014Actor *func_02065f88(s32 id, Ov014Vec *pos);
extern s32 Interp_SinLerp(s32 a, s32 b, s32 c);

struct Ov014SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov014Spawn_Init(Ov014SpawnDesc *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

struct Ov014Bit16 {
    u8 b0 : 1;
};

extern char data_ov014_02217d3a[];
extern char data_ov014_02217d4c[];
extern u8 data_ov014_02216e08[];
extern Ov014Actor *Group_SpawnActor(void *mgr, Ov014SpawnDesc *d, Ov014Vec *pos, u16 *rot, u16 a);

static inline void Ov014_TimerDec(Ov014Sub40 *s) {
    if (s->timer != 0) {
        s->timer--;
    }
}

void func_ov014_022136b4(Ov014Act_0221267c *self) {
    Ov014Sub40 *s = self->unk_40;
    switch (Ov014Sub40_State(s)) {
    case 0: {
        s32 base;
        u16 ang;
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d3a, 0x19a, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state = 10;
        self->unk_40->timer = 0x14;
        base = self->unk_354 != 0 ? -0x1555 : 0x1555;
        ang = FX_Atan2(self->unk_84.x - self->pos.x, self->unk_84.z - self->pos.z);
        self->unk_34c = base + ang;
        self->unk_312 = 3;
        self->unk_350 = (-base * 2) / 3;
        break;
    }
    case 10: {
        Ov014Actor *e = func_02065f88(0x5e1, &self->unk_33c);
        e->v14(0x2000, 0x2000, 0x2000);
        self->unk_40->state++;
        self->unk_40->timer = 0x3c;
        break;
    }
    case 11: {
        self->rot[1] = func_01ffc128(self->unk_34c, self->rot[1], 0x400, 1, 0x8000);
        s = self->unk_40;
        if (Ov014Sub40_Timer(s) == 0) {
            func_ov000_02190cb0(self->unk_38, data_ov014_02217d4c, 0x19a, 0);
            func_ov000_02191618(self->unk_38);
            self->unk_40->state++;
        } else {
            Ov014_TimerDec(s);
        }
        break;
    }
    case 12: {
        Ov014SpawnDesc d;
        Ov014Actor *o;
        if (self->unk_38->unk_c4 != 1) {
            break;
        }
        Ov014Spawn_Init(&d, 0x483b);
        o = Group_SpawnActor(data_ov000_021ccd64, &d, &self->unk_33c, self->rot, 0xffff);
        o->unk_60 = data_ov014_02216e08;
        o->unk_90 = self->unk_90;
        if (o->unk_4c != NULL) {
            o->unk_4c->target = self->id;
        }
        FLD(Ov014Bit16, o, 0x16).b0 = 1;
        self->target_id = o->id;
        self->unk_312--;
        self->unk_40->state++;
        self->unk_40->timer = 0x32;
        break;
    }
    case 13:
        if (Ov014Sub40_Timer(s) == 0) {
            func_ov000_02190cb0(self->unk_38, data_ov014_02217d3a, 0x19a, 0);
            func_ov000_021915a0(self->unk_38);
            if (self->unk_312 == 0) {
                self->unk_40->state = 0x14;
                self->unk_40->timer = 0x14;
            } else {
                self->unk_34c = self->unk_34c + self->unk_350;
                self->unk_40->state = 0xb;
                self->unk_40->timer = 0x14;
            }
        } else {
            Ov014_TimerDec(s);
        }
        break;
    case 0x14:
        if (Ov014Sub40_Timer(s) == 0) {
            s->state = 0xffff;
        } else {
            Ov014_TimerDec(s);
        }
        break;
    default:
        s->state = 0xffff;
        break;
    }
}

void func_ov014_02213a4c(Ov014Act_0221267c *self) {
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d7c, 0x1000, 0);
        func_ov000_02191318(self->unk_38, 0);
        func_ov000_02191618(self->unk_38);
        self->unk_40->state++;
        func_02049f44(data_02097e4c, 0x67, &self->pos, 0);
        break;
    case 1:
        if (func_ov000_02191120(self->unk_38)) {
            self->unk_40->state = 0xffff;
        }
        break;
    default:
        self->unk_40->state = 0xffff;
        break;
    }
}

void func_ov014_02213afc(Ov014Act_0221267c *self) {
    switch (self->unk_40->state) {
    case 0: {
        u8 c;
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d7c, 0x19a, 0);
        func_ov000_02191318(self->unk_38, 0);
        func_ov000_021915a0(self->unk_38);
        func_ov000_021911c8(self->unk_38, 0x800);
        self->unk_40->state++;
        self->unk_40->timer = 120;
        c = 0x15;
        func_ov000_0219bd20(0x483a, self->id, 2, 1, 1, &c);
        func_ov000_0219bd20(0x483b, self->id, 2, 1, 1, &c);
        func_02049f44(data_02097e4c, 0x68, &self->pos, 0);
        break;
    }
    case 1: {
        u8 b;
        if (self->unk_40->timer % 30 == 0) {
            func_02065f88(0x38a, &self->pos);
        }
        b = Interp_SinLerp(FX_Div(self->unk_40->timer << 12, 0x78000), 0, 0x1f000) >> 12;
        self->unk_38->unk_be = b;
        self->unk_2e6 = b;
        if (self->unk_40->timer == 0) {
            self->unk_40->state++;
        }
        if (self->unk_40->timer != 0) {
            self->unk_40->timer--;
        }
        break;
    }
    case 2:
        func_ov000_0218bed8(data_ov000_021ccd64, 0, (Actor *)self);
        self->v08();
        self->unk_40->state = 0xffff;
        break;
    }
}

}
