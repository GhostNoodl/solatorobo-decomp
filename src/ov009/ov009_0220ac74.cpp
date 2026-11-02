#include "ov009/ov009.h"

extern "C" {


void func_ov009_0220ac74(Ov009ActVt_02217390 *self) {
    func_ov003_021d3d28(self);
    if (self->target != 0xffff) {
        return;
    }
    if (self->hit->unk_54 & 0x20000000) {
        return;
    }
    func_ov000_02198360(self->fsm, 0x15, 0);
}

}

#ifdef NONMATCHING
// Status (round drA): func_ov009_0220acb8 is 15 / 13 (raw / register-masked, dsi/1.3 with the project flags); this
// is the best clean draft. Blocker: the ROM computes y + 0x1333 before the unk_f0 load and colours the stack-
// argument constants 0x64/0x1000 ip/r3 (ours r3/r1). History: docs/MATCHING.md rounds qpC, nmA, mtA, cvA (search for
// the address); the full list is docs/UNMATCHED.md.
// func_ov009_0220acb8 (state handler of the vtable data_ov009_02217390 actor): 15 raw (round mtA; qpC's
// scratch draft was 47 with a (u16) cast on the 0xf0 angle term, nmA found 15 without it). This file's .text
// ends at 0x0220acb8, so the function belongs here once it matches. Left: the ROM computes y + 0x1333 before
// the unk_f0 load and colours the stack-argument constants 0x64/0x1000 ip/r3 (ours r3/r1, materialized just
// before their stores). Typing self as the class (unk_f0 a field, unk_4c read as the u8 * field or a void *
// cast), a direct call instead of Ov009_Blast, or the radius as Ov009_Blast's first argument changes nothing.
extern "C" {

extern void func_0203f364(ActorSub48 *p);
extern Ov009V *func_02065f88(s32 id, VecFx32 *pos);
extern u16 func_ov000_02199e94(void *p);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 mask, const VecFx32 *v, void *e, s32 f, s32 g, s16 h, s32 i);
extern void func_ov000_0218996c(s32 a, s32 b);

static inline u16 Ov009_Tick(ActorSub40 *s) {
    s->timer++;
    return s->timer;
}

static inline u16 Ov009_Ang(Ov009ActVt_02217390 *self) {
    return func_ov000_02199e94(self->targetObj) + ((u32)(self->unk_f0 * 0x4000) >> 16);
}

static inline void Ov009_Blast(Ov009ActVt_02217390 *self, u16 ang, const VecFx32 *v, s32 r) {
    func_ov000_0219aae8(self, self, ang, 0x20, 0, v, 0, r, 0, 0x64, 0x1000);
}

void func_ov009_0220acb8(Ov009ActVt_02217390 *self) {
    switch (self->fsm->st) {
    case 0: {
        Ov009V *e;
        s32 y;
        VecFx32 v;
        ActorSub48 *s48;
        ActorSub44 *s44;
        *self->hp = 0;
        s48 = self->hit;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        e = func_02065f88(3, &self->pos);
        y = self->radius + self->unk_f0 * 8;
        e->v0c(y);
        v.x = 0;
        v.y = y;
        v.z = 0;
        e->v20(&v);
        Ov009_Blast(self, Ov009_Ang(self), &v, y + 0x1333);
        func_ov000_0218996c(10, 0x19);
        self->targetObj->target = 0xffff;
        self->fsm->st++;
        break;
    }
    case 1:
        if (Ov009_Tick(self->fsm) > 0x1e) {
            func_ov003_021d6a3c(self, 1, 0, 0);
        } else {
            self->model->alpha = 0x1f - self->fsm->timer;
        }
        break;
    }
}

}
#endif
