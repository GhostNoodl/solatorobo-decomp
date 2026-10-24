#include "ov010/ov010.h"

struct Ov010IdNode {
    u16 id;
    Ov010IdNode *next;
};

struct Ov010IdList {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 count;
    u16 ids[0x11];
    Ov010IdNode *head;
};

struct Ov010Wave {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_05;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    u16 unk_0c;
    u16 unk_0e;
    Ov010IdList *list;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    u16 state;
    u16 timer;
};

extern "C" {

extern void *data_ov000_021ccd68;
extern const Ov010Blk12 data_ov010_0220f564;
extern u8 *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov010_0220dbc0(Ov010IdList *l);
extern u16 *func_ov010_0220da74(Ov010IdList *l, Ov010Vec *pos, s32 b, s32 c, s32 d, u16 e, u16 f);
extern s32 _s32_div_f(s32 a, s32 b);
extern void func_ov003_021da48c(void *p, s32 a);

static inline u8 *Ov010w_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline u8 Ov010w_Count(Ov010IdList *l) {
    u8 c = 0;
    if (l->b0) {
        c = l->count;
    }
    return c;
}

static inline u16 Ov010w_Get(Ov010IdList *l, s32 i) {
    u16 id = 0xffff;
    if (l->b0 && i >= 0 && i < l->count) {
        id = l->ids[i];
    }
    return id;
}

static inline BOOL Ov010w_IsActive(u8 *a) {
    BOOL r = FALSE;
    if (a != NULL) {
        s32 k = FLD(s32, a, 0xd8);
        r = (u32)(k - 1) <= 2;
    }
    return r;
}
static inline void Ov010w_Collect(Ov010IdList *l) {
    if (l->b0) {
        Ov010IdNode *n;
        l->count = 0;
        for (n = l->head; n != NULL; n = n->next) {
            if (Ov010w_IsActive(Ov010w_FindActor(n->id)) == TRUE) {
                l->ids[l->count] = n->id;
                l->count++;
            }
        }
    }
}

static inline void Ov010w_StartAll(Ov010Wave *self) {
    s32 i;
    for (i = 0; i < Ov010w_Count(self->list); i++) {
        u8 *a = Ov010w_FindActor(Ov010w_Get(self->list, i));
        if (a != NULL && FLD(u8, a, 0x14) != 1 && !FLD(Ov010Flags8, a, 0xce).b0) {
            FLD(Ov010Flags8, a, 0xce).b0 = 1;
            FLD(Ov010Flags8, a, 0xce).b2 = 1;
            func_ov003_021da48c(a + 0x158, 3);
        }
    }
}

static inline BOOL Ov010w_Tick(Ov010Wave *self) {
    return self->timer % (0x19 / (self->unk_0a - 1)) == 0;
}
static inline BOOL Ov010w_Last(Ov010Wave *self) {
    BOOL r = TRUE;
    if (self->unk_0c != self->unk_0a) {
        r = FALSE;
    }
    return r;
}
void func_ov010_02209948(Ov010Wave *self) {
    BOOL ok;
    if (!self->b0) {
        return;
    }
    switch (self->state) {
    case 0: {
        u8 *a;
        Ov010Vec p;
        s32 i;
        func_ov010_0220dbc0(self->list);
        a = Ov010w_FindActor(self->unk_06);
        if (a == NULL) {
            self->state = 0x70;
            return;
        }
        p = FLD(Ov010Vec, a, 0x70);
        for (i = 0; i < self->unk_0a; i++) {
            func_ov010_0220da74(self->list, &p, self->unk_1c, self->unk_14, self->unk_18, self->unk_06, self->unk_08);
        }
        self->state = 0x10;
        break;
    }
    case 0x10: {
        Ov010IdList *l = self->list;
        s32 i;
        ok = TRUE;
        if (l->b0) {
            Ov010IdNode *n;
            l->count = 0;
            for (n = l->head; n != NULL; n = n->next) {
                Ov010w_FindActor(n->id);
                l->ids[l->count] = n->id;
                l->count++;
            }
        }
        for (i = 0; i < Ov010w_Count(self->list); i++) {
            u8 *a = Ov010w_FindActor(Ov010w_Get(self->list, i));
            if (a != NULL && FLD(u8, a, 0x14) == 1) {
                ok = FALSE;
                break;
            }
        }
        if (ok) {
            self->state = 0x20;
        }
        break;
    }
    case 0x20: {
        BOOL last = Ov010w_Last(self);
        BOOL tick = Ov010w_Tick(self);
        if (last) {
            self->timer = 0;
            self->state = 0x30;
        } else if (tick) {
            Ov010IdList *l = self->list;
            u8 *a;
            u8 *s;
            u16 idx;
            BOOL more;
            if (l->b0) {
                Ov010IdNode *n;
                l->count = 0;
                for (n = l->head; n != NULL; n = n->next) {
                    u8 *e = Ov010w_FindActor(n->id);
                    if (e != NULL && FLD(s32, e, 0xd8) == 1) {
                        l->ids[l->count] = n->id;
                        l->count++;
                    }
                }
            }
            a = Ov010w_FindActor(Ov010w_Get(self->list, 0));
            idx = self->unk_0c;
            more = idx < self->unk_0a;
            s = Ov010w_FindActor(self->unk_06);
            if (a != NULL && FLD(u8, a, 0x14) != 1 && s != NULL && more) {
                s32 q = 0x2000 / (self->unk_0a - 1);
                Ov010Vec v;
                Ov010Blk12 t = data_ov010_0220f564;
                t.w[0] = q * idx - 0x1000;
                func_ov003_021d9980(&v, FLD(u16, s, 0x7e), (Ov010Vec *)&t);
                if (FLD(u8, a, 0x14) != 1 && !FLD(Ov010Flags8, a, 0xce).b1) {
                    FLD(Ov010Flags8, a, 0xce).b1 = 1;
                    func_ov003_021da48c(a + 0x16c, 2);
                    Ov010_VecCopy(&FLD(Ov010Vec, a, 0xfc), &v);
                }
            }
            self->unk_0c++;
        }
        self->timer++;
        break;
    }
    case 0x30:
        self->timer++;
        if (self->timer > 0x41) {
            self->timer = 0;
            self->state = 0x40;
        }
        break;
    case 0x40:
        Ov010w_Collect(self->list);
        Ov010w_StartAll(self);
        self->state = 0x41;
        break;
    case 0x41: {
        BOOL ok = TRUE;
        Ov010w_Collect(self->list);
        {
            s32 i;
            for (i = 0; i < Ov010w_Count(self->list); i++) {
                u8 *a = Ov010w_FindActor(Ov010w_Get(self->list, i));
                if (a != NULL && FLD(Ov010Flags8, a, 0xce).b0) {
                    ok = FALSE;
                    break;
                }
            }
            if (ok) {
                self->state = 0x70;
            }
        }
        break;
    }
    case 0x70:
        ((Ov010V *)self)->v0c();
        break;
    }
}

}
