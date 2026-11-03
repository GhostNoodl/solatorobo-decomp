#include "types.h"
#include "ov003/ActorApi.h"
#include "ov003/Actor.h"
#include "ov000/ObjLayouts.h"
#include "ov003/Shot.h"

extern "C" {

extern void func_01ffc9fc(VecFx32 *src, VecFx32 *dst, u16 angle);
extern void Heap_Free(void *p);

Ov003Shot *Ov003ActVt_021f7de4_Dtor(Ov003Shot *self) {
    ActorEx_DtorBase(self);
    return self;
}

Ov003Shot *Ov003ActVt_021f7de4_DtorDelete(Ov003Shot *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

ActorEx *Ov003ActorEx_Ctor(ActorEx *self) {
    ActorEx_DtorBase(self);
    return self;
}

void Ov003Shot_Init(ActorEx *self) {
    VecFx32 v;
    ActorEx_Init(self);
    v.x = 0;
    v.y = 0;
    v.z = 0x1000;
    func_01ffc9fc(&v, &v, self->rot_y);
    VEC_Add(&v, &self->pos, &v);
    self->unk_84.x = v.x;
    self->unk_84.y = v.y;
    self->unk_84.z = v.z;
}

}
