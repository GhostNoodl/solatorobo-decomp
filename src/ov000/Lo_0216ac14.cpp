#include "ov000/LoCommon.h"
#include "Main/Gfx/TexObj.h"
#include "ov000/Obj0216ad04.h"

typedef struct {
    u32 a : 8;
    u32 b : 8;
    u32 c : 9;
    u32 d : 7;
    u32 f : 10;
    u32 rest : 22;
} LoGlyphEnt;

extern "C" {

// The OAM callback of Obj0216ad04's model (entry 6, registered by func_ov000_0216b1b4 with the
// object as the entry's argument): draws value as one or two digits.
LoGlyphEnt *func_ov000_0216ac14(TexObj *self, TexObjEntry *msg, LoGlyphEnt *arr, u16 *cnt) {
    u16 n = *cnt;
    LoGlyphEnt *e = &arr[n - 1];
    if (msg->index == 6) {
        u32 f = e->f;
        s32 v = ((Obj0216ad04 *)msg->unk_08)->value;
        if (v >= 10) {
            e[-1].f = f - v % 10;
            e[0].f = f - v / 10;
            arr = e - 1;
            n = 2;
        } else {
            e[-1].f = f - v % 10;
            arr = e - 1;
            n = 1;
        }
    }
    *cnt = n;
    return arr;
}

}
