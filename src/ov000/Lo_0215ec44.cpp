#include "ov000/LoCommon.h"

extern "C" {

void STD_CopyLString(void *dst, const void *src, s32 n);

static inline void LoInitEC44(void *self) {
    LFLD(s32, self, 0x0) = 0;
    LFLD(s32, self, 0x4) = 0;
    LFLD(s32, self, 0x8) = 0;
    LFLD(s32, self, 0xc) = 0;
    LFLD(s32, self, 0x1c) = 0;
    LFLD(s32, self, 0x18) = 0;
    LFLD(s32, self, 0x10) = 0x80000;
    LFLD(s32, self, 0x14) = 0xf000;
    LFLD(s32, self, 0x20) = 0;
    LFLD(s32, self, 0x24) = 0;
    LFLD(s32, self, 0x28) = 0;
}

void func_ov000_0215ec44(void *self) {
    LoInitEC44(self);
}

void func_ov000_0215ec80(void *self) {
    LO_FREE_M(self, 0x28);
    LoInitEC44(self);
}

}

typedef struct {
    u16 x;
    u16 y;
    u16 z;
} V6_0215ed18;

typedef struct {
    u32 b0 : 1;
    u32 col : 2;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 rest : 27;
} Flags0215ed18;

typedef struct {
    u32 b0 : 2;
    u32 alpha : 5;
    u32 polyId : 6;
    u32 b13 : 6;
    u32 b19 : 1;
    u32 b20 : 1;
    u32 b21 : 1;
    u32 rest : 10;
} MdlFlags0215ed18;

typedef struct {
    Flags0215ed18 flags;
    s32 x;
    s32 y;
    s32 z;
    s32 w;
    s32 h;
    s32 dx;
    s32 dy;
    u8 pad20[8];
    u8 *model;
} Obj0215ed18;

extern "C" {
extern u8 *data_02097d48;
extern V6_0215ed18 data_02fe01a0[];
extern u16 data_02fe014c[];
extern u16 data_02fe0158[];
extern u16 data_02fe0164[];
extern u16 data_02fe0170[];
extern u16 data_02fe017c[];
s32 func_02043d48(void *p);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);

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

static inline void G3_Vtx(u16 x, u16 y, u16 z) {
    u32 v[2];
    v[0] = x | (y << 16);
    v[1] = z;
    NNS_G3dGeBufferOP_N(0x23, v, 2);
}

static inline BOOL HasAlpha0215ed18(u8 *m) {
    return LFLD(MdlFlags0215ed18, m, 0x6c).b19 ? TRUE : FALSE;
}

static inline BOOL Flag20_0215ed18(u8 *m) {
    return LFLD(MdlFlags0215ed18, m, 0x6c).b20 ? TRUE : FALSE;
}

static inline BOOL Flag21_0215ed18(u8 *m) {
    return LFLD(MdlFlags0215ed18, m, 0x6c).b21 ? TRUE : FALSE;
}

void func_ov000_0215ed18(Obj0215ed18 *self) {
    u8 *g;
    s32 y;
    s32 x;
    s32 z;
    s32 alpha;
    u32 col;
    u32 misc;
    u8 mode;
    V6_0215ed18 *vtx;
    u16 *tbl;
    s32 w;
    s32 i;
    g = data_02097d48;
    x = self->x;
    x += 0x8000;
    y = self->y;
    z = self->z;
    x += self->dx << 12;
    y += self->dy << 12;
    misc = 0;
    G3_Cmd1(0x2a, 0x20000000);
    alpha = HasAlpha0215ed18(self->model) ? (u8)LFLD(MdlFlags0215ed18, self->model, 0x6c).alpha : 0x1e;
    if (Flag20_0215ed18(self->model)) {
        misc |= 0x4000;
    }
    col = self->flags.col;
    w = self->w - 0x10000;
    mode = 0xd0;
    vtx = data_02fe01a0;
    if (self->flags.b4 ? TRUE : FALSE) {
        tbl = data_02fe014c;
    } else {
        if (col == 0) {
            tbl = data_02fe0158;
        } else if (col == 1) {
            tbl = data_02fe0164;
        } else if (col == 2) {
            tbl = data_02fe0170;
        } else if (col == 3) {
            tbl = data_02fe017c;
        }
    }
    if (self->flags.b0) {
        x -= self->w >> 1;
    }
    G3_Cmd1(0x29, misc | mode | (func_02043d48(g + 0x8b0) << 24) | (alpha << 16));
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, x, y, z);
    G3_Vec(0x1b, w, self->h + 0x2000, 0x1000);
    G3_Cmd1(0x40, 2);
    G3_Cmd1(0x20, 0);
    for (i = 0; i < 6; i++) {
        G3_Vtx(vtx[i].x, vtx[i].y, vtx[i].z);
    }
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3_Cmd1(0x12, 1);
    if (Flag21_0215ed18(self->model)) {
        misc |= 0x800;
    }
    G3_Cmd1(0x29, misc | mode | (g[0x8b1] << 24) | (alpha << 16));
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, x, y + 0x1000, self->z);
    G3_Vec(0x1b, w, self->h, 0x1000);
    G3_Cmd1(0x40, 2);
    for (i = 0; i < 6; i++) {
        G3_Cmd1(0x20, tbl[i]);
        G3_Vtx(vtx[i].x, vtx[i].y, vtx[i].z);
    }
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3_Cmd1(0x12, 1);
    LFLD(MdlFlags0215ed18, self->model, 0x6c).polyId = func_02043d48(g + 0x8b0);
}

}
