#include "ov008/ov008.h"

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
void func_ov008_021cdb00(Ov008Mgr *m);
BOOL func_ov008_021cddc8(Ov008Mgr *m);
void func_ov008_021cdebc(Ov008Mgr *m);
void func_ov008_021cfa38(Ov008Mgr *m);
void func_ov008_021cee4c(Ov008Mgr *m);
void func_ov008_021cce38(Ov008Caption *p);
BOOL func_ov008_021cf878(Ov008Menu *self, Ov008Sel *sel);
void GfxSys_StartFadeIn(s32 a, int b, int c);
void GfxSys_StartFadeOut(int a, int b, int c);
void *MsgRes_GetLines(void *a, u16 b, s32 *c, int d);
void func_ov000_0214c6b4(void *a, s32 b, void *c, int d);
u16 func_02061d54(s32 a);
s32 MsgRes_GetString(void *p, s32 id);
void *SndMgr_PlayVolume(void *a, s32 b, s32 c, s32 d, s32 e);
void TexObj_TickAnim(void *a, int b);
void Model0218fe1c_UpdateAnim(void *a, s32 b);
BOOL Model0218fe1c_SetAnim(void *a, const char *b, s32 c, s32 d);
Ov008MdlAnm *Model0218fe1c_GetAnimCtrl(void *a, s32 b);

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

static inline void Ov008Menu_SetPos(Ov008Menu *w, s16 x, s16 y, s16 z) {
    w->posX = x;
    w->posY = y;
    w->posZ = z;
}

static inline BOOL Ov008_Has200(Ov008Talk *p) {
    return p->unk_200 != NULL ? TRUE : FALSE;
}

extern "C" {

s32 func_ov008_021ce518(Ov008Mgr *m) {
    s32 n;
    Ov008Dialog *w;
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
        GfxSys_StartFadeIn(0x8000, 0, -1);
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
            if (m->menu != NULL) {
                m->menu->flags |= 2;
            }
            if (m->talk != NULL) {
                m->talk->flags |= 2;
            }
        }
        if (m->talk != NULL) {
            if (!Ov008_Has200(m->talk)) {
                if (m->unk_110 == 0xffff) {
                    m->menu->flags &= ~4;
                } else {
                    s32 t;
                    void *r = MsgRes_GetLines(m->unk_fc->unk_bc, m->unk_110, &t, 1);
                    func_ov000_0214c6b4(m->talk, t, r, 0x3c);
                    m->menu->flags |= 4;
                    m->unk_110 = 0xffff;
                }
            } else {
                m->menu->flags |= 4;
            }
        }
        n = 0;
        if (m->menu->v1c()) {
            n++;
        }
        if (m->talk != NULL && m->talk->v1c()) {
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
            w = (Ov008Dialog *)Heap_Alloc(0x1e4);
            if (w != NULL) {
                OV008_SET_VT(w, &data_ov000_021cac60);
                w->v28();
                OV008_SET_VT(w, &data_ov000_021caec8);
                w->v28();
                OV008_SET_VT(w, &data_ov000_021cb1b0);
                w->v28();
                OV008_SET_VT(w, &data_ov000_021cb0b8);
                w->v28();
            }
            m->dialog = w;
            m->dialog->text = MsgRes_GetString(res, id);
            m->dialog->owner = m;
            Ov008Menu_SetPos(m->dialog, 0, 0, 0);
            m->dialog->flags |= 0x80000;
            m->dialog->onDecide = (Ov008Cb)func_ov008_021cf878;
            m->dialog->v08();
            m->state = 12;
        }
    case 12:
        if (m->flags.b2) {
            m->dialog->flags |= 2;
        }
        if (m->dialog->v1c()) {
            break;
        }
        if (m->flags.b1) {
            m->flags.b0 = true;
        }
        OV008_FREE_V(m->dialog, v04);
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
        GfxSys_StartFadeOut(0x1e000, 2, -1);
        m->state = 9;
    case 9:
        if (!Ov008_FadeDone(0)) {
            break;
        }
    case 7:
        OV008_FREE_V(m->menu, v04);
        OV008_FREE_V(m->talk, v04);
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
        Model0218fe1c_SetAnim(m->unk_d0, s, 0, 1);
        Model0218fe1c_GetAnimCtrl(m->unk_d0, 0)->unk_112 = 0xb33;
        Model0218fe1c_SetAnim(m->unk_c8, s, 0, 1);
        Model0218fe1c_GetAnimCtrl(m->unk_c8, 0)->unk_112 = 0xb33;
        m->state = 14;
    }
    case 14:
        switch (++m->unk_114) {
        case 11:
            SndMgr_PlayVolume(data_02097e4c, 0x35, -1, -1, -1);
            break;
        case 16:
        case 30:
            SndMgr_PlayVolume(data_02097e4c, 0x32, -1, -1, -1);
            break;
        case 20:
            if (m->panel != NULL) {
                m->panel->unk_68 = 1;
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
            GfxSys_StartFadeOut(0x1e000, 2, -1);
            m->state = 9;
            break;
        }
        }
        break;
    case 5:
        break;
    }
    if (m->unk_e8 != NULL) {
        TexObj_TickAnim(m->unk_e8, 0);
    }
    func_ov008_021cee4c(m);
    if (m->state >= 5) {
        Model0218fe1c_UpdateAnim(m->unk_c8, 0x1000);
        Model0218fe1c_UpdateAnim(m->unk_d0, 0x1000);
    }
    if (m->caption != NULL) {
        func_ov008_021cce38(m->caption);
    }
    return 1;
}

}
