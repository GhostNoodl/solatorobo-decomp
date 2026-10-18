#include "ov014/ov014.h"

extern "C" {

extern const u8 data_ov014_0221668c[][6];
extern Ov014Actor *func_ov000_0219bf90(void);
extern void func_ov003_021ceff4(void *p);
extern void func_ov000_0219bd20(s32 a, u16 b, s32 c, s32 d, s32 e, void *f);
extern void func_ov003_021daa6c(void *p, s32 a);

static inline u8 *Ov014_AnimCur(u8 *t) {
    return FLD(u8 *, t, 0xc) + FLD(u16, t, 8) * 8;
}

void func_ov014_02200444(Ov014Actor *self) {
    u8 b;
    s16 v;
    Ov014Actor *a;
    if (!Ov014_GameIdle()) {
        return;
    }
    self->unk_90 = 0xffff;
    a = func_ov000_0219bf90();
    if (a != NULL) {
        self->unk_90 = a->id;
    }
    if (self->unk_40->unk_13 == 1) {
        u32 f = FLD(u32, self, 0xf4);
        if (f == 0) {
            s16 m;
            if ((self->unk_30 & 0x4000) && (m = FLD(s16, self, 0xfc)) != 0xff && data_ov014_0221668c[FLD(s16, self, 0xf0)][m] != 0) {
                s32 sel = 0xff;
                switch (m) {
                case 0:
                    sel = 0;
                    break;
                case 1:
                case 2:
                    sel = 1;
                    break;
                case 3:
                case 4:
                case 5:
                    sel = 2;
                    break;
                }
                if (sel != 0xff) {
                    FLD(u8 *, self, 0x104) = Ov014_AnimCur(FLD(u8 *, self, 0x114));
                    while (sel != *FLD(s16 *, self, 0x104)) {
                        func_ov003_021ceff4((u8 *)self + 0x108);
                        FLD(u8 *, self, 0x104) = Ov014_AnimCur(FLD(u8 *, self, 0x114));
                    }
                    FLD(u8, self, 0xfe) = 0;
                    v = FLD(s16, self, 0xf0);
                    func_ov000_0219bd20(0x5c0e, self->kind, 0xe, 1, 2, &v);
                    switch (*FLD(s16 *, self, 0x104)) {
                    case 0:
                        FLD(s32, self, 0xf4) |= 4;
                        self->unk_40->flags |= 0x8000;
                        break;
                    case 1:
                        FLD(s32, self, 0xf4) |= 8;
                        self->unk_40->flags |= 0x10000;
                        break;
                    case 2:
                        FLD(s32, self, 0xf4) |= 0x10;
                        self->unk_40->flags |= 0x20000;
                        break;
                    }
                    FLD(s16, self, 0xfc) = 0xff;
                }
            }
        } else if (f & 1) {
            self->unk_b6++;
            if (self->unk_b6 >= 10) {
                func_ov003_021daa6c(FLD(void *, self, 0x100), 0xff);
                FLD(u32, self, 0xf4) ^= 1;
                b = FLD(s16, self, 0xf0) + 3;
                func_ov000_0219bd20(0x5c0e, self->kind, 6, 1, 1, &b);
                self->unk_b6 = 0;
            }
        }
    }
    func_ov003_021dacfc(FLD(void *, self, 0x100));
}
}
