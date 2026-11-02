#include "ov000/VObj.h"

extern "C" {

void *func_ov000_0218c928(void *ptr);
void Heap_Free(void *ptr);
void *Heap_Alloc(u32 size);
void *func_ov000_021b5054(void *p);
void func_0206e678(void);
extern void *data_ov000_021ccd6c;

void *Ov000ActVt_021cc7cc_Dtor(void *self) {
    func_ov000_0218c928(self);
    return self;
}

void *Ov000ActVt_021cc7cc_DtorDelete(void *self) {
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
