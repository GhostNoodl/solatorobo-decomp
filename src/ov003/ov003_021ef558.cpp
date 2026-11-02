#include "types.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"
#include "ov003/ActorApi.h"

extern "C" {

extern void *data_ov000_021ccd64;
extern void func_ov000_0218bed8(void *mgr, s32 a, void *obj);
extern void Heap_Free(void *p);

void Ov003ActVt_021f9d78_Start(ActorEx *self) {
    BOOL keep;
    s16 sub;
    s16 mode;
    func_ov000_02197d80(self);
    sub = self->unk_1a;
    mode = self->unk_18;
    keep = TRUE;
    if (sub == 0) {
        if (mode == 1 || mode == 3 || (u16)(s16)(mode - 5) <= 1) {
            keep = FALSE;
        }
    } else {
        if (mode == 2 || (u16)(s16)(mode - 4) <= 2) {
            keep = FALSE;
        }
    }
    if (!keep) {
        func_ov000_0218bed8(data_ov000_021ccd64, 2, self);
        self->vfunc_08();
        return;
    }
    func_ov000_02194758(self);
}

ActorEx *Ov003ActVt_021f9f40_Dtor(ActorEx *self) {
    func_ov000_0219429c(self);
    return self;
}

ActorEx *Ov003ActVt_021f9f40_DtorDelete(ActorEx *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f9ea8_Dtor(ActorEx *self) {
    func_ov000_0219429c(self);
    return self;
}

ActorEx *Ov003ActVt_021f9ea8_DtorDelete(ActorEx *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f9ce0_Dtor(ActorEx *self) {
    func_ov000_0219429c(self);
    return self;
}

ActorEx *Ov003ActVt_021f9ce0_DtorDelete(ActorEx *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActVt_021f9d78_Dtor(ActorEx *self) {
    func_ov000_0219429c(self);
    return self;
}

ActorEx *Ov003ActVt_021f9d78_DtorDelete(ActorEx *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void Ov003ActVt_021fa07c_Start(ActorEx *self) {
    func_ov000_02194758(self);
    self->fsm->flags |= 0x100000000ULL;
    self->unk_84.x = self->pos.x;
    self->unk_84.y = self->pos.y;
    self->unk_84.z = self->pos.z;
}

}
