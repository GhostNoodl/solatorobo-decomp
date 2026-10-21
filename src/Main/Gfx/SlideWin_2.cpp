#include "Main/Gfx/SlideWin.h"
#include "Main/Gfx/GfxMgr.h"

extern "C" {

typedef u16 (*SlideCharFn)(const char **s);

typedef struct SlideFont {
    /* 0x0 */ s8 *info;
    /* 0x4 */ SlideCharFn splitChar;
} SlideFont;

extern void *func_0203a4c0(GfxMgr *mgr);
extern void func_0204cc18(TextWin *win, const char **s);
extern void func_020708fc(u16 id, char *out);
extern void func_02070b98(u16 id, char *out, u16 a, u16 b);
extern int func_020359fc(void *a, void *b, int c, int d);
extern const char *data_0208cc90;
extern const char *data_0208b9cc[];
void func_02051f70(SlideWin *win);

static inline Model *SlideModel_Init(Model *model, const char *name, const char *file, int a) {
    func_02041218(model->pltt);
    func_02041440(model, file, a);
    STD_CopyString(model->name, name);
    return model;
}

static inline void SlidePanel_SetCur(SlidePanel *p, u8 v) {
    if (p->cur == 0) p->next = v; else p->next = p->cur;
    p->cur = v;
}

void func_02051a34(SlideWin *win, SlideCharFn fn) {
    char name[0x20];
    BOOL open;
    u16 c;
    SlidePanel *panel;
    SlideFont *font;
    s32 skip;
    s32 pos;
    s32 line;
    const char *s;
    char file[0x20];
    data_02097ce0->unk_004 = win->unk_28;
    font = (SlideFont *)func_0203a4c0(data_02097ce0);
    panel = NULL;
    fn = font->splitChar;
    line = 0;
    open = FALSE;
    skip = 0;
    pos = 0;
    s = win->text;
    while (*s != 0) {
        while ((c = fn(&s)) != 0) {
            if (c == '\n') {
                if (*s != 0) {
                    continue;
                }
            } else if (c == '\\') {
                fn(&s);
            } else if (c == '<') {
                func_0204cc18(win, &s);
                switch (win->code) {
                    case 0x18:
                    case 0x19:
                        if (skip == 0) {
                            win->unk_vf80();
                        }
                        break;
                    case 0x15:
                        pos++;
                        break;
                    case 0x3:
                        pos++;
                        open = TRUE;
                        break;
                    case 0x22:
                        if (skip == 0) {
                            func_02051f70(win);
                        }
                        break;
                    case 0x23:
                        if (skip == 0) {
                            win->style = win->value;
                        }
                        break;
                    case 0x4:
                        pos++;
                        if (open) {
                            panel = &win->panels[win->value];
                            if (!panel->flag20) {
                                panel->kind = win->value;
                                panel->flag9 = win->args[0];
                                panel->unk_0_10 = win->args[1] & 3;
                                panel->flag23 = 0;
                                panel->flag25 = 0;
                            }
                        }
                        break;
                    case 0xe:
                        if (panel != NULL && !panel->flag20) {
                            if (win->value == 0) {
                                panel->flag23 = 1;
                            }
                            if (win->value == 1) {
                                panel->flag25 = 1;
                            }
                        }
                        break;
                    case 0xf:
                        if (panel != NULL && !panel->flag20) {
                            SlidePanel_SetCur(panel, win->value & 7);
                        }
                        break;
                    case 0x0:
                        if (panel != NULL && !panel->flag20) {
                            if (win->args[0] != -1 && win->mode != 0 && (win->value >> 12) != 3) {
                                Model *m;
                                func_020708fc(win->value, name);
                                func_02070b98(win->value, file, win->args[2], win->args[0]);
                                if (win->args[1] & 2) {
                                    panel->flag26 = 1;
                                } else {
                                    panel->flag26 = 0;
                                }
                                panel->unk_0a = win->value;
                                panel->unk_0e = win->args[2];
                                panel->unk_12 = win->args[0];
                                panel->flag22 = panel->flag23;
                                panel->flag24 = panel->flag25;
                                panel->flag27 = 0;
                                panel->flag20 = 1;
                                panel->textPos = (u16)pos;
                                m = (Model *)func_0203dd9c(0x160);
                                if (m != NULL) {
                                    SlideModel_Init(m, name, file, 1);
                                }
                                panel->nextModel = m;
                                func_020359fc(m->name, m->unk_04c, 2, 0);
                                if (panel->kind > 2) {
                                    m = (Model *)func_0203dd9c(0x160);
                                    if (m != NULL) {
                                        SlideModel_Init(m, data_0208cc90, data_0208b9cc[panel->unk_0_10], 1);
                                    }
                                    panel->nextModel2 = m;
                                    func_020359fc(m->name, m->unk_04c, 2, 0);
                                }
                                skip++;
                            } else {
                                panel->unk_0a = win->value;
                            }
                        }
                        panel = NULL;
                        break;
                }
            } else {
                pos++;
                skip++;
            }
            if (*s == 0) {
                open = FALSE;
                if (++line >= win->numLines) {
                    return;
                }
                s++;
            }
        }
    }
}

}
