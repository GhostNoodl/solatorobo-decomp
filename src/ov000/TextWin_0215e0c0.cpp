#include "Main/Gfx/FieldMsg.h"
#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

extern "C" {

extern const char data_ov000_021cabf4[];
extern void *gMsgRes;
char *MsgRes_GetString(void *p, s32 id);
void LoBase021cafc0_021cb0b8_Setup(LoBase021cafc0_021cb0b8 *self);

static inline TextWin *TextWin_New(void) {
    TextWin *win = (TextWin *)Heap_Alloc(0xb8);
    if (win != NULL) {
        *(const u32 **)win = TextWin_vtbl;
        TextWin_Init(win);
    }
    return win;
}

static inline void SetText(TextWin *win, u32 text) {
    win->str = text;
    win->unk_4c = Text_Measure(win->font, win->spacing, win->str, &win->width, &win->height, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    gGfxMgr->unk_004 = win->font;
}

static inline char *FindSpace(Lo021cb0b8 *self, s32 need) {
    s32 i;
    if (self->buf[0] == 0) {
        return self->buf;
    }
    for (i = 0; i < 0xff; i++) {
        if (self->buf[i] == 0 && self->buf[i + 1] == 0) {
            s32 n = i + 1;
            if (0xff - n > need) {
                return self->buf + n;
            }
            return self->buf;
        }
    }
    return NULL;
}

void LoBase021cafc0_021cb0b8_SetTitle(Lo021cb0b8 *self, const char *text) {
    char *dst;
    char *p;
    if (self->title != NULL) {
        return;
    }
    dst = FindSpace(self, STD_GetStringLength(text) + 1);
    STD_CopyString(dst, text);
    p = STD_SearchString(dst, data_ov000_021cabf4);
    if (p != NULL) {
        *p = 0;
    }
    self->title = TextWin_New();
    self->title->font = 8;
    SetText(self->title, (u32)dst);
    self->title->color0 = 0x7fff;
    self->title->color1 = 0x67f;
    self->title->flags |= 0x40;
    self->title->flags |= 0x1000000;
    self->title->flags |= 0x400000;
    self->title->flags |= 0x40000000;
    self->title->flags |= 0x4;
    if (p == NULL) {
        return;
    }
    self->title2 = TextWin_New();
    self->title2->font = 8;
    SetText(self->title2, (u32)(p + 1));
    self->title2->color0 = 0x7fff;
    self->title2->color1 = 0x67f;
    self->title2->flags |= 0x40;
    self->title2->flags |= 0x1000000;
    self->title2->flags |= 0x400000;
    self->title2->flags |= 0x40000000;
    self->title2->flags |= 0x4;
}

void Lo021cb0b8_Setup(Lo021cb0b8 *self) {
    char *p;
    char *dst;
    char *q;
    u16 i;
    BOOL done;
    UiListItem *node;
    u16 key;

    {
        void *d = gMsgRes;
        char *t;
        self->posX = 0;
        self->posY = 0;
        self->posZ = 0;
        if (self->msgId != 0xffff) {
            t = MsgRes_GetString(d, self->msgId);
        } else {
            t = MsgRes_GetString(d, 0x8d);
        }
        self->vfunc_10(t);
    }
    p = self->text;
    i = 0;
    done = FALSE;
    while (*p == '<') {
        p++;
        while (*p != '>') {
            p++;
        }
        if (*++p == 0) {
            p++;
        }
    }
    dst = FindSpace(self, STD_GetStringLength(p) + 1);
    STD_CopyString(dst, p);
    do {
        q = STD_SearchString(dst, data_ov000_021cabf4);
        if (q != NULL) {
            *q = 0;
        } else {
            done = TRUE;
        }
        self->vfunc_74(dst, i, 0xffff, 0xffff);
        dst = q + 1;
        i++;
    } while (!done);
    LoBase021cafc0_021cb0b8_Setup(self);
    key = self->key;
    for (node = self->items; node != NULL; node = node->next) {
        if (node->id == key) {
            break;
        }
    }
    self->vfunc_a8(node);
}

}
