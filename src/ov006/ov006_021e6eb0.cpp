#include "ov006/SlotManager.h"
#include "ov006/Racer.h"

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

typedef struct ov006_Disp021e6eb0 {
    u8 unk0[0x18];
    u16 unk18_0 : 10;
    u16 unk18_10 : 1;
    u16 unk18_11 : 5;
} ov006_Disp021e6eb0;

extern "C" {

extern ov006_Disp021e6eb0 *data_0214a424;
const ov006_Sub021e6eb0 *ov006_Slot_GetSub2C(ov006_Slot *self);
ov006_Slot *ov006_SlotManager_GetSlot_021db060(ov006_SlotManager *self, u32 idx);

void Ov006ActVt_021ec4f4_UpdateMode1(Ov006Racer *self) {
    const ov006_Sub021e6eb0 *sub;
    sub = ov006_Slot_GetSub2C(ov006_SlotManager_GetSlot_021db060(data_ov006_021ec884, 0));
    self->rank = (sub->bits >> (self->idx * 2)) & 3;
    sub = ov006_Slot_GetSub2C(ov006_SlotManager_GetSlot_021db060(data_ov006_021ec884, self->idx));
    {
        u16 old = self->held;
        u16 cur = sub->buttons;
        self->trig = cur;
        self->trig &= (u16)~old;
        self->release = old;
        self->release &= (u16)~cur;
        self->held = cur;
    }
    self->unk_1aa = sub->kind;
    self->swap = sub->flag;
    self->pos.x = sub->x;
    self->pos.y = sub->y;
    self->pos.z = sub->z;
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
// Status (round drA): Ov006Racer_ReadKeys is 22 / 13 (raw / register-masked, dsi/1.3 with the project flags); this
// is the best clean draft. Blocker: the ROM issues the dz smull before the t->x load and builds hy + curYaw before
// hp + curPitch (the 20-21 drafts start with a junk store). History: docs/MATCHING.md rounds rtG, pmB, qpL, nmA, cvA
// (search for the address); the full list is docs/UNMATCHED.md.
// Ov006Racer_ReadKeys: 23 raw / 12 register-masked (round rtG; the older 21 / 10 drafts start with
// a junk `kq = 1; if ((u32)self & 3) kq = 1;` store). Left: the target issues the dz `smull`
// before the `t->x` load, and builds `hy + curYaw` before `hp + curPitch` (its `unk19C_8` test
// is also read earlier). Statement order of the squares, temporaries, a squaring inline and the
// order of the dp/dy/hp/hy/p/y statements did not reach either.
// Round pmB: reusing one scratch for dp/hp (and for dy/hy), so that rule F keeps the earlier
// definitions as statements, gives 22 / 12 at best (reuse inside one angle) and 176-180 / 46 when
// one local carries both angles; computing y before p gives 28 / 14.
// Round qpL: not a numbering or block question (raH/rule F do not reach it); left as bgV/pmB found.

#define OV006A_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV006A_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV006A_SQRT_PARAM (*(volatile u64 *)0x40002b8)

extern "C" {

u8 ov006_CountFinished(void);
u16 FX_Atan2(s32 y, s32 x);

static inline u16 ov006_HalfAngle(u16 d) {
    if (d < 0x8000) {
        return d >> 1;
    }
    return -(u16)((u16)-d >> 1);
}

void Ov006Racer_ReadKeys(Ov006Racer *self, u16 *keys) {
//DB
    u16 up;
    u16 hy;
    u16 down;
    BOOL a;
    BOOL b;
    u16 dy;
    Ov006RacerPt *t;
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
    self->aim.x = 0;
    self->aim.y = 0;
    self->aim.z = 0;
    t = &self->pts[self->nextPt];
    if (t != NULL) {
        self->aim.y = FX_Atan2(t->pos.x - self->pos.x, t->pos.z - self->pos.z);
        {
            dz = self->pos.z - t->pos.z;
            dx = self->pos.x - t->pos.x;
            sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            OV006A_SQRTCNT = 1;
            OV006A_SQRT_PARAM = (u64)(sq * 4);
        }
        while (OV006A_SQRTCNT & 0x8000) {
        }
        self->aim.x = -FX_Atan2(t->pos.y - self->pos.y, (s32)(OV006A_SQRT_RESULT + 1) >> 1);
    }
    dp = self->aim.x - self->courseRot.x;
    dy = self->aim.y - self->courseRot.y;
    hp = ov006_HalfAngle(dp);
    hy = ov006_HalfAngle(dy);
    p = (u16)(hp + self->courseRot.x) - self->look2.x;
    y = (u16)(hy + self->courseRot.y) - self->look2.y;
    up = 0x40;
    down = 0x80;
    if (self->swap) {
        up = 0x80;
        down = 0x40;
    }
    a = FALSE;
    b = FALSE;
    if (y > 0x280 && y < 0x8000) {
        *keys |= 0x20;
        if (y > 0x700 && !(self->trig & 0x20)) {
            a = TRUE;
        }
    } else if (y < 0xfd80 && y >= 0x8000) {
        *keys |= 0x10;
        if (y < 0xf900 && !(self->trig & 0x10)) {
            a = TRUE;
        }
    }
    if (p > 0x2c0 && p < 0x8000) {
        *keys |= up;
        if (p > 0x840 && !(self->trig & up)) {
            b = TRUE;
        }
    } else if (p < 0xfd40 && p >= 0x8000) {
        *keys |= down;
        if (p < 0xf7c0 && !(self->trig & down)) {
            b = TRUE;
        }
    }
    if (a) {
        *keys |= 0x300;
        if (!b && self->turnMode <= 2) {
            *keys &= 0xff3f;
        }
    } else if (b) {
        *keys |= 0x300;
        if (self->turnMode <= 2) {
            *keys &= 0xffcf;
        }
    }
    {
        over = FALSE;
        if (self->unk_19f > data_ov006_021ec884->info->unkB) {
            over = TRUE;
        }
        if (over) {
            return;
        }
    }
    if (ov006_CountFinished() <= 1) {
        return;
    }
    if (self->boost != 0) {
        if (self->runSpeed < 0x399 || !(*keys & 0xf0)) {
            *keys |= 2;
        }
    }
    if (self->unk_1aa != 0) {
        *keys |= 0x400;
    }
}

}
#endif
