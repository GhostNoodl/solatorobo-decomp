#include "ov000/VObj.h"
#include "Main/Sys/SysState.h"
#include "Main/Res/ResMgr.h"
#include "ov000/FieldMgr.h"

extern "C" {

void func_0203f920(void *p);
void HitMesh_Detach(void *p);
void Heap_Free(void *p);
void func_0203f0b4(void *p);
FieldPropModel *func_ov000_021b700c(FieldPropModel *p);
void func_02036838(void *mgr, const char *name, s32 type, s32 force);

FieldPropModel *func_ov000_021b6f94(FieldPropModel *p);

FieldProp *func_ov000_021b79f4(FieldProp *self) {
    self->loader.path = NULL;
    self->loader.name = NULL;
    self->loader.state = -1;
    self->loader.flags = 0;
    self->loader.mdl = NULL;
    self->loader.tex = NULL;
    self->loader.anm = NULL;
    self->loader.hit = NULL;
    func_ov000_021b6f94(&self->model);
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

FieldProp *func_ov000_021b7a7c(FieldProp *self) {
    if (self->hitMesh != NULL) {
        void *saved;
        void *p;
        func_0203f920(self->hitMesh);
        saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->heapHi;
        p = self->hitMesh;
        if (p != NULL) {
            if (p != NULL) {
                HitMesh_Detach(p);
                Heap_Free(p);
            }
            self->hitMesh = NULL;
        }
        data_02097dd0->cur = saved;
    }
    func_ov000_021b700c(&self->model);
    if (self->loader.mdl != NULL) {
        func_0203f0b4(*self->loader.mdl);
    }
    if (self->loader.tex != NULL) {
        func_0203f0b4(*self->loader.tex);
    }
    if (self->loader.flag0 && self->loader.flag1) {
        func_02036838(data_02097cdc, self->loader.path, 7, 0);
    }
    return self;
}

}
