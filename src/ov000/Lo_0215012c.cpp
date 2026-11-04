#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"

extern "C" {
extern u8 Task_vtbl[];
extern u8 QuestWin_vtbl[];
extern u8 TextWin_vtbl[];
void *Heap_Alloc(u32 size);
void TextWin_Init(TextWin *win);

#define TEXTWIN_INIT(win) VOBJ_SET_VTABLE(win, TextWin_vtbl); TextWin_Init(win)

Lo021ca9c4 *QuestWin_New(void) {
    Lo021ca9c4 *o = (Lo021ca9c4 *)Heap_Alloc(sizeof(Lo021ca9c4));
    if (o != NULL) {
        VOBJ_SET_VTABLE(o, Task_vtbl);
        o->vfunc_58();
        VOBJ_SET_VTABLE(o, QuestWin_vtbl);
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
