#include "ov000/VObj.h"

typedef struct {
    u32 b0 : 1;
    u32 rest : 31;
    s32 unk_04;
    s32 unk_08;
} Obj021bc644;

extern "C" {

BOOL func_ov000_021bc474(Obj021bc644 *self);
BOOL func_ov000_021bca00(Obj021bc644 *self);

BOOL func_ov000_021bc644(Obj021bc644 *self) {
    BOOL r;
    if (self->unk_08 == 0) {
        return TRUE;
    }
    r = TRUE;
    switch (self->unk_08) {
    case 1:
        if (self->unk_04 == 2) {
            self->b0 = 1;
        } else {
            self->b0 = 0;
        }
        func_ov000_021bc474(self);
        r = FALSE;
        break;
    case 2:
        self->b0 = 0;
        func_ov000_021bc474(self);
        break;
    case 3:
        r = func_ov000_021bca00(self);
        break;
    }
    return r;
}

}
