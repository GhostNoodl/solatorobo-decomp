#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"

class Robo021b06dcCls;
typedef void (Robo021b06dcCls::*Robo021b06dcPmf)();

typedef struct {
    s32 key;
    Robo021b06dcPmf fn;
} Robo021b06dcEntry;

typedef struct {
    u16 b0 : 4;
    u16 b4 : 1;
    u16 b5 : 11;
} B9a_021b06dc;

typedef struct {
    u16 b0 : 10;
    u16 b10 : 1;
    u16 b11 : 5;
} B18_021b06dc;

extern "C" {

extern Robo021b06dcEntry data_ov000_021ca1b0[];
extern u8 *data_ov000_021ccd30;
extern u8 *data_0214a424;
void func_ov000_021697dc(void *p, u16 a, u16 b);
void func_ov000_0216b508(void *p, s32 a, BOOL b);

static inline BOOL PlayerIdle021b06dc(void) {
    FieldState *pl = data_ov000_021ccd54;
    if (pl != NULL) {
        if (pl->head != pl->tail ? TRUE : FALSE) {
            return FALSE;
        }
        if (pl->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline void SetGauge021b06dc(u16 a, u16 b) {
    u8 *o = LFLD(u8 *, data_ov000_021ccd30, 0x11c);
    if (o != NULL && LFLD(void *, o, 0x58) != NULL) {
        func_ov000_021697dc(LFLD(void *, o, 0x58), a, b);
        LFLD(u32, LFLD(u8 *, o, 0x58), 0xc) |= 0x80;
    }
}

void func_ov000_021b06dc(Robo021ca458 *self) {
    s32 k;
    s32 i;
    self->unk_b29 = 0;
    if (self->unk_b2e != 0) {
        self->unk_b2e--;
    }
    k = self->fsm->current;
    for (i = 0; i < 6; i++) {
        if (k == *(s32 *)((u8 *)data_ov000_021ca1b0 + i * 12)) {
            (((Robo021b06dcCls *)self)->*data_ov000_021ca1b0[i].fn)();
            break;
        }
    }
    if (LFLD(u16, ((u8 *)self->hp), 0xa) != 0) {
        LFLD(u16, ((u8 *)self->hp), 0xa)--;
    }
    {
        u8 *st = ((u8 *)self->fsm);
        LFLD(s64, st, 4) = 0;
    }
    self->hit->unk_9a_4 = 0;
    if (PlayerIdle021b06dc()) {
        SetGauge021b06dc(LFLD(u16, ((u8 *)self->hp), 0), LFLD(u16, ((u8 *)self->hp), 2));
    }
    {
        BOOL f = LFLD(B18_021b06dc, data_0214a424, 0x18).b10 ? TRUE : FALSE;
        u8 *o = LFLD(u8 *, data_ov000_021ccd30, 0x11c);
        if (o != NULL) {
            func_ov000_0216b508(LFLD(void *, o, 0x68), 1, f);
        }
    }
}

}
