#include "ov015/ov015.h"

extern "C" {

void Camera_Dtor(void *p);


extern const VecFx32 data_ov015_02212584;
extern const VecFx32 data_ov015_02212590;
void func_ov000_021c8408(s32 idx, int x, int y, int z, u16 color, const void *oam, const void *tex, u32 texBase, u32 plttBase, const void *mtx, u32 arg);

void func_ov015_021fcb1c(Ov015Hud *self) {
    VecFx32 off;
    VecFx32 v2;
    VecFx32 v;
    s32 cnt;
    s32 x;
    s32 y;
    if (self->unk_1c < 0x3c) {
        x = 0;
        y = 0x8000;
        off.x = x;
        off.y = Ov015c_Sub(y, 0x18000);
        off.z = x;
    } else {
        Ov015c_SetV(&off, 0, -0x34000, 0);
        off.y -= 0x10000;
    }
    if (self->unk_1c < 0x3c) {
        s32 sc;
        self->mdl0->unk_150 = -0x1666;
        Ov015Model_SetPos(self->mdl0, x, y);
        if (self->unk_1c < 0x10) {
            sc = FX_Mul(FX_SinCosTable_[(FX_Mul(0x3fff000, FX_Div((self->unk_1c % 8) << 12, 0x8000)) >> 16) * 2], 0x4cd) + 0xb33;
        } else {
            sc = 0x1000;
        }
        self->mdl0->unk_158 = (void *)func_ov000_021c8408;
        MTX_Identity22_((MtxFx22 *)((u8 *)self->mdl0 + 0x114));
        MTX_ScaleApply22((MtxFx22 *)((u8 *)self->mdl0 + 0x114), (MtxFx22 *)((u8 *)self->mdl0 + 0x114), sc, sc);
        Ov015Model_PlayPart(self->mdl0, 7, 1);
        MTX_Identity22_((MtxFx22 *)((u8 *)self->mdl0 + 0x114));
        self->mdl0->unk_158 = NULL;
    }
    cnt = self->frame;
    self->mdl1->unk_150 = -0x199a;
    VEC_Add((VecFx32 *)&off, (VecFx32 *)&data_ov015_02212584, (VecFx32 *)&v);
    Ov015Model_SetPosV(self->mdl1, &v);
    Ov015Model_PlayPart(self->mdl1, 0x10, 0);
    if (cnt % 8 < 4) {
        VEC_Add((VecFx32 *)&off, (VecFx32 *)&data_ov015_02212590, (VecFx32 *)&v2);
        self->mdl0->unk_150 = -0x1ccd;
        Ov015Model_SetPosV(self->mdl0, &v2);
        Ov015Model_PlayPart(self->mdl0, 0xd, 0);
    }
    if (self->unk_1c > 0x3c) {
        self->unk_1c = 0x3d;
    }
}

void *Ov015Vt_0221291c_Dtor(u8 *self) {
    Camera_Dtor(self + 0xc0);
    Camera_Dtor(self + 0x4);
    return self;
}

void *Ov015Vt_0221291c_DtorDelete(u8 *self) {
    Camera_Dtor(self + 0xc0);
    Camera_Dtor(self + 0x4);
    Heap_Free(self);
    return self;
}

static inline void Ov015Cam_SetFovy(Ov015Cam *c, s32 deg) {
    u16 idx;
    c->fovyDeg = deg;
    c->fovy = (u16)(((s64)c->fovyDeg * 0xb60b60b60bLL + 0x80000000000LL) >> 44);
    idx = (u16)(c->fovy >> 1);
    c->fovySin = FX_SinCosTable_[(idx >> 4) * 2];
    c->fovyCos = FX_SinCosTable_[(idx >> 4) * 2 + 1];
    c->dirty = 1;
}

static inline void Ov015_V3Set(Ov015Vec *v, s32 x, s32 y, s32 z) {
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
    c->dirty = 1;
    c->mode = 0;
}

void Ov015CamPair_Init(Ov015CamPair *self) {
    Ov015Cam_Init(&self->cam0, 0x2000, -0x1000);
    Ov015Cam_Init(&self->cam1, -0x1800, 0);
    self->unk_18c.x = -0x333;
    self->unk_18c.y = 0x6400;
    self->unk_18c.z = -0x1000;
    self->unk_198 = 0x5a3d;
}

}
