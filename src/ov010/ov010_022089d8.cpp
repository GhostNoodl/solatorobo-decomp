#include "ov010/ov010.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Snd/SndMgr.h"

extern "C" {

extern u8 data_ov010_0220f024[];
extern const VecFx32 data_ov010_0220f144;
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *a, const char *b, s16 c, u8 d);
extern void Model0218fe1c_SetLoop(Model0218fe1c *a);
extern u16 FX_Atan2(s32 y, s32 x);
extern s32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);
extern BOOL History_SetState(ActorSub40 *a, u8 b, BOOL c);

static inline BOOL Ov010_Begin(u16 *st) {
    if (*st == 0) {
        (*st)++;
        return TRUE;
    }
    return FALSE;
}

void Ov010ActVt_0221009c_State20(Ov003Actor *self) {
    BOOL anim = FALSE;
    switch (self->unk_18) {
    case 0: {
        ActorSub40 *st = self->fsm;
        if (st->st == 0) {
            Ov010_VecSet(&self->pos, -0xd9e, 0x2a35, -0x8687);
            self->pos.y += 0xd000;
            self->rot_x = 0;
            self->rot_y = 0xff;
            self->rot_z = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            self->speed = 0x200;
            anim = TRUE;
            SndMgr_PlayAt(data_02097e4c, 0x51, &self->pos, 0);
            self->fsm->st++;
        } else {
            const VecFx32 *t = &data_ov010_0220f144;
            if (self->speed >= 0x40) {
                if (self->friction == 0) {
                    if (VEC_Distance(t, &self->pos) < 0x2000) {
                        self->friction = 0xf00;
                    }
                }
                Ov003Vec_ApproachWithin(&self->pos, t, &self->pos, self->speed, self->velY);
                Ov003Actor_SetMotion(self, self->speed, self->velY, self->friction, self->gravity);
                self->moveYaw = FX_Atan2(t->x - self->pos.x, t->z - self->pos.z);
            } else {
                if (st->timer == 0) {
                    Effect_SpawnId(0x12f, &self->pos)->SetScaleAll(0xe66);
                }
                self->fsm->timer++;
                if (self->fsm->timer > 0x5a) {
                    self->speed = 0;
                    self->velY = 0;
                    self->friction = 0;
                    self->gravity = 0;
                    Ov003Actor_State20(self);
                } else {
                    Ov003Vec_ApproachWithin(&self->pos, t, &self->pos, self->speed, self->velY);
                    Ov003Actor_SetMotion(self, self->speed, self->velY, self->friction, self->gravity);
                    self->moveYaw = FX_Atan2(t->x - self->pos.x, t->z - self->pos.z);
                }
            }
        }
        break;
    }
    case 1:
    case 2: {
        if (((const u16 *)self->fsm)[0] == 0) {
            self->fsm->st++;
            anim = TRUE;
        }
        Ov010_VecSet(&self->pos, -0xd9e, 0x2a35, -0x8687);
        self->rot_x = 0;
        self->rot_y = 0xff;
        self->rot_z = 0;
        History_SetState(self->fsm, 1, 0);
        break;
    }
    }
    if (anim) {
        Model0218fe1c_SetAnim(self->model, FLD(const char *, data_ov010_0220f024, 0x2c), 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        self->model->visible = 1;
    }
}
}
