#include "types.h"
#include "Main/Sys/FieldState.h"
#include "ov003/Unit.h"
#include "ov000/ActorParts.h"

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0x10];
    u16 unk_20;
    u8 unk_22[0x1e];
    ActorSub40 *work;
    u8 unk_44[0x2c];
    s32 pos[3];
} Ov003Prop;

extern void *data_ov000_021ccd64;
extern void ActorEx_Start(void *p);
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);
extern void GroupNode_SetSpawnRange(Ov003Unit *u, s32 a, s32 b);

void Ov003ActVt_021f8188_Start(Ov003Prop *self) {
    Ov003Unit *u;
    ActorEx_Start(self);
    u = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (u == NULL) {
        return;
    }
    u->unk_a2_0 = 0;
    GroupNode_SetSpawnRange(u, 0x5000, 0);
}

extern void func_ov000_0218996c(u8 a, u8 b);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);

void Ov003Prop_State21(Ov003Prop *self) {
    ActorSub40 *w = self->work;
    switch (w->st) {
    case 0:
        w->timer++;
        if (w->timer > 0x2d) {
            func_ov000_0218996c(0x28, 0x5a);
            self->work->timer = 0;
            self->work->st++;
        }
        break;
    case 1:
        w->timer++;
        if (w->timer > 100) {
            func_020627a0(self->unk_0e, self->unk_0c);
            func_020627dc(4);
            data_ov000_021ccd54->stageFlags = 1;
            self->work->timer = 0;
            self->work->st++;
        } else {
            self->pos[1] -= self->work->timer * 2 + 0x200;
        }
        break;
    case 2:
        w->timer++;
        if (w->timer > 0x32) {
            self->pos[1] += 0x1e800;
            self->work->st++;
        }
        self->pos[1] -= 0x266;
        break;
    }
}
