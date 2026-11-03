#include "ov008/ov008.h"
#include "Main/Res/ResArc.h"
#include "Main/Res/ArcName.h"


extern "C" {

extern Ov008Mgr *gOv008Mgr;
void *Camera_Ctor(void *p);
void func_0204b420(void *p);
void func_ov008_021cd500(Ov008Mgr *m);
void func_ov008_021cd584(Ov008Mgr *m);
void func_ov000_0214bc10(void);
void func_ov000_0214c210(void);
extern void *ResHandle_vtbl;

extern void *UiList_vtbl;
extern void *UiObj_vtbl;
extern void *StageRes_vtbl;
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
void *ResSet_Init(void *p);
BOOL ResSet_UpdateLoad(void *p);
void LangData_LocalizePath(char *dst, const char *src);
void StageRes_Init(void *p);
void StageRes_Open(void *p, const char *a, const char *b);
BOOL StageRes_IsAllLoaded(void *p);
void func_ov000_0214bb80(void);
void func_ov000_0214c1ac(void);
BOOL func_ov000_0214bc6c(void);
BOOL func_ov000_0214c270(void);

}

static inline void Ov008_SetNameA(Ov008Anim *p, const char *a, const char *b) {
    STD_CopyString(p->mdlDir, a);
    STD_CopyString(p->mdlName, b);
    p->unk_03 |= 2;
}

static inline void Ov008_SetNameB(Ov008Anim *p, const char *a, const char *b) {
    STD_CopyString(p->anmDir, a);
    STD_CopyString(p->anmName, b);
    p->unk_03 |= 4;
}

static inline Ov008Anim *Ov008_NewMsg(void) {
    Ov008Anim *p = (Ov008Anim *)Heap_Alloc(0x138);
    if (p != NULL) {
        p = (Ov008Anim *)ResSet_Init(p);
    }
    return p;
}

static inline Ov008Pic *Ov008_NewText(void) {
    Ov008Pic *p = (Ov008Pic *)Heap_Alloc(0x4c);
    if (p != NULL) {
        OV008_SET_VT(p, &ResHandle_vtbl);
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
    if (m->unk_c4->unk_00 >= 0 && !ResSet_UpdateLoad(m->unk_c4)) {
        r = FALSE;
    }
    if (m->unk_cc->unk_00 >= 0 && !ResSet_UpdateLoad(m->unk_cc)) {
        r = FALSE;
    }
    if (!ResMgr_IsLoaded(data_0208cca0, 7)) {
        r = FALSE;
    }
    if (!ResMgr_IsLoaded(data_0208cc94, 7)) {
        r = FALSE;
    }
    if (!StageRes_IsAllLoaded(m->unk_fc)) {
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
