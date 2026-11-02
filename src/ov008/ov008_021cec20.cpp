#include "ov008/ov008.h"

extern "C" {

struct Ov008Pos16 {
    s16 x;
    s16 y;
};

extern Ov008Pos16 data_ov008_021d02fc[];
void func_ov008_021cf040(Ov008Mgr *m);
BOOL Model021903b4_Draw(void *p);
void func_ov008_021ccf44(Ov008Panel *p);

static inline void Ov008_SetPos(Model *e, Ov008Pos16 *p) {
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
        m->unk_e8->unk_085 = (u8)(m->unk_e8->unk_085 & 0xfb) | 4;
        Ov008_DrawModel2(m->unk_e8);
        m->unk_e8->unk_085 &= 0xfb;
    }
    func_ov008_021cf040(m);
    if (m->state >= 5 && m->unk_c8 != NULL && m->unk_d0 != NULL) {
        m->cam.v00();
        Model021903b4_Draw(m->unk_c8);
        Model021903b4_Draw(m->unk_d0);
    }
    switch (m->state) {
    case 0:
    case 1:
    case 2:
        break;
    case 10:
    case 11:
    case 12:
        if (m->menu != NULL) {
            m->menu->v20();
        }
        if (m->talk != NULL) {
            m->talk->v20();
        }
        if (m->state == 11 || m->state == 12) {
            if (m->dialog != NULL) {
                m->dialog->v20();
            }
        }
        break;
    }
}

void func_ov008_021cee4c(Ov008Mgr *m) {
    if (m->panel == NULL || m->caption == NULL || m->menu == NULL) {
        return;
    }
    if (m->caption->pic.v34()) {
        Ov008Panel *a = m->panel;
        Ov008Caption *b = m->caption;
        if (a->pic.v34()) {
            a->pic.v0c();
        }
        MI_CpuCopy8(&b->pic, &a->pic, 0x4c);
        if (a->state == 0) {
            a->state = 0xf;
        } else if (a->state == 0x10) {
            a->state = 0x11;
            if (a->offset <= 0) {
                a->unk_5c = 0;
            } else {
                a->unk_5c = a->offset;
            }
            a->offset = -0x1000;
        }
        m->caption->pic.v08();
        if (!m->flags.b3) {
            m->flags.b4 = 0;
            m->flags.b3 = 1;
            m->flags.cnt = 0;
            m->unk_11c = 0x80000;
        }
    }
    func_ov008_021ccf44(m->panel);
    if (m->flags.b4 == 1) {
        m->unk_11c += FX_Mul(m->unk_11c, 0x666);
        if (Ov008_Abs(m->unk_11c) > 0x80000) {
            m->unk_11c = 0x80000;
            m->flags.b3 = 0;
        }
    } else if (m->flags.b3 == 1) {
        s16 c = m->flags.cnt - 1;
        if (c < 0) {
            c = 0;
            m->unk_11c -= FX_Mul(m->unk_11c, 0x333);
            if (Ov008_Abs(m->unk_11c) < 0x800) {
                m->unk_11c = 0;
            }
        }
        m->flags.cnt = c;
    }
}

}
