#include "ov015/ov015.h"

extern "C" {

void func_0204b420(void *p);

struct Ov015cVec {
    s32 x;
    s32 y;
    s32 z;
};

extern const Ov015cVec data_ov015_02212584;
extern const Ov015cVec data_ov015_02212590;
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);
s32 FX_Div(s32 a, s32 b);
void MTX_Identity22_(void *m);
void MTX_ScaleApply22(void *src, void *dst, s32 x, s32 y);
void VEC_Add(const Ov015cVec *a, const Ov015cVec *b, Ov015cVec *o);
void func_ov000_021c8408(void);

static inline void *Ov015c_GetPart(void *self, int idx) {
    if (idx >= FLD(s32, self, 0x80)) {
        return NULL;
    }
    return FLD(u8 *, self, 0x78) + idx * 0x28;
}

static inline void Ov015c_PlayPart(void *model, int idx, int flag) {
    void *res = FLD(void *, model, 0x28);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = Ov015c_GetPart(model, idx);
    if (part != NULL && FLD(void *, part, 0x4) != NULL) {
        anim = FLD(void *, FLD(void *, part, 0x4), 0x30);
    } else {
        anim = NNS_G2dGetCellDataByIdx(FLD(void *, res, 0x4), **(u16 **)FLD(void *, NNS_G2dGetAnimSequenceByIdx(FLD(void *, res, 0xc), idx), 0xc));
    }
    func_02042628(model, anim, part, flag);
}

static inline s32 Ov015c_Sin(s32 t) {
    return FX_SinCosTable_[(Ov015_FxMul(t, 0x3fff000) >> 16) * 2];
}

static inline s32 Ov015c_SinIdx(s32 idx) {
    return FX_SinCosTable_[idx * 2];
}

static inline s32 Ov015c_Sin2(s32 t) {
    return Ov015c_SinIdx(Ov015_FxMul(t, 0x3fff000) >> 16);
}

static inline void Ov015c_SetV(Ov015cVec *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline s32 Ov015c_Sub(s32 a, s32 b) {
    return a - b;
}

static inline void Ov015c_SetPosV(void *m, const Ov015cVec *v) {
    FLD(s32, m, 0xfc) = v->x;
    FLD(s32, m, 0x100) = v->y;
}

static inline void Ov015c_SetPos(void *m, s32 x, s32 y) {
    FLD(s32, m, 0xfc) = x;
    FLD(s32, m, 0x100) = y;
}

void func_ov015_021fcb1c(u8 *self) {
    Ov015cVec off;
    Ov015cVec v2;
    Ov015cVec v;
    s32 cnt;
    s32 x;
    s32 y;
    if (FLD(s32, self, 0x1c) < 0x3c) {
        x = 0;
        y = 0x8000;
        off.x = x;
        off.y = Ov015c_Sub(y, 0x18000);
        off.z = x;
    } else {
        Ov015c_SetV(&off, 0, -0x34000, 0);
        off.y -= 0x10000;
    }
    if (FLD(s32, self, 0x1c) < 0x3c) {
        s32 sc;
        FLD(s32, FLD(void *, self, 0x24), 0x150) = -0x1666;
        Ov015c_SetPos(FLD(void *, self, 0x24), x, y);
        if (FLD(s32, self, 0x1c) < 0x10) {
            sc = Ov015_FxMul(FX_SinCosTable_[(Ov015_FxMul(0x3fff000, FX_Div((FLD(s32, self, 0x1c) % 8) << 12, 0x8000)) >> 16) * 2], 0x4cd) + 0xb33;
        } else {
            sc = 0x1000;
        }
        FLD(void *, FLD(void *, self, 0x24), 0x158) = (void *)func_ov000_021c8408;
        MTX_Identity22_(FLD(u8 *, self, 0x24) + 0x114);
        MTX_ScaleApply22(FLD(u8 *, self, 0x24) + 0x114, FLD(u8 *, self, 0x24) + 0x114, sc, sc);
        Ov015c_PlayPart(FLD(void *, self, 0x24), 7, 1);
        MTX_Identity22_(FLD(u8 *, self, 0x24) + 0x114);
        FLD(void *, FLD(void *, self, 0x24), 0x158) = NULL;
    }
    cnt = FLD(s32, self, 0x8);
    FLD(s32, FLD(void *, self, 0x28), 0x150) = -0x199a;
    VEC_Add(&off, &data_ov015_02212584, &v);
    Ov015c_SetPosV(FLD(void *, self, 0x28), &v);
    Ov015c_PlayPart(FLD(void *, self, 0x28), 0x10, 0);
    if (cnt % 8 < 4) {
        VEC_Add(&off, &data_ov015_02212590, &v2);
        FLD(s32, FLD(void *, self, 0x24), 0x150) = -0x1ccd;
        Ov015c_SetPosV(FLD(void *, self, 0x24), &v2);
        Ov015c_PlayPart(FLD(void *, self, 0x24), 0xd, 0);
    }
    if (FLD(s32, self, 0x1c) > 0x3c) {
        FLD(s32, self, 0x1c) = 0x3d;
    }
}

void *func_ov015_021fce4c(u8 *self) {
    func_0204b420(self + 0xc0);
    func_0204b420(self + 0x4);
    return self;
}

void *func_ov015_021fce6c(u8 *self) {
    func_0204b420(self + 0xc0);
    func_0204b420(self + 0x4);
    func_0203de1c(self);
    return self;
}

static inline void Ov015Cam_SetFovy(Ov015Cam *c, s32 deg) {
    u16 idx;
    c->fovyDeg = deg;
    c->fovy = (u16)(((s64)c->fovyDeg * 0xb60b60b60bLL + 0x80000000000LL) >> 44);
    idx = (u16)(c->fovy >> 1);
    c->fovySin = FX_SinCosTable_[(idx >> 4) * 2];
    c->fovyCos = FX_SinCosTable_[(idx >> 4) * 2 + 1];
    c->unk_3e = 1;
}

static inline void Ov015_V3Set(Ov015V3 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void Ov015Cam_Init(Ov015Cam *c, s32 ay, s32 az) {
    Ov015_V3Set(&c->pos, 0, 0x2000, 0x2000);
    Ov015_V3Set(&c->at, 0, ay, az);
    Ov015_V3Set(&c->up, 0, 0x1000, 0);
    Ov015Cam_SetFovy(c, 0x1e000);
    c->near = 0x119a;
    c->far = 0x7d0000;
    c->unk_3e = 1;
    c->unk_40 = 0;
}

void func_ov015_021fce94(Ov015CamPair *self) {
    Ov015Cam_Init(&self->cam0, 0x2000, -0x1000);
    Ov015Cam_Init(&self->cam1, -0x1800, 0);
    self->unk_18c = -0x333;
    self->unk_190 = 0x6400;
    self->unk_194 = -0x1000;
    self->unk_198 = 0x5a3d;
}

}
