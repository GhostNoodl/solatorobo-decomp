#include "types.h"

typedef struct {
    u8 unk_00[0x4];
    s32 state;
    u8 unk_08[0x4];
    u32 flag_0 : 1;
    u32 flag_1 : 1;
    u32 flag_2 : 30;
    void *unk_10;
    u8 unk_14[0x1c];
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    u8 unk_3c[0x48];
    void *unk_84;
    void *unk_88;
} Scene0214ca8c;

extern "C" {

BOOL Model_IsReady(void *obj, u32 mask);
void func_ov000_0214ccf8(Scene0214ca8c *self);

BOOL Menu021ca94c_IsLoaded(Scene0214ca8c *self) {
    BOOL done = TRUE;

    if (self->unk_10 != NULL && !Model_IsReady(self->unk_10, 0xffff)) {
        done = FALSE;
    }
    if (self->unk_84 != NULL && !Model_IsReady(self->unk_84, 0xffff)) {
        done = FALSE;
    }
    if (self->unk_88 != NULL && !Model_IsReady(self->unk_88, 0xffff)) {
        done = FALSE;
    }
    return done;
}

void func_ov000_0214caf8(Scene0214ca8c *self) {
    if (self->state != 2) {
        return;
    }
    self->unk_30 = self->unk_34;
    self->unk_38 = 0x1000;
    func_ov000_0214ccf8(self);
    if (self->flag_1) {
        self->flag_0 = 1;
        self->state = 1;
    }
}

}
