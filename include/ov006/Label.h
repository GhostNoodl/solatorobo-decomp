#ifndef OV006_LABEL_H
#define OV006_LABEL_H

#include "ov006/ov006.h"

typedef struct ov006_Label {
    void *vtbl;
    int state;
    u16 unk8;
    u8 unkA[0x56];
    char unk60[0x20];
    char unk80[0x20];
    u8 unkA0;
    u8 unkA1[3];
    u16 unkA4;
} ov006_Label;

#ifdef __cplusplus
extern "C" {
#endif

void func_0201e5a0(void *dst, const void *src, u32 size);

#ifdef __cplusplus
}
#endif

static inline void ov006_Label_Set(ov006_Label *self, const char *a, const char *b, u16 c) {
    self->unkA0 = 1;
    if (a == NULL) {
        self->unk60[0] = 0;
    } else {
        func_0201e5a0(self->unk60, a, 0x20);
    }
    if (b == NULL) {
        self->unk80[0] = 0;
    } else {
        func_0201e5a0(self->unk80, b, 0x20);
    }
    self->unkA4 = c;
    if (self->state == 0) {
        self->state = 5;
        self->unk8 = 0;
    } else if ((u32)(self->state - 1) <= 1) {
        self->state = 3;
        self->unk8 = 0;
    }
}

#endif
