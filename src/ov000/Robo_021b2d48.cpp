#include "ov000/LoCommon.h"
#include "ov000/ActorMgr.h"
#include "ov000/ObjLayouts.h"

extern "C" {
extern void *gSndMgr;
void *Actor_GetTargetSub44(Actor *self);
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
void *Target_GetKindMask(void *p);
void *func_ov000_021b2f08(Robo021ca458 *self, void *a, void *b, BOOL c);
void *SndMgr_PlayVolume(void *p, s32 id, s32 a, s32 b, s32 c);
void *Obj021984c8_GetActor(void *p);
BOOL Model0218fe1c_GetAnimCtrl(void *p, s32 a);
void func_ov000_021b3bd8(void *self);
void func_ov000_021b3738(Robo021ca458 *self, void *t);

static inline Actor *FindActor021b2d48(u16 id) {
    ActorMgr *mgr = gActorMgr;
    if (mgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(mgr, id);
}

void func_ov000_021b2d48(Robo021ca458 *self) {
    u8 *res = NULL;
    BOOL flag = FALSE;
    Model0218fe1c *tgt = NULL;
    u8 *sub = NULL;
    BOOL search = FALSE;

    if (self->unk_b2f != 0) {
        self->unk_b2f--;
        res = (u8 *)Actor_GetTargetSub44(self);
    } else if ((self->hit->unk_54 & 0x400) || self->unk_b22_0 > 1) {
        self->unk_b2f = 0;
    } else {
        Actor *a = FindActor021b2d48(self->unk_b1c);
        if (a != NULL && (sub = ((u8 *)a->targetObj)) != NULL) {
            if (sub[1] == 6) {
                tgt = (Model0218fe1c *)Target_GetKindMask(sub);
            } else if (sub[1] == 1 || sub[1] == 5) {
                flag = TRUE;
            }
        }
        if (sub == NULL || tgt != NULL || flag) {
            search = TRUE;
        }
    }
    if (search) {
        res = (u8 *)func_ov000_021b2f08(self, tgt, sub, flag);
    }
    if (res != NULL) {
        if (self->target != LFLD(u16, res, 0x20)) {
            SndMgr_PlayVolume(gSndMgr, 0x22, -1, -1, -1);
            self->target = LFLD(u16, res, 0x20);
        }
        if ((LFLD(u16, res, 0x20) >> 12) == 4) {
            u8 *t = (u8 *)Obj021984c8_GetActor(res);
            if (t != NULL && (tgt = (Model0218fe1c *)LFLD(u8 *, t, 0x38)) != NULL) {
                flag = TRUE;
                if (!Model0218fe1c_GetAnimCtrl(tgt, 1)) {
                    tgt->color = 0x73ff;
                    tgt->color2 = 0x73ff;
                    tgt->blend = 2;
                    tgt->blendMax = 1;
                }
            }
        }
    } else {
        self->target = 0xffff;
    }
    func_ov000_021b3bd8(self);
    func_ov000_021b3738(self, res);
}
}
