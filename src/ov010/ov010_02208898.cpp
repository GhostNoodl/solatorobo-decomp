#include "ov010/ov010.h"

extern "C" {

extern u8 data_ov010_0220f394[];
extern u8 data_ov010_0220f310[];
extern u8 data_ov010_0220f1d0[];
extern BOOL Ov003Sequence_HasEntries(void *p, void *a);

static inline void Ov010_PlayAnim(Ov010Obj0220ffe4 *self, void *anim, s32 n) {
    if (!Ov003Sequence_HasEntries(&self->seq, anim)) {
        Ov003Sequence_SetEntries(&self->seq, anim, n);
    }
}

void Ov010Obj0220ffe4_PlayHpAnim(Ov010Obj0220ffe4 *self) {
    u16 *hp = self->hp;
    s32 r = (hp[0] << 12) / hp[1];
    if (r <= 0x733) {
        Ov010_PlayAnim(self, data_ov010_0220f394, 0x1e);
    } else if (r <= 0xccd) {
        Ov010_PlayAnim(self, data_ov010_0220f310, 0x16);
    } else if (r <= 0x1000) {
        Ov010_PlayAnim(self, data_ov010_0220f1d0, 0xd);
    }
}

BOOL Ov010Obj0220ffe4_GetType(Ov010Obj0220ffe4 *self, s32 *out) {
    *out = 9;
    return TRUE;
}

void Ov010Obj0220ffe4_GetSfxIds(Ov010Obj0220ffe4 *self, s32 *out) {
    out[0] = 0x905;
    out[1] = 0x906;
    out[2] = 0x904;
    out[3] = 0x900;
    out[4] = 0x903;
    out[5] = 0x900;
    out[7] = 0x902;
}

void Ov010ActVt_0221009c_Start(Ov010Obj0221009c *self) {
    Ov010ActVt_02210154_Start(self);
    self->unk_f3 = self->unk_18 == 2;
}

}
