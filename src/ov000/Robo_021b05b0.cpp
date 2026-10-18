#include "ov000/LoCommon.h"
#include "ov000/Actor.h"

extern "C" {
extern s32 data_ov000_021c9ff8[];
void func_ov000_02198360(void *s, s32 a, s32 b);
BOOL func_ov000_0219840c(void *s, s32 *list, s32 count, BOOL push);
void func_ov000_0218d7e8(void *self, u8 arg);

void func_ov000_021b05b0(u8 *self) {
    ActorSub40 *s;
    LFLD(void *, self, 0x38) = self + 0x368;
    LFLD(void *, self, 0x48) = self + 0x6c0;
    LFLD(s32, self, 0xb08) = 0x2cd;
    s = LFLD(ActorSub40 *, self, 0x40);
    if (s->flags != 0) {
        if (s->flags & 1) {
            return;
        }
        if (s->flags & 0x80000000) {
            func_ov000_02198360(s, 0x1f, 0);
        } else if (s->flags & 2) {
            func_ov000_02198360(s, 1, 1);
        } else if ((s->flags & 0x40000) || (s->flags & 0x80000)) {
            func_ov000_02198360(s, 0x12, 1);
        }
    }
    s = LFLD(ActorSub40 *, self, 0x40);
    switch (s->unk_13) {
    case 1:
        if (s->flags & 2) {
            break;
        }
    case 2:
        if (!func_ov000_0219840c(s, data_ov000_021c9ff8, 2, TRUE)) {
            func_ov000_02198360(LFLD(void *, self, 0x40), 1, 0);
        }
        break;
    }
    func_ov000_0218d7e8(self, LFLD(ActorSub40 *, self, 0x40)->unk_13);
}
}
