#include "ov010/ov010.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov010_0220f024[];
extern void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);
extern BOOL func_ov000_02191120(void *p);
extern void *func_ov000_0219bf90(void);
extern void func_02049f44(void *a, s32 b, void *c, s32 d);
extern void func_ov010_0220a040(void *self, u16 a, s32 b, s32 c, s32 d, u16 e, u16 f);
extern void func_ov010_0220d9c0(void *p, void *h);
extern BOOL func_ov010_0220da4c(void *p);
extern void func_ov003_021d8a7c(void *p, s32 a);
extern void func_ov003_021d8afc(void *p);
extern void func_ov003_021d969c(void *p, s32 a);

void func_ov010_0220522c(u8 *self) {
    switch (FLD(u16, FLD(u8 *, self, 0x40), 0)) {
    case 0:
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x10;
        break;
    case 0x10:
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f024[7], 0x266, 0);
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x11;
        func_02049f44(data_02097e4c, FLD(s32, self, 0x134), self + 0x70, 0);
    case 0x11:
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x32) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x20;
        }
        break;
    case 0x20: {
        u8 *pl = (u8 *)func_ov000_0219bf90();
        func_ov010_0220a040(FLD(void *, self, 0x10c), FLD(u8, self, 0x171), FLD(s32, self, 0x15c), FLD(s32, self, 0xfc),
                            FLD(s32, self, 0x100), FLD(u16, self, 0xc), FLD(u16, pl, 0xc));
        func_ov010_0220d9c0(self + 0x174, FLD(void *, self, 0x10c));
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x21;
        break;
    }
    case 0x21:
        if (func_ov010_0220da4c(self + 0x174) && func_ov000_02191120(FLD(void *, self, 0x38))) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x30;
        }
        if (func_ov000_02191120(FLD(void *, self, 0x38))) {
            func_ov003_021d8a7c(FLD(void *, self, 0x118), 1);
        }
        break;
    case 0x30:
        func_ov010_0220d9c0(self + 0x174, FLD(void *, self, 0x110));
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x31;
        break;
    case 0x31:
        if (func_ov010_0220da4c(self + 0x174)) {
            func_ov003_021d8afc(FLD(void *, self, 0x118));
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x40;
        }
        break;
    case 0x40:
        func_ov003_021d969c(self + 0x160, 1);
        break;
    }
    if (func_ov000_02191120(FLD(void *, self, 0x38))) {
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f024[0xb], 0x800, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
    }
}

}
