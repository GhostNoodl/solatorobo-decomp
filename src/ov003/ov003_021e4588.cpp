#include "ov003/GmObj.h"

typedef struct {
    u8 unk_00[0x16];
    u8 unk_16_0 : 1;
} Ov003Spawned;

typedef struct {
    s32 m[9];
    s32 tx, ty, tz;
} Ov003BigMtx;

typedef struct {
    u8 unk_00[0x98];
} Ov003BigRObj;

typedef struct {
    u8 unk_00[0x84];
    void **unk_84;
} Ov003BigRes;

typedef struct {
    u16 unk_00;
    u16 ang;
    Ov003Vec3 v;
} Ov003BigEnt;

typedef struct {
    void *unk_00;
    void *mdl;
    u8 unk_08[0xac];
    u16 unk_b4;
    u8 unk_b6[0xc];
    u16 unk_c2_0 : 7;
    u16 unk_c2_7 : 1;
} Ov003BigMdl;

typedef struct {
    void *vtbl;
    u8 unk_04[0x8];
    u16 unk_0c;
    u8 unk_0e[0xa];
    s16 unk_18;
    s16 unk_1a;
    u8 unk_1c[0x18];
    Ov003BigRes *unk_34;
    u8 unk_38[0x38];
    Ov003Vec3 pos;
    u16 rot[3];
    u8 unk_82[0xe];
    u8 unk_90[3];
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
    u8 unk_94[0x38];
    u16 unk_cc_0 : 1;
    u8 unk_ce[2];
    s16 res;
    u8 unk_d2[0x136];
    s16 res2;
    u8 unk_20a;
    u8 unk_20b;
    u8 unk_20c[0x84];
    u8 unk_290[0x20];
    u8 unk_2b0[0x90];
    Ov003BigMdl sub;
    u8 unk_404[0x24];
    Ov003Vec3 unk_428[4];
    s32 unk_458[4];
    u8 unk_468[4];
    u8 unk_46c[0x260];
    Ov003BigRObj obj1[4];
    Ov003BigRObj obj2[3];
    Ov003Vec3 unk_af4[3];
    u8 unk_b18;
} Ov003Big;

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern char data_ov003_021f8574[];
extern char data_ov003_021f858d[];
extern char data_ov003_021f8593[];
extern char data_ov003_021f859e[];
extern void func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021911c8(void *model, s32 a);
extern BOOL func_ov000_02191120(void *model);
extern void func_02049f44(void *mgr, s32 id, Ov003Vec3 *pos, s32 a);
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern Ov003Spawned *func_ov000_0218bf1c(void *mgr, Ov003SpawnInfo *info, Ov003Vec3 *pos, void *rot, u16 a);
extern void func_ov000_0219b71c(Ov003Vec3 *pos, Ov003Vec3 *v, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_0218996c(s32 a, s32 b);
extern s32 func_02040498(s32 max);
extern void func_ov000_0219433c(void *self);
extern void func_ov000_0218f074(s16 *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern void STD_CopyString(void *dst, const void *src);
extern BOOL func_ov000_021946f8(void *self);
extern BOOL func_ov000_0218f110(s16 *res);

BOOL func_ov003_021e4588(Ov003Big *self) {
    BOOL r = func_ov000_021946f8(self);
    if (self->res >= 0 && !func_ov000_0218f110(&self->res)) {
        r = FALSE;
    }
    if (self->res2 >= 0 && !func_ov000_0218f110(&self->res2)) {
        r = FALSE;
    }
    return r;
}


extern const s16 FX_SinCosTable_[];
extern const Ov003BigEnt data_ov003_021f5bf0[];
extern void func_ov000_02194758(void *self);
extern void func_ov000_0218ffdc(Ov003BigMdl *m, s16 *res, s32 a, s32 b);
extern void func_ov000_02190758(Ov003BigMdl *m, u16 *rot, s32 a);
extern void NNSi_G3dModifyMatFlag(void *mdl, s32 on, u32 flag);
extern void NNSi_G3dModifyPolygonAttrMask(void *mdl, s32 on, u32 mask);
extern void func_01ffc9fc(Ov003Vec3 *dst, const Ov003Vec3 *src, u16 angle);
extern void VEC_Add(Ov003Vec3 *a, Ov003Vec3 *b, Ov003Vec3 *dst);
extern void func_0203f990(Ov003BigRObj *o, void *res);
extern void MTX_Identity43_(Ov003BigMtx *m);
extern void MTX_RotX43_(Ov003BigMtx *m, s32 s, s32 c);
extern void MTX_RotY43_(Ov003BigMtx *m, s32 s, s32 c);
extern void MTX_RotZ43_(Ov003BigMtx *m, s32 s, s32 c);
extern void MTX_Concat43(Ov003BigMtx *a, Ov003BigMtx *b, Ov003BigMtx *out);
extern void func_0203f9dc(Ov003BigRObj *o, Ov003BigMtx *m);
extern void func_0203f8d8(Ov003BigRObj *o);
extern void func_0203f920(Ov003BigRObj *o);
extern void func_ov003_021e51f8(Ov003Big *self, u32 a);

#define OV003BIG_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003BIG_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

static inline void Ov003Big_SetMtx(Ov003BigRObj *o, Ov003Vec3 *v, u16 rx, u16 ry, u16 rz) {
    Ov003BigMtx m;
    Ov003BigMtx t;
    BOOL set = FALSE;
    MTX_Identity43_(&m);
    if (rz != 0) {
        MTX_RotZ43_(&m, OV003BIG_SIN(rz), OV003BIG_COS(rz));
        set = TRUE;
    }
    if (ry != 0) {
        if (set) {
            MTX_RotY43_(&t, OV003BIG_SIN(ry), OV003BIG_COS(ry));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotY43_(&m, OV003BIG_SIN(ry), OV003BIG_COS(ry));
            set = TRUE;
        }
    }
    if (rx != 0) {
        if (set) {
            MTX_RotX43_(&t, OV003BIG_SIN(rx), OV003BIG_COS(rx));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotX43_(&m, OV003BIG_SIN(rx), OV003BIG_COS(rx));
            set = TRUE;
        }
    }
    m.tx = v->x;
    m.ty = v->y;
    m.tz = v->z;
    func_0203f9dc(o, &m);
}

static inline void *Ov003Big_Res(Ov003BigRes *r) {
    return r->unk_84 != NULL ? *r->unk_84 : NULL;
}

void func_ov003_021e45dc(Ov003Big *self) {
    s32 i;
    func_ov000_02194758(self);
    self->unk_cc_0 = 0;
    func_ov000_0218ffdc(&self->sub, &self->res, 0, 1);
    self->sub.unk_b4 = self->unk_0c;
    func_ov000_02190758(&self->sub, self->rot, 0);
    NNSi_G3dModifyMatFlag(self->sub.mdl, 1, 0x40);
    NNSi_G3dModifyMatFlag(self->sub.mdl, 1, 0x80);
    NNSi_G3dModifyMatFlag(self->sub.mdl, 1, 0x200);
    NNSi_G3dModifyMatFlag(self->sub.mdl, 1, 0x400);
    self->sub.unk_c2_7 = 1;
    NNSi_G3dModifyPolygonAttrMask(self->sub.mdl, 1, 0x1f0000);
    for (i = 0; i < 4; i++) {
        const Ov003BigEnt *e = &data_ov003_021f5bf0[i];
        Ov003Vec3 v;
        u16 ry;
        u16 rz;
        u16 rx;
        void *r;
        func_01ffc9fc(&v, &e->v, self->rot[1]);
        VEC_Add(&v, &self->pos, &v);
        ry = self->rot[1] + e->ang;
        r = Ov003Big_Res(self->unk_34);
        rz = self->rot[2];
        rx = self->rot[0];
        func_0203f990(&self->obj1[i], r);
        Ov003Big_SetMtx(&self->obj1[i], &v, rx, ry, rz);
        if (self->unk_1a == 0 || i <= 1) {
            func_0203f8d8(&self->obj1[i]);
        } else {
            func_0203f920(&self->obj1[i]);
        }
        if (i != 0) {
            ry += 0x8000;
            func_0203f990(&self->obj2[i - 1], Ov003Big_Res(self->unk_34));
            Ov003Big_SetMtx(&self->obj2[i - 1], &v, rx, ry, rz);
            func_0203f920(&self->obj2[i - 1]);
            v.x += (s32)(((s64)OV003BIG_SIN(ry) * 0x400 + 0x800) >> 12);
            v.z += (s32)(((s64)OV003BIG_COS(ry) * 0x400 + 0x800) >> 12);
            self->unk_af4[i - 1].x = v.x;
            self->unk_af4[i - 1].y = v.y;
            self->unk_af4[i - 1].z = v.z;
        }
    }
    {
        u32 a = 0;
        if (self->unk_93_1) {
            a = 0xffff;
        }
        func_ov003_021e51f8(self, a);
    }
}

}
