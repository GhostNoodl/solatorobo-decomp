#include "ov000/VObj.h"
#include "Main/Res/StageCmd.h"
#include "ov000/ObjLayouts.h"
#include "ov000/LoCommon.h"
#include "ov000/Actor.h"

extern "C" {

void func_ov000_02199dc0(ActorSub4c *self, Actor *out) {
    s32 d = self->unk_50;
    s32 x, y, w;
    w = 0x52;
    if (d == 0) {
        if (self->type == 0xf || self->type == 0x13) {
            x = 0x31f;
            y = 0x31f - 0x52;
        } else {
            x = 0x348;
            y = 0x348 - 0x7b;
        }
    } else {
        s32 e = self->unk_54;
        s64 q = 0x6cd000LL / (d + ABS(e));
        x = (s32)((q * (d + 0x52) + 0x800) >> 12);
        y = (s32)((q * e + 0x800) >> 12);
        w = 0x14;
    }
    x += self->unk_58;
    if (out != NULL) {
        out->speed = x;
        out->velY = y;
        out->friction = 0;
        out->gravity = w;
    }
}


}
