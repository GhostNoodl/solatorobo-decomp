#include "ov000/VObj.h"

typedef struct Node021c4738 {
    u8 unk_00[0x18];
    u32 unk_18;
    u8 unk_1c[0xc];
    struct Node021c4738 *next;
    struct Node021c4738 *prev;
} Node021c4738;

typedef struct {
    u8 unk_00[0x94];
    Node021c4738 *head;
    s32 count;
    s32 unk_9c;
    Node021c4738 *unk_a0;
    u8 unk_a4[0x8];
    u16 unk_ac;
} List021c4738;

extern "C" {

static inline Node021c4738 *List021c4738_GetAt(List021c4738 *self, s32 index) {
    Node021c4738 *n = self->head;
    s32 i = 0;
    while (n != NULL) {
        if (i == index) {
            break;
        }
        n = n->next;
        i++;
    }
    return n;
}

void func_ov000_021c4738(List021c4738 *self, s32 index) {
    Node021c4738 *n;
    s32 i;
    if (self->head == NULL) {
        self->unk_a0 = NULL;
        return;
    }
    n = List021c4738_GetAt(self, index);
    self->unk_a0 = n;
    self->unk_ac = 7;
    for (i = index - 1; i >= self->unk_9c; i--) {
        self->unk_ac += (u16)n->unk_18;
        n = n->prev;
    }
}

}
