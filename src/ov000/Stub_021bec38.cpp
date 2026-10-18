#include "ov000/VObj.h"

typedef struct {
    u32 b0 : 8;
    u32 b8 : 8;
    u32 b16 : 9;
    u32 b25 : 7;
    u32 c0 : 10;
    u32 c10 : 22;
} Entry021bec38;

typedef struct {
    u8 unk_00[0x3c];
    s32 unk_3c;
} Sub021bec38;

typedef struct {
    u16 type;
    u8 unk_02[0x6];
    Sub021bec38 *unk_08;
} Src021bec38;

extern "C" {

Entry021bec38 *func_ov000_021bec38(void *self, Src021bec38 *src, Entry021bec38 *out, u16 *count) {
    u16 n = *count;
    Entry021bec38 *e = &out[n - 1];
    if (src->type == 2) {
        e->c0 = e->c0 - src->unk_08->unk_3c;
        e->b16 = 0x1f8;
        e->b0 = 0xd4;
        out = e;
        n = 1;
    }
    *count = n;
    return out;
}

}
