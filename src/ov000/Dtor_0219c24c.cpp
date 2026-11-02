#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#include "ov000/HeapScope.h"
#include "ov000/ObjLayouts.h"
#include "ov000/ActorMarker.h"

extern "C" {

extern u8 data_ov000_021cc774[];
void *func_ov000_0218fee4(void *p);
void *func_ov000_0218ea20(void *p);
void func_0203f2b8(void *p);
void *func_ov000_0218c928(void *p);

u8 *Robo021ca458_Dtor(Robo021ca458 *self) {
    LFLD(void *, self, 0x00) = data_ov000_021cc774;
    HEAP_DELETE_FN(self->unk_998, func_ov000_0218fee4);
    HEAP_DELETE_FN(self->unk_99c, func_ov000_0218ea20);
    HEAP_DELETE_MARKER(self->unk_9b0);
    HEAP_DELETE_MARKER(self->unk_9b4);
    self->model = NULL;
    self->unk_34 = 0;
    self->hit = NULL;
    func_ov000_0218ea20(&self->res3);
    func_ov000_0218fee4(&self->mdl2);
    func_0203f2b8(&self->hit1);
    func_ov000_0218ea20(&self->res2);
    func_ov000_0218ea20(&self->res1);
    func_ov000_0218fee4(&self->mdl1);
    func_0203f2b8(&self->hit0);
    func_ov000_0218ea20(&self->res0);
    func_ov000_0218fee4(&self->mdl0);
    func_ov000_0218c928(self);
    return (u8 *)self;
}

u8 *Robo021ca458_DtorDelete(Robo021ca458 *self) {
    LFLD(void *, self, 0x00) = data_ov000_021cc774;
    HEAP_DELETE_FN(self->unk_998, func_ov000_0218fee4);
    HEAP_DELETE_FN(self->unk_99c, func_ov000_0218ea20);
    HEAP_DELETE_MARKER(self->unk_9b0);
    HEAP_DELETE_MARKER(self->unk_9b4);
    self->model = NULL;
    self->unk_34 = 0;
    self->hit = NULL;
    func_ov000_0218ea20(&self->res3);
    func_ov000_0218fee4(&self->mdl2);
    func_0203f2b8(&self->hit1);
    func_ov000_0218ea20(&self->res2);
    func_ov000_0218ea20(&self->res1);
    func_ov000_0218fee4(&self->mdl1);
    func_0203f2b8(&self->hit0);
    func_ov000_0218ea20(&self->res0);
    func_ov000_0218fee4(&self->mdl0);
    func_ov000_0218c928(self);
    Heap_Free(self);
    return (u8 *)self;
}

}
