#include "types.h"
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

extern void *data_ov000_021ccd64;
extern Actor *Group_SpawnActor(void *mgr, Ov003SpawnInfo *info, VecFx32 *pos, const void *rot, u16 a);
extern void func_ov000_0218d46c(Actor *o, u16 a, s32 b);
extern s32 Rand_UpTo(s32 n);
extern void func_ov000_0219763c(void *self);

void func_ov003_021ed058(ActorEx *self) {
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
        o = Group_SpawnActor(data_ov000_021ccd64, &info, &self->pos, &self->rot_x, 0xffff);
        if (o != NULL) {
            o->flags_0 = 1;
            func_ov000_0218d46c(o, self->id, 4);
            o->speed = Rand_UpTo(0x80) + 0x19a;
            o->velY = 0x333;
            o->friction = 0;
            o->gravity = 0x52;
            o->moveYaw = self->rot_y;
        }
    }
    func_ov000_0219763c(self);
}

extern Ov003ShotDef data_ov003_021f6c04;
extern void func_ov003_021dae58(ActorEx *self);

void Ov003ActVt_021f9a80_Init(Ov003HomingShot *self) {
    func_ov003_021dae58(self);
    self->shotDef = &data_ov003_021f6c04;
}

}
