#include "ov000/VObj.h"

typedef struct Node021b53a8 {
    u8 unk_00[0x4];
    struct Node021b53a8 *next;
    u8 unk_08[0xee];
    u8 unk_f6_0 : 2;
    u8 unk_f6_2 : 1;
    u8 unk_f6_3 : 5;
} Node021b53a8;

extern "C" {

BOOL func_0203dc9c(void *self, s32 a);
void func_ov000_021b7e34(Node021b53a8 *n);

void func_ov000_021b53a8(void *self) {
    Node021b53a8 *n;
    if (func_0203dc9c(self, 1)) {
        return;
    }
    for (n = *(Node021b53a8 **)((u8 *)self + 0x1c); n != NULL; n = n->next) {
        if (n->unk_f6_2) {
            func_ov000_021b7e34(n);
        }
    }
}

}
