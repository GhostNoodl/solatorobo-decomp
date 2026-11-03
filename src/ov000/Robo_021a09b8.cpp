#include "ov000/LoCommon.h"
#include "ov000/ActorMgr.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"

extern "C" {
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
s32 History_PickFlagged(void *s, s32 *list, s32 count, BOOL push);
BOOL History_SetState(void *s, s32 a, s32 b);
void Shared_SetEventActor(u16 a, u16 b);
void func_020627dc(u16 a);
void func_ov000_02182590(void *p);
BOOL StageRes_HasQueued(void);
void StageRes_Push207(s32 a, s32 b);

static inline Actor *FindActor021a09b8(u16 id) {
    ActorMgr *mgr = gActorMgr;
    if (mgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(mgr, id);
}

static inline void Ping021a09b8(void) {
    FieldState *g = gSceneCmd;
    g->stageFlags = 1;
    func_ov000_02182590((u8 *)g + 0xac);
}

s32 func_ov000_021a09b8(Robo021ca458 *self, s32 *list, s32 count) {
    Actor *a;
    u8 kind;
    s32 r;
    ActorSub4c *sub;
    BOOL done;

    a = NULL;
    r = History_PickFlagged(((void *)self->fsm), list, count, FALSE);
    if (r == 0) {
        return r;
    }
    a = FindActor021a09b8(self->target);
    sub = NULL;
    if (a != NULL) {
        sub = (ActorSub4c *)((u8 *)a->targetObj);
    }
    kind = 0;
    if (sub != NULL) {
        kind = sub->type;
    }
    done = FALSE;
    switch (r) {
    case 6:
        if (a == NULL || sub == NULL) {
            break;
        }
        if (kind != 4 && kind != 6 && kind != 0xc && kind != 0xd) {
            break;
        }
        if (sub->unk_18_1 && sub->unk_03 != 0xa && sub->unk_03 != 0xb) {
            Shared_SetEventActor(a->kind, a->id);
            func_020627dc(a->unk_18);
            Ping021a09b8();
            if (StageRes_HasQueued()) {
                done = TRUE;
            }
        }
        if (done) {
            r = 0;
        } else {
            switch (sub->type) {
            case 6:
                if (self->unk_b24_1) {
                    r = 0;
                    StageRes_Push207(0x64, 0);
                }
                break;
            case 0xc:
            case 0xd:
                if (!self->unk_b24_1) {
                    r = 0;
                    StageRes_Push207(0x65, 0);
                }
                break;
            }
        }
        break;
    case 7:
    case 0x18:
        if (a == NULL || sub == NULL) {
            break;
        }
        if (kind != 5 && kind != 0xe && kind != 0xf && kind != 0x11 && kind != 0x13 && kind != 0x12 && kind != 0x14) {
            break;
        }
        if (sub->unk_18_1) {
            Shared_SetEventActor(a->kind, a->id);
            func_020627dc(a->unk_18);
            Ping021a09b8();
            if (StageRes_HasQueued()) {
                done = TRUE;
            }
        }
        if (done) {
            r = 0;
            self->unk_b2c_4 = 0;
        } else if (!self->unk_b24_1) {
            r = 0;
            StageRes_Push207(0x65, 0);
        }
        break;
    case 8:
    case 0x1e:
        if (a == NULL || sub == NULL) {
            break;
        }
        if (sub->unk_18_1 && sub->unk_03 != 0xa && sub->unk_03 != 0xb) {
            Shared_SetEventActor(a->kind, a->id);
            func_020627dc(a->unk_18);
            Ping021a09b8();
            if (StageRes_HasQueued()) {
                done = TRUE;
            }
        }
        if (done) {
            r = 0;
        } else if (self->unk_b24_1) {
            r = 0;
            StageRes_Push207(0x64, 0);
        }
        break;
    case 0x10:
        if (a == NULL) {
            break;
        }
        Shared_SetEventActor(a->kind, a->id);
        Ping021a09b8();
        if (StageRes_HasQueued()) {
            r = 0;
        }
        break;
    case 0x1d:
        Shared_SetEventActor(a->kind, a->id);
        Ping021a09b8();
        if (StageRes_HasQueued()) {
            r = 0;
        } else {
            switch (sub->type) {
            case 8:
                if (self->unk_b24_1) {
                    StageRes_Push207(0x64, 0);
                    r = 0;
                }
                break;
            case 0x10:
                if (!self->unk_b24_1) {
                    StageRes_Push207(0x65, 0);
                    r = 0;
                }
                break;
            }
        }
        break;
    }
    if (r != 0) {
        History_SetState(((void *)self->fsm), (u8)r, 0);
    }
    return r;
}

}
