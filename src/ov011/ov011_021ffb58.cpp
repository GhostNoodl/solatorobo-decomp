#include "ov011/ov011.h"

extern "C" {

extern void *data_02097e4c;
void *func_02049f44(void *a, s32 b, void *c, s32 d);
void func_ov003_021d4fd8(void *p);
void func_ov003_021d5348(void *p);

void func_ov003_021d5900(void *p);
void func_ov000_0218e8ec(void *mgr, u16 id, s32 c);
BOOL func_ov000_02198360(void *a, s32 b, s32 c);
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
    u16 cnt;
    u8 pad02[2];
    u64 flags;
    u8 pad0c[7];
    u8 state;
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
    u8 pad44[4];
    u8 *unk_48;
    u8 pad4c[4];
    u16 *unk_50;
    u8 pad54[0x10];
    s32 unk_64;
    u8 pad68[0x2c];
    u8 f94_0 : 1;
    u8 f94_m : 2;
    u8 f94_r : 5;
    u8 pad95[0x5b];
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

Ov011V *func_02065f88(s32 id, Ov011Vec *v);
void func_ov003_021d6054(void *p);
void func_ov011_021ffe50(Ov011Fb *self) {
    if (*self->unk_40 == 0) {
        Ov011FbObj *o;
        Ov011V *v;
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4812, 0x15);
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
        v = func_02065f88(0x69, (Ov011Vec *)((u8 *)self + 0x70));
        if (v != NULL) {
            v->v0c(0x2800);
            v->v24(0, 0x1000, 0);
        }
    }
    func_ov003_021d6054(self);
}

struct Ov011FxDesc {
    u8 pad[4];
    const char *name;
    const char *arc;
    u8 pad0c[0x14];
    Ov011Vec pos;
};
extern Ov011FxDesc data_ov011_02207258;
extern Ov011Vec data_ov011_02207278;
Ov011V *func_02066900(const char *arc, const char *name, const Ov011Vec *pos);
Ov011V *func_020657b0(void *m, void *id);
void func_02065860(void *m, void *id);
BOOL func_ov011_02202d04(void *self, const Ov011Vec *to, const Ov011Vec *from, s16 speed);
void func_ov003_021da40c(void *p);

#define D58 ((s32 *)&data_ov011_02207258)
static inline void VSet_ff38(Ov011Vec *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void func_ov011_021fff38(Ov011Fb *self) {
    Ov011Vec t;
    Ov011Vec arr_[2];

    Ov011FbObj *o;
    Ov011Vec *home;

    s32 y;
    home = (Ov011Vec *)&data_ov011_02207278;
    y = D58[9];
    t.x = D58[8];
    t.y = y - 0x2000;
    t.z = D58[10];
    o = self->unk_104;
    if (o == NULL) {
        return;
    }
    switch (o->state) {
    case 0:
        break;
    case 1: {
        u8 n;
        s32 v = self->unk_3c->unk_14;
        n = self->unk_3c->unk_19;
        if (n == 0xff) {
            n = 0xf;
        }
        v += Ov011_FxMul(0x8000 - v, 0x333);
        if (n >= 0x1e) {
            n = 0x1e;
        } else {
            n++;
        }
        self->unk_3c->unk_14 = v;
        self->unk_3c->unk_19 = n;
        break;
    }
    case 2:
        if (o->cnt == 0) {
            Ov011V *g;
            o->obj.v08();
            func_ov011_02202d04(&self->unk_104->obj, &t, home, 0x19a);
            self->unk_104->cnt++;
            arr_[1] = *(Ov011Vec *)(self->unk_48 + 0x68);
            g = func_02066900((const char *)((volatile s32 *)D58)[2], (const char *)((volatile s32 *)D58)[1], &arr_[1]);
            self->unk_104->unk_38 = FLD(void *, g, 0x24);
            FLD(s32, g, 0xc8) = -1;
        }
        if (self->unk_104->unk_38 != NULL) {
            Ov011V *e = func_020657b0(data_0214a420, self->unk_104->unk_38);
            if (e != NULL) {
                arr_[0] = *(Ov011Vec *)(self->unk_48 + 0x68);
                e->v18(&arr_[0]);
            }
        }
        self->f94_m = 1;
        break;
    case 3:
        if (o->cnt == 0) {
            o->obj.v08();
            func_ov011_02202d04(&self->unk_104->obj, home, &t, 0x19a);
            self->unk_104->cnt++;
            if (self->unk_104->unk_38 != NULL) {
                func_02065860(data_0214a420, self->unk_104->unk_38);
                self->unk_104->unk_38 = NULL;
            }
            self->b0 = 0;
        } else {
            s32 v;
            v = self->unk_3c->unk_14;
            u8 n = self->unk_3c->unk_19;
            if (n <= 0xf) {
                n = 0xf;
                if (o->obj.v14()) {
                    self->unk_104->obj.v08();
                    self->f94_m = 0;
                    self->unk_104->flags |= 1;
                }
            } else {
                n--;
                v += Ov011_FxMul((self->unk_64 << 1) - v, 0x59a);
            }
            self->unk_3c->unk_14 = v;
            self->unk_3c->unk_19 = n;
        }
        break;
    }
    func_ov003_021da40c(self->unk_104);
    self->unk_104->obj.v0c();
}
#pragma force_active reset
}
