#include "ov008/ov008.h"

extern "C" {

struct Ov008Pos16 {
    s16 x;
    s16 y;
};

extern Ov008Pos16 data_ov008_021d02fc[];
void func_ov008_021cf040(Ov008Mgr *m);
BOOL func_ov000_021903b4(void *p);
void func_ov008_021ccf44(Ov008Panel *p);
void MI_CpuCopy8(const void *src, void *dst, u32 size);

static inline void Ov008_SetPos(Ov008Sprite *e, Ov008Pos16 *p) {
    s32 x = p->x - 0x80;
    s32 y = p->y - 0x60;
    e->unk_10c = x << 12;
    e->unk_110 = y << 12;
}

void func_ov008_021cec20(Ov008Mgr *m) {
    if (m->unk_d8 != NULL) {
        Ov008_DrawModel2(m->unk_d8);
    }
    if (m->unk_e8 != NULL) {
        Ov008_SetPos(m->unk_e8, &data_ov008_021d02fc[m->unk_112]);
        m->unk_e8->unk_85 = (u8)(m->unk_e8->unk_85 & 0xfb) | 4;
        Ov008_DrawModel2(m->unk_e8);
        m->unk_e8->unk_85 &= 0xfb;
    }
    func_ov008_021cf040(m);
    if (m->state >= 5 && m->unk_c8 != NULL && m->unk_d0 != NULL) {
        m->cam.v00();
        func_ov000_021903b4(m->unk_c8);
        func_ov000_021903b4(m->unk_d0);
    }
    switch (m->state) {
    case 0:
    case 1:
    case 2:
        break;
    case 10:
    case 11:
    case 12:
        if (m->unk_100 != NULL) {
            m->unk_100->v20();
        }
        if (m->unk_10c != NULL) {
            m->unk_10c->v20();
        }
        if (m->state == 11 || m->state == 12) {
            if (m->unk_104 != NULL) {
                m->unk_104->v20();
            }
        }
        break;
    }
}

void func_ov008_021cee4c(Ov008Mgr *m) {
    if (m->unk_f8 == NULL || m->unk_f4 == NULL || m->unk_100 == NULL) {
        return;
    }
    if (m->unk_f4->pic.v34()) {
        Ov008Panel *a = m->unk_f8;
        Ov008Caption *b = m->unk_f4;
        if (a->pic.v34()) {
            a->pic.v0c();
        }
        MI_CpuCopy8(&b->pic, &a->pic, 0x4c);
        if (a->state == 0) {
            a->state = 0xf;
        } else if (a->state == 0x10) {
            a->state = 0x11;
            if (a->unk_54 <= 0) {
                a->unk_5c = 0;
            } else {
                a->unk_5c = a->unk_54;
            }
            a->unk_54 = -0x1000;
        }
        m->unk_f4->pic.v08();
        if (!m->flags.b3) {
            m->flags.b4 = 0;
            m->flags.b3 = 1;
            m->flags.cnt = 0;
            m->unk_11c = 0x80000;
        }
    }
    func_ov008_021ccf44(m->unk_f8);
    if (m->flags.b4 == 1) {
        m->unk_11c += Ov008_FxMul(m->unk_11c, 0x666);
        if (Ov008_Abs(m->unk_11c) > 0x80000) {
            m->unk_11c = 0x80000;
            m->flags.b3 = 0;
        }
    } else if (m->flags.b3 == 1) {
        s16 c = m->flags.cnt - 1;
        if (c < 0) {
            c = 0;
            m->unk_11c -= Ov008_FxMul(m->unk_11c, 0x333);
            if (Ov008_Abs(m->unk_11c) < 0x800) {
                m->unk_11c = 0;
            }
        }
        m->flags.cnt = c;
    }
}

}
