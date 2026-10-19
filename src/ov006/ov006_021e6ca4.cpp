#include "ov006/Tasks.h"
#include "Main/Math/MathItcm.h"

typedef struct ov006_Cam6ca4 {
    u8 unk0[0xf8];
    VecFx32 pos;
} ov006_Cam6ca4;

typedef struct ov006_Model6ca4 {
    u8 unk0[0x78];
    VecFx32 pos;
} ov006_Model6ca4;

typedef struct ov006_Prop6ca4 {
    u8 unk0[0x38];
    ov006_Model6ca4 *unk38;
    u8 unk3C[0x34];
    VecFx32 pos;
    u8 unk7C[0x34];
    u8 unkB0[0x78];
    VecFx32 unk128;
    u8 unk134[0x64];
    void *unk198;
    u16 unk19C_0 : 2;
    u16 unk19C_2 : 11;
    u16 unk19C_13 : 1;
    u16 unk19C_14 : 2;
} ov006_Prop6ca4;

extern "C" {

extern ov006_Cam6ca4 *data_ov000_021ccd54;
extern VecFx32 data_ov006_021eb8ec;
extern VecFx32 data_ov006_021eb8d4;
extern VecFx32 data_ov006_021eb8e0;
extern VecFx32 data_ov006_021eb8bc;
extern fx32 data_ov006_021ec484[2];

BOOL func_01ffc23c(VecFx32 *p, VecFx32 *min, VecFx32 *max);
void func_ov000_02190758(void *a, void *b, int c);
BOOL func_ov000_021903b4(void *a);
void func_ov006_021dca94(void *p);

BOOL func_ov006_021e6ca4(ov006_Prop6ca4 *self) {
    VecFx32 d;
    BOOL ret;
    BOOL done;
    const ov006_Cam6ca4 *cam;
    self->unk19C_0 = 0;
    ret = FALSE;
    cam = data_ov000_021ccd54;
    {
        fx32 cx = cam->pos.x;
        fx32 cy = cam->pos.y;
        fx32 cz = cam->pos.z;
        d.x = self->pos.x - cx;
        d.y = self->pos.y - cy;
        d.z = self->pos.z - cz;
    }
    done = FALSE;
    if (func_01ffc23c(&d, &data_ov006_021eb8ec, &data_ov006_021eb8d4) && HitMagSq(&d) <= data_ov006_021ec484[0]) {
        self->unk38->pos = self->pos;
        func_ov000_02190758(self->unk38, self->unk7C, 1);
        ret = func_ov000_021903b4(self->unk38);
        if (ret) {
            self->unk19C_0 |= 1;
        }
        done = TRUE;
    }
    if (!done && func_01ffc23c(&d, &data_ov006_021eb8e0, &data_ov006_021eb8bc) && HitMagSq(&d) <= data_ov006_021ec484[1]) {
        self->unk128 = self->pos;
        func_ov000_02190758(self->unkB0, self->unk7C, 1);
        ret = func_ov000_021903b4(self->unkB0);
        if (ret) {
            self->unk19C_0 |= 2;
        }
    }
    if (ret && self->unk19C_13) {
        func_ov006_021dca94(self->unk198);
    }
    return ret;
}

}
