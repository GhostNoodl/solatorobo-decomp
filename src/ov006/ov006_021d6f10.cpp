#include "ov006/Window.h"

/* The task with vtable data_ov006_021ebfc0 (task type 1); this is its draw slot 0x1c. */
struct ov006_Task021d6f10 : public ov006_Task {
    u8 unk10[0xc];
    void *unk1C;
    void *unk20;
    Model *unk24;
    void *unk28;
    void *unk2C;
    void *unk30;
    ov006_ListWin *unk34;
};

extern "C" {

void func_ov006_021de6bc(void *a);
void func_ov006_021e0480(void *a);
void func_ov006_021e28b4(void *a);
void func_ov006_021e1bb4(void *a);
void func_ov006_021e2490(void *a);
void func_ov006_021e463c(ov006_Unk021ec888 *self);

void func_ov006_021d6f10(ov006_Task021d6f10 *self) {
    if (self->state == 3) {
        func_ov006_021de6bc(self->unk1C);
        if (self->unk20 != NULL) {
            func_ov006_021e0480(self->unk20);
        }
        func_ov006_021e28b4(self->unk30);
        func_ov006_021e1bb4(self->unk28);
        func_ov006_021e2490(self->unk2C);
        Model_PlayPart(self->unk24, 0);
        if (self->unk34 != NULL) {
            self->unk34->vfunc_20();
        }
    }
    if (data_ov006_021ec888 != NULL) {
        func_ov006_021e463c(data_ov006_021ec888);
    }
}

}
