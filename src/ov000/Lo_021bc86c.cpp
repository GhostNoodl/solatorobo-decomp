#include "ov000/LoCommon.h"

typedef struct {
    u32 unk_00;
    void *unk_04;
} DLRef021bc86c;

extern "C" {
extern u8 *data_02097d48;
extern DLRef021bc86c data_0208b3d0;
extern DLRef021bc86c data_020828f8;
void func_02043d20(void *obj, int a);
u8 func_02043d48(void *p);
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

void func_ov000_021bc86c(void) {
    u8 *g = data_02097d48;
    u32 size;
    func_02043d20(g + 0x8b0, 0);
    G3_Cmd1(0x29, 0 | (1 << 4) | (3 << 6) | (1 << 11) | (func_02043d48(g + 0x8b0) << 24) | (0x1e << 16));
    G3_Cmd1(0x2a, 0x20000000);
    G3_Cmd1(0x20, 0);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, 0, 0, -0xc4d);
    G3_Vec(0x1b, 0x100000, 0xc000, 0x1000);
    size = (u32)data_020828f8.unk_04;
    NNS_G3dGeSendDL(data_0208b3d0.unk_04, size);
    G3_Cmd1(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, 0, 0x92000, -0x99a);
    G3_Vec(0x1b, 0x100000, 0x2e000, 0x1000);
    NNS_G3dGeSendDL(data_0208b3d0.unk_04, size);
    G3_Cmd1(0x12, 1);
}

}
