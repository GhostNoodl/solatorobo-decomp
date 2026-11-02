#include "ov000/Group.h"

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

extern "C" {

void GroupNode_SetSpawnRange(GroupNode *u, s32 a, s32 b) {
    if (b == 0) {
        b = a;
    }
    u->spawnRange = FX_MUL(a, 0x37000);
    u->spawnHeight = FX_MUL(b, 0x14000);
    u->despawnRange = FX_MUL(a, 0x39000);
    u->despawnHeight = FX_MUL(b, 0x16000);
    u->fadeStart = FX_MUL(a, 0x32000);
    func_ov000_0218b420(u);
}

static inline void Unit0218b700_SetSize(GroupNode *u, s32 a, s32 b) {
    if (b == 0) {
        b = a;
    }
    u->spawnRange = FX_MUL(a, 0x37000);
    u->spawnHeight = FX_MUL(b, 0x14000);
    u->despawnRange = FX_MUL(a, 0x39000);
    u->despawnHeight = FX_MUL(b, 0x16000);
    u->fadeStart = FX_MUL(a, 0x32000);
    func_ov000_0218b420(u);
}

// Case 6 comes before case 3 in the first switch (the compiler cross-jumps the identical bodies),
// and the mode 5 path edits a copy of the flag byte so the bits are stored once.
void func_ov000_0218b7c0(GroupNode *u, s32 kind, s32 mode) {
    s32 x = 0x1000;
    s32 y = x;
    if (mode == 5) {
        GroupNodeFlags t = u->flags;
        t.useAngle = 0;
        t.toGround = 0;
        x = 0x599a;
        y = 0x4000;
        if (kind == 6) {
            x = 0xc000;
        }
        t.unk_5 = 1;
        u->flags = t;
    } else {
        switch (kind) {
        case 6:
            u->flags.unk_0 = 0;
            u->flags.useRange = 0;
            func_ov000_0218b420(u);
            u->flags.useHeight = 0;
            func_ov000_0218b420(u);
            u->flags.unk_5 = 1;
            break;
        case 3:
            u->flags.unk_0 = 0;
            u->flags.useRange = 0;
            func_ov000_0218b420(u);
            u->flags.useHeight = 0;
            func_ov000_0218b420(u);
            u->flags.unk_5 = 1;
            break;
        case 4:
            u->flags.unk_6 = 1;
            break;
        }
        switch (mode) {
        case 1:
        case 2:
            u->flags.unk_0 = 0;
            u->flags.useRange = 0;
            func_ov000_0218b420(u);
            u->flags.useHeight = 0;
            func_ov000_0218b420(u);
            break;
        case 3:
            u->flags.useHeight = 0;
            func_ov000_0218b420(u);
            x = 0x2000;
            y = 0x1ccd;
            u->flags.useAngle = 0;
            u->flags.toGround = 0;
            break;
        case 4:
            u->flags.useHeight = 0;
            func_ov000_0218b420(u);
            y = 0x1ccd;
            x = 0x2000;
            u->flags.useAngle = 0;
            break;
        }
    }
    if (x != 0x1000 || y != 0x1000) {
        Unit0218b700_SetSize(u, x, y);
    }
}

}
