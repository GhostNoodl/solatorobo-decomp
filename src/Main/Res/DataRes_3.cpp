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

static inline BOOL TextWin_IsFlag29(TextWin *win) {
    return win->flag29 == 1 ? TRUE : FALSE;
}

static inline void DataRes_Reset(DataRes *res) {
    res->type = 0;
    res->data = NULL;
    res->end = NULL;
    res->unk_54 = 0;
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

void func_02058fe4(void) {
    void *heap = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    if (data_02fe152c != NULL) {
        if (data_02fe152c != NULL) {
            data_02fe152c->DeletingDtor();
        }
        data_02fe152c = NULL;
    }
    data_02097dd0->cur = heap;
}

DataRes *func_02059040(DataRes *res) {
    *(const u32 **)res = data_0208be94;
    res->Unload();
    *(const u32 **)res = data_0208b318;
    res->Unload();
    func_0203de1c(res);
    return res;
}

void func_0205908c(DataRes *res) {
    res->type = 0;
    res->data = NULL;
}

void func_0205909c(DataRes *res) {
    res->Clear();
}

BOOL func_020590b0(DataRes *res) {
    if (res->loaded) {
        return TRUE;
    }
    res->data = *(u8 **)res->GetData();
    res->loaded = TRUE;
    return TRUE;
}


extern void MI_CpuFill8(void *dst, u32 value, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

u32 func_020590e8(DataRes *res, u8 *buf, u32 size) {
    SaveLayout *layout;
    u32 n;
    u32 pos;
    SaveBlock *b;
    u32 i;
    u8 *src;
    layout = (SaveLayout *)res->data;
    pos = 0;
    MI_CpuFill8(buf, 0, size);
    buf[pos++] = layout->count;
    for (i = 0; i < layout->count; i++) {
        b = &layout->blocks[i];
        n = ((b->bits + 7) & ~7) >> 3;
        if (pos + 2 < size) {
            buf[pos] = ((u8 *)&n)[0];
            buf[pos + 1] = ((u8 *)&n)[1];
        }
        pos += 2;
        src = (u8 *)layout->blocks + b->offset;
        if (pos + n < size) {
            MI_CpuCopy8(src, buf + pos, n);
        }
        pos += n;
    }
    return (pos + 1) & ~1;
}

u32 func_020591a4(DataRes *res, u8 *buf, BOOL keepSome) {
    SaveLayout *layout;
    u32 pos;
    u32 i;
    u32 n;
    u32 count;
    u8 stored;
    BOOL copy;
    layout = (SaveLayout *)res->data;
    pos = 0;
    count = layout->count;
    stored = buf[pos++];
    if (stored <= count) {
        count = stored;
    }
    for (i = 0; i < count; i++) {
        SaveBlock *b = &layout->blocks[i];
        u16 tmp;
        u32 bytes;
        u8 *dst;
        ((u8 *)&tmp)[0] = buf[pos];
        ((u8 *)&tmp)[1] = buf[pos + 1];
        bytes = ((b->bits + 7) & ~7) >> 3;
        pos += 2;
        n = tmp;
        if (n >= bytes) {
            n = bytes;
        }
        copy = TRUE;
        dst = (u8 *)layout->blocks + b->offset;
        if (keepSome && (i == 0 || i == 2 || i == 1 || i == 5)) {
            copy = FALSE;
        }
        if (copy) {
            MI_CpuCopy8(buf + pos, dst, n);
        }
        pos += n;
    }
    return (pos + 1) & ~1;
}

}
