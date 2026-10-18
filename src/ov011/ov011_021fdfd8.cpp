#include "ov011/ov011.h"

struct Ov011Bit01 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
};

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
void *func_ov011_02201254(void *self);
void VEC_Add(const Ov011Vec *a, const Ov011Vec *b, Ov011Vec *c);

struct Ov011KeyVal {
    s32 key;
    s32 val;
};
extern const Ov011KeyVal data_ov011_02207380[];
void func_ov011_021fb8d4(void *a, s32 b, void *c, void *d);

void func_ov011_021fdfd8(u8 *self) {
    Ov011Node *n;
    switch (FLD(u16, self, 0x20)) {
    case 0: {
        u8 key = FLD(u8, self, 0x33);
        s32 v = -1;
        u32 i;
        for (i = 0; i < 2; i++) {
            s32 k = data_ov011_02207380[i].key;
            if (k == key) {
                v = data_ov011_02207380[i].val;
            }
        }
        func_ov011_021fb8d4(self + 0xb4, v, self, self + 0x204);
        FLD(u16, self, 0x20) = 1;
        break;
    }
    case 1: {
        BOOL r = FALSE;
        if (FLD(Ov011Bit01, self, 0xb4).b0) {
            r = !FLD(Ov011Bit01, self, 0xb4).b1;
        }
        if (r) {
            FLD(u16, self, 0x20) = 2;
            FLD(Ov011Bit01, self, 0).b2 = 1;
        }
        break;
    }
    case 2:
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
        break;
    }
}

}
