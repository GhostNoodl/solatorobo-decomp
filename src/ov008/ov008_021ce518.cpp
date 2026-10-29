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
    s32 unk_114;
    s32 unk_118;
    s32 unk_11c;
};

struct Ov008Snd {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 rest : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
};

struct Ov008Fade {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
};

extern "C" {

extern Ov008Fade data_02097d78;
extern Ov008Snd *data_02097e48;
extern void *data_02097e4c;
extern void *data_02149ef8;
extern char data_ov008_021d04f4[];
extern void *data_ov000_021cac60;
extern void *data_ov000_021caec8;
extern void *data_ov000_021cb1b0;
extern void *data_ov000_021cb0b8;
void func_ov008_021cdb00(Ov008Mgr3 *m);
BOOL func_ov008_021cddc8(Ov008Mgr3 *m);
void func_ov008_021cdebc(Ov008Mgr3 *m);
void func_ov008_021cfa38(Ov008Mgr3 *m);
void func_ov008_021cee4c(Ov008Mgr3 *m);
void func_ov008_021cce38(void *p);
BOOL func_ov008_021cf878(void);
void func_0203cb78(s32 a, int b, int c);
void func_0203cc58(int a, int b, int c);
void *func_0204c08c(void *a, u16 b, s32 *c, int d);
void func_ov000_0214c6b4(void *a, s32 b, void *c, int d);
u16 func_02061d54(s32 a);
s32 func_0204c0e8(void *p, s32 id);
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
void func_02041cb4(void *a, int b);
void func_ov000_02190a80(void *a, s32 b);
BOOL func_ov000_02190cb0(void *a, const char *b, s32 c, s32 d);
void *func_ov000_02190a30(void *a, s32 b);

}

static inline BOOL Ov008_FadeDone(int ch) {
    BOOL r;
    if (data_02097d78.unk_0c == 4) {
        r = TRUE;
    } else {
        r = (&data_02097d78.unk_00)[ch] == 4;
    }
    return r;
}

static inline void Ov008_SetRot(void *w, s16 x, s16 y, s16 z) {
    FLD(s16, w, 0x64) = x;
    FLD(s16, w, 0x66) = y;
    FLD(s16, w, 0x68) = z;
}

static inline BOOL Ov008_Has200(void *p) {
    return FLD(void *, p, 0x200) != NULL ? TRUE : FALSE;
}

extern "C" {

s32 func_ov008_021ce518(Ov008Mgr3 *m) {
    s32 n;
    Ov008V *w;
    s32 id;
    void *res;
    switch (m->state) {
    case 0:
        return 0;
    case 1:
        func_ov008_021cdb00(m);
        m->state = 2;
    case 2:
        if (!func_ov008_021cddc8(m)) {
            break;
        }
        m->state = 3;
    case 3:
        if (!Ov008_FadeDone(0)) {
            break;
        }
        if (!Ov008_FadeDone(1)) {
            break;
        }
        m->state = 4;
    case 4:
        func_0203cb78(0x8000, 0, -1);
        func_ov008_021cdebc(m);
    case 6:
        func_ov008_021cfa38(m);
        m->state = 10;
    case 10:
        if (m->flags.b0) {
            if (!m->flags.b4) {
                m->flags.b4 = true;
                m->unk_11c = 0x2000;
            }
            if (m->unk_100 != NULL) {
                FLD(u32, m->unk_100, 0xc) |= 2;
            }
            if (m->unk_10c != NULL) {
                FLD(u32, m->unk_10c, 0xc) |= 2;
            }
        }
        if (m->unk_10c != NULL) {
            if (!Ov008_Has200(m->unk_10c)) {
                if (m->unk_110 == 0xffff) {
                    FLD(u32, m->unk_100, 0xc) &= ~4;
                } else {
                    s32 t;
                    void *r = func_0204c08c(FLD(void *, m->unk_fc, 0xbc), m->unk_110, &t, 1);
                    func_ov000_0214c6b4(m->unk_10c, t, r, 0x3c);
                    FLD(u32, m->unk_100, 0xc) |= 4;
                    m->unk_110 = 0xffff;
                }
            } else {
                FLD(u32, m->unk_100, 0xc) |= 4;
            }
        }
        n = 0;
        if (m->unk_100->v1c()) {
            n++;
        }
        if (m->unk_10c != NULL && m->unk_10c->v1c()) {
            n++;
        }
        if (n != 0) {
            break;
        }
        m->flags.b0 = 0;
        if (!m->flags.b1 && m->flags.b2) {
            m->state = 7;
            break;
        }
        m->flags.b2 = 0;
        m->state = 8;
        break;
    case 11:
        if (m->flags.b2) {
            m->flags.b0 = true;
            m->state = 10;
            break;
        } else {
            res = data_02149ef8;
            id = func_02061d54(0x1a);
            w = (Ov008V *)func_0203dd9c(0x1e4);
            if (w != NULL) {
                FLD(void *, w, 0) = &data_ov000_021cac60;
                w->v28();
                FLD(void *, w, 0) = &data_ov000_021caec8;
                w->v28();
                FLD(void *, w, 0) = &data_ov000_021cb1b0;
                w->v28();
                FLD(void *, w, 0) = &data_ov000_021cb0b8;
                w->v28();
            }
            m->unk_104 = w;
            FLD(s32, m->unk_104, 0x1dc) = func_0204c0e8(res, id);
            FLD(void *, m->unk_104, 0x8) = m;
            Ov008_SetRot(m->unk_104, 0, 0, 0);
            FLD(u32, m->unk_104, 0xc) |= 0x80000;
            FLD(void *, m->unk_104, 0x84) = (void *)func_ov008_021cf878;
            m->unk_104->v08();
            m->state = 12;
        }
    case 12:
        if (m->flags.b2) {
            FLD(u32, m->unk_104, 0xc) |= 2;
        }
        if (m->unk_104->v1c()) {
            break;
        }
        if (m->flags.b1) {
            m->flags.b0 = true;
        }
        OV008_FREE_V(m->unk_104, v04);
        m->state = 10;
        break;
    case 8:
        if (m->flags.b1) {
            m->state = 13;
            break;
        }
        {
            Ov008Snd *g = data_02097e48;
            if (g->b3) {
                g->unk_06 = 0x8000;
                g->unk_08 = 0x14;
                g->unk_02 = 0;
            }
        }
        func_0203cc58(0x1e000, 2, -1);
        m->state = 9;
    case 9:
        if (!Ov008_FadeDone(0)) {
            break;
        }
    case 7:
        OV008_FREE_V(m->unk_100, v04);
        OV008_FREE_V(m->unk_10c, v04);
        if (m->flags.b2) {
            m->flags.b2 = 0;
            m->state = 6;
        } else {
            m->state = 0;
        }
        break;
    case 13: {
        const char *s = data_ov008_021d04f4;
        m->unk_114 = 0;
        func_ov000_02190cb0(m->unk_d0, s, 0, 1);
        FLD(s16, func_ov000_02190a30(m->unk_d0, 0), 0x112) = 0xb33;
        func_ov000_02190cb0(m->unk_c8, s, 0, 1);
        FLD(s16, func_ov000_02190a30(m->unk_c8, 0), 0x112) = 0xb33;
        m->state = 14;
    }
    case 14:
        switch (++m->unk_114) {
        case 11:
            func_02049a48(data_02097e4c, 0x35, -1, -1, -1);
            break;
        case 16:
        case 30:
            func_02049a48(data_02097e4c, 0x32, -1, -1, -1);
            break;
        case 20:
            if (m->unk_f8 != NULL) {
                FLD(u8, m->unk_f8, 0x68) = 1;
            }
            break;
        default:
            break;
        case 40: {
            Ov008Snd *g = data_02097e48;
            if (g->b3) {
                g->unk_06 = 0x8000;
                g->unk_08 = 0x1e;
                g->unk_02 = 0;
            }
            func_0203cc58(0x1e000, 2, -1);
            m->state = 9;
            break;
        }
        }
        break;
    case 5:
        break;
    }
    if (m->unk_e8 != NULL) {
        func_02041cb4(m->unk_e8, 0);
    }
    func_ov008_021cee4c(m);
    if (m->state >= 5) {
        func_ov000_02190a80(m->unk_c8, 0x1000);
        func_ov000_02190a80(m->unk_d0, 0x1000);
    }
    if (m->unk_f4 != NULL) {
        func_ov008_021cce38(m->unk_f4);
    }
    return 1;
}

}
