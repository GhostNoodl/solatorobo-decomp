#include "ov000/LoCommon.h"
#include "Main/Res/StageFlags.h"
#include "ov000/ObjLayouts.h"

extern "C" {
extern u8 data_ov000_021cb8e0[];
extern u8 *data_ov000_021ccd30;
void LangData_LocalizePath(char *buf, const void *s);
void *ResMgr_Load(const char *name, s32 a, s32 b);
BOOL ResMgr_IsLoaded(const char *name, s32 a);
void func_ov000_02164a94(Lo021cb6b0 *self);
void func_ov000_02167d64(Lo021cb6b0 *self);
void func_ov000_02166be8(Lo021cb6b0 *self);

void func_ov000_021645b8(Lo021cb6b0 *self) {
    switch (self->unk_20) {
    case 0: {
        char buf[0x20];
        LangData_LocalizePath(buf, data_ov000_021cb8e0);
        ResMgr_Load(buf, 7, 0);
        self->unk_20 = 1;
    }
    case 1: {
        char buf[0x20];
        LangData_LocalizePath(buf, data_ov000_021cb8e0);
        if (LBIT(data_ov000_021ccd30, 0x114).b0) {
            return;
        }
        if (!ResMgr_IsLoaded(buf, 7)) {
            return;
        }
        self->unk_20 = 2;
    }
    case 2:
        self->vfunc_0c();
        func_ov000_02164a94(self);
        self->unk_20 = 7;
        return;
    case 7: {
        s32 t = ((s32)data_0214a424->unk_020);
        s32 d = LO_FX_MUL((t - self->unk_50) << 12, 0xf6);
        if ((d < 0 ? -d : d) < 0x1000) {
            self->unk_50 = t;
        } else {
            self->unk_50 += d >> 12;
        }
        func_ov000_02167d64(self);
        func_ov000_02166be8(self);
        break;
    }
    }
}
}
