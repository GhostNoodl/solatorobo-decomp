#include "nitro/fx.h"

#include "ov000/FieldMgr.h"
#define SC(r) FX_SinCosTable_[((r) >> 4) * 2], FX_SinCosTable_[((r) >> 4) * 2 + 1]

extern "C" {

const char *func_02039674(const void *path);

static inline void RotZYX(MtxFx33 *m, const u16 *rot) {
    MtxFx33 t;
    BOOL any;
    u16 rz;
    u16 rx;
    u16 ry;
    any = FALSE;
    rz = rot[2];
    ry = rot[1];
    rx = rot[0];
    MTX_Identity33_(m);
    if (rz != 0) {
        MTX_RotZ33_(m, SC(rz));
        any = TRUE;
    }
    if (ry != 0) {
        if (any) {
            MTX_RotY33_(&t, SC(ry));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotY33_(m, SC(ry));
            any = TRUE;
        }
    }
    if (rx != 0) {
        if (any) {
            MTX_RotX33_(&t, SC(rx));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotX33_(m, SC(rx));
        }
    }
}

void func_ov000_021b8014(FieldProp *self, const FieldPropDef *def, s32 a, u8 b) {
    self->loader.flag0 = 1;
    self->loader.flag2 = 1;
    if (def->hit) {
        self->loader.flag8 = 1;
    }
    self->unk_f0 = a;
    self->unk_f4 = b;
    if (def->tex) {
        self->loader.flag4 = 1;
    }
    if (def->anim) {
        self->loader.flag6 = 1;
        if (def->loop) {
            self->model.loop = 1;
        }
        if (def->unk_30 != 0x1000) {
            self->model.speed = def->unk_30;
        }
    }
    self->loader.state = 0;
    self->loader.def = def;
    self->loader.name = func_02039674(def);
    self->model.trans = def->pos;
    RotZYX(&self->model.rot, def->rot);
    if (def->boxTest) {
        self->model.boxTest = 1;
    }
    self->model.scale.x = def->sx << 4;
    self->model.scale.y = def->sy << 4;
    self->model.scale.z = def->sz << 4;
    if (def->fade) {
        self->fade = 1;
    }
    if (def->lod) {
        self->lod = 1;
    }
    if (def->addInvTrans) {
        self->model.addInvTrans = 1;
    }
}

}
