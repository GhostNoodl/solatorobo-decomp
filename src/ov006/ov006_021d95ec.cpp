#include "ov006/ov006.h"

typedef struct ov006_Task021d95ec {
    void *vtbl;
    u32 flags;
    int unk8;
    int unkC;
} ov006_Task021d95ec;

extern "C" {

extern u8 *data_02097d48;
extern void *data_ov000_021ccd40;
void func_ov000_02180660(int a, int b);
void func_ov006_021da098(ov006_Task021d95ec *self);
void func_ov006_021da208(ov006_Task021d95ec *self);

BOOL func_ov006_021d95ec(ov006_Task021d95ec *self) {
    switch (self->unkC) {
    case 0:
        func_ov000_02180660(0x23, 0);
        data_02097d48[0x8b0] |= 0x30;
        *(vu16 *)0x4000060 = (*(vu16 *)0x4000060 & ~0x3000) | 0x20;
        self->unkC++;
    case 1:
        if (data_ov000_021ccd40 != NULL) {
            VCALL(data_ov000_021ccd40, 4C);
            data_ov006_021ec888->unk15E = 2;
            func_ov006_021da098(self);
            func_ov006_021da208(self);
            return TRUE;
        }
        break;
    }
    return FALSE;
}

}
