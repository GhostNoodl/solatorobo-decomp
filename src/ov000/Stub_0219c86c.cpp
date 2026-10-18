#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x1b];
    u8 unk_1b;
} Sub0219c86c;

typedef struct {
    u8 unk_00[0x3c];
    Sub0219c86c *unk_3c;
    u8 unk_40[0x154];
    s16 unk_194;
    u8 unk_196[0x2ba];
    s16 unk_450;
    u8 unk_452[0x40e];
    s16 unk_860;
    u8 unk_862[0x13a];
    s16 *unk_99c;
} Obj0219c86c;

extern "C" {

BOOL func_ov000_0219c86c(Obj0219c86c *self) {
    BOOL r = TRUE;
    BOOL ok;
    u8 k;
    if (self->unk_194 >= 0) {
        r = FALSE;
    }
    if (self->unk_450 >= 0) {
        r = FALSE;
    }
    if (self->unk_860 >= 0) {
        r = FALSE;
    }
    k = self->unk_3c->unk_1b;
    ok = TRUE;
    if (k != 3 && k != 0) {
        ok = FALSE;
    }
    if (!ok) {
        r = FALSE;
    }
    if (self->unk_99c != NULL && *self->unk_99c >= 0) {
        r = FALSE;
    }
    return r;
}

}
