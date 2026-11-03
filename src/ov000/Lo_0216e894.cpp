#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "nitro/fx.h"
#include "ov000/LoTimer.h"

extern "C" {

Robo021ca458 *ActorMgr_FindPlayer(void);
BOOL Actor_IsDead(void);
void func_020627fc(u16 a);
void func_0206280c(u16 a);
void func_ov000_02182590(void *p);
extern void *SndMgr_PlayVolume(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *data_02097e4c;

void LoTimer_Finish(LoTimer *self) {
    if (self->b13 == 1) {
        return;
    }
    self->b13 = 1;
    if (self->b14 == 1) {
        self->result = 1;
    } else if (self->b10 == 1) {
        self->result = 2;
    } else {
        self->result = 3;
    }
    if (self->b6 != 1) {
        return;
    }
    ActorMgr_FindPlayer();
    if (!Actor_IsDead()) {
        s32 v = self->time;
        FieldState *g;
        if (v > 0xffff) {
            v = 0xffff;
        }
        func_020627fc(self->result);
        func_0206280c(v);
        g = data_ov000_021ccd54;
        ((u8 *)g)[0xac] = 1;
        func_ov000_02182590((u8 *)g + 0xac);
    }
    self->state = 9;
}

static inline void Bounce(LoTimer *self) {
    self->b16 = 0;
    self->b8 = 0;
    self->b10 = 1;
    self->unk_34 = 0x2000;
    self->unk_38 = 0x2000;
    self->unk_3c = 0;
}

void func_ov000_0216e968(LoTimer *self) {
    s32 t;
    if (!self->b16) {
        SndMgr_PlayVolume(data_02097e4c, 0x4a, -1, -1, -1);
        self->b16 = 1;
    }
    self->unk_38 += 0x1000;
    t = FX_Div(self->unk_38, 0x14000);
    if (t >= 0x1000) {
        t = 0x1000;
        if (self->unk_38 >= 0x3c000) {
            if (self->b9 == 1) {
                if (self->unk_38 >= 0x64000) {
                    if (self->mode == 2) {
                        if (self->b17 == 1 && !self->b14 && self->unk_28 != 0 && self->unk_28 < self->time) {
                            Bounce(self);
                        } else {
                            LoTimer_Finish(self);
                        }
                    } else {
                        if (self->b17 == 1 && !self->b14 && self->unk_28 != 0 && self->unk_28 > self->time) {
                            Bounce(self);
                        } else {
                            LoTimer_Finish(self);
                        }
                    }
                    self->unk_38 = 0;
                    self->b8 = 0;
                }
            } else {
                self->b5 = 0;
                self->unk_38 = 0;
                self->b8 = 0;
            }
        }
    }
    self->unk_3c = (s32)(((s64)FX_SinCosTable_[((s32)(t << 15) >> 16) * 2] * (s64)0x1800 + 0x800) >> 12);
}

}
