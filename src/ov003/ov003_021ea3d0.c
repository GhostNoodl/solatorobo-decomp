#include "types.h"

typedef struct {
    u8 unk_00[0x18];
    s16 kind;
    u8 unk_1a[0x26];
    void *work;
} Ov003Spin2;

extern BOOL func_ov000_02194c08(void *self);
extern void func_ov000_02198360(void *p, s32 a, s32 b);

BOOL func_ov003_021ea3d0(Ov003Spin2 *self) {
    BOOL r = func_ov000_02194c08(self);
    if (self->kind == 1 && r == FALSE) {
        func_ov000_02198360(self->work, 0x15, 0);
    }
    return r;
}
