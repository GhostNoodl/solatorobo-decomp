#include "ov000/VObj.h"
#include "Main/Gfx/TextWin.h"
#include "ov000/UiObj.h"

typedef struct {
    u8 unk_00[0xf4];
    UiLabel *unk_f4;
    UiLabel *unk_f8;
    UiLabel *unk_fc;
} Obj021c55e8;

extern "C" {

void *Heap_Alloc(u32 size);

static inline UiLabel *New0215f514(void) {
    UiLabel *p = (UiLabel *)Heap_Alloc(sizeof(UiLabel));
    if (p != NULL) {
        UiLabel_Reset_0215f514(p);
    }
    return p;
}

void Obj021c55e8_SetLabel1(Obj021c55e8 *self, s32 a) {
    self->unk_f4 = New0215f514();
    UiLabel_SetText(self->unk_f4, a);
    self->unk_f4->width = self->unk_f4->text->width + 0x10;
}

void Obj021c55e8_SetLabel2(Obj021c55e8 *self, s32 a) {
    self->unk_f8 = New0215f514();
    UiLabel_SetText(self->unk_f8, a);
    self->unk_f8->width = self->unk_f8->text->width + 0x10;
}

void Obj021c55e8_SetLabel3(Obj021c55e8 *self, s32 a) {
    self->unk_fc = New0215f514();
    UiLabel_SetText(self->unk_fc, a);
    self->unk_fc->width = self->unk_fc->text->width + 0x10;
}

}
