#include "ov014/ov014.h"

extern "C" {

extern char data_ov014_02217a4e[];
extern char data_ov014_02217a72[];
extern void *func_ov000_02191318(void *a, s32 b);
extern void func_ov000_02191618(void *p);
extern void func_ov000_021911c8(void *a, s32 b);
extern void func_ov014_0220a2d0(Ov014Act_02209280 *self, s32 a);

static inline void Ov014_TickA(ActorSub40 *st) {
    u16 t = ActorSub40_Timer(st);
    if (t != 0) {
        st->timer = t - 1;
    }
}

void func_ov014_0220abf8(Ov014Act_02209280 *self) {
    switch (self->fsm->st) {
    case 0: {
        u32 mask = 0;
        const Ov003Step *p;
        func_ov000_02190cb0(self->model, data_ov014_02217a72, 0x2ab, 0);
        func_ov000_021911c8(self->model, 0x1000);
        func_ov000_02191318(self->model, 0);
        func_ov000_02191618(self->model);
        p = self->step;
        self->unk_fc = 1;
        self->unk_f8 = p->a;
        switch (p->op) {
        case 0:
            self->unk_f4 = 0xffff;
            break;
        case 1:
            self->unk_f4 = mask;
            break;
        case 2: {
            u8 n = p->a - 1;
            if (n <= 31) {
                mask |= 1 << (u8)Rand_UpTo(n);
            }
            self->unk_f4 = mask;
            break;
        }
        case 3: {
            u8 n = p->a - 1;
            if (n <= 31) {
                u8 k;
                for (k = 2; k != 0; k--) {
                    u8 r = Rand_UpTo(n);
                    while (mask & (1 << r)) {
                        r++;
                        r %= n + 1;
                    }
                    mask |= 1 << r;
                }
            }
            self->unk_f4 = mask;
            break;
        }
        case 4: {
            u8 n = p->a - 1;
            if (n <= 31) {
                u8 k;
                for (k = 3; k != 0; k--) {
                    u8 r = Rand_UpTo(n);
                    while (mask & (1 << r)) {
                        r++;
                        r %= n + 1;
                    }
                    mask |= 1 << r;
                }
            }
            self->unk_f4 = mask;
            break;
        }
        default:
            self->unk_f4 = 0;
            break;
        }
        self->fsm->st++;
        break;
    }
    case 1: {
        FieldState *g;
        EffectObj *e;
        if (self->model->anim_state == 3) {
            e = func_02065f88(0x648, &self->pos);
            e->SetScaleAll(0x3000);
            e->loopCount = 2;
            func_02049f44(data_02097e4c, 0xc00, &self->pos, 0);
        }
        if (self->model->anim_state != 1) {
            return;
        }
        e = func_02065f88(0x66, &self->pos);
        e->AddPosXYZ(0, 0x4000, 0);
        e->SetScaleAll(0x4000);
        e->SetRotXYZ(0x3fff, 0, 0);
        func_02049f44(data_02097e4c, 0xc06, &self->pos, 0);
        g = data_ov000_021ccd54;
        g->cam.base.shakeX = 1;
        g->cam.base.shakeY = 1;
        g->cam.base.shakeZ = 1;
        g->cam.base.shakeTime = 10;
        g->cam.base.shakeLen = 10;
        g->cam.base.shakeCur = 10;
        self->fsm->st++;
        break;
    }
    case 2:
        func_ov014_0220a2d0(self, (self->unk_f4 & (1 << (self->unk_f8 - 1))) ? 1 : 0);
        self->unk_f8--;
        if (self->unk_f8 == 0) {
            self->fsm->st = 4;
            return;
        }
        self->fsm->st++;
        self->fsm->timer = self->step->time;
        break;
    case 3: {
        ActorSub40 *st = self->fsm;
        if (st->timer == 0) {
            if (func_ov000_02191120(self->model)) {
                func_ov000_02190cb0(self->model, data_ov014_02217a4e, 0xcd, 0);
                func_ov000_021915a0(self->model);
            }
            self->fsm->st--;
            break;
        }
        Ov014_TickA(st);
        break;
    }
    case 4:
        self->fsm->st = 0xffff;
        self->unk_fc = 1;
        break;
    }
}

extern void func_ov014_0220c09c(Ov014Act_02209280 *self);
extern void func_ov014_0220cd74(Ov014Act_02209280 *self);

void func_ov014_0220afb8(Ov014Act_02209280 *self) {
    switch (self->step->op) {
    case 9:
        func_ov014_0220c09c(self);
        break;
    case 10:
        func_ov014_0220cd74(self);
        break;
    }
}


extern char data_ov014_02217a4e[];
extern char data_ov014_02217a78[];
extern char data_ov014_02217a7e[];
extern void *func_ov000_02191318(void *a, s32 b);
extern void func_ov000_02191618(void *p);
extern void func_ov000_021911c8(void *a, s32 b);
extern void func_ov014_02209fa0(Ov014Act_02209280 *self, s16 a, s32 b);

void func_ov014_0220afe8(Ov014Act_02209280 *self) {
    ActorSub40 *st = self->fsm;
    switch (st->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov014_02217a4e, 0x2ab, 0);
        func_ov000_02191318(self->model, 0);
        func_ov000_021915a0(self->model);
        self->unk_fc = 1;
        self->fsm->st++;
        break;
    case 1: {
        FieldState *g = data_ov000_021ccd54;
        g->cam.base.shakeX = 1;
        g->cam.base.shakeY = 1;
        g->cam.base.shakeZ = 1;
        g->cam.base.shakeTime = 10;
        g->cam.base.shakeLen = 10;
        g->cam.base.shakeCur = 10;
        func_02049f44(data_02097e4c, 0xc03, &self->pos, 0);
        self->fsm->st++;
        self->fsm->timer = 0x28;
        break;
    }
    case 2:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            self->fsm->st = 10;
        }
        break;
    case 10:
        self->unk_f4 = 0;
        func_ov000_02190cb0(self->model, data_ov014_02217a78, 0x2ab, 0);
        func_ov000_02191318(self->model, 0);
        func_ov000_02191618(self->model);
        switch (self->step->op) {
        case 5:
            self->unk_f8 = 3;
            break;
        case 6:
            self->unk_f8 = 3;
            break;
        case 7:
            self->unk_f8 = 2;
            break;
        }
        self->fsm->st++;
        break;
    case 11: {
        FieldState *g;
        if (self->model->anim_state != 1) {
            break;
        }
        func_02049f44(data_02097e4c, 0xc04, &self->pos, 0);
        self->model->anim_state = 0;
        g = data_ov000_021ccd54;
        g->cam.base.shakeX = 1;
        g->cam.base.shakeY = 1;
        g->cam.base.shakeZ = 1;
        g->cam.base.shakeTime = 5;
        g->cam.base.shakeLen = 7;
        g->cam.base.shakeCur = 7;
        func_ov014_02209fa0(self, (s16)self->step->a, self->step->op);
        self->unk_f8--;
        self->unk_f4 ^= 1;
        self->fsm->st++;
        self->fsm->timer = 0;
    }
    case 12:
        if (self->unk_f8 != 0) {
            s32 v;
            func_ov000_02190cb0(self->model, ((s32)self->unk_f4) != 0 ? data_ov014_02217a7e : data_ov014_02217a78, 0xcd, 0);
            v = FX_Div(0x50000, self->step->time << 12);
            if (v > 0x2000) {
                v = 0x2000;
            } else if (v < 0x800) {
                v = 0x800;
            }
            func_ov000_021911c8(self->model, (s16)v);
            func_ov000_02191318(self->model, 0);
            func_ov000_02191618(self->model);
            self->fsm->st = 11;
        } else if (func_ov000_02191120(self->model)) {
            self->fsm->st = 0x14;
        }
        break;
    case 20:
        self->unk_fc = 0;
        self->fsm->st = 0xffff;
        break;
    }
}

}
