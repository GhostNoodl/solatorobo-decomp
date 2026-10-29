#include "ov008/ov008.h"

struct Ov008Mgr {
    s32 unk_00;
    s32 unk_04;
    u8 unk_08[0xbc];
    void *unk_c4;
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
    void *unk_100;
    void *unk_104;
    void *unk_108;
    void *unk_10c;
    u16 unk_110;
    u16 unk_112;
    s32 unk_114;
    s32 unk_118;
    s32 unk_11c;
};

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

struct Ov008Vec3 {
    s32 x;
    s32 y;
    s32 z;
};

struct Ov008Rot3 {
    u16 x;
    u16 y;
    u16 z;
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

struct Ov008Bits85 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
};

struct Ov008Bits6c {
    u32 b0 : 2;
    u32 b2 : 5;
    u32 rest : 25;
};

struct Ov008Bits8b0 {
    u8 b0 : 4;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 rest : 2;
};


struct Ov008Fade {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
};

extern "C" {

extern Ov008Fade data_02097d78;
extern char data_ov008_021d04f4[];
extern void *data_02149ef8;
extern void *data_ov000_021caec8;
extern void *data_ov000_021cb1b0;
extern void *data_ov000_021cb0b8;
extern void *data_02097e4c;
void func_ov008_021cdb00(Ov008Mgr3 *m);
BOOL func_ov008_021cddc8(Ov008Mgr3 *m);
void func_ov008_021cdebc(Ov008Mgr *m);
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

extern char data_ov008_021d04a7[];
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_0208b318;
extern void *data_ov000_021cac60;
void STD_CopyString(void *dst, const void *src);

extern const Ov008Vec3 data_ov008_021d02d0;
extern const Ov008Vec3 data_ov008_021d02dc;
extern const Ov008Rot3 data_ov008_021d02c8;
extern char data_ov008_021d04f0[];
extern char data_ov008_021d04c5[];
extern void *data_0208cb74;
extern void *data_0208cc88;
extern void *data_ov000_021ca94c;
extern void *data_0208ba70;
extern Ov008Snd *data_02097e48;
extern u8 *data_02097d48;

void *func_ov000_0218fe1c(void *p);
BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_02190cb0(void *a, const char *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void *func_ov000_02190a30(void *a, s32 b);
void func_02041440(void *p, const void *res, int c);
void func_020417e0(void *a, void *b);
void func_02041d9c(void *a, int b, int c);
void func_02041cf8(void *a, int b);
void func_02041c18(void *a, void *b);
void func_02041c34(void *a, int b, void *f, int c);
void func_02041c5c(void *a, void *f);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
BOOL func_0205aa30(void *p);
s32 func_ov000_0214bc94(void);
void func_0204c7d0(void *p);
void func_0204aab0(void *p);
void func_020626c0(void);
void *func_ov008_021cd26c(void);
void *func_ov008_021cd3dc(void);

}

static inline void *Ov008_NewMdl(void) {
    void *a = func_0203dd9c(0xe8);
    if (a != NULL) {
        a = func_ov000_0218fe1c(a);
    }
    return a;
}

extern "C" {

void func_ov008_021cdebc(Ov008Mgr *m) {
    Ov008Vec3 pos = data_ov008_021d02d0;
    Ov008Vec3 tgt = data_ov008_021d02dc;
    Ov008Rot3 rot = data_ov008_021d02c8;
    void *res;
    void *p;
    FLD(Ov008Vec3, m, 0x18) = pos;
    FLD(Ov008Vec3, m, 0x24) = tgt;
    FLD(u16, m, 0x4e) = rot.z;
    FLD(u16, m, 0x4a) = rot.x;
    FLD(u16, m, 0x4c) = rot.y;
    FLD(s32, m, 0x50) = 0x4400;
    FLD(u16, m, 0x48) = 1;

    m->unk_c8 = Ov008_NewMdl();
    func_ov000_0218ffdc(m->unk_c8, m->unk_c4, 0, 1);
    func_ov000_02190cb0(m->unk_c8, data_ov008_021d04f0, 0, 1);
    FLD(s16, m->unk_c8, 0xb4) = 0;
    func_ov000_021915a0(m->unk_c8);
    FLD(s16, func_ov000_02190a30(m->unk_c8, 0), 0x112) = 0x400;

    m->unk_d0 = Ov008_NewMdl();
    func_ov000_0218ffdc(m->unk_d0, m->unk_cc, 0, 1);
    func_ov000_02190cb0(m->unk_d0, data_ov008_021d04f0, 0, 1);
    FLD(s16, m->unk_d0, 0xb4) = 0;
    func_ov000_021915a0(m->unk_d0);
    FLD(s16, func_ov000_02190a30(m->unk_d0, 0), 0x112) = 0x400;

    p = func_0203dd9c(0x160);
    if (p != NULL) {
        const char *name = data_ov008_021d04a7;
        if (name) {
            func_02041218((u8 *)p + 0x88);
            func_02041440(p, name, 0);
        }
    }
    m->unk_d8 = p;
    func_020417e0(m->unk_d8, (void *)((Ov008V *)m->unk_d4)->v10());
    func_02041d9c(m->unk_d8, 2, 0xffff);

    p = func_0203dd9c(0x160);
    if (p != NULL) {
        const char *name = data_ov008_021d04a7;
        if (name) {
            func_02041218((u8 *)p + 0x88);
            func_02041440(p, name, 0);
        }
    }
    m->unk_e0 = p;
    func_020417e0(m->unk_e0, (void *)((Ov008V *)m->unk_dc)->v10());
    func_02041d9c(m->unk_e0, 0, 0xffff);
    FLD(s32, m->unk_e0, 0x150) = -0x1fe66;

    p = func_0203dd9c(0x160);
    if (p != NULL) {
        const char *name = data_ov008_021d04c5;
        if (name) {
            func_02041218((u8 *)p + 0x88);
            func_02041440(p, name, 0);
        }
    }
    m->unk_e8 = p;
    func_020417e0(m->unk_e8, (void *)((Ov008V *)m->unk_e4)->v10());
    func_02041d9c(m->unk_e8, 2, 0xffff);
    func_02041d9c(m->unk_e8, 0, 0xffff);
    func_02041cf8(m->unk_e8, 0);
    FLD(u8, m->unk_e8, 0x85) &= (u8)~4;
    FLD(u8, m->unk_e8, 0x85) &= (u8)~1;
    func_02041c18(m->unk_e8, m);
    func_02041c34(m->unk_e8, 2, (void *)func_ov008_021cd26c, 0);

    {
    void *q;
    res = func_02034d88(func_02035d5c(data_0208cca0), data_0208cb74);
    q = func_0203dd9c(0x160);
    if (q != NULL) {
        void *file = data_0208cca0;
        void *nm = data_0208cb74;
        func_02041218((u8 *)q + 0x88);
        func_02041440(q, nm, 0);
        STD_CopyString((u8 *)q + 0x2c, file);
    }
    m->unk_ec = q;
    func_020417e0(q, res);
    FLD(u32, m->unk_ec, 0x6c) |= 2;
    func_02041d9c(m->unk_ec, 0, 0xd);
    }

    {
    void *q;
    res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
    q = func_0203dd9c(0x160);
    if (q != NULL) {
        void *file = data_0208cc94;
        void *nm = data_0208cc88;
        func_02041218((u8 *)q + 0x88);
        func_02041440(q, nm, 0);
        STD_CopyString((u8 *)q + 0x2c, file);
    }
    m->unk_f0 = q;
    func_020417e0(q, res);
    FLD(u32, m->unk_f0, 0x6c) |= 2;
    func_02041d9c(m->unk_f0, 0, 6);
    }
    FLD(u32, m->unk_f0, 0x6c) |= 0x80000;
    FLD(Ov008Bits6c, m->unk_f0, 0x6c).b2 = 0x1e;
    func_02041c5c(m->unk_f0, (void *)func_ov008_021cd3dc);

    p = func_0203dd9c(0x54);
    if (p != NULL) {
        FLD(void *, p, 4) = &data_0208b318;
        VOBJ(p, 4)->v08();
        FLD(s32, p, 0) = 0;
        VOBJ(p, 4)->v08();
        FLD(u16, p, 0x50) = 0xffff;
        FLD(u16, p, 0x52) = 0xffff;
    }
    m->unk_f4 = p;

    p = func_0203dd9c(0x6c);
    if (p != NULL) {
        FLD(void *, p, 4) = &data_0208b318;
        VOBJ(p, 4)->v08();
        FLD(s32, p, 0) = 0;
        VOBJ(p, 4)->v08();
        FLD(s32, p, 0x50) = 0;
        FLD(s32, p, 0x54) = 0;
        FLD(s32, p, 0x58) = 0;
        FLD(s32, p, 0x5c) = 0;
        FLD(s32, p, 0x60) = 0;
        FLD(s32, p, 0x64) = 0;
        FLD(u8, p, 0x68) = 0;
    }
    m->unk_f8 = p;

    func_0205aa30(m->unk_fc);
    func_ov000_0214bc94();

    p = func_0203dd9c(0x21c);
    if (p != NULL) {
        FLD(void *, p, 0) = &data_ov000_021cac60;
        ((Ov008V *)p)->v28();
        FLD(void *, p, 0) = &data_ov000_021ca94c;
        FLD(void *, p, 0x90) = &data_0208ba70;
        func_0204c7d0((u8 *)p + 0x90);
        FLD(void *, p, 0x148) = &data_0208ba70;
        func_0204c7d0((u8 *)p + 0x148);
        ((Ov008V *)p)->v28();
    }
    m->unk_10c = p;
    ((Ov008V *)p)->v08();
    FLD(s16, m->unk_10c, 0x68) = -0x2000;

    {
        Ov008Snd *g = data_02097e48;
        if (g->b0 && !(g->unk_06 == 0xffff && g->unk_04 == 0xc)) {
            if (g->unk_02 != 10 && g->unk_02 != 0) {
                if (g->unk_06 != 0xffff) {
                    func_0204aab0(g);
                }
                g->unk_02 = 1;
            } else {
                g->unk_02 = 0;
            }
            g->unk_06 = 0xc;
            g->unk_08 = 10;
        }
    }
    FLD(u8, data_02097d48, 0x8b0) = (u8)(FLD(u8, data_02097d48, 0x8b0) & ~0x10) | 0x20;
    *(vu16 *)0x4000060 &= 0xcfdf;
    func_020626c0();
}

}
