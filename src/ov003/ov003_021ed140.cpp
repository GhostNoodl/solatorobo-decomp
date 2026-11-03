#include "types.h"
#include "ov003/ActorApi.h"
#include "Main/Math/Rot16.h"
#include "ov003/Actor.h"
#include "ov000/ObjLayouts.h"
#include "ov003/Shot.h"

extern "C" {


typedef struct {
    u16 id;
    u16 kind;
    u16 unk_04[4];
    s16 unk_0c;
} Ov003SpawnInfo;

extern void *gGroup;
extern Actor *Group_SpawnActor(void *mgr, Ov003SpawnInfo *info, VecFx32 *pos, const void *rot, u16 a);
extern void Actor_SendMsgU8(Actor *o, u16 a, u8 b);
extern u32 Rand_UpTo(u32 n);

void Ov003ActVt_021f9b18_StateDie(ActorEx *self) {
    if (self->fsm->st == 0 && self->unk_18 != 0) {
        Ov003SpawnInfo info;
        Actor *o;
        s32 i;
        info.id = 0x5401;
        info.kind = 0x5000;
        for (i = 0; i < 4; i++) {
            info.unk_04[i] = 0;
        }
        info.unk_0c = -1;
        o = Group_SpawnActor(gGroup, &info, &self->pos, &self->rot_x, 0xffff);
        if (o != NULL) {
            o->flags_0 = 1;
            Actor_SendMsgU8(o, self->id, 4);
            o->speed = Rand_UpTo(0x80) + 0x19a;
            o->velY = 0x333;
            o->friction = 0;
            o->gravity = 0x52;
            o->moveYaw = self->rot_y;
        }
    }
    ActorEx_StateDie(self);
}

extern Ov003ShotDef data_ov003_021f6c04;
extern void Ov003Shot_Init(ActorEx *self);

void Ov003ActVt_021f9a80_Init(Ov003HomingShot *self) {
    Ov003Shot_Init(self);
    self->shotDef = &data_ov003_021f6c04;
}

}
