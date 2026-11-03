#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"

typedef struct {
    u16 x;
    u16 y;
    u16 z;
} Rot021b08ec;

extern "C" {

void func_ov000_021b0db0(Robo021ca458 *self, s32 id);

void Robo021ca458_Mode5_State02(Robo021ca458 *self) {
    func_ov000_021b0db0(self, 0x2cd);
}

extern void *data_02097e4c;
extern MessageQueue021cb980 *data_ov000_021ccd30;
extern VecFx32 data_ov000_021ca024;
extern u8 data_ov000_021ca2a8[];
extern u8 data_ov000_021ca2e4[];
void Vec_RotateY(VecFx32 *out, const VecFx32 *in, u16 ang);
void *Actor_SpawnKind(s32 kind, VecFx32 *pos, void *rot, u16 a, u16 b);
void *SndMgr_PlayAtPitch(void *a, s32 b, void *c, s32 d);
void *SndMgr_PlayAt(void *a, s32 b, void *c, s32 d);
BOOL History_SetState(void *s, s32 a, s32 b);
void func_ov000_02168e18(Lo021cb840 *self, s32 a, s32 b, VecFx32 *p);

static inline void SetPal(Model0218fe1c *sub) {
    sub->color = 0x73ea;
    sub->color2 = 0x7ffc;
    sub->blend = 0x15;
    sub->blendMax = 0x14;
}

void Robo021ca458_Mode5_State0e(Robo021ca458 *self) {
    ActorSub40 *s;
    s32 id;
    switch (self->fsm->st) {
    case 0:
        if (self->unk_b36 != 0) {
            self->unk_b36 = 1;
        }
        self->unk_b08 = 0x2cd;
        self->fsm->st++;
    case 1:
        s = self->fsm;
        s->timer++;
        if (s->timer <= self->unk_b36) {
            u16 t = self->fsm->timer;
            VecFx32 ofs;
            ListBuffer021cb940 *p;
            if (t < 0xc) {
                break;
            }
            if (t == 0xc) {
                SndMgr_PlayAtPitch(data_02097e4c, 0x5b, (u8 *)self + 0x70, 2);
            } else if (t == 0x23) {
                SndMgr_PlayAtPitch(data_02097e4c, 0x44, (u8 *)self + 0x70, 2);
                SndMgr_PlayAt(data_02097e4c, 0x78, (u8 *)self + 0x70, 0);
                SetPal(self->model);
            } else if (t >= 0x41) {
                SndMgr_PlayAt(data_02097e4c, 0x36, (u8 *)self + 0x70, 0);
                SetPal(self->model);
                self->fsm->timer = 0x23;
            }
            ofs.x = 0;
            ofs.y = 0xc00;
            ofs.z = 0;
            if (t > 0x23) {
                t = 0x23;
            }
            p = data_ov000_021ccd30->unk_11c;
            if (p != NULL && p->unk_70 != NULL) {
                func_ov000_02168e18(p->unk_70, t, 0x23, &ofs);
            }
            self->unk_b08 = 0x166;
        } else {
            s32 kind;
            u8 *tbl;
            s32 ang;
            u16 tm;
            VecFx32 pos;
            Rot021b08ec rot;
            VObj *o;
            kind = 0x4831;
            tbl = data_ov000_021ca2a8;
            ang = 0x7b;
            s = self->fsm;
            tm = s->timer;
            {
                u16 nt = 0xa;
                if (tm >= 0x23) {
                    nt = 0x28;
                    kind++;
                    tbl = data_ov000_021ca2e4;
                    ang = 0xa4;
                }
                s->timer = nt;
            }
            Vec_RotateY(&pos, &data_ov000_021ca024, self->rot_y);
            VEC_Add(&pos, (VecFx32 *)((u8 *)self + 0xaf0), &pos);
            rot.x = ((-0x6800 - self->unk_af0.y) >> 5) + 0xfa00;
            rot.y = 0x8000;
            rot.z = 0;
            o = (VObj *)Actor_SpawnKind(kind, &pos, &rot, self->id, 0xffff);
            if (o != NULL) {
                EffectObj *e;
                LFLD(u8 *, o, 0x60) = tbl;
                if (LFLD(u8 *, o, 0x4c) != NULL) {
                    LFLD(u8, LFLD(u8 *, o, 0x4c), 0x18) |= 0x40;
                }
                e = Effect_SpawnId(0x68, &pos);
                self->unk_b48 = e->id;
                self->unk_b5e = ang;
                self->unk_b4c = 0;
                self->unk_b50 = 0x3400;
                self->unk_b54 = 0x3000;
                self->unk_b58 = 0xc000;
                self->unk_b5a = 0;
                self->unk_b5c = 0;
                e->unk_29 = 1;
                e->SetScaleAll(0x666);
            }
            self->fsm->st++;
        }
        break;
    case 2: {
        s = self->fsm;
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            if (self->unk_b36 != 0) {
                self->fsm->st = 0;
            } else {
                History_SetState(self->fsm, 1, 0);
            }
        }
        break;
    }
    }
    id = 0;
    if (self->padCur & 0xf0) {
        id = self->unk_b08;
    }
    func_ov000_021b0db0(self, id);
}

}
