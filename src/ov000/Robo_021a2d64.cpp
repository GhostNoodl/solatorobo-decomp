#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"

typedef struct {
    u16 b0 : 7;
    u16 b7 : 1;
    u16 b8 : 8;
} Ba4_021a2d64;

typedef struct {
    u16 state;
    u16 sub;
} St_021a2d64;

extern "C" {

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
void *func_02049f44(void *mgr, s32 id, void *pos, s32 a);

static inline BOOL GBusy021a2d64(FieldState *g) {
    return g->head != g->tail ? TRUE : FALSE;
}

static inline BOOL GReady(FieldState *g) {
    if (GBusy021a2d64(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}
static inline BOOL GIdle021a2d64(void) {
    FieldState *g = data_ov000_021ccd54;
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
    switch (((St_021a2d64 *)self->fsm)->state) {
    case 0: {
        s32 lim;
        BOOL fall;
        self->unk_b24_17 = 0;
        self->gravity = 0x29;
        self->unk_b36 = 0;
        if (!(self->msg_flags & 0x80)) {
            ActorSub48 *s48 = self->hit;
            s32 d = self->pos.y - s48->check.y;
            if (d <= 0 && !(s48->unk_54 & 0x20000000)) {
                flag = TRUE;
            } else if (d > 0x28cd) {
                flag = TRUE;
            }
        }
        if (self->unk_b22_3) {
            if (!flag) {
                self->velY = 0;
            }
            if (idle) {
                EffectObj *e = func_02065f88(0x2bd, &self->pos);
                e->speed = 0x2000;
                e->SetScaleAll(0x159a);
                func_02049f44(data_02097e4c, 0x35, (u8 *)self + 0x70, 0);
            }
            ((St_021a2d64 *)self->fsm)->sub = 2;
            ((St_021a2d64 *)self->fsm)->state++;
        } else if (idle && (Ba4_021a2d64 *)self->unk_ba4 != NULL && ((Ba4_021a2d64 *)self->unk_ba4)[3].b7 &&
                   self->unk_b38 >= 10) {
            u16 prev;
            func_ov000_02190cb0(self->model, data_ov000_021cc63c, 0x400, 0);
            func_ov000_021915a0(self->model);
            if (!flag) {
                if (self->speed > 0x29) {
                    if (self->velY < -0x60) {
                        self->velY = -0x60;
                    }
                } else {
                    self->velY = 0x85;
                }
            }
            func_ov000_021b1dd8((u8 *)self, self->unk_b08 >> 2, 0x200, 0xf00, 0, 1);
            prev = self->rot_y;
            self->rot_y = prev + 0xe00;
            if (prev > 0x8000 && self->rot_y < 0x8000) {
                func_02049f44(data_02097e4c, 0x35, (u8 *)self + 0x70, 0);
            }
            ((St_021a2d64 *)self->fsm)->sub = 2;
        } else if (((St_021a2d64 *)self->fsm)->sub == 0) {
            func_ov000_02190cb0(self->model, data_ov000_021cc642, 0x1000, 1);
            if (!flag) {
                if (self->speed > 0x29) {
                    if (self->velY < -0x60) {
                        self->velY = -0x60;
                    }
                } else {
                    self->velY = 0x5c;
                }
            }
            ((St_021a2d64 *)self->fsm)->sub = 4;
            if (!idle) {
                Model0218fe1c *mdl = self->model;
                mdl->evScript = NULL;
                mdl->evCursor = NULL;
                ((St_021a2d64 *)self->fsm)->sub = 5;
            }
            ((St_021a2d64 *)self->fsm)->state++;
        } else {
            ((St_021a2d64 *)self->fsm)->state++;
        }
        fall = FALSE;
        if (!(self->hit->unk_54 & 0x20000000)) {
            lim = -0xf000;
            if (self->unk_b22_0 != 0 || self->unk_b24_12 != 0 || self->unk_b24_19) {
                lim = -0x2d000;
            }
            if (self->pos.y - self->unk_afc.y < lim) {
                fall = TRUE;
            }
        }
        if (fall) {
            self->unk_b24_18 = 1;
            self->gravity = 0x52;
            func_ov000_02198360(self->fsm, 4, 0);
        }
        break;
    }
    case 1:
        if (idle) {
            func_ov000_021b1dd8((u8 *)self, self->unk_b08 >> 2, 0x200, 0xf00, 0x466, 1);
        } else {
            func_ov000_021987b8(self->hit, 0, 0, 0);
        }
        st = (St_021a2d64 *)self->fsm;
        if (st->sub != 0) {
            st->sub--;
        }
        if (st->sub == 0) {
            if (!self->unk_b22_3) {
                self->gravity = 0x52;
            }
            func_ov000_02198360(self->fsm, 4, 0);
        }
        break;
    }
    turned = FALSE;
    if (self->unk_b24_1 && (self->hit->unk_54 & 0x400)) {
        self->moveYaw = FX_Atan2(self->unk_af0.x - self->pos.x,
                                         self->unk_af0.z - self->pos.z);
        self->speed = 0x66;
        self->friction = 0;
        if (!self->unk_b24_17 || (self->hit->unk_50 & 0x40000000)) {
            self->velY = 0x200;
        }
        self->gravity = 0x52;
        self->unk_b24_17 = 1;
        turned = TRUE;
    }
    if (!turned) {
        return;
    }
    func_ov000_02190cb0(self->model, data_ov000_021cc62a, 0x800, 0);
    func_ov000_02198360(self->fsm, 4, 0);
}

}
