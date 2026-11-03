#include "types.h"
#include "Main/Gfx/TexObj.h"
#include "ov000/Obj0216c954.h"

typedef struct {
    u32 a : 8;
    u32 b : 8;
    u32 x : 9;
    u32 c : 7;
    u32 chr : 10;
    u32 d : 22;
} Glyph0216c800;

extern "C" {

// The OAM callback of Obj0216c954's model (entry 6, registered by func_ov000_0216ca70 with the
// object as the entry's argument): draws count and total as two digits each.
Glyph0216c800 *func_ov000_0216c800(TexObj *self, TexObjEntry *e, Glyph0216c800 *arr, u16 *count) {
    u16 n = *count;
    Glyph0216c800 *last = &arr[n - 1];
    if (e->index == 6) {
        Obj0216c954 *o = (Obj0216c954 *)e->unk_08;
        u32 base = last->chr;
        s32 a = o->count;
        s32 b = o->total;
        arr[0].chr = base - a / 10;
        arr[0].x = 0x52;
        arr[0].a = 0x53;
        arr[1].chr = base - a % 10;
        arr[1].x = 0x5b;
        arr[1].a = 0x53;
        arr[2].chr = base - b / 10;
        arr[2].x = 0x6d;
        arr[2].a = 0x53;
        arr[3].chr = base - b % 10;
        arr[3].x = 0x76;
        arr[3].a = 0x53;
        n = 4;
    }
    *count = n;
    return arr;
}

}
