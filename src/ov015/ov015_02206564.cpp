#include "ov015/ov015.h"

extern "C" {

extern u8 *data_02097dc8;
extern void *data_02097e4c;
extern u8 *data_ov000_021ccd44;
void func_02049a48(void *a, int b, int c, int d, int e);
void func_ov000_0218084c(void *a, s32 b, s32 c);
extern u8 data_ov000_021ccd34;
void func_ov000_0217357c(void *self);
extern u8 *data_0214a424;
extern void *data_02149ef8;
void *func_0204c0e8(void *a, int id);
u8 *func_0206f000(u16 id);
void func_0206f21c(u16 id, s32 n);
void func_0206f5e4(u16 id, s32 n);
void func_ov000_0215d980(void *a, u32 b, s32 c);
void func_ov000_0215c1bc(void *a, s32 b, void *c);
extern Ov015Globals data_ov015_02213320;
void func_ov000_02180660(s32 a, s32 b);
extern void *data_ov000_021ccd40;
extern u8 data_ov015_02213360[];

void func_ov015_02206564(u8 *self) {
    u8 *pd = data_02097dc8;
    u16 pad = FLD(u16, pd, 0x12);
    BOOL on = FLD(Ov015ObjFlags, FLD(u8 *, self, 0x4c), 0xc).b1 ? TRUE : FALSE;
    if (!on) {

        return;
    }
    if (!(pad & 2)) {
        return;
    }
    func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    FLD(s32, self, 0x54) = 0;
    FLD(u32, FLD(u8 *, self, 0x3c), 0xc) |= 2;
    FLD(u32, FLD(u8 *, self, 0x44), 0xc) |= 2;
    FLD(u32, FLD(u8 *, self, 0x40), 0xc) |= 2;
    FLD(u32, FLD(u8 *, self, 0x48), 0xc) |= 2;
    FLD(u32, FLD(u8 *, self, 0x50), 0xc) |= 2;
    func_ov000_0218084c(data_ov000_021ccd44, 0x1f, FLD(s32, self, 0xc));
    FLD(u32, self, 0x4) |= 6;
}

static inline BOOL Ov015_IsFinished(u8 *o) {
    BOOL r = FALSE;
    if (FLD(Ov015ObjFlags, o, 0xc).b1 ? TRUE : FALSE) {
        if (VCALL(o)->v0c() == 0) r = TRUE;
    }
    return r;
}
void func_ov015_02206648(u8 *self) {
    switch (FLD(s32, self, 0x8)) {
    case 8:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    case 0xa:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    }
    if (!Ov015_IsFinished(FLD(u8 *, self, 0x4c)) || !Ov015_IsFinished(FLD(u8 *, self, 0x50))) {
        data_ov000_021ccd34 = 1;
        FLD(u32, FLD(u8 *, self, 0x3c), 0xc) |= 4;
    } else {
        data_ov000_021ccd34 = 0;
        FLD(u32, FLD(u8 *, self, 0x3c), 0xc) &= ~4;
    }

    VCALL(FLD(void *, self, 0x3c))->v1c();
    VCALL(FLD(void *, self, 0x40))->v1c();
    VCALL(FLD(void *, self, 0x44))->v1c();
    VCALL(FLD(void *, self, 0x48))->v1c();
    VCALL(FLD(void *, self, 0x4c))->v1c();
    VCALL(FLD(void *, self, 0x50))->v1c();
}

static inline bool Ov015Child_Is2(Ov015Child *c) {
    return c->state == 2;
}

bool func_ov015_022067b4(Ov015Child *self) {
    BOOL r = Ov015Child_Is2(self);
    return r;
}

void func_ov015_022067d4(u8 *self) {
    s32 a = FLD(s32, self, 0x58);
    s32 r = 0;
    if (a < 0x1000000) {
        r = a + 0x8000;
    }
    FLD(s32, self, 0x58) = r;
    if (FLD(s32, self, 0x5c) <= 0) {
        FLD(s32, self, 0x5c) = 0x1000000;
    } else {
        FLD(s32, self, 0x5c) -= 0x8000;
    }
}

void func_ov015_02206800(u8 *self) {
    if (VCALL(self)->v28() == 0) {
        return;
    }
    func_ov000_0217357c(self);
    VCALL(FLD(void *, self, 0x3c))->v20();
    VCALL(FLD(void *, self, 0x40))->v20();
    VCALL(FLD(void *, self, 0x44))->v20();
    VCALL(FLD(void *, self, 0x48))->v20();
    VCALL(FLD(void *, self, 0x4c))->v20();
    VCALL(FLD(void *, self, 0x50))->v20();
}

static inline u8 *Ov015_ListNth3(u8 *o) {
    u8 *p = FLD(u8 *, o, 0x98);
    s32 n;
    if (p == NULL) return NULL;
    n = FLD(s8, o, 0xb1);
    while (n-- != 0) {
        p = FLD(u8 *, p, 0x2c);
    }
    return p;
}
static inline void Ov015_ShopMsg(u8 *self, s32 id) {
    func_ov000_0215c1bc(FLD(void *, self, 0x50), 0x8000, func_0204c0e8(data_02149ef8, id));
    FLD(u32, FLD(u8 *, self, 0x50), 0xc) &= ~2;
    VCALL(FLD(void *, self, 0x50))->v70();
}
static inline void Ov015_SetMoney24(u16 v) {
    if (v > 9999) v = 9999;
    FLD(u16, data_0214a424, 0x24) = v;
}
BOOL func_ov015_02206888(u8 *self) {
    u8 *item = Ov015_ListNth3(FLD(u8 *, self, 0x3c));
    u16 id = FLD(s32, item, 0x10);
    u8 *def = func_0206f000(id);
    BOOL consume = TRUE;
    BOOL r = TRUE;
    if (FLD(u32, FLD(u8 *, self, 0x40), 0x8c) < FLD(u32, item, 0xc)) {
        if (FLD(void *, self, 0x50) != NULL) Ov015_ShopMsg(self, 0x9c);
        return FALSE;
    }
    switch (def[0]) {
    case 0:
        if (FLD(u16, data_0214a424, 0x28) >= 100) {
            if (FLD(void *, self, 0x50) != NULL) Ov015_ShopMsg(self, 0x9e);
            r = FALSE;
        } else {
            func_0206f21c(FLD(u16, def, 0x2), consume);
            if (def[1] == 0) consume = FALSE;
        }
        break;
    case 1: {
        u32 s = def[1] + FLD(u16, data_0214a424, 0x24);
        if (s > 9999) s = 9999;
        Ov015_SetMoney24(s);
        break;
    }
    }
    if (r) {
        func_ov000_0215d980(FLD(void *, self, 0x40), FLD(u32, FLD(u8 *, self, 0x40), 0x8c) - FLD(u32, item, 0xc), 0);
        if (consume) {
            VCALL(FLD(void *, self, 0x3c))->v70(item);
            func_0206f5e4(id, 1);
        }
        {
            u8 *save = data_0214a424;
            u32 m = FLD(u32, FLD(u8 *, self, 0x40), 0x8c);
            if (m > 99999) m = 99999;
            FLD(u32, save, 0x618) = m;

        }
    }
    return r;
}

void func_ov015_02206aa0(Ov015Child *self) {
    FLD(s32, self, 0x8) = 1;
    FLD(s32, self, 0xc) = 0;
    FLD(s32, self, 0x10) = 5;
}

BOOL func_ov015_02206abc(void) {
    func_ov000_02180660(0x1e, ((Ov015Main *)data_ov015_02213320.unk_00)->unk_04);
    return TRUE;
}

BOOL func_ov015_02206ae0(void) {
    BOOL r = FALSE;
    if (data_ov000_021ccd40 != NULL) {
        r = TRUE;
    }
    return r;
}

BOOL func_ov015_02206afc(void) {
    data_ov015_02213360[0] = 0;
    data_ov015_02213360[1] = 0;
    data_ov015_02213360[2] = 0;
    return TRUE;
}

struct Ov015Flags0 {
    u32 flag0 : 1;
    u32 flag1 : 1;
    u32 rest : 30;
};

static inline bool Ov015Task_Flag1(Ov015Task *t) {
    return t->flag1;
}

static inline bool Ov015Flags0_Flag1(Ov015Flags0 *t) {
    return t->flag1;
}

BOOL func_ov015_02206b1c(u8 *self) {
    BOOL r;
    u8 *t;
    FLD(void *, self, 0xc) = data_ov000_021ccd40;
    r = TRUE;
    {
        BOOL b = Ov015Flags0_Flag1((Ov015Flags0 *)data_ov000_021ccd44);
        if (b) {
            r = FALSE;
        }
    }
    t = FLD(u8 *, self, 0xc);
    if (t != NULL && Ov015Task_Flag1((Ov015Task *)t) != 0) {
        switch (FLD(s32, t, 0x14)) {
        case 0x1f:
            FLD(s32, self, 0x10) = FLD(s32, t, 0x94);
            break;
        case 0x20:
            FLD(s32, self, 0x10) = FLD(s32, t, 0x58);
            break;
        case 0x21:
            FLD(s32, self, 0x10) = FLD(s32, t, 0x50);
            break;
        case 0x22:
            FLD(s32, self, 0x10) = FLD(s32, t, 0x54);
            break;
        }
    }
    return r;
}

void func_ov015_02206bcc(void) {
}

s32 func_ov015_02206bd0(u8 *self) {
    s32 r;
    switch (FLD(s32, self, 0x10)) {
    case 4:
        r = 2;
        break;
    case 5:
        r = 3;
        break;
    }
    return r;
}


typedef struct {
    u32 y : 8;
    u32 attr0hi : 8;
    u32 x : 9;
    u32 attr1hi : 7;
    u32 charName : 10;
    u32 prio : 2;
    u32 pal : 4;
    u32 attr3 : 16;
} Ov015Oam;

typedef struct {
    u32 sizeS;
    u32 sizeT;
    u32 fmt;
    u32 bExtendedPlt;
    u32 plttUse;
    u32 mappingType;
} Ov015ImgAttr;

extern u32 data_ov015_02212600[];
void func_02043064(const Ov015Oam *attr, u32 *w, u32 *h);
void NNS_G3dGeBufferOP_N(u32 op, const void *args, u32 num);

static inline void Ov015_G3Cmd2(u32 op, u32 a, u32 b) {
    u32 v[2];
    v[0] = a;
    v[1] = b;
    NNS_G3dGeBufferOP_N(op, v, 2);
}

static inline void Ov015_G3Cmd1(u32 op, u32 v) {
    u32 a = v;
    NNS_G3dGeBufferOP_N(op, &a, 1);
}

void func_ov015_02206bf0(void *self, s32 x, s32 y, s32 z, s32 unused, Ov015Oam *oam,
                         const Ov015ImgAttr *img, u32 charBase, u32 plttBase, s32 unused2, const s32 *ofs) {
    s32 mv[3];
    s32 tv[3];
    s32 sv[3];
    u32 fmt;
    u32 pal;
    u32 h;
    u32 w;
    s32 shift;
    u16 charName;
    s32 ox;
    s32 oy;

    charName = (u16)oam->charName;
    shift = ((s32)(img->mappingType & 0x700000) >> 20) + 5;
    ox = ofs[0];
    oy = ofs[1];
    func_02043064(oam, &w, &h);
    *(vu32 *)0x40004a8 = ((charBase + (charName << shift)) >> 3) | (img->fmt << 26) | 0x40000000 | (w << 20) |
                         (h << 23) | 0x30000 | (img->plttUse << 29);
    fmt = data_ov015_02212600[(*(u32 *)oam << 18) >> 31];
    if (img->bExtendedPlt != 0) {
        pal = (u16)oam->pal << 9;
    } else if (fmt == 4) {
        pal = 0;
    } else {
        pal = (u16)oam->pal << 5;
    }
    *(vu32 *)0x40004ac = (plttBase + pal) >> (4 - (fmt == 2));
    Ov015_G3Cmd1(0x10, 3);
    mv[0] = ox & -0x1000;
    mv[1] = oy & -0x1000;
    mv[2] = 0;
    NNS_G3dGeBufferOP_N(0x1c, mv, 3);
    Ov015_G3Cmd1(0x10, 2);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    tv[0] = x - 0x80000;
    tv[1] = y - 0x60000;
    tv[2] = z;
    NNS_G3dGeBufferOP_N(0x1c, tv, 3);
    sv[0] = 0x100000;
    sv[1] = 0xc0000;
    sv[2] = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, sv, 3);
    Ov015_G3Cmd1(0x40, 1);
    Ov015_G3Cmd1(0x20, 0x2214);
    Ov015_G3Cmd1(0x22, 0xc000000);
    Ov015_G3Cmd2(0x23, 0x10000000, 0);
    Ov015_G3Cmd1(0x22, 0xc001000);
    Ov015_G3Cmd1(0x25, 0x10001000);
    Ov015_G3Cmd1(0x20, 0x7fff);
    Ov015_G3Cmd1(0x22, 0x1000);
    Ov015_G3Cmd1(0x25, 0x1000);
    Ov015_G3Cmd1(0x22, 0);
    Ov015_G3Cmd1(0x25, 0);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    Ov015_G3Cmd1(0x12, 1);
}

}
