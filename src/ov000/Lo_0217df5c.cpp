#include "ov000/LoCommon.h"

typedef struct {
    u32 b0 : 2;
    u32 f2 : 5;
    u32 f7 : 6;
    u32 pad13 : 6;
    u32 b19 : 1;
    u32 b20 : 1;
    u32 b21 : 1;
    u32 rest : 10;
} LoMdlFlags0217df5c;

#define MF(m) LFLD(LoMdlFlags0217df5c, m, 0x6c)

typedef struct {
    s32 x, y, z;
} LoVec0217df5c;

extern "C" {

extern u8 *data_02097d48;
extern u8 data_0208b3d0[];
extern LoVec0217df5c data_ov000_021c9c10;
u8 func_02043d48(void *p);
void func_02043d20(void *p, s32 a);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
void NNS_G3dGeSendDL(const void *dl, u32 size);
s32 func_ov000_0214b8ec(void *p);
void func_ov000_0214b1a0(LoVec0217df5c *pos, LoVec0217df5c *col, s32 a, s32 b);

static inline void *LoModelGetPart(void *self, int idx) {
    if (idx >= LFLD(s32, self, 0x80)) {
        return NULL;
    }
    return (u8 *)LFLD(void *, self, 0x78) + idx * 0x28;
}

static inline void LoModelPlayPart(void *model, int idx) {
    void *res = LFLD(void *, model, 0x28);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = LoModelGetPart(model, idx);
    if (part != NULL && LFLD(void *, part, 0x4) != NULL) {
        anim = LFLD(void *, LFLD(void *, part, 0x4), 0x30);
    } else {
        anim = NNS_G2dGetCellDataByIdx(LFLD(void *, res, 0x4), **(u16 **)LFLD(void *, NNS_G2dGetAnimSequenceByIdx(LFLD(void *, res, 0xc), idx), 0xc));
    }
    func_02042628(model, anim, part, 0);
}

static inline void LoSetPosFx0217df5c(void *m, s32 x, s32 y) {
    LFLD(s32, m, 0xfc) = x;
    LFLD(s32, m, 0x100) = y;
}

static inline void LoSetPosV0217df5c(void *m, LoVec0217df5c *p) {
    LFLD(s32, m, 0xfc) = p->x;
    LFLD(s32, m, 0x100) = p->y;
}

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

void func_ov000_0217df5c(u8 *self, LoVec0217df5c *pos) {
    LoVec0217df5c v;
    u8 *g = data_02097d48;
    u32 size;
    u8 i;
    MF(LFLD(void *, self, 0xa0)).b19 = 1;
    MF(LFLD(void *, self, 0xa0)).f7 = func_02043d48(g + 0x8b0);
    MF(LFLD(void *, self, 0xa0)).f2 = 0x1c;
    LoSetPosV0217df5c(LFLD(void *, self, 0xa0), pos);
    LFLD(s32, LFLD(void *, self, 0xa0), 0x150) = -0x1ccd;
    LoModelPlayPart(LFLD(void *, self, 0xa0), 1);
    if (LFLD(u8, self, 0x71) != 0) {
        v.x = pos->x - 0x6f000;
        v.y = pos->y - 0x4a000;
        v.z = pos->z;
        MF(LFLD(void *, self, 0xa0)).b19 = 0;
        MF(LFLD(void *, self, 0xa0)).f2 = 0x1f;
        for (i = 0; i < 3; i++) {
            LFLD(s32, LFLD(void *, self, 0xa0), 0x150) = -0x1c8d;
            LoSetPosV0217df5c(LFLD(void *, self, 0xa0), &v);
            LoModelPlayPart(LFLD(void *, self, 0xa0), 2);
            if (i < LFLD(u8, self, 0x71)) {
                LFLD(s32, LFLD(void *, self, 0xa0), 0x150) = -0x1c4d;
                LoSetPosV0217df5c(LFLD(void *, self, 0xa0), &v);
                LoModelPlayPart(LFLD(void *, self, 0xa0), 3);
            }
            v.x += 0xc000;
        }
    }
    func_02043d20(g + 0x8b0, 0);
    G3_Vec(0x1b, 0x1000, 0x1000, 0x1000);
    G3_Cmd1(0x2a, 0x20000000);
    G3_Cmd1(0x29, 0x1f00d0);
    G3_Cmd1(0x20, 0);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos->x + 0x80000, pos->y + 0x16000, -0x1c8d);
    G3_Vec(0x1b, 0xea000, 0xc000, 0x1000);
    size = *(u32 *)0x020828f8;
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 0), size);
    G3_Cmd1(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos->x + 0xc000, pos->y + 0x60000, -0x1c8d);
    G3_Vec(0x1b, 0x2000, 0xa0000, 0x1000);
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 0), size);
    G3_Cmd1(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos->x + 0xf4000, pos->y + 0x60000, -0x1c8d);
    G3_Vec(0x1b, 0x2000, 0xa0000, 0x1000);
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 0), size);
    G3_Cmd1(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos->x + 0x80000, pos->y + 0xaf000, -0x1c8d);
    G3_Vec(0x1b, 0xea000, 0x2000, 0x1000);
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 0), size);
    G3_Cmd1(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos->x + 0xbe000, pos->y + 0x74000, -0x1c8d);
    G3_Vec(0x1b, 0x66000, 0x71000, 0x1000);
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 0), size);
    G3_Cmd1(0x12, 1);
    {
    LoVec0217df5c c = data_ov000_021c9c10;
    v.x = pos->x + 0xbe000;
    v.y = pos->y + 0x6e000;
    v.z = -0x1c4d;
    func_ov000_0214b1a0(&v, &c, 0x1f, func_ov000_0214b8ec(LFLD(void *, self, 0x6c)));
    }
}

}
