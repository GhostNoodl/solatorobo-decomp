#include "ov006/SlotManager.h"

typedef struct ov006_Sub021e6eb0 {
    u16 buttons;
    u8 kind : 3;
    u8 b3 : 1;
    u8 flag : 1;
    u8 b5 : 3;
    u8 bits;
    s32 x;
    s32 y;
    s32 z;
} ov006_Sub021e6eb0;

typedef struct ov006_Prop021e6eb0 {
    u8 unk0[0x70];
    s32 x;
    s32 y;
    s32 z;
    u8 unk7C[0x120];
    u16 unk19C_0 : 8;
    u16 flag : 1;
    u16 toggle : 1;
    u16 unk19C_10 : 6;
    u8 idx;
    u8 unk19F;
    int unk1A0;
    u16 held;
    u16 trig;
    u16 release;
    u8 kind;
    u8 unk1AB;
    u8 unk1AC;
    u8 unk1AD;
} ov006_Prop021e6eb0;

typedef struct ov006_Disp021e6eb0 {
    u8 unk0[0x18];
    u16 unk18_0 : 10;
    u16 unk18_10 : 1;
    u16 unk18_11 : 5;
} ov006_Disp021e6eb0;

extern "C" {

extern ov006_Disp021e6eb0 *data_0214a424;
const ov006_Sub021e6eb0 *func_ov006_021dab98(ov006_Slot *self);
ov006_Slot *func_ov006_021db060(ov006_SlotManager *self, u32 idx);

void func_ov006_021e6eb0(ov006_Prop021e6eb0 *self) {
    const ov006_Sub021e6eb0 *sub;
    sub = func_ov006_021dab98(func_ov006_021db060(data_ov006_021ec884, 0));
    self->unk1AD = (sub->bits >> (self->idx * 2)) & 3;
    sub = func_ov006_021dab98(func_ov006_021db060(data_ov006_021ec884, self->idx));
    {
        u16 old = self->held;
        u16 cur = sub->buttons;
        self->trig = cur;
        self->trig &= (u16)~old;
        self->release = old;
        self->release &= (u16)~cur;
        self->held = cur;
    }
    self->kind = sub->kind;
    self->flag = sub->flag;
    self->x = sub->x;
    self->y = sub->y;
    self->z = sub->z;
    if (!(self->trig & 4)) {
        return;
    }
    self->toggle = (u16)(self->toggle == 0 ? 1 : 0);
    if (self->idx != data_ov006_021ec884->unk5) {
        return;
    }
    if (self->toggle) {
        data_0214a424->unk18_10 = 1;
    } else {
        data_0214a424->unk18_10 = 0;
    }
}

}

#ifdef NONMATCHING
// func_ov006_021e7004: 23 raw / 12 register-masked (round rtG; the older 21 / 10 drafts start with
// a junk `kq = 1; if ((u32)self & 3) kq = 1;` store). Left: the target issues the dz `smull`
// before the `t->x` load, and builds `hy + curYaw` before `hp + curPitch` (its `unk19C_8` test
// is also read earlier). Statement order of the squares, temporaries, a squaring inline and the
// order of the dp/dy/hp/hy/p/y statements did not reach either.
// Round pmB: reusing one scratch for dp/hp (and for dy/hy), so that rule F keeps the earlier
// definitions as statements, gives 22 / 12 at best (reuse inside one angle) and 176-180 / 46 when
// one local carries both angles; computing y before p gives 28 / 14.
// Round qpL: not a numbering or block question (raH/rule F do not reach it); left as bgV/pmB found.

typedef struct ov006_Aim7004Tgt {
    s32 x;
    s32 y;
    s32 z;
    s32 w;
} ov006_Aim7004Tgt;

typedef struct ov006_Aim7004 {
    u8 unk0[0x70];
    s32 posX;
    s32 posY;
    s32 posZ;
    u8 unk7C[0x120];
    u16 unk19C_0 : 2;
    u16 unk19C_2 : 4;
    u16 unk19C_6 : 2;
    u16 unk19C_8 : 1;
    u16 unk19C_9 : 7;
    u8 unk19E;
    u8 unk19F;
    s32 unk1A0;
    u16 unk1A4;
    u16 unk1A6;
    u16 unk1A8;
    u8 unk1AA;
    u8 unk1AB[0xf];
    u16 unk1BA;
    u16 unk1BC;
    u8 unk1BE[0x38];
    u16 unk1F6;
    u8 unk1F8[8];
    ov006_Aim7004Tgt *tgts;
    u8 unk204[6];
    u8 tgtIdx;
    u8 unk20B;
    u16 curPitch;
    u16 curYaw;
    u16 unk210;
    u16 pitch;
    u16 yaw;
    u16 unk216;
} ov006_Aim7004;

#define OV006A_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV006A_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV006A_SQRT_PARAM (*(volatile u64 *)0x40002b8)

extern "C" {

u8 func_ov006_021d8cb8(void);
u16 FX_Atan2(s32 y, s32 x);

static inline u16 ov006_HalfAngle(u16 d) {
    if (d < 0x8000) {
        return d >> 1;
    }
    return -(u16)((u16)-d >> 1);
}

void func_ov006_021e7004(ov006_Aim7004 *self, u16 *keys) {
//DB
    u16 up;
    u16 hy;
    u16 down;
    BOOL a;
    BOOL b;
    u16 dy;
    ov006_Aim7004Tgt *t;
    u16 dp;
    u16 hp;
    u16 p;
    u16 y;
    s64 sq;
    s32 dx;
    s32 dz;
    BOOL over;
//DE
    *keys = 1;
    self->pitch = 0;
    self->yaw = 0;
    self->unk216 = 0;
    t = &self->tgts[self->tgtIdx];
    if (t != NULL) {
        self->yaw = FX_Atan2(t->x - self->posX, t->z - self->posZ);
        {
            dz = self->posZ - t->z;
            dx = self->posX - t->x;
            sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            OV006A_SQRTCNT = 1;
            OV006A_SQRT_PARAM = (u64)(sq * 4);
        }
        while (OV006A_SQRTCNT & 0x8000) {
        }
        self->pitch = -FX_Atan2(t->y - self->posY, (s32)(OV006A_SQRT_RESULT + 1) >> 1);
    }
    dp = self->pitch - self->curPitch;
    dy = self->yaw - self->curYaw;
    hp = ov006_HalfAngle(dp);
    hy = ov006_HalfAngle(dy);
    p = (u16)(hp + self->curPitch) - self->unk1BA;
    y = (u16)(hy + self->curYaw) - self->unk1BC;
    up = 0x40;
    down = 0x80;
    if (self->unk19C_8) {
        up = 0x80;
        down = 0x40;
    }
    a = FALSE;
    b = FALSE;
    if (y > 0x280 && y < 0x8000) {
        *keys |= 0x20;
        if (y > 0x700 && !(self->unk1A6 & 0x20)) {
            a = TRUE;
        }
    } else if (y < 0xfd80 && y >= 0x8000) {
        *keys |= 0x10;
        if (y < 0xf900 && !(self->unk1A6 & 0x10)) {
            a = TRUE;
        }
    }
    if (p > 0x2c0 && p < 0x8000) {
        *keys |= up;
        if (p > 0x840 && !(self->unk1A6 & up)) {
            b = TRUE;
        }
    } else if (p < 0xfd40 && p >= 0x8000) {
        *keys |= down;
        if (p < 0xf7c0 && !(self->unk1A6 & down)) {
            b = TRUE;
        }
    }
    if (a) {
        *keys |= 0x300;
        if (!b && self->unk19C_2 <= 2) {
            *keys &= 0xff3f;
        }
    } else if (b) {
        *keys |= 0x300;
        if (self->unk19C_2 <= 2) {
            *keys &= 0xffcf;
        }
    }
    {
        over = FALSE;
        if (self->unk19F > data_ov006_021ec884->unk8->unkB) {
            over = TRUE;
        }
        if (over) {
            return;
        }
    }
    if (func_ov006_021d8cb8() <= 1) {
        return;
    }
    if (self->unk1F6 != 0) {
        if (self->unk1A0 < 0x399 || !(*keys & 0xf0)) {
            *keys |= 2;
        }
    }
    if (self->unk1AA != 0) {
        *keys |= 0x400;
    }
}

}
#endif
