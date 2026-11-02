#include "ov000/ActorBase.h"

extern "C" {

Actor *func_ov000_0218c928(Actor *self);
void Heap_Free(void *ptr);
void *Heap_Alloc(u32 size);
void *func_ov000_021b5054(void *p);
void func_0206e678(void);
extern void *data_ov000_021ccd6c;

Actor *Ov000ActVt_021cc7cc_Dtor(Actor *self) {
    func_ov000_0218c928(self);
    return self;
}

Actor *Ov000ActVt_021cc7cc_DtorDelete(Actor *self) {
    func_ov000_0218c928(self);
    Heap_Free(self);
    return self;
}

void func_ov000_021b4eec(void) {
    if (data_ov000_021ccd6c == NULL) {
        void *p = Heap_Alloc(0x294);
        if (p != NULL) {
            p = func_ov000_021b5054(p);
        }
        data_ov000_021ccd6c = p;
    }
    func_0206e678();
}

}
