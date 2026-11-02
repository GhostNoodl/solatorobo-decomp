#include "types.h"
#include "ov003/Shot.h"

// The effect object func_02065f88 returns (Main EffectObj; only the methods used here).
class Ov003AkFx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void SetScaleXYZ(s32 x, s32 y, s32 z);
    virtual void v18();
    virtual void v1c();
    virtual void AddPos(VecFx32 *v);
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void SetRot(ActorRot *r);
};

extern "C" {

extern Ov003ShotDef data_ov003_021f4a34[];
extern Ov003ShotStep data_ov003_021f49c4[];
extern VecFx32 data_02092a50;
extern void *data_02097e4c;
extern void func_ov000_02194758(void *self);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern MtxFx43 *NNS_G3dGlbGetInvV(void);
extern void *func_02049f44(void *mgr, s32 id, VecFx32 *pos, s32 a);
extern Ov003AkFx *func_02065f88(s32 id, VecFx32 *pos);

#define OV003AK_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003AK_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

void func_ov003_021daec0(Ov003Shot *self) {
    func_ov000_02194758(self);
    func_ov000_02198360(self->fsm, 0xb, 0);
    if (self->shotDef != NULL) {
        self->def = self->shotDef;
    } else {
        self->def = &data_ov003_021f4a34[self->unk_18];
    }
    self->steps = self->def->steps;
    if (self->steps == NULL) {
        self->steps = data_ov003_021f49c4;
    }
    if (self->def->viewSpace) {
        MtxFx43 *m;
        s32 x;
        s32 y;
        s32 z;
        self->viewPos.x = self->pos.x;
        self->viewPos.y = self->pos.y;
        self->viewPos.z = self->pos.z;
        m = NNS_G3dGlbGetInvV();
        y = self->pos.y;
        x = self->pos.x;
        z = self->pos.z;
        self->pos.x = (s32)(((s64)x * m->a[0] + (s64)y * m->a[3] + (s64)z * m->a[6]) >> 12);
        self->pos.y = (s32)(((s64)x * m->a[1] + (s64)y * m->a[4] + (s64)z * m->a[7]) >> 12);
        self->pos.z = (s32)(((s64)x * m->a[2] + (s64)y * m->a[5] + (s64)z * m->a[8]) >> 12);
        VEC_Add(&self->pos, &data_02092a50, &self->pos);
    }
    if (self->def->sound >= 0) {
        func_02049f44(data_02097e4c, self->def->sound, &self->pos, 0);
    }
    if (self->def->spawn.id != -1) {
        Ov003AkFx *e = func_02065f88(self->def->spawn.id, &self->pos);
        VecFx32 v;
        MtxFx33 m;
        MtxFx33 t;
        BOOL set;
        u16 rz;
        u16 ry;
        u16 rx;
        s32 s;
        e->SetRot(&self->rot);
        set = FALSE;
        v.x = self->def->spawn.x << 4;
        v.y = self->def->spawn.y << 4;
        v.z = self->def->spawn.z << 4;
        ry = self->rot_y;
        rz = self->rot_z;
        rx = self->rot_x;
        MTX_Identity33_(&m);
        if (ry != 0) {
            MTX_RotY33_(&m, OV003AK_SIN(ry), OV003AK_COS(ry));
            set = TRUE;
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX33_(&t, OV003AK_SIN(rx), OV003AK_COS(rx));
                MTX_Concat33(&t, &m, &m);
            } else {
                MTX_RotX33_(&m, OV003AK_SIN(rx), OV003AK_COS(rx));
                set = TRUE;
            }
        }
        if (rz != 0) {
            if (set) {
                MTX_RotZ33_(&t, OV003AK_SIN(rz), OV003AK_COS(rz));
                MTX_Concat33(&t, &m, &m);
            } else {
                MTX_RotZ33_(&m, OV003AK_SIN(rz), OV003AK_COS(rz));
                set = TRUE;
            }
        }
        MTX_MultVec33(&v, &m, &v);
        e->AddPos(&v);
        s = self->def->spawn.scale << 4;
        e->SetScaleXYZ(s, s, s);
    }
    if (self->unk_44 != NULL) {
        self->unk_44->unk_0c.y = 0;
    }
    if (self->hit != NULL) {
        self->hit->unk_30 = self->def->sphereFlags;
        self->hit->offset.y = 0;
        self->hit->unk_9a_7 = 1;
    }
    if (self->def->billboard && self->model != NULL) {
        self->model->invV = 1;
    }
    if (self->def->flags & 4) {
        self->unk_cc_2 = 1;
    }
}

}
