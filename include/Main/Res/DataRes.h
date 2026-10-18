#ifndef MAIN_RES_DATARES_H
#define MAIN_RES_DATARES_H

#include "types.h"
#include "Main/Res/ResMgr.h"

// Resource handle holding a raw data file (same base as MsgRes: vtable data_0208b318).
// The vtables stay in asm.
struct DataRes {
    /* 0x00 */ // vtable
    virtual void unk_vf00();
    virtual DataRes *DeletingDtor();
    virtual void Clear();
    virtual void Unload();
    virtual void **GetData();
    virtual void unk_vf14();
    virtual void Open18(char *arcName, char *name);
    virtual void unk_vf1c();
    virtual void unk_vf20();
    virtual void Open(char *arcName, char *name);
    virtual void unk_vf28();
    virtual BOOL IsLoaded();
    /* 0x04 */ char arcName[0x20];
    /* 0x24 */ char name[0x20];
    /* 0x44 */ int type;
    /* 0x48 */ u8 loaded;
    /* 0x4c */ u8 *data;
    /* 0x50 */ u8 *end;
    /* 0x54 */ u32 unk_54;
};

// Data resource with "TPOS"/"TEVP" chunks (same base as DataRes).
struct PosEvRes {
    /* 0x00 */ // vtable
    virtual void unk_vf00();
    virtual PosEvRes *DeletingDtor();
    virtual void Clear();
    virtual void Unload();
    virtual void **GetData();
    virtual void unk_vf14();
    virtual void Open18(char *arcName, char *name);
    virtual void unk_vf1c();
    virtual void unk_vf20();
    virtual void Open(char *arcName, char *name);
    virtual void unk_vf28();
    virtual BOOL IsLoaded();
    /* 0x04 */ char arcName[0x20];
    /* 0x24 */ char name[0x20];
    /* 0x44 */ int type;
    /* 0x48 */ u8 loaded;
    /* 0x4c */ u32 posCount;
    /* 0x50 */ u8 *pos;
    /* 0x54 */ u32 evCount;
    /* 0x58 */ u8 *ev;
};

typedef struct SaveEntry {
    /* 0x00 */ u16 bit;
    /* 0x02 */ u16 id;
} SaveEntry;

typedef struct SaveBlock {
    /* 0x00 */ u8 unk_00[8];
    /* 0x08 */ u32 offset;
    /* 0x0c */ u32 bits;
    /* 0x10 */ u32 tableOffset;
    /* 0x14 */ u32 count;
    /* 0x18 */ u8 unk_18[8];
} SaveBlock;

typedef struct SaveLayout {
    /* 0x00 */ u8 unk_00[0xc];
    /* 0x0c */ u32 count;
    /* 0x10 */ SaveBlock blocks[1];
} SaveLayout;

typedef struct SaveRef {
    /* 0x00 */ u32 idx;
    /* 0x04 */ u16 unk_04;
    /* 0x08 */ SaveBlock *block;
    /* 0x0c */ SaveEntry *table;
    /* 0x10 */ u32 count;
} SaveRef;

extern "C" {

extern const u32 data_0208b318[];
extern void *func_0203dd9c(u32 size);
extern void func_0203de1c(void *ptr);
extern void func_0206e900(char *dst, const char *src);

}

#endif
