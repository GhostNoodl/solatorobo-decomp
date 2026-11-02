#include "ov008/ov008.h"

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
void func_ov008_021cdb00(Ov008Mgr *m);
BOOL func_ov008_021cddc8(Ov008Mgr *m);
void func_ov008_021cdebc(Ov008Mgr *m);
void func_ov008_021cfa38(Ov008Mgr *m);
void func_ov008_021cee4c(Ov008Mgr *m);
void func_ov008_021cce38(Ov008Caption *p);
BOOL func_ov008_021cf878(void);
void func_0203cb78(s32 a, int b, int c);
void func_0203cc58(int a, int b, int c);
void *func_0204c08c(void *a, u16 b, s32 *c, int d);
void func_ov000_0214c6b4(void *a, s32 b, void *c, int d);
u16 func_02061d54(s32 a);
s32 MsgRes_GetString(void *p, s32 id);
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
void func_02041cb4(void *a, int b);
void func_ov000_02190a80(void *a, s32 b);

extern char data_ov008_021d04a7[];
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_0208b318;
extern void *data_ov000_021cac60;
void *STD_CopyString(void *dst, const void *src);

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
extern Ov008Sys *data_02097d48;

void *func_ov000_0218fe1c(void *p);
BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_02190cb0(void *a, const char *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
Ov008MdlAnm *func_ov000_02190a30(void *a, s32 b);
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

static inline Ov008Model *Ov008_NewMdl(void) {
    Ov008Model *a = (Ov008Model *)Heap_Alloc(0xe8);
    if (a != NULL) {
        a = (Ov008Model *)func_ov000_0218fe1c(a);
    }
    return a;
}

extern "C" {

void func_ov008_021cdebc(Ov008Mgr *m) {
    Ov008Vec3 pos = data_ov008_021d02d0;
    Ov008Vec3 tgt = data_ov008_021d02dc;
    Ov008Rot3 rot = data_ov008_021d02c8;
    void *res;
    Ov008Sprite *p;
    Ov008Caption *c;
    Ov008Panel *pn;
    Ov008Talk *t;
    m->cam.unk_10 = pos;
    m->cam.unk_1c = tgt;
    m->cam.unk_46 = rot.z;
    m->cam.unk_42 = rot.x;
    m->cam.unk_44 = rot.y;
    m->cam.unk_48 = 0x4400;
    m->cam.unk_40 = 1;

    m->unk_c8 = Ov008_NewMdl();
    func_ov000_0218ffdc(m->unk_c8, m->unk_c4, 0, 1);
    func_ov000_02190cb0(m->unk_c8, data_ov008_021d04f0, 0, 1);
    m->unk_c8->unk_b4 = 0;
    func_ov000_021915a0(m->unk_c8);
    func_ov000_02190a30(m->unk_c8, 0)->unk_112 = 0x400;

    m->unk_d0 = Ov008_NewMdl();
    func_ov000_0218ffdc(m->unk_d0, m->unk_cc, 0, 1);
    func_ov000_02190cb0(m->unk_d0, data_ov008_021d04f0, 0, 1);
    m->unk_d0->unk_b4 = 0;
    func_ov000_021915a0(m->unk_d0);
    func_ov000_02190a30(m->unk_d0, 0)->unk_112 = 0x400;

    p = (Ov008Sprite *)Heap_Alloc(0x160);
    if (p != NULL) {
        const char *name = data_ov008_021d04a7;
        if (name) {
            func_02041218(p->unk_88);
            func_02041440(p, name, 0);
        }
    }
    m->unk_d8 = p;
    func_020417e0(m->unk_d8, (void *)m->unk_d4->v10());
    func_02041d9c(m->unk_d8, 2, 0xffff);

    p = (Ov008Sprite *)Heap_Alloc(0x160);
    if (p != NULL) {
        const char *name = data_ov008_021d04a7;
        if (name) {
            func_02041218(p->unk_88);
            func_02041440(p, name, 0);
        }
    }
    m->unk_e0 = p;
    func_020417e0(m->unk_e0, (void *)m->unk_dc->v10());
    func_02041d9c(m->unk_e0, 0, 0xffff);
    m->unk_e0->unk_150 = -0x1fe66;

    p = (Ov008Sprite *)Heap_Alloc(0x160);
    if (p != NULL) {
        const char *name = data_ov008_021d04c5;
        if (name) {
            func_02041218(p->unk_88);
            func_02041440(p, name, 0);
        }
    }
    m->unk_e8 = p;
    func_020417e0(m->unk_e8, (void *)m->unk_e4->v10());
    func_02041d9c(m->unk_e8, 2, 0xffff);
    func_02041d9c(m->unk_e8, 0, 0xffff);
    func_02041cf8(m->unk_e8, 0);
    m->unk_e8->unk_85 &= (u8)~4;
    m->unk_e8->unk_85 &= (u8)~1;
    func_02041c18(m->unk_e8, m);
    func_02041c34(m->unk_e8, 2, (void *)func_ov008_021cd26c, 0);

    {
    Ov008Sprite *q;
    res = func_02034d88(func_02035d5c(data_0208cca0), data_0208cb74);
    q = (Ov008Sprite *)Heap_Alloc(0x160);
    if (q != NULL) {
        void *file = data_0208cca0;
        void *nm = data_0208cb74;
        func_02041218(q->unk_88);
        func_02041440(q, nm, 0);
        STD_CopyString(q->unk_2c, file);
    }
    m->unk_ec = q;
    func_020417e0(q, res);
    m->unk_ec->flags |= 2;
    func_02041d9c(m->unk_ec, 0, 0xd);
    }

    {
    Ov008Sprite *q;
    res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
    q = (Ov008Sprite *)Heap_Alloc(0x160);
    if (q != NULL) {
        void *file = data_0208cc94;
        void *nm = data_0208cc88;
        func_02041218(q->unk_88);
        func_02041440(q, nm, 0);
        STD_CopyString(q->unk_2c, file);
    }
    m->unk_f0 = q;
    func_020417e0(q, res);
    m->unk_f0->flags |= 2;
    func_02041d9c(m->unk_f0, 0, 6);
    }
    m->unk_f0->flags |= 0x80000;
    m->unk_f0->attr.alpha = 0x1e;
    func_02041c5c(m->unk_f0, (void *)func_ov008_021cd3dc);

    c = (Ov008Caption *)Heap_Alloc(0x54);
    if (c != NULL) {
        OV008_SET_VT(&c->pic, &data_0208b318);
        c->pic.v08();
        c->state = 0;
        c->pic.v08();
        c->unk_50 = 0xffff;
        c->unk_52 = 0xffff;
    }
    m->unk_f4 = c;

    pn = (Ov008Panel *)Heap_Alloc(0x6c);
    if (pn != NULL) {
        OV008_SET_VT(&pn->pic, &data_0208b318);
        pn->pic.v08();
        pn->state = 0;
        pn->pic.v08();
        pn->unk_50 = 0;
        pn->unk_54 = 0;
        pn->unk_58 = 0;
        pn->unk_5c = 0;
        pn->unk_60 = 0;
        pn->unk_64 = 0;
        pn->unk_68 = 0;
    }
    m->unk_f8 = pn;

    func_0205aa30(m->unk_fc);
    func_ov000_0214bc94();

    t = (Ov008Talk *)Heap_Alloc(0x21c);
    if (t != NULL) {
        OV008_SET_VT(t, &data_ov000_021cac60);
        t->v28();
        OV008_SET_VT(t, &data_ov000_021ca94c);
        OV008_SET_VT(&t->unk_90, &data_0208ba70);
        func_0204c7d0(&t->unk_90);
        OV008_SET_VT(&t->unk_148, &data_0208ba70);
        func_0204c7d0(&t->unk_148);
        t->v28();
    }
    m->unk_10c = t;
    t->v08();
    m->unk_10c->unk_68 = -0x2000;

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
    data_02097d48->unk_8b0.unk_00 = (u8)(data_02097d48->unk_8b0.unk_00 & ~0x10) | 0x20;
    *(vu16 *)0x4000060 &= 0xcfdf;
    func_020626c0();
}

}
