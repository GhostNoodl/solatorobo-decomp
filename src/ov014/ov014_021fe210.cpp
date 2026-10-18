#include "ov014/ov014.h"

struct Ov014SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov014Spawn_Init(Ov014SpawnDesc *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

static inline void Ov014Spawn_Set(Ov014SpawnDesc *d, u16 k) {
    d->kind = k;
    d->flags = k & 0xf000;
}

extern "C" {

struct Ov014V12 { s32 a[3]; };
extern Ov014Vec data_ov014_02216818[];
extern void func_ov003_021ceff4(void *p);
extern BOOL func_ov003_021d9edc(s32 a);
extern void func_ov003_021d87d0(void *p, s32 a);
extern void func_ov003_021d85c8(void *p, s32 a, s32 b, s32 c, s32 d);
extern Ov014Actor *func_ov000_02192b24(Ov014SpawnDesc *desc);

static inline u8 *Ov014_AnimCur(u8 *t) {
    return FLD(u8 *, t, 0xc) + FLD(u16, t, 8) * 8;
}

void func_ov014_021fe210(Ov014Actor *self) {
    u8 m = FLD(u8, self, 0x138);
    if (m == 0) {
        u8 *t = FLD(u8 *, self, 0x14c);
        FLD(u8 *, self, 0x13c) = FLD(u8 *, t, 0xc) + FLD(u16, t, 8) * 8;
        func_ov003_021ceff4((u8 *)self + 0x140);
        switch (*FLD(s16 *, self, 0x13c)) {
        case 0:
        case 1:
        case 2:
            FLD(s32, self, 0xf4) |= 4;
            self->unk_40->flags |= 0x8000;
            break;
        case 3:
        case 4:
            FLD(s32, self, 0xf4) |= 0x200000;
            FLD(s32, self, 0xf4) |= 4;
            self->unk_40->flags |= 0x8000;
            break;
        case 5:
            FLD(s32, self, 0xf4) |= 0x10;
            self->unk_40->flags |= 0x20000;
            break;
        }
    } else {
        s32 pct = (u16)(self->unk_50[0] * 100 / self->unk_50[1]);
        if (pct >= 30) {
            if (!(m & 0x80)) {
                if (!func_ov003_021d9edc(0x482b)) {
                    FLD(u8, self, 0x138) |= 0x80;
                } else if (self->unk_30 & 0x40) {
                    if (FLD(u8, self, 0xf8) == 10) {
                        FLD(u8, self, 0x138) |= 0x80;
                    }
                    FLD(u8, self, 0xf8) = 0xff;
                }
            }
            if (FLD(u8, self, 0x138) & 0x80) {
                u8 *t;
                func_ov003_021ceff4((u8 *)self + 0x160);
                t = FLD(u8 *, self, 0x16c);
                FLD(u8 *, self, 0x15c) = Ov014_AnimCur(t);
                switch (*(s16 *)FLD(u8 *, self, 0x15c)) {
                case 10:
                    FLD(u8, self, 0x138) ^= 0x80;
                    break;
                case 11:
                case 12:
                    FLD(s32, self, 0xf4) |= 8;
                    self->unk_40->flags |= 0x10000;
                    break;
                }
            }
        }
    }
    if ((self->unk_30 & 0x200) && self->unk_50[0] != 0) {
        func_ov003_021d87d0((u8 *)self + 0x100, 0);
        func_ov003_021d85c8((u8 *)self + 0x100, 0x1e, 0, 0, 0);
    }
}

}
