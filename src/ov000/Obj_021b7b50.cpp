#include "ov000/Actor.h"
#include "ov000/FieldMgr.h"

extern "C" {

BOOL func_ov000_021b7f0c(FieldProp *self);
void HitMesh_Link(void *p);
void func_0203f920(void *p);
BOOL func_01ffc23c(VecFx32 *v, VecFx32 *min, VecFx32 *max);
s32 VEC_Mag(const VecFx32 *v);
s32 FX_Div(s32 a, s32 b);
void func_ov000_021b7838(FieldPropModel *p, s32 speed);

static inline struct NNSG3dRenderObj_ *FieldProp_GetModel(FieldProp *self, u8 n) {
    if (n == 0) {
        return (struct NNSG3dRenderObj_ *)self->model.robj;
    }
    return self->model.sub[n - 1];
}

static inline void FieldProp_SetModel(FieldProp *self, u8 n) {
    struct NNSG3dRenderObj_ *p;
    self->model.cur = n;
    p = FieldProp_GetModel(self, n);
    if (p != NULL) {
        self->model.rob = p;
    }
}

s32 func_ov000_021b7b50(FieldProp *self) {
    VecFx32 d;
    s32 mag;
    switch (self->state) {
    case 0:
        if (!func_ov000_021b7f0c(self)) {
            break;
        }
        self->visible = 1;
        self->model.on = 1;
        if (!self->fade && !self->lod) {
            if (self->hitMesh != NULL) {
                HitMesh_Link(self->hitMesh);
            }
            self->state = 10;
            break;
        }
        self->state++;
    case 1:
        if (self->keepHit && self->hitMesh != NULL) {
            HitMesh_Link(self->hitMesh);
        }
        {
            VecFx32 *g = &data_ov000_021ccd54->cam.base.eye;
            s32 gx = g->x, gy = g->y, gz = g->z;
            d.x = self->model.trans.x;
            d.y = self->model.trans.y;
            d.z = self->model.trans.z;
            d.x -= gx;
            d.y -= gy;
            d.z -= gz;
        }
        if (!func_01ffc23c(&d, &self->viewMin, &self->viewMax)) {
            self->visible = 0;
            if (self->hitMesh != NULL && !self->keepHit) {
                func_0203f920(self->hitMesh);
            }
            break;
        }
        mag = VEC_Mag(&d);
        if (self->viewScale != 0 && self->viewScale != 0x1000) {
            mag = FX_Div(mag, self->viewScale);
        }
        self->model.alpha = 0x1f;
        if (self->fade) {
            if (mag > 0xc3000) {
                self->visible = 0;
                if (self->hitMesh != NULL && !self->keepHit) {
                    func_0203f920(self->hitMesh);
                }
                break;
            }
            if (!self->visible) {
                self->model.alpha = 1;
                self->visible = 1;
            } else if (mag > 0x9b000) {
                self->model.alpha = 0x1f - (u8)((s64)(mag - 0x9b000) * 0x1c / 0x28000);
            }
            if (self->hitMesh != NULL && !self->keepHit) {
                if (mag < 0x3c000) {
                    HitMesh_Link(self->hitMesh);
                } else {
                    func_0203f920(self->hitMesh);
                }
            }
        }
        if (self->lod && self->visible) {
            if (mag > 0x9b000) {
                u8 n = 1;
                if (self->model.nsub < n) {
                    n = self->model.nsub;
                }
                if (n != self->model.cur) {
                    FieldProp_SetModel(self, n);
                }
            } else if (self->model.cur != 0) {
                FieldProp_SetModel(self, 0);
            }
        }
        if (mag < 0xaf000) {
            func_ov000_021b7838(&self->model, 0x1000);
        }
        break;
    case 10:
        func_ov000_021b7838(&self->model, 0x1000);
        self->visible = 1;
        break;
    }
    return 0;
}

}
