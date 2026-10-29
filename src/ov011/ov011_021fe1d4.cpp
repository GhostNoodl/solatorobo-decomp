#include "ov011/ov011.h"

struct Ov011Bit01 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
};

static inline void Ov011Ent_Lerp2(Ov011Ent *e, s32 to, s32 frames) {
    s32 c = e->unk_0c;
    if (e->b0) {
        e->b2 = 1;
        Ov011_SetLerp(&e->unk_0c, c, to, frames);
    }
}

static inline void Ov011Ent_Lerp3(Ov011Ent *e, s32 to, s32 frames) {
    u16 c = e->unk_18;
    if (e->b0) {
        e->b3 = 1;
        Ov011_SetLerp(&e->unk_18, c, to, frames);
    }
}

static inline void Ov011Ent_Lerp4(Ov011Ent *e, s32 to, s32 frames) {
    s32 c = e->unk_24;
    if (e->b0) {
        e->b4 = 1;
        Ov011_SetLerp(&e->unk_24, c, to, frames);
    }
}

static inline BOOL Ov011Ent_Done4(Ov011Ent *e) {
    BOOL r = FALSE;
    if (e->b0) {
        r = !e->b4;
    }
    return r;
}

static inline BOOL Ov011Ent_Done2(Ov011Ent *e) {
    BOOL r = FALSE;
    if (e->b0) {
        r = !e->b2;
    }
    return r;
}

static inline BOOL Ov011Ent_Done3(Ov011Ent *e) {
    BOOL r = FALSE;
    if (e->b0) {
        r = !e->b3;
    }
    return r;
}

static inline BOOL Ov011Ent_AllDone(Ov011Ent *e) {
    if (!Ov011Ent_Done4(e)) {
        return FALSE;
    }
    if (!Ov011Ent_Done2(e)) {
        return FALSE;
    }
    if (!Ov011Ent_Done3(e)) {
        return FALSE;
    }
    return TRUE;
}

static inline Ov011PNode *Ov011Ent_Find(Ov011Ent *e, void *k) {
    Ov011PNode *r = NULL;
    Ov011PNode *n;
    if (e->b0) {
        for (n = e->unk_04; n != NULL; n = n->next) {
            if (k == n) {
                r = n;
                break;
            }
        }
    }
    return r;
}

extern "C" {


u32 func_ov011_02201244(void *self);
BOOL func_ov000_02198360(void *a, s32 b, s32 c);
void *func_ov011_02201254(void *self);
void VEC_Add(const Ov011Vec *a, const Ov011Vec *b, Ov011Vec *c);


#pragma force_active on
void func_ov011_021fe1d4(u8 *self) {
    Ov011Node *n;
    switch (FLD(u16, self, 0x20)) {
    case 0:
        if (FLD(Ov011Bit01, self, 0x1b4).b0) {
            void *o = FLD(void *, self, 8);
            FLD(Ov011Bit01, self, 0x1b4).b1 = 1;
            FLD(u16, self, 0x1b6) = FLD(u16, o, 0xc);
            FLD(void *, self, 0x1b8) = self;
            FLD(void *, self, 0x1bc) = self + 0x204;
            func_ov000_02198360(self + 0x1c0, 2, 0);
        }
        FLD(u16, self, 0x20) = 1;
        break;
    case 1: {
        BOOL r = FALSE;
        if (FLD(Ov011Bit01, self, 0x1b4).b0) {
            r = !FLD(Ov011Bit01, self, 0x1b4).b1;
        }
        if (r) {
            FLD(u16, self, 0x20) = 2;
            FLD(Ov011Bit01, self, 0).b2 = 1;
        }
        break;
    }
    }
    for (n = FLD(Ov011Node *, self, 0xc); n != NULL; n = n->next) {
        void *a = Ov011_FindActor(n->id);
        if (func_ov011_02201244(a)) {
            void *owner = FLD(void *, self, 8);
            if (Ov011Ent_Find((Ov011Ent *)(self + 0x204), func_ov011_02201254(a)) != NULL) {
                Ov011PNode *p = Ov011Ent_Find((Ov011Ent *)(self + 0x204), func_ov011_02201254(a));
                Ov011Vec r;
                Ov011Vec o;
                Ov011Vec v;
                v.x = p->v.x;
                v.y = p->v.y;
                v.z = p->v.z;
                o.x = FLD(s32, owner, 0x70);
                o.y = FLD(s32, owner, 0x74);
                o.z = FLD(s32, owner, 0x78);
                VEC_Add(&v, &o, &r);
                FLD(s32, a, 0x70) = r.x;
                FLD(s32, a, 0x74) = r.y;
                FLD(s32, a, 0x78) = r.z;
            }
        }
    }
}
#pragma force_active reset
}
