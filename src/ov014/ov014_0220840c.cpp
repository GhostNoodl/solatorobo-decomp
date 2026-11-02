#include "ov014/ov014.h"

struct Ov014HitArg {
    u8 a;
    u8 pad;
    u16 b;
    u16 c;
};

extern "C" {

extern Ov003Actor *Actor_GetTarget(Actor *self);
extern s32 func_ov000_0219a510(Actor *self, u16 mask, VecFx32 *pos, s32 r, s32 a, Ov003Actor **list);
extern Ov003Actor *func_ov000_021985c0(Ov003Actor *p);
void MIi_CpuClear32(u32 data, void *dest, u32 size);

static inline BOOL Ov014_AnyHit(Ov014ActEx_0220774c *self) {
    s32 r = self->unk_d4;
    if (r != 0) {
        Ov003Actor *list[0x20];
        s32 n = func_ov000_0219a510(self, 2, &self->pos, FX_Mul(r, 0xb33), 0x800, list);
        s32 i;
        if (n != 0) {
            for (i = 0; i < n; i++) {
                if (list[i] != NULL && func_ov000_021985c0(list[i]) != NULL) {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

void func_ov014_0220840c(Ov014ActEx_0220774c *self) {
    Ov003Actor *t = Actor_GetTarget(self);
    VecFx32 p;
    p.x = t->pos.x;
    p.y = t->pos.y;
    p.z = t->pos.z;
    if (t->hp[0] != 0) {
        if (Ov014_AnyHit(self) && t != NULL) {
            Ov014HitArg arg;
            arg.b = 0x666;
            arg.a = 1;
            arg.c = 1;
            Actor_SendMsg(t, self->id, 0xb, 1, 6, &arg);
            p.y += 0x1800;
            if (!Ov003FxList_Has(self->unk_d8, 0xfe)) {
                EffectObj *e = func_02065f88(0xcb, &p);
                e->SetRotXYZ(0, 0, 0x7fff);
                e->SetScaleAll(0xb33);
                MIi_CpuClear32(-1, (u8 *)e + 0x84, 0x40);
                func_0204a028(data_02097e4c, 0x11, &self->pos, -10);
                func_ov003_021da9ac(self->unk_d8, 0xfe, e);
            } else {
                func_ov003_021daae4(self->unk_d8, 0xfe, &p, 0, 0, 0, 0);
            }
        } else {
            Ov003FxList_Kill(self->unk_d8, 0xfe);
        }
    } else {
        func_ov000_02198360(self->fsm, 0x15, 0);
    }
}


extern u8 data_ov014_02217708[];
extern void *ActorEx_Ctor(void *self);
extern void func_ov000_02194758(void *self);
extern void func_0203f364(ActorSub48 *p);

#pragma force_active on
Ov014ActEx_02208618 *Ov014ActEx_02208618_Ctor(Ov014ActEx_02208618 *self) {
    ActorEx_Ctor(self);
    FLD(void *, self, 0) = data_ov014_02217708;
    self->unk_d0 = 0;
    self->unk_d8 = NULL;
    self->unk_d4 = 0;
    return self;
}
#pragma force_active reset

Ov014ActEx_02208618 *Ov014ActEx_02208618_Dtor(Ov014ActEx_02208618 *self) {
    FLD(void *, self, 0) = data_ov014_02217708;
    Ov014_FreeFx(self, 0xd8);
    func_ov000_0219429c(self);
    return self;
}

Ov014ActEx_02208618 *Ov014ActEx_02208618_DtorDelete(Ov014ActEx_02208618 *self) {
    FLD(void *, self, 0) = data_ov014_02217708;
    Ov014_FreeFx(self, 0xd8);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void Ov014ActEx_02208618_Start(Ov014ActEx_02208618 *self) {
    ActorSub48 *m;
    func_ov000_02194758(self);
    self->unk_d8 = Ov014_NewFx();
    m = self->hit;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    func_0203f364(m);
    self->hit->unk_30 = 0;
    func_ov000_02198360(self->fsm, 0xb, 0);
}

void Ov014ActEx_02208618_Update(Ov014ActEx_02208618 *self) {
    func_ov000_021953b4(self);
    func_ov003_021dacfc(((void *)self->unk_d8));
}

}
