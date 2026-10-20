// Built at a lower optimization level: the loops are not rotated.
#pragma optimization_level 2
#include "ov006/ov006.h"

extern "C" {

extern void *data_ov006_021ec404;
extern void *data_ov006_021ec444;
extern u16 data_ov006_021eb840[];
void MI_CpuFill8(void *dst, u8 value, u32 size);
void MIi_CpuClear16(int value, void *dst, u32 size);

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

ov006_Unk021ec888 *func_ov006_021e3f10(ov006_Unk021ec888 *self) {
    int i;
    self->vtbl = &data_ov006_021ec404;
    self->vtbl2 = &data_ov006_021ec444;
    self->unk10 = 0;
    self->unk8 = 0;
    self->unkC = 0;
    self->unk14 = 0;
    self->unk18 = 1;
    self->unk1C = 0;
    self->nodes = NULL;
    ov006_Menu_ClearNodes(self);
    self->unk28 = 0;
    self->unk2C = 0;
    self->unk30 = 0;
    MI_CpuFill8(&self->unk34, 0, sizeof(self->unk34));
    self->unk34.key.h[0] = data_ov006_021eb840[8];
    self->unk34.key.h[1] = data_ov006_021eb840[9];
    self->unk34.key.h[2] = data_ov006_021eb840[10];
    MI_CpuFill8(self->unkF4, 0, sizeof(self->unkF4));
    self->unk15A = 0;
    self->unk15C = 0;
    self->unk15E = 0;
    self->unk15F = 0;
    self->unk160 = 0x14;
    for (i = 0; i < 4; i++) {
        ov006_MenuEntry *e = &self->entries[i];
        e->unk0_0 = 0;
        e->unk0_4 = 0;
        MIi_CpuClear16(0, e->unk2, sizeof(e->unk2));
    }
    self->unk1D4 = NULL;
    self->unk1D8 = NULL;
    return self;
}

}
