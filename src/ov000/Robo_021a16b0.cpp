#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"

extern "C" {

extern char data_ov000_021cc5e3[];
extern char data_ov000_021cc618[];
extern char *data_ov000_021ca040[];
extern void *data_02097e4c;
BOOL Model0218fe1c_SetAnim(void *a, void *b, s32 c, s32 d);
void Model0218fe1c_SetLoop(void *a);
void Model0218fe1c_StopAnim(void *a);
void SndMgr_StopSeqArc(void *a, s32 b);
void Body_Update(void *a, s32 b, s32 c, s32 d);
void func_ov000_021b209c(u8 *self);
void func_ov000_021b2b08(u8 *self);

static inline BOOL PlayerIdle021a16b0(void) {
    FieldState *pl = data_ov000_021ccd54;
    if (pl != NULL) {
        if (pl->head != pl->tail ? TRUE : FALSE) {
            return FALSE;
        }
        if (pl->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

void Robo021ca458_State01(Robo021ca458 *self) {
    switch (self->fsm->st) {
    case 0:
        self->fsm->timer = 0;
        self->fsm->st++;
        if (self->unk_b22_0 > 1) {
            if (self->unk_998 != NULL) {
                Model0218fe1c_StopAnim(self->unk_998);
            }
            if (self->seSlot >= 0) {
                SndMgr_StopSeqArc(data_02097e4c, self->seSlot);
                self->seSlot = -1;
            }
            if (self->unk_b22_0 > 1) {
                self->unk_b22_0 = 1;
                self->rot_x = 0;
                self->rot_z = 0;
                self->unk_9a6 = 0;
                self->unk_9a8 = 0;
                self->unk_9aa = 0;
                self->unk_9a0 = 0;
                self->unk_9a2 = 0;
                self->unk_9a4 = 0;
            }
        }
    case 1: {
        char *name = data_ov000_021cc5e3;
        s32 rate = 0x2ab;
        s32 d = 0;
        if (self->unk_b24_1) {
            if (!self->unk_b22_3) {
                name = data_ov000_021ca040[self->unk_b24_5];
            } else {
                if (self->unk_b24_5 != 0) {
                    name = data_ov000_021cc618;
                }
                rate = 0xa4;
            }
        } else if (self->hit->unk_50 & 0x400) {
            name = data_ov000_021cc618;
        }
        if (self->unk_b24_25) {
            self->unk_b24_25 = 0;
            rate = 0x1000;
            d = 1;
        }
        Model0218fe1c_SetAnim(self->model, name, rate, d);
        Model0218fe1c_SetLoop(self->model);
        if (self->unk_b24_12 != 0) {
            self->fsm->st++;
            if (self->unk_b2f == 0) {
                self->unk_b2f = 1;
            }
            return;
        }
        if (self->fsm->timer >= 0x5a) {
            if (self->unk_b32 == 0) {
                self->unk_b32 = 1;
            }
        } else if (PlayerIdle021a16b0() && self->mode == 1 && !self->unk_b29_1 &&
                   !self->unk_b28_2 && self->unk_b2e == 0 &&
                   self->unk_b22_0 == 0) {
            self->fsm->timer++;
        } else {
            self->fsm->timer = 0;
        }
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->hit->unk_9a |= 0x20;
        if (self->msg_flags & 0x80) {
            Body_Update(self->hit, 1, 0, 0);
        }
        return;
    }
    case 2:
        if (self->unk_b24_12 == 0) {
            return;
        }
        if (self->unk_b24_12 != 3) {
            func_ov000_021b209c((u8 *)self);
        } else {
            func_ov000_021b2b08((u8 *)self);
        }
        return;
    }
}

}
