#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "nitro/fx.h"
#include "Main/Gfx/GfxMgr.h"

extern "C" {

typedef void (*VFunc)(void);

extern VFunc data_0208ba70[];
void *func_02061d64(u16 idx);
void func_0204c7d0(void *p);
s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);

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

struct Obj021ba92c {
    u8 unk_00[0x4];
    s32 unk_04;
    u16 unk_08;
    u8 unk_0a[0x6];
    Ov000Text *unk_10;
    u8 unk_14[0x4];
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
};

s32 func_ov000_021ba92c(Obj021ba92c *self) {
    switch (self->unk_04) {
    case 1:
        self->unk_04 = 2;
    case 2:
        self->unk_04 = 4;
    case 4: {
        s32 m = data_ov000_021ccd54->unk_98;
        void *str;
        Ov000Text *t;
        if (!IsMode021ba92c(m) && (u32)(m - 0x11) > 2) {
            break;
        }
        str = func_02061d64(self->unk_08);
        t = (Ov000Text *)Heap_Alloc(0xb8);
        if (t != NULL) {
            t->vtbl = data_0208ba70;
            func_0204c7d0(t);
        }
        self->unk_10 = t;
        t->unk_28 = 8;
        self->unk_10->unk_2c = 0;
        t = self->unk_10;
        t->unk_24 = (s32)str;
        t->unk_4c = Text_Measure(t->unk_28, t->unk_38, t->unk_24, &t->unk_44, &t->unk_48, t->unk_37 != 0);
        data_02097ce0->unk_004 = t->unk_28;
        ((VObj *)self->unk_10)->vfunc_14();
        self->unk_10->flags |= 0x40;
        self->unk_10->flags |= 0x1000000;
        self->unk_10->flags |= 0x40000000;
        self->unk_10->flags |= 4;
        self->unk_04 = 10;
        break;
    }
    case 10:
        self->unk_04 = 11;
    case 11:
        if (++self->unk_18 > 0x90) {
            self->unk_18 = 0;
            self->unk_04 = 12;
            break;
        }
        self->unk_1c = Wave021ba92c(FX_SinCosTable_, self->unk_18, 0x30000);
        self->unk_20 = Wave021ba92c(FX_SinCosTable_, self->unk_18, 0x30000);
        self->unk_24 = Wave021ba92c(FX_SinCosTable_, self->unk_18 - 0x18, 0x30000);
        self->unk_28 = Wave021ba92c(FX_SinCosTable_, self->unk_18 - 0x48, 0x48000);
        break;
    case 12:
        if (++self->unk_18 > 0x30) {
            self->unk_18 = 0;
            self->unk_2c = 0;
            self->unk_28 = 0;
            self->unk_24 = 0;
            self->unk_20 = 0;
            self->unk_1c = 0;
            self->unk_04 = 13;
        }
        break;
    case 13: {
        s32 v;
        if (++self->unk_18 > 0x20) {
            self->unk_18 = 0;
            self->unk_04 = 17;
            break;
        }
        v = Wave021ba92c(FX_SinCosTable_, self->unk_18, 0x20000);
        self->unk_1c = v;
        self->unk_20 = v;
        self->unk_24 = v;
        self->unk_28 = v;
        break;
    }
    case 17:
        return 0;
    }
    return 1;
}

}
