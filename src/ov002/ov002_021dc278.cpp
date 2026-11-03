#include "ov002/ov002.h"

extern "C" {

void func_ov002_021dc730(Obj021eff10 *self);
void func_ov002_021dc83c(Obj021eff10 *self);
void func_ov002_021dcf00(Obj021eff10 *self);
void func_ov002_021dd130(Obj021eff10 *self);
void func_ov002_021dd29c(Obj021eff10 *self);
void func_ov002_021dd434(Obj021eff10 *self);
void func_ov002_021dd9dc(Obj021eff10 *self);

static inline void ov002_Anim_Tick(Ov002Mdl021efe3c *mdl) {
    s32 v = mdl->frame;
    if (mdl->anm[0] != NULL) {
        mdl->anm[0]->frame = v;
    }
    if (mdl->anm[1] != NULL) {
        mdl->anm[1]->frame = v;
    }
    if (mdl->anm[2] != NULL) {
        mdl->anm[2]->frame = v;
    }
    mdl->frame = (mdl->frame + 0x1000) % mdl->frameCount;
}

static inline BOOL ov002_Msg_IsDone(UiObj *m) {
    return m->state == 5;
}

void func_ov002_021dc278(Obj021eff10 *self, Obj021eff50 *other) {
    self->owner = other;
    ov002_Anim_Tick(&self->unk_14->mdl);
    if (self->unk_0c != NULL) {
        self->unk_0c->vfunc_1c();
    }
    {
        Obj021efe5c *m = self->unk_08;
        ov002_Anim_Tick(&m->mdl);
        m->unk_1d8 = (u16)(m->unk_1d8 + 1);
    }
    switch (self->unk_18 / 10 * 10) {
    case 0:
        func_ov002_021dc730(self);
        break;
    case 10:
        func_ov002_021dc83c(self);
        break;
    case 20:
        func_ov002_021dcf00(self);
        break;
    case 30:
        func_ov002_021dd130(self);
        break;
    case 40:
        func_ov002_021dd29c(self);
        break;
    case 50:
        func_ov002_021dd434(self);
        break;
    case 60:
        if (ov002_Msg_IsDone(self->unk_0c)) {
            s32 r = self->unk_1c;
            if (r == 1 || r == -1) {
                SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
            } else if (r == 0) {
                self->unk_18 = 0x46;
                break;
            } else if (r == 2) {
                func_ov002_021dd9dc(self);
            } else {
                break;
            }
            self->unk_18 = 10;
        }
        break;
    case 70: {
        Obj021efe6c *board = self->owner->board;
        s32 row = self->unk_28;
        Obj021efe4c *q = board->field;
        s32 col = self->unk_24;
        Ov002Cell *base;
        Ov002Cell *e;
        if (q == NULL || (base = board->cells) == NULL) {
            e = NULL;
        } else {
            e = &base[row * q->map->h + col];
        }
        if (e->unk_2 == 1) {
            Obj021efe9c *t = (Obj021efe9c *)e->obj;
            t->unk_cd = 0;
            t->unk_9c = 0xf85;
        } else if (e->unk_2 == 2) {
            ((Obj021efed4 *)e->obj)->unk_9c = 0;
        }
        {
            Obj021eff50 *o = self->owner;
            o->unk_10 = NULL;
            o->unk_0c = 0x28;
        }
        self->unk_18 = 0x50;
        break;
    }
    }
    self->owner = NULL;
}

}
