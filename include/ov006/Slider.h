#ifndef OV006_SLIDER_H
#define OV006_SLIDER_H

#include "ov006/ov006.h"

typedef struct ov006_Slider {
    void *vtbl;
    u8 unk4;
    u8 unk5[0x17];
    int unk1C;
    u8 unk20[4];
    void *unk24;
    void *unk28;
} ov006_Slider;

#ifdef __cplusplus
extern "C" {
#endif

BOOL func_02054f10(void *a, int b);

#ifdef __cplusplus
}
#endif

static inline void ov006_Slider_Update(ov006_Slider *self) {
    switch (self->unk4) {
    case 0:
        if (self->unk24 != NULL && !func_02054f10(self->unk24, 0xffff)) {
            return;
        }
        self->unk4 = 1;
        break;
    case 1:
        if (self->unk1C < 0) {
            self->unk1C += 2;
        }
        break;
    case 2:
        if (self->unk1C > -0x1e) {
            self->unk1C -= 2;
        }
        break;
    }
    VCALL(self->unk28, 8C);
}

#endif
