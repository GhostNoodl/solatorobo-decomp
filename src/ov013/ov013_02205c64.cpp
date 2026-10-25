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

u32 func_ov013_02205c64(Ov013Actor *self) {
    return FLD(Ov013Flags8, self, 0xce).b0;
}

struct Ov013Mtx33 {
    s32 m[3][3];
};

static inline void VEC_Subtract(const Ov013Vec *a, const Ov013Vec *b, Ov013Vec *o) {
    o->x = a->x - b->x;
    o->y = a->y - b->y;
    o->z = a->z - b->z;
}

extern void VEC_Normalize(const Ov013Vec *a, Ov013Vec *b);
extern void MTX_RotAxis33(Ov013Mtx33 *m, const Ov013Vec *v, s32 s, s32 c);
extern void MTX_MultVec33(const Ov013Vec *v, const Ov013Mtx33 *m, Ov013Vec *o);

static inline s32 Ov013_Dot(const Ov013Vec *a, const Ov013Vec *b) {
    return (s32)(((s64)a->x * b->x + (s64)a->y * b->y + (s64)a->z * b->z + 0x800) >> 12);
}

static inline s32 Ov013_Dot2(const Ov013Vec *a, const Ov013Vec *b) {
    s64 ax = a->x;
    s64 ay = a->y;
    s64 az = a->z;
    s64 bx = b->x;
    s64 by = b->y;
    s64 bz = b->z;
    return (s32)((az * bz + (ax * bx + ay * by) + 0x800) >> 12);
}

static inline void Ov013_Cross(const Ov013Vec *a, const Ov013Vec *b, Ov013Vec *o) {
    s32 x = (s32)(((s64)a->y * b->z - (s64)a->z * b->y + 0x800) >> 12);
    s32 y = (s32)(((s64)a->z * b->x - (s64)a->x * b->z + 0x800) >> 12);
    s32 z = (s32)(((s64)a->x * b->y - (s64)a->y * b->x + 0x800) >> 12);
    o->x = x;
    o->y = y;
    o->z = z;
}

void func_ov013_02205c74(Ov013Vec *out, const Ov013Vec *a, const Ov013Vec *b, const Ov013Vec *v, u16 ang) {
    Ov013Vec d;
    Ov013Vec axis;
    Ov013Mtx33 m1;
    Ov013Mtx33 m2;
    Ov013Vec r1;
    Ov013Vec r2;
    Ov013Vec res;
    VEC_Subtract(a, b, &d);
    VEC_Normalize(&d, &d);
    Ov013_Cross(v, &d, &axis);
    MTX_RotAxis33(&m1, &axis, FX_SinCosTable_[(ang >> 4) * 2], FX_SinCosTable_[(ang >> 4) * 2 + 1]);
    MTX_RotAxis33(&m2, &axis, FX_SinCosTable_[((u16)(0xffff - ang) >> 4) * 2], FX_SinCosTable_[((u16)(0xffff - ang) >> 4) * 2 + 1]);
    MTX_MultVec33(v, &m1, &r1);
    MTX_MultVec33(v, &m2, &r2);
    bool behind = 0 != (Ov013_Dot(&r1, v) < Ov013_Dot(&d, v));
    if (behind) {
        res = d;
    } else if (Ov013_Dot2(&r1, &d) > Ov013_Dot2(&r2, &d)) {
        res = r1;
    } else {
        res = r2;
    }
    *out = res;
}

}
