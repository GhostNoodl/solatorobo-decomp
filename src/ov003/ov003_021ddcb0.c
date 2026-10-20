#include "types.h"

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 1;
} Ov003Unit;

typedef struct {
    u8 unk_00[0x22];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
} Ov003Part44;

typedef struct {
    u8 unk_00[0x18];
    s16 unk_18;
    u8 unk_1a[0x6];
    u16 unk_20;
    u8 unk_22[0x22];
    Ov003Part44 *unk_44;
    u8 unk_48[0x4b];
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
} Ov003Prop;

extern void *data_ov000_021ccd64;
extern void func_ov000_0219433c(void *p);
extern void func_ov000_02194758(void *p);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);

void func_ov003_021ddcb0(Ov003Prop *self) {
    Ov003Unit *u;
    func_ov000_0219433c(self);
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_0 = 0;
    }
}

void func_ov003_021ddce4(Ov003Prop *self) {
    Ov003Part44 *p;
    func_ov000_02194758(self);
    p = self->unk_44;
    if (self->unk_18 == 0) {
        if ((u32)self & 3) {
            p = self->unk_44;
        }
        p->unk_22_0 = FALSE;
        p->unk_22_1 = FALSE;
    } else {
        p->unk_22_0 = 1;
        p->unk_22_1 = 1;
    }
    self->unk_93_1 = (u8)(u16)self->unk_18;
}
