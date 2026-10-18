#include "Main/Res/MsgRes.h"
#include "Main/Res/ResMgr.h"

extern "C" {

void *data_02149ef4;
MsgRes *data_02149ef8;
#define MSG_RES data_02149ef8

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

void func_0204c08c(MsgRes *res, s32 idx, char **out, s32 max);

char *func_0204c0e8(MsgRes *res, s32 idx) {
    return res->strings + (res->entries[idx] & ~0xff000000);
}

void func_0204c100(void) {
    MSG_RES->unk_vf2c();
}

BOOL func_0204c120(void) {
    return func_0204c030(MSG_RES);
}

#pragma force_active on
void func_0204c138(void) {
    MSG_RES->unk_vf34();
}
#pragma force_active reset

void func_0204c158(void);

void func_0204c214(void);

void *func_0204c270(void);

void func_0204c284(void);

MsgRes *func_0204c29c(MsgRes *res);

void func_0204c2e0(void *heap);

}
