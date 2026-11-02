#include "ov000/LoCommon.h"
#include "nitro/std.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"
#include "Main/Res/ResArc.h"

typedef struct {
    u32 a : 8;
    u32 b : 8;
    u32 c : 9;
    u32 d : 7;
    u32 f : 10;
    u32 rest : 22;
} LoGlyphEnt;

extern "C" {

extern void *data_02149ef8;
void *MsgRes_GetString(void *a, s32 b);
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
extern const char *data_0208cb84;
extern const char *data_0208cc8c;
extern const char *data_0208cb74;
extern const char *data_0208cca0;

struct Obj02159998 {
    u8 unk_00[0x70];
    u32 unk_70;
};

LoGlyphEnt *func_ov000_02159998(Obj02159998 *self, u16 *msg, LoGlyphEnt *arr, u16 *cnt) {
    u16 n = *cnt;
    LoGlyphEnt *e = &arr[n - 1];
    if (*msg == 2) {
        u32 v = e[0].f;
        u32 fl = self->unk_70;
        n = 1;
        if (fl & 1) {
            arr[0].f = v;
        }
        if (fl & 2) {
            arr[0].f = v - 1;
        }
        if (fl & 0x400) {
            arr[0].f = v - 2;
        }
        if (fl & 0x800) {
            arr[0].f = v - 3;
        }
        if (fl & 0x200) {
            arr[0].f = v - 4;
        }
        if (fl & 0x100) {
            arr[0].f = v - 5;
        }
        arr[0].c = 0;
        arr[0].a = 0;
    }
    *cnt = n;
    return arr;
}

}
