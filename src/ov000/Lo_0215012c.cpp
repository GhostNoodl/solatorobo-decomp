#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"

extern "C" {
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021ca9c4[];
extern u8 data_0208ba70[];
void *Heap_Alloc(u32 size);
void func_0204c7d0(TextWin *win);

#define TEXTWIN_INIT(win) VOBJ_SET_VTABLE(win, data_0208ba70); func_0204c7d0(win)

Lo021ca9c4 *Lo021ca9c4_New(void) {
    Lo021ca9c4 *o = (Lo021ca9c4 *)Heap_Alloc(sizeof(Lo021ca9c4));
    if (o != NULL) {
        VOBJ_SET_VTABLE(o, data_ov000_021cc060);
        o->vfunc_58();
        VOBJ_SET_VTABLE(o, data_ov000_021ca9c4);
        TEXTWIN_INIT(&o->text[0]);
        TEXTWIN_INIT(&o->text[1]);
        TEXTWIN_INIT(&o->text[2]);
        TEXTWIN_INIT(&o->text[3]);
        TEXTWIN_INIT(&o->text[4]);
        TEXTWIN_INIT(&o->text[5]);
        o->vfunc_58();
    }
    o->vfunc_08(0xf, 0xb4);
    return o;
}

}
