#include "ov009/ov009.h"

extern "C" {

extern char data_ov009_022179b4[];
extern void Actor_MoveToPos(Ov003Actor *self, const VecFx32 *v, s32 a);

void Ov009ActVt_02217aac_StateMove(Ov009ActVt_02217aac *self) {
    VecFx32 v;
    if (self->fsm->st == 0) {
        Model0218fe1c_SetAnim(self->model, data_ov009_022179b4, 0x155, 0);
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
    }
    self->speed = self->unk_b0->unk_00;
    if (self->unk_ff != 0) {
        self->speed = self->speed + (self->speed >> 3);
    }
    v = self->unk_b8;
    if (self->pos.y > v.y) {
        self->velY = -self->unk_b0->unk_00 >> 2;
    } else if (self->pos.y < v.y) {
        self->velY = self->unk_b0->unk_00 >> 2;
    } else {
        self->velY = 0;
    }
    Actor_MoveToPos(self, &v, self->unk_b0->unk_02);
    if ((self->velY > 0 && self->pos.y > v.y) || (self->velY < 0 && self->pos.y < v.y)) {
        self->pos.y = v.y;
    }
}

extern void *gSndMgr;
extern u8 data_ov009_022160b8[];
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *other, s32 a);
extern void *SndMgr_PlayAt(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern void Geom_AddRotatedOffset(VecFx32 *v, const void *a, u16 b);
extern void Actor_SendMsgU8(Ov003Actor *a, u16 id, s32 msg);
typedef u16 Ov009Row3[3];

void Ov009ActVt_02217aac_StateShoot(Ov009ActVt_02217aac *self) {
    Ov003Actor *t = Actor_GetTarget(self);
    ActorSub40 *st;
    if (t == NULL) {
        return;
    }
    switch (self->fsm->st) {
    case 0: {
        u16 pct;
        Model0218fe1c_SetAnim(self->model, data_ov009_022179b4, 0x155, 0);
        Model0218fe1c_SetLoop(self->model);
        pct = (self->hp[0] * 100) / self->hp[1];
        if (pct >= 0x4b) {
            self->unk_fd = 1;
            self->fsm->st = 1;
            return;
        }
        if (pct >= 0x28) {
            self->unk_fd = 2;
            self->fsm->st = 2;
            return;
        }
        self->unk_fd = 3;
        self->fsm->st = 2;
        return;
    }
    case 1:
        Actor_TurnToActor(self, t, self->unk_b0->unk_02);
        st = self->fsm;
        st->timer++;
        if (st->timer > 0x1e) {
            self->fsm->st = 3;
            self->fsm->timer = 0;
        }
        return;
    case 2:
        self->rot_y = Angle_Approach((((u16 *)self->unk_104) + self->unk_fc * 3)[self->unk_fd - 1], self->rot_y, self->unk_b0->unk_02, 1, 0x8000);
        st = self->fsm;
        st->timer++;
        if (st->timer > 0x14) {
            self->fsm->st = 3;
            self->fsm->timer = 0;
        }
        return;
    case 3: {
        VecFx32 p;
        Ov003Actor *h;
        SndMgr_PlayAt(gSndMgr, 0x2b, &self->pos, 0);
        p.x = self->pos.x;
        p.y = self->pos.y;
        p.z = self->pos.z;
        Geom_AddRotatedOffset(&p, data_ov009_022160b8, self->rot_y);
        h = static_cast<Ov003Actor *>(Ov003Actor_SpawnChild(self, 0x4802, &p, &self->rot_x, t));
        if (h != NULL) {
            Actor_SendMsgU8(h, self->id, 0xb);
            Effect_SpawnId(0x12c, &p)->SetRotXYZ(0, self->rot_y, 0);
        }
        if (--self->unk_fd == 0) {
            if (++self->unk_fe >= 2) {
                self->unk_fe = 0;
                self->fsm->timer = 0xb4;
                if (self->unk_ff != 0) {
                    self->fsm->timer = 100;
                }
                self->fsm->st = 4;
                return;
            }
            History_SetState(self->fsm, 1, 0);
            self->unk_b6 = 0xb4;
            if (self->unk_ff != 0) {
                self->unk_b6 = 0x96;
            }
            return;
        }
        self->fsm->st = 2;
        return;
    }
    case 4:
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            self->unk_fc = FLD(u8, ((u8 *)self->unk_100) + self->unk_fc * 16, 0xc);
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
}

}
