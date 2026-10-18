#include "types.h"

typedef struct Ov003SwNode Ov003SwNode;
struct Ov003SwNode {
    u8 unk_00[8];
    Ov003SwNode *next;
    u8 unk_0c[2];
    u16 id;
    u8 unk_10[0x83];
    u8 unk_93_0 : 1;
    u8 state : 3;
};

typedef struct {
    u8 unk_00[0xc];
    Ov003SwNode *head;
} Ov003SwList;

typedef struct {
    u8 unk_00[4];
    u16 ids[2];
} Ov003SwTargets;

typedef struct {
    u8 unk_00[0xe];
    u16 id;
    Ov003SwTargets targets;
} Ov003Switch;

BOOL func_ov003_021f0a38(Ov003Switch *self, Ov003Switch *def) {
    BOOL r = FALSE;
    s32 i;
    Ov003SwTargets *t = &def->targets;
    for (i = 0; i < 2; i++) {
        u16 id = t->ids[i];
        if (id != 0xffff) {
            if ((u16)(id & 0xf000)) {
                if (id == self->id) {
                    r = TRUE;
                }
            } else if ((u16)(id << 12) == (u16)(self->id & 0xf000)) {
                r = TRUE;
            }
        }
        if (r) {
            break;
        }
    }
    return r;
}
