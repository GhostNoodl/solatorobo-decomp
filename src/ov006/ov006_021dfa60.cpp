#include "ov006/Model.h"
#include "Main/Effect/Effect.h"

typedef struct ov006_Unk021dfa60 {
    void *vtbl;
    u8 unk4[0x10];
    int unk14;
    int unk18;
    VObj *unk1C;
    VObj *unk20;
} ov006_Unk021dfa60;

extern "C" {

extern u8 Ov006Vt_021ec23c_vtbl[];

static inline void ov006_Unk021dfa60_Kill(int id) {
    if (id != -1) {
        EffectObj *o = Effect_Find_020657b0(gEffectMgr, id);
        if (o != NULL) {
            void *saved = gSysState->cur;
            gSysState->cur = gSysState->heapHi;
            if (o != NULL) {
                if (o != NULL) {
                    o->Delete();
                }
            }
            gSysState->cur = saved;
        }
    }
}

static inline void ov006_Unk021dfa60_dtor(ov006_Unk021dfa60 *self) {
    self->vtbl = Ov006Vt_021ec23c_vtbl;
    ov006_Unk021dfa60_Kill(self->unk14);
    ov006_Unk021dfa60_Kill(self->unk18);
    OV006_DELETE_OBJECT(self->unk1C);
    OV006_DELETE_OBJECT(self->unk20);
}

ov006_Unk021dfa60 *Ov006Vt_021ec23c_Dtor(ov006_Unk021dfa60 *self) {
    ov006_Unk021dfa60_dtor(self);
    return self;
}

ov006_Unk021dfa60 *Ov006Vt_021ec23c_DtorDelete(ov006_Unk021dfa60 *self) {
    ov006_Unk021dfa60_dtor(self);
    Heap_Free(self);
    return self;
}

}
