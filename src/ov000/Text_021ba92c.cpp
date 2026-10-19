#include "ov000/LoCommon.h"
#include "nitro/fx.h"

extern "C" {

typedef void (*VFunc)(void);

extern u8 *data_ov000_021ccd54;
extern u8 *data_02097ce0;
extern VFunc data_0208ba70[];
void *func_02061d64(u16 idx);
void func_0204c7d0(void *p);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);

typedef struct Ov000Text {
    VFunc *vtbl;
    u32 flags;
    u8 pad08[0x1c];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    u8 pad30[0x4];
    s16 unk_34;
    u8 pad36;
    s8 unk_37;
    s32 unk_38;
    u8 pad3c[0x8];
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
} Ov000Text;

static inline BOOL IsMode021ba92c(s32 m) {
    if (m == 0x14 || (u32)(m - 0x16) <= 1) {
        return TRUE;
    }
    return FALSE;
}

static inline s32 Wave021ba92c(const s16 *tbl, s32 n, s32 d) {
    s32 r = FX_Div((n < 0 ? 0 : n) << 12, d);
    if (r >= 0x1000) {
        r = 0x1000;
    }
    return tbl[((r << 14) >> 16) * 2];
}

s32 func_ov000_021ba92c(u8 *self) {
    switch (LFLD(s32, self, 4)) {
    case 1:
        LFLD(s32, self, 4) = 2;
    case 2:
        LFLD(s32, self, 4) = 4;
    case 4: {
        s32 m = LFLD(s32, data_ov000_021ccd54, 0x98);
        void *str;
        Ov000Text *t;
        if (!IsMode021ba92c(m) && (u32)(m - 0x11) > 2) {
            break;
        }
        str = func_02061d64(LFLD(u16, self, 8));
        t = (Ov000Text *)func_0203dd9c(0xb8);
        if (t != NULL) {
            t->vtbl = data_0208ba70;
            func_0204c7d0(t);
        }
        LFLD(Ov000Text *, self, 0x10) = t;
        t->unk_28 = 8;
        LFLD(Ov000Text *, self, 0x10)->unk_2c = 0;
        t = LFLD(Ov000Text *, self, 0x10);
        t->unk_24 = (s32)str;
        t->unk_4c = func_0204c4fc(t->unk_28, t->unk_38, t->unk_24, &t->unk_44, &t->unk_48, t->unk_37 != 0);
        LFLD(s32, data_02097ce0, 4) = t->unk_28;
        LFLD(VObj *, self, 0x10)->vfunc_14();
        LFLD(Ov000Text *, self, 0x10)->flags |= 0x40;
        LFLD(Ov000Text *, self, 0x10)->flags |= 0x1000000;
        LFLD(Ov000Text *, self, 0x10)->flags |= 0x40000000;
        LFLD(Ov000Text *, self, 0x10)->flags |= 4;
        LFLD(s32, self, 4) = 10;
        break;
    }
    case 10:
        LFLD(s32, self, 4) = 11;
    case 11:
        if (++LFLD(s32, self, 0x18) > 0x90) {
            LFLD(s32, self, 0x18) = 0;
            LFLD(s32, self, 4) = 12;
            break;
        }
        LFLD(s32, self, 0x1c) = Wave021ba92c(FX_SinCosTable_, LFLD(s32, self, 0x18), 0x30000);
        LFLD(s32, self, 0x20) = Wave021ba92c(FX_SinCosTable_, LFLD(s32, self, 0x18), 0x30000);
        LFLD(s32, self, 0x24) = Wave021ba92c(FX_SinCosTable_, LFLD(s32, self, 0x18) - 0x18, 0x30000);
        LFLD(s32, self, 0x28) = Wave021ba92c(FX_SinCosTable_, LFLD(s32, self, 0x18) - 0x48, 0x48000);
        break;
    case 12:
        if (++LFLD(s32, self, 0x18) > 0x30) {
            LFLD(s32, self, 0x18) = 0;
            LFLD(s32, self, 0x2c) = 0;
            LFLD(s32, self, 0x28) = 0;
            LFLD(s32, self, 0x24) = 0;
            LFLD(s32, self, 0x20) = 0;
            LFLD(s32, self, 0x1c) = 0;
            LFLD(s32, self, 4) = 13;
        }
        break;
    case 13: {
        s32 v;
        if (++LFLD(s32, self, 0x18) > 0x20) {
            LFLD(s32, self, 0x18) = 0;
            LFLD(s32, self, 4) = 17;
            break;
        }
        v = Wave021ba92c(FX_SinCosTable_, LFLD(s32, self, 0x18), 0x20000);
        LFLD(s32, self, 0x1c) = v;
        LFLD(s32, self, 0x20) = v;
        LFLD(s32, self, 0x24) = v;
        LFLD(s32, self, 0x28) = v;
        break;
    }
    case 17:
        return 0;
    }
    return 1;
}

}
