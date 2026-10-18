#define SND_DEFINE_GLOBALS
#include "Main/Gfx/TextWin.h"
#include "Main/Snd/SndMgr.h"

// Base of the text layout helper; its vtable stays in asm.
struct TextLayout {
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void Clear();
};

extern "C" {

extern const u32 data_0208ba70[];
extern void (*data_0208afd8)(void *p);
extern void (*data_0208afe0)(void *p);

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

extern const char data_0208b9f5[];
extern const char data_0208b9fb[];
extern const char data_0208ba01[];
extern const char data_0208ba05[];
extern const char data_0208ba0c[];
extern const char data_0208ba12[];

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
    func_0201e520(model->name, name);
    return model;
}

}

struct TextModel : Model {
    TextModel(const char *name, const char *file, int a) {
        func_02041218(pltt);
        func_02041440(this, file, a);
        func_0201e520(this->name, name);
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
        tex = func_02023410(res->texRes, ***(u16 ***)((u8 *)func_02023390(res->mdlRes, idx) + 0xc));
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

extern void func_0202a3ec(int cmd, const void *data, int count);
extern void *func_0203972c(void *blocks, u32 count);
extern s32 func_0204f804(TextWinEx *win);
extern s32 data_02097d78[];

u8 *func_0204f354(void) {
    return data_02097d48->unk_8b0;
}

void func_0204f368(int light, int polyMode, int cullMode, int polygonId, int alpha, int misc) {
    u32 data = light | (polyMode << 4) | (cullMode << 6) | misc | (polygonId << 24) | (alpha << 16);
    func_0202a3ec(0x29, &data, 1);
}

void func_0204f3a0(int texFmt, int texGen, int s, int t, int repeat, int flip, int pltt0, u32 addr) {
    u32 data = (addr >> 3) | (texFmt << 26) | (texGen << 30) | (s << 20) | (t << 23) | (repeat << 16) | (flip << 18) | (pltt0 << 29);
    func_0202a3ec(0x2a, &data, 1);
}

void func_0204f3ec(void) {
    func_0202a3ec(0x11, NULL, 0);
}

void func_0204f404(s32 x, s32 y, s32 z) {
    s32 data[3];
    data[0] = x;
    data[1] = y;
    data[2] = z;
    func_0202a3ec(0x1c, data, 3);
}

void func_0204f430(s32 x, s32 y, s32 z) {
    s32 data[3];
    data[0] = x;
    data[1] = y;
    data[2] = z;
    func_0202a3ec(0x1b, data, 3);
}

void func_0204f45c(u32 color) {
    u32 data = color;
    func_0202a3ec(0x20, &data, 1);
}

void func_0204f478(s32 num, ...) {
    func_0202a3ec(0x12, &num, 1);
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
