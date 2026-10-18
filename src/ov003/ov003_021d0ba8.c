#include "types.h"

typedef struct {
    u8 unk_00[0x30];
} Ov003Slot30;

typedef struct {
    Ov003Slot30 slots[2];
    u8 ids[2];
} Ov003SlotTable;

typedef struct {
    u8 unk_00[0x2c];
    Ov003SlotTable *table;
} Ov003SlotOwner;

typedef struct {
    void *vtbl;
    Ov003SlotOwner *owner;
    u32 flags;
    u8 unk_0c[0x18];
    void (*func)(void *);
    u8 unk_28[0x6a];
    u8 unk_92;
    u8 unk_93[0x19];
    u8 unk_ac;
    u8 unk_ad;
    u8 unk_ae;
    u8 unk_af;
    void *unk_b0;
    u16 unk_b4;
    u16 unk_b6;
    u8 unk_b8[0xc];
    void *unk_c4;
    void *unk_c8;
    void *unk_cc;
    void *unk_d0;
    void *unk_d4;
    void *unk_d8;
    u16 unk_dc;
    u16 unk_de;
    void *unk_e0;
    void *unk_e4;
    u16 unk_e8;
    u16 unk_ea;
    u8 unk_ec;
    u8 unk_ed;
    u16 unk_ee;
} Ov003Obj;

extern void NNS_G3dGetCurrentMtx(void *p, s32 a);
extern void func_ov000_0218c2d4(Ov003Obj *self);
extern char data_ov003_021f7ab4[];

typedef struct {
    u16 bit0 : 1;
    u16 bit1 : 1;
} Ov003ResFlags;

typedef struct {
    u8 unk_00[0x12];
    Ov003ResFlags flags;
} Ov003ResInfo;

typedef struct {
    u8 unk_00[0x28];
    char *unk_28;
} Ov003ResParam;

typedef struct {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04[0xc];
    char unk_10[0x20];
    char unk_30[0x1c];
    char unk_4c[0x20];
    char unk_6c[0x58];
    char unk_c4[0x20];
    char unk_e4[0x1c];
    char unk_100[0x20];
    char unk_120[0x20];
} Ov003Res;

extern Ov003ResInfo *func_0206fef8(u16 id);
extern Ov003ResParam *func_02070558(u16 id);
extern char *func_0207011c(u16 id);
extern char *func_020701d4(u16 id);
extern char *func_0207005c(u16 id, s32 n);
extern void STD_CopyString(char *dst, const char *src);
extern void func_ov000_0218f074(Ov003Res *p, char *res, s32 a, s32 b, s32 c, s32 d);

void func_ov003_021d0a2c(Ov003Res *res, u16 id) {
    Ov003ResInfo *info = func_0206fef8(id);
    Ov003ResParam *param = func_02070558(id);
    char *name = func_0207011c(id);
    char *a;
    char *b;
    if (param->unk_28 != NULL) {
        char *alt = func_020701d4(id);
        if (info->flags.bit0) {
            STD_CopyString(res->unk_10, name);
            STD_CopyString(res->unk_30, alt);
            res->unk_03 |= 2;
        }
        if (info->flags.bit1) {
            STD_CopyString(res->unk_4c, name);
            STD_CopyString(res->unk_6c, alt);
            res->unk_03 |= 4;
        }
        alt = param->unk_28;
        STD_CopyString(res->unk_c4, name);
        STD_CopyString(res->unk_e4, alt);
        res->unk_03 |= 0x10;
    } else {
        func_ov000_0218f074(res, name, info->flags.bit0 != 0, info->flags.bit1 != 0, 0, 0);
    }
    a = func_0207005c(id, 0);
    b = func_0207005c(id, 1);
    if (a != NULL && b != NULL) {
        STD_CopyString(res->unk_100, a);
        STD_CopyString(res->unk_120, b);
        res->unk_03 |= 0x20;
    }
    res->unk_00 = 0;
}

void func_ov003_021d0ba8(Ov003Obj *self) {
    s32 id;
    Ov003SlotTable *t;
    s32 i;
    t = self->owner->table;
    if (self->flags & 0x10) {
        id = self->unk_ae;
    } else {
        id = -1;
    }
    for (i = 0; i < 2; i++) {
        if (t->ids[i] != 0xff && id == t->ids[i]) {
            NNS_G3dGetCurrentMtx(&t->slots[i], 0);
            return;
        }
    }
}

void func_ov003_021d0c04(Ov003Obj *self) {
    self->func = (void (*)(void *))func_ov003_021d0ba8;
    self->unk_92 = 3;
}

#define OV003_OBJ_CTOR(name)                 \
Ov003Obj *name(Ov003Obj *self) {             \
    func_ov000_0218c2d4(self);               \
    self->vtbl = data_ov003_021f7ab4;        \
    self->unk_b4 = 0;                        \
    self->unk_b6 = 0;                        \
    self->unk_ac = 0xff;                     \
    self->unk_ad = 0xff;                     \
    self->unk_ae = 0xff;                     \
    self->unk_b0 = NULL;                     \
    self->unk_c4 = NULL;                     \
    self->unk_d0 = NULL;                     \
    self->unk_d4 = NULL;                     \
    self->unk_d8 = NULL;                     \
    self->unk_e8 = 0;                        \
    self->unk_de = 0xffff;                   \
    self->unk_ea = 0;                        \
    self->unk_ec = 0;                        \
    self->unk_ee = 0;                        \
    self->unk_c8 = NULL;                     \
    self->unk_cc = NULL;                     \
    self->unk_e4 = NULL;                     \
    self->unk_e0 = NULL;                     \
    return self;                             \
}

OV003_OBJ_CTOR(func_ov003_021d0c1c)
OV003_OBJ_CTOR(func_ov003_021d0c94)

typedef struct {
    void *cur;
    u32 unk_04;
    void *alt;
} Ov003HeapCtx;

typedef struct {
    u8 unk_00[0x68];
    void *unk_68[2];
} Ov003SubD0;

extern Ov003HeapCtx *data_02097dd0;
extern void *data_0214a420;
extern void func_ov000_0218fee4(void *p);
extern void func_0203de1c(void *p);
extern void func_0203df0c(void *p);
extern void func_02065804(void *mgr, void *p);
extern void func_ov000_0218c928(Ov003Obj *self);

static inline void Ov003Obj_DtorBody(Ov003Obj *self) {
    s32 i;
    self->vtbl = data_ov003_021f7ab4;
    if (self->unk_d0 != NULL) {
        for (i = 0; i < 2; i++) {
            void *old = data_02097dd0->cur;
            void *m;
            data_02097dd0->cur = data_02097dd0->alt;
            m = ((Ov003SubD0 *)self->unk_d0)->unk_68[i];
            if (m != NULL) {
                if (m != NULL) {
                    func_ov000_0218fee4(m);
                    func_0203de1c(m);
                }
                ((Ov003SubD0 *)self->unk_d0)->unk_68[i] = NULL;
            }
            data_02097dd0->cur = old;
        }
        func_0203df0c(self->unk_d0);
    }
    if (self->unk_e4 != NULL) {
        func_02065804(data_0214a420, self->unk_e4);
        self->unk_e4 = NULL;
    }
    if (self->unk_e0 != NULL) {
        func_02065804(data_0214a420, self->unk_e0);
        self->unk_e0 = NULL;
    }
    func_ov000_0218c928(self);
}

Ov003Obj *func_ov003_021d0d0c(Ov003Obj *self) {
    Ov003Obj_DtorBody(self);
    return self;
}

Ov003Obj *func_ov003_021d0df0(Ov003Obj *self) {
    Ov003Obj_DtorBody(self);
    func_0203de1c(self);
    return self;
}

Ov003Obj *func_ov003_021d0edc(Ov003Obj *self) {
    Ov003Obj_DtorBody(self);
    return self;
}

typedef struct {
    u8 unk_00[0x12];
    u16 unk_12_0 : 12;
    u16 unk_12_12 : 2;
    u16 unk_12_14 : 2;
} Ov003InitInfo;

typedef struct {
    u8 unk_00[0xa];
    u16 unk_0a_0 : 3;
    u16 unk_0a_3 : 4;
    u16 unk_0a_7 : 3;
    u16 unk_0a_10 : 3;
    u16 unk_0a_13 : 1;
} Ov003InitParam;

typedef struct {
    u8 unk_00[0x18];
    u8 lo : 4;
    u8 hi : 4;
} Ov003InitShadow;

typedef struct {
    void *vtbl;
    u8 unk_04[0xa];
    u16 unk_0e;
    u8 unk_10[0x24];
    void *unk_34;
    u8 unk_38[4];
    Ov003InitShadow *unk_3c;
    void *unk_40;
    u8 unk_44[0x3a];
    u16 unk_7e;
    u8 unk_80[0x18];
    u16 unk_98;
    u8 unk_9a[0x16];
    Ov003InitParam *unk_b0;
    u8 unk_b4[0x24];
    void (*unk_d8)(void *p, u16 id);
    u8 unk_dc[0xe];
    u16 unk_ea_0 : 3;
    u16 unk_ea_3 : 7;
    u16 unk_ea_10 : 1;
} Ov003ObjInit;

extern void *func_0203dd9c(u32 size);
extern void *func_ov000_0218e9c4(void *p);
extern Ov003InitShadow *func_ov000_021919c8(void *p);
extern void func_ov000_02191b70(Ov003InitShadow *p);
extern void *func_ov000_02198328(void *p);
extern void func_ov000_02198360(void *p, s32 a, s32 b);

static inline void Ov003Shadow_Push(Ov003InitShadow *s, u8 v) {
    s->hi = s->lo;
    s->lo = v;
}

void func_ov003_021d0fc0(Ov003ObjInit *self) {
    Ov003InitInfo *info = (Ov003InitInfo *)func_0206fef8(self->unk_0e);
    void *p;
    self->unk_b0 = (Ov003InitParam *)((u8 *)func_02070558(self->unk_0e) + 0x10);
    p = func_0203dd9c(0x138);
    if (p != NULL) {
        p = func_ov000_0218e9c4(p);
    }
    self->unk_34 = p;
    if (self->unk_d8 != NULL) {
        self->unk_d8(p, self->unk_0e);
    } else {
        func_ov003_021d0a2c((Ov003Res *)p, self->unk_0e);
    }
    if (info->unk_12_12 != 0) {
        Ov003InitShadow *s = (Ov003InitShadow *)func_0203dd9c(0x1c);
        if (s != NULL) {
            s = func_ov000_021919c8(s);
        }
        self->unk_3c = s;
        if (info->unk_12_14 == 0) {
            Ov003Shadow_Push(s, 1);
        } else {
            Ov003Shadow_Push(s, 0);
        }
        func_ov000_02191b70(self->unk_3c);
    }
    p = func_0203dd9c(0x14);
    if (p != NULL) {
        p = func_ov000_02198328(p);
    }
    self->unk_40 = p;
    if (self->unk_b0->unk_0a_13) {
        func_ov000_02198360(p, 0x20, 0);
    }
    self->unk_98 = self->unk_7e;
    self->unk_ea_0 = self->unk_b0->unk_0a_7;
    self->unk_ea_10 = self->unk_b0->unk_0a_0 != 0;
}
