#pragma pool_strings on
#pragma dont_reuse_strings off
#include "ov007/ov007.h"
#include "nitro/std.h"
#include "Main/Movie/Movie.h"

extern "C" {

#pragma force_active on
void func_ov007_021ccda0(void) {
    Ov007Scene *p = (Ov007Scene *)Heap_Alloc(0x6c);
    if (p != NULL) {
        func_ov007_021cce28(p);
    }
    data_ov007_021cfc60 = p;
}

void func_ov007_021ccdc8(void) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (data_ov007_021cfc60 != NULL) {
        Ov007Scene *p = data_ov007_021cfc60;
        if (p != NULL) {
            func_ov007_021ccec0(p);
            Heap_Free(p);
        }
        data_ov007_021cfc60 = NULL;
    }
    data_02097dd0->cur = saved;
}

#pragma force_active reset

void func_ov007_021cce28(Ov007Scene *s) {
    s32 i;
    s->timer = 0;
    s->mode = 0;
    s->state = 1;
    s->sub = 0;
    s->idx = 0;
    s->pic = NULL;
    s->unk_18 = NULL;
    s->unk_1c = NULL;
    s->unk_20 = NULL;
    s->unk_24 = NULL;
    s->unk_28 = NULL;
    s->unk_2c = NULL;
    s->unk_30 = NULL;
    s->unk_34 = NULL;
    s->unk_38 = NULL;
    s->cam = NULL;
    s->menu = NULL;
    s->unk_4c = 0;
    s->unk_4d = 0;
    s->unk_4e = 0;
    s->unk_4f = 0;
    s->unk_50 = 0;
    s->unk_54 = 0;
    s->unk_58 = 0;
    for (i = 0; i < 2; i++) {
        s->wins[i] = NULL;
    }
    s->unk_64 = 0;
    s->unk_65 = 0x1f;
    s->unk_66 = 0;
    s->player = NULL;
}

void func_ov007_021ccec0(Ov007Scene *s) {
    OV007_FREE_V(s->pic, v04);
    OV007_FREE_V(s->menu, v04);
    OV007_FREE_V(s->player, v04);
    func_ov007_021ccf9c(s);
}

void func_ov007_021ccf9c(Ov007Scene *s) {
    s32 i;
    void *saved;
    s->unk_64 = 0;
    s->unk_4f = 0;
    OV007_FREE_D(s->unk_18, ResSet_ReleaseAll);
    OV007_FREE_D(s->unk_1c, ResSet_ReleaseAll);
    OV007_FREE_D(s->unk_20, ResSet_ReleaseAll);
    OV007_FREE_D(s->unk_24, ResSet_ReleaseAll);
    OV007_FREE_M(s->unk_28);
    OV007_FREE_M(s->unk_2c);
    OV007_FREE_D(s->unk_30, Model0218fe1c_FreeAnims);
    OV007_FREE_D(s->unk_34, Model0218fe1c_FreeAnims);
    OV007_FREE_D(s->unk_38, Model0218fe1c_FreeAnims);
    OV007_PUSH(saved); OV007_DEL_V(s->cam, v08); OV007_POP(saved);
    for (i = 0; i < 2; i++) {
        OV007_PUSH(saved); OV007_DEL_W(s->wins[i]); OV007_POP(saved);
    }
}

s32 func_ov007_021cd270(Ov007Scene *s) {
    Ov007Pic *pic;
    Ov007Player *pl;
    s->timer += 0x1000;
    if (s->player != NULL) {
        if (s->player->v1c() == 0) {
            OV007_FREE_V(s->player, v04);
        } else if (s->player->v0c() == 0) {
            return 1;
        }
    }
    switch (s->state) {
    case 1: {
        s32 m1 = -1;
        data_02097d48->pltt.id = m1;
        GfxSys_SetFadePlanes(0x3f, m1);
        GfxSys_StartFadeOut(0, 1, m1);
        s->state = 2;
        s->sub = 0;
        s->idx = 0;
    }
    case 2:
        switch (s->sub) {
        case 0:
            pic = (Ov007Pic *)Heap_Alloc(0x4c);
            if (pic != NULL) {
                OV007_SET_VT(pic, &data_0208b318);
                pic->v08();
            }
            s->pic = pic;
            pic->unk_44 = 7;
            s->pic->v20("pic/license_en");
            s->sub = 1;
            break;
        case 1:
            if (s->pic->v2c() != 0) {
                s->state = 3;
                s->sub = 0;
                s->idx = 0;
            }
            break;
        }
        break;
    case 3:
        func_ov007_021cd628(s);
        break;
    case 4:
        func_ov007_021cef80(s);
        break;
    case 5:
        func_ov007_021ce038(s);
        break;
    case 7:
        if (s->sub == 0 && func_ov000_02189068(data_ov000_021ccd54)) {
            if (s->player != NULL) {
                s->player->flags |= 0x40000;
                break;
            }
            GfxSys_StartFadeIn(1, 0, 0);
            if (s->player == NULL) {
                pl = (Ov007Player *)Heap_Alloc(0xe8);
                if (pl != NULL) {
                    OV007_SET_VT(pl, &data_ov000_021cac60);
                    pl->v28();
                    OV007_SET_VT(pl, &data_ov000_021cad50);
                    pl->v28();
                }
                s->player = pl;
                s->player->flags |= 0x10000;
                pl = s->player;
                pl->flags |= 0x8;
                pl->unk_48 = 0x14a5;
                pl->unk_54 = 0x1c;
                s->player->flags |= 0x20000;
                s->player->unk_1c = 4;
                s->player->v08();
                Obj0215c1bc_SetText(s->player, 0x8000, (char *)MsgRes_GetString(data_02149ef8, 0x76));
                s->player->posZ = -0x299a;
                s->player->v70();
            }
            s->sub = 1;
        }
        break;
    case 6:
        return 0;
    }
    return 1;
}

void func_ov007_021cd58c(Ov007RankA *task, Ov007Scene *s) {
    u32 b = task->unk_5c->unk_28->unk_24.rank;
    u8 lvl = b & ~0xc0;
    u8 fl = b & 0xc0;
    u8 a;
    u8 c;
    if (lvl > 20) {
        a = 3;
    } else if (lvl > 10) {
        a = 2;
    } else if (fl != 0 && lvl == 10) {
        a = 2;
    } else {
        a = 1;
    }
    if (lvl > 10 || (lvl == 10 && (fl & 0x40))) {
        c = 2;
    } else if (lvl > 0 || (lvl == 0 && (fl & 0x80))) {
        c = 1;
    } else {
        c = 0;
    }
    s->unk_4c = a;
    s->unk_4d = c;
}

}


extern "C" {

void func_ov007_021cd628(Ov007Scene *s) {
    void *saved;
    Ov007V *p;
    Model *m;
    Ov007Menu8 *t;
    Ov007Menu *mn;
    s32 res;
    if (s->menu != NULL) {
        s->menu->v0c();
        if (Ov007_Flag2(s->menu)) {
            OV007_FREE_V(s->menu, v04);
            s->state = 7;
            s->sub = 0;
            s->idx = 0;
            return;
        }
    }
    switch (s->sub) {
    case 1:
        if (!Ov007_FadeIdle() && !Ov007_FadeDone()) {
            return;
        }
        Ov007_FreePage(s);
        ++s->idx;
        s->sub = 2;
        return;
    case 0:
        if (s->mode == 0) {
            s->idx = 0;
            s->unk_4e = 0;
        } else if (s->mode == 1 || s->mode == 2) {
            s->unk_4d = 0;
            s->idx = 3;
        }
    case 2:
        p = (Ov007V *)s->pic->v10();
        if (s->idx >= 3) {
            if (s->idx == 3) {
                s->sub = 8;
                return;
            }
            if (s->idx == 4) {
                if (OS_IsRunOnTwl()) {
                    s->sub = 0xb;
                } else {
                    s->idx++;
                }
                return;
            }
            GfxSys_StartFadeOut(0, 1, -1);
            if (s->unk_4d == 0 || (s->mode == 1 || s->mode == 2)) {
                s->state = 5;
                s->sub = 0;
                s->idx = 0;
                return;
            }
            s->state = 4;
            s->sub = 0;
            s->idx = 0;
            return;
        }
        m = (Model *)Heap_Alloc(sizeof(Model));
        if (m != NULL) {
            res = data_ov007_021cfa50[s->idx].v;
            PlttRes_Init_02041218(&m->pltt);
            TexObj_Init(m, (const char *)res, 0);
        }
        s->unk_28 = m;
        TexObj_SetRes(s->unk_28, ResList_FindType2(p, m->unk_04c));
        s->unk_28->flags |= 2;
        TexObj_SelectImage(s->unk_28, 2, 0xffff);
        if (data_ov007_021cfa54[s->idx].v != 0) {
            m = (Model *)Heap_Alloc(sizeof(Model));
            if (m != NULL) {
                res = data_ov007_021cfa54[s->idx].v;
                PlttRes_Init_02041218(&m->pltt);
                TexObj_Init(m, (const char *)res, 0);
            }
            s->unk_2c = m;
            TexObj_SetRes(s->unk_2c, ResList_FindType2(p, m->unk_04c));
            s->unk_2c->flags |= 2;
            TexObj_SelectImage(s->unk_2c, 0, 0xffff);
        }
        s->sub = 3;
        return;
    case 3:
        if (s->unk_28 != NULL && !Model_IsReady(s->unk_28, 0xffff)) {
            return;
        }
        if (s->unk_2c != NULL && !Model_IsReady(s->unk_2c, 0xffff)) {
            return;
        }
        if (s->unk_4e == 0) {
            GfxSys_StartFadeIn(data_ov007_021cfa58[s->idx].v, 0, -1);
        } else {
            GfxSys_StartFadeIn(0, 0, -1);
        }
        s->unk_4e = 0;
        s->sub = 4;
        return;
    case 4:
        if (!Ov007_FadeIdle()) {
            if (data_ov007_021cfa64[s->idx].v != 1) {
                return;
            }
            if (!(data_02097dc8->trig & 1)) {
                return;
            }
            GfxSys_StartFadeIn(0, 0, -1);
            return;
        }
        s->timer = 0;
        s->sub = 5;
        return;
    case 5: {
        u8 kind = data_ov007_021cfa64[s->idx].v;
        if (kind != 0 && (data_02097dc8->trig & 1)) {
            if (s->timer < 0xf000) {
                return;
            }
            s->unk_4e = 1;
            if (kind == 1) {
                GfxSys_StartFadeOut(0, 1, -1);
                s->timer = 0;
                s->sub = 1;
                return;
            }
            GfxSys_StartFadeOut(data_ov007_021cfa60[s->idx].v, 1, -1);
            s->timer = 0;
            s->sub = 6;
            return;
        }
        if (s->timer < data_ov007_021cfa5c[s->idx].v) {
            return;
        }
        GfxSys_StartFadeOut(data_ov007_021cfa60[s->idx].v, 1, -1);
        s->sub = 6;
        return;
    }
    case 6:
        if (!Ov007_FadeIdle() && !Ov007_FadeDone()) {
            u8 kind = data_ov007_021cfa64[s->idx].v;
            if (kind == 0) {
                return;
            }
            if (!(data_02097dc8->trig & 1)) {
                return;
            }
            if (kind == 1) {
                GfxSys_StartFadeOut(0, 1, -1);
            }
            s->unk_4e = 1;
            return;
        }
        s->timer = 0;
        s->sub = 7;
        return;
    case 7:
        if (s->timer < 0x1e000 && s->unk_4e == 0) {
            if (!(data_02097dc8->trig & 1)) {
                return;
            }
            s->unk_4e = 1;
        }
        s->timer = 0;
        s->sub = 1;
        return;
    case 8:
        if (!func_ov000_02189068(data_ov000_021ccd54)) {
            return;
        }
        GfxSys_StartFadeIn(1, 0, 0);
        TaskHost_Create(8, 3);
        s->sub = 9;
        return;
    case 9:
        t = Task_FindById(8);
        if (t != NULL) {
            t->unk_bc = (void *)func_ov007_021cd58c;
            t->unk_c0 = s;
            s->sub = 10;
            data_02097dd0->unk_31 = 1;
        }
    case 10:
        data_02097dd0->unk_1f = 1;
        if (!Ov007_MenuDone()) {
            return;
        }
        TaskHost_Destroy();
        s->sub = 1;
        data_02097dd0->unk_31 = 0;
        return;
    case 11:
        s->timer = 0;
        mn = (Ov007Menu *)Heap_Alloc(0x58);
        if (mn != NULL) {
            OV007_SET_VT(mn, &data_0208b614);
            mn->v14();
            OV007_SET_VT(mn, &data_0208ca9c);
            mn->v14();
            OV007_SET_VT(mn, &data_0208c994);
            mn->v14();
        }
        s->menu = mn;
        mn->v08();
        s->menu->unk_48.b0 = 1;
        s->sub = 12;
    case 12:
        mn = s->menu;
        if (!Ov007_Flag7(mn)) {
            return;
        }
        if (!Ov007_Closed(mn)) {
            mn->unk_48.b3 = 1;
            if (s->player == NULL) {
                Ov007_NewPlayer(s, 0x6e);
            }
            GfxSys_StartFadeIn(1, 0, 0);
            s->sub = 0xf;
            data_02097dd0->unk_31 = 1;
            data_02097dd0->unk_1f = 1;
        } else {
            s->sub = 1;
        }
        return;
    case 15:
        data_02097dd0->unk_1f = 1;
        if (Ov007_Flag3(s->menu)) {
            return;
        }
    case 16:
        if (s->player != NULL) {
            data_02097dd0->unk_1f = 1;
            if (Ov007_Busy(s->player)) {
                return;
            }
            if (s->timer >= 0x78000) {
                s->player->flags |= 0x40000;
            }
            return;
        }
        s->sub = 1;
        data_02097dd0->unk_31 = 0;
        return;
    }
}

}


extern "C" {

void func_ov007_021cdff0(Ov007Rs *rs) {
    u32 v;
    Ov007RsMat *q;
    q = rs->unk_b0;
    v = q->unk_0c;
    q->unk_0c = (v & ~0x3f000000) | (Gfx3DState_NextPolyId((Gfx3DState *)data_02097d48->unk_8b0) << 24);
}

void func_ov007_021ce020(Ov007Rs *rs) {
    rs->unk_1c = (void *)func_ov007_021cdff0;
    rs->unk_90 = 2;
}

}




struct Ov007Bits16 {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 rest : 10;
};

struct Ov007Tbl3 {
    const char *s[3];
};

struct Ov007SndQ {
    u16 flag0 : 1;
    u16 flag1 : 1;
    u16 flag2 : 1;
    u16 flag3 : 1;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
};

struct Ov007Ce0 {
    u32 unk_000;
    u32 unk_004;
};

struct Ov007MsgQ {
    u8 unk_00[0x10];
    s32 buf[16];
    u8 unk_50[0x40];
    s32 read;
    s32 write;
};

extern "C" {

extern const Ov007Tbl3 data_ov007_021cfbb4;
extern Ov007SndQ *data_02097e48;
extern void *data_02097e4c;
extern void *data_0208ba70;

void *ResSet_Init(void *p);
BOOL ResSet_UpdateLoad(void *p);
void *Camera_Ctor(void *p);
void Camera_SetAnim(void *cam, void *anim);
void *Model0218fe1c_Init(void *p);
BOOL Model0218fe1c_SetRes(void *a, void *b, s32 c, s32 d);
BOOL Model0218fe1c_SetAnim(void *model, const char *name, s32 a, s32 b);
void Model0218fe1c_SetLoop(void *p);
void NNSi_G3dModifyPolygonAttrMask(void *p, s32 a, s32 b);
void TextWin_Init(TextWin *win);
u32 Text_Measure(u32 font, u32 spacing, u32 str, u32 *outW, u32 *outH, BOOL d);
void TextWin_RenderToVram(void *p);
void SndQueue_Push_0204aab0(Ov007SndQ *queue, u16 value);
void *SndMgr_PlayVolume(void *mgr, s32 id, s32 a, s32 b, s32 c);
void func_0204b924(void *p, s32 v);
Ov007MdlAnm *Model0218fe1c_GetAnimCtrl(void *a, s32 b);
void Model0218fe1c_UpdateAnim(void *a, s32 b);
BOOL Model0218fe1c_IsAnimDone(void *model);

}

static inline void Ov007_SetMdl(Ov007Anim *m, const char *dir, const char *name) {
    STD_CopyString(m->mdlDir, dir);
    STD_CopyString(m->mdlName, name);
    m->unk_03 |= 2;
}

static inline void Ov007_SetAnm(Ov007Anim *m, const char *dir, const char *name) {
    STD_CopyString(m->anmDir, dir);
    STD_CopyString(m->anmName, name);
    m->unk_03 |= 4;
}

static inline Ov007Anim *Ov007_NewRes(void) {
    Ov007Anim *m = (Ov007Anim *)Heap_Alloc(0x138);
    if (m != NULL) {
        m = (Ov007Anim *)ResSet_Init(m);
    }
    return m;
}

static inline Ov007Model *Ov007_NewMdl(void) {
    Ov007Model *m = (Ov007Model *)Heap_Alloc(0xe8);
    if (m != NULL) {
        m = (Ov007Model *)Model0218fe1c_Init(m);
    }
    return m;
}

static inline TextWin *Ov007_NewWin(void) {
    TextWin *win = (TextWin *)Heap_Alloc(sizeof(TextWin));
    if (win != NULL) {
        OV007_SET_VT(win, &data_0208ba70);
        TextWin_Init(win);
    }
    return win;
}

static inline TextWin *Ov007_MakeWin(s32 text) {
    TextWin *win = Ov007_NewWin();
    win->font = 8;
    win->str = text;
    win->unk_4c = Text_Measure(win->font, win->spacing, win->str, &win->width, &win->height, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = win->font;
    win->posZ = -0x299a;
    win->flags |= 0x40;
    win->flags |= 0x1000000;
    win->flags |= 0x4;
    TextWin_RenderToVram(win);
    return win;
}

static inline void Ov007_RequestBgm(Ov007SndQ *queue, u16 bgm) {
    if (!queue->flag0) {
        return;
    }
    if (queue->unk_06 == 0xffff && queue->unk_04 == bgm) {
        return;
    }
    if (queue->unk_02 != 10 && queue->unk_02 != 0) {
        if (queue->unk_06 != 0xffff) {
            SndQueue_Push_0204aab0(queue, queue->unk_06);
        }
        queue->unk_02 = 1;
    } else {
        queue->unk_02 = 0;
    }
    queue->unk_06 = bgm;
    queue->unk_08 = 10;
}

static inline void Ov007_StopBgm(Ov007SndQ *queue, u16 fade) {
    if (queue->flag3) {
        queue->unk_06 = 0x8000;
        queue->unk_08 = fade;
        queue->unk_02 = 0;
    }
}

static inline BOOL Ov007_HasMsgN(s32 r, s32 w, s32 id) {
    Ov007MsgQ *q = (Ov007MsgQ *)data_ov000_021ccd54;
    s32 i;
    for (i = r; i != w;) {
        if (q->buf[i] == id) {
            return TRUE;
        }
        if (++i >= 16) {
            i = 0;
        }
    }
    return FALSE;
}

static inline BOOL Ov007_HasMsg(s32 r, s32 w, s32 id) {
    Ov007MsgQ *q = (Ov007MsgQ *)*(volatile u32 *)&data_ov000_021ccd54;
    s32 i;
    for (i = r; i != w;) {
        if (q->buf[i] == id) {
            return TRUE;
        }
        if (++i >= 16) {
            i = 0;
        }
    }
    return FALSE;
}

static inline void Ov007_Go(Ov007Scene *s, s32 idx, s32 kind) {
    s->unk_58 = 0xe10;
    s->unk_54 = 0;
    s->unk_50 = kind;
    s->idx = idx;
    s->sub = 100;
}

static inline void Ov007Cam_SetFovy(Ov007Cam *o) {
    o->fovyIdx = 0xaaa;
    o->fovyDeg = 0xeff1;
    o->fovySin = FX_SinCosTable_[(0x555 >> 4) * 2];
    o->fovyCos = FX_SinCosTable_[(0x555 >> 4) * 2 + 1];
    o->projDirty = 1;
}

static inline void Ov007Cam_SetB(Ov007Cam *o, u8 a, u8 b, u16 c) {
    o->unk_3c = a;
    o->unk_3d = b;
    o->aspect = c;
    o->projDirty = 1;
}

static inline void Ov007Cam_SetC(Ov007Cam *o, s32 v) {
    o->nearClip = v;
    o->projDirty = 1;
}

static inline void Ov007Cam_SetD(Ov007Cam *o, s32 v) {
    o->farClip = v;
    o->projDirty = 1;
}

static inline void Ov007Cam_SetDist(Ov007Cam *o, s32 v) {
    o->dist = v;
}

static inline void Ov007Mdl_SetCb(Ov007Model *m, void *cb) {
    NNS_G3dRenderObjSetInitFunc((NNSG3dRenderObj *)m->unk_24, (NNSG3dSbcCallBackFunc)cb);
    m->unk_c2 = m->unk_c2 & ~0x20;
}

extern "C" {

void func_ov007_021ce038(Ov007Scene *s) {
    char buf[0x20];
    switch (s->sub) {
    case 0: {
        void *m;
        Ov007Pic *p;
        OV007_FREE_V(s->pic, v04);
        LangData_LocalizePath(buf, "pic/title");
        p = (Ov007Pic *)Heap_Alloc(0x4c);
        if (p != NULL) {
            OV007_SET_VT(p, &data_0208b318);
            p->v08();
        }
        s->pic = p;
        p->unk_44 = 7;
        s->pic->v1c(buf);
        s->unk_18 = Ov007_NewRes();
        if (s->unk_4c == 1) {
            Ov007_SetMdl(s->unk_18, "pic/titlemdl", "title1sky00");
            Ov007_SetAnm(s->unk_18, "pic/titlemdl", "title1sky");
        } else if (s->unk_4c == 2) {
            Ov007_SetMdl(s->unk_18, "pic/titlemdl", "title1sky01");
        } else {
            Ov007_SetMdl(s->unk_18, "pic/titlemdl", "title1sky02");
        }
        Ov007_SetAnm(s->unk_18, "pic/titlemdl", "title1sky");
        s->unk_18->unk_00 = 0;
        s->unk_1c = Ov007_NewRes();
        Ov007_SetMdl(s->unk_1c, "pic/titlemdl", "title1asm");
        Ov007_SetAnm(s->unk_1c, "pic/titlemdl", "title1asm");
        s->unk_1c->unk_00 = 0;
        s->unk_20 = Ov007_NewRes();
        Ov007_SetMdl(s->unk_20, "pic/titlemdl", "title1brd");
        Ov007_SetAnm(s->unk_20, "pic/titlemdl", "title1brd");
        s->unk_20->unk_00 = 0;
        s->unk_24 = Ov007_NewRes();
        Ov007_SetAnm(s->unk_24, "pic/titlemdl", "title1cam");
        s->unk_24->unk_00 = 0;
        s->sub = 1;
        break;
    }
    case 1: {
        Ov007Tbl3 tbl;
        Ov007V *p;
        Model *m;
        const char *res;
        if (!s->pic->v2c()) {
            break;
        }
        if (s->unk_18->unk_00 >= 0 && !ResSet_UpdateLoad(s->unk_18)) {
            break;
        }
        if (s->unk_1c->unk_00 >= 0 && !ResSet_UpdateLoad(s->unk_1c)) {
            break;
        }
        if (s->unk_20->unk_00 >= 0 && !ResSet_UpdateLoad(s->unk_20)) {
            break;
        }
        if (s->unk_24->unk_00 >= 0 && !ResSet_UpdateLoad(s->unk_24)) {
            break;
        }
        tbl = data_ov007_021cfbb4;
        p = (Ov007V *)s->pic->v10();
        m = (Model *)Heap_Alloc(sizeof(Model));
        if (m != NULL) {
            res = tbl.s[s->unk_4c - 1];
            PlttRes_Init_02041218(&m->pltt);
            TexObj_Init(m, (const char *)res, 0);
        }
        s->unk_28 = m;
        TexObj_SetRes(s->unk_28, ResList_FindType2(p, m->unk_04c));
        s->unk_28->flags |= 2;
        TexObj_SelectImage(s->unk_28, 2, 0xffff);
        m = (Model *)Heap_Alloc(sizeof(Model));
        if (m != NULL) {
            res = "cepct1cmn00";
            PlttRes_Init_02041218(&m->pltt);
            TexObj_Init(m, (const char *)res, 0);
        }
        s->unk_2c = m;
        TexObj_SetRes(s->unk_2c, ResList_FindType2(p, m->unk_04c));
        s->unk_2c->flags |= 2;
        TexObj_SelectImage(s->unk_2c, 0, 0xffff);
        s->sub = 2;
        break;
    }
    case 2: {
        void *res;
        void *o;
        u8 *k;
        if (!Model_IsReady(s->unk_28, 0xffff)) {
            break;
        }
        if (!Model_IsReady(s->unk_2c, 0xffff)) {
            break;
        }
        res = s->unk_24->unk_48;
        o = Heap_Alloc(0xbc);
        if (o != NULL) {
            o = Camera_Ctor(o);
        }
        s->cam = (Ov007Cam *)o;
        Camera_SetAnim(s->cam, NNS_G3dGetAnmByIdx(*(void **)res, 0));
        Ov007Cam_SetFovy(s->cam);
        Ov007Cam_SetB(s->cam, 4, 3, 0x1555);
        Ov007Cam_SetC(s->cam, 0x2000);
        Ov007Cam_SetD(s->cam, 0x7d0000);
        Ov007Cam_SetDist(s->cam, -0x1000);
        s->unk_30 = Ov007_NewMdl();
        Model0218fe1c_SetRes(s->unk_30, s->unk_18, 0, 1);
        if (s->unk_4c == 3) {
            Model0218fe1c_SetAnim(s->unk_30, "02", 0, 1);
        } else {
            Model0218fe1c_SetAnim(s->unk_30, "00", 0, 1);
        }
        s->unk_30->unk_b4 = 0;
        Model0218fe1c_SetLoop(s->unk_30);
        Ov007Mdl_SetCb(s->unk_30, (void *)func_ov007_021ce020);
        NNSi_G3dModifyPolygonAttrMask(s->unk_30->unk_04, 1, 0x3f000000);
        NNSi_G3dModifyPolygonAttrMask(s->unk_30->unk_04, 1, 0x1f0000);
        s->unk_40 = 0x1000;
        s->unk_34 = Ov007_NewMdl();
        Model0218fe1c_SetRes(s->unk_34, s->unk_1c, 0, 1);
        Model0218fe1c_SetAnim(s->unk_34, "00", 0, 1);
        s->unk_34->unk_b4 = 0;
        Model0218fe1c_SetLoop(s->unk_34);
        NNSi_G3dModifyPolygonAttrMask(s->unk_34->unk_04, 1, 0x3f000000);
        NNSi_G3dModifyPolygonAttrMask(s->unk_34->unk_04, 1, 0x1f0000);
        if (s->unk_4c != 3) {
            s->unk_38 = Ov007_NewMdl();
            Model0218fe1c_SetRes(s->unk_38, s->unk_20, 0, 1);
            s->unk_38->unk_b4 = 0;
            NNSi_G3dModifyPolygonAttrMask(s->unk_38->unk_04, 1, 0x3f000000);
            NNSi_G3dModifyPolygonAttrMask(s->unk_38->unk_04, 1, 0x1f0000);
            s->unk_44 = Rand_UpTo(0x78) + 0x3c;
        }
        {
            void *mgr = data_02149ef8;
            s->wins[0] = Ov007_MakeWin((s32)MsgRes_GetString(mgr, 0x51));
            s->wins[1] = Ov007_MakeWin((s32)MsgRes_GetString(mgr, 0x52));
        }
        GfxSys_StartFadeIn(0x3c000, 0, -1);
        Ov007_RequestBgm(data_02097e48, 3);
        Ov007_Go(s, 4, 1);
        if (s->mode == 2) {
            s->sub = 6;
        }
        break;
    }
    case 100:
        if (Ov007_FadeIdle()) {
            s->unk_4f |= 0x80;
            s->unk_54 += 0x1000;
            if (s->unk_54 >= 0x20000) {
                s->unk_54 = 0x20000;
                s->sub = s->idx;
            }
        }
        break;
    case 4: {
        u16 trg = data_02097dc8->trig;
        BOOL moved;
        if (s->unk_4d != 0) {
            if (--s->unk_58 < 0) {
                s->sub = 8;
                break;
            }
        }
        if (trg & 1) {
            SndMgr_PlayVolume(data_02097e4c, 0x21, -1, -1, -1);
            if (s->unk_64 == 0) {
                Ov007_Go(s, 7, 2);
            } else if (s->unk_64 == 1) {
                Ov007_Go(s, 10, 2);
            } else {
                Ov007_Go(s, 11, 2);
            }
            break;
        }
        moved = FALSE;
        if (data_02097dc8->repeat & 0x80) {
            s->unk_64++;
            if (s->unk_64 >= 2) {
                s->unk_64 = 1;
            } else {
                moved = TRUE;
            }
        } else if (data_02097dc8->repeat & 0x40) {
            s->unk_64--;
            if (s->unk_64 < 0) {
                s->unk_64 = 0;
            } else {
                moved = TRUE;
            }
        }
        if (moved) {
            SndMgr_PlayVolume(data_02097e4c, 0x1d, -1, -1, -1);
            if (s->unk_58 < 0x78) {
                s->unk_58 = 0x78;
            }
        }
        break;
    }
    case 6:
        if (!Ov007_FadeIdle()) {
            break;
        }
    case 7:
        TaskHost_Create(8, 0);
        s->sub = 5;
        break;
    case 8:
        GfxSys_StartFadeOut(0x3c000, 1, -1);
        Ov007_StopBgm(data_02097e48, 0x1e);
        s->sub = 9;
        break;
    case 9:
        if (Ov007_FadeDone()) {
            func_ov007_021ccf9c(s);
            s->state = 4;
            s->sub = 0;
            s->idx = 0;
        }
        break;
    case 10:
        TaskHost_Create(8, 1);
        s->sub = 5;
        break;
    case 11:
        TaskHost_Create(8, 2);
        s->sub = 5;
        break;
    case 5:
        if (Ov007_MenuDone()) {
            TaskHost_Destroy();
            {
            Ov007MsgQ *q0 = (Ov007MsgQ *)data_ov000_021ccd54;
            s32 r = q0->read;
            long w = q0->write;
            if (Ov007_HasMsgN(r, w, 2) || Ov007_HasMsg(r, w, 0x1c) || Ov007_HasMsg(r, w, 0x24) || Ov007_HasMsg(r, w, 0x23)) {
                s->sub = 12;
            } else {
                Ov007_Go(s, 4, 3);
            }
            }
        }
        break;
    case 12:
        GfxSys_StartFadeOut(0x3c000, 1, -1);
        Ov007_StopBgm(data_02097e48, 0x1e);
        s->sub = 13;
        break;
    case 13:
        if (Ov007_FadeDone()) {
            s->state = 6;
            s->sub = 0;
            s->idx = 0;
        }
        break;
    }
    if (s->cam != NULL) {
        func_0204b924(s->cam, 0x1000);
    }
    if (s->unk_30 != NULL) {
        if (s->unk_4c != 3 && !(s->timer & 0x3ffff)) {
            if (Rand_UpTo(100) < 50) {
                s->unk_40 -= 0xcd;
                if (s->unk_40 < 0xb33) {
                    s->unk_40 += 0x19a;
                }
            } else {
                s->unk_40 += 0xcd;
                if (s->unk_40 > 0x1000) {
                    s->unk_40 -= 0x19a;
                }
            }
            {
                s16 v = s->unk_40;
                Model0218fe1c_GetAnimCtrl(s->unk_30, 0)->unk_112 = v;
            }
        }
        Model0218fe1c_UpdateAnim(s->unk_30, 0x1000);
    }
    if (s->unk_34 != NULL) {
        Model0218fe1c_UpdateAnim(s->unk_34, 0x1000);
    }
    if (s->unk_38 == NULL) {
        return;
    }
    if (Model0218fe1c_IsAnimDone(s->unk_38)) {
        if (--s->unk_44 < 0) {
            s32 r = Rand_UpTo(0x1e);
            if (r <= 10) {
                Model0218fe1c_SetAnim(s->unk_38, "00", 0, 1);
            } else if (r <= 20) {
                Model0218fe1c_SetAnim(s->unk_38, "01", 0, 1);
            } else {
                Model0218fe1c_SetAnim(s->unk_38, "02", 0, 1);
            }
            s->unk_44 = Rand_UpTo(300) + 0xb4;
        }
    }
    Model0218fe1c_UpdateAnim(s->unk_38, 0x1000);
}

}


extern "C" {

void Movie_Load(Movie *a, int b, int c, BOOL d);
void Movie_RequestStop(Movie *a);
void Gfx3D_DrawPrimScaled(int a, int b, int c, u32 d);
void func_ov007_021cf474(Ov007Scene *s);

}

static inline s32 Ov007_Choice(Ov007Scene *s) {
    s32 r = -1;
    switch (s->unk_4d) {
    case 1:
        r = 0;
        break;
    case 2:
        r = 1;
        break;
    }
    return r;
}

static inline void Ov007_DrawModel(Model *m) {
    ModelPart *anim;
    ModelRes *res = m->res;
    void *arg;
    ModelPartRes *t;
    if (res == NULL) {
        return;
    }
    anim = NULL;
    if (m->numParts > 0) {
        anim = m->parts;
    }
    if (anim != NULL && (t = anim->res) != NULL) {
        arg = t->tex;
    } else {
        Ov007SprSeq *e = (Ov007SprSeq *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, 0);
        arg = NNS_G2dGetCellDataByIdx(res->texRes, **e->unk_0c);
    }
    TexObj_DrawCell(m, arg, anim, 0);
}

static inline void *Ov007_GetTex(Model *m, ModelRes *res, ModelPart *anim) {
    if (anim != NULL && anim->res != NULL) {
        return anim->res->tex;
    }
    return NNS_G2dGetCellDataByIdx(res->texRes, **((Ov007SprSeq *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, 0))->unk_0c);
}
static inline void Ov007_DrawModel2(Model *m) {
    ModelRes *res = m->res;
    if (res != NULL) {
        ModelPart *anim = 0 >= m->numParts ? NULL : m->parts;
        TexObj_DrawCell(m, Ov007_GetTex(m, res, anim), anim, 0);
    }
}

struct Ov007Vec {
    s32 x;
    s32 y;
    s32 z;
};

static inline void Ov007_SetupView(void) {
    u32 a;
    u32 b;
    Ov007Vec v;
    Gfx3D_SendDL((Gfx3DState *)data_02097d48->unk_8b0, 0);
    a = 0x20000000;
    NNS_G3dGeBufferOP_N(0x2a, &a, 1);
    b = 0x141f00d0;
    NNS_G3dGeBufferOP_N(0x29, &b, 1);
    v.z = -0x3000;
    v.x = 0;
    v.y = 0;
    NNS_G3dGeBufferOP_N(0x1c, (u32 *)&v, 3);
    Gfx3D_DrawPrimScaled(1, 0x100000, 0xc0000, 0x7fff);
}

static inline void Ov007_SetupView1(void) {
    u32 b;
    u32 a;
    Ov007Vec v;
    Gfx3D_SendDL((Gfx3DState *)data_02097d48->unk_8b0, 0);
    a = 0x20000000;
    NNS_G3dGeBufferOP_N(0x2a, &a, 1);
    b = 0x141f00d0;
    NNS_G3dGeBufferOP_N(0x29, &b, 1);
    v.z = -0x3000;
    v.x = 0;
    v.y = 0;
    NNS_G3dGeBufferOP_N(0x1c, (u32 *)&v, 3);
    Gfx3D_DrawPrimScaled(1, 0x100000, 0xc0000, 0x7fff);
}

extern "C" {

void func_ov007_021cef80(Ov007Scene *s) {
    char buf[0x20];
    Ov007Pic *p;
    switch (s->sub) {
    case 0:
        if (Ov007_Choice(s) < 0) {
            s->sub = 3;
            return;
        }
        s->sub = 1;
        return;
    case 1:
        if (!func_02036328()) {
            return;
        }
        OV007_FREE_V(s->pic, v04);
        GfxSys_StartFadeIn(0x1e000, 0, -1);
        Movie_Load(data_02097e3c, Ov007_Choice(s), -1, 0);
        s->sub = 2;
        return;
    case 2:
        if (!Ov007_FadeIdle()) {
            return;
        }
        if (data_02097e3c->state == 0) {
            LangData_LocalizePath(buf, "pic/title");
            p = (Ov007Pic *)Heap_Alloc(0x4c);
            if (p != NULL) {
                OV007_SET_VT(p, &data_0208b318);
                p->v08();
            }
            s->pic = p;
            p->unk_44 = 7;
            s->pic->v20(buf);
            GfxSys_StartFadeOut(0x3c000, 1, -1);
            s->sub = 3;
            return;
        }
        if (!(data_02097dc8->trig & 1)) {
            return;
        }
        Movie_RequestStop(data_02097e3c);
        return;
    case 3:
        if (!Ov007_FadeDone()) {
            return;
        }
        if (s->pic->v2c() != 0) {
            s->state = 5;
            s->sub = 0;
            s->idx = 0;
        }
        return;
    }
}

void func_ov007_021cf1d8(Ov007Scene *s) {
    switch (s->state) {
    case 3:
        if (Ov007_FadeDone()) {
            break;
        }
        if (s->unk_28 != NULL) {
            s->unk_28->unk_150 = -0x3000;
            Ov007_DrawModel(s->unk_28);
        }
        if (s->unk_2c != NULL) {
            s->unk_2c->unk_150 = -0x3000;
            s->unk_2c->flags &= ~0x80000;
            MODEL_FLAGS(s->unk_2c)->alpha = 0x1f;
            Ov007_DrawModel2(s->unk_2c);
            break;
        }
        Ov007_SetupView1();
        break;
    case 5:
        func_ov007_021cf474(s);
        break;
    case 7:
        Ov007_SetupView();
        break;
    }
    if (s->player != NULL) {
        s->player->v20();
    }
}

}
