// Built at a lower optimization level than the rest: loops are not rotated (they jump to a test at the
// bottom) and loop-invariant loads stay in the loop.
#pragma optimization_level 2
#include "ov006/ov006.h"

typedef struct ov006_Net021e5050 {
    u8 unk0[0x2c];
    int unk2C;
} ov006_Net021e5050;

extern "C" {

extern ov006_Net021e5050 *data_02097e40;
extern u8 data_ov006_021eb840[];
BOOL func_02046070(ov006_Net021e5050 *net, void *data, int a);
BOOL func_020463c8(ov006_Net021e5050 *net);
void ov006_Menu_PruneNodes(ov006_Unk021ec888 *self);
void ov006_Menu_SortNodes(ov006_Unk021ec888 *self);

static inline void ov006_Menu_ClearNodes(ov006_Unk021ec888 *self) {
    ov006_MenuNode *node = self->nodes;
    while (node != NULL) {
        ov006_MenuNode *next;
        void *saved;
        next = node->next;
        saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->heapHi;
        if (node != NULL) {
            if (node != NULL) {
                node->vfunc_04();
            }
            node = NULL;
        }
        data_02097dd0->cur = saved;
        node = next;
    }
    self->nodes = NULL;
    self->unk24 = 0;
    self->unk26 = 1;
}

void func_ov006_021e5050(ov006_Unk021ec888 *self) {
    switch (self->stateTime) {
    case 0:
        self->unk28 = 0;
        data_02097dd0->vblankFunc = NULL;
        ov006_Menu_ClearNodes(self);
        self->stateTime = 10;
        break;
    case 10:
        if (data_02097e40->unk2C != 1) {
            return;
        }
        func_02046070(data_02097e40, data_ov006_021eb840, 0);
        self->unk2C = 1;
        self->stateTime = 20;
        self->unk10 = 30;
        break;
    case 20:
        if (self->unk10 != 0) {
            self->unk10--;
        }
        if (self->unk10 != 0) {
            return;
        }
        func_020463c8(data_02097e40);
        self->unk2C = 0;
        self->unk28++;
        ov006_Menu_PruneNodes(self);
        if ((u32)self->unk28 % 10 == 0) {
            ov006_Menu_SortNodes(self);
        }
        self->stateTime = 30;
        self->unk10 = 30;
        break;
    case 30:
        if (self->unk10 != 0) {
            self->unk10--;
        }
        if (self->unk10 == 0) {
            self->unk26 = 0;
            self->stateTime = 10;
            self->unk10 = 0;
        }
        break;
    }
}

}
