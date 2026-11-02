#include "ov006/SlotManager.h"
#include "ov006/ov006.h"
#include "nitro/fx.h"
#include "Main/Effect/Effect.h"
#include "Main/Sys/FieldState.h"
#include "ov006/Racer.h"

typedef struct ov006_Ofs021e76d8 {
    VecFx32 a;
    VecFx32 b;
} ov006_Ofs021e76d8;

#define OV006_SINCOS FX_SinCosTable_

extern "C" {

extern void *data_02097e4c;
extern ov006_Ofs021e76d8 data_ov006_021eb954[];
AnimCtrl *func_ov000_02190a30(Model0218fe1c *a, int b);
void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
ov006_Slot *func_ov006_021db060(ov006_SlotManager *self, u32 idx);
u16 func_01ffc128(u16 target, u16 cur, s32 rate, u32 minStep, u16 maxStep);

void func_ov006_021e76d8(Ov006Racer *self) {
    VecFx32 v1;
    VecFx32 p1;
    MtxFx33 m;
    VecFx32 v2;
    VecFx32 o2;
    VecFx32 v3;
    VecFx32 o3;
    VecFx32 p4;
    MtxFx33 t;
    Rot16 r;
    Rot16 cr;
    EffectObj *e;
    if (self->unk_1f5 != 0) {
        self->unk_1f5--;
    }
    if (self->unk_1f8 != 0) {
        self->unk_1f8--;
        if (self->unk_1f8 == 0) {
            e = func_020657b0(data_0214a420, self->unk_1e8);
            if (e != NULL) {
                EffectObj_StopLoop(e);
                e->state = 4;
                self->unk_1e8 = 0;
            }
            {
                AnimCtrl *h = func_ov000_02190a30(self->model, 3);
                if (h != NULL) {
                    if (h->cur != NULL) {
                        h->cur->frame = 0;
                    }
                    h->paused = 1;
                }
            }
            {
                Model0218fe1c *m = self->model;
                m->color = 0x53ff;
                m->color2 = 0x53ff;
                m->blend = 2;
                m->blendMax = 1;
            }
        } else if (self->model->blend <= 1) {
            u16 a = 0;
            u16 b = 0;
            self->phase++;
            if (self->phase > 2) {
                self->phase = 0;
            }
            switch (self->phase) {
            case 0:
                a = 0x53ff;
                b = 0x7f94;
                break;
            case 1:
                a = 0x7f94;
                b = 0x5a5f;
                break;
            case 2:
                a = 0x5a5f;
                b = 0x53ff;
                break;
            }
            {
                Model0218fe1c *m = self->model;
                m->color = a;
                m->color2 = b;
                m->blend = 0x15;
                m->blendMax = 0x14;
            }
        }
        if (self->unk_1e8 != 0) {
            e = func_020657b0(data_0214a420, self->unk_1e8);
            if (e == NULL) {
                self->unk_1e8 = 0;
            } else {
                e->SetPos(&self->pos);
            }
        }
    }
    if (self->unk_1fa != 0) {
        self->unk_1fa--;
        if (self->boosting && self->unk_1fa != 0) {
            self->unk_1fa--;
        }
        if (self->unk_1fa == 0 || self->unk_1f8 != 0) {
            self->unk_1fa = 0;
            e = func_020657b0(data_0214a420, self->unk_1ec);
            if (e != NULL) {
                EffectObj_StopLoop(e);
                self->unk_1ec = 0;
            }
            if (self->unk_19c_0 & 1) {
                e = func_02065f88(0x38a, &self->pos);
                if (e != NULL) {
                    e->SetScaleAll(0x1800);
                    self->unk_1ec = e->id;
                    if (self->idx == data_ov006_021ec884->unk5) {
                        func_02049f44(data_02097e4c, 0x82, &self->pos, 0);
                    }
                }
            }
        } else if (self->unk_1ec == 0 && (self->unk_19c_0 & 1)) {
            e = func_02065f88(0x38c, &self->pos);
            if (e != NULL) {
                if (self->idx == data_ov006_021ec884->unk5) {
                    e->SetScaleAll(0x1266);
                } else {
                    e->SetScaleAll(0xa66);
                }
                e->speed = 0x800;
                self->unk_1ec = e->id;
            }
        }
    }
    if (self->unk_1ec != 0) {
        e = func_020657b0(data_0214a420, self->unk_1ec);
        if (e != NULL) {
            if (!(self->unk_19c_0 & 1)) {
                e->state = 4;
                self->unk_1ec = 0;
            } else {
                e->SetPos(&self->pos);
            }
        } else {
            self->unk_1ec = 0;
        }
    }
    if (self->unk_1d4 != 0) {
        e = func_020657b0(data_0214a420, self->unk_1d4);
        if (e == NULL) {
            self->unk_1d4 = 0;
        } else {
            v1.x = e->scale.x;
            v1.y = e->scale.y;
            v1.z = e->scale.z;
            v1.x += 0x52;
            v1.y += 0x52;
            v1.z += 0xa4;
            e->SetScale(&v1);
            p1 = self->pos;
            p1.y += self->centerY;
            e->SetPos(&p1);
            e->SetRot(&self->rot);
        }
    }
    if (self->unk_1d8 != 0 || self->unk_1dc != 0) {
        BOOL set;
        u16 idx = func_ov006_021db060(data_ov006_021ec884, self->idx)->unkC & 0xfff;
        u16 rz = self->rot.z;
        u16 ry = self->rot.y;
        u16 rx = self->rot.x;
        set = FALSE;
        MTX_Identity33_(&m);
        if (ry != 0) {
            MTX_RotY33_(&m, OV006_SINCOS[(ry >> 4) * 2], OV006_SINCOS[(ry >> 4) * 2 + 1]);
            set = TRUE;
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX33_(&t, OV006_SINCOS[(rx >> 4) * 2], OV006_SINCOS[(rx >> 4) * 2 + 1]);
                MTX_Concat33(&t, &m, &m);
            } else {
                MTX_RotX33_(&m, OV006_SINCOS[(rx >> 4) * 2], OV006_SINCOS[(rx >> 4) * 2 + 1]);
                set = TRUE;
            }
        }
        if (rz != 0) {
            if (set) {
                MTX_RotZ33_(&t, OV006_SINCOS[(rz >> 4) * 2], OV006_SINCOS[(rz >> 4) * 2 + 1]);
                MTX_Concat33(&t, &m, &m);
            } else {
                MTX_RotZ33_(&m, OV006_SINCOS[(rz >> 4) * 2], OV006_SINCOS[(rz >> 4) * 2 + 1]);
            }
        }
        r.x = func_01ffc128(self->rot.x, self->look2.x, 0x4cd, 1, 0x8000);
        r.y = func_01ffc128(self->rot.y, self->look2.y, 0x4cd, 1, 0x8000);
        r.z = self->rot.z;
        if (self->unk_1d8 != 0) {
            e = func_020657b0(data_0214a420, self->unk_1d8);
            if (e == NULL) {
                self->unk_1d8 = 0;
            } else {
                v2.x = e->scale.x;
                v2.y = e->scale.y;
                v2.z = e->scale.z;
                v2.x += 0x29;
                v2.y += 0x29;
                v2.z += 0xa4;
                e->SetScale(&v2);
                MTX_MultVec33(&data_ov006_021eb954[idx].a, &m, &o2);
                VEC_Add(&o2, &self->pos, &o2);
                e->SetPos(&o2);
                e->SetRot(&r);
            }
        }
        if (self->unk_1dc != 0) {
            e = func_020657b0(data_0214a420, self->unk_1dc);
            if (e == NULL) {
                self->unk_1dc = 0;
            } else {
                v3.x = e->scale.x;
                v3.y = e->scale.y;
                v3.z = e->scale.z;
                v3.x += 0x29;
                v3.y += 0x29;
                v3.z += 0xa4;
                e->SetScale(&v3);
                MTX_MultVec33(&data_ov006_021eb954[idx].b, &m, &o3);
                VEC_Add(&o3, &self->pos, &o3);
                e->SetPos(&o3);
                e->SetRot(&r);
            }
        }
    }
    if (self->unk_1d0 != 0) {
        e = func_020657b0(data_0214a420, self->unk_1d0);
        if (e == NULL) {
            self->unk_1d0 = 0;
        } else {
            e->SetPos(&self->pos);
        }
    }
    if (self->unk_1e0 != 0) {
        e = func_020657b0(data_0214a420, self->unk_1e0);
        if (e == NULL) {
            self->unk_1e0 = 0;
        } else {
            e->SetPos(&self->pos);
        }
    }
    if (self->unk_1e4 != 0) {
        e = func_020657b0(data_0214a420, self->unk_1e4);
        if (e == NULL) {
            self->unk_1e4 = 0;
        } else {
            e->SetPos(&self->pos);
        }
    }
    if (self->unk_1f0 != 0) {
        e = func_020657b0(data_0214a420, self->unk_1f0);
        if (e != NULL) {
            if (self->unk_19c_14) {
            Camera *c;
            s32 s;
            p4 = self->pos;
            p4.y += 0x800;
            e->SetPos(&p4);
            c = &data_ov000_021ccd54->cam.base;
            cr.x = c->pitch;
            cr.y = c->yaw;
            cr.z = c->roll;
            cr.x += 0xc000;
            e->SetRot(&cr);
            s = 0x2000;
            if (self->unk_1fc < 10) {
                s += (10 - self->unk_1fc) * 0x2800 / 10;
            }
            e->SetScaleAll(s);
            } else {
                e->state = 4;
                self->unk_1f0 = 0;
            }
        } else {
            self->unk_1f0 = 0;
        }
    }
}

}
