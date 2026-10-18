#ifndef MAIN_GFX_TEXTWIN_H
#define MAIN_GFX_TEXTWIN_H

#include "types.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/Model.h"

// Line buffer of a text window.
typedef struct TextLines {
    /* 0x0 */ u8 unk_0;
    /* 0x4 */ void *buf;
    /* 0x8 */ u16 capacity;
    /* 0xa */ u16 count;
    /* 0xc */ u32 unk_c;
} TextLines; // size 0x10

// Text window: lays out and renders message text with control codes.
// The vtable stays in asm.
struct TextWin {
    /* 0x00 */ // vtable
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void unk_vf08();
    virtual void OnSkip();
    virtual void unk_vf10();
    virtual void unk_vf14();
    virtual void unk_vf18();
    virtual void unk_vf1c();
    virtual void unk_vf20(int a, int b);
    virtual void unk_vf24();
    virtual void unk_vf28();
    virtual void unk_vf2c();
    virtual void unk_vf30();
    virtual void unk_vf34();
    virtual void unk_vf38();
    virtual void unk_vf3c();
    virtual void unk_vf40();
    virtual void unk_vf44();
    virtual void unk_vf48();
    virtual char *ParseEscape(char *p);
    virtual void unk_vf50();
    virtual void unk_vf54();
    virtual void unk_vf58();
    virtual void unk_vf5c();
    virtual void unk_vf60();
    virtual void unk_vf64();
    virtual void unk_vf68();
    virtual void unk_vf6c();
    virtual void unk_vf70();
    virtual void unk_vf74();
    virtual void unk_vf78();
    virtual void unk_vf7c();
    virtual void unk_vf80();
    virtual void unk_vf84();
    virtual void unk_vf88();
    virtual void unk_vf8c();
    virtual void Render();
    virtual void unk_vf94();
    virtual void unk_vf98();
    virtual void unk_vf9c();
    virtual void unk_vfa0();
    /* 0x04 */ u32 flag0 : 1;
    /* 0x04 */ u32 flag1 : 1;
    /* 0x04 */ u32 rendering : 1;
    /* 0x04 */ u32 flag3 : 1;
    /* 0x04 */ u32 flag4 : 1;
    /* 0x04 */ u32 flag5 : 1;
    /* 0x04 */ u32 noVram : 1;
    /* 0x04 */ u32 inRender : 1;
    /* 0x04 */ u32 unk_4_8 : 5;
    /* 0x04 */ u32 unk_4_13 : 8;
    /* 0x04 */ u32 noShadowShift : 1;
    /* 0x04 */ u32 unk_4_22 : 2;
    /* 0x04 */ u32 flag24 : 1;
    /* 0x04 */ u32 flag25 : 1;
    /* 0x04 */ u32 flag26 : 1;
    /* 0x04 */ u32 flag27 : 1;
    /* 0x04 */ u32 flag28 : 1;
    /* 0x04 */ u32 flag29 : 1;
    /* 0x04 */ u32 unk_4_30 : 1;
    /* 0x04 */ u32 flag31 : 1;
    /* 0x08 */ TextLines *lines;
    /* 0x0c */ void *unk_0c;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ Model *model;
    /* 0x18 */ s16 unk_18;
    /* 0x1a */ s16 unk_1a;
    /* 0x1c */ s16 unk_1c;
    /* 0x1e */ s16 unk_1e;
    /* 0x20 */ VramBlock *vram;
    /* 0x24 */ u32 unk_24;
    /* 0x28 */ u32 unk_28;
    /* 0x2c */ s32 unk_2c;
    /* 0x30 */ u32 unk_30;
    /* 0x34 */ s16 unk_34;
    /* 0x36 */ u8 unk_36;
    /* 0x37 */ u8 unk_37;
    /* 0x38 */ u32 unk_38;
    /* 0x3c */ s32 unk_3c;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ u32 vramSize;
    /* 0x48 */ u32 vramArg;
    /* 0x4c */ u32 unk_4c;
    /* 0x50 */ void *unk_50;
    /* 0x54 */ void *unk_54;
    /* 0x58 */ u32 unk_58;
    /* 0x5c */ u32 unk_5c;
    /* 0x60 */ s32 unk_60;
    /* 0x64 */ s32 unk_64;
    /* 0x68 */ void *unk_68;
    /* 0x6c */ void *unk_6c;
    /* 0x70 */ s32 unk_70;
    /* 0x74 */ u16 unk_74;
    /* 0x76 */ u16 unk_76;
    /* 0x78 */ u32 unk_78;
    /* 0x7c */ u32 unk_7c;
    /* 0x80 */ s32 code;
    /* 0x84 */ s32 value;
    /* 0x88 */ s32 args[4];
    /* 0x98 */ char text[0x20];
}; // size 0xb8

// Text window that keeps its glyphs in up to 0x80 VRAM blocks.
struct TextWinEx : TextWin {
    /* 0x0b8 */ u32 blocksReady : 1;
    /* 0x0b8 */ u32 unk_b8_1 : 31;
    /* 0x0bc */ VramBlock *blocks[0x80];
    /* 0x2bc */ u16 blockIds[0x80];
    /* 0x3bc */ s8 numBlocks;
    /* 0x3be */ s16 originX;
    /* 0x3c0 */ s16 originY;
    /* 0x3c4 */ s32 unk_3c4;
    /* 0x3c8 */ s32 unk_3c8;
    /* 0x3cc */ s32 unk_3cc;
    /* 0x3d0 */ s32 page;
    /* 0x3d4 */ s32 numPages;
    /* 0x3d8 */ s32 unk_3d8;
};

// Object owned by a text box, released through its deleting destructor.
struct TextBoxObj {
    virtual void unk_vf00();
    virtual void DeletingDtor();
};

typedef struct TextBoxLine {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01[0x7f];
    /* 0x80 */ s32 unk_80;
    /* 0x84 */ TextBoxObj *obj;
    /* 0x88 */ s32 unk_88;
    /* 0x8c */ s32 unk_8c;
    /* 0x90 */ s32 unk_90;
    /* 0x94 */ s32 unk_94;
    /* 0x98 */ s32 unk_98;
} TextBoxLine; // size 0x9c

// Multi-line text box.
typedef struct TextBox {
    /* 0x000 */ u16 unk_000;
    /* 0x002 */ u8 unk_002;
    /* 0x003 */ u8 unk_003;
    /* 0x004 */ u16 unk_004;
    /* 0x008 */ u32 unk_008;
    /* 0x00c */ Model *model;
    /* 0x010 */ u32 pltt;
    /* 0x014 */ s32 lineHeight;
    /* 0x018 */ s32 unk_018;
    /* 0x01c */ u32 unk_01c;
    /* 0x020 */ u32 unk_020;
    /* 0x024 */ u32 unk_024;
    /* 0x028 */ u32 unk_028;
    /* 0x02c */ TextBoxLine lines[3];
    /* 0x200 */ TextBoxObj *obj;
    /* 0x204 */ u32 unk_204;
    /* 0x208 */ u32 unk_208;
    /* 0x20c */ u32 unk_20c;
} TextBox;

#endif
