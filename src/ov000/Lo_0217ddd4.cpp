#include "ov000/LoCommon.h"

extern "C" {

extern u8 data_0208b318[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbf60[];
extern void *data_0208cc9c;
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_02097e4c;
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
s32 func_ov000_02154b58(void *p, s32 a);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215bb14(void *a, void *b);
void func_0206f21c(u16 a, s32 b);
void func_020359d0(void *a, s32 b, s32 c);
s32 func_02035b90(void *a, s32 b);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

void func_ov000_0217ddd4(void *self) {
    switch (LFLD(s32, self, 0x48)) {
    case 0: {
        u32 fl;
        s32 k;
        LFLD(VObj *, self, 0x5c)->vfunc_74();
        if (LFLD(VObj *, self, 0x60) != NULL) {
            LFLD(VObj *, self, 0x60)->vfunc_74();
        }
        fl = LFLD(u32, self, 4);
        if (fl & 0x10000000) {
            k = func_ov000_0217bd88(self, 0x8000, 0x84);
        } else if (fl & 0x100000) {
            k = func_ov000_0217bd88(self, 0x8000, 0x75);
        } else {
            k = func_ov000_0217bd88(self, 0x8000, 0x76);
        }
        if (!k) {
            return;
        }
        LFLD(s32, self, 0x48) = 1;
    }
    case 1:
        LFLD(u8, data_02097dd0, 0x31) = 0;
        break;
    }
}

extern s16 FX_SinCosTable_[];
s32 FX_Div(s32 a, s32 b);
typedef struct { s32 x, y, z; } V0217de7c;
void func_ov000_0217df5c(void *self, V0217de7c *v);
void func_ov000_0217e560(void *self, V0217de7c *v);

void func_ov000_0217de7c(void *self) {
    s32 st;
    if (LFLD(void *, self, 0x24) == NULL) {
        return;
    }
    st = LFLD(s32, self, 0x44);
    if ((st == 4 || st == 5 || st == 7) && LFLD(s32, self, 0xa4) != 0) {
        s32 t = FX_Div(LFLD(s32, self, 0xa4), 0x18000);
        s32 c = 0x1000 - FX_SinCosTable_[((t * 0x4000) >> 16) * 2];
        V0217de7c v;
        v.x = LO_FX_MUL(c, 0x140000);
        v.y = 0;
        v.x &= ~0xfff;
        v.y &= ~0xfff;
        func_ov000_0217df5c(self, &v);
        func_ov000_0217e560(self, &v);
    }
    if (LFLD(VObj *, self, 0x64) != NULL) {
        LFLD(VObj *, self, 0x64)->vfunc_20();
    }
}

}
