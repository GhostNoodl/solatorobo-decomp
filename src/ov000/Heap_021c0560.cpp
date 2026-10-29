#include "ov000/HeapScope.h"

typedef struct {
    u8 pad_00[0x6c];
    u32 unk_6c;
} Model021c0560;

typedef struct Obj021c0560 {
    u32 unk_00_0 : 1;
    u32 unk_00_1 : 1;
    u32 unk_00_2 : 1;
    u32 unk_00_3 : 1;
    u32 unk_00_4 : 28;
    u8 pad_04[0x14];
    Model021c0560 *unk_18;
    Model021c0560 *unk_1c;
    u8 pad_20[0x24];
    s32 unk_44;
    u8 pad_48[0x18];
    void (*unk_60)(struct Obj021c0560 *self);
    s32 unk_64;
    s32 unk_68;
    u8 pad_6c[0x14];
    s32 unk_80;
    s32 unk_84;
    s32 unk_88;
    Model021c0560 *unk_8c;
    Model021c0560 *unk_90;
    s32 unk_94;
} Obj021c0560;

extern "C" {

BOOL func_ov000_021bd374(Obj021c0560 *self, s32 len);
void *func_ov000_021c04e4(void);
void func_02041c34(void *model, s32 a, void *cb, void *arg);
void MI_CpuFill8(void *dst, s32 val, u32 size);

static inline BOOL Obj021c0560_Wait(Obj021c0560 *self) {
    if (!(self->unk_00_1 == 1 ? TRUE : FALSE) || (self->unk_00_3 == 1 ? TRUE : FALSE)) {
        return TRUE;
    }
    self->unk_68 = 10;
    return FALSE;
}

void func_ov000_021c0560(Obj021c0560 *self) {
    switch (self->unk_68) {
    case 5:
        HEAP_DELETE_MODEL(self->unk_8c);
        HEAP_DELETE_MODEL(self->unk_90);
        return;
    case 1:
        {
            Model021c0560 *model = self->unk_18;
            self->unk_90 = self->unk_1c;
            self->unk_18 = NULL;
            self->unk_8c = model;
            self->unk_1c = NULL;
            self->unk_94 = 5;
            model->unk_6c |= 0x200000;
            self->unk_8c->unk_6c |= 0x80000;
            self->unk_90->unk_6c |= 0x200000;
            self->unk_90->unk_6c |= 0x80000;
            func_02041c34(self->unk_90, 2, (void *)func_ov000_021c04e4, &self->unk_68);
        }
        self->unk_68 = 4;
    case 4:
        self->unk_84 = 0;
        self->unk_88 = 0;
        if (Obj021c0560_Wait(self)) {
            self->unk_68 = 5;
            if (self->unk_60 != NULL) {
                self->unk_60(self);
            }
            MI_CpuFill8(&self->unk_68, 0, 0x24);
            self->unk_68 = 4;
            self->unk_44 = -1;
            self->unk_60 = NULL;
            self->unk_64 = 0;
            return;
        }
    case 10:
        if (!func_ov000_021bd374(self, 0x6000)) {
            self->unk_80 = -0x1ccd;
        }
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
