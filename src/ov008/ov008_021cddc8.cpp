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
void STD_CopyString(void *dst, const void *src);
void STD_ConcatenateString(void *dst, const void *src);
void func_0206e900(char *dst, const char *src);
void func_0205a6a0(void *p);
void func_0205a840(void *p, const char *a, const char *b);
BOOL func_0205a9c8(void *p);
void func_ov000_0214bb80(void);
void func_ov000_0214c1ac(void);
BOOL func_ov000_0214bc6c(void);
BOOL func_ov000_0214c270(void);

}

static inline void Ov008_SetNameA(void *p, const char *a, const char *b) {
    STD_CopyString((u8 *)p + 0x10, a);
    STD_CopyString((u8 *)p + 0x30, b);
    FLD(u8, p, 3) |= 2;
}

static inline void Ov008_SetNameB(void *p, const char *a, const char *b) {
    STD_CopyString((u8 *)p + 0x4c, a);
    STD_CopyString((u8 *)p + 0x6c, b);
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

BOOL func_ov008_021cddc8(Ov008Mgr *m) {
    BOOL r = TRUE;
    if (((Ov008V *)m->unk_d4)->v2c() == 0) {
        r = FALSE;
    }
    if (((Ov008V *)m->unk_dc)->v2c() == 0) {
        r = FALSE;
    }
    if (((Ov008V *)m->unk_e4)->v2c() == 0) {
        r = FALSE;
    }
    if (FLD(s16, m->unk_c4, 0) >= 0 && !func_ov000_0218f110(m->unk_c4)) {
        r = FALSE;
    }
    if (FLD(s16, m->unk_cc, 0) >= 0 && !func_ov000_0218f110(m->unk_cc)) {
        r = FALSE;
    }
    if (!func_02035b90(data_0208cca0, 7)) {
        r = FALSE;
    }
    if (!func_02035b90(data_0208cc94, 7)) {
        r = FALSE;
    }
    if (!func_0205a9c8(m->unk_fc)) {
        r = FALSE;
    }
    if (!func_ov000_0214bc6c()) {
        r = FALSE;
    }
    if (!func_ov000_0214c270()) {
        r = FALSE;
    }
    return r;
}

}
