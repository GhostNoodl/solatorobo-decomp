#include "ov000/ActorBase.h"
#include "ov000/FieldMgr.h"

extern "C" {

Actor *Actor_DtorBase(Actor *self);
void Heap_Free(void *ptr);
void *Heap_Alloc(u32 size);
void func_0206e678(void);

Actor *Ov000ActVt_021cc7cc_Dtor(Actor *self) {
    Actor_DtorBase(self);
    return self;
}

Actor *Ov000ActVt_021cc7cc_DtorDelete(Actor *self) {
    Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

void func_ov000_021b4eec(void) {
    if (data_ov000_021ccd6c == NULL) {
        FieldMgr *p = (FieldMgr *)Heap_Alloc(sizeof(FieldMgr));
        if (p != NULL) {
            p = func_ov000_021b5054(p);
        }
        data_ov000_021ccd6c = p;
    }
    func_0206e678();
}

}
