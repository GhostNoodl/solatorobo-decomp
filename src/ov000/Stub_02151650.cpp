#include "ov000/VObj.h"

extern "C" {

void LoStatusWin_Draw(void *obj, s32 a, s32 *pos, s32 c);

s32 func_ov000_02151610(VObj *self, s32 a, s32 b, s32 c) {
    LoStatusWin_Draw(*(void **)((u8 *)self + 8), a, (s32 *)b, c);
    self->vfunc_24(a, b, c);
    return 0;
}

s32 func_ov000_02151650(VObj *self, s32 a, s32 b, s32 c) {
    return self->vfunc_60(a, b, c);
}

}
