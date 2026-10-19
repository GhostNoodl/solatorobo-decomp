#include "ov013/ov013.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern u8 data_ov013_0220b03a[];
extern u8 data_ov013_0220b064[];
extern u8 data_ov013_0220b108[];
extern u8 data_ov013_0220b218[];
extern BOOL func_ov003_021d984c(void *p, void *tbl);
extern void func_ov003_021d95e8(void *p, void *tbl, s32 n);
extern void func_ov003_021d969c(void *p, s32 a);
extern Ov013Actor *func_ov000_0218e6d0(void *mgr, u16 a, u16 b);

void func_ov013_02202c88(Ov013Actor *self) {
    void *tbl = NULL;
    s32 n = 0;
    switch (FLD(u8, self, 0x15d)) {
    case 1:
        tbl = data_ov013_0220b03a;
        n = 7;
        break;
    case 2:
        tbl = data_ov013_0220b064;
        n = 7;
        break;
    }
    if (!func_ov003_021d984c((u8 *)self + 0x14c, tbl)) {
        func_ov003_021d95e8((u8 *)self + 0x14c, tbl, n);
    }
}

void func_ov013_02202cec(Ov013Actor *self) {
    void *tbl = NULL;
    s32 n = 0;
    switch (FLD(u8, self, 0x15d)) {
    case 1:
        tbl = data_ov013_0220b218;
        n = 0x14;
        break;
    case 2:
        tbl = data_ov013_0220b108;
        n = 0xc;
        break;
    }
    if (!func_ov003_021d984c((u8 *)self + 0x14c, tbl)) {
        func_ov003_021d95e8((u8 *)self + 0x14c, tbl, n);
    }
}

void func_ov013_02202d50(Ov013Actor *self) {
    BOOL f = FALSE;
    Ov013Actor *a;
    if (data_ov000_021ccd68 == NULL) {
        a = NULL;
    } else {
        a = func_ov000_0218e6d0(data_ov000_021ccd68, 0x4000, 0x483e);
    }
    if (a != NULL) {
        u8 k;
        if (a->unk_40 != NULL) {
            k = a->unk_40->unk_13;
        } else {
            k = 0;
        }
        if (k == 9) {
            f = TRUE;
        }
    }
    if (!f) {
        func_ov003_021d969c((u8 *)self + 0x14c, 0);
    } else {
        func_ov003_021d969c((u8 *)self + 0x14c, 1);
    }
}


extern u8 data_ov013_0220aedc[];
extern const Ov013Vec data_ov013_0220af40;
extern void *data_02097e4c;
extern Ov013Actor *func_ov000_0219bf90(void);
extern Ov013Actor *func_ov003_021da32c(u16 kind);
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void *func_ov000_02190a30(void *a, s32 b);
extern void func_ov000_0218fa28(void *a, void *b, void *c, void *d, const char *e, s32 f, s32 g);
extern void func_ov000_0218d988(Ov013Actor *self, Ov013Actor *t, s32 a);
extern void func_ov003_021d9980(Ov013Vec *out, u16 rot, const Ov013Vec *v);
extern void VEC_Add(const Ov013Vec *a, const Ov013Vec *b, Ov013Vec *out);
extern void func_ov013_02204910(Ov013Actor *self, u16 a, u16 b, u16 c, u16 d);
extern void func_ov013_0220498c(Ov013Actor *self, s32 a);
extern void func_ov013_02204978(Ov013Actor *self, u16 a);
extern u32 func_ov013_02204968(Ov013Actor *self);
extern Ov013V *func_02065f88(s32 id, Ov013Vec *pos);
extern void func_0204a028(void *a, s32 b, Ov013Vec *c, s32 d);

static inline void Ov013_PartFlagB2(void *m, s32 i) {
    if (func_ov000_02190a30(m, i) != NULL) {
        FLD(Ov013Flags8, func_ov000_02190a30(m, i), 0x111).b2 = 1;
    }
}

static inline void Ov013_PartFlagB3(void *m, s32 i, s32 v) {
    if (func_ov000_02190a30(m, i) != NULL) {
        FLD(Ov013Flags8, func_ov000_02190a30(m, i), 0x111).b3 = v;
    }
}

static inline Ov013Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov013_02202dc8(Ov013Actor *self, u16 a, s32 b, BOOL c, u16 d) {
    FLD(Ov013Flags8, self, 0xf0).b4 = 0;
    switch (self->unk_40->state) {
    case 0: {
        Ov013Actor *o;
        const char *anim;
        void *m;
        self->unk_90 = func_ov000_0219bf90()->id;
        o = func_ov003_021da32c(0x483e);
        FLD(Ov013Flags8, o, 0x16).b0 = 1;
        FLD(u16, self, 0xf2) = o->id;
        anim = FLD(const char *, data_ov013_0220aedc, 4);
        func_ov000_02190cb0(self->unk_38, anim, 0x266, 0);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *p = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, p, FLD(void *, FLD(void *, p, 0x48), 8), anim, 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        m = self->unk_38;
        if (m != NULL) {
            Ov013_PartFlagB2(m, 0);
            Ov013_PartFlagB2(m, 1);
            Ov013_PartFlagB2(m, 3);
            Ov013_PartFlagB2(m, 4);
        }
        self->unk_40->state = 0x1e;
        break;
    }
    case 0x1e: {
        void *m;
        func_ov000_02190cb0(self->unk_38, FLD(const char *, data_ov013_0220aedc, 0x18), 0x1000, 0);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *p = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, p, FLD(void *, FLD(void *, p, 0x48), 8), FLD(const char *, data_ov013_0220aedc, 4), 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        self->unk_40->state = 0x1f;
        break;
    }
    case 0x1f: {
        Ov013Actor *t;
        Ov013Actor *o;
        Ov013Vec v;
        void *m;
        t = Ov013_FindActor(self->unk_90);
        if (t != NULL) {
            func_ov000_0218d988(self, t, self->unk_b0->unk_02);
        }
        if (FLD(s16, self->unk_38, 0xc4) != 1) {
            break;
        }
        o = Ov013_FindActor(FLD(u16, self, 0xf2));
        FLD(Ov013Flags8, self, 0xf0).b3 = 0;
        func_ov003_021d9980(&v, self->rot[1], &data_ov013_0220af40);
        VEC_Add(&v, &self->pos, &v);
        o->pos.x = v.x;
        o->pos.y = v.y;
        o->pos.z = v.z;
        func_ov013_02204910(o, self->id, self->unk_90, self->rot[1], a);
        func_ov013_0220498c(o, b);
        if (c) {
            func_ov013_02204978(o, d);
        }
        func_02065f88(0x57a, &self->pos)->v0c(0x2800);
        m = self->unk_38;
        if (m != NULL) {
            Ov013_PartFlagB3(m, 0, 1);
            Ov013_PartFlagB3(m, 1, 1);
            Ov013_PartFlagB3(m, 3, 1);
            Ov013_PartFlagB3(m, 4, 1);
        }
        func_0204a028(data_02097e4c, 0x2b, &self->pos, -5);
        self->unk_40->state = 0x28;
        break;
    }
    case 0x28: {
        Ov013Actor *o = Ov013_FindActor(FLD(u16, self, 0xf2));
        Ov013Actor *t = Ov013_FindActor(self->unk_90);
        Ov013Vec v;
        if (o == NULL || t == NULL) {
            FLD(Ov013Flags8, self, 0xf0).b5 = 1;
            self->unk_40->state = 0x3c;
            break;
        }
        if (FLD(void *, o, 0x4c) != NULL && t->id == FLD(u16, FLD(void *, o, 0x4c), 0x1c)) {
            FLD(Ov013Flags8, self, 0xf0).b5 = 0;
            self->unk_40->state = 0x3c;
            break;
        }
        if (!func_ov013_02204968(o)) {
            break;
        }
        FLD(Ov013Flags8, self, 0xf0).b5 = 1;
        v.x = o->pos.x;
        v.y = o->pos.y;
        v.z = o->pos.z;
        if (VEC_Distance(&self->pos, &v) >= 0x3000) {
            break;
        }
        func_0204a028(data_02097e4c, 0x66, &self->pos, -5);
        FLD(Ov013Flags8, self, 0xf0).b3 = 1;
        o->v08();
        self->unk_40->state = 0x3c;
        break;
    }
    case 0x3c: {
        void *m;
        func_ov003_021d969c((u8 *)self + 0x14c, FLD(Ov013Flags8, self, 0xf0).b5);
        m = self->unk_38;
        if (m != NULL) {
            Ov013_PartFlagB3(m, 0, 0);
            Ov013_PartFlagB3(m, 1, 0);
            Ov013_PartFlagB3(m, 3, 0);
            Ov013_PartFlagB3(m, 4, 0);
        }
        if (!func_ov000_02191120(self->unk_38)) {
            break;
        }
        FLD(u16, self, 0xf2) = 0xffff;
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    }
}

extern s32 func_ov000_0218fd84(void *p);
extern void func_ov013_022065d8(Ov013Actor *o, u16 a);
extern void func_ov013_022065e0(Ov013Actor *o, s32 a);
extern void func_02049f44(void *a, s32 b, Ov013Vec *c, s32 d);

struct Ov013Rot3 {
    u16 x;
    u16 y;
    u16 z;
};

void func_ov013_02203494(Ov013Actor *self, BOOL a, BOOL b, u16 c, s32 d) {
    switch (self->unk_40->state) {
    case 0: {
        void *m;
        func_ov000_02190cb0(self->unk_38, FLD(const char *, data_ov013_0220aedc, 0x38), 0x1000, 1);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *p = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, p, FLD(void *, FLD(void *, p, 0x48), 8), FLD(const char *, data_ov013_0220aedc, 4), 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        self->unk_40->state = 10;
        break;
    }
    case 10:
        func_ov000_0218d988(self, Ov013_FindActor(self->unk_90), 0x80);
        if ((u16)(s16)(FLD(s16, self->unk_38, 0xc4) - 1) <= 1) {
            self->unk_40->state = 20;
        }
    case 20: {
        u16 rot = self->rot[1];
        BOOL fire = FALSE;
        if (b && FLD(s16, self->unk_38, 0xc4) == 1) {
            rot = self->rot[1] + 0x1555;
            fire = TRUE;
        }
        if (a && FLD(s16, self->unk_38, 0xc4) == 2) {
            rot = self->rot[1] + 0xeaaa;
            fire = TRUE;
        }
        if (fire) {
            Ov013Vec v;
            Ov013Vec w;
            Ov013Actor *o;
            void *m = self->unk_38;
            v.x = FLD(s16, m, 0xc6) << 4;
            v.y = FLD(s16, m, 0xc8) << 4;
            v.z = FLD(s16, m, 0xca) << 4;
            if (self != NULL) {
                func_ov003_021d9980(&v, self->rot[1], &v);
            }
            {
                Ov013Rot3 r = {0, 0, 0};
                r.y = rot;
                VEC_Add(&self->pos, &v, &w);
                o = func_ov003_021da32c(0x4807);
                o->pos.x = w.x;
                o->pos.y = w.y;
                o->pos.z = w.z;
                *(Ov013Rot3 *)o->rot = r;
            }
            o->unk_90 = self->unk_90;
            FLD(u16, FLD(void *, o, 0x4c), 0x1c) = self->id;
            FLD(s32, o, 0x60) = d;
            func_ov013_022065d8(o, c);
            func_ov013_022065e0(o, 1);
            FLD(Ov013Flags8, o, 0x16).b0 = 1;
            func_02049f44(data_02097e4c, 0x54, &self->pos, 0);
        }
        if (func_ov000_0218fd84(func_ov000_02190a30(self->unk_38, 0))) {
            self->unk_40->state = 100;
        }
        break;
    }
    case 100: {
        void *m;
        const char *anim;
        func_ov003_021d969c((u8 *)self + 0x14c, 1);
        anim = FLD(const char *, data_ov013_0220aedc, 4);
        func_ov000_02190cb0(self->unk_38, anim, 0x266, 0);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *p = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, p, FLD(void *, FLD(void *, p, 0x48), 8), anim, 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        m = self->unk_38;
        if (m != NULL) {
            Ov013_PartFlagB2(m, 0);
            Ov013_PartFlagB2(m, 1);
            Ov013_PartFlagB2(m, 3);
            Ov013_PartFlagB2(m, 4);
        }
        break;
    }
    }
}
}
