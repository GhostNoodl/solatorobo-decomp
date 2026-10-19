#include "types.h"

typedef struct {
    u8 pad[0x12];
    u8 idx;
    u8 pad13;
} Link02165a20;

typedef struct {
    u32 unk_00_0 : 5;
    u32 a : 8;
    u32 b : 8;
    u32 unk_00_21 : 11;
    u16 dist;
    u8 pad06[4];
    u8 numLinks;
    u8 pad0b[9];
    Link02165a20 *links;
    u8 pad18[4];
} Node02165a20;

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 head;
    u8 tail;
    u8 pad05;
    u16 best;
    Node02165a20 *queue[32];
    Node02165a20 *path[32];
    u8 pathLen;
    u8 unk_109;
    u16 unk_10a;
    u16 unk_10c;
    u16 unk_10e;
    u16 unk_110;
} Path02165a20;

typedef struct {
    u8 pad[8];
    u8 numNodes;
    u8 pad09[0xc84 - 9];
    Node02165a20 *nodes;
    u8 pad0c88[0xcdc - 0xc88];
    Path02165a20 *path;
} Map02165a20;

typedef struct {
    u8 pad[0x30];
    Map02165a20 *map;
} Obj02165a20;

typedef struct {
    u8 pad[0x14];
    u8 key;
} Ent02165a20;

extern "C" {

extern u8 *data_ov000_021ccd54;
void *func_0203de84(u32 size, s32 align);
void func_0203df0c(void *p);
Ent02165a20 *func_ov000_02165e2c(Obj02165a20 *self, Node02165a20 *node);

static inline Node02165a20 *GetNode02165a20(Map02165a20 *m, u8 idx) {
    if (idx >= m->numNodes) {
        return NULL;
    }
    return &m->nodes[idx];
}

static inline Node02165a20 *FindNode02165a20(Map02165a20 *m, u8 a, u8 b) {
    u8 i;
    Node02165a20 *q = m->nodes;
    for (i = 0; i < m->numNodes; i++, q++) {
        if (a == q->a && b == q->b) {
            return q;
        }
    }
    return NULL;
}

static inline void FreePath02165a20(Obj02165a20 *self) {
    Map02165a20 *m = self->map;
    if (m != NULL && m->path != NULL) {
        func_0203df0c(m->path);
        m->path = NULL;
    }
}

void func_ov000_02165a20(Obj02165a20 *self, u8 *msg) {
    Map02165a20 *m = self->map;
    u8 *g;
    Node02165a20 *goal;
    Node02165a20 *start;
    Path02165a20 *p;
    u8 b;
    u8 i;
    u8 k;
    u16 best;
    if (m == NULL) {
        return;
    }
    g = data_ov000_021ccd54;
    if (g[0xca] != msg[0]) {
        return;
    }
    k = msg[1];
    b = msg[2];
    if (k != 0xff) {
        goal = FindNode02165a20(m, k, b);
    } else {
        goal = GetNode02165a20(m, b);
    }
    if (goal == NULL) {
        return;
    }
    p = (Path02165a20 *)func_0203de84(0x114, 4);
    m->path = p;
    p->unk_00 = 0xff;
    p->unk_01 = 0xff;
    p->unk_02 = 0xff;
    p->head = p->tail = 0;
    p->best = 0xffff;
    for (i = 0; i < m->numNodes; i++) {
        m->nodes[i].dist = 0xffff;
    }
    p->pathLen = 0;
    for (i = 0; i < 32; i++) {
        p->path[i] = NULL;
    }
    p->unk_109 = 0;
    p->unk_10a = 0;
    p->unk_10c = 0;
    p->unk_10e = 0;
    start = GetNode02165a20(self->map, g[0xcc]);
    if (start == NULL) {
        FreePath02165a20(self);
        return;
    }
    p->unk_109 = func_ov000_02165e2c(self, start)->key;
    start->dist = 0;
    p->queue[p->tail++] = start;
    while (p->head != p->tail) {
        Node02165a20 *n = p->queue[p->head++];
        if (n == goal) {
            p->best = n->dist;
        } else if (n->dist < p->best) {
            u8 j;
            Link02165a20 *l = n->links;
            for (j = 0; j < n->numLinks; j++, l++) {
                Node02165a20 *t = GetNode02165a20(self->map, l->idx);
                u16 d = n->dist + 1;
                if (t->dist > d) {
                    t->dist = d;
                    p->queue[p->tail++] = t;
                }
            }
        }
    }
    p->path[0] = goal;
    best = 0xffff;
    for (k = 1; goal->dist != 0; k++) {
        u8 j;
        Link02165a20 *l;
        for (l = goal->links, j = 0; j < goal->numLinks; j++, l++) {
            Node02165a20 *t = GetNode02165a20(self->map, l->idx);
            u16 d = t->dist;
            if (d < best) {
                p->path[k] = t;
                best = d;
            }
        }
        goal = p->path[k];
    }
    p->pathLen = k;
    p->unk_110 = 0x168 / p->pathLen;
    if (p->unk_110 < 0x3c) {
        p->unk_110 = 0x3c;
    }
}

}
