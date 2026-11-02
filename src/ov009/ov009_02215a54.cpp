#include "ov009/ov009.h"

extern "C" {

extern Actor *Target_Get(void *p);
extern s32 func_ov000_0219a510(Actor *self, u16 mask, const VecFx32 *pos, s32 r, s32 a, void **list);
extern Ov003Actor *func_ov000_021985c0(void *p);
extern void Ov003Pickup_Update(Actor *self, s32 a);
extern s32 func_0203db40(void *p);
extern void func_ov000_02190a80(Model0218fe1c *m, s32 a);
extern ActorEx *func_ov000_0219429c(ActorEx *self);

void Ov009ActExVt_0221802c_StateFly(Ov009ActExVt_0221802c *self) {
    func_ov000_02198360(self->fsm, 0x15, 0);
}

void Ov009ActExVt_0221802c_HitNearby(Ov009ActExVt_0221802c *self) {
    void *list[0x20];
    s32 r = self->radius + 0x333;
    u16 grp;
    s32 n;
    s32 i;
    self->hit->unk_44 = r;
    grp = Target_Get(self->targetObj)->id & 0xf000;
    n = func_ov000_0219a510(self, ~(1 << (grp >> 12)), &self->pos, r, 0, list);
    if (n == 0) {
        return;
    }
    for (i = 0; i < n; i++) {
        Ov003Actor *a;
        if (list[i] != NULL && (a = func_ov000_021985c0(list[i])) != NULL) {
            ActorSub4c *p = a->targetObj;
            if (p == NULL || grp != (u16)(p->target & 0xf000)) {
                Ov003Pickup_Update(self, 0);
                func_ov000_02198360(self->fsm, 0x15, 0);
                return;
            }
        }
    }
}

void Ov009ActorEx_Animate(Ov003Actor *self) {
    if (self->model != NULL) {
        func_ov000_02190a80(self->model, func_0203db40(&self->pause));
    }
}

void Ov009ActorEx_State23(void) {
}

void Ov009ActorEx_State22(void) {
}

void Ov009ActorEx_State21(void) {
}

void Ov009ActorEx_State20(void) {
}

void Ov009ActorEx_StateHurt(void) {
}

void Ov009ActorEx_State0e(void) {
}

void Ov009ActorEx_StateMove(void) {
}

void *Ov009ActExVt_0221802c_DtorDelete(Ov009ActExVt_0221802c *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov009ActExVt_0221802c_Dtor(Ov009ActExVt_0221802c *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov009ActVt_022180c4_DtorDelete(ActorEx *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov009ActVt_022180c4_Dtor(ActorEx *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov009ActExVt_0221828c_DtorDelete(Ov009ActExVt_0221828c *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov009ActExVt_0221828c_Dtor(Ov009ActExVt_0221828c *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov009ActVt_02218324_DtorDelete(ActorEx *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov009ActVt_02218324_Dtor(ActorEx *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov009ActExVt_022181f4_Dtor(Ov009ActExVt_022181f4 *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov009ActExVt_022181f4_DtorDelete(Ov009ActExVt_022181f4 *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov009ActVt_0221815c_Dtor(ActorEx *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov009ActVt_0221815c_DtorDelete(ActorEx *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

}
