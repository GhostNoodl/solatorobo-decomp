#ifndef MAIN_RES_MSGRES_H
#define MAIN_RES_MSGRES_H

#include "types.h"

// Resource handle holding a message (text) archive. The vtables stay in asm:
// data_0208b318 (base resource handle) and data_0208ba30 (message resource).
struct MsgRes {
    /* 0x00 */ // vtable
    virtual void unk_vf00();
    virtual MsgRes *DeletingDtor();
    virtual void Clear();
    virtual void Unload();
    virtual void **GetData();
    virtual void unk_vf14();
    virtual void unk_vf18();
    virtual void unk_vf1c();
    virtual void unk_vf20();
    virtual void Open(char *arcName, char *name);
    virtual void unk_vf28();
    virtual void unk_vf2c();
    virtual void unk_vf30();
    virtual void unk_vf34();
    /* 0x04 */ char arcName[0x20];
    /* 0x24 */ char name[0x20];
    /* 0x44 */ int type;
    /* 0x48 */ u8 loaded;
    /* 0x4c */ u32 *entries;
    /* 0x50 */ u32 numEntries;
    /* 0x54 */ char *strings;
};

#ifdef __cplusplus
extern "C" {
#endif

extern const u32 data_0208b318[];
extern const u32 data_0208ba30[];

#ifdef __cplusplus
}
#endif

#endif
