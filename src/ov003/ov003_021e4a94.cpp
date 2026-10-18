#include "ov003/GmObj.h"

typedef struct {
    u8 unk_00[0x16];
    u8 unk_16_0 : 1;
} Ov003Spawned;

typedef struct {
    void *vtbl;
    u8 unk_04[0x14];
    s16 unk_18;
    u8 unk_1a[0x76];
    u8 unk_90[3];
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
    u8 unk_94[0x3c];
    s16 res;
    u8 unk_d2[0x136];
    s16 res2;
    u8 unk_20a;
    u8 unk_20b;
    u8 unk_20c[0x84];
    u8 unk_290[0x20];
    u8 unk_2b0[0x90];
    Ov003Model sub;
    u8 unk_404[0x24];
    Ov003Vec3 unk_428[4];
    s32 unk_458[4];
    u8 unk_468[4];
    u8 unk_46c[0x6ac];
    u8 unk_b18;
} Ov003Big;

extern "C" {

extern BOOL func_ov000_02194c08(void *self);
extern BOOL func_ov000_021903b4(Ov003Model *m);

BOOL func_ov003_021e4a94(Ov003Big *self) {
    BOOL r = func_ov000_02194c08(self);
    s32 i;
    for (i = 0; i < 4; i++) {
        u8 a = self->unk_468[i];
        if (a != 0) {
            self->sub.unk_be = a;
            Ov003Model_SetScale(&self->sub, self->unk_458[i]);
            self->sub.pos.x = self->unk_428[i].x;
            self->sub.pos.y = self->unk_428[i].y;
            self->sub.pos.z = self->unk_428[i].z;
            if (func_ov000_021903b4(&self->sub)) {
                r = TRUE;
            }
        }
    }
    return r;
}

}
