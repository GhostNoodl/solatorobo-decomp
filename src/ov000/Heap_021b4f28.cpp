#include "ov000/HeapScope.h"
#include "Main/Sys/FieldState.h"
#include "ov000/FieldMgr.h"

typedef struct {
    u8 pad_00[8];
    void *unk_08;
} Info021b4f28;

extern "C" {

Info021b4f28 *Lang_GetGroup(u32 id);
void LangData_MakeBlockPath(char *buf, u8 *src);
void ResMgr_ReleaseArchive(void *a, void *b, s32 c);
void *FieldProp_Release(FieldProp *node);
void HitMesh_Detach(void *obj);
void LangData_UnloadWorldInfo(void);

static inline void FieldMgr_Delete(FieldMgr *o) {
    FieldProp *node;
    if (o->blockB != NULL) {
        FieldState *g = gSceneCmd;
        Info021b4f28 *info = Lang_GetGroup(g->unk_ca.c[0]);
        char buf[0x20];
        LangData_MakeBlockPath(buf, &g->unk_ca.c[0]);
        ResMgr_ReleaseArchive(info->unk_08, buf, 0);
        {
            FieldCam *sub = &gSceneCmd->cam;
            sub->zones = NULL;
            sub->zoneCount = 0;
        }
        o->blockB = NULL;
    }
    o->exits = NULL;
    FieldMgr_LoadBlockArchives(o, 1);
    while ((node = o->head) != NULL) {
        FieldProp *prev = node->prev;
        FieldProp *next = node->next;
        if (node != NULL) {
            FieldProp_Release(node);
            Heap_Free(node);
        }
        if (prev != NULL) {
            prev->next = next;
        } else {
            o->head = next;
        }
        if (next != NULL) {
            next->prev = prev;
        } else {
            o->tail = prev;
        }
    }
    HitMesh_Detach(o->hitMesh);
    Heap_Free(o);
}

void FieldMgr_Destroy(void) {
    FieldMgr *p;
    void *saved;
    saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    p = gFieldMgr;
    if (p != NULL) {
        if (p != NULL) {
            FieldMgr_Delete(p);
        }
        gFieldMgr = NULL;
    }
    gSysState->cur = saved;
    LangData_UnloadWorldInfo();
}

}
