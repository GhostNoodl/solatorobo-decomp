#include "ov010/ov010.h"

struct Ov010Sw {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_05[3];
    Ov010Vec unk_08;
    u16 unk_14[4];
    s32 unk_1c;
};

extern "C" {

extern u8 data_ov010_0220f220[];
extern u8 data_ov010_0220f448[];
extern u8 data_ov010_0220f298[];
extern u8 data_ov010_0220ffc4[];
extern u8 data_ov010_02210154[];
extern u8 *data_ov000_021ccd54;
extern void *data_0214a420;
extern s32 _s32_div_f(s32 a, s32 b);
extern BOOL func_ov003_021d984c(void *p, void *d);
extern void func_ov003_021d95e8(void *p, void *d, s32 n);
extern void *func_ov000_0219bf90(void);
extern void func_ov000_0218a358(void *a, const void *b, void *c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern s32 func_02012ab8(s32 a, s32 b);
extern void func_ov003_021cf3fc(s32 a);
extern void func_ov010_022075bc(void *p);
extern void func_ov003_021d8bb8(void *p);
extern void func_ov003_021d7fc0(void *p);
extern void func_ov010_0220d7c0(void *p);
extern void func_ov003_021d8f34(void *p);
extern void func_ov003_021d0edc(void *p);
extern void func_02065804(void *a, s32 b);

static inline void Ov010_PlayIfIdle(void *self, void *anim, s32 n) {
    if (!func_ov003_021d984c((u8 *)self + 0x160, anim)) {
        func_ov003_021d95e8((u8 *)self + 0x160, anim, n);
    }
}

void func_ov010_02208c3c(void *self) {
    u16 *p = FLD(u16 *, self, 0x50);
    s32 r = _s32_div_f(p[0] << 12, p[1]);
    if (r <= 0x554) {
        Ov010_PlayIfIdle(self, data_ov010_0220f220, 0x14);
    } else if (r <= 0xccd) {
        Ov010_PlayIfIdle(self, data_ov010_0220f448, 0x27);
    } else if (r <= 0x1000) {
        Ov010_PlayIfIdle(self, data_ov010_0220f298, 0x14);
    }
}

BOOL func_ov010_02208d10(void *self, s32 *out) {
    *out = 10;
    return TRUE;
}

void func_ov010_02208d20(void *self, s32 *out) {
    out[0] = 0xa05;
    out[1] = 0xa06;
    out[2] = 0xa04;
    out[3] = 0xa01;
    out[5] = 0xa03;
    out[6] = 0xa01;
    out[7] = 0xa02;
    out[8] = 0xa01;
}

void *func_ov010_02208d60(void *self) {
    FLD(void *, self, 0) = data_ov010_0220ffc4;
    ((Ov010V *)self)->v0c();
    return self;
}

void *func_ov010_02208d88(void *self) {
    FLD(void *, self, 0) = data_ov010_0220ffc4;
    ((Ov010V *)self)->v0c();
    func_0203de1c(self);
    return self;
}

BOOL func_ov010_02208db8(Ov010Sw *self) {
    self->b0 = 1;
    return TRUE;
}

void func_ov010_02208dd0(Ov010Sw *self) {
    if (self->b0) {
        self->b0 = 0;
    }
}

static inline BOOL Ov010_PlayerBusy(void *p) {
    return FLD(Ov010Flags32, p, 0xb24).b0 ? TRUE : FALSE;
}

void func_ov010_02208de8(Ov010Sw *self) {
    void *p;
    if (!self->b0) {
        return;
    }
    if (data_ov000_021ccd54 + 0xf4 == NULL) {
        return;
    }
    p = func_ov000_0219bf90();
    if (p == NULL) {
        return;
    }
    if (Ov010_PlayerBusy(p)) {
        return;
    }
    func_ov000_0218a358(data_ov000_021ccd54 + 0xf4, &self->unk_08, self->unk_14, self->unk_1c, 0, 0x1000, 0x1000, 1);
}

u16 func_ov010_02208e90(s32 a, s32 b) {
    s32 period = Ov010_FxMul(a, 0x3243) * 2;
    if (period == 0) {
        return 0;
    }
    while (b >= period) {
        b -= period;
    }
    return (u16)(Ov010_FxMul(func_02012ab8(b, period), 0xffff000) >> 12);
}

static inline void Ov010_02208f14_Body(void *self) {
    FLD(void *, self, 0) = data_ov010_02210154;
    func_ov003_021cf3fc(0);
    func_ov010_022075bc(self);
    func_ov003_021d8bb8((u8 *)self + 0x1dc);
    func_ov003_021d7fc0((u8 *)self + 0x1b0);
    func_ov010_0220d7c0((u8 *)self + 0x174);
    func_ov003_021d8f34((u8 *)self + 0x160);
    func_ov003_021d0edc(self);
}

void *func_ov010_02208f14(void *self) {
    Ov010_02208f14_Body(self);
    return self;
}

void *func_ov010_02208f68(void *self) {
    Ov010_02208f14_Body(self);
    func_0203de1c(self);
    return self;
}

void *func_ov010_02208fc4(void *self) {
    Ov010_02208f14_Body(self);
    return self;
}

void *func_ov010_02209018(void *self) {
    Ov010_02208f14_Body(self);
    func_0203de1c(self);
    return self;
}

void func_ov010_02209074(void *p) {
    if (p == NULL) {
        return;
    }
    if (FLD(s32, p, 4) > 0) {
        FLD(s32, p, 4)--;
        return;
    }
    func_02065804(data_0214a420, FLD(s32, p, 0x24));
    FLD(s32, p, 0xdc) = 0;
}

}
