#include "ov000/Actor.h"
#include "ov000/ObjLayouts.h"

#include "ov000/FieldMgr.h"

extern "C" {

extern ActorMgr *gActorMgr;
extern void *gDataRes;
Robo021ca458 *ActorMgr_FindPlayer(void);
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
void func_ov000_021b13cc(u8 *pl, s32 a);
void func_ov000_021b12c0(u8 *pl, s32 a);
u16 DataRes_ReadEntry(void *a, s32 b, s32 c, s32 d);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);

static inline Actor *FindActor021b65ec(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

static inline void PlSetPos021b65ec(Robo021ca458 *pl, const VecFx32 *pos, s16 rx, s16 ry, s16 rz) {
    pl->unk_75c = *pos;
    pl->unk_76c = rx;
    pl->unk_76e = ry;
    pl->unk_770 = rz;
}

static inline void PlSetCol021b65ec(Robo021ca458 *pl, u8 r, u8 g, u8 b) {
    pl->unk_772 = r;
    pl->unk_773 = g;
    pl->unk_774 = b;
}

static inline FieldId *PlCol021b65ec(Robo021ca458 *pl) {
    return &pl->fieldId;
}

static inline BOOL SameCol021b65ec(const FieldId *a, const FieldId *b) {
    BOOL r = FALSE;
    if (a->c[0] == b->c[0] && a->c[1] == b->c[1] && a->c[2] == b->c[2]) {
        r = TRUE;
    }
    return r;
}

void func_ov000_021b65ec(FieldMgr *self) {
    FieldState *g;
    Robo021ca458 *pl;
    FieldExit *item;
    // DECL-END
    pl = ActorMgr_FindPlayer();
    if (pl == NULL) {
        return;
    }
    item = &self->exits[self->exit];
    g = gSceneCmd;
    if (item->unk_1c_1 && pl->unk_b24_5) {
        Actor *a = FindActor021b65ec(pl->unk_b1c);
        if (a != NULL && a->targetObj != NULL) {
            a->targetObj->target = 0xffff;
        }
        pl->unk_b1c = 0xffff;
        pl->unk_b1e = 0xffff;
        pl->unk_b24_5 = 0;
        pl->unk_b24_7 = pl->unk_b24_9;
    }
    switch (item->type) {
    case 1:
        if (!pl->unk_b24_1) {
            return;
        }
        func_ov000_021b13cc((u8 *)pl, 0);
        pl->fieldId = g->unk_d0;
        {
            VecFx32 v;
            v.x = item->ox << 4;
            v.y = item->oy << 4;
            v.z = item->oz << 4;
            VEC_Add(&v, &item->pos, &v);
            PlSetPos021b65ec(pl, &v, 0, item->dir, 0);
        }
        break;
    case 2: {
        FieldId c;
        if (pl->unk_b24_1 ? TRUE : FALSE) {
            return;
        }
        c.c[0] = item->dest.c[0];
        c.c[1] = item->dest.c[1];
        c.c[2] = item->dest.c[2];
        if (c.c[0] == 0xff) {
            c.c[0] = g->unk_d0.c[0];
        }
        if (c.c[1] == 0xff) {
            c.c[1] = g->unk_d0.c[1];
        }
        if (c.c[2] == 0xff) {
            c.c[2] = g->unk_d0.c[2];
        }
        if (!SameCol021b65ec(&c, PlCol021b65ec(pl))) {
            return;
        }
        func_ov000_021b12c0((u8 *)pl, 0);
        break;
    }
    case 3: {
        FieldId c;
        if (DataRes_ReadEntry(gDataRes, 5, 1, 0) != 1) {
            return;
        }
        if (pl->unk_b24_1 ? TRUE : FALSE) {
            return;
        }
        func_ov000_021b12c0((u8 *)pl, 0);
        c.c[0] = item->dest.c[0];
        if (c.c[0] == 0xff) {
            c.c[0] = g->unk_d0.c[0];
        }
        c.c[1] = item->dest.c[1];
        if (c.c[1] == 0xff) {
            c.c[1] = g->unk_d0.c[1];
        }
        c.c[2] = item->dest.c[2];
        if (c.c[2] == 0xff) {
            c.c[2] = g->unk_d0.c[2];
        }
        pl->fieldId = c;
        break;
    }
    }
}

}
