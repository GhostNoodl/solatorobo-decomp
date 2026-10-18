#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0xb22];
    u16 unk_b22_0 : 9;
    u16 unk_b22_9 : 2;
    u16 unk_b22_11 : 5;
    u32 unk_b24_0 : 1;
    u32 unk_b24_1 : 1;
    u32 unk_b24_2 : 2;
    u32 unk_b24_4 : 28;
    u8 unk_b28;
    u8 unk_b29_0 : 3;
    u8 unk_b29_3 : 1;
    u8 unk_b29_4 : 4;
} Obj0219d538;

extern "C" {

BOOL func_ov000_0218d17c(Obj0219d538 *self);

BOOL func_ov000_0219d538(Obj0219d538 *self) {
    BOOL r = func_ov000_0218d17c(self);
    if (!r) {
        return r;
    }
    if (self->unk_b28 != 0) {
        r = FALSE;
    }
    if (self->unk_b24_2 != 0) {
        r = FALSE;
    }
    if (self->unk_b22_9 != 0) {
        r = FALSE;
    }
    if (self->unk_b24_0 != 0) {
        r = FALSE;
    }
    if (self->unk_b29_3 != 0) {
        r = FALSE;
    }
    return r;
}

}
