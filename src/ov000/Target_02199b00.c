#include "types.h"
#include "ov000/Vec.h"

typedef struct {
    u8 unk_00[0xc];
    u16 id;
} ActorT;

typedef struct {
    u8 type;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    u8 unk_0c[0x4];
    u16 kinds[2];
    u16 ids[2];
    u8 unk_18_0 : 3;
    u8 unk_18_3 : 1;
    u8 unk_18_4 : 4;
    u8 unk_19;
    u8 unk_1a;
    u8 unk_1b;
    u16 target;
    u16 unk_1e;
    u8 unk_20[0x24];
    VecFx32 dest;
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
} Target;

typedef struct {
    u8 unk_00[0x9c];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
} ActorP;

typedef struct ActorMgr ActorMgr;

extern u16 data_ov000_021c9fd0[][5];

u8 func_ov003_021cee68(Target *self);

extern ActorMgr *data_ov000_021ccd68;

ActorT *func_ov000_0218e640(ActorMgr *mgr, u16 id);
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *out);

static inline ActorT *FindActor(u16 id) {
    ActorMgr *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(mgr, id);
}

Target *func_ov000_02199b00(Target *self) {
    s32 i;

    self->type = 0;
    self->unk_01 = 0;
    self->unk_02 = 0;
    self->unk_03 = 0;
    self->unk_04 = 0;
    self->unk_06 = 0;
    self->unk_08 = 0;
    self->unk_0a = 0;
    for (i = 0; i < 2; i++) {
        self->kinds[i] = 0xffff;
    }
    for (i = 0; i < 2; i++) {
        self->ids[i] = 0xffff;
    }
    *(u8 *)((u8 *)self + 0x18) = 0;
    self->unk_19 = 0;
    self->unk_1a = 0;
    self->unk_1b = 0;
    self->target = 0xffff;
    self->unk_1e = 0;
    self->unk_50 = 0;
    self->unk_54 = 0;
    self->unk_58 = 0;
    return self;
}

void func_ov000_02199b88(Target *self, ActorT *actor) {
    self->target = actor != NULL ? actor->id : 0xffff;
}

ActorT *func_ov000_02199ba0(Target *self) {
    return FindActor(self->target);
}

u16 func_ov000_02199bc8(Target *self, VecFx32 *pos, u16 t, u16 dur) {
    VecFx32 d;

    if (!self->unk_18_3 && t < dur) {
        d.x = self->dest.x - pos->x;
        d.y = self->dest.y - pos->y;
        d.z = self->dest.z - pos->z;
        VEC_MultAdd((t << 12) / dur, &d, pos, pos);
        t++;
    } else {
        pos->x = self->dest.x;
        pos->y = self->dest.y;
        pos->z = self->dest.z;
    }
    return t;
}

BOOL func_ov000_02199c70(Target *self, u16 kind) {
    BOOL found = FALSE;
    s32 i;

    for (i = 0; i < 2; i++) {
        u16 k = self->kinds[i];
        if (k == 0xffff) {
            continue;
        }
        if (!(k & 0xfff)) {
            if (k == (u16)(kind & 0xf000)) {
                found = TRUE;
                break;
            }
        } else if (k == kind) {
            found = TRUE;
            break;
        }
    }
    return found;
}

BOOL func_ov000_02199cd8(Target *self, u16 id) {
    BOOL found = FALSE;
    s32 i;

    for (i = 0; i < 2; i++) {
        u16 k = self->ids[i];
        if (k == 0xffff) {
            continue;
        }
        if (!(k & 0xfff)) {
            if (k == (u16)(id & 0xf000)) {
                found = TRUE;
                break;
            }
        } else if (k == id) {
            found = TRUE;
            break;
        }
    }
    return found;
}

BOOL func_ov000_02199d40(Target *self) {
    BOOL any = FALSE;
    s32 i;

    for (i = 0; i < 2; i++) {
        if (self->ids[i] != 0xffff) {
            any = TRUE;
            break;
        }
    }
    return any;
}

u16 func_ov000_02199d78(Target *self) {
    u16 mask = 0;
    s32 i;

    for (i = 0; i < 2; i++) {
        if (self->kinds[i] != 0xffff) {
            mask = 1 << (self->kinds[i] >> 12);
        }
    }
    return mask;
}
