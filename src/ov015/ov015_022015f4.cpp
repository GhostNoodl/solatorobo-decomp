#include "ov015/ov015.h"

namespace Dup { extern "C" Ov015Stat data_ov015_0221332c; }

extern "C" {

extern char data_ov015_022128c1[];
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
void func_ov015_02211890(Ov015Info38 *self, u16 id, s32 mode);
void func_ov015_02209024(Ov015FishInfo *self, u16 a, const void *src);
void *Ov015Fish_Ctor(Ov015Fish *self);
void func_ov015_02209364(Ov015Fish *self);

BOOL func_ov015_022015f4(void) {
    return func_02035b90(data_ov015_022128c1, 7) != 0 ? TRUE : FALSE;
}

BOOL func_ov015_02201618(Ov015Game *self) {
    u16 ids[4];
    Ov015CamPair *o;
    Ov015List *l;
    u32 n;
    u32 i;
    o = (Ov015CamPair *)Heap_Alloc(0x1a0);
    if (o != NULL) {
        SET_VT(o, data_ov015_0221291c);
        func_0204b370(&o->cam0);
        func_0204b370(&o->cam1);
        o->mode = 1;
        o->target.x = 0;
        o->target.y = 0;
        o->target.z = 0;
        o->unk_18c.x = 0;
        o->unk_18c.y = 0;
        o->unk_18c.z = 0;
        o->unk_198 = 0;
        o->timer = 0;
    }
    self->cam = o;
    func_ov015_021fce94(o);
    if ((u32)(FLD(s32, data_ov015_02213320.unk_00, 0x4) - 1) <= 1) {
        u8 *p = (u8 *)Heap_Alloc(0x14);
        if (p != NULL) {
            SET_VT(p, data_ov015_02213198);
            func_ov015_02210b3c(p);
        }
        self->unk_90 = p;
    }
    l = (Ov015List *)Heap_Alloc(0x10);
    if (l != NULL) {
        SET_VT(l, data_ov015_0221290c);
        l->head = NULL;
        l->tail = NULL;
        l->count = 0;
    }
    self->fishList = l;
    n = func_ov015_02211160((u8 *)data_ov015_02213368, ids, 3);
    func_ov015_02211890(&self->info, FLD(u16, data_ov015_02213368, 0x8), self->ship->modelIdx);
    for (i = 0; i < n; i++) {
        u16 id = ids[i];
        u8 *def = func_02070744(id);
        Ov015Fish *e = (Ov015Fish *)Heap_Alloc(0x5b0);
        Ov015List *L;
        Ov015Node *nd;
        if (e != NULL) e = (Ov015Fish *)Ov015Fish_Ctor(e);
        e->id = id;
        func_ov015_02209024(&e->info, e->id, def);
        e->info.unk_20 = self->info.unk_20;
        e->info.unk_24 = self->info.unk_24;
        func_ov015_02209364(e);
        L = self->fishList;
        nd = (Ov015Node *)Heap_Alloc(0x10);
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
    self->step = 10;
    {
        SndQueue *pad = data_02097e48.queue;
        if (pad->flag3) {
            pad->unk_06 = 0x8000;
            pad->unk_08 = 0x1e;
            pad->unk_02 = 0;
        }
    }
    return TRUE;
}

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
BOOL func_ov015_022078bc(Ov015Ship *p);
s32 func_ov000_0218f110(void *a);
BOOL func_ov015_0220947c(Ov015Fish *self);
void func_0206e900(char *buf, const char *name);
int func_ov015_02210bd8(u8 *self);
BOOL func_ov015_02207adc(Ov015Ship *self);
BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
BOOL func_ov015_02209500(Ov015Fish *self);
s32 func_ov015_021fb474(u8 *self);
BOOL func_ov015_02210c28(void);
void func_ov000_02190a80(void *a, s32 b);
s32 func_ov015_02210c30(u8 *self, Ov015Stat *a, s32 b);
BOOL func_ov015_021ff4a0(Ov015Obj30 *self, Ov015Ship *a, Ov015CamPair *b, Ov015List *c, Ov015Info38 *d);
BOOL func_ov015_02200204(Ov015Obj34 *self, Ov015Ship *a, Ov015Fish *b, Ov015CamPair *c, Ov015Info38 *d);
BOOL func_ov015_021fb5d4(u8 *self);
void func_ov015_0220101c(Ov015Game *self);
void func_020656b4(void *p);
BOOL func_ov015_0220f568(u8 *self);

static inline BOOL Ov015_SysB4(void) {
    return data_02097d48->unk_a30_4 ? TRUE : FALSE;
}

static inline void Ov015_CamFovy(Ov015Cam *c) {
    u16 idx;
    c->fovy = (u16)(((s64)c->fovyDeg * 0xb60b60b60bLL + 0x80000000000LL) >> 44);
    idx = (u16)(c->fovy >> 1);
    c->fovySin = FX_SinCosTable_[(idx >> 4) * 2];
    c->fovyCos = FX_SinCosTable_[(idx >> 4) * 2 + 1];
    c->dirty = 1;
}

static inline void Ov015_CamUpdate(Ov015Game *self) {
    if (Ov015_SysB4()) {
        Ov015CamPair *cp = self->cam;
        Ov015_CamFovy(&cp->cam0);
        VCALL(&cp->cam0)->v00();
    } else {
        Ov015CamPair *cp = self->cam;
        Ov015_CamFovy(&cp->cam1);
        VCALL(&cp->cam1)->v00();
    }
}

static inline void Ov015_BgmFadeTo(u16 id) {
    SndQueue *p = data_02097e48.queue;
    if (p->flag0) {
        if (p->unk_06 != 0xffff || p->unk_04 != id) {
            if (p->unk_02 != 10 && p->unk_02 != 0) {
                if (p->unk_06 != 0xffff) {
                    func_0204aab0(p, p->unk_06);
                }
                p->unk_02 = 1;
            } else {
                p->unk_02 = 0;
            }
            p->unk_06 = id;
            p->unk_08 = 10;
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

BOOL func_ov015_0220182c(Ov015Game *self) {
    BOOL ret = TRUE;
    bool a = true;
    switch (self->step) {
    case 0:
        self->step = 10;
    case 10: {
        GfxSys *sys = data_02097d48;
        if (sys->state == 1) {
            Ov015SysMode v = OV015_SYS_MODE_2;
            sys->nextState = v;
            func_0203cb78(0x1000, 0, v - 3);
        }
        func_ov015_021fa73c((Ov015Fade *)func_ov015_021fa6d0(), 0x1000, 0);
        self->step = 0x14;
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
        if (!(func_ov015_022078bc(self->ship) & 1)) {
            a = false;
        } else {
            a = true;
        }
        p = self->unk_20;
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
        for (n = self->fishList->head; n != NULL; n = n->next) {
            c &= func_ov015_0220947c((Ov015Fish *)n->key);
        }
        c = b & c;
        q = self->unk_28;
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
        if (self->unk_90 != NULL) {
            d &= func_ov015_02210bd8(self->unk_90);
        }
        if (d) {
            self->step = 0x1e;
        }
        break;
    }
    case 0x1e: {
        u8 *p;
        Ov015Node *n;
        func_ov015_02207adc(self->ship);
        p = self->unk_20;
        func_ov000_0218ffdc(p + 0x13c, p + 0x4, 0, 1);
        func_ov000_02190cb0(p + 0x13c, data_ov015_02212899, 0x1000, 0);
        func_ov000_021915a0(p + 0x13c);
        ((Ov015AnimFlags *)(p + 0x1fe))->visible = 1;
        func_ov000_0218ffdc(p + 0x35c, p + 0x224, 0, 1);
        func_ov000_02190cb0(p + 0x35c, data_ov015_0221289f, 0x1000, 0);
        func_ov000_021915a0(p + 0x35c);
        ((Ov015AnimFlags *)(p + 0x41e))->visible = 1;
        func_ov000_0218ffdc(p + 0x57c, p + 0x444, 0, 1);
        func_ov000_02190cb0(p + 0x57c, data_ov015_022128a5, 0x1000, 0);
        func_ov000_021915a0(p + 0x57c);
        ((Ov015AnimFlags *)(p + 0x63e))->visible = 1;
        for (n = self->fishList->head; n != NULL; n = n->next) {
            func_ov015_02209500((Ov015Fish *)n->key);
        }
        func_ov015_021fb474(self->unk_28);
        if (self->unk_90 != NULL) {
            func_ov015_02210c28();
        }
        data_0214a420->drawFilter = 1;
        func_ov015_021fa71c((Ov015Fade *)func_ov015_021fa6d0(), 0x1e000, 0);
        self->step = 0x28;
        func_02049a48(data_02097e4c, 0x4f, -1, -1, -1);
        Ov015_BgmFadeTo(0x23);
        break;
    }
    case 0x28:
        Ov015_ModelsReset(self->unk_20);
        if (data_ov015_02213328 == 0) {
            func_02049a48(data_02097e4c, 0x3e, -1, -1, -1);
        }
        {
        u8 *m = self->unk_90;
        data_ov015_02213328 = (data_ov015_02213328 + 1) & 0xff;
        if (m != NULL) {
            if (func_ov015_02210c30(m, &data_ov015_0221332c, 0x28)) {
                self->phase1.unk_0c = 1;
            } else {
                self->phase1.unk_0c = 0;
            }
        }
        }
        if (!func_ov015_021ff4a0(&self->phase1, self->ship, self->cam, self->fishList, &self->info)) {
            self->step = 0x32;
            func_02049de8(data_02097e4c, 0x4f);
        }
        {
        Ov015CamPair *cp = self->cam;
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
        Ov015_ModelsReset(self->unk_20);
        if (self->unk_90 == NULL || self->phase2.step < 2 ||
            !func_ov015_02210c30(self->unk_90, &data_ov015_0221332c, 0x32)) {
            func_ov015_021fb5d4(self->unk_28);
            if (!func_ov015_02200204((Ov015Obj34 *)&self->phase2, self->ship, (Ov015Fish *)self->fishList->head->key,
                                     self->cam, &self->info)) {
                self->step = 0x3c;
                func_ov015_021fa73c((Ov015Fade *)func_ov015_021fa6d0(), 0x1e000, 0x7fff);
                FLD(s32, data_ov015_02213320.unk_00, 8) = Dup::data_ov015_0221332c.unk_30;
                if (Dup::data_ov015_0221332c.unk_30 == 2) {
                    func_ov015_021fa71c((Ov015Fade *)func_ov015_021fa6d0(), 0x1000, 0x7fff);
                    self->step = 0x50;
                }
            }
        }
        Ov015_CamUpdate(self);
        break;
    case 0x3c: {
        Ov015Fade *f;
        Ov015_CamUpdate(self);
        f = (Ov015Fade *)func_ov015_021fa6d0();
        if (f->time < f->duration) {
            break;
        }
        self->step = 0x46;
        {
            SndQueue *pad = data_02097e48.queue;
            if (pad->flag3) {
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
        if (!func_ov015_0220f568(self->unk_2c)) {
            self->step = 0x50;
        }
        break;
    case 0x50:
        self->step = -1;
        ret = FALSE;
        break;
    default:
        ret = FALSE;
        break;
    }
    return ret;
}

}
