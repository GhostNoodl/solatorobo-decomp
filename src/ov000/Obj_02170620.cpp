#include "types.h"
#include "Main/Sys/FieldState.h"
#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"
#include "ov000/MessageQueue.h"

#define NEW_02170620(o)                                    \
    do {                                                   \
        o = (Lo021cb0b8 *)Heap_Alloc(sizeof(Lo021cb0b8)); \
        if (o != NULL) {                                   \
            *(void **)o = UiObj_vtbl;             \
            o->vfunc_28();                                 \
            *(void **)o = UiList_vtbl;             \
            o->vfunc_28();                                 \
            *(void **)o = Ov000Vt_021cb1b0_vtbl;             \
            o->vfunc_28();                                 \
            *(void **)o = Ov000Vt_021cb0b8_vtbl;             \
            o->vfunc_28();                                 \
        }                                                  \
    } while (0)

extern "C" {
extern u8 UiObj_vtbl[];
extern u8 UiList_vtbl[];
extern u8 Ov000Vt_021cb1b0_vtbl[];
extern u8 Ov000Vt_021cb0b8_vtbl[];
void *Heap_Alloc(u32 size);
BOOL func_ov000_02184498(FieldState *p);

BOOL ListBuffer021cb940_OpenDialog(ListBuffer021cb940 *self, s32 kind, char *text) {
    Lo021cb0b8 *o;
    if (self->dialog != NULL) {
        return FALSE;
    }
    if (!func_ov000_02184498(gSceneCmd)) {
        return FALSE;
    }
    switch (kind) {
    case 0:
        NEW_02170620(o);
        self->dialog = o;
        o->text = text;
        self->dialog->flags &= ~0x4000000;
        break;
    case 1:
        NEW_02170620(o);
        self->dialog = o;
        o->text = text;
        self->dialog->flags |= 0x4000000;
        break;
    case 2:
        NEW_02170620(o);
        self->dialog = o;
        o->text = text;
        self->dialog->flags &= ~0x4000000;
        self->dialog->msgId = 0x8c;
        break;
    case 3:
        NEW_02170620(o);
        self->dialog = o;
        o->text = text;
        self->dialog->flags |= 0x4000000;
        self->dialog->msgId = 0x8c;
        break;
    }
    self->dialog->vfunc_08();
    if (self->state != 4) {
        self->state = 0xb;
    }
    return TRUE;
}
}
