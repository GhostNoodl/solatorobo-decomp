#include "ov006/Model.h"

typedef struct ov006_Unk02097e40 {
    u8 unk0[0x32];
    u16 unk32;
} ov006_Unk02097e40;

extern "C" {

extern void *data_ov006_021ec434;
extern u8 data_ov006_021eb840[];
extern ov006_Unk02097e40 *data_02097e40;

void MI_CpuFill8(void *dst, u8 value, u32 size);
void MI_CpuCopy8(const void *src, void *dst, u32 size);
void MIi_CpuClear16(int value, void *dst, u32 size);
int func_02046ab4(ov006_Unk02097e40 *a);
BOOL func_02045ea4(ov006_Unk02097e40 *a, BOOL enabled);
int func_ov006_021e4674(ov006_Unk021ec888 *self);

void func_ov006_021e4574(ov006_Unk021ec888 *self) {
    ov006_ModelHolder *holder;

    if (data_ov006_021ec888->unk8 == 0 || (holder = self->unk1D4) == NULL) {
        return;
    }
    if (holder->unkC >= 4) {
        return;
    }
    if (holder->model == NULL) {
        return;
    }
    ov006_Model_SetPos(holder->model, holder->unk8, 0x76000, 0x46000);
    ov006_Model_PlayPart(holder->model, holder->unkC);
}

void func_ov006_021e463c(ov006_Unk021ec888 *self) {
    Object *obj;
    if (data_ov006_021ec888->unk8 != 0 && (obj = self->unk1D8->obj) != NULL) {
        VCALL(obj, 20);
    }
}

int func_ov006_021e4674(ov006_Unk021ec888 *self) {
    int id = self->unk30;
    BOOL unique;
    do {
        unique = TRUE;
        if (id == 0) {
            unique = FALSE;
            id++;
        } else {
            ov006_MenuNode *node;
            for (node = self->nodes; node != NULL; node = node->next) {
                if (id == node->id) {
                    unique = FALSE;
                    id++;
                    break;
                }
            }
        }
    } while (!unique);
    self->unk30 = (u16)(id + 1);
    return id;
}

}
