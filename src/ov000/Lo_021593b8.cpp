#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u32 b0 : 13;
    u32 color : 8;
    u32 rest : 11;
} TextFlags021593b8;

typedef struct Item021593b8 {
    s32 unk_00;
    s16 idx;
    u8 pad_06[0x16];
    VObj *text;
    u8 pad_20[0x8];
    struct Item021593b8 *next2;
    struct Item021593b8 *next;
} Item021593b8;

typedef struct {
    Item021593b8 *item;
    s32 x;
    s32 y;
    s32 z;
    s32 col;
    s32 dim;
    s32 ofs;
    s32 pad;
} Msg021593b8;

extern "C" {

extern u8 *data_02097d48;
u8 Gfx3DState_NextPolyId(void *p);
void func_ov000_02153c48(void *item, s32 a, s32 b, s32 c, s32 d);
void func_ov000_02153f30(VObj *self, s32 a);
void func_ov000_02153f60(VObj *self, s32 a);

void func_ov000_021593b8(Lo021cb3a8 *self, s32 on, s32 *pos) {
    s32 lo;
    s32 k;
    s32 px;
    s32 hi;
    u8 *g;
    s32 first;
    s32 py;
    s32 dim;
    s32 ox;
    Item021593b8 *top;
    s32 oy;
    s32 s;
    s32 col;
    s32 ow;
    s32 lh;
    Item021593b8 *it;
    s32 last;

    if (on == 0 || (it = (Item021593b8 *)self->unk_94) == NULL) {
        return;
    }
    g = data_02097d48;
    k = 0;
    lh = self->vfunc_40();
    col = Gfx3DState_NextPolyId(g + 0x8b0);
    if (!(self->unk_0c & 0x20000)) {
        lo = ((Item021593b8 *)self->unk_98)->idx;
        hi = lo + self->unk_20;
        first = lo;
        last = hi;
    } else {
        s = self->unk_9e;
        if (s != 0) {
            top = (Item021593b8 *)self->unk_98;
            last = self->unk_20;
            lo = top->idx - 1;
            hi = top->idx + last + 1;
            if (top->next2 != NULL) {
                k--;
            }
        } else {
            top = (Item021593b8 *)self->unk_98;
            last = self->unk_20;
            lo = top->idx;
            hi = top->idx + last;
        }
        if (s > 0) {
            last -= 2;
            first = 0;
        } else {
            first = 1;
        }
    }
    ox = self->vfunc_30();
    oy = self->vfunc_34() + self->unk_9e;
    ow = self->vfunc_8c();
    while (it != NULL) {
        if (it->idx >= lo && it->idx < hi) {
            if (it->unk_00 != 0) {
                if (it->text == NULL) {
                    func_ov000_02153c48(it, self->unk_1c, 0, 1, 0);
                }
                if (k < first || k > last) {
                    dim = 1;
                    func_ov000_02153f30(it->text, self->unk_68);
                } else {
                    dim = 0;
                    func_ov000_02153f60(it->text, self->unk_68);
                }
                LFLD(TextFlags021593b8, it->text, 4).color = (u8)col;
                px = ox + (pos[0] >> 12);
                py = lh * k + (oy + (pos[1] >> 12));
                it->text->vfunc_20(px + ow, py);
                it->text->vfunc_90();
                self->vfunc_dc(it, px, py, col, dim);
                self->vfunc_e4(it, pos[0] >> 12, py, col, dim);
                if (self->unk_80 != NULL) {
                    Msg021593b8 m;
                    m.item = it;
                    m.x = px;
                    m.y = py;
                    m.z = self->unk_68;
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
