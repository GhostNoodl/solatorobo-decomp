#include "ov006/Tasks.h"

typedef struct ov006_Unk021dba5c {
    void *vtbl;
    int state;
    u8 unk8[0x2c];
    int unk34;
} ov006_Unk021dba5c;

extern "C" {

void func_ov006_021dba5c(ov006_Unk021dba5c *self) {
    switch (self->state) {
    case 0:
        self->unk34 = 0x4000;
        func_02049a48(data_02097e4c, 0x28, -1, -1, -1);
        break;
    case 1:
        self->unk34 = 0x4000;
        func_02049a48(data_02097e4c, 0x28, -1, -1, -1);
        break;
    }
}

}
