#include "ov011/ov011.h"

struct Ov011Chr {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    s16 unk_02;
    s16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 id;
    s32 mode;
    Ov011Vec off;
    void *anim;
    void *model;
    s32 unk_24;
    Ov011Model2 m28;
    u8 s88[0xc];
    u8 s94[3][0xc];
};

typedef void (Ov011Chr::*Ov011ChrFn)();

struct Ov011ChrEntry {
    s32 key;
    Ov011ChrFn fn;
};

extern "C" {

extern u8 data_ov011_022079d0[];
extern u8 data_ov011_022079b0[];
extern u8 data_ov011_02207418[];
extern const Ov011ChrEntry data_ov011_022074b0[];
extern Ov011Vec data_ov011_02207438;
void func_ov003_021d7ca8(void *p);
void func_ov003_021d7ce0(void *p);
void func_ov003_021d7d8c(void *p);
void func_ov003_021d7dd0(void *p);
void func_ov003_021d7d24(void *p, s32 a, s32 b, s32 c, s32 d);
void func_02009e24(void *arr, s32 count, u32 size, void *ctor, void *dtor);
void *func_ov000_0218e9c4(void *p);
void *func_ov000_0218fe1c(void *p);
void func_ov000_0218ea20(void *p);
void func_ov000_0218fee4(void *p);
void func_ov000_02193e5c(void *p, s32 a);
void func_ov000_0218f110(void *p);
s32 func_0206fef8(u32 id);
void func_ov000_0219badc(void *a, void *b, s32 c);
void func_02012be8(const Ov011Vec *a, const Ov011Vec *b, Ov011Vec *out);
BOOL func_ov011_02200b88(Ov011Model2 *self, void *a, u32 b);
void func_ov011_02200c30(Ov011Model2 *self);
s32 func_ov011_02200aac(void *p, s32 b);
void func_ov000_021903b4(void *p);
}

static inline void Ov011_FreeModelP(void **pp) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (*pp != NULL) {
        void *p = *pp;
        if (p != NULL) {
            func_ov000_0218fee4(p);
            func_0203de1c(p);
        }
        *pp = NULL;
    }
    data_02097dd0->cur = saved;
}

static inline void Ov011_FreeAnimP(void **pp) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (*pp != NULL) {
        void *p = *pp;
        if (p != NULL) {
            func_ov000_0218ea20(p);
            func_0203de1c(p);
        }
        *pp = NULL;
    }
    data_02097dd0->cur = saved;
}

static inline void *Ov011_FindActorN(u16 id) {
    void *a = NULL;
    if (data_ov000_021ccd68 != NULL) {
        a = func_ov000_0218e640(data_ov000_021ccd68, id);
    }
    return a;
}

static inline void Ov011Model2_Reset(Ov011Model2 *m) {
    if (m->b0) {
        m->b0 = 0;
        Ov011_FreeModelP(&m->model);
        OV011_TWV(m->m0c)->v08();
        OV011_TWV(m->m3c)->v08();
    }
}

static inline void Ov011Chr_Reset(Ov011Chr *self) {
    u32 i;
    if (!self->b0) {
        return;
    }
    Ov011Model2_Reset(&self->m28);
    func_ov003_021d7d8c(self->s88);
    for (i = 0; i < 3; i++) {
        func_ov003_021d7d8c(self->s94[i]);
    }
    self->b0 = 0;
}

static inline void Ov011TwA_Ctor(void *obj) {
    FLD(void *, obj, 0) = data_ov011_022079d0;
    OV011_TW(obj)->b0 = 0;
}

static inline void Ov011Tw_SetBoth(Ov011Tw *t, const Ov011Vec *src) {
    s32 x;
    s32 y;
    s32 z;
    x = src->x;
    t->v08.x = x;
    y = src->y;
    t->v08.y = y;
    z = src->z;
    t->v08.z = z;
    t->v14.x = x;
    t->v14.y = y;
    t->v14.z = z;
}

static inline void Ov011TwB_Ctor(void *obj) {
    Ov011Tw *t;
    FLD(void *, obj, 0) = data_ov011_022079b0;
    t = OV011_TW(obj);
    t->b0 = 0;
    t->b1 = 0;
    t->unk_02 = 0;
    Ov011Tw_SetBoth(t, &FLD(Ov011Vec, data_ov011_02207418, 0x20));
}

extern "C" {

Ov011Chr *func_ov011_02201c18(Ov011Chr *self) {
    void *p;
    Ov011TwA_Ctor(self->m28.m0c);
    Ov011TwB_Ctor(self->m28.m3c);
    self->m28.b0 = 0;
    func_ov003_021d7ca8(self->s88);
    func_02009e24(self->s94, 3, 0xc, func_ov003_021d7ca8, func_ov003_021d7ce0);
    self->b0 = 0;
    self->b1 = 0;
    p = func_0203dd9c(0x138);
    if (p != NULL) {
        p = func_ov000_0218e9c4(p);
    }
    self->anim = p;
    p = func_0203dd9c(0xe8);
    if (p != NULL) {
        p = func_ov000_0218fe1c(p);
    }
    self->model = p;
    return self;
}

}

static inline void Ov011TwB_Dtor(void *obj) {
    FLD(void *, obj, 0) = data_ov011_022079b0;
    OV011_TWV(obj)->v08();
}

static inline void Ov011TwA_Dtor(void *obj) {
    FLD(void *, obj, 0) = data_ov011_022079d0;
    OV011_TWV(obj)->v08();
}

extern "C" {

void func_02009f64(void *arr, s32 count, u32 size, void *dtor);

Ov011Chr *func_ov011_02201d10(Ov011Chr *self) {
    Ov011Chr_Reset(self);
    Ov011_FreeAnimP(&self->anim);
    Ov011_FreeModelP(&self->model);
    func_02009f64(self->s94, 3, 0xc, func_ov003_021d7ce0);
    func_ov003_021d7ce0(self->s88);
    Ov011Model2_Reset(&self->m28);
    Ov011TwB_Dtor(self->m28.m3c);
    Ov011TwA_Dtor(self->m28.m0c);
    return self;
}

BOOL func_ov011_02201f28(Ov011Chr *self, u16 id, const Ov011Vec *off, u16 c, s16 d, s16 e) {
    void *a;
    u32 i;
    self->id = id;
    self->b0 = 1;
    self->unk_02 = e;
    self->unk_04 = d;
    self->unk_06 = c;
    self->unk_08 = 0;
    self->mode = 0;
    self->off = *off;
    self->unk_24 = 0;
    func_ov000_02193e5c(self->anim, 0x4812);
    a = Ov011_FindActorN(self->id);
    if (a != NULL) {
        Ov011Vec p;
        p = FLD(Ov011Vec, a, 0x70);
        func_02012be8(&p, &self->off, &p);
        FLD(Ov011Vec, self->model, 0x78) = p;
    }
    func_ov003_021d7d24(self->s88, 0, 0, 1, 0);
    for (i = 0; i < 3; i++) {
        func_ov003_021d7d24(self->s94[i], 0, 0, 1, 0);
    }
    return TRUE;
}

void func_ov011_0220205c(Ov011Chr *self) {
    Ov011Chr_Reset(self);
}

void func_ov011_02202130(Ov011Chr *self) {
    s32 key;
    u32 i;
    if (!self->b0) {
        return;
    }
    if (!FLD(volatile Ov011Flags8, self, 0).b1) {
        if (FLD(s16, self->anim, 0) < 0) {
            s32 r;
            self->b1 = 1;
            r = func_0206fef8(0x4812);
            FLD(u16, self->model, 0xb4) = 0xffff;
            func_ov000_0219badc(self->model, self->anim, r);
            FLD(Ov011Flags, self->model, 0xc2).b0 = 0;
            func_ov011_02200b88(&self->m28, self->anim, 0x4812);
        } else {
            func_ov000_0218f110(self->anim);
        }
        return;
    }
    key = self->mode;
    for (i = 0; i < 6; i++) {
        if (key == data_ov011_022074b0[i].key && *(s32 *)&data_ov011_022074b0[i].fn != 0) {
            (self->*data_ov011_022074b0[i].fn)();
            break;
        }
    }
    func_ov003_021d7dd0(self->s88);
    for (i = 0; i < 3; i++) {
        func_ov003_021d7dd0(self->s94[i]);
    }
    func_ov011_02200c30(&self->m28);
}

void func_ov011_02202260(Ov011Chr *self) {
    if (!self->b0) {
        return;
    }
    if (self->model != NULL) {
        Ov011Vec p;
        Ov011Vec sv;
        Ov011Vec sa;
        Ov011Vec q;
        Ov011Vec s;
        void *a = Ov011_FindActor(self->id);
        if (a != NULL) {
            p = FLD(Ov011Vec, a, 0x70);
            func_02012be8(&p, &self->off, &p);
            FLD(Ov011Vec, self->model, 0x78) = p;
        }
        sv = FLD(Ov011Vec, self->model, 0x78);
        sa = FLD(Ov011Vec, self->model, 0xa8);
        OV011_BLKCPY(&q, &sv);
        OV011_BLKCPY(&s, &sa);
        q.x += func_ov011_02200aac(self->s94[0], 0x19a);
        q.y += func_ov011_02200aac(self->s94[1], 0x19a);
        q.z += func_ov011_02200aac(self->s94[2], 0x19a);
        s.x += func_ov011_02200aac(self->s88, 0x19a);
        s.y = s.x;
        FLD(Ov011Vec, self->model, 0x78) = q;
        FLD(Ov011Vec, self->model, 0xa8) = s;
        func_ov000_021903b4(self->model);
        FLD(Ov011Vec, self->model, 0x78) = sv;
        FLD(Ov011Vec, self->model, 0xa8) = sa;
    }
    if (!self->m28.b0) {
        return;
    }
    if (!self->m28.b2) {
        return;
    }
    func_ov000_021903b4(self->m28.model);
}

void func_ov011_02202464(Ov011Chr *self) {
    if (self->b0) {
        self->unk_08 = 0;
        self->unk_24 = 0;
        self->mode = 1;
    }
}

void func_ov011_02202488(Ov011Chr *self, u16 v) {
    if (self->b0) {
        self->unk_24 = 0;
        self->mode = 3;
        self->unk_08 = v;
    }
}

void func_ov011_022024ac(Ov011Chr *self, u16 v) {
    if (self->b0 && v != 0) {
        self->unk_24 = 0;
        self->mode = 5;
        self->unk_08 = v;
    }
}


}
