#include "ov014/ov014.h"

extern "C" {

extern u8 data_ov014_02217a48[];
extern u8 data_ov014_02217a4e[];
extern u8 data_ov014_02217a54[];
extern void func_ov000_021911c8(void *a, s32 b);
extern BOOL func_02049244(Ov014Vec *out, s32 speed, const Ov014Vec *from, const Ov014Vec *to, s32 minDist);

void func_ov014_0220a588(Ov014Actor *self) {
    if (self->unk_40->state == 0) {
        const void *anim;
        anim = data_ov014_02217a48;
        if (FLD(u8, self, 0x1a5) == 0) {
            anim = data_ov014_02217a4e;
        }
        if (self->unk_ee_0) {
            anim = data_ov014_02217a54;
        }
        func_ov000_02190cb0(self->unk_38, anim, 0xcd, 0);
        func_ov000_021911c8(self->unk_38, 0xc00);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
    if (FLD(u8, self, 0x1a5) == 0) {
        func_02049244(&self->pos, 0xcd, &self->pos, (Ov014Vec *)((u8 *)self + 0x1a8), 0xcd);
    } else if (self->unk_48->unk_9a_4) {
        self->unk_48->unk_9a_5 = 1;
        if (!(self->unk_48->unk_50 & 0x20000000)) {
            func_ov000_02198360(self->unk_40, 4, 0);
        }
    }
}

}
