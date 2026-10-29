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

struct Ov014V12 { s32 a[3]; };
extern const Ov014Vec data_ov014_02216818[];
extern void *func_ov003_021ceff4(void *p);
extern u16 func_ov003_021d9edc(s32 a);
extern void func_ov003_021d87d0(void *p, s32 a);
extern void func_ov003_021d85c8(void *p, s32 a, s32 b, s32 c, s32 d);
extern Ov014Actor *func_ov000_02192b24(Ov014SpawnDesc *desc);

static inline u8 *Ov014_AnimCur(u8 *t) {
    return FLD(u8 *, t, 0xc) + FLD(u16, t, 8) * 8;
}

void func_ov014_021fe210(Ov014Actor *self) {
    u8 m = FLD(u8, self, 0x138);
    if (m == 0) {
        u8 *t = FLD(u8 *, self, 0x14c);
        FLD(u8 *, self, 0x13c) = FLD(u8 *, t, 0xc) + FLD(u16, t, 8) * 8;
        func_ov003_021ceff4((u8 *)self + 0x140);
        switch (*FLD(s16 *, self, 0x13c)) {
        case 0:
        case 1:
        case 2:
            FLD(s32, self, 0xf4) |= 4;
            self->unk_40->flags |= 0x8000;
            break;
        case 3:
        case 4:
            FLD(s32, self, 0xf4) |= 0x200000;
            FLD(s32, self, 0xf4) |= 4;
            self->unk_40->flags |= 0x8000;
            break;
        case 5:
            FLD(s32, self, 0xf4) |= 0x10;
            self->unk_40->flags |= 0x20000;
            break;
        }
    } else {
        s32 pct = (u16)(self->unk_50[0] * 100 / self->unk_50[1]);
        if (pct >= 30) {
            if (!(m & 0x80)) {
                if (!func_ov003_021d9edc(0x482b)) {
                    FLD(u8, self, 0x138) |= 0x80;
                } else if (self->unk_30 & 0x40) {
                    if (FLD(u8, self, 0xf8) == 10) {
                        FLD(u8, self, 0x138) |= 0x80;
                    }
                    FLD(u8, self, 0xf8) = 0xff;
                }
            }
            if (FLD(u8, self, 0x138) & 0x80) {
                u8 *t;
                func_ov003_021ceff4((u8 *)self + 0x160);
                t = FLD(u8 *, self, 0x16c);
                FLD(u8 *, self, 0x15c) = Ov014_AnimCur(t);
                switch (*(s16 *)FLD(u8 *, self, 0x15c)) {
                case 10:
                    FLD(u8, self, 0x138) ^= 0x80;
                    break;
                case 11:
                case 12:
                    FLD(s32, self, 0xf4) |= 8;
                    self->unk_40->flags |= 0x10000;
                    break;
                }
            }
        }
    }
    if ((self->unk_30 & 0x200) && self->unk_50[0] != 0) {
        func_ov003_021d87d0((u8 *)self + 0x100, 0);
        func_ov003_021d85c8((u8 *)self + 0x100, 0x1e, 0, 0, 0);
    }
}
void func_ov014_021fe3ec(Ov014Actor *self) {
    Ov014SpawnDesc desc;
    Ov014Actor *o;
    Ov014Spawn_Init(&desc, 0xffff);
    Ov014Spawn_Set(&desc, 0x482b);
    o = func_ov000_02192b24(&desc);
    if (o == NULL) {
        return;
    }
    {
        const Ov014Vec *p = &data_ov014_02216818[FLD(u8, self, 0x139)];
        o->pos.x = p->x;
        o->pos.y = p->y;
        o->pos.z = p->z;
    }
    if (++FLD(u8, self, 0x139) >= 7) {
        FLD(u8, self, 0x139) = 0;
    }
    o->v04();
    FLD(Ov014Flags8, o, 0x16).b0 = 1;
    o->unk_90 = self->unk_90;
    if (FLD(u8 *, o, 0x4c) != NULL) {
        FLD(u16, FLD(u8 *, o, 0x4c), 0x1c) = self->id;
    }
}

extern void *data_02097e4c;
extern u8 data_ov014_02216564[];
extern const Ov014Vec data_ov014_02216600;
extern Ov014Actor *func_02065f88(s32 id, Ov014Vec *pos);
extern void *func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern void *func_0204a028(void *a, s32 b, Ov014Vec *c, s32 d);
extern void VEC_Add(const Ov014Vec *a, const Ov014Vec *b, Ov014Vec *out);
extern void func_ov000_0219bd20(s32 a, u16 b, s32 c, s32 d, s32 e, void *f);
extern void func_ov000_02191708(void *a);
void func_020627a0(u16 a, u16 b);
void func_020627dc(s32 a);

void func_ov014_021fe4d8(Ov014Actor *self) {
    Ov014Vec v1;
    Ov014Vec v2;
    u8 b;
    if (FLD(s16, self, 0xf0) != 0) {
        return;
    }
    switch (self->unk_40->state) {
    case 0:
        b = 1;
        func_ov000_0219bd20(0x5c19, self->kind, 6, 1, 1, &b);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 1: {
        Ov014Actor *e;
        if (FLD(u8, self, 0xf8) != 1) {
            break;
        }
        FLD(u8, self, 0xf8) = 0;
        e = func_02065f88(0x68, &self->pos);
        e->v0c(0x4000);
        e->v34(0xbfff, self->rot[1], 0);
        e->v28(data_ov014_02216564);
        func_ov000_02191708(self->unk_38);
        func_ov000_021915a0(self->unk_38);
        *(Ov014V12 *)&v1 = *(const Ov014V12 *)&data_ov014_02216600;
        VEC_Add(&v1, &self->pos, &v1);
        func_02049f44(data_02097e4c, 0x5b, &v1, 0);
        self->unk_40->state++;
        break;
    }
    case 2:
        self->unk_40->timer++;
        if (self->unk_40->timer == 0x78) {
            b = 2;
            func_ov000_0219bd20(0x5c19, self->kind, 6, 1, 1, &b);
        } else if (self->unk_40->timer == 0xdc) {
            FLD(u32, self, 0xf4) ^= 0x40;
            self->unk_93_4 = 1;
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            FLD(u8, data_ov000_021ccd54, 0xac) = 1;
        }
        if (Ov014_GameIdle()) {
            self->unk_40->timer = 0;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        if (self->unk_40->timer % 0x44 == 0) {
            *(Ov014V12 *)&v2 = *(const Ov014V12 *)&data_ov014_02216600;
            VEC_Add(&v2, &self->pos, &v2);
            func_0204a028(data_02097e4c, 0x39, &v2, -5);
        }
        break;
    }
}

extern void *data_0214a420;
extern void *data_ov014_02216500[];
extern const u8 data_ov014_022173c8[];
extern Ov014V *func_020657b0(void *a, void *b);
extern BOOL func_ov003_021daa0c(void *p, u8 id);
extern void *func_ov003_021daa3c(void *p, u8 id);
extern void func_ov003_021da9ac(void *p, u8 id, void *obj);
extern void func_02049de8(void *a, s32 b);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov003_021d87d0(void *p, s32 a);

void func_ov014_021fe7a4(Ov014Actor *self) {
    Ov014Vec v;
    Ov014Actor *e;
    Ov014Sub40 *w;
    if (FLD(s16, self, 0xf0) == 1) {
        *(Ov014V12 *)&v = *(const Ov014V12 *)&data_ov014_02216600;
        VEC_Add(&v, &self->pos, &v);
        w = self->unk_40;
        switch (w->state) {
        case 0:
            func_ov000_02190cb0(self->unk_38, data_ov014_02216500[3], 0x400, 0);
            func_ov000_021915a0(self->unk_38);
            FLD(s32, self, 0x9c) = 0;
            FLD(s32, self, 0xa0) = 0;
            FLD(s32, self, 0xa4) = 0;
            FLD(s32, self, 0xa8) = 0;
            FLD(u8, self, 0xf9) = 0;
            self->unk_40->state++;
            break;
        case 1:
            w->timer++;
            if (w->timer >= 0x32 || FLD(u8, self, 0xf9) != 0) {
                e = func_02065f88(0x68, &self->pos);
                e->v0c(0x4000);
                e->v24(0, -0x2000, 0);
                func_02049f44(data_02097e4c, 0x44, &v, 0);
                func_02049f44(data_02097e4c, 0x27, &v, 0);
                func_ov003_021da9ac(FLD(void *, self, 0xfc), 0xff, e);
                FLD(u8, self, 0xf9)++;
                self->unk_40->timer = 0;
                self->unk_40->state++;
            }
            break;
        case 2: {
            BOOL r = func_ov003_021daa0c(FLD(void *, self, 0xfc), 0xff);
            if (FLD(u8, self, 0xf9) >= 3) {
                if (!r) {
                    func_ov000_02190cb0(self->unk_38, data_ov014_02216500[2], 0x400, 0);
                    func_02049f44(data_02097e4c, 0x39, &v, 0);
                    self->unk_40->state++;
                }
            } else if (!r) {
                func_ov000_0218996c(5, 0x14);
                self->unk_40->state = 1;
            }
            break;
        }
        case 3:
            if (func_ov000_02191120(self->unk_38)) {
                func_ov003_021d87d0((u8 *)self + 0x100, 1);
                func_ov000_0218996c(10, 0x28);
                e = func_02065f88(0x69, &self->pos);
                func_02049f44(data_02097e4c, 0x5c, &v, 0);
                func_02049f44(data_02097e4c, 0x1a, &v, 0);
                func_ov003_021da9ac(FLD(void *, self, 0xfc), 0xff, e);
                func_ov000_02190cb0(self->unk_38, data_ov014_022173c8, 0x89, 0);
                func_ov000_021915a0(self->unk_38);
                self->unk_40->state = 0x1e;
            }
            break;
        case 0x1e:
            w->timer++;
            if (w->timer >= 0x32) {
                func_02049de8(data_02097e4c, 0x38);
                func_020627a0(self->kind, self->id);
                func_020627dc(4);
                FLD(u8, data_ov000_021ccd54, 0xac) = 1;
                self->unk_40->timer = 0;
                self->unk_40->state++;
            }
            break;
        }
        {
            Ov014V *o = func_020657b0(data_0214a420, func_ov003_021daa3c(FLD(void *, self, 0xfc), 0xff));
            if (o != NULL) {
                o->v0c(FLD(s32, o, 0x40) + 0x59a);
            }
        }
    }
    func_ov003_021dacfc(FLD(void *, self, 0xfc));
}

}
