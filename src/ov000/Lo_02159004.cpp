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
void func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
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

void func_ov000_02159004(Obj02155160 *self, s32 n, s32 commit) {
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
        q = self->unk_94;
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

}
