#include "ov010/ov010.h"

struct Ov010Heap022 {
    u32 cur;
    u32 unk_04;
    u32 def;
};

struct Ov010Snd {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 4;
    u8 unk_01;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
};

struct Ov010Rot3 {
    u16 x;
    u16 y;
    u16 z;
};

static inline void Ov010Snd_Init(Ov010Snd *s, u16 id) {
    s->b0 = 1;
    s->b1 = 0;
    s->b2 = 0;
    s->b3 = 0;
    s->unk_02 = id;
    s->unk_04 = 0;
    s->unk_06 = 0;
    s->unk_08 = 0;
    s->unk_0c = 0;
    s->unk_10 = 0;
    s->unk_14 = 0;
    s->unk_18 = 0x1be;
    s->unk_1c = -0x125e;
}

extern "C" {

extern u8 data_ov010_0220fe5c[];
extern const u8 data_ov003_021f4340;
extern void func_ov000_02194758(void *self);
extern void func_ov000_02198360(void *a, s32 b, s32 c);
extern void func_0203f364(void *p);
extern void func_ov003_021cf330(void *p, void *d, s32 c);

extern u8 data_ov010_0220fe6c[];
extern u8 data_ov010_0220efc8[];
extern Ov010Heap022 *data_02097dd0;
extern void *data_0214a420;

extern void func_ov000_02194074(void *self);
extern void func_ov000_0219429c(void *self);
extern void func_ov003_021cf2bc(void *p);
extern void func_ov003_021cf2d8(void *p);
extern void func_02065860(void *a, s32 b);
extern void MTX_RotZ33_(void *m, s32 s, s32 c);
extern void MTX_RotX33_(void *m, s32 s, s32 c);
extern void MTX_RotY33_(void *m, s32 s, s32 c);
extern void MTX_Concat33(void *a, void *b, void *c);
extern void MI_Copy36B(void *m, void *b);
extern void func_ov000_0218cea4(void *self);

static inline void Ov010_022020c8_Init(void *self) {
    FLD(Ov010Flags8, self, 0xce).b0 = 0;
    FLD(Ov010Flags8, self, 0xce).b1 = 0;
    FLD(Ov010Flags8, self, 0xce).b2 = 0;
    FLD(u16, self, 0xd0) = 0;
    FLD(s32, self, 0xd4) = -1;
    FLD(void *, self, 0xd8) = NULL;
    FLD(void *, self, 0xdc) = NULL;
    FLD(Ov010Vec, self, 0xf8) = FLD(Ov010Vec, self, 0xec) = FLD(Ov010Vec, self, 0xe0) = FLD(Ov010Vec, data_ov010_0220efc8, 0x38);
}

void *func_ov010_022020c8(void *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov010_0220fe6c;
    func_ov003_021cf2bc((u8 *)self + 0x104);
    Ov010_022020c8_Init(self);
    return self;
}

static inline void Ov010_022020c8_Dtor(void *self) {
    u32 saved;
    FLD(void *, self, 0) = data_ov010_0220fe6c;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(Ov010Snd *, self, 0xd8) != NULL) {
        Ov010Snd *s = FLD(Ov010Snd *, self, 0xd8);
        if (s != NULL) {
            if (s->b0) {
                s->b0 = 0;
                func_02065860(data_0214a420, s->unk_0c);
                func_02065860(data_0214a420, s->unk_10);
                s->unk_0c = 0;
                s->unk_10 = 0;
            }
            func_0203de1c(s);
        }
        FLD(Ov010Snd *, self, 0xd8) = NULL;
    }
    data_02097dd0->cur = saved;
    ((Ov010V *)((u8 *)self + 0x104))->v08();
    Ov010_022020c8_Init(self);
    func_ov003_021cf2d8((u8 *)self + 0x104);
    func_ov000_0219429c(self);
}

void *func_ov010_0220215c(void *self) {
    Ov010_022020c8_Dtor(self);
    return self;
}

void *func_ov010_0220228c(void *self) {
    Ov010_022020c8_Dtor(self);
    func_0203de1c(self);
    return self;
}

void func_ov010_022023c4(void *self) {
    u8 m1[0x24];
    u8 m2[0x24];
    FLD(Ov010Flags8, self, 0x93).b0 = 1;
    MTX_RotZ33_(m1, OV010_SIN(FLD(u16, self, 0x80)), OV010_COS(FLD(u16, self, 0x80)));
    MTX_RotX33_(m2, OV010_SIN(FLD(u16, self, 0x7c)), OV010_COS(FLD(u16, self, 0x7c)));
    MTX_Concat33(m1, m2, m1);
    MTX_RotY33_(m2, OV010_SIN(FLD(u16, self, 0x7e)), OV010_COS(FLD(u16, self, 0x7e)));
    MTX_Concat33(m1, m2, m1);
    MI_Copy36B(m1, FLD(u8 *, self, 0x38) + 0x84);
    FLD(Ov010Vec, FLD(u8 *, self, 0x38), 0x78) = FLD(Ov010Vec, self, 0x70);
    func_ov000_0218cea4(self);
}

struct Ov010Shot22 {
    u8 unk_00[0x70];
    Ov010Vec pos;
    Ov010Rot3 rot;
    u8 unk_82[0xe];
    u16 unk_90;
    u8 unk_92[0x3c];
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_cf;
    u16 unk_d0;
    s32 unk_d4;
    void *unk_d8;
    void *unk_dc;
    Ov010Vec unk_e0;
    Ov010Vec unk_ec;
};

void func_ov010_022024c4(Ov010Shot22 *self, u16 a, const Ov010Vec *pos, const Ov010Vec *v, const Ov010Rot3 *rot) {
    if (self->b0) {
        return;
    }
    self->unk_90 = a;
    self->unk_d4 = 0;
    self->b0 = 1;
    self->pos = *pos;
    self->unk_ec = *v;
    self->rot = *rot;
    self->unk_d0 = 0;
    self->unk_e0 = FLD(Ov010Vec, data_ov010_0220efc8, 0x38);
}

void func_ov010_02202560(Ov010Shot22 *self, u16 a, const Ov010Vec *pos, const Ov010Vec *v, const Ov010Rot3 *rot) {
    if (self->b0) {
        return;
    }
    self->unk_90 = a;
    self->unk_d4 = 1;
    self->b0 = 1;
    self->pos = *pos;
    self->unk_ec = *v;
    self->rot = *rot;
    self->unk_d0 = 0;
    self->unk_e0 = FLD(Ov010Vec, data_ov010_0220efc8, 0x38);
}

void func_ov010_02202600(void *self, void *fn) {
    FLD(void *, self, 0xdc) = fn;
}

void func_ov010_02202608(void *self) {
    void *m;
    Ov010Snd *s;
    u8 c;
    func_ov000_02194758(self);
    FLD(Ov010Flags, FLD(void *, self, 0x38), 0xc2).b0 = 0;
    func_ov000_02198360(FLD(void *, self, 0x40), 0x20, 0);
    m = FLD(void *, self, 0x48);
    FLD(Ov010Flags, m, 0x9a).b1 = 0;
    FLD(Ov010Flags, m, 0x9a).b4 = 0;
    FLD(Ov010Flags, FLD(void *, self, 0x48), 0x9a).b7 = 1;
    m = FLD(void *, self, 0x48);
    FLD(Ov010Flags, m, 0x9a).b0 = 0;
    FLD(Ov010Flags, m, 0x9a).b3 = 0;
    func_0203f364(m);
    c = data_ov003_021f4340;
    FLD(Ov010Flags, FLD(void *, self, 0x48), 0x9a).b6 = 0;
    FLD(s32, FLD(void *, self, 0x48), 0x30) = 0;
    FLD(s32, FLD(void *, self, 0x44), 0x1c) = FLD(s32, self, 0x64) * 2;
    func_ov003_021cf330((u8 *)self + 0x104, data_ov010_0220fe5c, c);
    s = (Ov010Snd *)func_0203dd9c(sizeof(Ov010Snd));
    if (s != NULL) {
        s->b0 = 0;
    }
    FLD(Ov010Snd *, self, 0xd8) = s;
    Ov010Snd_Init(s, FLD(u16, self, 0xc));
}


}
