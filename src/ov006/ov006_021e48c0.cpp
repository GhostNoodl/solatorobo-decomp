#include "ov006/Model.h"

typedef struct ov006_Unk02097e40 {
    u8 unk0[0x32];
    u16 unk32;
} ov006_Unk02097e40;

extern "C" {

extern void *data_ov006_021ec434;
extern u8 data_ov006_021eb840[];
extern ov006_Unk02097e40 *data_02097e40;

void *func_02023410(int a, u16 b);
void func_02042628(ov006_Model *model, void *a, ov006_ModelPart *part, int b);
void func_02016e28(void *dst, int value, u32 size);
void func_02016fa0(const void *src, void *dst, u32 size);
void func_02016ca4(int value, void *dst, u32 size);
int func_02046ab4(ov006_Unk02097e40 *a);
BOOL func_02045ea4(ov006_Unk02097e40 *a);
int func_ov006_021e4674(ov006_Unk021ec888 *self);

ov006_MenuNode *func_ov006_021e48c0(ov006_Unk021ec888 *self, int id) {
    ov006_MenuNode *node;
    for (node = self->nodes; node != NULL; node = node->next) {
        if (id == node->id) {
            break;
        }
    }
    return node;
}

ov006_MenuNode *func_ov006_021e48e8(ov006_MenuNode *self) {
    func_0203de1c(self);
    return self;
}

}
