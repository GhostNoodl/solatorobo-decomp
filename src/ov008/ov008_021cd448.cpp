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

void func_ov008_021cd448(void) {
    Ov008Mgr *p;
    if (gOv008Mgr != NULL) {
        return;
    }
    p = (Ov008Mgr *)Heap_Alloc(0x120);
    if (p != NULL) {
        Camera_Ctor(&p->cam);
        func_ov008_021cd500(p);
    }
    gOv008Mgr = p;
}

void Ov008Mgr_Delete(void) {
    if (gOv008Mgr == NULL) {
        return;
    }
    OV008_FREE(gOv008Mgr, Ov008Mgr *, (func_ov008_021cd584(p_), func_0204b420(&p_->cam), Heap_Free(p_)));
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
    m->caption = NULL;
    m->panel = NULL;
    m->unk_fc = NULL;
    m->menu = NULL;
    m->dialog = NULL;
    m->sel = NULL;
    m->talk = NULL;
    m->unk_110 = 0xffff;
    m->unk_112 = 0xffff;
    m->unk_114 = 0;
    m->unk_118 = 0;
    m->unk_11c = 0x80000;
}

void func_ov008_021cd584(Ov008Mgr *m) {
    OV008_FREE_D(m->unk_c8, Model0218fe1c_FreeAnims);
    OV008_FREE_D(m->unk_d0, Model0218fe1c_FreeAnims);
    OV008_FREE_M(m->unk_d8);
    OV008_FREE_M(m->unk_e0);
    OV008_FREE_M(m->unk_e8);
    OV008_FREE_M(m->unk_ec);
    OV008_FREE_M(m->unk_f0);
    {
        void *saved = gSysState->cur;
        gSysState->cur = gSysState->heapHi;
        if (m->panel != NULL) {
            Ov008Panel *p = m->panel;
            if (p != NULL) {
                p->pic.v0c();
                OV008_FREE_M(p->sprite);
                OV008_SET_VT(&p->pic, &ResHandle_vtbl);
                p->pic.v0c();
                Heap_Free(p);
            }
            m->panel = NULL;
        }
        gSysState->cur = saved;
    }
    OV008_FREE_D(m->unk_c4, ResSet_ReleaseAll);
    OV008_FREE_D(m->unk_cc, ResSet_ReleaseAll);
    OV008_FREE_V(m->unk_d4, v04);
    OV008_FREE_V(m->unk_dc, v04);
    OV008_FREE_V(m->unk_e4, v04);
    OV008_FREE(m->caption, Ov008Caption *, (p_->pic.v0c(), OV008_SET_VT(&p_->pic, &ResHandle_vtbl), p_->pic.v0c(), Heap_Free(p_)));
    OV008_FREE_V(m->unk_fc, v04);
    OV008_FREE_V(m->menu, v04);
    OV008_FREE_V(m->dialog, v04);
    OV008_FREE_V(m->talk, v04);
    ResMgr_ReleaseByName(gResMgr, data_0208cca0, 7, 0);
    ResMgr_ReleaseByName(gResMgr, data_0208cc94, 7, 0);
    func_ov000_0214bc10();
    func_ov000_0214c210();
}

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

Ov008V *Ov008Menu_DtorDelete(Ov008V *self) {
    OV008_SET_VT(self, &UiList_vtbl);
    self->v2c();
    OV008_SET_VT(self, &UiObj_vtbl);
    self->v2c();
    Heap_Free(self);
    return self;
}

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

}
