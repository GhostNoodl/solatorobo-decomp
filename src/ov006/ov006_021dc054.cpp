#include "ov006/Model.h"
#include "nitro/fx.h"

typedef struct ov006_Unk021dc054 {
    void *vtbl;
    s32 state;
    s16 timer;
    u8 unkA[2];
    u8 unkC[8];
    u8 unk14[4];
    char unk18[0x20];
    char unk38[0x6c];
    u16 unkA4;
    u8 unkA6[2];
    ov006_Model *unkA8;
    u16 unkAC;
    u8 unkAE[2];
    s32 unkB0;
    s32 unkB4;
    s32 unkB8;
    VecFx32 pos;
    VecFx32 dir;
    fx32 speed;
    fx32 unkD8;
    s32 unkDC;
    s32 unkE0;
    s32 unkE4;
    u8 unkE8;
} ov006_Unk021dc054;

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

typedef struct ov006_ModelFlags {
    u32 b0 : 2;
    u32 prio : 5;
    u32 pal : 6;
    u32 rest : 19;
} ov006_ModelFlags;

extern "C" {

extern u8 *data_02097d48;
u8 func_02043d48(void *p);

BOOL func_02049244(VecFx32 *out, s32 speed, const VecFx32 *from, const VecFx32 *to, s32 minDist);
void func_ov006_021dbbac(void *p);
BOOL func_02054f10(void *a, int b);

void func_ov006_021dc054(ov006_Unk021dc054 *self) {
    VecFx32 v = {0, 0, 0};
    fx32 t;
    u16 id;
    t = 0x1000;
    switch (self->state) {
    case 0:
        if (!VCALL(self->unk14, 34)) {
            self->state = 5;
            self->timer = 0;
            break;
        }
        id = self->unkA4;
        self->unkAC = id;
        {
            ov006_Model *model = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
            if (model != NULL) {
                func_02041218(model->unk88);
                func_02041440(model, self->unk38, 1);
                STD_CopyString(model->unk2C, self->unk18);
            }
            self->unkA8 = model;
        }
        func_020417e0(self->unkA8, (void *)VCALL(self->unk14, 10));
        self->unkA8->unk6C |= 2;
        func_02041d9c(self->unkA8, self->unkE0, id);
        self->unkA8->unk6C |= 0x80000;
        self->unkA8->unk6C |= 0x400000;
        VCALL(self->unk14, 08);
        self->unkA4 = 0xffff;
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
        if (self->unkA8 == NULL) {
            self->timer++;
            break;
        }
        if (func_02054f10(self->unkA8, 0xffff)) {
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
        OV006_DELETE_MODEL(self->unkA8);
        self->state = 5;
        self->timer = 0;
    }
    case 5:
        if (VCALL(self->unk14, 34)) {
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
    self->unkDC = FX_Mul(t, 0x1f000) >> 12;
    func_ov006_021dbbac(self->unkC);
}

}
