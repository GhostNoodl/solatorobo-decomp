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

u16 func_ov003_021cee68(Target *self);

extern ActorMgr *data_ov000_021ccd68;

ActorT *func_ov000_0218e640(ActorMgr *mgr, u16 id);
s32 _s32_div_f(s32 a, s32 b);
void func_02012fb8(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *out);

static inline ActorT *FindActor(u16 id) {
    ActorMgr *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(mgr, id);
}

BOOL func_ov000_0219b3b4(Target *self) {
    u8 type = self->type;
    u8 c = self->unk_02;
    u8 b = self->unk_01;
    BOOL ret = FALSE;

    if (type == 0xe || type == 0xf || type == 0x13) {
        if (b == 1 || b == 2 || b == 6) {
            if (c != 1 && c != 2 && c != 4) {
                ret = TRUE;
            }
        }
    }
    return ret;
}
