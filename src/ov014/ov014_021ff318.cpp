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

static inline void Ov014Spawn_Set(Ov014SpawnDesc *d, u16 k) {
    d->kind = k;
    d->flags = k & 0xf000;
}

extern "C" {

extern void *data_02097e4c;
extern BOOL func_ov003_021daa0c(void *p, u8 id);
extern void func_ov003_021da9ac(void *p, u8 id, void *obj);
extern void func_0204a028(void *a, s32 b, Ov014Vec *c, s32 d);
extern Ov014V *func_02065f88(s32 id, Ov014Vec *pos);
extern BOOL func_ov003_021d9edc(s32 id);
extern void func_ov014_021fe3ec(Ov014Actor *self);

void func_ov014_021ff318(Ov014Actor *self) {
    if (FLD(s16, self, 0xf0) != 1) {
        return;
    }
    switch (self->unk_40->state) {
    case 0: {
        Ov014V *e = func_02065f88(0x2bd, &self->pos);
        e->v24(0, 0, 0x7000);
        e->v0c(0x8000);
        e->v34(0x4000, 0, 0);
        func_ov003_021da9ac(FLD(void *, self, 0xfc), 0, e);
        self->unk_40->state++;
    }
    case 1: {
        u8 i;
        if (func_ov003_021daa0c(FLD(void *, self, 0xfc), 0)) {
            return;
        }
        for (i = 0; i < 2; i++) {
            Ov014V *e = func_02065f88(0x57e, &self->pos);
            e->v24(0, 0, 0x7000);
            e->v0c(0x3000);
            func_0204a028(data_02097e4c, 0x79, &self->pos, -5);
        }
        self->unk_40->state++;
        break;
    }
    case 2: {
        Ov014Sub40 *w = self->unk_40;
        w->timer++;
        if (w->timer < 10) {
            return;
        }
        self->unk_40->timer = 0;
        if (FLD(s16 *, self, 0x15c)[0] == 12 && !func_ov003_021d9edc(0x482b)) {
            self->unk_40->state = 10;
        } else {
            self->unk_40->state = 0x1e;
        }
        func_ov014_021fe3ec(self);
        break;
    }
    case 10: {
        Ov014Sub40 *w = self->unk_40;
        w->timer++;
        if (w->timer < FLD(u16 *, self, 0x15c)[1]) {
            return;
        }
        self->unk_40->timer = 0;
        self->unk_40->state = 1;
        break;
    }
    case 0x1e: {
        u16 lim = 0;
        Ov014Sub40 *w = self->unk_40;
        if (FLD(u16 *, self, 0x15c) != NULL) {
            lim = FLD(u16 *, self, 0x15c)[3];
        }
        w->timer++;
        if (w->timer < lim) {
            return;
        }
        if (FLD(u32, self, 0xf4) & 8) {
            FLD(u32, self, 0xf4) ^= 8;
        }
        FLD(u8, self, 0x138) ^= 0x80;
        self->unk_40->timer = 0;
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    }
}
extern void *data_ov000_021ccd68;
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
extern void func_020639d4(void *e, s32 a, s32 b);
extern Ov014Actor *func_ov000_0219bf90(void);
extern Ov014Actor *func_ov000_02192b24(Ov014SpawnDesc *desc);
extern void func_ov000_0219bebc(Ov014Actor *a, s32 b);

void func_ov014_021ff59c(Ov014Actor *self) {
    if (FLD(s16, self, 0xf0) != 1) {
        return;
    }
    switch (self->unk_40->state) {
    case 0: {
        Ov014V *e;
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x482b, 0x15);
        e = func_02065f88(0x2bd, &self->pos);
        e->v24(0, 0, 0x7000);
        e->v0c(0x8000);
        e->v34(0x4000, 0, 0);
        func_020639d4(e, 0x44, 0);
        func_ov003_021da9ac(FLD(void *, self, 0xfc), 0, e);
        FLD(u8, self, 0xf9) = 0;
        self->unk_40->state++;
        break;
    }
    case 1: {
        u8 i;
        if (!func_ov003_021daa0c(FLD(void *, self, 0xfc), 0)) {
            for (i = 0; i < 2; i++) {
                Ov014V *e = func_02065f88(0x57e, &self->pos);
                e->v24(0, 0, 0x7000);
                e->v0c(0x3000);
                func_ov003_021da9ac(FLD(void *, self, 0xfc), 1, e);
            }
            if (FLD(u8, self, 0xf9) == 1) {
                Ov014SpawnDesc desc;
                Ov014Actor *o;
                Ov014Spawn_Init(&desc, 0xffff);
                Ov014Spawn_Set(&desc, 0x482c);
                o = func_ov000_02192b24(&desc);
                if (o != NULL) {
                    o->pos.x = 0;
                    o->pos.y = 0x4719a;
                    o->pos.z = 0xf000;
                    o->unk_90 = self->unk_90;
                    o->v04();
                    FLD(Ov014Flags8, o, 0x16).b0 = 1;
                    func_ov000_0219bebc(o, FLD(s16, self, 0x13a));
                    if (FLD(u8 *, o, 0x4c) != NULL) {
                        FLD(u16, FLD(u8 *, o, 0x4c), 0x1c) = self->id;
                    }
                }
            }
            if (FLD(u8, self, 0xf9) >= 2) {
                self->unk_40->state = 0x1e;
            } else {
                self->unk_40->state++;
            }
        } else {
            Ov014Actor *pl = func_ov000_0219bf90();
            if (pl != NULL) {
                FLD(s32, pl, 0xb90) = self->pos.x;
                FLD(s32, pl, 0xb94) = self->pos.y;
                FLD(s32, pl, 0xb98) = self->pos.z;
                FLD(s32, pl, 0xb9c) = 0x400;
            }
        }
        break;
    }
    case 2:
        if (!func_ov003_021daa0c(FLD(void *, self, 0xfc), 1)) {
            FLD(u8, self, 0xf9)++;
            self->unk_40->state = 1;
        }
        break;
    case 0x1e:
        if (!func_ov003_021d9edc(0x482c)) {
            if (FLD(u32, self, 0xf4) & 0x10) {
                FLD(u32, self, 0xf4) ^= 0x10;
            }
            FLD(u32, self, 0xf4) |= 1;
            self->unk_40->timer = 0;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

}
