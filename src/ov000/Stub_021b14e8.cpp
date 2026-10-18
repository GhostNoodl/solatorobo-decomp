#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x18];
    u16 unk_18_0 : 9;
    u16 unk_18_9 : 1;
    u16 unk_18_10 : 6;
} Obj0214a424;

extern "C" {

extern Obj0214a424 *data_0214a424;
void func_02062764(s32 a, s32 b);

void func_ov000_021b14e8(void) {
    data_0214a424->unk_18_9 = 1;
    func_02062764(0xc, 4);
}

void func_ov000_021b1514(void) {
    data_0214a424->unk_18_9 = 0;
    func_02062764(0xc, 8);
}

}
