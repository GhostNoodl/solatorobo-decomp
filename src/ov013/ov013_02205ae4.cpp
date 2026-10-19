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

extern void func_ov003_021da108(Ov013Actor *self, s32 a, s32 b, s32 c, s32 d);
extern void func_02049f44(void *a, s32 b, Ov013Vec *c, s32 d);
extern void *data_02097e4c;
extern void *data_ov013_0220ba88[];
extern const u8 data_ov013_0220b2cc[];
extern void func_ov003_021d9980(void *out, u16 rot, const void *v);
extern void func_ov003_021cf2bc(void *p);
extern void func_ov003_021cf2d8(void *p);
extern void func_ov003_021cf33c(void *p, void *q);
extern void func_ov000_02194074(void *self);
extern BOOL func_ov000_02194c08(void *self);

void *func_ov013_02205ae4(Ov013Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov013_0220ba88;
    func_ov003_021cf2bc((u8 *)self + 0xe0);
    FLD(Ov013Flags8, self, 0xce).b0 = 0;
    FLD(Ov013Flags8, self, 0xce).b1 = 0;
    FLD(u16, self, 0xd0) = 0;
    FLD(u16, self, 0xd2) = 0;
    FLD(Ov013Vec, self, 0xd4) = *(Ov013Vec *)((u8 *)data_ov013_0220b290 + 0x30);
    return self;
}

void *func_ov013_02205b4c(Ov013Actor *self) {
    FLD(void *, self, 0) = data_ov013_0220ba88;
    ((Ov013V *)((u8 *)self + 0xe0))->v08();
    func_ov003_021cf2d8((u8 *)self + 0xe0);
    func_ov000_0219429c(self);
    return self;
}

void *func_ov013_02205b88(Ov013Actor *self) {
    FLD(void *, self, 0) = data_ov013_0220ba88;
    ((Ov013V *)((u8 *)self + 0xe0))->v08();
    func_ov003_021cf2d8((u8 *)self + 0xe0);
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

BOOL func_ov013_02205bcc(Ov013Actor *self) {
    func_ov003_021cf33c((u8 *)self + 0xe0, self->unk_40);
    return func_ov000_02194c08(self);
}

void func_ov013_02205bec(Ov013Actor *self, const Ov013Vec *v, u16 id, u16 plid, u16 r, u16 rot) {
    FLD(Ov013Flags8, self, 0xce).b0 = 0;
    FLD(Ov013Flags8, self, 0xce).b1 = 0;
    self->pos = *v;
    FLD(u16, FLD(void *, self, 0x4c), 0x1c) = id;
    self->unk_90 = plid;
    self->unk_98 = r;
    self->rot[1] = rot;
    func_ov003_021d9980((u8 *)self + 0xd4, self->unk_98, data_ov013_0220b2cc);
    FLD(u16, self, 0xd2) = 0x280;
    func_ov000_02198360(self->unk_40, 0xe, 0);
}

}
