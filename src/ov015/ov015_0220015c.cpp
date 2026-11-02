#include "ov015/ov015.h"

extern "C" {

s32 func_02065748(void *a, void *b);
s32 func_ov015_02209fb8(s32 x);
u8 *func_02066774(void *a, void *b, int c, void *d);
void *Ov015FishState2c_Ctor(Ov015FishState2c *self);
extern char data_ov015_022128c1[];
extern char data_ov015_022128d5[];
u8 *func_02066df0(void);
void func_ov015_02207c30(Ov015Ship *p);
BOOL func_ov015_022003ec(Ov015Obj34 *self);
void func_ov015_02209b80(Ov015Fish *self, s32 a, s32 b);
void func_ov015_021fd00c(Ov015CamPair *self, s32 mode, const Ov015VecC *v);

void func_ov015_0220015c(Ov015Obj34 *self) {
    self->unk_04 = NULL;
    self->unk_08 = 0;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
    self->unk_20 = 0;
    self->unk_24 = 0;
    self->unk_28 = 0;
    self->unk_2c = 0;
    self->unk_30 = 0;
}

void func_ov015_02200194(Ov015Obj34 *self) {
    void *saved;
    if (func_02065748(data_0214a420, self->unk_04) == 0) {
        return;
    }
    HEAP_PUSH(saved);
    DELETE_V(self->unk_04);
    HEAP_POP(saved);
}

BOOL func_ov015_02200204(Ov015Obj34 *self, Ov015Ship *a, Ov015Fish *b, Ov015CamPair *c, Ov015Info38 *d) {
    BOOL r = TRUE;
    self->unk_30 = d;
    self->unk_24 = a;
    self->unk_28 = b;
    self->unk_2c = c;
    switch (self->unk_08) {
    case 0: {
        u8 *m;
        a->unk_d3c = 1;
        a->unk_d4c = b->unk_40;
        m = (u8 *)Heap_Alloc(0x2c);
        if (m != NULL) m = (u8 *)Ov015FishState2c_Ctor((Ov015FishState2c *)m);
        func_ov015_02209b80(b, (s32)m, 2);
        b->unk_ac = -0x32000;
        b->unk_b0 = 0x32000;
        b->unk_b4 = 0x32000 - 0x69000;
        b->unk_b8 = 0x32000 - 0xdc000;
        data_ov015_0221332c.unk_00 = func_ov015_02209fb8(b->unk_40.z);
        self->unk_08 = 1;
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
            func_ov015_021fd00c(c, busy, (const Ov015VecC *)&b->unk_40);
            self->unk_0c += 0x1000;
        }
        if (!busy) {
            Ov015Vec v = a->unk_d08;
            self->unk_04 = func_02066774(data_ov015_022128c1, data_ov015_022128d5, 0, &v);
            FLD(s32, self->unk_04, 0xd4) = 3;
            FLD(s32, self->unk_04, 0x50) = -0x32000;
            VCALL(self->unk_04)->v14(0x333, 0x333, 0x333);
            FLD(s32, self->unk_04, 0xc8) = -1;
            self->unk_0c = 0;
            self->unk_08 = 2;
        }
        break;
    }
    case 2:
        if (!func_ov015_022003ec(self)) self->unk_08 = 3;
        break;
    case 3:
        r = FALSE;
        break;
    }
    self->unk_24 = NULL;
    self->unk_28 = NULL;
    self->unk_2c = NULL;
    FLD(s32, self, 0x30) = 0;
    return r;
}

}
