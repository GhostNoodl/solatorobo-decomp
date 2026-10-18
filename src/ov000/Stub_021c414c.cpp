#include "ov000/VObj.h"

typedef struct Node021c414c {
    u8 unk_00[0x4];
    s32 id;
    u8 unk_08[0x20];
    struct Node021c414c *next;
} Node021c414c;

extern "C" {

void func_ov000_021c403c(void *self, u16 index);

static inline void SelectNode(void *self, Node021c414c *target) {
    Node021c414c *n = *(Node021c414c **)((u8 *)self + 0x94);
    s32 i = 0;
    while (n != NULL) {
        if (n == target) {
            break;
        }
        n = n->next;
        i++;
    }
    if (n == NULL) {
        i = -1;
    }
    if (i >= 0) {
        func_ov000_021c403c(self, i);
    } else {
        func_ov000_021c403c(self, 0);
    }
}

void func_ov000_021c414c(void *self, Node021c414c *target) {
    Node021c414c *n = *(Node021c414c **)((u8 *)self + 0x94);
    s32 i = 0;
    while (n != NULL) {
        if (n == target) {
            break;
        }
        n = n->next;
        i++;
    }
    if (n == NULL) {
        i = -1;
    }
    if (i >= 0) {
        func_ov000_021c403c(self, i);
    } else {
        func_ov000_021c403c(self, 0);
    }
}


void func_ov000_021c41a4(void *self, s32 id) {
    Node021c414c *n;
    for (n = *(Node021c414c **)((u8 *)self + 0x94); n != NULL; n = n->next) {
        if (id == n->id) {
            break;
        }
    }
    if (n != NULL) {
        SelectNode(self, n);
    } else {
        func_ov000_021c403c(self, 0);
    }
}

}
