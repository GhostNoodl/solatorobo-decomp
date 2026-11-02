#include "ov006/Tasks.h"

extern "C" {

void func_ov006_021e463c(ov006_Unk021ec888 *self);

void func_ov006_021d9fc0(ov006_Task021ec040 *self) {
    if (self->unk10 != NULL) {
        self->unk10->vfunc_20();
    }
    if (self->unk14 != NULL) {
        self->unk14->vfunc_20();
    }
    if (self->unk18 != NULL) {
        self->unk18->vfunc_20();
    }
    if (self->unk1C != NULL) {
        self->unk1C->vfunc_20();
    }
    if (self->unk20 != NULL) {
        self->unk20->vfunc_20();
    }
    if (self->unk28 != NULL) {
        self->unk28->vfunc_20();
    }
    if (self->unk24 != NULL) {
        self->unk24->vfunc_20();
    }
    if (self->subState < 0x32) {
        return;
    }
    if (data_ov006_021ec888 != NULL) {
        func_ov006_021e463c(data_ov006_021ec888);
    }
}

}
