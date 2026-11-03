#include "types.h"
#include "Main/Sys/FieldState.h"
#include "ov000/FieldMgr.h"

extern "C" {

void PauseNode_Init(PauseNode *node);
void HitMesh_Init(void *p);

FieldMgr *func_ov000_021b5054(FieldMgr *self) {
    s32 i;

    PauseNode_Init(&self->pause);
    HitMesh_Init(self->hitMesh);
    if (gSceneCmd != NULL) {
        self->pause.parent = (PauseNode *)gSceneCmd->pause;
    }
    self->state = 0;
    self->unk_0c = NULL;
    self->blockA = NULL;
    self->blockB = NULL;
    self->exits = NULL;
    self->head = NULL;
    self->tail = NULL;
    self->curExit = 0xff;
    self->destExit = 0xff;
    self->exit = 0xff;
    for (i = 0; i < 0x20; i++) {
        self->ids[i] = 0xffff;
        self->vecs[i].x = 0;
        self->vecs[i].y = 0;
        self->vecs[i].z = 0;
    }
    self->unk_1f0 = 0xffff;
    self->step = NULL;
    self->unk_1f2 = 0;
    return self;
}

}
