#include "ov009/ov009.h"

extern "C" {

extern void func_0203f364(Ov009Sub48 *p);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern u16 func_ov000_02199e94(void *p);
extern void func_ov000_0219aae8(Ov009Actor *self, Ov009Actor *src, s32 a, s32 b, s32 c, const Ov009Vec *d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov003_021d6a3c(Ov009Actor *self, s32 a, s32 b, s32 c);

void func_ov009_0220acb8(Ov009Actor *self) {
    Ov009Vec sv;
    Ov009Sub40 *st;
    Ov009Sub44 *s44;
    Ov009V *e;
    Ov009Sub48 *s48;
    s32 h;
    switch (self->unk_40->state) {
    case 0: {
        *self->unk_50 = 0;
        s48 = self->unk_48;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        e = func_02065f88(3, &self->pos);
        h = self->unk_64 + FLD(u16, self, 0xf0) * 8;
        e->v0c(h);
        sv.x = 0;
        sv.y = h;
        sv.z = 0;
        e->v20(&sv);
        func_ov000_0219aae8(self, self, (u16)(func_ov000_02199e94(FLD(void *, self, 0x4c)) + ((u32)(FLD(u16, self, 0xf0) << 14) >> 16)), 0x20, 0, &sv, 0, h + 0x1333, 0, 0x64, 0x1000);
        func_ov000_0218996c(10, 0x19);
        FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
        self->unk_40->state++;
        break;
    }
    case 1: {
        st = self->unk_40;
        st->timer++;
        if (st->timer <= 0x1e) {
            FLD(u8, self->unk_38, 0xbe) = 0x1f - self->unk_40->timer;
            return;
        }
        func_ov003_021d6a3c(self, 1, 0, 0);
        break;
    }
    }
}

}
