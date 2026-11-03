#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/GfxMgr.h"

typedef struct {
    u32 b0 : 13;
    u32 color : 8;
    u32 rest : 11;
} TextFlags02158588;

typedef struct Item02158588 {
    s32 unk_00;
    s16 idx;
    u8 pad_06[0x16];
    VObj *text;
    u8 pad_20[0x8];
    struct Item02158588 *next2;
    struct Item02158588 *next;
} Item02158588;

typedef struct {
    Item02158588 *item;
    s32 x;
    s32 y;
    s32 z;
    s32 col;
    s32 dim;
    s32 ofs;
    s32 pad;
} Msg02158588;

extern "C" {

u8 Gfx3DState_NextPolyId(void *p);
void Obj02153c48_CreateText(void *item, s32 a, s32 b, s32 c, s32 d);
void func_ov000_02153f30(VObj *self, s32 a);
void func_ov000_02153f60(VObj *self, s32 a);

void UiList021cb4a8_DrawItems(UiList021cb4a8 *self, s32 on, s32 *pos) {
    Item02158588 *sel;
    s32 lo;
    s32 k;
    s32 px;
    s32 hi;
    GfxSys *g;
    s32 first;
    s32 py;
    s32 dim;
    s32 ox;
    Item02158588 *top;
    s32 oy;
    s32 s;
    s32 col;
    s32 d;
    s32 ow;
    s32 lh;
    Item02158588 *it;
    s32 last;

    if (on == 0 || (it = (Item02158588 *)self->items) == NULL) {
        return;
    }
    g = gGfxSys;
    lh = self->vfunc_40();
    col = Gfx3DState_NextPolyId(g->unk_8b0);
    s = self->unk_9e;
    if (s != 0) {
        top = (Item02158588 *)self->topItem;
        last = self->rows;
        lo = top->idx - 1;
        hi = top->idx + last + 1;
        if (top->next2 == NULL) k = 0; else k = -1;
    } else if (self->unk_a8 != NULL && self->unk_a0 != 0) {
        if (self->flags & 0x200000) {
            top = (Item02158588 *)self->topItem;
            last = self->rows;
            lo = top->idx - 1;
            hi = top->idx + last;
            if (top->next2 == NULL) k = 0; else k = -1;
        } else {
            top = (Item02158588 *)self->topItem;
            last = self->rows;
            k = 0;
            lo = top->idx;
            hi = top->idx + last + 1;
        }
    } else {
        top = (Item02158588 *)self->topItem;
        last = self->rows;
        k = 0;
        lo = top->idx;
        hi = top->idx + last;
    }
    if (s > 0 || self->unk_a0 > 0) {
        first = 0;
        last -= 2;
    } else if (s < 0 || self->unk_a0 < 0) {
        first = 1;
        last -= 1;
    } else {
        first = 0;
    }
    ox = self->vfunc_30();
    oy = self->unk_9e + self->vfunc_34();
    ow = self->vfunc_8c();
    while (it != NULL) {
        if (it->idx >= lo && it->idx < hi) {
            if (it->unk_00 != 0) {
                if (it->text == NULL) {
                    Obj02153c48_CreateText(it, self->font, 0, 0, 0);
                }
                if (k < first || k > last) {
                    dim = 1;
                    func_ov000_02153f30(it->text, self->posZ);
                } else {
                    dim = 0;
                    func_ov000_02153f60(it->text, self->posZ);
                }
                LFLD(TextFlags02158588, it->text, 4).color = (u8)col;
                d = 0;
                sel = (Item02158588 *)self->unk_a8;
                if (sel != NULL) {
                    s16 a0 = self->unk_a0;
                    if (a0 > 0 && it->idx < sel->idx) {
                        d = a0;
                    } else if (a0 < 0 && it->idx > sel->idx) {
                        d = a0;
                    }
                }
                if (self->flags & 0x1000000) {
                    ox = ((0x100 - LFLD(s32, it->text, 0x44)) >> 1) - self->posX;
                }
                px = ox + (pos[0] >> 12);
                py = d + (lh * k + (oy + (pos[1] >> 12)));
                it->text->vfunc_20(px + ow, py);
                it->text->vfunc_90();
                self->vfunc_dc(it, px, py, col, dim);
                self->vfunc_e0(it, px + ow, py, col, 0);
                self->vfunc_e4(it, pos[0] >> 12, py, col, dim);
                if (self->onDrawItem != NULL) {
                    Msg02158588 m;
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
