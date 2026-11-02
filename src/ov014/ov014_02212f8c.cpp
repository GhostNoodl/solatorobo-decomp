#include "ov014/ov014.h"

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

extern "C" {

extern u8 data_ov014_02217d3a[];
extern Ov014Actor *func_ov000_0219bf90(void);
extern void Actor_TurnToActor(Ov014Obj *self, Ov014Obj *target, s32 a);
extern void *data_ov000_021ccd64;
extern u8 data_ov014_02217d4c[];
extern u8 data_ov014_02216dc0[];
extern Ov014Actor *Actor_GetTarget(Ov014Obj *self);
extern Ov014Actor *func_02065f88(s32 id, Ov014Vec *pos);
extern void func_ov000_02191618(void *a);
extern Ov014Actor *Group_SpawnActor(void *mgr, Ov014SpawnDesc *d, void *pos, void *rot, u16 a);

static inline void Ov014_TimerTick(Ov014Sub40 *s) {
    if (s->timer != 0) {
        s->timer--;
    }
}

void func_ov014_02212f8c(Ov014Act_0221267c *self) {
    Ov014Sub40 *s = self->unk_40;
    switch (Ov014Sub40_State(s)) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d3a, 0x19a, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state++;
        self->unk_40->timer = 60;
        break;
    case 1:
        Actor_TurnToActor(self, func_ov000_0219bf90(), 0x400);
        s = self->unk_40;
        if (Ov014Sub40_Timer(s) == 0) {
            s->state++;
            self->unk_40->timer = 30;
        } else {
            Ov014_TimerTick(s);
        }
        break;
    case 2:
        if (Ov014Sub40_Timer(s) == 0) {
            s->state--;
            self->unk_40->timer = 60;
        } else {
            Ov014_TimerTick(s);
        }
        break;
    }
}

void func_ov014_0221308c(Ov014Act_0221267c *self) {
    Ov014Sub40 *s = self->unk_40;
    switch (Ov014Sub40_State(s)) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d3a, 0x19a, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state = 10;
        self->unk_40->timer = 20;
        break;
    case 10:
        Actor_TurnToActor(self, Actor_GetTarget(self), 0x400);
        s = self->unk_40;
        if (Ov014Sub40_Timer(s) == 0) {
            func_02065f88(0x5e2, (Ov014Vec *)((u8 *)self + 0x33c))->v14(0x2000, 0x2000, 0x2000);
            self->unk_40->state++;
            self->unk_40->timer = 60;
        } else {
            Ov014_TimerTick(s);
        }
        break;
    case 11:
        if (Ov014Sub40_Timer(s) == 0) {
            func_ov000_02190cb0(self->unk_38, data_ov014_02217d4c, 0x19a, 0);
            func_ov000_02191618(self->unk_38);
            self->unk_40->state++;
        } else {
            Ov014_TimerTick(s);
        }
        break;
    case 12:
        if (self->unk_38->unk_c4 == 1) {
            Ov014SpawnDesc desc;
            Ov014Actor *o;
            Ov014Spawn_Init(&desc, 0x483a);
            o = Group_SpawnActor(data_ov000_021ccd64, &desc, (u8 *)self + 0x33c, self->rot, 0xffff);
            o->unk_60 = data_ov014_02216dc0;
            o->unk_90 = self->unk_90;
            if (o->unk_4c != NULL) {
                o->unk_4c->target = self->id;
            }
            o->flags_0 = 1;
            self->target_id = o->id;
            self->unk_40->state = 20;
            self->unk_40->timer = 120;
        }
        break;
    case 20:
        if (Ov014Sub40_Timer(s) == 0) {
            s->state = 0xffff;
        } else {
            Ov014_TimerTick(s);
        }
        break;
    default:
        s->state = 0xffff;
        break;
    }
}


extern u16 FX_Atan2(s32 x, s32 z);
extern u16 func_01ffc128(u16 a, u16 b, s32 c, s32 d, s32 e);
extern void *data_ov000_021ccd68;
extern Ov014Actor *ActorMgr_GetActor(void *mgr, u16 id);

void func_ov014_02213318(Ov014Act_0221267c *self) {
    Ov014Sub40 *s = self->unk_40;
    switch (Ov014Sub40_State(s)) {
    case 0: {
        s32 base;
        u16 ang;
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d3a, 0x19a, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state = 10;
        self->unk_40->timer = 0x14;
        base = self->unk_354 != 0 ? 0x1fff : -0x1fff;
        ang = FX_Atan2(self->unk_84.x - self->pos.x, self->unk_84.z - self->pos.z);
        self->unk_34c = base + ang;
        self->unk_350 = (-base * 2) / 100;
        break;
    }
    case 10:
        self->rot[1] = func_01ffc128(self->unk_34c, self->rot[1], 0x400, 1, 0x8000);
        s = self->unk_40;
        if (Ov014Sub40_Timer(s) == 0) {
            func_02065f88(0x5dd, (Ov014Vec *)((u8 *)self + 0x33c))->v14(0x2000, 0x2000, 0x2000);
            self->unk_40->state++;
            self->unk_40->timer = 0x3c;
        } else {
            Ov014_TimerTick(s);
        }
        break;
    case 11:
        if (Ov014Sub40_Timer(s) == 0) {
            func_ov000_02190cb0(self->unk_38, data_ov014_02217d4c, 0x19a, 0);
            func_ov000_02191618(self->unk_38);
            self->unk_40->state++;
        } else {
            Ov014_TimerTick(s);
        }
        break;
    case 12:
        if (self->unk_38->unk_c4 == 1) {
            Ov014SpawnDesc desc;
            Ov014Actor *o;
            Ov014Spawn_Init(&desc, 0x483a);
            o = Group_SpawnActor(data_ov000_021ccd64, &desc, (u8 *)self + 0x33c, self->rot, 0xffff);
            o->unk_60 = data_ov014_02216dc0;
            o->unk_90 = self->unk_90;
            if (o->unk_4c != NULL) {
                o->unk_4c->target = self->id;
            }
            o->flags_0 = 1;
            self->target_id = o->id;
            self->unk_312--;
            self->unk_40->state++;
            self->unk_40->timer = 0x78;
        }
        break;
    case 13:
        if (Ov014Sub40_Timer(s) == 0) {
            s->state = 0x14;
        } else {
            Ov014Actor *a;
            u16 id;
            self->unk_34c += self->unk_350;
            self->rot[1] = self->unk_34c;
            id = self->target_id;
            if (data_ov000_021ccd68 == NULL) {
                a = NULL;
            } else {
                a = ActorMgr_GetActor(data_ov000_021ccd68, id);
            }
            if (a != NULL) {
                a->pos = self->unk_33c;
                a->rot[1] = self->unk_34c;
            }
            Ov014_TimerTick(self->unk_40);
        }
        break;
    case 20:
        s->state = 0xffff;
        break;
    default:
        s->state = 0xffff;
        break;
    }
}

}
