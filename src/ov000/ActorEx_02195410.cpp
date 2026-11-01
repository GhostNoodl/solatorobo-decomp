#include "ov000/Actor.h"
#include "ov000/LoCommon.h"

extern "C" {
extern s32 data_ov000_021c9d9c[];
extern s32 data_ov000_021c9db0[];
extern s32 data_ov000_021c9dc4[];
BOOL func_ov000_0219840c(void *s, s32 *list, s32 count, BOOL push);
void func_ov000_0218d7e8(void *self, u8 arg);

struct Obj02195410 {
    u8 unk_00[0x30];
    u32 unk_30;
    u8 unk_34[0xc];
    ActorSub40 *unk_40;
    u8 unk_44[0x8];
    void *unk_4c;
};

void func_ov000_02195410(Obj02195410 *self) {
    ActorSub40 *s = self->unk_40;
    if (s->flags != 0) {
        if (!func_ov000_0219840c(s, data_ov000_021c9d9c, 5, TRUE)) {
            if (self->unk_40->flags & 2) {
                func_ov000_02198360(self->unk_40, 1, 1);
            }
        }
    }
    s = self->unk_40;
    switch (s->unk_13) {
    case 9:
        func_ov000_0219840c(s, data_ov000_021c9db0, 5, TRUE);
        break;
    case 11:
        if (s->flags & 0x200) {
            func_ov000_02198360(s, 9, 0);
        } else if (s->flags & 0x800) {
            func_ov000_02198360(s, 0xb, 1);
        }
        break;
    case 4:
    case 10:
        if (s->flags & 0x200) {
            func_ov000_02198360(s, 9, 0);
        } else if (s->flags & 0x800) {
            func_ov000_02198360(s, 0xb, 0);
        }
        break;
    case 14:
        if (s->flags & 0x200) {
            func_ov000_02198360(s, 9, 0);
        }
        break;
    case 0:
        func_ov000_0219840c(s, data_ov000_021c9dc4, 9, TRUE);
        break;
    case 1:
    case 2:
        if ((s->flags & 0x400) && (self->unk_30 & 0x80)) {
            s->flags &= ~0x400;
            LFLD(u16, self->unk_4c, 0x1c) = 0xffff;
        }
        if (!func_ov000_0219840c(self->unk_40, data_ov000_021c9dc4, 9, TRUE)) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    func_ov000_0218d7e8(self, self->unk_40->unk_13);
}
}
