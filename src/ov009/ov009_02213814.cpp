#include "ov009/ov009.h"

extern "C" {

static inline s32 Ov009_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline s32 Ov009_DistXZ(const Ov009Vec *a, const Ov009Vec *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov009_Sqrt64(sq);
}

extern Ov009Actor *func_ov000_0219bf90(void);

void func_ov009_02213814(Ov009Actor *self) {
    u8 k;
    Ov009Actor *t;
    Ov009Vec v;
    s32 dist;
    if (!Ov009_GameIdle()) {
        return;
    }
    k = self->unk_40->unk_13;
    t = func_ov000_0219bf90();
    if (t == NULL) {
        return;
    }
    v = t->pos;
    dist = Ov009_DistXZ(&self->pos, &v);
    if (dist > 0x6000) {
        self->unk_b8 = v;
        self->unk_40->flags |= 4;
    }
    if (k == 1 || k == 2) {
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        self->unk_93_4 = 1;
        if (self->unk_b6 != 0) {
            return;
        }
        if (dist >= 0x7000) {
            func_ov000_02198360(self->unk_40, 0x10, 0);
        } else if (func_02040498(6) != 0) {
            func_ov000_02198360(self->unk_40, 0xf, 0);
        } else {
            func_ov000_02198360(self->unk_40, 0x10, 0);
        }
        self->unk_b6 = func_02040498(0x14) + 0x64;
    }
}

extern void *data_ov000_021ccd68;
extern u8 data_ov009_022179ba[];
extern u8 data_ov009_022179df[];
extern u8 data_ov009_022179e5[];
extern u8 data_ov009_022179eb[];
extern u8 data_ov009_022179b4[];
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 a);
extern BOOL func_ov000_02191120(void *m);
extern s32 FX_Div(s32 a, s32 b);
static inline Ov009Actor *Ov009_FindActor4(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov009_022139a4(Ov009Actor *self) {
    Ov009Actor *t = Ov009_FindActor4(self->unk_90);
    Ov009Sub40 *st;
    if (t == NULL) {
        return;
    }
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_022179ba, 0x2ab, 0);
        self->unk_40->state = 10;
        self->unk_40->timer = 0x78;
        break;
    case 10: {
        s32 d;
        s32 max;
        func_ov000_0218d988(self, t, self->unk_b0->unk_02);
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov009_022179df, 0x1000, 0);
        FLD(Ov009Vec, self, 0xf0).x = t->pos.x;
        FLD(Ov009Vec, self, 0xf0).y = t->pos.y;
        FLD(Ov009Vec, self, 0xf0).z = t->pos.z;
        self->unk_98 = self->rot[1];
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        d = FX_Div(Ov009_DistXZ(&self->pos, &FLD(Ov009Vec, self, 0xf0)), 0x18000);
        max = 0x452;
        if (self->unk_1a == 0) {
            max += 0x148;
        }
        if (d > max) {
            d = max;
        }
        if (d < 0xcd) {
            d = 0xcd;
        }
        self->unk_9c = d;
        self->unk_a0 = 0x266;
        self->unk_a8 = 0x52;
        self->unk_40->state = 0x14;
        self->unk_40->timer = 0;
        break;
    }
    case 0x14:
        if ((self->unk_48->unk_50 & 0x20000000) && self->unk_a0 < 0) {
            self->unk_9c = 0;
        }
        func_ov000_0218dbe0(self, 0);
        if (self->unk_48 != NULL) {
            func_ov000_021987b8(self->unk_48, 1, 0, 0);
        }
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov009_022179e5, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        if (self->unk_1a == 0) {
            self->unk_40->timer = func_02040498(0xf) + 300;
        } else {
            self->unk_40->timer = func_02040498(0xf) + 200;
        }
        self->unk_40->state = 0x1e;
        break;
    case 0x1e:
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            func_ov000_02190cb0(self->unk_38, data_ov009_022179eb, 0x1000, 0);
            self->unk_40->state = 0x1f;
            self->unk_40->timer = 0;
        }
        self->unk_94_1 = 0;
        break;
    case 0x1f:
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov009_022179b4, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state = 0x20;
        self->unk_40->timer = func_02040498(10) + 0x32;
        break;
    case 0x20:
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

}
