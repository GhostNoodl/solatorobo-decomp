#include "ov015/ov015.h"

#pragma pool_strings on
#pragma dont_reuse_strings off

extern "C" {

void func_ov015_02208474(u8 *self);
BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void func_ov000_02190e98(void *a, s32 b, s32 c, s32 d);
void func_ov000_021911c8(void *a, s32 b);
s32 func_ov000_021909a8(void *a, const void *b, const void *c);

BOOL func_ov000_0218f110(void *p);
void func_ov000_02191b70(void *p);
BOOL func_ov000_02191b9c(void *p);
extern const char *data_ov015_02212cac[];
extern const char *data_ov015_02212cb4[];
extern const char *data_ov015_02212cbc[];
extern const char *data_ov015_02212cc4[];

// STD_CopyString (nitro/std.h) returns its destination; this TU was built against a void-returning
// declaration, and the char * result changes the scheduling of func_ov015_022078bc, so the calls
// go through a void view of the same function.
typedef void (*Ov015CopyStringFn)(char *dst, const char *src);
#define OV015_COPY_STRING(d, s) ((Ov015CopyStringFn)STD_CopyString)(d, s)

static inline void Ov015_SetModel(Ov015Anim *o, const char *file, const char *name) {
    OV015_COPY_STRING(o->unk_10, file);
    OV015_COPY_STRING(o->unk_30, name);
    o->unk_03_1 = 1;
}
static inline void Ov015_SetAnim(Ov015Anim *o, const char *file, const char *name) {
    OV015_COPY_STRING(o->unk_4c, file);
    OV015_COPY_STRING(o->unk_6c, name);
    o->unk_03_2 = 1;
}

BOOL func_ov015_022078bc(Ov015Ship *self) {
    s32 kq;
    BOOL r = FALSE;
    switch (self->unk_d38) {
    case 10:
        Ov015_SetModel(&self->unk_00, data_ov015_02212cc4[self->unk_d48], data_ov015_02212cac[self->unk_d48]);
        Ov015_SetAnim(&self->unk_00, "mc/c1rob4", "c1rob4");
        self->unk_00.unk_00 = 0;
        Ov015_SetModel(&self->unk_220, data_ov015_02212cc4[self->unk_d48], data_ov015_02212cb4[self->unk_d48]);
        Ov015_SetAnim(&self->unk_220, "mc/c1rob4", "c1rob4cha");
        self->unk_220.unk_00 = 0;
        {
            const char *n = data_ov015_02212cbc[self->unk_d48];
            OV015_COPY_STRING(self->unk_a98.unk_10, data_ov015_02212cc4[self->unk_d48]);
            OV015_COPY_STRING(self->unk_a98.unk_30, n);
        }
        self->unk_a98.unk_00 = 0;
        self->unk_a98.unk_03_1 = 1;
        kq = 0xcb8;
        if ((u32)self & 3) {
            kq = 0xcb8;
        }
        func_ov000_02191b70((u8 *)self + kq);
        self->unk_d38 = 20;
        break;
    case 20: {
        BOOL ok = TRUE;
        BOOL t;
        u8 k;
        if (self->unk_00.unk_00 >= 0 && !func_ov000_0218f110(self)) ok = FALSE;
        if (self->unk_220.unk_00 >= 0 && !func_ov000_0218f110(&self->unk_220)) ok = FALSE;
        if (self->unk_a98.unk_00 >= 0 && !func_ov000_0218f110(&self->unk_a98)) ok = FALSE;
        k = self->unk_cb8.state;
        t = TRUE;
        if (k != 3 && k != 0) t = FALSE;
        if (!t && !func_ov000_02191b9c(&self->unk_cb8)) ok = FALSE;
        if (ok) {
            self->unk_d38 = 30;
            r = TRUE;
        }
        break;
    }
    case 30:
        r = TRUE;
        break;
    }
    return r;
}

BOOL func_ov015_02207adc(Ov015Ship *self) {
    s32 i;
    func_ov000_0218ffdc(&self->unk_138, self, 0, 1);
    func_ov000_02190cb0(&self->unk_138, "ang00", 0x1000, 0);
    func_ov000_021915a0(&self->unk_138);
    NNS_G3dRenderObjSetInitFunc((NNSG3dRenderObj *)(&self->unk_138.unk_24), (NNSG3dSbcCallBackFunc)func_ov015_02208474);
    self->unk_138.unk_c2.b5 = 0;
    self->unk_138.unk_c2.b8 = 1;
    self->unk_cd4.id = func_ov000_021909a8(&self->unk_138, self->unk_00.unk_6c, "ang05");
    for (i = 0; i < 8; i++) {
        func_ov000_0218ffdc(&self->unk_358[i], &self->unk_220, 0, 1);
        func_ov000_02190e98(&self->unk_358[i], 0, 0x1000, 0);
        func_ov000_021915a0(&self->unk_358[i]);
        func_ov000_021911c8(&self->unk_358[i], 0);
        self->unk_358[i].unk_a8 = 0x1333;
        self->unk_358[i].unk_ac = 0x1333;
        self->unk_358[i].unk_b0 = 0x1c00;
    }
    func_ov000_0218ffdc(&self->unk_bd0, &self->unk_a98, 0, 1);
    self->unk_cb8.prev = self->unk_cb8.type;
    self->unk_cb8.type = 3;
    self->unk_cb8.unk_14 = 0x2000;
    self->unk_d38 = 0x32;
    return TRUE;
}


extern const void *data_ov015_02212634[];
extern u16 data_ov015_0221262c[];
void func_ov000_02191618(void *a);
void func_ov000_02190a80(void *a, s32 b);
void func_ov000_02191780(void *a);
void func_ov000_021917f8(void *a);
u16 func_01ffc128(u16 a, u16 b, s32 c, s32 d, s32 e);
s32 Rand_PlusMinus(s32 max);
s32 Rand_UpTo(s32 max);
Ov015V *func_02065f88(s32 id, void *pos);
s32 func_02065748(void *a, void *b);

void func_ov015_02207c30(Ov015Ship *self) {
    u16 ang = 0x8000;
    switch (self->unk_d3a) {
    case 0:
        func_ov000_02190cb0(&self->unk_138, data_ov015_02212634[self->unk_d3a], 0x155, 0);
        func_ov000_021915a0(&self->unk_138);
        break;
    case 1:
    case 2:
    case 3:
        func_ov000_02190cb0(&self->unk_138, data_ov015_02212634[self->unk_d3a], 0x2ab, 0);
        func_ov000_02191618(&self->unk_138);
        ang = data_ov015_0221262c[self->unk_d3a] + Rand_PlusMinus(0x800);
        break;
    }
    func_ov000_02190a80(&self->unk_138, 0x1000);
    if (self->unk_d40) {
        self->unk_d22 = func_01ffc128(ang, self->unk_d22, 0x19a, 1, 0x8000);
    }
    if (self->unk_d3c == 1) {
        s32 v = self->unk_d3e;
        BOOL neg = FALSE;
        s32 i;
        if (v < 0) {
            v = (s16)-v;
            neg = TRUE;
        }
        for (i = 0; i < 8; i++) {
                func_ov000_021911c8(&self->unk_358[i], v);
            if (neg) {
                func_ov000_02191780(&self->unk_358[i]);
            } else {
                func_ov000_021917f8(&self->unk_358[i]);
            }
            func_ov000_02190a80(&self->unk_358[i], 0x1000);
        }
    }
    if (self->unk_d42) {
        if (self->unk_d28 == NULL) {
            Ov015VecC p = *(Ov015VecC *)&self->unk_cd4.m[3];
            Ov015V *e = func_02065f88(0x322, &p);
            self->unk_d28 = e;
            e->v14(0x1333, 0x1333, 0x1333);
            self->unk_d28->v34(0, 0, (u16)Rand_UpTo(0x3fff));
            FLD(s32, self->unk_d28, 0xc8) = -1;
            self->unk_d28->v08(3);
            FLD(s32, self->unk_d28, 0x3c) = 0x2000;
            self->unk_d2c = 0x5a;
        } else {
            if (Rand_UpTo(100) < 5) {
                Ov015VecC p = FLD(Ov015VecC, self->unk_d28, 0x58);
                Ov015V *e = func_02065f88(0x320, &p);
                e->v14(0x800, 0x800, 0x800);
                e->v08(3);
            }
            if (--self->unk_d2c < 0) {
                self->unk_d28->v34(0, 0, (u16)Rand_UpTo(0x3fff));
                self->unk_d2c = 0x5a;
            }
        }
        if (self->unk_d30 == NULL) {
            Ov015V *e = func_02065f88(0x322, &self->unk_d4c);
            self->unk_d30 = e;
            e->v34(0, 0, 0x3fff);
            FLD(s32, self->unk_d30, 0xc8) = -1;
            self->unk_d30->v08(1);
            FLD(s32, self->unk_d30, 0x50) = -0xaa000;
            FLD(s32, self->unk_d30, 0x54) = -0x37000;
            self->unk_d34 = 10;
        } else {
            if (--self->unk_d34 < 0) {
                self->unk_d34 = 0;
            }
        }
    } else {
        if (func_02065748(data_0214a420, self->unk_d28)) {
            void *saved;
            HEAP_PUSH(saved);
            DELETE_V(self->unk_d28);
            HEAP_POP(saved);
        }
        if (func_02065748(data_0214a420, self->unk_d30)) {
            void *saved;
            HEAP_PUSH(saved);
            DELETE_V(self->unk_d30);
            HEAP_POP(saved);
        }
    }
}

}
