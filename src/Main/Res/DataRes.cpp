#include "Main/Res/DataRes.h"
#include "Main/Gfx/TextWin.h"

extern "C" {

extern const u32 data_0208ba70[];
extern const u32 data_0208bbc8[];
extern const u32 data_0208bb1c[];
extern const u32 data_0208bf14[];
extern const u32 data_0208be94[];
extern const char data_0208bdf6[];
extern const char data_0208bdec[];
extern const char data_0208be0d[];
extern DataRes *data_02fe1530;
extern DataRes *data_02fe152c;

void func_02058b50(TextWin *win, s16 a, s16 b, s16 c) {
    win->unk_1a = a;
    win->flag28 = 1;
    win->unk_1c = b;
    win->unk_1e = c;
}

void func_02058b6c(TextWin *win) {
    win->flag5 = 0;
}

static inline BOOL TextWin_IsFlag29(TextWin *win) {
    return win->flag29 == 1 ? TRUE : FALSE;
}

BOOL func_02058b7c(TextWin *win) {
    return TextWin_IsFlag29(win) ? TRUE : FALSE;
}

TextWin *func_02058ba4(TextWin *win) {
    *(const u32 **)win = data_0208bbc8;
    win->unk_vf08();
    *(const u32 **)win = data_0208ba70;
    win->unk_vf08();
    func_0203de1c(win);
    return win;
}

TextWin *func_02058bf0(TextWin *win) {
    *(const u32 **)win = data_0208bbc8;
    win->unk_vf08();
    *(const u32 **)win = data_0208ba70;
    win->unk_vf08();
    return win;
}

TextWin *func_02058c34(TextWin *win) {
    *(const u32 **)win = data_0208bb1c;
    win->unk_vf08();
    *(const u32 **)win = data_0208ba70;
    win->unk_vf08();
    func_0203de1c(win);
    return win;
}

void func_02058c80(TextWinEx *win, s16 x, s16 y) {
    win->originX = x;
    win->originY = y;
}

TextWin *func_02058c90(TextWin *win) {
    *(const u32 **)win = data_0208bb1c;
    win->unk_vf08();
    *(const u32 **)win = data_0208ba70;
    win->unk_vf08();
    return win;
}

static inline void DataRes_Reset(DataRes *res) {
    res->type = 0;
    res->data = NULL;
    res->end = NULL;
    res->unk_54 = 0;
}

DataRes *func_02058cd4(DataRes *res) {
    DataRes_Reset(res);
    *(const u32 **)res = data_0208b318;
    res->Unload();
    return res;
}

static inline DataRes *DataRes_New(u32 size, const u32 *vtbl) {
    DataRes *res = (DataRes *)func_0203dd9c(size);
    if (res != NULL) {
        *(const u32 **)res = data_0208b318;
        res->Clear();
        *(const u32 **)res = vtbl;
        res->Clear();
    }
    return res;
}

static inline void DataRes_Open152c(const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    func_0206e900(arc, arcName);
    func_0206e900(file, name);
    data_02fe152c->Open(arc, file);
}

static inline void DataRes_Open1530(const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    func_0206e900(arc, arcName);
    func_0206e900(file, name);
    data_02fe1530->Open(arc, file);
}

static inline void DataRes_Open1530_18(const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    func_0206e900(arc, arcName);
    func_0206e900(file, name);
    data_02fe1530->Open18(arc, file);
}

void func_02058d10(BOOL open18);

}
