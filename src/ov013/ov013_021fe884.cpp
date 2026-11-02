#include "ov013/ov013.h"

struct Ov013Spot {
    VecFx32 pos;
    u16 rot;
};

extern "C" {

extern char data_ov013_0220b88d[];
extern void func_ov000_0219763c(Actor *self);
extern void func_ov000_02195d88(Actor *self);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern ActorGroup *ActorMgr_GetGroup(void *mgr, u16 id);
extern BOOL Ov003Vec_Equal(void *a, const Ov013Spot *b);

void func_ov013_021fe884(Ov013ActEx_021fdb70 *self) {
    if (self->fsm->st == 0) {
        EffectObj *p = func_020657b0(data_0214a420, self->unk_d0);
        if (p != NULL) {
            p->state = 4;
            self->unk_d0 = -1;
        }
    }
    func_ov000_0219763c(self);
}

void func_ov013_021fe8d0(Ov003Actor *self) {
    if (self->model != NULL) {
        func_ov000_02190a80(self->model, func_0203db40((u8 *)self + 0x24));
    }
}

void func_ov013_021fe8fc(void) {
}

void func_ov013_021fe900(void) {
}

void func_ov013_021fe904(void) {
}

void func_ov013_021fe908(void) {
}

void func_ov013_021fe90c(void) {
}

void func_ov013_021fe910(void) {
}

Ov013ActEx_021fdb70 *Ov013ActEx_021fdb70_DtorDelete(Ov013ActEx_021fdb70 *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

Ov013ActEx_021fdb70 *Ov013ActEx_021fdb70_Dtor(Ov013ActEx_021fdb70 *self) {
    func_ov000_0219429c(self);
    return self;
}

void func_ov013_021fe944(void) {
}

}
