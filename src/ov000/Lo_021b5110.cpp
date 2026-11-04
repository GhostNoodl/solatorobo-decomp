#include "types.h"
#include "ov000/ObjLayouts.h"
#include "ov000/Vec.h"
#include "Main/Sys/FieldState.h"
#include "ov000/FieldMgr.h"

typedef struct {
    u16 x, y, z;
} Rot021b5110;

extern "C" {

extern void *data_02149efc;
extern void *gSndMgr;
BOOL PauseNode_IsUpdatePaused(PauseNode *node, s32 a);
s32 FieldProp_Update(FieldProp *n);
Robo021ca458 *ActorMgr_FindPlayer(void);
BOOL Actor_IsDead(Robo021ca458 *pl);
BOOL Hit_PointInRotBox(VecFx32 *a, FieldExit *item, VecFx32 *min, VecFx32 *max, Rot021b5110 *rot);
void *SndMgr_PlayVolume(void *mgr, s32 id, s32 a, s32 b, s32 c);
void SceneCmd_Push09(FieldId *c, s32 a);

static inline void SetRot(Rot021b5110 *r, u16 x, u16 y, u16 z) {
    r->x = x;
    r->y = y;
    r->z = z;
}

static inline BOOL QueueBusy(void) {
    FieldState *g = gSceneCmd;
    s32 t = g->tail;
    return g->head != t;
}

static inline void Push(s32 cmd, s32 arg) {
    FieldState *g = gSceneCmd;
    g->queue[g->tail] = cmd;
    g->queueArg[g->tail] = arg;
    if (++g->tail >= 0x10) {
        g->tail = 0;
    }
}

void FieldMgr_Update(FieldMgr *self) {
    FieldProp *n;
    Robo021ca458 *pl;
    FieldExit *item;
    u8 i;
    u8 hit;
    if (PauseNode_IsUpdatePaused(&self->pause, 1)) {
        return;
    }
    for (n = self->head; n != NULL; n = n->next) {
        FieldProp_Update(n);
    }
    if (*(void **)&self->step != NULL) {
        (self->*self->step)();
    }
    pl = ActorMgr_FindPlayer();
    if (pl == NULL || pl->mode == 3) {
        return;
    }
    if (Actor_IsDead(pl)) {
        return;
    }
    if (self->blockB == NULL) {
        return;
    }
    if (self->destExit != 0xff || self->exit != 0xff) {
        return;
    }
    item = self->exits;
    hit = 0xff;
    for (i = 0; i < self->blockB->count0; i++, item++) {
        VecFx32 max;
        VecFx32 min;
        Rot021b5110 rot;
        max.x = item->hx << 4;
        max.y = item->hy << 4;
        max.z = item->hz << 4;
        min.x = -max.x;
        min.y = -max.y;
        min.z = -max.z;
        SetRot(&rot, 0, item->rot, 0);
        if (Hit_PointInRotBox(&self->playerPos, item, &min, &max, &rot)) {
            hit = i;
            if (self->curExit == i) {
                break;
            }
            self->exit = i;
            self->destExit = item->destExit;
            if (self->destExit == 0xff) {
                BOOL busy = FALSE;
                if (data_02149efc != NULL) {
                    busy = TRUE;
                }
                if (busy || QueueBusy()) {
                    SndMgr_PlayVolume(gSndMgr, 0x20, -1, -1, -1);
                } else {
                    Push(0x1d, 0);
                }
            } else {
                FieldId c;
                FieldState *gm = gSceneCmd;
                u8 r = item->dest.c[0];
                u8 g = item->dest.c[1];
                u8 b = item->dest.c[2];
                if (r == 0xff) r = gm->unk_ca.c[0];
                if (g == 0xff) g = gm->unk_ca.c[1];
                if (b == 0xff) b = gm->unk_ca.c[2];
                c.c[0] = r;
                c.c[1] = g;
                c.c[2] = b;
                SceneCmd_Push09(&c, 1);
            }
            break;
        }
    }
    if (hit == 0xff) {
        self->curExit = 0xff;
    }
}
}
