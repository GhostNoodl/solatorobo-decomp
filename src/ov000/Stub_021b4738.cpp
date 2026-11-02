#include "ov000/ObjLayouts.h"
#include "ov000/MessageQueue.h"
#include "Main/Res/StageFlags.h"

extern "C" {

extern char data_ov000_021cc5e3[];
extern MessageQueue021cb980 *data_ov000_021ccd30;
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_021697dc(Lo021cb798 *self, u16 a, u16 b);
BOOL func_ov000_02198360(void *a, s32 b, s32 c);

u16 func_ov000_02198da8(ActorSub48 *body, u16 angle);

BOOL func_ov000_021b468c(Robo021ca458 *self) {
    BOOL r = FALSE;
    if (self->unk_b24_12 == 0) {
        ActorSub48 *body = self->hit;
        if ((body->unk_50 & 0x40000000) || body->unk_58 != 0) {
            if (!self->unk_b24_18) {
                self->moveYaw = func_ov000_02198da8(body, self->moveYaw);
                self->speed = 0x8a;
                if (self->hit->unk_84 > 0x400 || self->hit->unk_58 != 0) {
                    self->speed = 0x229;
                    if (self->velY < -0xcd) {
                        self->velY = -0xcd;
                    }
                }
            }
            self->unk_b24_16 = 1;
            r = TRUE;
        }
    }
    return r;
}

u8 func_0206d204(void *p, s32 a);

BOOL func_ov000_021b4738(Actor *self) {
    BOOL r = FALSE;
    s32 x = func_0206d204(data_0214a424, 0);
    if (self->hp[0] == 0 && x == 0) {
        r = TRUE;
    }
    return r;
}

void func_ov000_021b4774(Robo021ca458 *self) {
    u16 *p;
    u16 v;
    ListBuffer021cb940 *o;

    func_ov000_02190cb0(self->model, data_ov000_021cc5e3, 0x400, 0);
    self->unk_b24_0 = 0;
    p = self->hp;
    v = p[1];
    p[0] = v;
    o = data_ov000_021ccd30->unk_11c;
    if (o != NULL && o->unk_58 != NULL) {
        o->unk_58->unk_0c_7 = 0;
        func_ov000_021697dc(o->unk_58, v, v);
        o->unk_58->unk_0c_7 = 1;
    }
    self->model->visible = 1;
    self->unk_3c->unk_19 = 0xff;
    func_ov000_02198360(self->fsm, 1, 0);
}

}
