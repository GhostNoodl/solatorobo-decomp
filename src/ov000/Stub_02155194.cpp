#include "ov000/VObj.h"

typedef struct {
    void *current;
    void *unk_04;
    void *unk_08;
} HeapState02155160;

typedef struct Node02155160 {
    u32 unk_00;
    s16 idx;
    s16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    VObj *unk_1c;
    VObj *unk_20;
    u32 unk_24;
    struct Node02155160 *prev;
    struct Node02155160 *next;
} Node02155160;

extern "C" {
extern void *data_02097e4c;
extern HeapState02155160 *data_02097dd0;
void func_0203de1c(void *ptr);
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
}

class Obj02155160 : public VObj {
public:
    u8 pad_04[0x8];
    u32 unk_0c;
    u8 pad_10[0x10];
    s32 unk_20;
    u8 pad_24[0x50];
    u32 unk_74;
    u8 pad_78[0x1c];
    Node02155160 *unk_94;
    Node02155160 *unk_98;
    s16 unk_9c;
    u8 pad_9e[0x2];
    s16 unk_a0;
    s16 unk_a2;
    Node02155160 *unk_a4;
    Node02155160 *unk_a8;
    u8 pad_ac[0x4];
    s8 unk_b0;
    s8 unk_b1;
    s8 unk_b2;
    s8 unk_b3;
};

extern "C" {

void func_ov000_02155160(Obj02155160 *self, s32 a) {
    Node02155160 *v = self->unk_94;
    self->unk_b1 = 0;
    self->unk_98 = v;
    self->unk_a4 = v;
    if (v != NULL) {
        self->vfunc_b4(a, 1);
    }
}

void func_ov000_02155194(VObj *self, void *p) {
    if (p != NULL) {
        self->vfunc_a4(*(s16 *)((u8 *)p + 4));
    } else {
        self->vfunc_a4(0);
    }
}

void func_ov000_021551c4(Obj02155160 *self, s32 n, s32 b) {
    s32 m;
    s32 lim;
    s32 v;
    s8 old = self->unk_b1;
    self->unk_b1 = old - (s8)n;
    self->unk_b0 = old;
    lim = *(s16 *)((u8 *)self->unk_98 + 4);
    m = 0;
    if (self->unk_b1 + lim < 0) {
        self->unk_b1 = -lim;
    }
    v = self->unk_b1;
    if (v < 0) {
        if (self->unk_0c & 0x20000) {
            m = v;
        }
        self->unk_b1 = 0;
    }
    self->vfunc_bc(m, b);
    self->unk_a2 = 4;
}

void func_ov000_02155238(Obj02155160 *self, s32 n, s32 b) {
    s32 d;
    s8 old = self->unk_b1;
    self->unk_b0 = old;
    if (self->unk_0c & 0x20000) {
        d = *(s16 *)((u8 *)self->unk_98 + 4) - n;
        if (d < 0) {
            self->unk_b1 = old + (s8)d;
            n += d;
            if (self->unk_b1 < 0) {
                self->unk_b1 = 0;
            }
        }
    } else {
        n = 0;
        self->unk_b1 = 0;
    }
    self->vfunc_bc(-n, b);
    self->unk_a2 = 8;
}


void func_ov000_021552b0(Obj02155160 *self, s32 n, s32 b) {
    s32 m;
    s32 lim;
    s32 v;
    s32 cnt;
    s8 old = self->unk_b1;
    self->unk_b1 = old + (s8)n;
    self->unk_b0 = old;
    lim = *(s16 *)((u8 *)self->unk_98 + 4);
    m = 0;
    if (self->unk_b1 + lim >= self->unk_9c) {
        self->unk_b1 = self->unk_9c - lim - 1;
    }
    v = self->unk_b1;
    cnt = self->unk_20;
    if (v >= cnt) {
        if (self->unk_0c & 0x20000) {
            m = v - cnt + 1;
        }
        self->unk_b1 = cnt - 1;
    }
    self->vfunc_bc(m, b);
    self->unk_a2 = 4;
}

void func_ov000_02155338(Obj02155160 *self, s32 n, s32 b) {
    s32 d;
    s32 cnt;
    s8 old = self->unk_b1;
    self->unk_b0 = old;
    if (self->unk_0c & 0x20000) {
        cnt = self->unk_20;
        d = self->unk_9c - (*(s16 *)((u8 *)self->unk_98 + 4) + n);
        if (d < cnt) {
            d = cnt - d;
            self->unk_b1 = old + (s8)d;
            n -= d;
            if (self->unk_b1 >= cnt) {
                self->unk_b1 = cnt - 1;
            }
        }
    } else {
        n = 0;
        self->unk_b1 = self->unk_20 - 1;
    }
    self->vfunc_bc(n, b);
    self->unk_a2 = 8;
}


void func_ov000_021553c8(Obj02155160 *self, s32 n, s32 commit) {
    Node02155160 *p;
    Node02155160 *q;
    s32 i;
    s32 k;
    i = n;
    p = self->unk_98;
    if (n > 0) {
        while (i != 0) {
            i--;
            p = p->next;
        }
    } else if (n < 0) {
        while (i != 0) {
            i++;
            p = p->prev;
        }
    }
    k = self->unk_b1;
    if (commit) {
        self->unk_98 = p;
    }
    self->unk_a4 = p;
    self->unk_b2 = 10;
    if (self->unk_b0 != k || n != 0) {
        q = self->unk_a4;
        i = k;
        while (i--) {
            q = q->next;
        }
        if (self->vfunc_9c(q) == 0) {
            self->unk_0c |= 2;
        }
        if (!commit) {
            func_02049a48(data_02097e4c, 0x1d, -1, -1, -1);
        }
        self->unk_b3++;
    } else {
        if (commit) {
            if (self->vfunc_9c(p) == 0) {
                self->unk_0c |= 2;
            }
        }
        self->unk_b3 = 0;
    }
}


static inline void Node02155160_DeleteObj(VObj **pp) {
    void *saved = data_02097dd0->current;
    data_02097dd0->current = data_02097dd0->unk_08;
    if (*pp != NULL) {
        if (*pp != NULL) {
            (*pp)->vfunc_04();
        }
        *pp = NULL;
    }
    data_02097dd0->current = saved;
}

static inline void Node02155160_Delete(Node02155160 *node) {
    if (node != NULL) {
        Node02155160_DeleteObj(&node->unk_1c);
        Node02155160_DeleteObj(&node->unk_20);
        node->unk_00 = 0;
        node->idx = 0;
        node->unk_06 = 0;
        node->unk_08 = 0xffff;
        node->unk_0a = 0xffff;
        node->unk_0c = 0;
        node->unk_10 = 0;
        node->unk_14 = 0;
        node->unk_18 = 0;
        node->unk_1c = NULL;
        node->unk_20 = NULL;
        node->unk_24 = 0;
        node->prev = NULL;
        node->next = NULL;
        func_0203de1c(node);
    }
}

void func_ov000_021554f0(Obj02155160 *self) {
    Node02155160 *node;
    Node02155160 *p;
    Node02155160 *q;
    s32 pos;
    s32 i;
    s16 j;
    void *saved;
    pos = self->unk_98->idx;
    node = self->unk_a8;
    if (node == self->unk_94) {
        self->unk_94 = node->next;
        if (self->unk_94 != NULL) {
            self->unk_94->prev = NULL;
        }
    }
    if (node->prev != NULL) {
        node->prev->next = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
    self->unk_9c--;
    j = 0;
    for (p = self->unk_94; p != NULL; p = p->next) {
        p->idx = j;
        j++;
    }
    if (self->unk_0c & 0x200000) {
        i = self->unk_9c - self->unk_20;
        p = self->unk_94;
        if (i > 0) {
            while (i--) {
                p = p->next;
            }
        }
        self->unk_98 = p;
    } else {
        p = self->unk_94;
        if (pos > 0) {
            while (pos--) {
                p = p->next;
            }
        }
        self->unk_98 = p;
    }
    if (self->unk_b1 >= self->unk_9c) {
        self->unk_b1 = self->unk_9c - 1;
    }
    self->unk_a4 = self->unk_98;
    q = self->unk_a4;
    if (q == NULL) {
        q = NULL;
    } else {
        i = self->unk_b1;
        while (i--) {
            q = q->next;
        }
    }
    if (self->vfunc_9c(q) == 0) {
        self->unk_0c |= 2;
    }
    saved = data_02097dd0->current;
    data_02097dd0->current = data_02097dd0->unk_08;
    if (node != NULL) {
        Node02155160_Delete(node);
    }
    data_02097dd0->current = saved;
    self->unk_0c &= ~0x300000;
    self->unk_a8 = NULL;
    self->unk_a0 = 0;
    if (self->unk_74 == 0) {
        self->unk_0c &= ~1;
    }
}

}
