#include "Main/Sys/SysTask.h"

extern "C" {

void func_02063374(Unk0214a418 *self) {
    void *saved;
    void *p;
    SysTaskVObj *v;

    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    p = self->unk_14;
    if (p != NULL) {
        if (p != NULL) {
            func_02041558(p);
            func_02041278((u8 *)p + 0x88);
            func_0203de1c(p);
        }
        self->unk_14 = NULL;
    }
    data_02097dd0->cur = saved;

    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    v = self->unk_10;
    if (v != NULL) {
        if (v != NULL) {
            v->Delete();
        }
        self->unk_10 = NULL;
    }
    data_02097dd0->cur = saved;

    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    p = self->unk_0c;
    if (p != NULL) {
        if (p != NULL) {
            func_ov000_0218fee4(p);
            func_0203de1c(p);
        }
        self->unk_0c = NULL;
    }
    data_02097dd0->cur = saved;

    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    p = self->unk_08;
    if (p != NULL) {
        if (p != NULL) {
            func_ov000_0218ea20(p);
            func_0203de1c(p);
        }
        self->unk_08 = NULL;
    }
    data_02097dd0->cur = saved;
    self->unk_04 = 0;
}

}
