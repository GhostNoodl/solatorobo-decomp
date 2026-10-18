#include "ov000/VObj.h"
#include "ov000/CmdQueue.h"

typedef struct {
    s32 x0;
    s32 x1;
    u16 y0;
    u16 y1;
} LerpAngle0218a5ec;

typedef struct {
    u8 unk_00[0x4];
    CmdQueue *unk_04;
} Data021ccd50;

typedef struct {
    u16 flags;
} Obj02097e48;

typedef struct {
    u8 a, b, c;
} Rgb3;

extern "C" {
s32 FX_Div(s32 a, s32 b);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
extern Data021ccd50 data_ov000_021ccd50;
extern Obj02097e48 *data_02097e48;
void STD_CopyString(void *a, const char *b);
void STD_ConcatenateString(void *a, const char *b);
s32 NNS_G3dGetResDictIdxByName(void *dict, void *name);

static inline u16 LerpAng(u16 a, u16 b, s32 t) {
    return func_01ffc128(a, b, t, 1, 0x8000);
}

s32 func_ov000_021909a8(void **self, const char *a, const char *b) {
    u32 name[4];
    u8 *res;
    u32 i;
    for (i = 0; i < 4; i++) {
        name[i] = 0;
    }
    if (a != NULL) {
        STD_CopyString(name, a);
    } else {
        STD_CopyString(name, (const char *)((u8 *)self[0] + 0x30));
    }
    if (b != NULL) {
        STD_ConcatenateString(name, b);
    }
    res = (u8 *)self[1];
    res = res != NULL ? res + 0x40 : NULL;
    if (res == NULL) {
        return -1;
    }
    return NNS_G3dGetResDictIdxByName(res, name);
}

}
