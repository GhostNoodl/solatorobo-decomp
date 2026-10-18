#ifndef MAIN_SAVE_GAMESAVE_H
#define MAIN_SAVE_GAMESAVE_H

#include "Main/Save/SaveBase.h"
#include "Main/Res/StageCmd.h"

// Game progress save (one slot holding a StageFlags image).

typedef struct GameSaveSlot {
    /* 0x00 */ u32 saveCount;
    /* 0x04 */ u32 frameCount;
    /* 0x08 */ u32 unk_08;
    /* 0x0c */ u32 unk_0c_0 : 8;
    /* 0x0c */ u32 unk_0c_8 : 8;
    /* 0x0c */ u32 unk_0c_16 : 8;
    /* 0x0c */ u32 unk_0c_24 : 4;
    /* 0x0c */ u32 unk_0c_28 : 4;
} GameSaveSlot; // size 0x10

struct GameSave : public SaveBase {
    virtual void vf74();
    virtual void vf78();
    /* 0x48 */ union {
        u32 flags;
        struct {
            u32 active : 1;
            u32 flag1 : 1;
            u32 flag2 : 1;
            u32 flag3 : 1;
            u32 flag4 : 1;
            u32 flag5 : 1;
            u32 flag6 : 1;
            u32 flag7 : 1;
            u32 flag8 : 1;
            u32 flag9 : 1;
            u32 flag10 : 1;
            u32 flag11 : 1;
            u32 flag12 : 1;
            u32 flag13 : 1;
            u32 flag14 : 1;
            u32 unk_15 : 17;
        } bits;
    };
    /* 0x4c */ void (*onReset)(void *slot, void *dst, u32 size);
    /* 0x50 */ void (*onSave)(void *slot, void *dst, u32 size);
    /* 0x54 */ void (*onLoad)(void *slot, void *dst, u32 size);
};

extern "C" {

extern u8 data_0214a428[0x640];
extern u32 data_0208b614[];
extern u32 data_0208c994[];
extern u32 data_0208ca9c[];
extern char data_0208cb18[];
extern void func_0204730c(SaveBase *s);
extern void func_020473ac(SaveBase *s, s32 state);
extern void func_02046cd0(SysCard *card);
extern void func_02047c2c(SaveBase *s);
extern void func_02048164(SaveBase *s);
extern void func_0204880c(SaveBase *s);

}

#endif
