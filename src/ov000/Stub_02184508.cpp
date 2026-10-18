#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x15];
    u8 unk_15;
    u8 unk_16[0xb12];
    u8 unk_b28_0 : 2;
    u8 unk_b28_2 : 1;
    u8 unk_b28_3 : 5;
} Obj0219bf90;

extern "C" {

Obj0219bf90 *func_ov000_0219bf90(void);

void func_ov000_02184508(void) {
    Obj0219bf90 *p = func_ov000_0219bf90();
    if (p == NULL) {
        return;
    }
    if (p->unk_b28_0 != 0) {
        return;
    }
    p->unk_15 = 3;
    p->unk_b28_0 = 0;
    p->unk_b28_2 = 1;
}

void func_ov000_02184548(void *self) {
    Obj0219bf90 *p;
    if (*((u8 *)self + 0xca) == 0xfe) {
        return;
    }
    p = func_ov000_0219bf90();
    if (p == NULL) {
        return;
    }
    if (p->unk_b28_0 != 0) {
        return;
    }
    p->unk_15 = 1;
    p->unk_b28_0 = 0;
    p->unk_b28_2 = 0;
}

}
