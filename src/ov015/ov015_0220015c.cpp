#include "ov015/ov015.h"

extern "C" {

s32 func_ov015_02209fb8(s32 x);
void *Ov015FishState2c_Ctor(Ov015FishState2c *self);
extern char data_ov015_022128c1[];
extern char data_ov015_022128d5[];
u8 *func_02066df0(void);
void func_ov015_02207c30(Ov015Ship *p);
BOOL func_ov015_022003ec(Ov015Obj34 *self);
void Ov015Fish_SetNextState(Ov015Fish *self, s32 a, s32 b);
void func_ov015_021fd00c(Ov015CamPair *self, s32 mode, const Ov015Vec *v);

void func_ov015_0220015c(Ov015Obj34 *self) {
    self->fx = NULL;
    self->step = 0;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
    self->unk_20 = 0;
    self->ship = 0;
    self->fish = 0;
    self->cam = 0;
    self->info = 0;
}

void func_ov015_02200194(Ov015Obj34 *self) {
    void *saved;
    if (EffectMgr_Contains(data_0214a420, self->fx) == 0) {
        return;
    }
    HEAP_PUSH(saved);
    DELETE_V(self->fx);
    HEAP_POP(saved);
}

BOOL func_ov015_02200204(Ov015Obj34 *self, Ov015Ship *a, Ov015Fish *b, Ov015CamPair *c, Ov015Info38 *d) {
    BOOL r = TRUE;
    self->info = d;
    self->ship = a;
    self->fish = b;
    self->cam = c;
    switch (self->step) {
    case 0: {
        u8 *m;
        a->unk_d3c = 1;
        a->unk_d4c = b->pos;
        m = (u8 *)Heap_Alloc(0x2c);
        if (m != NULL) m = (u8 *)Ov015FishState2c_Ctor((Ov015FishState2c *)m);
        Ov015Fish_SetNextState(b, (s32)m, 2);
        b->minX = -0x32000;
        b->maxX = 0x32000;
        b->maxZ = 0x32000 - 0x69000;
        b->minZ = 0x32000 - 0xdc000;
        data_ov015_0221332c.unk_00 = func_ov015_02209fb8(b->pos.z);
        self->step = 1;
    }
    case 1: {
        BOOL busy;
        if (self->unk_0c > 0x78000) {
            busy = FALSE;
        } else {
            if (self->unk_0c == 0x28000) {
                FLD(s32, func_02066df0(), 0xd4) = 1;
            }
            func_ov015_02207c30(a);
            busy = TRUE;
            func_ov015_021fd00c(c, busy, (const Ov015Vec *)&b->pos);
            self->unk_0c += 0x1000;
        }
        if (!busy) {
            Ov015Vec v = a->unk_d08;
            self->fx = Effect3D_Create(data_ov015_022128c1, data_ov015_022128d5, 0, &v);
            self->fx->unk_d4 = 3;
            self->fx->unk_50 = -0x32000;
            VCALL(self->fx)->v14(0x333, 0x333, 0x333);
            self->fx->loopCount = -1;
            self->unk_0c = 0;
            self->step = 2;
        }
        break;
    }
    case 2:
        if (!func_ov015_022003ec(self)) self->step = 3;
        break;
    case 3:
        r = FALSE;
        break;
    }
    self->ship = NULL;
    self->fish = NULL;
    self->cam = NULL;
    FLD(s32, self, 0x30) = 0;
    return r;
}

}
