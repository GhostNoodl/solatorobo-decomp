#include "ov006/ov006.h"
#include "Main/Gfx/SlidePanel.h"
#include "ov006/Racer.h"


extern "C" {

extern u8 Ov006ActVt_021ec4f4_vtbl[];
void *Actor_Ctor(void *self);
void *Model0218fe1c_Init(void *p);
u8 func_ov006_021d8d9c(void);
int func_ov006_021d8d4c(void);
int func_ov006_021d8de0(void);
void SndMgr_StopSeqArc(SndMgr *a, s32 b);
void *Model0218fe1c_FreeAnims(void *p);
void *Actor_DtorBase(void *self);

Ov006Racer *Ov006ActVt_021ec4f4_Ctor(Ov006Racer *self) {
    int i;
    Actor_Ctor(self);
    *(void **)self = Ov006ActVt_021ec4f4_vtbl;
    Model0218fe1c_Init(&self->mdl);
    self->prm = NULL;
    self->marker = NULL;
    self->unk_19c = 0;
    self->unk_19f = 0;
    self->runSpeed = 0;
    self->held = 0;
    self->trig = 0;
    self->release = 0;
    self->unk_1aa = 0;
    self->unk_1ab = 0;
    self->unk_1ac = 0;
    self->rank = 0xff;
    self->look.x = 0;
    self->look.y = 0;
    self->look.z = 0;
    self->lookVX = 0;
    self->lookVY = 0;
    self->unk_1b8 = 0;
    self->look2.x = 0;
    self->look2.y = 0;
    self->look2.z = 0;
    self->unk_1c0.x = 0;
    self->unk_1c0.y = 0;
    self->unk_1c0.z = 0;
    self->unk_1cc = 0;
    self->unk_1d0 = 0;
    self->unk_1d4 = 0;
    self->unk_1d8 = 0;
    self->unk_1dc = 0;
    self->unk_1e0 = 0;
    self->unk_1e4 = 0;
    self->unk_1e8 = 0;
    self->unk_1ec = 0;
    self->unk_1f0 = 0;
    self->unk_1f4 = 0;
    self->unk_1f5 = 0;
    self->boost = 1000;
    self->unk_1f8 = 0;
    self->unk_1fa = 0;
    self->unk_1fc = 0;
    self->seq = -1;
    self->ptCount = func_ov006_021d8d9c();
    self->pts = (Ov006RacerPt *)func_ov006_021d8d4c();
    self->goal = (Ov006RacerPt *)func_ov006_021d8de0();
    self->lastPt = 0;
    self->nextPt = 1;
    self->laps = 0;
    self->courseRot.x = 0;
    self->courseRot.y = 0;
    self->courseRot.z = 0;
    self->aim.x = 0;
    self->aim.y = 0;
    self->aim.z = 0;
    for (i = 0; i < 8; i++) {
        self->unk_21e[i] = 0;
    }
    self->unk_227 = 0;
    self->unk_226 = 0;
    return self;
}

static inline void Ov006Racer_Dtor(Ov006Racer *self) {
    *(void **)self = Ov006ActVt_021ec4f4_vtbl;
    OV006_DELETE_OBJECT(self->marker);
    if (self->seq > 0) {
        SndMgr_StopSeqArc(gSndMgr, self->seq);
    }
    Model0218fe1c_FreeAnims(&self->mdl);
    Actor_DtorBase(self);
}

Ov006Racer *Ov006ActVt_021ec4f4_Dtor(Ov006Racer *self) {
    Ov006Racer_Dtor(self);
    return self;
}

Ov006Racer *Ov006ActVt_021ec4f4_DtorDelete(Ov006Racer *self) {
    Ov006Racer_Dtor(self);
    Heap_Free(self);
    return self;
}

}
