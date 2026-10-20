#include "types.h"

typedef struct {
    s32 m[4][3];
} Mtx43_02194758;

typedef struct {
    u8 kind;
    u8 pad;
    u16 type : 3;
    u16 b3 : 1;
    u16 b4 : 3;
    u16 b7 : 1;
    u16 rest : 8;
} Param02194758;

typedef struct {
    u8 pad[0x10];
    s16 unk_10;
    u16 b0 : 1;
    u16 rest : 15;
    s16 unk_14;
    s16 unk_16;
} Info02194758;

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
} Obj48_02194758;

typedef struct {
    u8 pad00[0x10];
    s32 unk_10;
    u8 pad14[0x8];
    s32 unk_1c;
    u16 unk_20;
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 rest : 10;
} Obj44_02194758;

typedef struct {
    u8 pad00[0xb4];
    u16 unk_b4;
} Model02194758;

typedef struct {
    u8 pad00[0x5c];
    s32 unk_5c;
} Obj5c_02194758;

typedef struct {
    u8 pad00[0x14];
    s32 unk_14;
} Obj3c_02194758;

typedef struct {
    u8 pad00[0x18];
    u8 b0 : 5;
    u8 b5 : 1;
    u8 b6 : 2;
} Obj4c_02194758;

typedef struct {
    u8 pad00[0x84];
    void **unk_84;
} Res02194758;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec02194758;

typedef struct {
    u8 pad00[0xc];
    u16 unk_0c;
    u16 id;
    u8 pad10[0x24];
    Res02194758 *unk_34;
    Model02194758 *unk_38;
    Obj3c_02194758 *unk_3c;
    void *unk_40;
    Obj44_02194758 *unk_44;
    Obj48_02194758 *unk_48;
    Obj4c_02194758 *unk_4c;
    u8 pad50[0x8];
    void *unk_58;
    Obj5c_02194758 *unk_5c;
    u8 pad60[0x4];
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    Vec02194758 pos;
    u16 rx;
    u16 ry;
    u16 rz;
    u8 pad82[0x16];
    u16 unk_98;
    u8 pad9a[0x16];
    Param02194758 *unk_b0;
    u8 padb4[0x18];
    u16 cc_0 : 1;
    u16 cc_1 : 15;
} Actor02194758;

extern "C" {
extern const s16 FX_SinCosTable_[];
void *func_0203dd9c(u32 size);
Info02194758 *func_0206fef8(u16 id);
void *func_020704b4(u16 id);
Model02194758 *func_ov000_0218fe1c(void *p);
void func_ov000_0219badc(Model02194758 *m, Res02194758 *res, Info02194758 *info);
Obj48_02194758 *func_ov000_021985e8(void *p);
void func_ov000_02198c8c(Obj48_02194758 *o, u16 id);
void func_0203f324(Obj48_02194758 *o);
void func_0203f364(Obj48_02194758 *o);
void func_ov000_0219864c(Obj48_02194758 *o, void *a, s32 b);
void func_ov000_02198360(void *p, s32 a, s32 b);
Obj44_02194758 *func_ov000_021984c8(void *p);
void func_ov000_021984f4(Obj44_02194758 *o, void *a, s32 b);
void *func_0203f80c(void *p);
void func_0203f990(void *mesh, void *res);
void func_0203f9b8(void *mesh, s32 scale);
void func_0203f9dc(void *mesh, const Mtx43_02194758 *mtx);
Obj5c_02194758 *func_ov000_021bd198(void *p);
void func_ov000_021bd314(Obj5c_02194758 *p, s32 a);
void MTX_Identity43_(Mtx43_02194758 *m);
void MTX_RotX43_(Mtx43_02194758 *m, s32 s, s32 c);
void MTX_RotY43_(Mtx43_02194758 *m, s32 s, s32 c);
void MTX_RotZ43_(Mtx43_02194758 *m, s32 s, s32 c);
void MTX_Concat43(Mtx43_02194758 *a, Mtx43_02194758 *b, Mtx43_02194758 *out);

#define SIN02194758(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define COS02194758(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

static inline Model02194758 *NewModel02194758(void) {
    void *p = func_0203dd9c(0xe8);
    if (p != NULL) {
        p = func_ov000_0218fe1c(p);
    }
    return (Model02194758 *)p;
}

static inline Obj48_02194758 *NewObj48_02194758(void) {
    void *p = func_0203dd9c(0x9c);
    if (p != NULL) {
        p = func_ov000_021985e8(p);
    }
    return (Obj48_02194758 *)p;
}

static inline Obj44_02194758 *NewObj44_02194758(void) {
    void *p = func_0203dd9c(0x24);
    if (p != NULL) {
        p = func_ov000_021984c8(p);
    }
    return (Obj44_02194758 *)p;
}

static inline void *NewMesh02194758(void) {
    void *p = func_0203dd9c(0x98);
    if (p != NULL) {
        func_0203f80c(p);
    }
    return p;
}

static inline Obj5c_02194758 *NewObj5c_02194758(void) {
    void *p = func_0203dd9c(0xa8);
    if (p != NULL) {
        func_ov000_021bd198(p);
    }
    return (Obj5c_02194758 *)p;
}

static inline void *GetRes02194758(Res02194758 *res) {
    return res->unk_84 != NULL ? *res->unk_84 : NULL;
}

void func_ov000_02194758(Actor02194758 *self) {
    Info02194758 *info = func_0206fef8(self->id);
    func_020704b4(self->id);
    self->unk_64 = info->unk_14 << 4;
    self->unk_68 = info->unk_16 << 4;
    self->unk_6c = self->unk_68 >> 1;
    self->unk_98 = self->ry;
    if (info->b0) {
        self->unk_38 = NewModel02194758();
        self->unk_38->unk_b4 = self->unk_0c;
        func_ov000_0219badc(self->unk_38, self->unk_34, info);
    }
    if (self->unk_3c != NULL) {
        self->unk_3c->unk_14 = self->unk_64 + (s32)((u32)self->unk_64 + (self->unk_64 >> 2));
    }
    if (self->unk_b0->type != 0) {
        Obj48_02194758 *o;
        self->unk_48 = NewObj48_02194758();
        func_ov000_02198c8c(self->unk_48, self->unk_0c);
        self->unk_48->unk_28 = 0x10;
        self->unk_48->unk_38 = self->unk_64;
        self->unk_48->unk_60 = self->unk_6c;
        o = self->unk_48;
        o->b0 = 1;
        o->b3 = 1;
        func_0203f324(o);
        *(u16 *)((u8 *)self->unk_48 + 0x9a) |= 0x12;
        if (self->unk_b0->type == 2) {
            o = self->unk_48;
            o->b3 = 0;
            func_0203f364(o);
        } else if (self->unk_b0->type == 3) {
            o = self->unk_48;
            o->b1 = 0;
            o->b4 = 0;
        }
        if (self->unk_64 >> 1 < 0x4cd) {
            self->unk_48->unk_48 = 0x4cd;
        }
        func_ov000_0219864c(self->unk_48, NULL, 0);
    } else {
        func_ov000_02198360(self->unk_40, 1, 0);
    }
    if (self->unk_b0->b4 != 0) {
        Obj44_02194758 *o;
        self->unk_44 = NewObj44_02194758();
        self->unk_44->unk_1c = self->unk_64;
        self->unk_44->unk_10 = self->unk_6c;
        self->unk_44->unk_20 = self->unk_0c;
        o = self->unk_44;
        o->b0 = 1;
        o->b1 = 1;
        if (self->unk_b0->b4 == 3) {
            self->unk_44->b4 = 1;
        } else if (self->unk_b0->b4 == 4) {
            self->unk_44->b5 = 1;
        }
        func_ov000_021984f4(self->unk_44, NULL, 0);
        if (self->unk_b0->b4 == 2) {
            if (self->unk_4c != NULL) {
                self->unk_4c->b5 = 1;
            }
        }
    }
    if (self->unk_b0->b3 && GetRes02194758(self->unk_34) != NULL) {
        Mtx43_02194758 t;
        Mtx43_02194758 m;
        void *mesh;
        u16 rx;
        u16 ry;
        u16 rz;
        BOOL set;
        self->unk_58 = NewMesh02194758();
        func_0203f990(self->unk_58, GetRes02194758(self->unk_34));
        func_0203f9b8(self->unk_58, info->unk_10);
        mesh = self->unk_58;
        rz = self->rz;
        ry = self->ry;
        rx = self->rx;
        set = FALSE;
        MTX_Identity43_(&m);
        if (rz != 0) {
            MTX_RotZ43_(&m, SIN02194758(rz), COS02194758(rz));
            set = TRUE;
        }
        if (ry != 0) {
            if (set) {
                MTX_RotY43_(&t, SIN02194758(ry), COS02194758(ry));
                MTX_Concat43(&t, &m, &m);
            } else {
                MTX_RotY43_(&m, SIN02194758(ry), COS02194758(ry));
                set = TRUE;
            }
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX43_(&t, SIN02194758(rx), COS02194758(rx));
                MTX_Concat43(&t, &m, &m);
            } else {
                MTX_RotX43_(&m, SIN02194758(rx), COS02194758(rx));
            }
        }
        m.m[3][0] = self->pos.x;
        m.m[3][1] = self->pos.y;
        m.m[3][2] = self->pos.z;
        func_0203f9dc(mesh, &m);
        self->cc_0 = 1;
    }
    if (self->unk_b0->b7) {
        Obj5c_02194758 *p = NewObj5c_02194758();
        self->unk_5c = p;
        func_ov000_021bd314(p, 1);
        self->unk_5c->unk_5c = self->unk_68;
    }
}

}
