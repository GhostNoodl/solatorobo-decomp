#include "ov000/VObj.h"
#include "ov000/HeapScope.h"

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08[8];
    s32 unk_28[6];
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    s32 unk_64;
    s32 unk_68[9];
} Obj021bd198;

extern "C" {

void MI_CpuFill8(void *dst, s32 val, u32 size);
void *func_ov000_0218ea20(void *p);

void func_ov000_021bd198(Obj021bd198 *self) {
    s32 i;
    self->unk_00 = 0;
    self->unk_04 = 0;
    for (i = 0; i < 8; i++) {
        self->unk_08[i] = 0;
    }
    for (i = 0; i < 6; i++) {
        self->unk_28[i] = 0;
    }
    self->unk_40 = 10;
    self->unk_44 = -1;
    self->unk_48 = -1;
    self->unk_4c = 0x1000;
    self->unk_50 = 0;
    self->unk_54 = 0;
    self->unk_58 = 0;
    self->unk_5c = 0;
    self->unk_60 = 0;
    self->unk_64 = 0;
    MI_CpuFill8(self->unk_68, 0, sizeof(self->unk_68));
    self->unk_68[0] = 4;
}

void func_ov000_021bd228(Obj021bd198 *self) {
    s32 i;
    self->unk_68[0] = 5;
    if (self->unk_60 != 0) {
        ((void (*)(void *))self->unk_60)(self);
    }
    HEAP_DELETE_FN(self->unk_04, func_ov000_0218ea20);
    for (i = 4; i < 8; i++) {
        void *saved = data_02097dd0->current;
        void *p;
        data_02097dd0->current = data_02097dd0->unk_08;
        p = (void *)self->unk_08[(u32)i];
        if (p != NULL) {
            if (p != NULL) {
                MODEL_DELETE(p);
            }
            self->unk_08[i] = 0;
        }
        data_02097dd0->current = saved;
    }
    func_ov000_021bd198(self);
}

}
