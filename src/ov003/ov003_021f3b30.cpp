#include "types.h"
#include "Main/Effect/Effect.h"
#include "nitro/std.h"
#include "ov003/Prop.h"
#include "Main/Res/StageFlags.h"


extern "C" {
extern s32 Rand_PlusMinus(s32 max);
extern u32 Rand_UpTo(u32 max);

void Ov003ActVt_021fa5a0_RunState(Ov003Prop021fa5a0 *self) {
    EffectObj *e;
    s32 id;
    s32 s;
    s32 a;
    s32 b;
    self->unk_2d0++;
    if (!(self->unk_2d0 & 0x3f)) {
        e = func_02065f88(0x325, &self->pos);
        if (e != NULL) {
            e->SetRotXYZ(0xc000, 0, 0);
            e->SetScaleXYZ(0x666, 0x733, 0x666);
            a = Rand_PlusMinus(0x8cd);
            b = Rand_PlusMinus(0x8cd);
            e->AddPosXYZ(a, 0x59a, b);
        }
    }
    if ((self->unk_2d0 & 0x7f) != 0x10) {
        return;
    }
    id = 0x322;
    if (Rand_UpTo(3) == 0) {
        id = 4;
    }
    e = func_02065f88(id, &self->pos);
    if (e == NULL) {
        return;
    }
    s = Rand_PlusMinus(0x19a) + 0x666;
    e->SetScaleXYZ(s, s, s);
    a = Rand_PlusMinus(0xb33);
    b = Rand_UpTo(0x1000 - 0xb33);
    e->AddPosXYZ(a, b + 0x800, Rand_PlusMinus(0xb33));
}

}
