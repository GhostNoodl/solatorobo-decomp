#include "ov008/ov008.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Res/ResArc.h"
#include "Main/Res/ArcName.h"

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

extern Ov008Fade gFadeState;
extern char data_ov008_021d04f4[];
extern void *gMsgRes;
extern void *UiList_vtbl;
extern void *Ov000Vt_021cb1b0_vtbl;
extern void *Ov000Vt_021cb0b8_vtbl;
extern void *gSndMgr;
void Ov008WorldMap_LoadRes(Ov008Mgr *m);
BOOL Ov008WorldMap_IsResReady(Ov008Mgr *m);
void Ov008WorldMap_Setup(Ov008Mgr *m);
void Ov008WorldMap_BuildMenu(Ov008Mgr *m);
void Ov008WorldMap_UpdateCaption(Ov008Mgr *m);
void Ov008Caption_Update(Ov008Caption *p);
BOOL Ov008WorldMap_DialogOnDecide(void);
void GfxSys_StartFadeIn(s32 a, int b, int c);
void GfxSys_StartFadeOut(int a, int b, int c);
void *MsgRes_GetLines(void *a, u16 b, s32 *c, int d);
void func_ov000_0214c6b4(void *a, s32 b, void *c, int d);
u16 func_02061d54(s32 a);
s32 MsgRes_GetString(void *p, s32 id);
void *SndMgr_PlayVolume(void *a, s32 b, s32 c, s32 d, s32 e);
void TexObj_TickAnim(void *a, int b);
void Model0218fe1c_UpdateAnim(void *a, s32 b);

extern char data_ov008_021d04a7[];
extern void *ResHandle_vtbl;
extern void *UiObj_vtbl;

extern const VecFx32 data_ov008_021d02d0;
extern const VecFx32 data_ov008_021d02dc;
extern const Ov008Rot3 data_ov008_021d02c8;
extern char data_ov008_021d04f0[];
extern char data_ov008_021d04c5[];
extern void *Menu021ca94c_vtbl;
extern void *TextWin_vtbl;
extern Ov008Snd *gSndQueue;

void *Model0218fe1c_Init(void *p);
BOOL Model0218fe1c_SetRes(void *a, void *b, s32 c, s32 d);
BOOL Model0218fe1c_SetAnim(void *a, const char *b, s32 c, s32 d);
void Model0218fe1c_SetLoop(void *a);
Ov008MdlAnm *Model0218fe1c_GetAnimCtrl(void *a, s32 b);
void TexObj_StartAnim(void *a, int b);
void func_02041c18(void *a, void *b);
void TexObj_SetOamFunc(void *a, int b, void *f, int c);
void TexObj_SetAllOamFuncs(void *a, void *f);
BOOL StageRes_Bind(void *p);
s32 SceneResSet_Bind08(void);
void TextWin_Init(TextWin *win);
void SndQueue_Push_0204aab0(void *p);
void Shared_ClearMark(void);
void *func_ov008_021cd26c(void);
void *func_ov008_021cd3dc(void);

}

static inline Ov008Model *Ov008_NewMdl(void) {
    Ov008Model *a = (Ov008Model *)Heap_Alloc(0xe8);
    if (a != NULL) {
        a = (Ov008Model *)Model0218fe1c_Init(a);
    }
    return a;
}

extern "C" {

void Ov008WorldMap_Setup(Ov008Mgr *m) {
    VecFx32 pos = data_ov008_021d02d0;
    VecFx32 tgt = data_ov008_021d02dc;
    Ov008Rot3 rot = data_ov008_021d02c8;
    void *res;
    Model *p;
    Ov008Caption *c;
    Ov008Panel *pn;
    Ov008Talk *t;
    m->cam.eye = pos;
    m->cam.at = tgt;
    m->cam.roll = rot.z;
    m->cam.pitch = rot.x;
    m->cam.yaw = rot.y;
    m->cam.dist = 0x4400;
    m->cam.mode = 1;

    m->unk_c8 = Ov008_NewMdl();
    Model0218fe1c_SetRes(m->unk_c8, m->unk_c4, 0, 1);
    Model0218fe1c_SetAnim(m->unk_c8, data_ov008_021d04f0, 0, 1);
    m->unk_c8->unk_b4 = 0;
    Model0218fe1c_SetLoop(m->unk_c8);
    Model0218fe1c_GetAnimCtrl(m->unk_c8, 0)->unk_112 = 0x400;

    m->unk_d0 = Ov008_NewMdl();
    Model0218fe1c_SetRes(m->unk_d0, m->unk_cc, 0, 1);
    Model0218fe1c_SetAnim(m->unk_d0, data_ov008_021d04f0, 0, 1);
    m->unk_d0->unk_b4 = 0;
    Model0218fe1c_SetLoop(m->unk_d0);
    Model0218fe1c_GetAnimCtrl(m->unk_d0, 0)->unk_112 = 0x400;

    p = (Model *)Heap_Alloc(sizeof(Model));
    if (p != NULL) {
        const char *name = data_ov008_021d04a7;
        if (name) {
            PlttRes_Init_02041218(&p->pltt);
            TexObj_Init(p, name, 0);
        }
    }
    m->unk_d8 = p;
    TexObj_SetRes(m->unk_d8, (void *)m->unk_d4->v10());
    TexObj_SelectImage(m->unk_d8, 2, 0xffff);

    p = (Model *)Heap_Alloc(sizeof(Model));
    if (p != NULL) {
        const char *name = data_ov008_021d04a7;
        if (name) {
            PlttRes_Init_02041218(&p->pltt);
            TexObj_Init(p, name, 0);
        }
    }
    m->unk_e0 = p;
    TexObj_SetRes(m->unk_e0, (void *)m->unk_dc->v10());
    TexObj_SelectImage(m->unk_e0, 0, 0xffff);
    m->unk_e0->unk_150 = -0x1fe66;

    p = (Model *)Heap_Alloc(sizeof(Model));
    if (p != NULL) {
        const char *name = data_ov008_021d04c5;
        if (name) {
            PlttRes_Init_02041218(&p->pltt);
            TexObj_Init(p, name, 0);
        }
    }
    m->unk_e8 = p;
    TexObj_SetRes(m->unk_e8, (void *)m->unk_e4->v10());
    TexObj_SelectImage(m->unk_e8, 2, 0xffff);
    TexObj_SelectImage(m->unk_e8, 0, 0xffff);
    TexObj_StartAnim(m->unk_e8, 0);
    m->unk_e8->unk_085 &= (u8)~4;
    m->unk_e8->unk_085 &= (u8)~1;
    func_02041c18(m->unk_e8, m);
    TexObj_SetOamFunc(m->unk_e8, 2, (void *)func_ov008_021cd26c, 0);

    {
    Model *q;
    res = ResList_FindType2(ResMgr_GetArcList(data_0208cca0), data_0208cb74);
    q = (Model *)Heap_Alloc(sizeof(Model));
    if (q != NULL) {
        const char *file = data_0208cca0;
        const char *nm = data_0208cb74;
        PlttRes_Init_02041218(&q->pltt);
        TexObj_Init(q, (char *)nm, 0);
        STD_CopyString(q->name, (char *)file);
    }
    m->unk_ec = q;
    TexObj_SetRes(q, res);
    m->unk_ec->flags |= 2;
    TexObj_SelectImage(m->unk_ec, 0, 0xd);
    }

    {
    Model *q;
    res = ResList_FindType2(ResMgr_GetArcList(data_0208cc94), data_0208cc88);
    q = (Model *)Heap_Alloc(sizeof(Model));
    if (q != NULL) {
        const char *file = data_0208cc94;
        const char *nm = data_0208cc88;
        PlttRes_Init_02041218(&q->pltt);
        TexObj_Init(q, (char *)nm, 0);
        STD_CopyString(q->name, (char *)file);
    }
    m->unk_f0 = q;
    TexObj_SetRes(q, res);
    m->unk_f0->flags |= 2;
    TexObj_SelectImage(m->unk_f0, 0, 6);
    }
    m->unk_f0->flags |= 0x80000;
    MODEL_FLAGS(m->unk_f0)->alpha = 0x1e;
    TexObj_SetAllOamFuncs(m->unk_f0, (void *)func_ov008_021cd3dc);

    c = (Ov008Caption *)Heap_Alloc(0x54);
    if (c != NULL) {
        OV008_SET_VT(&c->pic, &ResHandle_vtbl);
        c->pic.v08();
        c->state = 0;
        c->pic.v08();
        c->next = 0xffff;
        c->shown = 0xffff;
    }
    m->caption = c;

    pn = (Ov008Panel *)Heap_Alloc(0x6c);
    if (pn != NULL) {
        OV008_SET_VT(&pn->pic, &ResHandle_vtbl);
        pn->pic.v08();
        pn->state = 0;
        pn->pic.v08();
        pn->sprite = 0;
        pn->offset = 0;
        pn->unk_58 = 0;
        pn->unk_5c = 0;
        pn->alpha = 0;
        pn->speed = 0;
        pn->unk_68 = 0;
    }
    m->panel = pn;

    StageRes_Bind(m->unk_fc);
    SceneResSet_Bind08();

    t = (Ov008Talk *)Heap_Alloc(0x21c);
    if (t != NULL) {
        OV008_SET_VT(t, &UiObj_vtbl);
        t->v28();
        OV008_SET_VT(t, &Menu021ca94c_vtbl);
        OV008_SET_VT(&t->win, &TextWin_vtbl);
        TextWin_Init(&t->win);
        OV008_SET_VT(&t->win2, &TextWin_vtbl);
        TextWin_Init(&t->win2);
        t->v28();
    }
    m->talk = t;
    t->v08();
    m->talk->unk_68 = -0x2000;

    {
        Ov008Snd *g = gSndQueue;
        if (g->b0 && !(g->unk_06 == 0xffff && g->unk_04 == 0xc)) {
            if (g->unk_02 != 10 && g->unk_02 != 0) {
                if (g->unk_06 != 0xffff) {
                    SndQueue_Push_0204aab0(g);
                }
                g->unk_02 = 1;
            } else {
                g->unk_02 = 0;
            }
            g->unk_06 = 0xc;
            g->unk_08 = 10;
        }
    }
    gGfxSys->unk_8b0[0] = (u8)(gGfxSys->unk_8b0[0] & ~0x10) | 0x20;
    *(vu16 *)0x4000060 &= 0xcfdf;
    Shared_ClearMark();
}

}
