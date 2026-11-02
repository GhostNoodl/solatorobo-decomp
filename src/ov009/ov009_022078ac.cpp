#include "ov009/ov009.h"

extern "C" {

extern char data_ov009_022172af[];
extern BOOL Model021903b4_Draw(void *p);
extern void Model0218fe1c_UpdateAnim(Model0218fe1c *p, s16 a);

struct Ov009Bits16 {
    u16 b0 : 1;
    u16 b1 : 15;
};

BOOL Ov009ActVt_02217844_Draw(Ov009ActVt_02217844 *self) {
    BOOL r = Ov003Actor_Draw(self);
    if (r) {
        VecFx32 p;
        p = self->pos;
        if (Geom_SnapToGround(&p, 0x2000, -0x5000) != -0x1000) {
            Model021903b4_Draw(&self->modelObj);
        }
    }
    return r;
}

void Ov009ActVt_02217844_Animate(Ov009ActVt_02217844 *self) {
    Ov003Actor_Animate(self);
    Model0218fe1c_UpdateAnim(&self->modelObj, 0x1000);
}
extern BOOL Hit_DiffInCylinder(VecFx32 *a, VecFx32 *b, fx32 r, fx32 h);
extern Ov003Actor *ActorMgr_FindPlayer(void);

void Ov009ActVt_02217844_Update(Ov009ActVt_02217844 *self) {
    Ov003Actor *pl;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (Geom_SnapToGround(&self->pos, 0x1000, -0x3000) == -0x1000) {
        return;
    }
    self->target = 0xffff;
    pl = ActorMgr_FindPlayer();
    if (pl != NULL) {
        self->target = pl->id;
    }
    if (self->unk_1a == 0) {
        if (self->fsm->current == 0xf) {
            return;
        }
        if (Hit_DiffInCylinder(&pl->pos, &self->pos, pl->radius + 0x6800, 0x6000)) {
            self->fsm->flags |= 0x8000;
        }
    } else {
        VecFx32 v;
        if (self->fsm->current == 0x10) {
            return;
        }
        {
            s32 x = self->pos.x;
            s32 z = self->pos.z;
            s32 y = self->pos.y - 0x1000;
            v.x = x;
            v.z = z;
            v.y = y;
        }
        if (Hit_DiffInCylinder(&pl->pos, &v, pl->radius + 0x6800, 0x6000)) {
            self->fsm->flags |= 0x10000;
        }
    }
}

}
