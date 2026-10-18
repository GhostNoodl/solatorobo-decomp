#include "ov000/VObj.h"

extern "C" {

void func_ov000_0218c928(void *ptr);
void func_0203de1c(void *ptr);
void *func_0203dd9c(u32 size);
void *func_ov000_021b5054(void *p);
void func_0206e678(void);
extern void *data_ov000_021ccd6c;

void *func_ov000_021b4ebc(void *self) {
    func_ov000_0218c928(self);
    return self;
}

void *func_ov000_021b4ed0(void *self) {
    func_ov000_0218c928(self);
    func_0203de1c(self);
    return self;
}

void func_ov000_021b4eec(void) {
    if (data_ov000_021ccd6c == NULL) {
        void *p = func_0203dd9c(0x294);
        if (p != NULL) {
            p = func_ov000_021b5054(p);
        }
        data_ov000_021ccd6c = p;
    }
    func_0206e678();
}

}
