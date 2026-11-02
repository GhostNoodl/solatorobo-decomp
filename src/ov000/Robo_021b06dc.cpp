#include "ov000/LoCommon.h"
#include "Main/Res/StageCmd.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "ov000/MessageQueue.h"

class Robo021b06dcCls;
typedef void (Robo021b06dcCls::*Robo021b06dcPmf)();

typedef struct {
    s32 key;
    Robo021b06dcPmf fn;
} Robo021b06dcEntry;

extern "C" {

extern Robo021b06dcEntry data_ov000_021ca1b0[];
void func_ov000_021697dc(Lo021cb798 *p, u16 a, u16 b);
void Lo0216b474_Ask(Lo0216b474 *p, s32 want, BOOL part22);

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
    // data_ov000_021ccd30 is the field's MessageQueue021cb980 (Main/Sys/Field.h's view of it is FieldPlayer)
    ListBuffer021cb940 *o = (ListBuffer021cb940 *)data_ov000_021ccd30->unk_11c;
    if (o != NULL && o->unk_58 != NULL) {
        func_ov000_021697dc(o->unk_58, a, b);
        o->unk_58->unk_0c |= 0x80;
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
    if (self->hpObj->unk_0a != 0) {
        self->hpObj->unk_0a--;
    }
    {
        ActorSub40 *st = (ActorSub40 *)((u8 *)self->fsm);
        st->flags = 0;
    }
    self->hit->unk_9a_4 = 0;
    if (PlayerIdle021b06dc()) {
        SetGauge021b06dc(self->hpObj->cur, self->hpObj->max);
    }
    {
        BOOL f = data_0214a424->bits18.flag10 ? TRUE : FALSE;
        ListBuffer021cb940 *o = (ListBuffer021cb940 *)data_ov000_021ccd30->unk_11c;
        if (o != NULL) {
            Lo0216b474_Ask(o->unk_68, 1, f);
        }
    }
}

}
