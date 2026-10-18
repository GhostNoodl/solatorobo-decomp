#include "ov000/VObj.h"

typedef struct {
    u32 flag : 1;
    u32 rest : 31;
    s32 unk_04;
} Obj021bc458;

extern "C" {

void func_ov000_021bc458(Obj021bc458 *self) {
    self->flag = 1;
    self->unk_04 = 2;
}

}
