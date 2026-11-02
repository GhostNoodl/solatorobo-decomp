#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern u8 data_ov009_022172af[];
extern u8 data_ov009_022172bb[];
extern s32 func_02040498(s32 max);
extern u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
extern void func_ov000_02191418(void *m, s32 a, s32 b);
extern BOOL func_ov000_02191508(void *m);
extern void func_ov000_0218dbe0(Ov009Obj *self, s32 turn);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
void func_ov009_0220b258(Ov009ActVt_022172e4 *self) {
    Ov009Sub40 *st = self->unk_40;
    Ov009Sub44 *s44;
    switch (st->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_022172af, 0x400, 1);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
        break;
    case 1:
        if (self->unk_38->unk_e4 & 0x80) {
            self->rot[1] = self->unk_fc;
            self->unk_98 = self->rot[1];
        } else {
            self->rot[1] = func_01ffc128(self->unk_fc, self->rot[1], 0x400, 1, 0x8000);
        }
        if (self->unk_38->unk_e4 & 0x8000000) {
            func_ov000_02191418(self->unk_38, 3, 0);
        }
        if (!func_ov000_02191508(self->unk_38)) {
            func_ov000_0218dbe0(self, 0);
        }
        if (self->unk_a0 < 0 && (self->unk_48->unk_50 & 0x20000000)) {
            self->unk_a0 = 0;
            self->unk_a8 = 0;
            func_ov000_02190cb0(self->unk_38, data_ov009_022172bb, 0x200, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_40->state++;
            self->unk_40->timer = func_02040498(0x14) + 0x28;
            self->unk_a4 = 0xc00;
            self->unk_fc += 0x8000;
            func_02065f88(0x2bc, &self->pos);
            func_02065f88(0x2bd, &self->pos);
            func_02049f44(data_02097e4c, 0x3d, &self->pos, 0);
        }
        break;
    case 2:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            self->unk_fe++;
            if (self->unk_fe <= 1) {
                self->unk_40->state = 0;
            } else {
                self->unk_fe = 0;
                func_ov000_02198360(self->unk_40, 1, 0);
            }
        }
        self->unk_48->unk_9a_5 = 1;
        break;
    }
    if (!(self->unk_48->unk_50 & 0x20000000)) {
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
    }
}

}
