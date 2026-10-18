#include "ov000/Actor.h"

extern "C" {

extern char data_ov000_021cc5e3[];
void func_ov000_021b0db0(Actor *self, s32 id);

void func_ov000_021b0860(Actor *self) {
    switch (*(u16 *)self->unk_40) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov000_021cc5e3, 0x89, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        (*(u16 *)self->unk_40)++;
    case 1:
        func_ov000_021b0db0(self, 0);
        break;
    }
}

}
