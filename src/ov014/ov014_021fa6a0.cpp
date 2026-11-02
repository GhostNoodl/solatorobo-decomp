#include "ov014/ov014.h"

struct Ov014A {
    u8 unk_00[0xf8];
    VecFx32 unk_f8[2];
};

extern "C" {

extern u8 data_ov014_02217114[];
extern const VecFx32 data_ov014_02216468[];
extern char data_ov014_022170d8[];
extern char data_ov014_022170e7[];
extern char data_ov014_022170f4[];

extern void *ResSet_Init(void *p);
extern void *Model0218fe1c_Init(void *p);
extern void *Model0218fe1c_FreeAnims(void *p);
extern void *ResSet_ReleaseAll(void *p);
extern void SndMgr_LoadHeapState(SndMgr *a, s32 b, s32 c);
extern void func_ov000_02187a20(void *a, s32 b);

#pragma force_active on
Ov003Actor *Ov014Act_021fa6a0_Ctor(Ov014Act_021fa6a0 *self) {
    u8 i;
    Ov003Actor_Ctor(self);
    *(void **)self = data_ov014_02217114;
    ResSet_Init(&self->unk_124);
    Model0218fe1c_Init(&self->mdl);
    Ov003ScriptList_Init(&self->scripts);
    for (i = 0; i < 2; i++) {
        ((Ov014A *)self)->unk_f8[i] = data_ov014_02216468[i];
    }
    self->unk_f0 = 0;
    self->unk_f4 = 0;
    self->step = NULL;
    self->unk_11e = 0;
    self->unk_11f = 0;
    self->unk_364 = 0x1000;
    return self;
}
#pragma force_active reset

static inline void Ov014_StopSnd(void) {
    if (ResMgr_IsLoaded(data_ov014_022170d8, 7)) {
        ResMgr_ReleaseByName(data_02097cdc, data_ov014_022170d8, 7, 0);
    }
}

Ov014Act_021fa6a0 *Ov014Act_021fa6a0_Dtor(Ov014Act_021fa6a0 *self) {
    *(void **)self = data_ov014_02217114;
    Ov014_StopSnd();
    Ov003Vt_021f7974_Dtor(&self->scripts);
    Model0218fe1c_FreeAnims(&self->mdl);
    ResSet_ReleaseAll(&self->unk_124);
    Ov003Actor_DtorBase(self);
    return self;
}

Ov014Act_021fa6a0 *Ov014Act_021fa6a0_DtorDelete(Ov014Act_021fa6a0 *self) {
    *(void **)self = data_ov014_02217114;
    Ov014_StopSnd();
    Ov003Vt_021f7974_Dtor(&self->scripts);
    Model0218fe1c_FreeAnims(&self->mdl);
    ResSet_ReleaseAll(&self->unk_124);
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

}
