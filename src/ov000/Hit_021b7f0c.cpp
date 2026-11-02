#include "ov000/LoCommon.h"
#include "ov000/Vec.h"
#include "nitro/mi.h"
#include "ov000/FieldMgr.h"

typedef struct {
    s32 m[9];
    VecFx32 t;
} Mtx021b7f0c;

extern "C" {
void HitMesh_Init(void *mesh);
void HitMesh_Link(void *mesh);
void HitMesh_SetRes(void *mesh, void *res);
void HitMesh_SetScale(void *mesh, int scale);
void HitMesh_SetMtx(void *mesh, const void *mtx);
BOOL func_ov000_021b6d28(FieldPropLoader *p);
void func_ov000_021b70c0(FieldPropModel *a, FieldPropLoader *b, s32 c, u8 d, s32 e, s32 f);

BOOL func_ov000_021b7f0c(FieldProp *self) {
    BOOL ok = TRUE;
    if (self->loader.state >= 0) {
        if (!func_ov000_021b6d28(&self->loader)) {
            ok = FALSE;
        } else {
            s32 a = 0;
            s32 m;
            if (!self->fade && !self->lod) {
                a = ok;
            }
            m = 0;
            if (self->lod) {
                m = 2;
            }
            func_ov000_021b70c0(&self->model, &self->loader, self->unk_f0, self->unk_f4, a, m);
            if (self->loader.hit != NULL) {
                Mtx021b7f0c mtx;
                void *mesh;
                s32 scale;
                MI_Copy36B(&self->model.rot, mtx.m);
                { s32 x = self->model.trans.x; s32 y = self->model.trans.y; s32 z = self->model.trans.z; mtx.t.x = x; mtx.t.y = y; mtx.t.z = z; }
                scale = self->model.scale.x;
                mesh = Heap_Alloc(0x98);
                if (mesh != NULL) {
                    HitMesh_Init(mesh);
                }
                self->hitMesh = mesh;
                HitMesh_SetRes(mesh, *self->loader.hit);
                HitMesh_SetMtx(self->hitMesh, &mtx);
                HitMesh_SetScale(self->hitMesh, scale);
                HitMesh_Link(self->hitMesh);
            }
        }
    }
    return ok;
}
}
