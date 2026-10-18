#include "ov010/ov010.h"

struct Ov010Rot {
    u16 x;
    u16 y;
    u16 z;
};

struct Ov010Mtx33 {
    s32 m[9];
};

struct Ov010Col {
    u32 a;
    u32 b;
};

struct Ov010Task {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_05;
    u16 unk_06;
    u16 id;
    u8 unk_0a[2];
    Ov010Vec v0c;
    Ov010Vec v18;
};

extern "C" {

extern void *data_ov000_021ccd68;
extern u8 data_ov010_0220efb0[];
extern u8 data_ov010_0220fdf4[];
extern void *func_ov000_0218e640(void *a, u16 b);
extern u8 *func_ov003_021da32c(s32 kind);
extern void MTX_RotX33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_RotY33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_RotZ33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_MultVec33(const Ov010Vec *v, const Ov010Mtx33 *m, Ov010Vec *o);
extern void VEC_Add(Ov010Vec *a, const Ov010Vec *b, Ov010Vec *c);
extern void func_ov003_021d9f04(Ov010Col *out, const void *p);
extern void func_ov010_022024c4(u8 *e, u16 a, Ov010Vec *b, Ov010Vec *c, Ov010Col *d);
extern void func_ov010_02202560(u8 *e, u16 a, Ov010Vec *b, Ov010Vec *c, Ov010Rot *d);
extern void func_ov010_02202600(u8 *e, void *fn);
extern BOOL func_ov010_022018c4(u16 id, const Ov010Vec *a, const Ov010Vec *b);

static inline void *Ov010_FindObjById(u16 id) {
    if (data_ov000_021ccd68 != NULL) {
        return func_ov000_0218e640(data_ov000_021ccd68, id);
    }
    return NULL;
}

static inline u8 *Ov010_SpawnShot(Ov010Task *t) {
    u8 *e = func_ov003_021da32c(0x4829);
    FLD(Ov010Flags8, e, 0x16).b0 = 1;
    if (FLD(u8 *, e, 0x4c) != NULL) {
        FLD(u16, FLD(u8 *, e, 0x4c), 0x1c) = t->id;
    }
    return e;
}

u8 *func_ov010_02201cc8(Ov010Task *t) {
    u8 *e = NULL;
    if (t->b0) {
        u8 *obj = (u8 *)Ov010_FindObjById(t->id);
        if (obj != NULL) {
            Ov010Mtx33 mx;
            Ov010Mtx33 my;
            Ov010Mtx33 mz;
            Ov010Vec p;
            Ov010Vec d;
            Ov010Vec o;
            Ov010Col c;
            Ov010Rot r;
            e = Ov010_SpawnShot(t);
            r = FLD(Ov010Rot, obj, 0x7c);
            MTX_RotX33_(&mx, OV010_SIN(r.x), OV010_COS(r.x));
            MTX_RotY33_(&my, OV010_SIN(r.y), OV010_COS(r.y));
            MTX_RotZ33_(&mz, OV010_SIN(r.z), OV010_COS(r.z));
            MTX_MultVec33(&t->v18, &mz, &d);
            MTX_MultVec33(&d, &mx, &d);
            MTX_MultVec33(&d, &my, &d);
            p = FLD(Ov010Vec, obj, 0x70);
            VEC_Add(&p, &d, &p);
            MTX_MultVec33(&t->v0c, &mz, &o);
            MTX_MultVec33(&o, &mx, &o);
            MTX_MultVec33(&o, &my, &o);
            func_ov003_021d9f04(&c, data_ov010_0220efb0);
            func_ov010_022024c4(e, t->unk_06, &p, &o, &c);
            func_ov010_02202600(e, (void *)func_ov010_022018c4);
        }
    }
    return e;
}

void func_ov010_02201eac(Ov010Task *t, u16 a, u16 id, const Ov010Vec *v0, const Ov010Vec *v1) {
    t->b0 = 1;
    t->unk_06 = a;
    t->id = id;
    t->v0c = *v0;
    t->v18 = *v1;
}

void func_ov010_02201f00(void) {
}

void *func_ov010_02201f04(void *o) {
    func_0203de1c(o);
    return o;
}

void *func_ov010_02201f18(void) {
    u8 *p = (u8 *)func_0203dd9c(0x24);
    if (p != NULL) {
        FLD(void *, p, 0) = data_ov010_0220fdf4;
        FLD(Ov010Flags8, p, 4).b0 = 0;
    }
    return p;
}

u8 *func_ov010_02201f44(Ov010Task *t) {
    u8 *e = NULL;
    if (t->b0) {
        u8 *obj = (u8 *)Ov010_FindObjById(t->id);
        if (obj != NULL) {
            Ov010Vec p;
            Ov010Vec d;
            Ov010Vec o;
            Ov010Rot r;
            e = Ov010_SpawnShot(t);
            p = FLD(Ov010Vec, obj, 0x70);
            OV010_BLKCPY(&d, &t->v18);
            func_ov003_021d9980(&d, FLD(u16, obj, 0x7e), &d);
            VEC_Add(&p, &d, &p);
            r = FLD(Ov010Rot, obj, 0x7c);
            r.x = 0;
            r.z = 0;
            func_ov003_021d9980(&o, FLD(u16, obj, 0x7e), &t->v0c);
            func_ov010_02202560(e, t->unk_06, &p, &o, &r);
            func_ov010_02202600(e, (void *)func_ov010_022018c4);
        }
    }
    return e;
}

void func_ov010_02202074(Ov010Task *t, u16 a, u16 id, const Ov010Vec *v0, const Ov010Vec *v1) {
    t->b0 = 1;
    t->unk_06 = a;
    t->id = id;
    t->v0c = *v0;
    t->v18 = *v1;
}

}
