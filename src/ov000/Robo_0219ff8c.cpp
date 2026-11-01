#include "ov000/Actor.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
} Bits32_0219ff8c;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 2;
    u16 rest : 10;
} Bits16_0219ff8c;

typedef struct {
    u8 st : 2;
    u8 b2 : 1;
    u8 rest : 5;
} Bits8_0219ff8c;

typedef struct {
    u8 b0 : 4;
    u8 b4 : 1;
    u8 rest : 3;
} Bits93_0219ff8c;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 rest : 11;
} Bits22_0219ff8c;

extern "C" {

void func_ov000_021bd300(void *p);
void func_ov000_021b1a54(u8 *self, BOOL flag);
void func_0203f364(void *p);
Actor *func_ov000_0218e640(ActorMgr *mgr, u16 id);

struct Obj0219ff8c {
    u8 unk_00[0x15];
    u8 unk_15;
    u8 unk_16[0x2a];
    u8 *unk_40;
    u8 unk_44[0x4];
    u8 *unk_48;
    u8 unk_4c[0x4];
    u16 *unk_50;
    u8 unk_54[0x8];
    u8 *unk_5c;
    u8 unk_60[0x10];
    s32 unk_70;
    u8 unk_74[0x4];
    s32 unk_78;
    u8 unk_7c[0x17];
    Bits93_0219ff8c unk_93;
    u8 unk_94[0x91c];
    u8 *unk_9b0;
    u8 unk_9b4[0x15c];
    s32 unk_b10;
    u8 unk_b14[0x4];
    s32 unk_b18;
    u8 unk_b1c[0x2];
    u16 unk_b1e;
    u8 unk_b20[0x2];
    Bits22_0219ff8c unk_b22;
    Bits32_0219ff8c unk_b24;
    Bits8_0219ff8c unk_b28;
    u8 unk_b29[0x3];
    Bits16_0219ff8c unk_b2c;
    u8 unk_b2e[0x8];
    u16 unk_b36;
    u16 unk_b38;
    u8 unk_b3a[0x2e];
    u16 unk_b68;
    u16 unk_b6a;
    u16 unk_b6c;
    u16 unk_b6e;
};

static inline s32 Dist0219ff8c(Obj0219ff8c *self) {
    s32 dx = self->unk_70 - self->unk_b10;
    s32 dz = self->unk_78 - self->unk_b18;
    {
        s64 sq = (s64)dx * dx;
        sq += (s64)dz * dz;
        REG_SQRTCNT = 1;
        REG_SQRT_PARAM = (u64)(sq << 2);
    }
    while (REG_SQRTCNT & 0x8000) {
    }
    return (s32)(REG_SQRT_RESULT + 1) >> 1;
}

void func_ov000_0219ff8c(Obj0219ff8c *self) {
    self->unk_b68 = 0;
    self->unk_b6a = 0;
    self->unk_b6c = 0;
    self->unk_b6e = 0;
    self->unk_b36 = 0;
    self->unk_b38 = 0;
    self->unk_b2c.b4 = 0;
    LFLD(Bits32_0219ff8c, self->unk_5c, 0).b1 = 0;
    func_ov000_021bd300(self->unk_5c);
    LFLD(Bits32_0219ff8c, self->unk_9b0, 0).b1 = 0;
    func_ov000_021bd300(self->unk_9b0);
    if (self->unk_b24.b0) {
        self->unk_b24.b0 = 0;
        if (*self->unk_50 == 0) {
            *self->unk_50 = 1;
        }
    }
    if (self->unk_b22.b3 && !self->unk_b22.b4 &&
        !self->unk_93.b4 && !self->unk_b24.b0) {
        func_ov000_021b1a54((u8 *)self, TRUE);
    }
    if (self->unk_b28.st != 0) {
        {
            u8 *p = self->unk_48;
            LFLD(Bits16_0219ff8c, p, 0x9a).b3 = 0;
            func_0203f364(p);
        }
        switch (self->unk_b28.st) {
        case 1:
            if (Dist0219ff8c(self) <= 0x400) {
                LFLD(u64, self->unk_40, 4) |= 2;
            } else {
                LFLD(u64, self->unk_40, 4) |= 4;
            }
            break;
        case 2:
            if (Dist0219ff8c(self) <= 0x400) {
                self->unk_15 = 1;
                self->unk_b28.st = 0;
                self->unk_b28.b2 = 0;
                LFLD(u64, self->unk_40, 4) |= 2;
            } else {
                LFLD(u64, self->unk_40, 4) |= 4;
            }
            break;
        case 3:
            LFLD(u64, self->unk_40, 4) |= 4;
            self->unk_b28.st = 2;
            break;
        }
        return;
    }
    if (self->unk_b1e != 0xffff) {
        Actor *a = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, self->unk_b1e);
        if (a == NULL) {
            self->unk_b1e = 0xffff;
        }
    }
}

}
