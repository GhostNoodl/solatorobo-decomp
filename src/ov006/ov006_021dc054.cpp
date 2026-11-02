#include "ov006/Label.h"
#include "nitro/fx.h"
#include "Main/Gfx/GfxMgr.h"

static inline void ov006_VecZero(VecFx32 *v) {
    v->x = 0;
    v->y = 0;
    v->z = 0;
}

static inline void ov006_VecScale(const VecFx32 *a, fx32 s, VecFx32 *out) {
    out->x = FX_Mul(a->x, s);
    out->y = FX_Mul(a->y, s);
    out->z = FX_Mul(a->z, s);
}

extern "C" {

u8 Gfx3DState_NextPolyId(void *p);

BOOL func_02049244(VecFx32 *out, s32 speed, const VecFx32 *from, const VecFx32 *to, s32 minDist);
void ov006_ResLoader_Update(ov006_ResLoader *self);
BOOL func_02054f10(void *a, int b);

void ov006_Label_Update(ov006_Label *self) {
    VecFx32 v = {0, 0, 0};
    fx32 t;
    u16 id;
    t = 0x1000;
    switch (self->state) {
    case 0:
        if (!self->loader.res.vfunc_34()) {
            self->state = 5;
            self->timer = 0;
            break;
        }
        id = self->partId;
        self->part = id;
        {
            Model *model = (Model *)Heap_Alloc(sizeof(Model));
            if (model != NULL) {
                func_02041218(&model->pltt);
                func_02041440(model, self->loader.res.name, 1);
                STD_CopyString(model->name, self->loader.res.arcName);
            }
            self->model = model;
        }
        func_020417e0(self->model, (void *)self->loader.res.vfunc_10());
        self->model->flags |= 2;
        func_02041d9c(self->model, self->unkE0, id);
        self->model->flags |= 0x80000;
        self->model->flags |= 0x400000;
        self->loader.res.vfunc_08();
        self->partId = 0xffff;
        self->state = 1;
        ov006_VecScale(&self->dir, self->speed, &self->pos);
        self->timer = 0;
    case 1: {
        VecFx32 zero;
        fx32 d;
        zero.x = 0;
        zero.y = 0;
        zero.z = 0;
        func_02049244(&self->pos, 0x400 - 0xcd, &self->pos, &zero, 0xcd);
        d = VEC_Distance(&self->pos, &zero);
        t = FX_Div(FX_Mul(self->speed, 0x1200) - d, self->speed);
        if (d < 0xcd) {
            if (self->unkE8) {
                self->state = 7;
                self->timer = 0;
            } else {
                self->state = 2;
                self->timer = 0;
            }
        }
        break;
    }
    case 2:
        if (self->timer != 0) {
            break;
        }
        if (self->model == NULL) {
            self->timer++;
            break;
        }
        if (func_02054f10(self->model, 0xffff)) {
            self->timer++;
        }
        break;
    case 3:
        if (self->unkD8 <= 0x1000) {
            ov006_VecScale(&self->dir, -self->unkD8, &self->pos);
        } else {
            self->pos.x = FX_Mul(self->dir.x, -0x1000);
            self->pos.y = FX_Mul(self->dir.y, -0x1000);
            self->pos.z = FX_Mul(self->dir.z, -0x1000);
        }
        self->state = 4;
        self->timer = 0;
    case 4: {
        fx32 mag = VEC_Mag(&self->pos);
        t = FX_Div(self->unkD8 - mag, self->unkD8);
        self->pos.x = FX_Mul(self->pos.x, 0x1666);
        self->pos.y = FX_Mul(self->pos.y, 0x1666);
        self->pos.z = FX_Mul(self->pos.z, 0x1666);
        if (mag < self->unkD8) {
            break;
        }
        OV006_DELETE_MODEL(self->model);
        self->state = 5;
        self->timer = 0;
    }
    case 5:
        if (self->loader.res.vfunc_34()) {
            self->state = 0;
            self->timer = 0;
        }
        break;
    case 6:
        self->unkE4 = 0x400;
        self->state = 7;
        self->timer = 0;
    case 7:
        self->pos.x += self->unkE4;
        if (self->pos.x > 0xc000) {
            self->state = 8;
            self->timer = 0;
        }
        break;
    case 8:
        break;
    }
    if (t >= 0x1000) {
        t = 0x1000;
    } else if (t < 0) {
        t = 0;
    }
    self->alpha = FX_Mul(t, 0x1f000) >> 12;
    ov006_ResLoader_Update(&self->loader);
}

}
