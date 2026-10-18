#include "ov006/ov006.h"

typedef struct ov006_Task021d9fc0 {
    void *vtbl;
    u32 flags;
    int unk8;
    int unkC;
    void *unk10;
    void *unk14;
    void *unk18;
    void *unk1C;
    void *unk20;
    void *unk24;
    void *unk28;
} ov006_Task021d9fc0;

extern "C" {

void func_ov006_021e463c(ov006_Unk021ec888 *self);

void func_ov006_021d9fc0(ov006_Task021d9fc0 *self) {
    if (self->unk10 != NULL) {
        VCALL(self->unk10, 20);
    }
    if (self->unk14 != NULL) {
        VCALL(self->unk14, 20);
    }
    if (self->unk18 != NULL) {
        VCALL(self->unk18, 20);
    }
    if (self->unk1C != NULL) {
        VCALL(self->unk1C, 20);
    }
    if (self->unk20 != NULL) {
        VCALL(self->unk20, 20);
    }
    if (self->unk28 != NULL) {
        VCALL(self->unk28, 20);
    }
    if (self->unk24 != NULL) {
        VCALL(self->unk24, 20);
    }
    if (self->unkC < 0x32) {
        return;
    }
    if (data_ov006_021ec888 != NULL) {
        func_ov006_021e463c(data_ov006_021ec888);
    }
}

}
