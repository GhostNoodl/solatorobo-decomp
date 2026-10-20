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


struct Ov011SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov011Spawn_Init(Ov011SpawnDesc *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

struct Ov011Rot {
    s16 x, y, z;
};

struct Ov011B16 {
    u8 b0 : 1;
    u8 rest : 7;
};

struct Ov011Msg {
    s32 a;
    s32 b;
    s32 c;
};

struct Ov011MsgB {
    s32 a;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
    u8 pad;
    u16 c;
    s16 d;
};

struct Ov011Mtx33 {
    s32 m[9];
};

extern "C" {

u32 func_ov011_02201244(void *self);
void *func_ov011_02201254(void *self);
void VEC_Add(const Ov011Vec *a, const Ov011Vec *b, Ov011Vec *c);
void func_ov000_0219bdb0(u16 a, u16 b, s32 c, s32 d, s32 e, void *f);
u32 func_ov011_02201b64(void *p);
BOOL func_ov011_02201b40(void *p);
void func_ov011_02201aac(void *p, const Ov011Vec *v);
void func_ov011_02201b80(void *p, const Ov011Vec *v);
void func_ov011_02201bac(void *p, u16 ang);
void MTX_RotY33_(Ov011Mtx33 *m, s32 s, s32 c);
void MTX_MultVec33(const Ov011Vec *v, const Ov011Mtx33 *m, Ov011Vec *out);
extern const Ov011Vec data_ov011_02207290;
extern void *data_ov000_021ccd64;
void *func_ov000_0218bf1c(void *mgr, Ov011SpawnDesc *d, Ov011Vec *pos, Ov011Rot *rot, u16 a);
void func_ov011_022011c0(void *self, u16 v);
void func_ov011_022011c8(void *a, s32 b);
void func_ov011_02201214(void *self, void *p);
Ov011Node *func_ov003_021d77e0(void *self);

static inline void Ov011_Send(u16 id, s32 a, s32 b) {
    Ov011Msg m;
    m.a = a;
    m.b = b;
    func_ov000_0219bdb0(id, 0xffff, 0xe, 1, 0xc, &m);
}

static inline BOOL Ov011_NodeAlive(Ov011Node *n) {
    if (n != NULL) {
        void *a = Ov011_FindActor(n->id);
        if (a != NULL && func_ov011_02201244(a)) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline Ov011PNode *Ov011_NewPNode(const Ov011Vec *v) {
    Ov011PNode *n = (Ov011PNode *)func_0203dd9c(0x10);
    n->v.x = v->x;
    n->v.y = v->y;
    n->v.z = v->z;
    n->next = NULL;
    return n;
}

void func_ov011_021fe3b4(u8 *self) {
    Ov011Vec v;
    Ov011Vec p;
    Ov011Mtx33 m;
    Ov011Vec t;
    Ov011MsgB mb;
    Ov011Msg mc;
    Ov011SpawnDesc d;
    Ov011Vec r;
    Ov011Vec o;
    Ov011Vec w;
    Ov011Rot rot;
    Ov011Ent *e = (Ov011Ent *)(self + 0x204);
    Ov011Node *n;
    s32 cnt = 0;
    s32 rem;
    for (n = FLD(Ov011Node *, self, 0xc); n != NULL; n = n->next) {
        if (Ov011_NodeAlive(n) == TRUE) {
            cnt++;
        }
    }
    rem = 5 - cnt;
    switch (FLD(u16, self, 0x20)) {
    case 0: {
        u16 id = FLD(u16, FLD(void *, self, 8), 0xc);
        mb.a = 2;
        mb.b0 = 0;
        mb.b1 = 0;
        mb.c = 0;
        mb.d = 0x1000;
        func_ov000_0219bdb0(id, 0xffff, 0xe, 1, 0xc, &mb);
        id = FLD(u16, FLD(void *, self, 8), 0xc);
        mc.a = 1;
        mc.b = 2;
        func_ov000_0219bdb0(id, 0xffff, 0xe, 1, 0xc, &mc);
        FLD(u16, self, 0x20) = 1;
        break;
    }
    case 1:
        if (rem == 0) {
            FLD(u16, self, 0x20) = 5;
        } else {
            FLD(u16, self, 0x20) = 2;
        }
        break;
    case 2:
        if (func_ov011_02201b64(self + 0x34)) {
            if (e->b0) {
                Ov011Ent_Lerp4(e, 0x2000, 1);
            }
            if (e->b0) {
                Ov011Ent_Lerp3(e, 0x71c, 1);
            }
            if (e->b0) {
                Ov011Ent_Lerp2(e, 0x3333, 1);
            }
            func_ov011_02201aac(self + 0x34, &data_ov011_02207290);
            FLD(u16, self, 0x20) = 3;
        }
        break;
    case 3:
        if (func_ov011_02201b40(self + 0x34)) {
            void *owner = FLD(void *, self, 8);
            s32 i;
            MTX_RotY33_(&m, OV011_SIN(FLD(u16, owner, 0x7e)), OV011_COS(FLD(u16, owner, 0x7e)));
            MTX_MultVec33(&data_ov011_02207290, &m, &v);
            owner = FLD(void *, self, 8);
            p.x = FLD(s32, owner, 0x70);
            p.y = FLD(s32, owner, 0x74);
            p.z = FLD(s32, owner, 0x78);
            VEC_Add(&p, &v, &p);
            for (i = 0; i < rem; i++) {
                void *ob;
                Ov011Node *nn;
                void *a;
                Ov011Spawn_Init(&d, 0x4812);
                rot.x = 0;
                rot.y = 0;
                rot.z = 0;
                ob = func_ov000_0218bf1c(data_ov000_021ccd64, &d, &p, &rot, 0xffff);
                func_ov011_022011c0(ob, FLD(u16, FLD(void *, self, 8), 0xc));
                func_ov011_022011c8(ob, 1);
                FLD(u16, FLD(void *, ob, 0x4c), 0x1c) = FLD(u16, FLD(void *, self, 8), 0xc);
                func_ov011_02201214(ob, NULL);
                FLD(Ov011B16, ob, 0x16).b0 = 1;
                nn = func_ov003_021d77e0(ob);
                {
                    Ov011Node *h = FLD(Ov011Node *, self, 0xc);
                    if (nn != NULL) {
                        nn->next = h;
                        h = nn;
                    }
                    FLD(Ov011Node *, self, 0xc) = h;
                }
                a = Ov011_FindActor(nn->id);
                if (a != NULL) {
                    Ov011PNode *pn = NULL;
                    if (e->b0) {
                        Ov011PNode *q = Ov011_NewPNode(&v);
                        e->unk_04 = Ov011_PushNode(e->unk_04, q);
                        pn = q;
                        e->unk_08 = 0;
                        e->b1 = 0;
                    }
                    func_ov011_02201214(a, pn);
                }
            }
            FLD(u16, self, 0x20) = 4;
        }
        break;
    case 4:
        FLD(u16, self, 0x22)++;
        if (FLD(u16, self, 0x22) > 10) {
            FLD(u16, self, 0x22) = 10;
            FLD(u16, self, 0x20) = 1;
        }
        break;
    case 5: {
        BOOL r = FALSE;
        if (e->b0) {
            r = e->b1;
        }
        if (r) {
            FLD(Ov011Bit01, self, 0).b2 = 1;
        }
        break;
    }
    }
    for (Ov011Node *n2 = FLD(Ov011Node *, self, 0xc); n2 != NULL; n2 = n2->next) {
        void *a = Ov011_FindActor(n2->id);
        if (func_ov011_02201244(a)) {
            void *owner = FLD(void *, self, 8);
            if (Ov011Ent_Find(e, func_ov011_02201254(a)) != NULL) {
                Ov011PNode *pp = Ov011Ent_Find(e, func_ov011_02201254(a));
                w.x = pp->v.x;
                w.y = pp->v.y;
                w.z = pp->v.z;
                o.x = FLD(s32, owner, 0x70);
                o.y = FLD(s32, owner, 0x74);
                o.z = FLD(s32, owner, 0x78);
                VEC_Add(&w, &o, &r);
                FLD(s32, a, 0x70) = r.x;
                FLD(s32, a, 0x74) = r.y;
                FLD(s32, a, 0x78) = r.z;
            }
        }
    }
    if (!func_ov011_02201b40(self + 0x34)) {
        void *owner = FLD(void *, self, 8);
        t.x = FLD(s32, owner, 0x70);
        t.y = FLD(s32, owner, 0x74);
        t.z = FLD(s32, owner, 0x78);
        func_ov011_02201b80(self + 0x34, &t);
        func_ov011_02201bac(self + 0x34, FLD(u16, FLD(void *, self, 8), 0x7e));
    }
}

}
