#include "types.h"

typedef struct {
    u16 a;
    u16 b;
} Ov003InPair;

typedef struct {
    Ov003InPair p;
} Ov003InPairW;

typedef struct {
    u8 pad00[0x12];
    u16 b0 : 5;
    u16 b5 : 3;
    u16 rest : 8;
    s16 unk_14;
    s16 unk_16;
} Ov003InInfo;

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u16 unk_04;
    u16 unk_06;
    Ov003InPairW unk_08;
    u32 unk_0c;
} Ov003InParam;

typedef struct {
    u8 pad00[8];
    u16 unk_08;
    u16 unk_0a_0 : 3;
    u16 unk_0a_3 : 2;
    u16 unk_0a_5 : 11;
    u16 unk_0c_0 : 5;
    u16 unk_0c_5 : 1;
    u16 unk_0c_6 : 10;
    u8 unk_0e[2];
    const char *unk_10[2];
} Ov003InB0;

typedef struct {
    u8 pad00[4];
    u8 *unk_04;
    u8 pad08[0xac];
    u16 unk_b4;
    u8 padb6[0xc];
    u16 unk_c2_0 : 4;
    u16 unk_c2_4 : 1;
    u16 unk_c2_5 : 11;
} Ov003InModel;

typedef struct {
    u8 pad00[0x28];
    s32 unk_28;
    u8 pad2c[0xc];
    s32 unk_38;
    u8 pad3c[0xc];
    s32 unk_48;
    u8 pad4c[0x14];
    s32 unk_60;
    u8 pad64[0x36];
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 rest : 10;
} Ov003InObj48;

typedef struct {
    u8 pad00[0x10];
    s32 unk_10;
    u8 pad14[0x8];
    s32 unk_1c;
    u16 unk_20;
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 2;
    u16 rest : 12;
} Ov003InObj44;

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u16 unk_04;
    u16 unk_06;
    Ov003InPairW unk_08;
    u32 unk_0c;
    u8 pad10[8];
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Ov003InObj4c;

typedef struct {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    u16 unk_0c;
    u16 unk_0e;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
} Ov003InObj50;

typedef struct {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
} Ov003InObj54;

typedef struct {
    u8 pad00[0x5c];
    s32 unk_5c;
} Ov003InObj5c;

typedef struct {
    u8 pad00[0x14];
    s32 unk_14;
} Ov003InObj3c;

typedef struct {
    u8 mtx[0x60];
    u8 idx[2];
    u16 unk_62[2];
    u8 unk_66[2];
    Ov003InModel *sub[2];
} Ov003InParts;

typedef struct {
    s32 frame;
    u32 unk_04;
    u8 *unk_08;
} Ov003InFrm;

typedef struct {
    Ov003InFrm *frm;
    u8 pad04[0x10d];
    u8 unk_111;
} Ov003InAnm;

typedef struct {
    u8 pad00[0xca];
    u8 unk_ca;
} Ov003InGame;

typedef struct {
    u8 pad00[0xc];
    u16 unk_0c;
    u16 id;
    u8 pad10[0x24];
    void *unk_34;
    Ov003InModel *unk_38;
    Ov003InObj3c *unk_3c;
    void *unk_40;
    Ov003InObj44 *unk_44;
    Ov003InObj48 *unk_48;
    Ov003InObj4c *unk_4c;
    Ov003InObj50 *unk_50;
    Ov003InObj54 *unk_54;
    void *unk_58;
    Ov003InObj5c *unk_5c;
    u8 pad60[0x4];
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    u8 pad70[0x40];
    Ov003InB0 *unk_b0;
    u8 padb4[0x1c];
    Ov003InParts *unk_d0;
    u8 padd4[0x8];
    u16 unk_dc;
    u8 padde[0xc];
    u16 unk_ea_0 : 3;
    u16 unk_ea_3 : 3;
    u16 unk_ea_6 : 8;
    u16 unk_ea_14 : 1;
} Ov003In;

extern "C" {
extern Ov003InGame *data_ov000_021ccd54;
void *func_0203dd9c(u32 size);
void *func_0203de84(u32 size, s32 align);
Ov003InInfo *func_0206fef8(u16 id);
Ov003InParam *func_02070558(u16 id);
Ov003InModel *func_ov000_0218fe1c(void *p);
void func_ov000_0219badc(Ov003InModel *m, void *res, Ov003InInfo *info);
Ov003InObj48 *func_ov000_021985e8(void *p);
void func_ov000_02198c8c(Ov003InObj48 *o, u16 id);
void func_0203f324(Ov003InObj48 *o);
void func_ov000_0219864c(Ov003InObj48 *o, void *a, s32 b);
Ov003InObj44 *func_ov000_021984c8(void *p);
void func_ov000_021984f4(Ov003InObj44 *o, void *a, s32 b);
Ov003InObj4c *func_ov000_02199b00(void *p);
Ov003InObj5c *func_ov000_021bd198(void *p);
BOOL func_ov000_021bd314(Ov003InObj5c *p, s32 a);
void STD_CopyString(char *dst, const char *src);
s32 NNS_G3dGetResDictIdxByName(const void *dict, const void *name);
BOOL func_ov000_0218ffdc(Ov003InModel *m, void *res, s32 idx, s32 b);
Ov003InAnm *func_ov000_02190a30(Ov003InModel *m, s32 n);
void func_ov000_02191920(Ov003InModel *m, s32 idx, s32 a, s32 b);
}

static inline Ov003InModel *Ov003In_NewModel(void) {
    void *p = func_0203dd9c(0xe8);
    if (p != NULL) {
        p = func_ov000_0218fe1c(p);
    }
    return (Ov003InModel *)p;
}

static inline Ov003InObj48 *Ov003In_NewObj48(void) {
    void *p = func_0203dd9c(0x9c);
    if (p != NULL) {
        p = func_ov000_021985e8(p);
    }
    return (Ov003InObj48 *)p;
}

static inline Ov003InObj44 *Ov003In_NewObj44(void) {
    void *p = func_0203dd9c(0x24);
    if (p != NULL) {
        p = func_ov000_021984c8(p);
    }
    return (Ov003InObj44 *)p;
}

static inline Ov003InObj4c *Ov003In_NewObj4c(void) {
    void *p = func_0203dd9c(0x5c);
    if (p != NULL) {
        p = func_ov000_02199b00(p);
    }
    return (Ov003InObj4c *)p;
}

static inline Ov003InObj5c *Ov003In_NewObj5c(void) {
    void *p = func_0203dd9c(0xa8);
    if (p != NULL) {
        func_ov000_021bd198(p);
    }
    return (Ov003InObj5c *)p;
}

static inline Ov003InObj50 *Ov003In_NewObj50(void) {
    Ov003InObj50 *p = (Ov003InObj50 *)func_0203dd9c(0x1c);
    if (p != NULL) {
        p->unk_00 = 100;
        p->unk_02 = 100;
        p->unk_04 = 0xffff;
        p->unk_0a = 0;
        p->unk_0e = 0;
        p->unk_0c = 0;
        p->unk_10 = 0;
        p->unk_14 = 0;
        p->unk_18 = 0;
    }
    return p;
}

static inline Ov003InObj54 *Ov003In_NewObj54(void) {
    Ov003InObj54 *p = (Ov003InObj54 *)func_0203dd9c(6);
    if (p != NULL) {
        p->unk_00 = 0;
        p->unk_02 = 0;
        p->unk_04 = 0;
    }
    return p;
}

extern "C" void func_ov003_021d112c(Ov003In *self) {
    Ov003InParam *param;
    Ov003InInfo *info;
    u8 n;
    s32 i;
    info = func_0206fef8(self->id);
    param = func_02070558(self->id);
    self->unk_64 = info->unk_14 << 4;
    self->unk_68 = info->unk_16 << 4;
    self->unk_6c = self->unk_68 >> 1;
    self->unk_38 = Ov003In_NewModel();
    self->unk_38->unk_b4 = self->unk_0c;
    func_ov000_0219badc(self->unk_38, self->unk_34, info);
    if (self->unk_3c != NULL) {
        self->unk_3c->unk_14 = self->unk_64 << 1;
    }
    {
        Ov003InObj48 *o;
        self->unk_48 = Ov003In_NewObj48();
        func_ov000_02198c8c(self->unk_48, self->unk_0c);
        self->unk_48->unk_28 = 0x20;
        self->unk_48->unk_38 = self->unk_64;
        self->unk_48->unk_60 = self->unk_6c;
        o = self->unk_48;
        o->b0 = 1;
        o->b3 = 1;
        func_0203f324(o);
        *(u16 *)((u8 *)self->unk_48 + 0x9a) |= 0x12;
        self->unk_48->b5 = 1;
        if (self->unk_64 >> 1 < 0x4cd) {
            self->unk_48->unk_48 = 0x4cd;
        }
        func_ov000_0219864c(self->unk_48, NULL, 0);
    }
    for (i = 0; i < 2; i++) {
        if (self->unk_b0->unk_10[i] != NULL || self->unk_b0->unk_0e[i] != 0) {
            Ov003InParts *pp = (Ov003InParts *)func_0203de84(0x70, 4);
            s32 j;
            self->unk_d0 = pp;
            for (j = 0; j < 2; j++) {
                pp->idx[j] = 0xff;
                pp->unk_62[j] = 0xffff;
                pp->sub[j] = NULL;
            }
            break;
        }
    }
    if (self->unk_d0 != NULL) {
        Ov003InAnm *anm;
        Ov003InModel *m;
        long k2;
        self->unk_ea_3 = 1;
        for (k2 = 0; k2 < 2; k2++) {
            if (self->unk_b0->unk_10[k2] != NULL) {
                u32 name[4];
                u32 k;
                u8 *dict;
                s32 idx;
                for (k = 0; k < 4; k++) {
                    name[k] = 0;
                }
                STD_CopyString((char *)name, self->unk_b0->unk_10[k2]);
                dict = NULL;
                if (self->unk_38->unk_04 != NULL) {
                    dict = self->unk_38->unk_04 + 0x40;
                }
                if (dict == NULL) {
                    idx = -1;
                } else {
                    idx = NNS_G3dGetResDictIdxByName(dict, name);
                }
                if (idx < 0) {
                    continue;
                }
                self->unk_d0->idx[k2] = idx;
                n = self->unk_b0->unk_0e[k2];
                if (n == 0) {
                    continue;
                }
                m = (Ov003InModel *)func_0203dd9c(0xe8);
                if (m != NULL) {
                    m = func_ov000_0218fe1c(m);
                }
                self->unk_d0->sub[k2] = m;
                if (info->b5 != 0 && self->unk_b0->unk_0c_5) {
                    func_ov000_0218ffdc(m, self->unk_34, n, 1);
                    anm = func_ov000_02190a30(m, 3);
                    if (anm != NULL) {
                        s32 f;
                        Ov003InFrm *frm;
                        func_ov000_02191920(m, n, 0x1000, 0);
                        {
                            s32 x = info->b5 << 12;
                            f = (s32)(info->b5 != 0 ? x + 0.5f : x - 0.5f);
                        }
                        frm = anm->frm;
                        if (frm != NULL) {
                            if (f >= 0) {
                                frm->frame = f;
                            } else {
                                frm->frame = (*(u16 *)(frm->unk_08 + 4) << 12) - 1;
                            }
                        }
                        anm->unk_111 |= 8;
                    }
                } else {
                    func_ov000_0218ffdc(m, self->unk_34, n, 0);
                }
                m->unk_c2_4 = 0;
            }
        }
    }
    {
        Ov003InObj44 *o;
        self->unk_44 = Ov003In_NewObj44();
        self->unk_44->unk_1c = self->unk_64;
        self->unk_44->unk_10 = self->unk_6c;
        self->unk_44->unk_20 = self->unk_0c;
        o = self->unk_44;
        o->b0 = 1;
        o->b1 = 1;
        func_ov000_021984f4(self->unk_44, NULL, 0);
        if (self->unk_b0->unk_0a_3 != 0) {
            self->unk_44->b2 = (u8)self->unk_b0->unk_0a_3;
        }
    }
    {
    Ov003InObj4c *o4c = Ov003In_NewObj4c();
    self->unk_4c = o4c;
    if (param != NULL) {
        o4c->unk_00 = param->unk_00;
        o4c->unk_01 = param->unk_01;
        o4c->unk_02 = param->unk_02;
        o4c->unk_03 = param->unk_03;
        o4c->unk_04 = param->unk_04;
        o4c->unk_06 = param->unk_06;
        o4c->unk_08 = param->unk_08;
        o4c->unk_0c = param->unk_0c;
    }
    }
    self->unk_4c->b1 = 0;
    {
        u16 n = self->unk_b0->unk_08;
        if (n != 0) {
            u16 d;
            self->unk_50 = Ov003In_NewObj50();
            self->unk_50->unk_00 = n;
            self->unk_50->unk_02 = n;
            d = self->unk_b0->unk_0a_0;
            self->unk_dc = d < 2 ? 0 : n / d;
            self->unk_50->unk_0c = 2;
        }
    }
    self->unk_54 = Ov003In_NewObj54();
    {
        Ov003InObj5c *p = Ov003In_NewObj5c();
        self->unk_5c = p;
        func_ov000_021bd314(p, 1);
        self->unk_5c->unk_5c = self->unk_68;
    }
    if (data_ov000_021ccd54->unk_ca == 0x11) {
        self->unk_ea_14 = 1;
    }
}
