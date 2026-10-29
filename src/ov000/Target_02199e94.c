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

u16 func_ov000_02199e94(Target *self) {
    u8 a = self->unk_19;
    u16 r = self->unk_08;
    s32 row;
    u8 b = self->unk_1a;
    u16 v;

    if (a != 0 && b != 0) {
        row = 0;
        if (a == 2) {
            row = 1;
        }
        v = data_ov000_021c9fd0[row][b - 1];
        if (self->unk_1b != 0) {
            v += self->unk_1b;
        }
        if (b == 1) {
            r = r + v;
        } else {
            r = v;
        }
    }
    return r;
}

u32 func_ov000_02199f08(Target *self) {
    u32 r = 0x40;
    u8 a = self->unk_19;

    if (a != 0) {
        u16 n = func_ov003_021cee68(self);
        if (a == 1) {
            n--;
        }
        if (self->unk_1a < n) {
            r = 0x41;
        }
    }
    return r;
}

void func_ov000_02199f48(Target *self, ActorT *actor) {
    self->unk_04 = actor != NULL ? actor->id : 0xffff;
}

ActorT *func_ov000_02199f60(Target *self) {
    return FindActor(self->unk_04);
}

void func_ov000_02199f88(Target *self, ActorP *out) {
    s32 a = 0;
    s32 b = 0;
    s32 c = 0;

    switch (*((u8 *)self + 9)) {
    case 0x10:
        a = 0x371;
        c = 0xccd;
        break;
    case 0x11:
        a = 0x79a;
        c = 0xcb8;
        break;
    case 0x20:
    case 0x50:
        a = 0x229;
        b = 0x28f;
        break;
    case 0x30:
        a = 0x27b;
        b = 0x39a;
        break;
    case 0x21:
    case 0x40:
    case 0x41:
    case 0x42:
        a = 0x66;
        b = 0x400;
        break;
    case 0x31:
        a = 0x66;
        b = 0x466;
        break;
    }
    if (out != NULL) {
        out->unk_9c = a;
        out->unk_a0 = b;
        out->unk_a4 = c;
        out->unk_a8 = 0x52;
    }
}

void func_ov000_0219a088(u16 *self) {
    if (self[0] == 0) {
        return;
    }
    self[0]--;
    if (self[0] == 0) {
        self[1] = 0;
    }
}
