#include "types.h"
#include "Main/Sys/FieldState.h"
#include "ov003/Unit.h"
#include "ov003/ActEx.h"

extern "C" {

extern void *data_ov000_021ccd64;
extern void *func_0203db40(PauseNode *p);
extern void func_ov000_02190a80(Model0218fe1c *a, void *b);
extern void Heap_Free(void *p);
extern void func_ov000_0219433c(ActorEx *self);
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);

void func_ov003_021dcb10(ActorEx *self) {
    if (self->model != NULL) {
        func_ov000_02190a80(self->model, func_0203db40(&self->pause));
    }
}

void func_ov003_021dcb3c(void) {

}

void func_ov003_021dcb40(void) {

}

void func_ov003_021dcb44(void) {

}

void func_ov003_021dcb48(void) {

}

void func_ov003_021dcb4c(void) {

}

void func_ov003_021dcb50(void) {

}

void func_ov003_021dcb54(void) {

}

ActorEx *Ov003ActVt_021f7d4c_DtorDelete(ActorEx *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f7d4c_Dtor(ActorEx *self) {
    func_ov000_0219429c(self);
    return self;
}

void Ov003ActVt_021f7fac_Init(ActorEx *self) {
    Ov003Unit *unit;
    func_ov000_0219433c(self);
    unit = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (unit != NULL) {
        unit->unk_a2_0 = 0;
    }
    self->unk_cc_3 = 0;
}

extern const s16 FX_SinCosTable_[];
extern char data_ov003_021f803c[];
extern char data_ov003_021f8041[];
extern char data_ov003_021f8046[];
extern char data_ov003_021f804b[];
extern void func_ov000_02194758(ActorEx *self);
extern void HitMesh_SetMtx(void *obj, MtxFx43 *m);
extern void HitMesh_SetScale(void *obj, s32 a);
extern void func_0203f920(void *obj);
extern void func_ov000_02197d80(ActorEx *self);
extern BOOL func_ov000_02190cb0(Model0218fe1c *model, const char *name, s32 a, s32 b);
extern void *func_ov000_02191318(Model0218fe1c *model, s32 a);
extern void func_ov000_02191618(Model0218fe1c *model);
extern AnimCtrl *func_ov000_02190a30(Model0218fe1c *model, s32 n);

#define OV003GT_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003GT_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

static inline void Ov003Gate_ClearPart(ActorSub44 *s) {
    if (s != NULL) {
        s->unk_22_0 = 0;
        s->unk_22_1 = 0;
    }
}

void Ov003ActVt_021f7fac_Start(ActorEx *self) {
    void *obj;
    func_ov000_02194758(self);
    obj = self->hitMesh;
    if (obj != NULL && (self->kind == 0x460b || self->kind == 0x4625)) {
        MtxFx43 t;
        MtxFx43 m;
        u16 rx;
        u16 ry;
        u16 rz;
        BOOL set = FALSE;
        ry = self->rot_y + 0x8000;
        rz = self->rot_z;
        rx = self->rot_x;
        MTX_Identity43_(&m);
        if (rz != 0) {
            MTX_RotZ43_(&m, OV003GT_SIN(rz), OV003GT_COS(rz));
            set = TRUE;
        }
        if (ry != 0) {
            if (set) {
                MTX_RotY43_(&t, OV003GT_SIN(ry), OV003GT_COS(ry));
                MTX_Concat43(&t, &m, &m);
            } else {
                MTX_RotY43_(&m, OV003GT_SIN(ry), OV003GT_COS(ry));
                set = TRUE;
            }
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX43_(&t, OV003GT_SIN(rx), OV003GT_COS(rx));
                MTX_Concat43(&t, &m, &m);
            } else {
                MTX_RotX43_(&m, OV003GT_SIN(rx), OV003GT_COS(rx));
                set = TRUE;
            }
        }
        m._30 = self->pos.x;
        m._31 = self->pos.y;
        m._32 = self->pos.z;
        HitMesh_SetMtx(obj, &m);
        if (data_ov000_021ccd54->unk_ca.c[0] == 9) {
            HitMesh_SetScale(self->hitMesh, 0x1b33);
        }
    }
    func_ov000_02197d80(self);
    switch (self->unk_18) {
    case 2:
        if (self->model != NULL) {
            func_ov000_02190cb0(self->model, data_ov003_021f803c, 0x1000, 0);
        }
        self->unk_cc_0 = 0;
        if (self->hitMesh != NULL) {
            func_0203f920(self->hitMesh);
        }
        Ov003Gate_ClearPart(self->unk_44);
        break;
    case 1:
        if (self->model != NULL) {
            func_ov000_02190cb0(self->model, data_ov003_021f8041, 0x1000, 0);
        }
        break;
    case 0:
        if (self->model != NULL) {
            func_ov000_02190cb0(self->model, data_ov003_021f8046, 0x1000, 0);
        }
        break;
    case 3:
        if (self->model != NULL) {
            func_ov000_02190cb0(self->model, data_ov003_021f8046, 0x1000, 0);
            func_ov000_02190cb0(self->model, data_ov003_021f804b, 0x1000, 0);
        }
        if (self->unk_1a != 1) {
            Ov003Gate_ClearPart(self->unk_44);
        }
        break;
    }
    if (self->model != NULL) {
        AnimCtrl *a;
        func_ov000_02191318(self->model, -1);
        {
            Model0218fe1c *m = self->model;
            m->evScript = NULL;
            m->evCursor = NULL;
        }
        func_ov000_02191618(self->model);
        a = func_ov000_02190a30(self->model, 2);
        if (a != NULL) {
            a->loop = 1;
        }
        if (self->param->unk_01 == 1) {
            self->model->boxTest = 0;
        }
    }
    self->fsm->st = 0;
    self->unk_93_1 = (u8)(u16)self->unk_18;
    self->unk_ce = 2;
}

} // extern "C"
