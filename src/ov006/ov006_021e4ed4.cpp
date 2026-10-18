#include "ov006/ov006.h"
#include <nitro/mi.h>

typedef struct ov006_Unk02097e40 {
    u8 unk0[0x2c];
    int unk2C;
} ov006_Unk02097e40;

typedef struct ov006_Obj021e4ed4 {
    void *vtbl;
    u8 unk4[8];
    u32 unkC;
} ov006_Obj021e4ed4;

extern "C" {

extern ov006_Unk02097e40 *data_02097e40;
void func_02045094(ov006_Unk02097e40 *p);
void func_02045498(ov006_Unk02097e40 *p, int a);

static inline void ov006_Menu_ClearNodes(ov006_Unk021ec888 *self) {
    ov006_MenuNode *node = self->nodes;
    while (node != NULL) {
        void *saved;
        ov006_MenuNode *next;
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

static inline void ov006_MenuEntry_Clear(ov006_MenuEntry *e) {
    e->unk0_0 = 0;
    e->unk0_4 = 0;
    MI_CpuFill16(e->unk2, 0, sizeof(e->unk2));
}

void func_ov006_021e4ed4(ov006_Unk021ec888 *self) {
    int i;

    switch (self->unkC) {
    case 0:
        data_02097dd0->unk18 = 0;
        func_02045094(data_02097e40);
        if (self->unkC < 0xff) {
            self->unkC++;
        }
        if (self->unk1D8 != NULL && self->unk1D8->obj != NULL) {
            ((ov006_Obj021e4ed4 *)self->unk1D8->obj)->unkC |= 2;
        }
    case 1:
        if (data_02097e40->unk2C == 1) {
            if (self->unkC < 0xff) {
                self->unkC++;
            }
        } else if (data_02097e40->unk2C == 8 || data_02097e40->unk2C == 9) {
            func_02045498(data_02097e40, 0);
        }
        break;
    case 2:
        ov006_Menu_ClearNodes(self);
        for (i = 0; i < 4; i++) {
            ov006_MenuEntry_Clear(&self->entries[i]);
        }
        self->unk8 = 3;
        self->unkC = 0;
        break;
    }
}

}
