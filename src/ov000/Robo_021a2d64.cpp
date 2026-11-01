#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 10;
    u32 b12 : 2;
    u32 b14 : 3;
    u32 b17 : 1;
    u32 b18 : 1;
    u32 b19 : 1;
    u32 b20 : 12;
} B24_021a2d64;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 12;
} B22_021a2d64;

typedef struct {
    u16 b0 : 7;
    u16 b7 : 1;
    u16 b8 : 8;
} Ba4_021a2d64;

typedef struct {
    u16 state;
    u16 sub;
} St_021a2d64;

#define B24(self) LFLD(B24_021a2d64, self, 0xb24)
#define B22(self) LFLD(B22_021a2d64, self, 0xb22)

extern "C" {

extern u8 *data_ov000_021ccd54;
extern void *data_02097e4c;
extern char data_ov000_021cc62a[];
extern char data_ov000_021cc63c[];
extern char data_ov000_021cc642[];
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
BOOL func_ov000_02198360(void *st, s32 state, s32 x);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
void func_ov000_021b1dd8(u8 *self, s32 target, s32 rate, s32 speed, s32 turn, u8 anim);
u16 FX_Atan2(s32 y, s32 x);
u8 *func_02065f88(s32 id, void *pos);
void *func_02049f44(void *mgr, s32 id, void *pos, s32 a);

static inline BOOL GBusy021a2d64(u8 *g) {
    return LFLD(s32, g, 0x90) != LFLD(s32, g, 0x94) ? TRUE : FALSE;
}

static inline BOOL GReady(u8 *g) {
    if (GBusy021a2d64(g)) {
        return FALSE;
    }
    if (LFLD(s32, g, 0) != 3) {
        return FALSE;
    }
    return TRUE;
}
static inline BOOL GIdle021a2d64(void) {
    u8 *g = data_ov000_021ccd54;
    if (g != NULL) {
        return GReady(g);
    }
    return TRUE;
}

void func_ov000_021a2d64(Robo021ca458 *self) {
    BOOL idle = GIdle021a2d64();
    BOOL flag = FALSE;
    BOOL turned;
    St_021a2d64 *st;
    switch (((St_021a2d64 *)self->unk_40)->state) {
    case 0: {
        s32 lim;
        BOOL fall;
        B24(self).b17 = 0;
        self->unk_a8 = 0x29;
        self->unk_b36 = 0;
        if (!(self->msg_flags & 0x80)) {
            u8 *s48 = (u8 *)self->unk_48;
            s32 d = self->pos.y - LFLD(s32, s48, 0x6c);
            if (d <= 0 && !(LFLD(u32, s48, 0x54) & 0x20000000)) {
                flag = TRUE;
            } else if (d > 0x28cd) {
                flag = TRUE;
            }
        }
        if (B22(self).b3) {
            if (!flag) {
                self->unk_a0 = 0;
            }
            if (idle) {
                u8 *e = func_02065f88(0x2bd, (u8 *)self + 0x70);
                LFLD(s32, e, 0x3c) = 0x2000;
                (*(void (**)(u8 *, s32))(LFLD(u8 *, e, 0) + 0xc))(e, 0x159a);
                func_02049f44(data_02097e4c, 0x35, (u8 *)self + 0x70, 0);
            }
            ((St_021a2d64 *)self->unk_40)->sub = 2;
            ((St_021a2d64 *)self->unk_40)->state++;
        } else if (idle && (Ba4_021a2d64 *)self->unk_ba4 != NULL && ((Ba4_021a2d64 *)self->unk_ba4)[3].b7 &&
                   self->unk_b38 >= 10) {
            u16 prev;
            func_ov000_02190cb0(self->unk_38, data_ov000_021cc63c, 0x400, 0);
            func_ov000_021915a0(self->unk_38);
            if (!flag) {
                if (self->unk_9c > 0x29) {
                    if (self->unk_a0 < -0x60) {
                        self->unk_a0 = -0x60;
                    }
                } else {
                    self->unk_a0 = 0x85;
                }
            }
            func_ov000_021b1dd8((u8 *)self, self->unk_b08 >> 2, 0x200, 0xf00, 0, 1);
            prev = self->rot_y;
            self->rot_y = prev + 0xe00;
            if (prev > 0x8000 && self->rot_y < 0x8000) {
                func_02049f44(data_02097e4c, 0x35, (u8 *)self + 0x70, 0);
            }
            ((St_021a2d64 *)self->unk_40)->sub = 2;
        } else if (((St_021a2d64 *)self->unk_40)->sub == 0) {
            func_ov000_02190cb0(self->unk_38, data_ov000_021cc642, 0x1000, 1);
            if (!flag) {
                if (self->unk_9c > 0x29) {
                    if (self->unk_a0 < -0x60) {
                        self->unk_a0 = -0x60;
                    }
                } else {
                    self->unk_a0 = 0x5c;
                }
            }
            ((St_021a2d64 *)self->unk_40)->sub = 4;
            if (!idle) {
                u8 *mdl = (u8 *)self->unk_38;
                LFLD(s32, mdl, 0xd8) = 0;
                LFLD(s32, mdl, 0xdc) = 0;
                ((St_021a2d64 *)self->unk_40)->sub = 5;
            }
            ((St_021a2d64 *)self->unk_40)->state++;
        } else {
            ((St_021a2d64 *)self->unk_40)->state++;
        }
        fall = FALSE;
        if (!(LFLD(u32, self->unk_48, 0x54) & 0x20000000)) {
            lim = -0xf000;
            if (B22(self).b0 != 0 || B24(self).b12 != 0 || B24(self).b19) {
                lim = -0x2d000;
            }
            if (self->pos.y - self->unk_b00 < lim) {
                fall = TRUE;
            }
        }
        if (fall) {
            B24(self).b18 = 1;
            self->unk_a8 = 0x52;
            func_ov000_02198360(self->unk_40, 4, 0);
        }
        break;
    }
    case 1:
        if (idle) {
            func_ov000_021b1dd8((u8 *)self, self->unk_b08 >> 2, 0x200, 0xf00, 0x466, 1);
        } else {
            func_ov000_021987b8(self->unk_48, 0, 0, 0);
        }
        st = (St_021a2d64 *)self->unk_40;
        if (st->sub != 0) {
            st->sub--;
        }
        if (st->sub == 0) {
            if (!B22(self).b3) {
                self->unk_a8 = 0x52;
            }
            func_ov000_02198360(self->unk_40, 4, 0);
        }
        break;
    }
    turned = FALSE;
    if (B24(self).b1 && (LFLD(u32, self->unk_48, 0x54) & 0x400)) {
        self->unk_98 = FX_Atan2(self->unk_af0 - self->pos.x,
                                         self->unk_af8 - self->pos.z);
        self->unk_9c = 0x66;
        self->unk_a4 = 0;
        if (!B24(self).b17 || (LFLD(u32, self->unk_48, 0x50) & 0x40000000)) {
            self->unk_a0 = 0x200;
        }
        self->unk_a8 = 0x52;
        B24(self).b17 = 1;
        turned = TRUE;
    }
    if (!turned) {
        return;
    }
    func_ov000_02190cb0(self->unk_38, data_ov000_021cc62a, 0x800, 0);
    func_ov000_02198360(self->unk_40, 4, 0);
}

}
