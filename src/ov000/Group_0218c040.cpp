#include "ov000/LoCommon.h"
#include "ov000/ActorMgr.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ActorBase.h"
#include "ov000/Vec.h"
#include "ov000/Group.h"

extern "C" {
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);

static inline Actor *FindActor0218c040(u16 id) {
    ActorMgr *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(mgr, id);
}

static inline BOOL IsHere0218c040(GroupNode *e) {
    FieldState *g = data_ov000_021ccd54;
    BOOL ret = FALSE;
    if (g->unk_ca.c[0] == e->fieldId.c[0] && g->unk_ca.c[1] == e->fieldId.c[1] && g->unk_ca.c[2] == e->fieldId.c[2]) {
        ret = TRUE;
    }
    return ret;
}

// Collects up to max positions of the group's nodes in the current field: their actors (or the
// recorded position of an actor that is gone), or the node's own position before it spawned.
s32 func_ov000_0218c040(Group *list, s32 max, VecFx32 *out, s32 kind, u16 id) {
    s32 n = 0;
    GroupNode *e;
    s32 i;

    for (e = list->head; e != NULL; e = e->next) {
        if (!IsHere0218c040(e)) {
            continue;
        }
        if (kind != 0 && kind != (e->spawn.group >> 12)) {
            continue;
        }
        if (id != 0xffff && e->spawn.kind != id) {
            continue;
        }
        if (e->count != 0) {
            for (i = 0; i < e->count; i++) {
                Actor *a = FindActor0218c040(e->entries[i].actor);
                if (a != NULL) {
                    if (id == 0xffff || id == a->kind) {
                        out[n].x = a->pos.x;
                        out[n].y = a->pos.y;
                        out[n].z = a->pos.z;
                        n++;
                    }
                } else if (e->entries[i].actor != 0xffff && (id == 0xffff || id == e->entries[i].kind)) {
                    out[n].x = e->entries[i].pos.x;
                    out[n].y = e->entries[i].pos.y;
                    out[n].z = e->entries[i].pos.z;
                    n++;
                }
                if (n >= max) {
                    break;
                }
            }
        } else {
            out[n].x = e->pos.x;
            out[n].y = e->pos.y;
            out[n].z = e->pos.z;
            n++;
        }
        if (n >= max) {
            break;
        }
    }
    return n;
}
}
