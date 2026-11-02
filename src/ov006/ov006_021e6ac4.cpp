#include "ov006/Tasks.h"
#include "Main/Effect/Effect.h"
#include "ov006/Racer.h"


extern "C" {

extern const u16 data_ov006_021eb89c[];

BOOL func_ov000_0218d494(Actor *self, ActorMsg *msg);

static inline void Ov006Racer_Ack(Ov006Racer *self, ActorMsg *msg) {
    self->msg_flags |= 1 << msg->type;
    msg->type = 0;
}

BOOL func_ov006_021e6ac4(Ov006Racer *self, ActorMsg *msg) {
    BOOL pass;
    if (!self->vfunc_14()) {
        Ov006Racer_Ack(self, msg);
        return TRUE;
    }
    pass = TRUE;
    switch (msg->type) {
    case 9:
        pass = FALSE;
        if (self->unk_1f5 == 0 && self->unk_1f8 == 0) {
            Model0218fe1c *c;
            self->fsm->flags |= 0x40000;
            c = self->model;
            self->unk_1f5 = msg->hit.kind == 0x10 ? 0x37 : 0x64;
            c->color = 0x14bf;
            c->color2 = 0x739f;
            c->blend = 0xb;
            c->blendMax = 0xa;
        }
        break;
    case 11:
        pass = FALSE;
        if (msg->id != self->id) {
            u16 v = data_ov006_021eb89c[self->rank];
            if (self->unk_1fa < v) {
                self->unk_1fa = v;
            }
            if (self->idx == data_ov006_021ec884->unk5) {
                EffectObj *e = func_02065f88(0x648, &self->pos);
                if (e != NULL) {
                    EffectObj *old;
                    e->SetScaleAll(0x1800);
                    e->speed = 0x1800;
                    old = func_020657b0(data_0214a420, self->unk_1ec);
                    if (old != NULL) {
                        EffectObj_StopLoop(old);
                        old->state = 4;
                    }
                    self->unk_1ec = e->id;
                }
                func_02049f44(data_02097e4c, 0x41, &self->pos, 0);
            }
        }
        break;
    }
    if (pass && func_ov000_0218d494(self, msg)) {
        return TRUE;
    }
    Ov006Racer_Ack(self, msg);
    return TRUE;
}

}
