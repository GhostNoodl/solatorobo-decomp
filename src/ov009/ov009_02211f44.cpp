#include "ov009/ov009.h"

extern "C" {

extern void NNS_G3dGetCurrentMtx(void *p, s32 a);

void func_ov009_02211f44(Ov009Actor *self) {
    u8 *p = FLD(u8 *, self->unk_04, 0x2c);
    s32 v;
    if (p == NULL) {
        return;
    }
    if (self->unk_08 & 0x10) {
        v = self->unk_ae;
    } else {
        v = -1;
    }
    if (v == FLD(s32, p, 0)) {
        NNS_G3dGetCurrentMtx(p + 4, 0);
    }
}

void func_ov009_02211f84(Ov009Actor *self) {
    FLD(void *, self, 0x24) = (void *)func_ov009_02211f44;
    self->unk_92 = 3;
}

extern char data_ov009_022179c0[];
extern char data_ov009_022179c7[];
extern char data_ov009_022179d1[];
extern char data_ov009_022179d8[];
extern s32 func_ov000_021909a8(Ov009Sub38 *m, const char *a, const char *b);
extern void NNS_G3dRenderObjSetInitFunc(void *p, void *cb);
extern void func_0203f2b8(void *p);
extern u8 *func_0206fef8(void *res);
extern void HitMesh_Init(void *p);
extern void HitMesh_SetRes(void *p, s32 v);
extern void HitMesh_SetScale(void *p, s32 v);
extern void HitMesh_SetMtx(void *mesh, const void *mtx);
extern void HitMesh_Link(void *p);
extern u8 *Group_FindNode(void *mgr, u16 id);
extern void func_ov000_0218b700(u8 *p, s32 a, s32 b);
struct Ov009Mtx43b {
    s32 m[9];
    Ov009Vec t;
};

struct Ov009Bit8 {
    u8 b0 : 1;
    u8 b1 : 7;
};

void func_ov009_02211f9c(Ov009ActSpin *self) {
    Ov009Sub38 *m;
    u8 *c;
    u32 *o;
    u32 v;
    void *saved;
    u8 *p;
    func_ov003_021d112c(self);
    switch (self->kind) {
    case 0x504f:
        self->unk_f4 = func_ov000_021909a8(self->unk_38, data_ov009_022179c0, data_ov009_022179c7);
        break;
    case 0x5050:
        self->unk_f4 = func_ov000_021909a8(self->unk_38, data_ov009_022179d1, data_ov009_022179d8);
        break;
    }
    MTX_Identity43_((MtxFx43 *)(&self->unk_f8));
    m = self->unk_38;
    NNS_G3dRenderObjSetInitFunc(m->unk_24, (void *)func_ov009_02211f84);
    m->unk_c2_5 = 0;
    self->unk_38->unk_c2_8 = 1;
    self->unk_38->unk_50 = &self->unk_f4;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_48 != NULL) {
        Ov009Sub48 *d = self->unk_48;
        if (d != NULL) {
            func_0203f2b8(d);
            Heap_Free(d);
        }
        self->unk_48 = NULL;
    }
    data_02097dd0->cur = saved;
    c = func_0206fef8((void *)self->kind);
    o = FLD(u32 *, self->unk_34, 0x84);
    v = o != NULL ? *o : 0;
    if (v != 0) {
        void *q = Heap_Alloc(0x98);
        if (q != NULL) {
            HitMesh_Init(q);
        }
        self->unk_58 = q;
        o = FLD(u32 *, self->unk_34, 0x84);
        HitMesh_SetRes(self->unk_58, o != NULL ? *o : 0);
        HitMesh_SetScale(self->unk_58, FLD(s16, c, 0x10));
        {
            void *obj;
            Ov009Mtx43b t;
            Ov009Mtx43b mt;
            u16 rx;
            u16 ry;
            u16 rz;
            BOOL set = FALSE;
            rz = self->rot[2];
            obj = self->unk_58;
            ry = self->rot[1];
            rx = self->rot[0];
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
        HitMesh_Link(self->unk_58);
    }
    p = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        ((Ov009Bit8 *)(p + 0xa2))->b0 = 0;
        func_ov000_0218b700(p, 0x3000, 0);
    }
    self->unk_b6 = 0x1e;
    self->unk_ea_0 = 0;
    self->unk_134.x = self->pos.x;
    self->unk_134.y = self->pos.y;
    self->unk_134.z = self->pos.z;
    self->unk_f2 = 0;
}

}
