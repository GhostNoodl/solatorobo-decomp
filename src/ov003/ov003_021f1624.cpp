#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003InVec;

typedef struct {
    u8 r, g, b;
} Ov003InCol;

typedef struct {
    u8 unk_00[0x12];
    u16 unk_12_0 : 11;
    u16 unk_12_11 : 1;
    u16 unk_12_12 : 2;
    s16 unk_14;
    s16 unk_16;
} Ov003InRes;

typedef struct {
    s16 unk_00;
} Ov003InB0;

typedef struct {
    u8 unk_00[0xb4];
    u16 unk_b4;
    u8 unk_b6[9];
    u8 unk_bf;
    u8 unk_c0[2];
    u16 unk_c2_0 : 3;
    u16 unk_c2_3 : 1;
} Ov003InModel;

typedef struct {
    u8 unk_00[0x14];
    s32 unk_14;
} Ov003InS3c;

typedef struct {
    u8 unk_00[0x28];
    s32 unk_28;
    u8 unk_2c[0xc];
    s32 unk_38;
    u8 unk_3c[0x24];
    s32 unk_60;
    u8 unk_64[0x36];
    u16 enable : 1;
    u16 unk_9a_1 : 1;
    u16 unk_9a_2 : 1;
    u16 visible : 1;
    u16 unk_9a_4 : 1;
} Ov003InCtl;

typedef struct {
    u8 unk_00[0x10];
    s32 unk_10;
    u8 unk_14[8];
    s32 unk_1c;
    u16 unk_20;
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
    u16 unk_22_2 : 3;
    u16 unk_22_5 : 1;
} Ov003InS44;

typedef struct {
    u8 unk_00;
    u8 unk_01[0x17];
    u8 unk_18;
} Ov003InS4c;

typedef struct {
    u8 unk_00[0x28];
    u32 unk_28;
    u8 unk_2c[0x18];
    s32 unk_44;
    u8 unk_48[0x14];
    s32 unk_5c;
    u8 unk_60[8];
    s32 unk_68;
} Ov003InIcon;

typedef struct {
    u8 unk_00[0x2c];
    u32 unk_2c;
} Ov003InHit;

typedef struct {
    u8 unk_00[0xca];
    Ov003InCol unk_ca;
} Ov003InGame;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0xa];
    s16 unk_1a;
    u8 unk_1c[0x18];
    void *unk_34;
    Ov003InModel *model;
    Ov003InS3c *unk_3c;
    u8 unk_40[4];
    Ov003InS44 *unk_44;
    Ov003InCtl *ctl;
    Ov003InS4c *unk_4c;
    u8 unk_50[0xc];
    Ov003InIcon *unk_5c;
    u8 unk_60[4];
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    Ov003InVec pos;
    u16 rot[3];
    u8 unk_82[0x2a];
    Ov003InIcon *unk_ac;
    Ov003InB0 *unk_b0;
} Ov003In;

extern "C" {

extern Ov003InHit data_02fe0f14;
extern Ov003InGame *data_ov000_021ccd54;
extern Ov003InCol data_ov003_021f7388;
extern char data_ov003_021fa208[];
extern Ov003InRes *func_0206fef8(u16 id);
extern Ov003InB0 *func_020702c8(u16 id);
extern Ov003InB0 *func_02070410(u16 id);
extern Ov003InB0 *func_0207036c(u16 id);
extern void *func_0203dd9c(u32 size);
extern Ov003InModel *func_ov000_0218fe1c(void *p);
extern void func_ov000_0219badc(Ov003InModel *model, void *p, Ov003InRes *res);
extern s32 func_02040528(s32 max);
extern void func_ov000_021911c8(Ov003InModel *model, s32 v);
extern s32 func_ov000_0219a2f4(Ov003InVec *pos, s32 a, s32 b);
extern void func_ov000_02191ec4(Ov003InS3c *p, s32 a, u32 b);
extern char *func_0207005c(u16 id, s32 n);
extern int STD_CompareString(const char *a, const char *b);
extern Ov003InCtl *func_ov000_021985e8(void *p);
extern void func_ov000_02198c8c(Ov003InCtl *p, u16 id);
extern void func_0203f324(Ov003InCtl *p);
extern void func_ov000_0219864c(Ov003InCtl *p, s32 a, s32 b);
extern Ov003InS44 *func_ov000_021984c8(void *p);
extern Ov003InS4c *func_ov000_02199b00(void *p);
extern void func_ov000_021bd198(Ov003InIcon *p);
extern void func_ov000_021bd314(Ov003InIcon *p, s32 id);
extern void func_ov000_02190758(Ov003InModel *model, u16 *rot, s32 a);

static inline void Ov003In_Icon(Ov003InIcon *icon, u16 id) {
    if (icon->unk_44 == 10 && icon->unk_68 == 10) {
        icon->unk_68 = 3;
    }
    icon->unk_28 = id;
}

static inline BOOL Ov003In_SameCol(const Ov003InCol *a, Ov003InCol b) {
    BOOL r = FALSE;
    if (a->r == b.r && a->g == b.g && a->b == b.b) {
        r = TRUE;
    }
    return r;
}

void func_ov003_021f1624(Ov003In *self) {
    Ov003InRes *res = func_0206fef8(self->unk_0e);
    Ov003InIcon *icon;
    char *name;
    {
        Ov003InB0 *p;
        u16 k = self->unk_0c & 0xf000;
        if (k == 0x1000) {
            p = func_020702c8(self->unk_0e);
        } else if (k == 0x3000) {
            p = func_02070410(self->unk_0e);
        } else if (k == 0x2000) {
            p = func_0207036c(self->unk_0e);
        } else {
            goto skip;
        }
        if (p != NULL) {
            self->unk_b0 = p;
        }
    }
skip:
    self->unk_64 = res->unk_14 << 4;
    self->unk_68 = res->unk_16 << 4;
    self->unk_6c = self->unk_68 >> 1;
    if (self->unk_34 != NULL) {
        Ov003InModel *m = (Ov003InModel *)func_0203dd9c(0xe8);
        s16 v;
        if (m != NULL) {
            m = func_ov000_0218fe1c(m);
        }
        self->model = m;
        m->unk_b4 = self->unk_0c;
        func_ov000_0219badc(self->model, self->unk_34, res);
        if (res->unk_12_11 && self->rot[1] > 0x4000 && self->rot[1] < 0xc000) {
            self->model->unk_c2_3 = 1;
        }
        if (self->unk_b0 == NULL || (v = self->unk_b0->unk_00) == 0) {
            v = 0x1c3;
            v += (s16)func_02040528(0xa4);
        }
        func_ov000_021911c8(self->model, v);
        if (self->unk_3c != NULL) {
            self->unk_3c->unk_14 = self->unk_64 * 3;
            if (func_ov000_0219a2f4(&self->pos, self->unk_68, -0x5000) != -0x1000) {
                func_ov000_02191ec4(self->unk_3c, 1, data_02fe0f14.unk_2c);
                if (data_02fe0f14.unk_2c & 0x80000) {
                    self->model->unk_bf = 0x13;
                }
            }
        }
    }
    name = func_0207005c(self->unk_0e, 0);
    if (name == NULL || STD_CompareString(name, data_ov003_021fa208) != 0) {
        if (res->unk_12_12) {
            Ov003InCtl *c = (Ov003InCtl *)func_0203dd9c(0x9c);
            if (c != NULL) {
                c = func_ov000_021985e8(c);
            }
            self->ctl = c;
            func_ov000_02198c8c(c, self->unk_0c);
            self->ctl->unk_28 = 8;
            self->ctl->unk_38 = self->unk_64;
            self->ctl->unk_60 = self->unk_6c;
            c = self->ctl;
            c->enable = 1;
            c->visible = 1;
            func_0203f324(c);
            c = self->ctl;
            c->unk_9a_1 = 0;
            c->unk_9a_4 = 0;
            func_ov000_0219864c(self->ctl, 0, 0);
        }
        if (!Ov003In_SameCol(&data_ov000_021ccd54->unk_ca, data_ov003_021f7388)) {
            Ov003InS44 *s = (Ov003InS44 *)func_0203dd9c(0x24);
            if (s != NULL) {
                s = func_ov000_021984c8(s);
            }
            self->unk_44 = s;
            s->unk_1c = self->unk_64;
            self->unk_44->unk_10 = self->unk_6c;
            self->unk_44->unk_20 = self->unk_0c;
            s = self->unk_44;
            s->unk_22_0 = 1;
            s->unk_22_1 = 1;
            if (self->unk_0e == 0x2003 && self->unk_1a != 0) {
                self->unk_44->unk_22_5 = 1;
            }
        }
        {
            Ov003InS4c *d = (Ov003InS4c *)func_0203dd9c(0x5c);
            if (d != NULL) {
                d = func_ov000_02199b00(d);
            }
            self->unk_4c = d;
            d->unk_00 = 3;
            self->unk_4c->unk_18 |= 2;
        }
        icon = (Ov003InIcon *)func_0203dd9c(0xa8);
        if (icon != NULL) {
            func_ov000_021bd198(icon);
        }
        self->unk_5c = icon;
        func_ov000_021bd314(icon, 10);
        Ov003In_Icon(self->unk_5c, self->unk_0e);
        self->unk_5c->unk_5c = self->unk_68;
    }
    icon = (Ov003InIcon *)func_0203dd9c(0xa8);
    if (icon != NULL) {
        func_ov000_021bd198(icon);
    }
    self->unk_ac = icon;
    icon->unk_5c = self->unk_68 + 0x800;
    if (self->model != NULL) {
        func_ov000_02190758(self->model, self->rot, 0);
    }
}

}
