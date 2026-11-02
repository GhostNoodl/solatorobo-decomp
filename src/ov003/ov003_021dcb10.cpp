#include "types.h"
#include "ov003/ActorApi.h"
#include "Main/Sys/FieldState.h"
#include "ov003/Unit.h"
#include "ov003/ActEx.h"

extern "C" {

extern void *data_ov000_021ccd64;
extern void *func_0203db40(PauseNode *p);
extern void Model0218fe1c_UpdateAnim(Model0218fe1c *a, void *b);
extern void Heap_Free(void *p);
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);

void Ov003ActorBase_Animate(ActorEx *self) {
    if (self->model != NULL) {
        Model0218fe1c_UpdateAnim(self->model, func_0203db40(&self->pause));
    }
}

void Ov003ActorEx_State23(void) {

}

void Ov003ActorEx_State22(void) {

}

void Ov003ActorEx_State21(void) {

}

void Ov003ActorEx_State20(void) {

}

void Ov003ActorEx_StateHurt(void) {

}

void Ov003ActorEx_State0e(void) {

}

void Ov003ActorEx_StateMove(void) {

}

ActorEx *Ov003ActVt_021f7d4c_DtorDelete(ActorEx *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f7d4c_Dtor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

void Ov003ActVt_021f7fac_Init(ActorEx *self) {
    Ov003Unit *unit;
    ActorEx_InitActor(self);
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
extern void HitMesh_SetMtx(void *obj, MtxFx43 *m);
extern void HitMesh_SetScale(void *obj, s32 a);
extern void HitMesh_Unlink_0203f920(void *obj);
extern void Obj02197d80_LoadValue(ActorEx *self);
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *model, const char *name, s32 a, s32 b);
extern void *Model0218fe1c_SetAnimFrame(Model0218fe1c *model, s32 a);
extern void Model0218fe1c_ClearLoop(Model0218fe1c *model);
extern AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *model, s32 n);

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
    ActorEx_Start(self);
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
    Obj02197d80_LoadValue(self);
    switch (self->unk_18) {
    case 2:
        if (self->model != NULL) {
            Model0218fe1c_SetAnim(self->model, data_ov003_021f803c, 0x1000, 0);
        }
        self->unk_cc_0 = 0;
        if (self->hitMesh != NULL) {
            HitMesh_Unlink_0203f920(self->hitMesh);
        }
        Ov003Gate_ClearPart(self->unk_44);
        break;
    case 1:
        if (self->model != NULL) {
            Model0218fe1c_SetAnim(self->model, data_ov003_021f8041, 0x1000, 0);
        }
        break;
    case 0:
        if (self->model != NULL) {
            Model0218fe1c_SetAnim(self->model, data_ov003_021f8046, 0x1000, 0);
        }
        break;
    case 3:
        if (self->model != NULL) {
            Model0218fe1c_SetAnim(self->model, data_ov003_021f8046, 0x1000, 0);
            Model0218fe1c_SetAnim(self->model, data_ov003_021f804b, 0x1000, 0);
        }
        if (self->unk_1a != 1) {
            Ov003Gate_ClearPart(self->unk_44);
        }
        break;
    }
    if (self->model != NULL) {
        AnimCtrl *a;
        Model0218fe1c_SetAnimFrame(self->model, -1);
        {
            Model0218fe1c *m = self->model;
            m->evScript = NULL;
            m->evCursor = NULL;
        }
        Model0218fe1c_ClearLoop(self->model);
        a = Model0218fe1c_GetAnimCtrl(self->model, 2);
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
