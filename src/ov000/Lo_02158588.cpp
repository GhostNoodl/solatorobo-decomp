#include "ov000/LoCommon.h"

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

extern u8 *data_02097d48;
u8 func_02043d48(void *p);
void func_ov000_02153c48(void *item, s32 a, s32 b, s32 c, s32 d);
void func_ov000_02153f30(VObj *self, s32 a);
void func_ov000_02153f60(VObj *self, s32 a);

void func_ov000_02158588(VObj *self, s32 on, s32 *pos) {
    Item02158588 *sel;
    s32 lo;
    s32 k;
    s32 px;
    s32 hi;
    u8 *g;
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

    if (on == 0 || (it = LFLD(Item02158588 *, self, 0x94)) == NULL) {
        return;
    }
    g = data_02097d48;
    lh = self->vfunc_40();
    col = func_02043d48(g + 0x8b0);
    s = LFLD(s16, self, 0x9e);
    if (s != 0) {
        top = LFLD(Item02158588 *, self, 0x98);
        last = LFLD(s32, self, 0x20);
        lo = top->idx - 1;
        hi = top->idx + last + 1;
        if (top->next2 == NULL) k = 0; else k = -1;
    } else if (LFLD(void *, self, 0xa8) != NULL && LFLD(s16, self, 0xa0) != 0) {
        if (LFLD(u32, self, 0xc) & 0x200000) {
            top = LFLD(Item02158588 *, self, 0x98);
            last = LFLD(s32, self, 0x20);
            lo = top->idx - 1;
            hi = top->idx + last;
            if (top->next2 == NULL) k = 0; else k = -1;
        } else {
            top = LFLD(Item02158588 *, self, 0x98);
            last = LFLD(s32, self, 0x20);
            k = 0;
            lo = top->idx;
            hi = top->idx + last + 1;
        }
    } else {
        top = LFLD(Item02158588 *, self, 0x98);
        last = LFLD(s32, self, 0x20);
        k = 0;
        lo = top->idx;
        hi = top->idx + last;
    }
    if (s > 0 || LFLD(s16, self, 0xa0) > 0) {
        first = 0;
        last -= 2;
    } else if (s < 0 || LFLD(s16, self, 0xa0) < 0) {
        first = 1;
        last -= 1;
    } else {
        first = 0;
    }
    ox = self->vfunc_30();
    oy = LFLD(s16, self, 0x9e) + self->vfunc_34();
    ow = self->vfunc_8c();
    while (it != NULL) {
        if (it->idx >= lo && it->idx < hi) {
            if (it->unk_00 != 0) {
                if (it->text == NULL) {
                    func_ov000_02153c48(it, LFLD(s32, self, 0x1c), 0, 0, 0);
                }
                if (k < first || k > last) {
                    dim = 1;
                    func_ov000_02153f30(it->text, LFLD(s16, self, 0x68));
                } else {
                    dim = 0;
                    func_ov000_02153f60(it->text, LFLD(s16, self, 0x68));
                }
                LFLD(TextFlags02158588, it->text, 4).color = (u8)col;
                d = 0;
                sel = LFLD(Item02158588 *, self, 0xa8);
                if (sel != NULL) {
                    s16 a0 = LFLD(s16, self, 0xa0);
                    if (a0 > 0 && it->idx < sel->idx) {
                        d = a0;
                    } else if (a0 < 0 && it->idx > sel->idx) {
                        d = a0;
                    }
                }
                if (LFLD(u32, self, 0xc) & 0x1000000) {
                    ox = ((0x100 - LFLD(s32, it->text, 0x44)) >> 1) - LFLD(s16, self, 0x64);
                }
                px = ox + (pos[0] >> 12);
                py = d + (lh * k + (oy + (pos[1] >> 12)));
                it->text->vfunc_20(px + ow, py);
                it->text->vfunc_90();
                self->vfunc_dc(it, px, py, col, dim);
                self->vfunc_e0(it, px + ow, py, col, 0);
                self->vfunc_e4(it, pos[0] >> 12, py, col, dim);
                if (LFLD(void *, self, 0x80) != NULL) {
                    Msg02158588 m;
                    m.item = it;
                    m.x = px;
                    m.y = py;
                    m.z = LFLD(s16, self, 0x68);
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
