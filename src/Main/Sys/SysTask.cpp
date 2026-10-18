#include "Main/Sys/SysTask.h"

extern "C" {

void func_0206298c(void) {
    Unk0214a418 *p;
    if (data_0214a418 != NULL) {
        return;
    }
    data_02097dd0->cur = data_02097dd0->unk_04;
    p = (Unk0214a418 *)func_0203dd9c(sizeof(Unk0214a418));
    if (p != NULL) {
        p->unk_00 = 0;
        p->unk_04 = 0;
        p->unk_08 = NULL;
        p->unk_0c = NULL;
        p->unk_10 = NULL;
        p->unk_14 = NULL;
    }
    data_0214a418 = p;
    data_02097dd0->cur = data_02097dd0->unk_08;
    data_02097d4c = func_02062aa0;
    data_02097d44 = 0;
}

static inline void Unk0214a418_Dtor(Unk0214a418 *p) {
    func_02063374(p);
    p->unk_00 = 0;
    p->unk_04 = 0;
    p->unk_08 = NULL;
    p->unk_0c = NULL;
    p->unk_10 = NULL;
    p->unk_14 = NULL;
}

void func_02062a24(void) {
    void *saved = data_02097dd0->cur;
    Unk0214a418 *p;
    data_02097dd0->cur = data_02097dd0->unk_04;
    p = data_0214a418;
    if (p != NULL) {
        if (p != NULL) {
            Unk0214a418_Dtor(p);
            func_0203de1c(p);
        }
        data_0214a418 = NULL;
    }
    data_02097dd0->cur = saved;
}

s32 func_02062aa0(s32 arg) {
    if (data_0214a418 == NULL) {
        return 0;
    }
    return func_02062ac8(data_0214a418, arg);
}

}
