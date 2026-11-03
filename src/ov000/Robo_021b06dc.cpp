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

extern Robo021b06dcEntry Robo021ca458_Mode5StateTable[];
void func_ov000_021697dc(Lo021cb798 *p, u16 a, u16 b);
void Lo0216b474_Ask(Lo0216b474 *p, s32 want, BOOL part22);

static inline BOOL PlayerIdle021b06dc(void) {
    FieldState *pl = gSceneCmd;
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
    // gMessageQueue is the field's MessageQueue021cb980 (Main/Sys/Field.h's view of it is FieldPlayer)
    ListBuffer021cb940 *o = (ListBuffer021cb940 *)gMessageQueue->unk_11c;
    if (o != NULL && o->unk_58 != NULL) {
        func_ov000_021697dc(o->unk_58, a, b);
        o->unk_58->unk_0c |= 0x80;
    }
}

void Robo021ca458_RunMode5State(Robo021ca458 *self) {
    s32 k;
    s32 i;
    self->unk_b29 = 0;
    if (self->unk_b2e != 0) {
        self->unk_b2e--;
    }
    k = self->fsm->current;
    for (i = 0; i < 6; i++) {
        if (k == *(s32 *)((u8 *)Robo021ca458_Mode5StateTable + i * 12)) {
            (((Robo021b06dcCls *)self)->*Robo021ca458_Mode5StateTable[i].fn)();
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
        BOOL f = gStageFlags->bits18.flag10 ? TRUE : FALSE;
        ListBuffer021cb940 *o = (ListBuffer021cb940 *)gMessageQueue->unk_11c;
        if (o != NULL) {
            Lo0216b474_Ask(o->unk_68, 1, f);
        }
    }
}

}
