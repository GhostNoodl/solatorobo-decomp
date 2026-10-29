#include "ov013/ov013.h"

struct Ov013Cam {
    u8 unk_00[0x4];
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_05;
    u16 id;
    Ov013Vec min;
    Ov013Vec max;
    Ov013Vec off;
};


struct Ov013Pair32 {
    s32 a;
    s32 b;
};

extern "C" {

extern void *data_ov013_0220bbb8[];
extern char data_ov013_0220ba58[];
extern char data_ov013_0220ba60[];
extern void func_ov003_021d9980(Ov013Vec *out, u16 rot, const Ov013Vec *v);
extern void *func_ov000_02194074(void *self);
extern void *func_ov003_021cf2bc(void *p);
extern void *func_ov003_021cf2d8(void *p);
extern void *func_ov000_0218ea20(void *p);
extern void *func_ov000_0218fee4(void *p);
extern void *func_ov000_0218e9c4(void *p);
extern void func_ov000_0219433c(void *self);
extern BOOL func_ov000_021946f8(void *self);
extern BOOL func_ov000_0218f110(void *p);

extern void *data_ov000_021ccd68;
extern u8 data_ov013_0220aedc[];
extern const Ov013Vec data_ov013_0220af58;
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern u8 *func_ov000_0219bf90(void);
extern void VEC_Add(const Ov013Vec *a, const Ov013Vec *b, Ov013Vec *out);

static inline Ov013Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline void Ov013_RotY(Ov013Vec *out, const Ov013Vec *v, Ov013Actor *a) {
    if (a != NULL) {
        func_ov003_021d9980(out, a->rot[1], v);
    }
}


void func_ov013_0220428c(Ov013Cam *self) {
    Ov013Actor *t;
    u8 *pl;
    Ov013Vec p;
    Ov013Vec o;
    if (!self->b0) {
        return;
    }
    t = Ov013_FindActor(self->id);
    pl = func_ov000_0219bf90();
    if (t == NULL || pl == NULL) {
        return;
    }
    p = t->pos;
    Ov013_RotY(&o, &data_ov013_0220af58, t);
    VEC_Add(&p, &o, &p);
    VEC_Add(&p, &self->off, &p);
    self->off = FLD(Ov013Vec, data_ov013_0220aedc, 0x4c);
    if (self->b1) {
        p.x = p.x > self->max.x ? self->max.x : (p.x < self->min.x ? self->min.x : p.x);
        p.y = p.y > self->max.y ? self->max.y : (p.y < self->min.y ? self->min.y : p.y);
        p.z = p.z > self->max.z ? self->max.z : (p.z < self->min.z ? self->min.z : p.z);
    }
    FLD(Ov013Vec, pl, 0xb90) = p;
    FLD(s32, pl, 0xb9c) = 0x700;
}

void func_ov013_022043f8(void *self, u32 *p) {
    if (p != NULL) {
        FLD(u32, self, 0x24) = *p;
    }
}

void func_ov013_02204408(Ov013Vec *out, const Ov013Vec *v, Ov013Actor *a) {
    if (a != NULL) {
        func_ov003_021d9980(out, a->rot[1], v);
    }
}

void func_ov013_02204428(Ov013Vec *dst, const Ov013Vec *src, Ov013Actor *owner) {
    *dst = *src;
}

void func_ov013_02204444(void) {
}

BOOL func_ov013_02204448(void) {
    return TRUE;
}

void func_ov013_02204450(void) {
}

}
