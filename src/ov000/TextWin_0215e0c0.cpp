#include "Main/Gfx/FieldMsg.h"
#include "ov000/VObj.h"

typedef struct {
    u8 pad[0x14];
    TextWin *win;
    u8 pad18[0xbc];
    TextWin *win2;
    s8 buf[0x100];
    u16 msgId;
    u8 pad1da[2];
    char *text;
    u16 key;
} Obj0215e0c0;

typedef struct Node0215e344 {
    u8 pad[6];
    u16 id;
    u8 pad8[0x24];
    struct Node0215e344 *next;
} Node0215e344;

extern "C" {

extern const char data_ov000_021cabf4[];
char *STD_SearchString(char *str, const char *sub);
extern void *data_02149ef8;
char *func_0204c0e8(void *p, s32 id);
void func_ov000_0215aa78(VObj *self);

static inline TextWin *TextWin_New(void) {
    TextWin *win = (TextWin *)func_0203dd9c(0xb8);
    if (win != NULL) {
        *(const u32 **)win = data_0208ba70;
        func_0204c7d0(win);
    }
    return win;
}

static inline void SetText(TextWin *win, u32 text) {
    win->unk_24 = text;
    win->unk_4c = func_0204c4fc(win->unk_28, win->unk_38, win->unk_24, &win->vramSize, &win->vramArg, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = win->unk_28;
}

static inline char *FindSpace(Obj0215e0c0 *self, s32 need) {
    s32 i;
    if (self->buf[0] == 0) {
        return (char *)self->buf;
    }
    for (i = 0; i < 0xff; i++) {
        if (self->buf[i] == 0 && self->buf[i + 1] == 0) {
            s32 n = i + 1;
            if (0xff - n > need) {
                return (char *)self->buf + n;
            }
            return (char *)self->buf;
        }
    }
    return NULL;
}

void func_ov000_0215e0c0(Obj0215e0c0 *self, const char *text) {
    char *dst;
    char *p;
    if (self->win != NULL) {
        return;
    }
    dst = FindSpace(self, STD_GetStringLength(text) + 1);
    STD_CopyString(dst, text);
    p = STD_SearchString(dst, data_ov000_021cabf4);
    if (p != NULL) {
        *p = 0;
    }
    self->win = TextWin_New();
    self->win->unk_28 = 8;
    SetText(self->win, (u32)dst);
    self->win->unk_74 = 0x7fff;
    self->win->unk_76 = 0x67f;
    *(u32 *)((u8 *)self->win + 4) |= 0x40;
    *(u32 *)((u8 *)self->win + 4) |= 0x1000000;
    *(u32 *)((u8 *)self->win + 4) |= 0x400000;
    *(u32 *)((u8 *)self->win + 4) |= 0x40000000;
    *(u32 *)((u8 *)self->win + 4) |= 0x4;
    if (p == NULL) {
        return;
    }
    self->win2 = TextWin_New();
    self->win2->unk_28 = 8;
    SetText(self->win2, (u32)(p + 1));
    self->win2->unk_74 = 0x7fff;
    self->win2->unk_76 = 0x67f;
    *(u32 *)((u8 *)self->win2 + 4) |= 0x40;
    *(u32 *)((u8 *)self->win2 + 4) |= 0x1000000;
    *(u32 *)((u8 *)self->win2 + 4) |= 0x400000;
    *(u32 *)((u8 *)self->win2 + 4) |= 0x40000000;
    *(u32 *)((u8 *)self->win2 + 4) |= 0x4;
}

void func_ov000_0215e344(Obj0215e0c0 *self) {
    char *p;
    char *dst;
    char *q;
    u16 i;
    BOOL done;
    Node0215e344 *node;
    u16 key;

    {
        void *d = data_02149ef8;
        char *t;
        *(u16 *)((u8 *)self + 0x64) = 0;
        *(u16 *)((u8 *)self + 0x66) = 0;
        *(u16 *)((u8 *)self + 0x68) = 0;
        if (self->msgId != 0xffff) {
            t = func_0204c0e8(d, self->msgId);
        } else {
            t = func_0204c0e8(d, 0x8d);
        }
        ((VObj *)self)->vfunc_10(t);
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
        ((VObj *)self)->vfunc_74(dst, i, 0xffff, 0xffff);
        dst = q + 1;
        i++;
    } while (!done);
    func_ov000_0215aa78((VObj *)self);
    key = self->key;
    for (node = *(Node0215e344 **)((u8 *)self + 0x94); node != NULL; node = node->next) {
        if (node->id == key) {
            break;
        }
    }
    ((VObj *)self)->vfunc_a8(node);
}

}
