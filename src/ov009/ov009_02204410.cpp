#include "ov009/ov009.h"

extern "C" {

struct Ov009Msg {
    u8 unk_00[0x5];
    u8 type;
    u8 unk_06[0x2];
    u8 idx;
    u8 unk_09[0x3];
    Ov009Vec v;
};

extern void func_ov003_021d1c00(Ov009Actor *self, Ov009Msg *msg);

void func_ov009_02204410(Ov009Actor *self, Ov009Msg *msg) {
    if (msg->type == 0xe) {
        Ov009Vec *dst = (Ov009Vec *)((u8 *)self + msg->idx * 0xc + 0x10c);
        dst->x = msg->v.x;
        dst->y = msg->v.y;
        dst->z = msg->v.z;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
    }
    func_ov003_021d1c00(self, msg);
}

}
