#include "ov000/LoCommon.h"

typedef struct {
    u8 pad_00[0x12];
    u16 trg;
} Pad021bb8dc;

extern "C" {
extern u8 *data_ov000_021ccd30;
extern char *data_ov000_021cc858;
extern char data_ov000_021cc894[];
extern Pad021bb8dc *data_02097dc8;
extern void *data_02097e4c;
extern const s16 FX_SinCosTable_[];
void func_0206e900(char *dst, const char *src);
void func_ov000_021bbd94(u8 *self);
BOOL func_02054f10(void *a, s32 b);
s32 FX_Div(s32 a, s32 b);
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
void func_ov000_02165da0(void *p);
BOOL func_ov000_02165df4(void *p);
void func_ov000_02165d78(void *p);

static inline void *Get021bb8dc(void) {
    u8 *p = LFLD(u8 *, data_ov000_021ccd30, 0x118);
    if (p == NULL) {
        return NULL;
    }
    if (LFLD(s32, p, 0x28) != 1) {
        return NULL;
    }
    return LFLD(void *, p, 0x30);
}

struct Obj021bb8dc {
    u8 unk_00[0x48];
    s32 unk_48;
    u8 unk_4c[0x4];
    s32 unk_50;
    s16 unk_54;
    u8 unk_56[0x2];
    void *unk_58;
    VObj *unk_5c;
    s32 unk_60;
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
};

static inline BOOL Ready021bb8dc(Obj021bb8dc *self) {
    BOOL ok = TRUE;
    if (!((VObj *)((u8 *)self + 4))->vfunc_2c()) {
        ok = FALSE;
    }
    return ok;
}

BOOL func_ov000_021bb8dc(Obj021bb8dc *self) {
    s32 t;
    void *p = Get021bb8dc();

    switch (self->unk_50) {
    case 1: {
        char buf[0x20];
        func_0206e900(buf, data_ov000_021cc858);
        self->unk_48 = 2;
        ((VObj *)((u8 *)self + 4))->vfunc_24(buf, data_ov000_021cc894);
        self->unk_50 = 2;
    }
    case 2:
        if (!Ready021bb8dc(self)) {
            break;
        }
        self->unk_50 = 4;
    case 4:
        func_ov000_021bbd94((u8 *)self);
        self->unk_50 = 10;
    case 10:
        if (!func_02054f10(self->unk_58, 0xffff)) {
            break;
        }
        self->unk_50 = 6;
    case 6:
        self->unk_64 += 0x1000;
        t = FX_Div(self->unk_64, 0x1e000);
        if (t > 0x1000) {
            self->unk_50 = 11;
            self->unk_64 = 0x1e000;
            t = 0x1000;
            if ((void *)self->unk_5c != NULL) {
                LFLD(u32, self->unk_5c, 0xc) &= ~2;
            }
        }
        self->unk_68 = FX_SinCosTable_[((t << 14) >> 16) * 2];
        break;
    case 11:
        if (data_02097dc8->trg & 2) {
            func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
            self->unk_50 = 12;
            break;
        }
        switch (self->unk_54) {
        case 0:
            if (++self->unk_6c > 0x3c) {
                func_ov000_02165da0(p);
                self->unk_54 = 10;
            }
            break;
        case 10:
            if (func_ov000_02165df4(p)) {
                self->unk_6c = 0;
                self->unk_54 = 20;
            }
            break;
        case 20:
            if (++self->unk_6c > 0x78) {
                self->unk_6c = 0;
                self->unk_54 = 100;
            }
            break;
        case 100:
            self->unk_50 = 12;
            break;
        }
        break;
    case 12:
        func_ov000_02165d78(p);
        if ((void *)self->unk_5c != NULL) {
            LFLD(u32, self->unk_5c, 0xc) |= 2;
        }
        self->unk_50 = 13;
    case 13:
        self->unk_64 -= 0x1000;
        t = FX_Div(self->unk_64, 0x1e000);
        if (t <= 0) {
            t = 0;
            self->unk_64 = 0;
            self->unk_50 = 17;
        }
        self->unk_68 = FX_SinCosTable_[((t << 14) >> 16) * 2];
        break;
    case 17:
        return FALSE;
    }
    if (self->unk_5c != NULL) {
        self->unk_5c->vfunc_1c();
    }
    self->unk_60 += 0x1000;
    if (self->unk_60 < 0) {
        self->unk_60 -= (s32)0x80000001;
    }
    return TRUE;
}
}
