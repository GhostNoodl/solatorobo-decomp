#pragma inline_max_size(4096)
#include "Main/Gfx/SlideWin.h"
#include "Main/Sys/Field.h"
#include "Main/Gfx/FieldMsg.h"
#include "nnsys/g2d/g2d_Font.h"

// Name box and glyph cache of a slide window (at 0xc0).
struct SlideMsg {
    /* 0x000 */ u32 active : 1;
    /* 0x000 */ u32 shown : 1;
    /* 0x000 */ u32 unk_0_2 : 2;
    /* 0x000 */ u32 opening : 1;
    /* 0x000 */ u32 opened : 1;
    /* 0x000 */ u32 count : 8;
    /* 0x000 */ u32 flag14 : 1;
    /* 0x000 */ u32 closing : 1;
    /* 0x000 */ u32 flag16 : 1;
    /* 0x000 */ u32 unk_0_17 : 15;
    /* 0x004 */ s16 x;
    /* 0x006 */ s16 y;
    /* 0x008 */ s32 timer;
    /* 0x00c */ s32 t;
    /* 0x010 */ VramBlock *blocks[0x80];
    /* 0x210 */ u16 ids[0x80];
    /* 0x310 */ u16 nameId;
    /* 0x312 */ u16 prevNameId;
    /* 0x314 */ char name[0x20];
    /* 0x334 */ char prevName[0x20];
    /* 0x354 */ TextWin *win;
    /* 0x358 */ u32 vramSize;
    /* 0x35c */ s32 timer2;
    /* 0x360 */ s32 t2;
}; // size 0x364

struct SlideWinX : TextWin {
    /* 0x0b8 */ u32 mode : 4;
    /* 0x0b8 */ u32 unk_b8_4 : 10;
    /* 0x0b8 */ u32 flag14 : 1;
    /* 0x0b8 */ u32 unk_b8_15 : 1;
    /* 0x0b8 */ u32 unk_b8_16 : 8;
    /* 0x0b8 */ u32 unk_b8_24 : 8;
    /* 0x0bc */ u32 unk_bc_0 : 2;
    /* 0x0bc */ u32 style : 4;
    /* 0x0bc */ u32 unk_bc_6 : 26;
    /* 0x0c0 */ SlideMsg msgs[1];
    /* 0x424 */ SlidePanelItem items[2];
    /* 0x4bc */ SlidePanel panels[5];
    /* 0xb24 */ u8 unk_b24[0x38];
    /* 0xb5c */ s32 unk_b5c;
    /* 0xb60 */ s32 unk_b60;
    /* 0xb64 */ s32 unk_b64;
    /* 0xb68 */ s32 unk_b68;
    /* 0xb6c */ s32 unk_b6c;
    /* 0xb70 */ s32 page;
    /* 0xb74 */ s32 numPages;
    /* 0xb78 */ u32 unk_b78;
    /* 0xb7c */ const char *str;
};

struct SlideModel : Model {
    SlideModel(const char *name, const char *file, int a) {
        func_02041218(pltt);
        func_02041440(this, file, a);
        STD_CopyString(this->name, name);
    }
    static void *operator new(unsigned long size) {
        return func_0203dd9c(size);
    }
};

extern "C" {

extern void *func_0203a4c0(GfxMgr *mgr);
extern void func_0203a4dc(GfxMgr *mgr, void *arg);
extern void func_0203a5a4(GfxMgr *mgr, u16 c);
extern VramBlock *func_020397fc(u32 size, u32 arg, u32 c);
extern void func_0204cc18(TextWin *win, const char **s);
extern void func_0204cb28(TextWin *win, u32 arg);
extern void func_02051f70(SlideWinX *win);
extern const char *func_0206ffa0(u16 id);
extern void func_020708fc(u16 id, char *out);
extern void func_02070b98(u16 id, char *out, u16 a, u16 b);
extern void func_020359fc(const char *a, const void *b, int c, int d);
extern const char *data_0208b9cc[];
extern const char *data_0208cc90;

static inline void SlideMsg_ClearVram(VramBlock *b, u32 v4, u32 v6) {
    MIi_CpuClearFast(0, (u8 *)(b->kind == 4 ? v4 : v6) + b->addr, b->size - b->pad);
}

static inline void SlideMsg_Free(SlideMsg *msg, u32 v4, u32 v6) {
    int i;
    msg->active = 0;
    msg->count = 0;
    for (i = 0; i < 0x80; i++) {
        if (msg->blocks[i] != NULL) {
            SlideMsg_ClearVram(msg->blocks[i], v4, v6);
            func_02039828(msg->blocks[i]);
            msg->blocks[i] = NULL;
            msg->ids[i] = 0;
        }
    }
}

static inline BOOL SlideMsg_Close(SlideMsg *msg) {
    if (msg->flag16) {
        return FALSE;
    }
    msg->closing = 1;
    msg->flag16 = 1;
    msg->timer2 = 0;
    msg->t2 = 0;
    return TRUE;
}

static inline void SlideMsg_Open(SlideMsg *msg) {
    msg->active = 1;
    msg->unk_0_2 = 0;
    msg->opening = 1;
}

static inline void SlideMsg_SetName(SlideMsg *msg, const char *name, u16 id) {
    STD_CopyString(msg->name, name);
    msg->nameId = id;
}

static inline TextWin *SlideMsg_NewWin(void) {
    TextWin *win = (TextWin *)func_0203dd9c(0xb8);
    if (win != NULL) {
        *(const u32 **)win = data_0208ba70;
        func_0204c7d0(win);
    }
    return win;
}

static inline void SlideMsg_Show(SlideMsg *msg, const char *text) {
    TextWin *win;
    if (msg->win == NULL) {
        msg->win = SlideMsg_NewWin();
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
    msg->vramSize = msg->win->vramSize;
    msg->closing = 1;
    msg->flag16 = 0;
    msg->timer2 = 0;
    msg->t2 = 0;
    STD_CopyString(msg->prevName, msg->name);
    msg->prevNameId = msg->nameId;
}

static inline BOOL SlideMsg_NameChanged(SlideMsg *msg) {
    return STD_CompareString(msg->prevName, msg->name) != 0 ? TRUE : FALSE;
}

static inline BOOL Gfx_IsFadeIdle2(int ch) {
    if (data_02097d78[3] == 0 && data_02097d78[ch] == 0) {
        return TRUE;
    }
    return FALSE;
}

static inline BOOL Gfx_IsFadeDone(int ch) {
    if (data_02097d78[3] == 4) {
        return TRUE;
    }
    return data_02097d78[ch] == 4 ? TRUE : FALSE;
}

static inline BOOL SlideWin_IsClosing(SlideWinX *win) {
    int i;
    for (i = 0; i < 1; i++) {
        if (win->msgs[i].closing == 1) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline BOOL SlideWin_IsLoading(SlideWinX *win) {
    SlidePanel *e = win->panels;
    int i;
    for (i = 0; i < 5; i++, e++) {
        if (e->flag20 == 1 || e->nextModel != NULL) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline BOOL SlideWin_IsMoving(SlideWinX *win) {
    int i;
    for (i = 0; i < 5; i++) {
        if (win->panels[i].moving == 1) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline void SlidePanelItem_Close(SlidePanelItem *item) {
    if (!item->active) {
        if (item->unk_1c != NULL && item->state < 2) {
            item->active = 0;
            item->unk_0c = 0xffff;
            item->state = 2;
        }
    }
}

static inline u16 SlideWin_ConvId(u16 v) {
    if (v >= 150) {
        v += 0xff79;
    } else if (v >= 100) {
        v += 0xffa7;
    }
    return v;
}

static inline void SlidePanel_Open(SlidePanel *panel, BOOL sound) {
    int i;
    if (!panel->visible) {
        return;
    }
    if (!panel->flag27) {
        for (i = 0; i < 3; i++) {
            SlidePanelItem_Close(&panel->items[i]);
        }
        if (!panel->opened) {
            if (panel->cur == 3) {
                panel->state = 3;
                panel->frames = 10;
            } else {
                panel->state = 1;
                s32 target = SlidePanel_GetTarget(panel);
                panel->frames = SlidePanel_Abs(SlidePanel_GetEdge2(panel) - target) / 10;
            }
            panel->moving = 1;
            panel->frame = 0;
            panel->unk_20 = 0;
            if (sound && Gfx_IsFadeIdle(0)) {
                if (panel->kind >= 3) {
                    func_02049a48(data_02097e4c, 0x2f, -1, -1, -1);
                } else {
                    func_02049a48(data_02097e4c, 0x28, -1, -1, -1);
                }
            }
        }
        panel->opened = 1;
    }
}

static inline void GfxMgr_SetCursor(GfxMgr *m, s32 x, s32 y) {
    m->unk_00c = x;
    m->unk_00e = y;
}

static inline void SlideWin_ResetWait(SlideWinX *win) {
    win->unk_b5c = 0;
    win->unk_7c = 0;
}
static inline void SlideMsg_SetId(SlideMsg *msg, u16 c) {
    msg->ids[msg->count] = c;
}
static inline void SlideWin_Put(SlideWinX *win, SlideMsg *msg, u16 c) {
    win->unk_b5c = 0;
    win->unk_7c = 0;
    msg->ids[msg->count] = c;
}
/* OBJ VRAM bases of the two screens. Enum-typed locals are not constant-propagated,
   so the clear selects between registers as in the ROM (round lfA). */
typedef enum { SLIDE_VRAM_MAIN = 0x6400000, SLIDE_VRAM_SUB = 0x6600000 } SlideVram;

s32 func_020572f8(SlideWinX *win, SlideMsg *msg) {
    s16 count;
    s32 color;
    s32 adv;
    u8 stop;
    u8 nameChanged;
    s32 lineH;
    NNSG2dFont *font;
    NNSiG2dSplitCharCallback fn;
    u16 c;
    SlidePanel *panel;
    const char *saved;
    char name[0x20];
    char file[0x20];
    SlideVram v4;
    SlideVram v6;

    data_02097ce0->unk_004 = win->unk_28;
    panel = NULL;
    count = 0;
    data_02097ce0->unk_012 = win->unk_34;
    c = 0;
    if (win->unk_b60 >= 0) {
        return 0;
    }
    win->unk_b60 = 0;
    if (win->unk_b64 >= 0) {
        return 0;
    }
    win->unk_b64 = win->unk_b68;
    if ((!Gfx_IsFadeIdle2(0) && !Gfx_IsFadeDone(0)) || win->flag3 || win->flag25 || win->unk_bc_0 == 1 || win->style || win->flag14 ||
        SlideWin_IsClosing(win) || SlideWin_IsLoading(win) || Field_IsPlayerBusy()) {
        return 0;
    }
    if (*win->str == 0) {
        goto end;
    }
    font = (NNSG2dFont *)func_0203a4c0(data_02097ce0);
    adv = 0;
    fn = font->cbCharSpliter;
    msg = win->msgs;
    stop = adv;
    nameChanged = adv;
    lineH = font->pRes->linefeed + 1;
    color = win->unk_2c;
    saved = win->str;
    if ((c = fn((const void **)&win->str)) != 0) {
        v4 = SLIDE_VRAM_MAIN;
        v6 = SLIDE_VRAM_SUB;
        do {
            if (c == '\n') {
                win->unk_3c = msg->x;
                saved = win->str;
                win->unk_40 += lineH;
                continue;
            }
            if (c == '\\') {
                c = fn((const void **)&win->str);
            } else if (c == '<') {
                func_0204cc18(win, &win->str);
                switch (win->code) {
                case 20:
                    func_0204cb28(win, (u32)win->str);
                    break;
                case 22:
                case 23:
                    win->unk_vf7c();
                    break;
                case 24:
                case 25:
                    if (win->unk_b6c != 0) {
                        win->unk_vf80();
                    }
                    break;
                case 26:
                case 27:
                    win->unk_vf84();
                    break;
                case 28:
                case 29:
                    win->unk_vf88();
                    break;
                case 30:
                case 31:
                case 32:
                case 33:
                    win->unk_b8_16 = win->value;
                    win->unk_b8_24 = win->args[0];
                    break;
                case 34:
                    func_02051f70(win);
                    break;
                case 35:
                    win->style = win->value;
                    break;
                case 3:
                    win->unk_b6c++;
                    break;
                case 21:
                    win->unk_b6c++;
                    if (win->value != 0) {
                        win->flag27 = 1;
                    }
                    break;
                case 17:
                    if (win->value == 0) {
                        win->unk_b68 = 3;
                    } else if (win->value == 1) {
                        win->unk_b68 = 1;
                    } else if (win->value == 2) {
                        win->unk_b68 = 0;
                    } else if (win->value == 3) {
                        win->unk_b68 = 7;
                    } else {
                        win->text[0] = 0;
                        SlideMsg_Close(msg);
                        SlideMsg_Free(msg, v4, v6);
                        win->unk_3c = msg->x;
                        win->unk_40 = msg->y;
                    }
                    break;
                case 18:
                    win->unk_b64 = win->value;
                    stop = TRUE;
                    break;
                case 19:
                    win->unk_b60 = win->value;
                    stop = TRUE;
                    break;
                case 16:
                    color = win->unk_2c = win->value;
                    break;
                case 13:
                    if (win->mode) {
                        panel = &win->panels[win->value];
                        SlidePanel_Open(panel, TRUE);
                    }
                    break;
                case 36:
                    nameChanged = 0;
                    win->text[0] = 0;
                    SlideMsg_Close(msg);
                    SlideMsg_Free(msg, v4, v6);
                    win->unk_3c = msg->x;
                    win->unk_40 = msg->y;
                    win->flag27 = 1;
                    break;
                case 5: {
                    s32 a = win->args[0];
                    s32 idx = 0;
                    if (a >= 150) {
                        idx = 2;
                    } else if (a >= 100) {
                        idx = 1;
                        if (a == 100) {
                            break;
                        }
                    }
                    {
                        SlidePanelItem *item = &win->panels[win->value - 1].items[idx];
                        item->unk_0c = SlideWin_ConvId(a);
                        item->active = 1;
                    }
                    break;
                }
                case 6:
                    if (win->args[0] == 100) {
                        break;
                    }
                    win->items[0].unk_0c = SlideWin_ConvId(win->args[0]);
                    win->items[0].active = 1;
                    break;
                case 7:
                    win->items[1].unk_0c = SlideWin_ConvId(win->args[0]);
                    win->items[1].active = 1;
                    break;
                case 8:
                    SlidePanelItem_Close(&win->panels[win->value].items[0]);
                    break;
                case 9:
                    SlidePanelItem_Close(&win->panels[win->value].items[1]);
                    break;
                case 10:
                    SlidePanelItem_Close(&win->panels[win->value].items[2]);
                    break;
                case 11:
                    SlidePanelItem_Close(&win->items[0]);
                    break;
                case 12:
                    SlidePanelItem_Close(&win->items[1]);
                    break;
                case 4:
                    if (msg->active) {
                        SlideMsg_Free(msg, v4, v6);
                        win->unk_3c = msg->x;
                        win->unk_40 = msg->y;
                        win->str = saved;
                        return -1;
                    }
                    panel = &win->panels[win->value];
                    if (panel->moving == 1) {
                        win->str = saved;
                        return -1;
                    }
                    win->unk_b6c++;
                    if (win->mode) {
                        panel->kind = win->value;
                        panel->flag9 = win->args[0];
                        panel->unk_0_10 = win->args[1] & 3;
                        panel->flag23 = 0;
                        panel->flag25 = 0;
                    }
                    if (panel->unk_0a & 0xf000) {
                        nameChanged = 1;
                        if ((s8)panel->unk_128 == 0) {
                            STD_CopyString((char *)win->text, func_0206ffa0(panel->unk_0a));
                        } else {
                            STD_CopyString((char *)win->text, (char *)&panel->unk_128);
                        }
                        SlideMsg_SetName(msg, (char *)win->text, panel->unk_0a);
                    }
                    SlideMsg_Open(msg);
                    break;
                case 14:
                    if (panel != NULL) {
                        if (win->value == 0) {
                            panel->flag23 = 1;
                        }
                        if (win->value == 1) {
                            panel->flag25 = 1;
                        }
                    }
                    break;
                case 15:
                    if (panel != NULL) {
                        u32 v = win->value & 7;
                        if (panel->cur == 0) {
                            panel->next = v;
                        } else {
                            panel->next = panel->cur;
                        }
                        panel->cur = v;
                    }
                    break;
                case 0:
                    if (panel != NULL) {
                        if (win->args[0] != -1 && win->mode != 0 && (win->value >> 12) != 3) {
                            if (panel->textPos != (u16)win->unk_b6c) {
                                func_020708fc(win->value, name);
                                func_02070b98(win->value, file, win->args[2], win->args[0]);
                                if (panel->unk_08 == win->value && panel->unk_0a == win->value &&
                                    panel->unk_0c == win->args[2] && panel->unk_0e == win->args[2]) {
                                    panel->flag27 = 1;
                                } else {
                                    panel->flag27 = 0;
                                    panel->flag22 = panel->flag23;
                                    panel->flag24 = panel->flag25;
                                }
                                if (win->args[1] & 2) {
                                    if (!panel->flag26) {
                                        panel->flag27 = 0;
                                    }
                                    panel->flag26 = 1;
                                } else {
                                    if (panel->flag26 == 1) {
                                        panel->flag27 = 0;
                                    }
                                    panel->flag26 = 0;
                                }
                                panel->unk_0a = win->value;
                                panel->unk_0e = win->args[2];
                                panel->unk_12 = win->args[0];
                                panel->flag20 = 1;
                                panel->textPos = (u16)win->unk_b6c;
                                {
                                    SlideModel *m = new SlideModel(name, file, 1);
                                    panel->nextModel = m;
                                    func_020359fc(m->name, m->unk_04c, 2, 0);
                                }
                                if (panel->kind > 2) {
                                    SlideModel *m = new SlideModel(data_0208cc90, data_0208b9cc[panel->unk_0_10], 1);
                                    panel->nextModel2 = m;
                                    func_020359fc(m->name, m->unk_04c, 2, 0);
                                }
                                if (!panel->flag27 || panel->unk_10 != panel->unk_12) {
                                    for (int i = 0; i < 3; i++) {
                                        SlidePanelItem_Close(&panel->items[i]);
                                    }
                                }
                            }
                        } else {
                            if (win->args[0] == -1 && panel->model == NULL) {
                                panel->cur = 0;
                                panel->next = 0;
                            }
                            panel->unk_0a = win->value;
                        }
                        if (win->args[1] & 1) {
                            STD_CopyString((char *)&panel->unk_128, (char *)win->text);
                        } else {
                            panel->unk_128 = 0;
                        }
                    }
                    if (!(win->args[1] & 1)) {
                        STD_CopyString((char *)win->text, func_0206ffa0(win->value));
                    }
                    panel = NULL;
                case 1:
                    SlideMsg_SetName(msg, (char *)win->text, win->value);
                    nameChanged = 1;
                    break;
                }
                saved = win->str;
                if (!stop) {
                    continue;
                }
            } else if (c == 0x3001) {
                c = ' ';
                adv = 8;
            } else if (c == 0x3002) {
                c = ' ';
                adv = 0x10;
            } else if (c == ' ') {
                adv = -win->unk_b68;
            }
            if (nameChanged) {
                if (msg->win == NULL) {
                    SlideMsg_Show(msg, (char *)win->text);
                } else if (SlideMsg_NameChanged(msg)) {
                    if (!SlideMsg_Close(msg)) {
                        SlideMsg_Show(msg, (char *)win->text);
                    }
                }
                SlideMsg_Open(msg);
            }
            if (win->unk_b5c >= 0 || SlideWin_IsLoading(win) || SlideWin_IsMoving(win) || SlideWin_IsClosing(win) ||
                !msg->opened || stop) {
                win->str = saved;
                break;
            }
            SlideWin_ResetWait(win);
            if (!msg->active) {
                SlideMsg_Open(msg);
            }
            msg->ids[msg->count] = c;
            if (msg->blocks[msg->count] == NULL) {
                u16 idx = NNS_G2dFontFindGlyphIndex(font, c);
                const NNSG2dCharWidths *cw;
                if (idx == 0xffff) {
                    idx = font->pRes->alterCharIndex;
                }
                cw = NNS_G2dFontGetCharWidthsFromIndex(font, idx);
                msg->blocks[msg->count] = func_020397fc(cw->left + font->pRes->pGlyph->cellWidth,
                                                        font->pRes->pGlyph->cellHeight, 0);
            }
            func_0203a4dc(data_02097ce0, msg->blocks[msg->count]);
            GfxMgr_SetCursor(data_02097ce0, win->unk_3c, win->unk_40 - 1);
            data_02097ce0->unk_008 = color;
            func_0203a5a4(data_02097ce0, c);
            count++;
            if (c < 0x80 || c > 0xaf) {
                func_02049a48(data_02097e4c, 0x23, 0xe, -1, -1);
            }
            {
                u32 n;
                win->unk_3c = data_02097ce0->unk_00c;
                win->unk_b6c++;
                n = msg->count + 1;
                if (n < 0x80) {
                    msg->count = n;
                }
            }
            if (win->unk_b68 != 0) {
                if (adv != 0) {
                    win->unk_b64 = adv + win->unk_b68;
                } else {
                    win->unk_b64 = win->unk_b68;
                }
            } else {
                win->unk_b64 = 0;
            }
            break;
        } while ((c = fn((const void **)&win->str)) != 0);
    }
end:
    if (win->unk_b60 == 0) {
        if (c == 0 || *win->str == 0) {
            if (win->page >= win->numPages) {
                win->OnSkip();
            } else {
                win->page++;
                if (*win->str == 0) {
                    win->str++;
                }
                win->flag25 = 1;
                win->unk_18 = 0;
                win->unk_2c = 0;
            }
        }
    }
    return count;
}

}
