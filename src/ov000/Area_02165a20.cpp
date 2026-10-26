#include "types.h"

typedef struct {
    u8 pad[0x12];
    u8 to;
    u8 pad13;
} Ent02165a20;

typedef struct {
    u32 b0 : 5;
    u32 m : 8;
    u32 n : 8;
} AreaBits02165a20;

typedef struct {
    AreaBits02165a20 bits;
    u16 dist;
    u8 pad6[4];
    u8 count;
    u8 padb[9];
    Ent02165a20 *ents;
    u8 pad18[4];
} Area02165a20;

typedef struct {
    u8 a;
    u8 b;
    u8 c;
    u8 head;
    u8 tail;
    u8 pad5;
    u16 best;
    Area02165a20 *queue[32];
    Area02165a20 *path[32];
    u8 len;
    u8 key;
    u16 unk_10a;
    u16 unk_10c;
    u16 unk_10e;
    u16 step;
} Ctx02165a20;

typedef struct {
    u8 pad[8];
    u8 count;
    u8 pad9[0xc7b];
    Area02165a20 *areas;
    u8 padc88[0x54];
    Ctx02165a20 *ctx;
} Sub02165a20;

typedef struct {
    u8 pad[0x30];
    Sub02165a20 *sub;
} Obj02165a20;

extern "C" {

extern u8 *data_ov000_021ccd54;
void *func_0203de84(u32 size, s32 align);
void func_0203df0c(void *p);
u8 *func_ov000_02165e2c(Obj02165a20 *self, Area02165a20 *area);

static inline Area02165a20 *GetArea02165a20(Sub02165a20 *w, u8 i) {
    return i >= w->count ? NULL : &w->areas[i];
}

static inline Area02165a20 *FindArea02165a20(Sub02165a20 *w, u8 a, u8 b) {
    if (a != 0xff) {
        u8 i;
        Area02165a20 *s;
        for (i = 0, s = w->areas; i < w->count; i++, s++) {
            if (a == s->bits.m && b == s->bits.n) {
                return s;
            }
        }
        return NULL;
    }
    if (b >= w->count) {
        return NULL;
    }
    return &w->areas[b];
}

void func_ov000_02165a20(Obj02165a20 *self, u8 *key) {
    Sub02165a20 *w = self->sub;
    u8 *pl;
    Area02165a20 *start;
    Area02165a20 *dst;
    Ctx02165a20 *p;
    u8 i;
    Ent02165a20 *e;
    if (w == NULL) {
        return;
    }
    pl = data_ov000_021ccd54;
    if (pl[0xca] != key[0]) {
        return;
    }
    start = FindArea02165a20(w, key[1], key[2]);
    if (start == NULL) {
        return;
    }
    p = (Ctx02165a20 *)func_0203de84(0x114, 4);
    w->ctx = p;
    p->a = 0xff;
    p->b = 0xff;
    p->c = 0xff;
    p->head = p->tail = 0;
    p->best = 0xffff;
    for (i = 0; i < w->count; i++) {
        w->areas[i].dist = 0xffff;
    }
    p->len = 0;
    for (i = 0; i < 0x20; i++) {
        p->path[i] = NULL;
    }
    p->key = 0;
    p->unk_10a = 0;
    p->unk_10c = 0;
    p->unk_10e = 0;
    w = self->sub;
    dst = GetArea02165a20(w, pl[0xcc]);
    if (dst == NULL) {
        if (w != NULL && w->ctx != NULL) {
            func_0203df0c(w->ctx);
            w->ctx = NULL;
        }
        return;
    }
    p->key = func_ov000_02165e2c(self, dst)[0x14];
    dst->dist = 0;
    p->queue[p->tail++] = dst;
    while (p->head != p->tail) {
        Area02165a20 *cur = p->queue[p->head++];
        if (cur == start) {
            p->best = cur->dist;
        } else if (cur->dist < p->best) {
            u8 k;
            Ent02165a20 *e = cur->ents;
            for (k = 0; k < cur->count; k++, e++) {
                Area02165a20 *nb = GetArea02165a20(self->sub, e->to);
                u16 d = cur->dist + 1;
                if (nb->dist > d) {
                    nb->dist = d;
                    p->queue[p->tail++] = nb;
                }
            }
        }
    }
    p->path[0] = start;
    {
        u32 best;
        best = 0xffff;
        for (i = 1; start->dist != 0; i++) {
            e = start->ents;
            u8 k;
            for (k = 0; k < start->count; k++, e++) {
                Area02165a20 *nb = GetArea02165a20(self->sub, e->to);
                u16 d = nb->dist;
                if (d < best) {
                    p->path[i] = nb;
                    best = d;
                }
            }
            start = p->path[i];
        }
        p->len = i;
        p->step = 0x168 / p->len;
        if (p->step < 0x3c) {
            p->step = 0x3c;
        }
    }
}

}
