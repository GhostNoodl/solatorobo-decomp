#include "nitro/gx.h"
#include "nitro/gx_bgcnt.h"
#include "Main/Gfx/FieldMsg.h"
#include "Main/Sys/Field.h"

extern "C" {

static inline TextWin *TextWin_New(void) {
    TextWin *win = (TextWin *)Heap_Alloc(0xb8);
    if (win != NULL) {
        *(const u32 **)win = data_0208ba70;
        TextWin_Init(win);
    }
    return win;
}

void func_020556a0(FieldMsg *msg, const char *text) {
    TextWin *win;
    if (msg->win == NULL) {
        msg->win = TextWin_New();
    } else {
        msg->win->unk_vf08();
    }
    msg->win->font = 4;
    msg->win->unk_2c = 0;
    win = msg->win;
    win->str = (u32)text;
    win->unk_4c = Text_Measure(win->font, win->spacing, win->str, &win->width, &win->height, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = win->font;
    msg->win->unk_vf20(0, 0xc0);
    msg->win->noVram = 1;
    msg->win->flag24 = 1;
    if (STD_CompareString(text, data_0208ba20) != 0) {
        msg->win->rendering = 1;
    } else {
        msg->win->rendering = 0;
    }
    msg->winWidth = msg->win->width;
    msg->flag15 = 1;
    msg->flag16 = 0;
    msg->unk_35c = 0;
    msg->unk_360 = 0;
    STD_CopyString(msg->prevName, msg->name);
    msg->unk_312 = msg->unk_310;
}

BOOL FieldMsg_IsBusy(FieldMsg *msg) {
    FieldMsgEntry *e = msg->entries;
    int i;
    for (i = 0; i < 5; i++, e++) {
        if (e->busy == 1 || e->unk_030 != NULL) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline BOOL Field_HasEvent(void) {
    return data_ov000_021ccd54->event != 0 ? TRUE : FALSE;
}

BOOL Field_HasEvent_02055844(void) {
    return Field_HasEvent() ? TRUE : FALSE;
}

void Field_ClearEvent(void) {
    if (data_ov000_021ccd54->event != 0xffff) {
        data_ov000_021ccd54->event = 0;
    }
}

BOOL Field_IsPlayerBusy_02055898(void) {
    return Field_IsPlayerBusy();
}

// Same VRAM-free loop as MainVt_0208bbc8_Release: the OBJ VRAM bases are read with the
// SDK getters into locals before the loop, and `i` is a `long`.
void func_0205592c(GlyphCache *cache) {
    long i;
    u8 *objBase;
    u8 *subObjBase;
    cache->flag0 = 0;
    cache->count = 0;
    i = 0;
    objBase = (u8 *)G2_GetOBJCharPtr();
    subObjBase = (u8 *)G2S_GetOBJCharPtr();
    for (; i < 0x80; i++) {
        if (cache->blocks[i] != NULL) {
            VramBlock *b = cache->blocks[i];
            MIi_CpuClearFast(0, (b->kind == 4 ? objBase : subObjBase) + b->addr, b->size - b->pad);
            VramBlock_Free(cache->blocks[i]);
            cache->blocks[i] = NULL;
            cache->ids[i] = 0;
        }
    }
}

}
