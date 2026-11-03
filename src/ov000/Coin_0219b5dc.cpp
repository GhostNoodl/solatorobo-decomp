#include "ov000/Actor.h"
#include "ov000/Group.h"


extern "C" {
BOOL func_020621f8(void);
Actor *Group_SpawnActor(void *mgr, GroupActorDesc *desc, s32 a, s32 b, u16 c);

void func_ov000_0219b5dc(u16 amount, s32 a, s32 b) {
    s32 n;
    if (func_020621f8()) {
        return;
    }
    for (n = 0; n < 3; n++) {
        u16 id;
        if (amount >= 50) {
            amount -= 50;
            id = 0x4c3d;
        } else if (amount >= 20) {
            amount -= 20;
            id = 0x4c3c;
        } else if (amount >= 10) {
            amount -= 10;
            id = 0x4c02;
        } else if (amount >= 5) {
            amount -= 5;
            id = 0x4c01;
        } else if (amount >= 1) {
            amount -= 1;
            id = 0x4c00;
        } else {
            return;
        }
        if (id != 0xffff) {
            GroupActorDesc desc;
            s32 i;
            Actor *o;
            desc.kind = id;
            desc.group = id & 0xf000;
            for (i = 0; i < 4; i++) {
                desc.args[i] = 0;
            }
            desc.unk_0c = -1;
            o = Group_SpawnActor(gGroup, &desc, a, b, 0xffff);
            if (o != NULL) {
                o->flags_0 = 1;
            }
        }
    }
}
}
