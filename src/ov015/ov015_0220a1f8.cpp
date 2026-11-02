#include "ov015/ov015.h"

extern "C" {

s32 Interp_SinLerp(s32 t, s32 a, s32 b);
void func_ov015_0220afcc(Ov015FishState2c *self);
void func_ov015_0220b1b8(Ov015FishState2c *self);
void func_ov015_0220ac40(Ov015FishState2c *self, Ov015Fish *p);
void func_ov015_0220ad68(Ov015FishState2c *self, Ov015Fish *p);
BOOL func_ov015_0220ae90(Ov015FishState2c *self);
s32 Rand_UpTo(s32 max);
extern u8 data_ov015_02212f20[];
extern u8 data_ov015_02212f04[];

static inline s32 Ov015_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline Ov015V *Ov015_NewTask18(void) {
    Ov015FishState18 *t = (Ov015FishState18 *)Heap_Alloc(0x18);
    if (t != NULL) {
        SET_VT(t, data_ov015_02212f20);
        t->fish = 0;
        t->step = 0;
        t->timer = 0;
        t->duration = 0;
        t->fxKey = 0;
    }
    return (Ov015V *)t;
}

static inline Ov015V *Ov015_NewTask1c(void) {
    Ov015FishState1c *t = (Ov015FishState1c *)Heap_Alloc(0x1c);
    if (t != NULL) {
        SET_VT(t, data_ov015_02212f04);
        t->step = 0;
        t->timer = 0;
        t->unk_0c = 0;
        t->unk_10 = 0;
        t->fish = 0;
    }
    return (Ov015V *)t;
}

static inline void Ov015_Sounds(void) {
    func_02049a48(data_02097e4c, 0x55, -1, -1, -1);
    func_02049a48(data_02097e4c, 0x3e, -1, -1, -1);
}

static inline s32 Ov015_Speed(Ov015FishState2c *self) {
    s32 b = Ov015_FxMul64((self->fish)->info.unk_0a << 4, 0x19a) + 0x800;
    return Interp_SinLerp(FX_Mul(self->unk_18, self->unk_18), b / 5, b);
}

static inline s32 Ov015_Wait(Ov015FishState2c *self) {
    s32 c = (self->fish)->info.unk_0a << 4;
    BOOL in;
    s32 b;
    s32 n;
    BOOL inX;
    BOOL inZ;
    Ov015Fish *q;
    s32 a;
    a = 0xf0000 - Ov015_FxMul64(c, 0xf000);
    if (a < 0xb4000) {
        a = 0xb4000;
    }
    b = 0x78000 - Ov015_FxMul64(c, 0x1e000);
    if (b < 0) {
        b = 0;
    }
    n = (s16)((b + Rand_UpTo(a - b)) >> 12);
    q = self->fish;
    in = FALSE;
    inZ = FALSE;
    inX = FALSE;
    if (q->pos.x >= q->minX && q->pos.x <= q->maxX) {
        inX = TRUE;
    }
    if (inX && q->pos.z <= q->maxZ) {
        inZ = TRUE;
    }
    if (inZ && q->pos.z >= q->minZ) {
        in = TRUE;
    }
    if (!in && n > 200) {
        n = 200;
    }
    return n;
}

BOOL Ov015FishState2c_Update(Ov015FishState2c *self, Ov015Fish *p) {
    Ov015Stat *g = &data_ov015_0221332c;
    self->fish = p;
    self->unk_14 = FALSE;
    if (g->unk_28 != 3) {
        self->unk_14 |= g->unk_14 == 3 && p->unk_bc == 2;
        self->unk_14 |= g->unk_14 == 2 && (self->fish)->unk_bc == 3;
        if (self->unk_14) {
            self->unk_16--;
            if (self->unk_16 <= 0) {
                self->unk_16 = 0;
            }
        } else {
            self->unk_16 = 0x5a;
        }
        self->unk_18 = FX_Div(self->unk_16 << 12, 0x5a000);
    }
    if (func_ov015_0220ae90(self)) {
        p->nextState = Ov015_NewTask18();
        p->nextStateId = 3;
        return TRUE;
    }
    if (g->unk_00 < 0xfa000) {
        p->minX = -0x21555;
        p->maxX = 0x21555;
    } else {
        p->minX = -0x32000;
        p->maxX = 0x32000;
    }
    switch (self->step) {
    case 0:
        if (self->unk_06 <= 0) {
            self->step = Rand_UpTo(1) != 0 ? 5 : 6;
            self->unk_06 = 0x1e;
        }
        break;
    case 1: {
        Ov015VecC pos(*(Ov015VecC *)&p->pos);
        Ov015VecC dir(*(Ov015VecC *)&p->dir);
        s32 d = Ov015_Speed(self);
        p->pos.x = pos.x - d;
        p->unk_a8 = d;
        p->pos.y = pos.y;
        p->pos.z = pos.z;
        dir.x -= d;
        VEC_Normalize((VecFx32 *)&dir, (VecFx32 *)(&p->dir));
        func_ov015_0220afcc(self);
        func_ov015_0220b1b8(self);
        if (self->unk_06 <= 0 || p->pos.x < p->minX) {
            p->unk_bc = 3;
            self->step = 4;
            self->unk_06 = 0x14;
            Ov015_Sounds();
        }
        break;
    }
    case 2: {
        Ov015VecC pos(*(Ov015VecC *)&p->pos);
        Ov015VecC dir(*(Ov015VecC *)&p->dir);
        s32 d = Ov015_Speed(self);
        p->pos.x = pos.x + d;
        p->unk_a8 = d;
        p->pos.y = pos.y;
        p->pos.z = pos.z;
        dir.x += d;
        VEC_Normalize((VecFx32 *)&dir, (VecFx32 *)(&p->dir));
        func_ov015_0220afcc(self);
        func_ov015_0220b1b8(self);
        if (self->unk_06 <= 0 || p->pos.x > p->maxX) {
            p->unk_bc = 2;
            self->step = 3;
            self->unk_06 = 0x14;
            Ov015_Sounds();
        }
        break;
    }
    case 3:
        func_ov015_0220ac40(self, p);
        if (self->unk_06 <= 0) {
            p->unk_bc = 3;
            self->step = 5;
            self->unk_06 = 0x1e;
        }
        break;
    case 4:
        func_ov015_0220ad68(self, p);
        if (self->unk_06 <= 0) {
            p->unk_bc = 2;
            self->step = 6;
            self->unk_06 = 0x1e;
        }
        break;
    case 5: {
        Ov015VecC pos(*(Ov015VecC *)&p->pos);
        Ov015VecC dir(*(Ov015VecC *)&p->dir);
        s32 t = FX_Div((0x1e - self->unk_06) << 12, 0x1e000);
        s32 d = FX_Mul(Ov015_Speed(self), t);
        BOOL spawn;
        p->pos.x = pos.x - d;
        p->pos.y = pos.y;
        p->pos.z = pos.z;
        p->unk_a8 = d;
        dir.z = FX_Mul(dir.z, 0xfae);
        dir.x -= 0x29;
        VEC_Normalize((VecFx32 *)&dir, (VecFx32 *)(&p->dir));
        func_ov015_0220afcc(self);
        func_ov015_0220b1b8(self);
        if (self->unk_06 > 0) {
            break;
        }
        p->unk_bc = 3;
        spawn = FALSE;
        if (self->unk_08 != 0) {
            self->unk_08--;
            if (self->unk_08 <= 0) {
                self->unk_08 = 0;
            }
        } else {
            Ov015Fish *q = self->fish;
            if (q->info.unk_18 != 0 && Rand_UpTo(0x1000) < q->info.unk_18 << 4) {
                spawn = TRUE;
            }
        }
        if (spawn) {
            p->nextState = Ov015_NewTask1c();
            p->nextStateId = 4;
        }
        self->step = 1;
        self->unk_06 = Ov015_Wait(self);
        break;
    }
    case 6: {
        Ov015VecC pos(*(Ov015VecC *)&p->pos);
        Ov015VecC dir(*(Ov015VecC *)&p->dir);
        s32 t = FX_Div((0x1e - self->unk_06) << 12, 0x1e000);
        s32 d = FX_Mul(Ov015_Speed(self), t);
        BOOL spawn;
        p->pos.x = pos.x + d;
        p->pos.y = pos.y;
        p->pos.z = pos.z;
        p->unk_a8 = d;
        dir.z = FX_Mul(dir.z, 0xfae);
        dir.x += 0x29;
        VEC_Normalize((VecFx32 *)&dir, (VecFx32 *)(&p->dir));
        func_ov015_0220afcc(self);
        func_ov015_0220b1b8(self);
        if (self->unk_06 > 0) {
            break;
        }
        p->unk_bc = 2;
        spawn = FALSE;
        if (self->unk_08 != 0) {
            self->unk_08--;
            if (self->unk_08 <= 0) {
                self->unk_08 = 0;
            }
        } else {
            Ov015Fish *q = self->fish;
            if (q->info.unk_18 != 0 && Rand_UpTo(0x1000) < q->info.unk_18 << 4) {
                spawn = TRUE;
            }
        }
        if (spawn) {
            p->nextState = Ov015_NewTask1c();
            p->nextStateId = 4;
        }
        self->step = 2;
        self->unk_06 = Ov015_Wait(self);
        break;
    }
    }
    self->unk_06--;
    if (self->unk_06 <= 0) {
        self->unk_06 = 0;
    }
    return TRUE;
}

}
