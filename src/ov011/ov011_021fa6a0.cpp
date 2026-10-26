#include "ov011/ov011.h"

class Ov011Mgr {
public:
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 count;
    s32 unk_04;
    Ov011E38 *arr8;
    Ov011E30 *arrC;
    u16 *ids;
    Ov011List *list;
    Ov011Ent *unk_18;
    u16 state;
    u16 timer;
    u64 flags;
    u8 unk_28[0x7];
    u8 unk_2f;
};

typedef void (Ov011Mgr::*Ov011MgrFn)();

struct Ov011Pmf {
    void *ptr;
    s32 adj;
};

struct Ov011MgrEntry {
    s32 key;
    Ov011MgrFn fn;
};

extern "C" {

BOOL func_ov011_021fa6a0(Ov011Node *n) {
    return Ov011_NodeValid(n);
}

BOOL func_ov011_021fa720(Ov011Ent *e, s32 a, s32 b, s32 c, s32 d) {
    e->b0 = 1;
    e->b1 = 1;
    e->b2 = 0;
    e->b3 = 0;
    e->b4 = 0;
    e->unk_04 = NULL;
    e->unk_08 = 0;
    e->unk_0c = b;
    e->unk_10 = 0;
    e->unk_18 = c;
    e->unk_1c = 0;
    e->unk_14 = 0;
    e->unk_24 = d;
    e->unk_28 = 0;
    e->unk_2c = 0;
    e->unk_30 = 0;
    e->unk_34 = a;
    return TRUE;
}

Ov011LNode *func_ov011_021fa790(Ov011LNode *head, Ov011LNode *item) {
    Ov011LNode *n;
    Ov011LNode *prev;
    if (head == NULL || item == NULL) {
        return head;
    }
    n = head;
    prev = NULL;
    for (; n != NULL; n = n->next) {
        if (n == item) {
            if (prev == NULL) {
                return n->next;
            }
            prev->next = n->next;
            return head;
        }
        prev = n;
    }
    return head;
}

extern const Ov011MgrEntry data_ov011_02207344[];
void __cxa_vec_delete(void *arr, u32 size, u32 hdr, void *dtor);
void *__cxa_vec_new(u32 count, u32 size, u32 hdr, void *ctor, void *dtor);
void func_ov003_021d79ec(void *p);
void func_ov003_021d79d0(void *p);
void func_ov011_02202a70(void *p);
void func_ov011_02202a54(void *p);
void func_ov003_021da40c(void *p);
void func_ov003_021da48c(void *p, s32 a);
void func_ov011_022011fc(void *a, s32 b);

void func_ov011_021fa7dc(Ov011Mgr *self) {
    u32 saved;
    if (!self->b0) {
        return;
    }
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->arr8 != NULL) {
        __cxa_vec_delete(self->arr8, 0x38, 8, func_ov003_021d79ec);
        self->arr8 = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->arrC != NULL) {
        __cxa_vec_delete(self->arrC, 0x30, 8, func_ov011_02202a70);
        self->arrC = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->ids != NULL) {
        func_0203de50(self->ids);
        self->ids = NULL;
    }
    data_02097dd0->cur = saved;
    self->b0 = 0;
}

void func_ov011_021fa8c8(Ov011Mgr *self) {
    u32 i;
    s32 j;
    u8 key;
    if (!self->b0) {
        return;
    }
    if (!self->b1) {
        return;
    }
    key = self->unk_2f;
    for (i = 0; i < 5; i++) {
        if (key == data_ov011_02207344[i].key && *(s32 *)&data_ov011_02207344[i].fn != 0) {
            (self->*data_ov011_02207344[i].fn)();
            break;
        }
    }
    if (self->arr8 != NULL) {
        for (j = 0; j < self->count; j++) {
            self->arr8[j].v0c();
        }
    }
    if (self->arrC != NULL) {
        for (j = 0; j < self->count; j++) {
            self->arrC[j].v0c();
        }
    }
    func_ov003_021da40c(&self->state);
}

void func_ov011_021fa9d8(Ov011Mgr *self) {
    s32 j;
    Ov011Node *head;
    Ov011Node *n;
    s32 cnt;
    head = self->list->head;
    if (head == NULL) {
        self->flags |= 4;
    } else {
        cnt = 0;
        for (n = head; n != NULL; n = n->next) {
            if (func_ov011_021fa6a0(n) == TRUE) {
                cnt++;
            }
        }
        self->count = cnt;
        self->arr8 = (Ov011E38 *)__cxa_vec_new(self->count, 0x38, 8, func_ov003_021d79d0, func_ov003_021d79ec);
        self->arrC = (Ov011E30 *)__cxa_vec_new(self->count, 0x30, 8, func_ov011_02202a54, func_ov011_02202a70);
        self->ids = (u16 *)func_0203dddc(self->count * 2);
        j = 0;
        for (n = head; n != NULL; n = n->next) {
            if (Ov011_NodeValid(n)) {
                self->ids[j++] = n->id;
            }
        }
    }
    self->flags |= 8;
}

void func_ov011_021fab74(Ov011Mgr *self) {
    s32 i;
    u32 saved;
    if (self->ids != NULL) {
        for (i = 0; i < self->count; i++) {
            void *a = Ov011_FindActor(self->ids[i]);
            if (a != NULL) {
                func_ov011_022011fc(a, 0);
            }
        }
    }
    self->count = 0;
    self->b1 = 0;
    self->unk_04 = -1;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->arr8 != NULL) {
        __cxa_vec_delete(self->arr8, 0x38, 8, func_ov003_021d79ec);
        self->arr8 = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->arrC != NULL) {
        __cxa_vec_delete(self->arrC, 0x30, 8, func_ov011_02202a70);
        self->arrC = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->ids != NULL) {
        func_0203de50(self->ids);
        self->ids = NULL;
    }
    data_02097dd0->cur = saved;
    func_ov003_021da48c(&self->state, 0);
}

}

extern "C" {

struct Ov011Msg {
    s32 a;
    s32 b;
    s32 c;
};

void func_ov000_0219bdb0(u16 a, u16 b, s32 c, s32 d, s32 e, void *f);
void func_ov011_022011c8(void *a, s32 b);
void func_ov011_02202ac8(void *p, Ov011Vec *a, Ov011Vec *b, s32 c, s32 d);

static inline void Ov011_Send(u16 id, s32 a, s32 b) {
    Ov011Msg m;
    m.a = a;
    m.b = b;
    func_ov000_0219bdb0(id, 0xffff, 0xe, 1, 0xc, &m);
}

void func_ov011_021facc4(Ov011Mgr *self) {
    Ov011Vec v2;
    Ov011Vec v1;
    void *actor;
    BOOL ok;
    u16 i;
    void *a;
    actor = self->list->actor;
    switch (self->state) {
    case 0:
        for (i = 0; i < self->count; i++) {
            a = Ov011_FindActor(self->ids[i]);
            if (a != NULL) {
                func_ov011_022011fc(a, 1);
            }
        }
        Ov011_Send(FLD(u16, actor, 0xc), 1, 0);
        self->state = 1;
        break;
    case 1:
        if (++self->timer < 60) {
            return;
        }
        self->timer = 0;
        for (i = 0; i < self->count; i++) {
            a = Ov011_FindActor(self->ids[i]);
            if (a != NULL) {
                func_ov011_022011fc(a, 0);
                func_ov011_022011c8(a, 1);
            }
        }
        Ov011_Send(FLD(u16, actor, 0xc), 1, 1);
        self->state = 2;
        break;
    case 2:
        for (i = 0; i < self->count; i++) {
            a = Ov011_FindActor(self->ids[i]);
            if (a != NULL) {
                v1 = FLD(Ov011Vec, a, 0x70);
                v2.x = v1.x;
                v2.y = v1.y + 0x4000;
                v2.z = v1.z;
                func_ov011_02202ac8(&self->arrC[i], &v2, &v1, 0x4cd, 0);
            }
        }
        self->state = 3;
        break;
    case 3:
        ok = TRUE;
        for (i = 0; i < self->count; i++) {
            a = Ov011_FindActor(self->ids[i]);
            if (a != NULL) {
                FLD(Ov011Vec, a, 0x70) = *(Ov011Vec *)self->arrC[i].v10();
                if (!self->arrC[i].v14()) {
                    ok = FALSE;
                }
            }
        }
        if (!ok) {
            return;
        }
        Ov011_Send(FLD(u16, actor, 0xc), 1, 2);
        self->flags |= 0x10;
        break;
    }
}

}

extern "C" {

BOOL func_ov003_021d7a44(void *self, const Ov011Vec *target, const Ov011Vec *start, s32 speed, s32 maxDist, u8 noSnap);
void func_ov003_021d7c08(void *self, const Ov011Vec *target);
void func_ov011_02201214(void *self, void *p);

static inline Ov011PNode *Ov011_NewPNode(const Ov011Vec *v) {
    Ov011PNode *n = (Ov011PNode *)func_0203dd9c(0x10);
    n->v.x = v->x;
    n->v.y = v->y;
    n->v.z = v->z;
    n->next = NULL;
    return n;
}

void func_ov011_021fb02c(Ov011Mgr *self) {
    Ov011Vec v;
    Ov011Vec p;
    Ov011Vec v2;
    void *a;
    u16 i;
    s32 j;
    Ov011Ent *e;
    void *actor;
    BOOL ok;
    actor = self->list->actor;
    if (self->state == 0) {
        v = FLD(Ov011Vec, actor, 0x70);
        v.y += 0x6800;
        for (i = 0; i < self->count; i++) {
            a = Ov011_FindActor(self->ids[i]);
            if (a != NULL) {
                p = FLD(Ov011Vec, a, 0x70);
                func_ov003_021d7a44(&self->arr8[i], &v, &p, 0x52, 0x3000, 0);
            }
        }
        self->state++;
        return;
    }
    v2 = FLD(Ov011Vec, actor, 0x70);
    v2.y += 0x6800;
    for (s32 k = 0; k < self->count; k++) {
        func_ov003_021d7c08(&self->arr8[k], &v2);
    }
    ok = TRUE;
    for (i = 0; i < self->count; i++) {
        a = Ov011_FindActor(self->ids[i]);
        if (a != NULL) {
            FLD(Ov011Vec, a, 0x70) = *(Ov011Vec *)self->arr8[i].v10();
            if (!self->arr8[i].v14()) {
                ok = FALSE;
            }
        }
    }
    if (!ok) {
        return;
    }
    for (j = 0; j < self->count; j++) {
        a = Ov011_FindActor(self->ids[j]);
        if (a != NULL) {
            Ov011Vec delta;
            Ov011PNode *n;
            delta.x = FLD(s32, a, 0x70) - FLD(s32, actor, 0x70);
            delta.y = FLD(s32, a, 0x74) - FLD(s32, actor, 0x74);
            delta.z = FLD(s32, a, 0x78) - FLD(s32, actor, 0x78);
            e = self->unk_18;
            n = NULL;
            if (e->b0) {
                Ov011PNode *q = Ov011_NewPNode(&delta);
                e->unk_04 = Ov011_PushNode(e->unk_04, q);
                n = q;
                e->b1 = 0;
                e->unk_08 = 0;
            }
            func_ov011_02201214(a, n);
        }
    }
    for (i = 0; i < self->count; i++) {
        self->arr8[i].v08();
    }
    if (self->unk_04 == 0) {
        self->flags |= 4;
    } else if (self->unk_04 == 1) {
        self->flags |= 0x20;
    }
}

}
