#include "ov000/VObj.h"
#include "Main/Res/StageCmd.h"
#include "ov000/ObjLayouts.h"
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
    u16 b0 : 3;
    u16 b3 : 3;
    u16 st : 3;
    u16 b9 : 2;
    u16 b11 : 2;
    u16 b13 : 1;
    u16 b14 : 2;
} Bits21b1d28;

extern "C" {
extern Data021ccd50 data_ov000_021ccd50;
extern Obj02097e48 *data_02097e48;
extern void *data_02097e4c;
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_02062764(s32 a, s32 b);

static inline void Set54(u8 *t, u8 n, s32 c) {
    LFLD(u16, LFLD(u8 *, t, 0x54), 0x8a) = n <= 1 ? 1 : n;
    LFLD(s32, LFLD(u8 *, t, 0x54), 0x8c) = c;
}
static inline void Set54b(u8 *t, s32 c, u8 n) {
    LFLD(u16, LFLD(u8 *, t, 0x54), 0x8a) = n <= 1 ? 1 : n;
    LFLD(s32, LFLD(u8 *, t, 0x54), 0x8c) = c;
}
struct Obj02199dc0 {
    u8 unk_00;
    u8 unk_01[0x4f];
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
};

void func_ov000_02199dc0(Obj02199dc0 *self, u8 *out) {
    s32 d = self->unk_50;
    s32 x, y, w;
    w = 0x52;
    if (d == 0) {
        if (self->unk_00 == 0xf || self->unk_00 == 0x13) {
            x = 0x31f;
            y = 0x31f - 0x52;
        } else {
            x = 0x348;
            y = 0x348 - 0x7b;
        }
    } else {
        s32 e = self->unk_54;
        s64 q = 0x6cd000LL / (d + ABS(e));
        x = (s32)((q * (d + 0x52) + 0x800) >> 12);
        y = (s32)((q * e + 0x800) >> 12);
        w = 0x14;
    }
    x += self->unk_58;
    if (out != NULL) {
        LFLD(s32, out, 0x9c) = x;
        LFLD(s32, out, 0xa0) = y;
        LFLD(s32, out, 0xa4) = 0;
        LFLD(s32, out, 0xa8) = w;
    }
}

struct SetSt21bSelf {
    u8 unk_00[0x40];
    ActorSub40 *unk_40;
};

static inline void SetSt21b(SetSt21bSelf *self, u16 st) {
    u8 *sub = (u8 *)self + 0x22;
    Bits21b1d28 *b = &LFLD(Bits21b1d28, sub, 0xb00);
    ActorSub40 *p;
    b->st = st;
    b->b9 = 1;
    p = self->unk_40;
    p->flags |= 0x80000000;
    func_ov000_02198360(self->unk_40, 0x1f, 0);
}

}
