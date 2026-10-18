#include "ov011/ov011.h"

extern "C" {

extern void *data_02097e4c;
void func_02049f44(void *a, s32 b, void *c, s32 d);
void func_ov003_021d4fd8(void *p);
void func_ov003_021d5348(void *p);

void func_ov003_021d5900(void *p);
void func_ov000_0218e8ec(void *mgr, u16 id, s32 c);
void func_ov000_02198360(void *a, s32 b, s32 c);
void func_02065804(void *a, void *b);
extern void *data_0214a420;

struct Ov011FbChr {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
    u8 pad[3];
    s32 unk_04;
};

struct Ov011FbScl {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
    u8 pad;
    u16 sx;
    u16 sy;
};

struct Ov011FbObj {
    u8 pad[0x14];
    Ov011V obj;
    u8 pad18[0x20];
    void *unk_38;
};

struct Ov011FbSub {
    u8 pad[0x14];
    s32 unk_14;
    u8 pad18;
    u8 unk_19;
};

struct Ov011Fb {
    u8 pad[0x3c];
    Ov011FbSub *unk_3c;
    u16 *unk_40;
    u8 pad44[0xc];
    u16 *unk_50;
    u8 pad54[0x10];
    s32 unk_64;
    u8 pad68[0x88];
    u8 b0 : 1;
    u8 b1 : 1;
    u8 restf0 : 6;
    u8 padf1[7];
    s32 unk_f8;
    u8 padfc[4];
    Ov011FbChr *unk_100;
    Ov011FbObj *unk_104;
    Ov011FbScl *unk_108;
};

static inline void Ov011_ChrKick(Ov011FbChr *c, s32 v) {
    if (c->b0 && c->b2) {
        c->unk_04 = v;
        c->b2 = 0;
    }
}

static inline u32 Ov011_ChrBusy(Ov011FbChr *c) {
    u32 r = 0;
    if (c->b0) {
        r = c->b2;
    }
    return r;
}

#pragma force_active on
void func_ov011_021ffb58(Ov011Fb *self) {
    switch (*self->unk_40) {
    case 0:
        if (self->b1) {
            Ov011_ChrKick(self->unk_100, 2);
        } else {
            Ov011_ChrKick(self->unk_100, 3);
        }
        *self->unk_40 = 1;
        break;
    case 1:
        if (Ov011_ChrBusy(self->unk_100)) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    self->unk_f8 = 0x3e69;
}

void func_ov011_021ffc38(Ov011Fb *self) {
    switch (*self->unk_40) {
    case 0:
        Ov011_ChrKick(self->unk_100, 4);
        *self->unk_40 = 1;
        break;
    case 1:
        if (Ov011_ChrBusy(self->unk_100)) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

void func_ov011_021ffcd0(Ov011Fb *self) {
    if (*self->unk_40 == 0) {
        Ov011FbChr *c;
        Ov011FbScl *p;
        Ov011FbObj *o;
        self->b0 = 0;
        c = self->unk_100;
        if (c->b0) {
            c->b1 = 1;
        }
        p = self->unk_108;
        p->b0 = 0;
        p->b1 = 0;
        p->sx = 0;
        p->sy = 0x1000;
        o = self->unk_104;
        if (o != NULL) {
            func_ov003_021da48c(o, 0);
            o->obj.v08();
            if (o->unk_38 != NULL) {
                func_02065804(data_0214a420, o->unk_38);
                o->unk_38 = NULL;
            }
        }
        self->unk_3c->unk_14 = self->unk_64 << 1;
        self->unk_3c->unk_19 = 0xff;
        if (*self->unk_50 == 0) {
            func_ov000_0218e8ec(data_ov000_021ccd68, 0x4812, 0x15);
        }
    }
    func_ov003_021d5900(self);
}

void func_ov011_021ffdd0(void *self) {
    if (**(u16 **)((u8 *)self + 0x40) == 0) {
        func_02049f44(data_02097e4c, 0x42, (u8 *)self + 0x70, 0);
    }
    func_ov003_021d4fd8(self);
}

void func_ov011_021ffe10(void *self) {
    if (**(u16 **)((u8 *)self + 0x40) == 0) {
        func_02049f44(data_02097e4c, 0x42, (u8 *)self + 0x70, 0);
    }
    func_ov003_021d5348(self);
}
#pragma force_active reset
}
