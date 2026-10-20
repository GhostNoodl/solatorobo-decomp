#pragma pool_strings on
#pragma dont_reuse_strings off
#include "ov007/ov007.h"

extern "C" {

#pragma force_active on
void func_ov007_021ccda0(void) {
    Ov007Scene *p = (Ov007Scene *)func_0203dd9c(0x6c);
    if (p != NULL) {
        func_ov007_021cce28(p);
    }
    data_ov007_021cfc60 = p;
}

void func_ov007_021ccdc8(void) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (data_ov007_021cfc60 != NULL) {
        Ov007Scene *p = data_ov007_021cfc60;
        if (p != NULL) {
            func_ov007_021ccec0(p);
            func_0203de1c(p);
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
    s->unk_14 = NULL;
    s->unk_18 = NULL;
    s->unk_1c = NULL;
    s->unk_20 = NULL;
    s->unk_24 = NULL;
    s->unk_28 = NULL;
    s->unk_2c = NULL;
    s->unk_30 = NULL;
    s->unk_34 = NULL;
    s->unk_38 = NULL;
    s->unk_3c = NULL;
    s->unk_48 = NULL;
    s->unk_4c = 0;
    s->unk_4d = 0;
    s->unk_4e = 0;
    s->unk_4f = 0;
    s->unk_50 = 0;
    s->unk_54 = 0;
    s->unk_58 = 0;
    for (i = 0; i < 2; i++) {
        s->unk_5c[i] = NULL;
    }
    s->unk_64 = 0;
    s->unk_65 = 0x1f;
    s->unk_66 = 0;
    s->unk_68 = NULL;
}

void func_ov007_021ccec0(Ov007Scene *s) {
    OV007_FREE_V(s->unk_14, v04);
    OV007_FREE_V(s->unk_48, v04);
    OV007_FREE_V(s->unk_68, v04);
    func_ov007_021ccf9c(s);
}

void func_ov007_021ccf9c(Ov007Scene *s) {
    s32 i;
    u32 saved;
    s->unk_64 = 0;
    s->unk_4f = 0;
    OV007_FREE_D(s->unk_18, func_ov000_0218ea20);
    OV007_FREE_D(s->unk_1c, func_ov000_0218ea20);
    OV007_FREE_D(s->unk_20, func_ov000_0218ea20);
    OV007_FREE_D(s->unk_24, func_ov000_0218ea20);
    OV007_FREE_M(s->unk_28);
    OV007_FREE_M(s->unk_2c);
    OV007_FREE_D(s->unk_30, func_ov000_0218fee4);
    OV007_FREE_D(s->unk_34, func_ov000_0218fee4);
    OV007_FREE_D(s->unk_38, func_ov000_0218fee4);
    OV007_PUSH(saved); OV007_DEL_V(s->unk_3c, v08); OV007_POP(saved);
    for (i = 0; i < 2; i++) {
        OV007_PUSH(saved); OV007_DEL_V(s->unk_5c[i], v04); OV007_POP(saved);
    }
}

s32 func_ov007_021cd270(Ov007Scene *s) {
    Ov007V *p;
    s->timer += 0x1000;
    if (s->unk_68 != NULL) {
        if (s->unk_68->v1c() == 0) {
            OV007_FREE_V(s->unk_68, v04);
        } else if (s->unk_68->v0c() == 0) {
            return 1;
        }
    }
    switch (s->state) {
    case 1: {
        s32 m1 = -1;
        FLD(s32, data_02097d48, 0x9e4) = m1;
        func_0203c9e8(0x3f, m1);
        func_0203cc58(0, 1, m1);
        s->state = 2;
        s->sub = 0;
        s->idx = 0;
    }
    case 2:
        switch (s->sub) {
        case 0:
            p = (Ov007V *)func_0203dd9c(0x4c);
            if (p != NULL) {
                FLD(void *, p, 0) = &data_0208b318;
                p->v08();
            }
            s->unk_14 = p;
            FLD(s32, p, 0x44) = 7;
            s->unk_14->v20("pic/license_en");
            s->sub = 1;
            break;
        case 1:
            if (s->unk_14->v2c() != 0) {
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
            if (s->unk_68 != NULL) {
                FLD(u32, s->unk_68, 0xc) |= 0x40000;
                break;
            }
            func_0203cb78(1, 0, 0);
            if (s->unk_68 == NULL) {
                p = (Ov007V *)func_0203dd9c(0xe8);
                if (p != NULL) {
                    FLD(void *, p, 0) = &data_ov000_021cac60;
                    p->v28();
                    FLD(void *, p, 0) = &data_ov000_021cad50;
                    p->v28();
                }
                s->unk_68 = p;
                FLD(u32, s->unk_68, 0xc) |= 0x10000;
                p = s->unk_68;
                FLD(u32, p, 0xc) |= 0x8;
                FLD(u16, p, 0x48) = 0x14a5;
                FLD(s32, p, 0x54) = 0x1c;
                FLD(u32, s->unk_68, 0xc) |= 0x20000;
                FLD(s32, s->unk_68, 0x1c) = 4;
                s->unk_68->v08();
                func_ov000_0215c1bc(s->unk_68, 0x8000, func_0204c0e8(data_02149ef8, 0x76));
                FLD(s16, s->unk_68, 0x68) = -0x299a;
                s->unk_68->v70();
            }
            s->sub = 1;
        }
        break;
    case 6:
        return 0;
    }
    return 1;
}

void func_ov007_021cd58c(void *task, Ov007Scene *s) {
    u32 b = FLD(Ov007Rank, FLD(void *, FLD(void *, task, 0x5c), 0x28), 0x24).rank;
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
    u32 saved;
    Ov007V *p;
    void *m;
    s32 res;
    if (s->unk_48 != NULL) {
        s->unk_48->v0c();
        if (Ov007_Flag2(s->unk_48)) {
            OV007_FREE_V(s->unk_48, v04);
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
        p = (Ov007V *)s->unk_14->v10();
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
            func_0203cc58(0, 1, -1);
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
        m = func_0203dd9c(0x160);
        if (m != NULL) {
            res = data_ov007_021cfa50[s->idx].v;
            func_02041218((u8 *)m + 0x88);
            func_02041440(m, res, 0);
        }
        s->unk_28 = m;
        func_020417e0(s->unk_28, func_02034d88(p, (u8 *)m + 0x4c));
        FLD(u32, s->unk_28, 0x6c) |= 2;
        func_02041d9c(s->unk_28, 2, 0xffff);
        if (data_ov007_021cfa54[s->idx].v != 0) {
            m = func_0203dd9c(0x160);
            if (m != NULL) {
                res = data_ov007_021cfa54[s->idx].v;
                func_02041218((u8 *)m + 0x88);
                func_02041440(m, res, 0);
            }
            s->unk_2c = m;
            func_020417e0(s->unk_2c, func_02034d88(p, (u8 *)m + 0x4c));
            FLD(u32, s->unk_2c, 0x6c) |= 2;
            func_02041d9c(s->unk_2c, 0, 0xffff);
        }
        s->sub = 3;
        return;
    case 3:
        if (s->unk_28 != NULL && !func_02054f10(s->unk_28, 0xffff)) {
            return;
        }
        if (s->unk_2c != NULL && !func_02054f10(s->unk_2c, 0xffff)) {
            return;
        }
        if (s->unk_4e == 0) {
            func_0203cb78(data_ov007_021cfa58[s->idx].v, 0, -1);
        } else {
            func_0203cb78(0, 0, -1);
        }
        s->unk_4e = 0;
        s->sub = 4;
        return;
    case 4:
        if (!Ov007_FadeIdle()) {
            if (data_ov007_021cfa64[s->idx].v != 1) {
                return;
            }
            if (!(data_02097dc8->trg & 1)) {
                return;
            }
            func_0203cb78(0, 0, -1);
            return;
        }
        s->timer = 0;
        s->sub = 5;
        return;
    case 5: {
        u8 kind = data_ov007_021cfa64[s->idx].v;
        if (kind != 0 && (data_02097dc8->trg & 1)) {
            if (s->timer < 0xf000) {
                return;
            }
            s->unk_4e = 1;
            if (kind == 1) {
                func_0203cc58(0, 1, -1);
                s->timer = 0;
                s->sub = 1;
                return;
            }
            func_0203cc58(data_ov007_021cfa60[s->idx].v, 1, -1);
            s->timer = 0;
            s->sub = 6;
            return;
        }
        if (s->timer < data_ov007_021cfa5c[s->idx].v) {
            return;
        }
        func_0203cc58(data_ov007_021cfa60[s->idx].v, 1, -1);
        s->sub = 6;
        return;
    }
    case 6:
        if (!Ov007_FadeIdle() && !Ov007_FadeDone()) {
            u8 kind = data_ov007_021cfa64[s->idx].v;
            if (kind == 0) {
                return;
            }
            if (!(data_02097dc8->trg & 1)) {
                return;
            }
            if (kind == 1) {
                func_0203cc58(0, 1, -1);
            }
            s->unk_4e = 1;
            return;
        }
        s->timer = 0;
        s->sub = 7;
        return;
    case 7:
        if (s->timer < 0x1e000 && s->unk_4e == 0) {
            if (!(data_02097dc8->trg & 1)) {
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
        func_0203cb78(1, 0, 0);
        func_ov000_02180660(8, 3);
        s->sub = 9;
        return;
    case 9:
        p = (Ov007V *)func_ov000_02173610(8);
        if (p != NULL) {
            FLD(void *, p, 0xbc) = (void *)func_ov007_021cd58c;
            FLD(void *, p, 0xc0) = s;
            s->sub = 10;
            FLD(u8, data_02097dd0, 0x31) = 1;
        }
    case 10:
        FLD(u8, data_02097dd0, 0x1f) = 1;
        if (!Ov007_MenuDone()) {
            return;
        }
        func_ov000_02180754();
        s->sub = 1;
        FLD(u8, data_02097dd0, 0x31) = 0;
        return;
    case 11:
        s->timer = 0;
        p = (Ov007V *)func_0203dd9c(0x58);
        if (p != NULL) {
            FLD(void *, p, 0) = &data_0208b614;
            p->v14();
            FLD(void *, p, 0) = &data_0208ca9c;
            p->v14();
            FLD(void *, p, 0) = &data_0208c994;
            p->v14();
        }
        s->unk_48 = p;
        p->v08();
        FLD(Ov007Flags44, s->unk_48, 0x48).b0 = 1;
        s->sub = 12;
    case 12:
        p = s->unk_48;
        if (!Ov007_Flag7(p)) {
            return;
        }
        if (!Ov007_Closed(p)) {
            FLD(Ov007Flags44, p, 0x48).b3 = 1;
            if (s->unk_68 == NULL) {
                Ov007_NewPlayer(s, 0x6e);
            }
            func_0203cb78(1, 0, 0);
            s->sub = 0xf;
            FLD(u8, data_02097dd0, 0x31) = 1;
            FLD(u8, data_02097dd0, 0x1f) = 1;
        } else {
            s->sub = 1;
        }
        return;
    case 15:
        FLD(u8, data_02097dd0, 0x1f) = 1;
        if (Ov007_Flag3(s->unk_48)) {
            return;
        }
    case 16:
        if (s->unk_68 != NULL) {
            FLD(u8, data_02097dd0, 0x1f) = 1;
            if (Ov007_Busy(s->unk_68)) {
                return;
            }
            if (s->timer >= 0x78000) {
                FLD(u32, s->unk_68, 0xc) |= 0x40000;
            }
            return;
        }
        s->sub = 1;
        FLD(u8, data_02097dd0, 0x31) = 0;
        return;
    }
}

}


extern "C" {

void func_ov007_021cdff0(void *task) {
    u32 v;
    void *q;
    q = FLD(void *, task, 0xb0);
    v = FLD(u32, q, 0xc);
    FLD(u32, q, 0xc) = (v & ~0x3f000000) | (func_02043d48(data_02097d48 + 0x8b0) << 24);
}

void func_ov007_021ce020(void *task) {
    FLD(void *, task, 0x1c) = (void *)func_ov007_021cdff0;
    FLD(u8, task, 0x90) = 2;
}

}


extern "C" const s16 FX_SinCosTable_[];


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
extern Ov007Ce0 *data_02097ce0;
extern void *data_0208ba70;

void func_0206e900(char *dst, const char *src);
void STD_CopyString(char *dst, const char *src);
void *func_ov000_0218e9c4(void *p);
BOOL func_ov000_0218f110(void *p);
void *func_0204b370(void *p);
void *NNS_G3dGetAnmByIdx(void *file, s32 index);
void func_0204b8e8(void *cam, void *anim);
void *func_ov000_0218fe1c(void *p);
void func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
void func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
void func_ov000_021915a0(void *p);
void NNS_G3dRenderObjSetInitFunc(void *p, void *cb);
void NNSi_G3dModifyPolygonAttrMask(void *p, s32 a, s32 b);
s32 func_02040498(s32 max);
void func_0204c7d0(void *p);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void func_0204ca70(void *p);
void func_0204aab0(Ov007SndQ *queue, u16 value);
void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
void func_0204b924(void *p, s32 v);
void *func_ov000_02190a30(void *a, s32 b);
void func_ov000_02190a80(void *a, s32 b);
BOOL func_ov000_02191120(void *model);

}

static inline void Ov007_SetMdl(void *m, const char *dir, const char *name) {
    STD_CopyString((char *)m + 0x10, dir);
    STD_CopyString((char *)m + 0x30, name);
    FLD(u8, m, 0x3) |= 2;
}

static inline void Ov007_SetAnm(void *m, const char *dir, const char *name) {
    STD_CopyString((char *)m + 0x4c, dir);
    STD_CopyString((char *)m + 0x6c, name);
    FLD(u8, m, 0x3) |= 4;
}

static inline void *Ov007_NewRes(void) {
    void *m = func_0203dd9c(0x138);
    if (m != NULL) {
        m = func_ov000_0218e9c4(m);
    }
    return m;
}

static inline void *Ov007_NewMdl(void) {
    void *m = func_0203dd9c(0xe8);
    if (m != NULL) {
        m = func_ov000_0218fe1c(m);
    }
    return m;
}

static inline void *Ov007_NewWin(void) {
    void *win = func_0203dd9c(0xb8);
    if (win != NULL) {
        FLD(void *, win, 0) = &data_0208ba70;
        func_0204c7d0(win);
    }
    return win;
}

static inline void *Ov007_MakeWin(s32 text) {
    void *win = Ov007_NewWin();
    FLD(s32, win, 0x28) = 8;
    FLD(s32, win, 0x24) = text;
    FLD(s32, win, 0x4c) = func_0204c4fc(FLD(s32, win, 0x28), FLD(s32, win, 0x38), FLD(s32, win, 0x24), (u8 *)win + 0x44, (u8 *)win + 0x48, FLD(s8, win, 0x37) != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = FLD(s32, win, 0x28);
    FLD(s32, win, 0x70) = -0x299a;
    FLD(u32, win, 0x4) |= 0x40;
    FLD(u32, win, 0x4) |= 0x1000000;
    FLD(u32, win, 0x4) |= 0x4;
    func_0204ca70(win);
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
            func_0204aab0(queue, queue->unk_06);
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

static inline BOOL Ov007_HasMsgP(Ov007MsgQ *q, s32 r, s32 w, s32 id) {
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

static inline void Ov007Cam_SetA(void *o) {
    FLD(u16, o, 0x36) = 0xaaa;
    FLD(s32, o, 0x38) = 0xeff1;
    FLD(s16, o, 0x30) = FX_SinCosTable_[(0x555 >> 4) * 2];
    FLD(s16, o, 0x32) = FX_SinCosTable_[(0x555 >> 4) * 2 + 1];
    FLD(u8, o, 0x3e) = 1;
}

static inline void Ov007Cam_SetB(void *o, u8 a, u8 b, u16 c) {
    FLD(u8, o, 0x3c) = a;
    FLD(u8, o, 0x3d) = b;
    FLD(u16, o, 0x34) = c;
    FLD(u8, o, 0x3e) = 1;
}

static inline void Ov007Cam_SetC(void *o, s32 v) {
    FLD(s32, o, 0x28) = v;
    FLD(u8, o, 0x3e) = 1;
}

static inline void Ov007Cam_SetD(void *o, s32 v) {
    FLD(s32, o, 0x2c) = v;
    FLD(u8, o, 0x3e) = 1;
}

static inline void Ov007Cam_SetE(void *o, s32 v) {
    FLD(s32, o, 0x48) = v;
}

static inline void Ov007Mdl_SetCb(void *m, void *cb) {
    NNS_G3dRenderObjSetInitFunc((u8 *)m + 0x24, cb);
    FLD(u16, m, 0xc2) = FLD(u16, m, 0xc2) & ~0x20;
}

extern "C" {

void func_ov007_021ce038(Ov007Scene *s) {
    char buf[0x20];
    switch (s->sub) {
    case 0: {
        void *m;
        Ov007V *p;
        OV007_FREE_V(s->unk_14, v04);
        func_0206e900(buf, "pic/title");
        p = (Ov007V *)func_0203dd9c(0x4c);
        if (p != NULL) {
            FLD(void *, p, 0) = &data_0208b318;
            p->v08();
        }
        s->unk_14 = p;
        FLD(s32, p, 0x44) = 7;
        s->unk_14->v1c(buf);
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
        FLD(s16, s->unk_18, 0) = 0;
        s->unk_1c = Ov007_NewRes();
        Ov007_SetMdl(s->unk_1c, "pic/titlemdl", "title1asm");
        Ov007_SetAnm(s->unk_1c, "pic/titlemdl", "title1asm");
        FLD(s16, s->unk_1c, 0) = 0;
        s->unk_20 = Ov007_NewRes();
        Ov007_SetMdl(s->unk_20, "pic/titlemdl", "title1brd");
        Ov007_SetAnm(s->unk_20, "pic/titlemdl", "title1brd");
        FLD(s16, s->unk_20, 0) = 0;
        s->unk_24 = Ov007_NewRes();
        Ov007_SetAnm(s->unk_24, "pic/titlemdl", "title1cam");
        FLD(s16, s->unk_24, 0) = 0;
        s->sub = 1;
        break;
    }
    case 1: {
        Ov007Tbl3 tbl;
        Ov007V *p;
        void *m;
        const char *res;
        if (!s->unk_14->v2c()) {
            break;
        }
        if (FLD(s16, s->unk_18, 0) >= 0 && !func_ov000_0218f110(s->unk_18)) {
            break;
        }
        if (FLD(s16, s->unk_1c, 0) >= 0 && !func_ov000_0218f110(s->unk_1c)) {
            break;
        }
        if (FLD(s16, s->unk_20, 0) >= 0 && !func_ov000_0218f110(s->unk_20)) {
            break;
        }
        if (FLD(s16, s->unk_24, 0) >= 0 && !func_ov000_0218f110(s->unk_24)) {
            break;
        }
        tbl = data_ov007_021cfbb4;
        p = (Ov007V *)s->unk_14->v10();
        m = func_0203dd9c(0x160);
        if (m != NULL) {
            res = tbl.s[s->unk_4c - 1];
            func_02041218((u8 *)m + 0x88);
            func_02041440(m, (s32)res, 0);
        }
        s->unk_28 = m;
        func_020417e0(s->unk_28, func_02034d88(p, (u8 *)m + 0x4c));
        FLD(u32, s->unk_28, 0x6c) |= 2;
        func_02041d9c(s->unk_28, 2, 0xffff);
        m = func_0203dd9c(0x160);
        if (m != NULL) {
            res = "cepct1cmn00";
            func_02041218((u8 *)m + 0x88);
            func_02041440(m, (s32)res, 0);
        }
        s->unk_2c = m;
        func_020417e0(s->unk_2c, func_02034d88(p, (u8 *)m + 0x4c));
        FLD(u32, s->unk_2c, 0x6c) |= 2;
        func_02041d9c(s->unk_2c, 0, 0xffff);
        s->sub = 2;
        break;
    }
    case 2: {
        void *res;
        void *o;
        u8 *k;
        if (!func_02054f10(s->unk_28, 0xffff)) {
            break;
        }
        if (!func_02054f10(s->unk_2c, 0xffff)) {
            break;
        }
        res = FLD(void *, s->unk_24, 0x48);
        o = func_0203dd9c(0xbc);
        if (o != NULL) {
            o = func_0204b370(o);
        }
        s->unk_3c = (Ov007V *)o;
        func_0204b8e8(s->unk_3c, NNS_G3dGetAnmByIdx(*(void **)res, 0));
        Ov007Cam_SetA(s->unk_3c);
        Ov007Cam_SetB(s->unk_3c, 4, 3, 0x1555);
        Ov007Cam_SetC(s->unk_3c, 0x2000);
        Ov007Cam_SetD(s->unk_3c, 0x7d0000);
        Ov007Cam_SetE(s->unk_3c, -0x1000);
        s->unk_30 = Ov007_NewMdl();
        func_ov000_0218ffdc(s->unk_30, s->unk_18, 0, 1);
        if (s->unk_4c == 3) {
            func_ov000_02190cb0(s->unk_30, "02", 0, 1);
        } else {
            func_ov000_02190cb0(s->unk_30, "00", 0, 1);
        }
        FLD(u16, s->unk_30, 0xb4) = 0;
        func_ov000_021915a0(s->unk_30);
        Ov007Mdl_SetCb(s->unk_30, (void *)func_ov007_021ce020);
        NNSi_G3dModifyPolygonAttrMask(FLD(void *, s->unk_30, 0x4), 1, 0x3f000000);
        NNSi_G3dModifyPolygonAttrMask(FLD(void *, s->unk_30, 0x4), 1, 0x1f0000);
        FLD(s16, s, 0x40) = 0x1000;
        s->unk_34 = Ov007_NewMdl();
        func_ov000_0218ffdc(s->unk_34, s->unk_1c, 0, 1);
        func_ov000_02190cb0(s->unk_34, "00", 0, 1);
        FLD(u16, s->unk_34, 0xb4) = 0;
        func_ov000_021915a0(s->unk_34);
        NNSi_G3dModifyPolygonAttrMask(FLD(void *, s->unk_34, 0x4), 1, 0x3f000000);
        NNSi_G3dModifyPolygonAttrMask(FLD(void *, s->unk_34, 0x4), 1, 0x1f0000);
        if (s->unk_4c != 3) {
            s->unk_38 = Ov007_NewMdl();
            func_ov000_0218ffdc(s->unk_38, s->unk_20, 0, 1);
            FLD(u16, s->unk_38, 0xb4) = 0;
            NNSi_G3dModifyPolygonAttrMask(FLD(void *, s->unk_38, 0x4), 1, 0x3f000000);
            NNSi_G3dModifyPolygonAttrMask(FLD(void *, s->unk_38, 0x4), 1, 0x1f0000);
            FLD(s32, s, 0x44) = func_02040498(0x78) + 0x3c;
        }
        {
            void *mgr = data_02149ef8;
            s->unk_5c[0] = (Ov007V *)Ov007_MakeWin(func_0204c0e8(mgr, 0x51));
            s->unk_5c[1] = (Ov007V *)Ov007_MakeWin(func_0204c0e8(mgr, 0x52));
        }
        func_0203cb78(0x3c000, 0, -1);
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
        u16 trg = data_02097dc8->trg;
        BOOL moved;
        if (s->unk_4d != 0) {
            if (--s->unk_58 < 0) {
                s->sub = 8;
                break;
            }
        }
        if (trg & 1) {
            func_02049a48(data_02097e4c, 0x21, -1, -1, -1);
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
        if (FLD(u16, data_02097dc8, 0x16) & 0x80) {
            s->unk_64++;
            if (s->unk_64 >= 2) {
                s->unk_64 = 1;
            } else {
                moved = TRUE;
            }
        } else if (FLD(u16, data_02097dc8, 0x16) & 0x40) {
            s->unk_64--;
            if (s->unk_64 < 0) {
                s->unk_64 = 0;
            } else {
                moved = TRUE;
            }
        }
        if (moved) {
            func_02049a48(data_02097e4c, 0x1d, -1, -1, -1);
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
        func_ov000_02180660(8, 0);
        s->sub = 5;
        break;
    case 8:
        func_0203cc58(0x3c000, 1, -1);
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
        func_ov000_02180660(8, 1);
        s->sub = 5;
        break;
    case 11:
        func_ov000_02180660(8, 2);
        s->sub = 5;
        break;
    case 5:
        if (Ov007_MenuDone()) {
            func_ov000_02180754();
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
        func_0203cc58(0x3c000, 1, -1);
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
    if (s->unk_3c != NULL) {
        func_0204b924(s->unk_3c, 0x1000);
    }
    if (s->unk_30 != NULL) {
        if (s->unk_4c != 3 && !(s->timer & 0x3ffff)) {
            if (func_02040498(100) < 50) {
                FLD(s16, s, 0x40) -= 0xcd;
                if (FLD(s16, s, 0x40) < 0xb33) {
                    FLD(s16, s, 0x40) += 0x19a;
                }
            } else {
                FLD(s16, s, 0x40) += 0xcd;
                if (FLD(s16, s, 0x40) > 0x1000) {
                    FLD(s16, s, 0x40) -= 0x19a;
                }
            }
            {
                s16 v = FLD(s16, s, 0x40);
                FLD(s16, func_ov000_02190a30(s->unk_30, 0), 0x112) = v;
            }
        }
        func_ov000_02190a80(s->unk_30, 0x1000);
    }
    if (s->unk_34 != NULL) {
        func_ov000_02190a80(s->unk_34, 0x1000);
    }
    if (s->unk_38 == NULL) {
        return;
    }
    if (func_ov000_02191120(s->unk_38)) {
        if (--FLD(s32, s, 0x44) < 0) {
            s32 r = func_02040498(0x1e);
            if (r <= 10) {
                func_ov000_02190cb0(s->unk_38, "00", 0, 1);
            } else if (r <= 20) {
                func_ov000_02190cb0(s->unk_38, "01", 0, 1);
            } else {
                func_ov000_02190cb0(s->unk_38, "02", 0, 1);
            }
            FLD(s32, s, 0x44) = func_02040498(300) + 0xb4;
        }
    }
    func_ov000_02190a80(s->unk_38, 0x1000);
}

}


extern "C" {

extern void *data_02097e3c;
BOOL func_02036328(void);
void func_020444b0(void *a, s32 b, int c, int d);
void func_02044524(void *a);
void func_0206e900(char *dst, const char *src);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);
void func_02043d20(void *a, int b);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
void func_02043db4(int a, s32 b, s32 c, s32 d);
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

static inline void Ov007_DrawModel(void *m) {
    void *anim;
    void *res = FLD(void *, m, 0x28);
    void *arg;
    void *t;
    if (res == NULL) {
        return;
    }
    anim = NULL;
    if (FLD(s32, m, 0x80) > 0) {
        anim = FLD(void *, m, 0x78);
    }
    if (anim != NULL && (t = FLD(void *, anim, 0x4)) != NULL) {
        arg = FLD(void *, t, 0x30);
    } else {
        void *e = NNS_G2dGetAnimSequenceByIdx(FLD(void *, res, 0xc), 0);
        arg = NNS_G2dGetCellDataByIdx(FLD(void *, res, 0x4), **(u16 **)FLD(void *, e, 0xc));
    }
    func_02042628(m, arg, anim, 0);
}

static inline void *Ov007_GetTex(void *m, void *res, void *anim) {
    if (anim != NULL && FLD(void *, anim, 0x4) != NULL) {
        return FLD(void *, FLD(void *, anim, 0x4), 0x30);
    }
    return NNS_G2dGetCellDataByIdx(FLD(void *, res, 0x4), **(u16 **)FLD(void *, NNS_G2dGetAnimSequenceByIdx(FLD(void *, res, 0xc), 0), 0xc));
}
static inline void Ov007_DrawModel2(void *m) {
    void *res = FLD(void *, m, 0x28);
    if (res != NULL) {
        void *anim = 0 >= FLD(s32, m, 0x80) ? NULL : FLD(void *, m, 0x78);
        func_02042628(m, Ov007_GetTex(m, res, anim), anim, 0);
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
    func_02043d20(data_02097d48 + 0x8b0, 0);
    a = 0x20000000;
    NNS_G3dGeBufferOP_N(0x2a, &a, 1);
    b = 0x141f00d0;
    NNS_G3dGeBufferOP_N(0x29, &b, 1);
    v.z = -0x3000;
    v.x = 0;
    v.y = 0;
    NNS_G3dGeBufferOP_N(0x1c, &v, 3);
    func_02043db4(1, 0x100000, 0xc0000, 0x7fff);
}

static inline void Ov007_SetupView1(void) {
    u32 b;
    u32 a;
    Ov007Vec v;
    func_02043d20(data_02097d48 + 0x8b0, 0);
    a = 0x20000000;
    NNS_G3dGeBufferOP_N(0x2a, &a, 1);
    b = 0x141f00d0;
    NNS_G3dGeBufferOP_N(0x29, &b, 1);
    v.z = -0x3000;
    v.x = 0;
    v.y = 0;
    NNS_G3dGeBufferOP_N(0x1c, &v, 3);
    func_02043db4(1, 0x100000, 0xc0000, 0x7fff);
}

struct Ov007Mdl6c {
    u32 b0 : 2;
    u32 b2 : 5;
    u32 rest : 25;
};

extern "C" {

void func_ov007_021cef80(Ov007Scene *s) {
    char buf[0x20];
    Ov007V *p;
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
        OV007_FREE_V(s->unk_14, v04);
        func_0203cb78(0x1e000, 0, -1);
        func_020444b0(data_02097e3c, Ov007_Choice(s), -1, 0);
        s->sub = 2;
        return;
    case 2:
        if (!Ov007_FadeIdle()) {
            return;
        }
        if (FLD(u8, data_02097e3c, 0x149) == 0) {
            func_0206e900(buf, "pic/title");
            p = (Ov007V *)func_0203dd9c(0x4c);
            if (p != NULL) {
                FLD(void *, p, 0) = &data_0208b318;
                p->v08();
            }
            s->unk_14 = p;
            FLD(s32, p, 0x44) = 7;
            s->unk_14->v20(buf);
            func_0203cc58(0x3c000, 1, -1);
            s->sub = 3;
            return;
        }
        if (!(data_02097dc8->trg & 1)) {
            return;
        }
        func_02044524(data_02097e3c);
        return;
    case 3:
        if (!Ov007_FadeDone()) {
            return;
        }
        if (s->unk_14->v2c() != 0) {
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
            FLD(s32, s->unk_28, 0x150) = -0x3000;
            Ov007_DrawModel(s->unk_28);
        }
        if (s->unk_2c != NULL) {
            FLD(s32, s->unk_2c, 0x150) = -0x3000;
            FLD(u32, s->unk_2c, 0x6c) &= ~0x80000;
            FLD(Ov007Mdl6c, s->unk_2c, 0x6c).b2 = 0x1f;
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
    if (s->unk_68 != NULL) {
        s->unk_68->v20();
    }
}

}
