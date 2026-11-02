#include "ov006/SlotManager.h"
#include "ov006/ov006.h"
#include "nitro/fx.h"
#include "Main/Effect/Effect.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Snd/SndMgr.h"
#include "ov006/Racer.h"


extern "C" {

extern char data_ov006_021ec4ad[];
extern char data_ov006_021ec4bc[];
extern char data_ov006_021ec4c8[];
extern char data_ov006_021ec4d4[];
extern u8 data_ov006_021eb908[];
extern s32 data_ov006_021eb8f8[];
ov006_Slot *ov006_SlotManager_GetSlot_021db060(ov006_SlotManager *self, u32 idx);
ov006_SlotSub *ov006_Slot_GetSub2C(ov006_Slot *self);

#define MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

static inline void ov006_ModeDown(Ov006Racer *self) {
    u32 mode = self->turnMode;
    if (mode != 0) {
        if (mode != 1) {
            self->turnMode = 1;
        } else {
            self->turnMode = 0;
        }
    }
}

void Ov006Racer_UpdateSpeed(Ov006Racer *self) {
    u16 drain;
    s32 accel;
    s32 max;
    EffectObj *e;

    self->boosting = 0;
    if ((self->held & 1) || ((self->held & 2) && self->boost != 0)) {
        if ((self->held & 2) && self->boost != 0) {
            self->boosting = 1;
            drain = 100 - self->prm->unk_07 * 4;
            if (self->trig & 2) {
                drain = 1000 - self->prm->unk_07 * 8;
                if ((self->unk_19c_0 & 1) && data_ov006_021ec884->unk13D == 0) {
                    func_02049f44(data_02097e4c, 0x32, &self->pos, 0);
                    if (self->unk_1d4 != 0) {
                        EffectObj *old = func_020657b0(data_0214a420, self->unk_1d4);
                        if (old != NULL) {
                            old->state = 4;
                            self->unk_1d4 = 0;
                        }
                    }
                    e = Effect3D_Create(data_ov006_021ec4ad, data_ov006_021ec4bc, data_ov006_021ec4bc, &self->pos);
                    if (e != NULL) {
                        self->unk_1d4 = e->id;
                        e->speed = 0x2000;
                        e->SetScaleAll(0x4000);
                        e->SetRot(&self->rot);
                    }
                }
            } else if (self->unk_1d4 == 0 && (self->unk_19c_0 & 1) && data_ov006_021ec884->unk13D == 0) {
                e = func_02065f88(0x4b0, &self->pos);
                if (e != NULL) {
                    self->unk_1d4 = e->id;
                    e->SetScaleAll(0x1ccd);
                    e->SetRot(&self->rot);
                    e->alpha = FX_Div(0x15000, 0x1f000);
                }
            }
            if (self->rank >= data_ov006_021ec884->numActive - 1) {
                drain -= 15;
            }
            if (self->boost < drain) {
                self->boost = 0;
            } else {
                self->boost -= drain;
            }
        }
        if ((self->held & 0x300) && self->runSpeed >= 0x95b) {
            if (self->turnMode < 2) {
                self->turnMode = 2;
            }
            if (self->turnMode == 2) {
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
                        self->turnMode = data_ov006_021eb908[idx];
                    }
                }
            } else if (data_ov006_021ec884->unk13D == 0) {
                if (self->unk_1d8 == 0 && (self->unk_19c_0 & 1)) {
                    EffectObj *e;
                    e = Effect3D_Create(data_ov006_021ec4ad, data_ov006_021ec4c8, data_ov006_021ec4c8, &self->pos);
                    if (e != NULL) {
                        self->unk_1d8 = e->id;
                        e->unk_28 = 0;
                        e->speed = 0x2000;
                        e->SetScaleXYZ(0x1000, 0x1000, 0x2000);
                        e->unk_29 = 1;
                    }
                    e = Effect3D_Create(data_ov006_021ec4ad, data_ov006_021ec4c8, data_ov006_021ec4c8, &self->pos);
                    if (e != NULL) {
                        self->unk_1dc = e->id;
                        e->unk_28 = 0;
                        e->speed = 0x2000;
                        e->SetScaleXYZ(0x1000, 0x1000, 0x2000);
                        e->unk_29 = 1;
                    }
                    if (self->idx == data_ov006_021ec884->unk5) {
                        func_02049a48(data_02097e4c, 0x51, -1, -1, -1);
                    }
                }
                if (++self->unk_227 > 30) {
                    self->unk_227 = 0;
                    if (++self->unk_21e[5] > 99) {
                        self->unk_21e[5] = 99;
                    }
                }
            }
        } else {
            ov006_ModeDown(self);
        }
        accel = self->prm->unk_04 * 5 + 0x10;
        max = (self->prm->unk_05 << 7) + (self->prm->unk_05 << 5) + 0xe66;
        if (self->unk_1cc >= 0x3c) {
            if (self->rank >= data_ov006_021ec884->numActive - 1) {
                accel += 0x18;
            }
            if (data_ov006_021ec860->unk1C == 0) {
                ov006_SlotManager *mgr = data_ov006_021ec884;
                if (self->idx != mgr->unk5 && (ov006_Slot_GetSub2C(ov006_SlotManager_GetSlot_021db060(mgr, mgr->unk5))->unk3 & 3) < (u32)self->rank) {
                    accel += 0x60;
                }
            }
        }
        if (self->boosting) {
            max = 0x199a;
            accel = self->prm->unk_07 * 2 + 0x100;
            if (self->runSpeed < 0x800) {
                self->runSpeed = 0x800;
            }
        } else if (self->turnMode != 0) {
            if (self->runSpeed >= 0xb84) {
                accel = -8 - ((self->runSpeed - 0xb84) >> 7);
                if (self->runSpeed + accel < 0xb84) {
                    accel = 0xb84 - self->runSpeed;
                }
            }
        } else if (self->held & 0xf0) {
            if (self->runSpeed > 0xa70) {
                accel = -16;
                if (self->trig & 0xf0) {
                    accel *= 2;
                }
                if (self->runSpeed + accel < 0xa70) {
                    accel = 0xa70 - self->runSpeed;
                }
            } else {
                accel -= accel >> 2;
            }
        }
        if (self->unk_1fa != 0) {
            max = MUL(max, data_ov006_021eb8f8[self->rank]);
        }
        if (self->runSpeed > max) {
            if (self->runSpeed - max > 0x28) {
                self->runSpeed -= 0x28;
            } else {
                self->runSpeed = max;
            }
            if (data_ov006_021ec884->unk13D == 0) {
                if (++self->unk_226 > 30) {
                    self->unk_226 = 0;
                    if (++self->unk_21e[4] > 99) {
                        self->unk_21e[4] = 99;
                    }
                }
            }
        } else {
            self->runSpeed += accel;
            if (self->runSpeed > max) {
                self->runSpeed = max;
                if (data_ov006_021ec884->unk13D == 0) {
                    if (++self->unk_226 > 30) {
                        self->unk_226 = 0;
                        if (++self->unk_21e[4] > 99) {
                            self->unk_21e[4] = 99;
                        }
                    }
                }
            } else if (self->runSpeed < 0xcd) {
                self->runSpeed = 0xcd;
            }
        }
        if (self->boosting) {
            return;
        }
        if (self->turnMode != 0 || self->unk_1d4 != 0) {
            return;
        }
        if (!(self->unk_19c_0 & 1)) {
            return;
        }
        if (data_ov006_021ec884->unk13D != 0) {
            return;
        }
        e = Effect3D_Create(data_ov006_021ec4ad, data_ov006_021ec4d4, data_ov006_021ec4d4, &self->pos);
        if (e == NULL) {
            return;
        }
        self->unk_1d4 = e->id;
        e->SetRot(&self->rot);
        e->unk_28 = 0;
        e->SetScaleAll(self->runSpeed * 2 < 0x666 ? 0x666 : self->runSpeed * 2);
        {
            s32 s = self->runSpeed;
            if (s < 0xe66) {
                s32 d = 0xe66 - s;
                s = d + (d >> 1) + 0xe66;
            }
            e->speed = s;
        }
        if (self->runSpeed >= 0xa70) {
            e->alpha = FX_Div(0x10000, 0x1f000);
        }
    } else {
        BOOL c;
        self->runSpeed -= 0x28;
        c = FALSE;
        if (self->unk_19f > data_ov006_021ec884->info->unkB) {
            c = TRUE;
        }
        if (c) {
            self->runSpeed -= 0x50;
        }
        if (self->runSpeed < 0xcd) {
            self->runSpeed = 0xcd;
        }
        ov006_ModeDown(self);
    }
}

}
