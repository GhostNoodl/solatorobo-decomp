#include "ov013/ov013.h"

extern "C" {

extern void *Ov013Act_02207968_vtbl;
extern Ov003Actor *ActorMgr_FindPlayer(void);

Ov013Act_02207968 *Ov013Act_02207968_Ctor(Ov013Act_02207968 *self) {
    Ov003Actor_Ctor(self);
    *(void **)self = &Ov013Act_02207968_vtbl;
    self->unk_f0 = 0;
    self->unk_f4 = 0;
    self->unk_f1 = 0;
    self->unk_f2 = 0;
    self->unk_110 = 0;
    self->unk_111 = 0;
    self->unk_f8.x = 0;
    self->unk_f8.y = 0;
    self->unk_f8.z = 0;
    self->unk_104.x = 0;
    self->unk_104.y = 0;
    self->unk_104.z = 0;
    return self;
}

void Ov013Act_02207968_Start(Ov013Act_02207968 *self) {
    ActorSub48 *m;
    Ov003Actor *p;
    Ov003Actor_Start(self);
    self->pos.x = -0x3000;
    self->pos.y = -0x32000;
    self->pos.z = -0x8000;
    Ov013_VecSet(&self->hit->offset, 0, -0x4cd, 0);
    m = self->hit;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    Ov013_VecSet(&self->unk_44->unk_0c, 0, -0x4cd, 0);
    self->target = 0xffff;
    p = ActorMgr_FindPlayer();
    if (p != NULL) {
        self->target = p->id;
    }
    self->unk_93_4 = 1;
    self->unk_94_1 = 1;
    self->unk_b6 = 0x46;
}

}
