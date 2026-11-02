#include "ov014/ov014.h"

extern "C" {

extern u8 data_ov014_02217f18[];
extern void *ActorEx_Ctor(void *self);
extern void func_ov000_02194758(void *self);
extern BOOL func_ov000_02194c08(void *self);

void func_ov014_022152d4(Ov014ActEx_022142fc *self) {
    self->vfunc_08();
}

#pragma force_active on
Ov014ActEx_022152e8 *Ov014ActEx_022152e8_Ctor(Ov014ActEx_022152e8 *self) {
    ActorEx_Ctor(self);
    FLD(void *, self, 0) = data_ov014_02217f18;
    self->unk_d0.x = 0;
    self->unk_d0.y = 0;
    self->unk_d0.z = 0;
    self->unk_dc.x = 0;
    self->unk_dc.y = 0;
    self->unk_dc.z = 0;
    self->unk_f0 = 0;
    self->unk_e8 = 0;
    self->unk_ec = 0;
    self->unk_f4 = 0;
    return self;
}
#pragma force_active reset

void *Ov014ActEx_022152e8_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov014ActEx_022152e8_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void Ov014ActEx_022152e8_Draw(Ov014ActEx_022152e8 *self) {
    func_ov000_02194c08(self);
}

void Ov014ActEx_022152e8_Start(Ov014ActEx_022152e8 *self) {
    ActorSub44 *n;
    func_ov000_02194758(self);
    func_ov000_02198360(self->fsm, 0xb, 0);
    self->unk_44->unk_0c.y = 0;
    n = self->unk_44;
    n->unk_22_0 = 0;
    n->unk_22_1 = 0;
    self->hit->unk_30 = 0x60000000;
    self->hit->unk_4c = 0x9000;
    FLD(Ov014Flags, self->model, 0xc2).b4 = 0;
}

}
