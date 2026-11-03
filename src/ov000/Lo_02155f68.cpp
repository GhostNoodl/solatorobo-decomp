#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/GfxMgr.h"

#define GX_PACK_POLYGONATTR_PARAM(light, polyMode, cullMode, polygonID, alpha, misc) \
    ((u32)(((light) << 0) | ((polyMode) << 4) | ((cullMode) << 6) | (misc) | ((polygonID) << 24) | ((alpha) << 16)))

typedef struct {
    u16 x;
    u16 y;
    u16 z;
} V6;

typedef struct {
    u32 b0 : 13;
    u32 color : 8;
    u32 rest : 11;
} TextFlags021561f8;


typedef struct {
    UiListItem *item;
    s32 x;
    s32 y;
    s32 z;
    s32 col;
    s32 dim;
    s32 ofs;
    s32 pad;
} Msg021561f8;

extern "C" {
u8 Gfx3DState_NextPolyId(void *p);
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

static inline void G3_Vtx(s16 x, s16 y, s16 z) {
    u32 v[2];
    v[0] = (u16)x | ((u16)y << 16);
    v[1] = (u16)z;
    NNS_G3dGeBufferOP_N(0x23, v, 2);
}

static inline void G3_VtxXY(s16 x, s16 y) {
    u32 v = (u16)x | ((u16)y << 16);
    NNS_G3dGeBufferOP_N(0x25, &v, 1);
}

static inline void G3_PolygonAttr(s32 light, s32 polyMode, s32 cullMode, s32 polygonID, s32 alpha, s32 misc) {
    G3_Cmd1(0x29, light | (polyMode << 4) | (cullMode << 6) | (polygonID << 24) | (alpha << 16) | misc);
}

static inline void G3_Cmd2(int cmd, u32 a, u32 b) {
    u32 v[2];
    v[0] = a;
    v[1] = b;
    NNS_G3dGeBufferOP_N(cmd, v, 2);
}

void UiList_DrawFrame(UiList *self, s32 a1, s32 *pos, s32 a3) {
    s16 z;
    GfxSys *g;
    s32 sx;
    s32 sy;
    s32 alpha;
    V6 *v;
    z = self->posZ - 0x110;
    g = data_02097d48;
    G3_Cmd1(0x2a, 0x20000000);
    alpha = self->unk_54;
    G3_Cmd1(0x29, GX_PACK_POLYGONATTR_PARAM(0, 1, 3, Gfx3DState_NextPolyId(g->unk_8b0), alpha, 0x800));
    sx = self->width << 12;
    sy = self->height << 12;
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos[0], pos[1], z);
    G3_Vec(0x1b, sx, sy, 0x1000);
    G3_Cmd1(0x40, 2);
    G3_Cmd1(0x20, self->color);
    v = (V6 *)self->shape;
    if (v != NULL) {
        s32 i;
        G3_Cmd2(0x23, v[0].x | (v[0].y << 16), 0);
        for (i = 1; i < self->shapeCount; i++) {
            v = (V6 *)self->shape;
            G3_Cmd1(0x25, v[i].x | (v[i].y << 16));
        }
    } else {
        G3_Cmd2(0x23, 0, 0);
        G3_Cmd1(0x25, 0x10000000);
        G3_Cmd1(0x25, 0xe00e29);
        G3_Cmd1(0x25, 0xf600e74);
        G3_Cmd1(0x25, 0xbc01000);
    }
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3_Cmd1(0x12, 1);
    if (self->flag6 ? TRUE : FALSE) {
        ((VObj *)self)->vfunc_6c(a1, pos, a3);
    }
}


void Obj02153c48_CreateText(void *item, s32 a, s32 b, s32 c, s32 d);
void func_ov000_02153f30(VObj *self, s32 a);
void func_ov000_02153f60(VObj *self, s32 a);

void func_ov000_021561f8(UiList *self, s32 on, s32 *pos) {
    s32 lo;
    s32 k;
    s32 px;
    s32 hi;
    GfxSys *g;
    s32 first;
    s32 py;
    s32 dim;
    s32 ox;
    UiListItem *top;
    s32 oy;
    s32 s;
    s32 col;
    s32 d;
    s32 ow;
    s32 lh;
    UiListItem *it;
    s32 last;

    if (on == 0 || (it = (UiListItem *)self->items) == NULL) {
        return;
    }
    g = data_02097d48;
    k = 0;
    lh = self->vfunc_40();
    col = Gfx3DState_NextPolyId(g->unk_8b0);
    if (!(self->flags & 0x20000)) {
        lo = ((UiListItem *)self->topItem)->index;
        hi = lo + self->rows;
        first = lo;
        last = hi;
    } else {
        s = self->unk_9e;
        if (s != 0) {
            top = (UiListItem *)self->topItem;
            last = self->rows;
            lo = top->index - 2;
            hi = top->index + last + 2;
            if (top->prev == NULL) {
                k = 1;
            } else if (top->prev->prev != NULL) {
                k--;
            }
        } else if (self->unk_a8 != NULL) {
            if (self->flags & 0x200000) {
                top = (UiListItem *)self->topItem;
                last = self->rows;
                lo = top->index - 2;
                hi = top->index + last + 1;
                if (top->prev == NULL) {
                    k = 1;
                } else if (top->prev->prev != NULL) {
                    k--;
                }
            } else {
                top = (UiListItem *)self->topItem;
                last = self->rows;
                lo = top->index - 1;
                hi = top->index + last + 2;
                if (top->prev == NULL) {
                    k = 1;
                }
            }
        } else {
            top = (UiListItem *)self->topItem;
            last = self->rows;
            lo = top->index - 1;
            hi = top->index + last + 1;
            if (top->prev == NULL) {
                k = 1;
            }
        }
        if (s > 0 || self->unk_a0 > 0) {
            first = 0;
        } else if (s < 0 || self->unk_a0 < 0) {
            last++;
            first = 1;
        } else {
            first = 1;
        }
    }
    ox = self->vfunc_30();
    oy = self->vfunc_34() + self->unk_9e;
    ow = self->vfunc_8c();
    while (it != NULL) {
        if (it->index >= lo && it->index < hi) {
            if (((s32)it->name) != 0) {
                if (it->label == NULL) {
                    Obj02153c48_CreateText(it, self->font, 0, 0, 0);
                }
                if (k < first || k > last) {
                    dim = 1;
                    func_ov000_02153f30(it->label, self->posZ);
                } else {
                    dim = 0;
                    func_ov000_02153f60(it->label, self->posZ);
                }
                LFLD(TextFlags021561f8, it->label, 4).color = (u8)col;
                d = 0;
                if ((UiListItem *)self->unk_a8 != NULL) {
                    s = self->unk_a0;
                    if (s > 0 && it->index < ((UiListItem *)self->unk_a8)->index) {
                        d = s;
                    } else if (s < 0 && it->index > ((UiListItem *)self->unk_a8)->index) {
                        d = s;
                    }
                }
                if (self->flags & 0x1000000) {
                    ox = ((0x100 - LFLD(s32, it->label, 0x44)) >> 1) - self->posX;
                }
                px = ox + (pos[0] >> 12);
                py = d + (lh * k + (oy + (pos[1] >> 12)));
                it->label->vfunc_20(px + ow, py);
                it->label->vfunc_90();
                self->vfunc_dc(it, px, py, col, dim);
                self->vfunc_e0(it, px + ow, py, col, 0);
                self->vfunc_e4(it, pos[0] >> 12, py, col, dim);
                if (self->onDrawItem != NULL) {
                    Msg021561f8 m;
                    m.item = it;
                    m.x = px;
                    m.y = py;
                    m.z = self->posZ;
                    m.col = col;
                    m.dim = dim;
                    m.ofs = -0x110;
                    self->vfunc_48(3, &m);
                }
            }
            k++;
        } else {
            LO_FREE_V(it, 0x1c);
        }
        it = it->next;
    }
}

}
