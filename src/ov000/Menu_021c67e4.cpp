#include "types.h"
#include "nitro/fx.h"
#include "ov000/VObj.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 pad_00[0x12];
    u16 trg;
    u8 pad_14[2];
    u16 rep;
} Pad021c67e4;

class Node021c67e4 {
public:
    virtual void vfunc_00();
    virtual void vfunc_04();
    virtual void Refresh();
    virtual void Update();

    u8 pad_04[0x8];
    s32 x;
    s32 y;
    s32 z;
    u8 pad_18[4];
    s32 val;
    u8 on : 1;
    u8 focus : 1;
    u8 pad_20_2 : 6;
    u8 pad_21[3];
    s32 dir;
    Node021c67e4 *next;
};

typedef struct {
    u8 pad_00[4];
    s32 x;
    s32 y;
    s32 z;
} Cursor021c6b28;

class Arrow021c6b28 : public VObj {
public:
    u8 pad_04[0x40];
    s32 width;
    u8 pad_48[0x28];
    s32 z;
};

typedef struct Obj021c67e4 Obj021c67e4;
typedef void (*Cb021c67e4)(Obj021c67e4 *self, Node021c67e4 *node);

struct Obj021c67e4 : public VObj {
    u8 pad_04[0x8];
    u32 unk_0c_0 : 2;
    u32 unk_0c_2 : 1;
    u32 unk_0c_3 : 29;
    u8 pad_10[0x58];
    s16 z;
    u8 pad_6a[0x1a];
    Node021c67e4 *head;
    Node021c67e4 *cur;
    u8 unk_8c;
    u8 pad_8d[3];
    s32 count;
    s32 index;
    s32 prevIndex;
    Cursor021c6b28 *cursor;
    Arrow021c6b28 *arrow;
    s32 width;
    s32 height;
    u8 pad_ac[0x8];
    s32 val;
    s32 dir;
    s32 timer;
    s32 scroll;
    u32 wrap : 1;
    u32 showCursor : 1;
    u32 unk_c4_2 : 30;
    Cb021c67e4 onPress;
    Cb021c67e4 onMove;
};

extern "C" {

extern Pad021c67e4 *data_02097dc8;
extern void *data_02097e4c;
void func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);

static inline Node021c67e4 *At021c67e4(Obj021c67e4 *self, s32 i) {
    Node021c67e4 *n;
    s32 k = 0;
    for (n = self->head; n != NULL; n = n->next) {
        if (k == i) {
            break;
        }
        k++;
    }
    return n;
}

static inline void Body(Obj021c67e4 *self) {
    s32 zero;
    s32 cur;
    s32 d;
    u16 trg;
    u16 rep;
    zero = 0;
    if (self->unk_0c_2) {
        return;
    }
    if (self->timer > 0) {
        return;
    }
    d = zero;
    cur = d;
    trg = data_02097dc8->trg;
    rep = data_02097dc8->rep;
    if (trg & 1) {
        if (self->onPress != NULL) {
            self->onPress(self, self->cur);
        }
        self->unk_8c = 1;
    } else if (rep & 0x20) {
        d--;
    } else if (rep & 0x10) {
        d = 1;
    }
    if (d != 0) {
        BOOL wrap;
        s32 nx;
        self->prevIndex = self->index;
        wrap = self->wrap ? TRUE : FALSE;
        cur = self->index;
        if (d > 0) {
            if (wrap) {
                s32 n = self->count;
                nx = (cur + d % n) % n;
            } else {
                nx = cur + d;
                if (nx >= self->count) {
                    nx = self->count - 1;
                }
            }
        } else {
            if (wrap) {
                s32 n = self->count;
                s32 m = (d < 0 ? -d : d) % n;
                nx = cur - m;
                if (nx < 0) {
                    nx = n - m;
                }
            } else {
                if (cur - (d < 0 ? -d : d) < 0) {
                    nx = 0;
                } else {
                    nx = cur - (d < 0 ? -d : d);
                }
            }
        }
        cur = cur != nx;
        self->index = nx;
    }
    if (cur) {
        Node021c67e4 *node;
        func_02049a48(data_02097e4c, 0x1d, -1, -1, -1);
        node = At021c67e4(self, self->index);
        self->cur = node;
        if (node != NULL) {
            self->val = node->val;
        }
        if (self->onMove != NULL) {
            self->onMove(self, self->cur);
        }
        self->unk_8c = zero;
        self->timer = 15;
        self->dir = d;
    } else {
        self->timer = zero;
        self->dir = zero;
    }
}

void func_ov000_021c67e4(Obj021c67e4 *self) {
    Body(self);
}

// Marks the selected item and its two neighbours (wrapping if the menu wraps),
// then counts down the input repeat timer.
void func_ov000_021c69e4(Obj021c67e4 *self) {
    s32 next;
    BOOL wrap;
    Node021c67e4 *node;
    s32 i;
    s32 cur;
    s32 prev;
    wrap = self->wrap ? TRUE : FALSE;
    cur = self->index;
    if (wrap) {
        s32 n = self->count;
        s32 m = 1 % n;
        prev = cur - m;
        if (prev < 0) {
            prev = n - m;
        }
    } else {
        prev = cur - 1;
        if (prev < 0) {
            prev = 0;
        }
    }
    if (wrap) {
        s32 n = self->count;
        next = (cur + 1 % n) % n;
    } else {
        next = cur + 1;
        if (next >= self->count) {
            next = self->count - 1;
        }
    }
    node = self->head;
    i = 0;
    while (node != NULL) {
        if (i == cur) {
            node->on = 1;
            node->focus = 1;
        } else if (i == prev) {
            node->on = 1;
            node->focus = 0;
        } else if (i == next) {
            node->on = 1;
            node->focus = 0;
        } else {
            node->on = 0;
            node->focus = 0;
        }
        node->dir = self->dir;
        node->Refresh();
        node = node->next;
        i++;
    }
    self->timer = self->timer > 0 ? self->timer - 1 : 0;
}

extern s32 data_ov000_021cc994;
void func_ov000_0215eab4(Cursor021c6b28 *p);
void func_ov000_021c6d64(Obj021c67e4 *self, s32 a, VecFx32 *pos, s32 b);

static inline Node021c67e4 *At6b28(Obj021c67e4 *self, s32 i) {
    // u32 counter: swaps the registers of i and k in the loop compare.
    Node021c67e4 *n;
    u32 k = 0;
    for (n = self->head; n != NULL; n = n->next) {
        if (k == i) {
            break;
        }
        k++;
    }
    return n;
}
static inline void Place021c6b28(Obj021c67e4 *self, Node021c67e4 *n, VecFx32 *p, s32 ofs) {
    if (n != NULL) {
        s32 x = p->x + ofs;
        s32 z = self->z;
        s32 y = p->y;
        n->x = x;
        n->y = y;
        n->z = z;
        n->Update();
    }
}

void func_ov000_021c6b28(Obj021c67e4 *self, s32 a, VecFx32 *pos, s32 b) {
    VecFx32 p;
    s32 cur;
    s32 prev;
    p = *pos;
    p.z = self->z;
    self->vfunc_60(a, &p, b);
    prev = cur = 0;
    if (self->timer > 0) {
        s32 step = data_ov000_021cc994;
        prev = (0xf - self->timer) * (step * -self->dir);
        cur = self->timer * (step * self->dir);
    }
    Place021c6b28(self, At6b28(self, self->index), &p, cur);
    if (self->timer > 0) {
        Place021c6b28(self, At6b28(self, self->prevIndex), &p, prev);
    }
    if (self->showCursor) {
        s32 x = p.x;
        s32 y = p.y;
        s32 z = p.z;
        Cursor021c6b28 *c;
        x += (0x100 - self->width) << 11;
        y += (self->height << 12) - (self->scroll << 15);
        c = self->cursor;
        c->x = x;
        c->y = y;
        c->z = z + 0x20;
        func_ov000_0215eab4(self->cursor);
        self->arrow->vfunc_20(((self->width - self->arrow->width) >> 1) + (x >> 12), (y >> 12) + 2);
        self->arrow->z = z + 0x20;
        self->arrow->vfunc_90();
    }
    func_ov000_021c6d64(self, a, &p, b);
}

}
