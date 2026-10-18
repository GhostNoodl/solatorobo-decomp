#include "ov006/ov006.h"

typedef struct ov006_Vec021eacd8 {
    s32 x;
    s32 y;
    s32 z;
} ov006_Vec021eacd8;

typedef struct ov006_Game021eacd8 {
    u8 unk0[0xf8];
    ov006_Vec021eacd8 unkF8;
} ov006_Game021eacd8;

typedef struct ov006_Model021eacd8 {
    u8 unk0[0x78];
    ov006_Vec021eacd8 pos;
} ov006_Model021eacd8;

typedef struct ov006_Obj021eacd8 {
    u8 unk0[0x38];
    ov006_Model021eacd8 *unk38;
    u8 unk3C[0x34];
    ov006_Vec021eacd8 unk70;
    u8 unk7C[4];
} ov006_Obj021eacd8;

extern "C" {

extern ov006_Game021eacd8 *data_ov000_021ccd54;
BOOL func_01ffc198(ov006_Vec021eacd8 *a, ov006_Vec021eacd8 *b, s32 r);
void func_ov000_02190758(ov006_Model021eacd8 *a, void *b, int c);
int func_ov000_021903b4(ov006_Model021eacd8 *a);

int func_ov006_021eb534(ov006_Obj021eacd8 *self) {
    ov006_Model021eacd8 *m = self->unk38;
    ov006_Vec021eacd8 target;
    int r;
    target.x = data_ov000_021ccd54->unkF8.x;
    target.y = data_ov000_021ccd54->unkF8.y;
    target.z = data_ov000_021ccd54->unkF8.z;
    r = 0;
    if (func_01ffc198(&self->unk70, &target, 0x190000)) {
        m->pos = self->unk70;
        func_ov000_02190758(m, self->unk7C, 1);
        r = func_ov000_021903b4(m);
    }
    return r;
}

}
