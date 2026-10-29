// One source file for 0x0204c158..0x02052fcc: the message resource singleton, the
// text windows and text boxes, the slide windows, the scene shake and the 3D object
// animation code. It is one translation unit because its string literals share one
// pool (0x0208b9dc..0x0208ba20). The former files are kept as they were, each in its
// own namespace, so that their local typedefs, inlines and extern declarations do not
// clash.
#pragma pool_strings on
#pragma dont_reuse_strings off

#include "nitro/os_interrupt.h"
#include "nitro/gx.h"
#include "nitro/gx_g3b.h"
#include "nitro/gx_bgcnt.h"
#include "nitro/mi.h"
#include "Main/Res/MsgRes.h"
#include "Main/Res/ResMgr.h"
#include "Main/Gfx/TextWin.h"
#define SND_DEFINE_GLOBALS
#include "Main/Snd/SndMgr.h"
#include "nnsys/g2d/g2d_Font.h"
#include "Main/Gfx/GfxMgr.h"
#include "types.h"
#include "Main/Gfx/SlideWin.h"
#include "Main/Res/StageRes.h"
#include "Main/Gfx/Obj3D.h"
#include "Main/Sys/GameScene.h"
#include "Main/Sys/Field.h"

// ---- MsgRes_3
namespace m_MsgRes_3 {

extern "C" {

// Defined as two globals in the message resource TU.
extern struct {
    void *unk_00;
    MsgRes *res;
} data_02149ef4;
#define MSG_RES data_02149ef4.res

extern void *func_0203dd9c(u32 size);
extern void func_0203de1c(void *ptr);
extern void func_0206e900(char *dst, const char *src);

static inline void MsgRes_Reset(MsgRes *res) {
    res->type = 0;
    res->entries = NULL;
    res->numEntries = 0;
    res->strings = NULL;
}

void func_0204bfcc(MsgRes *res);

static inline void MsgRes_OpenFile(MsgRes *res, const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    func_0206e900(arc, arcName);
    func_0206e900(file, name);
    res->Open(arc, file);
}

void func_0204bfe4(MsgRes *res, const char *arcName, const char *name);

BOOL func_0204c030(MsgRes *res);

u32 func_0204c08c(MsgRes *res, s32 idx, char **out, s32 max);

char *func_0204c0e8(MsgRes *res, s32 idx);

void func_0204c100(void);

BOOL func_0204c120(void);

void func_0204c138(void);

static inline void MsgRes_OpenFile2(MsgRes *res, const char *arcName, const char *name) {
    char file[0x20];
    char arc[0x20];
    func_0206e900(arc, arcName);
    func_0206e900(file, name);
    res->Open(arc, file);
}

void func_0204c158(void) {
    MsgRes *res;
    if (MSG_RES != NULL) {
        return;
    }
    res = (MsgRes *)func_0203dd9c(sizeof(MsgRes));
    if (res != NULL) {
        *(const u32 **)res = data_0208b318;
        res->Clear();
        *(const u32 **)res = data_0208ba30;
        MsgRes_Reset(res);
    }
    MSG_RES = res;
    MsgRes_OpenFile2(res, "script/cmninfo", "cmn.ccmes");
}

void func_0204c214(void) {
    void *heap = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    if (MSG_RES != NULL) {
        if (MSG_RES != NULL) {
            MSG_RES->DeletingDtor();
        }
        MSG_RES = NULL;
    }
    data_02097dd0->cur = heap;
}

void *func_0204c270(void) {
    return data_02097dd0->cur;
}

void func_0204c284(void) {
    data_02097dd0->cur = data_02097dd0->unk_08;
}

MsgRes *func_0204c29c(MsgRes *res) {
    MsgRes_Reset(res);
    *(const u32 **)res = data_0208b318;
    res->Unload();
    func_0203de1c(res);
    return res;
}

void func_0204c2e0(void *heap) {
    data_02097dd0->cur = heap;
}

}

}  // namespace m_MsgRes_3
#undef MSG_RES

// ---- TextWin
namespace m_TextWin {

// Base of the text layout helper; its vtable stays in asm.
struct TextLayout {
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void Clear();
};

extern "C" {

extern const u32 data_0208ba70[];
extern void (*NNS_GfdDefaultFuncFreeTexVram)(void *p);
extern void (*NNS_GfdDefaultFuncFreePlttVram)(void *p);

extern void *func_0203de84(u32 size, u32 align);
extern void func_0203df0c(void *ptr);
extern void func_0203de1c(void *ptr);
extern void func_0203e58c(void *ptr);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void func_02039828(VramBlock *block);
extern VramBlock *func_020397fc(u32 size, u32 arg, u32 c);
extern s32 func_02040778(const char *s, int *len);
extern void func_0205bef8(void *cmd);

typedef u16 (*TextScanCharFn)(const char **s);

// Stack copy of a TextWin used only for tag parsing.
typedef struct TextScanParser {
    /* 0x00 */ const u32 *vt;
    /* 0x04 */ u8 unk_04[0x7c];
    /* 0x80 */ s32 code;
    /* 0x84 */ s32 value;
    /* 0x88 */ u8 unk_88[0x30];
} TextScanParser;

extern void *func_0203a4c0(GfxMgr *mgr);
void func_0204c7d0(TextWin *win);
void func_0204cc18(TextScanParser *p, const char **s);

// Copies the visible characters of str into out (keeping tag 0x10 verbatim)
// and returns the width of the last line.
s32 func_0204c2f4(char *out, s32 outSize, const char *str) {
    const char *s;
    TextScanParser p;
    const char *tmp;
    TextScanCharFn fn;
    const char *start;
    u16 c;
    s32 len;
    s32 maxW;
    NNSG2dFont *f;
    s32 w;
    u32 n;
    u32 i;
    if (str == NULL) {
        return 0;
    }
    f = (NNSG2dFont *)func_0203a4c0(data_02097ce0);
    fn = (TextScanCharFn)f->cbCharSpliter;
    len = 0;
    s = str;
    p.vt = data_0208ba70;
    func_0204c7d0((TextWin *)&p);
    maxW = 0;
    w = 0;
    // The outer loop is entered at its test and tests *s twice there.
    goto test;
    do {
        while (start = s, (c = fn(&s)) != 0) {
            if (c == '\n') {
                maxW = w > maxW ? w : maxW;
                w = 0;
            }
            if (c == '\\') {
                start = s;
                c = fn(&s);
            } else if (c == '<') {
                tmp = s;
                func_0204cc18(&p, &tmp);
                if (p.code == 0x10) {
                    out[len++] = c;
                    do {
                        c = fn(&s);
                        if (len < outSize - 1) {
                            out[len++] = c;
                        }
                    } while (c != '>');
                } else {
                    s = tmp;
                }
                start = s;
            }
            n = s - start;
            if (n != 0) {
                for (i = 0; i < n; i++) {
                    if (len < outSize - 1) {
                        out[len++] = start[i];
                    }
                }
                out[len] = 0;
                w += NNS_G2dFontGetCharWidth(f, c);
            }
            if (*s == 0) {
                break;
            }
        }
    test:
        if (*s == 0) {
            break;
        }
    } while (*s != 0);
    p.vt = data_0208ba70;
    ((TextLayout *)&p)->Clear();
    return w;
}


TextLayout *func_0204c4d4(TextLayout *layout) {
    *(const u32 **)layout = data_0208ba70;
    layout->Clear();
    return layout;
}

// Measures str: the widest line in *outW and the total height in *outH.
// Returns the number of characters; raw skips escapes and tags.
s32 func_0204c4fc(s32 font, s32 spacing, const char *str, s32 *outW, s32 *outH, bool raw) {
    const char *s;
    TextScanParser p;
    u16 c;
    s32 w;
    s32 n;
    NNSG2dFont *f;
    TextScanCharFn fn;
    s32 maxW;
    s32 h;
    data_02097ce0->unk_004 = font;
    f = (NNSG2dFont *)func_0203a4c0(data_02097ce0);
    fn = (TextScanCharFn)f->cbCharSpliter;
    s = str;
    p.vt = data_0208ba70;
    func_0204c7d0((TextWin *)&p);
    n = 0;
    w = 0;
    maxW = 0;
    h = spacing + f->pRes->pGlyph->cellHeight;
    while (*s != 0) {
        while ((c = fn(&s)) != 0) {
            if (c == '\n') {
                if (w > maxW) {
                    maxW = w;
                }
                w = 0;
                h += spacing + f->pRes->pGlyph->cellHeight;
                break;
            }
            if (!raw) {
                if (c == '\\') {
                    c = fn(&s);
                } else if (c == '<') {
                    func_0204cc18(&p, &s);
                    if (*s == 0) {
                        break;
                    }
                    continue;
                }
            }
            w += NNS_G2dFontGetCharWidth(f, c);
            n++;
            if (*s == 0) {
                break;
            }
        }
    }
    if (w > maxW) {
        maxW = w;
    }
    if (outW != NULL) {
        *outW = maxW;
    }
    if (outH != NULL) {
        *outH = h;
    }
    p.vt = data_0208ba70;
    ((TextLayout *)&p)->Clear();
    return n;
}

void func_0204c7d0(TextWin *win);

void func_0204c8a8(TextWin *win);

Model *func_0204c9f8(Model *model);

void func_0204ca14(TextWin *win, u32 n);

void func_0204ca70(TextWin *win);

typedef struct TextCmd {
    /* 0x0 */ u32 unk_0;
    /* 0x4 */ u16 flags;
    /* 0x6 */ u16 id;
    /* 0x8 */ u16 args[6];
} TextCmd;

void func_0204cb28(TextWin *win, u32 arg);

char *func_0204cef4(TextWin *win, char *p);

char *func_0204cf18(TextWin *win, char *p);

char *func_0204cf6c(TextWin *win, char *p);

char *func_0204cfa0(TextWin *win, char *p);

char *func_0204d014(TextWin *win, char *p);


// Compares a tag name up to its closing '>'. Returns 0 on a match.
static inline int TextWin_TagCmp(char c, const char *s, const char *tag) {
    if (c != '>') {
        do {
            if (*s++ != *tag++) {
                return 1;
            }
        } while (*s != '>');
    }
    return 0;
}

char *func_0204d040(TextWin *win, char *p);

char *func_0204d238(TextWin *win, char *p);

char *func_0204d380(TextWin *win, char *p);

char *func_0204d4b0(TextWin *win, char *p);

char *func_0204d54c(TextWin *win, char *p);

char *func_0204d57c(TextWin *win, char *p);

char *func_0204d7e0(TextWin *win, char *p);

char *func_0204d82c(TextWin *win, char *p);

char *func_0204d870(TextWin *win, char *p);

char *func_0204d8c0(TextWin *win, char *p);

char *func_0204d8f8(TextWin *win, char *p);

char *func_0204d930(TextWin *win, char *p);

char *func_0204d9f0(TextWin *win, char *p);

char *func_0204da2c(TextWin *win, char *p);

char *func_0204da68(TextWin *win, char *p);

char *func_0204da78(TextWin *win, char *p);

extern SndQueue *data_02097e48;
extern SndMgr *data_02097e4c;
extern void func_0204aab0(SndQueue *queue, u16 value);
extern void func_0204a284(SndMgr *mgr, s32 fade);

static inline void SndQueue_RequestBgm(SndQueue *queue, u16 bgm) {
    if (!queue->flag0) {
        return;
    }
    if (queue->unk_06 == 0xffff && queue->unk_04 == bgm) {
        return;
    }
    if (queue->unk_02 != 10 && queue->unk_02 != 0) {
        if (queue->unk_06 != 0xffff) {
            func_0204aab0(queue, queue->unk_06);
        }
        queue->unk_02 = 1;
    } else {
        queue->unk_02 = 0;
    }
    queue->unk_06 = bgm;
    queue->unk_08 = 10;
}

static inline void SndQueue_StopBgm(SndQueue *queue, u16 fade) {
    if (queue->flag3) {
        queue->unk_06 = 0x8000;
        queue->unk_08 = fade;
        queue->unk_02 = 0;
    }
}

void func_0204daf4(TextWin *win);

void func_0204dbc8(TextWin *win);

void func_0204dc04(TextWin *win);

extern SndHandle *func_02049a48(SndMgr *mgr, s32 id, s32 volume, s32 targetVolume, s32 frames);
extern void func_02049de8(SndMgr *mgr, s32 id);

void func_0204dc84(TextWin *win);

typedef struct PadState {
    /* 0x00 */ u8 unk_00[0x12];
    /* 0x12 */ u16 trig;
} PadState;

extern PadState *data_02097dc8;

BOOL func_0204dccc(TextWin *win);

u16 func_0204dd84(void);

void func_0204dd98(TextWin *win);

static inline void TextWin_SetOrigin(u16 x, u16 y) {
    GfxMgr *gfx = data_02097ce0;
    gfx->unk_00c = x;
    gfx->unk_00e = y;
}

void func_0204dda8(TextWin *win);

static inline void TextWin_RenderOutline(TextWin *win) {
    win->unk_3c++;
    win->Render();
    win->unk_3c--;
    win->unk_3c--;
    win->Render();
    win->unk_3c++;
    win->unk_40++;
    win->Render();
    win->unk_40--;
    win->unk_40--;
    win->Render();
    win->unk_40++;
}

void func_0204de78(TextWin *win);

static inline BOOL TextWin_IsFlag31(TextWin *win) {
    return win->flag31 ? TRUE : FALSE;
}

BOOL func_0204e218(TextWin *win);

extern void *func_0203dd9c(u32 size);
extern void *func_02035d5c(char *name);
extern void *func_02034d88(void *a, void *b);
extern s32 FX_Div(s32 a, s32 b);
extern const s16 FX_SinCosTable_[];
extern const char *data_0208cb84;
extern const char *data_0208cc8c;
extern const char *data_0208cb74;
extern const char *data_0208cca0;

static inline Model *Model_Init(Model *model, const char *name, const char *file, int a) {
    func_02041218(model->pltt);
    func_02041440(model, file, a);
    STD_CopyString(model->name, name);
    return model;
}

}

struct TextModel : Model {
    TextModel(const char *name, const char *file, int a) {
        func_02041218(pltt);
        func_02041440(this, file, a);
        STD_CopyString(this->name, name);
    }
    static void *operator new(unsigned long size) {
        return func_0203dd9c(size);
    }
};

extern "C" {

static inline s16 TextWin_SinIdx(s32 angle) {
    return FX_SinCosTable_[(angle >> 4) * 2];
}

static inline s32 TextWin_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void Model_SetPos(Model *model, s32 x, s32 y) {
    model->x = x;
    model->y = y;
}

void func_0204dff8(TextWin *win);

Model *func_0204e238(Model *model, const char *name, const char *file, int a);

void *func_0204e278(void *pltt);

char *func_0204e28c(Model *model);

void *func_0204e294(Model *model);

void func_0204e29c(Model *model);

s16 func_0204e2ac(s32 angle);

s32 func_0204e2c4(s32 a, s32 b);

void func_0204e2dc(Model *model, s32 v);

void func_0204e2e4(Model *model, s32 idx);

extern void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
extern void *func_0203972c(void *blocks, u32 count);
extern s32 func_0204f804(TextWinEx *win);
extern s32 data_02097d78[];

u8 *func_0204f354(void);

void func_0204f368(int light, int polyMode, int cullMode, int polygonId, int alpha, int misc);

void func_0204f3a0(int texFmt, int texGen, int s, int t, int repeat, int flip, int pltt0, u32 addr);

void func_0204f3ec(void);

void func_0204f404(s32 x, s32 y, s32 z);

void func_0204f430(s32 x, s32 y, s32 z);

void func_0204f45c(u32 color);

void func_0204f478(s32 num, ...);

void func_0204f49c(TextWinEx *win);

static inline void TextWin_ClearVram(VramBlock *b) {
    MIi_CpuClearFast(0, (u8 *)(b->kind == 4 ? 0x6400000 : 0x6600000) + b->addr, b->size - b->pad);
}

static inline void TextWinEx_FreeBlocks(TextWinEx *win) {
    int i = 0;
    win->numBlocks = i;
    for (; i < 0x80; i++) {
        if (win->blocks[i] != NULL) {
            TextWin_ClearVram(win->blocks[i]);
            func_02039828(win->blocks[i]);
            win->blocks[i] = NULL;
            win->blockIds[i] = 0;
        }
    }
}

void func_0204f524(TextWinEx *win);

BOOL func_0204f5bc(TextWinEx *win);

void func_0204f784(TextWinEx *win);

BOOL func_0204ffb0(int idx);

TextLayout *func_0205070c(TextLayout *layout);

void func_0205073c(TextWin *win, s32 x, s32 y);

static inline void TextBoxLine_Init(TextBoxLine *line) {
    line->unk_00 = 0;
    line->unk_80 = 0;
    line->obj = NULL;
    line->unk_88 = 0;
    line->unk_8c = 0;
    line->unk_90 = 0;
    line->unk_94 = 0;
    line->unk_98 = 0;
}

void func_02050748(TextBox *box);

void func_020507d8(TextBox *box);

void func_020508e4(TextWin *win);

void func_02050e94(Model *model);

void func_02050ea4(Model *model, u32 v);

}

}  // namespace m_TextWin

// ---- TextWinScan
namespace m_TextWinScan {

// Base of the text layout helper; its vtable stays in asm.
struct TextLayout {
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void Clear();
};

extern "C" {

extern const u32 data_0208ba70[];

typedef s32 (*TextScanCharFn)(const char **s);

// Stack copy of a TextWin used only for tag parsing.
typedef struct TextScanParser {
    /* 0x00 */ const u32 *vt;
    /* 0x04 */ u8 unk_04[0x7c];
    /* 0x80 */ s32 code;
    /* 0x84 */ s32 value;
    /* 0x88 */ u8 unk_88[0x30];
} TextScanParser;

void *func_0203a4c0(GfxMgr *mgr);
void func_0204c7d0(TextWin *win);
void func_0204cc18(TextScanParser *p, const char **s);

void func_0204c6bc(const char *str, s32 maxLines, void *arg, void (*cb)(void *arg, s32 *tag)) {
    const char *s;
    TextScanParser p;
    s32 n;
    TextScanCharFn fn;
    s32 c;
    data_02097ce0->unk_004 = 3;
    fn = *(TextScanCharFn *)((u8 *)func_0203a4c0(data_02097ce0) + 4);
    s = str;
    n = 0;
    p.vt = data_0208ba70;
    func_0204c7d0((TextWin *)&p);
    while (*s != 0) {
        while ((c = fn(&s)) != 0) {
            if (c != '\n') {
                if (c == '\\') {
                    fn(&s);
                } else if (c == '<') {
                    func_0204cc18(&p, &s);
                    cb(arg, &p.code);
                }
                if (*s == 0) {
                    if (++n >= maxLines) {
                        break;
                    }
                    s++;
                }
            }
        }
    }
    p.vt = data_0208ba70;
    ((TextLayout *)&p)->Clear();
}

}

}  // namespace m_TextWinScan

// ---- TextWin_2
namespace m_TextWin_2 {

// Base of the text layout helper; its vtable stays in asm.
struct TextLayout {
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void Clear();
};

extern "C" {

extern const u32 data_0208ba70[];
extern void (*NNS_GfdDefaultFuncFreeTexVram)(void *p);
extern void (*NNS_GfdDefaultFuncFreePlttVram)(void *p);

extern void *func_0203de84(u32 size, u32 align);
extern void func_0203df0c(void *ptr);
extern void func_0203de1c(void *ptr);
extern void func_0203e58c(void *ptr);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void func_02039828(VramBlock *block);
extern VramBlock *func_020397fc(u32 size, u32 arg, u32 c);
extern s32 func_02040778(const char *s, int *len);
extern void func_0205bef8(void *cmd);

TextLayout *func_0204c4d4(TextLayout *layout);

void func_0204c7d0(TextWin *win) {
    *(u32 *)((u8 *)win + 4) = 0;
    win->unk_4_13 = 1;
    win->lines = NULL;
    win->unk_0c = NULL;
    win->unk_10 = 0;
    win->model = NULL;
    win->unk_18 = 0;
    win->unk_1a = 0;
    win->unk_1c = 0;
    win->unk_1e = 0;
    win->vram = NULL;
    win->unk_24 = 0;
    win->unk_28 = 3;
    win->unk_2c = 0;
    win->unk_30 = 5;
    win->unk_38 = 0;
    win->unk_34 = 1;
    win->unk_36 = 0;
    win->unk_37 = 0;
    win->unk_3c = 0;
    win->unk_40 = 0;
    win->vramSize = 0;
    win->vramArg = 0;
    win->unk_4c = 0;
    win->unk_50 = NULL;
    win->unk_54 = NULL;
    win->unk_58 = 0;
    win->unk_5c = 0;
    win->unk_60 = -1;
    win->unk_64 = -1;
    win->unk_68 = NULL;
    win->unk_6c = NULL;
    win->unk_70 = 0;
    win->unk_74 = 0x7fff;
    win->unk_76 = 0x7fff;
    win->unk_78 = 0;
    win->unk_7c = 0;
    win->code = -1;
    win->value = 0;
    win->args[0] = 0;
    win->args[1] = 0;
    win->args[2] = 0;
    win->args[3] = 0;
    win->text[0] = 0;
}

void func_0204c8a8(TextWin *win) {
    void *saved;
    if (win->lines != NULL) {
        if (win->lines->buf != NULL) {
            func_0203df0c(win->lines->buf);
            win->lines->buf = NULL;
        }
        if (win->lines != NULL) {
            func_0203df0c(win->lines);
            win->lines = NULL;
        }
    }
    if (win->unk_0c != NULL) {
        func_0203df0c(win->unk_0c);
        win->unk_0c = NULL;
    }
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    {
        Model *p = win->model;
        if (p != NULL) {
            if (p != NULL) {
                func_02041558(p);
                func_02041278(p->pltt);
                func_0203de1c(p);
            }
            win->model = NULL;
        }
    }
    data_02097dd0->cur = saved;
    if (win->vram != NULL) {
        VramBlock *b = win->vram;
        MIi_CpuClearFast(0, (u8 *)(b->kind == 4 ? 0x6400000 : 0x6600000) + b->addr, b->size - b->pad);
        func_02039828(win->vram);
    }
    if (win->unk_50 != NULL) {
        NNS_GfdDefaultFuncFreeTexVram(win->unk_50);
    }
    if (win->unk_54 != NULL) {
        NNS_GfdDefaultFuncFreePlttVram(win->unk_54);
    }
    if (win->unk_68 != NULL) {
        func_0203df0c(win->unk_68);
        win->unk_68 = NULL;
    }
    func_0203e58c(win->unk_6c);
    func_0204c7d0(win);
}

Model *func_0204c9f8(Model *model) {
    func_02041558(model);
    func_02041278(model->pltt);
    return model;
}

void func_0204ca14(TextWin *win, u32 n) {
    win->lines = (TextLines *)func_0203de84(0x10, 4);
    win->lines->unk_0 = 0;
    win->lines->buf = func_0203de84(n * 8, 4);
    win->lines->capacity = n;
    win->lines->count = 0;
    win->lines->unk_c = 3;
}

void func_0204ca70(TextWin *win) {
    u32 saved;
    data_02097ce0->unk_004 = win->unk_28;
    saved = win->rendering;
    win->rendering = 1;
    if (win->noVram) {
        win->inRender = 1;
        win->Render();
        win->inRender = 0;
    } else {
        win->vram = func_020397fc(win->vramSize, win->vramArg, 0);
        win->vram->unk_10_29 = 0;
        win->Render();
        win->vram->unk_10_29 = 1;
    }
    win->rendering = saved;
}

typedef struct TextCmd {
    /* 0x0 */ u32 unk_0;
    /* 0x4 */ u16 flags;
    /* 0x6 */ u16 id;
    /* 0x8 */ u16 args[6];
} TextCmd;

void func_0204cb28(TextWin *win, u32 arg) {
    TextCmd cmd;
    u16 n;
    u16 i;
    n = (win->value & 0xff00) >> 8;
    cmd.unk_0 = 0;
    cmd.id = win->value;
    for (i = 0; i < n; i++) {
        cmd.args[i] = win->args[i];
    }
    switch (cmd.id) {
    case 0x237:
        if (cmd.args[0] == 0) {
            u32 v = arg + 5;
            cmd.args[1] = v >> 16;
            cmd.args[2] = v;
        }
        break;
    case 0x13e:
    case 0x172:
    case 0x371:
        win->flag27 = 1;
        cmd.flags |= 0x100;
        break;
    }
    func_0205bef8(&cmd);
}

char *func_0204cef4(TextWin *win, char *p);

char *func_0204cf18(TextWin *win, char *p);

char *func_0204cf6c(TextWin *win, char *p);

char *func_0204cfa0(TextWin *win, char *p);

char *func_0204d014(TextWin *win, char *p);


// Compares a tag name up to its closing '>'. Returns 0 on a match.
static inline int TextWin_TagCmp(char c, const char *s, const char *tag) {
    if (c != '>') {
        do {
            if (*s++ != *tag++) {
                return 1;
            }
        } while (*s != '>');
    }
    return 0;
}

char *func_0204d040(TextWin *win, char *p);

char *func_0204d238(TextWin *win, char *p);

char *func_0204d380(TextWin *win, char *p);

char *func_0204d4b0(TextWin *win, char *p);

char *func_0204d54c(TextWin *win, char *p);

char *func_0204d57c(TextWin *win, char *p);

char *func_0204d7e0(TextWin *win, char *p);

char *func_0204d82c(TextWin *win, char *p);

char *func_0204d870(TextWin *win, char *p);

char *func_0204d8c0(TextWin *win, char *p);

char *func_0204d8f8(TextWin *win, char *p);

char *func_0204d930(TextWin *win, char *p);

char *func_0204d9f0(TextWin *win, char *p);

char *func_0204da2c(TextWin *win, char *p);

char *func_0204da68(TextWin *win, char *p);

char *func_0204da78(TextWin *win, char *p);

extern SndQueue *data_02097e48;
extern SndMgr *data_02097e4c;
extern void func_0204aab0(SndQueue *queue, u16 value);
extern void func_0204a284(SndMgr *mgr, s32 fade);

static inline void SndQueue_RequestBgm(SndQueue *queue, u16 bgm) {
    if (!queue->flag0) {
        return;
    }
    if (queue->unk_06 == 0xffff && queue->unk_04 == bgm) {
        return;
    }
    if (queue->unk_02 != 10 && queue->unk_02 != 0) {
        if (queue->unk_06 != 0xffff) {
            func_0204aab0(queue, queue->unk_06);
        }
        queue->unk_02 = 1;
    } else {
        queue->unk_02 = 0;
    }
    queue->unk_06 = bgm;
    queue->unk_08 = 10;
}

static inline void SndQueue_StopBgm(SndQueue *queue, u16 fade) {
    if (queue->flag3) {
        queue->unk_06 = 0x8000;
        queue->unk_08 = fade;
        queue->unk_02 = 0;
    }
}

void func_0204daf4(TextWin *win);

void func_0204dbc8(TextWin *win);

void func_0204dc04(TextWin *win);

extern SndHandle *func_02049a48(SndMgr *mgr, s32 id, s32 volume, s32 targetVolume, s32 frames);
extern void func_02049de8(SndMgr *mgr, s32 id);

void func_0204dc84(TextWin *win);

typedef struct PadState {
    /* 0x00 */ u8 unk_00[0x12];
    /* 0x12 */ u16 trig;
} PadState;

extern PadState *data_02097dc8;

BOOL func_0204dccc(TextWin *win);

u16 func_0204dd84(void);

void func_0204dd98(TextWin *win);

static inline void TextWin_SetOrigin(u16 x, u16 y) {
    GfxMgr *gfx = data_02097ce0;
    gfx->unk_00c = x;
    gfx->unk_00e = y;
}

void func_0204dda8(TextWin *win);

static inline void TextWin_RenderOutline(TextWin *win) {
    win->unk_3c++;
    win->Render();
    win->unk_3c--;
    win->unk_3c--;
    win->Render();
    win->unk_3c++;
    win->unk_40++;
    win->Render();
    win->unk_40--;
    win->unk_40--;
    win->Render();
    win->unk_40++;
}

void func_0204de78(TextWin *win);

static inline BOOL TextWin_IsFlag31(TextWin *win) {
    return win->flag31 ? TRUE : FALSE;
}

BOOL func_0204e218(TextWin *win);

extern void *func_0203dd9c(u32 size);
extern void *func_02035d5c(char *name);
extern void *func_02034d88(void *a, void *b);
extern s32 FX_Div(s32 a, s32 b);
extern const s16 FX_SinCosTable_[];
extern const char *data_0208cb84;
extern const char *data_0208cc8c;
extern const char *data_0208cb74;
extern const char *data_0208cca0;

static inline Model *Model_Init(Model *model, const char *name, const char *file, int a) {
    func_02041218(model->pltt);
    func_02041440(model, file, a);
    STD_CopyString(model->name, name);
    return model;
}

}

struct TextModel : Model {
    TextModel(const char *name, const char *file, int a) {
        func_02041218(pltt);
        func_02041440(this, file, a);
        STD_CopyString(this->name, name);
    }
    static void *operator new(unsigned long size) {
        return func_0203dd9c(size);
    }
};

extern "C" {

static inline s16 TextWin_SinIdx(s32 angle) {
    return FX_SinCosTable_[(angle >> 4) * 2];
}

static inline s32 TextWin_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void Model_SetPos(Model *model, s32 x, s32 y) {
    model->x = x;
    model->y = y;
}

static inline void Model_ApplyPart(Model *model, s32 idx) {
    ModelRes *res = model->res;
    ModelPart *part;
    void *tex;
    if (res == NULL) {
        return;
    }
    part = idx >= model->numParts ? NULL : &model->parts[idx];
    if (part != NULL && part->res != NULL) {
        tex = part->res->tex;
    } else {
        tex = NNS_G2dGetCellDataByIdx(res->texRes, ***(u16 ***)((u8 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx) + 0xc));
    }
    func_02042628(model, tex, part, 0);
}

void func_0204dff8(TextWin *win);

Model *func_0204e238(Model *model, const char *name, const char *file, int a);

void *func_0204e278(void *pltt);

char *func_0204e28c(Model *model);

void *func_0204e294(Model *model);

void func_0204e29c(Model *model);

s16 func_0204e2ac(s32 angle);

s32 func_0204e2c4(s32 a, s32 b);

void func_0204e2dc(Model *model, s32 v);

void func_0204e2e4(Model *model, s32 idx);

extern void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
extern void *func_0203972c(void *blocks, u32 count);
extern s32 func_0204f804(TextWinEx *win);
extern s32 data_02097d78[];

u8 *func_0204f354(void);

void func_0204f368(int light, int polyMode, int cullMode, int polygonId, int alpha, int misc);

void func_0204f3a0(int texFmt, int texGen, int s, int t, int repeat, int flip, int pltt0, u32 addr);

void func_0204f3ec(void);

void func_0204f404(s32 x, s32 y, s32 z);

void func_0204f430(s32 x, s32 y, s32 z);

void func_0204f45c(u32 color);

void func_0204f478(s32 num, ...);

void func_0204f49c(TextWinEx *win);

static inline void TextWin_ClearVram(VramBlock *b) {
    MIi_CpuClearFast(0, (u8 *)(b->kind == 4 ? 0x6400000 : 0x6600000) + b->addr, b->size - b->pad);
}

static inline void TextWinEx_FreeBlocks(TextWinEx *win) {
    int i = 0;
    win->numBlocks = i;
    for (; i < 0x80; i++) {
        if (win->blocks[i] != NULL) {
            TextWin_ClearVram(win->blocks[i]);
            func_02039828(win->blocks[i]);
            win->blocks[i] = NULL;
            win->blockIds[i] = 0;
        }
    }
}

void func_0204f524(TextWinEx *win);

BOOL func_0204f5bc(TextWinEx *win);

void func_0204f784(TextWinEx *win);

BOOL func_0204ffb0(int idx);

TextLayout *func_0205070c(TextLayout *layout);

void func_0205073c(TextWin *win, s32 x, s32 y);

static inline void TextBoxLine_Init(TextBoxLine *line) {
    line->unk_00 = 0;
    line->unk_80 = 0;
    line->obj = NULL;
    line->unk_88 = 0;
    line->unk_8c = 0;
    line->unk_90 = 0;
    line->unk_94 = 0;
    line->unk_98 = 0;
}

void func_02050748(TextBox *box);

void func_020507d8(TextBox *box);

void func_020508e4(TextWin *win);

void func_02050e94(Model *model);

void func_02050ea4(Model *model, u32 v);

BOOL func_0204cc18(TextWin *win, char **pp) {
    char *p = *pp;
    win->code = -1;
    switch (*p) {
    case 'p':
        if (p[1] == 's') {
            *pp = win->unk_vf28(p + 2);
        } else {
            *pp = win->unk_vf24(p + 2);
        }
        return TRUE;
    case 'd':
        *pp = win->unk_vf2c(p + 1);
        return TRUE;
    case 'q':
        *pp = win->unk_vf30(p + 1);
        return TRUE;
    case 'r':
        *pp = win->unk_vf34(p + 1);
        return TRUE;
    case 'f':
        *pp = win->unk_vf38(p + 1);
        return TRUE;
    case 'm':
        *pp = win->unk_vf3c(p + 1);
        return TRUE;
    case 'c':
        *pp = win->unk_vf40(p + 1);
        return TRUE;
    case 'a':
        *pp = win->unk_vf44(p + 1);
        return TRUE;
    case 'w':
        *pp = win->unk_vf48(p + 1);
        return TRUE;
    case 'e':
        *pp = win->unk_vf50(p + 1);
        return TRUE;
    case 'h':
        *pp = win->unk_vf54(p + 1);
        return TRUE;
    case 'b':
        *pp = win->unk_vf58(p + 1);
        return TRUE;
    case 'v':
        *pp = win->unk_vf5c(p + 1);
        return TRUE;
    case 'i':
        *pp = win->unk_vf60(p + 1);
        return TRUE;
    case 's':
        *pp = win->unk_vf64(p + 1);
        return TRUE;
    case 'o':
        *pp = win->unk_vf68(p + 1);
        return TRUE;
    case 't':
        *pp = win->unk_vf6c(p + 1);
        return TRUE;
    case 'k':
        *pp = win->unk_vf70(p + 1);
        return TRUE;
    case 'n':
        *pp = win->unk_vf74(p + 1);
        return TRUE;
    case 'z':
        *pp = win->unk_vf78(p + 1);
        return TRUE;
    }
    return FALSE;
}

}

}  // namespace m_TextWin_2

// ---- TextWin_3
namespace m_TextWin_3 {

// Base of the text layout helper; its vtable stays in asm.
struct TextLayout {
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void Clear();
};

extern "C" {

extern const u32 data_0208ba70[];
extern void (*NNS_GfdDefaultFuncFreeTexVram)(void *p);
extern void (*NNS_GfdDefaultFuncFreePlttVram)(void *p);

extern void *func_0203de84(u32 size, u32 align);
extern void func_0203df0c(void *ptr);
extern void func_0203de1c(void *ptr);
extern void func_0203e58c(void *ptr);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void func_02039828(VramBlock *block);
extern VramBlock *func_020397fc(u32 size, u32 arg, u32 c);
extern s32 func_02040778(const char *s, int *len);
extern void func_0205bef8(void *cmd);

TextLayout *func_0204c4d4(TextLayout *layout);

void func_0204c7d0(TextWin *win);

void func_0204c8a8(TextWin *win);

Model *func_0204c9f8(Model *model);

void func_0204ca14(TextWin *win, u32 n);

void func_0204ca70(TextWin *win);

typedef struct TextCmd {
    /* 0x0 */ u32 unk_0;
    /* 0x4 */ u16 flags;
    /* 0x6 */ u16 id;
    /* 0x8 */ u16 args[6];
} TextCmd;

void func_0204cb28(TextWin *win, u32 arg);

char *func_0204cef4(TextWin *win, char *p) {
    win->code = 0x11;
    win->value = *p == 'c' ? -1 : *p - '0';
    return p + 2;
}

char *func_0204cf18(TextWin *win, char *p) {
    int len;
    if (*p == 'e') {
        return win->ParseEscape(p + 1);
    }
    win->code = 0x12;
    win->value = func_02040778(p, &len);
    return p + len + 1;
}

char *func_0204cf6c(TextWin *win, char *p) {
    int len;
    win->code = 0x13;
    win->value = func_02040778(p, &len);
    return p + len + 1;
}

char *func_0204cfa0(TextWin *win, char *p) {
    int len;
    int i;
    p++;
    win->code = 0x14;
    win->value = func_02040778(p, &len);
    i = 0;
    p += len;
    while (*p == ',') {
        win->args[i] = func_02040778(p + 1, &len);
        i++;
        p += len + 1;
    }
    return p + 1;
}

char *func_0204d014(TextWin *win, char *p) {
    win->code = 0x15;
    win->value = 0;
    if (*p == 'n') {
        win->value = 1;
        p++;
    }
    return p + 1;
}


// Compares a tag name up to its closing '>'. Returns 0 on a match.
static inline int TextWin_TagCmp(char c, const char *s, const char *tag) {
    if (c != '>') {
        do {
            if (*s++ != *tag++) {
                return 1;
            }
        } while (*s != '>');
    }
    return 0;
}

char *func_0204d040(TextWin *win, char *p) {
    s32 color;
    char c = *p;
    if (c >= '0' && c <= '9') {
        color = c - '0';
        p++;
    } else if (c >= 'a' && c <= 'f') {
        color = c - 'a';
        p++;
    } else if (TextWin_TagCmp(c, p, "WHITE") == 0) {
        p += 5;
        color = 0;
    } else if (TextWin_TagCmp(c, p, "BLACK") == 0) {
        p += 5;
        color = 5;
    } else if (TextWin_TagCmp(c, p, "RED") == 0) {
        p += 3;
        color = 1;
    } else if (TextWin_TagCmp(c, p, "YELLOW") == 0) {
        p += 6;
        color = 4;
    } else if (TextWin_TagCmp(c, p, "GREEN") == 0) {
        p += 5;
        color = 2;
    } else if (TextWin_TagCmp(c, p, "BLUE") == 0) {
        p += 4;
        color = 3;
    }
    win->code = 0x10;
    win->value = color;
    return p + 1;
}

char *func_0204d238(TextWin *win, char *p) {
    s32 a;
    if (*p == 's') {
        win->code = 3;
    } else if (*p == 'r') {
        win->code = 4;
        if (p[1] == 't') {
            win->value = 4;
            p++;
            a = 0;
            if (p[1] == 'c') {
                p++;
                a = 1;
            } else if (p[1] == 'r') {
                p++;
                a = 2;
            } else if (p[1] == 'g') {
                p++;
                a = 3;
            }
            win->args[1] = a;
        } else {
            win->value = 2;
        }
        win->args[0] = 0;
    } else if (*p == 'R') {
        win->code = 4;
        win->value = 2;
        win->args[0] = 1;
    } else if (*p == 'l') {
        win->code = 4;
        if (p[1] == 't') {
            win->value = 3;
            p++;
            a = 0;
            if (p[1] == 'c') {
                p++;
                a = 1;
            } else if (p[1] == 'r') {
                p++;
                a = 2;
            } else if (p[1] == 'g') {
                p++;
                a = 3;
            }
            win->args[1] = a;
        } else {
            win->value = 1;
        }
        win->args[0] = 0;
    } else if (*p == 'L') {
        win->code = 4;
        win->value = 1;
        win->args[0] = 1;
    } else if (*p == 'c') {
        win->code = 4;
        win->value = 0;
        win->args[0] = 0;
    } else {
        win->code = 2;
        win->value = *p - '0';
    }
    return p + 2;
}

char *func_0204d380(TextWin *win, char *p) {
    int len;
    s32 v;
    if (*p == 'd') {
        v = func_02040778(p + 1, &len) & 0xff;
        win->value = v;
        if (v >= 20) {
            win->code = 0xc;
        } else if (v >= 10) {
            win->code = 0xb;
        } else {
            win->code = 8;
        }
        p++;
    } else if (*p == 'f') {
        v = func_02040778(p + 1, &len) & 0xff;
        win->value = v;
        if (v >= 20) {
            win->code = 0xc;
        } else if (v >= 10) {
            win->code = 0xb;
        } else {
            win->code = 9;
        }
        p++;
    } else if (*p == 'b') {
        v = func_02040778(p + 1, &len) & 0xff;
        win->value = v;
        if (v >= 20) {
            win->code = 0xc;
        } else if (v >= 10) {
            win->code = 0xb;
        } else {
            win->code = 0xa;
        }
        p++;
    } else {
        s32 hi;
        v = func_02040778(p, &len);
        hi = (v >> 8) & 0xff;
        win->args[0] = v & 0xff;
        win->value = hi;
        if (hi >= 20) {
            win->code = 7;
        } else if (hi >= 10) {
            win->code = 6;
        } else {
            win->code = 5;
        }
    }
    return p + len + 1;
}

char *func_0204d4b0(TextWin *win, char *p) {
    int len;
    win->code = 0xd;
    if (*p == 'd') {
        win->value = func_02040778(p + 1, &len);
        p += len;
    } else if (*p == 'l') {
        if (p[1] == 't') {
            win->value = 3;
            p++;
        } else {
            win->value = 1;
        }
    } else if (*p == 'c') {
        win->value = 0;
    } else if (*p == 'r') {
        if (p[1] == 't') {
            win->value = 4;
            p++;
        } else {
            win->value = 2;
        }
    }
    return p + 2;
}

char *func_0204d54c(TextWin *win, char *p) {
    win->code = 0xe;
    if (*p == 'H') {
        win->value = 0;
    } else if (*p == 'V') {
        win->value = 1;
    }
    return p + 2;
}

char *func_0204d57c(TextWin *win, char *p) {
    win->code = 0xf;
    if (*p == 'r') {
        win->value = 1;
    } else if (*p == 'l') {
        win->value = 2;
    } else if (*p == 'f') {
        win->value = 3;
    }
    return p + 2;
}

static inline char *TextWin_FindComma(char *p) {
    while (*p != '>') {
        if (*p == ',') {
            return p;
        }
        p++;
    }
    return NULL;
}

static inline int TextWin_CopyParen(const char *s, char *dst) {
    int j = 0;
    dst[0] = 0;
    if (s[j + 1] != '(') {
        return j;
    }
    j++;
    while (s[j + 1] != ')') {
        dst[0] = s[j++ + 1];
        dst++;
    }
    dst[0] = 0;
    return j + 1;
}

char *func_0204d5bc(TextWin *win, char *p) {
    char buf[0x10];
    char *q;
    long i;
    char c;
    win->code = 0;
    win->value = func_02040778(p, NULL);
    win->args[0] = 0;
    win->args[1] = 0;
    win->args[2] = 1;
    p += 4;
    q = TextWin_FindComma(p);
    while (q != NULL) {
        c = q[1];
        if (c == 'n') {
            win->args[0] = -1;
            p += 2;
        } else if (c == 'f') {
            win->args[0] = func_02040778(q + 2, NULL);
            p += 4;
        } else if (c == 'o') {
            for (i = 2;; i++) {
                c = q[i];
                if (c == ',' || c == '>') {
                    break;
                }
                if (c == 'n') {
                    i += TextWin_CopyParen(q + i, win->text);
                    win->args[1] |= 1;
                } else if (c == 'i') {
                    win->args[1] |= 2;
                } else if (c == 't') {
                    i += TextWin_CopyParen(q + i, buf);
                    win->args[2] = (u16)(func_02040778(buf, NULL) + 1);
                    win->args[1] |= 4;
                }
            }
            p += i;
        }
        q = TextWin_FindComma(p);
    }
    return p + 1;
}

char *func_0204d7e0(TextWin *win, char *p);

char *func_0204d82c(TextWin *win, char *p);

char *func_0204d870(TextWin *win, char *p);

char *func_0204d8c0(TextWin *win, char *p);

char *func_0204d8f8(TextWin *win, char *p);

char *func_0204d930(TextWin *win, char *p);

char *func_0204d9f0(TextWin *win, char *p);

char *func_0204da2c(TextWin *win, char *p);

char *func_0204da68(TextWin *win, char *p);

char *func_0204da78(TextWin *win, char *p);

extern SndQueue *data_02097e48;
extern SndMgr *data_02097e4c;
extern void func_0204aab0(SndQueue *queue, u16 value);
extern void func_0204a284(SndMgr *mgr, s32 fade);

static inline void SndQueue_RequestBgm(SndQueue *queue, u16 bgm) {
    if (!queue->flag0) {
        return;
    }
    if (queue->unk_06 == 0xffff && queue->unk_04 == bgm) {
        return;
    }
    if (queue->unk_02 != 10 && queue->unk_02 != 0) {
        if (queue->unk_06 != 0xffff) {
            func_0204aab0(queue, queue->unk_06);
        }
        queue->unk_02 = 1;
    } else {
        queue->unk_02 = 0;
    }
    queue->unk_06 = bgm;
    queue->unk_08 = 10;
}

static inline void SndQueue_StopBgm(SndQueue *queue, u16 fade) {
    if (queue->flag3) {
        queue->unk_06 = 0x8000;
        queue->unk_08 = fade;
        queue->unk_02 = 0;
    }
}

void func_0204daf4(TextWin *win);

void func_0204dbc8(TextWin *win);

void func_0204dc04(TextWin *win);

extern SndHandle *func_02049a48(SndMgr *mgr, s32 id, s32 volume, s32 targetVolume, s32 frames);
extern void func_02049de8(SndMgr *mgr, s32 id);

void func_0204dc84(TextWin *win);

typedef struct PadState {
    /* 0x00 */ u8 unk_00[0x12];
    /* 0x12 */ u16 trig;
} PadState;

extern PadState *data_02097dc8;

BOOL func_0204dccc(TextWin *win);

u16 func_0204dd84(void);

void func_0204dd98(TextWin *win);

static inline void TextWin_SetOrigin(u16 x, u16 y) {
    GfxMgr *gfx = data_02097ce0;
    gfx->unk_00c = x;
    gfx->unk_00e = y;
}

void func_0204dda8(TextWin *win);

static inline void TextWin_RenderOutline(TextWin *win) {
    win->unk_3c++;
    win->Render();
    win->unk_3c--;
    win->unk_3c--;
    win->Render();
    win->unk_3c++;
    win->unk_40++;
    win->Render();
    win->unk_40--;
    win->unk_40--;
    win->Render();
    win->unk_40++;
}

void func_0204de78(TextWin *win);

static inline BOOL TextWin_IsFlag31(TextWin *win) {
    return win->flag31 ? TRUE : FALSE;
}

BOOL func_0204e218(TextWin *win);

extern void *func_0203dd9c(u32 size);
extern void *func_02035d5c(char *name);
extern void *func_02034d88(void *a, void *b);
extern s32 FX_Div(s32 a, s32 b);
extern const s16 FX_SinCosTable_[];
extern const char *data_0208cb84;
extern const char *data_0208cc8c;
extern const char *data_0208cb74;
extern const char *data_0208cca0;

static inline Model *Model_Init(Model *model, const char *name, const char *file, int a) {
    func_02041218(model->pltt);
    func_02041440(model, file, a);
    STD_CopyString(model->name, name);
    return model;
}

}

struct TextModel : Model {
    TextModel(const char *name, const char *file, int a) {
        func_02041218(pltt);
        func_02041440(this, file, a);
        STD_CopyString(this->name, name);
    }
    static void *operator new(unsigned long size) {
        return func_0203dd9c(size);
    }
};

extern "C" {

static inline s16 TextWin_SinIdx(s32 angle) {
    return FX_SinCosTable_[(angle >> 4) * 2];
}

static inline s32 TextWin_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void Model_SetPos(Model *model, s32 x, s32 y) {
    model->x = x;
    model->y = y;
}

static inline void Model_ApplyPart(Model *model, s32 idx) {
    ModelRes *res = model->res;
    ModelPart *part;
    void *tex;
    if (res == NULL) {
        return;
    }
    part = idx >= model->numParts ? NULL : &model->parts[idx];
    if (part != NULL && part->res != NULL) {
        tex = part->res->tex;
    } else {
        tex = NNS_G2dGetCellDataByIdx(res->texRes, ***(u16 ***)((u8 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx) + 0xc));
    }
    func_02042628(model, tex, part, 0);
}

void func_0204dff8(TextWin *win);

Model *func_0204e238(Model *model, const char *name, const char *file, int a);

void *func_0204e278(void *pltt);

char *func_0204e28c(Model *model);

void *func_0204e294(Model *model);

void func_0204e29c(Model *model);

s16 func_0204e2ac(s32 angle);

s32 func_0204e2c4(s32 a, s32 b);

void func_0204e2dc(Model *model, s32 v);

void func_0204e2e4(Model *model, s32 idx);

extern void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
extern void *func_0203972c(void *blocks, u32 count);
extern s32 func_0204f804(TextWinEx *win);
extern s32 data_02097d78[];

u8 *func_0204f354(void);

void func_0204f368(int light, int polyMode, int cullMode, int polygonId, int alpha, int misc);

void func_0204f3a0(int texFmt, int texGen, int s, int t, int repeat, int flip, int pltt0, u32 addr);

void func_0204f3ec(void);

void func_0204f404(s32 x, s32 y, s32 z);

void func_0204f430(s32 x, s32 y, s32 z);

void func_0204f45c(u32 color);

void func_0204f478(s32 num, ...);

void func_0204f49c(TextWinEx *win);

static inline void TextWin_ClearVram(VramBlock *b) {
    MIi_CpuClearFast(0, (u8 *)(b->kind == 4 ? 0x6400000 : 0x6600000) + b->addr, b->size - b->pad);
}

static inline void TextWinEx_FreeBlocks(TextWinEx *win) {
    int i = 0;
    win->numBlocks = i;
    for (; i < 0x80; i++) {
        if (win->blocks[i] != NULL) {
            TextWin_ClearVram(win->blocks[i]);
            func_02039828(win->blocks[i]);
            win->blocks[i] = NULL;
            win->blockIds[i] = 0;
        }
    }
}

void func_0204f524(TextWinEx *win);

BOOL func_0204f5bc(TextWinEx *win);

void func_0204f784(TextWinEx *win);

BOOL func_0204ffb0(int idx);

TextLayout *func_0205070c(TextLayout *layout);

void func_0205073c(TextWin *win, s32 x, s32 y);

static inline void TextBoxLine_Init(TextBoxLine *line) {
    line->unk_00 = 0;
    line->unk_80 = 0;
    line->obj = NULL;
    line->unk_88 = 0;
    line->unk_8c = 0;
    line->unk_90 = 0;
    line->unk_94 = 0;
    line->unk_98 = 0;
}

void func_02050748(TextBox *box);

void func_020507d8(TextBox *box);

void func_020508e4(TextWin *win);

void func_02050e94(Model *model);

void func_02050ea4(Model *model, u32 v);

}

}  // namespace m_TextWin_3

// ---- TextWin_4
namespace m_TextWin_4 {

// Base of the text layout helper; its vtable stays in asm.
struct TextLayout {
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void Clear();
};

extern "C" {

extern const u32 data_0208ba70[];
extern void (*NNS_GfdDefaultFuncFreeTexVram)(void *p);
extern void (*NNS_GfdDefaultFuncFreePlttVram)(void *p);

extern void *func_0203de84(u32 size, u32 align);
extern void func_0203df0c(void *ptr);
extern void func_0203de1c(void *ptr);
extern void func_0203e58c(void *ptr);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void func_02039828(VramBlock *block);
extern VramBlock *func_020397fc(u32 size, u32 arg, u32 c);
extern s32 func_02040778(const char *s, int *len);
extern void func_0205bef8(void *cmd);

TextLayout *func_0204c4d4(TextLayout *layout);

void func_0204c7d0(TextWin *win);

void func_0204c8a8(TextWin *win);

Model *func_0204c9f8(Model *model);

void func_0204ca14(TextWin *win, u32 n);

void func_0204ca70(TextWin *win);

typedef struct TextCmd {
    /* 0x0 */ u32 unk_0;
    /* 0x4 */ u16 flags;
    /* 0x6 */ u16 id;
    /* 0x8 */ u16 args[6];
} TextCmd;

void func_0204cb28(TextWin *win, u32 arg);

char *func_0204cef4(TextWin *win, char *p);

char *func_0204cf18(TextWin *win, char *p);

char *func_0204cf6c(TextWin *win, char *p);

char *func_0204cfa0(TextWin *win, char *p);

char *func_0204d014(TextWin *win, char *p);


// Compares a tag name up to its closing '>'. Returns 0 on a match.
static inline int TextWin_TagCmp(char c, const char *s, const char *tag) {
    if (c != '>') {
        do {
            if (*s++ != *tag++) {
                return 1;
            }
        } while (*s != '>');
    }
    return 0;
}

char *func_0204d040(TextWin *win, char *p);

char *func_0204d238(TextWin *win, char *p);

char *func_0204d380(TextWin *win, char *p);

char *func_0204d4b0(TextWin *win, char *p);

char *func_0204d54c(TextWin *win, char *p);

char *func_0204d57c(TextWin *win, char *p);

char *func_0204d7e0(TextWin *win, char *p) {
    int i = 0;
    win->code = 1;
    win->value = 0;
    while (*p != '>') {
        win->text[i++] = *p++;
    }
    win->text[i] = 0;
    return p + 1;
}

char *func_0204d82c(TextWin *win, char *p) {
    int len;
    if (*p == 'p') {
        win->code = 0x16;
    } else {
        win->code = 0x17;
    }
    win->value = func_02040778(p + 1, &len);
    p++;
    p += len;
    return p + 1;
}

char *func_0204d870(TextWin *win, char *p) {
    int len;
    s32 v;
    if (*p == 'p') {
        win->code = 0x18;
        win->value = func_02040778(p + 1, &len);
    } else {
        win->code = 0x19;
        win->value = 0;
    }
    p++;
    p += len;
    return p + 1;
}

char *func_0204d8c0(TextWin *win, char *p) {
    int len;
    win->code = 0x1a;
    win->value = func_02040778(p + 1, &len);
    p++;
    p += len;
    return p + 1;
}

char *func_0204d8f8(TextWin *win, char *p) {
    int len;
    win->code = 0x1c;
    win->value = func_02040778(p + 1, &len);
    p++;
    p += len;
    return p + 1;
}

char *func_0204d930(TextWin *win, char *p) {
    int len = 0;
    if (*p == 'e') {
        win->code = 0x1f;
        win->value = 0xfc;
        win->args[0] = func_02040778(p + 1, &len);
    } else if (*p == 'f') {
        win->code = 0x1f;
        win->value = 0xfd;
        win->args[0] = func_02040778(p + 1, &len);
    } else if (*p == 'a') {
        win->code = 0x20;
        win->value = 0xff;
        win->args[0] = func_02040778(p + 1, &len);
    } else if (*p == 'b') {
        win->code = 0x21;
        win->value = 0xfe;
        win->args[0] = func_02040778(p + 1, &len);
    } else {
        win->code = 0x1e;
        win->value = func_02040778(p, &len);
        win->args[0] = 0x1e;
    }
    p++;
    p += len;
    return p + 1;
}

char *func_0204d9f0(TextWin *win, char *p) {
    int len = 0;
    win->code = 0x22;
    win->value = func_02040778(p, &len);
    return p + len + 1;
}

char *func_0204da2c(TextWin *win, char *p) {
    int len = 0;
    win->code = 0x23;
    win->value = func_02040778(p, &len);
    return p + len + 1;
}

char *func_0204da68(TextWin *win, char *p) {
    win->code = 0x24;
    return p + 1;
}

char *func_0204da78(TextWin *win, char *p) {
    int len = 0;
    win->code = 0x25;
    if (*p == 'a') {
        win->value = 0;
    } else if (*p == 'b') {
        win->value = 1;
    } else if (*p == 'c') {
        win->value = 2;
    } else if (*p == 'd') {
        win->value = 3;
    }
    win->args[0] = func_02040778(p + 1, &len);
    p++;
    p += len;
    return p + 1;
}

extern SndQueue *data_02097e48;
extern SndMgr *data_02097e4c;
extern void func_0204aab0(SndQueue *queue, u16 value);
extern void func_0204a284(SndMgr *mgr, s32 fade);

static inline void SndQueue_RequestBgm(SndQueue *queue, u16 bgm) {
    if (!queue->flag0) {
        return;
    }
    if (queue->unk_06 == 0xffff && queue->unk_04 == bgm) {
        return;
    }
    if (queue->unk_02 != 10 && queue->unk_02 != 0) {
        if (queue->unk_06 != 0xffff) {
            func_0204aab0(queue, queue->unk_06);
        }
        queue->unk_02 = 1;
    } else {
        queue->unk_02 = 0;
    }
    queue->unk_06 = bgm;
    queue->unk_08 = 10;
}

static inline void SndQueue_StopBgm(SndQueue *queue, u16 fade) {
    if (queue->flag3) {
        queue->unk_06 = 0x8000;
        queue->unk_08 = fade;
        queue->unk_02 = 0;
    }
}

void func_0204daf4(TextWin *win) {
    if (win->code == 0x16) {
        SndQueue_RequestBgm(data_02097e48, win->value);
    } else {
        SndQueue_StopBgm(data_02097e48, win->value);
    }
}

void func_0204dbc8(TextWin *win) {
    if (win->code == 0x18) {
        func_0204a20c(data_02097e4c, win->value);
    } else {
        func_0204a284(data_02097e4c, -1);
    }
}

void func_0204dc04(TextWin *win) {
    if (win->code == 0x1a) {
        SndQueue *queue = data_02097e48;
        u16 se = win->value;
        if (queue->flag0 == 1 && queue->unk_74 == 0xffff && queue->unk_72 == se) {
            return;
        }
        queue->unk_74 = se;
        queue->unk_70 = 0;
    } else {
        SndQueue *queue = data_02097e48;
        queue->unk_74 = 0x8000;
        queue->unk_70 = 0;
    }
}

extern SndHandle *func_02049a48(SndMgr *mgr, s32 id, s32 volume, s32 targetVolume, s32 frames);
extern void func_02049de8(SndMgr *mgr, s32 id);

void func_0204dc84(TextWin *win) {
    if (win->code == 0x1c) {
        func_02049a48(data_02097e4c, win->value, -1, -1, -1);
    } else {
        func_02049de8(data_02097e4c, win->value);
    }
}

typedef struct PadState {
    /* 0x00 */ u8 unk_00[0x12];
    /* 0x12 */ u16 trig;
} PadState;

extern PadState *data_02097dc8;

BOOL func_0204dccc(TextWin *win) {
    if (win->flag3) {
        return FALSE;
    }
    if (win->flag26) {
        win->unk_18++;
        if (win->unk_18 >= 0x280) {
            win->unk_18 = 0x258;
        }
        if (win->unk_18 >= 10 && (data_02097dc8->trig & 1)) {
            func_02049a48(data_02097e4c, 0x24, 0x50, -1, -1);
            win->flag29 = 1;
            win->OnSkip();
        }
    }
    return TRUE;
}

u16 func_0204dd84(void) {
    return data_02097dc8->trig;
}

void func_0204dd98(TextWin *win) {
    win->flag3 = 1;
}

static inline void TextWin_SetOrigin(u16 x, u16 y) {
    GfxMgr *gfx = data_02097ce0;
    gfx->unk_00c = x;
    gfx->unk_00e = y;
}

void func_0204dda8(TextWin *win) {
    if (!win->rendering) {
        return;
    }
    if (!win->flag3 && win->flag26) {
        if (!win->flag28) {
            win->unk_1a = win->unk_3c + win->vramSize + 8;
            win->unk_1c = win->unk_40 + 0xc;
        }
        win->unk_vf98();
    }
    data_02097ce0->unk_004 = win->unk_28;
    data_02097ce0->unk_012 = win->unk_34;
    TextWin_SetOrigin(win->unk_3c, win->unk_40);
    if (win->noVram) {
        win->unk_vfa0();
    } else {
        win->unk_vf9c();
    }
}

static inline void TextWin_RenderOutline(TextWin *win) {
    win->unk_3c++;
    win->Render();
    win->unk_3c--;
    win->unk_3c--;
    win->Render();
    win->unk_3c++;
    win->unk_40++;
    win->Render();
    win->unk_40--;
    win->unk_40--;
    win->Render();
    win->unk_40++;
}

void func_0204de78(TextWin *win) {
    if (win->noVram) {
        u16 color0 = win->unk_74;
        u16 color1 = win->unk_76;
        s32 base = win->unk_70;
        win->unk_76 = 0;
        win->unk_74 = 0;
        if (!win->noShadowShift) {
            win->unk_70 -= 0x20;
        }
        TextWin_RenderOutline(win);
        win->unk_74 = color0;
        win->unk_76 = color1;
        win->unk_70 = base;
    } else {
        s32 pltt = win->unk_2c;
        win->unk_2c = pltt + 0x10;
        TextWin_RenderOutline(win);
        win->unk_2c = pltt;
    }
}

static inline BOOL TextWin_IsFlag31(TextWin *win) {
    return win->flag31 ? TRUE : FALSE;
}

BOOL func_0204e218(TextWin *win);

extern void *func_0203dd9c(u32 size);
extern void *func_02035d5c(char *name);
extern void *func_02034d88(void *a, void *b);
extern s32 FX_Div(s32 a, s32 b);
extern const s16 FX_SinCosTable_[];
extern const char *data_0208cb84;
extern const char *data_0208cc8c;
extern const char *data_0208cb74;
extern const char *data_0208cca0;

static inline Model *Model_Init(Model *model, const char *name, const char *file, int a) {
    func_02041218(model->pltt);
    func_02041440(model, file, a);
    STD_CopyString(model->name, name);
    return model;
}

}

struct TextModel : Model {
    TextModel(const char *name, const char *file, int a) {
        func_02041218(pltt);
        func_02041440(this, file, a);
        STD_CopyString(this->name, name);
    }
    static void *operator new(unsigned long size) {
        return func_0203dd9c(size);
    }
};

extern "C" {

static inline s16 TextWin_SinIdx(s32 angle) {
    return FX_SinCosTable_[(angle >> 4) * 2];
}

static inline s32 TextWin_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void Model_SetPos(Model *model, s32 x, s32 y) {
    model->x = x;
    model->y = y;
}

static inline void Model_ApplyPart(Model *model, s32 idx) {
    ModelRes *res = model->res;
    ModelPart *part;
    void *tex;
    if (res == NULL) {
        return;
    }
    part = idx >= model->numParts ? NULL : &model->parts[idx];
    if (part != NULL && part->res != NULL) {
        tex = part->res->tex;
    } else {
        tex = NNS_G2dGetCellDataByIdx(res->texRes, ***(u16 ***)((u8 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx) + 0xc));
    }
    func_02042628(model, tex, part, 0);
}

void func_0204dff8(TextWin *win);

Model *func_0204e238(Model *model, const char *name, const char *file, int a);

void *func_0204e278(void *pltt);

char *func_0204e28c(Model *model);

void *func_0204e294(Model *model);

void func_0204e29c(Model *model);

s16 func_0204e2ac(s32 angle);

s32 func_0204e2c4(s32 a, s32 b);

void func_0204e2dc(Model *model, s32 v);

void func_0204e2e4(Model *model, s32 idx);

extern void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
extern void *func_0203972c(void *blocks, u32 count);
extern s32 func_0204f804(TextWinEx *win);
extern s32 data_02097d78[];

u8 *func_0204f354(void);

void func_0204f368(int light, int polyMode, int cullMode, int polygonId, int alpha, int misc);

void func_0204f3a0(int texFmt, int texGen, int s, int t, int repeat, int flip, int pltt0, u32 addr);

void func_0204f3ec(void);

void func_0204f404(s32 x, s32 y, s32 z);

void func_0204f430(s32 x, s32 y, s32 z);

void func_0204f45c(u32 color);

void func_0204f478(s32 num, ...);

void func_0204f49c(TextWinEx *win);

static inline void TextWin_ClearVram(VramBlock *b) {
    MIi_CpuClearFast(0, (u8 *)(b->kind == 4 ? 0x6400000 : 0x6600000) + b->addr, b->size - b->pad);
}

static inline void TextWinEx_FreeBlocks(TextWinEx *win) {
    int i = 0;
    win->numBlocks = i;
    for (; i < 0x80; i++) {
        if (win->blocks[i] != NULL) {
            TextWin_ClearVram(win->blocks[i]);
            func_02039828(win->blocks[i]);
            win->blocks[i] = NULL;
            win->blockIds[i] = 0;
        }
    }
}

void func_0204f524(TextWinEx *win);

BOOL func_0204f5bc(TextWinEx *win);

void func_0204f784(TextWinEx *win);

BOOL func_0204ffb0(int idx);

TextLayout *func_0205070c(TextLayout *layout);

void func_0205073c(TextWin *win, s32 x, s32 y);

static inline void TextBoxLine_Init(TextBoxLine *line) {
    line->unk_00 = 0;
    line->unk_80 = 0;
    line->obj = NULL;
    line->unk_88 = 0;
    line->unk_8c = 0;
    line->unk_90 = 0;
    line->unk_94 = 0;
    line->unk_98 = 0;
}

void func_02050748(TextBox *box);

void func_020507d8(TextBox *box);

void func_020508e4(TextWin *win);

void func_02050e94(Model *model);

void func_02050ea4(Model *model, u32 v);

}

extern "C" {

void func_0204dff8(TextWin *win) {
    s16 t = win->unk_18;
    s32 r;
    s16 s;
    if (win->model == NULL) {
        if (win->flag31 ? TRUE : FALSE) {
            Model *m = (Model *)func_0203dd9c(0x160);
            if (m != NULL) {
                Model_Init(m, data_0208cc8c, data_0208cb84, 0);
            }
            win->model = m;
        } else {
            Model *m = (Model *)func_0203dd9c(0x160);
            if (m != NULL) {
                Model_Init(m, data_0208cca0, data_0208cb74, 0);
            }
            win->model = m;
        }
        {
            void *res = func_02035d5c(win->model->name);
            func_020417e0(win->model, func_02034d88(res, win->model->unk_04c));
        }
        win->model->flags |= 2;
        func_02041d9c(win->model, 0, 4);
        return;
    }
    r = FX_Div(((u32)t % 40) << 12, 0x28000);
    if (r >= 0x1000) {
        r = 0x1000;
    }
    s = FX_SinCosTable_[((r << 14) >> 16) * 2];
    Model_SetPos(win->model, (win->unk_1a - 0x80) << 12, (win->unk_1c + (TextWin_FxMul(s, 0x6000) >> 12) - 0x60) << 12);
    win->model->unk_150 = win->unk_1e;
    Model_ApplyPart(win->model, 4);
}

}

}  // namespace m_TextWin_4

// ---- TextWin_5
namespace m_TextWin_5 {

// Base of the text layout helper; its vtable stays in asm.
struct TextLayout {
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void Clear();
};

extern "C" {

extern const u32 data_0208ba70[];
extern void (*NNS_GfdDefaultFuncFreeTexVram)(void *p);
extern void (*NNS_GfdDefaultFuncFreePlttVram)(void *p);

extern void *func_0203de84(u32 size, u32 align);
extern void func_0203df0c(void *ptr);
extern void func_0203de1c(void *ptr);
extern void func_0203e58c(void *ptr);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void func_02039828(VramBlock *block);
extern VramBlock *func_020397fc(u32 size, u32 arg, u32 c);
extern s32 func_02040778(const char *s, int *len);
extern void func_0205bef8(void *cmd);

TextLayout *func_0204c4d4(TextLayout *layout);

void func_0204c7d0(TextWin *win);

void func_0204c8a8(TextWin *win);

Model *func_0204c9f8(Model *model);

void func_0204ca14(TextWin *win, u32 n);

void func_0204ca70(TextWin *win);

typedef struct TextCmd {
    /* 0x0 */ u32 unk_0;
    /* 0x4 */ u16 flags;
    /* 0x6 */ u16 id;
    /* 0x8 */ u16 args[6];
} TextCmd;

void func_0204cb28(TextWin *win, u32 arg);

char *func_0204cef4(TextWin *win, char *p);

char *func_0204cf18(TextWin *win, char *p);

char *func_0204cf6c(TextWin *win, char *p);

char *func_0204cfa0(TextWin *win, char *p);

char *func_0204d014(TextWin *win, char *p);


// Compares a tag name up to its closing '>'. Returns 0 on a match.
static inline int TextWin_TagCmp(char c, const char *s, const char *tag) {
    if (c != '>') {
        do {
            if (*s++ != *tag++) {
                return 1;
            }
        } while (*s != '>');
    }
    return 0;
}

char *func_0204d040(TextWin *win, char *p);

char *func_0204d238(TextWin *win, char *p);

char *func_0204d380(TextWin *win, char *p);

char *func_0204d4b0(TextWin *win, char *p);

char *func_0204d54c(TextWin *win, char *p);

char *func_0204d57c(TextWin *win, char *p);

char *func_0204d7e0(TextWin *win, char *p);

char *func_0204d82c(TextWin *win, char *p);

char *func_0204d870(TextWin *win, char *p);

char *func_0204d8c0(TextWin *win, char *p);

char *func_0204d8f8(TextWin *win, char *p);

char *func_0204d930(TextWin *win, char *p);

char *func_0204d9f0(TextWin *win, char *p);

char *func_0204da2c(TextWin *win, char *p);

char *func_0204da68(TextWin *win, char *p);

char *func_0204da78(TextWin *win, char *p);

extern SndQueue *data_02097e48;
extern SndMgr *data_02097e4c;
extern void func_0204aab0(SndQueue *queue, u16 value);
extern void func_0204a284(SndMgr *mgr, s32 fade);

static inline void SndQueue_RequestBgm(SndQueue *queue, u16 bgm) {
    if (!queue->flag0) {
        return;
    }
    if (queue->unk_06 == 0xffff && queue->unk_04 == bgm) {
        return;
    }
    if (queue->unk_02 != 10 && queue->unk_02 != 0) {
        if (queue->unk_06 != 0xffff) {
            func_0204aab0(queue, queue->unk_06);
        }
        queue->unk_02 = 1;
    } else {
        queue->unk_02 = 0;
    }
    queue->unk_06 = bgm;
    queue->unk_08 = 10;
}

static inline void SndQueue_StopBgm(SndQueue *queue, u16 fade) {
    if (queue->flag3) {
        queue->unk_06 = 0x8000;
        queue->unk_08 = fade;
        queue->unk_02 = 0;
    }
}

void func_0204daf4(TextWin *win);

void func_0204dbc8(TextWin *win);

void func_0204dc04(TextWin *win);

extern SndHandle *func_02049a48(SndMgr *mgr, s32 id, s32 volume, s32 targetVolume, s32 frames);
extern void func_02049de8(SndMgr *mgr, s32 id);

void func_0204dc84(TextWin *win);

typedef struct PadState {
    /* 0x00 */ u8 unk_00[0x12];
    /* 0x12 */ u16 trig;
} PadState;

extern PadState *data_02097dc8;

BOOL func_0204dccc(TextWin *win);

u16 func_0204dd84(void);

void func_0204dd98(TextWin *win);

static inline void TextWin_SetOrigin(u16 x, u16 y) {
    GfxMgr *gfx = data_02097ce0;
    gfx->unk_00c = x;
    gfx->unk_00e = y;
}

void func_0204dda8(TextWin *win);

static inline void TextWin_RenderOutline(TextWin *win) {
    win->unk_3c++;
    win->Render();
    win->unk_3c--;
    win->unk_3c--;
    win->Render();
    win->unk_3c++;
    win->unk_40++;
    win->Render();
    win->unk_40--;
    win->unk_40--;
    win->Render();
    win->unk_40++;
}

void func_0204de78(TextWin *win);

static inline BOOL TextWin_IsFlag31(TextWin *win) {
    return win->flag31 ? TRUE : FALSE;
}

BOOL func_0204e218(TextWin *win) {
    return TextWin_IsFlag31(win) ? TRUE : FALSE;
}

extern void *func_0203dd9c(u32 size);
extern void *func_02035d5c(char *name);
extern void *func_02034d88(void *a, void *b);
extern s32 FX_Div(s32 a, s32 b);
extern const s16 FX_SinCosTable_[];
extern const char *data_0208cb84;
extern const char *data_0208cc8c;
extern const char *data_0208cb74;
extern const char *data_0208cca0;

static inline Model *Model_Init(Model *model, const char *name, const char *file, int a) {
    func_02041218(model->pltt);
    func_02041440(model, file, a);
    STD_CopyString(model->name, name);
    return model;
}

}

struct TextModel : Model {
    TextModel(const char *name, const char *file, int a) {
        func_02041218(pltt);
        func_02041440(this, file, a);
        STD_CopyString(this->name, name);
    }
    static void *operator new(unsigned long size) {
        return func_0203dd9c(size);
    }
};

extern "C" {

static inline s16 TextWin_SinIdx(s32 angle) {
    return FX_SinCosTable_[(angle >> 4) * 2];
}

static inline s32 TextWin_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void Model_SetPos(Model *model, s32 x, s32 y) {
    model->x = x;
    model->y = y;
}

static inline void Model_ApplyPart(Model *model, s32 idx) {
    ModelRes *res = model->res;
    ModelPart *part;
    void *tex;
    if (res == NULL) {
        return;
    }
    part = idx >= model->numParts ? NULL : &model->parts[idx];
    if (part != NULL && part->res != NULL) {
        tex = part->res->tex;
    } else {
        tex = NNS_G2dGetCellDataByIdx(res->texRes, ***(u16 ***)((u8 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx) + 0xc));
    }
    func_02042628(model, tex, part, 0);
}

void func_0204dff8(TextWin *win);

Model *func_0204e238(Model *model, const char *name, const char *file, int a) {
    func_02041218(model->pltt);
    func_02041440(model, file, a);
    STD_CopyString(model->name, name);
    return model;
}

void *func_0204e278(void *pltt) {
    func_02041218(pltt);
    return pltt;
}

char *func_0204e28c(Model *model) {
    return model->name;
}

void *func_0204e294(Model *model) {
    return model->unk_04c;
}

void func_0204e29c(Model *model) {
    model->flags |= 2;
}

s16 func_0204e2ac(s32 angle) {
    return FX_SinCosTable_[(angle >> 4) * 2];
}

s32 func_0204e2c4(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

void func_0204e2dc(Model *model, s32 v) {
    model->unk_150 = v;
}

void func_0204e2e4(Model *model, s32 idx) {
    Model_ApplyPart(model, idx);
}

extern void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
extern void *func_0203972c(void *blocks, u32 count);
extern s32 func_0204f804(TextWinEx *win);
extern s32 data_02097d78[];

u8 *func_0204f354(void);

void func_0204f368(int light, int polyMode, int cullMode, int polygonId, int alpha, int misc);

void func_0204f3a0(int texFmt, int texGen, int s, int t, int repeat, int flip, int pltt0, u32 addr);

void func_0204f3ec(void);

void func_0204f404(s32 x, s32 y, s32 z);

void func_0204f430(s32 x, s32 y, s32 z);

void func_0204f45c(u32 color);

void func_0204f478(s32 num, ...);

void func_0204f49c(TextWinEx *win);

static inline void TextWin_ClearVram(VramBlock *b) {
    MIi_CpuClearFast(0, (u8 *)(b->kind == 4 ? 0x6400000 : 0x6600000) + b->addr, b->size - b->pad);
}

static inline void TextWinEx_FreeBlocks(TextWinEx *win) {
    int i = 0;
    win->numBlocks = i;
    for (; i < 0x80; i++) {
        if (win->blocks[i] != NULL) {
            TextWin_ClearVram(win->blocks[i]);
            func_02039828(win->blocks[i]);
            win->blocks[i] = NULL;
            win->blockIds[i] = 0;
        }
    }
}

void func_0204f524(TextWinEx *win);

BOOL func_0204f5bc(TextWinEx *win);

void func_0204f784(TextWinEx *win);

BOOL func_0204ffb0(int idx);

TextLayout *func_0205070c(TextLayout *layout);

void func_0205073c(TextWin *win, s32 x, s32 y);

static inline void TextBoxLine_Init(TextBoxLine *line) {
    line->unk_00 = 0;
    line->unk_80 = 0;
    line->obj = NULL;
    line->unk_88 = 0;
    line->unk_8c = 0;
    line->unk_90 = 0;
    line->unk_94 = 0;
    line->unk_98 = 0;
}

void func_02050748(TextBox *box);

void func_020507d8(TextBox *box);

void func_020508e4(TextWin *win);

void func_02050e94(Model *model);

void func_02050ea4(Model *model, u32 v);

typedef u16 (*TextWinCharFn)(const char **s);

typedef struct TextWinFont {
    /* 0x0 */ s8 *info;
    /* 0x4 */ TextWinCharFn splitChar;
} TextWinFont;

extern GfxCell *func_0203a4a4(GfxMgr *mgr);
extern void *func_0203a4c0(GfxMgr *mgr);
extern void func_0203a4d4(GfxMgr *mgr, void *arg);
extern void func_0203a0cc(GfxMgr *mgr, VramBlock *block, GfxCell *cell, u32 size, u32 arg, s32 color);
extern void func_0204cc18(TextWin *win, const char **s);
extern int NNS_G2dCharCanvasDrawChar(const void *canvas, const void *font, int x, int y, int color, u16 c);

void func_0204e358(TextWin *win) {
    s32 color;
    const char *s;
    s32 hi;
    s32 x;
    TextWinCharFn fn;
    u16 c;
    s32 lineH;
    GfxCell *cell;
    TextWinFont *font;
    s32 y;
    cell = func_0203a4a4(data_02097ce0);
    hi = win->unk_2c >> 4;
    color = win->unk_2c % 16 + 1;
    if (win->vram == NULL) {
        win->vram = func_020397fc(win->vramSize, win->vramArg, 0);
    }
    win->vram->unk_10_31 = win->flag5;
    if (win->lines != NULL) {
        func_0203a4d4(data_02097ce0, win->lines);
    }
    func_0203a0cc(data_02097ce0, win->vram, cell, win->vramSize, win->vramArg, hi);
    if (!win->vram->temporary) {
        if (win->vram->temporary || win->vram->unk_10_2) {
            return;
        }
    }
    font = (TextWinFont *)func_0203a4c0(data_02097ce0);
    fn = font->splitChar;
    s = (const char *)win->unk_24;
    lineH = win->unk_38 + font->info[1];
    y = 0;
    while (*s != 0) {
        x = 0;
        while ((c = fn(&s)) != 0) {
            if (c == '\n') {
                color = win->unk_2c % 15 + 1;
                break;
            }
            if ((s8)win->unk_37 == 0) {
                if (c == '\\') {
                    c = fn(&s);
                } else if (c == '<') {
                    func_0204cc18(win, &s);
                    if (win->code == 0x10) {
                        color = win->value % 15 + 1;
                    }
                    continue;
                } else if ((s8)win->unk_36 == 0) {
                    if (c == 0x3001) {
                        c = ' ';
                    } else if (c == 0x3002) {
                        c = ' ';
                    }
                }
            }
            x += NNS_G2dCharCanvasDrawChar(cell, font, x, y, color, c);
            if (*s == 0) {
                break;
            }
        }
        y += lineH;
    }
    win->vram->unk_10_2 = 1;
}

extern void func_020430b8(int w, int h, u32 *ws, u32 *hs);
extern void DC_FlushRange(const void *start, u32 size);
extern u32 (*NNS_GfdDefaultFuncAllocTexVram)(u32 size, BOOL is4x4, u32 opt);
extern u32 (*NNS_GfdDefaultFuncAllocPlttVram)(u32 size, BOOL is4pltt, u32 opt);
extern void *func_0203e458(int type, void *src, u32 dst, u32 size, u32 chunk);
extern void *func_02039720(void);
extern void func_0204eb3c(TextWin *win);

void func_0204e5d4(TextWin *win) {
    u32 *dst;
    long outline;
    u32 size;
    s32 color;
    long pitch;

    u16 c;
    s32 end;
    const NNSG2dCharWidths *widths;
    u16 idx;
    s32 t;
    const char *s;
    s32 lineH;
    s32 bp;
    long w;

    s32 y;
    NNSG2dFontGlyph *glyph;
    s16 sh;
    s32 ch;
    long rowOff;
    s32 row;
    s32 bit;
    s32 bx;
    NNSG2dFont *font;
    NNSiG2dSplitCharCallback fn;
    s32 shadow;
    s32 px;

    if (win->flag24 == 1) {
        func_020430b8(win->vramSize + 2, win->vramArg + 2, &win->unk_58, &win->unk_5c);
        outline = TRUE;
    } else {
        func_020430b8(win->vramSize, win->vramArg, &win->unk_58, &win->unk_5c);
        outline = FALSE;
    }
    size = ((8 << win->unk_58) << win->unk_5c) << 2;
    win->unk_68 = func_0203de84(size, 4);
    bx = 0;
    MIi_CpuClearFast(0, win->unk_68, size);
    font = (NNSG2dFont *)func_0203a4c0(data_02097ce0);
    fn = font->cbCharSpliter;
    s = (const char *)win->unk_24;
    color = win->unk_2c % 15 + 1;
    shadow = (s32)win->unk_30 % 15 + 1;
    pitch = (8 << win->unk_58) >> 3;
    dst = (u32 *)win->unk_68;
    y = bx;
    lineH = win->unk_38 + font->pRes->pGlyph->cellHeight;
    while ((c = fn((const void **)&s)) != 0) {
        const u8 *src;
        if (c == '\n') {

            y += lineH;
            bx = 0;
            dst = (u32 *)win->unk_68 + pitch * (y + 1);
            continue;
        }
        if ((s8)win->unk_37 == 0) {
            if (c == '\\') {
                c = fn((const void **)&s);
            } else if (c == '<') {
                func_0204cc18(win, &s);
                if (win->code == 0x10) {
                    color = win->value % 15 + 1;
                }
                continue;
            } else if ((s8)win->unk_36 == 0) {
                if (c == 0x3001) {
                    c = ' ';
                } else if (c == 0x3002) {
                    c = ' ';
                }
            }
        }
        idx = NNS_G2dFontFindGlyphIndex(font, c);
        if (idx == 0xffff) {
            idx = font->pRes->alterCharIndex;
        }
        widths = NNS_G2dFontGetCharWidthsFromIndex(font, idx);
        glyph = font->pRes->pGlyph;
        src = glyph->glyphTable + idx * glyph->cellSize;
        bit = 0;
        end = widths->left + glyph->cellWidth;
        rowOff = pitch * (outline + 1);
        ch = glyph->cellHeight;
        row = 0;
        for (; row < ch; row++) {
            for (px = widths->left + outline; px < end + outline; px++) {
                if ((src[bit >> 3] >> (7 - (bit & 7))) & 1) {
                    w = rowOff + ((bx + px * 4) >> 5);
                    sh = (bx + px * 4) & 0x1f;
                    dst[w] &= ~(0xf << sh);
                    dst[w] |= color << sh;
                    if (outline) {
                        t = w - pitch;
                        if (((dst[t] >> sh) & 0xf) == 0) {
                            dst[t] |= shadow << sh;
                        }
                        dst[w + pitch] |= shadow << sh;
                        t = (bx + px * 4) - 4;
                        if ((((dst + rowOff)[t >> 5] >> (t & 0x1f)) & 0xf) == 0) {
                            (dst + rowOff)[t >> 5] |= shadow << (t & 0x1f);
                        }
                        t = (bx + px * 4) + 4;

                        (dst + rowOff)[t >> 5] |= shadow << (t & 0x1f);
                    }
                }
                bit++;
            }
            rowOff += pitch;
        }
        bp = bx + widths->charWidth * 4;
        bx = bp & 0x1f;
        dst += bp >> 5;
        if (*s == 0) {
            break;
        }
    }
    DC_FlushRange(win->unk_68, size);
    win->unk_50 = (void *)NNS_GfdDefaultFuncAllocTexVram(size, 0, 0);
    win->unk_54 = (void *)NNS_GfdDefaultFuncAllocPlttVram(0x40, 0, 0);
    OS_DisableIrq();
    func_0203e458(0, win->unk_68, ((u32)win->unk_50 & 0x1ffff) << 3, size, 0);
    win->unk_6c = func_0203e458(1, func_02039720(), ((u32)win->unk_54 & 0xffff) << 3, 0x40, 0);
    OS_EnableIrq();
    if (win->unk_4_30 == 1) {
        func_0204eb3c(win);
    }
}

}

}  // namespace m_TextWin_5

// ---- TextWin_13
namespace m_TextWin_13 {

extern "C" {
}

extern "C" {

extern s32 FX_Div(s32 a, s32 b);
extern void *func_0203de84(u32 size, u32 align);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void DC_FlushRange(const void *start, u32 size);

// Builds the display list that draws the window's glyph texture as a (gradient) quad.
void func_0204eb3c(TextWin *win) {
    u32 buf[0x40];
    GXDLInfo dl;
    s32 w = (8 << win->unk_58) << 12;
    s32 h = (8 << win->unk_5c) << 12;
    if (win->unk_60 != -1) {
        if (win->unk_60 < w) {
            w = win->unk_60;
        }
        if (w == 0) {
            return;
        }
    }
    if (win->unk_64 != -1) {
        if (win->unk_64 < h) {
            h = win->unk_64;
        }
        if (h == 0) {
            return;
        }
    }
    G3_BeginMakeDL(&dl, buf, sizeof(buf));
    G3B_Scale(&dl, w, h, 0x1000);
    if (win->unk_78 != 0) {
        fx16 y;
        s32 split = (s32)win->unk_78;
        y = FX_Div(split, h);
        G3B_Begin(&dl, GX_BEGIN_QUAD_STRIP);
        G3B_Color(&dl, win->unk_74);
        G3B_TexCoord(&dl, w, 0);
        G3B_Vtx(&dl, 0x1000, 0, 0);
        G3B_TexCoord(&dl, 0, 0);
        G3B_VtxXY(&dl, 0, 0);
        G3B_Color(&dl, win->unk_76);
        G3B_TexCoord(&dl, w, split);
        G3B_VtxXY(&dl, 0x1000, y);
        G3B_TexCoord(&dl, 0, split);
        G3B_VtxXY(&dl, 0, y);
        G3B_Color(&dl, win->unk_76);
        G3B_TexCoord(&dl, w, h);
        G3B_VtxXY(&dl, 0x1000, 0x1000);
        G3B_TexCoord(&dl, 0, h);
        G3B_VtxXY(&dl, 0, 0x1000);
    } else {
        G3B_Begin(&dl, GX_BEGIN_QUADS);
        G3B_Color(&dl, win->unk_74);
        G3B_TexCoord(&dl, w, 0);
        G3B_Vtx(&dl, 0x1000, 0, 0);
        G3B_TexCoord(&dl, 0, 0);
        G3B_VtxXY(&dl, 0, 0);
        G3B_Color(&dl, win->unk_76);
        G3B_TexCoord(&dl, 0, h);
        G3B_VtxXY(&dl, 0, 0x1000);
        G3B_TexCoord(&dl, w, h);
        G3B_VtxXY(&dl, 0x1000, 0x1000);
    }
    win->unk_10 = G3_EndMakeDL(&dl);
    win->unk_0c = func_0203de84(win->unk_10, 4);
    MI_CpuCopy8(buf, win->unk_0c, win->unk_10);
    DC_FlushRange(win->unk_0c, win->unk_10);
}

extern void func_0203df0c(void *ptr);
extern BOOL func_0203e63c(void *task);
extern void func_02043d20(void *p, int a);

extern void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
extern void NNS_G3dGeSendDL(const void *dl, u32 size);
extern void func_0204e5d4(TextWin *win);

static inline void TW_PolygonAttr(int light, int polyMode, int cullMode, int polygonId, int alpha, int misc) {
    u32 data = light | (polyMode << 4) | (cullMode << 6) | misc | (polygonId << 24) | (alpha << 16);
    NNS_G3dGeBufferOP_N(0x29, &data, 1);
}

static inline void TW_TexImageParam(int texFmt, int texGen, int s, int t, int repeat, int flip, int pltt0, u32 addr) {
    u32 data = (addr >> 3) | (texFmt << 26) | (texGen << 30) | (s << 20) | (t << 23) | (repeat << 16) | (flip << 18) | (pltt0 << 29);
    NNS_G3dGeBufferOP_N(0x2a, &data, 1);
}

static inline void TW_TexPlttBase(u32 addr) {
    u32 data = addr >> 4;
    NNS_G3dGeBufferOP_N(0x2b, &data, 1);
}

static inline u32 TW_PlttAddr(void *key) {
    return ((u32)key & 0xffff) << 3;
}

static inline void TW_PushMtx(void) {
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
}

static inline void TW_Translate(s32 x, s32 y, s32 z) {
    s32 data[3];
    data[0] = x;
    data[1] = y;
    data[2] = z;
    NNS_G3dGeBufferOP_N(0x1c, data, 3);
}

static inline void TW_Scale(s32 x, s32 y, s32 z) {
    s32 data[3];
    data[0] = x;
    data[1] = y;
    data[2] = z;
    NNS_G3dGeBufferOP_N(0x1b, data, 3);
}

static inline void TW_Begin(u32 prim) {
    u32 data = prim;
    NNS_G3dGeBufferOP_N(0x40, &data, 1);
}

static inline void TW_End(void) {
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
}

static inline void TW_Color(u32 color) {
    u32 data = color;
    NNS_G3dGeBufferOP_N(0x20, &data, 1);
}

static inline void TW_TexCoord(s32 s, s32 t) {
    u32 data = (u16)(s16)(s >> 8) | ((u16)(s16)(t >> 8) << 16);
    NNS_G3dGeBufferOP_N(0x22, &data, 1);
}

static inline void TW_Vtx(s16 x, s16 y, s16 z) {
    u32 data[2];
    data[0] = (u16)x | ((u16)y << 16);
    data[1] = (u16)z;
    NNS_G3dGeBufferOP_N(0x23, data, 2);
}

static inline void TW_VtxXY(s16 x, s16 y) {
    u32 data = (u16)x | ((u16)y << 16);
    NNS_G3dGeBufferOP_N(0x25, &data, 1);
}

static inline void TW_PopMtx(s32 num) {
    NNS_G3dGeBufferOP_N(0x12, &num, 1);
}

static inline BOOL TextWin_IsReady(TextWin *win) {
    if (win->unk_6c == NULL) {
        return TRUE;
    }
    if (func_0203e63c(win->unk_6c)) {
        win->unk_6c = NULL;
    } else {
        return win->noVram ? FALSE : TRUE;
    }
    return TRUE;
}
void func_0204edd8(TextWin *win) {
    s32 w;
    s32 h;
    if (win->unk_50 == NULL) {
        func_0204e5d4(win);
    }
    if (!TextWin_IsReady(win)) {
        return;
    }
    if (win->unk_68 != NULL) {
        func_0203df0c(win->unk_68);
        win->unk_68 = NULL;
    }
    if (win->inRender) {
        return;
    }
    func_02043d20(data_02097d48->unk_8b0, 0);
    {
        int misc = 0;
        int id = (u8)win->unk_4_13;
        int alpha = win->flag5 ? (u8)win->unk_4_8 : 0x1f;
        if (win->noShadowShift) {
            misc |= 0x4000;
        }
        if (win->flag22) {
            misc |= 0x800;
        }
        TW_PolygonAttr(0, 0, 3, id, alpha, misc);
    }
    {
    s32 pl = win->unk_2c >> 4;
    TW_TexImageParam(3, 1, win->unk_58, win->unk_5c, 0, 0, 1, ((u32)win->unk_50 & 0x1ffff) << 3);
    TW_TexPlttBase(TW_PlttAddr(win->unk_54) + pl * 0x20);
    }
    {
        s32 x = win->unk_3c << 12;
        s32 y = (win->unk_40 - 2) << 12;
        TW_PushMtx();
        TW_Translate(x, y, win->unk_70);
    }
    if (win->unk_0c != NULL) {
        NNS_G3dGeSendDL(win->unk_0c, win->unk_10);
    } else {
        w = (8 << win->unk_58) << 12;
        h = (8 << win->unk_5c) << 12;
        if (win->unk_60 != -1) {
            if (win->unk_60 < w) {
                w = win->unk_60;
            }
            if (w == 0) {
                return;
            }
        }
        if (win->unk_64 != -1) {
            if (win->unk_64 < h) {
                h = win->unk_64;
            }
            if (h == 0) {
                return;
            }
        }
        TW_Scale(w, h, 0x1000);
        if (win->unk_78 != 0) {
            s16 y;
            s32 split = (s32)win->unk_78;
            y = FX_Div(split, h);
            TW_Begin(3);
            TW_Color(win->unk_74);
            TW_TexCoord(w, 0);
            TW_Vtx(0x1000, 0, 0);
            TW_TexCoord(0, 0);
            TW_VtxXY(0, 0);
            TW_Color(win->unk_76);
            TW_TexCoord(w, split);
            TW_VtxXY(0x1000, y);
            TW_TexCoord(0, split);
            TW_VtxXY(0, y);
            TW_Color(win->unk_76);
            TW_TexCoord(w, h);
            TW_VtxXY(0x1000, 0x1000);
            TW_TexCoord(0, h);
            TW_VtxXY(0, 0x1000);
        } else {
            TW_Begin(1);
            TW_Color(win->unk_74);
            TW_TexCoord(w, 0);
            TW_Vtx(0x1000, 0, 0);
            TW_TexCoord(0, 0);
            TW_VtxXY(0, 0);
            TW_Color(win->unk_76);
            TW_TexCoord(0, h);
            TW_VtxXY(0, 0x1000);
            TW_TexCoord(w, h);
            TW_VtxXY(0x1000, 0x1000);
        }
        TW_End();
    }
    TW_PopMtx(1);
}

}

}  // namespace m_TextWin_13

// ---- TextWin_6
namespace m_TextWin_6 {

// Base of the text layout helper; its vtable stays in asm.
struct TextLayout {
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void Clear();
};

extern "C" {

extern const u32 data_0208ba70[];
extern void (*NNS_GfdDefaultFuncFreeTexVram)(void *p);
extern void (*NNS_GfdDefaultFuncFreePlttVram)(void *p);

extern void *func_0203de84(u32 size, u32 align);
extern void func_0203df0c(void *ptr);
extern void func_0203de1c(void *ptr);
extern void func_0203e58c(void *ptr);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void func_02039828(VramBlock *block);
extern VramBlock *func_020397fc(u32 size, u32 arg, u32 c);
extern s32 func_02040778(const char *s, int *len);
extern void func_0205bef8(void *cmd);

TextLayout *func_0204c4d4(TextLayout *layout);

void func_0204c7d0(TextWin *win);

void func_0204c8a8(TextWin *win);

Model *func_0204c9f8(Model *model);

void func_0204ca14(TextWin *win, u32 n);

void func_0204ca70(TextWin *win);

typedef struct TextCmd {
    /* 0x0 */ u32 unk_0;
    /* 0x4 */ u16 flags;
    /* 0x6 */ u16 id;
    /* 0x8 */ u16 args[6];
} TextCmd;

void func_0204cb28(TextWin *win, u32 arg);

char *func_0204cef4(TextWin *win, char *p);

char *func_0204cf18(TextWin *win, char *p);

char *func_0204cf6c(TextWin *win, char *p);

char *func_0204cfa0(TextWin *win, char *p);

char *func_0204d014(TextWin *win, char *p);


// Compares a tag name up to its closing '>'. Returns 0 on a match.
static inline int TextWin_TagCmp(char c, const char *s, const char *tag) {
    if (c != '>') {
        do {
            if (*s++ != *tag++) {
                return 1;
            }
        } while (*s != '>');
    }
    return 0;
}

char *func_0204d040(TextWin *win, char *p);

char *func_0204d238(TextWin *win, char *p);

char *func_0204d380(TextWin *win, char *p);

char *func_0204d4b0(TextWin *win, char *p);

char *func_0204d54c(TextWin *win, char *p);

char *func_0204d57c(TextWin *win, char *p);

char *func_0204d7e0(TextWin *win, char *p);

char *func_0204d82c(TextWin *win, char *p);

char *func_0204d870(TextWin *win, char *p);

char *func_0204d8c0(TextWin *win, char *p);

char *func_0204d8f8(TextWin *win, char *p);

char *func_0204d930(TextWin *win, char *p);

char *func_0204d9f0(TextWin *win, char *p);

char *func_0204da2c(TextWin *win, char *p);

char *func_0204da68(TextWin *win, char *p);

char *func_0204da78(TextWin *win, char *p);

extern SndQueue *data_02097e48;
extern SndMgr *data_02097e4c;
extern void func_0204aab0(SndQueue *queue, u16 value);
extern void func_0204a284(SndMgr *mgr, s32 fade);

static inline void SndQueue_RequestBgm(SndQueue *queue, u16 bgm) {
    if (!queue->flag0) {
        return;
    }
    if (queue->unk_06 == 0xffff && queue->unk_04 == bgm) {
        return;
    }
    if (queue->unk_02 != 10 && queue->unk_02 != 0) {
        if (queue->unk_06 != 0xffff) {
            func_0204aab0(queue, queue->unk_06);
        }
        queue->unk_02 = 1;
    } else {
        queue->unk_02 = 0;
    }
    queue->unk_06 = bgm;
    queue->unk_08 = 10;
}

static inline void SndQueue_StopBgm(SndQueue *queue, u16 fade) {
    if (queue->flag3) {
        queue->unk_06 = 0x8000;
        queue->unk_08 = fade;
        queue->unk_02 = 0;
    }
}

void func_0204daf4(TextWin *win);

void func_0204dbc8(TextWin *win);

void func_0204dc04(TextWin *win);

extern SndHandle *func_02049a48(SndMgr *mgr, s32 id, s32 volume, s32 targetVolume, s32 frames);
extern void func_02049de8(SndMgr *mgr, s32 id);

void func_0204dc84(TextWin *win);

typedef struct PadState {
    /* 0x00 */ u8 unk_00[0x12];
    /* 0x12 */ u16 trig;
} PadState;

extern PadState *data_02097dc8;

BOOL func_0204dccc(TextWin *win);

u16 func_0204dd84(void);

void func_0204dd98(TextWin *win);

static inline void TextWin_SetOrigin(u16 x, u16 y) {
    GfxMgr *gfx = data_02097ce0;
    gfx->unk_00c = x;
    gfx->unk_00e = y;
}

void func_0204dda8(TextWin *win);

static inline void TextWin_RenderOutline(TextWin *win) {
    win->unk_3c++;
    win->Render();
    win->unk_3c--;
    win->unk_3c--;
    win->Render();
    win->unk_3c++;
    win->unk_40++;
    win->Render();
    win->unk_40--;
    win->unk_40--;
    win->Render();
    win->unk_40++;
}

void func_0204de78(TextWin *win);

static inline BOOL TextWin_IsFlag31(TextWin *win) {
    return win->flag31 ? TRUE : FALSE;
}

BOOL func_0204e218(TextWin *win);

extern void *func_0203dd9c(u32 size);
extern void *func_02035d5c(char *name);
extern void *func_02034d88(void *a, void *b);
extern s32 FX_Div(s32 a, s32 b);
extern const s16 FX_SinCosTable_[];
extern const char *data_0208cb84;
extern const char *data_0208cc8c;
extern const char *data_0208cb74;
extern const char *data_0208cca0;

static inline Model *Model_Init(Model *model, const char *name, const char *file, int a) {
    func_02041218(model->pltt);
    func_02041440(model, file, a);
    STD_CopyString(model->name, name);
    return model;
}

}

struct TextModel : Model {
    TextModel(const char *name, const char *file, int a) {
        func_02041218(pltt);
        func_02041440(this, file, a);
        STD_CopyString(this->name, name);
    }
    static void *operator new(unsigned long size) {
        return func_0203dd9c(size);
    }
};

extern "C" {

static inline s16 TextWin_SinIdx(s32 angle) {
    return FX_SinCosTable_[(angle >> 4) * 2];
}

static inline s32 TextWin_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void Model_SetPos(Model *model, s32 x, s32 y) {
    model->x = x;
    model->y = y;
}

static inline void Model_ApplyPart(Model *model, s32 idx) {
    ModelRes *res = model->res;
    ModelPart *part;
    void *tex;
    if (res == NULL) {
        return;
    }
    part = idx >= model->numParts ? NULL : &model->parts[idx];
    if (part != NULL && part->res != NULL) {
        tex = part->res->tex;
    } else {
        tex = NNS_G2dGetCellDataByIdx(res->texRes, ***(u16 ***)((u8 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx) + 0xc));
    }
    func_02042628(model, tex, part, 0);
}

void func_0204dff8(TextWin *win);

Model *func_0204e238(Model *model, const char *name, const char *file, int a);

void *func_0204e278(void *pltt);

char *func_0204e28c(Model *model);

void *func_0204e294(Model *model);

void func_0204e29c(Model *model);

s16 func_0204e2ac(s32 angle);

s32 func_0204e2c4(s32 a, s32 b);

void func_0204e2dc(Model *model, s32 v);

void func_0204e2e4(Model *model, s32 idx);

extern void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
extern void *func_0203972c(void *blocks, u32 count);
extern s32 func_0204f804(TextWinEx *win);
extern s32 data_02097d78[];

u8 *func_0204f354(void) {
    return data_02097d48->unk_8b0;
}

void func_0204f368(int light, int polyMode, int cullMode, int polygonId, int alpha, int misc) {
    u32 data = light | (polyMode << 4) | (cullMode << 6) | misc | (polygonId << 24) | (alpha << 16);
    NNS_G3dGeBufferOP_N(0x29, &data, 1);
}

void func_0204f3a0(int texFmt, int texGen, int s, int t, int repeat, int flip, int pltt0, u32 addr) {
    u32 data = (addr >> 3) | (texFmt << 26) | (texGen << 30) | (s << 20) | (t << 23) | (repeat << 16) | (flip << 18) | (pltt0 << 29);
    NNS_G3dGeBufferOP_N(0x2a, &data, 1);
}

void func_0204f3ec(void) {
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
}

void func_0204f404(s32 x, s32 y, s32 z) {
    s32 data[3];
    data[0] = x;
    data[1] = y;
    data[2] = z;
    NNS_G3dGeBufferOP_N(0x1c, data, 3);
}

void func_0204f430(s32 x, s32 y, s32 z) {
    s32 data[3];
    data[0] = x;
    data[1] = y;
    data[2] = z;
    NNS_G3dGeBufferOP_N(0x1b, data, 3);
}

void func_0204f45c(u32 color) {
    u32 data = color;
    NNS_G3dGeBufferOP_N(0x20, &data, 1);
}

void func_0204f478(s32 num, ...) {
    NNS_G3dGeBufferOP_N(0x12, &num, 1);
}

void func_0204f49c(TextWinEx *win) {
    int i;
    win->unk_38 = 2;
    *(u32 *)((u8 *)win + 0xb8) = 0;
    win->blocksReady = 1;
    for (i = 0; i < 0x80; i++) {
        win->blocks[i] = NULL;
        win->blockIds[i] = 0;
    }
    win->originY = 0;
    win->numBlocks = 0;
    win->originX = win->originY;
    win->unk_1a = 0;
    win->unk_1c = 0;
    win->unk_1e = -0x200;
    win->unk_3c4 = 0;
    win->unk_3c8 = 1;
    win->unk_3cc = 0;
    win->page = 0;
    win->numPages = 0;
    win->unk_3d8 = 0;
}

static inline void TextWin_ClearVram(VramBlock *b) {
    MIi_CpuClearFast(0, (u8 *)(b->kind == 4 ? 0x6400000 : 0x6600000) + b->addr, b->size - b->pad);
}

static inline void TextWinEx_FreeBlocks(TextWinEx *win) {
    int i = 0;
    win->numBlocks = i;
    for (; i < 0x80; i++) {
        if (win->blocks[i] != NULL) {
            TextWin_ClearVram(win->blocks[i]);
            func_02039828(win->blocks[i]);
            win->blocks[i] = NULL;
            win->blockIds[i] = 0;
        }
    }
}

void func_0204f524(TextWinEx *win);

BOOL func_0204f5bc(TextWinEx *win);

void func_0204f784(TextWinEx *win);

BOOL func_0204ffb0(int idx);

TextLayout *func_0205070c(TextLayout *layout);

void func_0205073c(TextWin *win, s32 x, s32 y);

static inline void TextBoxLine_Init(TextBoxLine *line) {
    line->unk_00 = 0;
    line->unk_80 = 0;
    line->obj = NULL;
    line->unk_88 = 0;
    line->unk_8c = 0;
    line->unk_90 = 0;
    line->unk_94 = 0;
    line->unk_98 = 0;
}

void func_02050748(TextBox *box);

void func_020507d8(TextBox *box);

void func_020508e4(TextWin *win);

void func_02050e94(Model *model);

void func_02050ea4(Model *model, u32 v);

}

}  // namespace m_TextWin_6

// ---- TextWin_7
namespace m_TextWin_7 {

// Base of the text layout helper; its vtable stays in asm.
struct TextLayout {
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void Clear();
};

extern "C" {

extern const u32 data_0208ba70[];
extern void (*NNS_GfdDefaultFuncFreeTexVram)(void *p);
extern void (*NNS_GfdDefaultFuncFreePlttVram)(void *p);

extern void *func_0203de84(u32 size, u32 align);
extern void func_0203df0c(void *ptr);
extern void func_0203de1c(void *ptr);
extern void func_0203e58c(void *ptr);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void func_02039828(VramBlock *block);
extern VramBlock *func_020397fc(u32 size, u32 arg, u32 c);
extern s32 func_02040778(const char *s, int *len);
extern void func_0205bef8(void *cmd);

TextLayout *func_0204c4d4(TextLayout *layout);

void func_0204c7d0(TextWin *win);

void func_0204c8a8(TextWin *win);

Model *func_0204c9f8(Model *model);

void func_0204ca14(TextWin *win, u32 n);

void func_0204ca70(TextWin *win);

typedef struct TextCmd {
    /* 0x0 */ u32 unk_0;
    /* 0x4 */ u16 flags;
    /* 0x6 */ u16 id;
    /* 0x8 */ u16 args[6];
} TextCmd;

void func_0204cb28(TextWin *win, u32 arg);

char *func_0204cef4(TextWin *win, char *p);

char *func_0204cf18(TextWin *win, char *p);

char *func_0204cf6c(TextWin *win, char *p);

char *func_0204cfa0(TextWin *win, char *p);

char *func_0204d014(TextWin *win, char *p);


// Compares a tag name up to its closing '>'. Returns 0 on a match.
static inline int TextWin_TagCmp(char c, const char *s, const char *tag) {
    if (c != '>') {
        do {
            if (*s++ != *tag++) {
                return 1;
            }
        } while (*s != '>');
    }
    return 0;
}

char *func_0204d040(TextWin *win, char *p);

char *func_0204d238(TextWin *win, char *p);

char *func_0204d380(TextWin *win, char *p);

char *func_0204d4b0(TextWin *win, char *p);

char *func_0204d54c(TextWin *win, char *p);

char *func_0204d57c(TextWin *win, char *p);

char *func_0204d7e0(TextWin *win, char *p);

char *func_0204d82c(TextWin *win, char *p);

char *func_0204d870(TextWin *win, char *p);

char *func_0204d8c0(TextWin *win, char *p);

char *func_0204d8f8(TextWin *win, char *p);

char *func_0204d930(TextWin *win, char *p);

char *func_0204d9f0(TextWin *win, char *p);

char *func_0204da2c(TextWin *win, char *p);

char *func_0204da68(TextWin *win, char *p);

char *func_0204da78(TextWin *win, char *p);

extern SndQueue *data_02097e48;
extern SndMgr *data_02097e4c;
extern void func_0204aab0(SndQueue *queue, u16 value);
extern void func_0204a284(SndMgr *mgr, s32 fade);

static inline void SndQueue_RequestBgm(SndQueue *queue, u16 bgm) {
    if (!queue->flag0) {
        return;
    }
    if (queue->unk_06 == 0xffff && queue->unk_04 == bgm) {
        return;
    }
    if (queue->unk_02 != 10 && queue->unk_02 != 0) {
        if (queue->unk_06 != 0xffff) {
            func_0204aab0(queue, queue->unk_06);
        }
        queue->unk_02 = 1;
    } else {
        queue->unk_02 = 0;
    }
    queue->unk_06 = bgm;
    queue->unk_08 = 10;
}

static inline void SndQueue_StopBgm(SndQueue *queue, u16 fade) {
    if (queue->flag3) {
        queue->unk_06 = 0x8000;
        queue->unk_08 = fade;
        queue->unk_02 = 0;
    }
}

void func_0204daf4(TextWin *win);

void func_0204dbc8(TextWin *win);

void func_0204dc04(TextWin *win);

extern SndHandle *func_02049a48(SndMgr *mgr, s32 id, s32 volume, s32 targetVolume, s32 frames);
extern void func_02049de8(SndMgr *mgr, s32 id);

void func_0204dc84(TextWin *win);

typedef struct PadState {
    /* 0x00 */ u8 unk_00[0x12];
    /* 0x12 */ u16 trig;
} PadState;

extern PadState *data_02097dc8;

BOOL func_0204dccc(TextWin *win);

u16 func_0204dd84(void);

void func_0204dd98(TextWin *win);

static inline void TextWin_SetOrigin(u16 x, u16 y) {
    GfxMgr *gfx = data_02097ce0;
    gfx->unk_00c = x;
    gfx->unk_00e = y;
}

void func_0204dda8(TextWin *win);

static inline void TextWin_RenderOutline(TextWin *win) {
    win->unk_3c++;
    win->Render();
    win->unk_3c--;
    win->unk_3c--;
    win->Render();
    win->unk_3c++;
    win->unk_40++;
    win->Render();
    win->unk_40--;
    win->unk_40--;
    win->Render();
    win->unk_40++;
}

void func_0204de78(TextWin *win);

static inline BOOL TextWin_IsFlag31(TextWin *win) {
    return win->flag31 ? TRUE : FALSE;
}

BOOL func_0204e218(TextWin *win);

extern void *func_0203dd9c(u32 size);
extern void *func_02035d5c(char *name);
extern void *func_02034d88(void *a, void *b);
extern s32 FX_Div(s32 a, s32 b);
extern const s16 FX_SinCosTable_[];
extern const char *data_0208cb84;
extern const char *data_0208cc8c;
extern const char *data_0208cb74;
extern const char *data_0208cca0;

static inline Model *Model_Init(Model *model, const char *name, const char *file, int a) {
    func_02041218(model->pltt);
    func_02041440(model, file, a);
    STD_CopyString(model->name, name);
    return model;
}

}

struct TextModel : Model {
    TextModel(const char *name, const char *file, int a) {
        func_02041218(pltt);
        func_02041440(this, file, a);
        STD_CopyString(this->name, name);
    }
    static void *operator new(unsigned long size) {
        return func_0203dd9c(size);
    }
};

extern "C" {

static inline s16 TextWin_SinIdx(s32 angle) {
    return FX_SinCosTable_[(angle >> 4) * 2];
}

static inline s32 TextWin_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void Model_SetPos(Model *model, s32 x, s32 y) {
    model->x = x;
    model->y = y;
}

static inline void Model_ApplyPart(Model *model, s32 idx) {
    ModelRes *res = model->res;
    ModelPart *part;
    void *tex;
    if (res == NULL) {
        return;
    }
    part = idx >= model->numParts ? NULL : &model->parts[idx];
    if (part != NULL && part->res != NULL) {
        tex = part->res->tex;
    } else {
        tex = NNS_G2dGetCellDataByIdx(res->texRes, ***(u16 ***)((u8 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx) + 0xc));
    }
    func_02042628(model, tex, part, 0);
}

void func_0204dff8(TextWin *win);

Model *func_0204e238(Model *model, const char *name, const char *file, int a);

void *func_0204e278(void *pltt);

char *func_0204e28c(Model *model);

void *func_0204e294(Model *model);

void func_0204e29c(Model *model);

s16 func_0204e2ac(s32 angle);

s32 func_0204e2c4(s32 a, s32 b);

void func_0204e2dc(Model *model, s32 v);

void func_0204e2e4(Model *model, s32 idx);

extern void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
extern void *func_0203972c(void *blocks, u32 count);
extern s32 func_0204f804(TextWinEx *win);
extern s32 data_02097d78[];

u8 *func_0204f354(void);

void func_0204f368(int light, int polyMode, int cullMode, int polygonId, int alpha, int misc);

void func_0204f3a0(int texFmt, int texGen, int s, int t, int repeat, int flip, int pltt0, u32 addr);

void func_0204f3ec(void);

void func_0204f404(s32 x, s32 y, s32 z);

void func_0204f430(s32 x, s32 y, s32 z);

void func_0204f45c(u32 color);

void func_0204f478(s32 num, ...);

void func_0204f49c(TextWinEx *win);

// Clears a glyph block's VRAM, given the main and sub OBJ character bases.
static inline void TextWin_ClearVramAt(VramBlock *b, u8 *main, u8 *sub) {
    MIi_CpuClearFast(0, (b->kind == 4 ? main : sub) + b->addr, b->size - b->pad);
}

void func_0204f524(TextWinEx *win) {
    long i;
    u8 *main;
    u8 *sub;
    i = 0;
    win->numBlocks = i;
    main = (u8 *)G2_GetOBJCharPtr();
    sub = (u8 *)G2S_GetOBJCharPtr();
    for (; i < 0x80; i++) {
        if (win->blocks[i] != NULL) {
            TextWin_ClearVramAt(win->blocks[i], main, sub);
            func_02039828(win->blocks[i]);
            win->blocks[i] = NULL;
            win->blockIds[i] = 0;
        }
    }
    func_0204f49c(win);
}

BOOL func_0204f5bc(TextWinEx *win) {
    long i;
    u8 *main;
    u8 *sub;
    if (win->flag3) {
        return FALSE;
    }
    win->unk_3c4--;
    if (!win->flag0) {
        win->flag0 = 1;
        win->unk_3c = win->originX;
        win->unk_40 = win->originY;
    }
    if (win->flag25 && win->blocksReady) {
        win->unk_18++;
        if (win->unk_18 >= 0x280) {
            win->unk_18 = 0x258;
        }
        if (!win->flag26 || (data_02097dc8->trig & 1)) {
            if (win->flag26) {
                func_02049a48(data_02097e4c, 0x24, 0x50, -1, -1);
            }
            if (win->page >= win->numPages) {
                win->flag29 = 1;
                win->OnSkip();
            } else {
                i = 0;
                win->numBlocks = i;
                main = (u8 *)G2_GetOBJCharPtr();
                sub = (u8 *)G2S_GetOBJCharPtr();
                for (; i < 0x80; i++) {
                    if (win->blocks[i] != NULL) {
                        TextWin_ClearVramAt(win->blocks[i], main, sub);
                        func_02039828(win->blocks[i]);
                        win->blocks[i] = NULL;
                        win->blockIds[i] = 0;
                    }
                }
                win->unk_3c = win->originX;
                win->unk_40 = win->originY;
            }
            win->flag25 = 0;
        }
    }
    return TRUE;
}

void func_0204f784(TextWinEx *win) {
    s32 n;
    u16 count;
    if (!win->rendering) {
        return;
    }
    if (win->flag25 && win->flag26 && win->blocksReady) {
        win->unk_vf98();
    }
    n = func_0204f804(win);
    if (n == -1) {
        return;
    }
    count = win->numBlocks - n;
    if (count == 0) {
        return;
    }
    func_0203972c(win->blocks, count);
}

extern void *func_0203a4c0(GfxMgr *mgr);
extern void func_0203a4dc(GfxMgr *mgr, void *arg);
extern void func_0203a5a4(GfxMgr *mgr, u16 c);
BOOL func_0204cc18(TextWin *win, char **pp);

s32 func_0204f804(TextWinEx *win) {
    BOOL stop;
    s32 lineH;
    s16 n;
    char *saved;
    s32 color;
    NNSiG2dSplitCharCallback fn;
    s32 pad;
    u16 c;
    NNSG2dFont *font;
    data_02097ce0->unk_004 = win->unk_28;
    data_02097ce0->unk_012 = win->unk_34;
    n = 0;
    if (win->unk_3c4 >= 0) {
        return n;
    }
    win->unk_3c4 = win->unk_3c8;
    if (win->flag3 || win->flag25) {
        return 0;
    }
    if (*(char *)win->unk_3d8 != 0) {
        font = (NNSG2dFont *)func_0203a4c0(data_02097ce0);
        fn = font->cbCharSpliter;
        pad = 0;
        stop = FALSE;
        lineH = win->unk_38 + font->pRes->linefeed;
        color = win->unk_2c;
        saved = (char *)win->unk_3d8;
        while ((c = fn((const void **)&win->unk_3d8)) != 0) {
            if (c == '\n') {
                win->unk_3c = win->originX;
                win->unk_40 += lineH;
                saved = (char *)win->unk_3d8;
                continue;
            }
            if (c == '\\') {
                c = fn((const void **)&win->unk_3d8);
            } else if (c == '<') {
                func_0204cc18(win, (char **)&win->unk_3d8);
                switch (win->code) {
                case 0x14:
                    func_0204cb28(win, win->unk_3d8);
                    stop = TRUE;
                    break;
                case 0x11:
                    if (win->value == 0) {
                        win->unk_3c8 = 3;
                    } else if (win->value == 1) {
                        win->unk_3c8 = 1;
                    } else if (win->value == 2) {
                        win->unk_3c8 = 0;
                    } else if (win->value == 3) {
                        win->unk_3c8 = 7;
                    }
                    break;
                case 0x12:
                    win->unk_3c4 += win->value;
                    stop = TRUE;
                    break;
                case 0x10:
                    color = win->value;
                    win->unk_2c = color;
                    break;
                }
                saved = (char *)win->unk_3d8;
                if (!stop) {
                    continue;
                }
            } else if (c == 0x3001) {
                c = ' ';
                pad = 8;
            } else if (c == 0x3002) {
                c = ' ';
                pad = 0x10;
            } else if (c == ' ') {
                pad = -win->unk_3c8;
            }
            if (stop) {
                win->unk_3d8 = (s32)saved;
                break;
            }
            win->blockIds[win->numBlocks] = c;
            if (win->blocks[win->numBlocks] == NULL) {
                u16 idx = NNS_G2dFontFindGlyphIndex(font, c);
                const NNSG2dCharWidths *widths;
                NNSG2dFontGlyph *glyph;
                if (idx == 0xffff) {
                    idx = font->pRes->alterCharIndex;
                }
                widths = NNS_G2dFontGetCharWidthsFromIndex(font, idx);
                glyph = font->pRes->pGlyph;
                win->blocks[win->numBlocks] = func_020397fc(widths->left + glyph->cellWidth, glyph->cellHeight, 0);
            }
            func_0203a4dc(data_02097ce0, win->blocks[win->numBlocks]);
            TextWin_SetOrigin(win->unk_3c, win->unk_40);
            data_02097ce0->unk_008 = color;
            func_0203a5a4(data_02097ce0, c);
            n++;
            if (win->flag23 == 1 && (c < 0x80 || c > 0xaf)) {
                func_02049a48(data_02097e4c, 0x23, 0xe, -1, -1);
            }
            win->unk_3c = data_02097ce0->unk_00c;
            if (win->numBlocks + 1 < 0x80) {
                win->numBlocks++;
            }
            win->unk_3cc++;
            if (win->unk_3c8 != 0) {
                if (pad != 0) {
                    win->unk_3c4 = pad + win->unk_3c8;
                } else {
                    win->unk_3c4 = win->unk_3c8;
                }
            } else {
                win->unk_3c4 = 0;
            }
            break;
        }
    }
    if (*(char *)win->unk_3d8 == 0) {
        if (win->page >= win->numPages) {
            win->OnSkip();
        } else {
            if (!win->flag28) {
                win->unk_1a = win->unk_3c + 8;
                win->unk_1c = win->unk_40 + 0xc;
            }
            win->page++;
            win->unk_3d8++;
            win->flag25 = 1;
            win->unk_18 = 0;
        }
    }
    return n;
}

BOOL func_0204ffb0(int idx);

TextLayout *func_0205070c(TextLayout *layout);

void func_0205073c(TextWin *win, s32 x, s32 y);

static inline void TextBoxLine_Init(TextBoxLine *line) {
    line->unk_00 = 0;
    line->unk_80 = 0;
    line->obj = NULL;
    line->unk_88 = 0;
    line->unk_8c = 0;
    line->unk_90 = 0;
    line->unk_94 = 0;
    line->unk_98 = 0;
}

void func_02050748(TextBox *box);

void func_020507d8(TextBox *box);

void func_020508e4(TextWin *win);

void func_02050e94(Model *model);

void func_02050ea4(Model *model, u32 v);

}

}  // namespace m_TextWin_7

// ---- TextWinOam
namespace m_TextWinOam {

extern "C" {

typedef struct TextWinOam {
    /* 0x0 */ u32 y : 8;
    /* 0x0 */ u32 attr0 : 8;
    /* 0x0 */ u32 x : 9;
    /* 0x0 */ u32 attr1 : 7;
    /* 0x4 */ u32 charName : 10;
    /* 0x4 */ u32 attr2 : 22;
} TextWinOam;

TextWinOam *func_0204fc4c(TextWin *win, const u16 *cmd, TextWinOam *oam, u16 *count) {
    u16 n = *count;
    TextWinOam *last = &oam[n - 1];
    if (*cmd == 2) {
        u32 name = last->charName;
        s32 flags = win->unk_70;
        n = 1;
        if (flags & 1) {
            oam->charName = name;
        }
        if (flags & 2) {
            oam->charName = name - 1;
        }
        if (flags & 0x400) {
            oam->charName = name - 2;
        }
        if (flags & 0x800) {
            oam->charName = name - 3;
        }
        if (flags & 0x200) {
            oam->charName = name - 4;
        }
        if (flags & 0x100) {
            oam->charName = name - 5;
        }
        oam->x = 0;
        oam->y = 0;
    }
    *count = n;
    return oam;
}

}

}  // namespace m_TextWinOam

// ---- TextWin_8
namespace m_TextWin_8 {

// Base of the text layout helper; its vtable stays in asm.
struct TextLayout {
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void Clear();
};

extern "C" {

extern const u32 data_0208ba70[];
extern void (*NNS_GfdDefaultFuncFreeTexVram)(void *p);
extern void (*NNS_GfdDefaultFuncFreePlttVram)(void *p);

extern void *func_0203de84(u32 size, u32 align);
extern void func_0203df0c(void *ptr);
extern void func_0203de1c(void *ptr);
extern void func_0203e58c(void *ptr);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void func_02039828(VramBlock *block);
extern VramBlock *func_020397fc(u32 size, u32 arg, u32 c);
extern s32 func_02040778(const char *s, int *len);
extern void func_0205bef8(void *cmd);

TextLayout *func_0204c4d4(TextLayout *layout);

void func_0204c7d0(TextWin *win);

void func_0204c8a8(TextWin *win);

Model *func_0204c9f8(Model *model);

void func_0204ca14(TextWin *win, u32 n);

void func_0204ca70(TextWin *win);

typedef struct TextCmd {
    /* 0x0 */ u32 unk_0;
    /* 0x4 */ u16 flags;
    /* 0x6 */ u16 id;
    /* 0x8 */ u16 args[6];
} TextCmd;

void func_0204cb28(TextWin *win, u32 arg);

char *func_0204cef4(TextWin *win, char *p);

char *func_0204cf18(TextWin *win, char *p);

char *func_0204cf6c(TextWin *win, char *p);

char *func_0204cfa0(TextWin *win, char *p);

char *func_0204d014(TextWin *win, char *p);


// Compares a tag name up to its closing '>'. Returns 0 on a match.
static inline int TextWin_TagCmp(char c, const char *s, const char *tag) {
    if (c != '>') {
        do {
            if (*s++ != *tag++) {
                return 1;
            }
        } while (*s != '>');
    }
    return 0;
}

char *func_0204d040(TextWin *win, char *p);

char *func_0204d238(TextWin *win, char *p);

char *func_0204d380(TextWin *win, char *p);

char *func_0204d4b0(TextWin *win, char *p);

char *func_0204d54c(TextWin *win, char *p);

char *func_0204d57c(TextWin *win, char *p);

char *func_0204d7e0(TextWin *win, char *p);

char *func_0204d82c(TextWin *win, char *p);

char *func_0204d870(TextWin *win, char *p);

char *func_0204d8c0(TextWin *win, char *p);

char *func_0204d8f8(TextWin *win, char *p);

char *func_0204d930(TextWin *win, char *p);

char *func_0204d9f0(TextWin *win, char *p);

char *func_0204da2c(TextWin *win, char *p);

char *func_0204da68(TextWin *win, char *p);

char *func_0204da78(TextWin *win, char *p);

extern SndQueue *data_02097e48;
extern SndMgr *data_02097e4c;
extern void func_0204aab0(SndQueue *queue, u16 value);
extern void func_0204a284(SndMgr *mgr, s32 fade);

static inline void SndQueue_RequestBgm(SndQueue *queue, u16 bgm) {
    if (!queue->flag0) {
        return;
    }
    if (queue->unk_06 == 0xffff && queue->unk_04 == bgm) {
        return;
    }
    if (queue->unk_02 != 10 && queue->unk_02 != 0) {
        if (queue->unk_06 != 0xffff) {
            func_0204aab0(queue, queue->unk_06);
        }
        queue->unk_02 = 1;
    } else {
        queue->unk_02 = 0;
    }
    queue->unk_06 = bgm;
    queue->unk_08 = 10;
}

static inline void SndQueue_StopBgm(SndQueue *queue, u16 fade) {
    if (queue->flag3) {
        queue->unk_06 = 0x8000;
        queue->unk_08 = fade;
        queue->unk_02 = 0;
    }
}

void func_0204daf4(TextWin *win);

void func_0204dbc8(TextWin *win);

void func_0204dc04(TextWin *win);

extern SndHandle *func_02049a48(SndMgr *mgr, s32 id, s32 volume, s32 targetVolume, s32 frames);
extern void func_02049de8(SndMgr *mgr, s32 id);

void func_0204dc84(TextWin *win);

typedef struct PadState {
    /* 0x00 */ u8 unk_00[0x12];
    /* 0x12 */ u16 trig;
} PadState;

extern PadState *data_02097dc8;

BOOL func_0204dccc(TextWin *win);

u16 func_0204dd84(void);

void func_0204dd98(TextWin *win);

static inline void TextWin_SetOrigin(u16 x, u16 y) {
    GfxMgr *gfx = data_02097ce0;
    gfx->unk_00c = x;
    gfx->unk_00e = y;
}

void func_0204dda8(TextWin *win);

static inline void TextWin_RenderOutline(TextWin *win) {
    win->unk_3c++;
    win->Render();
    win->unk_3c--;
    win->unk_3c--;
    win->Render();
    win->unk_3c++;
    win->unk_40++;
    win->Render();
    win->unk_40--;
    win->unk_40--;
    win->Render();
    win->unk_40++;
}

void func_0204de78(TextWin *win);

static inline BOOL TextWin_IsFlag31(TextWin *win) {
    return win->flag31 ? TRUE : FALSE;
}

BOOL func_0204e218(TextWin *win);

extern void *func_0203dd9c(u32 size);
extern void *func_02035d5c(char *name);
extern void *func_02034d88(void *a, void *b);
extern s32 FX_Div(s32 a, s32 b);
extern const s16 FX_SinCosTable_[];
extern const char *data_0208cb84;
extern const char *data_0208cc8c;
extern const char *data_0208cb74;
extern const char *data_0208cca0;

static inline Model *Model_Init(Model *model, const char *name, const char *file, int a) {
    func_02041218(model->pltt);
    func_02041440(model, file, a);
    STD_CopyString(model->name, name);
    return model;
}

}

struct TextModel : Model {
    TextModel(const char *name, const char *file, int a) {
        func_02041218(pltt);
        func_02041440(this, file, a);
        STD_CopyString(this->name, name);
    }
    static void *operator new(unsigned long size) {
        return func_0203dd9c(size);
    }
};

extern "C" {

static inline s16 TextWin_SinIdx(s32 angle) {
    return FX_SinCosTable_[(angle >> 4) * 2];
}

static inline s32 TextWin_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void Model_SetPos(Model *model, s32 x, s32 y) {
    model->x = x;
    model->y = y;
}

static inline void Model_ApplyPart(Model *model, s32 idx) {
    ModelRes *res = model->res;
    ModelPart *part;
    void *tex;
    if (res == NULL) {
        return;
    }
    part = idx >= model->numParts ? NULL : &model->parts[idx];
    if (part != NULL && part->res != NULL) {
        tex = part->res->tex;
    } else {
        tex = NNS_G2dGetCellDataByIdx(res->texRes, ***(u16 ***)((u8 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx) + 0xc));
    }
    func_02042628(model, tex, part, 0);
}

void func_0204dff8(TextWin *win);

Model *func_0204e238(Model *model, const char *name, const char *file, int a);

void *func_0204e278(void *pltt);

char *func_0204e28c(Model *model);

void *func_0204e294(Model *model);

void func_0204e29c(Model *model);

s16 func_0204e2ac(s32 angle);

s32 func_0204e2c4(s32 a, s32 b);

void func_0204e2dc(Model *model, s32 v);

void func_0204e2e4(Model *model, s32 idx);

extern void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
extern void *func_0203972c(void *blocks, u32 count);
extern s32 func_0204f804(TextWinEx *win);
extern s32 data_02097d78[];

u8 *func_0204f354(void);

void func_0204f368(int light, int polyMode, int cullMode, int polygonId, int alpha, int misc);

void func_0204f3a0(int texFmt, int texGen, int s, int t, int repeat, int flip, int pltt0, u32 addr);

void func_0204f3ec(void);

void func_0204f404(s32 x, s32 y, s32 z);

void func_0204f430(s32 x, s32 y, s32 z);

void func_0204f45c(u32 color);

void func_0204f478(s32 num, ...);

void func_0204f49c(TextWinEx *win);

static inline void TextWin_ClearVram(VramBlock *b) {
    MIi_CpuClearFast(0, (u8 *)(b->kind == 4 ? 0x6400000 : 0x6600000) + b->addr, b->size - b->pad);
}

static inline void TextWinEx_FreeBlocks(TextWinEx *win) {
    int i = 0;
    win->numBlocks = i;
    for (; i < 0x80; i++) {
        if (win->blocks[i] != NULL) {
            TextWin_ClearVram(win->blocks[i]);
            func_02039828(win->blocks[i]);
            win->blocks[i] = NULL;
            win->blockIds[i] = 0;
        }
    }
}

void func_0204f524(TextWinEx *win);

BOOL func_0204f5bc(TextWinEx *win);

void func_0204f784(TextWinEx *win);

typedef struct TextWinTitle {
    /* 0x000 */ u16 started : 1;
    /* 0x000 */ u16 active : 1;
    /* 0x000 */ u16 flag2 : 1;
    /* 0x000 */ u16 waiting : 1;
    /* 0x000 */ u16 autoAdvance : 1;
    /* 0x000 */ u16 rising : 1;
    /* 0x000 */ u16 flag6 : 1;
    /* 0x000 */ u16 fading : 1;
    /* 0x000 */ u16 done : 1;
    /* 0x000 */ u16 failed : 1;
    /* 0x002 */ s8 timer;
    /* 0x004 */ s16 waitCount;
    /* 0x008 */ s32 offset;
    /* 0x00c */ u8 unk_0c[0xc];
    /* 0x018 */ s32 seq;
    /* 0x01c */ u8 unk_1c[8];
    /* 0x024 */ s32 value;
    /* 0x028 */ s32 required;
    /* 0x02c */ u8 unk_2c[0x1e0];
    /* 0x20c */ s32 phase;
} TextWinTitle;

typedef struct TextWinFieldDisp {
    /* 0x0 */ u8 unk_00[0xe];
    /* 0xe */ u8 unk_0e_0 : 2;
    /* 0xe */ u8 mode : 2;
} TextWinFieldDisp;

extern TextWinFieldDisp *data_ov000_021ccd54;
extern void func_0203c9e8(int value, int ch);
extern void func_0203cb78(int duration, int mode, int ch);
extern void func_0203cc58(int duration, int mode, int ch);
extern s32 func_0204a2c8(SndMgr *mgr, s32 seq);
extern void func_02049870(SndMgr *mgr, s32 seq);
extern void func_02049950(SndMgr *mgr, int volume, int frames);

static inline BOOL TextWin_IsState4(int idx) {
    if (data_02097d78[3] == 4) {
        return TRUE;
    }
    return data_02097d78[idx] == 4 ? TRUE : FALSE;
}

BOOL func_0204fd60(TextWinTitle *t) {
    if (!t->active) {
        return TRUE;
    }
    if (t->done) {
        return FALSE;
    }
    if (!t->started) {
        t->started = 1;
        t->timer = 0x78;
        func_0203cb78(0, 0, 0);
        data_ov000_021ccd54->mode = 2;
    }
    if (t->fading && TextWin_IsState4(0)) {
        t->fading = 0;
        t->done = 1;
        data_ov000_021ccd54->mode = 0;
        return FALSE;
    }
    t->timer--;
    if (t->rising) {
        t->offset += 0x1000;
    } else {
        t->offset -= 0x1000;
    }
    if (t->waiting == 1) {
        BOOL next = FALSE;
        if (t->autoAdvance == 1) {
            t->waitCount++;
            if (t->waitCount > 0x5a) {
                next = TRUE;
            }
        } else if (data_02097dc8->trig & 1) {
            next = TRUE;
        }
        if (next) {
            t->waitCount = 0;
            t->rising = 0;
            t->waiting = 0;
            if (t->value < t->required) {
                t->failed = 1;
            } else {
                t->fading = 1;
                func_0203c9e8(0x3f, -1);
                func_0203cc58(0x78000, 2, 0);
                if (t->seq != -1) {
                    s32 vol = func_0204a2c8(data_02097e4c, t->seq);
                    func_02049870(data_02097e4c, t->seq);
                    func_02049950(data_02097e4c, 0, 0);
                    func_02049950(data_02097e4c, vol, 0xf0);
                }
            }
        }
    }
    t->phase += 0x1000;
    if (t->phase >= 0x3c000) {
        t->phase -= 0x3c000;
    }
    return TRUE;
}

BOOL func_0204ffb0(int idx) {
    return TextWin_IsState4(idx);
}

TextLayout *func_0205070c(TextLayout *layout);

void func_0205073c(TextWin *win, s32 x, s32 y);

static inline void TextBoxLine_Init(TextBoxLine *line) {
    line->unk_00 = 0;
    line->unk_80 = 0;
    line->obj = NULL;
    line->unk_88 = 0;
    line->unk_8c = 0;
    line->unk_90 = 0;
    line->unk_94 = 0;
    line->unk_98 = 0;
}

void func_02050748(TextBox *box);

void func_020507d8(TextBox *box);

void func_020508e4(TextWin *win);

void func_02050e94(Model *model);

void func_02050ea4(Model *model, u32 v);

extern void func_02043d20(void *obj, int a);
extern void func_02043db4(int a, s32 b, s32 c, u16 d);
extern BOOL func_0203e63c(void *id);
extern u32 func_0204c4fc(u32 a, u32 b, u32 c, u32 *outSize, u32 *outArg, BOOL d);
void func_020508f4(TextBox *box, u32 arg);
void func_02050b50(TextBox *box);

#define OBJ_DELETE_LINE(l) { \
        void *saved_ = data_02097dd0->cur; \
        data_02097dd0->cur = data_02097dd0->unk_08; \
        { \
            TextBoxObj *p_ = (l)->obj; \
            if (p_ != NULL) { \
                if (p_ != NULL) { \
                    p_->DeletingDtor(); \
                } \
                (l)->obj = NULL; \
            } \
        } \
        data_02097dd0->cur = saved_; \
    }

static inline TextWin *TextBox_NewWin(void) {
    TextWin *win = (TextWin *)func_0203dd9c(0xb8);
    if (win != NULL) {
        *(const u32 **)win = data_0208ba70;
        func_0204c7d0(win);
    }
    return win;
}

static inline BOOL TextBox_IsFading(TextBox *box) {
    int i;
    for (i = 0; i < 3; i++) {
        if (box->lines[i].obj != NULL && box->lines[i].fadeIn == 1) {
            return TRUE;
        }
    }
    return FALSE;
}


static inline void NNSi_G3dGeTexImageParam(int texFmt, int texGen, int s, int t, int repeat, int flip, int pltt0, u32 addr) {
    u32 tmp;
    tmp = (u32)(((addr) >> 3) | ((texFmt) << 26) | ((texGen) << 30) | ((s) << 20) | ((t) << 23) | ((repeat) << 16) | ((flip) << 18) | ((pltt0) << 29));
    NNS_G3dGeBufferOP_N(0x2a, &tmp, 1);
}
static inline void NNSi_G3dGePolygonAttr(int light, int polyMode, int cullMode, int polygonID, int alpha, int misc) {
    u32 tmp;
    tmp = (u32)((light) | ((polyMode) << 4) | ((cullMode) << 6) | (misc) | ((polygonID) << 24) | ((alpha) << 16));
    NNS_G3dGeBufferOP_N(0x29, &tmp, 1);
}
static inline void G3i_Translate(s32 x, s32 y, s32 z) {
    *(vu32 *)0x4000470 = (u32)x;
    *(vu32 *)0x4000470 = (u32)y;
    *(vu32 *)0x4000470 = (u32)z;
}
void func_0204ffdc(TextBox *box) {
    TextBoxLine *ln;
    BOOL busy;
    BOOL ready;
    int i;
    TextBoxLine *line;
    TextWin *win;
    s32 dx;
    s32 dy;
    s32 t;
    int alpha;

    if (!box->flag1) {
        return;
    }
    busy = FALSE;
    func_02043d20(data_02097d48->unk_8b0, 0);
    NNSi_G3dGeTexImageParam(0, 0, 0, 0, 0, 0, 1, 0);
    ready = TRUE;
    NNSi_G3dGePolygonAttr(0, 1, 3, 0x14, 0x1f, 0);
    G3i_Translate(0, 0, -0x10cd);
    func_02043db4(1, 0x100000, 0xc0000, 0);
    win = (TextWin *)box->obj;
    if (win != NULL) {
        if (win->unk_6c != NULL) {
            if (func_0203e63c(win->unk_6c)) {
                win->unk_6c = NULL;
            } else if (win->noVram) {
                ready = FALSE;
            }
        }
        if (ready) {
            line = &box->lines[box->unk_204];
            OBJ_DELETE_LINE(line);
            line->obj = box->obj;
            box->obj = NULL;
            if (line->obj != NULL) {
                line->unk_90 = 0;
                line->fadeIn = 1;
                line->unk_98 = 0;
            }
            box->unk_204++;
        }
    } else if (box->flag6 == 1) {
        for (i = 0; i < 3; i++) {
            if (box->lines[i].obj != NULL) {
                busy = TRUE;
            }
        }
        if (!busy) {
            box->flag6 = 0;
            if (box->unk_024 < box->unk_028) {
                box->unk_002 = 0x3c;
                func_020508f4(box, box->unk_020);
            } else {
                box->flag7 = 1;
                func_0203c9e8(0x3f, -1);
                func_0203cc58(0x78000, 2, 0);
                if (box->unk_018 != -1) {
                    s32 vol = func_0204a2c8(data_02097e4c, box->unk_018);
                    func_02049870(data_02097e4c, box->unk_018);
                    func_02049950(data_02097e4c, 0, 0);
                    func_02049950(data_02097e4c, vol, 0xf0);
                }
            }
        }
    } else if ((s8)box->unk_002 < 0) {
        box->unk_002 = 0;
        if (box->flag2) {
            box->flag2 = 0;
            box->flag3 = 1;
            box->flag5 = 1;
        }
        if (box->flag2 != 1 && box->flag3 != 1 && box->flag7 != 1 && !box->flag5 && box->flag9 != 1 && box->flag8 != 1) {
            if (box->unk_204 >= box->unk_208) {
                if (!TextBox_IsFading(box)) {
                    box->unk_024++;
                    box->flag2 = 1;
                }
            } else if (box->unk_204 < box->unk_208) {
                u32 saved;
                line = &box->lines[box->unk_204];
                win = TextBox_NewWin();
                win->unk_28 = box->pltt;
                win->unk_24 = (u32)line;
                win->unk_4c = func_0204c4fc(win->unk_28, win->unk_38, win->unk_24, &win->vramSize, &win->vramArg, (s8)win->unk_37 != 0 ? TRUE : FALSE);
                data_02097ce0->unk_004 = win->unk_28;
                win->unk_2c = 0;
                win->unk_74 = 0x77df;
                win->unk_76 = 0x67e;
                win->noVram = 1;
                win->flag22 = 1;
                win->flag24 = 1;
                win->unk_78 = 0x9000;
                win->unk_vf14();
                win->rendering = 1;
                data_02097ce0->unk_004 = win->unk_28;
                saved = win->rendering;
                win->rendering = 1;
                if (win->noVram) {
                    win->inRender = 1;
                    win->Render();
                    win->inRender = 0;
                } else {
                    win->vram = func_020397fc(win->vramSize, win->vramArg, 0);
                    win->vram->unk_10_29 = 0;
                    win->Render();
                    win->vram->unk_10_29 = 1;
                }
                win->rendering = saved;
                box->obj = (TextBoxObj *)win;
                box->unk_002 = 0x78;
            }
        }
    }
    {
    int j;
    ln = box->lines;
    for (j = 0; j < box->unk_204; j++, ln++) {
        if (ln->obj == NULL) {
            continue;
        }
        // Per-line draw offset; fading out slides the line to the right.
        dx = dy = 0;
        alpha = 0x1e;
        if (ln->fadeIn == 1) {
            ln->unk_98 += 0x1000;
            t = FX_Div(ln->unk_98, 0x3c000);
            if (t >= 0x1000) {
                t = 0x1000;
                ln->fadeIn = 0;
                dx = dy = 0;
            }
            alpha = (u8)(TextWin_FxMul(t, 0x1e000) >> 12);
        } else if (ln->fadeOut == 1) {
            if (--ln->unk_90 < 0) {
                ln->unk_90 = 0;
                t = FX_Div(0x10000 - ln->unk_98, 0x10000);
                ln->unk_98 += TextWin_FxMul(ln->unk_98, 0x19a);
                if (ln->unk_98 >= 0x10000) {
                    OBJ_DELETE_LINE(ln);
                    TextBoxLine_Init(ln);
                    continue;
                }
                if (t >= 0x1000) {
                    t = 0x1000;
                } else if (t < 0) {
                    t = 0;
                }
                dx = ln->unk_98 >> 12;
                alpha = (u8)(TextWin_FxMul(t, 0x1e000) >> 12);
            }
        }
        if (alpha != 0) {
            s32 x = dx + (0x80 - (ln->unk_88 >> 1));
            s32 y = dy;
            y += ((0xc0 - ln->unk_8c * (s32)box->unk_208) >> 1) + ln->unk_8c * j;
            ((TextWin *)ln->obj)->unk_4_8 = alpha;
            ((TextWin *)ln->obj)->unk_vf20(x, y);
            ((TextWin *)ln->obj)->Render();
        }
    }
    }
    if (!box->flag4) {
        func_02050b50(box);
    }
}

}

}  // namespace m_TextWin_8
#undef OBJ_DELETE_LINE

// ---- TextWin_9
namespace m_TextWin_9 {

// Base of the text layout helper; its vtable stays in asm.
struct TextLayout {
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void Clear();
};

extern "C" {

extern const u32 data_0208ba70[];
extern void (*NNS_GfdDefaultFuncFreeTexVram)(void *p);
extern void (*NNS_GfdDefaultFuncFreePlttVram)(void *p);

extern void *func_0203de84(u32 size, u32 align);
extern void func_0203df0c(void *ptr);
extern void func_0203de1c(void *ptr);
extern void func_0203e58c(void *ptr);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void func_02039828(VramBlock *block);
extern VramBlock *func_020397fc(u32 size, u32 arg, u32 c);
extern s32 func_02040778(const char *s, int *len);
extern void func_0205bef8(void *cmd);

TextLayout *func_0204c4d4(TextLayout *layout);

void func_0204c7d0(TextWin *win);

void func_0204c8a8(TextWin *win);

Model *func_0204c9f8(Model *model);

void func_0204ca14(TextWin *win, u32 n);

void func_0204ca70(TextWin *win);

typedef struct TextCmd {
    /* 0x0 */ u32 unk_0;
    /* 0x4 */ u16 flags;
    /* 0x6 */ u16 id;
    /* 0x8 */ u16 args[6];
} TextCmd;

void func_0204cb28(TextWin *win, u32 arg);

char *func_0204cef4(TextWin *win, char *p);

char *func_0204cf18(TextWin *win, char *p);

char *func_0204cf6c(TextWin *win, char *p);

char *func_0204cfa0(TextWin *win, char *p);

char *func_0204d014(TextWin *win, char *p);


// Compares a tag name up to its closing '>'. Returns 0 on a match.
static inline int TextWin_TagCmp(char c, const char *s, const char *tag) {
    if (c != '>') {
        do {
            if (*s++ != *tag++) {
                return 1;
            }
        } while (*s != '>');
    }
    return 0;
}

char *func_0204d040(TextWin *win, char *p);

char *func_0204d238(TextWin *win, char *p);

char *func_0204d380(TextWin *win, char *p);

char *func_0204d4b0(TextWin *win, char *p);

char *func_0204d54c(TextWin *win, char *p);

char *func_0204d57c(TextWin *win, char *p);

char *func_0204d7e0(TextWin *win, char *p);

char *func_0204d82c(TextWin *win, char *p);

char *func_0204d870(TextWin *win, char *p);

char *func_0204d8c0(TextWin *win, char *p);

char *func_0204d8f8(TextWin *win, char *p);

char *func_0204d930(TextWin *win, char *p);

char *func_0204d9f0(TextWin *win, char *p);

char *func_0204da2c(TextWin *win, char *p);

char *func_0204da68(TextWin *win, char *p);

char *func_0204da78(TextWin *win, char *p);

extern SndQueue *data_02097e48;
extern SndMgr *data_02097e4c;
extern void func_0204aab0(SndQueue *queue, u16 value);
extern void func_0204a284(SndMgr *mgr, s32 fade);

static inline void SndQueue_RequestBgm(SndQueue *queue, u16 bgm) {
    if (!queue->flag0) {
        return;
    }
    if (queue->unk_06 == 0xffff && queue->unk_04 == bgm) {
        return;
    }
    if (queue->unk_02 != 10 && queue->unk_02 != 0) {
        if (queue->unk_06 != 0xffff) {
            func_0204aab0(queue, queue->unk_06);
        }
        queue->unk_02 = 1;
    } else {
        queue->unk_02 = 0;
    }
    queue->unk_06 = bgm;
    queue->unk_08 = 10;
}

static inline void SndQueue_StopBgm(SndQueue *queue, u16 fade) {
    if (queue->flag3) {
        queue->unk_06 = 0x8000;
        queue->unk_08 = fade;
        queue->unk_02 = 0;
    }
}

void func_0204daf4(TextWin *win);

void func_0204dbc8(TextWin *win);

void func_0204dc04(TextWin *win);

extern SndHandle *func_02049a48(SndMgr *mgr, s32 id, s32 volume, s32 targetVolume, s32 frames);
extern void func_02049de8(SndMgr *mgr, s32 id);

void func_0204dc84(TextWin *win);

typedef struct PadState {
    /* 0x00 */ u8 unk_00[0x12];
    /* 0x12 */ u16 trig;
} PadState;

extern PadState *data_02097dc8;

BOOL func_0204dccc(TextWin *win);

u16 func_0204dd84(void);

void func_0204dd98(TextWin *win);

static inline void TextWin_SetOrigin(u16 x, u16 y) {
    GfxMgr *gfx = data_02097ce0;
    gfx->unk_00c = x;
    gfx->unk_00e = y;
}

void func_0204dda8(TextWin *win);

static inline void TextWin_RenderOutline(TextWin *win) {
    win->unk_3c++;
    win->Render();
    win->unk_3c--;
    win->unk_3c--;
    win->Render();
    win->unk_3c++;
    win->unk_40++;
    win->Render();
    win->unk_40--;
    win->unk_40--;
    win->Render();
    win->unk_40++;
}

void func_0204de78(TextWin *win);

static inline BOOL TextWin_IsFlag31(TextWin *win) {
    return win->flag31 ? TRUE : FALSE;
}

BOOL func_0204e218(TextWin *win);

extern void *func_0203dd9c(u32 size);
extern void *func_02035d5c(char *name);
extern void *func_02034d88(void *a, void *b);
extern s32 FX_Div(s32 a, s32 b);
extern const s16 FX_SinCosTable_[];
extern const char *data_0208cb84;
extern const char *data_0208cc8c;
extern const char *data_0208cb74;
extern const char *data_0208cca0;

static inline Model *Model_Init(Model *model, const char *name, const char *file, int a) {
    func_02041218(model->pltt);
    func_02041440(model, file, a);
    STD_CopyString(model->name, name);
    return model;
}

}

struct TextModel : Model {
    TextModel(const char *name, const char *file, int a) {
        func_02041218(pltt);
        func_02041440(this, file, a);
        STD_CopyString(this->name, name);
    }
    static void *operator new(unsigned long size) {
        return func_0203dd9c(size);
    }
};

extern "C" {

static inline s16 TextWin_SinIdx(s32 angle) {
    return FX_SinCosTable_[(angle >> 4) * 2];
}

static inline s32 TextWin_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void Model_SetPos(Model *model, s32 x, s32 y) {
    model->x = x;
    model->y = y;
}

static inline void Model_ApplyPart(Model *model, s32 idx) {
    ModelRes *res = model->res;
    ModelPart *part;
    void *tex;
    if (res == NULL) {
        return;
    }
    part = idx >= model->numParts ? NULL : &model->parts[idx];
    if (part != NULL && part->res != NULL) {
        tex = part->res->tex;
    } else {
        tex = NNS_G2dGetCellDataByIdx(res->texRes, ***(u16 ***)((u8 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx) + 0xc));
    }
    func_02042628(model, tex, part, 0);
}

void func_0204dff8(TextWin *win);

Model *func_0204e238(Model *model, const char *name, const char *file, int a);

void *func_0204e278(void *pltt);

char *func_0204e28c(Model *model);

void *func_0204e294(Model *model);

void func_0204e29c(Model *model);

s16 func_0204e2ac(s32 angle);

s32 func_0204e2c4(s32 a, s32 b);

void func_0204e2dc(Model *model, s32 v);

void func_0204e2e4(Model *model, s32 idx);

extern void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
extern void *func_0203972c(void *blocks, u32 count);
extern s32 func_0204f804(TextWinEx *win);
extern s32 data_02097d78[];

u8 *func_0204f354(void);

void func_0204f368(int light, int polyMode, int cullMode, int polygonId, int alpha, int misc);

void func_0204f3a0(int texFmt, int texGen, int s, int t, int repeat, int flip, int pltt0, u32 addr);

void func_0204f3ec(void);

void func_0204f404(s32 x, s32 y, s32 z);

void func_0204f430(s32 x, s32 y, s32 z);

void func_0204f45c(u32 color);

void func_0204f478(s32 num, ...);

void func_0204f49c(TextWinEx *win);

static inline void TextWin_ClearVram(VramBlock *b) {
    MIi_CpuClearFast(0, (u8 *)(b->kind == 4 ? 0x6400000 : 0x6600000) + b->addr, b->size - b->pad);
}

static inline void TextWinEx_FreeBlocks(TextWinEx *win) {
    int i = 0;
    win->numBlocks = i;
    for (; i < 0x80; i++) {
        if (win->blocks[i] != NULL) {
            TextWin_ClearVram(win->blocks[i]);
            func_02039828(win->blocks[i]);
            win->blocks[i] = NULL;
            win->blockIds[i] = 0;
        }
    }
}

void func_0204f524(TextWinEx *win);

BOOL func_0204f5bc(TextWinEx *win);

void func_0204f784(TextWinEx *win);

BOOL func_0204ffb0(int idx);

TextLayout *func_0205070c(TextLayout *layout) {
    *(const u32 **)layout = data_0208ba70;
    layout->Clear();
    func_0203de1c(layout);
    return layout;
}

void func_0205073c(TextWin *win, s32 x, s32 y) {
    win->unk_3c = x;
    win->unk_40 = y;
}

static inline void TextBoxLine_Init(TextBoxLine *line) {
    line->unk_00 = 0;
    line->unk_80 = 0;
    line->obj = NULL;
    line->unk_88 = 0;
    line->unk_8c = 0;
    line->unk_90 = 0;
    line->unk_94 = 0;
    line->unk_98 = 0;
}

void func_02050748(TextBox *box) {
    int i;
    box->unk_000 = 0;
    box->unk_003 = 0;
    box->unk_002 = 0;
    box->unk_004 = 0;
    box->unk_008 = 0;
    box->model = NULL;
    box->pltt = 8;
    box->lineHeight = 6;
    box->unk_018 = -1;
    box->unk_01c = 0;
    box->unk_020 = 0;
    box->unk_024 = 0;
    box->unk_028 = 0;
    for (i = 0; i < 3; i++) {
        TextBoxLine_Init(&box->lines[i]);
    }
    box->obj = NULL;
    box->unk_204 = 0;
    box->unk_208 = 0;
    box->unk_20c = 0;
}

void func_020507d8(TextBox *box);

void func_020508e4(TextWin *win);

void func_02050e94(Model *model);

void func_02050ea4(Model *model, u32 v);

}

}  // namespace m_TextWin_9

// ---- TextWin_10
namespace m_TextWin_10 {

// Base of the text layout helper; its vtable stays in asm.
struct TextLayout {
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void Clear();
};

extern "C" {

extern const u32 data_0208ba70[];
extern void (*NNS_GfdDefaultFuncFreeTexVram)(void *p);
extern void (*NNS_GfdDefaultFuncFreePlttVram)(void *p);

extern void *func_0203de84(u32 size, u32 align);
extern void func_0203df0c(void *ptr);
extern void func_0203de1c(void *ptr);
extern void func_0203e58c(void *ptr);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void func_02039828(VramBlock *block);
extern VramBlock *func_020397fc(u32 size, u32 arg, u32 c);
extern s32 func_02040778(const char *s, int *len);
extern void func_0205bef8(void *cmd);

TextLayout *func_0204c4d4(TextLayout *layout);

void func_0204c7d0(TextWin *win);

void func_0204c8a8(TextWin *win);

Model *func_0204c9f8(Model *model);

void func_0204ca14(TextWin *win, u32 n);

void func_0204ca70(TextWin *win);

typedef struct TextCmd {
    /* 0x0 */ u32 unk_0;
    /* 0x4 */ u16 flags;
    /* 0x6 */ u16 id;
    /* 0x8 */ u16 args[6];
} TextCmd;

void func_0204cb28(TextWin *win, u32 arg);

char *func_0204cef4(TextWin *win, char *p);

char *func_0204cf18(TextWin *win, char *p);

char *func_0204cf6c(TextWin *win, char *p);

char *func_0204cfa0(TextWin *win, char *p);

char *func_0204d014(TextWin *win, char *p);


// Compares a tag name up to its closing '>'. Returns 0 on a match.
static inline int TextWin_TagCmp(char c, const char *s, const char *tag) {
    if (c != '>') {
        do {
            if (*s++ != *tag++) {
                return 1;
            }
        } while (*s != '>');
    }
    return 0;
}

char *func_0204d040(TextWin *win, char *p);

char *func_0204d238(TextWin *win, char *p);

char *func_0204d380(TextWin *win, char *p);

char *func_0204d4b0(TextWin *win, char *p);

char *func_0204d54c(TextWin *win, char *p);

char *func_0204d57c(TextWin *win, char *p);

char *func_0204d7e0(TextWin *win, char *p);

char *func_0204d82c(TextWin *win, char *p);

char *func_0204d870(TextWin *win, char *p);

char *func_0204d8c0(TextWin *win, char *p);

char *func_0204d8f8(TextWin *win, char *p);

char *func_0204d930(TextWin *win, char *p);

char *func_0204d9f0(TextWin *win, char *p);

char *func_0204da2c(TextWin *win, char *p);

char *func_0204da68(TextWin *win, char *p);

char *func_0204da78(TextWin *win, char *p);

extern SndQueue *data_02097e48;
extern SndMgr *data_02097e4c;
extern void func_0204aab0(SndQueue *queue, u16 value);
extern void func_0204a284(SndMgr *mgr, s32 fade);

static inline void SndQueue_RequestBgm(SndQueue *queue, u16 bgm) {
    if (!queue->flag0) {
        return;
    }
    if (queue->unk_06 == 0xffff && queue->unk_04 == bgm) {
        return;
    }
    if (queue->unk_02 != 10 && queue->unk_02 != 0) {
        if (queue->unk_06 != 0xffff) {
            func_0204aab0(queue, queue->unk_06);
        }
        queue->unk_02 = 1;
    } else {
        queue->unk_02 = 0;
    }
    queue->unk_06 = bgm;
    queue->unk_08 = 10;
}

static inline void SndQueue_StopBgm(SndQueue *queue, u16 fade) {
    if (queue->flag3) {
        queue->unk_06 = 0x8000;
        queue->unk_08 = fade;
        queue->unk_02 = 0;
    }
}

void func_0204daf4(TextWin *win);

void func_0204dbc8(TextWin *win);

void func_0204dc04(TextWin *win);

extern SndHandle *func_02049a48(SndMgr *mgr, s32 id, s32 volume, s32 targetVolume, s32 frames);
extern void func_02049de8(SndMgr *mgr, s32 id);

void func_0204dc84(TextWin *win);

typedef struct PadState {
    /* 0x00 */ u8 unk_00[0x12];
    /* 0x12 */ u16 trig;
} PadState;

extern PadState *data_02097dc8;

BOOL func_0204dccc(TextWin *win);

u16 func_0204dd84(void);

void func_0204dd98(TextWin *win);

static inline void TextWin_SetOrigin(u16 x, u16 y) {
    GfxMgr *gfx = data_02097ce0;
    gfx->unk_00c = x;
    gfx->unk_00e = y;
}

void func_0204dda8(TextWin *win);

static inline void TextWin_RenderOutline(TextWin *win) {
    win->unk_3c++;
    win->Render();
    win->unk_3c--;
    win->unk_3c--;
    win->Render();
    win->unk_3c++;
    win->unk_40++;
    win->Render();
    win->unk_40--;
    win->unk_40--;
    win->Render();
    win->unk_40++;
}

void func_0204de78(TextWin *win);

static inline BOOL TextWin_IsFlag31(TextWin *win) {
    return win->flag31 ? TRUE : FALSE;
}

BOOL func_0204e218(TextWin *win);

extern void *func_0203dd9c(u32 size);
extern void *func_02035d5c(char *name);
extern void *func_02034d88(void *a, void *b);
extern s32 FX_Div(s32 a, s32 b);
extern const s16 FX_SinCosTable_[];
extern const char *data_0208cb84;
extern const char *data_0208cc8c;
extern const char *data_0208cb74;
extern const char *data_0208cca0;

static inline Model *Model_Init(Model *model, const char *name, const char *file, int a) {
    func_02041218(model->pltt);
    func_02041440(model, file, a);
    STD_CopyString(model->name, name);
    return model;
}

}

struct TextModel : Model {
    TextModel(const char *name, const char *file, int a) {
        func_02041218(pltt);
        func_02041440(this, file, a);
        STD_CopyString(this->name, name);
    }
    static void *operator new(unsigned long size) {
        return func_0203dd9c(size);
    }
};

extern "C" {

static inline s16 TextWin_SinIdx(s32 angle) {
    return FX_SinCosTable_[(angle >> 4) * 2];
}

static inline s32 TextWin_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void Model_SetPos(Model *model, s32 x, s32 y) {
    model->x = x;
    model->y = y;
}

static inline void Model_ApplyPart(Model *model, s32 idx) {
    ModelRes *res = model->res;
    ModelPart *part;
    void *tex;
    if (res == NULL) {
        return;
    }
    part = idx >= model->numParts ? NULL : &model->parts[idx];
    if (part != NULL && part->res != NULL) {
        tex = part->res->tex;
    } else {
        tex = NNS_G2dGetCellDataByIdx(res->texRes, ***(u16 ***)((u8 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx) + 0xc));
    }
    func_02042628(model, tex, part, 0);
}

void func_0204dff8(TextWin *win);

Model *func_0204e238(Model *model, const char *name, const char *file, int a);

void *func_0204e278(void *pltt);

char *func_0204e28c(Model *model);

void *func_0204e294(Model *model);

void func_0204e29c(Model *model);

s16 func_0204e2ac(s32 angle);

s32 func_0204e2c4(s32 a, s32 b);

void func_0204e2dc(Model *model, s32 v);

void func_0204e2e4(Model *model, s32 idx);

extern void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
extern void *func_0203972c(void *blocks, u32 count);
extern s32 func_0204f804(TextWinEx *win);
extern s32 data_02097d78[];

u8 *func_0204f354(void);

void func_0204f368(int light, int polyMode, int cullMode, int polygonId, int alpha, int misc);

void func_0204f3a0(int texFmt, int texGen, int s, int t, int repeat, int flip, int pltt0, u32 addr);

void func_0204f3ec(void);

void func_0204f404(s32 x, s32 y, s32 z);

void func_0204f430(s32 x, s32 y, s32 z);

void func_0204f45c(u32 color);

void func_0204f478(s32 num, ...);

void func_0204f49c(TextWinEx *win);

static inline void TextWin_ClearVram(VramBlock *b) {
    MIi_CpuClearFast(0, (u8 *)(b->kind == 4 ? 0x6400000 : 0x6600000) + b->addr, b->size - b->pad);
}

static inline void TextWinEx_FreeBlocks(TextWinEx *win) {
    int i = 0;
    win->numBlocks = i;
    for (; i < 0x80; i++) {
        if (win->blocks[i] != NULL) {
            TextWin_ClearVram(win->blocks[i]);
            func_02039828(win->blocks[i]);
            win->blocks[i] = NULL;
            win->blockIds[i] = 0;
        }
    }
}

void func_0204f524(TextWinEx *win);

BOOL func_0204f5bc(TextWinEx *win);

void func_0204f784(TextWinEx *win);

BOOL func_0204ffb0(int idx);

TextLayout *func_0205070c(TextLayout *layout);

void func_0205073c(TextWin *win, s32 x, s32 y);

static inline void TextBoxLine_Init(TextBoxLine *line) {
    line->unk_00 = 0;
    line->unk_80 = 0;
    line->obj = NULL;
    line->unk_88 = 0;
    line->unk_8c = 0;
    line->unk_90 = 0;
    line->unk_94 = 0;
    line->unk_98 = 0;
}

void func_02050748(TextBox *box);

void func_020507d8(TextBox *box) {
    void *saved;
    int i;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    {
        Model *p = box->model;
        if (p != NULL) {
            if (p != NULL) {
                func_02041558(p);
                func_02041278(p->pltt);
                func_0203de1c(p);
            }
            box->model = NULL;
        }
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    {
        TextBoxObj *p = box->obj;
        if (p != NULL) {
            if (p != NULL) {
                p->DeletingDtor();
            }
            box->obj = NULL;
        }
    }
    data_02097dd0->cur = saved;
    for (i = 0; i < 3; i++) {
        void *saved2 = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->unk_08;
        {
            TextBoxObj *p = box->lines[i].obj;
            if (p != NULL) {
                if (p != NULL) {
                    p->DeletingDtor();
                }
                box->lines[i].obj = NULL;
            }
        }
        data_02097dd0->cur = saved2;
        TextBoxLine_Init(&box->lines[i]);
    }
}

void func_020508e4(TextWin *win) {
    win->flag5 = 1;
}

void func_02050e94(Model *model);

void func_02050ea4(Model *model, u32 v);

}

}  // namespace m_TextWin_10

// ---- TextWin_14
namespace m_TextWin_14 {

// Base of the text layout helper; its vtable stays in asm.
struct TextLayout {
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void Clear();
};

extern "C" {

extern const u32 data_0208ba70[];

typedef struct TextScanTag {
    s32 code;
    s32 value;
} TextScanTag;

typedef struct TextScanParser {
    /* 0x00 */ const u32 *vt;
    /* 0x04 */ u8 unk_04[0x7c];
    /* 0x80 */ TextScanTag tag;
    /* 0x88 */ u8 unk_88[0x30];
} TextScanParser;

void *func_0203a4c0(GfxMgr *mgr);
void func_0204c7d0(TextWin *win);
void func_0204cc18(TextScanParser *p, const char **s);

// Splits the string into the box's lines. The copy is written `*dst = start[i]; dst++;`:
// `*dst++ = start[i]` makes MWCC give dst a new object below the named locals (round loopt).
void func_020508f4(TextBox *box, const char *str) {
    TextBoxLine *line;
    char *dst;
    NNSG2dFont *font;
    TextScanParser p;
    const char *start;
    TextScanTag *tag;
    s32 width;
    const char *s;
    s32 height;
    u16 c;
    NNSiG2dSplitCharCallback fn;
    u32 n;
    s32 nLines;
    u32 i;
    data_02097ce0->unk_004 = box->pltt;
    font = (NNSG2dFont *)func_0203a4c0(data_02097ce0);
    fn = font->cbCharSpliter;
    s = str;
    p.vt = data_0208ba70;
    line = &box->lines[0];
    func_0204c7d0((TextWin *)&p);
    nLines = 0;
    dst = (char *)&line->unk_00;
    width = nLines;
    height = box->lineHeight + font->pRes->pGlyph->cellHeight;
    goto test;
    do {
        while (start = s, (c = fn((const void **)&s)) != 0) {
            if (c == '\n') {
                line->unk_88 = width;
                line->unk_8c = height;
                line++;
                dst = (char *)&line->unk_00;
                nLines++;
                width = 0;
                break;
            }
            if (c == '\\') {
                start = s;
                c = fn((const void **)&s);
            } else if (c == '<') {
                func_0204cc18(&p, &s);
                tag = &p.tag;
                switch (tag->code) {
                case 0x15:
                    if (tag->value != 0) {
                        box->unk_000 |= 0x10;
                    }
                    break;
                case 0x16:
                    box->unk_018 = tag->value;
                    break;
                }
                start = s;
            } else if (c == 0x3001) {
                c = ' ';
            } else if (c == 0x3002) {
                c = ' ';
            }
            n = s - start;
            if (n != 0) {
                for (i = 0; i < n; i++) {
                    if (line->unk_80 < 0x7f) {
                        *dst = start[i];
                        dst++;
                        line->unk_80++;
                    }
                }
                *dst = 0;
                width += NNS_G2dFontGetCharWidth(font, c);
            }
            start = s;
            if (*start == 0) {
                box->unk_020 = (u32)(start + 1);
                line->unk_88 = width;
                line->unk_8c = height;
                break;
            }
        }
    test:
        if (*s == 0) {
            break;
        }
    } while (*s != 0);
    box->unk_204 = 0;
    box->unk_208 = nLines + 1;
    p.vt = data_0208ba70;
    ((TextLayout *)&p)->Clear();
}

}

}  // namespace m_TextWin_14

// ---- TextWin_11
namespace m_TextWin_11 {

// Base of the text layout helper; its vtable stays in asm.
struct TextLayout {
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void Clear();
};

extern "C" {

extern const u32 data_0208ba70[];
extern void (*NNS_GfdDefaultFuncFreeTexVram)(void *p);
extern void (*NNS_GfdDefaultFuncFreePlttVram)(void *p);

extern void *func_0203de84(u32 size, u32 align);
extern void func_0203df0c(void *ptr);
extern void func_0203de1c(void *ptr);
extern void func_0203e58c(void *ptr);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void func_02039828(VramBlock *block);
extern VramBlock *func_020397fc(u32 size, u32 arg, u32 c);
extern s32 func_02040778(const char *s, int *len);
extern void func_0205bef8(void *cmd);

TextLayout *func_0204c4d4(TextLayout *layout);

void func_0204c7d0(TextWin *win);

void func_0204c8a8(TextWin *win);

Model *func_0204c9f8(Model *model);

void func_0204ca14(TextWin *win, u32 n);

void func_0204ca70(TextWin *win);

typedef struct TextCmd {
    /* 0x0 */ u32 unk_0;
    /* 0x4 */ u16 flags;
    /* 0x6 */ u16 id;
    /* 0x8 */ u16 args[6];
} TextCmd;

void func_0204cb28(TextWin *win, u32 arg);

char *func_0204cef4(TextWin *win, char *p);

char *func_0204cf18(TextWin *win, char *p);

char *func_0204cf6c(TextWin *win, char *p);

char *func_0204cfa0(TextWin *win, char *p);

char *func_0204d014(TextWin *win, char *p);


// Compares a tag name up to its closing '>'. Returns 0 on a match.
static inline int TextWin_TagCmp(char c, const char *s, const char *tag) {
    if (c != '>') {
        do {
            if (*s++ != *tag++) {
                return 1;
            }
        } while (*s != '>');
    }
    return 0;
}

char *func_0204d040(TextWin *win, char *p);

char *func_0204d238(TextWin *win, char *p);

char *func_0204d380(TextWin *win, char *p);

char *func_0204d4b0(TextWin *win, char *p);

char *func_0204d54c(TextWin *win, char *p);

char *func_0204d57c(TextWin *win, char *p);

char *func_0204d7e0(TextWin *win, char *p);

char *func_0204d82c(TextWin *win, char *p);

char *func_0204d870(TextWin *win, char *p);

char *func_0204d8c0(TextWin *win, char *p);

char *func_0204d8f8(TextWin *win, char *p);

char *func_0204d930(TextWin *win, char *p);

char *func_0204d9f0(TextWin *win, char *p);

char *func_0204da2c(TextWin *win, char *p);

char *func_0204da68(TextWin *win, char *p);

char *func_0204da78(TextWin *win, char *p);

extern SndQueue *data_02097e48;
extern SndMgr *data_02097e4c;
extern void func_0204aab0(SndQueue *queue, u16 value);
extern void func_0204a284(SndMgr *mgr, s32 fade);

static inline void SndQueue_RequestBgm(SndQueue *queue, u16 bgm) {
    if (!queue->flag0) {
        return;
    }
    if (queue->unk_06 == 0xffff && queue->unk_04 == bgm) {
        return;
    }
    if (queue->unk_02 != 10 && queue->unk_02 != 0) {
        if (queue->unk_06 != 0xffff) {
            func_0204aab0(queue, queue->unk_06);
        }
        queue->unk_02 = 1;
    } else {
        queue->unk_02 = 0;
    }
    queue->unk_06 = bgm;
    queue->unk_08 = 10;
}

static inline void SndQueue_StopBgm(SndQueue *queue, u16 fade) {
    if (queue->flag3) {
        queue->unk_06 = 0x8000;
        queue->unk_08 = fade;
        queue->unk_02 = 0;
    }
}

void func_0204daf4(TextWin *win);

void func_0204dbc8(TextWin *win);

void func_0204dc04(TextWin *win);

extern SndHandle *func_02049a48(SndMgr *mgr, s32 id, s32 volume, s32 targetVolume, s32 frames);
extern void func_02049de8(SndMgr *mgr, s32 id);

void func_0204dc84(TextWin *win);

typedef struct PadState {
    /* 0x00 */ u8 unk_00[0x12];
    /* 0x12 */ u16 trig;
} PadState;

extern PadState *data_02097dc8;

BOOL func_0204dccc(TextWin *win);

u16 func_0204dd84(void);

void func_0204dd98(TextWin *win);

static inline void TextWin_SetOrigin(u16 x, u16 y) {
    GfxMgr *gfx = data_02097ce0;
    gfx->unk_00c = x;
    gfx->unk_00e = y;
}

void func_0204dda8(TextWin *win);

static inline void TextWin_RenderOutline(TextWin *win) {
    win->unk_3c++;
    win->Render();
    win->unk_3c--;
    win->unk_3c--;
    win->Render();
    win->unk_3c++;
    win->unk_40++;
    win->Render();
    win->unk_40--;
    win->unk_40--;
    win->Render();
    win->unk_40++;
}

void func_0204de78(TextWin *win);

static inline BOOL TextWin_IsFlag31(TextWin *win) {
    return win->flag31 ? TRUE : FALSE;
}

BOOL func_0204e218(TextWin *win);

extern void *func_0203dd9c(u32 size);
extern void *func_02035d5c(char *name);
extern void *func_02034d88(void *a, void *b);
extern s32 FX_Div(s32 a, s32 b);
extern const s16 FX_SinCosTable_[];
extern const char *data_0208cb84;
extern const char *data_0208cc8c;
extern const char *data_0208cb74;
extern const char *data_0208cca0;

static inline Model *Model_Init(Model *model, const char *name, const char *file, int a) {
    func_02041218(model->pltt);
    func_02041440(model, file, a);
    STD_CopyString(model->name, name);
    return model;
}

}

struct TextModel : Model {
    TextModel(const char *name, const char *file, int a) {
        func_02041218(pltt);
        func_02041440(this, file, a);
        STD_CopyString(this->name, name);
    }
    static void *operator new(unsigned long size) {
        return func_0203dd9c(size);
    }
};

extern "C" {

static inline s16 TextWin_SinIdx(s32 angle) {
    return FX_SinCosTable_[(angle >> 4) * 2];
}

static inline s32 TextWin_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void Model_SetPos(Model *model, s32 x, s32 y) {
    model->x = x;
    model->y = y;
}

static inline void Model_ApplyPart(Model *model, s32 idx) {
    ModelRes *res = model->res;
    ModelPart *part;
    void *tex;
    if (res == NULL) {
        return;
    }
    part = idx >= model->numParts ? NULL : &model->parts[idx];
    if (part != NULL && part->res != NULL) {
        tex = part->res->tex;
    } else {
        tex = NNS_G2dGetCellDataByIdx(res->texRes, ***(u16 ***)((u8 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx) + 0xc));
    }
    func_02042628(model, tex, part, 0);
}

void func_0204dff8(TextWin *win);

Model *func_0204e238(Model *model, const char *name, const char *file, int a);

void *func_0204e278(void *pltt);

char *func_0204e28c(Model *model);

void *func_0204e294(Model *model);

void func_0204e29c(Model *model);

s16 func_0204e2ac(s32 angle);

s32 func_0204e2c4(s32 a, s32 b);

void func_0204e2dc(Model *model, s32 v);

void func_0204e2e4(Model *model, s32 idx);

extern void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
extern void *func_0203972c(void *blocks, u32 count);
extern s32 func_0204f804(TextWinEx *win);
extern s32 data_02097d78[];

u8 *func_0204f354(void);

void func_0204f368(int light, int polyMode, int cullMode, int polygonId, int alpha, int misc);

void func_0204f3a0(int texFmt, int texGen, int s, int t, int repeat, int flip, int pltt0, u32 addr);

void func_0204f3ec(void);

void func_0204f404(s32 x, s32 y, s32 z);

void func_0204f430(s32 x, s32 y, s32 z);

void func_0204f45c(u32 color);

void func_0204f478(s32 num, ...);

void func_0204f49c(TextWinEx *win);

static inline void TextWin_ClearVram(VramBlock *b) {
    MIi_CpuClearFast(0, (u8 *)(b->kind == 4 ? 0x6400000 : 0x6600000) + b->addr, b->size - b->pad);
}

static inline void TextWinEx_FreeBlocks(TextWinEx *win) {
    int i = 0;
    win->numBlocks = i;
    for (; i < 0x80; i++) {
        if (win->blocks[i] != NULL) {
            TextWin_ClearVram(win->blocks[i]);
            func_02039828(win->blocks[i]);
            win->blocks[i] = NULL;
            win->blockIds[i] = 0;
        }
    }
}

void func_0204f524(TextWinEx *win);

BOOL func_0204f5bc(TextWinEx *win);

void func_0204f784(TextWinEx *win);

BOOL func_0204ffb0(int idx);

TextLayout *func_0205070c(TextLayout *layout);

void func_0205073c(TextWin *win, s32 x, s32 y);

static inline void TextBoxLine_Init(TextBoxLine *line) {
    line->unk_00 = 0;
    line->unk_80 = 0;
    line->obj = NULL;
    line->unk_88 = 0;
    line->unk_8c = 0;
    line->unk_90 = 0;
    line->unk_94 = 0;
    line->unk_98 = 0;
}

void func_02050748(TextBox *box);

void func_020507d8(TextBox *box);

void func_020508e4(TextWin *win);

void func_02050ea4(Model *model, u32 v);
extern void func_02041c5c(Model *model, void *fn);
extern void func_02041c20(Model *model, int a, void *arg);
extern void func_02041c18(Model *model, int a);
extern void *func_0204fc4c(TextWin *win, const u16 *cmd, void *oam, u16 *count);

// Updates the text box cursor model: creates it on first use, then animates its position and alpha.
void func_02050b50(TextBox *box) {
    s32 r;
    s16 s;
    s32 y;
    int i;
    u8 alpha;
    if (box->model == NULL) {
        Model *m = (Model *)func_0203dd9c(0x160);
        if (m != NULL) {
            Model_Init(m, data_0208cca0, data_0208cb74, 0);
        }
        box->model = m;
        func_020417e0(box->model, func_02034d88(func_02035d5c(m->name), box->model->unk_04c));
        box->model->flags |= 2;
        func_02041d9c(box->model, 0, 2);
        box->model->flags |= 0x80000;
        func_02041c5c(box->model, (void *)func_0204fc4c);
        func_02041c20(box->model, 2, box);
        func_02041c18(box->model, 1);
        return;
    }
    r = FX_Div(box->unk_008, 0xf000);
    if (r >= 0x1000) {
        box->unk_008 = 0xf000;
        r = 0x1000;
    } else if (r < 0) {
        box->unk_008 = 0;
        r = 0;
        if (box->flag9) {
            box->flag9 = 0;
            if ((s32)box->unk_024 < (s32)box->unk_028) {
                box->flag6 = 1;
                for (i = 0; i < 3; i++) {
                    if (box->lines[i].obj != NULL) {
                        box->lines[i].unk_90 = (i + 1) * 30;
                        // Byte-offset form: the target computes this address from box->lines, not box.
                        ((TextBoxLine *)((u8 *)box->lines + i * sizeof(TextBoxLine)))->unk_94 |= 2;
                        box->lines[i].unk_98 = 0x1000;
                    }
                }
            }
        }
    }
    s = FX_SinCosTable_[((r << 14) >> 16) * 2];
    if (box->flag5) {
        y = TextWin_FxMul(0x1000 - s, 0x10000) >> 12;
    } else {
        y = TextWin_FxMul(0x1000 - s, -0x10000) >> 12;
    }
    r = FX_Div(box->unk_20c, 0x3c000);
    if (r >= 0x1000) {
        r -= 0x1000;
    }
    alpha = TextWin_FxMul(TextWin_FxMul(s, TextWin_FxMul(FX_SinCosTable_[((r << 15) >> 16) * 2], 0x800) + 0x800), 0x1e000) >> 12;
    if (alpha != 0) {
        box->model->flags = (box->model->flags & ~0x7c) | (((u32)alpha << 27) >> 25);
        Model_SetPos(box->model, (y + 0x6c) << 12, 0x4c000);
        Model_ApplyPart(box->model, 2);
    }
}

void func_02050e94(Model *model) {
    model->flags |= 0x80000;
}

void func_02050ea4(Model *model, u32 v) {
    model->flags = (model->flags & ~0x7c) | ((v << 27) >> 25);
}

// OAM entries of a name label: y in the low byte of word 0, palette in word 1.
typedef struct NameOam {
    u32 y : 8;
    u32 unk_0_8 : 24;
    u32 charName : 10;
    u32 priority : 2;
    u32 cParam : 4;
    u32 unk_4_16 : 16;
} NameOam;

typedef struct NameOwnerSub {
    /* 0x00 */ u8 unk_00[0x12];
    /* 0x12 */ u16 id;
    /* 0x14 */ u8 unk_14[0x20];
    /* 0x34 */ char name[1];
} NameOwnerSub;

typedef struct NameOwner {
    /* 0x000 */ u8 unk_000[0x3c0];
    /* 0x3c0 */ NameOwnerSub sub;
} NameOwner;

typedef struct NameOamInfo {
    /* 0x0 */ u16 unk_0;
    /* 0x4 */ u32 unk_4;
    /* 0x8 */ NameOwner *owner;
} NameOamInfo;

const char *func_0206ffa0(s32 id);
int STD_CompareString(const char *a, const char *b);

// Recolours the last 4 OAM entries of a name label when the owner is not
// the default character (0x1000).
NameOam *func_02050ebc(void *self, NameOamInfo *info, NameOam *oam, u16 *num) {
    NameOam *last;
    NameOwner *owner;
    u16 n;
    u32 pal;
    char *name;
    int i;
    const char *str;
    n = *num;
    last = &oam[n - 1];
    if (info->unk_0 == 0) {
        owner = info->owner;
        name = owner->sub.name;
        pal = last->cParam;
        oam = last - 3;
        n = 4;
        str = func_0206ffa0(0x1000);
        if (name != NULL) {
            if (STD_CompareString(name, str) != 0) {
                pal++;
            }
        } else if (((NameOwnerSub *)((s32)owner + 0x3c0))->id != 0x1000) {
            // The integer add keeps 0x3c0 apart from the field offset.
            pal++;
        }
        for (i = 0; i < 4; i++) {
            oam[i].y = 0;
            oam[i].cParam = pal;
        }
    }
    *num = n;
    return oam;
}

}

}  // namespace m_TextWin_11

// ---- TextWin_12
namespace m_TextWin_12 {

extern "C" {

// Model transform slot inside the text window scene.
typedef struct TwXform {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ u16 unk_08;
    /* 0x0a */ u16 unk_0a;
    /* 0x0c */ u16 unk_0c;
    /* 0x0e */ u16 pad_0e;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1c */ s32 unk_1c;
    /* 0x20 */ s32 pos[3];
    /* 0x2c */ s32 scale[3];
    /* 0x38 */ u16 rot[3];
    /* 0x3e */ u16 pad_3e;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ u8 unk_48;
    /* 0x49 */ u8 pad_49[3];
} TwXform;

typedef struct TwGroup {
    /* 0x000 */ s32 unk_00;
    /* 0x004 */ s32 unk_04;
    /* 0x008 */ u16 unk_08;
    /* 0x00a */ u16 unk_0a;
    /* 0x00c */ u16 unk_0c;
    /* 0x00e */ u16 unk_0e;
    /* 0x010 */ u16 unk_10;
    /* 0x012 */ u16 unk_12;
    /* 0x014 */ u16 unk_14;
    /* 0x016 */ u16 unk_16;
    /* 0x018 */ s32 unk_18;
    /* 0x01c */ s32 unk_1c;
    /* 0x020 */ s32 unk_20;
    /* 0x024 */ s32 unk_24;
    /* 0x028 */ s32 unk_28;
    /* 0x02c */ s32 unk_2c;
    /* 0x030 */ s32 unk_30;
    /* 0x034 */ s32 unk_34;
    /* 0x038 */ s32 unk_38;
    /* 0x03c */ s32 unk_3c;
    /* 0x040 */ s32 unk_40;
    /* 0x044 */ TwXform xforms[3];
    /* 0x128 */ u8 unk_128;
    /* 0x129 */ u8 pad_129[0x1f];
} TwGroup;

typedef struct TwScene {
    /* 0x000 */ u8 unk_000[0x38];
    /* 0x038 */ s32 unk_038;
    /* 0x03c */ u8 unk_03c[0x7c];
    /* 0x0b8 */ s32 unk_0b8;
    /* 0x0bc */ s32 unk_0bc;
    /* 0x0c0 */ s32 unk_0c0;
    /* 0x0c4 */ u16 unk_0c4;
    /* 0x0c6 */ u16 unk_0c6;
    /* 0x0c8 */ s32 unk_0c8;
    /* 0x0cc */ s32 unk_0cc;
    /* 0x0d0 */ s32 unk_0d0[0x80];
    /* 0x2d0 */ u16 unk_2d0[0x80];
    /* 0x3d0 */ u8 unk_3d0[4];
    /* 0x3d4 */ u8 unk_3d4[0x40];
    /* 0x414 */ s32 unk_414;
    /* 0x418 */ s32 unk_418;
    /* 0x41c */ s32 unk_41c;
    /* 0x420 */ s32 unk_420;
    /* 0x424 */ TwXform xforms[2];
    /* 0x4bc */ TwGroup groups[5];
    /* 0xb24 */ s32 unk_b24[23];
} TwScene;

static inline void TwXform_Init(TwXform *x) {
    x->unk_00 = 0;
    x->unk_04 = 8;
    x->unk_10 = 0;
    x->unk_14 = 0;
    x->unk_18 = 0;
    x->unk_1c = 0;
    x->unk_08 = 0;
    x->unk_0a = 0xffff;
    x->unk_0c = 0xffff;
    x->pos[0] = 0;
    x->pos[1] = 0;
    x->pos[2] = 0;
    x->scale[0] = 0x1000;
    x->scale[1] = 0x1000;
    x->scale[2] = 0x1000;
    x->rot[0] = 0;
    x->rot[1] = 0;
    x->rot[2] = 0;
    x->unk_40 = 0;
    x->unk_44 = 0;
    x->unk_48 = 0x1e;
}

void func_02050f70(TwScene *s) {
    int i;
    int j;
    s->unk_038 = 2;
    s->unk_0b8 = 0;
    s->unk_0bc = 0;
    s->unk_0c0 = 0;
    s->unk_0c4 = 0;
    s->unk_0c6 = 0;
    s->unk_0c8 = 0;
    s->unk_0cc = 0;
    for (i = 0; i < 0x80; i++) {
        s->unk_0d0[i] = 0;
        s->unk_2d0[i] = 0;
    }
    MIi_CpuClear16(0, s->unk_3d0, 4);
    MIi_CpuClear32(0, s->unk_3d4, 0x40);
    s->unk_414 = 0;
    s->unk_418 = 0;
    s->unk_41c = 0;
    s->unk_420 = 0;
    TwXform_Init(&s->xforms[0]);
    TwXform_Init(&s->xforms[1]);
    for (i = 0; i < 5; i++) {
        s->groups[i].unk_00 = s->groups[i].unk_04 = 0;
        s->groups[i].unk_08 = s->groups[i].unk_0a = 0;
        s->groups[i].unk_0c = s->groups[i].unk_0e = 0;
        s->groups[i].unk_10 = s->groups[i].unk_12 = 0xffff;
        s->groups[i].unk_14 = s->groups[i].unk_16 = 0;
        s->groups[i].unk_18 = s->groups[i].unk_1c = s->groups[i].unk_20 = 0;
        s->groups[i].unk_24 = s->groups[i].unk_28 = 0;
        s->groups[i].unk_2c = s->groups[i].unk_30 = 0;
        s->groups[i].unk_34 = s->groups[i].unk_38 = 0;
        s->groups[i].unk_3c = 0;
        s->groups[i].unk_40 = 0;
        for (j = 0; j < 3; j++) {
            TwXform_Init(&s->groups[i].xforms[j]);
        }
        s->groups[i].unk_128 = 0;
    }
    s->unk_b24[0] = 0;
    s->unk_b24[1] = 0;
    s->unk_b24[2] = 0;
    s->unk_b24[3] = 0;
    s->unk_b24[4] = 0;
    s->unk_b24[5] = 0;
    s->unk_b24[6] = 0;
    s->unk_b24[7] = 0;
    s->unk_b24[8] = 0;
    s->unk_b24[9] = 0;
    s->unk_b24[10] = 0;
    s->unk_b24[11] = 0;
    s->unk_b24[12] = 0;
    s->unk_b24[13] = 0;
    s->unk_b24[14] = 0;
    s->unk_b24[15] = 0;
    s->unk_b24[16] = 0;
    s->unk_b24[17] = 1;
    s->unk_b24[18] = 0;
    s->unk_b24[19] = 0;
    s->unk_b24[20] = 0;
    s->unk_b24[21] = 0;
    s->unk_b24[22] = 0;
}

}

}  // namespace m_TextWin_12

// ---- SlideWin
namespace m_SlideWin {

extern "C" {

extern StageResSlot *func_0205b31c(void);
extern void func_0205b348(void);
extern void func_0204a284(SndMgr *mgr, s32 fade);

extern void func_ov000_0218fee4(void *p);
extern void func_ov000_0218ea20(void *p);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void func_02039828(VramBlock *block);
extern void func_02050f70(SlideWin *win);

#define SW_DELETE(field, dtor) \
    { \
        void *saved = data_02097dd0->cur; \
        data_02097dd0->cur = data_02097dd0->unk_08; \
        { \
            void *p = (field); \
            if (p != NULL) { \
                if (p != NULL) { \
                    dtor(p); \
                    func_0203de1c(p); \
                } \
                (field) = NULL; \
            } \
        } \
        data_02097dd0->cur = saved; \
    }

#define SW_DELETE_MODEL(field) \
    { \
        void *saved = data_02097dd0->cur; \
        data_02097dd0->cur = data_02097dd0->unk_08; \
        { \
            Model *p = (field); \
            if (p != NULL) { \
                if (p != NULL) { \
                    func_02041558(p); \
                    func_02041278(p->pltt); \
                    func_0203de1c(p); \
                } \
                (field) = NULL; \
            } \
        } \
        data_02097dd0->cur = saved; \
    }

#define SW_ITEM_INIT(x) \
    (x).bits = 0; \
    (x).state = 8; \
    (x).unk_10 = 0; \
    (x).unk_14 = 0; \
    (x).unk_18 = 0; \
    (x).unk_1c = 0; \
    (x).unk_08 = 0; \
    (x).unk_0a = 0xffff; \
    (x).unk_0c = 0xffff; \
    (x).pos[0] = 0; \
    (x).pos[1] = 0; \
    (x).pos[2] = 0; \
    (x).scale[0] = 0x1000; \
    (x).scale[1] = 0x1000; \
    (x).scale[2] = 0x1000; \
    (x).rot[0] = 0; \
    (x).rot[1] = 0; \
    (x).rot[2] = 0; \
    (x).unk_40 = 0; \
    (x).unk_44 = 0; \
    (x).unk_48 = 0x1e;

#define SW_ITEM_RELEASE(x) \
    SW_DELETE((x).unk_14, func_ov000_0218fee4) \
    SW_DELETE((x).unk_10, func_ov000_0218ea20) \
    SW_DELETE((x).unk_1c, func_ov000_0218fee4) \
    SW_DELETE((x).unk_18, func_ov000_0218ea20) \
    SW_ITEM_INIT(x)

// The OBJ VRAM bases are read with the SDK getters into locals (the cast of the
// inline's pointer result keeps them real variables), and `i` is a `long`:
// together these give the target's register order and put both bases in the
// entry block.
void func_02051210(SlideWin *win) {
    long i;
    int j;
    u8 *objBase;
    u8 *subObjBase;
    objBase = (u8 *)G2_GetOBJCharPtr();
    subObjBase = (u8 *)G2S_GetOBJCharPtr();
    {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->unk_08;
        {
            SlideObj *p = win->obj;
            if (p != NULL) {
                if (p != NULL) {
                    p->DeletingDtor();
                }
                win->obj = NULL;
            }
        }
        data_02097dd0->cur = saved;
    }
    for (i = 0; i < 0x80; i++) {
        if (win->blocks[i] != NULL) {
            VramBlock *b = win->blocks[i];
            MIi_CpuClearFast(0, (b->kind == 4 ? objBase : subObjBase) + b->addr, b->size - b->pad);
            func_02039828(win->blocks[i]);
        }
    }
    SW_ITEM_RELEASE(win->items[0])
    SW_ITEM_RELEASE(win->items[1])
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            SW_ITEM_RELEASE(win->panels[i].items[j])
        }
        SW_DELETE(win->panels[i].pltt, func_02041278)
        SW_DELETE(win->panels[i].nextPltt, func_02041278)
        SW_DELETE_MODEL(win->panels[i].model)
        SW_DELETE_MODEL(win->panels[i].nextModel)
        SW_DELETE_MODEL(win->panels[i].model2)
        SW_DELETE_MODEL(win->panels[i].nextModel2)
    }
    func_02050f70(win);
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

void func_020518bc(SlideWin *win) {
    int i;
    if (win->mode == 2 || win->mode == 3) {
        if (win->unk_b8_24) {
            win->flag14 = 1;
            return;
        }
        StageResSlot *cmd = func_0205b31c();
        if (cmd != NULL && cmd->id == 0x371) {
            win->flag14 = 1;
            cmd->bits.flag8 = 1;
            func_0205bef8(cmd);
            func_0205b348();
            for (i = 0; i < 5; i++) {
                SlidePanelItem_Close(&win->panels[i].items[0]);
            }
            return;
        }
    }
    win->flag3 = 1;
    SlidePanelItem_Close(&win->items[0]);
    SlidePanelItem_Close(&win->items[1]);
    func_0204a284(data_02097e4c, -1);
}

}

}  // namespace m_SlideWin
#undef SW_DELETE
#undef SW_DELETE_MODEL
#undef SW_ITEM_INIT
#undef SW_ITEM_RELEASE

// ---- SlideWin_2
namespace m_SlideWin_2 {

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

}  // namespace m_SlideWin_2

// ---- Obj3D
namespace m_Obj3D {

extern "C" {

extern int func_02043d48(void *obj);
extern s8 data_02149ef4;

void func_02051f3c(Obj3DLayer *layer, u32 v) {
    if (layer->cur == 0) {
        layer->prev = v;
    } else {
        layer->prev = layer->cur;
    }
    layer->cur = v;
}

void func_020520fc(Obj3DRender *render);

void func_02052160(Obj3DRender *render);

s32 func_020534c4(s32 x);

s32 func_020534d4(void);

}

}  // namespace m_Obj3D

// ---- SceneShake
namespace m_SceneShake {

extern "C" {

void func_02051f70(GameScene *scene) {
    FieldState *state = data_ov000_021ccd54;
    scene->shakeTime = 0;
    scene->shakePhase = -1;
    switch (scene->shakeType) {
    case 0:
        scene->shake = 1;
        scene->shakePeriod = 0x2000;
        scene->shakeAmp = 0x4000;
        scene->shakeLimit = 4;
        break;
    case 1:
        scene->shake = 1;
        scene->shakePeriod = 0x3000;
        scene->shakeAmp = 0x7000;
        scene->shakeLimit = 5;
        break;
    case 2:
        scene->shake = 1;
        scene->shakePeriod = 0x4000;
        scene->shakeAmp = 0xa000;
        scene->shakeLimit = 6;
        break;
    case 5:
        scene->shake = 2;
        scene->shakePeriod = 0x2000;
        scene->shakeAmp = 0x2000;
        scene->shakeLimit = -1;
        break;
    case 6:
        scene->shake = 2;
        scene->shakePeriod = 0x3000;
        scene->shakeAmp = 0x4000;
        scene->shakeLimit = -1;
        break;
    case 7:
        scene->shake = 2;
        scene->shakePeriod = 0x4000;
        scene->shakeAmp = 0x6000;
        scene->shakeLimit = -1;
        break;
    case 16:
        scene->shakeLimit = 0;
        scene->shake = 0;
        state->unk_18c = 0;
        state->unk_18d = 0;
        state->unk_18e = 0;
        state->unk_18f = 0;
        break;
    }
}

}

}  // namespace m_SceneShake

// ---- Obj3D_2 (at file scope: its member functions keep their mangled names)

// Built at optimization level 3: at O4 the 0xc/0xd/0xe test in func_020528ec
// becomes a range check that the target doesn't have.
#pragma optimization_level 3


class Obj3DAnimCls;
struct Obj3DAnimSlot;

// Per-state handler of an animation slot (pointer to member of the owner).
typedef s32 (Obj3DAnimCls::*Obj3DAnimHandler)(s32 state, struct Obj3DAnimSlot *slot);

// The owner of the animation slots (an Obj3DAnim); its state handlers are members.
class Obj3DAnimCls {
public:
    s32 func_02052628(s32 state, Obj3DAnimSlot *slot);
    s32 func_020528ec(s32 state, Obj3DAnimSlot *slot);
    s32 func_02052bec(s32 state, Obj3DAnimSlot *slot);
};

extern "C" {

extern int func_02043d48(void *obj);
extern s8 data_02149ef4;

void func_02051f3c(Obj3DLayer *layer, u32 v);

void func_020520fc(Obj3DRender *render) {
    GfxSys *sys;
    s32 limit;
    u32 attr;
    u32 alpha;
    Obj3DMtl *mtl;
    mtl = render->mtl;
    attr = mtl->polyAttr;
    alpha = (attr & 0x1f0000) >> 16;
    sys = data_02097d48;
    limit = data_02149ef4;
    if ((u32)limit < alpha) {
        alpha = limit;
    }
    if (alpha > 30) {
        alpha = 30;
    }
    mtl->polyAttr = (attr & 0xc0e0ffbf) | 0xc0 | (alpha << 16) | (func_02043d48(sys->unk_8b0) << 24);
}

void func_02052160(Obj3DRender *render) {
    render->callback = func_020520fc;
    render->callbackMode = 2;
}

// 0x138-byte model resource.
typedef struct Obj3DAnimMdl {
    /* 0x00 */ s16 frame;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 flags;
    /* 0x04 */ u8 unk_04[0xc];
    /* 0x10 */ char arc0[0x20];
    /* 0x30 */ char name0[0x1c];
    /* 0x4c */ char arc1[0x20];
    /* 0x6c */ char name1[0x20];
} Obj3DAnimMdl;

// 0xe8-byte render object.
typedef struct Obj3DAnimObj {
    /* 0x00 */ u8 unk_00[4];
    /* 0x04 */ void *mdl;
    /* 0x08 */ u8 unk_08[0x1c];
    /* 0x24 */ u8 renderObj[0x90];
    /* 0xb4 */ u16 unk_b4;
    /* 0xb6 */ u8 unk_b6[0xc];
    /* 0xc2 */ u16 unk_c2_0 : 5;
    /* 0xc2 */ u16 unk_c2_5 : 1;
    /* 0xc2 */ u16 unk_c2_6 : 10;
} Obj3DAnimObj;

typedef struct Obj3DAnimSlot {
    /* 0x00 */ u32 b0 : 1;
    /* 0x00 */ u32 b1 : 1;
    /* 0x00 */ u32 b2 : 1;
    /* 0x00 */ u32 b3 : 29;
    /* 0x04 */ s32 state;
    /* 0x08 */ u16 idx;
    /* 0x0a */ u16 cur;
    /* 0x0c */ u16 next;
    /* 0x10 */ Obj3DAnimMdl *mdl;
    /* 0x14 */ Obj3DAnimObj *obj;
    /* 0x18 */ Obj3DAnimMdl *oldMdl;
    /* 0x1c */ Obj3DAnimObj *oldObj;
    /* 0x20 */ s32 ofsX;
    /* 0x24 */ s32 ofsY;
    /* 0x28 */ s32 ofsZ;
    /* 0x2c */ u8 unk_2c[0x14];
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ u8 unk_48;
    /* 0x49 */ u8 unk_49[3];
} Obj3DAnimSlot; // size 0x4c

typedef struct Obj3DAnimGroupObj {
    /* 0x00 */ u8 unk_00[0xfc];
    /* 0xfc */ s32 x;
} Obj3DAnimGroupObj;

typedef struct Obj3DAnimGroup {
    /* 0x000 */ u32 unk_00_0 : 22;
    /* 0x000 */ u32 flip : 1;
    /* 0x000 */ u32 unk_00_23 : 9;
    /* 0x004 */ u8 unk_04[4];
    /* 0x008 */ u16 dir;
    /* 0x00a */ u8 unk_0a[0x22];
    /* 0x02c */ Obj3DAnimGroupObj *unk_2c;
    /* 0x030 */ u8 unk_030[0x14];
    /* 0x044 */ Obj3DAnimSlot slots[3];
    /* 0x128 */ u8 unk_128[0x20];
} Obj3DAnimGroup; // size 0x148

typedef struct Obj3DAnim {
    /* 0x000 */ u8 unk_000[0xb8];
    /* 0x0b8 */ u32 unk_b8_0 : 9;
    /* 0x0b8 */ u32 hasExtra : 1;
    /* 0x0b8 */ u32 unk_b8_10 : 22;
    /* 0x0bc */ struct {
        /* 0x000 */ u8 unk_000[0x368];
        /* 0x368 */ Obj3DAnimSlot extra[2];
        /* 0x400 */ Obj3DAnimGroup groups[5];
    } sub;
} Obj3DAnim;

typedef struct Obj3DAnimEnt {
    /* 0x00 */ const char *name;
    /* 0x04 */ u8 flip;
    /* 0x06 */ s16 ofs;
    /* 0x08 */ u8 unk_08[4];
    /* 0x0c */ Obj3DAnimHandler fn;
} Obj3DAnimEnt; // size 0x14

extern const Obj3DAnimEnt data_0208bc80[];
extern const char *data_0208cb80;

extern void *func_0203dd9c(u32 size);
extern void func_0203de1c(void *ptr);
extern BOOL func_0203e688(Obj3DAnimObj *o);
extern char *STD_CopyString(char *dst, const char *src);
extern s32 FX_Div(s32 a, s32 b);
extern Obj3DAnimMdl *func_ov000_0218e9c4(void *p);
extern void func_ov000_0218ea20(void *p);
extern BOOL func_ov000_0218f110(Obj3DAnimMdl *m);
extern Obj3DAnimObj *func_ov000_0218fe1c(void *p);
extern void func_ov000_0218fee4(void *p);
extern void func_ov000_0218ffdc(Obj3DAnimObj *a, Obj3DAnimMdl *b, s32 c, s32 d);
extern void func_ov000_02190a80(Obj3DAnimObj *a, s32 b);
extern void func_ov000_02190cb0(Obj3DAnimObj *a, const char *b, s32 c, s32 d);
extern BOOL func_ov000_02191120(Obj3DAnimObj *a);
extern void func_ov000_021915a0(Obj3DAnimObj *a);
extern void func_ov000_02191618(Obj3DAnimObj *a);
extern void NNS_G3dRenderObjSetInitFunc(void *ro, void (*fn)(Obj3DRender *));
extern void NNSi_G3dModifyPolygonAttrMask(void *mdl, u32 mat, u32 mask);
extern void NNSi_G3dModifyMatFlag(void *mdl, u32 mat, u32 flag);

void func_0205221c(Obj3DAnim *anim, int kind, Obj3DAnimSlot *slot);

void func_02052178(Obj3DAnim *anim) {
    Obj3DAnimGroup *g;
    int i;
    int j;
    if (anim->hasExtra == 1) {
        func_0205221c(anim, 1, &anim->sub.extra[0]);
    }
    for (i = 0; i < 3; i++) {
        g = anim->sub.groups;
        for (j = 0; j < 5; j++, g++) {
            Obj3DAnimSlot *slot = &g->slots[i];
            slot->idx = j;
            func_0205221c(anim, i, slot);
        }
    }
    if (anim->hasExtra == 1) {
        func_0205221c(anim, 2, &anim->sub.extra[1]);
    }

}

static inline Obj3DAnimMdl *AnimMdl_New(void) {
    void *p = func_0203dd9c(0x138);
    if (p != NULL) {
        p = func_ov000_0218e9c4(p);
    }
    return (Obj3DAnimMdl *)p;
}

static inline Obj3DAnimObj *AnimObj_New(void) {
    void *p = func_0203dd9c(0xe8);
    if (p != NULL) {
        p = func_ov000_0218fe1c(p);
    }
    return (Obj3DAnimObj *)p;
}

static inline void AnimMdl_Set0(Obj3DAnimMdl *m, const char *name) {
    STD_CopyString(m->arc0, data_0208cb80);
    STD_CopyString(m->name0, name);
    m->flags |= 2;
}

static inline void AnimMdl_Set1(Obj3DAnimMdl *m, const char *name) {
    STD_CopyString(m->arc1, data_0208cb80);
    STD_CopyString(m->name1, name);
    m->flags |= 4;
}



static inline s32 FxMulL(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

static inline void AnimSlot_DeleteObj(Obj3DAnimSlot *slot) {
    Obj3DAnimObj *p;
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    {
        p = slot->obj;
        if (p != NULL) {
            if (p != NULL) {
                func_ov000_0218fee4(p);
                func_0203de1c(p);
            }
            slot->obj = NULL;
        }
    }
    data_02097dd0->cur = saved;
}

static inline void AnimSlot_DeleteMdl(Obj3DAnimSlot *slot) {
    Obj3DAnimMdl *p;
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    {
        p = slot->mdl;
        if (p != NULL) {
            if (p != NULL) {
                func_ov000_0218ea20(p);
                func_0203de1c(p);
            }
            slot->mdl = NULL;
        }
    }
    data_02097dd0->cur = saved;
}

static inline void AnimSlot_SetupObj(Obj3DAnimSlot *slot) {
    Obj3DAnimObj *o;
    void *mdl;
    slot->obj = AnimObj_New();
    func_ov000_0218ffdc(slot->obj, slot->mdl, 0, 1);
    slot->obj->unk_b4 = 0;
    o = slot->obj;
    NNS_G3dRenderObjSetInitFunc(o->renderObj, func_02052160);
    o->unk_c2_5 = 0;
    func_ov000_02191618(slot->obj);
    mdl = slot->obj->mdl;
    NNSi_G3dModifyPolygonAttrMask(mdl, 1, 0x8000);
    NNSi_G3dModifyPolygonAttrMask(mdl, 1, 0x1f0000);
    NNSi_G3dModifyPolygonAttrMask(mdl, 1, 0x3f000000);
    NNSi_G3dModifyMatFlag(mdl, 1, 0x40);
    NNSi_G3dModifyMatFlag(mdl, 1, 0x80);
    NNSi_G3dModifyMatFlag(mdl, 1, 0x200);
    NNSi_G3dModifyMatFlag(mdl, 1, 0x400);
}


// Sets up the object with animation sequence "s00".
static inline void AnimSlot_SetupObjS00(Obj3DAnimSlot *slot) {
    Obj3DAnimObj *o;
    void *mdl;
    slot->obj = AnimObj_New();
    func_ov000_0218ffdc(slot->obj, slot->mdl, 0, 1);
    func_ov000_02190cb0(slot->obj, "s00", 0, 1);
    slot->obj->unk_b4 = 0;
    o = slot->obj;
    NNS_G3dRenderObjSetInitFunc(o->renderObj, func_02052160);
    o->unk_c2_5 = 0;
    func_ov000_02191618(slot->obj);
    mdl = slot->obj->mdl;
    NNSi_G3dModifyPolygonAttrMask(mdl, 1, 0x8000);
    NNSi_G3dModifyPolygonAttrMask(mdl, 1, 0x1f0000);
    NNSi_G3dModifyPolygonAttrMask(mdl, 1, 0x3f000000);
    NNSi_G3dModifyMatFlag(mdl, 1, 0x40);
    NNSi_G3dModifyMatFlag(mdl, 1, 0x80);
    NNSi_G3dModifyMatFlag(mdl, 1, 0x200);
    NNSi_G3dModifyMatFlag(mdl, 1, 0x400);
}


static inline s32 AnimSlot_Call(Obj3DAnim *anim, Obj3DAnimSlot *slot, u16 id, s32 state) {
    return (((Obj3DAnimCls *)anim)->*data_0208bc80[id].fn)(state, slot);
}

static inline void AnimSlot_DeleteOldObj(Obj3DAnimSlot *slot) {
    Obj3DAnimObj *p;
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    {
        p = slot->oldObj;
        if (p != NULL) {
            if (p != NULL) {
                func_ov000_0218fee4(p);
                func_0203de1c(p);
            }
            slot->oldObj = NULL;
        }
    }
    data_02097dd0->cur = saved;
}

static inline void AnimSlot_DeleteOldMdl(Obj3DAnimSlot *slot) {
    Obj3DAnimMdl *p;
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    {
        p = slot->oldMdl;
        if (p != NULL) {
            if (p != NULL) {
                func_ov000_0218ea20(p);
                func_0203de1c(p);
            }
            slot->oldMdl = NULL;
        }
    }
    data_02097dd0->cur = saved;
}

static inline void AnimSlot_Start(Obj3DAnim *anim, Obj3DAnimSlot *slot) {
    if (slot->next == 0xffff) {
        AnimSlot_DeleteObj(slot);
        AnimSlot_DeleteMdl(slot);
    } else {
        slot->oldMdl = slot->mdl;
        slot->mdl = NULL;
        slot->oldObj = slot->obj;
        slot->obj = NULL;
        slot->state = 0;
    }
    slot->unk_44 = 0;
    slot->unk_48 = 0x1e;
    slot->cur = slot->next;
    slot->next = 0xffff;
    slot->b1 = 0;
    AnimSlot_Call(anim, slot, slot->cur, 7);
}

void func_0205221c(Obj3DAnim *anim, int kind, Obj3DAnimSlot *slot) {
    if (slot->b2 == 1) {
        AnimSlot_Call(anim, slot, slot->next, 5);
        slot->b2 = 0;
    }
    if (slot->mdl != NULL) {
        func_ov000_0218f110(slot->mdl);
        if (slot->mdl->frame < 0) {
            if (slot->obj == NULL) {
                AnimSlot_Call(anim, slot, slot->next, 6);
            } else if (func_0203e688(slot->obj)) {
                slot->b1 = 1;
            }
        }
    }
    if (slot->cur == 0xffff) {
        if (!slot->b1) {
            return;
        }
        AnimSlot_Start(anim, slot);
    }
    if (kind == 0 && anim->sub.groups[slot->idx].unk_2c == NULL) {
        return;
    }
    if (slot->oldObj == NULL) {
        return;
    }
    slot->state = (((Obj3DAnimCls *)anim)->*data_0208bc80[slot->cur].fn)(slot->state, slot);
    if (slot->state == 8) {
        AnimSlot_DeleteOldObj(slot);
        AnimSlot_DeleteOldMdl(slot);
        slot->cur = 0xffff;
        if (slot->b1) {
            AnimSlot_Start(anim, slot);
        }
    }
    slot->unk_40 += 0x1000;
}

s32 Obj3DAnimCls::func_02052628(s32 state, Obj3DAnimSlot *slot) {
    const char *name;
    switch (state) {
    case 5: {
        const Obj3DAnimEnt *ent = &data_0208bc80[slot->next];
        Obj3DAnimMdl *m;
        AnimSlot_DeleteObj(slot);
        AnimSlot_DeleteMdl(slot);
        m = AnimMdl_New();
        slot->mdl = m;
        name = ent->name;
        AnimMdl_Set0(m, name);
        AnimMdl_Set1(slot->mdl, ent->name);
        slot->mdl->frame = 0;
        if (slot->oldObj != NULL) {
            slot->state = 2;
        }
        return state;
    }
    case 6:
        AnimSlot_SetupObjS00(slot);
        return state;
    case 0:
        if (func_ov000_02191120(slot->oldObj)) {
            state = 1;
            func_ov000_02190cb0(slot->oldObj, "s01", 0, 1);
            func_ov000_021915a0(slot->oldObj);
        }
        break;
    case 1:
        slot->unk_44 += 0x1000;
        break;
    case 2:
    case 4:
        state = 8;
        break;
    }
    func_ov000_02190a80(slot->oldObj, 0x1000);
    return state;
}


s32 Obj3DAnimCls::func_020528ec(s32 state, Obj3DAnimSlot *slot) {
    s32 r;
    switch (state) {
    case 5: {
        const Obj3DAnimEnt *ent = &data_0208bc80[slot->next];
        Obj3DAnimMdl *m;
        AnimSlot_DeleteObj(slot);
        AnimSlot_DeleteMdl(slot);
        m = AnimMdl_New();
        slot->mdl = m;
        AnimMdl_Set0(m, ent->name);
        slot->mdl->frame = 0;
        if (slot->oldObj != NULL) {
            slot->state = 2;
        }
        return state;
    }
    case 6:
        AnimSlot_SetupObj(slot);
        return state;
    case 7:
        slot->unk_48 = 0;
        return state;
    case 0:
        slot->unk_44 += 0x1000;
        r = FX_Div(slot->unk_44, 0x8000);
        if (r >= 0x1000) {
            r = 0x1000;
            state = 1;
        }
        slot->unk_48 = FxMulL(r, 0x1e000) >> 12;
        break;
    case 1:
        if (slot->cur == 0xc || slot->cur == 0xd || slot->cur == 0xe) {
            slot->unk_48 = 0x1e;
        }
        break;
    case 2:
        slot->unk_44 = 0;
        state = 3;
    case 3:
        slot->unk_44 += 0x1000;
        r = FX_Div(slot->unk_44, 0x8000);
        if (r >= 0x1000) {
            r = 0x1000;
            state = 4;
        }
        slot->unk_48 = FxMulL(0x1000 - r, 0x1e000) >> 12;
        break;
    case 4:
        state = 8;
        break;
    }
    func_ov000_02190a80(slot->oldObj, 0x1000);
    return state;
}


static inline s32 AnimGroup_OfsX(Obj3DAnimGroup *g, const Obj3DAnimEnt *ent) {
    s32 x = g->unk_2c->x;
    s32 ofs = ent->ofs;
    if (g->dir == 0x1000) {
        if (g->flip) {
            x = ent->flip ? x - (ofs << 12) : x + (ofs << 12);
        } else {
            x += ofs << 12;
        }
    } else {
        if (g->flip) {
            x -= ofs << 12;
        } else {
            x = ent->flip ? x - (ofs << 12) : x + (ofs << 12);
        }
    }
    return x;
}

static inline void AnimSlot_CalcOfs(Obj3DAnimSlot *slot, Obj3DAnimGroup *g, const Obj3DAnimEnt *ent) {
    if (g->unk_2c != NULL) {
        slot->ofsX = AnimGroup_OfsX(g, ent);
    }
}

s32 Obj3DAnimCls::func_02052bec(s32 state, Obj3DAnimSlot *slot) {
    Obj3DAnim *anim = (Obj3DAnim *)this;
    const char *name;
    s32 r;
    BOOL is10 = FALSE;
    if (slot->cur == 0x10) {
        is10 = TRUE;
    }
    slot->ofsX = 0;
    slot->ofsY = 0;
    slot->ofsZ = 0;
    if (is10) {
        AnimSlot_CalcOfs(slot, &anim->sub.groups[slot->idx], &data_0208bc80[slot->cur]);
    }
    switch (state) {
    case 5: {
        const Obj3DAnimEnt *ent = &data_0208bc80[slot->next];
        Obj3DAnimMdl *m;
        AnimSlot_DeleteObj(slot);
        AnimSlot_DeleteMdl(slot);
        m = AnimMdl_New();
        slot->mdl = m;
        name = ent->name;
        AnimMdl_Set0(m, name);
        AnimMdl_Set1(slot->mdl, ent->name);
        slot->mdl->frame = 0;
        if (slot->oldObj != NULL) {
            slot->state = 2;
        }
        return state;
    }
    case 6: {
        Obj3DAnimObj *o;
        void *mdl;
        slot->obj = AnimObj_New();
        func_ov000_0218ffdc(slot->obj, slot->mdl, 0, 1);
        func_ov000_02190cb0(slot->obj, "s01", 0, 1);
        slot->obj->unk_b4 = 0;
        o = slot->obj;
        NNS_G3dRenderObjSetInitFunc(o->renderObj, func_02052160);
        o->unk_c2_5 = 0;
        func_ov000_021915a0(slot->obj);
        mdl = slot->obj->mdl;
        NNSi_G3dModifyPolygonAttrMask(mdl, 1, 0x8000);
        NNSi_G3dModifyPolygonAttrMask(mdl, 1, 0x1f0000);
        NNSi_G3dModifyPolygonAttrMask(mdl, 1, 0x3f000000);
        NNSi_G3dModifyMatFlag(mdl, 1, 0x40);
        NNSi_G3dModifyMatFlag(mdl, 1, 0x80);
        NNSi_G3dModifyMatFlag(mdl, 1, 0x200);
        NNSi_G3dModifyMatFlag(mdl, 1, 0x400);
        return state;
    }
    case 7:
        slot->unk_48 = 0;
        return state;
    case 0:
        slot->unk_44 += 0x1000;
        r = FX_Div(slot->unk_44, 0x8000);
        if (r >= 0x1000) {
            r = 0x1000;
            state = 1;
        }
        slot->unk_48 = FxMulL(r, 0x1e000) >> 12;
        break;
    case 1:
        slot->unk_48 = 0x1e;
        slot->unk_44 += 0x1000;
        break;
    case 2:
        slot->unk_44 = 0;
        state = 3;
    case 3:
        slot->unk_44 += 0x1000;
        r = FX_Div(slot->unk_44, 0x8000);
        if (r >= 0x1000) {
            r = 0x1000;
            state = 4;
        }
        slot->unk_48 = FxMulL(0x1000 - r, 0x1e000) >> 12;
        break;
    case 4:
        state = 8;
        break;
    }
    func_ov000_02190a80(slot->oldObj, 0x1000);
    return state;
}

s32 func_020534c4(s32 x);

s32 func_020534d4(void);


}
