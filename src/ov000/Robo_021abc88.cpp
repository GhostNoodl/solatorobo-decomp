#include "ov000/LoCommon.h"
#include "Main/Res/StageCmd.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"

extern "C" {
extern u8 data_ov000_021cc62a[];
extern u8 data_ov000_021cc6c0[];
extern u8 data_ov000_021cc5e3[];
extern void *gSndMgr;
BOOL Model0218fe1c_SetAnim(void *a, void *b, s32 c, s32 d);
void Shared_ChangeFlags(s32 a, s32 b);
void *SndMgr_PlayAt(void *a, s32 b, void *c, s32 d);
u16 Angle_Approach(u16 target, u16 cur, s32 rate, s32 a, s32 b);
BOOL History_SetState(void *p, s32 a, s32 b);
void Actor_TurnToPos(Actor *self, void *v, s32 a);
void Actor_MoveToPos(Actor *self, const VecFx32 *target, s32 turn);
BOOL Model0218fe1c_IsAnimDone(void *a);
void Body_SetPos(void *body, VecFx32 *pos, u32 angle);
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *out);
void NNS_G3dRenderObjRemoveAnmObj(void *obj, void *anm);

void Robo021ca458_State1a(Robo021ca458 *self) {
    if (self->unk_b2f == 0) {
        self->unk_b2f++;
    }
    self->unk_44->unk_22_1 = 0;
    switch (self->fsm->st) {
    case 0: {
        s32 dx;
        s32 dz;
        self->unk_b24_2 = 1;
        Model0218fe1c_SetAnim(&self->mdl0, data_ov000_021cc62a, 0x800, 0);
        dx = self->unk_75c.x - self->pos.x;
        dz = self->unk_75c.z - self->pos.z;
        self->mdl0.unk_cc = -1;
        {
            s64 sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            REG_SQRTCNT = 1;
            REG_SQRT_PARAM = (u64)(sq << 2);
        }
        while (REG_SQRTCNT & 0x8000) {
        }
        self->speed = (s32)(REG_SQRT_RESULT + 1) >> 5;
        self->velY = 0x53f;
        self->gravity = 0x52;
        self->target = 0xffff;
        self->friction = 0;
        SndMgr_PlayAt(gSndMgr, 7, (u8 *)self + 0x70, 0);
        self->fsm->st++;
        self->fsm->timer = 0;
        gStageFlags->bits18.flag8 = 0;
        Shared_ChangeFlags(3, 1);
        gSceneCmd->stageFlags = 1;
        break;
    }
    case 1: {
        s32 d;
        u16 *s;
        Actor_TurnToPos(self, (u8 *)self + 0x75c, 0x59a);
        Actor_MoveToPos(self, (VecFx32 *)((u8 *)self + 0x75c), 0);
        d = self->pos.y - self->unk_75c.y;
        if (d < 0x1800) {
            self->pos.y += (self->unk_75c.y + 0x1800 - self->pos.y) >> 2;
        } else if (d > 0x1ccd) {
            self->pos.y += (self->unk_75c.y + 0x1ccd - self->pos.y) >> 2;
        }
        s = (u16 *)self->fsm;
        s[1]++;
        if (s[1] < 0x10) {
            return;
        }
        self->rot_y = Angle_Approach(self->unk_76e, self->rot_y, 0x800, 1, 0x8000);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        Model0218fe1c_SetAnim(&self->mdl0, data_ov000_021cc6c0, 0x400, 0);
        self->fsm->st++;
        break;
    }
    case 2:
        if (Model0218fe1c_IsAnimDone(&self->mdl0)) {
            AnimCtrl *p;
            self->pos = self->unk_75c;
            self->rot_x = self->unk_76c;
            self->rot_y = self->unk_76e;
            self->rot_z = self->unk_770;
            Body_SetPos(&self->hit0, (VecFx32 *)((u8 *)self + 0x70), self->rot_y);
            Body_SetPos(&self->hit1, (VecFx32 *)((u8 *)self + 0x75c), self->unk_76e);
            self->unk_b24_2 = 0;
            self->unk_b24_1 = 1;
            self->unk_b36 = 0;
            Model0218fe1c_SetAnim(&self->mdl1, data_ov000_021cc5e3, 0x155, 0);
            p = self->mdl1.unk_1c;
            if (p != NULL) {
                NNS_G3dRenderObjRemoveAnmObj((u8 *)self + 0x38c, ((void *)p->cur));
                p->name[0] = 0;
                p->index = 0xff;
                p->playing = 0;
                p->same = 0;
            }
            SndMgr_PlayAt(gSndMgr, 0xe, (u8 *)self + 0x70, 0);
            History_SetState(self->fsm, 1, 0);
        } else {
            VecFx32 d;
            s32 ty;
            self->rot_y = Angle_Approach(self->unk_76e, self->rot_y, 0x59a, 1, 0x8000);
            ty = self->unk_75c.y + 0x119a;
            {
                s32 tx = self->unk_75c.x;
                s32 tz = self->unk_75c.z;
                d.x = tx - self->pos.x;
                d.y = ty - self->pos.y;
                d.z = tz - self->pos.z;
            }
            VEC_MultAdd(0x400, &d, (VecFx32 *)((u8 *)self + 0x70), (VecFx32 *)((u8 *)self + 0x70));
        }
        break;
    }
}
}
