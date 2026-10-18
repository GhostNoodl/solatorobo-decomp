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

extern "C" {

extern Ov008Mgr *data_ov008_021d0500;
void func_0204b370(void *p);
void func_0204b420(void *p);
void func_ov008_021cd500(Ov008Mgr *m);
void func_ov008_021cd584(Ov008Mgr *m);
void func_ov000_0218ea20(void *p);
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
        func_0204b370((u8 *)p + 8);
        func_ov008_021cd500(p);
    }
    data_ov008_021d0500 = p;
}

void func_ov008_021cd48c(void) {
    if (data_ov008_021d0500 == NULL) {
        return;
    }
    OV008_FREE(data_ov008_021d0500, Ov008Mgr *, (func_ov008_021cd584(p_), func_0204b420((u8 *)p_ + 8), func_0203de1c(p_)));
}

void func_ov008_021cd500(Ov008Mgr *m) {
    m->unk_00 = 0;
    m->unk_04 = 1;
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
            void *p = m->unk_f8;
            if (p != NULL) {
                VOBJ(p, 4)->v0c();
                OV008_FREE_M(FLD(void *, p, 0x50));
                FLD(void *, p, 4) = &data_0208b318;
                VOBJ(p, 4)->v0c();
                func_0203de1c(p);
            }
            m->unk_f8 = NULL;
        }
        data_02097dd0->cur = saved;
    }
    OV008_FREE_D(m->unk_c4, func_ov000_0218ea20);
    OV008_FREE_D(m->unk_cc, func_ov000_0218ea20);
    OV008_FREE_V(*(Ov008V **)&m->unk_d4, v04);
    OV008_FREE_V(*(Ov008V **)&m->unk_dc, v04);
    OV008_FREE_V(*(Ov008V **)&m->unk_e4, v04);
    OV008_FREE(m->unk_f4, void *, (VOBJ(p_, 4)->v0c(), FLD(void *, p_, 4) = &data_0208b318, VOBJ(p_, 4)->v0c(), func_0203de1c(p_)));
    OV008_FREE_V(*(Ov008V **)&m->unk_fc, v04);
    OV008_FREE_V(*(Ov008V **)&m->unk_100, v04);
    OV008_FREE_V(*(Ov008V **)&m->unk_104, v04);
    OV008_FREE_V(*(Ov008V **)&m->unk_10c, v04);
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
void func_020359d0(void *a, int b, int c);
BOOL func_02035b90(void *a, int b);
void *func_ov000_0218e9c4(void *p);
BOOL func_ov000_0218f110(void *p);
void func_0201e520(void *dst, const void *src);
void func_0201e78c(void *dst, const void *src);
void func_0206e900(char *dst, const char *src);
void func_0205a6a0(void *p);
void func_0205a840(void *p, const char *a, const char *b);
BOOL func_0205a9c8(void *p);
void func_ov000_0214bb80(void);
void func_ov000_0214c1ac(void);
BOOL func_ov000_0214bc6c(void);
BOOL func_ov000_0214c270(void);

Ov008V *func_ov008_021cdab4(Ov008V *self) {
    FLD(void *, self, 0) = &data_ov000_021caec8;
    self->v2c();
    FLD(void *, self, 0) = &data_ov000_021cac60;
    self->v2c();
    func_0203de1c(self);
    return self;
}

}

static inline void Ov008_SetNameA(void *p, const char *a, const char *b) {
    func_0201e520((u8 *)p + 0x10, a);
    func_0201e520((u8 *)p + 0x30, b);
    FLD(u8, p, 3) |= 2;
}

static inline void Ov008_SetNameB(void *p, const char *a, const char *b) {
    func_0201e520((u8 *)p + 0x4c, a);
    func_0201e520((u8 *)p + 0x6c, b);
    FLD(u8, p, 3) |= 4;
}

static inline void *Ov008_NewMsg(void) {
    void *p = func_0203dd9c(0x138);
    if (p != NULL) {
        p = func_ov000_0218e9c4(p);
    }
    return p;
}

static inline Ov008V *Ov008_NewText(void) {
    Ov008V *p = (Ov008V *)func_0203dd9c(0x4c);
    if (p != NULL) {
        FLD(void *, p, 0) = &data_0208b318;
        p->v08();
    }
    return p;
}

extern "C" {

}
