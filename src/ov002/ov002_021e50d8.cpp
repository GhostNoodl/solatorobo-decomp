#include "ov002/ov002.h"
extern "C" {
typedef struct Rec021e50d8 {
    s32 id;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    u8 e;
    u8 f;
    s32 g;
} Rec021e50d8;

void func_ov002_021e50d8(void *self, s32 a, s32 b) {
    Rec021e50d8 rec;
    rec.id = 0;
    rec.a = a;
    rec.b = b;
    rec.c = 0;
    rec.d = 0;
    rec.e = 0;
    rec.f = 0;
    rec.g = 0;
    rec.id = (u8)FIELD(self, 0x4c, s32);
    MIi_CpuCopy32(&rec, (u8 *)self + 0xc0 + FIELD(self, 0x1a0, s32) * 0x1c, 0x1c);
    FIELD(self, 0x1a0, s32)++;
}
}
