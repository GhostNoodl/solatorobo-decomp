#include "ov002/ov002.h"

extern "C" {

void func_ov002_021ccda0(void) {
    Unk021f0f80 *p;
    if (data_ov002_021f0f80 != NULL) {
        return;
    }
    p = (Unk021f0f80 *)func_0203dd9c(sizeof(Unk021f0f80));
    if (p != NULL) {
        p->unk_00 = 0;
        p->unk_04 = 0;
        p->unk_08 = -1;
    }
    data_ov002_021f0f80 = p;
}

void func_ov002_021ccde4(void) {
    u32 saved;
    Unk021f0f80 *p;
    if (data_ov002_021f0f80 == NULL) {
        return;
    }
    saved = data_02097dd0[0];
    data_02097dd0[0] = data_02097dd0[2];
    p = data_ov002_021f0f80;
    if (p != NULL) {
        if (p != NULL) {
            if (p->unk_04 >= 1) {
                func_02036838(data_02097cdc, data_0208cca0, 7, 0);
                func_02036838(data_02097cdc, data_0208cc94, 7, 0);
                func_02036838(data_02097cdc, data_0214b105, 7, 0);
            }
            func_0203de1c(p);
        }
        data_ov002_021f0f80 = NULL;
    }
    data_02097dd0[0] = saved;
}

void func_ov002_021cceb4(Unk021cceb4 *self) {
    switch (self->state) {
    case 0:
        if (func_020594bc(data_02fe152c, 5, 1, 0) == 1) {
            data_0214a424->unk_18.b8 = 0;
            data_0214a424->unk_18.b9 = 0;
        }
        func_020359d0(data_0208cca0, 7, 0);
        func_020359d0(data_0208cc94, 7, 0);
        func_020359d0(data_0214b105, 7, 0);
        self->state = 1;
    case 1:
        func_02035b90(data_0208cca0, 7);
        func_02035b90(data_0208cc94, 7);
        if (func_02035b90(data_0214b105, 7) == 0) {
            return;
        }
        self->state = 2;
    case 2:
        func_ov000_02180660(0x10, 0);
        {
            BitByte *b = (BitByte *)(data_02097d48 + 0x8b0);
            b->b4 = 0;
            b->b5 = 1;
        }
        *(vu16 *)0x4000060 &= 0xcfdf;
        self->state = 3;
        return;
    case 3:
        BOOL r = func_ov002_inline_flag1();
        if (r) {
            func_ov000_02180754();
            func_0203cc58(0x1e000, 2, -1);
            self->flags.flag0 = 1;
            self->state = 4;
        }
        return;
    }
}

void func_ov002_021cd068(void) {
}

Task50 *func_ov002_021cd06c(void) {
    Task50 *p = (Task50 *)func_0203dd9c(sizeof(Task50));
    if (p != NULL) {
        Task_021cd06c_ctor(p);
    }
    VC(p, 0x8)(0x10, 0);
    return p;
}

void func_ov002_021cd0d4(Task50 *self) {
    func_020359fc(data_ov002_021ef3e4, data_ov002_021ef3ec, 2, 0);
    self->unk_4d = 1;
}

int func_ov002_021cd104(void) {
    return func_02035bd4(data_ov002_021ef3e4, data_ov002_021ef3ec, 2);
}

}
