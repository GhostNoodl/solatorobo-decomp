#include "ov000/LoCommon.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u16 b0 : 3;
    u16 rest : 13;
} B22_021ad8ac;

typedef struct {
    u32 b0 : 9;
    u32 b9 : 1;
    u32 b10 : 8;
    u32 b18 : 1;
    u32 rest : 13;
} B24_021ad8ac;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 2;
    u8 b4 : 1;
    u8 rest : 3;
} Bda_021ad8ac;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 2;
    u16 b3 : 7;
    u16 b10 : 1;
    u16 rest : 5;
} Cfg_021ad8ac;

extern "C" {
extern u8 *data_ov000_021ccd54;
extern void *data_02097e4c;
extern u8 *data_0214a424;
extern char data_ov000_021cc630[];
extern char data_ov000_021cc636[];
extern char data_ov000_021cc6e4[];
extern char data_ov000_021cc6ea[];
extern char data_ov000_021cc6ed[];
extern char data_ov000_021cc6f0[];
extern char data_ov000_021cc6f6[];
extern char data_ov000_021cc6fc[];
extern char data_ov000_021cc702[];
extern char data_ov000_021cc708[];
extern char data_ov000_021cc70b[];
extern char data_ov000_021cc711[];
extern char data_ov000_021cc717[];
BOOL func_ov000_02190cb0(void *p, void *a, s32 b, s32 c);
void func_ov000_021915a0(void *p);
void func_ov000_02191008(void *a);
BOOL func_ov000_02191120(void *a);
void func_ov000_021911c8(void *a, s32 b);
BOOL func_ov000_02198360(void *p, s32 a, s32 b);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
s32 func_02049afc(void *mgr, s32 id);
void func_02049bb4(void *mgr, s32 id);
void *func_02049f44(void *mgr, s32 id, void *pos, s32 a);
void *func_0204a028(void *mgr, s32 id, void *pos, s32 a);
VObj *func_02065f88(s32 id, void *pos);
void func_02062790(u16 a);
u16 func_0204bfa8(void *cam);
void func_ov000_0218dbe0(void *self, s32 a);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, void *v, s32 f, s32 g, s32 h, s32 i, s32 j);
void func_ov000_021b1fac(void *self, s32 a, s32 b);
s32 func_ov003_021ce5b8(u32 a);

static inline BOOL GBusy_021ad8ac(u8 *g) {
    return LFLD(s32, g, 0x90) != LFLD(s32, g, 0x94) ? TRUE : FALSE;
}

static inline BOOL GIdle_021ad8ac(void) {
    u8 *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (GBusy_021ad8ac(g)) {
            return FALSE;
        }
        if (LFLD(s32, g, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline u16 CamAng_021ad8ac(u8 *cam) {
    if (LFLD(u16, cam, 0x40) != 0) {
        return LFLD(u16, cam, 0x44);
    }
    return func_0204bfa8(cam);
}

struct Dust_021ad8acSelf {
    u8 unk_00[0x48];
    u8 *unk_48;
    u8 unk_4c[0x28];
    s32 unk_74;
};

static inline void Dust_021ad8ac(Dust_021ad8acSelf *self) {
    u8 *m = self->unk_48;
    if ((LFLD(u32, m, 0x54) & 0x20000000) && self->unk_74 - LFLD(s32, m, 0x6c) < 0x5000) {
        VecFx32 p;
        p.x = LFLD(s32, m, 0x68);
        p.y = LFLD(s32, m, 0x6c);
        p.z = LFLD(s32, m, 0x70);
        func_02065f88(0x12f, &p)->vfunc_0c(0x800);
    }
}

static inline void Kill_021ad8ac(Robo021ca458 *self) {
    if (self->unk_998 != NULL) {
        func_ov000_02191008(self->unk_998);
    }
    if (self->unk_b64 >= 0) {
        func_02049bb4(data_02097e4c, self->unk_b64);
        self->unk_b64 = -1;
    }
    if (LFLD(B22_021ad8ac, self, 0xb22).b0 > 1) {
        LFLD(B22_021ad8ac, self, 0xb22).b0 = 1;
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

static inline void StopSnd_021ad8ac(Robo021ca458 *self) {
    if (self->unk_b64 >= 0) {
        func_02049bb4(data_02097e4c, self->unk_b64);
        self->unk_b64 = -1;
    }
}

static inline void StartSnd_021ad8ac(Robo021ca458 *self) {
    if (self->unk_b64 < 0) {
        self->unk_b64 = func_02049afc(data_02097e4c, 0x33);
    }
}

void func_ov000_021ad8ac(Robo021ca458 *self) {
    u16 ang;
    BOOL turn;
    u8 *cam = data_ov000_021ccd54 + 0xf4;

    switch (LFLD(u16, self->unk_40, 0)) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov000_021cc6e4, 0x200, 1);
        func_ov000_021915a0(self->unk_38);
        func_ov000_02190cb0(self->unk_998, data_ov000_021cc6ea, 0x1000, 0);
        if ((self->unk_b68 & 2) && self->unk_9ac != 0 && self->unk_b64 < 0) {
            self->unk_b64 = func_02049afc(data_02097e4c, 0x33);
        }
        if (self->unk_a0 >= 0) {
            self->unk_a0 = 0;
        } else {
            self->unk_a0 = self->unk_a0 >> 1;
        }
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_7c = 0;
        self->unk_80 = 0;
        LFLD(u16, self->unk_40, 0)++;
        LFLD(u16, self->unk_40, 2) = 0;
        self->unk_92 = 0;
        LFLD(B22_021ad8ac, self, 0xb22).b0 = 2;
        {
            u8 *m = self->unk_48;
            if ((LFLD(u32, m, 0x54) & 0x20000000) && self->unk_70.y - LFLD(s32, m, 0x6c) < 0x5000) {
                VecFx32 p;
                p.x = LFLD(s32, m, 0x68);
                p.y = LFLD(s32, m, 0x6c);
                p.z = LFLD(s32, m, 0x70);
                func_02065f88(0x12f, &p)->vfunc_0c(0x800);
            }
        }
        func_02062790(1);
        LFLD(u8, data_ov000_021ccd54, 0xac) = 1;
    case 1: {
        if (!GIdle_021ad8ac()) {
            self->unk_9c = 0;
            self->unk_a4 = 0;
            self->unk_a0 = 0;
            self->unk_a8 = 0;
            func_ov000_02190cb0(self->unk_38, data_ov000_021cc6e4, 0xe4, 0);
            func_ov000_021915a0(self->unk_38);
            func_ov000_02190cb0(self->unk_998, data_ov000_021cc6ed, 0x1000, 0);
            func_ov000_021915a0(self->unk_998);
            self->unk_9a8 = func_01ffc128(0xc000, self->unk_9a8, 0x2cd, 1, 0x8000);
            self->unk_9aa = func_01ffc128(0, self->unk_9aa, 0x2cd, 1, 0x8000);
            StopSnd_021ad8ac(self);
        } else {
            u16 c = CamAng_021ad8ac(cam);
            u16 f;
            ang = c + self->unk_b6e;
            f = self->unk_b68;
            turn = FALSE;
            if (!(f & 0x100) && (f & 0xf0)) {
                u16 d;
                turn = TRUE;
                self->unk_7e = func_01ffc128(c, self->unk_7e, 0x19a, 1, 0x8000);
                d = self->unk_98 - ang;
                if (d < 0x1000 || d > 0xf000) {
                    self->unk_98 = func_01ffc128(ang, self->unk_98, 0xcd, 1, 0x8000);
                    self->unk_9c += LO_FX_MUL(0x133 - self->unk_9c, 0x133);
                } else {
                    self->unk_9c -= self->unk_9c >> 4;
                    if (self->unk_9c <= 0x29) {
                        self->unk_98 = ang;
                    }
                }
            } else {
                self->unk_9c -= self->unk_9c >> 5;
            }
            if ((self->unk_b68 & 2) && self->unk_9ac != 0) {
                s32 a0;
                u16 rot;
                if (self->unk_9ac > 1) {
                    self->unk_9ac--;
                } else {
                    self->unk_9ac = 0;
                }
                if (turn) {
                    self->unk_a0 += LO_FX_MUL(0x52 - self->unk_a0, 0x85);
                    if (self->unk_b68 & 0x40) {
                        u8 *st = self->unk_40;
                        LFLD(u16, st, 2)++;
                        if (LFLD(u16, st, 2) > 0x1e) {
                            self->unk_98 = self->unk_7e;
                            LFLD(u16, self->unk_40, 0) = 10;
                            LFLD(u16, self->unk_40, 2) = 0;
                        }
                    }
                } else {
                    self->unk_a0 += LO_FX_MUL(0x266 - self->unk_a0, 0x85);
                }
                rot = 0;
                if (turn) {
                    char *anim = NULL;
                    switch ((u32)(u16)((u16)(ang - self->unk_7e) + 0x1000) >> 13) {
                    case 0:
                        anim = data_ov000_021cc6f0;
                        break;
                    case 1:
                    case 2:
                    case 3:
                        anim = data_ov000_021cc6f6;
                        rot = 0xc00;
                        break;
                    case 4:
                        anim = data_ov000_021cc6fc;
                        break;
                    case 5:
                    case 6:
                    case 7:
                        anim = data_ov000_021cc702;
                        rot = 0xf400;
                        break;
                    }
                    if (anim != NULL) {
                        func_ov000_02190cb0(self->unk_38, anim, 0xcd, 0);
                    }
                } else {
                    func_ov000_02190cb0(self->unk_38, data_ov000_021cc6e4, 0xe4, 0);
                    func_ov000_021915a0(self->unk_38);
                }
                if ((self->unk_b6a & 2) || self->unk_b64 < 0) {
                    func_ov000_02190cb0(self->unk_998, data_ov000_021cc6ea, 0x1000, 0);
                    StartSnd_021ad8ac(self);
                    {
            u8 *m = self->unk_48;
            if ((LFLD(u32, m, 0x54) & 0x20000000) && self->unk_70.y - LFLD(s32, m, 0x6c) < 0x5000) {
                VecFx32 p;
                p.x = LFLD(s32, m, 0x68);
                p.y = LFLD(s32, m, 0x6c);
                p.z = LFLD(s32, m, 0x70);
                func_02065f88(0x12f, &p)->vfunc_0c(0x800);
            }
        }
                    func_ov000_0219aae8(self, self, 5, 0x11, 0x20, NULL, 0, 0x1000, 0, 0x64, 0x1000);
                } else if (func_ov000_02191120(self->unk_998)) {
                    func_ov000_02190cb0(self->unk_998, data_ov000_021cc6ed, 0x1000, 0);
                    func_ov000_021915a0(self->unk_998);
                }
                self->unk_9a8 = func_01ffc128(0xc000, self->unk_9a8, 0x2cd, 1, 0x8000);
                self->unk_9aa = func_01ffc128(rot, self->unk_9aa, 0x2cd, 1, 0x8000);
                if (self->unk_70.y > 0x4b000) {
                    self->unk_a0 = -0x100;
                }
                self->unk_a8 = 0;
            } else {
                if (self->unk_9ac == 0) {
                    func_02062790(0);
                    LFLD(u8, data_ov000_021ccd54, 0xac) = 1;
                }
                func_ov000_02190cb0(self->unk_38, data_ov000_021cc636, 0xcd, 0);
                func_ov000_021911c8(self->unk_38, 0x800);
                func_ov000_02190cb0(self->unk_998, data_ov000_021cc708, 0x1000, 0);
                self->unk_a8 += 2;
                if (self->unk_a8 > 0x14) {
                    self->unk_a8 = 0x14;
                }
                self->unk_9a8 = func_01ffc128(0, self->unk_9a8, 0x2cd, 1, 0x8000);
                self->unk_9aa = func_01ffc128(0, self->unk_9aa, 0x2cd, 1, 0x8000);
                StopSnd_021ad8ac(self);
                if (self->unk_70.y - self->unk_b00 < -0x2d000) {
                    Kill_021ad8ac(self);
                    LFLD(B24_021ad8ac, self, 0xb24).b18 = 1;
                    func_ov000_02198360(self->unk_40, 4, 0);
                }
            }
        }
        func_ov000_0218dbe0(self, 0);
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (self->unk_92 != 0) {
            self->unk_92--;
        }
        {
            u16 f = self->unk_b68;
            if (!(f & 0x100)) {
                u16 cur = LFLD(u16, cam, 0x42);
                u16 t = 0x2800;
                if (f & 0x80) {
                    t += 0x800;
                } else if (f & 0x30) {
                    t += 0x400;
                } else if (f & 0x40) {
                    t -= 0x2000;
                }
                LFLD(u16, cam, 0xf8) = func_01ffc128(t, cur, 0x266, 1, 0x8000);
                LFLD(Bda_021ad8ac, cam, 0xda).b4 = 1;
            }
        }
        LFLD(s32, cam, 0xf4) = LFLD(s32, cam, 0x48) + ((0xb800 - LFLD(s32, cam, 0x48)) >> 1);
        LFLD(Bda_021ad8ac, cam, 0xda).b2 = 1;
        LFLD(s32, cam, 0xdc) = 0;
        LFLD(s32, cam, 0xe0) = -0x800;
        LFLD(s32, cam, 0xe4) = 0;
        LFLD(Bda_021ad8ac, cam, 0xda).b0 = 1;
        if (LFLD(u32, self->unk_48, 0x50) & 0x20000000) {
            s32 r;
            func_ov000_02190cb0(self->unk_38, data_ov000_021cc630, 0x1000, 0);
            Kill_021ad8ac(self);
            func_02049f44(data_02097e4c, 8, (u8 *)self + 0x70, 0);
            r = func_ov003_021ce5b8(LFLD(u32, self->unk_48, 0x50));
            if (r >= 0) {
                func_0204a028(data_02097e4c, r, (u8 *)self + 0x70, -5);
                if ((LFLD(u32, self->unk_48, 0x50) & 0xf0f0f0) == 0xe0e000) {
                    VecFx32 p;
                    p.x = self->unk_70.x;
                    p.y = self->unk_70.y;
                    p.z = self->unk_70.z;
                    p.y += 0xccd;
                    func_02065f88(0x2bc, &p);
                    func_02065f88(0x2bd, &p)->vfunc_0c(0x1800);
                } else {
                    func_02065f88(0x12f, (u8 *)self + 0x70)->vfunc_0c(0x800);
                }
            }
            LFLD(u16, self->unk_40, 0)++;
            LFLD(u16, self->unk_40, 2) = 0;
            self->unk_a0 = 0;
            self->unk_a8 = 0;
            self->unk_a4 = 0x800;
            return;
        }
        if (!(LFLD(u32, self->unk_48, 0x50) & 0xc0000000)) {
            return;
        }
        if (self->unk_92 != 0) {
            return;
        }
        self->unk_98 = FX_Atan2(LFLD(s32, self->unk_48, 0x80), LFLD(s32, self->unk_48, 0x88));
        if (self->unk_a0 >= 0) {
            s32 a0;
            func_02049f44(data_02097e4c, 0x7c, (u8 *)self + 0x70, 0);
            self->unk_92 = 8;
            a0 = self->unk_a0;
            if (a0 < 0) {
                a0 = -a0;
            }
            self->unk_9c += a0;
            self->unk_a0 = self->unk_a0 >> 1;
        } else {
            self->unk_9c += self->unk_b08 >> 3;
        }
        return;
    }
    case 2: {
        u8 *st;
        func_ov000_021b1fac(self, 1, 1);
        self->unk_9a8 = func_01ffc128(0, self->unk_9a8, 0x800, 1, 0x8000);
        self->unk_9aa = func_01ffc128(0, self->unk_9aa, 0x59a, 1, 0x8000);
        st = self->unk_40;
        LFLD(u16, st, 2)++;
        if (LFLD(u16, st, 2) < 6) {
            return;
        }
        LFLD(u16, self->unk_40, 2) = 6;
        if (!func_ov000_02191120(self->unk_38) && LFLD(s64, self->unk_40, 4) == 0) {
            return;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        self->unk_9a6 = 0;
        self->unk_9a8 = 0;
        self->unk_9aa = 0;
        return;
    }
    case 10: {
        VObj *e;
        LFLD(B22_021ad8ac, self, 0xb22).b0 = 3;
        func_ov000_02190cb0(self->unk_38, data_ov000_021cc70b, 0x200, 1);
        func_ov000_021915a0(self->unk_38);
        func_ov000_02190cb0(self->unk_998, data_ov000_021cc6ea, 0x1000, 0);
        func_02049f44(data_02097e4c, 0x32, (u8 *)self + 0x70, 0);
        StartSnd_021ad8ac(self);
        e = func_02065f88(0x4b0, (u8 *)self + 0x70);
        self->unk_b40 = LFLD(s32, e, 0x24);
        e->vfunc_30((u8 *)self + 0x7c);
        func_02065f88(0x68, (u8 *)self + 0x70)->vfunc_34(0x4000, self->unk_7e, 0);
        self->unk_9a6 = 0;
        self->unk_9a8 = 0;
        self->unk_9aa = 0;
        self->unk_9a0 = 0;
        self->unk_9a2 = 0;
        self->unk_9a4 = 0;
        func_02062790(2);
        LFLD(u8, data_ov000_021ccd54, 0xac) = 1;
        LFLD(u16, self->unk_40, 0)++;
    }
    case 11: {
        u8 *st;
        if (!GIdle_021ad8ac()) {
            self->unk_9c = 0;
            self->unk_a4 = 0;
            self->unk_a0 = 0;
            self->unk_a8 = 0;
            self->unk_7c = func_01ffc128(0, self->unk_7c, 0x200, 1, 0x8000);
            self->unk_80 = func_01ffc128(0, self->unk_80, 0x266, 1, 0x8000);
            func_ov000_02190cb0(self->unk_38, data_ov000_021cc70b, 0x200, 0);
            func_ov000_021915a0(self->unk_38);
            func_ov000_02190cb0(self->unk_998, data_ov000_021cc6ed, 0x1000, 0);
            func_ov000_021915a0(self->unk_998);
            StopSnd_021ad8ac(self);
            LFLD(u16, self->unk_40, 0)++;
            return;
        }
        if (self->unk_9ac > 8) {
            self->unk_9ac -= 8;
        } else {
            self->unk_9ac = 0;
        }
        if (!func_ov000_02191120(self->unk_38)) {
            s32 tgt = LFLD(Cfg_021ad8ac, data_0214a424, 0x18).b1 == 1 ? 0x51f : 0x4cd;
            self->unk_9c += LO_FX_MUL(tgt - self->unk_9c, 0x200);
            self->unk_7c = func_01ffc128(0, self->unk_7c, 0x266, 1, 0x8000);
            self->unk_80 = func_01ffc128(0, self->unk_80, 0x266, 1, 0x8000);
        } else if ((self->unk_b6a & 0x100) && self->unk_9ac != 0) {
            char *anim;
            VObj *e;
            LFLD(B22_021ad8ac, self, 0xb22).b0 = 4;
            if (self->unk_9ac > 10) {
                self->unk_9ac -= 10;
            } else {
                self->unk_9ac = 0;
            }
            if (!LFLD(B24_021ad8ac, self, 0xb24).b9) {
                LFLD(B24_021ad8ac, self, 0xb24).b9 = 1;
                anim = data_ov000_021cc711;
            } else {
                LFLD(B24_021ad8ac, self, 0xb24).b9 = 0;
                anim = data_ov000_021cc717;
            }
            func_ov000_02190cb0(self->unk_38, anim, 0x800, 1);
            func_ov000_02190cb0(self->unk_998, data_ov000_021cc6ea, 0x1000, 0);
            self->unk_9c = LFLD(Cfg_021ad8ac, data_0214a424, 0x18).b1 == 1 ? 0xd1f : 0xccd;
            self->unk_9a0 = 0;
            self->unk_9a2 = 0;
            self->unk_9a4 = 0;
            e = func_02065f88(0x4b0, (u8 *)self + 0x70);
            self->unk_b40 = LFLD(s32, e, 0x24);
            e->vfunc_30((u8 *)self + 0x7c);
        } else if ((self->unk_b68 & 2) && self->unk_9ac != 0) {
            u16 f;
            s32 tgt;
            u16 cur;
            s32 sp;
            u16 t;
            s32 d;
            tgt = 0;
            LFLD(B22_021ad8ac, self, 0xb22).b0 = 3;
            func_ov000_02190cb0(self->unk_38, data_ov000_021cc70b, 0x200, 0);
            func_ov000_021915a0(self->unk_38);
            cur = LFLD(u16, cam, 0x42);
            f = self->unk_b68;
            if (((Cfg_021ad8ac *)(data_0214a424 + 0x18))->b10) {
                if (f & 0x40) {
                    f = 0x80;
                } else if (f & 0x80) {
                    f = 0x40;
                }
            }
            if (f & 0x40) {
                self->unk_9a0 = func_01ffc128(0x2000, self->unk_9a0, 0x133, 1, 0x8000);
                tgt = -0x414;
                cur = func_01ffc128(0x1200, cur, 0x1ae, 1, 0x8000);
            } else if (f & 0x80) {
                self->unk_9a0 = func_01ffc128(0xe000, self->unk_9a0, 0x133, 1, 0x8000);
                tgt = 0x414;
                cur = func_01ffc128(0xee00, cur, 0x1ae, 1, 0x8000);
            } else {
                self->unk_9a0 = func_01ffc128(0, self->unk_9a0, 0x10a, 1, 0x8000);
                cur = func_01ffc128(0x200, cur, 0x2cd, 1, 0x8000);
            }
            LFLD(u16, cam, 0xf8) = cur;
            LFLD(Bda_021ad8ac, cam, 0xda).b4 = 1;
            self->unk_7c = func_01ffc128(self->unk_9a0, self->unk_7c, 0x59a, 1, 0x8000);
            d = self->unk_70.y - self->unk_b00;
            if (d < -0x2d000) {
                self->unk_a0 = 0;
            } else if (d > 0x4b000) {
                self->unk_a0 = 0;
            } else {
                self->unk_a0 += LO_FX_MUL(tgt - self->unk_a0, 0x8f);
            }
            f = self->unk_b68;
            t = 0;
            if (f & 0x20) {
                t = 0xe0;
            } else if (f & 0x10) {
                t = 0xff20;
            }
            self->unk_9a2 = func_01ffc128(t, self->unk_9a2, 0x133, 1, 0x8000);
            self->unk_98 = self->unk_98 + self->unk_9a2;
            self->unk_7e = func_01ffc128(self->unk_98, self->unk_7e, 0xcd, 1, 0x8000);
            self->unk_80 = func_01ffc128(-((self->unk_9a2 << 5) + (self->unk_9a2 << 3)), self->unk_80, 0x59a, 1, 0x8000);
            sp = LFLD(Cfg_021ad8ac, data_0214a424, 0x18).b1 == 1 ? 0x51f : 0x4cd;
            if (self->unk_b68 & 0xf0) {
                sp -= sp >> 2;
            }
            self->unk_9c += LO_FX_MUL(sp - self->unk_9c, 0x8f);
            LFLD(u16, self->unk_40, 2) = 0;
        } else {
            LFLD(B22_021ad8ac, self, 0xb22).b0 = 3;
            func_ov000_02190cb0(self->unk_38, data_ov000_021cc70b, 0x200, 0);
            self->unk_9c -= self->unk_9c >> 5;
            self->unk_a0 += LO_FX_MUL(0x266 - self->unk_a0, 0x414);
            self->unk_7c = func_01ffc128(0xc000, self->unk_7c, 0x200, 1, 0x8000);
            self->unk_80 = func_01ffc128(0, self->unk_80, 0x266, 1, 0x8000);
            LFLD(u16, self->unk_40, 2)++;
        }
        st = self->unk_40;
        if (LFLD(u16, st, 2) > 0xc) {
            LFLD(u16, st, 0) = 0;
            StopSnd_021ad8ac(self);
            func_02049f44(data_02097e4c, 0x35, (u8 *)self + 0x70, 0);
        }
        if (func_ov000_02191120(self->unk_998)) {
            func_ov000_02190cb0(self->unk_998, data_ov000_021cc6ed, 0x1000, 0);
            func_ov000_021915a0(self->unk_998);
        }
        func_ov000_0218dbe0(self, 0);
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (self->unk_92 != 0) {
            self->unk_92--;
            return;
        }
        {
            u32 fl = LFLD(u32, self->unk_48, 0x50);
            if (fl & 0x20000000) {
                func_02049f44(data_02097e4c, 0x7c, (u8 *)self + 0x70, 0);
                self->unk_92 = 8;
                self->unk_a0 = 0x519;
                self->unk_9c = self->unk_9c >> 1;
                self->unk_9a0 = 0xee00;
                return;
            }
            if (!(fl & 0xc0000000)) {
                return;
            }
        }
        {
            u16 d;
            u16 h;
            func_02049f44(data_02097e4c, 0x7c, (u8 *)self + 0x70, 0);
            self->unk_92 = 8;
            d = FX_Atan2(LFLD(s32, self->unk_48, 0x80), LFLD(s32, self->unk_48, 0x88)) - self->unk_98;
            if (d <= 0x8000) {
                self->unk_9a2 = 0xc0;
                h = d >> 1;
            } else {
                self->unk_9a2 = 0xff40;
                h = -((u32)(u16)-d >> 1);
            }
            self->unk_98 += h;
            self->unk_9c = self->unk_9c >> 1;
            self->unk_a0 = self->unk_a0 >> 1;
        }
        return;
    }
    case 12:
        if (!GIdle_021ad8ac()) {
            return;
        }
        StartSnd_021ad8ac(self);
        LFLD(u16, self->unk_40, 0)--;
        return;
    }
}
}
