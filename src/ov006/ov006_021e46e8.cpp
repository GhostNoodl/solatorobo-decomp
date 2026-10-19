// Built at a lower optimization level than the rest: loops are not rotated (they jump to a test at the
// bottom) and loop-invariant loads stay in the loop.
#pragma optimization_level 2
#include "ov006/ov006.h"

extern "C" {

extern ObjectVtbl data_ov006_021ec434;
extern u8 data_ov006_021eb840[];

void MI_CpuFill8(void *dst, u8 value, u32 size);
void MI_CpuCopy8(const void *src, void *dst, u32 size);
int func_ov006_021e4674(ov006_Unk021ec888 *self);

static inline BOOL ov006_KeyEq(const u8 *a, const u8 *b) {
    BOOL e2;
    BOOL e3;
    BOOL e4;
    BOOL e0;
    BOOL e1;
    e4 = FALSE;
    e3 = FALSE;
    e2 = FALSE;
    e0 = FALSE;
    e1 = FALSE;
    if (a[0] == b[0] && a[1] == b[1]) {
        e0 = TRUE;
    }
    if (e0 && a[2] == b[2]) {
        e1 = TRUE;
    }
    if (e1 && a[3] == b[3]) {
        e2 = TRUE;
    }
    if (e2 && a[4] == b[4]) {
        e3 = TRUE;
    }
    if (e3 && a[5] == b[5]) {
        e4 = TRUE;
    }
    return e4;
}

static inline ov006_MenuNode *ov006_MenuNode_New(void) {
    ov006_MenuNode *n = (ov006_MenuNode *)func_0203dd9c(sizeof(ov006_MenuNode));
    if (n != NULL) {
        n->vtbl = &data_ov006_021ec434;
        n->id = 0;
        n->count = 0;
        n->timer = 0;
        MI_CpuFill8(&n->data, 0, sizeof(n->data));
        n->data.key.b[0] = data_ov006_021eb840[0x10];
        n->data.key.b[1] = data_ov006_021eb840[0x11];
        n->data.key.b[2] = data_ov006_021eb840[0x12];
        n->data.key.b[3] = data_ov006_021eb840[0x13];
        n->data.key.b[4] = data_ov006_021eb840[0x14];
        n->data.key.b[5] = data_ov006_021eb840[0x15];
        n->next = NULL;
        n->prev = NULL;
    }
    return n;
}

BOOL func_ov006_021e46e8(ov006_Unk021ec888 *self, ov006_MenuData *data) {
    ov006_MenuNode *n;
    for (n = self->nodes; n != NULL; n = n->next) {
        if (ov006_KeyEq(n->data.key.b, data->key.b)) {
            MI_CpuCopy8(data, &n->data, sizeof(n->data));
            if (n->count < 0xffff) {
                n->count++;
            }
            n->timer = 8;
            self->unk26 = 1;
            return TRUE;
        }
    }
    if (self->unk24 >= 4) {
        return FALSE;
    }
    n = ov006_MenuNode_New();
    MI_CpuCopy8(data, &n->data, sizeof(n->data));
    n->id = func_ov006_021e4674(self);
    n->timer = 8;
    if (self->nodes != NULL) {
        n->next = self->nodes;
        self->nodes->prev = n;
    }
    self->nodes = n;
    self->unk26 = 1;
    self->unk24++;
    return TRUE;
}

}
