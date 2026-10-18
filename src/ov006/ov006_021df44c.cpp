#include "ov006/ov006.h"

typedef struct ov006_Loader021df44c {
    void *vtbl;
    u8 unk4;
    u8 unk5[0x17];
    void *unk1C;
} ov006_Loader021df44c;

typedef struct ov006_Unk021df44c {
    void *vtbl;
    u8 state;
    u8 unk5[3];
    int timer;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
    u8 unk10[0x74];
    int alpha;
    ov006_Loader021df44c *unk88;
} ov006_Unk021df44c;

extern "C" {

BOOL func_02054f10(void *a, int b);

static inline void ov006_Loader021df44c_Update(ov006_Loader021df44c *self) {
    if (!self->unk4 && self->unk1C != NULL && func_02054f10(self->unk1C, 0xffff)) {
        self->unk4 = 1;
    }
}

void func_ov006_021df44c(ov006_Unk021df44c *self) {
    if (self->state == 0) {
        return;
    }
    switch (self->state) {
    case 1:
        self->b1 = 0;
        self->timer = 0x20;
        self->state = 2;
    case 2:
        if (++self->alpha > 0x20) {
            self->alpha = 0x20;
        }
        if (--self->timer < 0) {
            self->timer = 0;
            self->state = 3;
        }
        break;
    case 3:
        if (self->b1) {
            self->b1 = 0;
            self->timer = 0;
            self->state = 4;
        }
        break;
    case 4:
        self->b0 = 0;
        self->timer = 0x20;
        self->state = 5;
    case 5:
        if (--self->alpha < 0) {
            self->alpha = 0;
        }
        if (--self->timer < 0) {
            self->timer = 0;
            self->state = 6;
        }
        break;
    case 6:
        if (self->b0) {
            self->b0 = 0;
            self->state = 1;
        }
        break;
    }
    ov006_Loader021df44c_Update(self->unk88);
}

}
