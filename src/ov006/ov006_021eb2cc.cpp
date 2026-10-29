#pragma pool_strings on
#pragma dont_reuse_strings off
#include "ov006/ov006.h"

typedef struct ov006_Vec021eb2cc {
    s32 x, y, z;
} ov006_Vec021eb2cc;

typedef struct ov006_Rot021eb2cc {
    u16 x, y, z;
} ov006_Rot021eb2cc;

typedef struct ov006_State021eb2cc {
    u16 phase;
    u16 timer;
} ov006_State021eb2cc;

typedef struct ov006_Obj021eb2cc {
    u8 unk0[0x38];
    void *unk38;
    u8 unk3C[4];
    ov006_State021eb2cc *unk40;
    u8 unk44[0x2c];
    ov006_Vec021eb2cc unk70;
    ov006_Rot021eb2cc unk7C;
    u8 unk82[0x4c];
    u8 unkCE;
} ov006_Obj021eb2cc;

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021911c8(void *a, s16 b);
void func_ov000_021915a0(void *a);
void *func_02065f88(s32 id, ov006_Vec021eb2cc *pos);
void *func_02049f44(void *a, s32 b, ov006_Vec021eb2cc *c, s32 d);
BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, ov006_Vec021eb2cc *pos, ov006_Rot021eb2cc *rot,
                         s32 f, s32 g, s32 h, s32 i);
void func_ov000_0218bed8(void *a, s32 b, void *actor);

void func_ov006_021eb2cc(ov006_Obj021eb2cc *self) {
    BOOL any;
    int i;
    ov006_Rot021eb2cc rot;
    void *p;
    ov006_State021eb2cc *state = self->unk40;
    switch (state->phase) {
    case 0:
        func_ov000_02190cb0(self->unk38, "act00", 0x1000, 0);
        self->unkCE = 0;
        self->unk7C.y += 0x8000;
        self->unk40->phase++;
        break;
    case 1:
        state->timer++;
        if (state->timer <= 30) {
            return;
        }
        func_ov000_02190cb0(self->unk38, "act01", 0x1000, 0);
        func_ov000_021911c8(self->unk38, 0x2800);
        func_ov000_021915a0(self->unk38);
        self->unk40->timer = 0;
        self->unk40->phase++;
        break;
    case 2:
        state->timer++;
        if (state->timer > 0xa8c || self->unkCE >= 3) {
            p = func_02065f88(5, &self->unk70);
            if (p != NULL) {
                VCALL(p, 0C, 0x5000);
            }
            func_02049f44(data_02097e4c, 0x56, &self->unk70, 0);
            func_ov000_0219aae8(self, self, 1, 0x11, 0x80, NULL, NULL, 0x7800, 0, -1, 0x1000);
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            VCALL(self, 08);
            return;
        }
        any = FALSE;
        rot = self->unk7C;
        for (i = 0; i < 3; i++) {
            rot.z += 0x2aab;
            if (func_ov000_0219aae8(self, self, 1, 0x10, 0x80, NULL, &rot, 0x4400, 0x3c000, -1, 0x1000)) {
                any = TRUE;
            }
            rot.z += 0x2aab;
        }
        if (any) {
            self->unkCE++;
        }
        break;
    }
}

}
