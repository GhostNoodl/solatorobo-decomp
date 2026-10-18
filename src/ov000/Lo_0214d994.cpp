#include "ov000/VObj.h"
#include "ov000/ModelPart.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    u8 pad_00[0x200];
    u8 *unk_200;
} Obj0214d994;

typedef struct {
    u32 b0 : 10;
    u32 b10 : 1;
    u32 b11 : 21;
} Bits0214d994;

typedef struct {
    u32 unk_00;
    void *unk_04;
} DLRef0214d994;

extern "C" {
extern u8 *data_02097d48;
extern DLRef0214d994 data_0208b3d0;
extern DLRef0214d994 data_020828f8;
void func_02043d20(void *obj, int a);
s32 func_02043d48(void *p);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
void NNS_G3dGeSendDL(const void *dl, u32 size);

static inline void G3_Vec(int cmd, int x, int y, int z) {
    int v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    NNS_G3dGeBufferOP_N(cmd, v, 3);
}

static inline void G3_Cmd1(int cmd, u32 value) {
    u32 v = value;
    NNS_G3dGeBufferOP_N(cmd, &v, 1);
}

void func_ov000_0214d994(Obj0214d994 *self) {
    u8 *p = self->unk_200;
    u8 *g = data_02097d48;
    s32 v;
    s32 alpha;
    v = LFLD(s32, p, 0xb30);
    if ((LFLD(Bits0214d994, p, 0xb8).b10 == 1) ? TRUE : FALSE) {
        v = 0x1000 - v;
    }
    alpha = LO_FX_MUL(v, 0x14000) >> 12 & 0xff;
    if (alpha == 0) {
        return;
    }
    func_02043d20(g + 0x8b0, 0);
    G3_Cmd1(0x2a, 0x20000000);
    G3_Cmd1(0x29, 0 | (1 << 4) | (3 << 6) | (func_02043d48(g + 0x8b0) << 24) | (alpha << 16));
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, 0, 0, -0xccd);
    G3_Vec(0x1b, 0x100000, 0xc0000, 0x1000);
    G3_Cmd1(0x20, 0x7fff);
    NNS_G3dGeSendDL(data_0208b3d0.unk_04, (u32)data_020828f8.unk_04);
    G3_Cmd1(0x12, 1);
}

}
