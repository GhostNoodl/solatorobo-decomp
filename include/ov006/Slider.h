#ifndef OV006_SLIDER_H
#define OV006_SLIDER_H

#include "ov006/Caption.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL Model_IsReady(void *a, int b);

#ifdef __cplusplus
}
#endif

// The caption update (ov006_Caption_Update): once the model is loaded, visible becomes 1 and
// ofsY moves toward 0; with visible 2 it moves back toward -0x1e.
static inline void ov006_Slider_Update(ov006_Caption *self) {
    switch (self->visible) {
    case 0:
        if (self->model != NULL && !Model_IsReady(self->model, 0xffff)) {
            return;
        }
        self->visible = 1;
        break;
    case 1:
        if (self->ofsY < 0) {
            self->ofsY += 2;
        }
        break;
    case 2:
        if (self->ofsY > -0x1e) {
            self->ofsY -= 2;
        }
        break;
    }
    self->label->unk_vf8c();
}

#endif
