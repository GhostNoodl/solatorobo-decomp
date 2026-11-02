#include "ov000/ObjLayouts.h"
#include "Main/Res/StageFlags.h"

extern "C" {

void func_ov000_021b209c(Robo021ca458 *self);
void Actor_Move(Actor *self, s32 a);
void func_ov000_021987b8(ActorSub48 *p, s32 a, s32 b, s32 c);

void func_ov000_021b1fac(Robo021ca458 *self, BOOL a, s32 b) {
    s32 ox;
    s32 oy;
    if (self->unk_b24_12) {
        func_ov000_021b209c(self);
        return;
    }
    ox = self->pos.x;
    oy = self->pos.y;
    if (a) {
        self->hit->unk_9a |= 0x20;
    }
    Actor_Move(self, 0);
    if (ox != self->pos.x || oy != self->pos.y) {
        s32 t = self->unk_ba8 + self->speed;
        self->unk_ba8 = t;
        if (t > 0x1000) {
            StageFlags *g = data_0214a424;
            u32 v = g->unk_010 + ((u32)t >> 12);
            if (v >= 999999) {
                g->unk_010 = 999999;
            } else {
                g->unk_010 = v;
            }
            self->unk_ba8 &= 0xfff;
        }
    }
    func_ov000_021987b8(self->hit, b, 0, 0);
    if (self->velY < 0 && (self->hit->unk_50 & 0x20000000)) {
        self->velY = 0;
    }
}

}
