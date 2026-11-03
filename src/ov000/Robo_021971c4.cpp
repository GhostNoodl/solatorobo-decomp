#include "nitro/fx.h"
#include "ov000/ActorMgr.h"
#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"


typedef struct {
    u8 unk_00[0x158];
    u32 flags[1][4];
} Save021971c4;

extern "C" {
extern char data_ov000_021cc469[];
extern void *gGroup;
extern Save021971c4 *gStageFlags;
void *Target_Get(void *p);
BOOL Model0218fe1c_SetAnim(void *a, const char *b, s32 c, s32 d);
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
void Actor_SendMsgU8(void *o, u16 id, s32 c);
void Target_Set(void *a, void *b);
BOOL Target_MatchesId(void *a, u16 id);
BOOL Model0218fe1c_IsAnimDone(void *a);
void Actor_SendMsg(Actor *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
u8 *Tbl_Elem_020704b4(u16 id);
void Drop_SpawnWeighted(u16 *ids, u8 *rates, s32 n, void *pos, void *rot, u8 check);
BOOL History_SetState(void *s, s32 a, s32 b);
u16 LangData_GetIndex(u32 a, u32 b);
void func_020627c8(void);
void Group_UpdateActor(void *a, s32 b, void *c);
u16 Target_LerpToDest(void *a, void *pos, s32 b, s32 c);

static inline Actor *FindActor021971c4(u16 id) {
    ActorMgr *mgr = gActorMgr;
    if (mgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(mgr, id);
}

static inline void SetNibble021971c4(s32 row, s32 idx, u32 value) {
    s32 sh = idx % 8;
    u32 *p;

    sh *= 4;
    p = &gStageFlags->flags[row][idx / 8];
    *p = (*p & ~(0xf << sh)) | ((value & 0xf) << sh);
}

static inline int GetNibble021971c4(s32 row, s32 idx) {
    u32 v = gStageFlags->flags[row][idx / 8];
    return (v >> ((idx % 8) * 4)) & 0xf;
}

void ActorEx_State06(VObj *obj) {
    ActorEx *self = (ActorEx *)obj;
    u32 none = 0xffff;
    s32 zero = 0;
    Actor *tgt = (Actor *)Target_Get(((u8 *)self->targetObj));
    switch (self->fsm->st) {
    case 0:
        if (self->model != NULL) {
            Model0218fe1c_SetAnim(self->model, data_ov000_021cc469, 0x1000, zero);
        }
        if (tgt != NULL) {
            if (self->target != none) {
                Actor *a;
                obj->vfunc_88();
                a = FindActor021971c4(self->target);
                if (a != NULL) {
                    Actor_SendMsgU8(a, self->id, 6);
                    a->target = none;
                    if (a->targetObj != NULL) {
                        Target_Set(((void *)a->targetObj), self);
                    }
                }
            } else if (Target_MatchesId(((u8 *)self->targetObj), tgt->kind)) {
                obj->vfunc_8c();
                self->targetObj->target = none;
            }
        }
        self->fsm->st++;
        break;
    case 1:
        if (self->model != NULL && !Model0218fe1c_IsAnimDone(self->model)) {
            break;
        }
        if (tgt != NULL) {
            Actor_SendMsg(tgt, self->id, 3, 1, zero, (const void *)zero);
        }
        if (self->targetObj->unk_01 == 8) {
            u8 *d = Tbl_Elem_020704b4(self->kind);
            Drop_SpawnWeighted((u16 *)(d + 0x20), d + 0x24, 2, &self->pos, (u8 *)self + 0x7c, zero);
        }
        if (self->target != none) {
            ActorSub4c *m = self->targetObj;
            if (m->unk_02 != 0 && m->unk_02 != 7) {
                m->target = none;
            } else {
                History_SetState(self->fsm, 9, 0);
            }
            self->target = none;
        } else {
            self->targetObj->target = none;
            History_SetState(self->fsm, 1, 0);
        }
        if (self->targetObj->unk_02 == 5) {
            u8 idx = self->unk_17;
            s32 row;
            if (idx != 0xff) {
                row = LangData_GetIndex(self->unk_ac, self->unk_ad);
                if (row != none) {
                    u8 val = 0xf;
                    val |= GetNibble021971c4(row, idx) & 8;
                    SetNibble021971c4(row, idx, val);
                }
            }
            func_020627c8();
            Group_UpdateActor(gGroup, 0, self);
            obj->vfunc_08();
        }
        break;
    }
    if (tgt != NULL && self->target != none) {
        Target_LerpToDest(((u8 *)self->targetObj), &self->pos, 0, 0);
        self->rot_x = tgt->rot_x;
        self->rot_y = tgt->rot_y;
        self->rot_z = tgt->rot_z;
    }
}

}
