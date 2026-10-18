#include "types.h"
#include "ov000/Vec.h"

#define HISTORY_LEN 7

typedef struct {
    u16 unk_00;
    u16 unk_02;
    u64 mask;
    u8 history[HISTORY_LEN];
    u8 current;
} History;

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

typedef struct {
    VecFx32 pos;
    VecFx32 prev;
    VecFx32 unk_18;
    u8 unk_24;
    u8 unk_25;
    u8 unk_26[0xa];
    u32 unk_30;
    u32 unk_34;
    s32 unk_38;
    u8 unk_3c[0x8];
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
    VecFx32 offset;
    VecFx32 check;
    u8 unk_74[0x24];
    u16 unk_98;
    u16 unk_9a_0 : 3;
    u16 unk_9a_3 : 1;
    u16 unk_9a_4 : 1;
    u16 unk_9a_5 : 1;
    u16 unk_9a_6 : 1;
    u16 unk_9a_7 : 1;
    u16 unk_9a_8 : 1;
    u16 unk_9a_9 : 1;
    u16 unk_9a_10 : 6;
} Obj021985e8;

typedef struct {
    VecFx32 unk_00;
    u8 unk_0c[0x20];
    u32 unk_2c;
} ColState;

extern ColState data_02fe0f14;

s32 func_ov000_0219a2f4(VecFx32 *pos, s32 height, s32 depth);

typedef struct {
    u8 unk_00[0x70];
    VecFx32 pos;
    u16 rot_x;
    u16 rot_y;
    u16 rot_z;
} ActorC;

typedef struct ActorMgr ActorMgr;

extern ActorMgr *data_ov000_021ccd68;

ActorC *func_ov000_0218e640(ActorMgr *mgr, u16 id);
void func_01ffc9fc(VecFx32 *out, const VecFx32 *in, u32 angle);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
void func_0203f260(Obj021985e8 *self);
void func_0203f324(Obj021985e8 *self);
void func_0203f364(Obj021985e8 *self);
void func_ov000_02198ad8(Obj021985e8 *self, VecFx32 *pos, VecFx32 *offset);

static inline ActorC *FindActor(u16 id) {
    ActorMgr *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(mgr, id);
}

void func_ov000_0219830c(void) {
}

void func_ov000_02198310(void) {
}

void func_ov000_02198314(void) {
}

void func_ov000_02198318(void) {
}

void func_ov000_0219831c(void) {
}

void func_ov000_02198320(void) {
}

void func_ov000_02198324(void) {
}

void func_ov000_02198328(History *self) {
    s32 i;
    self->unk_00 = 0;
    self->unk_02 = 0;
    self->mask = 0;
    for (i = 0; i < HISTORY_LEN; i++) {
        self->history[i] = 0;
    }
    self->current = 1;
}

static inline BOOL History_Push(History *self, u8 value, BOOL force) {
    s32 i;
    if (self->current == value && !force) {
        return FALSE;
    }
    for (i = HISTORY_LEN - 1; i > 0; i--) {
        self->history[i] = self->history[i - 1];
    }
    self->history[0] = self->current;
    self->unk_00 = 0;
    self->current = value;
    self->unk_02 = 0;
    return TRUE;
}

BOOL func_ov000_02198360(History *self, u8 value, BOOL force) {
    return History_Push(self, value, force);
}

BOOL func_ov000_021983b0(History *self, u8 value, s32 count, BOOL checkCurrent) {
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

s32 func_ov000_0219840c(History *self, s32 *list, s32 count, BOOL push) {
    s32 result = 0;
    s32 i;
    if (self->mask != 0) {
        for (i = 0; i < count; i++) {
            s32 bit = list[i];
            if (self->mask & ((u64)1 << bit)) {
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

void func_ov000_021984c8(Obj021984c8 *self) {
    self->offset.x = 0;
    self->offset.y = 0;
    self->offset.z = 0;
    self->unk_1a = 0;
    self->unk_1c = 0;
    self->unk_20 = 0xffff;
    *(u16 *)((u8 *)self + 0x22) = 0;
}

void func_ov000_021984f4(Obj021984c8 *self, VecFx32 *pos, u16 *rot) {
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

ActorC *func_ov000_021985c0(Obj021984c8 *self) {
    return FindActor(self->unk_20);
}

Obj021985e8 *func_ov000_021985e8(Obj021985e8 *self) {
    func_0203f260(self);
    self->unk_98 = 0xffff;
    self->unk_44 = 0;
    self->unk_48 = 0;
    self->unk_4c = 0xa000;
    self->offset.x = 0;
    self->offset.y = 0;
    self->offset.z = 0;
    *(u16 *)((u8 *)self + 0x9a) = 0;
    self->unk_30 = 0xc0000000;
    self->unk_34 = 0;
    func_0203f324(self);
    self->unk_50 = 0;
    self->unk_54 = 0;
    self->unk_58 = 0;
    return self;
}

void func_ov000_0219864c(Obj021985e8 *self, VecFx32 *pos, u16 *rot) {
    VecFx32 base;
    VecFx32 ofs;
    ActorC *actor = FindActor(self->unk_98);

    if (actor == NULL) {
        func_0203f364(self);
        self->unk_50 = 0;
        self->unk_54 = 0;
        self->unk_58 = 0;
    } else {
        if (!self->unk_9a_3) {
            func_0203f364(self);
        } else {
            func_0203f324(self);
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
