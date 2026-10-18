#include "ov009/ov009.h"

extern "C" {

extern char data_ov009_02216b98[];
extern BOOL func_02035b90(const char *name, s32 a);
extern BOOL func_ov000_0218cf5c(Ov009Actor *self);
extern void func_ov000_0219864c(void *a, s32 b, s32 c);
extern void func_0203f8d8(void *p);

BOOL func_ov009_02202acc(Ov009Actor *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (self->kind == 0x5055) {
        r = (r & func_02035b90(data_ov009_02216b98, 7)) ? TRUE : FALSE;
    }
    return r;
}

void func_ov009_02202b14(Ov009Actor *self) {
    if (self->unk_48 != NULL) {
        func_ov000_0219864c(self->unk_48, 0, 0);
    }
    if (FLD(void *, self, 0x58) != NULL) {
        func_0203f8d8(FLD(void *, self, 0x58));
    }
}

}
