#include "ov011/ov011.h"


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
    e->active = 1;
    e->settled = 1;
    e->radiusLerp = 0;
    e->spinLerp = 0;
    e->heightLerp = 0;
    e->nodes = NULL;
    e->blend = 0;
    e->radius = b;
    e->radiusTo = 0;
    e->spin = c;
    e->spinTo = 0;
    e->radiusStep = 0;
    e->height = d;
    e->heightTo = 0;
    e->heightStep = 0;
    e->angle = 0;
    e->dir = a;
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
void *Ov003Vt_021f7d2c_Dtor(void *p);
void *Ov003Vt_021f7d2c_Ctor(void *p);
void *Ov011Vt_022079d0_Dtor(void *p);
void *Ov011Vt_022079d0_Ctor(void *p);
void func_ov011_022011fc(void *a, u8 b);

void func_ov011_021fa7dc(Ov011Mgr *self) {
    void *saved;
    if (!self->b0) {
        return;
    }
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->arr8 != NULL) {
        __cxa_vec_delete(self->arr8, 0x38, 8, Ov003Vt_021f7d2c_Dtor);
        self->arr8 = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->arrC != NULL) {
        __cxa_vec_delete(self->arrC, 0x30, 8, Ov011Vt_022079d0_Dtor);
        self->arrC = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->ids != NULL) {
        Heap_FreeArray(self->ids);
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
        self->arr8 = (Ov011E38 *)__cxa_vec_new(self->count, 0x38, 8, Ov003Vt_021f7d2c_Ctor, Ov003Vt_021f7d2c_Dtor);
        self->arrC = (Ov011E30 *)__cxa_vec_new(self->count, 0x30, 8, Ov011Vt_022079d0_Ctor, Ov011Vt_022079d0_Dtor);
        self->ids = (u16 *)Heap_AllocArray(self->count * 2);
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
    void *saved;
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
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->arr8 != NULL) {
        __cxa_vec_delete(self->arr8, 0x38, 8, Ov003Vt_021f7d2c_Dtor);
        self->arr8 = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->arrC != NULL) {
        __cxa_vec_delete(self->arrC, 0x30, 8, Ov011Vt_022079d0_Dtor);
        self->arrC = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->ids != NULL) {
        Heap_FreeArray(self->ids);
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

void ActorMgr_SendMsg(u16 a, u16 b, u8 c, BOOL d, u32 e, const void *f);
void func_ov011_022011c8(void *a, s32 b);
BOOL func_ov011_02202ac8(void *p, VecFx32 *a, VecFx32 *b, s32 c, u8 d);

static inline void Ov011_Send(u16 id, s32 a, s32 b) {
    Ov011Msg m;
    m.a = a;
    m.b = b;
    ActorMgr_SendMsg(id, 0xffff, 0xe, 1, 0xc, &m);
}

void func_ov011_021facc4(Ov011Mgr *self) {
    VecFx32 v2;
    VecFx32 v1;
    Actor *actor;
    BOOL ok;
    u16 i;
    Actor *a;
    actor = self->list->actor;
    switch (self->state) {
    case 0:
        for (i = 0; i < self->count; i++) {
            a = Ov011_FindActor(self->ids[i]);
            if (a != NULL) {
                func_ov011_022011fc(a, 1);
            }
        }
        Ov011_Send(actor->id, 1, 0);
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
        Ov011_Send(actor->id, 1, 1);
        self->state = 2;
        break;
    case 2:
        for (i = 0; i < self->count; i++) {
            a = Ov011_FindActor(self->ids[i]);
            if (a != NULL) {
                v1 = a->pos;
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
                a->pos = *(VecFx32 *)self->arrC[i].v10();
                if (!self->arrC[i].v14()) {
                    ok = FALSE;
                }
            }
        }
        if (!ok) {
            return;
        }
        Ov011_Send(actor->id, 1, 2);
        self->flags |= 0x10;
        break;
    }
}

}

extern "C" {

BOOL Ov003Mover_Start(void *self, const VecFx32 *target, const VecFx32 *start, s32 speed, s32 maxDist, u8 noSnap);
void func_ov003_021d7c08(void *self, const VecFx32 *target);

static inline Ov011PNode *Ov011_NewPNode(const VecFx32 *v) {
    Ov011PNode *n = (Ov011PNode *)Heap_Alloc(0x10);
    n->v.x = v->x;
    n->v.y = v->y;
    n->v.z = v->z;
    n->next = NULL;
    return n;
}

void func_ov011_021fb02c(Ov011Mgr *self) {
    VecFx32 v;
    VecFx32 p;
    VecFx32 v2;
    Ov011Npc *a;
    u16 i;
    s32 j;
    Ov011Ent *e;
    Actor *actor;
    BOOL ok;
    actor = self->list->actor;
    if (self->state == 0) {
        v = actor->pos;
        v.y += 0x6800;
        for (i = 0; i < self->count; i++) {
            a = Ov011_FindNpc(self->ids[i]);
            if (a != NULL) {
                p = a->pos;
                Ov003Mover_Start(&self->arr8[i], &v, &p, 0x52, 0x3000, 0);
            }
        }
        self->state++;
        return;
    }
    v2 = actor->pos;
    v2.y += 0x6800;
    for (s32 k = 0; k < self->count; k++) {
        func_ov003_021d7c08(&self->arr8[k], &v2);
    }
    ok = TRUE;
    for (i = 0; i < self->count; i++) {
        a = Ov011_FindNpc(self->ids[i]);
        if (a != NULL) {
            a->pos = *(VecFx32 *)self->arr8[i].v10();
            if (!self->arr8[i].v14()) {
                ok = FALSE;
            }
        }
    }
    if (!ok) {
        return;
    }
    for (j = 0; j < self->count; j++) {
        a = Ov011_FindNpc(self->ids[j]);
        if (a != NULL) {
            VecFx32 delta;
            Ov011PNode *n;
            delta.x = a->pos.x - actor->pos.x;
            delta.y = a->pos.y - actor->pos.y;
            delta.z = a->pos.z - actor->pos.z;
            e = self->ent;
            n = NULL;
            if (e->active) {
                Ov011PNode *q = Ov011_NewPNode(&delta);
                e->nodes = Ov011_PushNode(e->nodes, q);
                n = q;
                e->settled = 0;
                e->blend = 0;
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
