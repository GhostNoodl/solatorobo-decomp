#include "ov013/ov013.h"

extern "C" {

extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern BOOL Hit_ApplyInArea(void *a, void *b, u16 c, u8 d, u16 mask, void *v, s32 e, s32 f, s32 g, s32 h, s32 i);

static inline Ov003Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}


void Ov013ActEx_0220a9a8_State0a(Ov013ActEx_0220a9a8 *self) {
    s32 v = 0;
    EffectObj *p;
    Ov003Actor *t;
    p = Effect_Find_020657b0(data_0214a420, ((s32)self->unk_bc));
    if (p != NULL) {
        EffectObj *q;
        v = p->alpha;
        if (v > 0) {
            v -= 0x52;
        }
        p->alpha = v < 0 ? 0 : v;
        p->alpha = v > 0x1000 ? 0x1000 : v;
        q = p->child;
        if (q != NULL) {
            q->alpha = v < 0 ? 0 : v;
            q->alpha = v > 0x1000 ? 0x1000 : v;
        }
    }
    if (v <= 0) {
        History_SetState(self->fsm, 0x15, 0);
        if (p != NULL) {
            p->state = 4;
        }
        return;
    }
    t = Ov013_FindActor(self->target);
    if (t == NULL) {
        return;
    }
    Hit_ApplyInArea(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, 1 << (t->id >> 12), NULL, 0,
                        self->hit->radius, self->unk_d0, -1, 0x1000);
}

Ov013ActEx_0220a9a8 *Ov013ActEx_0220a9a8_DtorDelete(Ov013ActEx_0220a9a8 *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov013ActEx_0220a9a8 *Ov013ActEx_0220a9a8_Dtor(Ov013ActEx_0220a9a8 *self) {
    ActorEx_DtorBase(self);
    return self;
}

Ov013ActEx_0220a4e0 *Ov013ActEx_0220a4e0_DtorDelete(Ov013ActEx_0220a4e0 *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov013ActEx_0220a4e0 *Ov013ActEx_0220a4e0_Dtor(Ov013ActEx_0220a4e0 *self) {
    ActorEx_DtorBase(self);
    return self;
}

}
