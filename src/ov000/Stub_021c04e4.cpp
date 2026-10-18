#include "ov000/VObj.h"

typedef struct {
    u32 b0 : 8;
    u32 b8 : 8;
    u32 b16 : 9;
    u32 b25 : 7;
    u32 c0 : 10;
    u32 c10 : 22;
} Entry021c04e4;

typedef struct {
    u8 unk_00[0x2c];
    s32 unk_2c;
} Sub021c04e4;

typedef struct {
    u16 type;
    u8 unk_02[0x6];
    Sub021c04e4 *unk_08;
} Src021c04e4;

extern "C" {

Entry021c04e4 *func_ov000_021c04e4(void *self, Src021c04e4 *src, Entry021c04e4 *out, u16 *count) {
    u16 n = *count;
    Entry021c04e4 *e = &out[n - 1];
    if (src->type == 2) {
        e->c0 = e->c0 - src->unk_08->unk_2c;
        e->b16 = 0x1f0;
        e->b0 = 0xf8;
        out = e;
        n = 1;
    }
    *count = n;
    return out;
}

}
