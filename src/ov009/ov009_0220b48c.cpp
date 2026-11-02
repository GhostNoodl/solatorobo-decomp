#include "ov009/ov009.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Snd/SndMgr.h"

extern "C" {


void Ov009ActVt_022176ec_Start(Ov009ActVt_022176ec *self) {
    func_ov003_021d112c(self);
    self->unk_f0 = self->pos;
    self->unk_ea |= 0x1000;
    if (self->hit->unk_54 & 0x400) {
        return;
    }
    func_ov003_021d6a3c(self, 1, 1, 0);
}

extern void func_0203f364(ActorSub48 *p);
extern Ov003Actor *func_ov000_0219bf90(void);
extern BOOL Hit_DiffInCylinder(VecFx32 *a, VecFx32 *b, fx32 r, fx32 h);
void Ov009ActVt_022176ec_Update(Ov009ActVt_022176ec *self) {
    ActorSub40 *st = self->fsm;
    ActorSub48 *s48;
    Ov003Actor *t;
    BOOL in;
    if (st->current != 0x15 && (self->hit->unk_50 & 0x20000000) && !(self->hit->unk_50 & 0x400) &&
        self->targetObj->target == 0xffff) {
        st->flags |= 0x200000;
        func_02049f44(data_02097e4c, 0x6c, &self->pos, 0);
        return;
    }
    s48 = self->hit;
    s48->unk_9a_0 = 0;
    s48->unk_9a_3 = 0;
    func_0203f364(s48);
    if (!Ov009_GameIdle()) {
        return;
    }
    self->target = 0xffff;
    t = func_ov000_0219bf90();
    if (t != NULL) {
        self->target = t->id;
    }
    in = FALSE;
    if (t != NULL && t->hit != NULL && (t->hit->unk_54 & 0x400)) {
        in = TRUE;
    }
    if (in) {
        VecFx32 v;
        v.x = t->pos.x;
        v.y = t->pos.y;
        v.z = t->pos.z;
        self->unk_b8 = v;
        if (!Hit_DiffInSphere(&self->pos, &v, self->radius + 0x1800)) {
            self->fsm->flags |= 4;
            return;
        }
        self->fsm->flags |= 0x8000;
        return;
    }
    {
        VecFx32 p;
        p.x = self->unk_f0.x;
        p.y = self->unk_f0.y;
        p.z = self->unk_f0.z;
        p.y -= 0xa000;
        if (Hit_DiffInCylinder(&self->pos, &p, self->radius + 0x1000, 0x14000)) {
            return;
        }
    }
    self->unk_b8 = self->unk_f0;
    self->fsm->flags |= 4;
}

}
