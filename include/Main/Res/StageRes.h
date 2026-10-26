#ifndef MAIN_RES_STAGERES_H
#define MAIN_RES_STAGERES_H

#include "types.h"
#include "Main/Res/DataRes.h"
#include "Main/Gfx/ObjPool.h"

// Resource handle (ResHandle base) bundling a sub resource and a TPOS/TEVP data resource.
struct StageRes {
    /* 0x00 */ // vtable
    virtual void unk_vf00();
    virtual StageRes *DeletingDtor();
    virtual void Clear();
    virtual void Unload();
    virtual void **GetData();
    virtual void unk_vf14();
    virtual void unk_vf18();
    virtual void unk_vf1c();
    virtual void unk_vf20();
    virtual void unk_vf24();
    virtual void unk_vf28();
    virtual BOOL IsLoaded();
    virtual void unk_vf30();
    virtual void unk_vf34();
    virtual void unk_vf38();
    virtual u16 unk_vf3c(u16 *cmd);
    virtual u16 Eval(u16 *cmd, int mode, u16 val);
    virtual u16 unk_vf44(u16 *cmd);
    /* 0x04 */ char arcName[0x20];
    /* 0x24 */ char name[0x20];
    /* 0x44 */ int type;
    /* 0x48 */ u8 loaded;
    /* 0x4c */ u8 *data;
    /* 0x50 */ u32 size;
    /* 0x54 */ u32 unk_54;
    /* 0x58 */ u8 unk_58;
    /* 0x59 */ u8 unk_59;
    /* 0x5a */ u8 unk_5a;
    /* 0x5b */ u8 unk_5b;
    /* 0x5c */ u16 value;
    /* 0x5e */ u8 condStack[0x10];
    /* 0x6e */ u16 condCount;
    /* 0x70 */ u16 opStack[0x10];
    /* 0x90 */ u16 opCount;
    /* 0x92 */ u16 blockStack[0x10];
    /* 0xb2 */ u16 unk_b2;
    /* 0xb4 */ u16 *varId;
    /* 0xb8 */ u16 op;
    /* 0xbc */ DataRes *sub;
    /* 0xc0 */ PosEvRes *posEv;
};

typedef struct StageResSlot {
    /* 0x00 */ StageRes *res;
    /* 0x04 */ union {
        u16 unk_04;
        struct {
            u16 unk_04_0 : 8;
            u16 flag8 : 1;
            u16 flag9 : 1;
            u16 unk_04_10 : 6;
        } bits;
    };
    /* 0x06 */ u16 id;
    /* 0x08 */ u16 args[6];
} StageResSlot;

extern "C" {

extern StageResSlot data_02149f18[0x40];
extern const u32 data_0208b318[];
extern const u32 data_0208ba30[];
extern const u32 data_0208bed4[];
extern const char data_0208be17[];
extern const char data_0208be19[];
extern const char data_0208be20[];
extern void func_02038520(StageRes *res);
extern void func_02038b88(StageRes *res, char *arcName, char *name);
extern char *STD_CopyString(char *dst, const char *src);
extern char *STD_SearchString(char *str, const char *sub);
extern void func_0206e900(char *dst, const char *src);
extern void func_0204bfcc(DataRes *res);
extern void func_0204bfe4(DataRes *res, const char *arcName, char *name);
extern void func_0204c030(DataRes *res);
extern BOOL func_02059784(PosEvRes *res);
extern int (*data_0208bde8)(StageResSlot *slot);
extern int func_0205bef8(StageResSlot *slot);
extern DataRes *data_02fe152c;

extern void MI_CpuFill8(void *dst, u32 value, u32 size);

static inline void Slot_Init(StageResSlot *slot) {
    s8 j;
    slot->res = NULL;
    slot->unk_04 = 0;
    slot->id = 0x81;
    for (j = 0; j < 6; j++) {
        slot->args[j] = 0;
    }
}

static inline StageResSlot *Slot_Alloc(void) {
    s32 end = data_02149f04;
    StageResSlot *slot = &data_02149f18[end];
    data_02149f04 = end + 1;
    if (data_02149f04 >= 0x40) {
        data_02149f04 = 0;
    }
    Slot_Init(slot);
    return slot;
}

static inline StageResSlot *StageRes_Peek(void) {
    if (data_02149f14 == data_02149f04) {
        return NULL;
    }
    return &data_02149f18[data_02149f14];
}

static inline void StageRes_Pop(void) {
    if (data_02149f14 == data_02149f04) {
        return;
    }
    data_02149f14++;
    if (data_02149f14 >= 0x40) {
        data_02149f14 = 0;
    }
}

static inline StageResSlot *StageRes_Last(void) {
    s32 end = data_02149f04;
    if (data_02149f14 == end) {
        return NULL;
    }
    end -= 1;
    if (end < 0) {
        end += 0x40;
    }
    return &data_02149f18[end];
}

}

#endif
