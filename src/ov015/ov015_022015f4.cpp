#include "ov015/ov015.h"

namespace Dup { extern "C" Ov015Stat data_ov015_0221332c; }

extern "C" {

extern char data_ov015_022128c1[];
s32 func_02035b90(void *a, int b);
extern Ov015Shared *data_ov015_02213368;
extern Ov015Globals data_ov015_02213320;
extern u8 data_ov015_0221291c[];
extern u8 data_ov015_02213198[];
extern u8 data_ov015_0221290c[];
extern u8 data_ov015_0221295c[];
void *func_0204b370(void *p);
u8 *func_02070744(u16 id);
void func_ov015_021fce94(Ov015CamPair *self);
void func_ov015_02210b3c(u8 *self);
s32 func_ov015_02211160(u8 *self, u16 *out, u32 n);
void func_ov015_02211890(u8 *self, u16 id, s32 mode);
void func_ov015_02209024(u8 *self, u16 a, const void *src);
void *func_ov015_02209114(u8 *self);
void func_ov015_02209364(u8 *self);

BOOL func_ov015_022015f4(void) {
    return func_02035b90(data_ov015_022128c1, 7) != 0 ? TRUE : FALSE;
}

BOOL func_ov015_02201618(u8 *self) {
    u16 ids[4];
    u8 *o;
    Ov015List *l;
    u32 n;
    u32 i;
    o = (u8 *)func_0203dd9c(0x1a0);
    if (o != NULL) {
        SET_VT(o, data_ov015_0221291c);
        func_0204b370(o + 0x4);
        func_0204b370(o + 0xc0);
        FLD(s32, o, 0x17c) = 1;
        FLD(s32, o, 0x180) = 0;
        FLD(s32, o, 0x184) = 0;
        FLD(s32, o, 0x188) = 0;
        FLD(s32, o, 0x18c) = 0;
        FLD(s32, o, 0x190) = 0;
        FLD(s32, o, 0x194) = 0;
        FLD(s32, o, 0x198) = 0;
        FLD(s32, o, 0x19c) = 0;
    }
    FLD(u8 *, self, 0x24) = o;
    func_ov015_021fce94((Ov015CamPair *)o);
    if ((u32)(FLD(s32, data_ov015_02213320.unk_00, 0x4) - 1) <= 1) {
        u8 *p = (u8 *)func_0203dd9c(0x14);
        if (p != NULL) {
            SET_VT(p, data_ov015_02213198);
            func_ov015_02210b3c(p);
        }
        FLD(u8 *, self, 0x90) = p;
    }
    l = (Ov015List *)func_0203dd9c(0x10);
    if (l != NULL) {
        SET_VT(l, data_ov015_0221290c);
        l->head = NULL;
        l->tail = NULL;
        l->count = 0;
    }
    FLD(Ov015List *, self, 0x1c) = l;
    n = func_ov015_02211160((u8 *)data_ov015_02213368, ids, 3);
    func_ov015_02211890(self + 0x94, FLD(u16, data_ov015_02213368, 0x8), FLD(u16, FLD(u8 *, self, 0x18), 0xd48));
    for (i = 0; i < n; i++) {
        u16 id = ids[i];
        u8 *def = func_02070744(id);
        u8 *e = (u8 *)func_0203dd9c(0x5b0);
        Ov015List *L;
        Ov015Node *nd;
        if (e != NULL) e = (u8 *)func_ov015_02209114(e);
        FLD(u16, e, 0x4) = id;
        func_ov015_02209024(e + 0xc0, FLD(u16, e, 0x4), def);
        FLD(s32, e, 0xe0) = FLD(s32, self, 0xb4);
        FLD(s32, e, 0xe4) = FLD(s32, self, 0xb8);
        func_ov015_02209364(e);
        L = FLD(Ov015List *, self, 0x1c);
        nd = (Ov015Node *)func_0203dd9c(0x10);
        if (nd != NULL) {
            SET_VT(nd, data_ov015_0221295c);
            nd->key = (s32)e;
            nd->prev = NULL;
            nd->next = NULL;
        }
        if (L->head == NULL) {
            L->head = nd;
            L->tail = nd;
        } else {
            L->head->prev = nd;
            nd->next = L->head;
            L->head = nd;
        }
        L->count++;
    }
    FLD(s32, self, 0xc) = 10;
    {
        Ov015Pad *pad = data_02097e48;
        if (pad->b3) {
            pad->unk_06 = 0x8000;
            pad->unk_08 = 0x1e;
            pad->unk_02 = 0;
        }
    }
    return TRUE;
}

extern const s16 FX_SinCosTable_[];
extern u8 *data_02097d48;
extern void *data_02097e4c;
extern char data_ov015_022128ab[];
extern char data_ov015_02212899[];
extern char data_ov015_0221289f[];
extern char data_ov015_022128a5[];
extern s32 data_ov015_02213328;
extern u8 *data_0214a424;
void func_0203cb78(s32 a, s32 b, s32 c);
Ov015V *func_ov015_021fa6d0(void);
void func_ov015_021fa71c(Ov015Fade *self, s32 c, u16 d);
void func_ov015_021fa73c(Ov015Fade *self, s32 c, u16 d);
BOOL func_ov015_022078bc(void *p);
s32 func_ov000_0218f110(void *a);
BOOL func_ov015_0220947c(u8 *self);
void func_0206e900(char *buf, const char *name);
void *func_020359d0(void *a, int b, int c);
int func_ov015_02210bd8(u8 *self);
BOOL func_ov015_02207adc(u8 *self);
BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
BOOL func_ov015_02209500(u8 *self);
s32 func_ov015_021fb474(u8 *self);
BOOL func_ov015_02210c28(void);
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
void func_02049de8(void *a, s32 b);
void func_ov000_02190a80(void *a, s32 b);
s32 func_ov015_02210c30(u8 *self, Ov015Stat *a, s32 b);
BOOL func_ov015_021ff4a0(u8 *self, u8 *a, u8 *b, Ov015List *c, u8 *d);
BOOL func_ov015_02200204(u8 *self, u8 *a, u8 *b, u8 *c, u8 *d);
BOOL func_ov015_021fb5d4(u8 *self);
void func_ov015_0220101c(u8 *self);
void func_020656b4(void *p);
BOOL func_ov015_0220f568(u8 *self);

static inline BOOL Ov015_SysB4(void) {
    return ((Ov015SysA30 *)(data_02097d48 + 0xa30))->b4 ? TRUE : FALSE;
}

static inline void Ov015_CamFovy(Ov015Cam *c) {
    u16 idx;
    c->fovy = (u16)(((s64)c->fovyDeg * 0xb60b60b60bLL + 0x80000000000LL) >> 44);
    idx = (u16)(c->fovy >> 1);
    c->fovySin = FX_SinCosTable_[(idx >> 4) * 2];
    c->fovyCos = FX_SinCosTable_[(idx >> 4) * 2 + 1];
    c->unk_3e = 1;
}

static inline void Ov015_CamUpdate(u8 *self) {
    if (Ov015_SysB4()) {
        Ov015CamPair *cp = FLD(Ov015CamPair *, self, 0x24);
        Ov015_CamFovy(&cp->cam0);
        VCALL(&cp->cam0)->v00();
    } else {
        Ov015CamPair *cp = FLD(Ov015CamPair *, self, 0x24);
        Ov015_CamFovy(&cp->cam1);
        VCALL(&cp->cam1)->v00();
    }
}

static inline void Ov015_BgmFadeTo(u16 id) {
    Ov015Bgm *p = (Ov015Bgm *)data_02097e48;
    if (p->active) {
        if (p->unk6 != 0xffff || p->unk4 != id) {
            if (p->unk2 != 10 && p->unk2 != 0) {
                if (p->unk6 != 0xffff) {
                    func_0204aab0(p);
                }
                p->unk2 = 1;
            } else {
                p->unk2 = 0;
            }
            p->unk6 = id;
            p->unk8 = 10;
        }
    }
}

static inline void Ov015_ModelsReset(u8 *p) {
    FLD(s32, p, 0x1b4) = 0;
    FLD(s32, p, 0x1b8) = 0;
    FLD(s32, p, 0x1bc) = 0;
    func_ov000_02190a80(p + 0x13c, 0x800);
    FLD(s32, p, 0x3d4) = 0;
    FLD(s32, p, 0x3d8) = 0x1000;
    FLD(s32, p, 0x3dc) = 0;
    func_ov000_02190a80(p + 0x35c, 0x800);
    FLD(s32, p, 0x5f4) = 0;
    FLD(s32, p, 0x5f8) = 0x23333;
    FLD(s32, p, 0x5fc) = 0x4cd;
    func_ov000_02190a80(p + 0x57c, 0x400);
}

typedef enum { OV015_SYS_MODE_2 = 2 } Ov015SysMode;

BOOL func_ov015_0220182c(u8 *self) {
    BOOL ret = TRUE;
    bool a = true;
    switch (FLD(s32, self, 0xc)) {
    case 0:
        FLD(s32, self, 0xc) = 10;
    case 10: {
        u8 *sys = data_02097d48;
        if (FLD(s32, sys, 0) == 1) {
            Ov015SysMode v = OV015_SYS_MODE_2;
            FLD(s32, sys, 4) = v;
            func_0203cb78(0x1000, 0, v - 3);
        }
        func_ov015_021fa73c((Ov015Fade *)func_ov015_021fa6d0(), 0x1000, 0);
        FLD(s32, self, 0xc) = 0x14;
        break;
    }
    case 0x14: {
        Ov015Node *n;
        bool a;
        u8 *q;
        u8 *p;
        bool d;
        bool c;
        bool b;
        char buf[0x20];
        if (!(func_ov015_022078bc(FLD(void *, self, 0x18)) & 1)) {
            a = false;
        } else {
            a = true;
        }
        p = FLD(u8 *, self, 0x20);
        b = true;
        if (FLD(s16, p, 0x4) >= 0 && !func_ov000_0218f110(p + 0x4)) {
            b = false;
        }
        if (FLD(s16, p, 0x224) >= 0 && !func_ov000_0218f110(p + 0x224)) {
            b = false;
        }
        if (FLD(s16, p, 0x444) >= 0 && !func_ov000_0218f110(p + 0x444)) {
            b = false;
        }
        b = a & b;
        c = true;
        for (n = FLD(Ov015List *, self, 0x1c)->head; n != NULL; n = n->next) {
            c &= func_ov015_0220947c((u8 *)n->key);
        }
        c = b & c;
        q = FLD(u8 *, self, 0x28);
        d = false;
        func_0206e900(buf, data_ov015_022128ab);
        switch (FLD(s32, q, 4)) {
        case 0:
            func_020359d0(buf, 7, 0);
            FLD(s32, q, 4) = 10;
        case 10:
            if (func_02035b90(buf, 7) == 0) {
                break;
            }
            FLD(s32, q, 4) = 0x1e;
        case 0x1e:
            FLD(s32, q, 4) = 0x1e;
            d = true;
            break;
        }
        d = c & d;
        if (FLD(u8 *, self, 0x90) != NULL) {
            d &= func_ov015_02210bd8(FLD(u8 *, self, 0x90));
        }
        if (d) {
            FLD(s32, self, 0xc) = 0x1e;
        }
        break;
    }
    case 0x1e: {
        u8 *p;
        Ov015Node *n;
        func_ov015_02207adc(FLD(u8 *, self, 0x18));
        p = FLD(u8 *, self, 0x20);
        func_ov000_0218ffdc(p + 0x13c, p + 0x4, 0, 1);
        func_ov000_02190cb0(p + 0x13c, data_ov015_02212899, 0x1000, 0);
        func_ov000_021915a0(p + 0x13c);
        ((Ov015AnimFlags *)(p + 0x1fe))->b0 = 1;
        func_ov000_0218ffdc(p + 0x35c, p + 0x224, 0, 1);
        func_ov000_02190cb0(p + 0x35c, data_ov015_0221289f, 0x1000, 0);
        func_ov000_021915a0(p + 0x35c);
        ((Ov015AnimFlags *)(p + 0x41e))->b0 = 1;
        func_ov000_0218ffdc(p + 0x57c, p + 0x444, 0, 1);
        func_ov000_02190cb0(p + 0x57c, data_ov015_022128a5, 0x1000, 0);
        func_ov000_021915a0(p + 0x57c);
        ((Ov015AnimFlags *)(p + 0x63e))->b0 = 1;
        for (n = FLD(Ov015List *, self, 0x1c)->head; n != NULL; n = n->next) {
            func_ov015_02209500((u8 *)n->key);
        }
        func_ov015_021fb474(FLD(u8 *, self, 0x28));
        if (FLD(u8 *, self, 0x90) != NULL) {
            func_ov015_02210c28();
        }
        FLD(u8, data_0214a420, 0x10) = 1;
        func_ov015_021fa71c((Ov015Fade *)func_ov015_021fa6d0(), 0x1e000, 0);
        FLD(s32, self, 0xc) = 0x28;
        func_02049a48(data_02097e4c, 0x4f, -1, -1, -1);
        Ov015_BgmFadeTo(0x23);
        break;
    }
    case 0x28:
        Ov015_ModelsReset(FLD(u8 *, self, 0x20));
        if (data_ov015_02213328 == 0) {
            func_02049a48(data_02097e4c, 0x3e, -1, -1, -1);
        }
        {
        u8 *m = FLD(u8 *, self, 0x90);
        data_ov015_02213328 = (data_ov015_02213328 + 1) & 0xff;
        if (m != NULL) {
            if (func_ov015_02210c30(m, &data_ov015_0221332c, 0x28)) {
                FLD(u8, self, 0x3c) = 1;
            } else {
                FLD(u8, self, 0x3c) = 0;
            }
        }
        }
        if (!func_ov015_021ff4a0(self + 0x30, FLD(u8 *, self, 0x18), FLD(u8 *, self, 0x24), FLD(Ov015List *, self, 0x1c), self + 0x94)) {
            FLD(s32, self, 0xc) = 0x32;
            func_02049de8(data_02097e4c, 0x4f);
        }
        {
        Ov015CamPair *cp = FLD(Ov015CamPair *, self, 0x24);
        if (Ov015_SysB4()) {
            Ov015_CamFovy(&cp->cam0);
            VCALL(&cp->cam0)->v00();
        } else {
            Ov015_CamFovy(&cp->cam1);
            VCALL(&cp->cam1)->v00();
        }
        }
        break;
    case 0x32:
        Ov015_ModelsReset(FLD(u8 *, self, 0x20));
        if (FLD(u8 *, self, 0x90) == NULL || FLD(s32, self, 0x64) < 2 ||
            !func_ov015_02210c30(FLD(u8 *, self, 0x90), &data_ov015_0221332c, 0x32)) {
            func_ov015_021fb5d4(FLD(u8 *, self, 0x28));
            if (!func_ov015_02200204(self + 0x5c, FLD(u8 *, self, 0x18), (u8 *)FLD(Ov015List *, self, 0x1c)->head->key,
                                     FLD(u8 *, self, 0x24), self + 0x94)) {
                FLD(s32, self, 0xc) = 0x3c;
                func_ov015_021fa73c((Ov015Fade *)func_ov015_021fa6d0(), 0x1e000, 0x7fff);
                FLD(s32, data_ov015_02213320.unk_00, 8) = Dup::data_ov015_0221332c.unk_30;
                if (Dup::data_ov015_0221332c.unk_30 == 2) {
                    func_ov015_021fa71c((Ov015Fade *)func_ov015_021fa6d0(), 0x1000, 0x7fff);
                    FLD(s32, self, 0xc) = 0x50;
                }
            }
        }
        Ov015_CamUpdate(self);
        break;
    case 0x3c: {
        Ov015Fade *f;
        Ov015_CamUpdate(self);
        f = (Ov015Fade *)func_ov015_021fa6d0();
        if (f->unk_14 < f->unk_0c) {
            break;
        }
        FLD(s32, self, 0xc) = 0x46;
        {
            Ov015Pad *pad = data_02097e48;
            if (pad->b3) {
                pad->unk_06 = 0x8000;
                pad->unk_08 = 0x1e;
                pad->unk_02 = 0;
            }
        }
        func_ov015_0220101c(self);
        func_020656b4(data_0214a420);
        func_ov015_021fa71c((Ov015Fade *)func_ov015_021fa6d0(), 0x1000, 0x7fff);
        {
            u32 v = FLD(u16, data_0214a424, 0x61c) + 1;
            if (v >= 1000) {
                v = 1000;
            }
            FLD(u16, data_0214a424, 0x61c) = v;
        }
        break;
    }
    case 0x46:
        if (!func_ov015_0220f568(FLD(u8 *, self, 0x2c))) {
            FLD(s32, self, 0xc) = 0x50;
        }
        break;
    case 0x50:
        FLD(s32, self, 0xc) = -1;
        ret = FALSE;
        break;
    default:
        ret = FALSE;
        break;
    }
    return ret;
}

}
