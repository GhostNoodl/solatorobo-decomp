#include "ov014/ov014.h"

extern "C" {

extern u8 Ov014Act_0221267c_vtbl[];
extern char data_ov014_02217d8e[];
extern char data_ov014_02217d95[];
extern void *ResSet_Init(void *p);
extern void *Model0218fe1c_Init(void *p);
extern void *Model0218fe1c_FreeAnims(void *p);
extern void *ResSet_ReleaseAll(void *p);
extern BOOL Actor_IsReady(Ov003Actor *self);
extern BOOL ResSet_UpdateLoad(ResSet *p);
extern s32 Ov003Actor_HandleMsg(Ov003Actor *self, Ov014Msg *msg);

#pragma force_active on
Ov003Actor *Ov014Act_0221267c_Ctor(Ov014Act_0221267c *self) {
    Ov003Actor_Ctor(self);
    *(void **)self = Ov014Act_0221267c_vtbl;
    ResSet_Init(&self->unk_f0);
    Model0218fe1c_Init(&self->mdl);
    self->unk_310 = 0;
    self->unk_312 = 0;
    MIi_CpuClearFast(0, &self->unk_314, sizeof(Ov014JointMtx));
    self->unk_34c = 0;
    self->unk_348 = 0;
    self->unk_350 = 0;
    self->unk_354 = 0;
    return self;
}
#pragma force_active reset

Ov014Act_0221267c *Ov014Act_0221267c_Dtor(Ov014Act_0221267c *self) {
    Model0218fe1c_FreeAnims(&self->mdl);
    ResSet_ReleaseAll(&self->unk_f0);
    Ov003Actor_DtorBase(self);
    return self;
}

Ov014Act_0221267c *Ov014Act_0221267c_DtorDelete(Ov014Act_0221267c *self) {
    Model0218fe1c_FreeAnims(&self->mdl);
    ResSet_ReleaseAll(&self->unk_f0);
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

static inline void Ov014Names_Set(Ov014Names *n, const char *a, const char *b) {
    STD_CopyString(n->mdlDir, a);
    STD_CopyString(n->mdlName, b);
    n->ownMdl = 1;
}

void Ov014Act_0221267c_Init(Ov014Act_0221267c *self) {
    Ov003Actor_Init(self);
    {
        const char *b = data_ov014_02217d8e;
        Ov014Names *n = &self->unk_f0;
        if (b) {
            Ov014Names_Set(n, data_ov014_02217d95, b);
        }
        n->unk_00 = 0;
    }
}

}
