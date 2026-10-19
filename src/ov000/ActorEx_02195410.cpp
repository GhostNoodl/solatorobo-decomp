#include "ov000/Actor.h"
#include "ov000/LoCommon.h"

extern "C" {
extern s32 data_ov000_021c9d9c[];
extern s32 data_ov000_021c9db0[];
extern s32 data_ov000_021c9dc4[];
BOOL func_ov000_0219840c(void *s, s32 *list, s32 count, BOOL push);
void func_ov000_0218d7e8(void *self, u8 arg);

void func_ov000_02195410(u8 *self) {
    ActorSub40 *s = LFLD(ActorSub40 *, self, 0x40);
    if (s->flags != 0) {
        if (!func_ov000_0219840c(s, data_ov000_021c9d9c, 5, TRUE)) {
            if (LFLD(ActorSub40 *, self, 0x40)->flags & 2) {
                func_ov000_02198360(LFLD(void *, self, 0x40), 1, 1);
            }
        }
    }
    s = LFLD(ActorSub40 *, self, 0x40);
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
        if ((s->flags & 0x400) && (LFLD(u32, self, 0x30) & 0x80)) {
            s->flags &= ~0x400;
            LFLD(u16, LFLD(void *, self, 0x4c), 0x1c) = 0xffff;
        }
        if (!func_ov000_0219840c(LFLD(void *, self, 0x40), data_ov000_021c9dc4, 9, TRUE)) {
            func_ov000_02198360(LFLD(void *, self, 0x40), 1, 0);
        }
        break;
    }
    func_ov000_0218d7e8(self, LFLD(ActorSub40 *, self, 0x40)->unk_13);
}
}
