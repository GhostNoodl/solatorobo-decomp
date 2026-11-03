#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/LoTimer.h"

extern "C" {

void func_020627fc(s32 a);
void func_ov000_02182590(void *p);
void SceneCmd_Push27(void *p, s32 a, s32 b, s32 c);

void func_ov000_0216d9dc(void *self, s32 unused, u16 *msg) {
    u16 type = msg[0];
    void *p = LFLD(void *, msg, 8);
    u16 ang;
    if (type != 0x1e) {
        return;
    }
    ang = LFLD(u16, p, 0x44);
    MTX_Identity43_((MtxFx43 *)self);
    MTX_RotY43_((MtxFx43 *)self, FX_SinCosTable_[(ang >> 4) * 2], FX_SinCosTable_[(ang >> 4) * 2 + 1]);
}

void LoTimer_Setup(LoTimer *self, s32 mode, s32 limit, s32 c) {
    self->mode = mode;
    self->limit = limit;
    self->unk_28 = c;
    switch (mode) {
    case 1:
        self->shownTime = 0;
        self->time = 0;
        if (limit == 0) {
            self->limit = 0x7fffffff;
        }
        break;
    case 2:
        self->shownTime = limit;
        self->time = limit;
        break;
    }
    self->b7 = 0;
}

void func_ov000_0216da78(LoTimer *self) {
    s32 v = self->time;
    self->b9 = 1;
    self->b16 = 0;
    self->b5 = 1;
    self->b8 = 1;
    self->shownTime = v;
    if (self->b6 == 1) {
        FieldState *d;
        func_020627fc(4);
        d = data_ov000_021ccd54;
        d->stageFlags = 1;
        func_ov000_02182590((u8 *)d + 0xac);
        SceneCmd_Push27(data_ov000_021ccd54, 0xffff, 0, 0);
    }
}

}


extern "C" {
extern const s16 FX_SinCosTable_[];
extern int data_02097d78[];
bool TaskList_HasTasks_021735e8(void);
BOOL Model_IsReady(void *a, s32 b);
s32 FX_Div(s32 a, s32 b);
void func_020627fc(s32 a);
void func_ov000_02182590(void *p);
void SceneCmd_Push27(void *p, s32 a, s32 b, s32 c);


static inline BOOL GBusy0216dae4(FieldState *g) {
    return g->head != g->tail ? TRUE : FALSE;
}

static inline BOOL GIdle0216dae4(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (GBusy0216dae4(g)) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline BOOL FadeIdle0216dae4(void) {
    return (data_02097d78[3] == 0 && data_02097d78[0] == 0) ? TRUE : FALSE;
}

static inline BOOL Ready0216dae4(LoTimer *self) {
    if (!Model_IsReady(self->unk_10, 0xffff) || !Model_IsReady(self->unk_14, 0xffff)) {
        return FALSE;
    }
    return TRUE;
}

static inline void Done0216dae4(LoTimer *self) {
    s32 v = self->time;
    self->shownTime = v;
    self->b9 = 1;
    self->b16 = 0;
    self->b5 = 1;
    self->b8 = 1;
    if (self->b6 == 1) {
        FieldState *d;
        func_020627fc(4);
        d = data_ov000_021ccd54;
        d->stageFlags = 1;
        func_ov000_02182590((u8 *)d + 0xac);
        SceneCmd_Push27(data_ov000_021ccd54, 0xffff, 0, 0);
    }
}

BOOL LoTimer_Update(LoTimer *self) {
    if (self->b2 == 1) {
        if (!self->b0 && !TaskList_HasTasks_021735e8()) {
            self->b4 = 1;
        } else if (self->state == 7 || self->state == 9) {
            self->b4 = 0;
            self->f18 = 0;
        }
    }
    switch (self->state) {
    case 3:
        return FALSE;
    case 0:
        self->state = 1;
    case 1:
        self->state = 4;
    case 4:
        if (self->b2 && self->b4) {
            self->b3 = 1;
            self->state = 5;
        } else {
            if (self->b0) {
                self->state = 3;
            }
            break;
        }
    case 5:
        func_ov000_0216e67c(self);
        self->state = 6;
    case 6:
        if (!Ready0216dae4(self)) {
            break;
        }
        self->b5 = 1;
        self->slideTime = 0;
        self->slide = 0x1000;
        self->state = 8;
    case 8: {
        s32 t;
        self->slideTime += 0x1000;
        t = FX_Div(self->slideTime, 0x1e000);
        if (t >= 0x1000) {
            self->slideTime = 0;
            self->b5 = 0;
            t = 0x1000;
            if (self->b3) {
                self->state = 7;
            } else {
                self->state = 4;
                break;
            }
        }
        self->slide = FX_SinCosTable_[(((t * 0x4000) >> 12) >> 4) * 2];
        if (self->b3) {
            self->slide = 0x1000 - self->slide;
        }
    }
    case 7:
        if (self->b9 == 1) {
            func_ov000_0216eaf8(self);
        } else if ((self->b22 || FadeIdle0216dae4()) && (!self->b6 || GIdle0216dae4()) && self->b7 == 1) {
            if (self->mode == 2) {
                self->time -= self->step;
                if (self->time <= 0) {
                    self->time = 0;
                    self->b14 = 1;
                    if (self->b6 == 1) {
                        Done0216dae4(self);
                    }
                }
            } else {
                self->time += self->step;
                if (self->time >= 0x57e40) {
                    self->time = 0x57e40;
                }
                if (self->time > self->limit) {
                    self->time = self->limit;
                    self->b14 = 1;
                    if (self->b6 == 1) {
                        Done0216dae4(self);
                    }
                }
            }
        }
        if (self->b8 != 1) {
            self->shownTime = self->time;
        } else {
            func_ov000_0216e968(self);
        }
    case 9:
        if (!self->b2 || !self->b4) {
            self->b5 = 1;
            self->b3 = 0;
            self->state = 8;
        }
        break;
    }
    return TRUE;
}
}
