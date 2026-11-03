#include "ov006/Window.h"

/* The task with vtable Ov006Vt_021ebfc0_vtbl (task type 1); this is its draw slot 0x1c. */
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

void ov006_Hud021de6bc_Draw(void *a);
void ov006_Unk021e0480_Draw(void *a);
void ov006_Marks_Draw(void *a);
void ov006_Unk021e1bb4_Draw(void *a);
void ov006_MarkerSet_Draw(void *a);
void ov006_Menu_ReleaseObj(ov006_Menu *self);

void Ov006Vt_021ebfc0_Draw(ov006_Task021d6f10 *self) {
    if (self->state == 3) {
        ov006_Hud021de6bc_Draw(self->unk1C);
        if (self->unk20 != NULL) {
            ov006_Unk021e0480_Draw(self->unk20);
        }
        ov006_Marks_Draw(self->unk30);
        ov006_Unk021e1bb4_Draw(self->unk28);
        ov006_MarkerSet_Draw(self->unk2C);
        Model_PlayPart(self->unk24, 0);
        if (self->unk34 != NULL) {
            self->unk34->vfunc_20();
        }
    }
    if (gOv006Menu != NULL) {
        ov006_Menu_ReleaseObj(gOv006Menu);
    }
}

}
