#include "ov000/HeapScope.h"
#include "ov000/Vec.h"

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    u8 pad_00[0x6c];
    u32 unk_6c;
} Model021bfa10;

typedef struct {
    u32 unk_00_0 : 1;
    u32 unk_00_1 : 1;
    u32 unk_00_2 : 1;
    u32 unk_00_3 : 1;
    u32 unk_00_4 : 28;
    u8 pad_04[0x14];
    Model021bfa10 *unk_18;
    Model021bfa10 *unk_1c;
    Model021bfa10 *unk_20;
    u8 pad_24[4];
    s32 unk_28;
    u8 pad_2c[0x24];
    VecFx32 unk_50;
    u8 pad_5c[0xc];
    s32 unk_68;
    u8 pad_6c[0x14];
    s32 unk_80;
    s32 unk_84;
    s32 unk_88;
    Model021bfa10 *unk_8c;
    Model021bfa10 *unk_90;
    Model021bfa10 *unk_94;
    s32 unk_98;
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
} Obj021bfa10;

extern "C" {

BOOL func_ov000_021bd374(Obj021bfa10 *self, s32 len);
void func_ov000_021bd474(Obj021bfa10 *self, VecFx32 *pos);
void func_ov000_021bec38(void);
void func_02041c34(void *model, s32 a, void *cb, void *arg);

static inline BOOL Obj021bfa10_Wait(Obj021bfa10 *self) {
    if (!(self->unk_00_1 == 1 ? TRUE : FALSE) || (self->unk_00_3 == 1 ? TRUE : FALSE)) {
        return TRUE;
    }
    self->unk_68 = 10;
    return FALSE;
}

void func_ov000_021bfa10(Obj021bfa10 *self) {
    VecFx32 pos;
    switch (self->unk_68) {
    case 5:
        HEAP_DELETE_MODEL(self->unk_8c);
        HEAP_DELETE_MODEL(self->unk_90);
        HEAP_DELETE_MODEL(self->unk_94);
        return;
    case 1:
        {
            Model021bfa10 *model = self->unk_18;
            self->unk_90 = self->unk_1c;
            self->unk_94 = self->unk_20;
            self->unk_18 = NULL;
            self->unk_8c = model;
            self->unk_1c = NULL;
            self->unk_20 = NULL;
            self->unk_98 = 0;
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = self->unk_28;
            model->unk_6c |= 0x200000;
            self->unk_8c->unk_6c |= 0x80000;
            self->unk_90->unk_6c |= 0x200000;
            self->unk_90->unk_6c |= 0x80000;
            func_02041c34(self->unk_90, 2, (void *)func_ov000_021bec38, &self->unk_68);
            self->unk_94->unk_6c |= 0x200000;
            self->unk_94->unk_6c |= 0x80000;
        }
        self->unk_68 = 4;
    case 4:
        self->unk_84 = 0;
        self->unk_88 = 0;
        if (Obj021bfa10_Wait(self)) {
            return;
        }
    case 10:
        if (func_ov000_021bd374(self, 0x6000)) {
            return;
        }
        if (++self->unk_98 < 0x12) {
            self->unk_a0 += FX_MUL(0x3000 - self->unk_a0, 0x19a);
        } else if (self->unk_98 >= 0x30) {
            self->unk_98 = 0;
            self->unk_a0 = 0;
        } else {
            self->unk_a0 += FX_MUL(-self->unk_a0, 0xcd);
        }
        pos = self->unk_50;
        func_ov000_021bd474(self, &pos);
        self->unk_80 = -0x1ccd;
        break;
    case 0:
    case 2:
    case 3:
    case 6:
    case 7:
    case 8:
    case 9:
        break;
    }
}

}
