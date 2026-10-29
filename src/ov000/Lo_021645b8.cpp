#include "ov000/LoCommon.h"

extern "C" {
extern u8 data_ov000_021cb8e0[];
extern u8 *data_ov000_021ccd30;
extern u8 *data_0214a424;
void func_0206e900(char *buf, const void *s);
void *func_020359d0(const char *name, s32 a, s32 b);
BOOL func_02035b90(const char *name, s32 a);
void func_ov000_02164a94(void *self);
void func_ov000_02167d64(void *self);
void func_ov000_02166be8(void *self);

void func_ov000_021645b8(VObj *self) {
    switch (LFLD(s32, self, 0x20)) {
    case 0: {
        char buf[0x20];
        func_0206e900(buf, data_ov000_021cb8e0);
        func_020359d0(buf, 7, 0);
        LFLD(s32, self, 0x20) = 1;
    }
    case 1: {
        char buf[0x20];
        func_0206e900(buf, data_ov000_021cb8e0);
        if (LBIT(data_ov000_021ccd30, 0x114).b0) {
            return;
        }
        if (!func_02035b90(buf, 7)) {
            return;
        }
        LFLD(s32, self, 0x20) = 2;
    }
    case 2:
        self->vfunc_0c();
        func_ov000_02164a94(self);
        LFLD(s32, self, 0x20) = 7;
        return;
    case 7: {
        s32 t = LFLD(s32, data_0214a424, 0x20);
        s32 d = LO_FX_MUL((t - LFLD(s32, self, 0x50)) << 12, 0xf6);
        if ((d < 0 ? -d : d) < 0x1000) {
            LFLD(s32, self, 0x50) = t;
        } else {
            LFLD(s32, self, 0x50) += d >> 12;
        }
        func_ov000_02167d64(self);
        func_ov000_02166be8(self);
        break;
    }
    }
}
}
