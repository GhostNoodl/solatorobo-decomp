#include "Main/Res/DataRes.h"
#include "Main/Gfx/TextWin.h"

extern "C" {

extern const u32 TextWin_vtbl[];
extern const u32 MainVt_0208bbc8_vtbl[];
extern const u32 TextWinEx_vtbl[];
extern const u32 MainVt_0208bf14_vtbl[];
extern const u32 MainVt_0208be94_vtbl[];
extern DataRes *gStageDataRes;
extern DataRes *gDataRes;

void TextWin_SetModelPos(TextWin *win, s16 a, s16 b, s16 c) {
    win->modelX = a;
    win->flag28 = 1;
    win->modelY = b;
    win->unk_1e = c;
}

void TextWin_DisableAlpha(TextWin *win) {
    win->flag5 = 0;
}

static inline BOOL TextWin_IsFlag29(TextWin *win) {
    return win->flag29 == 1 ? TRUE : FALSE;
}

BOOL TextWin_WasSkipped(TextWin *win) {
    return TextWin_IsFlag29(win) ? TRUE : FALSE;
}

TextWin *MainVt_0208bbc8_DtorDelete(TextWin *win) {
    *(const u32 **)win = MainVt_0208bbc8_vtbl;
    win->unk_vf08();
    *(const u32 **)win = TextWin_vtbl;
    win->unk_vf08();
    Heap_Free(win);
    return win;
}

TextWin *MainVt_0208bbc8_Dtor(TextWin *win) {
    *(const u32 **)win = MainVt_0208bbc8_vtbl;
    win->unk_vf08();
    *(const u32 **)win = TextWin_vtbl;
    win->unk_vf08();
    return win;
}

TextWin *TextWinEx_DtorDelete(TextWin *win) {
    *(const u32 **)win = TextWinEx_vtbl;
    win->unk_vf08();
    *(const u32 **)win = TextWin_vtbl;
    win->unk_vf08();
    Heap_Free(win);
    return win;
}

void TextWinEx_SetPos(TextWinEx *win, s16 x, s16 y) {
    win->originX = x;
    win->originY = y;
}

TextWin *TextWinEx_Dtor(TextWin *win) {
    *(const u32 **)win = TextWinEx_vtbl;
    win->unk_vf08();
    *(const u32 **)win = TextWin_vtbl;
    win->unk_vf08();
    return win;
}

static inline void DataRes_Reset(DataRes *res) {
    res->type = 0;
    res->data = NULL;
    res->end = NULL;
    res->unk_54 = 0;
}

DataRes *MainVt_0208ba30_Dtor(DataRes *res) {
    DataRes_Reset(res);
    *(const u32 **)res = ResHandle_vtbl;
    res->Unload();
    return res;
}

static inline DataRes *DataRes_New(u32 size, const u32 *vtbl) {
    DataRes *res = (DataRes *)Heap_Alloc(size);
    if (res != NULL) {
        *(const u32 **)res = ResHandle_vtbl;
        res->Clear();
        *(const u32 **)res = vtbl;
        res->Clear();
    }
    return res;
}

static inline void DataRes_Open152c(const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    LangData_LocalizePath(arc, arcName);
    LangData_LocalizePath(file, name);
    gDataRes->Open(arc, file);
}

static inline void DataRes_Open1530(const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    LangData_LocalizePath(arc, arcName);
    LangData_LocalizePath(file, name);
    gStageDataRes->Open(arc, file);
}

static inline void DataRes_Open1530_18(const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    LangData_LocalizePath(arc, arcName);
    LangData_LocalizePath(file, name);
    gStageDataRes->Open18(arc, file);
}

void DataRes1530_Create(BOOL open18);

}
