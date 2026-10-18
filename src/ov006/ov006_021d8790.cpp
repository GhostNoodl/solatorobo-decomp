#include "ov006/ov006.h"

typedef struct ov006_Fade021d8790 {
    s32 unk0[3];
    s32 unkC;
} ov006_Fade021d8790;

typedef struct ov006_Scene021d8790 {
    u8 unk0[0x3c];
    int unk3C;
    u8 unk40[0x2e];
    u8 unk6E;
} ov006_Scene021d8790;

extern "C" {

extern ov006_Fade021d8790 data_02097d78;
void func_0203cb78(s32 a, int b, int c);
void func_0203cc58(s32 a, int b, int c);
void func_0203cd10(void);
void func_ov006_021e5e00(ov006_Unk021ec888 *p);

static inline BOOL ov006_FadeIdle(void) {
    BOOL r;
    if (data_02097d78.unkC == 0 && data_02097d78.unk0[0] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

static inline BOOL ov006_FadeDone(int ch) {
    BOOL r;
    if (data_02097d78.unkC == 4) {
        r = TRUE;
    } else {
        r = data_02097d78.unk0[ch] == 4;
    }
    return r;
}

u8 func_ov006_021d8790(ov006_Scene021d8790 *self) {
    switch (self->unk6E) {
    case 0:
        if (data_ov006_021ec888->unk8 == 9) {
            if (!ov006_FadeIdle()) {
                func_0203cb78(0x1000, 0, 0);
                func_0203cb78(0x1000, 0, 1);
            }
            self->unk6E = 1;
        }
        break;
    case 1:
        func_ov006_021e5e00(data_ov006_021ec888);
        self->unk6E = 2;
        break;
    case 2:
        if (data_ov006_021ec888->unk8 != 9) {
            func_0203cc58(0x1000, 0, 0);
            func_0203cc58(0x1000, 0, 1);
            self->unk6E = 3;
        }
        break;
    case 3:
        if (ov006_FadeDone(0) && ov006_FadeDone(1)) {
            self->unk3C = 4;
            self->unk6E = 4;
        }
        break;
    }
    if (self->unk6E != 0) {
        func_0203cd10();
    }
    return self->unk6E;
}

}
