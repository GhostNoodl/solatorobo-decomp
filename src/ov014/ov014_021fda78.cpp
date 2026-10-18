#include "ov014/ov014.h"

extern "C" {

extern s32 func_ov014_021fe008(Ov014Actor *self, Ov014Msg *msg);
extern s32 func_ov003_021d1c00(Ov014Actor *self, Ov014Msg *msg);

s32 func_ov014_021fda78(Ov014Actor *self, Ov014Msg *msg) {
    s32 r = 0;
    switch (FLD(s16, self, 0xf0)) {
    case 0:
        r = func_ov014_021fe008(self, msg);
        break;
    case 1:
        if (msg->type == 6) {
            FLD(u8, self, 0xf8) = msg->idx;
            switch (FLD(u16, msg, 6)) {
            case 0x482b:
                break;
            case 0x580c:
            case 0x580d:
            case 0x580e: {
                u16 n = FLD(u8, self, 0xf8) - 1;
                if (!(n != 0 && n != 1 && n != 2)) {
                    u8 bit = 1 << n;
                    if (FLD(u8, self, 0x138) & bit) {
                        FLD(u8, self, 0x138) ^= bit;
                    }
                    FLD(u8, self, 0xf8) = 0xff;
                    FLD(s32, self, 0xf4) |= 1;
                }
                break;
            }
            }
            self->unk_30 |= 1 << msg->type;
            msg->type = 0;
            r = 0;
        } else {
            r = func_ov003_021d1c00(self, msg);
        }
        break;
    }
    return r;
}

}
