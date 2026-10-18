#include "ov000/VObj.h"

typedef struct {
    u32 unk_00;
    u32 unk_04_0 : 12;
    u32 pal : 4;
    u32 unk_04_16 : 16;
} Entry021be1a8;

typedef struct {
    u8 unk_00[0x30];
    s32 unk_30;
} Sub021be1a8;

typedef struct {
    u16 type;
    u8 unk_02[0x6];
    Sub021be1a8 *unk_08;
} Src021be1a8;

extern "C" {

Entry021be1a8 *func_ov000_021be1a8(void *self, Src021be1a8 *src, Entry021be1a8 *out, u16 *count) {
    u16 n = *count;
    Entry021be1a8 *last = &out[n - 1];
    if (src->type == 3) {
        u32 pal = last->pal;
        if (src->unk_08->unk_30 == 0) {
            s32 i;
            for (i = 0; i < n; i++) {
                out[i].pal = pal + 2;
            }
        }
    }
    *count = n;
    return out;
}

}
