#include "ov006/Model.h"

typedef struct ov006_Unk02097e40 {
    u8 unk0[0x32];
    u16 unk32;
} ov006_Unk02097e40;

extern "C" {

extern void *data_ov006_021ec434;
extern u8 data_ov006_021eb840[];
extern ov006_Unk02097e40 *data_02097e40;

void *NNS_G2dGetCellDataByIdx(int a, u16 b);
void func_02042628(ov006_Model *model, void *a, ov006_ModelPart *part, int b);
void MI_CpuFill8(void *dst, u8 value, u32 size);
void MI_CpuCopy8(const void *src, void *dst, u32 size);
void MIi_CpuClear16(int value, void *dst, u32 size);
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

// The timer is read again here instead of reusing the value tested by the caller.
static inline void ov006_MenuNode_Tick(ov006_MenuNode *n) {
    u8 t = ((volatile ov006_MenuNode *)n)->timer;
    if (t != 0) {
        n->timer = t - 1;
    }
}

static inline void ov006_MenuNode_Delete(ov006_MenuNode *node) {
    OV006_DELETE_OBJECT(node);
}

static inline void ov006_Menu_Unlink(ov006_Unk021ec888 *self, ov006_MenuNode *n) {
    if (self->nodes == n) {
        self->nodes = n->next;
    }
    if (n->prev != NULL) {
        n->prev->next = n->next;
    }
    if (n->next != NULL) {
        n->next->prev = n->prev;
    }
}

void func_ov006_021e48fc(ov006_Unk021ec888 *self) {
    ov006_MenuNode *n = self->nodes;
    ov006_MenuNode *next;
    if (n == NULL) {
        return;
    }
    do {
        next = n->next;
        if (n->timer == 0) {
            ov006_Menu_Unlink(self, n);
            ov006_MenuNode_Delete(n);
            self->unk24--;
            self->unk26 = 1;
        } else {
            ov006_MenuNode_Tick(n);
        }
        n = next;
    } while (n != NULL);
}

}
