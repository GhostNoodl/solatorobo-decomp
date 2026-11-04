#include "ov000/VObj.h"
#include "Main/Sys/SysState.h"
#include "Main/Res/ResMgr.h"
#include "ov000/FieldMgr.h"

extern "C" {

void HitMesh_Unlink_0203f920(void *p);
void HitMesh_Detach(void *p);
void Heap_Free(void *p);
void Vram_FreeRes(void *p);
FieldPropModel *FieldPropModel_Dtor(FieldPropModel *p);
void ResMgr_ReleaseByName(void *mgr, const char *name, s32 type, s32 force);

FieldPropModel *FieldPropModel_Ctor(FieldPropModel *p);

FieldProp *FieldProp_Ctor(FieldProp *self) {
    self->loader.path = NULL;
    self->loader.name = NULL;
    self->loader.state = -1;
    self->loader.flags = 0;
    self->loader.mdl = NULL;
    self->loader.tex = NULL;
    self->loader.anm = NULL;
    self->loader.hit = NULL;
    FieldPropModel_Ctor(&self->model);
    self->prev = NULL;
    self->next = NULL;
    self->hitMesh = NULL;
    self->unk_f0 = 0;
    self->unk_f4 = 0;
    self->state = 0;
    self->unk_f6 = 0;
    self->viewScale = 0;
    self->viewMin.x = -0xc3000;
    self->viewMin.y = -0x4e000;
    self->viewMin.z = -0xc3000;
    self->viewMax.x = 0xc3000;
    self->viewMax.y = 0x4e000;
    self->viewMax.z = 0xc3000;
    return self;
}

FieldProp *FieldProp_Release(FieldProp *self) {
    if (self->hitMesh != NULL) {
        void *saved;
        void *p;
        HitMesh_Unlink_0203f920(self->hitMesh);
        saved = gSysState->cur;
        gSysState->cur = gSysState->heapHi;
        p = self->hitMesh;
        if (p != NULL) {
            if (p != NULL) {
                HitMesh_Detach(p);
                Heap_Free(p);
            }
            self->hitMesh = NULL;
        }
        gSysState->cur = saved;
    }
    FieldPropModel_Dtor(&self->model);
    if (self->loader.mdl != NULL) {
        Vram_FreeRes(*self->loader.mdl);
    }
    if (self->loader.tex != NULL) {
        Vram_FreeRes(*self->loader.tex);
    }
    if (self->loader.flag0 && self->loader.flag1) {
        ResMgr_ReleaseByName(gResMgr, self->loader.path, 7, 0);
    }
    return self;
}

}
