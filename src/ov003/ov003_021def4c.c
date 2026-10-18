#include "types.h"

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 1;
} Ov003Unit;

typedef struct {
    u8 unk_00[0x20];
    u16 unk_20;
} Ov003Prop;

extern void *data_ov000_021ccd64;
extern void func_ov000_02194758(void *p);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_ov000_0218b700(Ov003Unit *u, s32 a, s32 b);

void func_ov003_021def4c(Ov003Prop *self) {
    Ov003Unit *u;
    func_ov000_02194758(self);
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (u == NULL) {
        return;
    }
    u->unk_a2_0 = 0;
    func_ov000_0218b700(u, 0x5000, 0);
}
