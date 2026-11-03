#include "ov009/ov009.h"

extern "C" {


void Ov009Part_CaptureMtx_02211f44(Ov003Actor *self) {
    u8 *p = FLD(u8 *, self->prev, 0x2c);
    s32 v;
    if (p == NULL) {
        return;
    }
    // This method reads 0x04 as an owner and 0x08 as flag bits, not as Actor::prev/next.
    if ((u32)self->next & 0x10) {
        v = self->unk_ae;
    } else {
        v = -1;
    }
    if (v == FLD(s32, p, 0)) {
        NNS_G3dGetCurrentMtx((MtxFx43 *)(p + 4), NULL);
    }
}

void Ov009Part_StartCapture_02211f84(Ov003Actor *self) {
    FLD(void *, self, 0x24) = (void *)Ov009Part_CaptureMtx_02211f44;
    self->unk_92 = 3;
}

extern char data_ov009_022179c0[];
extern char data_ov009_022179c7[];
extern char data_ov009_022179d1[];
extern char data_ov009_022179d8[];
extern s32 Model_FindResIdxByName(Model0218fe1c *m, const char *a, const char *b);
extern void HitSphere_Unlink_0203f2b8(void *p);
extern u8 *Tbl_FindEntry_0206fef8(void *res);
extern void HitMesh_Init(void *p);
extern void HitMesh_SetRes(void *p, s32 v);
extern void HitMesh_SetScale(void *p, s32 v);
extern void HitMesh_SetMtx(void *mesh, const void *mtx);
extern void HitMesh_Link(void *p);
struct Ov009Mtx43b {
    s32 m[9];
    VecFx32 t;
};

void Ov009ActSpin_Start(Ov009ActSpin *self) {
    Model0218fe1c *m;
    u8 *c;
    u32 *o;
    u32 v;
    void *saved;
    GroupNode *p;
    Ov003Actor_Start(self);
    switch (self->kind) {
    case 0x504f:
        self->unk_f4 = Model_FindResIdxByName(self->model, data_ov009_022179c0, data_ov009_022179c7);
        break;
    case 0x5050:
        self->unk_f4 = Model_FindResIdxByName(self->model, data_ov009_022179d1, data_ov009_022179d8);
        break;
    }
    MTX_Identity43_((MtxFx43 *)(&self->unk_f8));
    m = self->model;
    NNS_G3dRenderObjSetInitFunc((NNSG3dRenderObj *)m->unk_24, (NNSG3dSbcCallBackFunc)Ov009Part_StartCapture_02211f84);
    m->clearInit = 0;
    self->model->flushVP = 1;
    self->model->renderUser = &self->unk_f4;
    saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (self->hit != NULL) {
        ActorSub48 *d = self->hit;
        if (d != NULL) {
            HitSphere_Unlink_0203f2b8(d);
            Heap_Free(d);
        }
        self->hit = NULL;
    }
    gSysState->cur = saved;
    c = Tbl_FindEntry_0206fef8((void *)self->kind);
    o = ((Ov009Names *)self->unk_34)->unk_84;
    v = o != NULL ? *o : 0;
    if (v != 0) {
        void *q = Heap_Alloc(0x98);
        if (q != NULL) {
            HitMesh_Init(q);
        }
        self->hitMesh = q;
        o = ((Ov009Names *)self->unk_34)->unk_84;
        HitMesh_SetRes(self->hitMesh, o != NULL ? *o : 0);
        HitMesh_SetScale(self->hitMesh, FLD(s16, c, 0x10));
        {
            void *obj;
            Ov009Mtx43b t;
            Ov009Mtx43b mt;
            u16 rx;
            u16 ry;
            u16 rz;
            BOOL set = FALSE;
            rz = self->rot_z;
            obj = self->hitMesh;
            ry = self->rot_y;
            rx = self->rot_x;
            MTX_Identity43_((MtxFx43 *)&mt);
            if (rz != 0) {
                MTX_RotZ43_((MtxFx43 *)&mt, OV009_SIN(rz), OV009_COS(rz));
                set = TRUE;
            }
            if (ry != 0) {
                if (set) {
                    MTX_RotY43_((MtxFx43 *)&t, OV009_SIN(ry), OV009_COS(ry));
                    MTX_Concat43((MtxFx43 *)&t, (MtxFx43 *)&mt, (MtxFx43 *)&mt);
                } else {
                    MTX_RotY43_((MtxFx43 *)&mt, OV009_SIN(ry), OV009_COS(ry));
                    set = TRUE;
                }
            }
            if (rx != 0) {
                if (set) {
                    MTX_RotX43_((MtxFx43 *)&t, OV009_SIN(rx), OV009_COS(rx));
                    MTX_Concat43((MtxFx43 *)&t, (MtxFx43 *)&mt, (MtxFx43 *)&mt);
                } else {
                    MTX_RotX43_((MtxFx43 *)&mt, OV009_SIN(rx), OV009_COS(rx));
                    set = TRUE;
                }
            }
            mt.t.x = self->pos.x;
            mt.t.y = self->pos.y;
            mt.t.z = self->pos.z;
            HitMesh_SetMtx(obj, &mt);
        }
        HitMesh_Link(self->hitMesh);
    }
    p = Group_FindNode(gGroup, self->unk_20);
    if (p != NULL) {
        p->flags.unk_0 = 0;
        GroupNode_SetSpawnRange(p, 0x3000, 0);
    }
    self->unk_b6 = 0x1e;
    self->unk_ea_0 = 0;
    self->unk_134.x = self->pos.x;
    self->unk_134.y = self->pos.y;
    self->unk_134.z = self->pos.z;
    self->unk_f2 = 0;
}

}
