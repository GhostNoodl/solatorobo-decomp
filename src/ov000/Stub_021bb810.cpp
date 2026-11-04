#include "ov000/VObj.h"
#include "Main/Sys/SysState.h"
#include "Main/Effect/Effect.h"

typedef struct {
    s32 unk_00;
    s32 unk_04;
    u8 unk_08;
    s32 unk_0c;
    EffectObj *unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
} Obj021bb810;
SIZE_ASSERT(Obj021bb810, 0x20);

extern "C" {


static inline void Obj021bb810_Init(Obj021bb810 *self, s32 a) {
    self->unk_00 = 1;
    self->unk_04 = a;
    self->unk_08 = 1;
    self->unk_0c = -1;
    self->unk_10 = NULL;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
}

void Obj021bb810_Init_021bb810(Obj021bb810 *self, s32 a) {
    self->unk_00 = 1;
    self->unk_04 = a;
    self->unk_08 = 1;
    self->unk_0c = -1;
    self->unk_10 = NULL;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
}

void Obj021bb810_Release(Obj021bb810 *self) {
    if (EffectMgr_Contains(gEffectMgr, self->unk_10)) {
        void *saved = gSysState->cur;
        gSysState->cur = gSysState->heapHi;
        if (self->unk_10 != NULL) {
            if (self->unk_10 != NULL) {
                self->unk_10->Delete();
            }
            self->unk_10 = NULL;
        }
        gSysState->cur = saved;
    }
    Obj021bb810_Init(self, 0);
}

}
