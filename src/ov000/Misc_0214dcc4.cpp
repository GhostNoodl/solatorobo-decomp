#include "types.h"

typedef struct {
    u8 unk_00[0x10];
    void *unk_10;
    u8 unk_14[0xa0];
    void *unk_b4;
} Obj0214dcc4;

extern "C" {

void func_ov000_02157c28(Obj0214dcc4 *self);
BOOL func_ov000_02152e5c(Obj0214dcc4 *self);
void func_02041d9c(void *obj, s32 a, s32 b);
void func_02041c34(void *obj, s32 a, void (*cb)(void), void *arg);
void func_ov000_0214db04(void);

void func_ov000_0214dcc4(Obj0214dcc4 *self) {
    func_ov000_02157c28(self);
    if (func_ov000_02152e5c(self)) {
        func_02041d9c(self->unk_10, 0, 0xc);
        func_02041d9c(self->unk_10, 0, 0xd);
    }
    if (self->unk_b4 != NULL) {
        func_02041d9c(self->unk_b4, 0, 0x1e);
        func_02041c34(self->unk_b4, 0x1e, func_ov000_0214db04, self);
    }
}

}
