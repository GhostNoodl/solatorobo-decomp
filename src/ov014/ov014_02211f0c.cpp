#include "ov014/ov014.h"

extern "C" {

extern char data_ov014_02217d7c[];
extern char data_ov014_02217d82[];
extern s16 *func_ov000_02191318(Model0218fe1c *a, s32 b);
extern void func_ov000_02191618(Model0218fe1c *a);

void func_ov014_02211f0c(Ov014Act_0220f9d0 *self) {
    switch (self->fsm->st) {
    case 0: {
        ActorSub44 *n;
        if (self->unk_150 == 0x4806) {
            func_ov000_02190cb0(self->model, data_ov014_02217d7c, 0x1000, 0);
        } else {
            func_ov000_02190cb0(self->model, data_ov014_02217d82, 0x1000, 0);
        }
        func_ov000_02191318(self->model, 0);
        func_ov000_02191618(self->model);
        self->fsm->st++;
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->unk_44->unk_22_4 = 0;
        break;
    }
    case 1: {
        ActorSub44 *n;
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        self->fsm->st = 0xffff;
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        self->unk_44->unk_22_4 = 1;
        break;
    }
    default: {
        ActorSub44 *n;
        self->fsm->st = 0xffff;
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        self->unk_44->unk_22_4 = 1;
        break;
    }
    }
}

extern char data_ov014_02217d88[];
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_ov000_02182590(void *p);
extern void func_ov000_021911c8(Model0218fe1c *a, s16 b);
extern AnimCtrl *func_ov000_02190a30(Model0218fe1c *self, u32 i);
extern void func_ov000_0219bd20(s32 a, u16 b, s32 c, s32 d, s32 e, u8 *f);
extern void func_ov000_0218996c(u8 a, u8 b);

// *(&data_02097e4c) keeps the global's address in a saved register (r7) across the
// switch, as in the target; a plain data_02097e4c reloads it from the pool each time.
void func_ov014_02212050(Ov014Act_0220f9d0 *self) {
    u16 t;
    VecFx32 v1;
    VecFx32 v3;
    u8 b;
    switch (ActorSub40_State(self->fsm)) {
    case 0: {
        FieldState *g;
        ActorSub44 *n;
        EffectObj *e;
        func_020627a0(self->kind, self->id);
        func_020627dc(5);
        g = data_ov000_021ccd54;
        g->stageFlags = 1;
        func_ov000_02182590((u8 *)g + 0xac);
        func_ov000_02190cb0(self->model, data_ov014_02217d88, 0x19a, 0);
        func_ov000_021911c8(self->model, 0x400);
        func_ov000_02191618(self->model);
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->targetObj->target = 0xffff;
        b = 0x15;
        func_ov000_0219bd20(0x5c16, self->id, 2, 1, 1, &b);
        func_ov000_0219bd20(0x4806, self->id, 2, 1, 1, &b);
        func_ov000_0219bd20(0x4814, self->id, 2, 1, 1, &b);
        func_ov000_0219bd20(0x4815, self->id, 2, 1, 1, &b);
        func_ov000_0219bd20(0x4816, self->id, 2, 1, 1, &b);
        func_ov000_0219bd20(0x4838, self->id, 2, 1, 1, &b);
        func_ov000_0219bd20(0x4839, self->id, 2, 1, 1, &b);
        e = func_02065f88(0x69, &self->pos);
        if (e != NULL) {
            e->AddPosXYZ(0, 0x6000, 0x4000);
            e->SetScaleAll(0x6000);
        }
        func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
        func_ov000_0218996c(0xc, 0x5a);
        self->fsm->timer = 0x258;
        self->fsm->st++;
        break;
    }
    case 1: {
        t = self->fsm->timer;
        if (t != 0) {
        if (t == 0x21c) {
            EffectObj *e = func_02065f88(0x390, &self->pos);
            e->AddPosXYZ(0, 0x6000, 0x2000);
            e->SetScaleAll(0x3000);
            self->unk_158 = e->id;
            func_02049f44(*(&data_02097e4c), 0x44, &self->pos, 0);
        }
        if (t == 0x1fe || t == 0x1e0 || t == 0x1c2 || t == 0x1a4) {
            func_02049f44(*(&data_02097e4c), 0x44, &self->pos, 0);
        }
        if (t == 0x12c) {
            EffectMgr_StopLoop(data_0214a420, self->unk_158);
        }
        if (t == 0x140) {
            FieldState *g = data_ov000_021ccd54;
            SndQueue *h;
            g->cam.base.shakeX = 1;
            g->cam.base.shakeY = 0;
            g->cam.base.shakeZ = 0;
            g->cam.base.shakeTime = 0x10;
            g->cam.base.shakeLen = 0x1e;
            g->cam.base.shakeCur = 0x1e;
            g->cam.base.shakeRandom = 1;
            h = data_02097e48.queue;
            if (h->flag0 != 1 || h->unk_74 != 0xffff || h->unk_72 != 0x38) {
                h->unk_74 = 0x38;
                h->unk_70 = 0;
            }
        }
        if (t <= 0xc8 && t % 30 == 0) {
            EffectObj *e;
            s32 r;
            v1 = self->pos;
            v1.x += Rand_PlusMinus(0x4000);
            v1.y = Rand_PlusMinus(0x3000) + 0x5000;
            v1.z += Rand_PlusMinus(0x1000) + 0x5000;
            e = func_02065f88(0x38f, &v1);
            r = Rand_UpTo(0x1000);
            e->SetScaleXYZ(r + 0x2800, r + 0x2800, r + 0x2800);
            func_02049f44(*(&data_02097e4c), 0x35, &v1, 0);
            func_02049f44(*(&data_02097e4c), 0x56, &v1, 0);
        }
        if (t > 0xfa) {
            s32 a = 0;
            AnimCtrl *q = func_ov000_02190a30(self->model, 0);
            if (q->cur != NULL) {
                a = q->cur->frame;
            }
            if (a >= 0x8000) {
                func_ov000_02191318(self->model, 0);
            }
        }
        if (t == 0xfa) {
            func_ov000_021911c8(self->model, 0x1000);
        }
        {
            ActorSub40 *s = self->fsm;
            if (s->timer != 0) {
                s->timer--;
            }
        }
        } else {
            FieldState *g;
            self->fsm->st++;
            g = data_ov000_021ccd54;
            g->cam.base.shakeRandom = 0;
            g->cam.base.shakeTime = 0;
            g->cam.base.shakeLen = 0;
            g->cam.base.shakeCur = 0;
        }
        break;
    }
    case 2:
        func_ov003_021d6a3c(self, 0, 1, 1);
        func_ov000_02190cb0(self->model, data_ov014_02217d88, 0x19a, 0);
        func_ov000_02191618(self->model);
        func_ov000_021911c8(self->model, 0x1000);
        self->fsm->st++;
        self->fsm->timer = 0;
        break;
    case 3: {
        ActorSub40 *s = self->fsm;
        s->timer++;
        if (s->timer % 48 != 0) {
            break;
        }
        v3 = self->pos;
        v3.x += Rand_PlusMinus(0xa000);
        v3.y = Rand_PlusMinus(0x3000) + 0x5000;
        v3.z += Rand_PlusMinus(0x1000) + 0x5000;
        func_02065f88(0x38f, &v3)->SetScaleXYZ(0x2ccd, 0x2ccd, 0x2ccd);
        func_0204a028(*(&data_02097e4c), 0x35, &v3, -(Rand_UpTo(5) + 2));
        func_02049f44(*(&data_02097e4c), 0x56, &v3, 0);
        func_ov000_0218996c(10, 0x1e);
        break;
    }
    }
}

}
