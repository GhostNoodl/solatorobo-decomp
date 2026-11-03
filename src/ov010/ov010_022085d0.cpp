#include "ov010/ov010.h"
#include "Main/Sys/FieldState.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Snd/SndMgr.h"

struct Ov010Rot {
    s16 v[3];
};

extern "C" {

extern u8 data_ov010_0220f024[];
extern VecFx32 data_ov010_0220f114;
extern VecFx32 data_ov010_0220f120;
void Shared_SetEventActor(u16 a, u16 b);
void func_020627dc(s32 a);

void Ov010ActVt_0220ffe4_State23(Ov010Obj0220ffe4 *self) {
    ActorSub40 *w = self->fsm;
    switch (w->st) {
    case 0:
        w->timer = 0;
        self->fsm->st = 0x1e;
        break;
    case 0x1e:
        Effect_SpawnId(0x389, &data_ov010_0220f114)->SetScaleAll(0x2000);
        Effect_SpawnId(0x322, &data_ov010_0220f114)->SetScaleAll(0x1800);
        Effect_SpawnId(0x389, &data_ov010_0220f120)->SetScaleAll(0x2000);
        Effect_SpawnId(0x322, &data_ov010_0220f114)->SetScaleAll(0x1800);
        SndMgr_PlayAt(data_02097e4c, 0x79, &self->pos, 0);
        self->fsm->st = 0x1f;
        self->fsm->timer = 0x28;
        break;
    case 0x1f:
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer == 0) {
            self->fsm->st = 0x28;
        }
        break;
    case 0x28: {
        Ov010Rot r;
        Actor *o;
        r = FLD(Ov010Rot, data_ov010_0220f024, 0x3e);
        o = Ov003_SpawnById(0x5816);
        Ov010_VecSet(&o->pos, 0x2ee1, -0xc000, -0x2000);
        o->rot_x = r.v[0];
        o->rot_y = r.v[1];
        o->rot_z = r.v[2];
        o = Ov003_SpawnById(0x5816);
        Ov010_VecSet(&o->pos, -0x2571, -0xc000, -0x2000);
        o->rot_x = r.v[0];
        o->rot_y = r.v[1];
        o->rot_z = r.v[2];
        Effect_SpawnId(0x579, &data_ov010_0220f114)->SetScaleAll(0x2000);
        Effect_SpawnId(0x579, &data_ov010_0220f120)->SetScaleAll(0x2000);
        SndMgr_PlayAt(data_02097e4c, 0x5c, &self->pos, 0);
        self->fsm->st = 100;
        break;
    }
    case 100:
        Shared_SetEventActor(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
        self->fsm->st = 0x65;
        self->unk_1fc = 1;
        break;
    case 0x65:
        break;
    }
}
}
