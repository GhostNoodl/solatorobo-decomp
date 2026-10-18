#include "ov000/VObj.h"
#include "ov000/HeapScope.h"

class Node02182374 : public VObj {
public:
    u8 pad_04[0xc2];
    u16 id;
    u8 pad_c8[8];
    Node02182374 *prev;
    Node02182374 *next;
};

typedef struct {
    u8 unk_00[0xac];
    u8 unk_ac;
} Ctrl02182374;

typedef struct {
    u8 unk_00[0x4];
    Ctrl02182374 *unk_04;
} Data02182374;

typedef struct {
    u8 pad_00[0x10];
    Node02182374 *head;
} Obj02182374;

extern "C" {

extern Data02182374 data_ov000_021ccd50;
extern void *data_02fe152c;
u32 func_ov000_0214bf2c(u32 id);
void func_020592c4(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_02182590(u8 *p);

void func_ov000_02182374(Obj02182374 *self, u32 id, BOOL force) {
    u32 flags = func_ov000_0214bf2c(id);
    BOOL b = TRUE;
    Node02182374 *node;
    if (force) {
        b = FALSE;
        func_020592c4(data_02fe152c, 1, 1, id, 1);
        func_020592c4(data_02fe152c, 1, 0x201, id, 0);
    } else if (flags & 0x20) {
        func_020592c4(data_02fe152c, 1, 1, id, 1);
    }
    if (b) {
        func_020592c4(data_02fe152c, 1, 0x301, id, 1);
    }
    for (node = self->head; node != NULL; node = node->next) {
        if (node->id == id) {
            break;
        }
    }
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        self->head = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
    {
        void *saved = data_02097dd0->current;
        data_02097dd0->current = data_02097dd0->unk_08;
        if (node != NULL) {
            if (node != NULL) {
                node->vfunc_04();
            }
            node = NULL;
        }
        data_02097dd0->current = saved;
    }
    {
        Ctrl02182374 *c = data_ov000_021ccd50.unk_04;
        c->unk_ac = 1;
        func_ov000_02182590(&c->unk_ac);
    }
}

}
