#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

typedef struct Node021c65e0 {
    u8 pad_00[4];
    s32 key;
    u8 pad_08[0x20];
    struct Node021c65e0 *next;
} Node021c65e0;

static inline Node021c65e0 *At021c65e0(u8 *self, s32 i) {
    Node021c65e0 *n;
    s32 k = 0;
    for (n = LFLD(Node021c65e0 *, self, 0x84); n != NULL; n = n->next) {
        if (k == i) {
            break;
        }
        k++;
    }
    return n;
}

static inline s32 IndexOf021c65e0(u8 *self, Node021c65e0 *node) {
    Node021c65e0 *n;
    s32 k;
    k = 0;
    for (n = LFLD(Node021c65e0 *, self, 0x84); n != NULL; n = n->next) {
        if (n == node) {
            break;
        }
        k++;
    }
    if (n == NULL) {
        k = -1;
    }
    return k;
}

static inline Node021c65e0 *Find021c65e0(u8 *self, s32 key) {
    Node021c65e0 *n;
    for (n = LFLD(Node021c65e0 *, self, 0x84); n != NULL; n = n->next) {
        if (key == n->key) {
            break;
        }
    }
    return n;
}

static inline void Select021c65e0(u8 *self, s32 i) {
    if (i >= LFLD(s32, self, 0x90)) {
        LFLD(s32, self, 0x94) = 0;
        return;
    }
    LFLD(s32, self, 0x94) = i;
    LFLD(Node021c65e0 *, self, 0x88) = At021c65e0(self, i);
}

static inline Node021c65e0 *At2_021c65e0(u8 *self, s32 i) {
    s32 k = 0;
    Node021c65e0 *n;
    for (n = LFLD(Node021c65e0 *, self, 0x84); n != NULL; n = n->next) {
        if (k == i) {
            break;
        }
        k++;
    }
    return n;
}

static inline void Select2_021c65e0(u8 *self, s32 i) {
    if (i >= LFLD(s32, self, 0x90)) {
        LFLD(s32, self, 0x94) = 0;
        return;
    }
    LFLD(s32, self, 0x94) = i;
    LFLD(Node021c65e0 *, self, 0x88) = At2_021c65e0(self, i);
}

void func_ov000_021c65e0(u8 *self, s32 key) {
    Node021c65e0 *node = Find021c65e0(self, key);
    s32 i;
    if (node != NULL) {
        i = IndexOf021c65e0(self, node);
        if (i >= 0) {
            Select021c65e0(self, i);
        } else {
            Select021c65e0(self, 0);
        }
    } else {
        Select2_021c65e0(self, 0);
    }
}
}
