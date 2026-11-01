#include "ov008/ov008.h"


extern "C" {

extern Ov008Mgr *data_ov008_021d0500;
void *func_0204b370(void *p);
void func_0204b420(void *p);
void func_ov008_021cd500(Ov008Mgr *m);
void func_ov008_021cd584(Ov008Mgr *m);
void *func_ov000_0218ea20(void *p);
void func_02036838(void *a, void *b, int c, int d);
void func_ov000_0214bc10(void);
void func_ov000_0214c210(void);
extern void *data_02097cdc;
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_0208b318;

void func_ov008_021cd448(void) {
    Ov008Mgr *p;
    if (data_ov008_021d0500 != NULL) {
        return;
    }
    p = (Ov008Mgr *)func_0203dd9c(0x120);
    if (p != NULL) {
        func_0204b370(&p->cam);
        func_ov008_021cd500(p);
    }
    data_ov008_021d0500 = p;
}

void func_ov008_021cd48c(void) {
    if (data_ov008_021d0500 == NULL) {
        return;
    }
    OV008_FREE(data_ov008_021d0500, Ov008Mgr *, (func_ov008_021cd584(p_), func_0204b420(&p_->cam), func_0203de1c(p_)));
}

void func_ov008_021cd500(Ov008Mgr *m) {
    m->unk_00 = 0;
    m->state = 1;
    m->unk_c4 = NULL;
    m->unk_c8 = NULL;
    m->unk_cc = NULL;
    m->unk_d0 = NULL;
    m->unk_d4 = NULL;
    m->unk_d8 = NULL;
    m->unk_dc = NULL;
    m->unk_e0 = NULL;
    m->unk_e4 = NULL;
    m->unk_e8 = NULL;
    m->unk_ec = NULL;
    m->unk_f0 = NULL;
    m->unk_f4 = NULL;
    m->unk_f8 = NULL;
    m->unk_fc = NULL;
    m->unk_100 = NULL;
    m->unk_104 = NULL;
    m->unk_108 = NULL;
    m->unk_10c = NULL;
    m->unk_110 = 0xffff;
    m->unk_112 = 0xffff;
    m->unk_114 = 0;
    m->unk_118 = 0;
    m->unk_11c = 0x80000;
}

void func_ov008_021cd584(Ov008Mgr *m) {
    OV008_FREE_D(m->unk_c8, func_ov000_0218fee4);
    OV008_FREE_D(m->unk_d0, func_ov000_0218fee4);
    OV008_FREE_M(m->unk_d8);
    OV008_FREE_M(m->unk_e0);
    OV008_FREE_M(m->unk_e8);
    OV008_FREE_M(m->unk_ec);
    OV008_FREE_M(m->unk_f0);
    {
        u32 saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (m->unk_f8 != NULL) {
            Ov008Panel *p = m->unk_f8;
            if (p != NULL) {
                p->pic.v0c();
                OV008_FREE_M(p->unk_50);
                OV008_SET_VT(&p->pic, &data_0208b318);
                p->pic.v0c();
                func_0203de1c(p);
            }
            m->unk_f8 = NULL;
        }
        data_02097dd0->cur = saved;
    }
    OV008_FREE_D(m->unk_c4, func_ov000_0218ea20);
    OV008_FREE_D(m->unk_cc, func_ov000_0218ea20);
    OV008_FREE_V(m->unk_d4, v04);
    OV008_FREE_V(m->unk_dc, v04);
    OV008_FREE_V(m->unk_e4, v04);
    OV008_FREE(m->unk_f4, Ov008Caption *, (p_->pic.v0c(), OV008_SET_VT(&p_->pic, &data_0208b318), p_->pic.v0c(), func_0203de1c(p_)));
    OV008_FREE_V(m->unk_fc, v04);
    OV008_FREE_V(m->unk_100, v04);
    OV008_FREE_V(m->unk_104, v04);
    OV008_FREE_V(m->unk_10c, v04);
    func_02036838(data_02097cdc, data_0208cca0, 7, 0);
    func_02036838(data_02097cdc, data_0208cc94, 7, 0);
    func_ov000_0214bc10();
    func_ov000_0214c210();
}

extern void *data_ov000_021caec8;
extern void *data_ov000_021cac60;
extern void *data_0208bf54;
extern char data_ov008_021d0462[];
extern char data_ov008_021d0470[];
extern char data_ov008_021d047c[];
extern char data_ov008_021d0487[];
extern char data_ov008_021d049b[];
extern char data_ov008_021d04a7[];
extern char data_ov008_021d04b3[];
extern char data_ov008_021d04c5[];
extern char data_ov008_021d04d1[];
extern char data_ov008_021d04d9[];
extern char data_ov008_021d04e1[];
void *func_020359d0(void *a, int b, int c);
BOOL func_02035b90(void *a, int b);
void *func_ov000_0218e9c4(void *p);
BOOL func_ov000_0218f110(void *p);
void *STD_CopyString(void *dst, const void *src);
void *STD_ConcatenateString(void *dst, const void *src);
void func_0206e900(char *dst, const char *src);
void func_0205a6a0(void *p);
void func_0205a840(void *p, const char *a, const char *b);
BOOL func_0205a9c8(void *p);
void func_ov000_0214bb80(void);
void func_ov000_0214c1ac(void);
BOOL func_ov000_0214bc6c(void);
BOOL func_ov000_0214c270(void);

Ov008V *func_ov008_021cdab4(Ov008V *self) {
    OV008_SET_VT(self, &data_ov000_021caec8);
    self->v2c();
    OV008_SET_VT(self, &data_ov000_021cac60);
    self->v2c();
    func_0203de1c(self);
    return self;
}

}

static inline void Ov008_SetNameA(Ov008Anim *p, const char *a, const char *b) {
    STD_CopyString(p->unk_10, a);
    STD_CopyString(p->unk_30, b);
    p->unk_03 |= 2;
}

static inline void Ov008_SetNameB(Ov008Anim *p, const char *a, const char *b) {
    STD_CopyString(p->unk_4c, a);
    STD_CopyString(p->unk_6c, b);
    p->unk_03 |= 4;
}

static inline Ov008Anim *Ov008_NewMsg(void) {
    Ov008Anim *p = (Ov008Anim *)func_0203dd9c(0x138);
    if (p != NULL) {
        p = (Ov008Anim *)func_ov000_0218e9c4(p);
    }
    return p;
}

static inline Ov008Pic *Ov008_NewText(void) {
    Ov008Pic *p = (Ov008Pic *)func_0203dd9c(0x4c);
    if (p != NULL) {
        OV008_SET_VT(p, &data_0208b318);
        p->v08();
    }
    return p;
}

extern "C" {

}
