#include "types.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Sys/FieldState.h"
#include "ov000/FieldMgr.h"

typedef struct {
    u8 pad[8];
    void *unk_08;
} Ent021b53f4;

extern "C" {
void Gfx3DState_SetDefaults(void *p);
void Gfx3DState_Apply(void *p);
void GfxCamParam_Init(s32 *proj);
void *FieldProp_Release(FieldProp *n);
void Heap_Free(void *p);
Ent021b53f4 *Lang_GetGroup(u8 id);
void LangData_MakeBlockPath(char *buf, u8 *ids);
void ResMgr_ReleaseArchive(void *a, char *buf, s32 c);

void func_ov000_021b53f4(FieldMgr *self) {
    FieldState *pb;
    FieldProp *prev;
    FieldProp *next;
    FieldProp *n;
    GfxSys *d48 = gGfxSys;
    Gfx3DState_SetDefaults(d48->unk_8b0);
    Gfx3DState_Apply(d48->unk_8b0);
    pb = gSceneCmd;
    GfxCamParam_Init(&pb->cam.base.nearClip);
    pb->cam.base.wallClip = 0;
    pb->cam.unk_da = 0;
    pb->cam.timer = 0;
    if (self->exits != NULL && self->exit != 0xff) {
        func_ov000_021b65ec(self);
    }
    while ((n = self->head) != NULL) {
        prev = n->prev;
        next = n->next;
        if (n != NULL) {
            FieldProp_Release(n);
            Heap_Free(n);
        }
        if (prev != NULL) {
            prev->next = next;
        } else {
            self->head = next;
        }
        if (next != NULL) {
            next->prev = prev;
        } else {
            self->tail = prev;
        }
    }
    if (self->blockB != NULL) {
        FieldState *p = gSceneCmd;
        u8 *ids = p->unk_d0.c;
        Ent021b53f4 *e;
        char buf[0x20];
        if (ids[0] == 0xff || ids[1] == 0xff || ids[2] == 0xff) {
            ids = p->unk_ca.c;
        }
        e = Lang_GetGroup(ids[0]);
        LangData_MakeBlockPath(buf, ids);
        ResMgr_ReleaseArchive(e->unk_08, buf, 0);
        {
            FieldCam *sub = &gSceneCmd->cam;
            sub->zones = NULL;
            sub->zoneCount = 0;
        }
        self->blockB = NULL;
    }
    self->exits = NULL;
    {
        FieldState *p = gSceneCmd;
        if (p->unk_ca.c[0] != p->unk_d0.c[0] || p->unk_ca.c[1] != p->unk_d0.c[1] || p->unk_c9 != 0) {
            FieldMgr_LoadBlockArchives(self, 0);
        }
    }
    self->unk_1f2 = 0;
    self->state = 0;
}

}
