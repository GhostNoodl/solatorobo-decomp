#include "types.h"
#include "ov000/Vec.h"
#include "ov000/ActorParts.h"


typedef struct {
    VecFx32 pos;
    VecFx32 offset;
    u16 angle;
    u16 unk_1a;
    u32 unk_1c;
    u16 unk_20;
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
    u16 unk_22_2 : 14;
} Obj021984c8;
SIZE_ASSERT(Obj021984c8, 0x24);


typedef struct {
    VecFx32 unk_00;
    u8 unk_0c[0x20];
    u32 unk_2c;
} ColState;

extern ColState data_02fe0f14;

s32 Geom_SnapToGround(VecFx32 *pos, s32 height, s32 depth);

typedef struct {
    u8 unk_00[0x70];
    VecFx32 pos;
    u16 rot_x;
    u16 rot_y;
    u16 rot_z;
} ActorC;

typedef struct ActorMgr ActorMgr;

extern ActorMgr *data_ov000_021ccd68;

ActorC *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
void func_01ffc9fc(VecFx32 *out, const VecFx32 *in, u32 angle);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
void HitSphere_Init(ActorSub48 *self);
void HitSphere_Link(ActorSub48 *self);
void HitSphere_Unlink_0203f364(ActorSub48 *self);
void func_ov000_02198ad8(ActorSub48 *self, VecFx32 *pos, VecFx32 *offset);

static inline ActorC *FindActor(u16 id) {
    ActorMgr *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(mgr, id);
}

void ActorEx_State23(void) {
}

void ActorEx_State22(void) {
}

void ActorEx_State21(void) {
}

void ActorEx_State20(void) {
}

void ActorEx_StateHurt(void) {
}

void ActorEx_State0e(void) {
}

void ActorEx_StateMove(void) {
}

ActorSub40 *History_Init(ActorSub40 *self) {
    s32 i;
    self->st = 0;
    self->timer = 0;
    self->flags = 0;
    for (i = 0; i < HISTORY_LEN; i++) {
        self->history[i] = 0;
    }
    self->current = 1;
    return self;
}

static inline BOOL History_Push(ActorSub40 *self, u8 value, BOOL force) {
    s32 i;
    if (self->current == value && !force) {
        return FALSE;
    }
    for (i = HISTORY_LEN - 1; i > 0; i--) {
        self->history[i] = self->history[i - 1];
    }
    self->history[0] = self->current;
    self->st = 0;
    self->current = value;
    self->timer = 0;
    return TRUE;
}

BOOL History_SetState(ActorSub40 *self, u8 value, BOOL force) {
    return History_Push(self, value, force);
}

BOOL History_HasState(ActorSub40 *self, u8 value, s32 count, BOOL checkCurrent) {
    BOOL found = FALSE;
    s32 i;
    if (checkCurrent && self->current == value) {
        found = TRUE;
    } else {
        if (count > HISTORY_LEN) {
            count = HISTORY_LEN;
        }
        for (i = 0; i < count; i++) {
            if (value == self->history[i]) {
                found = TRUE;
                break;
            }
        }
    }
    return found;
}

s32 History_PickFlagged(ActorSub40 *self, s32 *list, s32 count, BOOL push) {
    s32 result = 0;
    s32 i;
    if (self->flags != 0) {
        for (i = 0; i < count; i++) {
            s32 bit = list[i];
            if (self->flags & ((u64)1 << bit)) {
                if (push) {
                    History_Push(self, bit, FALSE);
                }
                result = bit;
                break;
            }
        }
    }
    return result;
}

Obj021984c8 *Obj021984c8_Init(Obj021984c8 *self) {
    self->offset.x = 0;
    self->offset.y = 0;
    self->offset.z = 0;
    self->unk_1a = 0;
    self->unk_1c = 0;
    self->unk_20 = 0xffff;
    *(u16 *)((u8 *)self + 0x22) = 0;
    return self;
}

void Obj021984c8_UpdatePos(Obj021984c8 *self, VecFx32 *pos, u16 *rot) {
    VecFx32 base;
    VecFx32 ofs;
    ActorC *actor = FindActor(self->unk_20);
    u32 angle;

    if (actor == NULL) {
        return;
    }
    if (!self->unk_22_1) {
        return;
    }
    if (pos != NULL) {
        base.x = pos->x;
        base.y = pos->y;
        base.z = pos->z;
    } else {
        base.x = actor->pos.x;
        base.y = actor->pos.y;
        base.z = actor->pos.z;
    }
    angle = rot != NULL ? rot[1] : actor->rot_y;
    self->angle = angle + self->unk_1a;
    func_01ffc9fc(&ofs, &self->offset, angle);
    VEC_Add(&base, &ofs, &self->pos);
}

ActorC *Obj021984c8_GetActor(Obj021984c8 *self) {
    return FindActor(self->unk_20);
}

ActorSub48 *ActorSub48_Init(ActorSub48 *self) {
    HitSphere_Init(self);
    self->owner = 0xffff;
    self->unk_44 = 0;
    self->unk_48 = 0;
    self->unk_4c = 0xa000;
    self->offset.x = 0;
    self->offset.y = 0;
    self->offset.z = 0;
    *(u16 *)((u8 *)self + 0x9a) = 0;
    self->unk_30 = 0xc0000000;
    self->unk_34 = 0;
    HitSphere_Link(self);
    self->unk_50 = 0;
    self->unk_54 = 0;
    self->unk_58 = 0;
    return self;
}

void ActorSub48_UpdatePos(ActorSub48 *self, VecFx32 *pos, u16 *rot) {
    VecFx32 base;
    VecFx32 ofs;
    ActorC *actor = FindActor(self->owner);

    if (actor == NULL) {
        HitSphere_Unlink_0203f364(self);
        self->unk_50 = 0;
        self->unk_54 = 0;
        self->unk_58 = 0;
    } else {
        if (!self->unk_9a_3) {
            HitSphere_Unlink_0203f364(self);
        } else {
            HitSphere_Link(self);
        }
        if (!self->unk_9a_8) {
            if (self->unk_9a_4) {
                self->unk_50 = 0;
                self->unk_54 = 0;
                self->unk_58 = 0;
            }
            if (pos != NULL) {
                base.x = pos->x;
                base.y = pos->y;
                base.z = pos->z;
            } else {
                base.x = actor->pos.x;
                base.y = actor->pos.y;
                base.z = actor->pos.z;
            }
            func_01ffc9fc(&ofs, &self->offset, rot != NULL ? rot[1] : actor->rot_y);
            VEC_Add(&base, &ofs, &base);
            func_ov000_02198ad8(self, &base, &ofs);
            if (pos != NULL) {
                pos->x = base.x;
                pos->y = base.y;
                pos->z = base.z;
            } else {
                actor->pos.x = base.x;
                actor->pos.y = base.y;
                actor->pos.z = base.z;
            }
        }
    }
    self->unk_9a_8 = 0;
}
