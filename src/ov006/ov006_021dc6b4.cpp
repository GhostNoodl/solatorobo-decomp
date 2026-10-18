#include "ov006/ov006.h"

typedef struct ov006_Entry021dc6b4 {
    u32 unk0;
    u32 lo : 12;
    u32 pal : 4;
    u32 hi : 16;
} ov006_Entry021dc6b4;

typedef struct ov006_Unk021dc6b4 {
    u8 unk0[0x70];
    int unk70;
} ov006_Unk021dc6b4;

extern "C" {

ov006_Entry021dc6b4 *func_ov006_021dc6b4(ov006_Unk021dc6b4 *self, u16 *type, ov006_Entry021dc6b4 *arr, u16 *count) {
    u16 n = *count;
    if (*type == 0xf) {
        u8 add = self->unk70;
        int i;
        for (i = 0; i < n; i++) {
            arr[i].pal = arr[i].pal + add;
        }
    }
    *count = n;
    return arr;
}

}
