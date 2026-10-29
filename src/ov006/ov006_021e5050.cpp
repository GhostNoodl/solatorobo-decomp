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
void func_ov006_021e48fc(ov006_Unk021ec888 *self);
void func_ov006_021e49bc(ov006_Unk021ec888 *self);

static inline void ov006_Menu_ClearNodes(ov006_Unk021ec888 *self) {
    ov006_MenuNode *node = self->nodes;
    while (node != NULL) {
        ov006_MenuNode *next;
        void *saved;
        next = node->next;
        saved = data_02097dd0->current;
        data_02097dd0->current = data_02097dd0->unk8;
        if (node != NULL) {
            if (node != NULL) {
                node->vtbl->dtor((Object *)node);
            }
            node = NULL;
        }
        data_02097dd0->current = saved;
        node = next;
    }
    self->nodes = NULL;
    self->unk24 = 0;
    self->unk26 = 1;
}

void func_ov006_021e5050(ov006_Unk021ec888 *self) {
    switch (self->unkC) {
    case 0:
        self->unk28 = 0;
        data_02097dd0->unk18 = 0;
        ov006_Menu_ClearNodes(self);
        self->unkC = 10;
        break;
    case 10:
        if (data_02097e40->unk2C != 1) {
            return;
        }
        func_02046070(data_02097e40, data_ov006_021eb840, 0);
        self->unk2C = 1;
        self->unkC = 20;
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
        func_ov006_021e48fc(self);
        if ((u32)self->unk28 % 10 == 0) {
            func_ov006_021e49bc(self);
        }
        self->unkC = 30;
        self->unk10 = 30;
        break;
    case 30:
        if (self->unk10 != 0) {
            self->unk10--;
        }
        if (self->unk10 == 0) {
            self->unk26 = 0;
            self->unkC = 10;
            self->unk10 = 0;
        }
        break;
    }
}

}
