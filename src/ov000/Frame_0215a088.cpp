extern "C" {
#include "nitro/gx.h"
}
#include "nitro/gx_g3b.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vtx0215a088;

typedef struct {
    Vtx0215a088 v[4];
} Vtxs0215a088;

typedef struct {
    fx32 s;
    fx32 t;
} Tc0215a088;

typedef struct {
    Tc0215a088 t[16];
} Tcs0215a088;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 sx;
    fx32 sy;
    s8 vi[4];
    s8 ti[4];
} Quad0215a088;

typedef struct {
    Quad0215a088 q[8];
} Quads0215a088;

typedef struct {
    u8 pad_00[0x24];
    s32 unk_24;
    s32 unk_28;
    u8 pad_2c[0xac];
    void *unk_d8;
    u32 unk_dc;
} Frame0215a088;

extern "C" {
extern const Vtxs0215a088 data_ov000_021c98fa;
extern const Tcs0215a088 data_ov000_021c995c;
extern const Quads0215a088 data_ov000_021c99dc;
void *func_0203de84(u32 size, u32 align);
void DC_FlushRange(const void *p, u32 size);

void func_ov000_0215a088(Frame0215a088 *self) {
    Tcs0215a088 tc;
    Quads0215a088 quads;
    GXDLInfo dl;
    Vtxs0215a088 vtx;
    s32 x = self->unk_24 << 12;
    s32 y = self->unk_28 << 12;
    s32 i;
    Quad0215a088 *q;
    s32 j;

    self->unk_dc = 0x480;
    self->unk_d8 = func_0203de84(0x480, 4);
    G3_BeginMakeDL(&dl, self->unk_d8, self->unk_dc);
    G3B_Color(&dl, 0x7fff);
    vtx = data_ov000_021c98fa;
    tc = data_ov000_021c995c;
    quads = data_ov000_021c99dc;
    quads.q[1].x = x - 0x8000;
    quads.q[2].y = y - 0x8000;
    quads.q[3].x = x - 0x8000;
    quads.q[3].y = y - 0x8000;
    quads.q[4].sx = x - 0x10000;
    quads.q[5].sy = y - 0x10000;
    quads.q[6].y = y - 0x8000;
    quads.q[6].sx = x - 0x10000;
    quads.q[7].x = x - 0x8000;
    quads.q[7].sy = y - 0x10000;
    q = quads.q;
    for (i = 0; i < 8; i++) {
        G3B_PushMtx(&dl);
        G3B_Translate(&dl, q->x, q->y, 0);
        G3B_Scale(&dl, q->sx, q->sy, 0x1000);
        G3B_Begin(&dl, GX_BEGIN_QUADS);
        for (j = 0; j < 4; j++) {
            G3B_TexCoord(&dl, tc.t[q->ti[j]].s, tc.t[q->ti[j]].t);
            G3B_Vtx(&dl, vtx.v[q->vi[j]].x, vtx.v[q->vi[j]].y, 0);
        }
        G3B_End(&dl);
        G3B_PopMtx(&dl, 1);
        q++;
    }
    self->unk_dc = G3_EndMakeDL(&dl);
    DC_FlushRange(self->unk_d8, self->unk_dc);
}
}
