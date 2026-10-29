#include "ov014/ov014.h"

extern "C" {

extern Ov014Actor *func_ov000_0219bf90(void);
extern void func_ov014_021fe0dc(Ov014Actor *self);
extern void func_ov014_021fe210(Ov014Actor *self);
extern s32 func_ov003_021d1c00(Ov014Actor *self, Ov014Msg *msg);
extern void *func_ov003_021ceff4(void *p);
extern void func_ov000_0219bd20(s32 a, u16 b, s32 c, s32 d, s32 e, u8 *f);
extern u16 func_ov003_021d9edc(s32 a);

void func_ov014_021fdedc(Ov014Actor *self) {
    if (!Ov014_GameIdle()) {
        return;
    }
    {
        Ov014Actor *a;
        self->unk_90 = 0xffff;
        a = func_ov000_0219bf90();
        if (a != NULL) {
            self->unk_90 = a->id;
        }
    }
    if (self->unk_40->unk_13 == 1 && self->unk_93_4) {
        s32 f = FLD(s32, self, 0xf4);
        if (f == 0) {
            switch (FLD(s16, self, 0xf0)) {
            case 0:
                func_ov014_021fe0dc(self);
                break;
            case 1:
                func_ov014_021fe210(self);
                break;
            }
        } else if ((f & 1) && FLD(u8, self, 0x138) == 0) {
            u16 lim = 30;
            u8 *p = FLD(u8 *, self, 0x13c);
            if (p != NULL) {
                lim = FLD(u16, p, 6);
            }
            self->unk_b6++;
            if (self->unk_b6 >= lim) {
                FLD(s32, self, 0xf4) ^= 1;
                self->unk_b6 = 0;
            }
        }
    }
    func_ov003_021dacfc(FLD(void *, self, 0xfc));
}

s32 func_ov014_021fe008(Ov014Actor *self, Ov014Msg *msg) {
    switch (msg->type) {
    case 6: {
        u8 v = msg->idx;
        u16 n = v - 3;
        FLD(u8, self, 0xf8) = v;
        switch (n) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4: {
            u8 bit = 1 << n;
            if (FLD(u8, self, 0x138) & bit) {
                FLD(u8, self, 0x138) ^= bit;
            }
            FLD(u8, self, 0xf8) = 0xff;
            FLD(s32, self, 0xf4) = 1;
            break;
        }
        }
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
        break;
    }
    case 14:
        FLD(u8, self, 0x138) |= (u8)(1 << FLD(s16, msg, 8));
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
        break;
    }
    return func_ov003_021d1c00(self, msg);
}

void func_ov014_021fe0dc(Ov014Actor *self) {
    u8 c;
    Ov014Sub40 *st;
    switch (FLD(u16, self, 0xb4)) {
    case 0:
        if (FLD(u8, self, 0x138) == 0) {
            u8 *t = FLD(u8 *, self, 0x14c);
            FLD(u8 *, self, 0x13c) = FLD(u8 *, t, 0xc) + FLD(u16, t, 8) * 8;
            func_ov003_021ceff4((u8 *)self + 0x140);
            c = *FLD(s16 *, self, 0x13c);
            func_ov000_0219bd20(0x5c19, self->kind, 0xe, 1, 1, &c);
            self->unk_40->timer = 0;
            FLD(u16, self, 0xb4)++;
        }
        break;
    case 1:
        st = self->unk_40;
        st->timer++;
        if (st->timer < 10) {
            if (FLD(u8, self, 0xf8) == 2) {
                FLD(u8, self, 0xf8) = 0xff;
                FLD(s32, self, 0xf4) |= 0x100000;
                self->unk_40->timer = 0;
                FLD(u16, self, 0xb4) = 0;
            }
        } else {
            self->unk_40->timer = 0;
            FLD(u16, self, 0xb4) = 0;
        }
        break;
    }
    if (!(FLD(s32, self, 0xf4) & 0x1000) && !func_ov003_021d9edc(0x5c19)) {
        FLD(s32, self, 0xf4) |= 0x1000;
        func_ov000_02198360(self->unk_40, 0x15, 0);
    }
}

}
