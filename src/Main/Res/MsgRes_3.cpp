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

char *func_0204c0e8(MsgRes *res, s32 idx);

void func_0204c100(void);

BOOL func_0204c120(void);

void func_0204c138(void);

void func_0204c158(void);

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
