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

extern void *gMsgRes;
void *MsgRes_GetString(void *a, s32 b);
extern u8 UiObj_vtbl[];
extern u8 UiList_vtbl[];
extern u8 Ov000Vt_021cb1b0_vtbl[];
extern u8 Ov000Vt_021cb0b8_vtbl[];
extern const char *ResName_WifiCells;
extern const char *ArcPath_MenuWifi;
extern const char *ResName_CommonCells;
extern const char *ArcPath_Menu;

struct Obj02159998 {
    u8 unk_00[0x70];
    u32 unk_70;
};

LoGlyphEnt *Lo021cb5a8_OamCallback(Obj02159998 *self, u16 *msg, LoGlyphEnt *arr, u16 *cnt) {
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
