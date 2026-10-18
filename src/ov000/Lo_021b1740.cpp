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
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
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
void func_ov000_021b1740(u8 *self, BOOL flag) {
    u32 st;
    if (LFLD(Bits21b1d28, self, 0xb22).b0 == 0) {
        return;
    }
    if (LFLD(Bits21b1d28, self, 0xb22).b9 != 0) {
        return;
    }
    st = 0;
    if (((Save0214a424 *)data_0214a424)->b1 == 1) {
        st = 2;
    }
    if (LFLD(Bits21b1d28, self, 0xb22).b9 < 2) {
        LFLD(Bits21b1d28, self, 0xb22).st = (u16)st;
        LFLD(Bits21b1d28, self, 0xb22).b9 = 1;
        LFLD(ActorSub40 *, self, 0x40)->flags |= 0x80000000;
        func_ov000_02198360(LFLD(void *, self, 0x40), 0x1f, 0);
    }
    func_02062764(0x30, 0x10);
    if (flag) {
        LFLD(u8, data_ov000_021ccd54, 0xac) = 1;
    }
}

}
