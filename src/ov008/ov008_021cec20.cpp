#include "ov008/ov008.h"

struct Ov008Mgr3Flags {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 cnt : 8;
    u32 rest : 19;
};

struct Ov008Mgr3 {
    Ov008Mgr3Flags flags;
    s32 state;
    Ov008V sub;
    u8 unk_0c[0xbc];
    void *unk_c8;
    void *unk_cc;
    void *unk_d0;
    void *unk_d4;
    void *unk_d8;
    void *unk_dc;
    void *unk_e0;
    void *unk_e4;
    void *unk_e8;
    void *unk_ec;
    void *unk_f0;
    void *unk_f4;
    void *unk_f8;
    void *unk_fc;
    Ov008V *unk_100;
    Ov008V *unk_104;
    void *unk_108;
    Ov008V *unk_10c;
    u16 unk_110;
    u16 unk_112;
    u8 unk_114[0x8];
    s32 unk_11c;
};

extern "C" {

struct Ov008Pos16 {
    s16 x;
    s16 y;
};

extern Ov008Pos16 data_ov008_021d02fc[];
void func_ov008_021cf040(Ov008Mgr3 *m);
void func_ov000_021903b4(void *p);
void func_ov008_021ccf44(void *p);
void MI_CpuCopy8(const void *src, void *dst, u32 size);

static inline void Ov008_SetPos(void *e, Ov008Pos16 *p) {
    s32 x = p->x - 0x80;
    s32 y = p->y - 0x60;
    FLD(s32, e, 0x10c) = x << 12;
    FLD(s32, e, 0x110) = y << 12;
}

void func_ov008_021cec20(Ov008Mgr3 *m) {
    if (m->unk_d8 != NULL) {
        Ov008_DrawModel2(m->unk_d8);
    }
    if (m->unk_e8 != NULL) {
        Ov008_SetPos(m->unk_e8, &data_ov008_021d02fc[m->unk_112]);
        FLD(u8, m->unk_e8, 0x85) = (u8)(FLD(u8, m->unk_e8, 0x85) & 0xfb) | 4;
        Ov008_DrawModel2(m->unk_e8);
        FLD(u8, m->unk_e8, 0x85) &= 0xfb;
    }
    func_ov008_021cf040(m);
    if (m->state >= 5 && m->unk_c8 != NULL && m->unk_d0 != NULL) {
        m->sub.v00();
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

void func_ov008_021cee4c(Ov008Mgr3 *m) {
    if (m->unk_f8 == NULL || m->unk_f4 == NULL || m->unk_100 == NULL) {
        return;
    }
    if (VOBJ(m->unk_f4, 4)->v34()) {
        void *a = m->unk_f8;
        void *b = m->unk_f4;
        if (VOBJ(a, 4)->v34()) {
            VOBJ(a, 4)->v0c();
        }
        MI_CpuCopy8((u8 *)b + 4, (u8 *)a + 4, 0x4c);
        if (FLD(s32, a, 0) == 0) {
            FLD(s32, a, 0) = 0xf;
        } else if (FLD(s32, a, 0) == 0x10) {
            FLD(s32, a, 0) = 0x11;
            if (FLD(s32, a, 0x54) <= 0) {
                FLD(s32, a, 0x5c) = 0;
            } else {
                FLD(s32, a, 0x5c) = FLD(s32, a, 0x54);
            }
            FLD(s32, a, 0x54) = -0x1000;
        }
        VOBJ(m->unk_f4, 4)->v08();
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
