#include "ov000/VObj.h"
#include "ov000/LoCommon.h"
#include "ov000/Actor.h"
#include "ov000/CmdQueue.h"

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

typedef struct {
    u8 unk_00[6];
    u16 h6;
    u8 unk_08[4];
    s32 unk_0c;
} Item02177f40;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 3;
    u16 st : 3;
    u16 b9 : 2;
    u16 b11 : 2;
    u16 b13 : 1;
    u16 b14 : 2;
} Bits21b1d28;

typedef struct {
    u8 unk_00[0x18];
    u16 b0 : 1;
    u16 b1 : 2;
    u16 b3 : 13;
} Save0214a424;

extern "C" {
extern Data021ccd50 data_ov000_021ccd50;
extern Obj02097e48 *data_02097e48;
extern u8 *data_0214a424;
extern void *data_02097e4c;
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL func_ov000_0219bf90(void *p);
void func_02062764(s32 a, s32 b);

static inline void Set54(u8 *t, u8 n, s32 c) {
    LFLD(u16, LFLD(u8 *, t, 0x54), 0x8a) = n <= 1 ? 1 : n;
    LFLD(s32, LFLD(u8 *, t, 0x54), 0x8c) = c;
}
static inline void Set54b(u8 *t, s32 c, u8 n) {
    LFLD(u16, LFLD(u8 *, t, 0x54), 0x8a) = n <= 1 ? 1 : n;
    LFLD(s32, LFLD(u8 *, t, 0x54), 0x8c) = c;
}
void func_ov000_02199dc0(u8 *self, u8 *out) {
    s32 d = LFLD(s32, self, 0x50);
    s32 x, y, w;
    w = 0x52;
    if (d == 0) {
        if (self[0] == 0xf || self[0] == 0x13) {
            x = 0x31f;
            y = 0x31f - 0x52;
        } else {
            x = 0x348;
            y = 0x348 - 0x7b;
        }
    } else {
        s32 e = LFLD(s32, self, 0x54);
        s64 q = 0x6cd000LL / (d + ABS(e));
        x = (s32)((q * (d + 0x52) + 0x800) >> 12);
        y = (s32)((q * e + 0x800) >> 12);
        w = 0x14;
    }
    x += LFLD(s32, self, 0x58);
    if (out != NULL) {
        LFLD(s32, out, 0x9c) = x;
        LFLD(s32, out, 0xa0) = y;
        LFLD(s32, out, 0xa4) = 0;
        LFLD(s32, out, 0xa8) = w;
    }
}

static inline void SetSt21b(u8 *self, u16 st) {
    u8 *sub = self + 0x22;
    Bits21b1d28 *b = &LFLD(Bits21b1d28, sub, 0xb00);
    ActorSub40 *p;
    b->st = st;
    b->b9 = 1;
    p = LFLD(ActorSub40 *, self, 0x40);
    p->flags |= 0x80000000;
    func_ov000_02198360(LFLD(void *, self, 0x40), 0x1f, 0);
}

}
