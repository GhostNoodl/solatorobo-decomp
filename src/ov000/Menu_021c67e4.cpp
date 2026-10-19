#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 pad_00[0x12];
    u16 trg;
    u8 pad_14[2];
    u16 rep;
} Pad021c67e4;

typedef struct Node021c67e4 {
    u8 pad_00[0x1c];
    s32 val;
    u8 pad_20[8];
    struct Node021c67e4 *next;
} Node021c67e4;

typedef struct Obj021c67e4 Obj021c67e4;
typedef void (*Cb021c67e4)(Obj021c67e4 *self, Node021c67e4 *node);

struct Obj021c67e4 {
    u8 pad_00[0xc];
    u32 unk_0c_0 : 2;
    u32 unk_0c_2 : 1;
    u32 unk_0c_3 : 29;
    u8 pad_10[0x74];
    Node021c67e4 *head;
    Node021c67e4 *cur;
    u8 unk_8c;
    u8 pad_8d[3];
    s32 count;
    s32 index;
    s32 prevIndex;
    u8 pad_9c[0x18];
    s32 val;
    s32 dir;
    s32 timer;
    u8 pad_c0[4];
    u32 wrap : 1;
    u32 unk_c4_1 : 31;
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

}
