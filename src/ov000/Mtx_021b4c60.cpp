#include "nitro/fx.h"

typedef struct {
    u8 pad_00[0x10];
    s16 unk_10;
    u16 b0 : 1;
    u16 rest : 15;
    s16 unk_14;
    s16 unk_16;
} Cfg021b4c60;

typedef struct {
    u8 pad[0x84];
    void **unk_84;
} Res021b4c60;

typedef struct {
    u8 b0 : 5;
    u8 b5 : 1;
    u8 rest : 2;
} Flags021b4c60;

typedef struct {
    u8 pad_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 pad_10[0x24];
    Res021b4c60 *res;
    u8 *model;
    u8 *obj;
    u8 pad_40[0x18];
    void *unk_58;
    u8 pad_5c[0x8];
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    VecFx32 pos;
    u16 rx;
    u16 ry;
    u16 rz;
    u8 pad_82[0x2a];
    Flags021b4c60 *flags;
} Obj021b4c60;

extern "C" {

Cfg021b4c60 *func_0206fef8(u16 id);
void *func_020705fc(u16 id);
void *func_0203dd9c(u32 size);
void *func_ov000_0218fe1c(void *m);
void func_ov000_0219badc(void *m, Res021b4c60 *res, Cfg021b4c60 *cfg);
void func_0203f80c(void *o);
void func_0203f990(void *o, void *a);
void func_0203f9b8(void *o, s32 a);
void func_0203f8d8(void *o);
void func_0203f9dc(void *o, MtxFx43 *m);

static inline void *ResData(Res021b4c60 *res) {
    return res->unk_84 != NULL ? *res->unk_84 : NULL;
}

void func_ov000_021b4c60(Obj021b4c60 *self) {
    MtxFx43 t;
    MtxFx43 m;
    MtxFx43 *pm = &m;
    Cfg021b4c60 *cfg = func_0206fef8(self->unk_0e);
    func_020705fc(self->unk_0e);
    self->unk_64 = cfg->unk_14 << 4;
    self->unk_68 = cfg->unk_16 << 4;
    self->unk_6c = self->unk_68 >> 1;
    if (cfg->b0) {
        u8 *mdl = (u8 *)func_0203dd9c(0xe8);
        if (mdl != NULL) {
            mdl = (u8 *)func_ov000_0218fe1c(mdl);
        }
        self->model = mdl;
        *(u16 *)(mdl + 0xb4) = self->unk_0c;
        func_ov000_0219badc(self->model, self->res, cfg);
    }
    if (self->obj != NULL) {
        *(s32 *)(self->obj + 0x14) = self->unk_64 << 1;
    }
    if (!self->flags->b5) {
        return;
    }
    if (ResData(self->res) == NULL) {
        return;
    }
    {
        void *o = func_0203dd9c(0x98);
        if (o != NULL) {
            func_0203f80c(o);
        }
        self->unk_58 = o;
    }
    func_0203f990(self->unk_58, ResData(self->res));
    func_0203f9b8(self->unk_58, cfg->unk_10);
    func_0203f8d8(self->unk_58);
    {
        void *o;
        u16 rx;
        u16 ry;
        u16 rz;
        BOOL any;
        rz = self->rz;
        o = self->unk_58;
        ry = self->ry;
        rx = self->rx;
        any = FALSE;
        MTX_Identity43_(pm);
        if (rz != 0) {
            MTX_RotZ43_(pm, FX_SinCosTable_[(rz >> 4) * 2], FX_SinCosTable_[(rz >> 4) * 2 + 1]);
            any = TRUE;
        }
        if (ry != 0) {
            if (any) {
                MTX_RotY43_(&t, FX_SinCosTable_[(ry >> 4) * 2], FX_SinCosTable_[(ry >> 4) * 2 + 1]);
                MTX_Concat43(&t, &m, &m);
            } else {
                MTX_RotY43_(&m, FX_SinCosTable_[(ry >> 4) * 2], FX_SinCosTable_[(ry >> 4) * 2 + 1]);
                any = TRUE;
            }
        }
        if (rx != 0) {
            if (any) {
                MTX_RotX43_(&t, FX_SinCosTable_[(rx >> 4) * 2], FX_SinCosTable_[(rx >> 4) * 2 + 1]);
                MTX_Concat43(&t, &m, &m);
            } else {
                MTX_RotX43_(&m, FX_SinCosTable_[(rx >> 4) * 2], FX_SinCosTable_[(rx >> 4) * 2 + 1]);
            }
        }
        m._30 = self->pos.x;
        m._31 = self->pos.y;
        m._32 = self->pos.z;
        func_0203f9dc(o, &m);
    }
}

}
