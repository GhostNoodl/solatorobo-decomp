// Built at a lower optimization level than the rest of the overlay.
#pragma optimization_level 2
#include "ov006/Model.h"

typedef struct ov006_ModelFlags {
    u32 b0 : 2;
    u32 alpha : 5;
    u32 polyId : 6;
    u32 rest : 19;
} ov006_ModelFlags;

typedef struct ov006_Lbl021dc578 {
    u8 unk0[0xa8];
    ov006_Model *unkA8;
    u16 unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    u8 unkC0[0x1c];
    int unkDC;
    int unkE0;
} ov006_Lbl021dc578;

extern "C" {

extern u8 *data_02097d48;
BOOL func_02054f10(void *a, int b);
u8 func_02043d48(void *a);

static inline void ov006_Model_SetPolyId(ov006_Model *m, int id) {
    ((ov006_ModelFlags *)&m->unk6C)->polyId = id;
}

static inline void ov006_Model_SetAlpha(ov006_Model *m, u8 a) {
    ((ov006_ModelFlags *)&m->unk6C)->alpha = a;
}

void func_ov006_021dc578(ov006_Lbl021dc578 *self) {
    int alpha;
    int x;
    int y;
    if (self->unkA8 == NULL) {
        return;
    }
    if (!func_02054f10(self->unkA8, 0xffff)) {
        return;
    }
    alpha = (u8)self->unkDC;
    x = (self->unkBC + (self->unkB0 - 0x80000)) & ~0xfff;
    y = (self->unkB4 - 0x60000) & ~0xfff;
    if (alpha <= 0) {
        return;
    }
    ov006_Model_SetPolyId(self->unkA8, func_02043d48(data_02097d48 + 0x8b0));
    ov006_Model_SetAlpha(self->unkA8, alpha);
    { int i = self->unkE0; ov006_Model *m = self->unkA8; m->unkFC[i].x = x; m->unkFC[i].y = y; }
    self->unkA8->unk150 = self->unkB8;
    ov006_Model_PlayPart(self->unkA8, self->unkAC);
}

}
