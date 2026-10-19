#include "ov013/ov013.h"

class Ov013Cls;
typedef void (Ov013Cls::*Ov013Pmf)();

struct Ov013Rot {
    u16 x;
    u16 y;
    u16 z;
};

struct Ov013RotC {
    u16 x;
    u16 y;
    u16 z;
    Ov013RotC() {
        x = 0;
        y = 0;
        z = 0;
    }
};

struct Ov013Offs5 {
    u16 v[5];
};

extern "C" {

extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd64;
extern Ov013Pmf data_ov013_0220bc48;
extern Ov013Pmf data_ov013_0220bc50;
extern Ov013Pmf data_ov013_0220bc58;
extern const u8 data_ov003_021f4340;
extern char data_ov013_0220ba6c[];
extern u8 data_ov013_0220b308[];
extern u8 data_ov013_0220b324[];
extern u8 data_ov013_0220b290[];
extern void func_ov000_02194758(void *self);
extern char data_ov013_0220ba73[];
extern const Ov013Pmf data_ov013_0220bc60;
extern Ov013Pmf data_ov013_0220bc68;
extern Ov013Pmf data_ov013_0220bc70;
extern void func_0203f324(Ov013Sub48 *p);
extern void func_ov003_021f0c60(Ov013Actor *self, s32 a);
extern Ov013Actor *func_ov000_0218d240(Ov013Actor *self);
extern void func_ov000_0218dbe0(Ov013Actor *self, s32 a);
extern void *func_ov000_0218fe1c(void *p);
extern void func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
extern void func_0203f364(Ov013Sub48 *p);
extern void func_ov003_021cf330(void *p, const char *name, u8 a);
extern void func_ov013_02205760(Ov013Actor *self);
extern void func_ov003_021da40c(void *p);
extern void func_ov000_0218d7e8(Ov013Actor *self, s32 a);
extern BOOL func_ov000_021950e8(Ov013Actor *self, Ov013Msg *msg);
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern u16 FX_Atan2(s32 y, s32 x);
extern u8 *func_020704b4(u16 kind);
extern void func_ov013_02205098(Ov013Actor *self);
extern void func_ov000_02195d88(Ov013Actor *self);
extern Ov013Actor *func_ov003_021da32c(u16 kind);
extern void func_ov000_02197dec(Ov013Actor *self, s32 a, s32 b);
extern void func_ov000_0218bed8(void *a, s32 b, void *c);
extern void func_ov000_0219763c(Ov013Actor *self);

static inline Ov013Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline u16 Ov013_FaceAngle(Ov013Actor *self, Ov013Actor *a) {
    if (a != NULL) {
        if (a != NULL && a != self) {
            return FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
        }
        return self->rot[1];
    }
    return self->unk_98 + 0x7fff;
}

void func_ov013_02205760(Ov013Actor *self) {
    Ov013Offs5 offs;
    u16 ang;
    u32 i;
    u16 lvl;
    if (self->unk_40->state != 0) {
        return;
    }
    offs = *(Ov013Offs5 *)(data_ov013_0220b290 + 0xe);
    ang = Ov013_FaceAngle(self, Ov013_FindActor(self->unk_90));
    lvl = FLD(u16, FLD(void *, self, 0x4c), 0x1c);
    for (i = 0; i < 5; i++) {
        Ov013Actor *c;
        Ov013Rot r = {0, 0, 0};
        r.y = ang + offs.v[i];
        c = func_ov003_021da32c(0x480a);
        if (c != NULL) {
            c->pos = self->pos;
            FLD(Ov013Rot, c, 0x7c) = r;
            c->unk_90 = self->unk_90;
            FLD(u16, FLD(void *, c, 0x4c), 0x1c) = lvl;
            FLD(void *, c, 0x60) = data_ov013_0220b324;
        }
    }
    func_ov000_02198360(self->unk_40, 0x15, 1);
}

void func_ov013_022058d4(Ov013Actor *self) {
    func_ov000_02197dec(self, 0xf, 0x63);
    func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
    self->v08();
}

void func_ov013_02205914(Ov013Actor *self) {
    self->unk_64 = 0x1000;
    func_ov000_0219763c(self);
}

extern void *data_02097e4c;
extern void func_ov003_021da108(Ov013Actor *self, s32 a, s32 b, s32 c, s32 d);
extern void func_02049f44(void *a, s32 b, Ov013Vec *c, s32 d);

static inline s32 Ov013_Clamp(s32 v, s32 lo, s32 hi) {
    if (v > hi) {
        return hi;
    }
    if (v < lo) {
        return lo;
    }
    return v;
}

static inline void Ov013_SetAlpha(Ov013Sub38 *m, s32 a) {
    FLD(u8, m, 0xbe) = Ov013_Clamp(a, 1, 31);
}

void func_ov013_02205928(Ov013Actor *self) {
    volatile Ov013Sub40 *s = self->unk_40;
    switch (s->state) {
    case 0:
        FLD(u16, self, 0xd0) = 0;
        if (s->timer >= 3) {
            s->timer = 0;
            self->unk_40->state = 1;
        } else {
            s->timer++;
            return;
        }
    case 1:
        Ov013_SetAlpha(self->unk_38, 31 - self->unk_40->timer);
        if (self->unk_40->timer % 10 == 0) {
            func_ov003_021da108(self, 0x2800, 0x38b, 0x1000, 0x1000);
            func_02049f44(data_02097e4c, 0x1a, &self->pos, 0);
        }
        if (self->unk_40->timer == 0) {
            u8 *g = (u8 *)data_ov000_021ccd54;
            FLD(Ov013Flags8, g, 0x190).b2 = 1;
            FLD(Ov013Flags8, g, 0x190).b3 = 1;
            FLD(Ov013Flags8, g, 0x190).b4 = 1;
            g[0x18d] = 20;
            g[0x18e] = 0xf;
            g[0x18f] = 0xf;
        }
        if (self->unk_40->timer < 30) {
            ((volatile Ov013Sub40 *)self->unk_40)->timer++;
        } else {
            self->unk_40->timer = 0;
            self->unk_40->state = 2;
        }
        break;
    case 2:
        self->unk_38->unk_c2_0 = 0;
        func_ov000_02197dec(self, 0xf, 0x63);
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->v08();
        break;
    }
}

}
