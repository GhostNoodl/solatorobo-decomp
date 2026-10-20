#include "Main/Gfx/FieldMsg.h"
#include "Main/Sys/Field.h"

extern "C" {

static inline TextWin *TextWin_New(void) {
    TextWin *win = (TextWin *)func_0203dd9c(0xb8);
    if (win != NULL) {
        *(const u32 **)win = data_0208ba70;
        func_0204c7d0(win);
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
    msg->win->unk_28 = 4;
    msg->win->unk_2c = 0;
    win = msg->win;
    win->unk_24 = (u32)text;
    win->unk_4c = func_0204c4fc(win->unk_28, win->unk_38, win->unk_24, &win->vramSize, &win->vramArg, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = win->unk_28;
    msg->win->unk_vf20(0, 0xc0);
    msg->win->noVram = 1;
    msg->win->flag24 = 1;
    if (STD_CompareString(text, data_0208ba20) != 0) {
        msg->win->rendering = 1;
    } else {
        msg->win->rendering = 0;
    }
    msg->unk_358 = msg->win->vramSize;
    msg->flag15 = 1;
    msg->flag16 = 0;
    msg->unk_35c = 0;
    msg->unk_360 = 0;
    STD_CopyString(msg->prevName, msg->name);
    msg->unk_312 = msg->unk_310;
}

BOOL func_020557f8(FieldMsg *msg) {
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
    return data_ov000_021ccd54->unk_d4 != 0 ? TRUE : FALSE;
}

BOOL func_02055844(void) {
    return Field_HasEvent() ? TRUE : FALSE;
}

void func_02055870(void) {
    if (data_ov000_021ccd54->unk_d4 != 0xffff) {
        data_ov000_021ccd54->unk_d4 = 0;
    }
}

BOOL func_02055898(void) {
    return Field_IsPlayerBusy();
}

// Same VRAM-free loop as func_02051210: the bases are variables with two
// definitions (the second is dead but keeps the optimizer from propagating
// them), and `i` is a `long`, which gives the target's register order.
void func_0205592c(GlyphCache *cache) {
    long i;
    u8 *objBase;
    u8 *subObjBase;
    cache->flag0 = 0;
    cache->count = 0;
    objBase = (u8 *)0x6400000;
    subObjBase = (u8 *)0x6600000;
    if ((u32)cache & 3) {
        objBase = (u8 *)0x6400000;
        subObjBase = (u8 *)0x6600000;
    }
    for (i = 0; i < 0x80; i++) {
        if (cache->blocks[i] != NULL) {
            VramBlock *b = cache->blocks[i];
            MIi_CpuClearFast(0, (b->kind == 4 ? objBase : subObjBase) + b->addr, b->size - b->pad);
            func_02039828(cache->blocks[i]);
            cache->blocks[i] = NULL;
            cache->ids[i] = 0;
        }
    }
}

}
