#include "Main/Res/MsgRes.h"
#include "Main/Res/ResMgr.h"

extern "C" {

// Defined as two globals in the message resource TU.
extern struct {
    void *unk_00;
    MsgRes *res;
} data_02149ef4;
#define MSG_RES data_02149ef4.res

extern const char data_0208b9dc[];
extern const char data_0208b9e6[];

extern void *func_0203dd9c(u32 size);
extern void func_0203de1c(void *ptr);
extern void func_0206e900(char *dst, const char *src);

static inline void MsgRes_Reset(MsgRes *res) {
    res->type = 0;
    res->entries = NULL;
    res->numEntries = 0;
    res->strings = NULL;
}

void func_0204bfcc(MsgRes *res) {
    MsgRes_Reset(res);
}

static inline void MsgRes_OpenFile(MsgRes *res, const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    func_0206e900(arc, arcName);
    func_0206e900(file, name);
    res->Open(arc, file);
}

void func_0204bfe4(MsgRes *res, const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    func_0206e900(arc, arcName);
    func_0206e900(file, name);
    res->Open(arc, file);
}

BOOL func_0204c030(MsgRes *res) {
    u8 *data;
    u8 *hdr;
    if (res->loaded) {
        return TRUE;
    }
    data = *(u8 **)res->GetData();
    hdr = data + *(u32 *)(data + 4);
    res->entries = (u32 *)(hdr + *(u32 *)hdr);
    res->numEntries = *(u32 *)(hdr + 0xc);
    res->strings = (char *)(hdr + *(u32 *)(hdr + 8));
    res->loaded = TRUE;
    return TRUE;
}

u32 func_0204c08c(MsgRes *res, s32 idx, char **out, s32 max) {
    u32 e = res->entries[idx];
    s32 i = 0;
    u32 n = (e & 0xff000000) >> 24;
    char *str = res->strings + (e & ~0xff000000);
    for (; i < n; i++) {
        if (i < max) {
            out[i] = str;
        }
        while (*str != 0) {
            str++;
        }
        str++;
    }
    return n;
}

char *func_0204c0e8(MsgRes *res, s32 idx);

BOOL func_0204c100(void);

BOOL func_0204c120(void);

void func_0204c138(void);

void func_0204c158(void);

void func_0204c214(void);

void *func_0204c270(void);

void func_0204c284(void);

MsgRes *func_0204c29c(MsgRes *res);

void func_0204c2e0(void *heap);

}
