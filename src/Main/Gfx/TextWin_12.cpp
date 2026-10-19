#include "types.h"
#include "nitro/mi.h"

extern "C" {

// Model transform slot inside the text window scene.
typedef struct TwXform {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ u16 unk_08;
    /* 0x0a */ u16 unk_0a;
    /* 0x0c */ u16 unk_0c;
    /* 0x0e */ u16 pad_0e;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1c */ s32 unk_1c;
    /* 0x20 */ s32 pos[3];
    /* 0x2c */ s32 scale[3];
    /* 0x38 */ u16 rot[3];
    /* 0x3e */ u16 pad_3e;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ u8 unk_48;
    /* 0x49 */ u8 pad_49[3];
} TwXform;

typedef struct TwGroup {
    /* 0x000 */ s32 unk_00;
    /* 0x004 */ s32 unk_04;
    /* 0x008 */ u16 unk_08;
    /* 0x00a */ u16 unk_0a;
    /* 0x00c */ u16 unk_0c;
    /* 0x00e */ u16 unk_0e;
    /* 0x010 */ u16 unk_10;
    /* 0x012 */ u16 unk_12;
    /* 0x014 */ u16 unk_14;
    /* 0x016 */ u16 unk_16;
    /* 0x018 */ s32 unk_18;
    /* 0x01c */ s32 unk_1c;
    /* 0x020 */ s32 unk_20;
    /* 0x024 */ s32 unk_24;
    /* 0x028 */ s32 unk_28;
    /* 0x02c */ s32 unk_2c;
    /* 0x030 */ s32 unk_30;
    /* 0x034 */ s32 unk_34;
    /* 0x038 */ s32 unk_38;
    /* 0x03c */ s32 unk_3c;
    /* 0x040 */ s32 unk_40;
    /* 0x044 */ TwXform xforms[3];
    /* 0x128 */ u8 unk_128;
    /* 0x129 */ u8 pad_129[0x1f];
} TwGroup;

typedef struct TwScene {
    /* 0x000 */ u8 unk_000[0x38];
    /* 0x038 */ s32 unk_038;
    /* 0x03c */ u8 unk_03c[0x7c];
    /* 0x0b8 */ s32 unk_0b8;
    /* 0x0bc */ s32 unk_0bc;
    /* 0x0c0 */ s32 unk_0c0;
    /* 0x0c4 */ u16 unk_0c4;
    /* 0x0c6 */ u16 unk_0c6;
    /* 0x0c8 */ s32 unk_0c8;
    /* 0x0cc */ s32 unk_0cc;
    /* 0x0d0 */ s32 unk_0d0[0x80];
    /* 0x2d0 */ u16 unk_2d0[0x80];
    /* 0x3d0 */ u8 unk_3d0[4];
    /* 0x3d4 */ u8 unk_3d4[0x40];
    /* 0x414 */ s32 unk_414;
    /* 0x418 */ s32 unk_418;
    /* 0x41c */ s32 unk_41c;
    /* 0x420 */ s32 unk_420;
    /* 0x424 */ TwXform xforms[2];
    /* 0x4bc */ TwGroup groups[5];
    /* 0xb24 */ s32 unk_b24[23];
} TwScene;

static inline void TwXform_Init(TwXform *x) {
    x->unk_00 = 0;
    x->unk_04 = 8;
    x->unk_10 = 0;
    x->unk_14 = 0;
    x->unk_18 = 0;
    x->unk_1c = 0;
    x->unk_08 = 0;
    x->unk_0a = 0xffff;
    x->unk_0c = 0xffff;
    x->pos[0] = 0;
    x->pos[1] = 0;
    x->pos[2] = 0;
    x->scale[0] = 0x1000;
    x->scale[1] = 0x1000;
    x->scale[2] = 0x1000;
    x->rot[0] = 0;
    x->rot[1] = 0;
    x->rot[2] = 0;
    x->unk_40 = 0;
    x->unk_44 = 0;
    x->unk_48 = 0x1e;
}

void func_02050f70(TwScene *s) {
    int i;
    int j;
    s->unk_038 = 2;
    s->unk_0b8 = 0;
    s->unk_0bc = 0;
    s->unk_0c0 = 0;
    s->unk_0c4 = 0;
    s->unk_0c6 = 0;
    s->unk_0c8 = 0;
    s->unk_0cc = 0;
    for (i = 0; i < 0x80; i++) {
        s->unk_0d0[i] = 0;
        s->unk_2d0[i] = 0;
    }
    MIi_CpuClear16(0, s->unk_3d0, 4);
    MIi_CpuClear32(0, s->unk_3d4, 0x40);
    s->unk_414 = 0;
    s->unk_418 = 0;
    s->unk_41c = 0;
    s->unk_420 = 0;
    TwXform_Init(&s->xforms[0]);
    TwXform_Init(&s->xforms[1]);
    for (i = 0; i < 5; i++) {
        s->groups[i].unk_00 = s->groups[i].unk_04 = 0;
        s->groups[i].unk_08 = s->groups[i].unk_0a = 0;
        s->groups[i].unk_0c = s->groups[i].unk_0e = 0;
        s->groups[i].unk_10 = s->groups[i].unk_12 = 0xffff;
        s->groups[i].unk_14 = s->groups[i].unk_16 = 0;
        s->groups[i].unk_18 = s->groups[i].unk_1c = s->groups[i].unk_20 = 0;
        s->groups[i].unk_24 = s->groups[i].unk_28 = 0;
        s->groups[i].unk_2c = s->groups[i].unk_30 = 0;
        s->groups[i].unk_34 = s->groups[i].unk_38 = 0;
        s->groups[i].unk_3c = 0;
        s->groups[i].unk_40 = 0;
        for (j = 0; j < 3; j++) {
            TwXform_Init(&s->groups[i].xforms[j]);
        }
        s->groups[i].unk_128 = 0;
    }
    s->unk_b24[0] = 0;
    s->unk_b24[1] = 0;
    s->unk_b24[2] = 0;
    s->unk_b24[3] = 0;
    s->unk_b24[4] = 0;
    s->unk_b24[5] = 0;
    s->unk_b24[6] = 0;
    s->unk_b24[7] = 0;
    s->unk_b24[8] = 0;
    s->unk_b24[9] = 0;
    s->unk_b24[10] = 0;
    s->unk_b24[11] = 0;
    s->unk_b24[12] = 0;
    s->unk_b24[13] = 0;
    s->unk_b24[14] = 0;
    s->unk_b24[15] = 0;
    s->unk_b24[16] = 0;
    s->unk_b24[17] = 1;
    s->unk_b24[18] = 0;
    s->unk_b24[19] = 0;
    s->unk_b24[20] = 0;
    s->unk_b24[21] = 0;
    s->unk_b24[22] = 0;
}

}
