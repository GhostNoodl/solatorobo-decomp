#include "ov002/ov002.h"

extern "C" {

Task50 *func_ov002_021d22cc(void) {
    Task50 *p = (Task50 *)func_0203dd9c(0x118);
    if (p != NULL) {
        int i;
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021ef99c;
        func_02009e24((u8 *)p + 0x4c, 7, 0x18, func_ov002_021e4714, (void (*)(void *))func_ov002_021e473c);
        p->unk_3c = NULL;
        p->unk_40 = NULL;
        p->unk_44 = NULL;
        p->unk_48 = 0;
        for (i = 0; i < 7; i++) {
            func_ov002_021e4904((u8 *)p + 0x4c + i * 0x18);
        }
        MI_CpuFill8((u8 *)p + 0xf4, 0, 0x20);
        FIELD(p, 0x114, u8) = 0;
    }
    p->v0x8(0x18, 0x64);
    return p;
}

BOOL func_ov002_021d2390(void *self, void *arg) {
    u8 *owner = FIELD(self, 0x8, u8 *);
    if (arg != NULL) {
        u16 i = FIELD(arg, 0x4, u32);
        if (i <= 7) {
            void *str = FIELD(owner + i * 0x18, 0x60, void *);
            if (FIELD(owner, 0x40, VObject *) != NULL) {
                func_ov000_0215bb14(FIELD(owner, 0x40, VObject *), str);
                FIELD(owner, 0x40, VObject *)->v0x70();
            }
            func_02049a48(data_02097e4c, 0x1d, -1, -1, -1);
        }
    }
    return TRUE;
}

}
