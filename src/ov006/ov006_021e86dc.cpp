#include "ov006/SlotManager.h"
#include "ov006/ov006.h"
#include "nitro/fx.h"

typedef struct ov006_Rot021e86dc {
    u16 x;
    u16 y;
    u16 z;
} ov006_Rot021e86dc;

typedef struct ov006_Eff021e86dc {
    u8 unk0[0x24];
    int unk24;
    u8 unk28;
    u8 unk29;
    u8 unk2A[0x12];
    fx32 unk3C;
    u8 unk40[0x3c];
    fx32 unk7C;
} ov006_Eff021e86dc;

typedef struct ov006_Old021e86dc {
    u8 unk0[0x1c];
    int unk1C;
} ov006_Old021e86dc;

typedef struct ov006_Car021e86dc {
    u8 unk0[0x70];
    VecFx32 pos;
    ov006_Rot021e86dc rot;
    u8 unk82[0x2a];
    s8 *unkAC;
    u8 unkB0[0xec];
    u16 unk19C_0 : 2;
    u16 mode : 4;
    u16 boosting : 1;
    u16 unk19C_7 : 1;
    u16 swap : 1;
    u16 unk19C_9 : 7;
    u8 unk19E;
    u8 unk19F;
    s32 speed;
    u16 held;
    u16 trig;
    u8 unk1A8[5];
    u8 unk1AD;
    u8 unk1AE[0x1e];
    u32 unk1CC;
    u8 unk1D0[4];
    int unk1D4;
    int unk1D8;
    int unk1DC;
    u8 unk1E0[0x16];
    u16 boost;
    u8 unk1F8[2];
    u16 unk1FA;
    u8 unk1FC[0x26];
    u8 unk222;
    u8 unk223;
    u8 unk224[2];
    u8 unk226;
    u8 unk227;
} ov006_Car021e86dc;

extern "C" {

extern void *data_02097e4c;
extern void *data_0214a420;
extern char data_ov006_021ec4ad[];
extern char data_ov006_021ec4bc[];
extern char data_ov006_021ec4c8[];
extern char data_ov006_021ec4d4[];
extern u8 data_ov006_021eb908[];
extern s32 data_ov006_021eb8f8[];
ov006_Eff021e86dc *func_02065f88(s32 id, VecFx32 *pos);
ov006_Eff021e86dc *func_02066774(const char *a, const char *b, const char *c, VecFx32 *pos);
ov006_Old021e86dc *func_020657b0(void *a, int b);
void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
ov006_Slot *func_ov006_021db060(ov006_SlotManager *self, u32 idx);
ov006_SlotSub *func_ov006_021dab98(ov006_Slot *self);

#define MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

static inline void ov006_ModeDown(ov006_Car021e86dc *self) {
    u32 mode = self->mode;
    if (mode != 0) {
        if (mode != 1) {
            self->mode = 1;
        } else {
            self->mode = 0;
        }
    }
}

void func_ov006_021e86dc(ov006_Car021e86dc *self) {
    u16 drain;
    s32 accel;
    s32 max;
    ov006_Eff021e86dc *e;

    self->boosting = 0;
    if ((self->held & 1) || ((self->held & 2) && self->boost != 0)) {
        if ((self->held & 2) && self->boost != 0) {
            self->boosting = 1;
            drain = 100 - self->unkAC[7] * 4;
            if (self->trig & 2) {
                drain = 1000 - self->unkAC[7] * 8;
                if ((self->unk19C_0 & 1) && data_ov006_021ec884->unk13D == 0) {
                    func_02049f44(data_02097e4c, 0x32, &self->pos, 0);
                    if (self->unk1D4 != 0) {
                        ov006_Old021e86dc *old = func_020657b0(data_0214a420, self->unk1D4);
                        if (old != NULL) {
                            old->unk1C = 4;
                            self->unk1D4 = 0;
                        }
                    }
                    e = func_02066774(data_ov006_021ec4ad, data_ov006_021ec4bc, data_ov006_021ec4bc, &self->pos);
                    if (e != NULL) {
                        self->unk1D4 = e->unk24;
                        e->unk3C = 0x2000;
                        VCALL(e, 0C, 0x4000);
                        VCALL(e, 30, &self->rot);
                    }
                }
            } else if (self->unk1D4 == 0 && (self->unk19C_0 & 1) && data_ov006_021ec884->unk13D == 0) {
                e = func_02065f88(0x4b0, &self->pos);
                if (e != NULL) {
                    self->unk1D4 = e->unk24;
                    VCALL(e, 0C, 0x1ccd);
                    VCALL(e, 30, &self->rot);
                    e->unk7C = FX_Div(0x15000, 0x1f000);
                }
            }
            if (self->unk1AD >= data_ov006_021ec884->numActive - 1) {
                drain -= 15;
            }
            if (self->boost < drain) {
                self->boost = 0;
            } else {
                self->boost -= drain;
            }
        }
        if ((self->held & 0x300) && self->speed >= 0x95b) {
            if (self->mode < 2) {
                self->mode = 2;
            }
            if (self->mode == 2) {
                u16 h = self->held;
                if (h & 0xf0) {
                    u16 d = h;
                    u32 idx;
                    if (self->swap) {
                        if (h & 0x40) {
                            d = 0x80;
                        } else if (h & 0x80) {
                            d = 0x40;
                        }
                    }
                    idx = 0;
                    if (h & 0x10) {
                        idx |= 1;
                    } else if (h & 0x20) {
                        idx |= 2;
                    }
                    if (d & 0x40) {
                        idx |= 4;
                    } else if (d & 0x80) {
                        idx |= 8;
                    }
                    if (data_ov006_021eb908[idx] != 0) {
                        self->mode = data_ov006_021eb908[idx];
                    }
                }
            } else if (data_ov006_021ec884->unk13D == 0) {
                if (self->unk1D8 == 0 && (self->unk19C_0 & 1)) {
                    ov006_Eff021e86dc *e;
                    e = func_02066774(data_ov006_021ec4ad, data_ov006_021ec4c8, data_ov006_021ec4c8, &self->pos);
                    if (e != NULL) {
                        self->unk1D8 = e->unk24;
                        e->unk28 = 0;
                        e->unk3C = 0x2000;
                        VCALL(e, 14, 0x1000, 0x1000, 0x2000);
                        e->unk29 = 1;
                    }
                    e = func_02066774(data_ov006_021ec4ad, data_ov006_021ec4c8, data_ov006_021ec4c8, &self->pos);
                    if (e != NULL) {
                        self->unk1DC = e->unk24;
                        e->unk28 = 0;
                        e->unk3C = 0x2000;
                        VCALL(e, 14, 0x1000, 0x1000, 0x2000);
                        e->unk29 = 1;
                    }
                    if (self->unk19E == data_ov006_021ec884->unk5) {
                        func_02049a48(data_02097e4c, 0x51, -1, -1, -1);
                    }
                }
                if (++self->unk227 > 30) {
                    self->unk227 = 0;
                    if (++self->unk223 > 99) {
                        self->unk223 = 99;
                    }
                }
            }
        } else {
            ov006_ModeDown(self);
        }
        accel = self->unkAC[4] * 5 + 0x10;
        max = (self->unkAC[5] << 7) + (self->unkAC[5] << 5) + 0xe66;
        if (self->unk1CC >= 0x3c) {
            if (self->unk1AD >= data_ov006_021ec884->numActive - 1) {
                accel += 0x18;
            }
            if (data_ov006_021ec860->unk1C == 0) {
                ov006_SlotManager *mgr = data_ov006_021ec884;
                if (self->unk19E != mgr->unk5 && (func_ov006_021dab98(func_ov006_021db060(mgr, mgr->unk5))->unk3 & 3) < (u32)self->unk1AD) {
                    accel += 0x60;
                }
            }
        }
        if (self->boosting) {
            max = 0x199a;
            accel = self->unkAC[7] * 2 + 0x100;
            if (self->speed < 0x800) {
                self->speed = 0x800;
            }
        } else if (self->mode != 0) {
            if (self->speed >= 0xb84) {
                accel = -8 - ((self->speed - 0xb84) >> 7);
                if (self->speed + accel < 0xb84) {
                    accel = 0xb84 - self->speed;
                }
            }
        } else if (self->held & 0xf0) {
            if (self->speed > 0xa70) {
                accel = -16;
                if (self->trig & 0xf0) {
                    accel *= 2;
                }
                if (self->speed + accel < 0xa70) {
                    accel = 0xa70 - self->speed;
                }
            } else {
                accel -= accel >> 2;
            }
        }
        if (self->unk1FA != 0) {
            max = MUL(max, data_ov006_021eb8f8[self->unk1AD]);
        }
        if (self->speed > max) {
            if (self->speed - max > 0x28) {
                self->speed -= 0x28;
            } else {
                self->speed = max;
            }
            if (data_ov006_021ec884->unk13D == 0) {
                if (++self->unk226 > 30) {
                    self->unk226 = 0;
                    if (++self->unk222 > 99) {
                        self->unk222 = 99;
                    }
                }
            }
        } else {
            self->speed += accel;
            if (self->speed > max) {
                self->speed = max;
                if (data_ov006_021ec884->unk13D == 0) {
                    if (++self->unk226 > 30) {
                        self->unk226 = 0;
                        if (++self->unk222 > 99) {
                            self->unk222 = 99;
                        }
                    }
                }
            } else if (self->speed < 0xcd) {
                self->speed = 0xcd;
            }
        }
        if (self->boosting) {
            return;
        }
        if (self->mode != 0 || self->unk1D4 != 0) {
            return;
        }
        if (!(self->unk19C_0 & 1)) {
            return;
        }
        if (data_ov006_021ec884->unk13D != 0) {
            return;
        }
        e = func_02066774(data_ov006_021ec4ad, data_ov006_021ec4d4, data_ov006_021ec4d4, &self->pos);
        if (e == NULL) {
            return;
        }
        self->unk1D4 = e->unk24;
        VCALL(e, 30, &self->rot);
        e->unk28 = 0;
        VCALL(e, 0C, self->speed * 2 < 0x666 ? 0x666 : self->speed * 2);
        {
            s32 s = self->speed;
            if (s < 0xe66) {
                s32 d = 0xe66 - s;
                s = d + (d >> 1) + 0xe66;
            }
            e->unk3C = s;
        }
        if (self->speed >= 0xa70) {
            e->unk7C = FX_Div(0x10000, 0x1f000);
        }
    } else {
        BOOL c;
        self->speed -= 0x28;
        c = FALSE;
        if (self->unk19F > data_ov006_021ec884->unk8->unkB) {
            c = TRUE;
        }
        if (c) {
            self->speed -= 0x50;
        }
        if (self->speed < 0xcd) {
            self->speed = 0xcd;
        }
        ov006_ModeDown(self);
    }
}

}
