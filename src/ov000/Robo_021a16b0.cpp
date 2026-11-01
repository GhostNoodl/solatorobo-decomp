#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 3;
    u32 b5 : 2;
    u32 b7 : 5;
    u32 b12 : 2;
    u32 b14 : 11;
    u32 b25 : 1;
    u32 b26 : 6;
} B24_021a16b0;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 12;
} B22_021a16b0;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
} B8_021a16b0;

extern "C" {

extern char data_ov000_021cc5e3[];
extern char data_ov000_021cc618[];
extern char *data_ov000_021ca040[];
extern void *data_02097e4c;
extern u8 *data_ov000_021ccd54;
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void func_ov000_02191008(void *a);
void func_02049bb4(void *a, s32 b);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
void func_ov000_021b209c(u8 *self);
void func_ov000_021b2b08(u8 *self);

static inline BOOL PlayerIdle021a16b0(void) {
    u8 *pl = data_ov000_021ccd54;
    if (pl != NULL) {
        if (LFLD(s32, pl, 0x90) != LFLD(s32, pl, 0x94) ? TRUE : FALSE) {
            return FALSE;
        }
        if (LFLD(s32, pl, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

void func_ov000_021a16b0(Robo021ca458 *self) {
    switch (*(u16 *)self->unk_40) {
    case 0:
        ((u16 *)self->unk_40)[1] = 0;
        (*(u16 *)self->unk_40)++;
        if (LFLD(B22_021a16b0, self, 0xb22).b0 > 1) {
            if (self->unk_998 != NULL) {
                func_ov000_02191008(self->unk_998);
            }
            if (self->unk_b64 >= 0) {
                func_02049bb4(data_02097e4c, self->unk_b64);
                self->unk_b64 = -1;
            }
            if (LFLD(B22_021a16b0, self, 0xb22).b0 > 1) {
                LFLD(B22_021a16b0, self, 0xb22).b0 = 1;
                self->unk_7c = 0;
                self->unk_80 = 0;
                self->unk_9a6 = 0;
                self->unk_9a8 = 0;
                self->unk_9aa = 0;
                self->unk_9a0 = 0;
                self->unk_9a2 = 0;
                self->unk_9a4 = 0;
            }
        }
    case 1: {
        char *name = data_ov000_021cc5e3;
        s32 rate = 0x2ab;
        s32 d = 0;
        if (LFLD(B24_021a16b0, self, 0xb24).b1) {
            if (!LFLD(B22_021a16b0, self, 0xb22).b3) {
                name = data_ov000_021ca040[LFLD(B24_021a16b0, self, 0xb24).b5];
            } else {
                if (LFLD(B24_021a16b0, self, 0xb24).b5 != 0) {
                    name = data_ov000_021cc618;
                }
                rate = 0xa4;
            }
        } else if (LFLD(u32, self->unk_48, 0x50) & 0x400) {
            name = data_ov000_021cc618;
        }
        if (LFLD(B24_021a16b0, self, 0xb24).b25) {
            LFLD(B24_021a16b0, self, 0xb24).b25 = 0;
            rate = 0x1000;
            d = 1;
        }
        func_ov000_02190cb0(self->unk_38, name, rate, d);
        func_ov000_021915a0(self->unk_38);
        if (LFLD(B24_021a16b0, self, 0xb24).b12 != 0) {
            (*(u16 *)self->unk_40)++;
            if (self->unk_b2f == 0) {
                self->unk_b2f = 1;
            }
            return;
        }
        if (((u16 *)self->unk_40)[1] >= 0x5a) {
            if (self->unk_b32 == 0) {
                self->unk_b32 = 1;
            }
        } else if (PlayerIdle021a16b0() && self->unk_15 == 1 && !LFLD(B8_021a16b0, self, 0xb29).b1 &&
                   !LFLD(B8_021a16b0, self, 0xb28).b2 && self->unk_b2e == 0 &&
                   LFLD(B22_021a16b0, self, 0xb22).b0 == 0) {
            ((u16 *)self->unk_40)[1]++;
        } else {
            ((u16 *)self->unk_40)[1] = 0;
        }
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        LFLD(u16, self->unk_48, 0x9a) |= 0x20;
        if (self->unk_30 & 0x80) {
            func_ov000_021987b8(self->unk_48, 1, 0, 0);
        }
        return;
    }
    case 2:
        if (LFLD(B24_021a16b0, self, 0xb24).b12 == 0) {
            return;
        }
        if (LFLD(B24_021a16b0, self, 0xb24).b12 != 3) {
            func_ov000_021b209c((u8 *)self);
        } else {
            func_ov000_021b2b08((u8 *)self);
        }
        return;
    }
}

}
