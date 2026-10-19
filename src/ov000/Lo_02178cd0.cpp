#include "ov000/LoCommon.h"

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208bf54[];
extern u8 data_ov000_021cba18[];
extern u8 data_ov000_021cba20[];
extern u8 data_ov000_021cba28[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbe60[];
extern u8 *data_0214a424;
extern void *data_02149ef8;
extern void *data_02097e4c;
extern u16 *data_02097dc8;
extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_0205a6a0(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0205a840(void *p, void *buf, const void *s);
void *func_0204c0e8(void *p, s32 a);
void func_ov000_0215bb14(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215d980(void *a, s32 b, s32 c);
s32 func_0206d1d4(void *a, u16 b);
void func_02043d20(void *a, s32 b);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 count);
void func_0206f3f0(u16 id, s32 v);
void func_0206d02c(void *a);

void func_ov000_02178cd0(void *self) {
    s32 scale[3];
    if (LFLD(s32, self, 0x24) == 0) {
        return;
    }
    func_02043d20(data_02097d48 + 0x8b0, 0);
    scale[0] = 0x1000;
    scale[1] = 0x1000;
    scale[2] = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    LFLD(s32, self, 0x28) = FX_SinCosTable_[((LFLD(s32, self, 0x24) << 14) >> 16) * 2];
    LFLD(VObj *, self, 0x3c)->vfunc_20();
    LFLD(VObj *, self, 0x40)->vfunc_20();
    LFLD(VObj *, self, 0x44)->vfunc_20();
    if (LFLD(VObj *, self, 0x48) != NULL) {
        LFLD(VObj *, self, 0x48)->vfunc_20();
    }
    if (LFLD(VObj *, self, 0x4c) != NULL) {
        LFLD(VObj *, self, 0x4c)->vfunc_20();
    }
    LFLD(VObj *, self, 0x50)->vfunc_20();
    LFLD(VObj *, self, 0x54)->vfunc_20();
}

static inline u16 ItemKind(u16 v) { return v >> 12; }
static inline u16 ItemIdx(u16 v) { return v & 0xfff; }

void func_ov000_02178dcc(void *p, BOOL on) {
    u8 *self = (u8 *)p;
    u32 n;
    if (on && (n = LFLD(u32, LFLD(u8 *, self, 0x54), 0x8c) * LFLD(u16, LFLD(u8 *, self, 0x54), 0x88)) != 0) {
        s32 rest;
        u8 *node;
        u8 *list;
        {
            u8 *g = data_0214a424;
            if ((LFLD(u32, g, 0x20) += n) > 99999) {
                LFLD(u32, g, 0x20) = 99999;
            }
        }
        node = NULL;
        func_ov000_0215d980(LFLD(void *, self, 0x44), LFLD(u32, data_0214a424, 0x20), 0);
        func_02049a48(data_02097e4c, 0x30, -1, -1, -1);
        list = LFLD(u8 *, LFLD(u8 *, self, 0x3c), 0x98);
        if (list != NULL) {
            s32 i = LFLD(s8, LFLD(u8 *, self, 0x3c), 0xb1);
            while (i-- != 0) {
                list = LFLD(u8 *, list, 0x2c);
            }
            node = list;
        }
        rest = LFLD(u16, LFLD(u8 *, self, 0x54), 0x8a) - LFLD(u16, LFLD(u8 *, self, 0x54), 0x88);
        if (ItemKind(LFLD(u16, node, 6)) - 1 == 1) {
            s32 c = rest;
            if (c < 0) {
                c = 0;
            }
            func_0206f3f0(LFLD(u16, node, 6), c);
            func_0206d02c(data_0214a424);
        }
        if (LFLD(void *, self, 0x48) != NULL) {
            func_ov000_0215d980(LFLD(void *, self, 0x48), *(data_0214a424 + ItemIdx(LFLD(u16, node, 6)) + 0x2a), 1);
        }
        if (LFLD(void *, self, 0x4c) != NULL) {
            func_ov000_0215d980(LFLD(void *, self, 0x4c), func_0206d1d4(data_0214a424, LFLD(u16, node, 6)), 1);
        }
        if (rest <= 0) {
            LFLD(VObj *, self, 0x3c)->vfunc_70(node);
        }
    }
    LFLD(u32, LFLD(u8 *, self, 0x54), 0xc) |= 4;
    LFLD(u32, LFLD(u8 *, self, 0x54), 0xc) |= 2;
    LFLD(u32, LFLD(u8 *, self, 0x3c), 0xc) &= ~4;
}

}
